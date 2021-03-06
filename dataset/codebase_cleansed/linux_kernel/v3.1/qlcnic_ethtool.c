static int qlcnic_get_regs_len(struct net_device *dev)
{
return sizeof(diag_registers) + QLCNIC_RING_REGS_LEN +
QLCNIC_DEV_INFO_SIZE + 1;
}
static int qlcnic_get_eeprom_len(struct net_device *dev)
{
return QLCNIC_FLASH_TOTAL_SIZE;
}
static void
qlcnic_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *drvinfo)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
u32 fw_major, fw_minor, fw_build;
fw_major = QLCRD32(adapter, QLCNIC_FW_VERSION_MAJOR);
fw_minor = QLCRD32(adapter, QLCNIC_FW_VERSION_MINOR);
fw_build = QLCRD32(adapter, QLCNIC_FW_VERSION_SUB);
sprintf(drvinfo->fw_version, "%d.%d.%d", fw_major, fw_minor, fw_build);
strlcpy(drvinfo->bus_info, pci_name(adapter->pdev), 32);
strlcpy(drvinfo->driver, qlcnic_driver_name, 32);
strlcpy(drvinfo->version, QLCNIC_LINUX_VERSIONID, 32);
}
static int
qlcnic_get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
int check_sfp_module = 0;
u16 pcifn = adapter->ahw->pci_func;
if (adapter->ahw->port_type == QLCNIC_GBE) {
ecmd->supported = (SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full |
SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full);
ecmd->advertising = (ADVERTISED_100baseT_Half |
ADVERTISED_100baseT_Full |
ADVERTISED_1000baseT_Half |
ADVERTISED_1000baseT_Full);
ethtool_cmd_speed_set(ecmd, adapter->link_speed);
ecmd->duplex = adapter->link_duplex;
ecmd->autoneg = adapter->link_autoneg;
} else if (adapter->ahw->port_type == QLCNIC_XGBE) {
u32 val;
val = QLCRD32(adapter, QLCNIC_PORT_MODE_ADDR);
if (val == QLCNIC_PORT_MODE_802_3_AP) {
ecmd->supported = SUPPORTED_1000baseT_Full;
ecmd->advertising = ADVERTISED_1000baseT_Full;
} else {
ecmd->supported = SUPPORTED_10000baseT_Full;
ecmd->advertising = ADVERTISED_10000baseT_Full;
}
if (netif_running(dev) && adapter->has_link_events) {
ethtool_cmd_speed_set(ecmd, adapter->link_speed);
ecmd->autoneg = adapter->link_autoneg;
ecmd->duplex = adapter->link_duplex;
goto skip;
}
val = QLCRD32(adapter, P3P_LINK_SPEED_REG(pcifn));
ethtool_cmd_speed_set(ecmd, P3P_LINK_SPEED_MHZ *
P3P_LINK_SPEED_VAL(pcifn, val));
ecmd->duplex = DUPLEX_FULL;
ecmd->autoneg = AUTONEG_DISABLE;
} else
return -EIO;
skip:
ecmd->phy_address = adapter->physical_port;
ecmd->transceiver = XCVR_EXTERNAL;
switch (adapter->ahw->board_type) {
case QLCNIC_BRDTYPE_P3P_REF_QG:
case QLCNIC_BRDTYPE_P3P_4_GB:
case QLCNIC_BRDTYPE_P3P_4_GB_MM:
ecmd->supported |= SUPPORTED_Autoneg;
ecmd->advertising |= ADVERTISED_Autoneg;
case QLCNIC_BRDTYPE_P3P_10G_CX4:
case QLCNIC_BRDTYPE_P3P_10G_CX4_LP:
case QLCNIC_BRDTYPE_P3P_10000_BASE_T:
ecmd->supported |= SUPPORTED_TP;
ecmd->advertising |= ADVERTISED_TP;
ecmd->port = PORT_TP;
ecmd->autoneg = adapter->link_autoneg;
break;
case QLCNIC_BRDTYPE_P3P_IMEZ:
case QLCNIC_BRDTYPE_P3P_XG_LOM:
case QLCNIC_BRDTYPE_P3P_HMEZ:
ecmd->supported |= SUPPORTED_MII;
ecmd->advertising |= ADVERTISED_MII;
ecmd->port = PORT_MII;
ecmd->autoneg = AUTONEG_DISABLE;
break;
case QLCNIC_BRDTYPE_P3P_10G_SFP_PLUS:
case QLCNIC_BRDTYPE_P3P_10G_SFP_CT:
case QLCNIC_BRDTYPE_P3P_10G_SFP_QT:
ecmd->advertising |= ADVERTISED_TP;
ecmd->supported |= SUPPORTED_TP;
check_sfp_module = netif_running(dev) &&
adapter->has_link_events;
case QLCNIC_BRDTYPE_P3P_10G_XFP:
ecmd->supported |= SUPPORTED_FIBRE;
ecmd->advertising |= ADVERTISED_FIBRE;
ecmd->port = PORT_FIBRE;
ecmd->autoneg = AUTONEG_DISABLE;
break;
case QLCNIC_BRDTYPE_P3P_10G_TP:
if (adapter->ahw->port_type == QLCNIC_XGBE) {
ecmd->autoneg = AUTONEG_DISABLE;
ecmd->supported |= (SUPPORTED_FIBRE | SUPPORTED_TP);
ecmd->advertising |=
(ADVERTISED_FIBRE | ADVERTISED_TP);
ecmd->port = PORT_FIBRE;
check_sfp_module = netif_running(dev) &&
adapter->has_link_events;
} else {
ecmd->autoneg = AUTONEG_ENABLE;
ecmd->supported |= (SUPPORTED_TP | SUPPORTED_Autoneg);
ecmd->advertising |=
(ADVERTISED_TP | ADVERTISED_Autoneg);
ecmd->port = PORT_TP;
}
break;
default:
dev_err(&adapter->pdev->dev, "Unsupported board model %d\n",
adapter->ahw->board_type);
return -EIO;
}
if (check_sfp_module) {
switch (adapter->module_type) {
case LINKEVENT_MODULE_OPTICAL_UNKNOWN:
case LINKEVENT_MODULE_OPTICAL_SRLR:
case LINKEVENT_MODULE_OPTICAL_LRM:
case LINKEVENT_MODULE_OPTICAL_SFP_1G:
ecmd->port = PORT_FIBRE;
break;
case LINKEVENT_MODULE_TWINAX_UNSUPPORTED_CABLE:
case LINKEVENT_MODULE_TWINAX_UNSUPPORTED_CABLELEN:
case LINKEVENT_MODULE_TWINAX:
ecmd->port = PORT_TP;
break;
default:
ecmd->port = PORT_OTHER;
}
}
return 0;
}
static int
qlcnic_set_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
u32 config = 0;
u32 ret = 0;
struct qlcnic_adapter *adapter = netdev_priv(dev);
if (adapter->ahw->port_type != QLCNIC_GBE)
return -EOPNOTSUPP;
if (ecmd->duplex)
config |= 0x1;
if (ecmd->autoneg)
config |= 0x2;
switch (ethtool_cmd_speed(ecmd)) {
case SPEED_10:
config |= (0 << 8);
break;
case SPEED_100:
config |= (1 << 8);
break;
case SPEED_1000:
config |= (10 << 8);
break;
default:
return -EIO;
}
ret = qlcnic_fw_cmd_set_port(adapter, config);
if (ret == QLCNIC_RCODE_NOT_SUPPORTED)
return -EOPNOTSUPP;
else if (ret)
return -EIO;
adapter->link_speed = ethtool_cmd_speed(ecmd);
adapter->link_duplex = ecmd->duplex;
adapter->link_autoneg = ecmd->autoneg;
if (!netif_running(dev))
return 0;
dev->netdev_ops->ndo_stop(dev);
return dev->netdev_ops->ndo_open(dev);
}
static void
qlcnic_get_regs(struct net_device *dev, struct ethtool_regs *regs, void *p)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
struct qlcnic_recv_context *recv_ctx = adapter->recv_ctx;
struct qlcnic_host_sds_ring *sds_ring;
u32 *regs_buff = p;
int ring, i = 0, j = 0;
memset(p, 0, qlcnic_get_regs_len(dev));
regs->version = (QLCNIC_ETHTOOL_REGS_VER << 24) |
(adapter->ahw->revision_id << 16) | (adapter->pdev)->device;
regs_buff[0] = (0xcafe0000 | (QLCNIC_DEV_INFO_SIZE & 0xffff));
regs_buff[1] = QLCNIC_MGMT_API_VERSION;
for (i = QLCNIC_DEV_INFO_SIZE + 1; diag_registers[j] != -1; j++, i++)
regs_buff[i] = QLCRD32(adapter, diag_registers[j]);
if (!test_bit(__QLCNIC_DEV_UP, &adapter->state))
return;
regs_buff[i++] = 0xFFEFCDAB;
regs_buff[i++] = 1;
regs_buff[i++] = le32_to_cpu(*(adapter->tx_ring->hw_consumer));
regs_buff[i++] = readl(adapter->tx_ring->crb_cmd_producer);
regs_buff[i++] = 2;
regs_buff[i++] = readl(recv_ctx->rds_rings[0].crb_rcv_producer);
regs_buff[i++] = readl(recv_ctx->rds_rings[1].crb_rcv_producer);
regs_buff[i++] = adapter->max_sds_rings;
for (ring = 0; ring < adapter->max_sds_rings; ring++) {
sds_ring = &(recv_ctx->sds_rings[ring]);
regs_buff[i++] = readl(sds_ring->crb_sts_consumer);
}
}
static u32 qlcnic_test_link(struct net_device *dev)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
u32 val;
val = QLCRD32(adapter, CRB_XG_STATE_P3P);
val = XG_LINK_STATE_P3P(adapter->ahw->pci_func, val);
return (val == XG_LINK_UP_P3P) ? 0 : 1;
}
static int
qlcnic_get_eeprom(struct net_device *dev, struct ethtool_eeprom *eeprom,
u8 *bytes)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
int offset;
int ret;
if (eeprom->len == 0)
return -EINVAL;
eeprom->magic = (adapter->pdev)->vendor |
((adapter->pdev)->device << 16);
offset = eeprom->offset;
ret = qlcnic_rom_fast_read_words(adapter, offset, bytes,
eeprom->len);
if (ret < 0)
return ret;
return 0;
}
static void
qlcnic_get_ringparam(struct net_device *dev,
struct ethtool_ringparam *ring)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
ring->rx_pending = adapter->num_rxd;
ring->rx_jumbo_pending = adapter->num_jumbo_rxd;
ring->tx_pending = adapter->num_txd;
ring->rx_max_pending = adapter->max_rxd;
ring->rx_jumbo_max_pending = adapter->max_jumbo_rxd;
ring->tx_max_pending = MAX_CMD_DESCRIPTORS;
ring->rx_mini_max_pending = 0;
ring->rx_mini_pending = 0;
}
static u32
qlcnic_validate_ringparam(u32 val, u32 min, u32 max, char *r_name)
{
u32 num_desc;
num_desc = max(val, min);
num_desc = min(num_desc, max);
num_desc = roundup_pow_of_two(num_desc);
if (val != num_desc) {
printk(KERN_INFO "%s: setting %s ring size %d instead of %d\n",
qlcnic_driver_name, r_name, num_desc, val);
}
return num_desc;
}
static int
qlcnic_set_ringparam(struct net_device *dev,
struct ethtool_ringparam *ring)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
u16 num_rxd, num_jumbo_rxd, num_txd;
if (ring->rx_mini_pending)
return -EOPNOTSUPP;
num_rxd = qlcnic_validate_ringparam(ring->rx_pending,
MIN_RCV_DESCRIPTORS, adapter->max_rxd, "rx");
num_jumbo_rxd = qlcnic_validate_ringparam(ring->rx_jumbo_pending,
MIN_JUMBO_DESCRIPTORS, adapter->max_jumbo_rxd,
"rx jumbo");
num_txd = qlcnic_validate_ringparam(ring->tx_pending,
MIN_CMD_DESCRIPTORS, MAX_CMD_DESCRIPTORS, "tx");
if (num_rxd == adapter->num_rxd && num_txd == adapter->num_txd &&
num_jumbo_rxd == adapter->num_jumbo_rxd)
return 0;
adapter->num_rxd = num_rxd;
adapter->num_jumbo_rxd = num_jumbo_rxd;
adapter->num_txd = num_txd;
return qlcnic_reset_context(adapter);
}
static void qlcnic_get_channels(struct net_device *dev,
struct ethtool_channels *channel)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
channel->max_rx = rounddown_pow_of_two(min_t(int,
adapter->max_rx_ques, num_online_cpus()));
channel->max_tx = adapter->max_tx_ques;
channel->rx_count = adapter->max_sds_rings;
channel->tx_count = adapter->max_tx_ques;
}
static int qlcnic_set_channels(struct net_device *dev,
struct ethtool_channels *channel)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
int err;
if (channel->other_count || channel->combined_count ||
channel->tx_count != channel->max_tx)
return -EINVAL;
err = qlcnic_validate_max_rss(dev, channel->max_rx, channel->rx_count);
if (err)
return err;
err = qlcnic_set_max_rss(adapter, channel->rx_count);
netdev_info(dev, "allocated 0x%x sds rings\n",
adapter->max_sds_rings);
return err;
}
static void
qlcnic_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
int port = adapter->physical_port;
__u32 val;
if (adapter->ahw->port_type == QLCNIC_GBE) {
if ((port < 0) || (port > QLCNIC_NIU_MAX_GBE_PORTS))
return;
val = QLCRD32(adapter, QLCNIC_NIU_GB_MAC_CONFIG_0(port));
pause->rx_pause = qlcnic_gb_get_rx_flowctl(val);
val = QLCRD32(adapter, QLCNIC_NIU_GB_PAUSE_CTL);
switch (port) {
case 0:
pause->tx_pause = !(qlcnic_gb_get_gb0_mask(val));
break;
case 1:
pause->tx_pause = !(qlcnic_gb_get_gb1_mask(val));
break;
case 2:
pause->tx_pause = !(qlcnic_gb_get_gb2_mask(val));
break;
case 3:
default:
pause->tx_pause = !(qlcnic_gb_get_gb3_mask(val));
break;
}
} else if (adapter->ahw->port_type == QLCNIC_XGBE) {
if ((port < 0) || (port > QLCNIC_NIU_MAX_XG_PORTS))
return;
pause->rx_pause = 1;
val = QLCRD32(adapter, QLCNIC_NIU_XG_PAUSE_CTL);
if (port == 0)
pause->tx_pause = !(qlcnic_xg_get_xg0_mask(val));
else
pause->tx_pause = !(qlcnic_xg_get_xg1_mask(val));
} else {
dev_err(&netdev->dev, "Unknown board type: %x\n",
adapter->ahw->port_type);
}
}
static int
qlcnic_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
int port = adapter->physical_port;
__u32 val;
if (adapter->ahw->port_type == QLCNIC_GBE) {
if ((port < 0) || (port > QLCNIC_NIU_MAX_GBE_PORTS))
return -EIO;
val = QLCRD32(adapter, QLCNIC_NIU_GB_MAC_CONFIG_0(port));
if (pause->rx_pause)
qlcnic_gb_rx_flowctl(val);
else
qlcnic_gb_unset_rx_flowctl(val);
QLCWR32(adapter, QLCNIC_NIU_GB_MAC_CONFIG_0(port),
val);
val = QLCRD32(adapter, QLCNIC_NIU_GB_PAUSE_CTL);
switch (port) {
case 0:
if (pause->tx_pause)
qlcnic_gb_unset_gb0_mask(val);
else
qlcnic_gb_set_gb0_mask(val);
break;
case 1:
if (pause->tx_pause)
qlcnic_gb_unset_gb1_mask(val);
else
qlcnic_gb_set_gb1_mask(val);
break;
case 2:
if (pause->tx_pause)
qlcnic_gb_unset_gb2_mask(val);
else
qlcnic_gb_set_gb2_mask(val);
break;
case 3:
default:
if (pause->tx_pause)
qlcnic_gb_unset_gb3_mask(val);
else
qlcnic_gb_set_gb3_mask(val);
break;
}
QLCWR32(adapter, QLCNIC_NIU_GB_PAUSE_CTL, val);
} else if (adapter->ahw->port_type == QLCNIC_XGBE) {
if (!pause->rx_pause || pause->autoneg)
return -EOPNOTSUPP;
if ((port < 0) || (port > QLCNIC_NIU_MAX_XG_PORTS))
return -EIO;
val = QLCRD32(adapter, QLCNIC_NIU_XG_PAUSE_CTL);
if (port == 0) {
if (pause->tx_pause)
qlcnic_xg_unset_xg0_mask(val);
else
qlcnic_xg_set_xg0_mask(val);
} else {
if (pause->tx_pause)
qlcnic_xg_unset_xg1_mask(val);
else
qlcnic_xg_set_xg1_mask(val);
}
QLCWR32(adapter, QLCNIC_NIU_XG_PAUSE_CTL, val);
} else {
dev_err(&netdev->dev, "Unknown board type: %x\n",
adapter->ahw->port_type);
}
return 0;
}
static int qlcnic_reg_test(struct net_device *dev)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
u32 data_read;
data_read = QLCRD32(adapter, QLCNIC_PCIX_PH_REG(0));
if ((data_read & 0xffff) != adapter->pdev->vendor)
return 1;
return 0;
}
static int qlcnic_get_sset_count(struct net_device *dev, int sset)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
switch (sset) {
case ETH_SS_TEST:
return QLCNIC_TEST_LEN;
case ETH_SS_STATS:
if (adapter->flags & QLCNIC_ESWITCH_ENABLED)
return QLCNIC_STATS_LEN + QLCNIC_DEVICE_STATS_LEN;
return QLCNIC_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static int qlcnic_irq_test(struct net_device *netdev)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
int max_sds_rings = adapter->max_sds_rings;
int ret;
if (test_and_set_bit(__QLCNIC_RESETTING, &adapter->state))
return -EIO;
ret = qlcnic_diag_alloc_res(netdev, QLCNIC_INTERRUPT_TEST);
if (ret)
goto clear_it;
adapter->diag_cnt = 0;
ret = qlcnic_issue_cmd(adapter, adapter->ahw->pci_func,
adapter->fw_hal_version, adapter->ahw->pci_func,
0, 0, 0x00000011);
if (ret)
goto done;
msleep(10);
ret = !adapter->diag_cnt;
done:
qlcnic_diag_free_res(netdev, max_sds_rings);
clear_it:
adapter->max_sds_rings = max_sds_rings;
clear_bit(__QLCNIC_RESETTING, &adapter->state);
return ret;
}
static void qlcnic_create_loopback_buff(unsigned char *data, u8 mac[])
{
unsigned char random_data[] = {0xa8, 0x06, 0x45, 0x00};
memset(data, 0x4e, QLCNIC_ILB_PKT_SIZE);
memcpy(data, mac, ETH_ALEN);
memcpy(data + ETH_ALEN, mac, ETH_ALEN);
memcpy(data + 2 * ETH_ALEN, random_data, sizeof(random_data));
}
int qlcnic_check_loopback_buff(unsigned char *data, u8 mac[])
{
unsigned char buff[QLCNIC_ILB_PKT_SIZE];
qlcnic_create_loopback_buff(buff, mac);
return memcmp(data, buff, QLCNIC_ILB_PKT_SIZE);
}
static int qlcnic_do_lb_test(struct qlcnic_adapter *adapter)
{
struct qlcnic_recv_context *recv_ctx = adapter->recv_ctx;
struct qlcnic_host_sds_ring *sds_ring = &recv_ctx->sds_rings[0];
struct sk_buff *skb;
int i, loop, cnt = 0;
for (i = 0; i < QLCNIC_NUM_ILB_PKT; i++) {
skb = dev_alloc_skb(QLCNIC_ILB_PKT_SIZE);
qlcnic_create_loopback_buff(skb->data, adapter->mac_addr);
skb_put(skb, QLCNIC_ILB_PKT_SIZE);
adapter->diag_cnt = 0;
qlcnic_xmit_frame(skb, adapter->netdev);
loop = 0;
do {
msleep(1);
qlcnic_process_rcv_ring_diag(sds_ring);
if (loop++ > QLCNIC_ILB_MAX_RCV_LOOP)
break;
} while (!adapter->diag_cnt);
dev_kfree_skb_any(skb);
if (!adapter->diag_cnt)
dev_warn(&adapter->pdev->dev, "LB Test: %dth packet"
" not recevied\n", i + 1);
else
cnt++;
}
if (cnt != i) {
dev_warn(&adapter->pdev->dev, "LB Test failed\n");
return -1;
}
return 0;
}
static int qlcnic_loopback_test(struct net_device *netdev, u8 mode)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
int max_sds_rings = adapter->max_sds_rings;
struct qlcnic_host_sds_ring *sds_ring;
int loop = 0;
int ret;
if (!(adapter->capabilities & QLCNIC_FW_CAPABILITY_MULTI_LOOPBACK)) {
netdev_info(netdev, "Firmware is not loopback test capable\n");
return -EOPNOTSUPP;
}
netdev_info(netdev, "%s loopback test in progress\n",
mode == QLCNIC_ILB_MODE ? "internal" : "external");
if (adapter->op_mode == QLCNIC_NON_PRIV_FUNC) {
netdev_warn(netdev, "Loopback test not supported for non "
"privilege function\n");
return 0;
}
if (test_and_set_bit(__QLCNIC_RESETTING, &adapter->state))
return -EBUSY;
ret = qlcnic_diag_alloc_res(netdev, QLCNIC_LOOPBACK_TEST);
if (ret)
goto clear_it;
sds_ring = &adapter->recv_ctx->sds_rings[0];
ret = qlcnic_set_lb_mode(adapter, mode);
if (ret)
goto free_res;
adapter->diag_cnt = 0;
do {
msleep(500);
qlcnic_process_rcv_ring_diag(sds_ring);
if (loop++ > QLCNIC_ILB_MAX_RCV_LOOP) {
netdev_info(netdev, "firmware didnt respond to loopback"
" configure request\n");
ret = -QLCNIC_FW_NOT_RESPOND;
goto free_res;
} else if (adapter->diag_cnt) {
ret = adapter->diag_cnt;
goto free_res;
}
} while (!QLCNIC_IS_LB_CONFIGURED(adapter->ahw->loopback_state));
ret = qlcnic_do_lb_test(adapter);
qlcnic_clear_lb_mode(adapter);
free_res:
qlcnic_diag_free_res(netdev, max_sds_rings);
clear_it:
adapter->max_sds_rings = max_sds_rings;
clear_bit(__QLCNIC_RESETTING, &adapter->state);
return ret;
}
static void
qlcnic_diag_test(struct net_device *dev, struct ethtool_test *eth_test,
u64 *data)
{
memset(data, 0, sizeof(u64) * QLCNIC_TEST_LEN);
data[0] = qlcnic_reg_test(dev);
if (data[0])
eth_test->flags |= ETH_TEST_FL_FAILED;
data[1] = (u64) qlcnic_test_link(dev);
if (data[1])
eth_test->flags |= ETH_TEST_FL_FAILED;
if (eth_test->flags & ETH_TEST_FL_OFFLINE) {
data[2] = qlcnic_irq_test(dev);
if (data[2])
eth_test->flags |= ETH_TEST_FL_FAILED;
data[3] = qlcnic_loopback_test(dev, QLCNIC_ILB_MODE);
if (data[3])
eth_test->flags |= ETH_TEST_FL_FAILED;
if (eth_test->flags & ETH_TEST_FL_EXTERNAL_LB) {
data[4] = qlcnic_loopback_test(dev, QLCNIC_ELB_MODE);
if (data[4])
eth_test->flags |= ETH_TEST_FL_FAILED;
eth_test->flags |= ETH_TEST_FL_EXTERNAL_LB_DONE;
}
}
}
static void
qlcnic_get_strings(struct net_device *dev, u32 stringset, u8 * data)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
int index, i;
switch (stringset) {
case ETH_SS_TEST:
memcpy(data, *qlcnic_gstrings_test,
QLCNIC_TEST_LEN * ETH_GSTRING_LEN);
break;
case ETH_SS_STATS:
for (index = 0; index < QLCNIC_STATS_LEN; index++) {
memcpy(data + index * ETH_GSTRING_LEN,
qlcnic_gstrings_stats[index].stat_string,
ETH_GSTRING_LEN);
}
if (!(adapter->flags & QLCNIC_ESWITCH_ENABLED))
return;
for (i = 0; i < QLCNIC_DEVICE_STATS_LEN; index++, i++) {
memcpy(data + index * ETH_GSTRING_LEN,
qlcnic_device_gstrings_stats[i],
ETH_GSTRING_LEN);
}
}
}
static void
qlcnic_fill_device_stats(int *index, u64 *data,
struct __qlcnic_esw_statistics *stats)
{
int ind = *index;
data[ind++] = QLCNIC_FILL_ESWITCH_STATS(stats->unicast_frames);
data[ind++] = QLCNIC_FILL_ESWITCH_STATS(stats->multicast_frames);
data[ind++] = QLCNIC_FILL_ESWITCH_STATS(stats->broadcast_frames);
data[ind++] = QLCNIC_FILL_ESWITCH_STATS(stats->dropped_frames);
data[ind++] = QLCNIC_FILL_ESWITCH_STATS(stats->errors);
data[ind++] = QLCNIC_FILL_ESWITCH_STATS(stats->local_frames);
data[ind++] = QLCNIC_FILL_ESWITCH_STATS(stats->numbytes);
*index = ind;
}
static void
qlcnic_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 * data)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
struct qlcnic_esw_statistics port_stats;
int index, ret;
for (index = 0; index < QLCNIC_STATS_LEN; index++) {
char *p =
(char *)adapter +
qlcnic_gstrings_stats[index].stat_offset;
data[index] =
(qlcnic_gstrings_stats[index].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p:(*(u32 *)p);
}
if (!(adapter->flags & QLCNIC_ESWITCH_ENABLED))
return;
memset(&port_stats, 0, sizeof(struct qlcnic_esw_statistics));
ret = qlcnic_get_port_stats(adapter, adapter->ahw->pci_func,
QLCNIC_QUERY_RX_COUNTER, &port_stats.rx);
if (ret)
return;
qlcnic_fill_device_stats(&index, data, &port_stats.rx);
ret = qlcnic_get_port_stats(adapter, adapter->ahw->pci_func,
QLCNIC_QUERY_TX_COUNTER, &port_stats.tx);
if (ret)
return;
qlcnic_fill_device_stats(&index, data, &port_stats.tx);
}
static int qlcnic_set_led(struct net_device *dev,
enum ethtool_phys_id_state state)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
int max_sds_rings = adapter->max_sds_rings;
switch (state) {
case ETHTOOL_ID_ACTIVE:
if (!test_bit(__QLCNIC_DEV_UP, &adapter->state)) {
if (test_and_set_bit(__QLCNIC_RESETTING, &adapter->state))
return -EIO;
if (qlcnic_diag_alloc_res(dev, QLCNIC_LED_TEST)) {
clear_bit(__QLCNIC_RESETTING, &adapter->state);
return -EIO;
}
set_bit(__QLCNIC_DIAG_RES_ALLOC, &adapter->state);
}
if (adapter->nic_ops->config_led(adapter, 1, 0xf) == 0)
return 0;
dev_err(&adapter->pdev->dev,
"Failed to set LED blink state.\n");
break;
case ETHTOOL_ID_INACTIVE:
if (adapter->nic_ops->config_led(adapter, 0, 0xf))
dev_err(&adapter->pdev->dev,
"Failed to reset LED blink state.\n");
break;
default:
return -EINVAL;
}
if (test_and_clear_bit(__QLCNIC_DIAG_RES_ALLOC, &adapter->state)) {
qlcnic_diag_free_res(dev, max_sds_rings);
clear_bit(__QLCNIC_RESETTING, &adapter->state);
}
return -EIO;
}
static void
qlcnic_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
u32 wol_cfg;
wol->supported = 0;
wol->wolopts = 0;
wol_cfg = QLCRD32(adapter, QLCNIC_WOL_CONFIG_NV);
if (wol_cfg & (1UL << adapter->portnum))
wol->supported |= WAKE_MAGIC;
wol_cfg = QLCRD32(adapter, QLCNIC_WOL_CONFIG);
if (wol_cfg & (1UL << adapter->portnum))
wol->wolopts |= WAKE_MAGIC;
}
static int
qlcnic_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct qlcnic_adapter *adapter = netdev_priv(dev);
u32 wol_cfg;
if (wol->wolopts & ~WAKE_MAGIC)
return -EOPNOTSUPP;
wol_cfg = QLCRD32(adapter, QLCNIC_WOL_CONFIG_NV);
if (!(wol_cfg & (1 << adapter->portnum)))
return -EOPNOTSUPP;
wol_cfg = QLCRD32(adapter, QLCNIC_WOL_CONFIG);
if (wol->wolopts & WAKE_MAGIC)
wol_cfg |= 1UL << adapter->portnum;
else
wol_cfg &= ~(1UL << adapter->portnum);
QLCWR32(adapter, QLCNIC_WOL_CONFIG, wol_cfg);
return 0;
}
static int qlcnic_set_intr_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ethcoal)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
if (!test_bit(__QLCNIC_DEV_UP, &adapter->state))
return -EINVAL;
if (ethcoal->rx_coalesce_usecs > 0xffff ||
ethcoal->rx_max_coalesced_frames > 0xffff ||
ethcoal->tx_coalesce_usecs ||
ethcoal->tx_max_coalesced_frames ||
ethcoal->rx_coalesce_usecs_irq ||
ethcoal->rx_max_coalesced_frames_irq ||
ethcoal->tx_coalesce_usecs_irq ||
ethcoal->tx_max_coalesced_frames_irq ||
ethcoal->stats_block_coalesce_usecs ||
ethcoal->use_adaptive_rx_coalesce ||
ethcoal->use_adaptive_tx_coalesce ||
ethcoal->pkt_rate_low ||
ethcoal->rx_coalesce_usecs_low ||
ethcoal->rx_max_coalesced_frames_low ||
ethcoal->tx_coalesce_usecs_low ||
ethcoal->tx_max_coalesced_frames_low ||
ethcoal->pkt_rate_high ||
ethcoal->rx_coalesce_usecs_high ||
ethcoal->rx_max_coalesced_frames_high ||
ethcoal->tx_coalesce_usecs_high ||
ethcoal->tx_max_coalesced_frames_high)
return -EINVAL;
if (!ethcoal->rx_coalesce_usecs ||
!ethcoal->rx_max_coalesced_frames) {
adapter->ahw->coal.flag = QLCNIC_INTR_DEFAULT;
adapter->ahw->coal.rx_time_us =
QLCNIC_DEFAULT_INTR_COALESCE_RX_TIME_US;
adapter->ahw->coal.rx_packets =
QLCNIC_DEFAULT_INTR_COALESCE_RX_PACKETS;
} else {
adapter->ahw->coal.flag = 0;
adapter->ahw->coal.rx_time_us = ethcoal->rx_coalesce_usecs;
adapter->ahw->coal.rx_packets =
ethcoal->rx_max_coalesced_frames;
}
qlcnic_config_intr_coalesce(adapter);
return 0;
}
static int qlcnic_get_intr_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ethcoal)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
if (adapter->is_up != QLCNIC_ADAPTER_UP_MAGIC)
return -EINVAL;
ethcoal->rx_coalesce_usecs = adapter->ahw->coal.rx_time_us;
ethcoal->rx_max_coalesced_frames = adapter->ahw->coal.rx_packets;
return 0;
}
static u32 qlcnic_get_msglevel(struct net_device *netdev)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
return adapter->msg_enable;
}
static void qlcnic_set_msglevel(struct net_device *netdev, u32 msglvl)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
adapter->msg_enable = msglvl;
}
static int
qlcnic_get_dump_flag(struct net_device *netdev, struct ethtool_dump *dump)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct qlcnic_fw_dump *fw_dump = &adapter->ahw->fw_dump;
dump->len = fw_dump->tmpl_hdr->size + fw_dump->size;
dump->flag = fw_dump->tmpl_hdr->drv_cap_mask;
dump->version = adapter->fw_version;
return 0;
}
static int
qlcnic_get_dump_data(struct net_device *netdev, struct ethtool_dump *dump,
void *buffer)
{
int i, copy_sz;
u32 *hdr_ptr, *data;
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct qlcnic_fw_dump *fw_dump = &adapter->ahw->fw_dump;
if (!fw_dump->clr) {
netdev_info(netdev, "Dump not available\n");
qlcnic_api_unlock(adapter);
return -EINVAL;
}
copy_sz = fw_dump->tmpl_hdr->size;
hdr_ptr = (u32 *) fw_dump->tmpl_hdr;
data = buffer;
for (i = 0; i < copy_sz/sizeof(u32); i++)
*data++ = cpu_to_le32(*hdr_ptr++);
memcpy(buffer + copy_sz, fw_dump->data, fw_dump->size);
dump->len = copy_sz + fw_dump->size;
dump->flag = fw_dump->tmpl_hdr->drv_cap_mask;
vfree(fw_dump->data);
fw_dump->data = NULL;
fw_dump->clr = 0;
return 0;
}
static int
qlcnic_set_dump(struct net_device *netdev, struct ethtool_dump *val)
{
int ret = 0;
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct qlcnic_fw_dump *fw_dump = &adapter->ahw->fw_dump;
if (val->flag == QLCNIC_FORCE_FW_DUMP_KEY) {
if (!fw_dump->enable) {
netdev_info(netdev, "FW dump not enabled\n");
return ret;
}
if (fw_dump->clr) {
dev_info(&adapter->pdev->dev,
"Previous dump not cleared, not forcing dump\n");
return ret;
}
netdev_info(netdev, "Forcing a FW dump\n");
qlcnic_dev_request_reset(adapter);
} else if (val->flag == QLCNIC_DISABLE_FW_DUMP) {
if (fw_dump->enable) {
netdev_info(netdev, "Disabling FW dump\n");
fw_dump->enable = 0;
}
} else if (val->flag == QLCNIC_ENABLE_FW_DUMP) {
if (!fw_dump->enable && fw_dump->tmpl_hdr) {
netdev_info(netdev, "Enabling FW dump\n");
fw_dump->enable = 1;
}
} else {
if (val->flag > QLCNIC_DUMP_MASK_MAX ||
val->flag < QLCNIC_DUMP_MASK_MIN) {
netdev_info(netdev,
"Invalid dump level: 0x%x\n", val->flag);
ret = -EINVAL;
goto out;
}
fw_dump->tmpl_hdr->drv_cap_mask = val->flag & 0xff;
netdev_info(netdev, "Driver mask changed to: 0x%x\n",
fw_dump->tmpl_hdr->drv_cap_mask);
}
out:
return ret;
}
