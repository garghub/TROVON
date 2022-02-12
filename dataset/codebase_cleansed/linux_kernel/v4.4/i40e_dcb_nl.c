static void i40e_get_pfc_delay(struct i40e_hw *hw, u16 *delay)
{
u32 val;
val = rd32(hw, I40E_PRTDCB_GENC);
*delay = (u16)((val & I40E_PRTDCB_GENC_PFCLDA_MASK) >>
I40E_PRTDCB_GENC_PFCLDA_SHIFT);
}
static int i40e_dcbnl_ieee_getets(struct net_device *dev,
struct ieee_ets *ets)
{
struct i40e_pf *pf = i40e_netdev_to_pf(dev);
struct i40e_dcbx_config *dcbxcfg;
struct i40e_hw *hw = &pf->hw;
if (!(pf->dcbx_cap & DCB_CAP_DCBX_VER_IEEE))
return -EINVAL;
dcbxcfg = &hw->local_dcbx_config;
ets->willing = dcbxcfg->etscfg.willing;
ets->ets_cap = dcbxcfg->etscfg.maxtcs;
ets->cbs = dcbxcfg->etscfg.cbs;
memcpy(ets->tc_tx_bw, dcbxcfg->etscfg.tcbwtable,
sizeof(ets->tc_tx_bw));
memcpy(ets->tc_rx_bw, dcbxcfg->etscfg.tcbwtable,
sizeof(ets->tc_rx_bw));
memcpy(ets->tc_tsa, dcbxcfg->etscfg.tsatable,
sizeof(ets->tc_tsa));
memcpy(ets->prio_tc, dcbxcfg->etscfg.prioritytable,
sizeof(ets->prio_tc));
memcpy(ets->tc_reco_bw, dcbxcfg->etsrec.tcbwtable,
sizeof(ets->tc_reco_bw));
memcpy(ets->tc_reco_tsa, dcbxcfg->etsrec.tsatable,
sizeof(ets->tc_reco_tsa));
memcpy(ets->reco_prio_tc, dcbxcfg->etscfg.prioritytable,
sizeof(ets->reco_prio_tc));
return 0;
}
static int i40e_dcbnl_ieee_getpfc(struct net_device *dev,
struct ieee_pfc *pfc)
{
struct i40e_pf *pf = i40e_netdev_to_pf(dev);
struct i40e_dcbx_config *dcbxcfg;
struct i40e_hw *hw = &pf->hw;
int i;
if (!(pf->dcbx_cap & DCB_CAP_DCBX_VER_IEEE))
return -EINVAL;
dcbxcfg = &hw->local_dcbx_config;
pfc->pfc_cap = dcbxcfg->pfc.pfccap;
pfc->pfc_en = dcbxcfg->pfc.pfcenable;
pfc->mbc = dcbxcfg->pfc.mbc;
i40e_get_pfc_delay(hw, &pfc->delay);
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
pfc->requests[i] = pf->stats.priority_xoff_tx[i];
pfc->indications[i] = pf->stats.priority_xoff_rx[i];
}
return 0;
}
static u8 i40e_dcbnl_getdcbx(struct net_device *dev)
{
struct i40e_pf *pf = i40e_netdev_to_pf(dev);
return pf->dcbx_cap;
}
static void i40e_dcbnl_get_perm_hw_addr(struct net_device *dev,
u8 *perm_addr)
{
struct i40e_pf *pf = i40e_netdev_to_pf(dev);
int i, j;
memset(perm_addr, 0xff, MAX_ADDR_LEN);
for (i = 0; i < dev->addr_len; i++)
perm_addr[i] = pf->hw.mac.perm_addr[i];
for (j = 0; j < dev->addr_len; j++, i++)
perm_addr[i] = pf->hw.mac.san_addr[j];
}
void i40e_dcbnl_set_all(struct i40e_vsi *vsi)
{
struct net_device *dev = vsi->netdev;
struct i40e_pf *pf = i40e_netdev_to_pf(dev);
struct i40e_dcbx_config *dcbxcfg;
struct i40e_hw *hw = &pf->hw;
struct dcb_app sapp;
u8 prio, tc_map;
int i;
if (!(pf->flags & I40E_FLAG_DCB_ENABLED))
return;
if ((pf->flags & I40E_FLAG_MFP_ENABLED) && !(pf->hw.func_caps.iscsi))
return;
dcbxcfg = &hw->local_dcbx_config;
for (i = 0; i < dcbxcfg->numapps; i++) {
prio = dcbxcfg->app[i].priority;
tc_map = BIT(dcbxcfg->etscfg.prioritytable[prio]);
if (tc_map & vsi->tc_config.enabled_tc) {
sapp.selector = dcbxcfg->app[i].selector;
sapp.protocol = dcbxcfg->app[i].protocolid;
sapp.priority = prio;
dcb_ieee_setapp(dev, &sapp);
}
}
dcbnl_ieee_notify(dev, RTM_SETDCB, DCB_CMD_IEEE_SET, 0, 0);
}
static int i40e_dcbnl_vsi_del_app(struct i40e_vsi *vsi,
struct i40e_dcb_app_priority_table *app)
{
struct net_device *dev = vsi->netdev;
struct dcb_app sapp;
if (!dev)
return -EINVAL;
sapp.selector = app->selector;
sapp.protocol = app->protocolid;
sapp.priority = app->priority;
return dcb_ieee_delapp(dev, &sapp);
}
static void i40e_dcbnl_del_app(struct i40e_pf *pf,
struct i40e_dcb_app_priority_table *app)
{
int v, err;
for (v = 0; v < pf->num_alloc_vsi; v++) {
if (pf->vsi[v] && pf->vsi[v]->netdev) {
err = i40e_dcbnl_vsi_del_app(pf->vsi[v], app);
dev_dbg(&pf->pdev->dev, "Deleting app for VSI seid=%d err=%d sel=%d proto=0x%x prio=%d\n",
pf->vsi[v]->seid, err, app->selector,
app->protocolid, app->priority);
}
}
}
static bool i40e_dcbnl_find_app(struct i40e_dcbx_config *cfg,
struct i40e_dcb_app_priority_table *app)
{
int i;
for (i = 0; i < cfg->numapps; i++) {
if (app->selector == cfg->app[i].selector &&
app->protocolid == cfg->app[i].protocolid &&
app->priority == cfg->app[i].priority)
return true;
}
return false;
}
void i40e_dcbnl_flush_apps(struct i40e_pf *pf,
struct i40e_dcbx_config *old_cfg,
struct i40e_dcbx_config *new_cfg)
{
struct i40e_dcb_app_priority_table app;
int i;
if ((pf->flags & I40E_FLAG_MFP_ENABLED) && !(pf->hw.func_caps.iscsi))
return;
for (i = 0; i < old_cfg->numapps; i++) {
app = old_cfg->app[i];
if (!i40e_dcbnl_find_app(new_cfg, &app))
i40e_dcbnl_del_app(pf, &app);
}
}
void i40e_dcbnl_setup(struct i40e_vsi *vsi)
{
struct net_device *dev = vsi->netdev;
struct i40e_pf *pf = i40e_netdev_to_pf(dev);
if (!(pf->flags & I40E_FLAG_DCB_CAPABLE))
return;
dev->dcbnl_ops = &dcbnl_ops;
i40e_dcbnl_set_all(vsi);
}
