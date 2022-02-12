static int fm10k_dcbnl_ieee_getets(struct net_device *dev, struct ieee_ets *ets)
{
int i;
ets->ets_cap = IEEE_8021QAZ_MAX_TCS;
ets->cbs = 0;
memset(ets->tc_tx_bw, 0, sizeof(ets->tc_tx_bw));
memset(ets->tc_rx_bw, 0, sizeof(ets->tc_rx_bw));
memset(ets->tc_tsa, IEEE_8021QAZ_TSA_STRICT, sizeof(ets->tc_tsa));
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++)
ets->prio_tc[i] = netdev_get_prio_tc_map(dev, i);
return 0;
}
static int fm10k_dcbnl_ieee_setets(struct net_device *dev, struct ieee_ets *ets)
{
u8 num_tc = 0;
int i, err;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
if (ets->tc_tx_bw[i] || ets->tc_rx_bw[i])
return -EINVAL;
if (ets->tc_tsa[i] != IEEE_8021QAZ_TSA_STRICT)
return -EINVAL;
if (ets->prio_tc[i] > num_tc)
num_tc = ets->prio_tc[i];
}
if (num_tc)
num_tc++;
if (num_tc > IEEE_8021QAZ_MAX_TCS)
return -EINVAL;
if (num_tc != netdev_get_num_tc(dev)) {
err = fm10k_setup_tc(dev, num_tc);
if (err)
return err;
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++)
netdev_set_prio_tc_map(dev, i, ets->prio_tc[i]);
return 0;
}
static int fm10k_dcbnl_ieee_getpfc(struct net_device *dev, struct ieee_pfc *pfc)
{
struct fm10k_intfc *interface = netdev_priv(dev);
pfc->pfc_cap = IEEE_8021QAZ_MAX_TCS;
pfc->pfc_en = interface->pfc_en;
return 0;
}
static int fm10k_dcbnl_ieee_setpfc(struct net_device *dev, struct ieee_pfc *pfc)
{
struct fm10k_intfc *interface = netdev_priv(dev);
interface->pfc_en = pfc->pfc_en;
if (netif_running(dev))
fm10k_update_rx_drop_en(interface);
return 0;
}
static u8 fm10k_dcbnl_getdcbx(struct net_device __always_unused *dev)
{
return DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_IEEE;
}
static u8 fm10k_dcbnl_setdcbx(struct net_device __always_unused *dev, u8 mode)
{
return (mode != (DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_IEEE)) ? 1 : 0;
}
void fm10k_dcbnl_set_ops(struct net_device *dev)
{
struct fm10k_intfc *interface = netdev_priv(dev);
struct fm10k_hw *hw = &interface->hw;
if (hw->mac.type == fm10k_mac_pf)
dev->dcbnl_ops = &fm10k_dcbnl_ops;
}
