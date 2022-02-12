static int ql_update_ring_coalescing(struct ql_adapter *qdev)
{
int i, status = 0;
struct rx_ring *rx_ring;
struct cqicb *cqicb;
if (!netif_running(qdev->ndev))
return status;
cqicb = (struct cqicb *)&qdev->rx_ring[qdev->rss_ring_count];
if (le16_to_cpu(cqicb->irq_delay) != qdev->tx_coalesce_usecs ||
le16_to_cpu(cqicb->pkt_delay) !=
qdev->tx_max_coalesced_frames) {
for (i = qdev->rss_ring_count; i < qdev->rx_ring_count; i++) {
rx_ring = &qdev->rx_ring[i];
cqicb = (struct cqicb *)rx_ring;
cqicb->irq_delay = cpu_to_le16(qdev->tx_coalesce_usecs);
cqicb->pkt_delay =
cpu_to_le16(qdev->tx_max_coalesced_frames);
cqicb->flags = FLAGS_LI;
status = ql_write_cfg(qdev, cqicb, sizeof(*cqicb),
CFG_LCQ, rx_ring->cq_id);
if (status) {
netif_err(qdev, ifup, qdev->ndev,
"Failed to load CQICB.\n");
goto exit;
}
}
}
cqicb = (struct cqicb *)&qdev->rx_ring[0];
if (le16_to_cpu(cqicb->irq_delay) != qdev->rx_coalesce_usecs ||
le16_to_cpu(cqicb->pkt_delay) !=
qdev->rx_max_coalesced_frames) {
for (i = 0; i < qdev->rss_ring_count; i++, rx_ring++) {
rx_ring = &qdev->rx_ring[i];
cqicb = (struct cqicb *)rx_ring;
cqicb->irq_delay = cpu_to_le16(qdev->rx_coalesce_usecs);
cqicb->pkt_delay =
cpu_to_le16(qdev->rx_max_coalesced_frames);
cqicb->flags = FLAGS_LI;
status = ql_write_cfg(qdev, cqicb, sizeof(*cqicb),
CFG_LCQ, rx_ring->cq_id);
if (status) {
netif_err(qdev, ifup, qdev->ndev,
"Failed to load CQICB.\n");
goto exit;
}
}
}
exit:
return status;
}
static void ql_update_stats(struct ql_adapter *qdev)
{
u32 i;
u64 data;
u64 *iter = &qdev->nic_stats.tx_pkts;
spin_lock(&qdev->stats_lock);
if (ql_sem_spinlock(qdev, qdev->xg_sem_mask)) {
netif_err(qdev, drv, qdev->ndev,
"Couldn't get xgmac sem.\n");
goto quit;
}
for (i = 0x200; i < 0x280; i += 8) {
if (ql_read_xgmac_reg64(qdev, i, &data)) {
netif_err(qdev, drv, qdev->ndev,
"Error reading status register 0x%.04x.\n",
i);
goto end;
} else
*iter = data;
iter++;
}
for (i = 0x300; i < 0x3d0; i += 8) {
if (ql_read_xgmac_reg64(qdev, i, &data)) {
netif_err(qdev, drv, qdev->ndev,
"Error reading status register 0x%.04x.\n",
i);
goto end;
} else
*iter = data;
iter++;
}
iter += QLGE_RCV_MAC_ERR_STATS;
for (i = 0x500; i < 0x540; i += 8) {
if (ql_read_xgmac_reg64(qdev, i, &data)) {
netif_err(qdev, drv, qdev->ndev,
"Error reading status register 0x%.04x.\n",
i);
goto end;
} else
*iter = data;
iter++;
}
for (i = 0x568; i < 0x5a8; i += 8) {
if (ql_read_xgmac_reg64(qdev, i, &data)) {
netif_err(qdev, drv, qdev->ndev,
"Error reading status register 0x%.04x.\n",
i);
goto end;
} else
*iter = data;
iter++;
}
if (ql_read_xgmac_reg64(qdev, 0x5b8, &data)) {
netif_err(qdev, drv, qdev->ndev,
"Error reading status register 0x%.04x.\n", i);
goto end;
} else
*iter = data;
end:
ql_sem_unlock(qdev, qdev->xg_sem_mask);
quit:
spin_unlock(&qdev->stats_lock);
QL_DUMP_STAT(qdev);
}
static void ql_get_strings(struct net_device *dev, u32 stringset, u8 *buf)
{
int index;
switch (stringset) {
case ETH_SS_TEST:
memcpy(buf, *ql_gstrings_test, QLGE_TEST_LEN * ETH_GSTRING_LEN);
break;
case ETH_SS_STATS:
for (index = 0; index < QLGE_STATS_LEN; index++) {
memcpy(buf + index * ETH_GSTRING_LEN,
ql_gstrings_stats[index].stat_string,
ETH_GSTRING_LEN);
}
break;
}
}
static int ql_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_TEST:
return QLGE_TEST_LEN;
case ETH_SS_STATS:
return QLGE_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void
ql_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *stats, u64 *data)
{
struct ql_adapter *qdev = netdev_priv(ndev);
int index, length;
length = QLGE_STATS_LEN;
ql_update_stats(qdev);
for (index = 0; index < length; index++) {
char *p = (char *)qdev +
ql_gstrings_stats[index].stat_offset;
*data++ = (ql_gstrings_stats[index].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : (*(u32 *)p);
}
}
static int ql_get_link_ksettings(struct net_device *ndev,
struct ethtool_link_ksettings *ecmd)
{
struct ql_adapter *qdev = netdev_priv(ndev);
u32 supported, advertising;
supported = SUPPORTED_10000baseT_Full;
advertising = ADVERTISED_10000baseT_Full;
if ((qdev->link_status & STS_LINK_TYPE_MASK) ==
STS_LINK_TYPE_10GBASET) {
supported |= (SUPPORTED_TP | SUPPORTED_Autoneg);
advertising |= (ADVERTISED_TP | ADVERTISED_Autoneg);
ecmd->base.port = PORT_TP;
ecmd->base.autoneg = AUTONEG_ENABLE;
} else {
supported |= SUPPORTED_FIBRE;
advertising |= ADVERTISED_FIBRE;
ecmd->base.port = PORT_FIBRE;
}
ecmd->base.speed = SPEED_10000;
ecmd->base.duplex = DUPLEX_FULL;
ethtool_convert_legacy_u32_to_link_mode(ecmd->link_modes.supported,
supported);
ethtool_convert_legacy_u32_to_link_mode(ecmd->link_modes.advertising,
advertising);
return 0;
}
static void ql_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *drvinfo)
{
struct ql_adapter *qdev = netdev_priv(ndev);
strlcpy(drvinfo->driver, qlge_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, qlge_driver_version,
sizeof(drvinfo->version));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"v%d.%d.%d",
(qdev->fw_rev_id & 0x00ff0000) >> 16,
(qdev->fw_rev_id & 0x0000ff00) >> 8,
(qdev->fw_rev_id & 0x000000ff));
strlcpy(drvinfo->bus_info, pci_name(qdev->pdev),
sizeof(drvinfo->bus_info));
}
static void ql_get_wol(struct net_device *ndev, struct ethtool_wolinfo *wol)
{
struct ql_adapter *qdev = netdev_priv(ndev);
unsigned short ssys_dev = qdev->pdev->subsystem_device;
if (ssys_dev == QLGE_MEZZ_SSYS_ID_068 ||
ssys_dev == QLGE_MEZZ_SSYS_ID_180) {
wol->supported = WAKE_MAGIC;
wol->wolopts = qdev->wol;
}
}
static int ql_set_wol(struct net_device *ndev, struct ethtool_wolinfo *wol)
{
struct ql_adapter *qdev = netdev_priv(ndev);
unsigned short ssys_dev = qdev->pdev->subsystem_device;
if (ssys_dev != QLGE_MEZZ_SSYS_ID_068 &&
ssys_dev != QLGE_MEZZ_SSYS_ID_180) {
netif_info(qdev, drv, qdev->ndev,
"WOL is only supported for mezz card\n");
return -EOPNOTSUPP;
}
if (wol->wolopts & ~WAKE_MAGIC)
return -EINVAL;
qdev->wol = wol->wolopts;
netif_info(qdev, drv, qdev->ndev, "Set wol option 0x%x\n", qdev->wol);
return 0;
}
static int ql_set_phys_id(struct net_device *ndev,
enum ethtool_phys_id_state state)
{
struct ql_adapter *qdev = netdev_priv(ndev);
switch (state) {
case ETHTOOL_ID_ACTIVE:
if (ql_mb_get_led_cfg(qdev))
return -EIO;
ql_mb_set_led_cfg(qdev, QL_LED_BLINK);
return 0;
case ETHTOOL_ID_INACTIVE:
if (ql_mb_set_led_cfg(qdev, qdev->led_config))
return -EIO;
return 0;
default:
return -EINVAL;
}
}
static int ql_start_loopback(struct ql_adapter *qdev)
{
if (netif_carrier_ok(qdev->ndev)) {
set_bit(QL_LB_LINK_UP, &qdev->flags);
netif_carrier_off(qdev->ndev);
} else
clear_bit(QL_LB_LINK_UP, &qdev->flags);
qdev->link_config |= CFG_LOOPBACK_PCS;
return ql_mb_set_port_cfg(qdev);
}
static void ql_stop_loopback(struct ql_adapter *qdev)
{
qdev->link_config &= ~CFG_LOOPBACK_PCS;
ql_mb_set_port_cfg(qdev);
if (test_bit(QL_LB_LINK_UP, &qdev->flags)) {
netif_carrier_on(qdev->ndev);
clear_bit(QL_LB_LINK_UP, &qdev->flags);
}
}
static void ql_create_lb_frame(struct sk_buff *skb,
unsigned int frame_size)
{
memset(skb->data, 0xFF, frame_size);
frame_size &= ~1;
memset(&skb->data[frame_size / 2], 0xAA, frame_size / 2 - 1);
memset(&skb->data[frame_size / 2 + 10], 0xBE, 1);
memset(&skb->data[frame_size / 2 + 12], 0xAF, 1);
}
void ql_check_lb_frame(struct ql_adapter *qdev,
struct sk_buff *skb)
{
unsigned int frame_size = skb->len;
if ((*(skb->data + 3) == 0xFF) &&
(*(skb->data + frame_size / 2 + 10) == 0xBE) &&
(*(skb->data + frame_size / 2 + 12) == 0xAF)) {
atomic_dec(&qdev->lb_count);
return;
}
}
static int ql_run_loopback_test(struct ql_adapter *qdev)
{
int i;
netdev_tx_t rc;
struct sk_buff *skb;
unsigned int size = SMALL_BUF_MAP_SIZE;
for (i = 0; i < 64; i++) {
skb = netdev_alloc_skb(qdev->ndev, size);
if (!skb)
return -ENOMEM;
skb->queue_mapping = 0;
skb_put(skb, size);
ql_create_lb_frame(skb, size);
rc = ql_lb_send(skb, qdev->ndev);
if (rc != NETDEV_TX_OK)
return -EPIPE;
atomic_inc(&qdev->lb_count);
}
msleep(2);
ql_clean_lb_rx_ring(&qdev->rx_ring[0], 128);
return atomic_read(&qdev->lb_count) ? -EIO : 0;
}
static int ql_loopback_test(struct ql_adapter *qdev, u64 *data)
{
*data = ql_start_loopback(qdev);
if (*data)
goto out;
*data = ql_run_loopback_test(qdev);
out:
ql_stop_loopback(qdev);
return *data;
}
static void ql_self_test(struct net_device *ndev,
struct ethtool_test *eth_test, u64 *data)
{
struct ql_adapter *qdev = netdev_priv(ndev);
memset(data, 0, sizeof(u64) * QLGE_TEST_LEN);
if (netif_running(ndev)) {
set_bit(QL_SELFTEST, &qdev->flags);
if (eth_test->flags == ETH_TEST_FL_OFFLINE) {
if (ql_loopback_test(qdev, &data[0]))
eth_test->flags |= ETH_TEST_FL_FAILED;
} else {
data[0] = 0;
}
clear_bit(QL_SELFTEST, &qdev->flags);
msleep_interruptible(4 * 1000);
} else {
netif_err(qdev, drv, qdev->ndev,
"is down, Loopback test will fail.\n");
eth_test->flags |= ETH_TEST_FL_FAILED;
}
}
static int ql_get_regs_len(struct net_device *ndev)
{
struct ql_adapter *qdev = netdev_priv(ndev);
if (!test_bit(QL_FRC_COREDUMP, &qdev->flags))
return sizeof(struct ql_mpi_coredump);
else
return sizeof(struct ql_reg_dump);
}
static void ql_get_regs(struct net_device *ndev,
struct ethtool_regs *regs, void *p)
{
struct ql_adapter *qdev = netdev_priv(ndev);
ql_get_dump(qdev, p);
qdev->core_is_dumped = 0;
if (!test_bit(QL_FRC_COREDUMP, &qdev->flags))
regs->len = sizeof(struct ql_mpi_coredump);
else
regs->len = sizeof(struct ql_reg_dump);
}
static int ql_get_coalesce(struct net_device *dev, struct ethtool_coalesce *c)
{
struct ql_adapter *qdev = netdev_priv(dev);
c->rx_coalesce_usecs = qdev->rx_coalesce_usecs;
c->tx_coalesce_usecs = qdev->tx_coalesce_usecs;
c->rx_max_coalesced_frames = qdev->rx_max_coalesced_frames;
c->tx_max_coalesced_frames = qdev->tx_max_coalesced_frames;
return 0;
}
static int ql_set_coalesce(struct net_device *ndev, struct ethtool_coalesce *c)
{
struct ql_adapter *qdev = netdev_priv(ndev);
if (c->rx_coalesce_usecs > qdev->rx_ring_size / 2)
return -EINVAL;
if (c->rx_max_coalesced_frames > MAX_INTER_FRAME_WAIT)
return -EINVAL;
if (c->tx_coalesce_usecs > qdev->tx_ring_size / 2)
return -EINVAL;
if (c->tx_max_coalesced_frames > MAX_INTER_FRAME_WAIT)
return -EINVAL;
if (qdev->rx_coalesce_usecs == c->rx_coalesce_usecs &&
qdev->tx_coalesce_usecs == c->tx_coalesce_usecs &&
qdev->rx_max_coalesced_frames == c->rx_max_coalesced_frames &&
qdev->tx_max_coalesced_frames == c->tx_max_coalesced_frames)
return 0;
qdev->rx_coalesce_usecs = c->rx_coalesce_usecs;
qdev->tx_coalesce_usecs = c->tx_coalesce_usecs;
qdev->rx_max_coalesced_frames = c->rx_max_coalesced_frames;
qdev->tx_max_coalesced_frames = c->tx_max_coalesced_frames;
return ql_update_ring_coalescing(qdev);
}
static void ql_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ql_adapter *qdev = netdev_priv(netdev);
ql_mb_get_port_cfg(qdev);
if (qdev->link_config & CFG_PAUSE_STD) {
pause->rx_pause = 1;
pause->tx_pause = 1;
}
}
static int ql_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct ql_adapter *qdev = netdev_priv(netdev);
int status = 0;
if ((pause->rx_pause) && (pause->tx_pause))
qdev->link_config |= CFG_PAUSE_STD;
else if (!pause->rx_pause && !pause->tx_pause)
qdev->link_config &= ~CFG_PAUSE_STD;
else
return -EINVAL;
status = ql_mb_set_port_cfg(qdev);
return status;
}
static u32 ql_get_msglevel(struct net_device *ndev)
{
struct ql_adapter *qdev = netdev_priv(ndev);
return qdev->msg_enable;
}
static void ql_set_msglevel(struct net_device *ndev, u32 value)
{
struct ql_adapter *qdev = netdev_priv(ndev);
qdev->msg_enable = value;
}
