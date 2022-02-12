static inline void dmadesc_set_length_status(struct bcmgenet_priv *priv,
void __iomem *d, u32 value)
{
__raw_writel(value, d + DMA_DESC_LENGTH_STATUS);
}
static inline u32 dmadesc_get_length_status(struct bcmgenet_priv *priv,
void __iomem *d)
{
return __raw_readl(d + DMA_DESC_LENGTH_STATUS);
}
static inline void dmadesc_set_addr(struct bcmgenet_priv *priv,
void __iomem *d,
dma_addr_t addr)
{
__raw_writel(lower_32_bits(addr), d + DMA_DESC_ADDRESS_LO);
#ifdef CONFIG_PHYS_ADDR_T_64BIT
if (priv->hw_params->flags & GENET_HAS_40BITS)
__raw_writel(upper_32_bits(addr), d + DMA_DESC_ADDRESS_HI);
#endif
}
static inline void dmadesc_set(struct bcmgenet_priv *priv,
void __iomem *d, dma_addr_t addr, u32 val)
{
dmadesc_set_length_status(priv, d, val);
dmadesc_set_addr(priv, d, addr);
}
static inline dma_addr_t dmadesc_get_addr(struct bcmgenet_priv *priv,
void __iomem *d)
{
dma_addr_t addr;
addr = __raw_readl(d + DMA_DESC_ADDRESS_LO);
#ifdef CONFIG_PHYS_ADDR_T_64BIT
if (priv->hw_params->flags & GENET_HAS_40BITS)
addr |= (u64)__raw_readl(d + DMA_DESC_ADDRESS_HI) << 32;
#endif
return addr;
}
static inline u32 bcmgenet_rbuf_ctrl_get(struct bcmgenet_priv *priv)
{
if (GENET_IS_V1(priv))
return bcmgenet_rbuf_readl(priv, RBUF_FLUSH_CTRL_V1);
else
return bcmgenet_sys_readl(priv, SYS_RBUF_FLUSH_CTRL);
}
static inline void bcmgenet_rbuf_ctrl_set(struct bcmgenet_priv *priv, u32 val)
{
if (GENET_IS_V1(priv))
bcmgenet_rbuf_writel(priv, val, RBUF_FLUSH_CTRL_V1);
else
bcmgenet_sys_writel(priv, val, SYS_RBUF_FLUSH_CTRL);
}
static inline u32 bcmgenet_tbuf_ctrl_get(struct bcmgenet_priv *priv)
{
if (GENET_IS_V1(priv))
return bcmgenet_rbuf_readl(priv, TBUF_CTRL_V1);
else
return __raw_readl(priv->base +
priv->hw_params->tbuf_offset + TBUF_CTRL);
}
static inline void bcmgenet_tbuf_ctrl_set(struct bcmgenet_priv *priv, u32 val)
{
if (GENET_IS_V1(priv))
bcmgenet_rbuf_writel(priv, val, TBUF_CTRL_V1);
else
__raw_writel(val, priv->base +
priv->hw_params->tbuf_offset + TBUF_CTRL);
}
static inline u32 bcmgenet_bp_mc_get(struct bcmgenet_priv *priv)
{
if (GENET_IS_V1(priv))
return bcmgenet_rbuf_readl(priv, TBUF_BP_MC_V1);
else
return __raw_readl(priv->base +
priv->hw_params->tbuf_offset + TBUF_BP_MC);
}
static inline void bcmgenet_bp_mc_set(struct bcmgenet_priv *priv, u32 val)
{
if (GENET_IS_V1(priv))
bcmgenet_rbuf_writel(priv, val, TBUF_BP_MC_V1);
else
__raw_writel(val, priv->base +
priv->hw_params->tbuf_offset + TBUF_BP_MC);
}
static inline struct bcmgenet_priv *dev_to_priv(struct device *dev)
{
return netdev_priv(dev_get_drvdata(dev));
}
static inline u32 bcmgenet_tdma_readl(struct bcmgenet_priv *priv,
enum dma_reg r)
{
return __raw_readl(priv->base + GENET_TDMA_REG_OFF +
DMA_RINGS_SIZE + bcmgenet_dma_regs[r]);
}
static inline void bcmgenet_tdma_writel(struct bcmgenet_priv *priv,
u32 val, enum dma_reg r)
{
__raw_writel(val, priv->base + GENET_TDMA_REG_OFF +
DMA_RINGS_SIZE + bcmgenet_dma_regs[r]);
}
static inline u32 bcmgenet_rdma_readl(struct bcmgenet_priv *priv,
enum dma_reg r)
{
return __raw_readl(priv->base + GENET_RDMA_REG_OFF +
DMA_RINGS_SIZE + bcmgenet_dma_regs[r]);
}
static inline void bcmgenet_rdma_writel(struct bcmgenet_priv *priv,
u32 val, enum dma_reg r)
{
__raw_writel(val, priv->base + GENET_RDMA_REG_OFF +
DMA_RINGS_SIZE + bcmgenet_dma_regs[r]);
}
static inline u32 bcmgenet_tdma_ring_readl(struct bcmgenet_priv *priv,
unsigned int ring,
enum dma_ring_reg r)
{
return __raw_readl(priv->base + GENET_TDMA_REG_OFF +
(DMA_RING_SIZE * ring) +
genet_dma_ring_regs[r]);
}
static inline void bcmgenet_tdma_ring_writel(struct bcmgenet_priv *priv,
unsigned int ring,
u32 val,
enum dma_ring_reg r)
{
__raw_writel(val, priv->base + GENET_TDMA_REG_OFF +
(DMA_RING_SIZE * ring) +
genet_dma_ring_regs[r]);
}
static inline u32 bcmgenet_rdma_ring_readl(struct bcmgenet_priv *priv,
unsigned int ring,
enum dma_ring_reg r)
{
return __raw_readl(priv->base + GENET_RDMA_REG_OFF +
(DMA_RING_SIZE * ring) +
genet_dma_ring_regs[r]);
}
static inline void bcmgenet_rdma_ring_writel(struct bcmgenet_priv *priv,
unsigned int ring,
u32 val,
enum dma_ring_reg r)
{
__raw_writel(val, priv->base + GENET_RDMA_REG_OFF +
(DMA_RING_SIZE * ring) +
genet_dma_ring_regs[r]);
}
static int bcmgenet_get_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (!priv->phydev)
return -ENODEV;
return phy_ethtool_gset(priv->phydev, cmd);
}
static int bcmgenet_set_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (!priv->phydev)
return -ENODEV;
return phy_ethtool_sset(priv->phydev, cmd);
}
static int bcmgenet_set_rx_csum(struct net_device *dev,
netdev_features_t wanted)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 rbuf_chk_ctrl;
bool rx_csum_en;
rx_csum_en = !!(wanted & NETIF_F_RXCSUM);
rbuf_chk_ctrl = bcmgenet_rbuf_readl(priv, RBUF_CHK_CTRL);
if (rx_csum_en)
rbuf_chk_ctrl |= RBUF_RXCHK_EN;
else
rbuf_chk_ctrl &= ~RBUF_RXCHK_EN;
priv->desc_rxchk_en = rx_csum_en;
if (rx_csum_en && priv->crc_fwd_en)
rbuf_chk_ctrl |= RBUF_SKIP_FCS;
else
rbuf_chk_ctrl &= ~RBUF_SKIP_FCS;
bcmgenet_rbuf_writel(priv, rbuf_chk_ctrl, RBUF_CHK_CTRL);
return 0;
}
static int bcmgenet_set_tx_csum(struct net_device *dev,
netdev_features_t wanted)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
bool desc_64b_en;
u32 tbuf_ctrl, rbuf_ctrl;
tbuf_ctrl = bcmgenet_tbuf_ctrl_get(priv);
rbuf_ctrl = bcmgenet_rbuf_readl(priv, RBUF_CTRL);
desc_64b_en = !!(wanted & (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM));
if (desc_64b_en) {
tbuf_ctrl |= RBUF_64B_EN;
rbuf_ctrl |= RBUF_64B_EN;
} else {
tbuf_ctrl &= ~RBUF_64B_EN;
rbuf_ctrl &= ~RBUF_64B_EN;
}
priv->desc_64b_en = desc_64b_en;
bcmgenet_tbuf_ctrl_set(priv, tbuf_ctrl);
bcmgenet_rbuf_writel(priv, rbuf_ctrl, RBUF_CTRL);
return 0;
}
static int bcmgenet_set_features(struct net_device *dev,
netdev_features_t features)
{
netdev_features_t changed = features ^ dev->features;
netdev_features_t wanted = dev->wanted_features;
int ret = 0;
if (changed & (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM))
ret = bcmgenet_set_tx_csum(dev, wanted);
if (changed & (NETIF_F_RXCSUM))
ret = bcmgenet_set_rx_csum(dev, wanted);
return ret;
}
static u32 bcmgenet_get_msglevel(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
return priv->msg_enable;
}
static void bcmgenet_set_msglevel(struct net_device *dev, u32 level)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
priv->msg_enable = level;
}
static void bcmgenet_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "bcmgenet", sizeof(info->driver));
strlcpy(info->version, "v2.0", sizeof(info->version));
info->n_stats = BCMGENET_STATS_LEN;
}
static int bcmgenet_get_sset_count(struct net_device *dev, int string_set)
{
switch (string_set) {
case ETH_SS_STATS:
return BCMGENET_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void bcmgenet_get_strings(struct net_device *dev,
u32 stringset, u8 *data)
{
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < BCMGENET_STATS_LEN; i++) {
memcpy(data + i * ETH_GSTRING_LEN,
bcmgenet_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
}
break;
}
}
static void bcmgenet_update_mib_counters(struct bcmgenet_priv *priv)
{
int i, j = 0;
for (i = 0; i < BCMGENET_STATS_LEN; i++) {
const struct bcmgenet_stats *s;
u8 offset = 0;
u32 val = 0;
char *p;
s = &bcmgenet_gstrings_stats[i];
switch (s->type) {
case BCMGENET_STAT_NETDEV:
continue;
case BCMGENET_STAT_MIB_RX:
case BCMGENET_STAT_MIB_TX:
case BCMGENET_STAT_RUNT:
if (s->type != BCMGENET_STAT_MIB_RX)
offset = BCMGENET_STAT_OFFSET;
val = bcmgenet_umac_readl(priv, UMAC_MIB_START +
j + offset);
break;
case BCMGENET_STAT_MISC:
val = bcmgenet_umac_readl(priv, s->reg_offset);
if (val == ~0)
bcmgenet_umac_writel(priv, 0, s->reg_offset);
break;
}
j += s->stat_sizeof;
p = (char *)priv + s->stat_offset;
*(u32 *)p = val;
}
}
static void bcmgenet_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats,
u64 *data)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
int i;
if (netif_running(dev))
bcmgenet_update_mib_counters(priv);
for (i = 0; i < BCMGENET_STATS_LEN; i++) {
const struct bcmgenet_stats *s;
char *p;
s = &bcmgenet_gstrings_stats[i];
if (s->type == BCMGENET_STAT_NETDEV)
p = (char *)&dev->stats;
else
p = (char *)priv;
p += s->stat_offset;
data[i] = *(u32 *)p;
}
}
static void bcmgenet_power_down(struct bcmgenet_priv *priv,
enum bcmgenet_power_mode mode)
{
u32 reg;
switch (mode) {
case GENET_POWER_CABLE_SENSE:
phy_detach(priv->phydev);
break;
case GENET_POWER_PASSIVE:
bcmgenet_mii_reset(priv->dev);
if (priv->hw_params->flags & GENET_HAS_EXT) {
reg = bcmgenet_ext_readl(priv, EXT_EXT_PWR_MGMT);
reg |= (EXT_PWR_DOWN_PHY |
EXT_PWR_DOWN_DLL | EXT_PWR_DOWN_BIAS);
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
}
break;
default:
break;
}
}
static void bcmgenet_power_up(struct bcmgenet_priv *priv,
enum bcmgenet_power_mode mode)
{
u32 reg;
if (!(priv->hw_params->flags & GENET_HAS_EXT))
return;
reg = bcmgenet_ext_readl(priv, EXT_EXT_PWR_MGMT);
switch (mode) {
case GENET_POWER_PASSIVE:
reg &= ~(EXT_PWR_DOWN_DLL | EXT_PWR_DOWN_PHY |
EXT_PWR_DOWN_BIAS);
case GENET_POWER_CABLE_SENSE:
reg |= EXT_PWR_DN_EN_LD;
break;
default:
break;
}
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
bcmgenet_mii_reset(priv->dev);
}
static int bcmgenet_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
int val = 0;
if (!netif_running(dev))
return -EINVAL;
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
if (!priv->phydev)
val = -ENODEV;
else
val = phy_mii_ioctl(priv->phydev, rq, cmd);
break;
default:
val = -EINVAL;
break;
}
return val;
}
static struct enet_cb *bcmgenet_get_txcb(struct bcmgenet_priv *priv,
struct bcmgenet_tx_ring *ring)
{
struct enet_cb *tx_cb_ptr;
tx_cb_ptr = ring->cbs;
tx_cb_ptr += ring->write_ptr - ring->cb_ptr;
tx_cb_ptr->bd_addr = priv->tx_bds + ring->write_ptr * DMA_DESC_SIZE;
if (ring->write_ptr == ring->end_ptr)
ring->write_ptr = ring->cb_ptr;
else
ring->write_ptr++;
return tx_cb_ptr;
}
static void bcmgenet_free_cb(struct enet_cb *cb)
{
dev_kfree_skb_any(cb->skb);
cb->skb = NULL;
dma_unmap_addr_set(cb, dma_addr, 0);
}
static inline void bcmgenet_tx_ring16_int_disable(struct bcmgenet_priv *priv,
struct bcmgenet_tx_ring *ring)
{
bcmgenet_intrl2_0_writel(priv,
UMAC_IRQ_TXDMA_BDONE | UMAC_IRQ_TXDMA_PDONE,
INTRL2_CPU_MASK_SET);
}
static inline void bcmgenet_tx_ring16_int_enable(struct bcmgenet_priv *priv,
struct bcmgenet_tx_ring *ring)
{
bcmgenet_intrl2_0_writel(priv,
UMAC_IRQ_TXDMA_BDONE | UMAC_IRQ_TXDMA_PDONE,
INTRL2_CPU_MASK_CLEAR);
}
static inline void bcmgenet_tx_ring_int_enable(struct bcmgenet_priv *priv,
struct bcmgenet_tx_ring *ring)
{
bcmgenet_intrl2_1_writel(priv,
(1 << ring->index), INTRL2_CPU_MASK_CLEAR);
priv->int1_mask &= ~(1 << ring->index);
}
static inline void bcmgenet_tx_ring_int_disable(struct bcmgenet_priv *priv,
struct bcmgenet_tx_ring *ring)
{
bcmgenet_intrl2_1_writel(priv,
(1 << ring->index), INTRL2_CPU_MASK_SET);
priv->int1_mask |= (1 << ring->index);
}
static void __bcmgenet_tx_reclaim(struct net_device *dev,
struct bcmgenet_tx_ring *ring)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
int last_tx_cn, last_c_index, num_tx_bds;
struct enet_cb *tx_cb_ptr;
struct netdev_queue *txq;
unsigned int c_index;
c_index = bcmgenet_tdma_ring_readl(priv, ring->index, TDMA_CONS_INDEX);
txq = netdev_get_tx_queue(dev, ring->queue);
last_c_index = ring->c_index;
num_tx_bds = ring->size;
c_index &= (num_tx_bds - 1);
if (c_index >= last_c_index)
last_tx_cn = c_index - last_c_index;
else
last_tx_cn = num_tx_bds - last_c_index + c_index;
netif_dbg(priv, tx_done, dev,
"%s ring=%d index=%d last_tx_cn=%d last_index=%d\n",
__func__, ring->index,
c_index, last_tx_cn, last_c_index);
while (last_tx_cn-- > 0) {
tx_cb_ptr = ring->cbs + last_c_index;
if (tx_cb_ptr->skb) {
dev->stats.tx_bytes += tx_cb_ptr->skb->len;
dma_unmap_single(&dev->dev,
dma_unmap_addr(tx_cb_ptr, dma_addr),
tx_cb_ptr->skb->len,
DMA_TO_DEVICE);
bcmgenet_free_cb(tx_cb_ptr);
} else if (dma_unmap_addr(tx_cb_ptr, dma_addr)) {
dev->stats.tx_bytes +=
dma_unmap_len(tx_cb_ptr, dma_len);
dma_unmap_page(&dev->dev,
dma_unmap_addr(tx_cb_ptr, dma_addr),
dma_unmap_len(tx_cb_ptr, dma_len),
DMA_TO_DEVICE);
dma_unmap_addr_set(tx_cb_ptr, dma_addr, 0);
}
dev->stats.tx_packets++;
ring->free_bds += 1;
last_c_index++;
last_c_index &= (num_tx_bds - 1);
}
if (ring->free_bds > (MAX_SKB_FRAGS + 1))
ring->int_disable(priv, ring);
if (netif_tx_queue_stopped(txq))
netif_tx_wake_queue(txq);
ring->c_index = c_index;
}
static void bcmgenet_tx_reclaim(struct net_device *dev,
struct bcmgenet_tx_ring *ring)
{
unsigned long flags;
spin_lock_irqsave(&ring->lock, flags);
__bcmgenet_tx_reclaim(dev, ring);
spin_unlock_irqrestore(&ring->lock, flags);
}
static void bcmgenet_tx_reclaim_all(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
int i;
if (netif_is_multiqueue(dev)) {
for (i = 0; i < priv->hw_params->tx_queues; i++)
bcmgenet_tx_reclaim(dev, &priv->tx_rings[i]);
}
bcmgenet_tx_reclaim(dev, &priv->tx_rings[DESC_INDEX]);
}
static int bcmgenet_xmit_single(struct net_device *dev,
struct sk_buff *skb,
u16 dma_desc_flags,
struct bcmgenet_tx_ring *ring)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct device *kdev = &priv->pdev->dev;
struct enet_cb *tx_cb_ptr;
unsigned int skb_len;
dma_addr_t mapping;
u32 length_status;
int ret;
tx_cb_ptr = bcmgenet_get_txcb(priv, ring);
if (unlikely(!tx_cb_ptr))
BUG();
tx_cb_ptr->skb = skb;
skb_len = skb_headlen(skb) < ETH_ZLEN ? ETH_ZLEN : skb_headlen(skb);
mapping = dma_map_single(kdev, skb->data, skb_len, DMA_TO_DEVICE);
ret = dma_mapping_error(kdev, mapping);
if (ret) {
netif_err(priv, tx_err, dev, "Tx DMA map failed\n");
dev_kfree_skb(skb);
return ret;
}
dma_unmap_addr_set(tx_cb_ptr, dma_addr, mapping);
dma_unmap_len_set(tx_cb_ptr, dma_len, skb->len);
length_status = (skb_len << DMA_BUFLENGTH_SHIFT) | dma_desc_flags |
(priv->hw_params->qtag_mask << DMA_TX_QTAG_SHIFT) |
DMA_TX_APPEND_CRC;
if (skb->ip_summed == CHECKSUM_PARTIAL)
length_status |= DMA_TX_DO_CSUM;
dmadesc_set(priv, tx_cb_ptr->bd_addr, mapping, length_status);
ring->free_bds -= 1;
ring->prod_index += 1;
ring->prod_index &= DMA_P_INDEX_MASK;
return 0;
}
static int bcmgenet_xmit_frag(struct net_device *dev,
skb_frag_t *frag,
u16 dma_desc_flags,
struct bcmgenet_tx_ring *ring)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct device *kdev = &priv->pdev->dev;
struct enet_cb *tx_cb_ptr;
dma_addr_t mapping;
int ret;
tx_cb_ptr = bcmgenet_get_txcb(priv, ring);
if (unlikely(!tx_cb_ptr))
BUG();
tx_cb_ptr->skb = NULL;
mapping = skb_frag_dma_map(kdev, frag, 0,
skb_frag_size(frag), DMA_TO_DEVICE);
ret = dma_mapping_error(kdev, mapping);
if (ret) {
netif_err(priv, tx_err, dev, "%s: Tx DMA map failed\n",
__func__);
return ret;
}
dma_unmap_addr_set(tx_cb_ptr, dma_addr, mapping);
dma_unmap_len_set(tx_cb_ptr, dma_len, frag->size);
dmadesc_set(priv, tx_cb_ptr->bd_addr, mapping,
(frag->size << DMA_BUFLENGTH_SHIFT) | dma_desc_flags |
(priv->hw_params->qtag_mask << DMA_TX_QTAG_SHIFT));
ring->free_bds -= 1;
ring->prod_index += 1;
ring->prod_index &= DMA_P_INDEX_MASK;
return 0;
}
static int bcmgenet_put_tx_csum(struct net_device *dev, struct sk_buff *skb)
{
struct status_64 *status = NULL;
struct sk_buff *new_skb;
u16 offset;
u8 ip_proto;
u16 ip_ver;
u32 tx_csum_info;
if (unlikely(skb_headroom(skb) < sizeof(*status))) {
new_skb = skb_realloc_headroom(skb, sizeof(*status));
dev_kfree_skb(skb);
if (!new_skb) {
dev->stats.tx_errors++;
dev->stats.tx_dropped++;
return -ENOMEM;
}
skb = new_skb;
}
skb_push(skb, sizeof(*status));
status = (struct status_64 *)skb->data;
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
return 0;
}
offset = skb_checksum_start_offset(skb) - sizeof(*status);
tx_csum_info = (offset << STATUS_TX_CSUM_START_SHIFT) |
(offset + skb->csum_offset);
if (ip_proto == IPPROTO_TCP || ip_proto == IPPROTO_UDP) {
tx_csum_info |= STATUS_TX_CSUM_LV;
if (ip_proto == IPPROTO_UDP && ip_ver == ETH_P_IP)
tx_csum_info |= STATUS_TX_CSUM_PROTO_UDP;
} else
tx_csum_info = 0;
status->tx_csum_info = tx_csum_info;
}
return 0;
}
static netdev_tx_t bcmgenet_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct bcmgenet_tx_ring *ring = NULL;
struct netdev_queue *txq;
unsigned long flags = 0;
int nr_frags, index;
u16 dma_desc_flags;
int ret;
int i;
index = skb_get_queue_mapping(skb);
if (index == 0)
index = DESC_INDEX;
else
index -= 1;
nr_frags = skb_shinfo(skb)->nr_frags;
ring = &priv->tx_rings[index];
txq = netdev_get_tx_queue(dev, ring->queue);
spin_lock_irqsave(&ring->lock, flags);
if (ring->free_bds <= nr_frags + 1) {
netif_tx_stop_queue(txq);
netdev_err(dev, "%s: tx ring %d full when queue %d awake\n",
__func__, index, ring->queue);
ret = NETDEV_TX_BUSY;
goto out;
}
if (priv->desc_64b_en) {
ret = bcmgenet_put_tx_csum(dev, skb);
if (ret) {
ret = NETDEV_TX_OK;
goto out;
}
}
dma_desc_flags = DMA_SOP;
if (nr_frags == 0)
dma_desc_flags |= DMA_EOP;
ret = bcmgenet_xmit_single(dev, skb, dma_desc_flags, ring);
if (ret) {
ret = NETDEV_TX_OK;
goto out;
}
for (i = 0; i < nr_frags; i++) {
ret = bcmgenet_xmit_frag(dev,
&skb_shinfo(skb)->frags[i],
(i == nr_frags - 1) ? DMA_EOP : 0, ring);
if (ret) {
ret = NETDEV_TX_OK;
goto out;
}
}
skb_tx_timestamp(skb);
bcmgenet_tdma_ring_writel(priv, ring->index,
ring->prod_index, TDMA_PROD_INDEX);
if (ring->free_bds <= (MAX_SKB_FRAGS + 1)) {
netif_tx_stop_queue(txq);
ring->int_enable(priv, ring);
}
out:
spin_unlock_irqrestore(&ring->lock, flags);
return ret;
}
static int bcmgenet_rx_refill(struct bcmgenet_priv *priv,
struct enet_cb *cb)
{
struct device *kdev = &priv->pdev->dev;
struct sk_buff *skb;
dma_addr_t mapping;
int ret;
skb = netdev_alloc_skb(priv->dev,
priv->rx_buf_len + SKB_ALIGNMENT);
if (!skb)
return -ENOMEM;
WARN_ON(cb->skb != NULL);
cb->skb = skb;
mapping = dma_map_single(kdev, skb->data,
priv->rx_buf_len, DMA_FROM_DEVICE);
ret = dma_mapping_error(kdev, mapping);
if (ret) {
bcmgenet_free_cb(cb);
netif_err(priv, rx_err, priv->dev,
"%s DMA map failed\n", __func__);
return ret;
}
dma_unmap_addr_set(cb, dma_addr, mapping);
dmadesc_set_addr(priv, priv->rx_bd_assign_ptr, mapping);
priv->rx_bd_assign_index++;
priv->rx_bd_assign_index &= (priv->num_rx_bds - 1);
priv->rx_bd_assign_ptr = priv->rx_bds +
(priv->rx_bd_assign_index * DMA_DESC_SIZE);
return 0;
}
static unsigned int bcmgenet_desc_rx(struct bcmgenet_priv *priv,
unsigned int budget)
{
struct net_device *dev = priv->dev;
struct enet_cb *cb;
struct sk_buff *skb;
u32 dma_length_status;
unsigned long dma_flag;
int len, err;
unsigned int rxpktprocessed = 0, rxpkttoprocess;
unsigned int p_index;
unsigned int chksum_ok = 0;
p_index = bcmgenet_rdma_ring_readl(priv,
DESC_INDEX, RDMA_PROD_INDEX);
p_index &= DMA_P_INDEX_MASK;
if (p_index < priv->rx_c_index)
rxpkttoprocess = (DMA_C_INDEX_MASK + 1) -
priv->rx_c_index + p_index;
else
rxpkttoprocess = p_index - priv->rx_c_index;
netif_dbg(priv, rx_status, dev,
"RDMA: rxpkttoprocess=%d\n", rxpkttoprocess);
while ((rxpktprocessed < rxpkttoprocess) &&
(rxpktprocessed < budget)) {
cb = &priv->rx_cbs[priv->rx_read_ptr];
skb = cb->skb;
dma_unmap_single(&dev->dev, dma_unmap_addr(cb, dma_addr),
priv->rx_buf_len, DMA_FROM_DEVICE);
if (!priv->desc_64b_en) {
dma_length_status = dmadesc_get_length_status(priv,
priv->rx_bds +
(priv->rx_read_ptr *
DMA_DESC_SIZE));
} else {
struct status_64 *status;
status = (struct status_64 *)skb->data;
dma_length_status = status->length_status;
}
dma_flag = dma_length_status & 0xffff;
len = dma_length_status >> DMA_BUFLENGTH_SHIFT;
netif_dbg(priv, rx_status, dev,
"%s: p_ind=%d c_ind=%d read_ptr=%d len_stat=0x%08x\n",
__func__, p_index, priv->rx_c_index, priv->rx_read_ptr,
dma_length_status);
rxpktprocessed++;
priv->rx_read_ptr++;
priv->rx_read_ptr &= (priv->num_rx_bds - 1);
if (unlikely(!skb)) {
dev->stats.rx_dropped++;
dev->stats.rx_errors++;
goto refill;
}
if (unlikely(!(dma_flag & DMA_EOP) || !(dma_flag & DMA_SOP))) {
netif_err(priv, rx_status, dev,
"Droping fragmented packet!\n");
dev->stats.rx_dropped++;
dev->stats.rx_errors++;
dev_kfree_skb_any(cb->skb);
cb->skb = NULL;
goto refill;
}
if (unlikely(dma_flag & (DMA_RX_CRC_ERROR |
DMA_RX_OV |
DMA_RX_NO |
DMA_RX_LG |
DMA_RX_RXER))) {
netif_err(priv, rx_status, dev, "dma_flag=0x%x\n",
(unsigned int)dma_flag);
if (dma_flag & DMA_RX_CRC_ERROR)
dev->stats.rx_crc_errors++;
if (dma_flag & DMA_RX_OV)
dev->stats.rx_over_errors++;
if (dma_flag & DMA_RX_NO)
dev->stats.rx_frame_errors++;
if (dma_flag & DMA_RX_LG)
dev->stats.rx_length_errors++;
dev->stats.rx_dropped++;
dev->stats.rx_errors++;
dev_kfree_skb_any(cb->skb);
cb->skb = NULL;
goto refill;
}
chksum_ok = (dma_flag & priv->dma_rx_chk_bit) &&
priv->desc_rxchk_en;
skb_put(skb, len);
if (priv->desc_64b_en) {
skb_pull(skb, 64);
len -= 64;
}
if (likely(chksum_ok))
skb->ip_summed = CHECKSUM_UNNECESSARY;
skb_pull(skb, 2);
len -= 2;
if (priv->crc_fwd_en) {
skb_trim(skb, len - ETH_FCS_LEN);
len -= ETH_FCS_LEN;
}
skb->protocol = eth_type_trans(skb, priv->dev);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
if (dma_flag & DMA_RX_MULT)
dev->stats.multicast++;
napi_gro_receive(&priv->napi, skb);
cb->skb = NULL;
netif_dbg(priv, rx_status, dev, "pushed up to kernel\n");
refill:
err = bcmgenet_rx_refill(priv, cb);
if (err)
netif_err(priv, rx_err, dev, "Rx refill failed\n");
}
return rxpktprocessed;
}
static int bcmgenet_alloc_rx_buffers(struct bcmgenet_priv *priv)
{
struct enet_cb *cb;
int ret = 0;
int i;
netif_dbg(priv, hw, priv->dev, "%s:\n", __func__);
for (i = 0; i < priv->num_rx_bds; i++) {
cb = &priv->rx_cbs[priv->rx_bd_assign_index];
if (cb->skb)
continue;
dmadesc_set_length_status(priv, priv->rx_bd_assign_ptr,
priv->rx_buf_len << DMA_BUFLENGTH_SHIFT);
ret = bcmgenet_rx_refill(priv, cb);
if (ret)
break;
}
return ret;
}
static void bcmgenet_free_rx_buffers(struct bcmgenet_priv *priv)
{
struct enet_cb *cb;
int i;
for (i = 0; i < priv->num_rx_bds; i++) {
cb = &priv->rx_cbs[i];
if (dma_unmap_addr(cb, dma_addr)) {
dma_unmap_single(&priv->dev->dev,
dma_unmap_addr(cb, dma_addr),
priv->rx_buf_len, DMA_FROM_DEVICE);
dma_unmap_addr_set(cb, dma_addr, 0);
}
if (cb->skb)
bcmgenet_free_cb(cb);
}
}
static int reset_umac(struct bcmgenet_priv *priv)
{
struct device *kdev = &priv->pdev->dev;
unsigned int timeout = 0;
u32 reg;
bcmgenet_rbuf_ctrl_set(priv, 0);
udelay(10);
bcmgenet_umac_writel(priv, 0, UMAC_CMD);
bcmgenet_umac_writel(priv, CMD_SW_RESET, UMAC_CMD);
while (timeout++ < 1000) {
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
if (!(reg & CMD_SW_RESET))
return 0;
udelay(1);
}
if (timeout == 1000) {
dev_err(kdev,
"timeout waiting for MAC to come out of resetn\n");
return -ETIMEDOUT;
}
return 0;
}
static int init_umac(struct bcmgenet_priv *priv)
{
struct device *kdev = &priv->pdev->dev;
int ret;
u32 reg, cpu_mask_clear;
dev_dbg(&priv->pdev->dev, "bcmgenet: init_umac\n");
ret = reset_umac(priv);
if (ret)
return ret;
bcmgenet_umac_writel(priv, 0, UMAC_CMD);
bcmgenet_umac_writel(priv,
MIB_RESET_RX | MIB_RESET_TX | MIB_RESET_RUNT, UMAC_MIB_CTRL);
bcmgenet_umac_writel(priv, 0, UMAC_MIB_CTRL);
bcmgenet_umac_writel(priv, ENET_MAX_MTU_SIZE, UMAC_MAX_FRAME_LEN);
reg = bcmgenet_rbuf_readl(priv, RBUF_CTRL);
reg |= RBUF_ALIGN_2B;
bcmgenet_rbuf_writel(priv, reg, RBUF_CTRL);
if (!GENET_IS_V1(priv) && !GENET_IS_V2(priv))
bcmgenet_rbuf_writel(priv, 1, RBUF_TBUF_SIZE_CTRL);
bcmgenet_intrl2_0_writel(priv, 0xFFFFFFFF, INTRL2_CPU_MASK_SET);
bcmgenet_intrl2_0_writel(priv, 0xFFFFFFFF, INTRL2_CPU_CLEAR);
bcmgenet_intrl2_0_writel(priv, 0, INTRL2_CPU_MASK_CLEAR);
cpu_mask_clear = UMAC_IRQ_RXDMA_BDONE;
dev_dbg(kdev, "%s:Enabling RXDMA_BDONE interrupt\n", __func__);
if (phy_is_internal(priv->phydev))
cpu_mask_clear |= (UMAC_IRQ_LINK_DOWN | UMAC_IRQ_LINK_UP);
else if (priv->ext_phy)
cpu_mask_clear |= (UMAC_IRQ_LINK_DOWN | UMAC_IRQ_LINK_UP);
else if (priv->phy_interface == PHY_INTERFACE_MODE_MOCA) {
reg = bcmgenet_bp_mc_get(priv);
reg |= BIT(priv->hw_params->bp_in_en_shift);
if (netif_is_multiqueue(priv->dev))
reg |= priv->hw_params->bp_in_mask;
else
reg &= ~priv->hw_params->bp_in_mask;
bcmgenet_bp_mc_set(priv, reg);
}
if (priv->hw_params->flags & GENET_HAS_MDIO_INTR)
cpu_mask_clear |= UMAC_IRQ_MDIO_DONE | UMAC_IRQ_MDIO_ERROR;
bcmgenet_intrl2_0_writel(priv, cpu_mask_clear,
INTRL2_CPU_MASK_CLEAR);
dev_dbg(kdev, "done init umac\n");
return 0;
}
static void bcmgenet_init_tx_ring(struct bcmgenet_priv *priv,
unsigned int index, unsigned int size,
unsigned int write_ptr, unsigned int end_ptr)
{
struct bcmgenet_tx_ring *ring = &priv->tx_rings[index];
u32 words_per_bd = WORDS_PER_BD(priv);
u32 flow_period_val = 0;
unsigned int first_bd;
spin_lock_init(&ring->lock);
ring->index = index;
if (index == DESC_INDEX) {
ring->queue = 0;
ring->int_enable = bcmgenet_tx_ring16_int_enable;
ring->int_disable = bcmgenet_tx_ring16_int_disable;
} else {
ring->queue = index + 1;
ring->int_enable = bcmgenet_tx_ring_int_enable;
ring->int_disable = bcmgenet_tx_ring_int_disable;
}
ring->cbs = priv->tx_cbs + write_ptr;
ring->size = size;
ring->c_index = 0;
ring->free_bds = size;
ring->write_ptr = write_ptr;
ring->cb_ptr = write_ptr;
ring->end_ptr = end_ptr - 1;
ring->prod_index = 0;
if (index != DESC_INDEX)
flow_period_val = ENET_MAX_MTU_SIZE << 16;
bcmgenet_tdma_ring_writel(priv, index, 0, TDMA_PROD_INDEX);
bcmgenet_tdma_ring_writel(priv, index, 0, TDMA_CONS_INDEX);
bcmgenet_tdma_ring_writel(priv, index, 1, DMA_MBUF_DONE_THRESH);
bcmgenet_tdma_ring_writel(priv, index, flow_period_val,
TDMA_FLOW_PERIOD);
bcmgenet_tdma_ring_writel(priv, index,
((size << DMA_RING_SIZE_SHIFT) | RX_BUF_LENGTH),
DMA_RING_BUF_SIZE);
first_bd = write_ptr;
bcmgenet_tdma_ring_writel(priv, index, first_bd * words_per_bd,
DMA_START_ADDR);
bcmgenet_tdma_ring_writel(priv, index, first_bd * words_per_bd,
TDMA_READ_PTR);
bcmgenet_tdma_ring_writel(priv, index, first_bd,
TDMA_WRITE_PTR);
bcmgenet_tdma_ring_writel(priv, index, end_ptr * words_per_bd - 1,
DMA_END_ADDR);
}
static int bcmgenet_init_rx_ring(struct bcmgenet_priv *priv,
unsigned int index, unsigned int size)
{
u32 words_per_bd = WORDS_PER_BD(priv);
int ret;
priv->num_rx_bds = TOTAL_DESC;
priv->rx_bds = priv->base + priv->hw_params->rdma_offset;
priv->rx_bd_assign_ptr = priv->rx_bds;
priv->rx_bd_assign_index = 0;
priv->rx_c_index = 0;
priv->rx_read_ptr = 0;
priv->rx_cbs = kzalloc(priv->num_rx_bds * sizeof(struct enet_cb),
GFP_KERNEL);
if (!priv->rx_cbs)
return -ENOMEM;
ret = bcmgenet_alloc_rx_buffers(priv);
if (ret) {
kfree(priv->rx_cbs);
return ret;
}
bcmgenet_rdma_ring_writel(priv, index, 0, RDMA_WRITE_PTR);
bcmgenet_rdma_ring_writel(priv, index, 0, RDMA_PROD_INDEX);
bcmgenet_rdma_ring_writel(priv, index, 0, RDMA_CONS_INDEX);
bcmgenet_rdma_ring_writel(priv, index,
((size << DMA_RING_SIZE_SHIFT) | RX_BUF_LENGTH),
DMA_RING_BUF_SIZE);
bcmgenet_rdma_ring_writel(priv, index, 0, DMA_START_ADDR);
bcmgenet_rdma_ring_writel(priv, index,
words_per_bd * size - 1, DMA_END_ADDR);
bcmgenet_rdma_ring_writel(priv, index,
(DMA_FC_THRESH_LO << DMA_XOFF_THRESHOLD_SHIFT) |
DMA_FC_THRESH_HI, RDMA_XON_XOFF_THRESH);
bcmgenet_rdma_ring_writel(priv, index, 0, RDMA_READ_PTR);
return ret;
}
static void bcmgenet_init_multiq(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
unsigned int i, dma_enable;
u32 reg, dma_ctrl, ring_cfg = 0, dma_priority = 0;
if (!netif_is_multiqueue(dev)) {
netdev_warn(dev, "called with non multi queue aware HW\n");
return;
}
dma_ctrl = bcmgenet_tdma_readl(priv, DMA_CTRL);
dma_enable = dma_ctrl & DMA_EN;
dma_ctrl &= ~DMA_EN;
bcmgenet_tdma_writel(priv, dma_ctrl, DMA_CTRL);
bcmgenet_tdma_writel(priv, DMA_ARBITER_SP, DMA_ARB_CTRL);
for (i = 0; i < priv->hw_params->tx_queues; i++) {
bcmgenet_init_tx_ring(priv, i, priv->hw_params->bds_cnt,
i * priv->hw_params->bds_cnt,
(i + 1) * priv->hw_params->bds_cnt);
ring_cfg |= 1 << i;
dma_priority |= ((GENET_Q0_PRIORITY + i) <<
(GENET_MAX_MQ_CNT + 1) * i);
dma_ctrl |= 1 << (i + DMA_RING_BUF_EN_SHIFT);
}
reg = bcmgenet_tdma_readl(priv, DMA_RING_CFG);
reg |= ring_cfg;
bcmgenet_tdma_writel(priv, reg, DMA_RING_CFG);
reg = bcmgenet_tdma_readl(priv, DMA_RING_PRIORITY);
reg |= ((GENET_Q0_PRIORITY + priv->hw_params->tx_queues) << 20);
reg |= dma_priority;
bcmgenet_tdma_writel(priv, reg, DMA_PRIORITY);
reg = bcmgenet_tdma_readl(priv, DMA_CTRL);
reg |= dma_ctrl;
if (dma_enable)
reg |= DMA_EN;
bcmgenet_tdma_writel(priv, reg, DMA_CTRL);
}
static void bcmgenet_fini_dma(struct bcmgenet_priv *priv)
{
int i;
bcmgenet_rdma_writel(priv, 0, DMA_CTRL);
bcmgenet_tdma_writel(priv, 0, DMA_CTRL);
for (i = 0; i < priv->num_tx_bds; i++) {
if (priv->tx_cbs[i].skb != NULL) {
dev_kfree_skb(priv->tx_cbs[i].skb);
priv->tx_cbs[i].skb = NULL;
}
}
bcmgenet_free_rx_buffers(priv);
kfree(priv->rx_cbs);
kfree(priv->tx_cbs);
}
static int bcmgenet_init_dma(struct bcmgenet_priv *priv)
{
int ret;
netif_dbg(priv, hw, priv->dev, "bcmgenet: init_edma\n");
ret = bcmgenet_init_rx_ring(priv, DESC_INDEX, TOTAL_DESC);
if (ret) {
netdev_err(priv->dev, "failed to initialize RX ring\n");
return ret;
}
bcmgenet_rdma_writel(priv, DMA_MAX_BURST_LENGTH, DMA_SCB_BURST_SIZE);
bcmgenet_tdma_writel(priv, DMA_MAX_BURST_LENGTH, DMA_SCB_BURST_SIZE);
priv->tx_bds = priv->base + priv->hw_params->tdma_offset;
priv->num_tx_bds = TOTAL_DESC;
priv->tx_cbs = kzalloc(priv->num_tx_bds * sizeof(struct enet_cb),
GFP_KERNEL);
if (!priv->tx_cbs) {
bcmgenet_fini_dma(priv);
return -ENOMEM;
}
bcmgenet_init_multiq(priv->dev);
bcmgenet_init_tx_ring(priv, DESC_INDEX, GENET_DEFAULT_BD_CNT,
priv->hw_params->tx_queues * priv->hw_params->bds_cnt,
TOTAL_DESC);
return 0;
}
static int bcmgenet_poll(struct napi_struct *napi, int budget)
{
struct bcmgenet_priv *priv = container_of(napi,
struct bcmgenet_priv, napi);
unsigned int work_done;
bcmgenet_tx_reclaim(priv->dev, &priv->tx_rings[DESC_INDEX]);
work_done = bcmgenet_desc_rx(priv, budget);
priv->rx_c_index += work_done;
priv->rx_c_index &= DMA_C_INDEX_MASK;
bcmgenet_rdma_ring_writel(priv, DESC_INDEX,
priv->rx_c_index, RDMA_CONS_INDEX);
if (work_done < budget) {
napi_complete(napi);
bcmgenet_intrl2_0_writel(priv,
UMAC_IRQ_RXDMA_BDONE, INTRL2_CPU_MASK_CLEAR);
}
return work_done;
}
static void bcmgenet_irq_task(struct work_struct *work)
{
struct bcmgenet_priv *priv = container_of(
work, struct bcmgenet_priv, bcmgenet_irq_work);
netif_dbg(priv, intr, priv->dev, "%s\n", __func__);
if ((priv->hw_params->flags & GENET_HAS_MDIO_INTR) &&
(priv->irq0_stat & (UMAC_IRQ_LINK_UP|UMAC_IRQ_LINK_DOWN))) {
phy_mac_interrupt(priv->phydev,
priv->irq0_stat & UMAC_IRQ_LINK_UP);
priv->irq0_stat &= ~(UMAC_IRQ_LINK_UP|UMAC_IRQ_LINK_DOWN);
}
}
static irqreturn_t bcmgenet_isr1(int irq, void *dev_id)
{
struct bcmgenet_priv *priv = dev_id;
unsigned int index;
priv->irq1_stat =
bcmgenet_intrl2_1_readl(priv, INTRL2_CPU_STAT) &
~priv->int1_mask;
bcmgenet_intrl2_1_writel(priv, priv->irq1_stat, INTRL2_CPU_CLEAR);
netif_dbg(priv, intr, priv->dev,
"%s: IRQ=0x%x\n", __func__, priv->irq1_stat);
if (priv->irq1_stat & 0x0000ffff) {
index = 0;
for (index = 0; index < 16; index++) {
if (priv->irq1_stat & (1 << index))
bcmgenet_tx_reclaim(priv->dev,
&priv->tx_rings[index]);
}
}
return IRQ_HANDLED;
}
static irqreturn_t bcmgenet_isr0(int irq, void *dev_id)
{
struct bcmgenet_priv *priv = dev_id;
priv->irq0_stat =
bcmgenet_intrl2_0_readl(priv, INTRL2_CPU_STAT) &
~bcmgenet_intrl2_0_readl(priv, INTRL2_CPU_MASK_STATUS);
bcmgenet_intrl2_0_writel(priv, priv->irq0_stat, INTRL2_CPU_CLEAR);
netif_dbg(priv, intr, priv->dev,
"IRQ=0x%x\n", priv->irq0_stat);
if (priv->irq0_stat & (UMAC_IRQ_RXDMA_BDONE | UMAC_IRQ_RXDMA_PDONE)) {
if (likely(napi_schedule_prep(&priv->napi))) {
bcmgenet_intrl2_0_writel(priv,
UMAC_IRQ_RXDMA_BDONE, INTRL2_CPU_MASK_SET);
__napi_schedule(&priv->napi);
}
}
if (priv->irq0_stat &
(UMAC_IRQ_TXDMA_BDONE | UMAC_IRQ_TXDMA_PDONE)) {
bcmgenet_tx_reclaim(priv->dev, &priv->tx_rings[DESC_INDEX]);
}
if (priv->irq0_stat & (UMAC_IRQ_PHY_DET_R |
UMAC_IRQ_PHY_DET_F |
UMAC_IRQ_LINK_UP |
UMAC_IRQ_LINK_DOWN |
UMAC_IRQ_HFB_SM |
UMAC_IRQ_HFB_MM |
UMAC_IRQ_MPD_R)) {
schedule_work(&priv->bcmgenet_irq_work);
}
if ((priv->hw_params->flags & GENET_HAS_MDIO_INTR) &&
priv->irq0_stat & (UMAC_IRQ_MDIO_DONE | UMAC_IRQ_MDIO_ERROR)) {
priv->irq0_stat &= ~(UMAC_IRQ_MDIO_DONE | UMAC_IRQ_MDIO_ERROR);
wake_up(&priv->wq);
}
return IRQ_HANDLED;
}
static void bcmgenet_umac_reset(struct bcmgenet_priv *priv)
{
u32 reg;
reg = bcmgenet_rbuf_ctrl_get(priv);
reg |= BIT(1);
bcmgenet_rbuf_ctrl_set(priv, reg);
udelay(10);
reg &= ~BIT(1);
bcmgenet_rbuf_ctrl_set(priv, reg);
udelay(10);
}
static void bcmgenet_set_hw_addr(struct bcmgenet_priv *priv,
unsigned char *addr)
{
bcmgenet_umac_writel(priv, (addr[0] << 24) | (addr[1] << 16) |
(addr[2] << 8) | addr[3], UMAC_MAC0);
bcmgenet_umac_writel(priv, (addr[4] << 8) | addr[5], UMAC_MAC1);
}
static int bcmgenet_wol_resume(struct bcmgenet_priv *priv)
{
int ret;
clk_disable(priv->clk_wol);
ret = init_umac(priv);
if (ret)
return ret;
phy_init_hw(priv->phydev);
bcmgenet_mii_config(priv->dev);
return 0;
}
static u32 bcmgenet_dma_disable(struct bcmgenet_priv *priv)
{
u32 reg;
u32 dma_ctrl;
dma_ctrl = 1 << (DESC_INDEX + DMA_RING_BUF_EN_SHIFT) | DMA_EN;
reg = bcmgenet_tdma_readl(priv, DMA_CTRL);
reg &= ~dma_ctrl;
bcmgenet_tdma_writel(priv, reg, DMA_CTRL);
reg = bcmgenet_rdma_readl(priv, DMA_CTRL);
reg &= ~dma_ctrl;
bcmgenet_rdma_writel(priv, reg, DMA_CTRL);
bcmgenet_umac_writel(priv, 1, UMAC_TX_FLUSH);
udelay(10);
bcmgenet_umac_writel(priv, 0, UMAC_TX_FLUSH);
return dma_ctrl;
}
static void bcmgenet_enable_dma(struct bcmgenet_priv *priv, u32 dma_ctrl)
{
u32 reg;
reg = bcmgenet_rdma_readl(priv, DMA_CTRL);
reg |= dma_ctrl;
bcmgenet_rdma_writel(priv, reg, DMA_CTRL);
reg = bcmgenet_tdma_readl(priv, DMA_CTRL);
reg |= dma_ctrl;
bcmgenet_tdma_writel(priv, reg, DMA_CTRL);
}
static int bcmgenet_open(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
unsigned long dma_ctrl;
u32 reg;
int ret;
netif_dbg(priv, ifup, dev, "bcmgenet_open\n");
if (!IS_ERR(priv->clk))
clk_prepare_enable(priv->clk);
bcmgenet_umac_reset(priv);
ret = init_umac(priv);
if (ret)
goto err_clk_disable;
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
reg &= ~(CMD_TX_EN | CMD_RX_EN);
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
bcmgenet_set_hw_addr(priv, dev->dev_addr);
if (priv->wol_enabled) {
ret = bcmgenet_wol_resume(priv);
if (ret)
return ret;
}
if (phy_is_internal(priv->phydev)) {
reg = bcmgenet_ext_readl(priv, EXT_EXT_PWR_MGMT);
reg |= EXT_ENERGY_DET_MASK;
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
}
dma_ctrl = bcmgenet_dma_disable(priv);
ret = bcmgenet_init_dma(priv);
if (ret) {
netdev_err(dev, "failed to initialize DMA\n");
goto err_fini_dma;
}
bcmgenet_enable_dma(priv, dma_ctrl);
ret = request_irq(priv->irq0, bcmgenet_isr0, IRQF_SHARED,
dev->name, priv);
if (ret < 0) {
netdev_err(dev, "can't request IRQ %d\n", priv->irq0);
goto err_fini_dma;
}
ret = request_irq(priv->irq1, bcmgenet_isr1, IRQF_SHARED,
dev->name, priv);
if (ret < 0) {
netdev_err(dev, "can't request IRQ %d\n", priv->irq1);
goto err_irq0;
}
napi_enable(&priv->napi);
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
reg |= (CMD_TX_EN | CMD_RX_EN);
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
priv->crc_fwd_en = !!(reg & CMD_CRC_FWD);
device_set_wakeup_capable(&dev->dev, 1);
if (phy_is_internal(priv->phydev))
bcmgenet_power_up(priv, GENET_POWER_PASSIVE);
netif_tx_start_all_queues(dev);
phy_start(priv->phydev);
return 0;
err_irq0:
free_irq(priv->irq0, dev);
err_fini_dma:
bcmgenet_fini_dma(priv);
err_clk_disable:
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
return ret;
}
static int bcmgenet_dma_teardown(struct bcmgenet_priv *priv)
{
int ret = 0;
int timeout = 0;
u32 reg;
reg = bcmgenet_tdma_readl(priv, DMA_CTRL);
reg &= ~DMA_EN;
bcmgenet_tdma_writel(priv, reg, DMA_CTRL);
while (timeout++ < DMA_TIMEOUT_VAL) {
reg = bcmgenet_tdma_readl(priv, DMA_STATUS);
if (reg & DMA_DISABLED)
break;
udelay(1);
}
if (timeout == DMA_TIMEOUT_VAL) {
netdev_warn(priv->dev,
"Timed out while disabling TX DMA\n");
ret = -ETIMEDOUT;
}
usleep_range(10000, 20000);
reg = bcmgenet_rdma_readl(priv, DMA_CTRL);
reg &= ~DMA_EN;
bcmgenet_rdma_writel(priv, reg, DMA_CTRL);
timeout = 0;
while (timeout++ < DMA_TIMEOUT_VAL) {
reg = bcmgenet_rdma_readl(priv, DMA_STATUS);
if (reg & DMA_DISABLED)
break;
udelay(1);
}
if (timeout == DMA_TIMEOUT_VAL) {
netdev_warn(priv->dev,
"Timed out while disabling RX DMA\n");
ret = -ETIMEDOUT;
}
return ret;
}
static int bcmgenet_close(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
int ret;
u32 reg;
netif_dbg(priv, ifdown, dev, "bcmgenet_close\n");
phy_stop(priv->phydev);
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
reg &= ~CMD_RX_EN;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
netif_tx_stop_all_queues(dev);
ret = bcmgenet_dma_teardown(priv);
if (ret)
return ret;
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
reg &= ~CMD_TX_EN;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
napi_disable(&priv->napi);
bcmgenet_tx_reclaim_all(dev);
bcmgenet_fini_dma(priv);
free_irq(priv->irq0, priv);
free_irq(priv->irq1, priv);
cancel_work_sync(&priv->bcmgenet_irq_work);
if (phy_is_internal(priv->phydev))
bcmgenet_power_down(priv, GENET_POWER_PASSIVE);
if (priv->wol_enabled)
clk_enable(priv->clk_wol);
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
return 0;
}
static void bcmgenet_timeout(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
netif_dbg(priv, tx_err, dev, "bcmgenet_timeout\n");
dev->trans_start = jiffies;
dev->stats.tx_errors++;
netif_tx_wake_all_queues(dev);
}
static inline void bcmgenet_set_mdf_addr(struct bcmgenet_priv *priv,
unsigned char *addr,
int *i,
int *mc)
{
u32 reg;
bcmgenet_umac_writel(priv,
addr[0] << 8 | addr[1], UMAC_MDF_ADDR + (*i * 4));
bcmgenet_umac_writel(priv,
addr[2] << 24 | addr[3] << 16 |
addr[4] << 8 | addr[5],
UMAC_MDF_ADDR + ((*i + 1) * 4));
reg = bcmgenet_umac_readl(priv, UMAC_MDF_CTRL);
reg |= (1 << (MAX_MC_COUNT - *mc));
bcmgenet_umac_writel(priv, reg, UMAC_MDF_CTRL);
*i += 2;
(*mc)++;
}
static void bcmgenet_set_rx_mode(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct netdev_hw_addr *ha;
int i, mc;
u32 reg;
netif_dbg(priv, hw, dev, "%s: %08X\n", __func__, dev->flags);
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
if (dev->flags & IFF_PROMISC) {
reg |= CMD_PROMISC;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
bcmgenet_umac_writel(priv, 0, UMAC_MDF_CTRL);
return;
} else {
reg &= ~CMD_PROMISC;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
}
if (dev->flags & IFF_ALLMULTI) {
netdev_warn(dev, "ALLMULTI is not supported\n");
return;
}
i = 0;
mc = 0;
bcmgenet_set_mdf_addr(priv, dev->broadcast, &i, &mc);
bcmgenet_set_mdf_addr(priv, dev->dev_addr, &i, &mc);
if (netdev_uc_count(dev) > (MAX_MC_COUNT - mc))
return;
if (!netdev_uc_empty(dev))
netdev_for_each_uc_addr(ha, dev)
bcmgenet_set_mdf_addr(priv, ha->addr, &i, &mc);
if (netdev_mc_empty(dev) || netdev_mc_count(dev) >= (MAX_MC_COUNT - mc))
return;
netdev_for_each_mc_addr(ha, dev)
bcmgenet_set_mdf_addr(priv, ha->addr, &i, &mc);
}
static int bcmgenet_set_mac_addr(struct net_device *dev, void *p)
{
struct sockaddr *addr = p;
if (netif_running(dev))
return -EBUSY;
ether_addr_copy(dev->dev_addr, addr->sa_data);
return 0;
}
static void bcmgenet_set_hw_params(struct bcmgenet_priv *priv)
{
struct bcmgenet_hw_params *params;
u32 reg;
u8 major;
if (GENET_IS_V4(priv)) {
bcmgenet_dma_regs = bcmgenet_dma_regs_v3plus;
genet_dma_ring_regs = genet_dma_ring_regs_v4;
priv->dma_rx_chk_bit = DMA_RX_CHK_V3PLUS;
priv->version = GENET_V4;
} else if (GENET_IS_V3(priv)) {
bcmgenet_dma_regs = bcmgenet_dma_regs_v3plus;
genet_dma_ring_regs = genet_dma_ring_regs_v123;
priv->dma_rx_chk_bit = DMA_RX_CHK_V3PLUS;
priv->version = GENET_V3;
} else if (GENET_IS_V2(priv)) {
bcmgenet_dma_regs = bcmgenet_dma_regs_v2;
genet_dma_ring_regs = genet_dma_ring_regs_v123;
priv->dma_rx_chk_bit = DMA_RX_CHK_V12;
priv->version = GENET_V2;
} else if (GENET_IS_V1(priv)) {
bcmgenet_dma_regs = bcmgenet_dma_regs_v1;
genet_dma_ring_regs = genet_dma_ring_regs_v123;
priv->dma_rx_chk_bit = DMA_RX_CHK_V12;
priv->version = GENET_V1;
}
priv->hw_params = &bcmgenet_hw_params[priv->version];
params = priv->hw_params;
reg = bcmgenet_sys_readl(priv, SYS_REV_CTRL);
major = (reg >> 24 & 0x0f);
if (major == 5)
major = 4;
else if (major == 0)
major = 1;
if (major != priv->version) {
dev_err(&priv->pdev->dev,
"GENET version mismatch, got: %d, configured for: %d\n",
major, priv->version);
}
dev_info(&priv->pdev->dev, "GENET " GENET_VER_FMT,
major, (reg >> 16) & 0x0f, reg & 0xffff);
#ifdef CONFIG_PHYS_ADDR_T_64BIT
if (!(params->flags & GENET_HAS_40BITS))
pr_warn("GENET does not support 40-bits PA\n");
#endif
pr_debug("Configuration for version: %d\n"
"TXq: %1d, RXq: %1d, BDs: %1d\n"
"BP << en: %2d, BP msk: 0x%05x\n"
"HFB count: %2d, QTAQ msk: 0x%05x\n"
"TBUF: 0x%04x, HFB: 0x%04x, HFBreg: 0x%04x\n"
"RDMA: 0x%05x, TDMA: 0x%05x\n"
"Words/BD: %d\n",
priv->version,
params->tx_queues, params->rx_queues, params->bds_cnt,
params->bp_in_en_shift, params->bp_in_mask,
params->hfb_filter_cnt, params->qtag_mask,
params->tbuf_offset, params->hfb_offset,
params->hfb_reg_offset,
params->rdma_offset, params->tdma_offset,
params->words_per_bd);
}
static int bcmgenet_probe(struct platform_device *pdev)
{
struct device_node *dn = pdev->dev.of_node;
const struct of_device_id *of_id;
struct bcmgenet_priv *priv;
struct net_device *dev;
const void *macaddr;
struct resource *r;
int err = -EIO;
dev = alloc_etherdev_mqs(sizeof(*priv), GENET_MAX_MQ_CNT + 1, 1);
if (!dev) {
dev_err(&pdev->dev, "can't allocate net device\n");
return -ENOMEM;
}
of_id = of_match_node(bcmgenet_match, dn);
if (!of_id)
return -EINVAL;
priv = netdev_priv(dev);
priv->irq0 = platform_get_irq(pdev, 0);
priv->irq1 = platform_get_irq(pdev, 1);
if (!priv->irq0 || !priv->irq1) {
dev_err(&pdev->dev, "can't find IRQs\n");
err = -EINVAL;
goto err;
}
macaddr = of_get_mac_address(dn);
if (!macaddr) {
dev_err(&pdev->dev, "can't find MAC address\n");
err = -EINVAL;
goto err;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(priv->base)) {
err = PTR_ERR(priv->base);
goto err;
}
SET_NETDEV_DEV(dev, &pdev->dev);
dev_set_drvdata(&pdev->dev, dev);
ether_addr_copy(dev->dev_addr, macaddr);
dev->watchdog_timeo = 2 * HZ;
SET_ETHTOOL_OPS(dev, &bcmgenet_ethtool_ops);
dev->netdev_ops = &bcmgenet_netdev_ops;
netif_napi_add(dev, &priv->napi, bcmgenet_poll, 64);
priv->msg_enable = netif_msg_init(-1, GENET_MSG_DEFAULT);
dev->hw_features |= NETIF_F_SG | NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM | NETIF_F_RXCSUM;
dev->needed_headroom += 64;
netdev_boot_setup_check(dev);
priv->dev = dev;
priv->pdev = pdev;
priv->version = (enum bcmgenet_version)of_id->data;
bcmgenet_set_hw_params(priv);
init_waitqueue_head(&priv->wq);
priv->rx_buf_len = RX_BUF_LENGTH;
INIT_WORK(&priv->bcmgenet_irq_work, bcmgenet_irq_task);
priv->clk = devm_clk_get(&priv->pdev->dev, "enet");
if (IS_ERR(priv->clk))
dev_warn(&priv->pdev->dev, "failed to get enet clock\n");
priv->clk_wol = devm_clk_get(&priv->pdev->dev, "enet-wol");
if (IS_ERR(priv->clk_wol))
dev_warn(&priv->pdev->dev, "failed to get enet-wol clock\n");
if (!IS_ERR(priv->clk))
clk_prepare_enable(priv->clk);
err = reset_umac(priv);
if (err)
goto err_clk_disable;
err = bcmgenet_mii_init(dev);
if (err)
goto err_clk_disable;
netif_set_real_num_tx_queues(priv->dev, priv->hw_params->tx_queues + 1);
netif_set_real_num_rx_queues(priv->dev, priv->hw_params->rx_queues + 1);
err = register_netdev(dev);
if (err)
goto err_clk_disable;
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
return err;
err_clk_disable:
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
err:
free_netdev(dev);
return err;
}
static int bcmgenet_remove(struct platform_device *pdev)
{
struct bcmgenet_priv *priv = dev_to_priv(&pdev->dev);
dev_set_drvdata(&pdev->dev, NULL);
unregister_netdev(priv->dev);
bcmgenet_mii_exit(priv->dev);
free_netdev(priv->dev);
return 0;
}
