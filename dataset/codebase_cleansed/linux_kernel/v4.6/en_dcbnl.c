static int mlx5e_dcbnl_ieee_getets(struct net_device *netdev,
struct ieee_ets *ets)
{
struct mlx5e_priv *priv = netdev_priv(netdev);
if (!MLX5_CAP_GEN(priv->mdev, ets))
return -ENOTSUPP;
memcpy(ets, &priv->params.ets, sizeof(*ets));
return 0;
}
static void mlx5e_build_tc_group(struct ieee_ets *ets, u8 *tc_group, int max_tc)
{
bool any_tc_mapped_to_ets = false;
int strict_group;
int i;
for (i = 0; i <= max_tc; i++)
if (ets->tc_tsa[i] == IEEE_8021QAZ_TSA_ETS)
any_tc_mapped_to_ets = true;
strict_group = any_tc_mapped_to_ets ? 1 : 0;
for (i = 0; i <= max_tc; i++) {
switch (ets->tc_tsa[i]) {
case IEEE_8021QAZ_TSA_VENDOR:
tc_group[i] = MLX5E_VENDOR_TC_GROUP_NUM;
break;
case IEEE_8021QAZ_TSA_STRICT:
tc_group[i] = strict_group++;
break;
case IEEE_8021QAZ_TSA_ETS:
tc_group[i] = MLX5E_ETS_TC_GROUP_NUM;
break;
}
}
}
static void mlx5e_build_tc_tx_bw(struct ieee_ets *ets, u8 *tc_tx_bw,
u8 *tc_group, int max_tc)
{
int i;
for (i = 0; i <= max_tc; i++) {
switch (ets->tc_tsa[i]) {
case IEEE_8021QAZ_TSA_VENDOR:
tc_tx_bw[i] = MLX5E_MAX_BW_ALLOC;
break;
case IEEE_8021QAZ_TSA_STRICT:
tc_tx_bw[i] = MLX5E_MAX_BW_ALLOC;
break;
case IEEE_8021QAZ_TSA_ETS:
tc_tx_bw[i] = ets->tc_tx_bw[i] ?: MLX5E_MIN_BW_ALLOC;
break;
}
}
}
int mlx5e_dcbnl_ieee_setets_core(struct mlx5e_priv *priv, struct ieee_ets *ets)
{
struct mlx5_core_dev *mdev = priv->mdev;
u8 tc_tx_bw[IEEE_8021QAZ_MAX_TCS];
u8 tc_group[IEEE_8021QAZ_MAX_TCS];
int max_tc = mlx5_max_tc(mdev);
int err;
if (!MLX5_CAP_GEN(mdev, ets))
return -ENOTSUPP;
mlx5e_build_tc_group(ets, tc_group, max_tc);
mlx5e_build_tc_tx_bw(ets, tc_tx_bw, tc_group, max_tc);
err = mlx5_set_port_prio_tc(mdev, ets->prio_tc);
if (err)
return err;
err = mlx5_set_port_tc_group(mdev, tc_group);
if (err)
return err;
return mlx5_set_port_tc_bw_alloc(mdev, tc_tx_bw);
}
static int mlx5e_dbcnl_validate_ets(struct ieee_ets *ets)
{
int bw_sum = 0;
int i;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
if (ets->prio_tc[i] >= MLX5E_MAX_PRIORITY)
return -EINVAL;
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
if (ets->tc_tsa[i] == IEEE_8021QAZ_TSA_ETS)
bw_sum += ets->tc_tx_bw[i];
}
if (bw_sum != 0 && bw_sum != 100)
return -EINVAL;
return 0;
}
static int mlx5e_dcbnl_ieee_setets(struct net_device *netdev,
struct ieee_ets *ets)
{
struct mlx5e_priv *priv = netdev_priv(netdev);
int err;
err = mlx5e_dbcnl_validate_ets(ets);
if (err)
return err;
err = mlx5e_dcbnl_ieee_setets_core(priv, ets);
if (err)
return err;
memcpy(&priv->params.ets, ets, sizeof(*ets));
priv->params.ets.ets_cap = mlx5_max_tc(priv->mdev) + 1;
return 0;
}
static int mlx5e_dcbnl_ieee_getpfc(struct net_device *dev,
struct ieee_pfc *pfc)
{
struct mlx5e_priv *priv = netdev_priv(dev);
struct mlx5_core_dev *mdev = priv->mdev;
pfc->pfc_cap = mlx5_max_tc(mdev) + 1;
return mlx5_query_port_pfc(mdev, &pfc->pfc_en, NULL);
}
static int mlx5e_dcbnl_ieee_setpfc(struct net_device *dev,
struct ieee_pfc *pfc)
{
struct mlx5e_priv *priv = netdev_priv(dev);
struct mlx5_core_dev *mdev = priv->mdev;
enum mlx5_port_status ps;
u8 curr_pfc_en;
int ret;
mlx5_query_port_pfc(mdev, &curr_pfc_en, NULL);
if (pfc->pfc_en == curr_pfc_en)
return 0;
mlx5_query_port_admin_status(mdev, &ps);
if (ps == MLX5_PORT_UP)
mlx5_set_port_admin_status(mdev, MLX5_PORT_DOWN);
ret = mlx5_set_port_pfc(mdev, pfc->pfc_en, pfc->pfc_en);
if (ps == MLX5_PORT_UP)
mlx5_set_port_admin_status(mdev, MLX5_PORT_UP);
return ret;
}
static u8 mlx5e_dcbnl_getdcbx(struct net_device *dev)
{
return DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_IEEE;
}
static u8 mlx5e_dcbnl_setdcbx(struct net_device *dev, u8 mode)
{
if ((mode & DCB_CAP_DCBX_LLD_MANAGED) ||
(mode & DCB_CAP_DCBX_VER_CEE) ||
!(mode & DCB_CAP_DCBX_VER_IEEE) ||
!(mode & DCB_CAP_DCBX_HOST))
return 1;
return 0;
}
static int mlx5e_dcbnl_ieee_getmaxrate(struct net_device *netdev,
struct ieee_maxrate *maxrate)
{
struct mlx5e_priv *priv = netdev_priv(netdev);
struct mlx5_core_dev *mdev = priv->mdev;
u8 max_bw_value[IEEE_8021QAZ_MAX_TCS];
u8 max_bw_unit[IEEE_8021QAZ_MAX_TCS];
int err;
int i;
err = mlx5_query_port_ets_rate_limit(mdev, max_bw_value, max_bw_unit);
if (err)
return err;
memset(maxrate->tc_maxrate, 0, sizeof(maxrate->tc_maxrate));
for (i = 0; i <= mlx5_max_tc(mdev); i++) {
switch (max_bw_unit[i]) {
case MLX5_100_MBPS_UNIT:
maxrate->tc_maxrate[i] = max_bw_value[i] * MLX5E_100MB;
break;
case MLX5_GBPS_UNIT:
maxrate->tc_maxrate[i] = max_bw_value[i] * MLX5E_1GB;
break;
case MLX5_BW_NO_LIMIT:
break;
default:
WARN(true, "non-supported BW unit");
break;
}
}
return 0;
}
static int mlx5e_dcbnl_ieee_setmaxrate(struct net_device *netdev,
struct ieee_maxrate *maxrate)
{
struct mlx5e_priv *priv = netdev_priv(netdev);
struct mlx5_core_dev *mdev = priv->mdev;
u8 max_bw_value[IEEE_8021QAZ_MAX_TCS];
u8 max_bw_unit[IEEE_8021QAZ_MAX_TCS];
__u64 upper_limit_mbps = roundup(255 * MLX5E_100MB, MLX5E_1GB);
int i;
memset(max_bw_value, 0, sizeof(max_bw_value));
memset(max_bw_unit, 0, sizeof(max_bw_unit));
for (i = 0; i <= mlx5_max_tc(mdev); i++) {
if (!maxrate->tc_maxrate[i]) {
max_bw_unit[i] = MLX5_BW_NO_LIMIT;
continue;
}
if (maxrate->tc_maxrate[i] < upper_limit_mbps) {
max_bw_value[i] = div_u64(maxrate->tc_maxrate[i],
MLX5E_100MB);
max_bw_value[i] = max_bw_value[i] ? max_bw_value[i] : 1;
max_bw_unit[i] = MLX5_100_MBPS_UNIT;
} else {
max_bw_value[i] = div_u64(maxrate->tc_maxrate[i],
MLX5E_1GB);
max_bw_unit[i] = MLX5_GBPS_UNIT;
}
}
return mlx5_modify_port_ets_rate_limit(mdev, max_bw_value, max_bw_unit);
}
