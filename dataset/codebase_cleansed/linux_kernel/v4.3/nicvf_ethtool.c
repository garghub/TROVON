static int nicvf_get_settings(struct net_device *netdev,
struct ethtool_cmd *cmd)
{
struct nicvf *nic = netdev_priv(netdev);
cmd->supported = 0;
cmd->transceiver = XCVR_EXTERNAL;
if (nic->speed <= 1000) {
cmd->port = PORT_MII;
cmd->autoneg = AUTONEG_ENABLE;
} else {
cmd->port = PORT_FIBRE;
cmd->autoneg = AUTONEG_DISABLE;
}
cmd->duplex = nic->duplex;
ethtool_cmd_speed_set(cmd, nic->speed);
return 0;
}
static void nicvf_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *info)
{
struct nicvf *nic = netdev_priv(netdev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(nic->pdev), sizeof(info->bus_info));
}
static u32 nicvf_get_msglevel(struct net_device *netdev)
{
struct nicvf *nic = netdev_priv(netdev);
return nic->msg_enable;
}
static void nicvf_set_msglevel(struct net_device *netdev, u32 lvl)
{
struct nicvf *nic = netdev_priv(netdev);
nic->msg_enable = lvl;
}
static void nicvf_get_qset_strings(struct nicvf *nic, u8 **data, int qset)
{
int stats, qidx;
int start_qidx = qset * MAX_RCV_QUEUES_PER_QS;
for (qidx = 0; qidx < nic->qs->rq_cnt; qidx++) {
for (stats = 0; stats < nicvf_n_queue_stats; stats++) {
sprintf(*data, "rxq%d: %s", qidx + start_qidx,
nicvf_queue_stats[stats].name);
*data += ETH_GSTRING_LEN;
}
}
for (qidx = 0; qidx < nic->qs->sq_cnt; qidx++) {
for (stats = 0; stats < nicvf_n_queue_stats; stats++) {
sprintf(*data, "txq%d: %s", qidx + start_qidx,
nicvf_queue_stats[stats].name);
*data += ETH_GSTRING_LEN;
}
}
}
static void nicvf_get_strings(struct net_device *netdev, u32 sset, u8 *data)
{
struct nicvf *nic = netdev_priv(netdev);
int stats;
int sqs;
if (sset != ETH_SS_STATS)
return;
for (stats = 0; stats < nicvf_n_hw_stats; stats++) {
memcpy(data, nicvf_hw_stats[stats].name, ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
for (stats = 0; stats < nicvf_n_drv_stats; stats++) {
memcpy(data, nicvf_drv_stats[stats].name, ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
nicvf_get_qset_strings(nic, &data, 0);
for (sqs = 0; sqs < nic->sqs_count; sqs++) {
if (!nic->snicvf[sqs])
continue;
nicvf_get_qset_strings(nic->snicvf[sqs], &data, sqs + 1);
}
for (stats = 0; stats < BGX_RX_STATS_COUNT; stats++) {
sprintf(data, "bgx_rxstat%d: ", stats);
data += ETH_GSTRING_LEN;
}
for (stats = 0; stats < BGX_TX_STATS_COUNT; stats++) {
sprintf(data, "bgx_txstat%d: ", stats);
data += ETH_GSTRING_LEN;
}
}
static int nicvf_get_sset_count(struct net_device *netdev, int sset)
{
struct nicvf *nic = netdev_priv(netdev);
int qstats_count;
int sqs;
if (sset != ETH_SS_STATS)
return -EINVAL;
qstats_count = nicvf_n_queue_stats *
(nic->qs->rq_cnt + nic->qs->sq_cnt);
for (sqs = 0; sqs < nic->sqs_count; sqs++) {
struct nicvf *snic;
snic = nic->snicvf[sqs];
if (!snic)
continue;
qstats_count += nicvf_n_queue_stats *
(snic->qs->rq_cnt + snic->qs->sq_cnt);
}
return nicvf_n_hw_stats + nicvf_n_drv_stats +
qstats_count +
BGX_RX_STATS_COUNT + BGX_TX_STATS_COUNT;
}
static void nicvf_get_qset_stats(struct nicvf *nic,
struct ethtool_stats *stats, u64 **data)
{
int stat, qidx;
if (!nic)
return;
for (qidx = 0; qidx < nic->qs->rq_cnt; qidx++) {
nicvf_update_rq_stats(nic, qidx);
for (stat = 0; stat < nicvf_n_queue_stats; stat++)
*((*data)++) = ((u64 *)&nic->qs->rq[qidx].stats)
[nicvf_queue_stats[stat].index];
}
for (qidx = 0; qidx < nic->qs->sq_cnt; qidx++) {
nicvf_update_sq_stats(nic, qidx);
for (stat = 0; stat < nicvf_n_queue_stats; stat++)
*((*data)++) = ((u64 *)&nic->qs->sq[qidx].stats)
[nicvf_queue_stats[stat].index];
}
}
static void nicvf_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct nicvf *nic = netdev_priv(netdev);
int stat;
int sqs;
nicvf_update_stats(nic);
nicvf_update_lmac_stats(nic);
for (stat = 0; stat < nicvf_n_hw_stats; stat++)
*(data++) = ((u64 *)&nic->hw_stats)
[nicvf_hw_stats[stat].index];
for (stat = 0; stat < nicvf_n_drv_stats; stat++)
*(data++) = ((u64 *)&nic->drv_stats)
[nicvf_drv_stats[stat].index];
nicvf_get_qset_stats(nic, stats, &data);
for (sqs = 0; sqs < nic->sqs_count; sqs++) {
if (!nic->snicvf[sqs])
continue;
nicvf_get_qset_stats(nic->snicvf[sqs], stats, &data);
}
for (stat = 0; stat < BGX_RX_STATS_COUNT; stat++)
*(data++) = nic->bgx_stats.rx_stats[stat];
for (stat = 0; stat < BGX_TX_STATS_COUNT; stat++)
*(data++) = nic->bgx_stats.tx_stats[stat];
}
static int nicvf_get_regs_len(struct net_device *dev)
{
return sizeof(u64) * NIC_VF_REG_COUNT;
}
static void nicvf_get_regs(struct net_device *dev,
struct ethtool_regs *regs, void *reg)
{
struct nicvf *nic = netdev_priv(dev);
u64 *p = (u64 *)reg;
u64 reg_offset;
int mbox, key, stat, q;
int i = 0;
regs->version = 0;
memset(p, 0, NIC_VF_REG_COUNT);
p[i++] = nicvf_reg_read(nic, NIC_VNIC_CFG);
for (mbox = 0; mbox < NIC_PF_VF_MAILBOX_SIZE; mbox++)
p[i++] = nicvf_reg_read(nic,
NIC_VF_PF_MAILBOX_0_1 | (mbox << 3));
p[i++] = nicvf_reg_read(nic, NIC_VF_INT);
p[i++] = nicvf_reg_read(nic, NIC_VF_INT_W1S);
p[i++] = nicvf_reg_read(nic, NIC_VF_ENA_W1C);
p[i++] = nicvf_reg_read(nic, NIC_VF_ENA_W1S);
p[i++] = nicvf_reg_read(nic, NIC_VNIC_RSS_CFG);
for (key = 0; key < RSS_HASH_KEY_SIZE; key++)
p[i++] = nicvf_reg_read(nic, NIC_VNIC_RSS_KEY_0_4 | (key << 3));
for (stat = 0; stat < TX_STATS_ENUM_LAST; stat++)
p[i++] = nicvf_reg_read(nic,
NIC_VNIC_TX_STAT_0_4 | (stat << 3));
for (i = 0; i < RX_STATS_ENUM_LAST; i++)
p[i++] = nicvf_reg_read(nic,
NIC_VNIC_RX_STAT_0_13 | (stat << 3));
p[i++] = nicvf_reg_read(nic, NIC_QSET_RQ_GEN_CFG);
for (q = 0; q < MAX_CMP_QUEUES_PER_QS; q++) {
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_CFG, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_CFG2, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_THRESH, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_BASE, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_HEAD, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_TAIL, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_DOOR, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_STATUS, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_STATUS2, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_CQ_0_7_DEBUG, q);
}
for (q = 0; q < MAX_RCV_QUEUES_PER_QS; q++) {
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_RQ_0_7_CFG, q);
p[i++] = nicvf_queue_reg_read(nic,
NIC_QSET_RQ_0_7_STAT_0_1, q);
reg_offset = NIC_QSET_RQ_0_7_STAT_0_1 | (1 << 3);
p[i++] = nicvf_queue_reg_read(nic, reg_offset, q);
}
for (q = 0; q < MAX_SND_QUEUES_PER_QS; q++) {
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_CFG, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_THRESH, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_BASE, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_HEAD, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_TAIL, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_DOOR, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_STATUS, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_DEBUG, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_CNM_CHG, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1, q);
reg_offset = NIC_QSET_SQ_0_7_STAT_0_1 | (1 << 3);
p[i++] = nicvf_queue_reg_read(nic, reg_offset, q);
}
for (q = 0; q < MAX_RCV_BUF_DESC_RINGS_PER_QS; q++) {
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_RBDR_0_1_CFG, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_RBDR_0_1_THRESH, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_RBDR_0_1_BASE, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_RBDR_0_1_HEAD, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_RBDR_0_1_TAIL, q);
p[i++] = nicvf_queue_reg_read(nic, NIC_QSET_RBDR_0_1_DOOR, q);
p[i++] = nicvf_queue_reg_read(nic,
NIC_QSET_RBDR_0_1_STATUS0, q);
p[i++] = nicvf_queue_reg_read(nic,
NIC_QSET_RBDR_0_1_STATUS1, q);
reg_offset = NIC_QSET_RBDR_0_1_PREFETCH_STATUS;
p[i++] = nicvf_queue_reg_read(nic, reg_offset, q);
}
}
static int nicvf_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *cmd)
{
struct nicvf *nic = netdev_priv(netdev);
cmd->rx_coalesce_usecs = nic->cq_coalesce_usecs;
return 0;
}
static void nicvf_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct nicvf *nic = netdev_priv(netdev);
struct queue_set *qs = nic->qs;
ring->rx_max_pending = MAX_RCV_BUF_COUNT;
ring->rx_pending = qs->rbdr_len;
ring->tx_max_pending = MAX_SND_QUEUE_LEN;
ring->tx_pending = qs->sq_len;
}
static int nicvf_get_rss_hash_opts(struct nicvf *nic,
struct ethtool_rxnfc *info)
{
info->data = 0;
switch (info->flow_type) {
case TCP_V4_FLOW:
case TCP_V6_FLOW:
case UDP_V4_FLOW:
case UDP_V6_FLOW:
case SCTP_V4_FLOW:
case SCTP_V6_FLOW:
info->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
case IPV4_FLOW:
case IPV6_FLOW:
info->data |= RXH_IP_SRC | RXH_IP_DST;
break;
default:
return -EINVAL;
}
return 0;
}
static int nicvf_get_rxnfc(struct net_device *dev,
struct ethtool_rxnfc *info, u32 *rules)
{
struct nicvf *nic = netdev_priv(dev);
int ret = -EOPNOTSUPP;
switch (info->cmd) {
case ETHTOOL_GRXRINGS:
info->data = nic->rx_queues;
ret = 0;
break;
case ETHTOOL_GRXFH:
return nicvf_get_rss_hash_opts(nic, info);
default:
break;
}
return ret;
}
static int nicvf_set_rss_hash_opts(struct nicvf *nic,
struct ethtool_rxnfc *info)
{
struct nicvf_rss_info *rss = &nic->rss_info;
u64 rss_cfg = nicvf_reg_read(nic, NIC_VNIC_RSS_CFG);
if (!rss->enable)
netdev_err(nic->netdev,
"RSS is disabled, hash cannot be set\n");
netdev_info(nic->netdev, "Set RSS flow type = %d, data = %lld\n",
info->flow_type, info->data);
if (!(info->data & RXH_IP_SRC) || !(info->data & RXH_IP_DST))
return -EINVAL;
switch (info->flow_type) {
case TCP_V4_FLOW:
case TCP_V6_FLOW:
switch (info->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
rss_cfg &= ~(1ULL << RSS_HASH_TCP);
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
rss_cfg |= (1ULL << RSS_HASH_TCP);
break;
default:
return -EINVAL;
}
break;
case UDP_V4_FLOW:
case UDP_V6_FLOW:
switch (info->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
rss_cfg &= ~(1ULL << RSS_HASH_UDP);
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
rss_cfg |= (1ULL << RSS_HASH_UDP);
break;
default:
return -EINVAL;
}
break;
case SCTP_V4_FLOW:
case SCTP_V6_FLOW:
switch (info->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
rss_cfg &= ~(1ULL << RSS_HASH_L4ETC);
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
rss_cfg |= (1ULL << RSS_HASH_L4ETC);
break;
default:
return -EINVAL;
}
break;
case IPV4_FLOW:
case IPV6_FLOW:
rss_cfg = RSS_HASH_IP;
break;
default:
return -EINVAL;
}
nicvf_reg_write(nic, NIC_VNIC_RSS_CFG, rss_cfg);
return 0;
}
static int nicvf_set_rxnfc(struct net_device *dev, struct ethtool_rxnfc *info)
{
struct nicvf *nic = netdev_priv(dev);
switch (info->cmd) {
case ETHTOOL_SRXFH:
return nicvf_set_rss_hash_opts(nic, info);
default:
break;
}
return -EOPNOTSUPP;
}
static u32 nicvf_get_rxfh_key_size(struct net_device *netdev)
{
return RSS_HASH_KEY_SIZE * sizeof(u64);
}
static u32 nicvf_get_rxfh_indir_size(struct net_device *dev)
{
struct nicvf *nic = netdev_priv(dev);
return nic->rss_info.rss_size;
}
static int nicvf_get_rxfh(struct net_device *dev, u32 *indir, u8 *hkey,
u8 *hfunc)
{
struct nicvf *nic = netdev_priv(dev);
struct nicvf_rss_info *rss = &nic->rss_info;
int idx;
if (indir) {
for (idx = 0; idx < rss->rss_size; idx++)
indir[idx] = rss->ind_tbl[idx];
}
if (hkey)
memcpy(hkey, rss->key, RSS_HASH_KEY_SIZE * sizeof(u64));
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
return 0;
}
static int nicvf_set_rxfh(struct net_device *dev, const u32 *indir,
const u8 *hkey, u8 hfunc)
{
struct nicvf *nic = netdev_priv(dev);
struct nicvf_rss_info *rss = &nic->rss_info;
int idx;
if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP)
return -EOPNOTSUPP;
if (!rss->enable) {
netdev_err(nic->netdev,
"RSS is disabled, cannot change settings\n");
return -EIO;
}
if (indir) {
for (idx = 0; idx < rss->rss_size; idx++)
rss->ind_tbl[idx] = indir[idx];
}
if (hkey) {
memcpy(rss->key, hkey, RSS_HASH_KEY_SIZE * sizeof(u64));
nicvf_set_rss_key(nic);
}
nicvf_config_rss(nic);
return 0;
}
static void nicvf_get_channels(struct net_device *dev,
struct ethtool_channels *channel)
{
struct nicvf *nic = netdev_priv(dev);
memset(channel, 0, sizeof(*channel));
channel->max_rx = nic->max_queues;
channel->max_tx = nic->max_queues;
channel->rx_count = nic->rx_queues;
channel->tx_count = nic->tx_queues;
}
static int nicvf_set_channels(struct net_device *dev,
struct ethtool_channels *channel)
{
struct nicvf *nic = netdev_priv(dev);
int err = 0;
bool if_up = netif_running(dev);
int cqcount;
if (!channel->rx_count || !channel->tx_count)
return -EINVAL;
if (channel->rx_count > nic->max_queues)
return -EINVAL;
if (channel->tx_count > nic->max_queues)
return -EINVAL;
if (if_up)
nicvf_stop(dev);
cqcount = max(channel->rx_count, channel->tx_count);
if (cqcount > MAX_CMP_QUEUES_PER_QS) {
nic->sqs_count = roundup(cqcount, MAX_CMP_QUEUES_PER_QS);
nic->sqs_count = (nic->sqs_count / MAX_CMP_QUEUES_PER_QS) - 1;
} else {
nic->sqs_count = 0;
}
nic->qs->rq_cnt = min_t(u32, channel->rx_count, MAX_RCV_QUEUES_PER_QS);
nic->qs->sq_cnt = min_t(u32, channel->tx_count, MAX_SND_QUEUES_PER_QS);
nic->qs->cq_cnt = max(nic->qs->rq_cnt, nic->qs->sq_cnt);
nic->rx_queues = channel->rx_count;
nic->tx_queues = channel->tx_count;
err = nicvf_set_real_num_queues(dev, nic->tx_queues, nic->rx_queues);
if (err)
return err;
if (if_up)
nicvf_open(dev);
netdev_info(dev, "Setting num Tx rings to %d, Rx rings to %d success\n",
nic->tx_queues, nic->rx_queues);
return err;
}
void nicvf_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &nicvf_ethtool_ops;
}
