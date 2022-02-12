static int i40evf_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
ecmd->supported = 0;
ecmd->autoneg = AUTONEG_DISABLE;
ecmd->transceiver = XCVR_DUMMY1;
ecmd->port = PORT_NONE;
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
memcpy(data, i40evf_priv_flags_strings[i],
ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
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
static int i40evf_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_vsi *vsi = &adapter->vsi;
ec->tx_max_coalesced_frames = vsi->work_limit;
ec->rx_max_coalesced_frames = vsi->work_limit;
if (ITR_IS_DYNAMIC(vsi->rx_itr_setting))
ec->use_adaptive_rx_coalesce = 1;
if (ITR_IS_DYNAMIC(vsi->tx_itr_setting))
ec->use_adaptive_tx_coalesce = 1;
ec->rx_coalesce_usecs = vsi->rx_itr_setting & ~I40E_ITR_DYNAMIC;
ec->tx_coalesce_usecs = vsi->tx_itr_setting & ~I40E_ITR_DYNAMIC;
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
if (ec->tx_max_coalesced_frames_irq || ec->rx_max_coalesced_frames_irq)
vsi->work_limit = ec->tx_max_coalesced_frames_irq;
if ((ec->rx_coalesce_usecs >= (I40E_MIN_ITR << 1)) &&
(ec->rx_coalesce_usecs <= (I40E_MAX_ITR << 1)))
vsi->rx_itr_setting = ec->rx_coalesce_usecs;
else
return -EINVAL;
if ((ec->tx_coalesce_usecs >= (I40E_MIN_ITR << 1)) &&
(ec->tx_coalesce_usecs <= (I40E_MAX_ITR << 1)))
vsi->tx_itr_setting = ec->tx_coalesce_usecs;
else if (ec->use_adaptive_tx_coalesce)
vsi->tx_itr_setting = (I40E_ITR_DYNAMIC |
ITR_REG_TO_USEC(I40E_ITR_RX_DEF));
else
return -EINVAL;
if (ec->use_adaptive_rx_coalesce)
vsi->rx_itr_setting |= I40E_ITR_DYNAMIC;
else
vsi->rx_itr_setting &= ~I40E_ITR_DYNAMIC;
if (ec->use_adaptive_tx_coalesce)
vsi->tx_itr_setting |= I40E_ITR_DYNAMIC;
else
vsi->tx_itr_setting &= ~I40E_ITR_DYNAMIC;
for (i = 0; i < adapter->num_msix_vectors - NONQ_VECS; i++) {
q_vector = &adapter->q_vectors[i];
q_vector->rx.itr = ITR_TO_REG(vsi->rx_itr_setting);
wr32(hw, I40E_VFINT_ITRN1(0, i), q_vector->rx.itr);
q_vector->tx.itr = ITR_TO_REG(vsi->tx_itr_setting);
wr32(hw, I40E_VFINT_ITRN1(1, i), q_vector->tx.itr);
i40e_flush(hw);
}
return 0;
}
static int i40evf_get_rss_hash_opts(struct i40evf_adapter *adapter,
struct ethtool_rxnfc *cmd)
{
struct i40e_hw *hw = &adapter->hw;
u64 hena = (u64)rd32(hw, I40E_VFQF_HENA(0)) |
((u64)rd32(hw, I40E_VFQF_HENA(1)) << 32);
cmd->data = RXH_IP_SRC | RXH_IP_DST;
switch (cmd->flow_type) {
case TCP_V4_FLOW:
if (hena & BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV4_TCP))
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
break;
case UDP_V4_FLOW:
if (hena & BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV4_UDP))
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
break;
case SCTP_V4_FLOW:
case AH_ESP_V4_FLOW:
case AH_V4_FLOW:
case ESP_V4_FLOW:
case IPV4_FLOW:
break;
case TCP_V6_FLOW:
if (hena & BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV6_TCP))
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
break;
case UDP_V6_FLOW:
if (hena & BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV6_UDP))
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
break;
case SCTP_V6_FLOW:
case AH_ESP_V6_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case IPV6_FLOW:
break;
default:
cmd->data = 0;
return -EINVAL;
}
return 0;
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
ret = i40evf_get_rss_hash_opts(adapter, cmd);
break;
default:
break;
}
return ret;
}
static int i40evf_set_rss_hash_opt(struct i40evf_adapter *adapter,
struct ethtool_rxnfc *nfc)
{
struct i40e_hw *hw = &adapter->hw;
u32 flags = adapter->vf_res->vf_offload_flags;
u64 hena = (u64)rd32(hw, I40E_VFQF_HENA(0)) |
((u64)rd32(hw, I40E_VFQF_HENA(1)) << 32);
if (nfc->data & ~(RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3))
return -EINVAL;
if (!(nfc->data & RXH_IP_SRC) ||
!(nfc->data & RXH_IP_DST))
return -EINVAL;
switch (nfc->flow_type) {
case TCP_V4_FLOW:
if (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
if (flags & I40E_VIRTCHNL_VF_OFFLOAD_RSS_PCTYPE_V2)
hena |=
BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV4_TCP_SYN_NO_ACK);
hena |= BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV4_TCP);
} else {
return -EINVAL;
}
break;
case TCP_V6_FLOW:
if (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
if (flags & I40E_VIRTCHNL_VF_OFFLOAD_RSS_PCTYPE_V2)
hena |=
BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV6_TCP_SYN_NO_ACK);
hena |= BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV6_TCP);
} else {
return -EINVAL;
}
break;
case UDP_V4_FLOW:
if (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
if (flags & I40E_VIRTCHNL_VF_OFFLOAD_RSS_PCTYPE_V2)
hena |=
BIT_ULL(I40E_FILTER_PCTYPE_NONF_UNICAST_IPV4_UDP) |
BIT_ULL(I40E_FILTER_PCTYPE_NONF_MULTICAST_IPV4_UDP);
hena |= (BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV4_UDP) |
BIT_ULL(I40E_FILTER_PCTYPE_FRAG_IPV4));
} else {
return -EINVAL;
}
break;
case UDP_V6_FLOW:
if (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
if (flags & I40E_VIRTCHNL_VF_OFFLOAD_RSS_PCTYPE_V2)
hena |=
BIT_ULL(I40E_FILTER_PCTYPE_NONF_UNICAST_IPV6_UDP) |
BIT_ULL(I40E_FILTER_PCTYPE_NONF_MULTICAST_IPV6_UDP);
hena |= (BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV6_UDP) |
BIT_ULL(I40E_FILTER_PCTYPE_FRAG_IPV6));
} else {
return -EINVAL;
}
break;
case AH_ESP_V4_FLOW:
case AH_V4_FLOW:
case ESP_V4_FLOW:
case SCTP_V4_FLOW:
if ((nfc->data & RXH_L4_B_0_1) ||
(nfc->data & RXH_L4_B_2_3))
return -EINVAL;
hena |= BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV4_OTHER);
break;
case AH_ESP_V6_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case SCTP_V6_FLOW:
if ((nfc->data & RXH_L4_B_0_1) ||
(nfc->data & RXH_L4_B_2_3))
return -EINVAL;
hena |= BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV6_OTHER);
break;
case IPV4_FLOW:
hena |= (BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV4_OTHER) |
BIT_ULL(I40E_FILTER_PCTYPE_FRAG_IPV4));
break;
case IPV6_FLOW:
hena |= (BIT_ULL(I40E_FILTER_PCTYPE_NONF_IPV6_OTHER) |
BIT_ULL(I40E_FILTER_PCTYPE_FRAG_IPV6));
break;
default:
return -EINVAL;
}
wr32(hw, I40E_VFQF_HENA(0), (u32)hena);
wr32(hw, I40E_VFQF_HENA(1), (u32)(hena >> 32));
i40e_flush(hw);
return 0;
}
static int i40evf_set_rxnfc(struct net_device *netdev,
struct ethtool_rxnfc *cmd)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
int ret = -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_SRXFH:
ret = i40evf_set_rss_hash_opt(adapter, cmd);
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
static u32 i40evf_get_rxfh_indir_size(struct net_device *netdev)
{
return (I40E_VFQF_HLUT_MAX_INDEX + 1) * 4;
}
static int i40evf_get_rxfh(struct net_device *netdev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_vsi *vsi = &adapter->vsi;
u8 *seed = NULL, *lut;
int ret;
u16 i;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
if (!indir)
return 0;
seed = key;
lut = kzalloc(I40EVF_HLUT_ARRAY_SIZE, GFP_KERNEL);
if (!lut)
return -ENOMEM;
ret = i40evf_get_rss(vsi, seed, lut, I40EVF_HLUT_ARRAY_SIZE);
if (ret)
goto out;
for (i = 0; i < I40EVF_HLUT_ARRAY_SIZE; i++)
indir[i] = (u32)lut[i];
out:
kfree(lut);
return ret;
}
static int i40evf_set_rxfh(struct net_device *netdev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_vsi *vsi = &adapter->vsi;
u8 *seed = NULL;
u16 i;
if (key ||
(hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP))
return -EOPNOTSUPP;
if (!indir)
return 0;
if (key) {
if (!vsi->rss_hkey_user) {
vsi->rss_hkey_user = kzalloc(I40EVF_HKEY_ARRAY_SIZE,
GFP_KERNEL);
if (!vsi->rss_hkey_user)
return -ENOMEM;
}
memcpy(vsi->rss_hkey_user, key, I40EVF_HKEY_ARRAY_SIZE);
seed = vsi->rss_hkey_user;
}
if (!vsi->rss_lut_user) {
vsi->rss_lut_user = kzalloc(I40EVF_HLUT_ARRAY_SIZE,
GFP_KERNEL);
if (!vsi->rss_lut_user)
return -ENOMEM;
}
for (i = 0; i < I40EVF_HLUT_ARRAY_SIZE; i++)
vsi->rss_lut_user[i] = (u8)(indir[i]);
return i40evf_config_rss(vsi, seed, vsi->rss_lut_user,
I40EVF_HLUT_ARRAY_SIZE);
}
static u32 i40evf_get_priv_flags(struct net_device *dev)
{
struct i40evf_adapter *adapter = netdev_priv(dev);
u32 ret_flags = 0;
ret_flags |= adapter->flags & I40EVF_FLAG_RX_PS_ENABLED ?
I40EVF_PRIV_FLAGS_PS : 0;
return ret_flags;
}
static int i40evf_set_priv_flags(struct net_device *dev, u32 flags)
{
struct i40evf_adapter *adapter = netdev_priv(dev);
bool reset_required = false;
if ((flags & I40EVF_PRIV_FLAGS_PS) &&
!(adapter->flags & I40EVF_FLAG_RX_PS_ENABLED)) {
adapter->flags |= I40EVF_FLAG_RX_PS_ENABLED;
reset_required = true;
} else if (!(flags & I40EVF_PRIV_FLAGS_PS) &&
(adapter->flags & I40EVF_FLAG_RX_PS_ENABLED)) {
adapter->flags &= ~I40EVF_FLAG_RX_PS_ENABLED;
reset_required = true;
}
if (reset_required)
i40evf_schedule_reset(adapter);
return 0;
}
void i40evf_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &i40evf_ethtool_ops;
}
