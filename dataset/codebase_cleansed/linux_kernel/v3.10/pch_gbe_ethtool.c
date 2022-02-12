static int pch_gbe_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
int ret;
ret = mii_ethtool_gset(&adapter->mii, ecmd);
ecmd->supported &= ~(SUPPORTED_TP | SUPPORTED_1000baseT_Half);
ecmd->advertising &= ~(ADVERTISED_TP | ADVERTISED_1000baseT_Half);
if (!netif_carrier_ok(adapter->netdev))
ethtool_cmd_speed_set(ecmd, -1);
return ret;
}
static int pch_gbe_set_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
struct pch_gbe_hw *hw = &adapter->hw;
u32 speed = ethtool_cmd_speed(ecmd);
int ret;
pch_gbe_hal_write_phy_reg(hw, MII_BMCR, BMCR_RESET);
if (speed == UINT_MAX) {
speed = SPEED_1000;
ecmd->duplex = DUPLEX_FULL;
}
ret = mii_ethtool_sset(&adapter->mii, ecmd);
if (ret) {
pr_err("Error: mii_ethtool_sset\n");
return ret;
}
hw->mac.link_speed = speed;
hw->mac.link_duplex = ecmd->duplex;
hw->phy.autoneg_advertised = ecmd->advertising;
hw->mac.autoneg = ecmd->autoneg;
if (netif_running(adapter->netdev)) {
pch_gbe_down(adapter);
ret = pch_gbe_up(adapter);
} else {
pch_gbe_reset(adapter);
}
return ret;
}
static int pch_gbe_get_regs_len(struct net_device *netdev)
{
return PCH_GBE_REGS_LEN * (int)sizeof(u32);
}
static void pch_gbe_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
strlcpy(drvinfo->driver, KBUILD_MODNAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, pch_driver_version, sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, pci_name(adapter->pdev),
sizeof(drvinfo->bus_info));
drvinfo->regdump_len = pch_gbe_get_regs_len(netdev);
}
static void pch_gbe_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *p)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
struct pch_gbe_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
u32 *regs_buff = p;
u16 i, tmp;
regs->version = 0x1000000 | (__u32)pdev->revision << 16 | pdev->device;
for (i = 0; i < PCH_GBE_MAC_REGS_LEN; i++)
*regs_buff++ = ioread32(&hw->reg->INT_ST + i);
for (i = 0; i < PCH_GBE_PHY_REGS_LEN; i++) {
pch_gbe_hal_read_phy_reg(&adapter->hw, i, &tmp);
*regs_buff++ = tmp;
}
}
static void pch_gbe_get_wol(struct net_device *netdev,
struct ethtool_wolinfo *wol)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
wol->supported = WAKE_UCAST | WAKE_MCAST | WAKE_BCAST | WAKE_MAGIC;
wol->wolopts = 0;
if ((adapter->wake_up_evt & PCH_GBE_WLC_IND))
wol->wolopts |= WAKE_UCAST;
if ((adapter->wake_up_evt & PCH_GBE_WLC_MLT))
wol->wolopts |= WAKE_MCAST;
if ((adapter->wake_up_evt & PCH_GBE_WLC_BR))
wol->wolopts |= WAKE_BCAST;
if ((adapter->wake_up_evt & PCH_GBE_WLC_MP))
wol->wolopts |= WAKE_MAGIC;
}
static int pch_gbe_set_wol(struct net_device *netdev,
struct ethtool_wolinfo *wol)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
if ((wol->wolopts & (WAKE_PHY | WAKE_ARP | WAKE_MAGICSECURE)))
return -EOPNOTSUPP;
adapter->wake_up_evt = 0;
if ((wol->wolopts & WAKE_UCAST))
adapter->wake_up_evt |= PCH_GBE_WLC_IND;
if ((wol->wolopts & WAKE_MCAST))
adapter->wake_up_evt |= PCH_GBE_WLC_MLT;
if ((wol->wolopts & WAKE_BCAST))
adapter->wake_up_evt |= PCH_GBE_WLC_BR;
if ((wol->wolopts & WAKE_MAGIC))
adapter->wake_up_evt |= PCH_GBE_WLC_MP;
return 0;
}
static int pch_gbe_nway_reset(struct net_device *netdev)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
return mii_nway_restart(&adapter->mii);
}
static void pch_gbe_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
struct pch_gbe_tx_ring *txdr = adapter->tx_ring;
struct pch_gbe_rx_ring *rxdr = adapter->rx_ring;
ring->rx_max_pending = PCH_GBE_MAX_RXD;
ring->tx_max_pending = PCH_GBE_MAX_TXD;
ring->rx_pending = rxdr->count;
ring->tx_pending = txdr->count;
}
static int pch_gbe_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
struct pch_gbe_tx_ring *txdr, *tx_old;
struct pch_gbe_rx_ring *rxdr, *rx_old;
int tx_ring_size, rx_ring_size;
int err = 0;
if ((ring->rx_mini_pending) || (ring->rx_jumbo_pending))
return -EINVAL;
tx_ring_size = (int)sizeof(struct pch_gbe_tx_ring);
rx_ring_size = (int)sizeof(struct pch_gbe_rx_ring);
if ((netif_running(adapter->netdev)))
pch_gbe_down(adapter);
tx_old = adapter->tx_ring;
rx_old = adapter->rx_ring;
txdr = kzalloc(tx_ring_size, GFP_KERNEL);
if (!txdr) {
err = -ENOMEM;
goto err_alloc_tx;
}
rxdr = kzalloc(rx_ring_size, GFP_KERNEL);
if (!rxdr) {
err = -ENOMEM;
goto err_alloc_rx;
}
adapter->tx_ring = txdr;
adapter->rx_ring = rxdr;
rxdr->count =
clamp_val(ring->rx_pending, PCH_GBE_MIN_RXD, PCH_GBE_MAX_RXD);
rxdr->count = roundup(rxdr->count, PCH_GBE_RX_DESC_MULTIPLE);
txdr->count =
clamp_val(ring->tx_pending, PCH_GBE_MIN_RXD, PCH_GBE_MAX_RXD);
txdr->count = roundup(txdr->count, PCH_GBE_TX_DESC_MULTIPLE);
if ((netif_running(adapter->netdev))) {
err = pch_gbe_setup_rx_resources(adapter, adapter->rx_ring);
if (err)
goto err_setup_rx;
err = pch_gbe_setup_tx_resources(adapter, adapter->tx_ring);
if (err)
goto err_setup_tx;
#ifdef RINGFREE
adapter->rx_ring = rx_old;
adapter->tx_ring = tx_old;
pch_gbe_free_rx_resources(adapter, adapter->rx_ring);
pch_gbe_free_tx_resources(adapter, adapter->tx_ring);
kfree(tx_old);
kfree(rx_old);
adapter->rx_ring = rxdr;
adapter->tx_ring = txdr;
#else
pch_gbe_free_rx_resources(adapter, rx_old);
pch_gbe_free_tx_resources(adapter, tx_old);
kfree(tx_old);
kfree(rx_old);
adapter->rx_ring = rxdr;
adapter->tx_ring = txdr;
#endif
err = pch_gbe_up(adapter);
}
return err;
err_setup_tx:
pch_gbe_free_rx_resources(adapter, adapter->rx_ring);
err_setup_rx:
adapter->rx_ring = rx_old;
adapter->tx_ring = tx_old;
kfree(rxdr);
err_alloc_rx:
kfree(txdr);
err_alloc_tx:
if (netif_running(adapter->netdev))
pch_gbe_up(adapter);
return err;
}
static void pch_gbe_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
struct pch_gbe_hw *hw = &adapter->hw;
pause->autoneg =
((hw->mac.fc_autoneg) ? AUTONEG_ENABLE : AUTONEG_DISABLE);
if (hw->mac.fc == PCH_GBE_FC_RX_PAUSE) {
pause->rx_pause = 1;
} else if (hw->mac.fc == PCH_GBE_FC_TX_PAUSE) {
pause->tx_pause = 1;
} else if (hw->mac.fc == PCH_GBE_FC_FULL) {
pause->rx_pause = 1;
pause->tx_pause = 1;
}
}
static int pch_gbe_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
struct pch_gbe_hw *hw = &adapter->hw;
int ret = 0;
hw->mac.fc_autoneg = pause->autoneg;
if ((pause->rx_pause) && (pause->tx_pause))
hw->mac.fc = PCH_GBE_FC_FULL;
else if ((pause->rx_pause) && (!pause->tx_pause))
hw->mac.fc = PCH_GBE_FC_RX_PAUSE;
else if ((!pause->rx_pause) && (pause->tx_pause))
hw->mac.fc = PCH_GBE_FC_TX_PAUSE;
else if ((!pause->rx_pause) && (!pause->tx_pause))
hw->mac.fc = PCH_GBE_FC_NONE;
if (hw->mac.fc_autoneg == AUTONEG_ENABLE) {
if ((netif_running(adapter->netdev))) {
pch_gbe_down(adapter);
ret = pch_gbe_up(adapter);
} else {
pch_gbe_reset(adapter);
}
} else {
ret = pch_gbe_mac_force_mac_fc(hw);
}
return ret;
}
static void pch_gbe_get_strings(struct net_device *netdev, u32 stringset,
u8 *data)
{
u8 *p = data;
int i;
switch (stringset) {
case (u32) ETH_SS_STATS:
for (i = 0; i < PCH_GBE_GLOBAL_STATS_LEN; i++) {
memcpy(p, pch_gbe_gstrings_stats[i].string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
break;
}
}
static void pch_gbe_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct pch_gbe_adapter *adapter = netdev_priv(netdev);
int i;
const struct pch_gbe_stats *gstats = pch_gbe_gstrings_stats;
char *hw_stats = (char *)&adapter->stats;
pch_gbe_update_stats(adapter);
for (i = 0; i < PCH_GBE_GLOBAL_STATS_LEN; i++) {
char *p = hw_stats + gstats->offset;
data[i] = gstats->size == sizeof(u64) ? *(u64 *)p:(*(u32 *)p);
gstats++;
}
}
static int pch_gbe_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return PCH_GBE_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
void pch_gbe_set_ethtool_ops(struct net_device *netdev)
{
SET_ETHTOOL_OPS(netdev, &pch_gbe_ethtool_ops);
}
