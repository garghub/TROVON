static void dpaa2_eth_get_drvinfo(struct net_device *net_dev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->driver, KBUILD_MODNAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, dpaa2_eth_drv_version,
sizeof(drvinfo->version));
strlcpy(drvinfo->fw_version, "N/A", sizeof(drvinfo->fw_version));
strlcpy(drvinfo->bus_info, dev_name(net_dev->dev.parent->parent),
sizeof(drvinfo->bus_info));
}
static int
dpaa2_eth_get_link_ksettings(struct net_device *net_dev,
struct ethtool_link_ksettings *link_settings)
{
struct dpni_link_state state = {0};
int err = 0;
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
err = dpni_get_link_state(priv->mc_io, 0, priv->mc_token, &state);
if (err) {
netdev_err(net_dev, "ERROR %d getting link state", err);
goto out;
}
if (state.options & DPNI_LINK_OPT_AUTONEG)
link_settings->base.autoneg = AUTONEG_ENABLE;
if (!(state.options & DPNI_LINK_OPT_HALF_DUPLEX))
link_settings->base.duplex = DUPLEX_FULL;
link_settings->base.speed = state.rate;
out:
return err;
}
static int
dpaa2_eth_set_link_ksettings(struct net_device *net_dev,
const struct ethtool_link_ksettings *link_settings)
{
struct dpni_link_cfg cfg = {0};
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
int err = 0;
netdev_dbg(net_dev, "Setting link parameters...");
if (netif_running(net_dev)) {
netdev_info(net_dev, "Sorry, interface must be brought down first.\n");
return -EACCES;
}
cfg.rate = link_settings->base.speed;
if (link_settings->base.autoneg == AUTONEG_ENABLE)
cfg.options |= DPNI_LINK_OPT_AUTONEG;
else
cfg.options &= ~DPNI_LINK_OPT_AUTONEG;
if (link_settings->base.duplex == DUPLEX_HALF)
cfg.options |= DPNI_LINK_OPT_HALF_DUPLEX;
else
cfg.options &= ~DPNI_LINK_OPT_HALF_DUPLEX;
err = dpni_set_link_cfg(priv->mc_io, 0, priv->mc_token, &cfg);
if (err)
netdev_dbg(net_dev, "ERROR %d setting link cfg", err);
return err;
}
static void dpaa2_eth_get_strings(struct net_device *netdev, u32 stringset,
u8 *data)
{
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < DPAA2_ETH_NUM_STATS; i++) {
strlcpy(p, dpaa2_ethtool_stats[i], ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < DPAA2_ETH_NUM_EXTRA_STATS; i++) {
strlcpy(p, dpaa2_ethtool_extras[i], ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
break;
}
}
static int dpaa2_eth_get_sset_count(struct net_device *net_dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return DPAA2_ETH_NUM_STATS + DPAA2_ETH_NUM_EXTRA_STATS;
default:
return -EOPNOTSUPP;
}
}
static void dpaa2_eth_get_ethtool_stats(struct net_device *net_dev,
struct ethtool_stats *stats,
u64 *data)
{
int i = 0;
int j, k, err;
int num_cnt;
union dpni_statistics dpni_stats;
u64 cdan = 0;
u64 portal_busy = 0, pull_err = 0;
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
struct dpaa2_eth_drv_stats *extras;
struct dpaa2_eth_ch_stats *ch_stats;
memset(data, 0,
sizeof(u64) * (DPAA2_ETH_NUM_STATS + DPAA2_ETH_NUM_EXTRA_STATS));
for (j = 0; j <= 2; j++) {
err = dpni_get_statistics(priv->mc_io, 0, priv->mc_token,
j, &dpni_stats);
if (err != 0)
netdev_warn(net_dev, "dpni_get_stats(%d) failed", j);
switch (j) {
case 0:
num_cnt = sizeof(dpni_stats.page_0) / sizeof(u64);
break;
case 1:
num_cnt = sizeof(dpni_stats.page_1) / sizeof(u64);
break;
case 2:
num_cnt = sizeof(dpni_stats.page_2) / sizeof(u64);
break;
default:
break;
}
for (k = 0; k < num_cnt; k++)
*(data + i++) = dpni_stats.raw.counter[k];
}
for_each_online_cpu(k) {
extras = per_cpu_ptr(priv->percpu_extras, k);
for (j = 0; j < sizeof(*extras) / sizeof(__u64); j++)
*((__u64 *)data + i + j) += *((__u64 *)extras + j);
}
i += j;
for (j = 0; j < priv->num_channels; j++) {
ch_stats = &priv->channel[j]->stats;
cdan += ch_stats->cdan;
portal_busy += ch_stats->dequeue_portal_busy;
pull_err += ch_stats->pull_err;
}
*(data + i++) = portal_busy;
*(data + i++) = pull_err;
*(data + i++) = cdan;
}
static int dpaa2_eth_get_rxnfc(struct net_device *net_dev,
struct ethtool_rxnfc *rxnfc, u32 *rule_locs)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
switch (rxnfc->cmd) {
case ETHTOOL_GRXFH:
rxnfc->data = priv->rx_hash_fields;
break;
case ETHTOOL_GRXRINGS:
rxnfc->data = dpaa2_eth_queue_count(priv);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
