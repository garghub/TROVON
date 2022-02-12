static int i40evf_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
ecmd->supported = SUPPORTED_10000baseT_Full;
ecmd->autoneg = AUTONEG_DISABLE;
ecmd->transceiver = XCVR_DUMMY1;
ecmd->port = PORT_NONE;
return 0;
}
static int i40evf_get_sset_count(struct net_device *netdev, int sset)
{
if (sset == ETH_SS_STATS)
return I40EVF_STATS_LEN;
else
return -ENOTSUPP;
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
for (j = 0; j < adapter->vsi_res->num_queue_pairs; j++) {
data[i++] = adapter->tx_rings[j]->stats.packets;
data[i++] = adapter->tx_rings[j]->stats.bytes;
}
for (j = 0; j < adapter->vsi_res->num_queue_pairs; j++) {
data[i++] = adapter->rx_rings[j]->stats.packets;
data[i++] = adapter->rx_rings[j]->stats.bytes;
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
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++) {
snprintf(p, ETH_GSTRING_LEN, "tx-%u.packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "tx-%u.bytes", i);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++) {
snprintf(p, ETH_GSTRING_LEN, "rx-%u.packets", i);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "rx-%u.bytes", i);
p += ETH_GSTRING_LEN;
}
}
}
static u32 i40evf_get_msglevel(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
return adapter->msg_enable;
}
static void i40evf_set_msglevel(struct net_device *netdev, u32 data)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
adapter->msg_enable = data;
}
static void i40evf_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
strlcpy(drvinfo->driver, i40evf_driver_name, 32);
strlcpy(drvinfo->version, i40evf_driver_version, 32);
strlcpy(drvinfo->bus_info, pci_name(adapter->pdev), 32);
}
static void i40evf_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_ring *tx_ring = adapter->tx_rings[0];
struct i40e_ring *rx_ring = adapter->rx_rings[0];
ring->rx_max_pending = I40EVF_MAX_RXD;
ring->tx_max_pending = I40EVF_MAX_TXD;
ring->rx_pending = rx_ring->count;
ring->tx_pending = tx_ring->count;
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
if ((new_tx_count == adapter->txd_count) &&
(new_rx_count == adapter->rxd_count))
return 0;
adapter->txd_count = new_tx_count;
adapter->rxd_count = new_rx_count;
if (netif_running(netdev))
i40evf_reinit_locked(adapter);
return 0;
}
static int i40evf_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_vsi *vsi = &adapter->vsi;
ec->tx_max_coalesced_frames = vsi->work_limit;
ec->rx_max_coalesced_frames = vsi->work_limit;
if (ITR_IS_DYNAMIC(vsi->rx_itr_setting))
ec->rx_coalesce_usecs = 1;
else
ec->rx_coalesce_usecs = vsi->rx_itr_setting;
if (ITR_IS_DYNAMIC(vsi->tx_itr_setting))
ec->tx_coalesce_usecs = 1;
else
ec->tx_coalesce_usecs = vsi->tx_itr_setting;
return 0;
}
static int i40evf_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_hw *hw = &adapter->hw;
struct i40e_vsi *vsi = &adapter->vsi;
struct i40e_q_vector *q_vector;
int i;
if (ec->tx_max_coalesced_frames || ec->rx_max_coalesced_frames)
vsi->work_limit = ec->tx_max_coalesced_frames;
switch (ec->rx_coalesce_usecs) {
case 0:
vsi->rx_itr_setting = 0;
break;
case 1:
vsi->rx_itr_setting = (I40E_ITR_DYNAMIC
| ITR_REG_TO_USEC(I40E_ITR_RX_DEF));
break;
default:
if ((ec->rx_coalesce_usecs < (I40E_MIN_ITR << 1)) ||
(ec->rx_coalesce_usecs > (I40E_MAX_ITR << 1)))
return -EINVAL;
vsi->rx_itr_setting = ec->rx_coalesce_usecs;
break;
}
switch (ec->tx_coalesce_usecs) {
case 0:
vsi->tx_itr_setting = 0;
break;
case 1:
vsi->tx_itr_setting = (I40E_ITR_DYNAMIC
| ITR_REG_TO_USEC(I40E_ITR_TX_DEF));
break;
default:
if ((ec->tx_coalesce_usecs < (I40E_MIN_ITR << 1)) ||
(ec->tx_coalesce_usecs > (I40E_MAX_ITR << 1)))
return -EINVAL;
vsi->tx_itr_setting = ec->tx_coalesce_usecs;
break;
}
for (i = 0; i < adapter->num_msix_vectors - NONQ_VECS; i++) {
q_vector = adapter->q_vector[i];
q_vector->rx.itr = ITR_TO_REG(vsi->rx_itr_setting);
wr32(hw, I40E_VFINT_ITRN1(0, i), q_vector->rx.itr);
q_vector->tx.itr = ITR_TO_REG(vsi->tx_itr_setting);
wr32(hw, I40E_VFINT_ITRN1(1, i), q_vector->tx.itr);
i40e_flush(hw);
}
return 0;
}
void i40evf_set_ethtool_ops(struct net_device *netdev)
{
SET_ETHTOOL_OPS(netdev, &i40evf_ethtool_ops);
}
