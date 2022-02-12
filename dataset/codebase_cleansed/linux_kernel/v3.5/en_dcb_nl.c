static int mlx4_en_dcbnl_ieee_getets(struct net_device *dev,
struct ieee_ets *ets)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct ieee_ets *my_ets = &priv->ets;
if (!my_ets)
return -EINVAL;
ets->ets_cap = IEEE_8021QAZ_MAX_TCS;
ets->cbs = my_ets->cbs;
memcpy(ets->tc_tx_bw, my_ets->tc_tx_bw, sizeof(ets->tc_tx_bw));
memcpy(ets->tc_tsa, my_ets->tc_tsa, sizeof(ets->tc_tsa));
memcpy(ets->prio_tc, my_ets->prio_tc, sizeof(ets->prio_tc));
return 0;
}
static int mlx4_en_ets_validate(struct mlx4_en_priv *priv, struct ieee_ets *ets)
{
int i;
int total_ets_bw = 0;
int has_ets_tc = 0;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
if (ets->prio_tc[i] > MLX4_EN_NUM_UP) {
en_err(priv, "Bad priority in UP <=> TC mapping. TC: %d, UP: %d\n",
i, ets->prio_tc[i]);
return -EINVAL;
}
switch (ets->tc_tsa[i]) {
case IEEE_8021QAZ_TSA_STRICT:
break;
case IEEE_8021QAZ_TSA_ETS:
has_ets_tc = 1;
total_ets_bw += ets->tc_tx_bw[i];
break;
default:
en_err(priv, "TC[%d]: Not supported TSA: %d\n",
i, ets->tc_tsa[i]);
return -ENOTSUPP;
}
}
if (has_ets_tc && total_ets_bw != MLX4_EN_BW_MAX) {
en_err(priv, "Bad ETS BW sum: %d. Should be exactly 100%%\n",
total_ets_bw);
return -EINVAL;
}
return 0;
}
static int mlx4_en_config_port_scheduler(struct mlx4_en_priv *priv,
struct ieee_ets *ets, u16 *ratelimit)
{
struct mlx4_en_dev *mdev = priv->mdev;
int num_strict = 0;
int i;
__u8 tc_tx_bw[IEEE_8021QAZ_MAX_TCS] = { 0 };
__u8 pg[IEEE_8021QAZ_MAX_TCS] = { 0 };
ets = ets ?: &priv->ets;
ratelimit = ratelimit ?: priv->maxrate;
for (i = IEEE_8021QAZ_MAX_TCS - 1; i >= 0; i--) {
switch (ets->tc_tsa[i]) {
case IEEE_8021QAZ_TSA_STRICT:
pg[i] = num_strict++;
tc_tx_bw[i] = MLX4_EN_BW_MAX;
break;
case IEEE_8021QAZ_TSA_ETS:
pg[i] = MLX4_EN_TC_ETS;
tc_tx_bw[i] = ets->tc_tx_bw[i] ?: MLX4_EN_BW_MIN;
break;
}
}
return mlx4_SET_PORT_SCHEDULER(mdev->dev, priv->port, tc_tx_bw, pg,
ratelimit);
}
static int
mlx4_en_dcbnl_ieee_setets(struct net_device *dev, struct ieee_ets *ets)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct mlx4_en_dev *mdev = priv->mdev;
int err;
err = mlx4_en_ets_validate(priv, ets);
if (err)
return err;
err = mlx4_SET_PORT_PRIO2TC(mdev->dev, priv->port, ets->prio_tc);
if (err)
return err;
err = mlx4_en_config_port_scheduler(priv, ets, NULL);
if (err)
return err;
memcpy(&priv->ets, ets, sizeof(priv->ets));
return 0;
}
static int mlx4_en_dcbnl_ieee_getpfc(struct net_device *dev,
struct ieee_pfc *pfc)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
pfc->pfc_cap = IEEE_8021QAZ_MAX_TCS;
pfc->pfc_en = priv->prof->tx_ppp;
return 0;
}
static int mlx4_en_dcbnl_ieee_setpfc(struct net_device *dev,
struct ieee_pfc *pfc)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct mlx4_en_dev *mdev = priv->mdev;
int err;
en_dbg(DRV, priv, "cap: 0x%x en: 0x%x mbc: 0x%x delay: %d\n",
pfc->pfc_cap,
pfc->pfc_en,
pfc->mbc,
pfc->delay);
priv->prof->rx_pause = priv->prof->tx_pause = !!pfc->pfc_en;
priv->prof->rx_ppp = priv->prof->tx_ppp = pfc->pfc_en;
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
static u8 mlx4_en_dcbnl_getdcbx(struct net_device *dev)
{
return DCB_CAP_DCBX_VER_IEEE;
}
static u8 mlx4_en_dcbnl_setdcbx(struct net_device *dev, u8 mode)
{
if ((mode & DCB_CAP_DCBX_LLD_MANAGED) ||
(mode & DCB_CAP_DCBX_VER_CEE) ||
!(mode & DCB_CAP_DCBX_VER_IEEE) ||
!(mode & DCB_CAP_DCBX_HOST))
return 1;
return 0;
}
static int mlx4_en_dcbnl_ieee_getmaxrate(struct net_device *dev,
struct ieee_maxrate *maxrate)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
int i;
if (!priv->maxrate)
return -EINVAL;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++)
maxrate->tc_maxrate[i] =
priv->maxrate[i] * MLX4_RATELIMIT_UNITS_IN_KB;
return 0;
}
static int mlx4_en_dcbnl_ieee_setmaxrate(struct net_device *dev,
struct ieee_maxrate *maxrate)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
u16 tmp[IEEE_8021QAZ_MAX_TCS];
int i, err;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
tmp[i] = div_u64(maxrate->tc_maxrate[i] +
MLX4_RATELIMIT_UNITS_IN_KB - 1,
MLX4_RATELIMIT_UNITS_IN_KB);
}
err = mlx4_en_config_port_scheduler(priv, NULL, tmp);
if (err)
return err;
memcpy(priv->maxrate, tmp, sizeof(*priv->maxrate));
return 0;
}
