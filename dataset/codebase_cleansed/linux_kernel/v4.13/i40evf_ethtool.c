static int i40evf_get_link_ksettings(struct net_device *netdev,
struct ethtool_link_ksettings *cmd)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
ethtool_link_ksettings_zero_link_mode(cmd, supported);
cmd->base.autoneg = AUTONEG_DISABLE;
cmd->base.port = PORT_NONE;
switch (adapter->link_speed) {
case I40E_LINK_SPEED_40GB:
cmd->base.speed = SPEED_40000;
break;
case I40E_LINK_SPEED_25GB:
#ifdef SPEED_25000
cmd->base.speed = SPEED_25000;
#else
netdev_info(netdev,
"Speed is 25G, display not supported by this version of ethtool.\n");
#endif
break;
case I40E_LINK_SPEED_20GB:
cmd->base.speed = SPEED_20000;
break;
case I40E_LINK_SPEED_10GB:
cmd->base.speed = SPEED_10000;
break;
case I40E_LINK_SPEED_1GB:
cmd->base.speed = SPEED_1000;
break;
case I40E_LINK_SPEED_100MB:
cmd->base.speed = SPEED_100;
break;
default:
break;
}
cmd->base.duplex = DUPLEX_FULL;
return 0;
}
static int i40evf_get_sset_count(struct net_device *netdev, int sset)
{
if (sset == ETH_SS_STATS)
return I40EVF_STATS_LEN(netdev);
else if (sset == ETH_SS_PRIV_FLAGS)
return I40EVF_PRIV_FLAGS_STR_LEN;
else
return -EINVAL;
}
static void i40evf_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
int i, j;
char *p;
for (i = 0; i < I40EVF_GLOBAL_STATS_LEN; i++) {
p = (char *)adapter + i40evf_gstrings_stats[i].stat_offset;
data[i] = *(u64 *)p;
}
for (j = 0; j < adapter->num_active_queues; j++) {
data[i++] = adapter->tx_rings[j].stats.packets;
data[i++] = adapter->tx_rings[j].stats.bytes;
}
for (j = 0; j < adapter->num_active_queues; j++) {
data[i++] = adapter->rx_rings[j].stats.packets;
data[i++] = adapter->rx_rings[j].stats.bytes;
}
}
static void i40evf_get_strings(struct net_device *netdev, u32 sset, u8 *data)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
u8 *p = data;
int i;
if (sset == ETH_SS_STATS) {
for (i = 0; i < I40EVF_GLOBAL_STATS_LEN; i++) {
memcpy(p, i40evf_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < adapter->num_active_queues; i++) {
snprintf(p, ETH_GSTRING_LEN, "tx-%u.packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "tx-%u.bytes", i);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < adapter->num_active_queues; i++) {
snprintf(p, ETH_GSTRING_LEN, "rx-%u.packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "rx-%u.bytes", i);
p += ETH_GSTRING_LEN;
}
} else if (sset == ETH_SS_PRIV_FLAGS) {
for (i = 0; i < I40EVF_PRIV_FLAGS_STR_LEN; i++) {
snprintf(p, ETH_GSTRING_LEN, "%s",
i40evf_gstrings_priv_flags[i].flag_string);
p += ETH_GSTRING_LEN;
}
}
}
static u32 i40evf_get_priv_flags(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
u32 i, ret_flags = 0;
for (i = 0; i < I40EVF_PRIV_FLAGS_STR_LEN; i++) {
const struct i40evf_priv_flags *priv_flags;
priv_flags = &i40evf_gstrings_priv_flags[i];
if (priv_flags->flag & adapter->flags)
ret_flags |= BIT(i);
}
return ret_flags;
}
static int i40evf_set_priv_flags(struct net_device *netdev, u32 flags)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
u64 changed_flags;
u32 i;
changed_flags = adapter->flags;
for (i = 0; i < I40EVF_PRIV_FLAGS_STR_LEN; i++) {
const struct i40evf_priv_flags *priv_flags;
priv_flags = &i40evf_gstrings_priv_flags[i];
if (priv_flags->read_only)
continue;
if (flags & BIT(i))
adapter->flags |= priv_flags->flag;
else
adapter->flags &= ~(priv_flags->flag);
}
changed_flags ^= adapter->flags;
if (changed_flags & I40EVF_FLAG_LEGACY_RX) {
if (netif_running(netdev)) {
adapter->flags |= I40EVF_FLAG_RESET_NEEDED;
schedule_work(&adapter->reset_task);
}
}
return 0;
}
static u32 i40evf_get_msglevel(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
return adapter->msg_enable;
}
static void i40evf_set_msglevel(struct net_device *netdev, u32 data)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
if (I40E_DEBUG_USER & data)
adapter->hw.debug_mask = data;
adapter->msg_enable = data;
}
static void i40evf_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
strlcpy(drvinfo->driver, i40evf_driver_name, 32);
strlcpy(drvinfo->version, i40evf_driver_version, 32);
strlcpy(drvinfo->fw_version, "N/A", 4);
strlcpy(drvinfo->bus_info, pci_name(adapter->pdev), 32);
drvinfo->n_priv_flags = I40EVF_PRIV_FLAGS_STR_LEN;
}
static void i40evf_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
ring->rx_max_pending = I40EVF_MAX_RXD;
ring->tx_max_pending = I40EVF_MAX_TXD;
ring->rx_pending = adapter->rx_desc_count;
ring->tx_pending = adapter->tx_desc_count;
}
static int i40evf_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
u32 new_rx_count, new_tx_count;
if ((ring->rx_mini_pending) || (ring->rx_jumbo_pending))
return -EINVAL;
new_tx_count = clamp_t(u32, ring->tx_pending,
I40EVF_MIN_TXD,
I40EVF_MAX_TXD);
new_tx_count = ALIGN(new_tx_count, I40EVF_REQ_DESCRIPTOR_MULTIPLE);
new_rx_count = clamp_t(u32, ring->rx_pending,
I40EVF_MIN_RXD,
I40EVF_MAX_RXD);
new_rx_count = ALIGN(new_rx_count, I40EVF_REQ_DESCRIPTOR_MULTIPLE);
if ((new_tx_count == adapter->tx_desc_count) &&
(new_rx_count == adapter->rx_desc_count))
return 0;
adapter->tx_desc_count = new_tx_count;
adapter->rx_desc_count = new_rx_count;
if (netif_running(netdev)) {
adapter->flags |= I40EVF_FLAG_RESET_NEEDED;
schedule_work(&adapter->reset_task);
}
return 0;
}
static int __i40evf_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec,
int queue)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_vsi *vsi = &adapter->vsi;
struct i40e_ring *rx_ring, *tx_ring;
ec->tx_max_coalesced_frames = vsi->work_limit;
ec->rx_max_coalesced_frames = vsi->work_limit;
if (queue < 0)
queue = 0;
else if (queue >= adapter->num_active_queues)
return -EINVAL;
rx_ring = &adapter->rx_rings[queue];
tx_ring = &adapter->tx_rings[queue];
if (ITR_IS_DYNAMIC(rx_ring->rx_itr_setting))
ec->use_adaptive_rx_coalesce = 1;
if (ITR_IS_DYNAMIC(tx_ring->tx_itr_setting))
ec->use_adaptive_tx_coalesce = 1;
ec->rx_coalesce_usecs = rx_ring->rx_itr_setting & ~I40E_ITR_DYNAMIC;
ec->tx_coalesce_usecs = tx_ring->tx_itr_setting & ~I40E_ITR_DYNAMIC;
return 0;
}
static int i40evf_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
return __i40evf_get_coalesce(netdev, ec, -1);
}
static int i40evf_get_per_queue_coalesce(struct net_device *netdev,
u32 queue,
struct ethtool_coalesce *ec)
{
return __i40evf_get_coalesce(netdev, ec, queue);
}
static void i40evf_set_itr_per_queue(struct i40evf_adapter *adapter,
struct ethtool_coalesce *ec,
int queue)
{
struct i40e_vsi *vsi = &adapter->vsi;
struct i40e_hw *hw = &adapter->hw;
struct i40e_q_vector *q_vector;
u16 vector;
adapter->rx_rings[queue].rx_itr_setting = ec->rx_coalesce_usecs;
adapter->tx_rings[queue].tx_itr_setting = ec->tx_coalesce_usecs;
if (ec->use_adaptive_rx_coalesce)
adapter->rx_rings[queue].rx_itr_setting |= I40E_ITR_DYNAMIC;
else
adapter->rx_rings[queue].rx_itr_setting &= ~I40E_ITR_DYNAMIC;
if (ec->use_adaptive_tx_coalesce)
adapter->tx_rings[queue].tx_itr_setting |= I40E_ITR_DYNAMIC;
else
adapter->tx_rings[queue].tx_itr_setting &= ~I40E_ITR_DYNAMIC;
q_vector = adapter->rx_rings[queue].q_vector;
q_vector->rx.itr = ITR_TO_REG(adapter->rx_rings[queue].rx_itr_setting);
vector = vsi->base_vector + q_vector->v_idx;
wr32(hw, I40E_VFINT_ITRN1(I40E_RX_ITR, vector - 1), q_vector->rx.itr);
q_vector = adapter->tx_rings[queue].q_vector;
q_vector->tx.itr = ITR_TO_REG(adapter->tx_rings[queue].tx_itr_setting);
vector = vsi->base_vector + q_vector->v_idx;
wr32(hw, I40E_VFINT_ITRN1(I40E_TX_ITR, vector - 1), q_vector->tx.itr);
i40e_flush(hw);
}
static int __i40evf_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec,
int queue)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_vsi *vsi = &adapter->vsi;
int i;
if (ec->tx_max_coalesced_frames_irq || ec->rx_max_coalesced_frames_irq)
vsi->work_limit = ec->tx_max_coalesced_frames_irq;
if (ec->rx_coalesce_usecs == 0) {
if (ec->use_adaptive_rx_coalesce)
netif_info(adapter, drv, netdev, "rx-usecs=0, need to disable adaptive-rx for a complete disable\n");
} else if ((ec->rx_coalesce_usecs < (I40E_MIN_ITR << 1)) ||
(ec->rx_coalesce_usecs > (I40E_MAX_ITR << 1))) {
netif_info(adapter, drv, netdev, "Invalid value, rx-usecs range is 0-8160\n");
return -EINVAL;
}
else
if (ec->tx_coalesce_usecs == 0) {
if (ec->use_adaptive_tx_coalesce)
netif_info(adapter, drv, netdev, "tx-usecs=0, need to disable adaptive-tx for a complete disable\n");
} else if ((ec->tx_coalesce_usecs < (I40E_MIN_ITR << 1)) ||
(ec->tx_coalesce_usecs > (I40E_MAX_ITR << 1))) {
netif_info(adapter, drv, netdev, "Invalid value, tx-usecs range is 0-8160\n");
return -EINVAL;
}
if (queue < 0) {
for (i = 0; i < adapter->num_active_queues; i++)
i40evf_set_itr_per_queue(adapter, ec, i);
} else if (queue < adapter->num_active_queues) {
i40evf_set_itr_per_queue(adapter, ec, queue);
} else {
netif_info(adapter, drv, netdev, "Invalid queue value, queue range is 0 - %d\n",
adapter->num_active_queues - 1);
return -EINVAL;
}
return 0;
}
static int i40evf_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
return __i40evf_set_coalesce(netdev, ec, -1);
}
static int i40evf_set_per_queue_coalesce(struct net_device *netdev,
u32 queue,
struct ethtool_coalesce *ec)
{
return __i40evf_set_coalesce(netdev, ec, queue);
}
static int i40evf_get_rxnfc(struct net_device *netdev,
struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
int ret = -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_GRXRINGS:
cmd->data = adapter->num_active_queues;
ret = 0;
break;
case ETHTOOL_GRXFH:
netdev_info(netdev,
"RSS hash info is not available to vf, use pf.\n");
break;
default:
break;
}
return ret;
}
static void i40evf_get_channels(struct net_device *netdev,
struct ethtool_channels *ch)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
ch->max_combined = adapter->num_active_queues;
ch->max_other = NONQ_VECS;
ch->other_count = NONQ_VECS;
ch->combined_count = adapter->num_active_queues;
}
static u32 i40evf_get_rxfh_key_size(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
return adapter->rss_key_size;
}
static u32 i40evf_get_rxfh_indir_size(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
return adapter->rss_lut_size;
}
static int i40evf_get_rxfh(struct net_device *netdev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
u16 i;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
if (!indir)
return 0;
memcpy(key, adapter->rss_key, adapter->rss_key_size);
for (i = 0; i < adapter->rss_lut_size; i++)
indir[i] = (u32)adapter->rss_lut[i];
return 0;
}
static int i40evf_set_rxfh(struct net_device *netdev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
u16 i;
if (key ||
(hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP))
return -EOPNOTSUPP;
if (!indir)
return 0;
if (key) {
memcpy(adapter->rss_key, key, adapter->rss_key_size);
}
for (i = 0; i < adapter->rss_lut_size; i++)
adapter->rss_lut[i] = (u8)(indir[i]);
return i40evf_config_rss(adapter);
}
void i40evf_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &i40evf_ethtool_ops;
}
