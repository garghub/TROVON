static void nfp_net_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct nfp_net *nn = netdev_priv(netdev);
strlcpy(drvinfo->driver, nfp_net_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, nfp_net_driver_version,
sizeof(drvinfo->version));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"%d.%d.%d.%d",
nn->fw_ver.resv, nn->fw_ver.class,
nn->fw_ver.major, nn->fw_ver.minor);
strlcpy(drvinfo->bus_info, pci_name(nn->pdev),
sizeof(drvinfo->bus_info));
drvinfo->n_stats = NN_ET_STATS_LEN;
drvinfo->regdump_len = NFP_NET_CFG_BAR_SZ;
}
static void nfp_net_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct nfp_net *nn = netdev_priv(netdev);
ring->rx_max_pending = NFP_NET_MAX_RX_DESCS;
ring->tx_max_pending = NFP_NET_MAX_TX_DESCS;
ring->rx_pending = nn->rxd_cnt;
ring->tx_pending = nn->txd_cnt;
}
static int nfp_net_set_ring_size(struct nfp_net *nn, u32 rxd_cnt, u32 txd_cnt)
{
struct nfp_net_ring_set *reconfig_rx = NULL, *reconfig_tx = NULL;
struct nfp_net_ring_set rx = {
.n_rings = nn->num_rx_rings,
.mtu = nn->netdev->mtu,
.dcnt = rxd_cnt,
};
struct nfp_net_ring_set tx = {
.n_rings = nn->num_tx_rings,
.dcnt = txd_cnt,
};
if (nn->rxd_cnt != rxd_cnt)
reconfig_rx = &rx;
if (nn->txd_cnt != txd_cnt)
reconfig_tx = &tx;
return nfp_net_ring_reconfig(nn, &nn->xdp_prog,
reconfig_rx, reconfig_tx);
}
static int nfp_net_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct nfp_net *nn = netdev_priv(netdev);
u32 rxd_cnt, txd_cnt;
if (ring->rx_mini_pending || ring->rx_jumbo_pending)
return -EINVAL;
rxd_cnt = roundup_pow_of_two(ring->rx_pending);
txd_cnt = roundup_pow_of_two(ring->tx_pending);
if (rxd_cnt < NFP_NET_MIN_RX_DESCS || rxd_cnt > NFP_NET_MAX_RX_DESCS ||
txd_cnt < NFP_NET_MIN_TX_DESCS || txd_cnt > NFP_NET_MAX_TX_DESCS)
return -EINVAL;
if (nn->rxd_cnt == rxd_cnt && nn->txd_cnt == txd_cnt)
return 0;
nn_dbg(nn, "Change ring size: RxQ %u->%u, TxQ %u->%u\n",
nn->rxd_cnt, rxd_cnt, nn->txd_cnt, txd_cnt);
return nfp_net_set_ring_size(nn, rxd_cnt, txd_cnt);
}
static void nfp_net_get_strings(struct net_device *netdev,
u32 stringset, u8 *data)
{
struct nfp_net *nn = netdev_priv(netdev);
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < NN_ET_GLOBAL_STATS_LEN; i++) {
memcpy(p, nfp_net_et_stats[i].name, ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < nn->num_r_vecs; i++) {
sprintf(p, "rvec_%u_rx_pkts", i);
p += ETH_GSTRING_LEN;
sprintf(p, "rvec_%u_tx_pkts", i);
p += ETH_GSTRING_LEN;
sprintf(p, "rvec_%u_tx_busy", i);
p += ETH_GSTRING_LEN;
}
strncpy(p, "hw_rx_csum_ok", ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
strncpy(p, "hw_rx_csum_inner_ok", ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
strncpy(p, "hw_rx_csum_err", ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
strncpy(p, "hw_tx_csum", ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
strncpy(p, "hw_tx_inner_csum", ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
strncpy(p, "tx_gather", ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
strncpy(p, "tx_lso", ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
for (i = 0; i < nn->num_tx_rings; i++) {
sprintf(p, "txq_%u_pkts", i);
p += ETH_GSTRING_LEN;
sprintf(p, "txq_%u_bytes", i);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < nn->num_rx_rings; i++) {
sprintf(p, "rxq_%u_pkts", i);
p += ETH_GSTRING_LEN;
sprintf(p, "rxq_%u_bytes", i);
p += ETH_GSTRING_LEN;
}
break;
}
}
static void nfp_net_get_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
u64 gathered_stats[NN_ET_RVEC_GATHER_STATS] = {};
struct nfp_net *nn = netdev_priv(netdev);
struct rtnl_link_stats64 *netdev_stats;
struct rtnl_link_stats64 temp = {};
u64 tmp[NN_ET_RVEC_GATHER_STATS];
u8 __iomem *io_p;
int i, j, k;
u8 *p;
netdev_stats = dev_get_stats(netdev, &temp);
for (i = 0; i < NN_ET_GLOBAL_STATS_LEN; i++) {
switch (nfp_net_et_stats[i].type) {
case NETDEV_ET_STATS:
p = (char *)netdev_stats + nfp_net_et_stats[i].off;
data[i] = nfp_net_et_stats[i].sz == sizeof(u64) ?
*(u64 *)p : *(u32 *)p;
break;
case NFP_NET_DEV_ET_STATS:
io_p = nn->ctrl_bar + nfp_net_et_stats[i].off;
data[i] = readq(io_p);
break;
}
}
for (j = 0; j < nn->num_r_vecs; j++) {
unsigned int start;
do {
start = u64_stats_fetch_begin(&nn->r_vecs[j].rx_sync);
data[i++] = nn->r_vecs[j].rx_pkts;
tmp[0] = nn->r_vecs[j].hw_csum_rx_ok;
tmp[1] = nn->r_vecs[j].hw_csum_rx_inner_ok;
tmp[2] = nn->r_vecs[j].hw_csum_rx_error;
} while (u64_stats_fetch_retry(&nn->r_vecs[j].rx_sync, start));
do {
start = u64_stats_fetch_begin(&nn->r_vecs[j].tx_sync);
data[i++] = nn->r_vecs[j].tx_pkts;
data[i++] = nn->r_vecs[j].tx_busy;
tmp[3] = nn->r_vecs[j].hw_csum_tx;
tmp[4] = nn->r_vecs[j].hw_csum_tx_inner;
tmp[5] = nn->r_vecs[j].tx_gather;
tmp[6] = nn->r_vecs[j].tx_lso;
} while (u64_stats_fetch_retry(&nn->r_vecs[j].tx_sync, start));
for (k = 0; k < NN_ET_RVEC_GATHER_STATS; k++)
gathered_stats[k] += tmp[k];
}
for (j = 0; j < NN_ET_RVEC_GATHER_STATS; j++)
data[i++] = gathered_stats[j];
for (j = 0; j < nn->num_tx_rings; j++) {
io_p = nn->ctrl_bar + NFP_NET_CFG_TXR_STATS(j);
data[i++] = readq(io_p);
io_p = nn->ctrl_bar + NFP_NET_CFG_TXR_STATS(j) + 8;
data[i++] = readq(io_p);
}
for (j = 0; j < nn->num_rx_rings; j++) {
io_p = nn->ctrl_bar + NFP_NET_CFG_RXR_STATS(j);
data[i++] = readq(io_p);
io_p = nn->ctrl_bar + NFP_NET_CFG_RXR_STATS(j) + 8;
data[i++] = readq(io_p);
}
}
static int nfp_net_get_sset_count(struct net_device *netdev, int sset)
{
struct nfp_net *nn = netdev_priv(netdev);
switch (sset) {
case ETH_SS_STATS:
return NN_ET_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static u32 ethtool_flow_to_nfp_flag(u32 flow_type)
{
static const u32 xlate_ethtool_to_nfp[IPV6_FLOW + 1] = {
[TCP_V4_FLOW] = NFP_NET_CFG_RSS_IPV4_TCP,
[TCP_V6_FLOW] = NFP_NET_CFG_RSS_IPV6_TCP,
[UDP_V4_FLOW] = NFP_NET_CFG_RSS_IPV4_UDP,
[UDP_V6_FLOW] = NFP_NET_CFG_RSS_IPV6_UDP,
[IPV4_FLOW] = NFP_NET_CFG_RSS_IPV4,
[IPV6_FLOW] = NFP_NET_CFG_RSS_IPV6,
};
if (flow_type >= ARRAY_SIZE(xlate_ethtool_to_nfp))
return 0;
return xlate_ethtool_to_nfp[flow_type];
}
static int nfp_net_get_rss_hash_opts(struct nfp_net *nn,
struct ethtool_rxnfc *cmd)
{
u32 nfp_rss_flag;
cmd->data = 0;
if (!(nn->cap & NFP_NET_CFG_CTRL_RSS))
return -EOPNOTSUPP;
nfp_rss_flag = ethtool_flow_to_nfp_flag(cmd->flow_type);
if (!nfp_rss_flag)
return -EINVAL;
cmd->data |= RXH_IP_SRC | RXH_IP_DST;
if (nn->rss_cfg & nfp_rss_flag)
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
return 0;
}
static int nfp_net_get_rxnfc(struct net_device *netdev,
struct ethtool_rxnfc *cmd, u32 *rule_locs)
{
struct nfp_net *nn = netdev_priv(netdev);
switch (cmd->cmd) {
case ETHTOOL_GRXRINGS:
cmd->data = nn->num_rx_rings;
return 0;
case ETHTOOL_GRXFH:
return nfp_net_get_rss_hash_opts(nn, cmd);
default:
return -EOPNOTSUPP;
}
}
static int nfp_net_set_rss_hash_opt(struct nfp_net *nn,
struct ethtool_rxnfc *nfc)
{
u32 new_rss_cfg = nn->rss_cfg;
u32 nfp_rss_flag;
int err;
if (!(nn->cap & NFP_NET_CFG_CTRL_RSS))
return -EOPNOTSUPP;
if (nfc->data & ~(RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3))
return -EINVAL;
if (!(nfc->data & RXH_IP_SRC) ||
!(nfc->data & RXH_IP_DST))
return -EINVAL;
nfp_rss_flag = ethtool_flow_to_nfp_flag(nfc->flow_type);
if (!nfp_rss_flag)
return -EINVAL;
switch (nfc->data & (RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
case 0:
new_rss_cfg &= ~nfp_rss_flag;
break;
case (RXH_L4_B_0_1 | RXH_L4_B_2_3):
new_rss_cfg |= nfp_rss_flag;
break;
default:
return -EINVAL;
}
new_rss_cfg |= NFP_NET_CFG_RSS_TOEPLITZ;
new_rss_cfg |= NFP_NET_CFG_RSS_MASK;
if (new_rss_cfg == nn->rss_cfg)
return 0;
writel(new_rss_cfg, nn->ctrl_bar + NFP_NET_CFG_RSS_CTRL);
err = nfp_net_reconfig(nn, NFP_NET_CFG_UPDATE_RSS);
if (err)
return err;
nn->rss_cfg = new_rss_cfg;
nn_dbg(nn, "Changed RSS config to 0x%x\n", nn->rss_cfg);
return 0;
}
static int nfp_net_set_rxnfc(struct net_device *netdev,
struct ethtool_rxnfc *cmd)
{
struct nfp_net *nn = netdev_priv(netdev);
switch (cmd->cmd) {
case ETHTOOL_SRXFH:
return nfp_net_set_rss_hash_opt(nn, cmd);
default:
return -EOPNOTSUPP;
}
}
static u32 nfp_net_get_rxfh_indir_size(struct net_device *netdev)
{
struct nfp_net *nn = netdev_priv(netdev);
if (!(nn->cap & NFP_NET_CFG_CTRL_RSS))
return 0;
return ARRAY_SIZE(nn->rss_itbl);
}
static u32 nfp_net_get_rxfh_key_size(struct net_device *netdev)
{
return NFP_NET_CFG_RSS_KEY_SZ;
}
static int nfp_net_get_rxfh(struct net_device *netdev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct nfp_net *nn = netdev_priv(netdev);
int i;
if (!(nn->cap & NFP_NET_CFG_CTRL_RSS))
return -EOPNOTSUPP;
if (indir)
for (i = 0; i < ARRAY_SIZE(nn->rss_itbl); i++)
indir[i] = nn->rss_itbl[i];
if (key)
memcpy(key, nn->rss_key, NFP_NET_CFG_RSS_KEY_SZ);
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
return 0;
}
static int nfp_net_set_rxfh(struct net_device *netdev,
const u32 *indir, const u8 *key,
const u8 hfunc)
{
struct nfp_net *nn = netdev_priv(netdev);
int i;
if (!(nn->cap & NFP_NET_CFG_CTRL_RSS) ||
!(hfunc == ETH_RSS_HASH_NO_CHANGE || hfunc == ETH_RSS_HASH_TOP))
return -EOPNOTSUPP;
if (!key && !indir)
return 0;
if (key) {
memcpy(nn->rss_key, key, NFP_NET_CFG_RSS_KEY_SZ);
nfp_net_rss_write_key(nn);
}
if (indir) {
for (i = 0; i < ARRAY_SIZE(nn->rss_itbl); i++)
nn->rss_itbl[i] = indir[i];
nfp_net_rss_write_itbl(nn);
}
return nfp_net_reconfig(nn, NFP_NET_CFG_UPDATE_RSS);
}
static int nfp_net_get_regs_len(struct net_device *netdev)
{
return NFP_NET_CFG_BAR_SZ;
}
static void nfp_net_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *p)
{
struct nfp_net *nn = netdev_priv(netdev);
u32 *regs_buf = p;
int i;
regs->version = nn_readl(nn, NFP_NET_CFG_VERSION);
for (i = 0; i < NFP_NET_CFG_BAR_SZ / sizeof(u32); i++)
regs_buf[i] = readl(nn->ctrl_bar + (i * sizeof(u32)));
}
static int nfp_net_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct nfp_net *nn = netdev_priv(netdev);
if (!(nn->cap & NFP_NET_CFG_CTRL_IRQMOD))
return -EINVAL;
ec->rx_coalesce_usecs = nn->rx_coalesce_usecs;
ec->rx_max_coalesced_frames = nn->rx_coalesce_max_frames;
ec->tx_coalesce_usecs = nn->tx_coalesce_usecs;
ec->tx_max_coalesced_frames = nn->tx_coalesce_max_frames;
return 0;
}
static int nfp_net_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct nfp_net *nn = netdev_priv(netdev);
unsigned int factor;
if (ec->rx_coalesce_usecs_irq ||
ec->rx_max_coalesced_frames_irq ||
ec->tx_coalesce_usecs_irq ||
ec->tx_max_coalesced_frames_irq ||
ec->stats_block_coalesce_usecs ||
ec->use_adaptive_rx_coalesce ||
ec->use_adaptive_tx_coalesce ||
ec->pkt_rate_low ||
ec->rx_coalesce_usecs_low ||
ec->rx_max_coalesced_frames_low ||
ec->tx_coalesce_usecs_low ||
ec->tx_max_coalesced_frames_low ||
ec->pkt_rate_high ||
ec->rx_coalesce_usecs_high ||
ec->rx_max_coalesced_frames_high ||
ec->tx_coalesce_usecs_high ||
ec->tx_max_coalesced_frames_high ||
ec->rate_sample_interval)
return -ENOTSUPP;
factor = nn->me_freq_mhz / 16;
if (!(nn->cap & NFP_NET_CFG_CTRL_IRQMOD))
return -EINVAL;
if (!ec->rx_coalesce_usecs && !ec->rx_max_coalesced_frames)
return -EINVAL;
if (!ec->tx_coalesce_usecs && !ec->tx_max_coalesced_frames)
return -EINVAL;
if (ec->rx_coalesce_usecs * factor >= ((1 << 16) - 1))
return -EINVAL;
if (ec->tx_coalesce_usecs * factor >= ((1 << 16) - 1))
return -EINVAL;
if (ec->rx_max_coalesced_frames >= ((1 << 16) - 1))
return -EINVAL;
if (ec->tx_max_coalesced_frames >= ((1 << 16) - 1))
return -EINVAL;
nn->rx_coalesce_usecs = ec->rx_coalesce_usecs;
nn->rx_coalesce_max_frames = ec->rx_max_coalesced_frames;
nn->tx_coalesce_usecs = ec->tx_coalesce_usecs;
nn->tx_coalesce_max_frames = ec->tx_max_coalesced_frames;
nfp_net_coalesce_write_cfg(nn);
return nfp_net_reconfig(nn, NFP_NET_CFG_UPDATE_IRQMOD);
}
static void nfp_net_get_channels(struct net_device *netdev,
struct ethtool_channels *channel)
{
struct nfp_net *nn = netdev_priv(netdev);
unsigned int num_tx_rings;
num_tx_rings = nn->num_tx_rings;
if (nn->xdp_prog)
num_tx_rings -= nn->num_rx_rings;
channel->max_rx = min(nn->max_rx_rings, nn->max_r_vecs);
channel->max_tx = min(nn->max_tx_rings, nn->max_r_vecs);
channel->max_combined = min(channel->max_rx, channel->max_tx);
channel->max_other = NFP_NET_NON_Q_VECTORS;
channel->combined_count = min(nn->num_rx_rings, num_tx_rings);
channel->rx_count = nn->num_rx_rings - channel->combined_count;
channel->tx_count = num_tx_rings - channel->combined_count;
channel->other_count = NFP_NET_NON_Q_VECTORS;
}
static int nfp_net_set_num_rings(struct nfp_net *nn, unsigned int total_rx,
unsigned int total_tx)
{
struct nfp_net_ring_set *reconfig_rx = NULL, *reconfig_tx = NULL;
struct nfp_net_ring_set rx = {
.n_rings = total_rx,
.mtu = nn->netdev->mtu,
.dcnt = nn->rxd_cnt,
};
struct nfp_net_ring_set tx = {
.n_rings = total_tx,
.dcnt = nn->txd_cnt,
};
if (nn->num_rx_rings != total_rx)
reconfig_rx = &rx;
if (nn->num_stack_tx_rings != total_tx ||
(nn->xdp_prog && reconfig_rx))
reconfig_tx = &tx;
if (nn->xdp_prog)
tx.n_rings += total_rx;
return nfp_net_ring_reconfig(nn, &nn->xdp_prog,
reconfig_rx, reconfig_tx);
}
static int nfp_net_set_channels(struct net_device *netdev,
struct ethtool_channels *channel)
{
struct nfp_net *nn = netdev_priv(netdev);
unsigned int total_rx, total_tx;
if (!channel->combined_count ||
channel->other_count != NFP_NET_NON_Q_VECTORS ||
(channel->rx_count && channel->tx_count))
return -EINVAL;
total_rx = channel->combined_count + channel->rx_count;
total_tx = channel->combined_count + channel->tx_count;
if (total_rx > min(nn->max_rx_rings, nn->max_r_vecs) ||
total_tx > min(nn->max_tx_rings, nn->max_r_vecs))
return -EINVAL;
return nfp_net_set_num_rings(nn, total_rx, total_tx);
}
void nfp_net_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &nfp_net_ethtool_ops;
}
