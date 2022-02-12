static void fm10k_get_stat_strings(struct net_device *dev, u8 *data)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_iov_data *iov_data = interface->iov_data;
char *p = (char *)data;
unsigned int i;
unsigned int j;
for (i = 0; i < FM10K_NETDEV_STATS_LEN; i++) {
memcpy(p, fm10k_gstrings_net_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < FM10K_GLOBAL_STATS_LEN; i++) {
memcpy(p, fm10k_gstrings_global_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
if (interface->flags & FM10K_FLAG_DEBUG_STATS) {
for (i = 0; i < FM10K_DEBUG_STATS_LEN; i++) {
memcpy(p, fm10k_gstrings_debug_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
}
for (i = 0; i < FM10K_MBX_STATS_LEN; i++) {
memcpy(p, fm10k_gstrings_mbx_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
if (interface->hw.mac.type != fm10k_mac_vf) {
for (i = 0; i < FM10K_PF_STATS_LEN; i++) {
memcpy(p, fm10k_gstrings_pf_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
}
if ((interface->flags & FM10K_FLAG_DEBUG_STATS) && iov_data) {
for (i = 0; i < iov_data->num_vfs; i++) {
for (j = 0; j < FM10K_MBX_STATS_LEN; j++) {
snprintf(p,
ETH_GSTRING_LEN,
"vf_%u_%s", i,
fm10k_gstrings_mbx_stats[j].stat_string);
p += ETH_GSTRING_LEN;
}
}
}
for (i = 0; i < interface->hw.mac.max_queues; i++) {
snprintf(p, ETH_GSTRING_LEN, "tx_queue_%u_packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "tx_queue_%u_bytes", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "rx_queue_%u_packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "rx_queue_%u_bytes", i);
p += ETH_GSTRING_LEN;
}
}
static void fm10k_get_strings(struct net_device *dev,
u32 stringset, u8 *data)
{
char *p = (char *)data;
switch (stringset) {
case ETH_SS_TEST:
memcpy(data, *fm10k_gstrings_test,
FM10K_TEST_LEN * ETH_GSTRING_LEN);
break;
case ETH_SS_STATS:
fm10k_get_stat_strings(dev, data);
break;
case ETH_SS_PRIV_FLAGS:
memcpy(p, fm10k_prv_flags,
FM10K_PRV_FLAG_LEN * ETH_GSTRING_LEN);
break;
}
}
static int fm10k_get_sset_count(struct net_device *dev, int sset)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_iov_data *iov_data = interface->iov_data;
struct fm10k_hw *hw = &interface->hw;
int stats_len = FM10K_STATIC_STATS_LEN;
switch (sset) {
case ETH_SS_TEST:
return FM10K_TEST_LEN;
case ETH_SS_STATS:
stats_len += FM10K_QUEUE_STATS_LEN(hw->mac.max_queues);
if (hw->mac.type != fm10k_mac_vf)
stats_len += FM10K_PF_STATS_LEN;
if (interface->flags & FM10K_FLAG_DEBUG_STATS) {
stats_len += FM10K_DEBUG_STATS_LEN;
if (iov_data)
stats_len += FM10K_MBX_STATS_LEN * iov_data->num_vfs;
}
return stats_len;
case ETH_SS_PRIV_FLAGS:
return FM10K_PRV_FLAG_LEN;
default:
return -EOPNOTSUPP;
}
}
static void fm10k_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats __always_unused *stats,
u64 *data)
{
const int stat_count = sizeof(struct fm10k_queue_stats) / sizeof(u64);
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_iov_data *iov_data = interface->iov_data;
struct net_device_stats *net_stats = &netdev->stats;
char *p;
int i, j;
fm10k_update_stats(interface);
for (i = 0; i < FM10K_NETDEV_STATS_LEN; i++) {
p = (char *)net_stats + fm10k_gstrings_net_stats[i].stat_offset;
*(data++) = (fm10k_gstrings_net_stats[i].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
for (i = 0; i < FM10K_GLOBAL_STATS_LEN; i++) {
p = (char *)interface +
fm10k_gstrings_global_stats[i].stat_offset;
*(data++) = (fm10k_gstrings_global_stats[i].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
if (interface->flags & FM10K_FLAG_DEBUG_STATS) {
for (i = 0; i < FM10K_DEBUG_STATS_LEN; i++) {
p = (char *)interface + fm10k_gstrings_debug_stats[i].stat_offset;
*(data++) = (fm10k_gstrings_debug_stats[i].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
}
for (i = 0; i < FM10K_MBX_STATS_LEN; i++) {
p = (char *)&interface->hw.mbx + fm10k_gstrings_mbx_stats[i].stat_offset;
*(data++) = (fm10k_gstrings_mbx_stats[i].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
if (interface->hw.mac.type != fm10k_mac_vf) {
for (i = 0; i < FM10K_PF_STATS_LEN; i++) {
p = (char *)interface +
fm10k_gstrings_pf_stats[i].stat_offset;
*(data++) = (fm10k_gstrings_pf_stats[i].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
}
if ((interface->flags & FM10K_FLAG_DEBUG_STATS) && iov_data) {
for (i = 0; i < iov_data->num_vfs; i++) {
struct fm10k_vf_info *vf_info;
vf_info = &iov_data->vf_info[i];
if (!vf_info) {
data += FM10K_MBX_STATS_LEN;
continue;
}
for (j = 0; j < FM10K_MBX_STATS_LEN; j++) {
p = (char *)&vf_info->mbx + fm10k_gstrings_mbx_stats[j].stat_offset;
*(data++) = (fm10k_gstrings_mbx_stats[j].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
}
}
for (i = 0; i < interface->hw.mac.max_queues; i++) {
struct fm10k_ring *ring;
u64 *queue_stat;
ring = interface->tx_ring[i];
if (ring)
queue_stat = (u64 *)&ring->stats;
for (j = 0; j < stat_count; j++)
*(data++) = ring ? queue_stat[j] : 0;
ring = interface->rx_ring[i];
if (ring)
queue_stat = (u64 *)&ring->stats;
for (j = 0; j < stat_count; j++)
*(data++) = ring ? queue_stat[j] : 0;
}
}
static void fm10k_get_reg_q(struct fm10k_hw *hw, u32 *buff, int i)
{
int idx = 0;
buff[idx++] = fm10k_read_reg(hw, FM10K_RDBAL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_RDBAH(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_RDLEN(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TPH_RXCTRL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_RDH(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_RDT(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_RXQCTL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_RXDCTL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_RXINT(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_SRRCTL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_QPRC(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_QPRDC(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_QBRC_L(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_QBRC_H(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TDBAL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TDBAH(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TDLEN(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TPH_TXCTRL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TDH(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TDT(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TXDCTL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TXQCTL(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TXINT(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_QPTC(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_QBTC_L(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_QBTC_H(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TQDLOC(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_TX_SGLORT(i));
buff[idx++] = fm10k_read_reg(hw, FM10K_PFVTCTL(i));
BUG_ON(idx != FM10K_REGS_LEN_Q);
}
static void fm10k_get_reg_vsi(struct fm10k_hw *hw, u32 *buff, int i)
{
int idx = 0, j;
buff[idx++] = fm10k_read_reg(hw, FM10K_MRQC(i));
for (j = 0; j < 10; j++)
buff[idx++] = fm10k_read_reg(hw, FM10K_RSSRK(i, j));
for (j = 0; j < 32; j++)
buff[idx++] = fm10k_read_reg(hw, FM10K_RETA(i, j));
BUG_ON(idx != FM10K_REGS_LEN_VSI);
}
static void fm10k_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *p)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_hw *hw = &interface->hw;
u32 *buff = p;
u16 i;
regs->version = (1 << 24) | (hw->revision_id << 16) | hw->device_id;
switch (hw->mac.type) {
case fm10k_mac_pf:
*(buff++) = fm10k_read_reg(hw, FM10K_CTRL);
*(buff++) = fm10k_read_reg(hw, FM10K_CTRL_EXT);
*(buff++) = fm10k_read_reg(hw, FM10K_GCR);
*(buff++) = fm10k_read_reg(hw, FM10K_GCR_EXT);
for (i = 0; i < 8; i++) {
*(buff++) = fm10k_read_reg(hw, FM10K_DGLORTMAP(i));
*(buff++) = fm10k_read_reg(hw, FM10K_DGLORTDEC(i));
}
for (i = 0; i < 65; i++) {
fm10k_get_reg_vsi(hw, buff, i);
buff += FM10K_REGS_LEN_VSI;
}
*(buff++) = fm10k_read_reg(hw, FM10K_DMA_CTRL);
*(buff++) = fm10k_read_reg(hw, FM10K_DMA_CTRL2);
for (i = 0; i < FM10K_MAX_QUEUES_PF; i++) {
fm10k_get_reg_q(hw, buff, i);
buff += FM10K_REGS_LEN_Q;
}
*(buff++) = fm10k_read_reg(hw, FM10K_TPH_CTRL);
for (i = 0; i < 8; i++)
*(buff++) = fm10k_read_reg(hw, FM10K_INT_MAP(i));
for (i = 0; i < 130; i++)
*(buff++) = fm10k_read_reg(hw, FM10K_ITR(i));
break;
case fm10k_mac_vf:
*(buff++) = fm10k_read_reg(hw, FM10K_VFCTRL);
*(buff++) = fm10k_read_reg(hw, FM10K_VFINT_MAP);
*(buff++) = fm10k_read_reg(hw, FM10K_VFSYSTIME);
for (i = 0; i < 8; i++)
*(buff++) = fm10k_read_reg(hw, FM10K_VFITR(i));
fm10k_get_reg_vsi(hw, buff, 0);
buff += FM10K_REGS_LEN_VSI;
for (i = 0; i < FM10K_MAX_QUEUES_POOL; i++) {
if (i < hw->mac.max_queues)
fm10k_get_reg_q(hw, buff, i);
else
memset(buff, 0, sizeof(u32) * FM10K_REGS_LEN_Q);
buff += FM10K_REGS_LEN_Q;
}
break;
default:
return;
}
}
static int fm10k_get_regs_len(struct net_device *netdev)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_hw *hw = &interface->hw;
switch (hw->mac.type) {
case fm10k_mac_pf:
return FM10K_REGS_LEN_PF * sizeof(u32);
case fm10k_mac_vf:
return FM10K_REGS_LEN_VF * sizeof(u32);
default:
return 0;
}
}
static void fm10k_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct fm10k_intfc *interface = netdev_priv(dev);
strncpy(info->driver, fm10k_driver_name,
sizeof(info->driver) - 1);
strncpy(info->version, fm10k_driver_version,
sizeof(info->version) - 1);
strncpy(info->bus_info, pci_name(interface->pdev),
sizeof(info->bus_info) - 1);
}
static void fm10k_get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *pause)
{
struct fm10k_intfc *interface = netdev_priv(dev);
pause->autoneg = 0;
pause->tx_pause = 1;
pause->rx_pause = interface->rx_pause ? 1 : 0;
}
static int fm10k_set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *pause)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_hw *hw = &interface->hw;
if (pause->autoneg || !pause->tx_pause)
return -EINVAL;
if (hw->mac.type == fm10k_mac_pf)
interface->rx_pause = pause->rx_pause ? ~0 : 0;
else if (pause->rx_pause)
return -EINVAL;
if (netif_running(dev))
fm10k_update_rx_drop_en(interface);
return 0;
}
static u32 fm10k_get_msglevel(struct net_device *netdev)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
return interface->msg_enable;
}
static void fm10k_set_msglevel(struct net_device *netdev, u32 data)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
interface->msg_enable = data;
}
static void fm10k_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
ring->rx_max_pending = FM10K_MAX_RXD;
ring->tx_max_pending = FM10K_MAX_TXD;
ring->rx_mini_max_pending = 0;
ring->rx_jumbo_max_pending = 0;
ring->rx_pending = interface->rx_ring_count;
ring->tx_pending = interface->tx_ring_count;
ring->rx_mini_pending = 0;
ring->rx_jumbo_pending = 0;
}
static int fm10k_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_ring *temp_ring;
int i, err = 0;
u32 new_rx_count, new_tx_count;
if ((ring->rx_mini_pending) || (ring->rx_jumbo_pending))
return -EINVAL;
new_tx_count = clamp_t(u32, ring->tx_pending,
FM10K_MIN_TXD, FM10K_MAX_TXD);
new_tx_count = ALIGN(new_tx_count, FM10K_REQ_TX_DESCRIPTOR_MULTIPLE);
new_rx_count = clamp_t(u32, ring->rx_pending,
FM10K_MIN_RXD, FM10K_MAX_RXD);
new_rx_count = ALIGN(new_rx_count, FM10K_REQ_RX_DESCRIPTOR_MULTIPLE);
if ((new_tx_count == interface->tx_ring_count) &&
(new_rx_count == interface->rx_ring_count)) {
return 0;
}
while (test_and_set_bit(__FM10K_RESETTING, &interface->state))
usleep_range(1000, 2000);
if (!netif_running(interface->netdev)) {
for (i = 0; i < interface->num_tx_queues; i++)
interface->tx_ring[i]->count = new_tx_count;
for (i = 0; i < interface->num_rx_queues; i++)
interface->rx_ring[i]->count = new_rx_count;
interface->tx_ring_count = new_tx_count;
interface->rx_ring_count = new_rx_count;
goto clear_reset;
}
i = max_t(int, interface->num_tx_queues, interface->num_rx_queues);
temp_ring = vmalloc(i * sizeof(struct fm10k_ring));
if (!temp_ring) {
err = -ENOMEM;
goto clear_reset;
}
fm10k_down(interface);
if (new_tx_count != interface->tx_ring_count) {
for (i = 0; i < interface->num_tx_queues; i++) {
memcpy(&temp_ring[i], interface->tx_ring[i],
sizeof(struct fm10k_ring));
temp_ring[i].count = new_tx_count;
err = fm10k_setup_tx_resources(&temp_ring[i]);
if (err) {
while (i) {
i--;
fm10k_free_tx_resources(&temp_ring[i]);
}
goto err_setup;
}
}
for (i = 0; i < interface->num_tx_queues; i++) {
fm10k_free_tx_resources(interface->tx_ring[i]);
memcpy(interface->tx_ring[i], &temp_ring[i],
sizeof(struct fm10k_ring));
}
interface->tx_ring_count = new_tx_count;
}
if (new_rx_count != interface->rx_ring_count) {
for (i = 0; i < interface->num_rx_queues; i++) {
memcpy(&temp_ring[i], interface->rx_ring[i],
sizeof(struct fm10k_ring));
temp_ring[i].count = new_rx_count;
err = fm10k_setup_rx_resources(&temp_ring[i]);
if (err) {
while (i) {
i--;
fm10k_free_rx_resources(&temp_ring[i]);
}
goto err_setup;
}
}
for (i = 0; i < interface->num_rx_queues; i++) {
fm10k_free_rx_resources(interface->rx_ring[i]);
memcpy(interface->rx_ring[i], &temp_ring[i],
sizeof(struct fm10k_ring));
}
interface->rx_ring_count = new_rx_count;
}
err_setup:
fm10k_up(interface);
vfree(temp_ring);
clear_reset:
clear_bit(__FM10K_RESETTING, &interface->state);
return err;
}
static int fm10k_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct fm10k_intfc *interface = netdev_priv(dev);
ec->use_adaptive_tx_coalesce =
!!(interface->tx_itr & FM10K_ITR_ADAPTIVE);
ec->tx_coalesce_usecs = interface->tx_itr & ~FM10K_ITR_ADAPTIVE;
ec->use_adaptive_rx_coalesce =
!!(interface->rx_itr & FM10K_ITR_ADAPTIVE);
ec->rx_coalesce_usecs = interface->rx_itr & ~FM10K_ITR_ADAPTIVE;
return 0;
}
static int fm10k_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_q_vector *qv;
u16 tx_itr, rx_itr;
int i;
if ((ec->rx_coalesce_usecs > FM10K_ITR_MAX) ||
(ec->tx_coalesce_usecs > FM10K_ITR_MAX))
return -EINVAL;
tx_itr = ec->tx_coalesce_usecs;
rx_itr = ec->rx_coalesce_usecs;
if (ec->use_adaptive_tx_coalesce)
tx_itr = FM10K_ITR_ADAPTIVE | FM10K_ITR_10K;
if (ec->use_adaptive_rx_coalesce)
rx_itr = FM10K_ITR_ADAPTIVE | FM10K_ITR_20K;
interface->tx_itr = tx_itr;
interface->rx_itr = rx_itr;
for (i = 0; i < interface->num_q_vectors; i++) {
qv = interface->q_vector[i];
qv->tx.itr = tx_itr;
qv->rx.itr = rx_itr;
}
return 0;
}
static int fm10k_get_rss_hash_opts(struct fm10k_intfc *interface,
struct ethtool_rxnfc *cmd)
{
cmd->data = 0;
switch (cmd->flow_type) {
case TCP_V4_FLOW:
case TCP_V6_FLOW:
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
case UDP_V4_FLOW:
if (interface->flags & FM10K_FLAG_RSS_FIELD_IPV4_UDP)
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
case SCTP_V4_FLOW:
case SCTP_V6_FLOW:
case AH_ESP_V4_FLOW:
case AH_ESP_V6_FLOW:
case AH_V4_FLOW:
case AH_V6_FLOW:
case ESP_V4_FLOW:
case ESP_V6_FLOW:
case IPV4_FLOW:
case IPV6_FLOW:
cmd->data |= RXH_IP_SRC | RXH_IP_DST;
break;
case UDP_V6_FLOW:
if (interface->flags & FM10K_FLAG_RSS_FIELD_IPV6_UDP)
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
cmd->data |= RXH_IP_SRC | RXH_IP_DST;
break;
default:
return -EINVAL;
}
return 0;
}
static int fm10k_get_rxnfc(struct net_device *dev, struct ethtool_rxnfc *cmd,
u32 __always_unused *rule_locs)
{
struct fm10k_intfc *interface = netdev_priv(dev);
int ret = -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_GRXRINGS:
cmd->data = interface->num_rx_queues;
ret = 0;
break;
case ETHTOOL_GRXFH:
ret = fm10k_get_rss_hash_opts(interface, cmd);
break;
default:
break;
}
return ret;
}
static int fm10k_set_rss_hash_opt(struct fm10k_intfc *interface,
struct ethtool_rxnfc *nfc)
{
u32 flags = interface->flags;
if (nfc->data & ~(RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3))
return -EINVAL;
switch (nfc->flow_type) {
case TCP_V4_FLOW:
case TCP_V6_FLOW:
if (!(nfc->data & RXH_IP_SRC) ||
!(nfc->data & RXH_IP_DST) ||
!(nfc->data & RXH_L4_B_0_1) ||
!(nfc->data & RXH_L4_B_2_3))
return -EINVAL;
break;
case UDP_V4_FLOW:
if (!(nfc->data & RXH_IP_SRC) ||
!(nfc->data & RXH_IP_DST))
return -EINVAL;
switch (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
flags &= ~FM10K_FLAG_RSS_FIELD_IPV4_UDP;
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
flags |= FM10K_FLAG_RSS_FIELD_IPV4_UDP;
break;
default:
return -EINVAL;
}
break;
case UDP_V6_FLOW:
if (!(nfc->data & RXH_IP_SRC) ||
!(nfc->data & RXH_IP_DST))
return -EINVAL;
switch (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
flags &= ~FM10K_FLAG_RSS_FIELD_IPV6_UDP;
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
flags |= FM10K_FLAG_RSS_FIELD_IPV6_UDP;
break;
default:
return -EINVAL;
}
break;
case AH_ESP_V4_FLOW:
case AH_V4_FLOW:
case ESP_V4_FLOW:
case SCTP_V4_FLOW:
case AH_ESP_V6_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case SCTP_V6_FLOW:
if (!(nfc->data & RXH_IP_SRC) ||
!(nfc->data & RXH_IP_DST) ||
(nfc->data & RXH_L4_B_0_1) ||
(nfc->data & RXH_L4_B_2_3))
return -EINVAL;
break;
default:
return -EINVAL;
}
if (flags != interface->flags) {
struct fm10k_hw *hw = &interface->hw;
u32 mrqc;
if ((flags & UDP_RSS_FLAGS) &&
!(interface->flags & UDP_RSS_FLAGS))
netif_warn(interface, drv, interface->netdev,
"enabling UDP RSS: fragmented packets may arrive out of order to the stack above\n");
interface->flags = flags;
mrqc = FM10K_MRQC_IPV4 |
FM10K_MRQC_TCP_IPV4 |
FM10K_MRQC_IPV6 |
FM10K_MRQC_TCP_IPV6;
if (flags & FM10K_FLAG_RSS_FIELD_IPV4_UDP)
mrqc |= FM10K_MRQC_UDP_IPV4;
if (flags & FM10K_FLAG_RSS_FIELD_IPV6_UDP)
mrqc |= FM10K_MRQC_UDP_IPV6;
fm10k_write_reg(hw, FM10K_MRQC(0), mrqc);
}
return 0;
}
static int fm10k_set_rxnfc(struct net_device *dev, struct ethtool_rxnfc *cmd)
{
struct fm10k_intfc *interface = netdev_priv(dev);
int ret = -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_SRXFH:
ret = fm10k_set_rss_hash_opt(interface, cmd);
break;
default:
break;
}
return ret;
}
static int fm10k_mbx_test(struct fm10k_intfc *interface, u64 *data)
{
struct fm10k_hw *hw = &interface->hw;
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 attr_flag, test_msg[6];
unsigned long timeout;
int err;
if (hw->mac.type != fm10k_mac_vf)
return 0;
for (attr_flag = (1 << FM10K_TEST_MSG_UNSET);
attr_flag < (1 << (2 * FM10K_TEST_MSG_NESTED));
attr_flag += attr_flag) {
fm10k_tlv_msg_test_create(test_msg, attr_flag);
fm10k_mbx_lock(interface);
mbx->test_result = FM10K_NOT_IMPLEMENTED;
err = mbx->ops.enqueue_tx(hw, mbx, test_msg);
fm10k_mbx_unlock(interface);
timeout = jiffies + HZ;
do {
if (err < 0)
goto err_out;
usleep_range(500, 1000);
fm10k_mbx_lock(interface);
mbx->ops.process(hw, mbx);
fm10k_mbx_unlock(interface);
err = mbx->test_result;
if (!err)
break;
} while (time_is_after_jiffies(timeout));
if (err)
goto err_out;
}
err_out:
*data = err < 0 ? (attr_flag) : (err > 0);
return err;
}
static void fm10k_self_test(struct net_device *dev,
struct ethtool_test *eth_test, u64 *data)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_hw *hw = &interface->hw;
memset(data, 0, sizeof(*data) * FM10K_TEST_LEN);
if (FM10K_REMOVED(hw)) {
netif_err(interface, drv, dev,
"Interface removed - test blocked\n");
eth_test->flags |= ETH_TEST_FL_FAILED;
return;
}
if (fm10k_mbx_test(interface, &data[FM10K_TEST_MBX]))
eth_test->flags |= ETH_TEST_FL_FAILED;
}
static u32 fm10k_get_priv_flags(struct net_device *netdev)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
u32 priv_flags = 0;
if (interface->flags & FM10K_FLAG_DEBUG_STATS)
priv_flags |= 1 << FM10K_PRV_FLAG_DEBUG_STATS;
return priv_flags;
}
static int fm10k_set_priv_flags(struct net_device *netdev, u32 priv_flags)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
if (priv_flags >= (1 << FM10K_PRV_FLAG_LEN))
return -EINVAL;
if (priv_flags & (1 << FM10K_PRV_FLAG_DEBUG_STATS))
interface->flags |= FM10K_FLAG_DEBUG_STATS;
else
interface->flags &= ~FM10K_FLAG_DEBUG_STATS;
return 0;
}
static u32 fm10k_get_reta_size(struct net_device __always_unused *netdev)
{
return FM10K_RETA_SIZE * FM10K_RETA_ENTRIES_PER_REG;
}
static int fm10k_get_reta(struct net_device *netdev, u32 *indir)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
int i;
if (!indir)
return 0;
for (i = 0; i < FM10K_RETA_SIZE; i++, indir += 4) {
u32 reta = interface->reta[i];
indir[0] = (reta << 24) >> 24;
indir[1] = (reta << 16) >> 24;
indir[2] = (reta << 8) >> 24;
indir[3] = (reta) >> 24;
}
return 0;
}
static int fm10k_set_reta(struct net_device *netdev, const u32 *indir)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_hw *hw = &interface->hw;
int i;
u16 rss_i;
if (!indir)
return 0;
rss_i = interface->ring_feature[RING_F_RSS].indices;
for (i = fm10k_get_reta_size(netdev); i--;) {
if (indir[i] < rss_i)
continue;
return -EINVAL;
}
for (i = 0; i < FM10K_RETA_SIZE; i++, indir += 4) {
u32 reta = indir[0] |
(indir[1] << 8) |
(indir[2] << 16) |
(indir[3] << 24);
if (interface->reta[i] == reta)
continue;
interface->reta[i] = reta;
fm10k_write_reg(hw, FM10K_RETA(0, i), reta);
}
return 0;
}
static u32 fm10k_get_rssrk_size(struct net_device __always_unused *netdev)
{
return FM10K_RSSRK_SIZE * FM10K_RSSRK_ENTRIES_PER_REG;
}
static int fm10k_get_rssh(struct net_device *netdev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
int i, err;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
err = fm10k_get_reta(netdev, indir);
if (err || !key)
return err;
for (i = 0; i < FM10K_RSSRK_SIZE; i++, key += 4)
*(__le32 *)key = cpu_to_le32(interface->rssrk[i]);
return 0;
}
static int fm10k_set_rssh(struct net_device *netdev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct fm10k_hw *hw = &interface->hw;
int i, err;
if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP)
return -EOPNOTSUPP;
err = fm10k_set_reta(netdev, indir);
if (err || !key)
return err;
for (i = 0; i < FM10K_RSSRK_SIZE; i++, key += 4) {
u32 rssrk = le32_to_cpu(*(__le32 *)key);
if (interface->rssrk[i] == rssrk)
continue;
interface->rssrk[i] = rssrk;
fm10k_write_reg(hw, FM10K_RSSRK(0, i), rssrk);
}
return 0;
}
static unsigned int fm10k_max_channels(struct net_device *dev)
{
struct fm10k_intfc *interface = netdev_priv(dev);
unsigned int max_combined = interface->hw.mac.max_queues;
u8 tcs = netdev_get_num_tc(dev);
if (tcs > 1)
max_combined = 1 << (fls(max_combined / tcs) - 1);
return max_combined;
}
static void fm10k_get_channels(struct net_device *dev,
struct ethtool_channels *ch)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_hw *hw = &interface->hw;
ch->max_combined = fm10k_max_channels(dev);
ch->max_other = NON_Q_VECTORS(hw);
ch->other_count = ch->max_other;
ch->combined_count = interface->ring_feature[RING_F_RSS].indices;
}
static int fm10k_set_channels(struct net_device *dev,
struct ethtool_channels *ch)
{
struct fm10k_intfc *interface = netdev_priv(dev);
unsigned int count = ch->combined_count;
struct fm10k_hw *hw = &interface->hw;
if (!count || ch->rx_count || ch->tx_count)
return -EINVAL;
if (ch->other_count != NON_Q_VECTORS(hw))
return -EINVAL;
if (count > fm10k_max_channels(dev))
return -EINVAL;
interface->ring_feature[RING_F_RSS].limit = count;
return fm10k_setup_tc(dev, netdev_get_num_tc(dev));
}
static int fm10k_get_ts_info(struct net_device *dev,
struct ethtool_ts_info *info)
{
struct fm10k_intfc *interface = netdev_priv(dev);
info->so_timestamping =
SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
if (interface->ptp_clock)
info->phc_index = ptp_clock_index(interface->ptp_clock);
else
info->phc_index = -1;
info->tx_types = (1 << HWTSTAMP_TX_OFF) |
(1 << HWTSTAMP_TX_ON);
info->rx_filters = (1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_ALL);
return 0;
}
void fm10k_set_ethtool_ops(struct net_device *dev)
{
dev->ethtool_ops = &fm10k_ethtool_ops;
}
