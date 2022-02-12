static int xgbe_dcb_ieee_getets(struct net_device *netdev,
struct ieee_ets *ets)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
ets->ets_cap = pdata->hw_feat.tc_cnt;
if (pdata->ets) {
ets->cbs = pdata->ets->cbs;
memcpy(ets->tc_tx_bw, pdata->ets->tc_tx_bw,
sizeof(ets->tc_tx_bw));
memcpy(ets->tc_tsa, pdata->ets->tc_tsa,
sizeof(ets->tc_tsa));
memcpy(ets->prio_tc, pdata->ets->prio_tc,
sizeof(ets->prio_tc));
}
return 0;
}
static int xgbe_dcb_ieee_setets(struct net_device *netdev,
struct ieee_ets *ets)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
unsigned int i, tc_ets, tc_ets_weight;
u8 max_tc = 0;
tc_ets = 0;
tc_ets_weight = 0;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
netif_dbg(pdata, drv, netdev,
"TC%u: tx_bw=%hhu, rx_bw=%hhu, tsa=%hhu\n", i,
ets->tc_tx_bw[i], ets->tc_rx_bw[i],
ets->tc_tsa[i]);
netif_dbg(pdata, drv, netdev, "PRIO%u: TC=%hhu\n", i,
ets->prio_tc[i]);
max_tc = max_t(u8, max_tc, ets->prio_tc[i]);
if ((ets->tc_tx_bw[i] || ets->tc_tsa[i]))
max_tc = max_t(u8, max_tc, i);
switch (ets->tc_tsa[i]) {
case IEEE_8021QAZ_TSA_STRICT:
break;
case IEEE_8021QAZ_TSA_ETS:
tc_ets = 1;
tc_ets_weight += ets->tc_tx_bw[i];
break;
default:
netif_err(pdata, drv, netdev,
"unsupported TSA algorithm (%hhu)\n",
ets->tc_tsa[i]);
return -EINVAL;
}
}
if (max_tc >= pdata->hw_feat.tc_cnt) {
netif_err(pdata, drv, netdev,
"exceeded number of supported traffic classes\n");
return -EINVAL;
}
if (tc_ets && (tc_ets_weight != 100)) {
netif_err(pdata, drv, netdev,
"sum of ETS algorithm weights is not 100 (%u)\n",
tc_ets_weight);
return -EINVAL;
}
if (!pdata->ets) {
pdata->ets = devm_kzalloc(pdata->dev, sizeof(*pdata->ets),
GFP_KERNEL);
if (!pdata->ets)
return -ENOMEM;
}
pdata->num_tcs = max_tc + 1;
memcpy(pdata->ets, ets, sizeof(*pdata->ets));
pdata->hw_if.config_dcb_tc(pdata);
return 0;
}
static int xgbe_dcb_ieee_getpfc(struct net_device *netdev,
struct ieee_pfc *pfc)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
pfc->pfc_cap = pdata->hw_feat.tc_cnt;
if (pdata->pfc) {
pfc->pfc_en = pdata->pfc->pfc_en;
pfc->mbc = pdata->pfc->mbc;
pfc->delay = pdata->pfc->delay;
}
return 0;
}
static int xgbe_dcb_ieee_setpfc(struct net_device *netdev,
struct ieee_pfc *pfc)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
netif_dbg(pdata, drv, netdev,
"cap=%hhu, en=%#hhx, mbc=%hhu, delay=%hhu\n",
pfc->pfc_cap, pfc->pfc_en, pfc->mbc, pfc->delay);
if (pfc->pfc_en & ~((1 << pdata->hw_feat.tc_cnt) - 1)) {
netif_err(pdata, drv, netdev,
"PFC requested for unsupported traffic class\n");
return -EINVAL;
}
if (!pdata->pfc) {
pdata->pfc = devm_kzalloc(pdata->dev, sizeof(*pdata->pfc),
GFP_KERNEL);
if (!pdata->pfc)
return -ENOMEM;
}
memcpy(pdata->pfc, pfc, sizeof(*pdata->pfc));
pdata->hw_if.config_dcb_pfc(pdata);
return 0;
}
static u8 xgbe_dcb_getdcbx(struct net_device *netdev)
{
return DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_IEEE;
}
static u8 xgbe_dcb_setdcbx(struct net_device *netdev, u8 dcbx)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
u8 support = xgbe_dcb_getdcbx(netdev);
netif_dbg(pdata, drv, netdev, "DCBX=%#hhx\n", dcbx);
if (dcbx & ~support)
return 1;
if ((dcbx & support) != support)
return 1;
return 0;
}
const struct dcbnl_rtnl_ops *xgbe_get_dcbnl_ops(void)
{
return &xgbe_dcbnl_ops;
}
