int ixgbe_copy_dcb_cfg(struct ixgbe_dcb_config *src_dcb_cfg,
struct ixgbe_dcb_config *dst_dcb_cfg, int tc_max)
{
struct tc_configuration *src_tc_cfg = NULL;
struct tc_configuration *dst_tc_cfg = NULL;
int i;
if (!src_dcb_cfg || !dst_dcb_cfg)
return -EINVAL;
for (i = DCB_PG_ATTR_TC_0; i < tc_max + DCB_PG_ATTR_TC_0; i++) {
src_tc_cfg = &src_dcb_cfg->tc_config[i - DCB_PG_ATTR_TC_0];
dst_tc_cfg = &dst_dcb_cfg->tc_config[i - DCB_PG_ATTR_TC_0];
dst_tc_cfg->path[DCB_TX_CONFIG].prio_type =
src_tc_cfg->path[DCB_TX_CONFIG].prio_type;
dst_tc_cfg->path[DCB_TX_CONFIG].bwg_id =
src_tc_cfg->path[DCB_TX_CONFIG].bwg_id;
dst_tc_cfg->path[DCB_TX_CONFIG].bwg_percent =
src_tc_cfg->path[DCB_TX_CONFIG].bwg_percent;
dst_tc_cfg->path[DCB_TX_CONFIG].up_to_tc_bitmap =
src_tc_cfg->path[DCB_TX_CONFIG].up_to_tc_bitmap;
dst_tc_cfg->path[DCB_RX_CONFIG].prio_type =
src_tc_cfg->path[DCB_RX_CONFIG].prio_type;
dst_tc_cfg->path[DCB_RX_CONFIG].bwg_id =
src_tc_cfg->path[DCB_RX_CONFIG].bwg_id;
dst_tc_cfg->path[DCB_RX_CONFIG].bwg_percent =
src_tc_cfg->path[DCB_RX_CONFIG].bwg_percent;
dst_tc_cfg->path[DCB_RX_CONFIG].up_to_tc_bitmap =
src_tc_cfg->path[DCB_RX_CONFIG].up_to_tc_bitmap;
}
for (i = DCB_PG_ATTR_BW_ID_0; i < DCB_PG_ATTR_BW_ID_MAX; i++) {
dst_dcb_cfg->bw_percentage[DCB_TX_CONFIG]
[i-DCB_PG_ATTR_BW_ID_0] = src_dcb_cfg->bw_percentage
[DCB_TX_CONFIG][i-DCB_PG_ATTR_BW_ID_0];
dst_dcb_cfg->bw_percentage[DCB_RX_CONFIG]
[i-DCB_PG_ATTR_BW_ID_0] = src_dcb_cfg->bw_percentage
[DCB_RX_CONFIG][i-DCB_PG_ATTR_BW_ID_0];
}
for (i = DCB_PFC_UP_ATTR_0; i < DCB_PFC_UP_ATTR_MAX; i++) {
dst_dcb_cfg->tc_config[i - DCB_PFC_UP_ATTR_0].dcb_pfc =
src_dcb_cfg->tc_config[i - DCB_PFC_UP_ATTR_0].dcb_pfc;
}
dst_dcb_cfg->pfc_mode_enable = src_dcb_cfg->pfc_mode_enable;
return 0;
}
static u8 ixgbe_dcbnl_get_state(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
return !!(adapter->flags & IXGBE_FLAG_DCB_ENABLED);
}
static u8 ixgbe_dcbnl_set_state(struct net_device *netdev, u8 state)
{
u8 err = 0;
u8 prio_tc[MAX_USER_PRIORITY] = {0};
int i;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (!(adapter->dcbx_cap & DCB_CAP_DCBX_VER_CEE))
return 1;
if (!!state != !(adapter->flags & IXGBE_FLAG_DCB_ENABLED))
return err;
if (state > 0) {
err = ixgbe_setup_tc(netdev, adapter->dcb_cfg.num_tcs.pg_tcs);
ixgbe_dcb_unpack_map(&adapter->dcb_cfg, DCB_TX_CONFIG, prio_tc);
} else {
err = ixgbe_setup_tc(netdev, 0);
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++)
netdev_set_prio_tc_map(netdev, i, prio_tc[i]);
return err;
}
static void ixgbe_dcbnl_get_perm_hw_addr(struct net_device *netdev,
u8 *perm_addr)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int i, j;
memset(perm_addr, 0xff, MAX_ADDR_LEN);
for (i = 0; i < netdev->addr_len; i++)
perm_addr[i] = adapter->hw.mac.perm_addr[i];
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
for (j = 0; j < netdev->addr_len; j++, i++)
perm_addr[i] = adapter->hw.mac.san_addr[j];
break;
default:
break;
}
}
static void ixgbe_dcbnl_set_pg_tc_cfg_tx(struct net_device *netdev, int tc,
u8 prio, u8 bwg_id, u8 bw_pct,
u8 up_map)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (prio != DCB_ATTR_VALUE_UNDEFINED)
adapter->temp_dcb_cfg.tc_config[tc].path[0].prio_type = prio;
if (bwg_id != DCB_ATTR_VALUE_UNDEFINED)
adapter->temp_dcb_cfg.tc_config[tc].path[0].bwg_id = bwg_id;
if (bw_pct != DCB_ATTR_VALUE_UNDEFINED)
adapter->temp_dcb_cfg.tc_config[tc].path[0].bwg_percent =
bw_pct;
if (up_map != DCB_ATTR_VALUE_UNDEFINED)
adapter->temp_dcb_cfg.tc_config[tc].path[0].up_to_tc_bitmap =
up_map;
if ((adapter->temp_dcb_cfg.tc_config[tc].path[0].prio_type !=
adapter->dcb_cfg.tc_config[tc].path[0].prio_type) ||
(adapter->temp_dcb_cfg.tc_config[tc].path[0].bwg_id !=
adapter->dcb_cfg.tc_config[tc].path[0].bwg_id) ||
(adapter->temp_dcb_cfg.tc_config[tc].path[0].bwg_percent !=
adapter->dcb_cfg.tc_config[tc].path[0].bwg_percent) ||
(adapter->temp_dcb_cfg.tc_config[tc].path[0].up_to_tc_bitmap !=
adapter->dcb_cfg.tc_config[tc].path[0].up_to_tc_bitmap))
adapter->dcb_set_bitmap |= BIT_PG_TX;
if (adapter->temp_dcb_cfg.tc_config[tc].path[0].up_to_tc_bitmap !=
adapter->dcb_cfg.tc_config[tc].path[0].up_to_tc_bitmap)
adapter->dcb_set_bitmap |= BIT_PFC | BIT_APP_UPCHG;
}
static void ixgbe_dcbnl_set_pg_bwg_cfg_tx(struct net_device *netdev, int bwg_id,
u8 bw_pct)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
adapter->temp_dcb_cfg.bw_percentage[0][bwg_id] = bw_pct;
if (adapter->temp_dcb_cfg.bw_percentage[0][bwg_id] !=
adapter->dcb_cfg.bw_percentage[0][bwg_id])
adapter->dcb_set_bitmap |= BIT_PG_TX;
}
static void ixgbe_dcbnl_set_pg_tc_cfg_rx(struct net_device *netdev, int tc,
u8 prio, u8 bwg_id, u8 bw_pct,
u8 up_map)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (prio != DCB_ATTR_VALUE_UNDEFINED)
adapter->temp_dcb_cfg.tc_config[tc].path[1].prio_type = prio;
if (bwg_id != DCB_ATTR_VALUE_UNDEFINED)
adapter->temp_dcb_cfg.tc_config[tc].path[1].bwg_id = bwg_id;
if (bw_pct != DCB_ATTR_VALUE_UNDEFINED)
adapter->temp_dcb_cfg.tc_config[tc].path[1].bwg_percent =
bw_pct;
if (up_map != DCB_ATTR_VALUE_UNDEFINED)
adapter->temp_dcb_cfg.tc_config[tc].path[1].up_to_tc_bitmap =
up_map;
if ((adapter->temp_dcb_cfg.tc_config[tc].path[1].prio_type !=
adapter->dcb_cfg.tc_config[tc].path[1].prio_type) ||
(adapter->temp_dcb_cfg.tc_config[tc].path[1].bwg_id !=
adapter->dcb_cfg.tc_config[tc].path[1].bwg_id) ||
(adapter->temp_dcb_cfg.tc_config[tc].path[1].bwg_percent !=
adapter->dcb_cfg.tc_config[tc].path[1].bwg_percent) ||
(adapter->temp_dcb_cfg.tc_config[tc].path[1].up_to_tc_bitmap !=
adapter->dcb_cfg.tc_config[tc].path[1].up_to_tc_bitmap))
adapter->dcb_set_bitmap |= BIT_PG_RX;
if (adapter->temp_dcb_cfg.tc_config[tc].path[1].up_to_tc_bitmap !=
adapter->dcb_cfg.tc_config[tc].path[1].up_to_tc_bitmap)
adapter->dcb_set_bitmap |= BIT_PFC;
}
static void ixgbe_dcbnl_set_pg_bwg_cfg_rx(struct net_device *netdev, int bwg_id,
u8 bw_pct)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
adapter->temp_dcb_cfg.bw_percentage[1][bwg_id] = bw_pct;
if (adapter->temp_dcb_cfg.bw_percentage[1][bwg_id] !=
adapter->dcb_cfg.bw_percentage[1][bwg_id])
adapter->dcb_set_bitmap |= BIT_PG_RX;
}
static void ixgbe_dcbnl_get_pg_tc_cfg_tx(struct net_device *netdev, int tc,
u8 *prio, u8 *bwg_id, u8 *bw_pct,
u8 *up_map)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
*prio = adapter->dcb_cfg.tc_config[tc].path[0].prio_type;
*bwg_id = adapter->dcb_cfg.tc_config[tc].path[0].bwg_id;
*bw_pct = adapter->dcb_cfg.tc_config[tc].path[0].bwg_percent;
*up_map = adapter->dcb_cfg.tc_config[tc].path[0].up_to_tc_bitmap;
}
static void ixgbe_dcbnl_get_pg_bwg_cfg_tx(struct net_device *netdev, int bwg_id,
u8 *bw_pct)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
*bw_pct = adapter->dcb_cfg.bw_percentage[0][bwg_id];
}
static void ixgbe_dcbnl_get_pg_tc_cfg_rx(struct net_device *netdev, int tc,
u8 *prio, u8 *bwg_id, u8 *bw_pct,
u8 *up_map)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
*prio = adapter->dcb_cfg.tc_config[tc].path[1].prio_type;
*bwg_id = adapter->dcb_cfg.tc_config[tc].path[1].bwg_id;
*bw_pct = adapter->dcb_cfg.tc_config[tc].path[1].bwg_percent;
*up_map = adapter->dcb_cfg.tc_config[tc].path[1].up_to_tc_bitmap;
}
static void ixgbe_dcbnl_get_pg_bwg_cfg_rx(struct net_device *netdev, int bwg_id,
u8 *bw_pct)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
*bw_pct = adapter->dcb_cfg.bw_percentage[1][bwg_id];
}
static void ixgbe_dcbnl_set_pfc_cfg(struct net_device *netdev, int priority,
u8 setting)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
adapter->temp_dcb_cfg.tc_config[priority].dcb_pfc = setting;
if (adapter->temp_dcb_cfg.tc_config[priority].dcb_pfc !=
adapter->dcb_cfg.tc_config[priority].dcb_pfc) {
adapter->dcb_set_bitmap |= BIT_PFC;
adapter->temp_dcb_cfg.pfc_mode_enable = true;
}
}
static void ixgbe_dcbnl_get_pfc_cfg(struct net_device *netdev, int priority,
u8 *setting)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
*setting = adapter->dcb_cfg.tc_config[priority].dcb_pfc;
}
static void ixgbe_dcbnl_devreset(struct net_device *dev)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
while (test_and_set_bit(__IXGBE_RESETTING, &adapter->state))
usleep_range(1000, 2000);
if (netif_running(dev))
dev->netdev_ops->ndo_stop(dev);
ixgbe_clear_interrupt_scheme(adapter);
ixgbe_init_interrupt_scheme(adapter);
if (netif_running(dev))
dev->netdev_ops->ndo_open(dev);
clear_bit(__IXGBE_RESETTING, &adapter->state);
}
static u8 ixgbe_dcbnl_set_all(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int ret, i;
#ifdef IXGBE_FCOE
struct dcb_app app = {
.selector = DCB_APP_IDTYPE_ETHTYPE,
.protocol = ETH_P_FCOE,
};
u8 up;
if (adapter->dcbx_cap & DCB_CAP_DCBX_VER_IEEE) {
app.selector = IEEE_8021QAZ_APP_SEL_ETHERTYPE;
up = dcb_ieee_getapp_mask(netdev, &app);
} else {
up = dcb_getapp(netdev, &app);
}
#endif
if (!(adapter->dcbx_cap & DCB_CAP_DCBX_VER_CEE))
return 1;
ret = ixgbe_copy_dcb_cfg(&adapter->temp_dcb_cfg, &adapter->dcb_cfg,
MAX_TRAFFIC_CLASS);
if (ret)
return DCB_NO_HW_CHG;
if (adapter->dcb_cfg.pfc_mode_enable) {
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
if (adapter->hw.fc.current_mode != ixgbe_fc_pfc)
adapter->last_lfc_mode =
adapter->hw.fc.current_mode;
break;
default:
break;
}
adapter->hw.fc.requested_mode = ixgbe_fc_pfc;
} else {
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB:
adapter->hw.fc.requested_mode = ixgbe_fc_none;
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
adapter->hw.fc.requested_mode = adapter->last_lfc_mode;
break;
default:
break;
}
}
if (adapter->dcb_set_bitmap & (BIT_PG_TX|BIT_PG_RX)) {
u16 refill[MAX_TRAFFIC_CLASS], max[MAX_TRAFFIC_CLASS];
u8 bwg_id[MAX_TRAFFIC_CLASS], prio_type[MAX_TRAFFIC_CLASS];
u8 prio_tc[MAX_USER_PRIORITY];
int max_frame = adapter->netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
#ifdef IXGBE_FCOE
if (adapter->netdev->features & NETIF_F_FCOE_MTU)
max_frame = max(max_frame, IXGBE_FCOE_JUMBO_FRAME_SIZE);
#endif
ixgbe_dcb_calculate_tc_credits(&adapter->hw, &adapter->dcb_cfg,
max_frame, DCB_TX_CONFIG);
ixgbe_dcb_calculate_tc_credits(&adapter->hw, &adapter->dcb_cfg,
max_frame, DCB_RX_CONFIG);
ixgbe_dcb_unpack_refill(&adapter->dcb_cfg,
DCB_TX_CONFIG, refill);
ixgbe_dcb_unpack_max(&adapter->dcb_cfg, max);
ixgbe_dcb_unpack_bwgid(&adapter->dcb_cfg,
DCB_TX_CONFIG, bwg_id);
ixgbe_dcb_unpack_prio(&adapter->dcb_cfg,
DCB_TX_CONFIG, prio_type);
ixgbe_dcb_unpack_map(&adapter->dcb_cfg,
DCB_TX_CONFIG, prio_tc);
ixgbe_dcb_hw_ets_config(&adapter->hw, refill, max,
bwg_id, prio_type, prio_tc);
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++)
netdev_set_prio_tc_map(netdev, i, prio_tc[i]);
}
if (adapter->dcb_set_bitmap & BIT_PFC) {
u8 pfc_en;
u8 prio_tc[MAX_USER_PRIORITY];
ixgbe_dcb_unpack_map(&adapter->dcb_cfg,
DCB_TX_CONFIG, prio_tc);
ixgbe_dcb_unpack_pfc(&adapter->dcb_cfg, &pfc_en);
ixgbe_dcb_hw_pfc_config(&adapter->hw, pfc_en, prio_tc);
ret = DCB_HW_CHG;
}
if (adapter->dcb_cfg.pfc_mode_enable)
adapter->hw.fc.current_mode = ixgbe_fc_pfc;
#ifdef IXGBE_FCOE
if ((up && !(up & (1 << adapter->fcoe.up))) ||
(adapter->dcb_set_bitmap & BIT_APP_UPCHG)) {
adapter->fcoe.up = ffs(up) - 1;
ixgbe_dcbnl_devreset(netdev);
ret = DCB_HW_CHG_RST;
}
#endif
adapter->dcb_set_bitmap = 0x00;
return ret;
}
static u8 ixgbe_dcbnl_getcap(struct net_device *netdev, int capid, u8 *cap)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
switch (capid) {
case DCB_CAP_ATTR_PG:
*cap = true;
break;
case DCB_CAP_ATTR_PFC:
*cap = true;
break;
case DCB_CAP_ATTR_UP2TC:
*cap = false;
break;
case DCB_CAP_ATTR_PG_TCS:
*cap = 0x80;
break;
case DCB_CAP_ATTR_PFC_TCS:
*cap = 0x80;
break;
case DCB_CAP_ATTR_GSP:
*cap = true;
break;
case DCB_CAP_ATTR_BCN:
*cap = false;
break;
case DCB_CAP_ATTR_DCBX:
*cap = adapter->dcbx_cap;
break;
default:
*cap = false;
break;
}
return 0;
}
static u8 ixgbe_dcbnl_getnumtcs(struct net_device *netdev, int tcid, u8 *num)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
u8 rval = 0;
if (adapter->flags & IXGBE_FLAG_DCB_ENABLED) {
switch (tcid) {
case DCB_NUMTCS_ATTR_PG:
*num = adapter->dcb_cfg.num_tcs.pg_tcs;
break;
case DCB_NUMTCS_ATTR_PFC:
*num = adapter->dcb_cfg.num_tcs.pfc_tcs;
break;
default:
rval = -EINVAL;
break;
}
} else {
rval = -EINVAL;
}
return rval;
}
static u8 ixgbe_dcbnl_setnumtcs(struct net_device *netdev, int tcid, u8 num)
{
return -EINVAL;
}
static u8 ixgbe_dcbnl_getpfcstate(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
return adapter->dcb_cfg.pfc_mode_enable;
}
static void ixgbe_dcbnl_setpfcstate(struct net_device *netdev, u8 state)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
adapter->temp_dcb_cfg.pfc_mode_enable = state;
if (adapter->temp_dcb_cfg.pfc_mode_enable !=
adapter->dcb_cfg.pfc_mode_enable)
adapter->dcb_set_bitmap |= BIT_PFC;
}
static u8 ixgbe_dcbnl_getapp(struct net_device *netdev, u8 idtype, u16 id)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct dcb_app app = {
.selector = idtype,
.protocol = id,
};
if (!(adapter->dcbx_cap & DCB_CAP_DCBX_VER_CEE))
return 0;
return dcb_getapp(netdev, &app);
}
static int ixgbe_dcbnl_ieee_getets(struct net_device *dev,
struct ieee_ets *ets)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ieee_ets *my_ets = adapter->ixgbe_ieee_ets;
ets->ets_cap = adapter->dcb_cfg.num_tcs.pg_tcs;
if (!my_ets)
return 0;
ets->cbs = my_ets->cbs;
memcpy(ets->tc_tx_bw, my_ets->tc_tx_bw, sizeof(ets->tc_tx_bw));
memcpy(ets->tc_rx_bw, my_ets->tc_rx_bw, sizeof(ets->tc_rx_bw));
memcpy(ets->tc_tsa, my_ets->tc_tsa, sizeof(ets->tc_tsa));
memcpy(ets->prio_tc, my_ets->prio_tc, sizeof(ets->prio_tc));
return 0;
}
static int ixgbe_dcbnl_ieee_setets(struct net_device *dev,
struct ieee_ets *ets)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
int max_frame = dev->mtu + ETH_HLEN + ETH_FCS_LEN;
int i;
__u8 max_tc = 0;
if (!(adapter->dcbx_cap & DCB_CAP_DCBX_VER_IEEE))
return -EINVAL;
if (!adapter->ixgbe_ieee_ets) {
adapter->ixgbe_ieee_ets = kmalloc(sizeof(struct ieee_ets),
GFP_KERNEL);
if (!adapter->ixgbe_ieee_ets)
return -ENOMEM;
}
memcpy(adapter->ixgbe_ieee_ets, ets, sizeof(*adapter->ixgbe_ieee_ets));
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
if (ets->prio_tc[i] > max_tc)
max_tc = ets->prio_tc[i];
}
if (max_tc)
max_tc++;
if (max_tc > adapter->dcb_cfg.num_tcs.pg_tcs)
return -EINVAL;
if (max_tc != netdev_get_num_tc(dev))
ixgbe_setup_tc(dev, max_tc);
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++)
netdev_set_prio_tc_map(dev, i, ets->prio_tc[i]);
return ixgbe_dcb_hw_ets(&adapter->hw, ets, max_frame);
}
static int ixgbe_dcbnl_ieee_getpfc(struct net_device *dev,
struct ieee_pfc *pfc)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ieee_pfc *my_pfc = adapter->ixgbe_ieee_pfc;
int i;
pfc->pfc_cap = adapter->dcb_cfg.num_tcs.pfc_tcs;
if (!my_pfc)
return 0;
pfc->pfc_en = my_pfc->pfc_en;
pfc->mbc = my_pfc->mbc;
pfc->delay = my_pfc->delay;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
pfc->requests[i] = adapter->stats.pxoffrxc[i];
pfc->indications[i] = adapter->stats.pxofftxc[i];
}
return 0;
}
static int ixgbe_dcbnl_ieee_setpfc(struct net_device *dev,
struct ieee_pfc *pfc)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
u8 *prio_tc;
if (!(adapter->dcbx_cap & DCB_CAP_DCBX_VER_IEEE))
return -EINVAL;
if (!adapter->ixgbe_ieee_pfc) {
adapter->ixgbe_ieee_pfc = kmalloc(sizeof(struct ieee_pfc),
GFP_KERNEL);
if (!adapter->ixgbe_ieee_pfc)
return -ENOMEM;
}
prio_tc = adapter->ixgbe_ieee_ets->prio_tc;
memcpy(adapter->ixgbe_ieee_pfc, pfc, sizeof(*adapter->ixgbe_ieee_pfc));
return ixgbe_dcb_hw_pfc_config(&adapter->hw, pfc->pfc_en, prio_tc);
}
static int ixgbe_dcbnl_ieee_setapp(struct net_device *dev,
struct dcb_app *app)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
int err = -EINVAL;
if (!(adapter->dcbx_cap & DCB_CAP_DCBX_VER_IEEE))
return err;
err = dcb_ieee_setapp(dev, app);
#ifdef IXGBE_FCOE
if (!err && app->selector == IEEE_8021QAZ_APP_SEL_ETHERTYPE &&
app->protocol == ETH_P_FCOE) {
u8 app_mask = dcb_ieee_getapp_mask(dev, app);
if (app_mask & (1 << adapter->fcoe.up))
return err;
adapter->fcoe.up = app->priority;
ixgbe_dcbnl_devreset(dev);
}
#endif
return 0;
}
static int ixgbe_dcbnl_ieee_delapp(struct net_device *dev,
struct dcb_app *app)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
int err;
if (!(adapter->dcbx_cap & DCB_CAP_DCBX_VER_IEEE))
return -EINVAL;
err = dcb_ieee_delapp(dev, app);
#ifdef IXGBE_FCOE
if (!err && app->selector == IEEE_8021QAZ_APP_SEL_ETHERTYPE &&
app->protocol == ETH_P_FCOE) {
u8 app_mask = dcb_ieee_getapp_mask(dev, app);
if (app_mask & (1 << adapter->fcoe.up))
return err;
adapter->fcoe.up = app_mask ?
ffs(app_mask) - 1 : IXGBE_FCOE_DEFTC;
ixgbe_dcbnl_devreset(dev);
}
#endif
return err;
}
static u8 ixgbe_dcbnl_getdcbx(struct net_device *dev)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
return adapter->dcbx_cap;
}
static u8 ixgbe_dcbnl_setdcbx(struct net_device *dev, u8 mode)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ieee_ets ets = {0};
struct ieee_pfc pfc = {0};
if ((mode & DCB_CAP_DCBX_LLD_MANAGED) ||
((mode & DCB_CAP_DCBX_VER_IEEE) && (mode & DCB_CAP_DCBX_VER_CEE)) ||
!(mode & DCB_CAP_DCBX_HOST))
return 1;
if (mode == adapter->dcbx_cap)
return 0;
adapter->dcbx_cap = mode;
ets.ets_cap = 8;
pfc.pfc_cap = 8;
if (mode & DCB_CAP_DCBX_VER_IEEE) {
ixgbe_dcbnl_ieee_setets(dev, &ets);
ixgbe_dcbnl_ieee_setpfc(dev, &pfc);
} else if (mode & DCB_CAP_DCBX_VER_CEE) {
u8 mask = BIT_PFC | BIT_PG_TX | BIT_PG_RX | BIT_APP_UPCHG;
adapter->dcb_set_bitmap |= mask;
ixgbe_dcbnl_set_all(dev);
} else {
ixgbe_dcbnl_ieee_setets(dev, &ets);
ixgbe_dcbnl_ieee_setpfc(dev, &pfc);
ixgbe_setup_tc(dev, 0);
}
return 0;
}
