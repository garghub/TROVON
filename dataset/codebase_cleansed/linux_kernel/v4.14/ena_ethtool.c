static void ena_safe_update_stat(u64 *src, u64 *dst,
struct u64_stats_sync *syncp)
{
unsigned int start;
do {
start = u64_stats_fetch_begin_irq(syncp);
*(dst) = *src;
} while (u64_stats_fetch_retry_irq(syncp, start));
}
static void ena_queue_stats(struct ena_adapter *adapter, u64 **data)
{
const struct ena_stats *ena_stats;
struct ena_ring *ring;
u64 *ptr;
int i, j;
for (i = 0; i < adapter->num_queues; i++) {
ring = &adapter->tx_ring[i];
for (j = 0; j < ENA_STATS_ARRAY_TX; j++) {
ena_stats = &ena_stats_tx_strings[j];
ptr = (u64 *)((uintptr_t)&ring->tx_stats +
(uintptr_t)ena_stats->stat_offset);
ena_safe_update_stat(ptr, (*data)++, &ring->syncp);
}
ring = &adapter->rx_ring[i];
for (j = 0; j < ENA_STATS_ARRAY_RX; j++) {
ena_stats = &ena_stats_rx_strings[j];
ptr = (u64 *)((uintptr_t)&ring->rx_stats +
(uintptr_t)ena_stats->stat_offset);
ena_safe_update_stat(ptr, (*data)++, &ring->syncp);
}
}
}
static void ena_dev_admin_queue_stats(struct ena_adapter *adapter, u64 **data)
{
const struct ena_stats *ena_stats;
u32 *ptr;
int i;
for (i = 0; i < ENA_STATS_ARRAY_ENA_COM; i++) {
ena_stats = &ena_stats_ena_com_strings[i];
ptr = (u32 *)((uintptr_t)&adapter->ena_dev->admin_queue.stats +
(uintptr_t)ena_stats->stat_offset);
*(*data)++ = *ptr;
}
}
static void ena_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats,
u64 *data)
{
struct ena_adapter *adapter = netdev_priv(netdev);
const struct ena_stats *ena_stats;
u64 *ptr;
int i;
for (i = 0; i < ENA_STATS_ARRAY_GLOBAL; i++) {
ena_stats = &ena_stats_global_strings[i];
ptr = (u64 *)((uintptr_t)&adapter->dev_stats +
(uintptr_t)ena_stats->stat_offset);
ena_safe_update_stat(ptr, data++, &adapter->syncp);
}
ena_queue_stats(adapter, &data);
ena_dev_admin_queue_stats(adapter, &data);
}
int ena_get_sset_count(struct net_device *netdev, int sset)
{
struct ena_adapter *adapter = netdev_priv(netdev);
if (sset != ETH_SS_STATS)
return -EOPNOTSUPP;
return adapter->num_queues * (ENA_STATS_ARRAY_TX + ENA_STATS_ARRAY_RX)
+ ENA_STATS_ARRAY_GLOBAL + ENA_STATS_ARRAY_ENA_COM;
}
static void ena_queue_strings(struct ena_adapter *adapter, u8 **data)
{
const struct ena_stats *ena_stats;
int i, j;
for (i = 0; i < adapter->num_queues; i++) {
for (j = 0; j < ENA_STATS_ARRAY_TX; j++) {
ena_stats = &ena_stats_tx_strings[j];
snprintf(*data, ETH_GSTRING_LEN,
"queue_%u_tx_%s", i, ena_stats->name);
(*data) += ETH_GSTRING_LEN;
}
for (j = 0; j < ENA_STATS_ARRAY_RX; j++) {
ena_stats = &ena_stats_rx_strings[j];
snprintf(*data, ETH_GSTRING_LEN,
"queue_%u_rx_%s", i, ena_stats->name);
(*data) += ETH_GSTRING_LEN;
}
}
}
static void ena_com_dev_strings(u8 **data)
{
const struct ena_stats *ena_stats;
int i;
for (i = 0; i < ENA_STATS_ARRAY_ENA_COM; i++) {
ena_stats = &ena_stats_ena_com_strings[i];
snprintf(*data, ETH_GSTRING_LEN,
"ena_admin_q_%s", ena_stats->name);
(*data) += ETH_GSTRING_LEN;
}
}
static void ena_get_strings(struct net_device *netdev, u32 sset, u8 *data)
{
struct ena_adapter *adapter = netdev_priv(netdev);
const struct ena_stats *ena_stats;
int i;
if (sset != ETH_SS_STATS)
return;
for (i = 0; i < ENA_STATS_ARRAY_GLOBAL; i++) {
ena_stats = &ena_stats_global_strings[i];
memcpy(data, ena_stats->name, ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
ena_queue_strings(adapter, &data);
ena_com_dev_strings(&data);
}
static int ena_get_link_ksettings(struct net_device *netdev,
struct ethtool_link_ksettings *link_ksettings)
{
struct ena_adapter *adapter = netdev_priv(netdev);
struct ena_com_dev *ena_dev = adapter->ena_dev;
struct ena_admin_get_feature_link_desc *link;
struct ena_admin_get_feat_resp feat_resp;
int rc;
rc = ena_com_get_link_params(ena_dev, &feat_resp);
if (rc)
return rc;
link = &feat_resp.u.link;
link_ksettings->base.speed = link->speed;
if (link->flags & ENA_ADMIN_GET_FEATURE_LINK_DESC_AUTONEG_MASK) {
ethtool_link_ksettings_add_link_mode(link_ksettings,
supported, Autoneg);
ethtool_link_ksettings_add_link_mode(link_ksettings,
supported, Autoneg);
}
link_ksettings->base.autoneg =
(link->flags & ENA_ADMIN_GET_FEATURE_LINK_DESC_AUTONEG_MASK) ?
AUTONEG_ENABLE : AUTONEG_DISABLE;
link_ksettings->base.duplex = DUPLEX_FULL;
return 0;
}
static int ena_get_coalesce(struct net_device *net_dev,
struct ethtool_coalesce *coalesce)
{
struct ena_adapter *adapter = netdev_priv(net_dev);
struct ena_com_dev *ena_dev = adapter->ena_dev;
struct ena_intr_moder_entry intr_moder_entry;
if (!ena_com_interrupt_moderation_supported(ena_dev)) {
return -EOPNOTSUPP;
}
coalesce->tx_coalesce_usecs =
ena_com_get_nonadaptive_moderation_interval_tx(ena_dev) /
ena_dev->intr_delay_resolution;
if (!ena_com_get_adaptive_moderation_enabled(ena_dev)) {
coalesce->rx_coalesce_usecs =
ena_com_get_nonadaptive_moderation_interval_rx(ena_dev)
/ ena_dev->intr_delay_resolution;
} else {
ena_com_get_intr_moderation_entry(adapter->ena_dev, ENA_INTR_MODER_LOWEST, &intr_moder_entry);
coalesce->rx_coalesce_usecs_low = intr_moder_entry.intr_moder_interval;
coalesce->rx_max_coalesced_frames_low = intr_moder_entry.pkts_per_interval;
ena_com_get_intr_moderation_entry(adapter->ena_dev, ENA_INTR_MODER_MID, &intr_moder_entry);
coalesce->rx_coalesce_usecs = intr_moder_entry.intr_moder_interval;
coalesce->rx_max_coalesced_frames = intr_moder_entry.pkts_per_interval;
ena_com_get_intr_moderation_entry(adapter->ena_dev, ENA_INTR_MODER_HIGHEST, &intr_moder_entry);
coalesce->rx_coalesce_usecs_high = intr_moder_entry.intr_moder_interval;
coalesce->rx_max_coalesced_frames_high = intr_moder_entry.pkts_per_interval;
}
coalesce->use_adaptive_rx_coalesce =
ena_com_get_adaptive_moderation_enabled(ena_dev);
return 0;
}
static void ena_update_tx_rings_intr_moderation(struct ena_adapter *adapter)
{
unsigned int val;
int i;
val = ena_com_get_nonadaptive_moderation_interval_tx(adapter->ena_dev);
for (i = 0; i < adapter->num_queues; i++)
adapter->tx_ring[i].smoothed_interval = val;
}
static int ena_set_coalesce(struct net_device *net_dev,
struct ethtool_coalesce *coalesce)
{
struct ena_adapter *adapter = netdev_priv(net_dev);
struct ena_com_dev *ena_dev = adapter->ena_dev;
struct ena_intr_moder_entry intr_moder_entry;
int rc;
if (!ena_com_interrupt_moderation_supported(ena_dev)) {
return -EOPNOTSUPP;
}
if (coalesce->rx_coalesce_usecs_irq ||
coalesce->rx_max_coalesced_frames_irq ||
coalesce->tx_coalesce_usecs_irq ||
coalesce->tx_max_coalesced_frames ||
coalesce->tx_max_coalesced_frames_irq ||
coalesce->stats_block_coalesce_usecs ||
coalesce->use_adaptive_tx_coalesce ||
coalesce->pkt_rate_low ||
coalesce->tx_coalesce_usecs_low ||
coalesce->tx_max_coalesced_frames_low ||
coalesce->pkt_rate_high ||
coalesce->tx_coalesce_usecs_high ||
coalesce->tx_max_coalesced_frames_high ||
coalesce->rate_sample_interval)
return -EINVAL;
rc = ena_com_update_nonadaptive_moderation_interval_tx(ena_dev,
coalesce->tx_coalesce_usecs);
if (rc)
return rc;
ena_update_tx_rings_intr_moderation(adapter);
if (ena_com_get_adaptive_moderation_enabled(ena_dev)) {
if (!coalesce->use_adaptive_rx_coalesce) {
ena_com_disable_adaptive_moderation(ena_dev);
rc = ena_com_update_nonadaptive_moderation_interval_rx(ena_dev,
coalesce->rx_coalesce_usecs);
return rc;
}
} else {
if (coalesce->use_adaptive_rx_coalesce) {
ena_com_enable_adaptive_moderation(ena_dev);
} else {
rc = ena_com_update_nonadaptive_moderation_interval_rx(ena_dev,
coalesce->rx_coalesce_usecs);
return rc;
}
}
intr_moder_entry.intr_moder_interval = coalesce->rx_coalesce_usecs_low;
intr_moder_entry.pkts_per_interval = coalesce->rx_max_coalesced_frames_low;
intr_moder_entry.bytes_per_interval = ENA_INTR_BYTE_COUNT_NOT_SUPPORTED;
ena_com_init_intr_moderation_entry(adapter->ena_dev, ENA_INTR_MODER_LOWEST, &intr_moder_entry);
intr_moder_entry.intr_moder_interval = coalesce->rx_coalesce_usecs;
intr_moder_entry.pkts_per_interval = coalesce->rx_max_coalesced_frames;
intr_moder_entry.bytes_per_interval = ENA_INTR_BYTE_COUNT_NOT_SUPPORTED;
ena_com_init_intr_moderation_entry(adapter->ena_dev, ENA_INTR_MODER_MID, &intr_moder_entry);
intr_moder_entry.intr_moder_interval = coalesce->rx_coalesce_usecs_high;
intr_moder_entry.pkts_per_interval = coalesce->rx_max_coalesced_frames_high;
intr_moder_entry.bytes_per_interval = ENA_INTR_BYTE_COUNT_NOT_SUPPORTED;
ena_com_init_intr_moderation_entry(adapter->ena_dev, ENA_INTR_MODER_HIGHEST, &intr_moder_entry);
return 0;
}
static u32 ena_get_msglevel(struct net_device *netdev)
{
struct ena_adapter *adapter = netdev_priv(netdev);
return adapter->msg_enable;
}
static void ena_set_msglevel(struct net_device *netdev, u32 value)
{
struct ena_adapter *adapter = netdev_priv(netdev);
adapter->msg_enable = value;
}
static void ena_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct ena_adapter *adapter = netdev_priv(dev);
strlcpy(info->driver, DRV_MODULE_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_MODULE_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(adapter->pdev),
sizeof(info->bus_info));
}
static void ena_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct ena_adapter *adapter = netdev_priv(netdev);
struct ena_ring *tx_ring = &adapter->tx_ring[0];
struct ena_ring *rx_ring = &adapter->rx_ring[0];
ring->rx_max_pending = rx_ring->ring_size;
ring->tx_max_pending = tx_ring->ring_size;
ring->rx_pending = rx_ring->ring_size;
ring->tx_pending = tx_ring->ring_size;
}
static u32 ena_flow_hash_to_flow_type(u16 hash_fields)
{
u32 data = 0;
if (hash_fields & ENA_ADMIN_RSS_L2_DA)
data |= RXH_L2DA;
if (hash_fields & ENA_ADMIN_RSS_L3_DA)
data |= RXH_IP_DST;
if (hash_fields & ENA_ADMIN_RSS_L3_SA)
data |= RXH_IP_SRC;
if (hash_fields & ENA_ADMIN_RSS_L4_DP)
data |= RXH_L4_B_2_3;
if (hash_fields & ENA_ADMIN_RSS_L4_SP)
data |= RXH_L4_B_0_1;
return data;
}
static u16 ena_flow_data_to_flow_hash(u32 hash_fields)
{
u16 data = 0;
if (hash_fields & RXH_L2DA)
data |= ENA_ADMIN_RSS_L2_DA;
if (hash_fields & RXH_IP_DST)
data |= ENA_ADMIN_RSS_L3_DA;
if (hash_fields & RXH_IP_SRC)
data |= ENA_ADMIN_RSS_L3_SA;
if (hash_fields & RXH_L4_B_2_3)
data |= ENA_ADMIN_RSS_L4_DP;
if (hash_fields & RXH_L4_B_0_1)
data |= ENA_ADMIN_RSS_L4_SP;
return data;
}
static int ena_get_rss_hash(struct ena_com_dev *ena_dev,
struct ethtool_rxnfc *cmd)
{
enum ena_admin_flow_hash_proto proto;
u16 hash_fields;
int rc;
cmd->data = 0;
switch (cmd->flow_type) {
case TCP_V4_FLOW:
proto = ENA_ADMIN_RSS_TCP4;
break;
case UDP_V4_FLOW:
proto = ENA_ADMIN_RSS_UDP4;
break;
case TCP_V6_FLOW:
proto = ENA_ADMIN_RSS_TCP6;
break;
case UDP_V6_FLOW:
proto = ENA_ADMIN_RSS_UDP6;
break;
case IPV4_FLOW:
proto = ENA_ADMIN_RSS_IP4;
break;
case IPV6_FLOW:
proto = ENA_ADMIN_RSS_IP6;
break;
case ETHER_FLOW:
proto = ENA_ADMIN_RSS_NOT_IP;
break;
case AH_V4_FLOW:
case ESP_V4_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case SCTP_V4_FLOW:
case AH_ESP_V4_FLOW:
return -EOPNOTSUPP;
default:
return -EINVAL;
}
rc = ena_com_get_hash_ctrl(ena_dev, proto, &hash_fields);
if (rc)
return rc;
cmd->data = ena_flow_hash_to_flow_type(hash_fields);
return 0;
}
static int ena_set_rss_hash(struct ena_com_dev *ena_dev,
struct ethtool_rxnfc *cmd)
{
enum ena_admin_flow_hash_proto proto;
u16 hash_fields;
switch (cmd->flow_type) {
case TCP_V4_FLOW:
proto = ENA_ADMIN_RSS_TCP4;
break;
case UDP_V4_FLOW:
proto = ENA_ADMIN_RSS_UDP4;
break;
case TCP_V6_FLOW:
proto = ENA_ADMIN_RSS_TCP6;
break;
case UDP_V6_FLOW:
proto = ENA_ADMIN_RSS_UDP6;
break;
case IPV4_FLOW:
proto = ENA_ADMIN_RSS_IP4;
break;
case IPV6_FLOW:
proto = ENA_ADMIN_RSS_IP6;
break;
case ETHER_FLOW:
proto = ENA_ADMIN_RSS_NOT_IP;
break;
case AH_V4_FLOW:
case ESP_V4_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case SCTP_V4_FLOW:
case AH_ESP_V4_FLOW:
return -EOPNOTSUPP;
default:
return -EINVAL;
}
hash_fields = ena_flow_data_to_flow_hash(cmd->data);
return ena_com_fill_hash_ctrl(ena_dev, proto, hash_fields);
}
static int ena_set_rxnfc(struct net_device *netdev, struct ethtool_rxnfc *info)
{
struct ena_adapter *adapter = netdev_priv(netdev);
int rc = 0;
switch (info->cmd) {
case ETHTOOL_SRXFH:
rc = ena_set_rss_hash(adapter->ena_dev, info);
break;
case ETHTOOL_SRXCLSRLDEL:
case ETHTOOL_SRXCLSRLINS:
default:
netif_err(adapter, drv, netdev,
"Command parameter %d is not supported\n", info->cmd);
rc = -EOPNOTSUPP;
}
return rc;
}
static int ena_get_rxnfc(struct net_device *netdev, struct ethtool_rxnfc *info,
u32 *rules)
{
struct ena_adapter *adapter = netdev_priv(netdev);
int rc = 0;
switch (info->cmd) {
case ETHTOOL_GRXRINGS:
info->data = adapter->num_queues;
rc = 0;
break;
case ETHTOOL_GRXFH:
rc = ena_get_rss_hash(adapter->ena_dev, info);
break;
case ETHTOOL_GRXCLSRLCNT:
case ETHTOOL_GRXCLSRULE:
case ETHTOOL_GRXCLSRLALL:
default:
netif_err(adapter, drv, netdev,
"Command parameter %d is not supported\n", info->cmd);
rc = -EOPNOTSUPP;
}
return rc;
}
static u32 ena_get_rxfh_indir_size(struct net_device *netdev)
{
return ENA_RX_RSS_TABLE_SIZE;
}
static u32 ena_get_rxfh_key_size(struct net_device *netdev)
{
return ENA_HASH_KEY_SIZE;
}
static int ena_get_rxfh(struct net_device *netdev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct ena_adapter *adapter = netdev_priv(netdev);
enum ena_admin_hash_functions ena_func;
u8 func;
int rc;
rc = ena_com_indirect_table_get(adapter->ena_dev, indir);
if (rc)
return rc;
rc = ena_com_get_hash_function(adapter->ena_dev, &ena_func, key);
if (rc)
return rc;
switch (ena_func) {
case ENA_ADMIN_TOEPLITZ:
func = ETH_RSS_HASH_TOP;
break;
case ENA_ADMIN_CRC32:
func = ETH_RSS_HASH_XOR;
break;
default:
netif_err(adapter, drv, netdev,
"Command parameter is not supported\n");
return -EOPNOTSUPP;
}
if (hfunc)
*hfunc = func;
return rc;
}
static int ena_set_rxfh(struct net_device *netdev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct ena_adapter *adapter = netdev_priv(netdev);
struct ena_com_dev *ena_dev = adapter->ena_dev;
enum ena_admin_hash_functions func;
int rc, i;
if (indir) {
for (i = 0; i < ENA_RX_RSS_TABLE_SIZE; i++) {
rc = ena_com_indirect_table_fill_entry(ena_dev,
ENA_IO_RXQ_IDX(indir[i]),
i);
if (unlikely(rc)) {
netif_err(adapter, drv, netdev,
"Cannot fill indirect table (index is too large)\n");
return rc;
}
}
rc = ena_com_indirect_table_set(ena_dev);
if (rc) {
netif_err(adapter, drv, netdev,
"Cannot set indirect table\n");
return rc == -EPERM ? -EOPNOTSUPP : rc;
}
}
switch (hfunc) {
case ETH_RSS_HASH_TOP:
func = ENA_ADMIN_TOEPLITZ;
break;
case ETH_RSS_HASH_XOR:
func = ENA_ADMIN_CRC32;
break;
default:
netif_err(adapter, drv, netdev, "Unsupported hfunc %d\n",
hfunc);
return -EOPNOTSUPP;
}
if (key) {
rc = ena_com_fill_hash_function(ena_dev, func, key,
ENA_HASH_KEY_SIZE,
0xFFFFFFFF);
if (unlikely(rc)) {
netif_err(adapter, drv, netdev, "Cannot fill key\n");
return rc == -EPERM ? -EOPNOTSUPP : rc;
}
}
return 0;
}
static void ena_get_channels(struct net_device *netdev,
struct ethtool_channels *channels)
{
struct ena_adapter *adapter = netdev_priv(netdev);
channels->max_rx = adapter->num_queues;
channels->max_tx = adapter->num_queues;
channels->max_other = 0;
channels->max_combined = 0;
channels->rx_count = adapter->num_queues;
channels->tx_count = adapter->num_queues;
channels->other_count = 0;
channels->combined_count = 0;
}
static int ena_get_tunable(struct net_device *netdev,
const struct ethtool_tunable *tuna, void *data)
{
struct ena_adapter *adapter = netdev_priv(netdev);
int ret = 0;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
*(u32 *)data = adapter->rx_copybreak;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int ena_set_tunable(struct net_device *netdev,
const struct ethtool_tunable *tuna,
const void *data)
{
struct ena_adapter *adapter = netdev_priv(netdev);
int ret = 0;
u32 len;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
len = *(u32 *)data;
if (len > adapter->netdev->mtu) {
ret = -EINVAL;
break;
}
adapter->rx_copybreak = len;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
void ena_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &ena_ethtool_ops;
}
static void ena_dump_stats_ex(struct ena_adapter *adapter, u8 *buf)
{
struct net_device *netdev = adapter->netdev;
u8 *strings_buf;
u64 *data_buf;
int strings_num;
int i, rc;
strings_num = ena_get_sset_count(netdev, ETH_SS_STATS);
if (strings_num <= 0) {
netif_err(adapter, drv, netdev, "Can't get stats num\n");
return;
}
strings_buf = devm_kzalloc(&adapter->pdev->dev,
strings_num * ETH_GSTRING_LEN,
GFP_ATOMIC);
if (!strings_buf) {
netif_err(adapter, drv, netdev,
"failed to alloc strings_buf\n");
return;
}
data_buf = devm_kzalloc(&adapter->pdev->dev,
strings_num * sizeof(u64),
GFP_ATOMIC);
if (!data_buf) {
netif_err(adapter, drv, netdev,
"failed to allocate data buf\n");
devm_kfree(&adapter->pdev->dev, strings_buf);
return;
}
ena_get_strings(netdev, ETH_SS_STATS, strings_buf);
ena_get_ethtool_stats(netdev, NULL, data_buf);
if (buf)
for (i = 0; i < strings_num; i++) {
rc = snprintf(buf, ETH_GSTRING_LEN + sizeof(u64),
"%s %llu\n",
strings_buf + i * ETH_GSTRING_LEN,
data_buf[i]);
buf += rc;
}
else
for (i = 0; i < strings_num; i++)
netif_err(adapter, drv, netdev, "%s: %llu\n",
strings_buf + i * ETH_GSTRING_LEN,
data_buf[i]);
devm_kfree(&adapter->pdev->dev, strings_buf);
devm_kfree(&adapter->pdev->dev, data_buf);
}
void ena_dump_stats_to_buf(struct ena_adapter *adapter, u8 *buf)
{
if (!buf)
return;
ena_dump_stats_ex(adapter, buf);
}
void ena_dump_stats_to_dmesg(struct ena_adapter *adapter)
{
ena_dump_stats_ex(adapter, NULL);
}
