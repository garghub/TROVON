static u32 bnxt_get_msglevel(struct net_device *dev)
{
struct bnxt *bp = netdev_priv(dev);
return bp->msg_enable;
}
static void bnxt_set_msglevel(struct net_device *dev, u32 value)
{
struct bnxt *bp = netdev_priv(dev);
bp->msg_enable = value;
}
static int bnxt_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *coal)
{
struct bnxt *bp = netdev_priv(dev);
memset(coal, 0, sizeof(*coal));
coal->rx_coalesce_usecs = bp->rx_coal_ticks;
coal->rx_max_coalesced_frames = bp->rx_coal_bufs / 2;
coal->rx_coalesce_usecs_irq = bp->rx_coal_ticks_irq;
coal->rx_max_coalesced_frames_irq = bp->rx_coal_bufs_irq / 2;
coal->tx_coalesce_usecs = bp->tx_coal_ticks;
coal->tx_max_coalesced_frames = bp->tx_coal_bufs;
coal->tx_coalesce_usecs_irq = bp->tx_coal_ticks_irq;
coal->tx_max_coalesced_frames_irq = bp->tx_coal_bufs_irq;
coal->stats_block_coalesce_usecs = bp->stats_coal_ticks;
return 0;
}
static int bnxt_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *coal)
{
struct bnxt *bp = netdev_priv(dev);
bool update_stats = false;
int rc = 0;
bp->rx_coal_ticks = coal->rx_coalesce_usecs;
bp->rx_coal_bufs = coal->rx_max_coalesced_frames * 2;
bp->rx_coal_ticks_irq = coal->rx_coalesce_usecs_irq;
bp->rx_coal_bufs_irq = coal->rx_max_coalesced_frames_irq * 2;
bp->tx_coal_ticks = coal->tx_coalesce_usecs;
bp->tx_coal_bufs = coal->tx_max_coalesced_frames;
bp->tx_coal_ticks_irq = coal->tx_coalesce_usecs_irq;
bp->tx_coal_bufs_irq = coal->tx_max_coalesced_frames_irq;
if (bp->stats_coal_ticks != coal->stats_block_coalesce_usecs) {
u32 stats_ticks = coal->stats_block_coalesce_usecs;
stats_ticks = clamp_t(u32, stats_ticks,
BNXT_MIN_STATS_COAL_TICKS,
BNXT_MAX_STATS_COAL_TICKS);
stats_ticks = rounddown(stats_ticks, BNXT_MIN_STATS_COAL_TICKS);
bp->stats_coal_ticks = stats_ticks;
update_stats = true;
}
if (netif_running(dev)) {
if (update_stats) {
rc = bnxt_close_nic(bp, true, false);
if (!rc)
rc = bnxt_open_nic(bp, true, false);
} else {
rc = bnxt_hwrm_set_coal(bp);
}
}
return rc;
}
static int bnxt_get_sset_count(struct net_device *dev, int sset)
{
struct bnxt *bp = netdev_priv(dev);
switch (sset) {
case ETH_SS_STATS: {
int num_stats = BNXT_NUM_STATS * bp->cp_nr_rings;
if (bp->flags & BNXT_FLAG_PORT_STATS)
num_stats += BNXT_NUM_PORT_STATS;
return num_stats;
}
default:
return -EOPNOTSUPP;
}
}
static void bnxt_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *buf)
{
u32 i, j = 0;
struct bnxt *bp = netdev_priv(dev);
u32 buf_size = sizeof(struct ctx_hw_stats) * bp->cp_nr_rings;
u32 stat_fields = sizeof(struct ctx_hw_stats) / 8;
memset(buf, 0, buf_size);
if (!bp->bnapi)
return;
for (i = 0; i < bp->cp_nr_rings; i++) {
struct bnxt_napi *bnapi = bp->bnapi[i];
struct bnxt_cp_ring_info *cpr = &bnapi->cp_ring;
__le64 *hw_stats = (__le64 *)cpr->hw_stats;
int k;
for (k = 0; k < stat_fields; j++, k++)
buf[j] = le64_to_cpu(hw_stats[k]);
buf[j++] = cpr->rx_l4_csum_errors;
}
if (bp->flags & BNXT_FLAG_PORT_STATS) {
__le64 *port_stats = (__le64 *)bp->hw_rx_port_stats;
for (i = 0; i < BNXT_NUM_PORT_STATS; i++, j++) {
buf[j] = le64_to_cpu(*(port_stats +
bnxt_port_stats_arr[i].offset));
}
}
}
static void bnxt_get_strings(struct net_device *dev, u32 stringset, u8 *buf)
{
struct bnxt *bp = netdev_priv(dev);
u32 i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < bp->cp_nr_rings; i++) {
sprintf(buf, "[%d]: rx_ucast_packets", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: rx_mcast_packets", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: rx_bcast_packets", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: rx_discards", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: rx_drops", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: rx_ucast_bytes", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: rx_mcast_bytes", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: rx_bcast_bytes", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tx_ucast_packets", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tx_mcast_packets", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tx_bcast_packets", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tx_discards", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tx_drops", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tx_ucast_bytes", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tx_mcast_bytes", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tx_bcast_bytes", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tpa_packets", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tpa_bytes", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tpa_events", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: tpa_aborts", i);
buf += ETH_GSTRING_LEN;
sprintf(buf, "[%d]: rx_l4_csum_errors", i);
buf += ETH_GSTRING_LEN;
}
if (bp->flags & BNXT_FLAG_PORT_STATS) {
for (i = 0; i < BNXT_NUM_PORT_STATS; i++) {
strcpy(buf, bnxt_port_stats_arr[i].string);
buf += ETH_GSTRING_LEN;
}
}
break;
default:
netdev_err(bp->dev, "bnxt_get_strings invalid request %x\n",
stringset);
break;
}
}
static void bnxt_get_ringparam(struct net_device *dev,
struct ethtool_ringparam *ering)
{
struct bnxt *bp = netdev_priv(dev);
ering->rx_max_pending = BNXT_MAX_RX_DESC_CNT;
ering->rx_jumbo_max_pending = BNXT_MAX_RX_JUM_DESC_CNT;
ering->tx_max_pending = BNXT_MAX_TX_DESC_CNT;
ering->rx_pending = bp->rx_ring_size;
ering->rx_jumbo_pending = bp->rx_agg_ring_size;
ering->tx_pending = bp->tx_ring_size;
}
static int bnxt_set_ringparam(struct net_device *dev,
struct ethtool_ringparam *ering)
{
struct bnxt *bp = netdev_priv(dev);
if ((ering->rx_pending > BNXT_MAX_RX_DESC_CNT) ||
(ering->tx_pending > BNXT_MAX_TX_DESC_CNT) ||
(ering->tx_pending <= MAX_SKB_FRAGS))
return -EINVAL;
if (netif_running(dev))
bnxt_close_nic(bp, false, false);
bp->rx_ring_size = ering->rx_pending;
bp->tx_ring_size = ering->tx_pending;
bnxt_set_ring_params(bp);
if (netif_running(dev))
return bnxt_open_nic(bp, false, false);
return 0;
}
static void bnxt_get_channels(struct net_device *dev,
struct ethtool_channels *channel)
{
struct bnxt *bp = netdev_priv(dev);
int max_rx_rings, max_tx_rings, tcs;
bnxt_get_max_rings(bp, &max_rx_rings, &max_tx_rings, true);
channel->max_combined = max_t(int, max_rx_rings, max_tx_rings);
if (bnxt_get_max_rings(bp, &max_rx_rings, &max_tx_rings, false)) {
max_rx_rings = 0;
max_tx_rings = 0;
}
tcs = netdev_get_num_tc(dev);
if (tcs > 1)
max_tx_rings /= tcs;
channel->max_rx = max_rx_rings;
channel->max_tx = max_tx_rings;
channel->max_other = 0;
if (bp->flags & BNXT_FLAG_SHARED_RINGS) {
channel->combined_count = bp->rx_nr_rings;
if (BNXT_CHIP_TYPE_NITRO_A0(bp))
channel->combined_count--;
} else {
if (!BNXT_CHIP_TYPE_NITRO_A0(bp)) {
channel->rx_count = bp->rx_nr_rings;
channel->tx_count = bp->tx_nr_rings_per_tc;
}
}
}
static int bnxt_set_channels(struct net_device *dev,
struct ethtool_channels *channel)
{
struct bnxt *bp = netdev_priv(dev);
int max_rx_rings, max_tx_rings, tcs;
u32 rc = 0;
bool sh = false;
if (channel->other_count)
return -EINVAL;
if (!channel->combined_count &&
(!channel->rx_count || !channel->tx_count))
return -EINVAL;
if (channel->combined_count &&
(channel->rx_count || channel->tx_count))
return -EINVAL;
if (BNXT_CHIP_TYPE_NITRO_A0(bp) && (channel->rx_count ||
channel->tx_count))
return -EINVAL;
if (channel->combined_count)
sh = true;
bnxt_get_max_rings(bp, &max_rx_rings, &max_tx_rings, sh);
tcs = netdev_get_num_tc(dev);
if (tcs > 1)
max_tx_rings /= tcs;
if (sh &&
channel->combined_count > max_t(int, max_rx_rings, max_tx_rings))
return -ENOMEM;
if (!sh && (channel->rx_count > max_rx_rings ||
channel->tx_count > max_tx_rings))
return -ENOMEM;
if (netif_running(dev)) {
if (BNXT_PF(bp)) {
}
rc = bnxt_close_nic(bp, true, false);
if (rc) {
netdev_err(bp->dev, "Set channel failure rc :%x\n",
rc);
return rc;
}
}
if (sh) {
bp->flags |= BNXT_FLAG_SHARED_RINGS;
bp->rx_nr_rings = min_t(int, channel->combined_count,
max_rx_rings);
bp->tx_nr_rings_per_tc = min_t(int, channel->combined_count,
max_tx_rings);
} else {
bp->flags &= ~BNXT_FLAG_SHARED_RINGS;
bp->rx_nr_rings = channel->rx_count;
bp->tx_nr_rings_per_tc = channel->tx_count;
}
bp->tx_nr_rings = bp->tx_nr_rings_per_tc;
if (tcs > 1)
bp->tx_nr_rings = bp->tx_nr_rings_per_tc * tcs;
bp->cp_nr_rings = sh ? max_t(int, bp->tx_nr_rings, bp->rx_nr_rings) :
bp->tx_nr_rings + bp->rx_nr_rings;
bp->num_stat_ctxs = bp->cp_nr_rings;
netdev_update_features(dev);
if (netif_running(dev)) {
rc = bnxt_open_nic(bp, true, false);
if ((!rc) && BNXT_PF(bp)) {
}
}
return rc;
}
static int bnxt_grxclsrlall(struct bnxt *bp, struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
int i, j = 0;
cmd->data = bp->ntp_fltr_count;
for (i = 0; i < BNXT_NTP_FLTR_HASH_SIZE; i++) {
struct hlist_head *head;
struct bnxt_ntuple_filter *fltr;
head = &bp->ntp_fltr_hash_tbl[i];
rcu_read_lock();
hlist_for_each_entry_rcu(fltr, head, hash) {
if (j == cmd->rule_cnt)
break;
rule_locs[j++] = fltr->sw_id;
}
rcu_read_unlock();
if (j == cmd->rule_cnt)
break;
}
cmd->rule_cnt = j;
return 0;
}
static int bnxt_grxclsrule(struct bnxt *bp, struct ethtool_rxnfc *cmd)
{
struct ethtool_rx_flow_spec *fs =
(struct ethtool_rx_flow_spec *)&cmd->fs;
struct bnxt_ntuple_filter *fltr;
struct flow_keys *fkeys;
int i, rc = -EINVAL;
if (fs->location < 0 || fs->location >= BNXT_NTP_FLTR_MAX_FLTR)
return rc;
for (i = 0; i < BNXT_NTP_FLTR_HASH_SIZE; i++) {
struct hlist_head *head;
head = &bp->ntp_fltr_hash_tbl[i];
rcu_read_lock();
hlist_for_each_entry_rcu(fltr, head, hash) {
if (fltr->sw_id == fs->location)
goto fltr_found;
}
rcu_read_unlock();
}
return rc;
fltr_found:
fkeys = &fltr->fkeys;
if (fkeys->basic.ip_proto == IPPROTO_TCP)
fs->flow_type = TCP_V4_FLOW;
else if (fkeys->basic.ip_proto == IPPROTO_UDP)
fs->flow_type = UDP_V4_FLOW;
else
goto fltr_err;
fs->h_u.tcp_ip4_spec.ip4src = fkeys->addrs.v4addrs.src;
fs->m_u.tcp_ip4_spec.ip4src = cpu_to_be32(~0);
fs->h_u.tcp_ip4_spec.ip4dst = fkeys->addrs.v4addrs.dst;
fs->m_u.tcp_ip4_spec.ip4dst = cpu_to_be32(~0);
fs->h_u.tcp_ip4_spec.psrc = fkeys->ports.src;
fs->m_u.tcp_ip4_spec.psrc = cpu_to_be16(~0);
fs->h_u.tcp_ip4_spec.pdst = fkeys->ports.dst;
fs->m_u.tcp_ip4_spec.pdst = cpu_to_be16(~0);
fs->ring_cookie = fltr->rxq;
rc = 0;
fltr_err:
rcu_read_unlock();
return rc;
}
static int bnxt_get_rxnfc(struct net_device *dev, struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
struct bnxt *bp = netdev_priv(dev);
int rc = 0;
switch (cmd->cmd) {
case ETHTOOL_GRXRINGS:
cmd->data = bp->rx_nr_rings;
break;
case ETHTOOL_GRXCLSRLCNT:
cmd->rule_cnt = bp->ntp_fltr_count;
cmd->data = BNXT_NTP_FLTR_MAX_FLTR;
break;
case ETHTOOL_GRXCLSRLALL:
rc = bnxt_grxclsrlall(bp, cmd, (u32 *)rule_locs);
break;
case ETHTOOL_GRXCLSRULE:
rc = bnxt_grxclsrule(bp, cmd);
break;
default:
rc = -EOPNOTSUPP;
break;
}
return rc;
}
static u32 bnxt_get_rxfh_indir_size(struct net_device *dev)
{
return HW_HASH_INDEX_SIZE;
}
static u32 bnxt_get_rxfh_key_size(struct net_device *dev)
{
return HW_HASH_KEY_SIZE;
}
static int bnxt_get_rxfh(struct net_device *dev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct bnxt *bp = netdev_priv(dev);
struct bnxt_vnic_info *vnic = &bp->vnic_info[0];
int i = 0;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
if (indir)
for (i = 0; i < HW_HASH_INDEX_SIZE; i++)
indir[i] = le16_to_cpu(vnic->rss_table[i]);
if (key)
memcpy(key, vnic->rss_hash_key, HW_HASH_KEY_SIZE);
return 0;
}
static void bnxt_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct bnxt *bp = netdev_priv(dev);
char *pkglog;
char *pkgver = NULL;
pkglog = kmalloc(BNX_PKG_LOG_MAX_LENGTH, GFP_KERNEL);
if (pkglog)
pkgver = bnxt_get_pkgver(dev, pkglog, BNX_PKG_LOG_MAX_LENGTH);
strlcpy(info->driver, DRV_MODULE_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_MODULE_VERSION, sizeof(info->version));
if (pkgver && *pkgver != 0 && isdigit(*pkgver))
snprintf(info->fw_version, sizeof(info->fw_version) - 1,
"%s pkg %s", bp->fw_ver_str, pkgver);
else
strlcpy(info->fw_version, bp->fw_ver_str,
sizeof(info->fw_version));
strlcpy(info->bus_info, pci_name(bp->pdev), sizeof(info->bus_info));
info->n_stats = BNXT_NUM_STATS * bp->cp_nr_rings;
info->testinfo_len = BNXT_NUM_TESTS(bp);
info->eedump_len = 0;
info->regdump_len = 0;
kfree(pkglog);
}
u32 _bnxt_fw_to_ethtool_adv_spds(u16 fw_speeds, u8 fw_pause)
{
u32 speed_mask = 0;
if (fw_speeds & BNXT_LINK_SPEED_MSK_100MB)
speed_mask |= ADVERTISED_100baseT_Full;
if (fw_speeds & BNXT_LINK_SPEED_MSK_1GB)
speed_mask |= ADVERTISED_1000baseT_Full;
if (fw_speeds & BNXT_LINK_SPEED_MSK_2_5GB)
speed_mask |= ADVERTISED_2500baseX_Full;
if (fw_speeds & BNXT_LINK_SPEED_MSK_10GB)
speed_mask |= ADVERTISED_10000baseT_Full;
if (fw_speeds & BNXT_LINK_SPEED_MSK_40GB)
speed_mask |= ADVERTISED_40000baseCR4_Full;
if ((fw_pause & BNXT_LINK_PAUSE_BOTH) == BNXT_LINK_PAUSE_BOTH)
speed_mask |= ADVERTISED_Pause;
else if (fw_pause & BNXT_LINK_PAUSE_TX)
speed_mask |= ADVERTISED_Asym_Pause;
else if (fw_pause & BNXT_LINK_PAUSE_RX)
speed_mask |= ADVERTISED_Pause | ADVERTISED_Asym_Pause;
return speed_mask;
}
static void bnxt_fw_to_ethtool_advertised_spds(struct bnxt_link_info *link_info,
struct ethtool_link_ksettings *lk_ksettings)
{
u16 fw_speeds = link_info->auto_link_speeds;
u8 fw_pause = 0;
if (link_info->autoneg & BNXT_AUTONEG_FLOW_CTRL)
fw_pause = link_info->auto_pause_setting;
BNXT_FW_TO_ETHTOOL_SPDS(fw_speeds, fw_pause, lk_ksettings, advertising);
}
static void bnxt_fw_to_ethtool_lp_adv(struct bnxt_link_info *link_info,
struct ethtool_link_ksettings *lk_ksettings)
{
u16 fw_speeds = link_info->lp_auto_link_speeds;
u8 fw_pause = 0;
if (link_info->autoneg & BNXT_AUTONEG_FLOW_CTRL)
fw_pause = link_info->lp_pause;
BNXT_FW_TO_ETHTOOL_SPDS(fw_speeds, fw_pause, lk_ksettings,
lp_advertising);
}
static void bnxt_fw_to_ethtool_support_spds(struct bnxt_link_info *link_info,
struct ethtool_link_ksettings *lk_ksettings)
{
u16 fw_speeds = link_info->support_speeds;
BNXT_FW_TO_ETHTOOL_SPDS(fw_speeds, 0, lk_ksettings, supported);
ethtool_link_ksettings_add_link_mode(lk_ksettings, supported, Pause);
ethtool_link_ksettings_add_link_mode(lk_ksettings, supported,
Asym_Pause);
if (link_info->support_auto_speeds)
ethtool_link_ksettings_add_link_mode(lk_ksettings, supported,
Autoneg);
}
u32 bnxt_fw_to_ethtool_speed(u16 fw_link_speed)
{
switch (fw_link_speed) {
case BNXT_LINK_SPEED_100MB:
return SPEED_100;
case BNXT_LINK_SPEED_1GB:
return SPEED_1000;
case BNXT_LINK_SPEED_2_5GB:
return SPEED_2500;
case BNXT_LINK_SPEED_10GB:
return SPEED_10000;
case BNXT_LINK_SPEED_20GB:
return SPEED_20000;
case BNXT_LINK_SPEED_25GB:
return SPEED_25000;
case BNXT_LINK_SPEED_40GB:
return SPEED_40000;
case BNXT_LINK_SPEED_50GB:
return SPEED_50000;
default:
return SPEED_UNKNOWN;
}
}
static int bnxt_get_link_ksettings(struct net_device *dev,
struct ethtool_link_ksettings *lk_ksettings)
{
struct bnxt *bp = netdev_priv(dev);
struct bnxt_link_info *link_info = &bp->link_info;
struct ethtool_link_settings *base = &lk_ksettings->base;
u32 ethtool_speed;
ethtool_link_ksettings_zero_link_mode(lk_ksettings, supported);
bnxt_fw_to_ethtool_support_spds(link_info, lk_ksettings);
ethtool_link_ksettings_zero_link_mode(lk_ksettings, advertising);
if (link_info->autoneg) {
bnxt_fw_to_ethtool_advertised_spds(link_info, lk_ksettings);
ethtool_link_ksettings_add_link_mode(lk_ksettings,
advertising, Autoneg);
base->autoneg = AUTONEG_ENABLE;
if (link_info->phy_link_status == BNXT_LINK_LINK)
bnxt_fw_to_ethtool_lp_adv(link_info, lk_ksettings);
ethtool_speed = bnxt_fw_to_ethtool_speed(link_info->link_speed);
if (!netif_carrier_ok(dev))
base->duplex = DUPLEX_UNKNOWN;
else if (link_info->duplex & BNXT_LINK_DUPLEX_FULL)
base->duplex = DUPLEX_FULL;
else
base->duplex = DUPLEX_HALF;
} else {
base->autoneg = AUTONEG_DISABLE;
ethtool_speed =
bnxt_fw_to_ethtool_speed(link_info->req_link_speed);
base->duplex = DUPLEX_HALF;
if (link_info->req_duplex == BNXT_LINK_DUPLEX_FULL)
base->duplex = DUPLEX_FULL;
}
base->speed = ethtool_speed;
base->port = PORT_NONE;
if (link_info->media_type == PORT_PHY_QCFG_RESP_MEDIA_TYPE_TP) {
base->port = PORT_TP;
ethtool_link_ksettings_add_link_mode(lk_ksettings, supported,
TP);
ethtool_link_ksettings_add_link_mode(lk_ksettings, advertising,
TP);
} else {
ethtool_link_ksettings_add_link_mode(lk_ksettings, supported,
FIBRE);
ethtool_link_ksettings_add_link_mode(lk_ksettings, advertising,
FIBRE);
if (link_info->media_type == PORT_PHY_QCFG_RESP_MEDIA_TYPE_DAC)
base->port = PORT_DA;
else if (link_info->media_type ==
PORT_PHY_QCFG_RESP_MEDIA_TYPE_FIBRE)
base->port = PORT_FIBRE;
}
base->phy_address = link_info->phy_addr;
return 0;
}
static u32 bnxt_get_fw_speed(struct net_device *dev, u16 ethtool_speed)
{
struct bnxt *bp = netdev_priv(dev);
struct bnxt_link_info *link_info = &bp->link_info;
u16 support_spds = link_info->support_speeds;
u32 fw_speed = 0;
switch (ethtool_speed) {
case SPEED_100:
if (support_spds & BNXT_LINK_SPEED_MSK_100MB)
fw_speed = PORT_PHY_CFG_REQ_AUTO_LINK_SPEED_100MB;
break;
case SPEED_1000:
if (support_spds & BNXT_LINK_SPEED_MSK_1GB)
fw_speed = PORT_PHY_CFG_REQ_AUTO_LINK_SPEED_1GB;
break;
case SPEED_2500:
if (support_spds & BNXT_LINK_SPEED_MSK_2_5GB)
fw_speed = PORT_PHY_CFG_REQ_AUTO_LINK_SPEED_2_5GB;
break;
case SPEED_10000:
if (support_spds & BNXT_LINK_SPEED_MSK_10GB)
fw_speed = PORT_PHY_CFG_REQ_AUTO_LINK_SPEED_10GB;
break;
case SPEED_20000:
if (support_spds & BNXT_LINK_SPEED_MSK_20GB)
fw_speed = PORT_PHY_CFG_REQ_AUTO_LINK_SPEED_20GB;
break;
case SPEED_25000:
if (support_spds & BNXT_LINK_SPEED_MSK_25GB)
fw_speed = PORT_PHY_CFG_REQ_AUTO_LINK_SPEED_25GB;
break;
case SPEED_40000:
if (support_spds & BNXT_LINK_SPEED_MSK_40GB)
fw_speed = PORT_PHY_CFG_REQ_AUTO_LINK_SPEED_40GB;
break;
case SPEED_50000:
if (support_spds & BNXT_LINK_SPEED_MSK_50GB)
fw_speed = PORT_PHY_CFG_REQ_AUTO_LINK_SPEED_50GB;
break;
default:
netdev_err(dev, "unsupported speed!\n");
break;
}
return fw_speed;
}
u16 bnxt_get_fw_auto_link_speeds(u32 advertising)
{
u16 fw_speed_mask = 0;
if (advertising & (ADVERTISED_100baseT_Full |
ADVERTISED_100baseT_Half)) {
fw_speed_mask |= BNXT_LINK_SPEED_MSK_100MB;
}
if (advertising & (ADVERTISED_1000baseT_Full |
ADVERTISED_1000baseT_Half)) {
fw_speed_mask |= BNXT_LINK_SPEED_MSK_1GB;
}
if (advertising & ADVERTISED_10000baseT_Full)
fw_speed_mask |= BNXT_LINK_SPEED_MSK_10GB;
if (advertising & ADVERTISED_40000baseCR4_Full)
fw_speed_mask |= BNXT_LINK_SPEED_MSK_40GB;
return fw_speed_mask;
}
static int bnxt_set_link_ksettings(struct net_device *dev,
const struct ethtool_link_ksettings *lk_ksettings)
{
struct bnxt *bp = netdev_priv(dev);
struct bnxt_link_info *link_info = &bp->link_info;
const struct ethtool_link_settings *base = &lk_ksettings->base;
u32 speed, fw_advertising = 0;
bool set_pause = false;
int rc = 0;
if (!BNXT_SINGLE_PF(bp))
return -EOPNOTSUPP;
if (base->autoneg == AUTONEG_ENABLE) {
BNXT_ETHTOOL_TO_FW_SPDS(fw_advertising, lk_ksettings,
advertising);
link_info->autoneg |= BNXT_AUTONEG_SPEED;
if (!fw_advertising)
link_info->advertising = link_info->support_auto_speeds;
else
link_info->advertising = fw_advertising;
set_pause = true;
} else {
u16 fw_speed;
u8 phy_type = link_info->phy_type;
if (phy_type == PORT_PHY_QCFG_RESP_PHY_TYPE_BASET ||
phy_type == PORT_PHY_QCFG_RESP_PHY_TYPE_BASETE ||
link_info->media_type == PORT_PHY_QCFG_RESP_MEDIA_TYPE_TP) {
netdev_err(dev, "10GBase-T devices must autoneg\n");
rc = -EINVAL;
goto set_setting_exit;
}
if (base->duplex == DUPLEX_HALF) {
netdev_err(dev, "HALF DUPLEX is not supported!\n");
rc = -EINVAL;
goto set_setting_exit;
}
speed = base->speed;
fw_speed = bnxt_get_fw_speed(dev, speed);
if (!fw_speed) {
rc = -EINVAL;
goto set_setting_exit;
}
link_info->req_link_speed = fw_speed;
link_info->req_duplex = BNXT_LINK_DUPLEX_FULL;
link_info->autoneg = 0;
link_info->advertising = 0;
}
if (netif_running(dev))
rc = bnxt_hwrm_set_link_setting(bp, set_pause, false);
set_setting_exit:
return rc;
}
static void bnxt_get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct bnxt *bp = netdev_priv(dev);
struct bnxt_link_info *link_info = &bp->link_info;
if (BNXT_VF(bp))
return;
epause->autoneg = !!(link_info->autoneg & BNXT_AUTONEG_FLOW_CTRL);
epause->rx_pause = !!(link_info->req_flow_ctrl & BNXT_LINK_PAUSE_RX);
epause->tx_pause = !!(link_info->req_flow_ctrl & BNXT_LINK_PAUSE_TX);
}
static int bnxt_set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
int rc = 0;
struct bnxt *bp = netdev_priv(dev);
struct bnxt_link_info *link_info = &bp->link_info;
if (!BNXT_SINGLE_PF(bp))
return -EOPNOTSUPP;
if (epause->autoneg) {
if (!(link_info->autoneg & BNXT_AUTONEG_SPEED))
return -EINVAL;
link_info->autoneg |= BNXT_AUTONEG_FLOW_CTRL;
if (bp->hwrm_spec_code >= 0x10201)
link_info->req_flow_ctrl =
PORT_PHY_CFG_REQ_AUTO_PAUSE_AUTONEG_PAUSE;
} else {
if (link_info->autoneg & BNXT_AUTONEG_FLOW_CTRL)
link_info->force_link_chng = true;
link_info->autoneg &= ~BNXT_AUTONEG_FLOW_CTRL;
link_info->req_flow_ctrl = 0;
}
if (epause->rx_pause)
link_info->req_flow_ctrl |= BNXT_LINK_PAUSE_RX;
if (epause->tx_pause)
link_info->req_flow_ctrl |= BNXT_LINK_PAUSE_TX;
if (netif_running(dev))
rc = bnxt_hwrm_set_pause(bp);
return rc;
}
static u32 bnxt_get_link(struct net_device *dev)
{
struct bnxt *bp = netdev_priv(dev);
return bp->link_info.link_up;
}
static int bnxt_flash_nvram(struct net_device *dev,
u16 dir_type,
u16 dir_ordinal,
u16 dir_ext,
u16 dir_attr,
const u8 *data,
size_t data_len)
{
struct bnxt *bp = netdev_priv(dev);
int rc;
struct hwrm_nvm_write_input req = {0};
dma_addr_t dma_handle;
u8 *kmem;
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_NVM_WRITE, -1, -1);
req.dir_type = cpu_to_le16(dir_type);
req.dir_ordinal = cpu_to_le16(dir_ordinal);
req.dir_ext = cpu_to_le16(dir_ext);
req.dir_attr = cpu_to_le16(dir_attr);
req.dir_data_length = cpu_to_le32(data_len);
kmem = dma_alloc_coherent(&bp->pdev->dev, data_len, &dma_handle,
GFP_KERNEL);
if (!kmem) {
netdev_err(dev, "dma_alloc_coherent failure, length = %u\n",
(unsigned)data_len);
return -ENOMEM;
}
memcpy(kmem, data, data_len);
req.host_src_addr = cpu_to_le64(dma_handle);
rc = hwrm_send_message(bp, &req, sizeof(req), FLASH_NVRAM_TIMEOUT);
dma_free_coherent(&bp->pdev->dev, data_len, kmem, dma_handle);
return rc;
}
static int bnxt_firmware_reset(struct net_device *dev,
u16 dir_type)
{
struct bnxt *bp = netdev_priv(dev);
struct hwrm_fw_reset_input req = {0};
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_FW_RESET, -1, -1);
switch (dir_type) {
case BNX_DIR_TYPE_CHIMP_PATCH:
case BNX_DIR_TYPE_BOOTCODE:
case BNX_DIR_TYPE_BOOTCODE_2:
req.embedded_proc_type = FW_RESET_REQ_EMBEDDED_PROC_TYPE_BOOT;
req.selfrst_status = FW_RESET_REQ_SELFRST_STATUS_SELFRSTPCIERST;
break;
case BNX_DIR_TYPE_APE_FW:
case BNX_DIR_TYPE_APE_PATCH:
req.embedded_proc_type = FW_RESET_REQ_EMBEDDED_PROC_TYPE_MGMT;
req.selfrst_status = FW_RESET_REQ_SELFRST_STATUS_SELFRSTPCIERST;
break;
case BNX_DIR_TYPE_KONG_FW:
case BNX_DIR_TYPE_KONG_PATCH:
req.embedded_proc_type =
FW_RESET_REQ_EMBEDDED_PROC_TYPE_NETCTRL;
break;
case BNX_DIR_TYPE_BONO_FW:
case BNX_DIR_TYPE_BONO_PATCH:
req.embedded_proc_type = FW_RESET_REQ_EMBEDDED_PROC_TYPE_ROCE;
break;
default:
return -EINVAL;
}
return hwrm_send_message(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
}
static int bnxt_flash_firmware(struct net_device *dev,
u16 dir_type,
const u8 *fw_data,
size_t fw_size)
{
int rc = 0;
u16 code_type;
u32 stored_crc;
u32 calculated_crc;
struct bnxt_fw_header *header = (struct bnxt_fw_header *)fw_data;
switch (dir_type) {
case BNX_DIR_TYPE_BOOTCODE:
case BNX_DIR_TYPE_BOOTCODE_2:
code_type = CODE_BOOT;
break;
case BNX_DIR_TYPE_CHIMP_PATCH:
code_type = CODE_CHIMP_PATCH;
break;
case BNX_DIR_TYPE_APE_FW:
code_type = CODE_MCTP_PASSTHRU;
break;
case BNX_DIR_TYPE_APE_PATCH:
code_type = CODE_APE_PATCH;
break;
case BNX_DIR_TYPE_KONG_FW:
code_type = CODE_KONG_FW;
break;
case BNX_DIR_TYPE_KONG_PATCH:
code_type = CODE_KONG_PATCH;
break;
case BNX_DIR_TYPE_BONO_FW:
code_type = CODE_BONO_FW;
break;
case BNX_DIR_TYPE_BONO_PATCH:
code_type = CODE_BONO_PATCH;
break;
default:
netdev_err(dev, "Unsupported directory entry type: %u\n",
dir_type);
return -EINVAL;
}
if (fw_size < sizeof(struct bnxt_fw_header)) {
netdev_err(dev, "Invalid firmware file size: %u\n",
(unsigned int)fw_size);
return -EINVAL;
}
if (header->signature != cpu_to_le32(BNXT_FIRMWARE_BIN_SIGNATURE)) {
netdev_err(dev, "Invalid firmware signature: %08X\n",
le32_to_cpu(header->signature));
return -EINVAL;
}
if (header->code_type != code_type) {
netdev_err(dev, "Expected firmware type: %d, read: %d\n",
code_type, header->code_type);
return -EINVAL;
}
if (header->device != DEVICE_CUMULUS_FAMILY) {
netdev_err(dev, "Expected firmware device family %d, read: %d\n",
DEVICE_CUMULUS_FAMILY, header->device);
return -EINVAL;
}
stored_crc = le32_to_cpu(*(__le32 *)(fw_data + fw_size -
sizeof(stored_crc)));
calculated_crc = ~crc32(~0, fw_data, fw_size - sizeof(stored_crc));
if (calculated_crc != stored_crc) {
netdev_err(dev, "Firmware file CRC32 checksum (%08lX) does not match calculated checksum (%08lX)\n",
(unsigned long)stored_crc,
(unsigned long)calculated_crc);
return -EINVAL;
}
rc = bnxt_flash_nvram(dev, dir_type, BNX_DIR_ORDINAL_FIRST,
0, 0, fw_data, fw_size);
if (rc == 0)
rc = bnxt_firmware_reset(dev, dir_type);
return rc;
}
static int bnxt_flash_microcode(struct net_device *dev,
u16 dir_type,
const u8 *fw_data,
size_t fw_size)
{
struct bnxt_ucode_trailer *trailer;
u32 calculated_crc;
u32 stored_crc;
int rc = 0;
if (fw_size < sizeof(struct bnxt_ucode_trailer)) {
netdev_err(dev, "Invalid microcode file size: %u\n",
(unsigned int)fw_size);
return -EINVAL;
}
trailer = (struct bnxt_ucode_trailer *)(fw_data + (fw_size -
sizeof(*trailer)));
if (trailer->sig != cpu_to_le32(BNXT_UCODE_TRAILER_SIGNATURE)) {
netdev_err(dev, "Invalid microcode trailer signature: %08X\n",
le32_to_cpu(trailer->sig));
return -EINVAL;
}
if (le16_to_cpu(trailer->dir_type) != dir_type) {
netdev_err(dev, "Expected microcode type: %d, read: %d\n",
dir_type, le16_to_cpu(trailer->dir_type));
return -EINVAL;
}
if (le16_to_cpu(trailer->trailer_length) <
sizeof(struct bnxt_ucode_trailer)) {
netdev_err(dev, "Invalid microcode trailer length: %d\n",
le16_to_cpu(trailer->trailer_length));
return -EINVAL;
}
stored_crc = le32_to_cpu(*(__le32 *)(fw_data + fw_size -
sizeof(stored_crc)));
calculated_crc = ~crc32(~0, fw_data, fw_size - sizeof(stored_crc));
if (calculated_crc != stored_crc) {
netdev_err(dev,
"CRC32 (%08lX) does not match calculated: %08lX\n",
(unsigned long)stored_crc,
(unsigned long)calculated_crc);
return -EINVAL;
}
rc = bnxt_flash_nvram(dev, dir_type, BNX_DIR_ORDINAL_FIRST,
0, 0, fw_data, fw_size);
return rc;
}
static bool bnxt_dir_type_is_ape_bin_format(u16 dir_type)
{
switch (dir_type) {
case BNX_DIR_TYPE_CHIMP_PATCH:
case BNX_DIR_TYPE_BOOTCODE:
case BNX_DIR_TYPE_BOOTCODE_2:
case BNX_DIR_TYPE_APE_FW:
case BNX_DIR_TYPE_APE_PATCH:
case BNX_DIR_TYPE_KONG_FW:
case BNX_DIR_TYPE_KONG_PATCH:
case BNX_DIR_TYPE_BONO_FW:
case BNX_DIR_TYPE_BONO_PATCH:
return true;
}
return false;
}
static bool bnxt_dir_type_is_other_exec_format(u16 dir_type)
{
switch (dir_type) {
case BNX_DIR_TYPE_AVS:
case BNX_DIR_TYPE_EXP_ROM_MBA:
case BNX_DIR_TYPE_PCIE:
case BNX_DIR_TYPE_TSCF_UCODE:
case BNX_DIR_TYPE_EXT_PHY:
case BNX_DIR_TYPE_CCM:
case BNX_DIR_TYPE_ISCSI_BOOT:
case BNX_DIR_TYPE_ISCSI_BOOT_IPV6:
case BNX_DIR_TYPE_ISCSI_BOOT_IPV4N6:
return true;
}
return false;
}
static bool bnxt_dir_type_is_executable(u16 dir_type)
{
return bnxt_dir_type_is_ape_bin_format(dir_type) ||
bnxt_dir_type_is_other_exec_format(dir_type);
}
static int bnxt_flash_firmware_from_file(struct net_device *dev,
u16 dir_type,
const char *filename)
{
const struct firmware *fw;
int rc;
rc = request_firmware(&fw, filename, &dev->dev);
if (rc != 0) {
netdev_err(dev, "Error %d requesting firmware file: %s\n",
rc, filename);
return rc;
}
if (bnxt_dir_type_is_ape_bin_format(dir_type) == true)
rc = bnxt_flash_firmware(dev, dir_type, fw->data, fw->size);
else if (bnxt_dir_type_is_other_exec_format(dir_type) == true)
rc = bnxt_flash_microcode(dev, dir_type, fw->data, fw->size);
else
rc = bnxt_flash_nvram(dev, dir_type, BNX_DIR_ORDINAL_FIRST,
0, 0, fw->data, fw->size);
release_firmware(fw);
return rc;
}
static int bnxt_flash_package_from_file(struct net_device *dev,
char *filename, u32 install_type)
{
struct bnxt *bp = netdev_priv(dev);
struct hwrm_nvm_install_update_output *resp = bp->hwrm_cmd_resp_addr;
struct hwrm_nvm_install_update_input install = {0};
const struct firmware *fw;
u32 item_len;
u16 index;
int rc;
bnxt_hwrm_fw_set_time(bp);
if (bnxt_find_nvram_item(dev, BNX_DIR_TYPE_UPDATE,
BNX_DIR_ORDINAL_FIRST, BNX_DIR_EXT_NONE,
&index, &item_len, NULL) != 0) {
netdev_err(dev, "PKG update area not created in nvram\n");
return -ENOBUFS;
}
rc = request_firmware(&fw, filename, &dev->dev);
if (rc != 0) {
netdev_err(dev, "PKG error %d requesting file: %s\n",
rc, filename);
return rc;
}
if (fw->size > item_len) {
netdev_err(dev, "PKG insufficient update area in nvram: %lu",
(unsigned long)fw->size);
rc = -EFBIG;
} else {
dma_addr_t dma_handle;
u8 *kmem;
struct hwrm_nvm_modify_input modify = {0};
bnxt_hwrm_cmd_hdr_init(bp, &modify, HWRM_NVM_MODIFY, -1, -1);
modify.dir_idx = cpu_to_le16(index);
modify.len = cpu_to_le32(fw->size);
kmem = dma_alloc_coherent(&bp->pdev->dev, fw->size,
&dma_handle, GFP_KERNEL);
if (!kmem) {
netdev_err(dev,
"dma_alloc_coherent failure, length = %u\n",
(unsigned int)fw->size);
rc = -ENOMEM;
} else {
memcpy(kmem, fw->data, fw->size);
modify.host_src_addr = cpu_to_le64(dma_handle);
rc = hwrm_send_message(bp, &modify, sizeof(modify),
FLASH_PACKAGE_TIMEOUT);
dma_free_coherent(&bp->pdev->dev, fw->size, kmem,
dma_handle);
}
}
release_firmware(fw);
if (rc)
return rc;
if ((install_type & 0xffff) == 0)
install_type >>= 16;
bnxt_hwrm_cmd_hdr_init(bp, &install, HWRM_NVM_INSTALL_UPDATE, -1, -1);
install.install_type = cpu_to_le32(install_type);
rc = hwrm_send_message(bp, &install, sizeof(install),
INSTALL_PACKAGE_TIMEOUT);
if (rc)
return -EOPNOTSUPP;
if (resp->result) {
netdev_err(dev, "PKG install error = %d, problem_item = %d\n",
(s8)resp->result, (int)resp->problem_item);
return -ENOPKG;
}
return 0;
}
static int bnxt_flash_device(struct net_device *dev,
struct ethtool_flash *flash)
{
if (!BNXT_PF((struct bnxt *)netdev_priv(dev))) {
netdev_err(dev, "flashdev not supported from a virtual function\n");
return -EINVAL;
}
if (flash->region == ETHTOOL_FLASH_ALL_REGIONS ||
flash->region > 0xffff)
return bnxt_flash_package_from_file(dev, flash->data,
flash->region);
return bnxt_flash_firmware_from_file(dev, flash->region, flash->data);
}
static int nvm_get_dir_info(struct net_device *dev, u32 *entries, u32 *length)
{
struct bnxt *bp = netdev_priv(dev);
int rc;
struct hwrm_nvm_get_dir_info_input req = {0};
struct hwrm_nvm_get_dir_info_output *output = bp->hwrm_cmd_resp_addr;
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_NVM_GET_DIR_INFO, -1, -1);
mutex_lock(&bp->hwrm_cmd_lock);
rc = _hwrm_send_message(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
if (!rc) {
*entries = le32_to_cpu(output->entries);
*length = le32_to_cpu(output->entry_length);
}
mutex_unlock(&bp->hwrm_cmd_lock);
return rc;
}
static int bnxt_get_eeprom_len(struct net_device *dev)
{
return -1;
}
static int bnxt_get_nvram_directory(struct net_device *dev, u32 len, u8 *data)
{
struct bnxt *bp = netdev_priv(dev);
int rc;
u32 dir_entries;
u32 entry_length;
u8 *buf;
size_t buflen;
dma_addr_t dma_handle;
struct hwrm_nvm_get_dir_entries_input req = {0};
rc = nvm_get_dir_info(dev, &dir_entries, &entry_length);
if (rc != 0)
return rc;
if (len < 2)
return -EINVAL;
*data++ = dir_entries;
*data++ = entry_length;
len -= 2;
memset(data, 0xff, len);
buflen = dir_entries * entry_length;
buf = dma_alloc_coherent(&bp->pdev->dev, buflen, &dma_handle,
GFP_KERNEL);
if (!buf) {
netdev_err(dev, "dma_alloc_coherent failure, length = %u\n",
(unsigned)buflen);
return -ENOMEM;
}
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_NVM_GET_DIR_ENTRIES, -1, -1);
req.host_dest_addr = cpu_to_le64(dma_handle);
rc = hwrm_send_message(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
if (rc == 0)
memcpy(data, buf, len > buflen ? buflen : len);
dma_free_coherent(&bp->pdev->dev, buflen, buf, dma_handle);
return rc;
}
static int bnxt_get_nvram_item(struct net_device *dev, u32 index, u32 offset,
u32 length, u8 *data)
{
struct bnxt *bp = netdev_priv(dev);
int rc;
u8 *buf;
dma_addr_t dma_handle;
struct hwrm_nvm_read_input req = {0};
buf = dma_alloc_coherent(&bp->pdev->dev, length, &dma_handle,
GFP_KERNEL);
if (!buf) {
netdev_err(dev, "dma_alloc_coherent failure, length = %u\n",
(unsigned)length);
return -ENOMEM;
}
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_NVM_READ, -1, -1);
req.host_dest_addr = cpu_to_le64(dma_handle);
req.dir_idx = cpu_to_le16(index);
req.offset = cpu_to_le32(offset);
req.len = cpu_to_le32(length);
rc = hwrm_send_message(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
if (rc == 0)
memcpy(data, buf, length);
dma_free_coherent(&bp->pdev->dev, length, buf, dma_handle);
return rc;
}
static int bnxt_find_nvram_item(struct net_device *dev, u16 type, u16 ordinal,
u16 ext, u16 *index, u32 *item_length,
u32 *data_length)
{
struct bnxt *bp = netdev_priv(dev);
int rc;
struct hwrm_nvm_find_dir_entry_input req = {0};
struct hwrm_nvm_find_dir_entry_output *output = bp->hwrm_cmd_resp_addr;
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_NVM_FIND_DIR_ENTRY, -1, -1);
req.enables = 0;
req.dir_idx = 0;
req.dir_type = cpu_to_le16(type);
req.dir_ordinal = cpu_to_le16(ordinal);
req.dir_ext = cpu_to_le16(ext);
req.opt_ordinal = NVM_FIND_DIR_ENTRY_REQ_OPT_ORDINAL_EQ;
rc = hwrm_send_message_silent(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
if (rc == 0) {
if (index)
*index = le16_to_cpu(output->dir_idx);
if (item_length)
*item_length = le32_to_cpu(output->dir_item_length);
if (data_length)
*data_length = le32_to_cpu(output->dir_data_length);
}
return rc;
}
static char *bnxt_parse_pkglog(int desired_field, u8 *data, size_t datalen)
{
char *retval = NULL;
char *p;
char *value;
int field = 0;
if (datalen < 1)
return NULL;
data[datalen - 1] = 0;
for (p = data; *p != 0; p++) {
field = 0;
retval = NULL;
while (*p != 0 && *p != '\n') {
value = p;
while (*p != 0 && *p != '\t' && *p != '\n')
p++;
if (field == desired_field)
retval = value;
if (*p != '\t')
break;
*p = 0;
field++;
p++;
}
if (*p == 0)
break;
*p = 0;
}
return retval;
}
static char *bnxt_get_pkgver(struct net_device *dev, char *buf, size_t buflen)
{
u16 index = 0;
u32 datalen;
if (bnxt_find_nvram_item(dev, BNX_DIR_TYPE_PKG_LOG,
BNX_DIR_ORDINAL_FIRST, BNX_DIR_EXT_NONE,
&index, NULL, &datalen) != 0)
return NULL;
memset(buf, 0, buflen);
if (bnxt_get_nvram_item(dev, index, 0, datalen, buf) != 0)
return NULL;
return bnxt_parse_pkglog(BNX_PKG_LOG_FIELD_IDX_PKG_VERSION, buf,
datalen);
}
static int bnxt_get_eeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom,
u8 *data)
{
u32 index;
u32 offset;
if (eeprom->offset == 0)
return bnxt_get_nvram_directory(dev, eeprom->len, data);
index = eeprom->offset >> 24;
offset = eeprom->offset & 0xffffff;
if (index == 0) {
netdev_err(dev, "unsupported index value: %d\n", index);
return -EINVAL;
}
return bnxt_get_nvram_item(dev, index - 1, offset, eeprom->len, data);
}
static int bnxt_erase_nvram_directory(struct net_device *dev, u8 index)
{
struct bnxt *bp = netdev_priv(dev);
struct hwrm_nvm_erase_dir_entry_input req = {0};
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_NVM_ERASE_DIR_ENTRY, -1, -1);
req.dir_idx = cpu_to_le16(index);
return hwrm_send_message(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
}
static int bnxt_set_eeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom,
u8 *data)
{
struct bnxt *bp = netdev_priv(dev);
u8 index, dir_op;
u16 type, ext, ordinal, attr;
if (!BNXT_PF(bp)) {
netdev_err(dev, "NVM write not supported from a virtual function\n");
return -EINVAL;
}
type = eeprom->magic >> 16;
if (type == 0xffff) {
index = eeprom->magic & 0xff;
dir_op = eeprom->magic >> 8;
if (index == 0)
return -EINVAL;
switch (dir_op) {
case 0x0e:
if (eeprom->offset != ~eeprom->magic)
return -EINVAL;
return bnxt_erase_nvram_directory(dev, index - 1);
default:
return -EINVAL;
}
}
if (bnxt_dir_type_is_executable(type) == true)
return -EOPNOTSUPP;
ext = eeprom->magic & 0xffff;
ordinal = eeprom->offset >> 16;
attr = eeprom->offset & 0xffff;
return bnxt_flash_nvram(dev, type, ordinal, ext, attr, data,
eeprom->len);
}
static int bnxt_set_eee(struct net_device *dev, struct ethtool_eee *edata)
{
struct bnxt *bp = netdev_priv(dev);
struct ethtool_eee *eee = &bp->eee;
struct bnxt_link_info *link_info = &bp->link_info;
u32 advertising =
_bnxt_fw_to_ethtool_adv_spds(link_info->advertising, 0);
int rc = 0;
if (!BNXT_SINGLE_PF(bp))
return -EOPNOTSUPP;
if (!(bp->flags & BNXT_FLAG_EEE_CAP))
return -EOPNOTSUPP;
if (!edata->eee_enabled)
goto eee_ok;
if (!(link_info->autoneg & BNXT_AUTONEG_SPEED)) {
netdev_warn(dev, "EEE requires autoneg\n");
return -EINVAL;
}
if (edata->tx_lpi_enabled) {
if (bp->lpi_tmr_hi && (edata->tx_lpi_timer > bp->lpi_tmr_hi ||
edata->tx_lpi_timer < bp->lpi_tmr_lo)) {
netdev_warn(dev, "Valid LPI timer range is %d and %d microsecs\n",
bp->lpi_tmr_lo, bp->lpi_tmr_hi);
return -EINVAL;
} else if (!bp->lpi_tmr_hi) {
edata->tx_lpi_timer = eee->tx_lpi_timer;
}
}
if (!edata->advertised) {
edata->advertised = advertising & eee->supported;
} else if (edata->advertised & ~advertising) {
netdev_warn(dev, "EEE advertised %x must be a subset of autoneg advertised speeds %x\n",
edata->advertised, advertising);
return -EINVAL;
}
eee->advertised = edata->advertised;
eee->tx_lpi_enabled = edata->tx_lpi_enabled;
eee->tx_lpi_timer = edata->tx_lpi_timer;
eee_ok:
eee->eee_enabled = edata->eee_enabled;
if (netif_running(dev))
rc = bnxt_hwrm_set_link_setting(bp, false, true);
return rc;
}
static int bnxt_get_eee(struct net_device *dev, struct ethtool_eee *edata)
{
struct bnxt *bp = netdev_priv(dev);
if (!(bp->flags & BNXT_FLAG_EEE_CAP))
return -EOPNOTSUPP;
*edata = bp->eee;
if (!bp->eee.eee_enabled) {
edata->advertised = 0;
edata->tx_lpi_enabled = 0;
}
if (!bp->eee.eee_active)
edata->lp_advertised = 0;
return 0;
}
static int bnxt_read_sfp_module_eeprom_info(struct bnxt *bp, u16 i2c_addr,
u16 page_number, u16 start_addr,
u16 data_length, u8 *buf)
{
struct hwrm_port_phy_i2c_read_input req = {0};
struct hwrm_port_phy_i2c_read_output *output = bp->hwrm_cmd_resp_addr;
int rc, byte_offset = 0;
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_PORT_PHY_I2C_READ, -1, -1);
req.i2c_slave_addr = i2c_addr;
req.page_number = cpu_to_le16(page_number);
req.port_id = cpu_to_le16(bp->pf.port_id);
do {
u16 xfer_size;
xfer_size = min_t(u16, data_length, BNXT_MAX_PHY_I2C_RESP_SIZE);
data_length -= xfer_size;
req.page_offset = cpu_to_le16(start_addr + byte_offset);
req.data_length = xfer_size;
req.enables = cpu_to_le32(start_addr + byte_offset ?
PORT_PHY_I2C_READ_REQ_ENABLES_PAGE_OFFSET : 0);
mutex_lock(&bp->hwrm_cmd_lock);
rc = _hwrm_send_message(bp, &req, sizeof(req),
HWRM_CMD_TIMEOUT);
if (!rc)
memcpy(buf + byte_offset, output->data, xfer_size);
mutex_unlock(&bp->hwrm_cmd_lock);
byte_offset += xfer_size;
} while (!rc && data_length > 0);
return rc;
}
static int bnxt_get_module_info(struct net_device *dev,
struct ethtool_modinfo *modinfo)
{
struct bnxt *bp = netdev_priv(dev);
struct hwrm_port_phy_i2c_read_input req = {0};
struct hwrm_port_phy_i2c_read_output *output = bp->hwrm_cmd_resp_addr;
int rc;
if (bp->link_info.module_status >
PORT_PHY_QCFG_RESP_MODULE_STATUS_WARNINGMSG)
return -EOPNOTSUPP;
if (bp->hwrm_spec_code < 0x10202)
return -EOPNOTSUPP;
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_PORT_PHY_I2C_READ, -1, -1);
req.i2c_slave_addr = I2C_DEV_ADDR_A0;
req.page_number = 0;
req.page_offset = cpu_to_le16(SFP_EEPROM_SFF_8472_COMP_ADDR);
req.data_length = SFP_EEPROM_SFF_8472_COMP_SIZE;
req.port_id = cpu_to_le16(bp->pf.port_id);
mutex_lock(&bp->hwrm_cmd_lock);
rc = _hwrm_send_message(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
if (!rc) {
u32 module_id = le32_to_cpu(output->data[0]);
switch (module_id) {
case SFF_MODULE_ID_SFP:
modinfo->type = ETH_MODULE_SFF_8472;
modinfo->eeprom_len = ETH_MODULE_SFF_8472_LEN;
break;
case SFF_MODULE_ID_QSFP:
case SFF_MODULE_ID_QSFP_PLUS:
modinfo->type = ETH_MODULE_SFF_8436;
modinfo->eeprom_len = ETH_MODULE_SFF_8436_LEN;
break;
case SFF_MODULE_ID_QSFP28:
modinfo->type = ETH_MODULE_SFF_8636;
modinfo->eeprom_len = ETH_MODULE_SFF_8636_LEN;
break;
default:
rc = -EOPNOTSUPP;
break;
}
}
mutex_unlock(&bp->hwrm_cmd_lock);
return rc;
}
static int bnxt_get_module_eeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom,
u8 *data)
{
struct bnxt *bp = netdev_priv(dev);
u16 start = eeprom->offset, length = eeprom->len;
int rc = 0;
memset(data, 0, eeprom->len);
if (start < ETH_MODULE_SFF_8436_LEN) {
if (start + eeprom->len > ETH_MODULE_SFF_8436_LEN)
length = ETH_MODULE_SFF_8436_LEN - start;
rc = bnxt_read_sfp_module_eeprom_info(bp, I2C_DEV_ADDR_A0, 0,
start, length, data);
if (rc)
return rc;
start += length;
data += length;
length = eeprom->len - length;
}
if (length) {
start -= ETH_MODULE_SFF_8436_LEN;
bnxt_read_sfp_module_eeprom_info(bp, I2C_DEV_ADDR_A2, 1, start,
length, data);
}
return rc;
}
static int bnxt_nway_reset(struct net_device *dev)
{
int rc = 0;
struct bnxt *bp = netdev_priv(dev);
struct bnxt_link_info *link_info = &bp->link_info;
if (!BNXT_SINGLE_PF(bp))
return -EOPNOTSUPP;
if (!(link_info->autoneg & BNXT_AUTONEG_SPEED))
return -EINVAL;
if (netif_running(dev))
rc = bnxt_hwrm_set_link_setting(bp, true, false);
return rc;
}
