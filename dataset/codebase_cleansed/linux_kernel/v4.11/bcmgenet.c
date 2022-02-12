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
dmadesc_set_addr(priv, d, addr);
dmadesc_set_length_status(priv, d, val);
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
unsigned int ring, u32 val,
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
unsigned int ring, u32 val,
enum dma_ring_reg r)
{
__raw_writel(val, priv->base + GENET_RDMA_REG_OFF +
(DMA_RING_SIZE * ring) +
genet_dma_ring_regs[r]);
}
static int bcmgenet_begin(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
return clk_prepare_enable(priv->clk);
}
static void bcmgenet_complete(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
clk_disable_unprepare(priv->clk);
}
static int bcmgenet_get_link_ksettings(struct net_device *dev,
struct ethtool_link_ksettings *cmd)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (!priv->phydev)
return -ENODEV;
return phy_ethtool_ksettings_get(priv->phydev, cmd);
}
static int bcmgenet_set_link_ksettings(struct net_device *dev,
const struct ethtool_link_ksettings *cmd)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (!priv->phydev)
return -ENODEV;
return phy_ethtool_ksettings_set(priv->phydev, cmd);
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
static int bcmgenet_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
ec->tx_max_coalesced_frames =
bcmgenet_tdma_ring_readl(priv, DESC_INDEX,
DMA_MBUF_DONE_THRESH);
ec->rx_max_coalesced_frames =
bcmgenet_rdma_ring_readl(priv, DESC_INDEX,
DMA_MBUF_DONE_THRESH);
ec->rx_coalesce_usecs =
bcmgenet_rdma_readl(priv, DMA_RING16_TIMEOUT) * 8192 / 1000;
return 0;
}
static int bcmgenet_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
unsigned int i;
u32 reg;
if (ec->tx_max_coalesced_frames > DMA_INTR_THRESHOLD_MASK ||
ec->tx_max_coalesced_frames == 0 ||
ec->rx_max_coalesced_frames > DMA_INTR_THRESHOLD_MASK ||
ec->rx_coalesce_usecs > (DMA_TIMEOUT_MASK * 8) + 1)
return -EINVAL;
if (ec->rx_coalesce_usecs == 0 && ec->rx_max_coalesced_frames == 0)
return -EINVAL;
if (ec->tx_coalesce_usecs || ec->tx_coalesce_usecs_high ||
ec->tx_coalesce_usecs_irq || ec->tx_coalesce_usecs_low)
return -EOPNOTSUPP;
for (i = 0; i < priv->hw_params->tx_queues; i++)
bcmgenet_tdma_ring_writel(priv, i,
ec->tx_max_coalesced_frames,
DMA_MBUF_DONE_THRESH);
bcmgenet_tdma_ring_writel(priv, DESC_INDEX,
ec->tx_max_coalesced_frames,
DMA_MBUF_DONE_THRESH);
for (i = 0; i < priv->hw_params->rx_queues; i++) {
bcmgenet_rdma_ring_writel(priv, i,
ec->rx_max_coalesced_frames,
DMA_MBUF_DONE_THRESH);
reg = bcmgenet_rdma_readl(priv, DMA_RING0_TIMEOUT + i);
reg &= ~DMA_TIMEOUT_MASK;
reg |= DIV_ROUND_UP(ec->rx_coalesce_usecs * 1000, 8192);
bcmgenet_rdma_writel(priv, reg, DMA_RING0_TIMEOUT + i);
}
bcmgenet_rdma_ring_writel(priv, DESC_INDEX,
ec->rx_max_coalesced_frames,
DMA_MBUF_DONE_THRESH);
reg = bcmgenet_rdma_readl(priv, DMA_RING16_TIMEOUT);
reg &= ~DMA_TIMEOUT_MASK;
reg |= DIV_ROUND_UP(ec->rx_coalesce_usecs * 1000, 8192);
bcmgenet_rdma_writel(priv, reg, DMA_RING16_TIMEOUT);
return 0;
}
static void bcmgenet_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "bcmgenet", sizeof(info->driver));
strlcpy(info->version, "v2.0", sizeof(info->version));
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
static void bcmgenet_get_strings(struct net_device *dev, u32 stringset,
u8 *data)
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
static u32 bcmgenet_update_stat_misc(struct bcmgenet_priv *priv, u16 offset)
{
u16 new_offset;
u32 val;
switch (offset) {
case UMAC_RBUF_OVFL_CNT_V1:
if (GENET_IS_V2(priv))
new_offset = RBUF_OVFL_CNT_V2;
else
new_offset = RBUF_OVFL_CNT_V3PLUS;
val = bcmgenet_rbuf_readl(priv, new_offset);
if (val == ~0)
bcmgenet_rbuf_writel(priv, 0, new_offset);
break;
case UMAC_RBUF_ERR_CNT_V1:
if (GENET_IS_V2(priv))
new_offset = RBUF_ERR_CNT_V2;
else
new_offset = RBUF_ERR_CNT_V3PLUS;
val = bcmgenet_rbuf_readl(priv, new_offset);
if (val == ~0)
bcmgenet_rbuf_writel(priv, 0, new_offset);
break;
default:
val = bcmgenet_umac_readl(priv, offset);
if (val == ~0)
bcmgenet_umac_writel(priv, 0, offset);
break;
}
return val;
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
case BCMGENET_STAT_SOFT:
continue;
case BCMGENET_STAT_RUNT:
offset += BCMGENET_STAT_OFFSET;
case BCMGENET_STAT_MIB_TX:
offset += BCMGENET_STAT_OFFSET;
case BCMGENET_STAT_MIB_RX:
val = bcmgenet_umac_readl(priv,
UMAC_MIB_START + j + offset);
offset = 0;
break;
case BCMGENET_STAT_MISC:
if (GENET_IS_V1(priv)) {
val = bcmgenet_umac_readl(priv, s->reg_offset);
if (val == ~0)
bcmgenet_umac_writel(priv, 0,
s->reg_offset);
} else {
val = bcmgenet_update_stat_misc(priv,
s->reg_offset);
}
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
if (sizeof(unsigned long) != sizeof(u32) &&
s->stat_sizeof == sizeof(unsigned long))
data[i] = *(unsigned long *)p;
else
data[i] = *(u32 *)p;
}
}
static void bcmgenet_eee_enable_set(struct net_device *dev, bool enable)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 off = priv->hw_params->tbuf_offset + TBUF_ENERGY_CTRL;
u32 reg;
if (enable && !priv->clk_eee_enabled) {
clk_prepare_enable(priv->clk_eee);
priv->clk_eee_enabled = true;
}
reg = bcmgenet_umac_readl(priv, UMAC_EEE_CTRL);
if (enable)
reg |= EEE_EN;
else
reg &= ~EEE_EN;
bcmgenet_umac_writel(priv, reg, UMAC_EEE_CTRL);
reg = __raw_readl(priv->base + off);
if (enable)
reg |= TBUF_EEE_EN | TBUF_PM_EN;
else
reg &= ~(TBUF_EEE_EN | TBUF_PM_EN);
__raw_writel(reg, priv->base + off);
reg = bcmgenet_rbuf_readl(priv, RBUF_ENERGY_CTRL);
if (enable)
reg |= RBUF_EEE_EN | RBUF_PM_EN;
else
reg &= ~(RBUF_EEE_EN | RBUF_PM_EN);
bcmgenet_rbuf_writel(priv, reg, RBUF_ENERGY_CTRL);
if (!enable && priv->clk_eee_enabled) {
clk_disable_unprepare(priv->clk_eee);
priv->clk_eee_enabled = false;
}
priv->eee.eee_enabled = enable;
priv->eee.eee_active = enable;
}
static int bcmgenet_get_eee(struct net_device *dev, struct ethtool_eee *e)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct ethtool_eee *p = &priv->eee;
if (GENET_IS_V1(priv))
return -EOPNOTSUPP;
e->eee_enabled = p->eee_enabled;
e->eee_active = p->eee_active;
e->tx_lpi_timer = bcmgenet_umac_readl(priv, UMAC_EEE_LPI_TIMER);
return phy_ethtool_get_eee(priv->phydev, e);
}
static int bcmgenet_set_eee(struct net_device *dev, struct ethtool_eee *e)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct ethtool_eee *p = &priv->eee;
int ret = 0;
if (GENET_IS_V1(priv))
return -EOPNOTSUPP;
p->eee_enabled = e->eee_enabled;
if (!p->eee_enabled) {
bcmgenet_eee_enable_set(dev, false);
} else {
ret = phy_init_eee(priv->phydev, 0);
if (ret) {
netif_err(priv, hw, dev, "EEE initialization failed\n");
return ret;
}
bcmgenet_umac_writel(priv, e->tx_lpi_timer, UMAC_EEE_LPI_TIMER);
bcmgenet_eee_enable_set(dev, true);
}
return phy_ethtool_set_eee(priv->phydev, e);
}
static int bcmgenet_power_down(struct bcmgenet_priv *priv,
enum bcmgenet_power_mode mode)
{
int ret = 0;
u32 reg;
switch (mode) {
case GENET_POWER_CABLE_SENSE:
phy_detach(priv->phydev);
break;
case GENET_POWER_WOL_MAGIC:
ret = bcmgenet_wol_power_down_cfg(priv, mode);
break;
case GENET_POWER_PASSIVE:
if (priv->hw_params->flags & GENET_HAS_EXT) {
reg = bcmgenet_ext_readl(priv, EXT_EXT_PWR_MGMT);
reg |= (EXT_PWR_DOWN_PHY |
EXT_PWR_DOWN_DLL | EXT_PWR_DOWN_BIAS);
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
bcmgenet_phy_power_set(priv->dev, false);
}
break;
default:
break;
}
return 0;
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
case GENET_POWER_WOL_MAGIC:
bcmgenet_wol_power_up_cfg(priv, mode);
return;
default:
break;
}
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
if (mode == GENET_POWER_PASSIVE) {
bcmgenet_phy_power_set(priv->dev, true);
bcmgenet_mii_reset(priv->dev);
}
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
static inline void bcmgenet_rx_ring16_int_disable(struct bcmgenet_rx_ring *ring)
{
bcmgenet_intrl2_0_writel(ring->priv, UMAC_IRQ_RXDMA_DONE,
INTRL2_CPU_MASK_SET);
}
static inline void bcmgenet_rx_ring16_int_enable(struct bcmgenet_rx_ring *ring)
{
bcmgenet_intrl2_0_writel(ring->priv, UMAC_IRQ_RXDMA_DONE,
INTRL2_CPU_MASK_CLEAR);
}
static inline void bcmgenet_rx_ring_int_disable(struct bcmgenet_rx_ring *ring)
{
bcmgenet_intrl2_1_writel(ring->priv,
1 << (UMAC_IRQ1_RX_INTR_SHIFT + ring->index),
INTRL2_CPU_MASK_SET);
}
static inline void bcmgenet_rx_ring_int_enable(struct bcmgenet_rx_ring *ring)
{
bcmgenet_intrl2_1_writel(ring->priv,
1 << (UMAC_IRQ1_RX_INTR_SHIFT + ring->index),
INTRL2_CPU_MASK_CLEAR);
}
static inline void bcmgenet_tx_ring16_int_disable(struct bcmgenet_tx_ring *ring)
{
bcmgenet_intrl2_0_writel(ring->priv, UMAC_IRQ_TXDMA_DONE,
INTRL2_CPU_MASK_SET);
}
static inline void bcmgenet_tx_ring16_int_enable(struct bcmgenet_tx_ring *ring)
{
bcmgenet_intrl2_0_writel(ring->priv, UMAC_IRQ_TXDMA_DONE,
INTRL2_CPU_MASK_CLEAR);
}
static inline void bcmgenet_tx_ring_int_enable(struct bcmgenet_tx_ring *ring)
{
bcmgenet_intrl2_1_writel(ring->priv, 1 << ring->index,
INTRL2_CPU_MASK_CLEAR);
}
static inline void bcmgenet_tx_ring_int_disable(struct bcmgenet_tx_ring *ring)
{
bcmgenet_intrl2_1_writel(ring->priv, 1 << ring->index,
INTRL2_CPU_MASK_SET);
}
static unsigned int __bcmgenet_tx_reclaim(struct net_device *dev,
struct bcmgenet_tx_ring *ring)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct device *kdev = &priv->pdev->dev;
struct enet_cb *tx_cb_ptr;
unsigned int pkts_compl = 0;
unsigned int bytes_compl = 0;
unsigned int c_index;
unsigned int txbds_ready;
unsigned int txbds_processed = 0;
c_index = bcmgenet_tdma_ring_readl(priv, ring->index, TDMA_CONS_INDEX);
c_index &= DMA_C_INDEX_MASK;
if (likely(c_index >= ring->c_index))
txbds_ready = c_index - ring->c_index;
else
txbds_ready = (DMA_C_INDEX_MASK + 1) - ring->c_index + c_index;
netif_dbg(priv, tx_done, dev,
"%s ring=%d old_c_index=%u c_index=%u txbds_ready=%u\n",
__func__, ring->index, ring->c_index, c_index, txbds_ready);
while (txbds_processed < txbds_ready) {
tx_cb_ptr = &priv->tx_cbs[ring->clean_ptr];
if (tx_cb_ptr->skb) {
pkts_compl++;
bytes_compl += GENET_CB(tx_cb_ptr->skb)->bytes_sent;
dma_unmap_single(kdev,
dma_unmap_addr(tx_cb_ptr, dma_addr),
dma_unmap_len(tx_cb_ptr, dma_len),
DMA_TO_DEVICE);
bcmgenet_free_cb(tx_cb_ptr);
} else if (dma_unmap_addr(tx_cb_ptr, dma_addr)) {
dma_unmap_page(kdev,
dma_unmap_addr(tx_cb_ptr, dma_addr),
dma_unmap_len(tx_cb_ptr, dma_len),
DMA_TO_DEVICE);
dma_unmap_addr_set(tx_cb_ptr, dma_addr, 0);
}
txbds_processed++;
if (likely(ring->clean_ptr < ring->end_ptr))
ring->clean_ptr++;
else
ring->clean_ptr = ring->cb_ptr;
}
ring->free_bds += txbds_processed;
ring->c_index = (ring->c_index + txbds_processed) & DMA_C_INDEX_MASK;
dev->stats.tx_packets += pkts_compl;
dev->stats.tx_bytes += bytes_compl;
netdev_tx_completed_queue(netdev_get_tx_queue(dev, ring->queue),
pkts_compl, bytes_compl);
return pkts_compl;
}
static unsigned int bcmgenet_tx_reclaim(struct net_device *dev,
struct bcmgenet_tx_ring *ring)
{
unsigned int released;
unsigned long flags;
spin_lock_irqsave(&ring->lock, flags);
released = __bcmgenet_tx_reclaim(dev, ring);
spin_unlock_irqrestore(&ring->lock, flags);
return released;
}
static int bcmgenet_tx_poll(struct napi_struct *napi, int budget)
{
struct bcmgenet_tx_ring *ring =
container_of(napi, struct bcmgenet_tx_ring, napi);
unsigned int work_done = 0;
struct netdev_queue *txq;
unsigned long flags;
spin_lock_irqsave(&ring->lock, flags);
work_done = __bcmgenet_tx_reclaim(ring->priv->dev, ring);
if (ring->free_bds > (MAX_SKB_FRAGS + 1)) {
txq = netdev_get_tx_queue(ring->priv->dev, ring->queue);
netif_tx_wake_queue(txq);
}
spin_unlock_irqrestore(&ring->lock, flags);
if (work_done == 0) {
napi_complete(napi);
ring->int_enable(ring);
return 0;
}
return budget;
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
skb_len = skb_headlen(skb);
mapping = dma_map_single(kdev, skb->data, skb_len, DMA_TO_DEVICE);
ret = dma_mapping_error(kdev, mapping);
if (ret) {
priv->mib.tx_dma_failed++;
netif_err(priv, tx_err, dev, "Tx DMA map failed\n");
dev_kfree_skb(skb);
return ret;
}
dma_unmap_addr_set(tx_cb_ptr, dma_addr, mapping);
dma_unmap_len_set(tx_cb_ptr, dma_len, skb_len);
length_status = (skb_len << DMA_BUFLENGTH_SHIFT) | dma_desc_flags |
(priv->hw_params->qtag_mask << DMA_TX_QTAG_SHIFT) |
DMA_TX_APPEND_CRC;
if (skb->ip_summed == CHECKSUM_PARTIAL)
length_status |= DMA_TX_DO_CSUM;
dmadesc_set(priv, tx_cb_ptr->bd_addr, mapping, length_status);
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
unsigned int frag_size;
dma_addr_t mapping;
int ret;
tx_cb_ptr = bcmgenet_get_txcb(priv, ring);
if (unlikely(!tx_cb_ptr))
BUG();
tx_cb_ptr->skb = NULL;
frag_size = skb_frag_size(frag);
mapping = skb_frag_dma_map(kdev, frag, 0, frag_size, DMA_TO_DEVICE);
ret = dma_mapping_error(kdev, mapping);
if (ret) {
priv->mib.tx_dma_failed++;
netif_err(priv, tx_err, dev, "%s: Tx DMA map failed\n",
__func__);
return ret;
}
dma_unmap_addr_set(tx_cb_ptr, dma_addr, mapping);
dma_unmap_len_set(tx_cb_ptr, dma_len, frag_size);
dmadesc_set(priv, tx_cb_ptr->bd_addr, mapping,
(frag_size << DMA_BUFLENGTH_SHIFT) | dma_desc_flags |
(priv->hw_params->qtag_mask << DMA_TX_QTAG_SHIFT));
return 0;
}
static struct sk_buff *bcmgenet_put_tx_csum(struct net_device *dev,
struct sk_buff *skb)
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
dev->stats.tx_dropped++;
return NULL;
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
return skb;
}
offset = skb_checksum_start_offset(skb) - sizeof(*status);
tx_csum_info = (offset << STATUS_TX_CSUM_START_SHIFT) |
(offset + skb->csum_offset);
if (ip_proto == IPPROTO_TCP || ip_proto == IPPROTO_UDP) {
tx_csum_info |= STATUS_TX_CSUM_LV;
if (ip_proto == IPPROTO_UDP && ip_ver == ETH_P_IP)
tx_csum_info |= STATUS_TX_CSUM_PROTO_UDP;
} else {
tx_csum_info = 0;
}
status->tx_csum_info = tx_csum_info;
}
return skb;
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
ring = &priv->tx_rings[index];
txq = netdev_get_tx_queue(dev, ring->queue);
nr_frags = skb_shinfo(skb)->nr_frags;
spin_lock_irqsave(&ring->lock, flags);
if (ring->free_bds <= (nr_frags + 1)) {
if (!netif_tx_queue_stopped(txq)) {
netif_tx_stop_queue(txq);
netdev_err(dev,
"%s: tx ring %d full when queue %d awake\n",
__func__, index, ring->queue);
}
ret = NETDEV_TX_BUSY;
goto out;
}
if (skb_padto(skb, ETH_ZLEN)) {
ret = NETDEV_TX_OK;
goto out;
}
GENET_CB(skb)->bytes_sent = skb->len;
if (priv->desc_64b_en) {
skb = bcmgenet_put_tx_csum(dev, skb);
if (!skb) {
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
(i == nr_frags - 1) ? DMA_EOP : 0,
ring);
if (ret) {
ret = NETDEV_TX_OK;
goto out;
}
}
skb_tx_timestamp(skb);
ring->free_bds -= nr_frags + 1;
ring->prod_index += nr_frags + 1;
ring->prod_index &= DMA_P_INDEX_MASK;
netdev_tx_sent_queue(txq, GENET_CB(skb)->bytes_sent);
if (ring->free_bds <= (MAX_SKB_FRAGS + 1))
netif_tx_stop_queue(txq);
if (!skb->xmit_more || netif_xmit_stopped(txq))
bcmgenet_tdma_ring_writel(priv, ring->index,
ring->prod_index, TDMA_PROD_INDEX);
out:
spin_unlock_irqrestore(&ring->lock, flags);
return ret;
}
static struct sk_buff *bcmgenet_rx_refill(struct bcmgenet_priv *priv,
struct enet_cb *cb)
{
struct device *kdev = &priv->pdev->dev;
struct sk_buff *skb;
struct sk_buff *rx_skb;
dma_addr_t mapping;
skb = netdev_alloc_skb(priv->dev, priv->rx_buf_len + SKB_ALIGNMENT);
if (!skb) {
priv->mib.alloc_rx_buff_failed++;
netif_err(priv, rx_err, priv->dev,
"%s: Rx skb allocation failed\n", __func__);
return NULL;
}
mapping = dma_map_single(kdev, skb->data, priv->rx_buf_len,
DMA_FROM_DEVICE);
if (dma_mapping_error(kdev, mapping)) {
priv->mib.rx_dma_failed++;
dev_kfree_skb_any(skb);
netif_err(priv, rx_err, priv->dev,
"%s: Rx skb DMA mapping failed\n", __func__);
return NULL;
}
rx_skb = cb->skb;
if (likely(rx_skb))
dma_unmap_single(kdev, dma_unmap_addr(cb, dma_addr),
priv->rx_buf_len, DMA_FROM_DEVICE);
cb->skb = skb;
dma_unmap_addr_set(cb, dma_addr, mapping);
dmadesc_set_addr(priv, cb->bd_addr, mapping);
return rx_skb;
}
static unsigned int bcmgenet_desc_rx(struct bcmgenet_rx_ring *ring,
unsigned int budget)
{
struct bcmgenet_priv *priv = ring->priv;
struct net_device *dev = priv->dev;
struct enet_cb *cb;
struct sk_buff *skb;
u32 dma_length_status;
unsigned long dma_flag;
int len;
unsigned int rxpktprocessed = 0, rxpkttoprocess;
unsigned int p_index;
unsigned int discards;
unsigned int chksum_ok = 0;
p_index = bcmgenet_rdma_ring_readl(priv, ring->index, RDMA_PROD_INDEX);
discards = (p_index >> DMA_P_INDEX_DISCARD_CNT_SHIFT) &
DMA_P_INDEX_DISCARD_CNT_MASK;
if (discards > ring->old_discards) {
discards = discards - ring->old_discards;
dev->stats.rx_missed_errors += discards;
dev->stats.rx_errors += discards;
ring->old_discards += discards;
if (ring->old_discards >= 0xC000) {
ring->old_discards = 0;
bcmgenet_rdma_ring_writel(priv, ring->index, 0,
RDMA_PROD_INDEX);
}
}
p_index &= DMA_P_INDEX_MASK;
if (likely(p_index >= ring->c_index))
rxpkttoprocess = p_index - ring->c_index;
else
rxpkttoprocess = (DMA_C_INDEX_MASK + 1) - ring->c_index +
p_index;
netif_dbg(priv, rx_status, dev,
"RDMA: rxpkttoprocess=%d\n", rxpkttoprocess);
while ((rxpktprocessed < rxpkttoprocess) &&
(rxpktprocessed < budget)) {
cb = &priv->rx_cbs[ring->read_ptr];
skb = bcmgenet_rx_refill(priv, cb);
if (unlikely(!skb)) {
dev->stats.rx_dropped++;
goto next;
}
if (!priv->desc_64b_en) {
dma_length_status =
dmadesc_get_length_status(priv, cb->bd_addr);
} else {
struct status_64 *status;
status = (struct status_64 *)skb->data;
dma_length_status = status->length_status;
}
dma_flag = dma_length_status & 0xffff;
len = dma_length_status >> DMA_BUFLENGTH_SHIFT;
netif_dbg(priv, rx_status, dev,
"%s:p_ind=%d c_ind=%d read_ptr=%d len_stat=0x%08x\n",
__func__, p_index, ring->c_index,
ring->read_ptr, dma_length_status);
if (unlikely(!(dma_flag & DMA_EOP) || !(dma_flag & DMA_SOP))) {
netif_err(priv, rx_status, dev,
"dropping fragmented packet!\n");
dev->stats.rx_errors++;
dev_kfree_skb_any(skb);
goto next;
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
dev->stats.rx_errors++;
dev_kfree_skb_any(skb);
goto next;
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
napi_gro_receive(&ring->napi, skb);
netif_dbg(priv, rx_status, dev, "pushed up to kernel\n");
next:
rxpktprocessed++;
if (likely(ring->read_ptr < ring->end_ptr))
ring->read_ptr++;
else
ring->read_ptr = ring->cb_ptr;
ring->c_index = (ring->c_index + 1) & DMA_C_INDEX_MASK;
bcmgenet_rdma_ring_writel(priv, ring->index, ring->c_index, RDMA_CONS_INDEX);
}
return rxpktprocessed;
}
static int bcmgenet_rx_poll(struct napi_struct *napi, int budget)
{
struct bcmgenet_rx_ring *ring = container_of(napi,
struct bcmgenet_rx_ring, napi);
unsigned int work_done;
work_done = bcmgenet_desc_rx(ring, budget);
if (work_done < budget) {
napi_complete_done(napi, work_done);
ring->int_enable(ring);
}
return work_done;
}
static int bcmgenet_alloc_rx_buffers(struct bcmgenet_priv *priv,
struct bcmgenet_rx_ring *ring)
{
struct enet_cb *cb;
struct sk_buff *skb;
int i;
netif_dbg(priv, hw, priv->dev, "%s\n", __func__);
for (i = 0; i < ring->size; i++) {
cb = ring->cbs + i;
skb = bcmgenet_rx_refill(priv, cb);
if (skb)
dev_kfree_skb_any(skb);
if (!cb->skb)
return -ENOMEM;
}
return 0;
}
static void bcmgenet_free_rx_buffers(struct bcmgenet_priv *priv)
{
struct device *kdev = &priv->pdev->dev;
struct enet_cb *cb;
int i;
for (i = 0; i < priv->num_rx_bds; i++) {
cb = &priv->rx_cbs[i];
if (dma_unmap_addr(cb, dma_addr)) {
dma_unmap_single(kdev,
dma_unmap_addr(cb, dma_addr),
priv->rx_buf_len, DMA_FROM_DEVICE);
dma_unmap_addr_set(cb, dma_addr, 0);
}
if (cb->skb)
bcmgenet_free_cb(cb);
}
}
static void umac_enable_set(struct bcmgenet_priv *priv, u32 mask, bool enable)
{
u32 reg;
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
if (enable)
reg |= mask;
else
reg &= ~mask;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
if (enable == 0)
usleep_range(1000, 2000);
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
"timeout waiting for MAC to come out of reset\n");
return -ETIMEDOUT;
}
return 0;
}
static void bcmgenet_intr_disable(struct bcmgenet_priv *priv)
{
bcmgenet_intrl2_0_writel(priv, 0xFFFFFFFF, INTRL2_CPU_MASK_SET);
bcmgenet_intrl2_0_writel(priv, 0xFFFFFFFF, INTRL2_CPU_CLEAR);
bcmgenet_intrl2_0_writel(priv, 0, INTRL2_CPU_MASK_CLEAR);
bcmgenet_intrl2_1_writel(priv, 0xFFFFFFFF, INTRL2_CPU_MASK_SET);
bcmgenet_intrl2_1_writel(priv, 0xFFFFFFFF, INTRL2_CPU_CLEAR);
bcmgenet_intrl2_1_writel(priv, 0, INTRL2_CPU_MASK_CLEAR);
}
static void bcmgenet_link_intr_enable(struct bcmgenet_priv *priv)
{
u32 int0_enable = 0;
if (priv->internal_phy) {
int0_enable |= UMAC_IRQ_LINK_EVENT;
} else if (priv->ext_phy) {
int0_enable |= UMAC_IRQ_LINK_EVENT;
} else if (priv->phy_interface == PHY_INTERFACE_MODE_MOCA) {
if (priv->hw_params->flags & GENET_HAS_MOCA_LINK_DET)
int0_enable |= UMAC_IRQ_LINK_EVENT;
}
bcmgenet_intrl2_0_writel(priv, int0_enable, INTRL2_CPU_MASK_CLEAR);
}
static int init_umac(struct bcmgenet_priv *priv)
{
struct device *kdev = &priv->pdev->dev;
int ret;
u32 reg;
u32 int0_enable = 0;
u32 int1_enable = 0;
int i;
dev_dbg(&priv->pdev->dev, "bcmgenet: init_umac\n");
ret = reset_umac(priv);
if (ret)
return ret;
bcmgenet_umac_writel(priv, 0, UMAC_CMD);
bcmgenet_umac_writel(priv,
MIB_RESET_RX | MIB_RESET_TX | MIB_RESET_RUNT,
UMAC_MIB_CTRL);
bcmgenet_umac_writel(priv, 0, UMAC_MIB_CTRL);
bcmgenet_umac_writel(priv, ENET_MAX_MTU_SIZE, UMAC_MAX_FRAME_LEN);
reg = bcmgenet_rbuf_readl(priv, RBUF_CTRL);
reg |= RBUF_ALIGN_2B;
bcmgenet_rbuf_writel(priv, reg, RBUF_CTRL);
if (!GENET_IS_V1(priv) && !GENET_IS_V2(priv))
bcmgenet_rbuf_writel(priv, 1, RBUF_TBUF_SIZE_CTRL);
bcmgenet_intr_disable(priv);
int0_enable |= UMAC_IRQ_RXDMA_DONE;
int0_enable |= UMAC_IRQ_TXDMA_DONE;
if (priv->phy_interface == PHY_INTERFACE_MODE_MOCA) {
reg = bcmgenet_bp_mc_get(priv);
reg |= BIT(priv->hw_params->bp_in_en_shift);
if (netif_is_multiqueue(priv->dev))
reg |= priv->hw_params->bp_in_mask;
else
reg &= ~priv->hw_params->bp_in_mask;
bcmgenet_bp_mc_set(priv, reg);
}
if (priv->hw_params->flags & GENET_HAS_MDIO_INTR)
int0_enable |= (UMAC_IRQ_MDIO_DONE | UMAC_IRQ_MDIO_ERROR);
for (i = 0; i < priv->hw_params->rx_queues; ++i)
int1_enable |= (1 << (UMAC_IRQ1_RX_INTR_SHIFT + i));
for (i = 0; i < priv->hw_params->tx_queues; ++i)
int1_enable |= (1 << i);
bcmgenet_intrl2_0_writel(priv, int0_enable, INTRL2_CPU_MASK_CLEAR);
bcmgenet_intrl2_1_writel(priv, int1_enable, INTRL2_CPU_MASK_CLEAR);
dev_dbg(kdev, "done init umac\n");
return 0;
}
static void bcmgenet_init_tx_ring(struct bcmgenet_priv *priv,
unsigned int index, unsigned int size,
unsigned int start_ptr, unsigned int end_ptr)
{
struct bcmgenet_tx_ring *ring = &priv->tx_rings[index];
u32 words_per_bd = WORDS_PER_BD(priv);
u32 flow_period_val = 0;
spin_lock_init(&ring->lock);
ring->priv = priv;
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
ring->cbs = priv->tx_cbs + start_ptr;
ring->size = size;
ring->clean_ptr = start_ptr;
ring->c_index = 0;
ring->free_bds = size;
ring->write_ptr = start_ptr;
ring->cb_ptr = start_ptr;
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
((size << DMA_RING_SIZE_SHIFT) |
RX_BUF_LENGTH), DMA_RING_BUF_SIZE);
bcmgenet_tdma_ring_writel(priv, index, start_ptr * words_per_bd,
DMA_START_ADDR);
bcmgenet_tdma_ring_writel(priv, index, start_ptr * words_per_bd,
TDMA_READ_PTR);
bcmgenet_tdma_ring_writel(priv, index, start_ptr * words_per_bd,
TDMA_WRITE_PTR);
bcmgenet_tdma_ring_writel(priv, index, end_ptr * words_per_bd - 1,
DMA_END_ADDR);
}
static int bcmgenet_init_rx_ring(struct bcmgenet_priv *priv,
unsigned int index, unsigned int size,
unsigned int start_ptr, unsigned int end_ptr)
{
struct bcmgenet_rx_ring *ring = &priv->rx_rings[index];
u32 words_per_bd = WORDS_PER_BD(priv);
int ret;
ring->priv = priv;
ring->index = index;
if (index == DESC_INDEX) {
ring->int_enable = bcmgenet_rx_ring16_int_enable;
ring->int_disable = bcmgenet_rx_ring16_int_disable;
} else {
ring->int_enable = bcmgenet_rx_ring_int_enable;
ring->int_disable = bcmgenet_rx_ring_int_disable;
}
ring->cbs = priv->rx_cbs + start_ptr;
ring->size = size;
ring->c_index = 0;
ring->read_ptr = start_ptr;
ring->cb_ptr = start_ptr;
ring->end_ptr = end_ptr - 1;
ret = bcmgenet_alloc_rx_buffers(priv, ring);
if (ret)
return ret;
bcmgenet_rdma_ring_writel(priv, index, 0, RDMA_PROD_INDEX);
bcmgenet_rdma_ring_writel(priv, index, 0, RDMA_CONS_INDEX);
bcmgenet_rdma_ring_writel(priv, index, 1, DMA_MBUF_DONE_THRESH);
bcmgenet_rdma_ring_writel(priv, index,
((size << DMA_RING_SIZE_SHIFT) |
RX_BUF_LENGTH), DMA_RING_BUF_SIZE);
bcmgenet_rdma_ring_writel(priv, index,
(DMA_FC_THRESH_LO <<
DMA_XOFF_THRESHOLD_SHIFT) |
DMA_FC_THRESH_HI, RDMA_XON_XOFF_THRESH);
bcmgenet_rdma_ring_writel(priv, index, start_ptr * words_per_bd,
DMA_START_ADDR);
bcmgenet_rdma_ring_writel(priv, index, start_ptr * words_per_bd,
RDMA_READ_PTR);
bcmgenet_rdma_ring_writel(priv, index, start_ptr * words_per_bd,
RDMA_WRITE_PTR);
bcmgenet_rdma_ring_writel(priv, index, end_ptr * words_per_bd - 1,
DMA_END_ADDR);
return ret;
}
static void bcmgenet_init_tx_napi(struct bcmgenet_priv *priv)
{
unsigned int i;
struct bcmgenet_tx_ring *ring;
for (i = 0; i < priv->hw_params->tx_queues; ++i) {
ring = &priv->tx_rings[i];
netif_tx_napi_add(priv->dev, &ring->napi, bcmgenet_tx_poll, 64);
}
ring = &priv->tx_rings[DESC_INDEX];
netif_tx_napi_add(priv->dev, &ring->napi, bcmgenet_tx_poll, 64);
}
static void bcmgenet_enable_tx_napi(struct bcmgenet_priv *priv)
{
unsigned int i;
struct bcmgenet_tx_ring *ring;
for (i = 0; i < priv->hw_params->tx_queues; ++i) {
ring = &priv->tx_rings[i];
napi_enable(&ring->napi);
}
ring = &priv->tx_rings[DESC_INDEX];
napi_enable(&ring->napi);
}
static void bcmgenet_disable_tx_napi(struct bcmgenet_priv *priv)
{
unsigned int i;
struct bcmgenet_tx_ring *ring;
for (i = 0; i < priv->hw_params->tx_queues; ++i) {
ring = &priv->tx_rings[i];
napi_disable(&ring->napi);
}
ring = &priv->tx_rings[DESC_INDEX];
napi_disable(&ring->napi);
}
static void bcmgenet_fini_tx_napi(struct bcmgenet_priv *priv)
{
unsigned int i;
struct bcmgenet_tx_ring *ring;
for (i = 0; i < priv->hw_params->tx_queues; ++i) {
ring = &priv->tx_rings[i];
netif_napi_del(&ring->napi);
}
ring = &priv->tx_rings[DESC_INDEX];
netif_napi_del(&ring->napi);
}
static void bcmgenet_init_tx_queues(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 i, dma_enable;
u32 dma_ctrl, ring_cfg;
u32 dma_priority[3] = {0, 0, 0};
dma_ctrl = bcmgenet_tdma_readl(priv, DMA_CTRL);
dma_enable = dma_ctrl & DMA_EN;
dma_ctrl &= ~DMA_EN;
bcmgenet_tdma_writel(priv, dma_ctrl, DMA_CTRL);
dma_ctrl = 0;
ring_cfg = 0;
bcmgenet_tdma_writel(priv, DMA_ARBITER_SP, DMA_ARB_CTRL);
for (i = 0; i < priv->hw_params->tx_queues; i++) {
bcmgenet_init_tx_ring(priv, i, priv->hw_params->tx_bds_per_q,
i * priv->hw_params->tx_bds_per_q,
(i + 1) * priv->hw_params->tx_bds_per_q);
ring_cfg |= (1 << i);
dma_ctrl |= (1 << (i + DMA_RING_BUF_EN_SHIFT));
dma_priority[DMA_PRIO_REG_INDEX(i)] |=
((GENET_Q0_PRIORITY + i) << DMA_PRIO_REG_SHIFT(i));
}
bcmgenet_init_tx_ring(priv, DESC_INDEX, GENET_Q16_TX_BD_CNT,
priv->hw_params->tx_queues *
priv->hw_params->tx_bds_per_q,
TOTAL_DESC);
ring_cfg |= (1 << DESC_INDEX);
dma_ctrl |= (1 << (DESC_INDEX + DMA_RING_BUF_EN_SHIFT));
dma_priority[DMA_PRIO_REG_INDEX(DESC_INDEX)] |=
((GENET_Q0_PRIORITY + priv->hw_params->tx_queues) <<
DMA_PRIO_REG_SHIFT(DESC_INDEX));
bcmgenet_tdma_writel(priv, dma_priority[0], DMA_PRIORITY_0);
bcmgenet_tdma_writel(priv, dma_priority[1], DMA_PRIORITY_1);
bcmgenet_tdma_writel(priv, dma_priority[2], DMA_PRIORITY_2);
bcmgenet_init_tx_napi(priv);
bcmgenet_tdma_writel(priv, ring_cfg, DMA_RING_CFG);
if (dma_enable)
dma_ctrl |= DMA_EN;
bcmgenet_tdma_writel(priv, dma_ctrl, DMA_CTRL);
}
static void bcmgenet_init_rx_napi(struct bcmgenet_priv *priv)
{
unsigned int i;
struct bcmgenet_rx_ring *ring;
for (i = 0; i < priv->hw_params->rx_queues; ++i) {
ring = &priv->rx_rings[i];
netif_napi_add(priv->dev, &ring->napi, bcmgenet_rx_poll, 64);
}
ring = &priv->rx_rings[DESC_INDEX];
netif_napi_add(priv->dev, &ring->napi, bcmgenet_rx_poll, 64);
}
static void bcmgenet_enable_rx_napi(struct bcmgenet_priv *priv)
{
unsigned int i;
struct bcmgenet_rx_ring *ring;
for (i = 0; i < priv->hw_params->rx_queues; ++i) {
ring = &priv->rx_rings[i];
napi_enable(&ring->napi);
}
ring = &priv->rx_rings[DESC_INDEX];
napi_enable(&ring->napi);
}
static void bcmgenet_disable_rx_napi(struct bcmgenet_priv *priv)
{
unsigned int i;
struct bcmgenet_rx_ring *ring;
for (i = 0; i < priv->hw_params->rx_queues; ++i) {
ring = &priv->rx_rings[i];
napi_disable(&ring->napi);
}
ring = &priv->rx_rings[DESC_INDEX];
napi_disable(&ring->napi);
}
static void bcmgenet_fini_rx_napi(struct bcmgenet_priv *priv)
{
unsigned int i;
struct bcmgenet_rx_ring *ring;
for (i = 0; i < priv->hw_params->rx_queues; ++i) {
ring = &priv->rx_rings[i];
netif_napi_del(&ring->napi);
}
ring = &priv->rx_rings[DESC_INDEX];
netif_napi_del(&ring->napi);
}
static int bcmgenet_init_rx_queues(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 i;
u32 dma_enable;
u32 dma_ctrl;
u32 ring_cfg;
int ret;
dma_ctrl = bcmgenet_rdma_readl(priv, DMA_CTRL);
dma_enable = dma_ctrl & DMA_EN;
dma_ctrl &= ~DMA_EN;
bcmgenet_rdma_writel(priv, dma_ctrl, DMA_CTRL);
dma_ctrl = 0;
ring_cfg = 0;
for (i = 0; i < priv->hw_params->rx_queues; i++) {
ret = bcmgenet_init_rx_ring(priv, i,
priv->hw_params->rx_bds_per_q,
i * priv->hw_params->rx_bds_per_q,
(i + 1) *
priv->hw_params->rx_bds_per_q);
if (ret)
return ret;
ring_cfg |= (1 << i);
dma_ctrl |= (1 << (i + DMA_RING_BUF_EN_SHIFT));
}
ret = bcmgenet_init_rx_ring(priv, DESC_INDEX, GENET_Q16_RX_BD_CNT,
priv->hw_params->rx_queues *
priv->hw_params->rx_bds_per_q,
TOTAL_DESC);
if (ret)
return ret;
ring_cfg |= (1 << DESC_INDEX);
dma_ctrl |= (1 << (DESC_INDEX + DMA_RING_BUF_EN_SHIFT));
bcmgenet_init_rx_napi(priv);
bcmgenet_rdma_writel(priv, ring_cfg, DMA_RING_CFG);
if (dma_enable)
dma_ctrl |= DMA_EN;
bcmgenet_rdma_writel(priv, dma_ctrl, DMA_CTRL);
return 0;
}
static int bcmgenet_dma_teardown(struct bcmgenet_priv *priv)
{
int ret = 0;
int timeout = 0;
u32 reg;
u32 dma_ctrl;
int i;
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
netdev_warn(priv->dev, "Timed out while disabling TX DMA\n");
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
netdev_warn(priv->dev, "Timed out while disabling RX DMA\n");
ret = -ETIMEDOUT;
}
dma_ctrl = 0;
for (i = 0; i < priv->hw_params->rx_queues; i++)
dma_ctrl |= (1 << (i + DMA_RING_BUF_EN_SHIFT));
reg = bcmgenet_rdma_readl(priv, DMA_CTRL);
reg &= ~dma_ctrl;
bcmgenet_rdma_writel(priv, reg, DMA_CTRL);
dma_ctrl = 0;
for (i = 0; i < priv->hw_params->tx_queues; i++)
dma_ctrl |= (1 << (i + DMA_RING_BUF_EN_SHIFT));
reg = bcmgenet_tdma_readl(priv, DMA_CTRL);
reg &= ~dma_ctrl;
bcmgenet_tdma_writel(priv, reg, DMA_CTRL);
return ret;
}
static void bcmgenet_fini_dma(struct bcmgenet_priv *priv)
{
int i;
struct netdev_queue *txq;
bcmgenet_fini_rx_napi(priv);
bcmgenet_fini_tx_napi(priv);
bcmgenet_dma_teardown(priv);
for (i = 0; i < priv->num_tx_bds; i++) {
if (priv->tx_cbs[i].skb != NULL) {
dev_kfree_skb(priv->tx_cbs[i].skb);
priv->tx_cbs[i].skb = NULL;
}
}
for (i = 0; i < priv->hw_params->tx_queues; i++) {
txq = netdev_get_tx_queue(priv->dev, priv->tx_rings[i].queue);
netdev_tx_reset_queue(txq);
}
txq = netdev_get_tx_queue(priv->dev, priv->tx_rings[DESC_INDEX].queue);
netdev_tx_reset_queue(txq);
bcmgenet_free_rx_buffers(priv);
kfree(priv->rx_cbs);
kfree(priv->tx_cbs);
}
static int bcmgenet_init_dma(struct bcmgenet_priv *priv)
{
int ret;
unsigned int i;
struct enet_cb *cb;
netif_dbg(priv, hw, priv->dev, "%s\n", __func__);
priv->rx_bds = priv->base + priv->hw_params->rdma_offset;
priv->num_rx_bds = TOTAL_DESC;
priv->rx_cbs = kcalloc(priv->num_rx_bds, sizeof(struct enet_cb),
GFP_KERNEL);
if (!priv->rx_cbs)
return -ENOMEM;
for (i = 0; i < priv->num_rx_bds; i++) {
cb = priv->rx_cbs + i;
cb->bd_addr = priv->rx_bds + i * DMA_DESC_SIZE;
}
priv->tx_bds = priv->base + priv->hw_params->tdma_offset;
priv->num_tx_bds = TOTAL_DESC;
priv->tx_cbs = kcalloc(priv->num_tx_bds, sizeof(struct enet_cb),
GFP_KERNEL);
if (!priv->tx_cbs) {
kfree(priv->rx_cbs);
return -ENOMEM;
}
for (i = 0; i < priv->num_tx_bds; i++) {
cb = priv->tx_cbs + i;
cb->bd_addr = priv->tx_bds + i * DMA_DESC_SIZE;
}
bcmgenet_rdma_writel(priv, DMA_MAX_BURST_LENGTH, DMA_SCB_BURST_SIZE);
ret = bcmgenet_init_rx_queues(priv->dev);
if (ret) {
netdev_err(priv->dev, "failed to initialize Rx queues\n");
bcmgenet_free_rx_buffers(priv);
kfree(priv->rx_cbs);
kfree(priv->tx_cbs);
return ret;
}
bcmgenet_tdma_writel(priv, DMA_MAX_BURST_LENGTH, DMA_SCB_BURST_SIZE);
bcmgenet_init_tx_queues(priv->dev);
return 0;
}
static void bcmgenet_irq_task(struct work_struct *work)
{
unsigned long flags;
unsigned int status;
struct bcmgenet_priv *priv = container_of(
work, struct bcmgenet_priv, bcmgenet_irq_work);
netif_dbg(priv, intr, priv->dev, "%s\n", __func__);
spin_lock_irqsave(&priv->lock, flags);
status = priv->irq0_stat;
priv->irq0_stat = 0;
spin_unlock_irqrestore(&priv->lock, flags);
if (status & UMAC_IRQ_MPD_R) {
netif_dbg(priv, wol, priv->dev,
"magic packet detected, waking up\n");
bcmgenet_power_up(priv, GENET_POWER_WOL_MAGIC);
}
if (status & UMAC_IRQ_LINK_EVENT)
phy_mac_interrupt(priv->phydev,
!!(status & UMAC_IRQ_LINK_UP));
}
static irqreturn_t bcmgenet_isr1(int irq, void *dev_id)
{
struct bcmgenet_priv *priv = dev_id;
struct bcmgenet_rx_ring *rx_ring;
struct bcmgenet_tx_ring *tx_ring;
unsigned int index, status;
status = bcmgenet_intrl2_1_readl(priv, INTRL2_CPU_STAT) &
~bcmgenet_intrl2_1_readl(priv, INTRL2_CPU_MASK_STATUS);
bcmgenet_intrl2_1_writel(priv, status, INTRL2_CPU_CLEAR);
netif_dbg(priv, intr, priv->dev,
"%s: IRQ=0x%x\n", __func__, status);
for (index = 0; index < priv->hw_params->rx_queues; index++) {
if (!(status & BIT(UMAC_IRQ1_RX_INTR_SHIFT + index)))
continue;
rx_ring = &priv->rx_rings[index];
if (likely(napi_schedule_prep(&rx_ring->napi))) {
rx_ring->int_disable(rx_ring);
__napi_schedule_irqoff(&rx_ring->napi);
}
}
for (index = 0; index < priv->hw_params->tx_queues; index++) {
if (!(status & BIT(index)))
continue;
tx_ring = &priv->tx_rings[index];
if (likely(napi_schedule_prep(&tx_ring->napi))) {
tx_ring->int_disable(tx_ring);
__napi_schedule_irqoff(&tx_ring->napi);
}
}
return IRQ_HANDLED;
}
static irqreturn_t bcmgenet_isr0(int irq, void *dev_id)
{
struct bcmgenet_priv *priv = dev_id;
struct bcmgenet_rx_ring *rx_ring;
struct bcmgenet_tx_ring *tx_ring;
unsigned int status;
unsigned long flags;
status = bcmgenet_intrl2_0_readl(priv, INTRL2_CPU_STAT) &
~bcmgenet_intrl2_0_readl(priv, INTRL2_CPU_MASK_STATUS);
bcmgenet_intrl2_0_writel(priv, status, INTRL2_CPU_CLEAR);
netif_dbg(priv, intr, priv->dev,
"IRQ=0x%x\n", status);
if (status & UMAC_IRQ_RXDMA_DONE) {
rx_ring = &priv->rx_rings[DESC_INDEX];
if (likely(napi_schedule_prep(&rx_ring->napi))) {
rx_ring->int_disable(rx_ring);
__napi_schedule_irqoff(&rx_ring->napi);
}
}
if (status & UMAC_IRQ_TXDMA_DONE) {
tx_ring = &priv->tx_rings[DESC_INDEX];
if (likely(napi_schedule_prep(&tx_ring->napi))) {
tx_ring->int_disable(tx_ring);
__napi_schedule_irqoff(&tx_ring->napi);
}
}
if ((priv->hw_params->flags & GENET_HAS_MDIO_INTR) &&
status & (UMAC_IRQ_MDIO_DONE | UMAC_IRQ_MDIO_ERROR)) {
wake_up(&priv->wq);
}
status &= (UMAC_IRQ_LINK_EVENT |
UMAC_IRQ_MPD_R);
if (status) {
spin_lock_irqsave(&priv->lock, flags);
priv->irq0_stat |= status;
spin_unlock_irqrestore(&priv->lock, flags);
schedule_work(&priv->bcmgenet_irq_work);
}
return IRQ_HANDLED;
}
static irqreturn_t bcmgenet_wol_isr(int irq, void *dev_id)
{
struct bcmgenet_priv *priv = dev_id;
pm_wakeup_event(&priv->pdev->dev, 0);
return IRQ_HANDLED;
}
static void bcmgenet_poll_controller(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
disable_irq(priv->irq0);
bcmgenet_isr0(priv->irq0, priv);
enable_irq(priv->irq0);
disable_irq(priv->irq1);
bcmgenet_isr1(priv->irq1, priv);
enable_irq(priv->irq1);
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
static void bcmgenet_hfb_clear(struct bcmgenet_priv *priv)
{
u32 i;
bcmgenet_hfb_reg_writel(priv, 0x0, HFB_CTRL);
bcmgenet_hfb_reg_writel(priv, 0x0, HFB_FLT_ENABLE_V3PLUS);
bcmgenet_hfb_reg_writel(priv, 0x0, HFB_FLT_ENABLE_V3PLUS + 4);
for (i = DMA_INDEX2RING_0; i <= DMA_INDEX2RING_7; i++)
bcmgenet_rdma_writel(priv, 0x0, i);
for (i = 0; i < (priv->hw_params->hfb_filter_cnt / 4); i++)
bcmgenet_hfb_reg_writel(priv, 0x0,
HFB_FLT_LEN_V3PLUS + i * sizeof(u32));
for (i = 0; i < priv->hw_params->hfb_filter_cnt *
priv->hw_params->hfb_filter_size; i++)
bcmgenet_hfb_writel(priv, 0x0, i * sizeof(u32));
}
static void bcmgenet_hfb_init(struct bcmgenet_priv *priv)
{
if (GENET_IS_V1(priv) || GENET_IS_V2(priv))
return;
bcmgenet_hfb_clear(priv);
}
static void bcmgenet_netif_start(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
bcmgenet_enable_rx_napi(priv);
bcmgenet_enable_tx_napi(priv);
umac_enable_set(priv, CMD_TX_EN | CMD_RX_EN, true);
netif_tx_start_all_queues(dev);
bcmgenet_link_intr_enable(priv);
phy_start(priv->phydev);
}
static int bcmgenet_open(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
unsigned long dma_ctrl;
u32 reg;
int ret;
netif_dbg(priv, ifup, dev, "bcmgenet_open\n");
clk_prepare_enable(priv->clk);
if (priv->internal_phy)
bcmgenet_power_up(priv, GENET_POWER_PASSIVE);
bcmgenet_umac_reset(priv);
ret = init_umac(priv);
if (ret)
goto err_clk_disable;
umac_enable_set(priv, CMD_TX_EN | CMD_RX_EN, false);
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
priv->crc_fwd_en = !!(reg & CMD_CRC_FWD);
bcmgenet_set_hw_addr(priv, dev->dev_addr);
if (priv->internal_phy) {
reg = bcmgenet_ext_readl(priv, EXT_EXT_PWR_MGMT);
reg |= EXT_ENERGY_DET_MASK;
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
}
dma_ctrl = bcmgenet_dma_disable(priv);
ret = bcmgenet_init_dma(priv);
if (ret) {
netdev_err(dev, "failed to initialize DMA\n");
goto err_clk_disable;
}
bcmgenet_enable_dma(priv, dma_ctrl);
bcmgenet_hfb_init(priv);
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
ret = bcmgenet_mii_probe(dev);
if (ret) {
netdev_err(dev, "failed to connect to PHY\n");
goto err_irq1;
}
bcmgenet_netif_start(dev);
return 0;
err_irq1:
free_irq(priv->irq1, priv);
err_irq0:
free_irq(priv->irq0, priv);
err_fini_dma:
bcmgenet_fini_dma(priv);
err_clk_disable:
if (priv->internal_phy)
bcmgenet_power_down(priv, GENET_POWER_PASSIVE);
clk_disable_unprepare(priv->clk);
return ret;
}
static void bcmgenet_netif_stop(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
netif_tx_stop_all_queues(dev);
phy_stop(priv->phydev);
bcmgenet_intr_disable(priv);
bcmgenet_disable_rx_napi(priv);
bcmgenet_disable_tx_napi(priv);
cancel_work_sync(&priv->bcmgenet_irq_work);
priv->old_link = -1;
priv->old_speed = -1;
priv->old_duplex = -1;
priv->old_pause = -1;
}
static int bcmgenet_close(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
int ret;
netif_dbg(priv, ifdown, dev, "bcmgenet_close\n");
bcmgenet_netif_stop(dev);
phy_disconnect(priv->phydev);
umac_enable_set(priv, CMD_RX_EN, false);
ret = bcmgenet_dma_teardown(priv);
if (ret)
return ret;
umac_enable_set(priv, CMD_TX_EN, false);
bcmgenet_tx_reclaim_all(dev);
bcmgenet_fini_dma(priv);
free_irq(priv->irq0, priv);
free_irq(priv->irq1, priv);
if (priv->internal_phy)
ret = bcmgenet_power_down(priv, GENET_POWER_PASSIVE);
clk_disable_unprepare(priv->clk);
return ret;
}
static void bcmgenet_dump_tx_queue(struct bcmgenet_tx_ring *ring)
{
struct bcmgenet_priv *priv = ring->priv;
u32 p_index, c_index, intsts, intmsk;
struct netdev_queue *txq;
unsigned int free_bds;
unsigned long flags;
bool txq_stopped;
if (!netif_msg_tx_err(priv))
return;
txq = netdev_get_tx_queue(priv->dev, ring->queue);
spin_lock_irqsave(&ring->lock, flags);
if (ring->index == DESC_INDEX) {
intsts = ~bcmgenet_intrl2_0_readl(priv, INTRL2_CPU_MASK_STATUS);
intmsk = UMAC_IRQ_TXDMA_DONE | UMAC_IRQ_TXDMA_MBDONE;
} else {
intsts = ~bcmgenet_intrl2_1_readl(priv, INTRL2_CPU_MASK_STATUS);
intmsk = 1 << ring->index;
}
c_index = bcmgenet_tdma_ring_readl(priv, ring->index, TDMA_CONS_INDEX);
p_index = bcmgenet_tdma_ring_readl(priv, ring->index, TDMA_PROD_INDEX);
txq_stopped = netif_tx_queue_stopped(txq);
free_bds = ring->free_bds;
spin_unlock_irqrestore(&ring->lock, flags);
netif_err(priv, tx_err, priv->dev, "Ring %d queue %d status summary\n"
"TX queue status: %s, interrupts: %s\n"
"(sw)free_bds: %d (sw)size: %d\n"
"(sw)p_index: %d (hw)p_index: %d\n"
"(sw)c_index: %d (hw)c_index: %d\n"
"(sw)clean_p: %d (sw)write_p: %d\n"
"(sw)cb_ptr: %d (sw)end_ptr: %d\n",
ring->index, ring->queue,
txq_stopped ? "stopped" : "active",
intsts & intmsk ? "enabled" : "disabled",
free_bds, ring->size,
ring->prod_index, p_index & DMA_P_INDEX_MASK,
ring->c_index, c_index & DMA_C_INDEX_MASK,
ring->clean_ptr, ring->write_ptr,
ring->cb_ptr, ring->end_ptr);
}
static void bcmgenet_timeout(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 int0_enable = 0;
u32 int1_enable = 0;
unsigned int q;
netif_dbg(priv, tx_err, dev, "bcmgenet_timeout\n");
for (q = 0; q < priv->hw_params->tx_queues; q++)
bcmgenet_dump_tx_queue(&priv->tx_rings[q]);
bcmgenet_dump_tx_queue(&priv->tx_rings[DESC_INDEX]);
bcmgenet_tx_reclaim_all(dev);
for (q = 0; q < priv->hw_params->tx_queues; q++)
int1_enable |= (1 << q);
int0_enable = UMAC_IRQ_TXDMA_DONE;
bcmgenet_intrl2_0_writel(priv, int0_enable, INTRL2_CPU_MASK_CLEAR);
bcmgenet_intrl2_1_writel(priv, int1_enable, INTRL2_CPU_MASK_CLEAR);
netif_trans_update(dev);
dev->stats.tx_errors++;
netif_tx_wake_all_queues(dev);
}
static inline void bcmgenet_set_mdf_addr(struct bcmgenet_priv *priv,
unsigned char *addr,
int *i,
int *mc)
{
u32 reg;
bcmgenet_umac_writel(priv, addr[0] << 8 | addr[1],
UMAC_MDF_ADDR + (*i * 4));
bcmgenet_umac_writel(priv, addr[2] << 24 | addr[3] << 16 |
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
u16 gphy_rev;
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
gphy_rev = reg & 0xffff;
if (gphy_rev == 0 || gphy_rev == 0x01ff) {
pr_warn("Invalid GPHY revision detected: 0x%04x\n", gphy_rev);
return;
}
if ((gphy_rev & 0xf0) != 0)
priv->gphy_rev = gphy_rev << 8;
else if ((gphy_rev & 0xff00) != 0)
priv->gphy_rev = gphy_rev;
#ifdef CONFIG_PHYS_ADDR_T_64BIT
if (!(params->flags & GENET_HAS_40BITS))
pr_warn("GENET does not support 40-bits PA\n");
#endif
pr_debug("Configuration for version: %d\n"
"TXq: %1d, TXqBDs: %1d, RXq: %1d, RXqBDs: %1d\n"
"BP << en: %2d, BP msk: 0x%05x\n"
"HFB count: %2d, QTAQ msk: 0x%05x\n"
"TBUF: 0x%04x, HFB: 0x%04x, HFBreg: 0x%04x\n"
"RDMA: 0x%05x, TDMA: 0x%05x\n"
"Words/BD: %d\n",
priv->version,
params->tx_queues, params->tx_bds_per_q,
params->rx_queues, params->rx_bds_per_q,
params->bp_in_en_shift, params->bp_in_mask,
params->hfb_filter_cnt, params->qtag_mask,
params->tbuf_offset, params->hfb_offset,
params->hfb_reg_offset,
params->rdma_offset, params->tdma_offset,
params->words_per_bd);
}
static int bcmgenet_probe(struct platform_device *pdev)
{
struct bcmgenet_platform_data *pd = pdev->dev.platform_data;
struct device_node *dn = pdev->dev.of_node;
const struct of_device_id *of_id = NULL;
struct bcmgenet_priv *priv;
struct net_device *dev;
const void *macaddr;
struct resource *r;
int err = -EIO;
const char *phy_mode_str;
dev = alloc_etherdev_mqs(sizeof(*priv), GENET_MAX_MQ_CNT + 1,
GENET_MAX_MQ_CNT + 1);
if (!dev) {
dev_err(&pdev->dev, "can't allocate net device\n");
return -ENOMEM;
}
if (dn) {
of_id = of_match_node(bcmgenet_match, dn);
if (!of_id)
return -EINVAL;
}
priv = netdev_priv(dev);
priv->irq0 = platform_get_irq(pdev, 0);
priv->irq1 = platform_get_irq(pdev, 1);
priv->wol_irq = platform_get_irq(pdev, 2);
if (!priv->irq0 || !priv->irq1) {
dev_err(&pdev->dev, "can't find IRQs\n");
err = -EINVAL;
goto err;
}
if (dn) {
macaddr = of_get_mac_address(dn);
if (!macaddr) {
dev_err(&pdev->dev, "can't find MAC address\n");
err = -EINVAL;
goto err;
}
} else {
macaddr = pd->mac_address;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(priv->base)) {
err = PTR_ERR(priv->base);
goto err;
}
spin_lock_init(&priv->lock);
SET_NETDEV_DEV(dev, &pdev->dev);
dev_set_drvdata(&pdev->dev, dev);
ether_addr_copy(dev->dev_addr, macaddr);
dev->watchdog_timeo = 2 * HZ;
dev->ethtool_ops = &bcmgenet_ethtool_ops;
dev->netdev_ops = &bcmgenet_netdev_ops;
priv->msg_enable = netif_msg_init(-1, GENET_MSG_DEFAULT);
dev->hw_features |= NETIF_F_SG | NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM | NETIF_F_RXCSUM;
priv->wol_irq_disabled = true;
err = devm_request_irq(&pdev->dev, priv->wol_irq, bcmgenet_wol_isr, 0,
dev->name, priv);
if (!err)
device_set_wakeup_capable(&pdev->dev, 1);
dev->needed_headroom += 64;
netdev_boot_setup_check(dev);
priv->dev = dev;
priv->pdev = pdev;
if (of_id)
priv->version = (enum bcmgenet_version)of_id->data;
else
priv->version = pd->genet_version;
priv->clk = devm_clk_get(&priv->pdev->dev, "enet");
if (IS_ERR(priv->clk)) {
dev_warn(&priv->pdev->dev, "failed to get enet clock\n");
priv->clk = NULL;
}
clk_prepare_enable(priv->clk);
bcmgenet_set_hw_params(priv);
init_waitqueue_head(&priv->wq);
priv->rx_buf_len = RX_BUF_LENGTH;
INIT_WORK(&priv->bcmgenet_irq_work, bcmgenet_irq_task);
priv->clk_wol = devm_clk_get(&priv->pdev->dev, "enet-wol");
if (IS_ERR(priv->clk_wol)) {
dev_warn(&priv->pdev->dev, "failed to get enet-wol clock\n");
priv->clk_wol = NULL;
}
priv->clk_eee = devm_clk_get(&priv->pdev->dev, "enet-eee");
if (IS_ERR(priv->clk_eee)) {
dev_warn(&priv->pdev->dev, "failed to get enet-eee clock\n");
priv->clk_eee = NULL;
}
if (dn && !of_property_read_string(dn, "phy-mode", &phy_mode_str) &&
!strcasecmp(phy_mode_str, "internal"))
bcmgenet_power_up(priv, GENET_POWER_PASSIVE);
err = reset_umac(priv);
if (err)
goto err_clk_disable;
err = bcmgenet_mii_init(dev);
if (err)
goto err_clk_disable;
netif_set_real_num_tx_queues(priv->dev, priv->hw_params->tx_queues + 1);
netif_set_real_num_rx_queues(priv->dev, priv->hw_params->rx_queues + 1);
netif_carrier_off(dev);
clk_disable_unprepare(priv->clk);
err = register_netdev(dev);
if (err)
goto err;
return err;
err_clk_disable:
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
static int bcmgenet_suspend(struct device *d)
{
struct net_device *dev = dev_get_drvdata(d);
struct bcmgenet_priv *priv = netdev_priv(dev);
int ret;
if (!netif_running(dev))
return 0;
bcmgenet_netif_stop(dev);
if (!device_may_wakeup(d))
phy_suspend(priv->phydev);
netif_device_detach(dev);
umac_enable_set(priv, CMD_RX_EN, false);
ret = bcmgenet_dma_teardown(priv);
if (ret)
return ret;
umac_enable_set(priv, CMD_TX_EN, false);
bcmgenet_tx_reclaim_all(dev);
bcmgenet_fini_dma(priv);
if (device_may_wakeup(d) && priv->wolopts) {
ret = bcmgenet_power_down(priv, GENET_POWER_WOL_MAGIC);
clk_prepare_enable(priv->clk_wol);
} else if (priv->internal_phy) {
ret = bcmgenet_power_down(priv, GENET_POWER_PASSIVE);
}
clk_disable_unprepare(priv->clk);
return ret;
}
static int bcmgenet_resume(struct device *d)
{
struct net_device *dev = dev_get_drvdata(d);
struct bcmgenet_priv *priv = netdev_priv(dev);
unsigned long dma_ctrl;
int ret;
u32 reg;
if (!netif_running(dev))
return 0;
ret = clk_prepare_enable(priv->clk);
if (ret)
return ret;
if (priv->internal_phy)
bcmgenet_power_up(priv, GENET_POWER_PASSIVE);
bcmgenet_umac_reset(priv);
ret = init_umac(priv);
if (ret)
goto out_clk_disable;
if (priv->wolopts)
clk_disable_unprepare(priv->clk_wol);
phy_init_hw(priv->phydev);
bcmgenet_mii_config(priv->dev);
umac_enable_set(priv, CMD_TX_EN | CMD_RX_EN, false);
bcmgenet_set_hw_addr(priv, dev->dev_addr);
if (priv->internal_phy) {
reg = bcmgenet_ext_readl(priv, EXT_EXT_PWR_MGMT);
reg |= EXT_ENERGY_DET_MASK;
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
}
if (priv->wolopts)
bcmgenet_power_up(priv, GENET_POWER_WOL_MAGIC);
dma_ctrl = bcmgenet_dma_disable(priv);
ret = bcmgenet_init_dma(priv);
if (ret) {
netdev_err(dev, "failed to initialize DMA\n");
goto out_clk_disable;
}
bcmgenet_enable_dma(priv, dma_ctrl);
netif_device_attach(dev);
if (!device_may_wakeup(d))
phy_resume(priv->phydev);
if (priv->eee.eee_enabled)
bcmgenet_eee_enable_set(dev, true);
bcmgenet_netif_start(dev);
return 0;
out_clk_disable:
if (priv->internal_phy)
bcmgenet_power_down(priv, GENET_POWER_PASSIVE);
clk_disable_unprepare(priv->clk);
return ret;
}
