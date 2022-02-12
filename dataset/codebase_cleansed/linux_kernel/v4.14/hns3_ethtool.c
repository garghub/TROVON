static void hns3_driv_to_eth_caps(u32 caps, struct ethtool_link_ksettings *cmd,
bool is_advertised)
{
int i;
for (i = 0; i < ARRAY_SIZE(hns3_lm_map); i++) {
if (!(caps & hns3_lm_map[i].hns3_link_mode))
continue;
if (is_advertised) {
ethtool_link_ksettings_zero_link_mode(cmd,
advertising);
__set_bit(hns3_lm_map[i].ethtool_link_mode,
cmd->link_modes.advertising);
} else {
ethtool_link_ksettings_zero_link_mode(cmd,
supported);
__set_bit(hns3_lm_map[i].ethtool_link_mode,
cmd->link_modes.supported);
}
}
}
static int hns3_get_sset_count(struct net_device *netdev, int stringset)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
const struct hnae3_ae_ops *ops = h->ae_algo->ops;
if (!ops->get_sset_count)
return -EOPNOTSUPP;
switch (stringset) {
case ETH_SS_STATS:
return ((HNS3_TQP_STATS_COUNT * h->kinfo.num_tqps) +
ops->get_sset_count(h, stringset));
case ETH_SS_TEST:
return ops->get_sset_count(h, stringset);
}
return 0;
}
static void *hns3_update_strings(u8 *data, const struct hns3_stats *stats,
u32 stat_count, u32 num_tqps)
{
#define MAX_PREFIX_SIZE (8 + 4)
u32 size_left;
u32 i, j;
u32 n1;
for (i = 0; i < num_tqps; i++) {
for (j = 0; j < stat_count; j++) {
data[ETH_GSTRING_LEN - 1] = '\0';
n1 = snprintf(data, MAX_PREFIX_SIZE, "rcb_q%d_", i);
n1 = min_t(uint, n1, MAX_PREFIX_SIZE - 1);
size_left = (ETH_GSTRING_LEN - 1) - n1;
strncat(data, stats[j].stats_string, size_left);
data += ETH_GSTRING_LEN;
}
}
return data;
}
static u8 *hns3_get_strings_tqps(struct hnae3_handle *handle, u8 *data)
{
struct hnae3_knic_private_info *kinfo = &handle->kinfo;
data = hns3_update_strings(data, hns3_txq_stats, HNS3_TXQ_STATS_COUNT,
kinfo->num_tqps);
data = hns3_update_strings(data, hns3_rxq_stats, HNS3_RXQ_STATS_COUNT,
kinfo->num_tqps);
return data;
}
static void hns3_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
const struct hnae3_ae_ops *ops = h->ae_algo->ops;
char *buff = (char *)data;
if (!ops->get_strings)
return;
switch (stringset) {
case ETH_SS_STATS:
buff = hns3_get_strings_tqps(h, buff);
h->ae_algo->ops->get_strings(h, stringset, (u8 *)buff);
break;
case ETH_SS_TEST:
ops->get_strings(h, stringset, data);
break;
}
}
static u64 *hns3_get_stats_tqps(struct hnae3_handle *handle, u64 *data)
{
struct hns3_nic_priv *nic_priv = (struct hns3_nic_priv *)handle->priv;
struct hnae3_knic_private_info *kinfo = &handle->kinfo;
struct hns3_enet_ring *ring;
u8 *stat;
u32 i;
for (i = 0; i < kinfo->num_tqps; i++) {
ring = nic_priv->ring_data[i].ring;
for (i = 0; i < HNS3_TXQ_STATS_COUNT; i++) {
stat = (u8 *)ring + hns3_txq_stats[i].stats_offset;
*data++ = *(u64 *)stat;
}
}
for (i = 0; i < kinfo->num_tqps; i++) {
ring = nic_priv->ring_data[i + kinfo->num_tqps].ring;
for (i = 0; i < HNS3_RXQ_STATS_COUNT; i++) {
stat = (u8 *)ring + hns3_rxq_stats[i].stats_offset;
*data++ = *(u64 *)stat;
}
}
return data;
}
void hns3_get_stats(struct net_device *netdev, struct ethtool_stats *stats,
u64 *data)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
u64 *p = data;
if (!h->ae_algo->ops->get_stats || !h->ae_algo->ops->update_stats) {
netdev_err(netdev, "could not get any statistics\n");
return;
}
h->ae_algo->ops->update_stats(h, &netdev->stats);
p = hns3_get_stats_tqps(h, p);
h->ae_algo->ops->get_stats(h, p);
}
static void hns3_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
strncpy(drvinfo->version, hns3_driver_version,
sizeof(drvinfo->version));
drvinfo->version[sizeof(drvinfo->version) - 1] = '\0';
strncpy(drvinfo->driver, h->pdev->driver->name,
sizeof(drvinfo->driver));
drvinfo->driver[sizeof(drvinfo->driver) - 1] = '\0';
strncpy(drvinfo->bus_info, pci_name(h->pdev),
sizeof(drvinfo->bus_info));
drvinfo->bus_info[ETHTOOL_BUSINFO_LEN - 1] = '\0';
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version), "0x%08x",
priv->ae_handle->ae_algo->ops->get_fw_version(h));
}
static u32 hns3_get_link(struct net_device *netdev)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h;
h = priv->ae_handle;
if (h->ae_algo && h->ae_algo->ops && h->ae_algo->ops->get_status)
return h->ae_algo->ops->get_status(h);
else
return 0;
}
static void hns3_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *param)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
int queue_num = priv->ae_handle->kinfo.num_tqps;
param->tx_max_pending = HNS3_RING_MAX_PENDING;
param->rx_max_pending = HNS3_RING_MAX_PENDING;
param->tx_pending = priv->ring_data[0].ring->desc_num;
param->rx_pending = priv->ring_data[queue_num].ring->desc_num;
}
static void hns3_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *param)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
if (h->ae_algo && h->ae_algo->ops && h->ae_algo->ops->get_pauseparam)
h->ae_algo->ops->get_pauseparam(h, &param->autoneg,
&param->rx_pause, &param->tx_pause);
}
static int hns3_get_link_ksettings(struct net_device *netdev,
struct ethtool_link_ksettings *cmd)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
u32 supported_caps;
u32 advertised_caps;
u8 media_type = HNAE3_MEDIA_TYPE_UNKNOWN;
u8 link_stat;
u8 auto_neg;
u8 duplex;
u32 speed;
if (!h->ae_algo || !h->ae_algo->ops)
return -EOPNOTSUPP;
if (h->ae_algo->ops->get_ksettings_an_result) {
h->ae_algo->ops->get_ksettings_an_result(h, &auto_neg,
&speed, &duplex);
cmd->base.autoneg = auto_neg;
cmd->base.speed = speed;
cmd->base.duplex = duplex;
link_stat = hns3_get_link(netdev);
if (!link_stat) {
cmd->base.speed = (u32)SPEED_UNKNOWN;
cmd->base.duplex = DUPLEX_UNKNOWN;
}
}
if (h->ae_algo->ops->get_media_type) {
h->ae_algo->ops->get_media_type(h, &media_type);
switch (media_type) {
case HNAE3_MEDIA_TYPE_FIBER:
cmd->base.port = PORT_FIBRE;
supported_caps = HNS3_LM_FIBRE_BIT |
HNS3_LM_AUTONEG_BIT |
HNS3_LM_PAUSE_BIT |
HNS3_LM_1000BASET_FULL_BIT;
advertised_caps = supported_caps;
break;
case HNAE3_MEDIA_TYPE_COPPER:
cmd->base.port = PORT_TP;
supported_caps = HNS3_LM_TP_BIT |
HNS3_LM_AUTONEG_BIT |
HNS3_LM_PAUSE_BIT |
HNS3_LM_1000BASET_FULL_BIT |
HNS3_LM_100BASET_FULL_BIT |
HNS3_LM_100BASET_HALF_BIT |
HNS3_LM_10BASET_FULL_BIT |
HNS3_LM_10BASET_HALF_BIT;
advertised_caps = supported_caps;
break;
case HNAE3_MEDIA_TYPE_BACKPLANE:
cmd->base.port = PORT_NONE;
supported_caps = HNS3_LM_BACKPLANE_BIT |
HNS3_LM_PAUSE_BIT |
HNS3_LM_AUTONEG_BIT |
HNS3_LM_1000BASET_FULL_BIT |
HNS3_LM_100BASET_FULL_BIT |
HNS3_LM_100BASET_HALF_BIT |
HNS3_LM_10BASET_FULL_BIT |
HNS3_LM_10BASET_HALF_BIT;
advertised_caps = supported_caps;
break;
case HNAE3_MEDIA_TYPE_UNKNOWN:
default:
cmd->base.port = PORT_OTHER;
supported_caps = 0;
advertised_caps = 0;
break;
}
hns3_driv_to_eth_caps(supported_caps, cmd, false);
hns3_driv_to_eth_caps(advertised_caps, cmd, true);
}
if (h->ae_algo->ops->get_mdix_mode)
h->ae_algo->ops->get_mdix_mode(h, &cmd->base.eth_tp_mdix_ctrl,
&cmd->base.eth_tp_mdix);
cmd->base.mdio_support = ETH_MDIO_SUPPORTS_C22;
return 0;
}
static u32 hns3_get_rss_key_size(struct net_device *netdev)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
if (!h->ae_algo || !h->ae_algo->ops ||
!h->ae_algo->ops->get_rss_key_size)
return -EOPNOTSUPP;
return h->ae_algo->ops->get_rss_key_size(h);
}
static u32 hns3_get_rss_indir_size(struct net_device *netdev)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
if (!h->ae_algo || !h->ae_algo->ops ||
!h->ae_algo->ops->get_rss_indir_size)
return -EOPNOTSUPP;
return h->ae_algo->ops->get_rss_indir_size(h);
}
static int hns3_get_rss(struct net_device *netdev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
if (!h->ae_algo || !h->ae_algo->ops || !h->ae_algo->ops->get_rss)
return -EOPNOTSUPP;
return h->ae_algo->ops->get_rss(h, indir, key, hfunc);
}
static int hns3_set_rss(struct net_device *netdev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
if (!h->ae_algo || !h->ae_algo->ops || !h->ae_algo->ops->set_rss)
return -EOPNOTSUPP;
if ((hfunc != ETH_RSS_HASH_NO_CHANGE) && (hfunc != ETH_RSS_HASH_TOP)) {
netdev_err(netdev,
"hash func not supported (only Toeplitz hash)\n");
return -EOPNOTSUPP;
}
if (!indir) {
netdev_err(netdev,
"set rss failed for indir is empty\n");
return -EOPNOTSUPP;
}
return h->ae_algo->ops->set_rss(h, indir, key, hfunc);
}
static int hns3_get_rxnfc(struct net_device *netdev,
struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
struct hns3_nic_priv *priv = netdev_priv(netdev);
struct hnae3_handle *h = priv->ae_handle;
if (!h->ae_algo || !h->ae_algo->ops || !h->ae_algo->ops->get_tc_size)
return -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_GRXRINGS:
cmd->data = h->ae_algo->ops->get_tc_size(h);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
void hns3_ethtool_set_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &hns3_ethtool_ops;
}
