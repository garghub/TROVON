static int
uec_get_settings(struct net_device *netdev, struct ethtool_cmd *ecmd)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
struct phy_device *phydev = ugeth->phydev;
struct ucc_geth_info *ug_info = ugeth->ug_info;
if (!phydev)
return -ENODEV;
ecmd->maxtxpkt = 1;
ecmd->maxrxpkt = ug_info->interruptcoalescingmaxvalue[0];
return phy_ethtool_gset(phydev, ecmd);
}
static int
uec_set_settings(struct net_device *netdev, struct ethtool_cmd *ecmd)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
struct phy_device *phydev = ugeth->phydev;
if (!phydev)
return -ENODEV;
return phy_ethtool_sset(phydev, ecmd);
}
static void
uec_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
pause->autoneg = ugeth->phydev->autoneg;
if (ugeth->ug_info->receiveFlowControl)
pause->rx_pause = 1;
if (ugeth->ug_info->transmitFlowControl)
pause->tx_pause = 1;
}
static int
uec_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
int ret = 0;
ugeth->ug_info->receiveFlowControl = pause->rx_pause;
ugeth->ug_info->transmitFlowControl = pause->tx_pause;
if (ugeth->phydev->autoneg) {
if (netif_running(netdev)) {
printk(KERN_INFO
"Please re-open the interface.\n");
}
} else {
struct ucc_geth_info *ug_info = ugeth->ug_info;
ret = init_flow_control_params(ug_info->aufc,
ug_info->receiveFlowControl,
ug_info->transmitFlowControl,
ug_info->pausePeriod,
ug_info->extensionField,
&ugeth->uccf->uf_regs->upsmr,
&ugeth->ug_regs->uempr,
&ugeth->ug_regs->maccfg1);
}
return ret;
}
static uint32_t
uec_get_msglevel(struct net_device *netdev)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
return ugeth->msg_enable;
}
static void
uec_set_msglevel(struct net_device *netdev, uint32_t data)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
ugeth->msg_enable = data;
}
static int
uec_get_regs_len(struct net_device *netdev)
{
return sizeof(struct ucc_geth);
}
static void
uec_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *p)
{
int i;
struct ucc_geth_private *ugeth = netdev_priv(netdev);
u32 __iomem *ug_regs = (u32 __iomem *)ugeth->ug_regs;
u32 *buff = p;
for (i = 0; i < sizeof(struct ucc_geth) / sizeof(u32); i++)
buff[i] = in_be32(&ug_regs[i]);
}
static void
uec_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
struct ucc_geth_info *ug_info = ugeth->ug_info;
int queue = 0;
ring->rx_max_pending = UCC_GETH_BD_RING_SIZE_MAX;
ring->rx_mini_max_pending = UCC_GETH_BD_RING_SIZE_MAX;
ring->rx_jumbo_max_pending = UCC_GETH_BD_RING_SIZE_MAX;
ring->tx_max_pending = UCC_GETH_BD_RING_SIZE_MAX;
ring->rx_pending = ug_info->bdRingLenRx[queue];
ring->rx_mini_pending = ug_info->bdRingLenRx[queue];
ring->rx_jumbo_pending = ug_info->bdRingLenRx[queue];
ring->tx_pending = ug_info->bdRingLenTx[queue];
}
static int
uec_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
struct ucc_geth_info *ug_info = ugeth->ug_info;
int queue = 0, ret = 0;
if (ring->rx_pending < UCC_GETH_RX_BD_RING_SIZE_MIN) {
printk("%s: RxBD ring size must be no smaller than %d.\n",
netdev->name, UCC_GETH_RX_BD_RING_SIZE_MIN);
return -EINVAL;
}
if (ring->rx_pending % UCC_GETH_RX_BD_RING_SIZE_ALIGNMENT) {
printk("%s: RxBD ring size must be multiple of %d.\n",
netdev->name, UCC_GETH_RX_BD_RING_SIZE_ALIGNMENT);
return -EINVAL;
}
if (ring->tx_pending < UCC_GETH_TX_BD_RING_SIZE_MIN) {
printk("%s: TxBD ring size must be no smaller than %d.\n",
netdev->name, UCC_GETH_TX_BD_RING_SIZE_MIN);
return -EINVAL;
}
ug_info->bdRingLenRx[queue] = ring->rx_pending;
ug_info->bdRingLenTx[queue] = ring->tx_pending;
if (netif_running(netdev)) {
printk(KERN_INFO
"Please re-open the interface.\n");
}
return ret;
}
static int uec_get_sset_count(struct net_device *netdev, int sset)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
u32 stats_mode = ugeth->ug_info->statisticsMode;
int len = 0;
switch (sset) {
case ETH_SS_STATS:
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_HARDWARE)
len += UEC_HW_STATS_LEN;
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_FIRMWARE_TX)
len += UEC_TX_FW_STATS_LEN;
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_FIRMWARE_RX)
len += UEC_RX_FW_STATS_LEN;
return len;
default:
return -EOPNOTSUPP;
}
}
static void uec_get_strings(struct net_device *netdev, u32 stringset, u8 *buf)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
u32 stats_mode = ugeth->ug_info->statisticsMode;
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_HARDWARE) {
memcpy(buf, hw_stat_gstrings, UEC_HW_STATS_LEN *
ETH_GSTRING_LEN);
buf += UEC_HW_STATS_LEN * ETH_GSTRING_LEN;
}
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_FIRMWARE_TX) {
memcpy(buf, tx_fw_stat_gstrings, UEC_TX_FW_STATS_LEN *
ETH_GSTRING_LEN);
buf += UEC_TX_FW_STATS_LEN * ETH_GSTRING_LEN;
}
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_FIRMWARE_RX)
memcpy(buf, rx_fw_stat_gstrings, UEC_RX_FW_STATS_LEN *
ETH_GSTRING_LEN);
}
static void uec_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, uint64_t *data)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
u32 stats_mode = ugeth->ug_info->statisticsMode;
u32 __iomem *base;
int i, j = 0;
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_HARDWARE) {
if (ugeth->ug_regs)
base = (u32 __iomem *)&ugeth->ug_regs->tx64;
else
base = NULL;
for (i = 0; i < UEC_HW_STATS_LEN; i++)
data[j++] = base ? in_be32(&base[i]) : 0;
}
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_FIRMWARE_TX) {
base = (u32 __iomem *)ugeth->p_tx_fw_statistics_pram;
for (i = 0; i < UEC_TX_FW_STATS_LEN; i++)
data[j++] = base ? in_be32(&base[i]) : 0;
}
if (stats_mode & UCC_GETH_STATISTICS_GATHERING_MODE_FIRMWARE_RX) {
base = (u32 __iomem *)ugeth->p_rx_fw_statistics_pram;
for (i = 0; i < UEC_RX_FW_STATS_LEN; i++)
data[j++] = base ? in_be32(&base[i]) : 0;
}
}
static int uec_nway_reset(struct net_device *netdev)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
return phy_start_aneg(ugeth->phydev);
}
static void
uec_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->driver, DRV_NAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, DRV_VERSION, sizeof(drvinfo->version));
strlcpy(drvinfo->fw_version, "N/A", sizeof(drvinfo->fw_version));
strlcpy(drvinfo->bus_info, "QUICC ENGINE", sizeof(drvinfo->bus_info));
drvinfo->eedump_len = 0;
drvinfo->regdump_len = uec_get_regs_len(netdev);
}
static void uec_get_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
struct phy_device *phydev = ugeth->phydev;
if (phydev && phydev->irq)
wol->supported |= WAKE_PHY;
if (qe_alive_during_sleep())
wol->supported |= WAKE_MAGIC;
wol->wolopts = ugeth->wol_en;
}
static int uec_set_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct ucc_geth_private *ugeth = netdev_priv(netdev);
struct phy_device *phydev = ugeth->phydev;
if (wol->wolopts & ~(WAKE_PHY | WAKE_MAGIC))
return -EINVAL;
else if (wol->wolopts & WAKE_PHY && (!phydev || !phydev->irq))
return -EINVAL;
else if (wol->wolopts & WAKE_MAGIC && !qe_alive_during_sleep())
return -EINVAL;
ugeth->wol_en = wol->wolopts;
device_set_wakeup_enable(&netdev->dev, ugeth->wol_en);
return 0;
}
void uec_set_ethtool_ops(struct net_device *netdev)
{
SET_ETHTOOL_OPS(netdev, &uec_ethtool_ops);
}
