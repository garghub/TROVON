static u32 emac_get_msglevel(struct net_device *netdev)
{
struct emac_adapter *adpt = netdev_priv(netdev);
return adpt->msg_enable;
}
static void emac_set_msglevel(struct net_device *netdev, u32 data)
{
struct emac_adapter *adpt = netdev_priv(netdev);
adpt->msg_enable = data;
}
static int emac_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return EMAC_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void emac_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
unsigned int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < EMAC_STATS_LEN; i++) {
strlcpy(data, emac_ethtool_stat_strings[i],
ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
break;
}
}
static void emac_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats,
u64 *data)
{
struct emac_adapter *adpt = netdev_priv(netdev);
spin_lock(&adpt->stats.lock);
emac_update_hw_stats(adpt);
memcpy(data, &adpt->stats, EMAC_STATS_LEN * sizeof(u64));
spin_unlock(&adpt->stats.lock);
}
static int emac_nway_reset(struct net_device *netdev)
{
struct phy_device *phydev = netdev->phydev;
if (!phydev)
return -ENODEV;
return genphy_restart_aneg(phydev);
}
static void emac_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct emac_adapter *adpt = netdev_priv(netdev);
ring->rx_max_pending = EMAC_MAX_RX_DESCS;
ring->tx_max_pending = EMAC_MAX_TX_DESCS;
ring->rx_pending = adpt->rx_desc_cnt;
ring->tx_pending = adpt->tx_desc_cnt;
}
static int emac_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct emac_adapter *adpt = netdev_priv(netdev);
if (ring->rx_mini_pending || ring->rx_jumbo_pending)
return -EINVAL;
adpt->tx_desc_cnt =
clamp_val(ring->tx_pending, EMAC_MIN_TX_DESCS, EMAC_MAX_TX_DESCS);
adpt->rx_desc_cnt =
clamp_val(ring->rx_pending, EMAC_MIN_RX_DESCS, EMAC_MAX_RX_DESCS);
if (netif_running(netdev))
return emac_reinit_locked(adpt);
return 0;
}
static void emac_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct emac_adapter *adpt = netdev_priv(netdev);
pause->autoneg = adpt->automatic ? AUTONEG_ENABLE : AUTONEG_DISABLE;
pause->rx_pause = adpt->rx_flow_control ? 1 : 0;
pause->tx_pause = adpt->tx_flow_control ? 1 : 0;
}
static int emac_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct emac_adapter *adpt = netdev_priv(netdev);
adpt->automatic = pause->autoneg == AUTONEG_ENABLE;
adpt->rx_flow_control = pause->rx_pause != 0;
adpt->tx_flow_control = pause->tx_pause != 0;
if (netif_running(netdev))
return emac_reinit_locked(adpt);
return 0;
}
static void emac_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *buff)
{
struct emac_adapter *adpt = netdev_priv(netdev);
u32 *val = buff;
unsigned int i;
regs->version = EMAC_REGS_VERSION;
regs->len = EMAC_MAX_REG_SIZE * sizeof(u32);
for (i = 0; i < EMAC_MAX_REG_SIZE; i++)
val[i] = readl(adpt->base + emac_regs[i]);
}
static int emac_get_regs_len(struct net_device *netdev)
{
return EMAC_MAX_REG_SIZE * sizeof(u32);
}
void emac_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &emac_ethtool_ops;
}
