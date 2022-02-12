static int dpaa_get_link_ksettings(struct net_device *net_dev,
struct ethtool_link_ksettings *cmd)
{
int err;
if (!net_dev->phydev) {
netdev_dbg(net_dev, "phy device not initialized\n");
return 0;
}
err = phy_ethtool_ksettings_get(net_dev->phydev, cmd);
return err;
}
static int dpaa_set_link_ksettings(struct net_device *net_dev,
const struct ethtool_link_ksettings *cmd)
{
int err;
if (!net_dev->phydev) {
netdev_err(net_dev, "phy device not initialized\n");
return -ENODEV;
}
err = phy_ethtool_ksettings_set(net_dev->phydev, cmd);
if (err < 0)
netdev_err(net_dev, "phy_ethtool_ksettings_set() = %d\n", err);
return err;
}
static void dpaa_get_drvinfo(struct net_device *net_dev,
struct ethtool_drvinfo *drvinfo)
{
int len;
strlcpy(drvinfo->driver, KBUILD_MODNAME,
sizeof(drvinfo->driver));
len = snprintf(drvinfo->version, sizeof(drvinfo->version),
"%X", 0);
len = snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"%X", 0);
if (len >= sizeof(drvinfo->fw_version)) {
netdev_notice(net_dev, "snprintf() = %d\n", len);
}
strlcpy(drvinfo->bus_info, dev_name(net_dev->dev.parent->parent),
sizeof(drvinfo->bus_info));
}
static u32 dpaa_get_msglevel(struct net_device *net_dev)
{
return ((struct dpaa_priv *)netdev_priv(net_dev))->msg_enable;
}
static void dpaa_set_msglevel(struct net_device *net_dev,
u32 msg_enable)
{
((struct dpaa_priv *)netdev_priv(net_dev))->msg_enable = msg_enable;
}
static int dpaa_nway_reset(struct net_device *net_dev)
{
int err;
if (!net_dev->phydev) {
netdev_err(net_dev, "phy device not initialized\n");
return -ENODEV;
}
err = 0;
if (net_dev->phydev->autoneg) {
err = phy_start_aneg(net_dev->phydev);
if (err < 0)
netdev_err(net_dev, "phy_start_aneg() = %d\n",
err);
}
return err;
}
static void dpaa_get_pauseparam(struct net_device *net_dev,
struct ethtool_pauseparam *epause)
{
struct mac_device *mac_dev;
struct dpaa_priv *priv;
priv = netdev_priv(net_dev);
mac_dev = priv->mac_dev;
if (!net_dev->phydev) {
netdev_err(net_dev, "phy device not initialized\n");
return;
}
epause->autoneg = mac_dev->autoneg_pause;
epause->rx_pause = mac_dev->rx_pause_active;
epause->tx_pause = mac_dev->tx_pause_active;
}
static int dpaa_set_pauseparam(struct net_device *net_dev,
struct ethtool_pauseparam *epause)
{
struct mac_device *mac_dev;
struct phy_device *phydev;
bool rx_pause, tx_pause;
struct dpaa_priv *priv;
u32 newadv, oldadv;
int err;
priv = netdev_priv(net_dev);
mac_dev = priv->mac_dev;
phydev = net_dev->phydev;
if (!phydev) {
netdev_err(net_dev, "phy device not initialized\n");
return -ENODEV;
}
if (!(phydev->supported & SUPPORTED_Pause) ||
(!(phydev->supported & SUPPORTED_Asym_Pause) &&
(epause->rx_pause != epause->tx_pause)))
return -EINVAL;
mac_dev->autoneg_pause = !!epause->autoneg;
mac_dev->rx_pause_req = !!epause->rx_pause;
mac_dev->tx_pause_req = !!epause->tx_pause;
newadv = 0;
if (epause->rx_pause)
newadv = ADVERTISED_Pause | ADVERTISED_Asym_Pause;
if (epause->tx_pause)
newadv |= ADVERTISED_Asym_Pause;
oldadv = phydev->advertising &
(ADVERTISED_Pause | ADVERTISED_Asym_Pause);
if (oldadv != newadv) {
phydev->advertising &= ~(ADVERTISED_Pause
| ADVERTISED_Asym_Pause);
phydev->advertising |= newadv;
if (phydev->autoneg) {
err = phy_start_aneg(phydev);
if (err < 0)
netdev_err(net_dev, "phy_start_aneg() = %d\n",
err);
}
}
fman_get_pause_cfg(mac_dev, &rx_pause, &tx_pause);
err = fman_set_mac_active_pause(mac_dev, rx_pause, tx_pause);
if (err < 0)
netdev_err(net_dev, "set_mac_active_pause() = %d\n", err);
return err;
}
static int dpaa_get_sset_count(struct net_device *net_dev, int type)
{
unsigned int total_stats, num_stats;
num_stats = num_online_cpus() + 1;
total_stats = num_stats * (DPAA_STATS_PERCPU_LEN + DPAA_BPS_NUM) +
DPAA_STATS_GLOBAL_LEN;
switch (type) {
case ETH_SS_STATS:
return total_stats;
default:
return -EOPNOTSUPP;
}
}
static void copy_stats(struct dpaa_percpu_priv *percpu_priv, int num_cpus,
int crr_cpu, u64 *bp_count, u64 *data)
{
int num_values = num_cpus + 1;
int crr = 0, j;
data[crr * num_values + crr_cpu] = percpu_priv->in_interrupt;
data[crr++ * num_values + num_cpus] += percpu_priv->in_interrupt;
data[crr * num_values + crr_cpu] = percpu_priv->stats.rx_packets;
data[crr++ * num_values + num_cpus] += percpu_priv->stats.rx_packets;
data[crr * num_values + crr_cpu] = percpu_priv->stats.tx_packets;
data[crr++ * num_values + num_cpus] += percpu_priv->stats.tx_packets;
data[crr * num_values + crr_cpu] = percpu_priv->tx_confirm;
data[crr++ * num_values + num_cpus] += percpu_priv->tx_confirm;
data[crr * num_values + crr_cpu] = percpu_priv->tx_frag_skbuffs;
data[crr++ * num_values + num_cpus] += percpu_priv->tx_frag_skbuffs;
data[crr * num_values + crr_cpu] = percpu_priv->stats.tx_errors;
data[crr++ * num_values + num_cpus] += percpu_priv->stats.tx_errors;
data[crr * num_values + crr_cpu] = percpu_priv->stats.rx_errors;
data[crr++ * num_values + num_cpus] += percpu_priv->stats.rx_errors;
for (j = 0; j < DPAA_BPS_NUM; j++) {
data[crr * num_values + crr_cpu] = bp_count[j];
data[crr++ * num_values + num_cpus] += bp_count[j];
}
}
static void dpaa_get_ethtool_stats(struct net_device *net_dev,
struct ethtool_stats *stats, u64 *data)
{
u64 bp_count[DPAA_BPS_NUM], cg_time, cg_num;
struct dpaa_percpu_priv *percpu_priv;
struct dpaa_rx_errors rx_errors;
unsigned int num_cpus, offset;
struct dpaa_ern_cnt ern_cnt;
struct dpaa_bp *dpaa_bp;
struct dpaa_priv *priv;
int total_stats, i, j;
bool cg_status;
total_stats = dpaa_get_sset_count(net_dev, ETH_SS_STATS);
priv = netdev_priv(net_dev);
num_cpus = num_online_cpus();
memset(&bp_count, 0, sizeof(bp_count));
memset(&rx_errors, 0, sizeof(struct dpaa_rx_errors));
memset(&ern_cnt, 0, sizeof(struct dpaa_ern_cnt));
memset(data, 0, total_stats * sizeof(u64));
for_each_online_cpu(i) {
percpu_priv = per_cpu_ptr(priv->percpu_priv, i);
for (j = 0; j < DPAA_BPS_NUM; j++) {
dpaa_bp = priv->dpaa_bps[j];
if (!dpaa_bp->percpu_count)
continue;
bp_count[j] = *(per_cpu_ptr(dpaa_bp->percpu_count, i));
}
rx_errors.dme += percpu_priv->rx_errors.dme;
rx_errors.fpe += percpu_priv->rx_errors.fpe;
rx_errors.fse += percpu_priv->rx_errors.fse;
rx_errors.phe += percpu_priv->rx_errors.phe;
ern_cnt.cg_tdrop += percpu_priv->ern_cnt.cg_tdrop;
ern_cnt.wred += percpu_priv->ern_cnt.wred;
ern_cnt.err_cond += percpu_priv->ern_cnt.err_cond;
ern_cnt.early_window += percpu_priv->ern_cnt.early_window;
ern_cnt.late_window += percpu_priv->ern_cnt.late_window;
ern_cnt.fq_tdrop += percpu_priv->ern_cnt.fq_tdrop;
ern_cnt.fq_retired += percpu_priv->ern_cnt.fq_retired;
ern_cnt.orp_zero += percpu_priv->ern_cnt.orp_zero;
copy_stats(percpu_priv, num_cpus, i, bp_count, data);
}
offset = (num_cpus + 1) * (DPAA_STATS_PERCPU_LEN + DPAA_BPS_NUM);
memcpy(data + offset, &rx_errors, sizeof(struct dpaa_rx_errors));
offset += sizeof(struct dpaa_rx_errors) / sizeof(u64);
memcpy(data + offset, &ern_cnt, sizeof(struct dpaa_ern_cnt));
cg_num = 0;
cg_status = 0;
cg_time = jiffies_to_msecs(priv->cgr_data.congested_jiffies);
if (qman_query_cgr_congested(&priv->cgr_data.cgr, &cg_status) == 0) {
cg_num = priv->cgr_data.cgr_congested_count;
priv->cgr_data.congested_jiffies = 0;
priv->cgr_data.cgr_congested_count = 0;
}
offset += sizeof(struct dpaa_ern_cnt) / sizeof(u64);
data[offset++] = cg_time;
data[offset++] = cg_num;
data[offset++] = cg_status;
}
static void dpaa_get_strings(struct net_device *net_dev, u32 stringset,
u8 *data)
{
unsigned int i, j, num_cpus, size;
char string_cpu[ETH_GSTRING_LEN];
u8 *strings;
memset(string_cpu, 0, sizeof(string_cpu));
strings = data;
num_cpus = num_online_cpus();
size = DPAA_STATS_GLOBAL_LEN * ETH_GSTRING_LEN;
for (i = 0; i < DPAA_STATS_PERCPU_LEN; i++) {
for (j = 0; j < num_cpus; j++) {
snprintf(string_cpu, ETH_GSTRING_LEN, "%s [CPU %d]",
dpaa_stats_percpu[i], j);
memcpy(strings, string_cpu, ETH_GSTRING_LEN);
strings += ETH_GSTRING_LEN;
}
snprintf(string_cpu, ETH_GSTRING_LEN, "%s [TOTAL]",
dpaa_stats_percpu[i]);
memcpy(strings, string_cpu, ETH_GSTRING_LEN);
strings += ETH_GSTRING_LEN;
}
for (i = 0; i < DPAA_BPS_NUM; i++) {
for (j = 0; j < num_cpus; j++) {
snprintf(string_cpu, ETH_GSTRING_LEN,
"bpool %c [CPU %d]", 'a' + i, j);
memcpy(strings, string_cpu, ETH_GSTRING_LEN);
strings += ETH_GSTRING_LEN;
}
snprintf(string_cpu, ETH_GSTRING_LEN, "bpool %c [TOTAL]",
'a' + i);
memcpy(strings, string_cpu, ETH_GSTRING_LEN);
strings += ETH_GSTRING_LEN;
}
memcpy(strings, dpaa_stats_global, size);
}
