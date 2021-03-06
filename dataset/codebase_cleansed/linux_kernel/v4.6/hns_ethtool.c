static u32 hns_nic_get_link(struct net_device *net_dev)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
u32 link_stat = priv->link;
struct hnae_handle *h;
assert(priv && priv->ae_handle);
h = priv->ae_handle;
if (priv->phy) {
if (!genphy_update_link(priv->phy))
link_stat = priv->phy->link;
else
link_stat = 0;
}
if (h->dev && h->dev->ops && h->dev->ops->get_status)
link_stat = link_stat && h->dev->ops->get_status(h);
else
link_stat = 0;
return link_stat;
}
static void hns_get_mdix_mode(struct net_device *net_dev,
struct ethtool_cmd *cmd)
{
int mdix_ctrl, mdix, retval, is_resolved;
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct phy_device *phy_dev = priv->phy;
if (!phy_dev || !phy_dev->mdio.bus) {
cmd->eth_tp_mdix_ctrl = ETH_TP_MDI_INVALID;
cmd->eth_tp_mdix = ETH_TP_MDI_INVALID;
return;
}
phy_write(phy_dev, HNS_PHY_PAGE_REG, HNS_PHY_PAGE_MDIX);
retval = phy_read(phy_dev, HNS_PHY_CSC_REG);
mdix_ctrl = hnae_get_field(retval, PHY_MDIX_CTRL_M, PHY_MDIX_CTRL_S);
retval = phy_read(phy_dev, HNS_PHY_CSS_REG);
mdix = hnae_get_bit(retval, PHY_MDIX_STATUS_B);
is_resolved = hnae_get_bit(retval, PHY_SPEED_DUP_RESOLVE_B);
phy_write(phy_dev, HNS_PHY_PAGE_REG, HNS_PHY_PAGE_COPPER);
switch (mdix_ctrl) {
case 0x0:
cmd->eth_tp_mdix_ctrl = ETH_TP_MDI;
break;
case 0x1:
cmd->eth_tp_mdix_ctrl = ETH_TP_MDI_X;
break;
case 0x3:
cmd->eth_tp_mdix_ctrl = ETH_TP_MDI_AUTO;
break;
default:
cmd->eth_tp_mdix_ctrl = ETH_TP_MDI_INVALID;
break;
}
if (!is_resolved)
cmd->eth_tp_mdix = ETH_TP_MDI_INVALID;
else if (mdix)
cmd->eth_tp_mdix = ETH_TP_MDI_X;
else
cmd->eth_tp_mdix = ETH_TP_MDI;
}
static int hns_nic_get_settings(struct net_device *net_dev,
struct ethtool_cmd *cmd)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_handle *h;
u32 link_stat;
int ret;
u8 duplex;
u16 speed;
if (!priv || !priv->ae_handle)
return -ESRCH;
h = priv->ae_handle;
if (!h->dev || !h->dev->ops || !h->dev->ops->get_info)
return -ESRCH;
ret = h->dev->ops->get_info(h, NULL, &speed, &duplex);
if (ret < 0) {
netdev_err(net_dev, "%s get_info error!\n", __func__);
return -EINVAL;
}
cmd->autoneg = false;
ethtool_cmd_speed_set(cmd, speed);
cmd->duplex = duplex;
if (priv->phy)
(void)phy_ethtool_gset(priv->phy, cmd);
link_stat = hns_nic_get_link(net_dev);
if (!link_stat) {
ethtool_cmd_speed_set(cmd, (u32)SPEED_UNKNOWN);
cmd->duplex = DUPLEX_UNKNOWN;
}
if (cmd->autoneg)
cmd->advertising |= ADVERTISED_Autoneg;
cmd->supported |= h->if_support;
if (h->phy_if == PHY_INTERFACE_MODE_SGMII) {
cmd->supported |= SUPPORTED_TP;
cmd->advertising |= ADVERTISED_1000baseT_Full;
} else if (h->phy_if == PHY_INTERFACE_MODE_XGMII) {
cmd->supported |= SUPPORTED_FIBRE;
cmd->advertising |= ADVERTISED_10000baseKR_Full;
}
if (h->port_type == HNAE_PORT_SERVICE) {
cmd->port = PORT_FIBRE;
cmd->supported |= SUPPORTED_Pause;
} else {
cmd->port = PORT_TP;
}
cmd->transceiver = XCVR_EXTERNAL;
cmd->mdio_support = (ETH_MDIO_SUPPORTS_C45 | ETH_MDIO_SUPPORTS_C22);
hns_get_mdix_mode(net_dev, cmd);
return 0;
}
static int hns_nic_set_settings(struct net_device *net_dev,
struct ethtool_cmd *cmd)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_handle *h;
u32 speed;
if (!netif_running(net_dev))
return -ESRCH;
if (!priv || !priv->ae_handle || !priv->ae_handle->dev ||
!priv->ae_handle->dev->ops)
return -ENODEV;
h = priv->ae_handle;
speed = ethtool_cmd_speed(cmd);
if (h->phy_if == PHY_INTERFACE_MODE_XGMII) {
if (cmd->autoneg == AUTONEG_ENABLE || speed != SPEED_10000 ||
cmd->duplex != DUPLEX_FULL)
return -EINVAL;
} else if (h->phy_if == PHY_INTERFACE_MODE_SGMII) {
if (!priv->phy && cmd->autoneg == AUTONEG_ENABLE)
return -EINVAL;
if (speed == SPEED_1000 && cmd->duplex == DUPLEX_HALF)
return -EINVAL;
if (priv->phy)
return phy_ethtool_sset(priv->phy, cmd);
if ((speed != SPEED_10 && speed != SPEED_100 &&
speed != SPEED_1000) || (cmd->duplex != DUPLEX_HALF &&
cmd->duplex != DUPLEX_FULL))
return -EINVAL;
} else {
netdev_err(net_dev, "Not supported!");
return -ENOTSUPP;
}
if (h->dev->ops->adjust_link) {
h->dev->ops->adjust_link(h, (int)speed, cmd->duplex);
return 0;
}
netdev_err(net_dev, "Not supported!");
return -ENOTSUPP;
}
static int hns_nic_config_phy_loopback(struct phy_device *phy_dev, u8 en)
{
#define COPPER_CONTROL_REG 0
#define PHY_LOOP_BACK BIT(14)
u16 val = 0;
if (phy_dev->is_c45)
return -ENOTSUPP;
if (en) {
phy_write(phy_dev, HNS_PHY_PAGE_REG, 2);
phy_write(phy_dev, 21, 0x1046);
phy_write(phy_dev, 9, 0x1F00);
phy_write(phy_dev, 0, 0x9140);
phy_write(phy_dev, 0, 0x9140);
phy_write(phy_dev, 22, 0xFA);
phy_write(phy_dev, 1, 0x418);
phy_write(phy_dev, 7, 0x20C);
phy_write(phy_dev, 22, 0);
val = phy_read(phy_dev, COPPER_CONTROL_REG);
val |= PHY_LOOP_BACK;
phy_write(phy_dev, COPPER_CONTROL_REG, val);
} else {
phy_write(phy_dev, 22, 0xFA);
phy_write(phy_dev, 1, 0x400);
phy_write(phy_dev, 7, 0x200);
phy_write(phy_dev, 22, 0);
val = phy_read(phy_dev, COPPER_CONTROL_REG);
val &= ~PHY_LOOP_BACK;
phy_write(phy_dev, COPPER_CONTROL_REG, val);
}
return 0;
}
static int __lb_setup(struct net_device *ndev,
enum hnae_loop loop)
{
int ret = 0;
struct hns_nic_priv *priv = netdev_priv(ndev);
struct phy_device *phy_dev = priv->phy;
struct hnae_handle *h = priv->ae_handle;
switch (loop) {
case MAC_INTERNALLOOP_PHY:
if ((phy_dev) && (!phy_dev->is_c45)) {
ret = hns_nic_config_phy_loopback(phy_dev, 0x1);
ret |= h->dev->ops->set_loopback(h, loop, 0x1);
}
break;
case MAC_INTERNALLOOP_MAC:
if ((h->dev->ops->set_loopback) &&
(priv->ae_handle->phy_if != PHY_INTERFACE_MODE_XGMII))
ret = h->dev->ops->set_loopback(h, loop, 0x1);
break;
case MAC_INTERNALLOOP_SERDES:
if (h->dev->ops->set_loopback)
ret = h->dev->ops->set_loopback(h, loop, 0x1);
break;
case MAC_LOOP_NONE:
if ((phy_dev) && (!phy_dev->is_c45))
ret |= hns_nic_config_phy_loopback(phy_dev, 0x0);
if (h->dev->ops->set_loopback) {
if (priv->ae_handle->phy_if != PHY_INTERFACE_MODE_XGMII)
ret |= h->dev->ops->set_loopback(h,
MAC_INTERNALLOOP_MAC, 0x0);
ret |= h->dev->ops->set_loopback(h,
MAC_INTERNALLOOP_SERDES, 0x0);
}
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int __lb_up(struct net_device *ndev,
enum hnae_loop loop_mode)
{
struct hns_nic_priv *priv = netdev_priv(ndev);
struct hnae_handle *h = priv->ae_handle;
int speed, duplex;
int ret;
hns_nic_net_reset(ndev);
if (priv->phy) {
phy_disconnect(priv->phy);
msleep(100);
ret = hns_nic_init_phy(ndev, h);
if (ret)
return ret;
}
ret = __lb_setup(ndev, loop_mode);
if (ret)
return ret;
msleep(100);
ret = h->dev->ops->start ? h->dev->ops->start(h) : 0;
if (ret)
return ret;
if (priv->phy)
phy_start(priv->phy);
if (priv->ae_handle->phy_if != PHY_INTERFACE_MODE_XGMII)
speed = 1000;
else
speed = 10000;
duplex = 1;
h->dev->ops->adjust_link(h, speed, duplex);
return 0;
}
static void __lb_other_process(struct hns_nic_ring_data *ring_data,
struct sk_buff *skb)
{
struct net_device *ndev;
struct hns_nic_priv *priv;
struct hnae_ring *ring;
struct netdev_queue *dev_queue;
struct sk_buff *new_skb;
unsigned int frame_size;
int check_ok;
u32 i;
char buff[33];
if (!ring_data) {
ndev = skb->dev;
priv = netdev_priv(ndev);
frame_size = skb->len;
memset(skb->data, 0xFF, frame_size);
if ((!AE_IS_VER1(priv->enet_ver)) &&
(priv->ae_handle->port_type == HNAE_PORT_SERVICE)) {
memcpy(skb->data, ndev->dev_addr, 6);
skb->data[5] += 0x1f;
}
frame_size &= ~1ul;
memset(&skb->data[frame_size / 2], 0xAA, frame_size / 2 - 1);
memset(&skb->data[frame_size / 2 + 10], 0xBE,
frame_size / 2 - 11);
memset(&skb->data[frame_size / 2 + 12], 0xAF,
frame_size / 2 - 13);
return;
}
ring = ring_data->ring;
ndev = ring_data->napi.dev;
if (is_tx_ring(ring)) {
dev_queue = netdev_get_tx_queue(ndev, ring_data->queue_index);
netdev_tx_reset_queue(dev_queue);
return;
}
frame_size = skb->len;
frame_size &= ~1ul;
new_skb = skb_copy(skb, GFP_ATOMIC);
dev_kfree_skb_any(skb);
skb = new_skb;
check_ok = 0;
if (*(skb->data + 10) == 0xFF) {
if ((*(skb->data + frame_size / 2 + 10) == 0xBE) &&
(*(skb->data + frame_size / 2 + 12) == 0xAF))
check_ok = 1;
}
if (check_ok) {
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += skb->len;
} else {
ndev->stats.rx_frame_errors++;
for (i = 0; i < skb->len; i++) {
snprintf(buff + i % 16 * 2, 3,
"%02x", *(skb->data + i));
if ((i % 16 == 15) || (i == skb->len - 1))
pr_info("%s\n", buff);
}
}
dev_kfree_skb_any(skb);
}
static int __lb_clean_rings(struct hns_nic_priv *priv,
int ringid0, int ringid1, int budget)
{
int i, ret;
struct hns_nic_ring_data *ring_data;
struct net_device *ndev = priv->netdev;
unsigned long rx_packets = ndev->stats.rx_packets;
unsigned long rx_bytes = ndev->stats.rx_bytes;
unsigned long rx_frame_errors = ndev->stats.rx_frame_errors;
for (i = ringid0; i <= ringid1; i++) {
ring_data = &priv->ring_data[i];
(void)ring_data->poll_one(ring_data,
budget, __lb_other_process);
}
ret = (int)(ndev->stats.rx_packets - rx_packets);
ndev->stats.rx_packets = rx_packets;
ndev->stats.rx_bytes = rx_bytes;
ndev->stats.rx_frame_errors = rx_frame_errors;
return ret;
}
static int __lb_run_test(struct net_device *ndev,
enum hnae_loop loop_mode)
{
#define NIC_LB_TEST_PKT_NUM_PER_CYCLE 1
#define NIC_LB_TEST_RING_ID 0
#define NIC_LB_TEST_FRAME_SIZE 128
#define NIC_LB_TEST_NO_MEM_ERR 1
#define NIC_LB_TEST_TX_CNT_ERR 2
#define NIC_LB_TEST_RX_CNT_ERR 3
#define NIC_LB_TEST_RX_PKG_ERR 4
struct hns_nic_priv *priv = netdev_priv(ndev);
struct hnae_handle *h = priv->ae_handle;
int i, j, lc, good_cnt, ret_val = 0;
unsigned int size;
netdev_tx_t tx_ret_val;
struct sk_buff *skb;
size = NIC_LB_TEST_FRAME_SIZE;
skb = alloc_skb(size, GFP_KERNEL);
if (!skb)
return NIC_LB_TEST_NO_MEM_ERR;
(void)skb_put(skb, size);
skb->dev = ndev;
__lb_other_process(NULL, skb);
skb->queue_mapping = NIC_LB_TEST_RING_ID;
lc = 1;
for (j = 0; j < lc; j++) {
good_cnt = 0;
for (i = 0; i < NIC_LB_TEST_PKT_NUM_PER_CYCLE; i++) {
(void)skb_get(skb);
tx_ret_val = (netdev_tx_t)hns_nic_net_xmit_hw(
ndev, skb,
&tx_ring_data(priv, skb->queue_mapping));
if (tx_ret_val == NETDEV_TX_OK)
good_cnt++;
else
break;
}
if (good_cnt != NIC_LB_TEST_PKT_NUM_PER_CYCLE) {
ret_val = NIC_LB_TEST_TX_CNT_ERR;
dev_err(priv->dev, "%s sent fail, cnt=0x%x, budget=0x%x\n",
hns_nic_test_strs[loop_mode], good_cnt,
NIC_LB_TEST_PKT_NUM_PER_CYCLE);
break;
}
msleep(100);
good_cnt = __lb_clean_rings(priv,
h->q_num, h->q_num * 2 - 1,
NIC_LB_TEST_PKT_NUM_PER_CYCLE);
if (good_cnt != NIC_LB_TEST_PKT_NUM_PER_CYCLE) {
ret_val = NIC_LB_TEST_RX_CNT_ERR;
dev_err(priv->dev, "%s recv fail, cnt=0x%x, budget=0x%x\n",
hns_nic_test_strs[loop_mode], good_cnt,
NIC_LB_TEST_PKT_NUM_PER_CYCLE);
break;
}
(void)__lb_clean_rings(priv,
NIC_LB_TEST_RING_ID, NIC_LB_TEST_RING_ID,
NIC_LB_TEST_PKT_NUM_PER_CYCLE);
}
kfree_skb(skb);
return ret_val;
}
static int __lb_down(struct net_device *ndev)
{
struct hns_nic_priv *priv = netdev_priv(ndev);
struct hnae_handle *h = priv->ae_handle;
int ret;
ret = __lb_setup(ndev, MAC_LOOP_NONE);
if (ret)
netdev_err(ndev, "%s: __lb_setup return error(%d)!\n",
__func__,
ret);
if (priv->phy)
phy_stop(priv->phy);
if (h->dev->ops->stop)
h->dev->ops->stop(h);
usleep_range(10000, 20000);
(void)__lb_clean_rings(priv, 0, h->q_num - 1, 256);
hns_nic_net_reset(ndev);
return 0;
}
static void hns_nic_self_test(struct net_device *ndev,
struct ethtool_test *eth_test, u64 *data)
{
struct hns_nic_priv *priv = netdev_priv(ndev);
bool if_running = netif_running(ndev);
#define SELF_TEST_TPYE_NUM 3
int st_param[SELF_TEST_TPYE_NUM][2];
int i;
int test_index = 0;
st_param[0][0] = MAC_INTERNALLOOP_MAC;
st_param[0][1] = (priv->ae_handle->phy_if != PHY_INTERFACE_MODE_XGMII);
st_param[1][0] = MAC_INTERNALLOOP_SERDES;
st_param[1][1] = 1;
st_param[2][0] = MAC_INTERNALLOOP_PHY;
st_param[2][1] = ((!!(priv->ae_handle->phy_node)) &&
(priv->ae_handle->phy_if != PHY_INTERFACE_MODE_XGMII));
if (eth_test->flags == ETH_TEST_FL_OFFLINE) {
set_bit(NIC_STATE_TESTING, &priv->state);
if (if_running)
(void)dev_close(ndev);
for (i = 0; i < SELF_TEST_TPYE_NUM; i++) {
if (!st_param[i][1])
continue;
data[test_index] = __lb_up(ndev,
(enum hnae_loop)st_param[i][0]);
if (!data[test_index]) {
data[test_index] = __lb_run_test(
ndev, (enum hnae_loop)st_param[i][0]);
(void)__lb_down(ndev);
}
if (data[test_index])
eth_test->flags |= ETH_TEST_FL_FAILED;
test_index++;
}
hns_nic_net_reset(priv->netdev);
clear_bit(NIC_STATE_TESTING, &priv->state);
if (if_running)
(void)dev_open(ndev);
}
(void)msleep_interruptible(4 * 1000);
}
static void hns_nic_get_drvinfo(struct net_device *net_dev,
struct ethtool_drvinfo *drvinfo)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
assert(priv);
strncpy(drvinfo->version, HNAE_DRIVER_VERSION,
sizeof(drvinfo->version));
drvinfo->version[sizeof(drvinfo->version) - 1] = '\0';
strncpy(drvinfo->driver, HNAE_DRIVER_NAME, sizeof(drvinfo->driver));
drvinfo->driver[sizeof(drvinfo->driver) - 1] = '\0';
strncpy(drvinfo->bus_info, priv->dev->bus->name,
sizeof(drvinfo->bus_info));
drvinfo->bus_info[ETHTOOL_BUSINFO_LEN - 1] = '\0';
strncpy(drvinfo->fw_version, "N/A", ETHTOOL_FWVERS_LEN);
drvinfo->eedump_len = 0;
}
void hns_get_ringparam(struct net_device *net_dev,
struct ethtool_ringparam *param)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_ae_ops *ops;
struct hnae_queue *queue;
u32 uplimit = 0;
queue = priv->ae_handle->qs[0];
ops = priv->ae_handle->dev->ops;
if (ops->get_ring_bdnum_limit)
ops->get_ring_bdnum_limit(queue, &uplimit);
param->rx_max_pending = uplimit;
param->tx_max_pending = uplimit;
param->rx_pending = queue->rx_ring.desc_num;
param->tx_pending = queue->tx_ring.desc_num;
}
static void hns_get_pauseparam(struct net_device *net_dev,
struct ethtool_pauseparam *param)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_ae_ops *ops;
ops = priv->ae_handle->dev->ops;
if (ops->get_pauseparam)
ops->get_pauseparam(priv->ae_handle, &param->autoneg,
&param->rx_pause, &param->tx_pause);
}
static int hns_set_pauseparam(struct net_device *net_dev,
struct ethtool_pauseparam *param)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_handle *h;
struct hnae_ae_ops *ops;
assert(priv || priv->ae_handle);
h = priv->ae_handle;
ops = h->dev->ops;
if (!ops->set_pauseparam)
return -ESRCH;
return ops->set_pauseparam(priv->ae_handle, param->autoneg,
param->rx_pause, param->tx_pause);
}
static int hns_get_coalesce(struct net_device *net_dev,
struct ethtool_coalesce *ec)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_ae_ops *ops;
ops = priv->ae_handle->dev->ops;
ec->use_adaptive_rx_coalesce = 1;
ec->use_adaptive_tx_coalesce = 1;
if ((!ops->get_coalesce_usecs) ||
(!ops->get_rx_max_coalesced_frames))
return -ESRCH;
ops->get_coalesce_usecs(priv->ae_handle,
&ec->tx_coalesce_usecs,
&ec->rx_coalesce_usecs);
ops->get_rx_max_coalesced_frames(
priv->ae_handle,
&ec->tx_max_coalesced_frames,
&ec->rx_max_coalesced_frames);
return 0;
}
static int hns_set_coalesce(struct net_device *net_dev,
struct ethtool_coalesce *ec)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_ae_ops *ops;
int ret;
assert(priv || priv->ae_handle);
ops = priv->ae_handle->dev->ops;
if (ec->tx_coalesce_usecs != ec->rx_coalesce_usecs)
return -EINVAL;
if (ec->rx_max_coalesced_frames != ec->tx_max_coalesced_frames)
return -EINVAL;
if ((!ops->set_coalesce_usecs) ||
(!ops->set_coalesce_frames))
return -ESRCH;
ret = ops->set_coalesce_usecs(priv->ae_handle,
ec->rx_coalesce_usecs);
if (ret)
return ret;
ret = ops->set_coalesce_frames(
priv->ae_handle,
ec->rx_max_coalesced_frames);
return ret;
}
void hns_get_channels(struct net_device *net_dev, struct ethtool_channels *ch)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
ch->max_rx = priv->ae_handle->q_num;
ch->max_tx = priv->ae_handle->q_num;
ch->rx_count = priv->ae_handle->q_num;
ch->tx_count = priv->ae_handle->q_num;
}
void hns_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
u64 *p = data;
struct hns_nic_priv *priv = netdev_priv(netdev);
struct hnae_handle *h = priv->ae_handle;
const struct rtnl_link_stats64 *net_stats;
struct rtnl_link_stats64 temp;
if (!h->dev->ops->get_stats || !h->dev->ops->update_stats) {
netdev_err(netdev, "get_stats or update_stats is null!\n");
return;
}
h->dev->ops->update_stats(h, &netdev->stats);
net_stats = dev_get_stats(netdev, &temp);
p[0] = net_stats->rx_packets;
p[1] = net_stats->tx_packets;
p[2] = net_stats->rx_bytes;
p[3] = net_stats->tx_bytes;
p[4] = net_stats->rx_errors;
p[5] = net_stats->tx_errors;
p[6] = net_stats->rx_dropped;
p[7] = net_stats->tx_dropped;
p[8] = net_stats->multicast;
p[9] = net_stats->collisions;
p[10] = net_stats->rx_over_errors;
p[11] = net_stats->rx_crc_errors;
p[12] = net_stats->rx_frame_errors;
p[13] = net_stats->rx_fifo_errors;
p[14] = net_stats->rx_missed_errors;
p[15] = net_stats->tx_aborted_errors;
p[16] = net_stats->tx_carrier_errors;
p[17] = net_stats->tx_fifo_errors;
p[18] = net_stats->tx_heartbeat_errors;
p[19] = net_stats->rx_length_errors;
p[20] = net_stats->tx_window_errors;
p[21] = net_stats->rx_compressed;
p[22] = net_stats->tx_compressed;
p[23] = netdev->rx_dropped.counter;
p[24] = netdev->tx_dropped.counter;
p[25] = priv->tx_timeout_count;
h->dev->ops->get_stats(h, &p[26]);
}
void hns_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
struct hns_nic_priv *priv = netdev_priv(netdev);
struct hnae_handle *h = priv->ae_handle;
char *buff = (char *)data;
if (!h->dev->ops->get_strings) {
netdev_err(netdev, "h->dev->ops->get_strings is null!\n");
return;
}
if (stringset == ETH_SS_TEST) {
if (priv->ae_handle->phy_if != PHY_INTERFACE_MODE_XGMII) {
memcpy(buff, hns_nic_test_strs[MAC_INTERNALLOOP_MAC],
ETH_GSTRING_LEN);
buff += ETH_GSTRING_LEN;
}
memcpy(buff, hns_nic_test_strs[MAC_INTERNALLOOP_SERDES],
ETH_GSTRING_LEN);
buff += ETH_GSTRING_LEN;
if ((priv->phy) && (!priv->phy->is_c45))
memcpy(buff, hns_nic_test_strs[MAC_INTERNALLOOP_PHY],
ETH_GSTRING_LEN);
} else {
snprintf(buff, ETH_GSTRING_LEN, "rx_packets");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_packets");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_bytes");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_bytes");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_dropped");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_dropped");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "multicast");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "collisions");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_over_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_crc_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_frame_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_fifo_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_missed_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_aborted_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_carrier_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_fifo_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_heartbeat_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_length_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_window_errors");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "rx_compressed");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "tx_compressed");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "netdev_rx_dropped");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "netdev_tx_dropped");
buff = buff + ETH_GSTRING_LEN;
snprintf(buff, ETH_GSTRING_LEN, "netdev_tx_timeout");
buff = buff + ETH_GSTRING_LEN;
h->dev->ops->get_strings(h, stringset, (u8 *)buff);
}
}
int hns_get_sset_count(struct net_device *netdev, int stringset)
{
struct hns_nic_priv *priv = netdev_priv(netdev);
struct hnae_handle *h = priv->ae_handle;
struct hnae_ae_ops *ops = h->dev->ops;
if (!ops->get_sset_count) {
netdev_err(netdev, "get_sset_count is null!\n");
return -EOPNOTSUPP;
}
if (stringset == ETH_SS_TEST) {
u32 cnt = (sizeof(hns_nic_test_strs) / ETH_GSTRING_LEN);
if (priv->ae_handle->phy_if == PHY_INTERFACE_MODE_XGMII)
cnt--;
if ((!priv->phy) || (priv->phy->is_c45))
cnt--;
return cnt;
} else {
return (HNS_NET_STATS_CNT + ops->get_sset_count(h, stringset));
}
}
int hns_phy_led_set(struct net_device *netdev, int value)
{
int retval;
struct hns_nic_priv *priv = netdev_priv(netdev);
struct phy_device *phy_dev = priv->phy;
retval = phy_write(phy_dev, HNS_PHY_PAGE_REG, HNS_PHY_PAGE_LED);
retval |= phy_write(phy_dev, HNS_LED_FC_REG, value);
retval |= phy_write(phy_dev, HNS_PHY_PAGE_REG, HNS_PHY_PAGE_COPPER);
if (retval) {
netdev_err(netdev, "mdiobus_write fail !\n");
return retval;
}
return 0;
}
int hns_set_phys_id(struct net_device *netdev, enum ethtool_phys_id_state state)
{
struct hns_nic_priv *priv = netdev_priv(netdev);
struct hnae_handle *h = priv->ae_handle;
struct phy_device *phy_dev = priv->phy;
int ret;
if (phy_dev)
switch (state) {
case ETHTOOL_ID_ACTIVE:
ret = phy_write(phy_dev, HNS_PHY_PAGE_REG,
HNS_PHY_PAGE_LED);
if (ret)
return ret;
priv->phy_led_val = phy_read(phy_dev, HNS_LED_FC_REG);
ret = phy_write(phy_dev, HNS_PHY_PAGE_REG,
HNS_PHY_PAGE_COPPER);
if (ret)
return ret;
return 2;
case ETHTOOL_ID_ON:
ret = hns_phy_led_set(netdev, HNS_LED_FORCE_ON);
if (ret)
return ret;
break;
case ETHTOOL_ID_OFF:
ret = hns_phy_led_set(netdev, HNS_LED_FORCE_OFF);
if (ret)
return ret;
break;
case ETHTOOL_ID_INACTIVE:
ret = phy_write(phy_dev, HNS_PHY_PAGE_REG,
HNS_PHY_PAGE_LED);
if (ret)
return ret;
ret = phy_write(phy_dev, HNS_LED_FC_REG,
priv->phy_led_val);
if (ret)
return ret;
ret = phy_write(phy_dev, HNS_PHY_PAGE_REG,
HNS_PHY_PAGE_COPPER);
if (ret)
return ret;
break;
default:
return -EINVAL;
}
else
switch (state) {
case ETHTOOL_ID_ACTIVE:
return h->dev->ops->set_led_id(h, HNAE_LED_ACTIVE);
case ETHTOOL_ID_ON:
return h->dev->ops->set_led_id(h, HNAE_LED_ON);
case ETHTOOL_ID_OFF:
return h->dev->ops->set_led_id(h, HNAE_LED_OFF);
case ETHTOOL_ID_INACTIVE:
return h->dev->ops->set_led_id(h, HNAE_LED_INACTIVE);
default:
return -EINVAL;
}
return 0;
}
void hns_get_regs(struct net_device *net_dev, struct ethtool_regs *cmd,
void *data)
{
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_ae_ops *ops;
assert(priv || priv->ae_handle);
ops = priv->ae_handle->dev->ops;
cmd->version = HNS_CHIP_VERSION;
if (!ops->get_regs) {
netdev_err(net_dev, "ops->get_regs is null!\n");
return;
}
ops->get_regs(priv->ae_handle, data);
}
static int hns_get_regs_len(struct net_device *net_dev)
{
u32 reg_num;
struct hns_nic_priv *priv = netdev_priv(net_dev);
struct hnae_ae_ops *ops;
assert(priv || priv->ae_handle);
ops = priv->ae_handle->dev->ops;
if (!ops->get_regs_len) {
netdev_err(net_dev, "ops->get_regs_len is null!\n");
return -EOPNOTSUPP;
}
reg_num = ops->get_regs_len(priv->ae_handle);
if (reg_num > 0)
return reg_num * sizeof(u32);
else
return reg_num;
}
static int hns_nic_nway_reset(struct net_device *netdev)
{
int ret = 0;
struct hns_nic_priv *priv = netdev_priv(netdev);
struct phy_device *phy = priv->phy;
if (netif_running(netdev)) {
if (phy)
ret = genphy_restart_aneg(phy);
}
return ret;
}
static u32
hns_get_rss_key_size(struct net_device *netdev)
{
struct hns_nic_priv *priv = netdev_priv(netdev);
struct hnae_ae_ops *ops;
if (AE_IS_VER1(priv->enet_ver)) {
netdev_err(netdev,
"RSS feature is not supported on this hardware\n");
return 0;
}
ops = priv->ae_handle->dev->ops;
return ops->get_rss_key_size(priv->ae_handle);
}
static u32
hns_get_rss_indir_size(struct net_device *netdev)
{
struct hns_nic_priv *priv = netdev_priv(netdev);
struct hnae_ae_ops *ops;
if (AE_IS_VER1(priv->enet_ver)) {
netdev_err(netdev,
"RSS feature is not supported on this hardware\n");
return 0;
}
ops = priv->ae_handle->dev->ops;
return ops->get_rss_indir_size(priv->ae_handle);
}
static int
hns_get_rss(struct net_device *netdev, u32 *indir, u8 *key, u8 *hfunc)
{
struct hns_nic_priv *priv = netdev_priv(netdev);
struct hnae_ae_ops *ops;
if (AE_IS_VER1(priv->enet_ver)) {
netdev_err(netdev,
"RSS feature is not supported on this hardware\n");
return -EOPNOTSUPP;
}
ops = priv->ae_handle->dev->ops;
if (!indir)
return 0;
return ops->get_rss(priv->ae_handle, indir, key, hfunc);
}
static int
hns_set_rss(struct net_device *netdev, const u32 *indir, const u8 *key,
const u8 hfunc)
{
struct hns_nic_priv *priv = netdev_priv(netdev);
struct hnae_ae_ops *ops;
if (AE_IS_VER1(priv->enet_ver)) {
netdev_err(netdev,
"RSS feature is not supported on this hardware\n");
return -EOPNOTSUPP;
}
ops = priv->ae_handle->dev->ops;
if (key ||
(hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP))
return -EOPNOTSUPP;
if (!indir)
return 0;
return ops->set_rss(priv->ae_handle, indir, key, hfunc);
}
static int hns_get_rxnfc(struct net_device *netdev,
struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
struct hns_nic_priv *priv = netdev_priv(netdev);
switch (cmd->cmd) {
case ETHTOOL_GRXRINGS:
cmd->data = priv->ae_handle->q_num;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
void hns_ethtool_set_ops(struct net_device *ndev)
{
ndev->ethtool_ops = &hns_ethtool_ops;
}
