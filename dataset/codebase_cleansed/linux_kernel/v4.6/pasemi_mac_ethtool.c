static int
pasemi_mac_ethtool_get_settings(struct net_device *netdev,
struct ethtool_cmd *cmd)
{
struct pasemi_mac *mac = netdev_priv(netdev);
struct phy_device *phydev = mac->phydev;
if (!phydev)
return -EOPNOTSUPP;
return phy_ethtool_gset(phydev, cmd);
}
static int
pasemi_mac_ethtool_set_settings(struct net_device *netdev,
struct ethtool_cmd *cmd)
{
struct pasemi_mac *mac = netdev_priv(netdev);
struct phy_device *phydev = mac->phydev;
if (!phydev)
return -EOPNOTSUPP;
return phy_ethtool_sset(phydev, cmd);
}
static u32
pasemi_mac_ethtool_get_msglevel(struct net_device *netdev)
{
struct pasemi_mac *mac = netdev_priv(netdev);
return mac->msg_enable;
}
static void
pasemi_mac_ethtool_set_msglevel(struct net_device *netdev,
u32 level)
{
struct pasemi_mac *mac = netdev_priv(netdev);
mac->msg_enable = level;
}
static void
pasemi_mac_ethtool_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ering)
{
struct pasemi_mac *mac = netdev_priv(netdev);
ering->tx_max_pending = TX_RING_SIZE/2;
ering->tx_pending = RING_USED(mac->tx)/2;
ering->rx_max_pending = RX_RING_SIZE/4;
ering->rx_pending = RING_USED(mac->rx)/4;
}
static int pasemi_mac_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(ethtool_stats_keys);
default:
return -EOPNOTSUPP;
}
}
static void pasemi_mac_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct pasemi_mac *mac = netdev_priv(netdev);
int i;
data[0] = pasemi_read_dma_reg(PAS_DMA_RXINT_RCMDSTA(mac->dma_if))
>> PAS_DMA_RXINT_RCMDSTA_DROPS_S;
for (i = 0; i < 32; i++)
data[1+i] = pasemi_read_mac_reg(mac->dma_if, PAS_MAC_RMON(i));
}
static void pasemi_mac_get_strings(struct net_device *netdev, u32 stringset,
u8 *data)
{
memcpy(data, ethtool_stats_keys, sizeof(ethtool_stats_keys));
}
