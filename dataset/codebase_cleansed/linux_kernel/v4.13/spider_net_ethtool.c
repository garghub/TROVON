static int
spider_net_ethtool_get_link_ksettings(struct net_device *netdev,
struct ethtool_link_ksettings *cmd)
{
struct spider_net_card *card;
card = netdev_priv(netdev);
ethtool_link_ksettings_zero_link_mode(cmd, supported);
ethtool_link_ksettings_add_link_mode(cmd, supported, 1000baseT_Full);
ethtool_link_ksettings_add_link_mode(cmd, supported, FIBRE);
ethtool_link_ksettings_zero_link_mode(cmd, advertising);
ethtool_link_ksettings_add_link_mode(cmd, advertising, 1000baseT_Full);
ethtool_link_ksettings_add_link_mode(cmd, advertising, FIBRE);
cmd->base.port = PORT_FIBRE;
cmd->base.speed = card->phy.speed;
cmd->base.duplex = DUPLEX_FULL;
return 0;
}
static void
spider_net_ethtool_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct spider_net_card *card;
card = netdev_priv(netdev);
strlcpy(drvinfo->driver, spider_net_driver_name,
sizeof(drvinfo->driver));
strlcpy(drvinfo->version, VERSION, sizeof(drvinfo->version));
strlcpy(drvinfo->fw_version, "no information",
sizeof(drvinfo->fw_version));
strlcpy(drvinfo->bus_info, pci_name(card->pdev),
sizeof(drvinfo->bus_info));
}
static void
spider_net_ethtool_get_wol(struct net_device *netdev,
struct ethtool_wolinfo *wolinfo)
{
wolinfo->supported = 0;
wolinfo->wolopts = 0;
}
static u32
spider_net_ethtool_get_msglevel(struct net_device *netdev)
{
struct spider_net_card *card;
card = netdev_priv(netdev);
return card->msg_enable;
}
static void
spider_net_ethtool_set_msglevel(struct net_device *netdev,
u32 level)
{
struct spider_net_card *card;
card = netdev_priv(netdev);
card->msg_enable = level;
}
static int
spider_net_ethtool_nway_reset(struct net_device *netdev)
{
if (netif_running(netdev)) {
spider_net_stop(netdev);
spider_net_open(netdev);
}
return 0;
}
static void
spider_net_ethtool_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ering)
{
struct spider_net_card *card = netdev_priv(netdev);
ering->tx_max_pending = SPIDER_NET_TX_DESCRIPTORS_MAX;
ering->tx_pending = card->tx_chain.num_desc;
ering->rx_max_pending = SPIDER_NET_RX_DESCRIPTORS_MAX;
ering->rx_pending = card->rx_chain.num_desc;
}
static int spider_net_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(ethtool_stats_keys);
default:
return -EOPNOTSUPP;
}
}
static void spider_net_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct spider_net_card *card = netdev_priv(netdev);
data[0] = netdev->stats.tx_packets;
data[1] = netdev->stats.tx_bytes;
data[2] = netdev->stats.rx_packets;
data[3] = netdev->stats.rx_bytes;
data[4] = netdev->stats.tx_errors;
data[5] = netdev->stats.tx_dropped;
data[6] = netdev->stats.rx_dropped;
data[7] = card->spider_stats.rx_desc_error;
data[8] = card->spider_stats.tx_timeouts;
data[9] = card->spider_stats.alloc_rx_skb_error;
data[10] = card->spider_stats.rx_iommu_map_error;
data[11] = card->spider_stats.tx_iommu_map_error;
data[12] = card->spider_stats.rx_desc_unk_state;
}
static void spider_net_get_strings(struct net_device *netdev, u32 stringset,
u8 *data)
{
memcpy(data, ethtool_stats_keys, sizeof(ethtool_stats_keys));
}
