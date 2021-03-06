static void
mlx4_en_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *drvinfo)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct mlx4_en_dev *mdev = priv->mdev;
strncpy(drvinfo->driver, DRV_NAME, 32);
strncpy(drvinfo->version, DRV_VERSION " (" DRV_RELDATE ")", 32);
sprintf(drvinfo->fw_version, "%d.%d.%d",
(u16) (mdev->dev->caps.fw_ver >> 32),
(u16) ((mdev->dev->caps.fw_ver >> 16) & 0xffff),
(u16) (mdev->dev->caps.fw_ver & 0xffff));
strncpy(drvinfo->bus_info, pci_name(mdev->dev->pdev), 32);
drvinfo->n_stats = 0;
drvinfo->regdump_len = 0;
drvinfo->eedump_len = 0;
}
static u32 mlx4_en_get_msglevel(struct net_device *dev)
{
return ((struct mlx4_en_priv *) netdev_priv(dev))->msg_enable;
}
static void mlx4_en_set_msglevel(struct net_device *dev, u32 val)
{
((struct mlx4_en_priv *) netdev_priv(dev))->msg_enable = val;
}
static void mlx4_en_get_wol(struct net_device *netdev,
struct ethtool_wolinfo *wol)
{
struct mlx4_en_priv *priv = netdev_priv(netdev);
int err = 0;
u64 config = 0;
if (!priv->mdev->dev->caps.wol) {
wol->supported = 0;
wol->wolopts = 0;
return;
}
err = mlx4_wol_read(priv->mdev->dev, &config, priv->port);
if (err) {
en_err(priv, "Failed to get WoL information\n");
return;
}
if (config & MLX4_EN_WOL_MAGIC)
wol->supported = WAKE_MAGIC;
else
wol->supported = 0;
if (config & MLX4_EN_WOL_ENABLED)
wol->wolopts = WAKE_MAGIC;
else
wol->wolopts = 0;
}
static int mlx4_en_set_wol(struct net_device *netdev,
struct ethtool_wolinfo *wol)
{
struct mlx4_en_priv *priv = netdev_priv(netdev);
u64 config = 0;
int err = 0;
if (!priv->mdev->dev->caps.wol)
return -EOPNOTSUPP;
if (wol->supported & ~WAKE_MAGIC)
return -EINVAL;
err = mlx4_wol_read(priv->mdev->dev, &config, priv->port);
if (err) {
en_err(priv, "Failed to get WoL info, unable to modify\n");
return err;
}
if (wol->wolopts & WAKE_MAGIC) {
config |= MLX4_EN_WOL_DO_MODIFY | MLX4_EN_WOL_ENABLED |
MLX4_EN_WOL_MAGIC;
} else {
config &= ~(MLX4_EN_WOL_ENABLED | MLX4_EN_WOL_MAGIC);
config |= MLX4_EN_WOL_DO_MODIFY;
}
err = mlx4_wol_write(priv->mdev->dev, config, priv->port);
if (err)
en_err(priv, "Failed to set WoL information\n");
return err;
}
static int mlx4_en_get_sset_count(struct net_device *dev, int sset)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
switch (sset) {
case ETH_SS_STATS:
return NUM_ALL_STATS +
(priv->tx_ring_num + priv->rx_ring_num) * 2;
case ETH_SS_TEST:
return MLX4_EN_NUM_SELF_TEST - !(priv->mdev->dev->caps.loopback_support) * 2;
default:
return -EOPNOTSUPP;
}
}
static void mlx4_en_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, uint64_t *data)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
int index = 0;
int i;
spin_lock_bh(&priv->stats_lock);
for (i = 0; i < NUM_MAIN_STATS; i++)
data[index++] = ((unsigned long *) &priv->stats)[i];
for (i = 0; i < NUM_PORT_STATS; i++)
data[index++] = ((unsigned long *) &priv->port_stats)[i];
for (i = 0; i < priv->tx_ring_num; i++) {
data[index++] = priv->tx_ring[i].packets;
data[index++] = priv->tx_ring[i].bytes;
}
for (i = 0; i < priv->rx_ring_num; i++) {
data[index++] = priv->rx_ring[i].packets;
data[index++] = priv->rx_ring[i].bytes;
}
for (i = 0; i < NUM_PKT_STATS; i++)
data[index++] = ((unsigned long *) &priv->pkstats)[i];
spin_unlock_bh(&priv->stats_lock);
}
static void mlx4_en_self_test(struct net_device *dev,
struct ethtool_test *etest, u64 *buf)
{
mlx4_en_ex_selftest(dev, &etest->flags, buf);
}
static void mlx4_en_get_strings(struct net_device *dev,
uint32_t stringset, uint8_t *data)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
int index = 0;
int i;
switch (stringset) {
case ETH_SS_TEST:
for (i = 0; i < MLX4_EN_NUM_SELF_TEST - 2; i++)
strcpy(data + i * ETH_GSTRING_LEN, mlx4_en_test_names[i]);
if (priv->mdev->dev->caps.loopback_support)
for (; i < MLX4_EN_NUM_SELF_TEST; i++)
strcpy(data + i * ETH_GSTRING_LEN, mlx4_en_test_names[i]);
break;
case ETH_SS_STATS:
for (i = 0; i < NUM_MAIN_STATS; i++)
strcpy(data + (index++) * ETH_GSTRING_LEN, main_strings[i]);
for (i = 0; i< NUM_PORT_STATS; i++)
strcpy(data + (index++) * ETH_GSTRING_LEN,
main_strings[i + NUM_MAIN_STATS]);
for (i = 0; i < priv->tx_ring_num; i++) {
sprintf(data + (index++) * ETH_GSTRING_LEN,
"tx%d_packets", i);
sprintf(data + (index++) * ETH_GSTRING_LEN,
"tx%d_bytes", i);
}
for (i = 0; i < priv->rx_ring_num; i++) {
sprintf(data + (index++) * ETH_GSTRING_LEN,
"rx%d_packets", i);
sprintf(data + (index++) * ETH_GSTRING_LEN,
"rx%d_bytes", i);
}
for (i = 0; i< NUM_PKT_STATS; i++)
strcpy(data + (index++) * ETH_GSTRING_LEN,
main_strings[i + NUM_MAIN_STATS + NUM_PORT_STATS]);
break;
}
}
static int mlx4_en_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
int trans_type;
cmd->autoneg = AUTONEG_DISABLE;
cmd->supported = SUPPORTED_10000baseT_Full;
cmd->advertising = ADVERTISED_10000baseT_Full;
if (mlx4_en_QUERY_PORT(priv->mdev, priv->port))
return -ENOMEM;
trans_type = priv->port_state.transciver;
if (netif_carrier_ok(dev)) {
ethtool_cmd_speed_set(cmd, priv->port_state.link_speed);
cmd->duplex = DUPLEX_FULL;
} else {
ethtool_cmd_speed_set(cmd, -1);
cmd->duplex = -1;
}
if (trans_type > 0 && trans_type <= 0xC) {
cmd->port = PORT_FIBRE;
cmd->transceiver = XCVR_EXTERNAL;
cmd->supported |= SUPPORTED_FIBRE;
cmd->advertising |= ADVERTISED_FIBRE;
} else if (trans_type == 0x80 || trans_type == 0) {
cmd->port = PORT_TP;
cmd->transceiver = XCVR_INTERNAL;
cmd->supported |= SUPPORTED_TP;
cmd->advertising |= ADVERTISED_TP;
} else {
cmd->port = -1;
cmd->transceiver = -1;
}
return 0;
}
static int mlx4_en_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
if ((cmd->autoneg == AUTONEG_ENABLE) ||
(ethtool_cmd_speed(cmd) != SPEED_10000) ||
(cmd->duplex != DUPLEX_FULL))
return -EINVAL;
return 0;
}
static int mlx4_en_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *coal)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
coal->tx_coalesce_usecs = 0;
coal->tx_max_coalesced_frames = 0;
coal->rx_coalesce_usecs = priv->rx_usecs;
coal->rx_max_coalesced_frames = priv->rx_frames;
coal->pkt_rate_low = priv->pkt_rate_low;
coal->rx_coalesce_usecs_low = priv->rx_usecs_low;
coal->pkt_rate_high = priv->pkt_rate_high;
coal->rx_coalesce_usecs_high = priv->rx_usecs_high;
coal->rate_sample_interval = priv->sample_interval;
coal->use_adaptive_rx_coalesce = priv->adaptive_rx_coal;
return 0;
}
static int mlx4_en_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *coal)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
int err, i;
priv->rx_frames = (coal->rx_max_coalesced_frames ==
MLX4_EN_AUTO_CONF) ?
MLX4_EN_RX_COAL_TARGET :
coal->rx_max_coalesced_frames;
priv->rx_usecs = (coal->rx_coalesce_usecs ==
MLX4_EN_AUTO_CONF) ?
MLX4_EN_RX_COAL_TIME :
coal->rx_coalesce_usecs;
priv->pkt_rate_low = coal->pkt_rate_low;
priv->rx_usecs_low = coal->rx_coalesce_usecs_low;
priv->pkt_rate_high = coal->pkt_rate_high;
priv->rx_usecs_high = coal->rx_coalesce_usecs_high;
priv->sample_interval = coal->rate_sample_interval;
priv->adaptive_rx_coal = coal->use_adaptive_rx_coalesce;
priv->last_moder_time = MLX4_EN_AUTO_CONF;
if (priv->adaptive_rx_coal)
return 0;
for (i = 0; i < priv->rx_ring_num; i++) {
priv->rx_cq[i].moder_cnt = priv->rx_frames;
priv->rx_cq[i].moder_time = priv->rx_usecs;
err = mlx4_en_set_cq_moder(priv, &priv->rx_cq[i]);
if (err)
return err;
}
return 0;
}
static int mlx4_en_set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *pause)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct mlx4_en_dev *mdev = priv->mdev;
int err;
priv->prof->tx_pause = pause->tx_pause != 0;
priv->prof->rx_pause = pause->rx_pause != 0;
err = mlx4_SET_PORT_general(mdev->dev, priv->port,
priv->rx_skb_size + ETH_FCS_LEN,
priv->prof->tx_pause,
priv->prof->tx_ppp,
priv->prof->rx_pause,
priv->prof->rx_ppp);
if (err)
en_err(priv, "Failed setting pause params\n");
return err;
}
static void mlx4_en_get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *pause)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
pause->tx_pause = priv->prof->tx_pause;
pause->rx_pause = priv->prof->rx_pause;
}
static int mlx4_en_set_ringparam(struct net_device *dev,
struct ethtool_ringparam *param)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct mlx4_en_dev *mdev = priv->mdev;
u32 rx_size, tx_size;
int port_up = 0;
int err = 0;
if (param->rx_jumbo_pending || param->rx_mini_pending)
return -EINVAL;
rx_size = roundup_pow_of_two(param->rx_pending);
rx_size = max_t(u32, rx_size, MLX4_EN_MIN_RX_SIZE);
rx_size = min_t(u32, rx_size, MLX4_EN_MAX_RX_SIZE);
tx_size = roundup_pow_of_two(param->tx_pending);
tx_size = max_t(u32, tx_size, MLX4_EN_MIN_TX_SIZE);
tx_size = min_t(u32, tx_size, MLX4_EN_MAX_TX_SIZE);
if (rx_size == (priv->port_up ? priv->rx_ring[0].actual_size :
priv->rx_ring[0].size) &&
tx_size == priv->tx_ring[0].size)
return 0;
mutex_lock(&mdev->state_lock);
if (priv->port_up) {
port_up = 1;
mlx4_en_stop_port(dev);
}
mlx4_en_free_resources(priv, true);
priv->prof->tx_ring_size = tx_size;
priv->prof->rx_ring_size = rx_size;
err = mlx4_en_alloc_resources(priv);
if (err) {
en_err(priv, "Failed reallocating port resources\n");
goto out;
}
if (port_up) {
err = mlx4_en_start_port(dev);
if (err)
en_err(priv, "Failed starting port\n");
}
out:
mutex_unlock(&mdev->state_lock);
return err;
}
static void mlx4_en_get_ringparam(struct net_device *dev,
struct ethtool_ringparam *param)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
memset(param, 0, sizeof(*param));
param->rx_max_pending = MLX4_EN_MAX_RX_SIZE;
param->tx_max_pending = MLX4_EN_MAX_TX_SIZE;
param->rx_pending = priv->port_up ?
priv->rx_ring[0].actual_size : priv->rx_ring[0].size;
param->tx_pending = priv->tx_ring[0].size;
}
