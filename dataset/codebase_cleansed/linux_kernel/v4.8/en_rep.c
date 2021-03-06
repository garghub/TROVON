static void mlx5e_rep_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->driver, mlx5e_rep_driver_name,
sizeof(drvinfo->driver));
strlcpy(drvinfo->version, UTS_RELEASE, sizeof(drvinfo->version));
}
static void mlx5e_rep_get_strings(struct net_device *dev,
u32 stringset, uint8_t *data)
{
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < NUM_VPORT_REP_COUNTERS; i++)
strcpy(data + (i * ETH_GSTRING_LEN),
sw_rep_stats_desc[i].format);
break;
}
}
static void mlx5e_update_sw_rep_counters(struct mlx5e_priv *priv)
{
struct mlx5e_sw_stats *s = &priv->stats.sw;
struct mlx5e_rq_stats *rq_stats;
struct mlx5e_sq_stats *sq_stats;
int i, j;
memset(s, 0, sizeof(*s));
for (i = 0; i < priv->params.num_channels; i++) {
rq_stats = &priv->channel[i]->rq.stats;
s->rx_packets += rq_stats->packets;
s->rx_bytes += rq_stats->bytes;
for (j = 0; j < priv->params.num_tc; j++) {
sq_stats = &priv->channel[i]->sq[j].stats;
s->tx_packets += sq_stats->packets;
s->tx_bytes += sq_stats->bytes;
}
}
}
static void mlx5e_rep_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct mlx5e_priv *priv = netdev_priv(dev);
int i;
if (!data)
return;
mutex_lock(&priv->state_lock);
if (test_bit(MLX5E_STATE_OPENED, &priv->state))
mlx5e_update_sw_rep_counters(priv);
mutex_unlock(&priv->state_lock);
for (i = 0; i < NUM_VPORT_REP_COUNTERS; i++)
data[i] = MLX5E_READ_CTR64_CPU(&priv->stats.sw,
sw_rep_stats_desc, i);
}
static int mlx5e_rep_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return NUM_VPORT_REP_COUNTERS;
default:
return -EOPNOTSUPP;
}
}
int mlx5e_attr_get(struct net_device *dev, struct switchdev_attr *attr)
{
struct mlx5e_priv *priv = netdev_priv(dev);
struct mlx5_eswitch_rep *rep = priv->ppriv;
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
if (esw->mode == SRIOV_NONE)
return -EOPNOTSUPP;
switch (attr->id) {
case SWITCHDEV_ATTR_ID_PORT_PARENT_ID:
attr->u.ppid.id_len = ETH_ALEN;
ether_addr_copy(attr->u.ppid.id, rep->hw_id);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
int mlx5e_add_sqs_fwd_rules(struct mlx5e_priv *priv)
{
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct mlx5_eswitch_rep *rep = priv->ppriv;
struct mlx5e_channel *c;
int n, tc, err, num_sqs = 0;
u16 *sqs;
sqs = kcalloc(priv->params.num_channels * priv->params.num_tc, sizeof(u16), GFP_KERNEL);
if (!sqs)
return -ENOMEM;
for (n = 0; n < priv->params.num_channels; n++) {
c = priv->channel[n];
for (tc = 0; tc < c->num_tc; tc++)
sqs[num_sqs++] = c->sq[tc].sqn;
}
err = mlx5_eswitch_sqs2vport_start(esw, rep, sqs, num_sqs);
kfree(sqs);
return err;
}
int mlx5e_nic_rep_load(struct mlx5_eswitch *esw, struct mlx5_eswitch_rep *rep)
{
struct mlx5e_priv *priv = rep->priv_data;
if (test_bit(MLX5E_STATE_OPENED, &priv->state))
return mlx5e_add_sqs_fwd_rules(priv);
return 0;
}
void mlx5e_remove_sqs_fwd_rules(struct mlx5e_priv *priv)
{
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct mlx5_eswitch_rep *rep = priv->ppriv;
mlx5_eswitch_sqs2vport_stop(esw, rep);
}
void mlx5e_nic_rep_unload(struct mlx5_eswitch *esw,
struct mlx5_eswitch_rep *rep)
{
struct mlx5e_priv *priv = rep->priv_data;
if (test_bit(MLX5E_STATE_OPENED, &priv->state))
mlx5e_remove_sqs_fwd_rules(priv);
mlx5e_tc_cleanup(priv);
mlx5e_tc_init(priv);
}
static int mlx5e_rep_get_phys_port_name(struct net_device *dev,
char *buf, size_t len)
{
struct mlx5e_priv *priv = netdev_priv(dev);
struct mlx5_eswitch_rep *rep = priv->ppriv;
int ret;
ret = snprintf(buf, len, "%d", rep->vport - 1);
if (ret >= len)
return -EOPNOTSUPP;
return 0;
}
static int mlx5e_rep_ndo_setup_tc(struct net_device *dev, u32 handle,
__be16 proto, struct tc_to_netdev *tc)
{
struct mlx5e_priv *priv = netdev_priv(dev);
if (TC_H_MAJ(handle) != TC_H_MAJ(TC_H_INGRESS))
return -EOPNOTSUPP;
switch (tc->type) {
case TC_SETUP_CLSFLOWER:
switch (tc->cls_flower->command) {
case TC_CLSFLOWER_REPLACE:
return mlx5e_configure_flower(priv, proto, tc->cls_flower);
case TC_CLSFLOWER_DESTROY:
return mlx5e_delete_flower(priv, tc->cls_flower);
case TC_CLSFLOWER_STATS:
return mlx5e_stats_flower(priv, tc->cls_flower);
}
default:
return -EOPNOTSUPP;
}
}
static void mlx5e_build_rep_netdev_priv(struct mlx5_core_dev *mdev,
struct net_device *netdev,
const struct mlx5e_profile *profile,
void *ppriv)
{
struct mlx5e_priv *priv = netdev_priv(netdev);
u8 cq_period_mode = MLX5_CAP_GEN(mdev, cq_period_start_from_cqe) ?
MLX5_CQ_PERIOD_MODE_START_FROM_CQE :
MLX5_CQ_PERIOD_MODE_START_FROM_EQE;
priv->params.log_sq_size =
MLX5E_PARAMS_MINIMUM_LOG_SQ_SIZE;
priv->params.rq_wq_type = MLX5_WQ_TYPE_LINKED_LIST;
priv->params.log_rq_size = MLX5E_PARAMS_MINIMUM_LOG_RQ_SIZE;
priv->params.min_rx_wqes = mlx5_min_rx_wqes(priv->params.rq_wq_type,
BIT(priv->params.log_rq_size));
priv->params.rx_am_enabled = MLX5_CAP_GEN(mdev, cq_moderation);
mlx5e_set_rx_cq_mode_params(&priv->params, cq_period_mode);
priv->params.tx_max_inline = mlx5e_get_max_inline_cap(mdev);
priv->params.num_tc = 1;
priv->params.lro_wqe_sz =
MLX5E_PARAMS_DEFAULT_LRO_WQE_SZ;
priv->mdev = mdev;
priv->netdev = netdev;
priv->params.num_channels = profile->max_nch(mdev);
priv->profile = profile;
priv->ppriv = ppriv;
mutex_init(&priv->state_lock);
INIT_DELAYED_WORK(&priv->update_stats_work, mlx5e_update_stats_work);
}
static void mlx5e_build_rep_netdev(struct net_device *netdev)
{
netdev->netdev_ops = &mlx5e_netdev_ops_rep;
netdev->watchdog_timeo = 15 * HZ;
netdev->ethtool_ops = &mlx5e_rep_ethtool_ops;
#ifdef CONFIG_NET_SWITCHDEV
netdev->switchdev_ops = &mlx5e_rep_switchdev_ops;
#endif
netdev->features |= NETIF_F_VLAN_CHALLENGED | NETIF_F_HW_TC;
netdev->hw_features |= NETIF_F_HW_TC;
eth_hw_addr_random(netdev);
}
static void mlx5e_init_rep(struct mlx5_core_dev *mdev,
struct net_device *netdev,
const struct mlx5e_profile *profile,
void *ppriv)
{
mlx5e_build_rep_netdev_priv(mdev, netdev, profile, ppriv);
mlx5e_build_rep_netdev(netdev);
}
static int mlx5e_init_rep_rx(struct mlx5e_priv *priv)
{
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct mlx5_eswitch_rep *rep = priv->ppriv;
struct mlx5_core_dev *mdev = priv->mdev;
struct mlx5_flow_rule *flow_rule;
int err;
int i;
err = mlx5e_create_direct_rqts(priv);
if (err) {
mlx5_core_warn(mdev, "create direct rqts failed, %d\n", err);
return err;
}
err = mlx5e_create_direct_tirs(priv);
if (err) {
mlx5_core_warn(mdev, "create direct tirs failed, %d\n", err);
goto err_destroy_direct_rqts;
}
flow_rule = mlx5_eswitch_create_vport_rx_rule(esw,
rep->vport,
priv->direct_tir[0].tirn);
if (IS_ERR(flow_rule)) {
err = PTR_ERR(flow_rule);
goto err_destroy_direct_tirs;
}
rep->vport_rx_rule = flow_rule;
err = mlx5e_tc_init(priv);
if (err)
goto err_del_flow_rule;
return 0;
err_del_flow_rule:
mlx5_del_flow_rule(rep->vport_rx_rule);
err_destroy_direct_tirs:
mlx5e_destroy_direct_tirs(priv);
err_destroy_direct_rqts:
for (i = 0; i < priv->params.num_channels; i++)
mlx5e_destroy_rqt(priv, &priv->direct_tir[i].rqt);
return err;
}
static void mlx5e_cleanup_rep_rx(struct mlx5e_priv *priv)
{
struct mlx5_eswitch_rep *rep = priv->ppriv;
int i;
mlx5e_tc_cleanup(priv);
mlx5_del_flow_rule(rep->vport_rx_rule);
mlx5e_destroy_direct_tirs(priv);
for (i = 0; i < priv->params.num_channels; i++)
mlx5e_destroy_rqt(priv, &priv->direct_tir[i].rqt);
}
static int mlx5e_init_rep_tx(struct mlx5e_priv *priv)
{
int err;
err = mlx5e_create_tises(priv);
if (err) {
mlx5_core_warn(priv->mdev, "create tises failed, %d\n", err);
return err;
}
return 0;
}
static int mlx5e_get_rep_max_num_channels(struct mlx5_core_dev *mdev)
{
#define MLX5E_PORT_REPRESENTOR_NCH 1
return MLX5E_PORT_REPRESENTOR_NCH;
}
int mlx5e_vport_rep_load(struct mlx5_eswitch *esw,
struct mlx5_eswitch_rep *rep)
{
rep->priv_data = mlx5e_create_netdev(esw->dev, &mlx5e_rep_profile, rep);
if (!rep->priv_data) {
pr_warn("Failed to create representor for vport %d\n",
rep->vport);
return -EINVAL;
}
return 0;
}
void mlx5e_vport_rep_unload(struct mlx5_eswitch *esw,
struct mlx5_eswitch_rep *rep)
{
struct mlx5e_priv *priv = rep->priv_data;
mlx5e_destroy_netdev(esw->dev, priv);
}
