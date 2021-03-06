void enic_intr_coal_set_rx(struct enic *enic, u32 timer)
{
int i;
int intr;
for (i = 0; i < enic->rq_count; i++) {
intr = enic_msix_rq_intr(enic, i);
vnic_intr_coalescing_timer_set(&enic->intr[intr], timer);
}
}
static int enic_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct enic *enic = netdev_priv(netdev);
ecmd->supported = (SUPPORTED_10000baseT_Full | SUPPORTED_FIBRE);
ecmd->advertising = (ADVERTISED_10000baseT_Full | ADVERTISED_FIBRE);
ecmd->port = PORT_FIBRE;
ecmd->transceiver = XCVR_EXTERNAL;
if (netif_carrier_ok(netdev)) {
ethtool_cmd_speed_set(ecmd, vnic_dev_port_speed(enic->vdev));
ecmd->duplex = DUPLEX_FULL;
} else {
ethtool_cmd_speed_set(ecmd, SPEED_UNKNOWN);
ecmd->duplex = DUPLEX_UNKNOWN;
}
ecmd->autoneg = AUTONEG_DISABLE;
return 0;
}
static void enic_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct enic *enic = netdev_priv(netdev);
struct vnic_devcmd_fw_info *fw_info;
enic_dev_fw_info(enic, &fw_info);
strlcpy(drvinfo->driver, DRV_NAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, DRV_VERSION, sizeof(drvinfo->version));
strlcpy(drvinfo->fw_version, fw_info->fw_version,
sizeof(drvinfo->fw_version));
strlcpy(drvinfo->bus_info, pci_name(enic->pdev),
sizeof(drvinfo->bus_info));
}
static void enic_get_strings(struct net_device *netdev, u32 stringset,
u8 *data)
{
unsigned int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < enic_n_tx_stats; i++) {
memcpy(data, enic_tx_stats[i].name, ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
for (i = 0; i < enic_n_rx_stats; i++) {
memcpy(data, enic_rx_stats[i].name, ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
break;
}
}
static int enic_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return enic_n_tx_stats + enic_n_rx_stats;
default:
return -EOPNOTSUPP;
}
}
static void enic_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct enic *enic = netdev_priv(netdev);
struct vnic_stats *vstats;
unsigned int i;
enic_dev_stats_dump(enic, &vstats);
for (i = 0; i < enic_n_tx_stats; i++)
*(data++) = ((u64 *)&vstats->tx)[enic_tx_stats[i].index];
for (i = 0; i < enic_n_rx_stats; i++)
*(data++) = ((u64 *)&vstats->rx)[enic_rx_stats[i].index];
}
static u32 enic_get_msglevel(struct net_device *netdev)
{
struct enic *enic = netdev_priv(netdev);
return enic->msg_enable;
}
static void enic_set_msglevel(struct net_device *netdev, u32 value)
{
struct enic *enic = netdev_priv(netdev);
enic->msg_enable = value;
}
static int enic_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ecmd)
{
struct enic *enic = netdev_priv(netdev);
struct enic_rx_coal *rxcoal = &enic->rx_coalesce_setting;
ecmd->tx_coalesce_usecs = enic->tx_coalesce_usecs;
ecmd->rx_coalesce_usecs = enic->rx_coalesce_usecs;
if (rxcoal->use_adaptive_rx_coalesce)
ecmd->use_adaptive_rx_coalesce = 1;
ecmd->rx_coalesce_usecs_low = rxcoal->small_pkt_range_start;
ecmd->rx_coalesce_usecs_high = rxcoal->range_end;
return 0;
}
static int enic_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ecmd)
{
struct enic *enic = netdev_priv(netdev);
u32 tx_coalesce_usecs;
u32 rx_coalesce_usecs;
u32 rx_coalesce_usecs_low;
u32 rx_coalesce_usecs_high;
u32 coalesce_usecs_max;
unsigned int i, intr;
struct enic_rx_coal *rxcoal = &enic->rx_coalesce_setting;
coalesce_usecs_max = vnic_dev_get_intr_coal_timer_max(enic->vdev);
tx_coalesce_usecs = min_t(u32, ecmd->tx_coalesce_usecs,
coalesce_usecs_max);
rx_coalesce_usecs = min_t(u32, ecmd->rx_coalesce_usecs,
coalesce_usecs_max);
rx_coalesce_usecs_low = min_t(u32, ecmd->rx_coalesce_usecs_low,
coalesce_usecs_max);
rx_coalesce_usecs_high = min_t(u32, ecmd->rx_coalesce_usecs_high,
coalesce_usecs_max);
switch (vnic_dev_get_intr_mode(enic->vdev)) {
case VNIC_DEV_INTR_MODE_INTX:
if (tx_coalesce_usecs != rx_coalesce_usecs)
return -EINVAL;
if (ecmd->use_adaptive_rx_coalesce ||
ecmd->rx_coalesce_usecs_low ||
ecmd->rx_coalesce_usecs_high)
return -EOPNOTSUPP;
intr = enic_legacy_io_intr();
vnic_intr_coalescing_timer_set(&enic->intr[intr],
tx_coalesce_usecs);
break;
case VNIC_DEV_INTR_MODE_MSI:
if (tx_coalesce_usecs != rx_coalesce_usecs)
return -EINVAL;
if (ecmd->use_adaptive_rx_coalesce ||
ecmd->rx_coalesce_usecs_low ||
ecmd->rx_coalesce_usecs_high)
return -EOPNOTSUPP;
vnic_intr_coalescing_timer_set(&enic->intr[0],
tx_coalesce_usecs);
break;
case VNIC_DEV_INTR_MODE_MSIX:
for (i = 0; i < enic->wq_count; i++) {
intr = enic_msix_wq_intr(enic, i);
vnic_intr_coalescing_timer_set(&enic->intr[intr],
tx_coalesce_usecs);
}
if (rxcoal->use_adaptive_rx_coalesce) {
if (!ecmd->use_adaptive_rx_coalesce) {
rxcoal->use_adaptive_rx_coalesce = 0;
enic_intr_coal_set_rx(enic, rx_coalesce_usecs);
}
} else {
if (ecmd->use_adaptive_rx_coalesce)
rxcoal->use_adaptive_rx_coalesce = 1;
else
enic_intr_coal_set_rx(enic, rx_coalesce_usecs);
}
if (ecmd->rx_coalesce_usecs_high) {
if (rx_coalesce_usecs_high <
(rx_coalesce_usecs_low + ENIC_AIC_LARGE_PKT_DIFF))
return -EINVAL;
rxcoal->range_end = rx_coalesce_usecs_high;
rxcoal->small_pkt_range_start = rx_coalesce_usecs_low;
rxcoal->large_pkt_range_start = rx_coalesce_usecs_low +
ENIC_AIC_LARGE_PKT_DIFF;
}
break;
default:
break;
}
enic->tx_coalesce_usecs = tx_coalesce_usecs;
enic->rx_coalesce_usecs = rx_coalesce_usecs;
return 0;
}
void enic_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &enic_ethtool_ops;
}
