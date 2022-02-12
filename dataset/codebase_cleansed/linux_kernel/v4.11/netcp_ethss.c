static void keystone_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
strncpy(info->driver, NETCP_DRIVER_NAME, sizeof(info->driver));
strncpy(info->version, NETCP_DRIVER_VERSION, sizeof(info->version));
}
static u32 keystone_get_msglevel(struct net_device *ndev)
{
struct netcp_intf *netcp = netdev_priv(ndev);
return netcp->msg_enable;
}
static void keystone_set_msglevel(struct net_device *ndev, u32 value)
{
struct netcp_intf *netcp = netdev_priv(ndev);
netcp->msg_enable = value;
}
static struct gbe_intf *keystone_get_intf_data(struct netcp_intf *netcp)
{
struct gbe_intf *gbe_intf;
gbe_intf = netcp_module_get_intf_data(&gbe_module, netcp);
if (!gbe_intf)
gbe_intf = netcp_module_get_intf_data(&xgbe_module, netcp);
return gbe_intf;
}
static void keystone_get_stat_strings(struct net_device *ndev,
uint32_t stringset, uint8_t *data)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_intf *gbe_intf;
struct gbe_priv *gbe_dev;
int i;
gbe_intf = keystone_get_intf_data(netcp);
if (!gbe_intf)
return;
gbe_dev = gbe_intf->gbe_dev;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < gbe_dev->num_et_stats; i++) {
memcpy(data, gbe_dev->et_stats[i].desc,
ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
break;
case ETH_SS_TEST:
break;
}
}
static int keystone_get_sset_count(struct net_device *ndev, int stringset)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_intf *gbe_intf;
struct gbe_priv *gbe_dev;
gbe_intf = keystone_get_intf_data(netcp);
if (!gbe_intf)
return -EINVAL;
gbe_dev = gbe_intf->gbe_dev;
switch (stringset) {
case ETH_SS_TEST:
return 0;
case ETH_SS_STATS:
return gbe_dev->num_et_stats;
default:
return -EINVAL;
}
}
static void gbe_reset_mod_stats(struct gbe_priv *gbe_dev, int stats_mod)
{
void __iomem *base = gbe_dev->hw_stats_regs[stats_mod];
u32 __iomem *p_stats_entry;
int i;
for (i = 0; i < gbe_dev->num_et_stats; i++) {
if (gbe_dev->et_stats[i].type == stats_mod) {
p_stats_entry = base + gbe_dev->et_stats[i].offset;
gbe_dev->hw_stats[i] = 0;
gbe_dev->hw_stats_prev[i] = readl(p_stats_entry);
}
}
}
static inline void gbe_update_hw_stats_entry(struct gbe_priv *gbe_dev,
int et_stats_entry)
{
void __iomem *base = NULL;
u32 __iomem *p_stats_entry;
u32 curr, delta;
base = gbe_dev->hw_stats_regs[gbe_dev->et_stats[et_stats_entry].type];
p_stats_entry = base + gbe_dev->et_stats[et_stats_entry].offset;
curr = readl(p_stats_entry);
delta = curr - gbe_dev->hw_stats_prev[et_stats_entry];
gbe_dev->hw_stats_prev[et_stats_entry] = curr;
gbe_dev->hw_stats[et_stats_entry] += delta;
}
static void gbe_update_stats(struct gbe_priv *gbe_dev, uint64_t *data)
{
int i;
for (i = 0; i < gbe_dev->num_et_stats; i++) {
gbe_update_hw_stats_entry(gbe_dev, i);
if (data)
data[i] = gbe_dev->hw_stats[i];
}
}
static inline void gbe_stats_mod_visible_ver14(struct gbe_priv *gbe_dev,
int stats_mod)
{
u32 val;
val = readl(GBE_REG_ADDR(gbe_dev, switch_regs, stat_port_en));
switch (stats_mod) {
case GBE_STATSA_MODULE:
case GBE_STATSB_MODULE:
val &= ~GBE_STATS_CD_SEL;
break;
case GBE_STATSC_MODULE:
case GBE_STATSD_MODULE:
val |= GBE_STATS_CD_SEL;
break;
default:
return;
}
writel(val, GBE_REG_ADDR(gbe_dev, switch_regs, stat_port_en));
}
static void gbe_reset_mod_stats_ver14(struct gbe_priv *gbe_dev, int stats_mod)
{
gbe_stats_mod_visible_ver14(gbe_dev, stats_mod);
gbe_reset_mod_stats(gbe_dev, stats_mod);
}
static void gbe_update_stats_ver14(struct gbe_priv *gbe_dev, uint64_t *data)
{
u32 half_num_et_stats = (gbe_dev->num_et_stats / 2);
int et_entry, j, pair;
for (pair = 0; pair < 2; pair++) {
gbe_stats_mod_visible_ver14(gbe_dev, (pair ?
GBE_STATSC_MODULE :
GBE_STATSA_MODULE));
for (j = 0; j < half_num_et_stats; j++) {
et_entry = pair * half_num_et_stats + j;
gbe_update_hw_stats_entry(gbe_dev, et_entry);
if (data)
data[et_entry] = gbe_dev->hw_stats[et_entry];
}
}
}
static void keystone_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *stats,
uint64_t *data)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_intf *gbe_intf;
struct gbe_priv *gbe_dev;
gbe_intf = keystone_get_intf_data(netcp);
if (!gbe_intf)
return;
gbe_dev = gbe_intf->gbe_dev;
spin_lock_bh(&gbe_dev->hw_stats_lock);
if (gbe_dev->ss_version == GBE_SS_VERSION_14)
gbe_update_stats_ver14(gbe_dev, data);
else
gbe_update_stats(gbe_dev, data);
spin_unlock_bh(&gbe_dev->hw_stats_lock);
}
static int keystone_get_link_ksettings(struct net_device *ndev,
struct ethtool_link_ksettings *cmd)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct phy_device *phy = ndev->phydev;
struct gbe_intf *gbe_intf;
int ret;
if (!phy)
return -EINVAL;
gbe_intf = keystone_get_intf_data(netcp);
if (!gbe_intf)
return -EINVAL;
if (!gbe_intf->slave)
return -EINVAL;
ret = phy_ethtool_ksettings_get(phy, cmd);
if (!ret)
cmd->base.port = gbe_intf->slave->phy_port_t;
return ret;
}
static int keystone_set_link_ksettings(struct net_device *ndev,
const struct ethtool_link_ksettings *cmd)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct phy_device *phy = ndev->phydev;
struct gbe_intf *gbe_intf;
u8 port = cmd->base.port;
u32 advertising, supported;
u32 features;
ethtool_convert_link_mode_to_legacy_u32(&advertising,
cmd->link_modes.advertising);
ethtool_convert_link_mode_to_legacy_u32(&supported,
cmd->link_modes.supported);
features = advertising & supported;
if (!phy)
return -EINVAL;
gbe_intf = keystone_get_intf_data(netcp);
if (!gbe_intf)
return -EINVAL;
if (!gbe_intf->slave)
return -EINVAL;
if (port != gbe_intf->slave->phy_port_t) {
if ((port == PORT_TP) && !(features & ADVERTISED_TP))
return -EINVAL;
if ((port == PORT_AUI) && !(features & ADVERTISED_AUI))
return -EINVAL;
if ((port == PORT_BNC) && !(features & ADVERTISED_BNC))
return -EINVAL;
if ((port == PORT_MII) && !(features & ADVERTISED_MII))
return -EINVAL;
if ((port == PORT_FIBRE) && !(features & ADVERTISED_FIBRE))
return -EINVAL;
}
gbe_intf->slave->phy_port_t = port;
return phy_ethtool_ksettings_set(phy, cmd);
}
static int keystone_get_ts_info(struct net_device *ndev,
struct ethtool_ts_info *info)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_intf *gbe_intf;
gbe_intf = netcp_module_get_intf_data(&gbe_module, netcp);
if (!gbe_intf || !gbe_intf->gbe_dev->cpts)
return -EINVAL;
info->so_timestamping =
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
info->phc_index = gbe_intf->gbe_dev->cpts->phc_index;
info->tx_types =
(1 << HWTSTAMP_TX_OFF) |
(1 << HWTSTAMP_TX_ON);
info->rx_filters =
(1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_EVENT);
return 0;
}
static int keystone_get_ts_info(struct net_device *ndev,
struct ethtool_ts_info *info)
{
info->so_timestamping =
SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE;
info->phc_index = -1;
info->tx_types = 0;
info->rx_filters = 0;
return 0;
}
static void gbe_set_slave_mac(struct gbe_slave *slave,
struct gbe_intf *gbe_intf)
{
struct net_device *ndev = gbe_intf->ndev;
writel(mac_hi(ndev->dev_addr), GBE_REG_ADDR(slave, port_regs, sa_hi));
writel(mac_lo(ndev->dev_addr), GBE_REG_ADDR(slave, port_regs, sa_lo));
}
static int gbe_get_slave_port(struct gbe_priv *priv, u32 slave_num)
{
if (priv->host_port == 0)
return slave_num + 1;
return slave_num;
}
static void netcp_ethss_link_state_action(struct gbe_priv *gbe_dev,
struct net_device *ndev,
struct gbe_slave *slave,
int up)
{
struct phy_device *phy = slave->phy;
u32 mac_control = 0;
if (up) {
mac_control = slave->mac_control;
if (phy && (phy->speed == SPEED_1000)) {
mac_control |= MACSL_GIG_MODE;
mac_control &= ~MACSL_XGIG_MODE;
} else if (phy && (phy->speed == SPEED_10000)) {
mac_control |= MACSL_XGIG_MODE;
mac_control &= ~MACSL_GIG_MODE;
}
writel(mac_control, GBE_REG_ADDR(slave, emac_regs,
mac_control));
cpsw_ale_control_set(gbe_dev->ale, slave->port_num,
ALE_PORT_STATE,
ALE_PORT_STATE_FORWARD);
if (ndev && slave->open &&
slave->link_interface != SGMII_LINK_MAC_PHY &&
slave->link_interface != XGMII_LINK_MAC_PHY)
netif_carrier_on(ndev);
} else {
writel(mac_control, GBE_REG_ADDR(slave, emac_regs,
mac_control));
cpsw_ale_control_set(gbe_dev->ale, slave->port_num,
ALE_PORT_STATE,
ALE_PORT_STATE_DISABLE);
if (ndev &&
slave->link_interface != SGMII_LINK_MAC_PHY &&
slave->link_interface != XGMII_LINK_MAC_PHY)
netif_carrier_off(ndev);
}
if (phy)
phy_print_status(phy);
}
static bool gbe_phy_link_status(struct gbe_slave *slave)
{
return !slave->phy || slave->phy->link;
}
static void netcp_ethss_update_link_state(struct gbe_priv *gbe_dev,
struct gbe_slave *slave,
struct net_device *ndev)
{
int sp = slave->slave_num;
int phy_link_state, sgmii_link_state = 1, link_state;
if (!slave->open)
return;
if (!SLAVE_LINK_IS_XGMII(slave)) {
sgmii_link_state =
netcp_sgmii_get_port_link(SGMII_BASE(gbe_dev, sp), sp);
}
phy_link_state = gbe_phy_link_status(slave);
link_state = phy_link_state & sgmii_link_state;
if (atomic_xchg(&slave->link_state, link_state) != link_state)
netcp_ethss_link_state_action(gbe_dev, ndev, slave,
link_state);
}
static void xgbe_adjust_link(struct net_device *ndev)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_intf *gbe_intf;
gbe_intf = netcp_module_get_intf_data(&xgbe_module, netcp);
if (!gbe_intf)
return;
netcp_ethss_update_link_state(gbe_intf->gbe_dev, gbe_intf->slave,
ndev);
}
static void gbe_adjust_link(struct net_device *ndev)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_intf *gbe_intf;
gbe_intf = netcp_module_get_intf_data(&gbe_module, netcp);
if (!gbe_intf)
return;
netcp_ethss_update_link_state(gbe_intf->gbe_dev, gbe_intf->slave,
ndev);
}
static void gbe_adjust_link_sec_slaves(struct net_device *ndev)
{
struct gbe_priv *gbe_dev = netdev_priv(ndev);
struct gbe_slave *slave;
for_each_sec_slave(slave, gbe_dev)
netcp_ethss_update_link_state(gbe_dev, slave, NULL);
}
static int gbe_port_reset(struct gbe_slave *slave)
{
u32 i, v;
writel(SOFT_RESET, GBE_REG_ADDR(slave, emac_regs, soft_reset));
for (i = 0; i < DEVICE_EMACSL_RESET_POLL_COUNT; i++) {
v = readl(GBE_REG_ADDR(slave, emac_regs, soft_reset));
if ((v & SOFT_RESET_MASK) != SOFT_RESET)
return 0;
}
return GMACSL_RET_WARN_RESET_INCOMPLETE;
}
static void gbe_port_config(struct gbe_priv *gbe_dev, struct gbe_slave *slave,
int max_rx_len)
{
void __iomem *rx_maxlen_reg;
u32 xgmii_mode;
if (max_rx_len > NETCP_MAX_FRAME_SIZE)
max_rx_len = NETCP_MAX_FRAME_SIZE;
if ((gbe_dev->ss_version == XGBE_SS_VERSION_10) &&
(slave->link_interface >= XGMII_LINK_MAC_PHY)) {
xgmii_mode = readl(GBE_REG_ADDR(gbe_dev, ss_regs, control));
xgmii_mode |= (1 << slave->slave_num);
writel(xgmii_mode, GBE_REG_ADDR(gbe_dev, ss_regs, control));
}
if (IS_SS_ID_MU(gbe_dev))
rx_maxlen_reg = GBE_REG_ADDR(slave, port_regs, rx_maxlen);
else
rx_maxlen_reg = GBE_REG_ADDR(slave, emac_regs, rx_maxlen);
writel(max_rx_len, rx_maxlen_reg);
writel(slave->mac_control, GBE_REG_ADDR(slave, emac_regs, mac_control));
}
static void gbe_sgmii_rtreset(struct gbe_priv *priv,
struct gbe_slave *slave, bool set)
{
if (SLAVE_LINK_IS_XGMII(slave))
return;
netcp_sgmii_rtreset(SGMII_BASE(priv, slave->slave_num),
slave->slave_num, set);
}
static void gbe_slave_stop(struct gbe_intf *intf)
{
struct gbe_priv *gbe_dev = intf->gbe_dev;
struct gbe_slave *slave = intf->slave;
gbe_sgmii_rtreset(gbe_dev, slave, true);
gbe_port_reset(slave);
cpsw_ale_control_set(gbe_dev->ale, slave->port_num,
ALE_PORT_STATE, ALE_PORT_STATE_DISABLE);
cpsw_ale_del_mcast(gbe_dev->ale, intf->ndev->broadcast,
1 << slave->port_num, 0, 0);
if (!slave->phy)
return;
phy_stop(slave->phy);
phy_disconnect(slave->phy);
slave->phy = NULL;
}
static void gbe_sgmii_config(struct gbe_priv *priv, struct gbe_slave *slave)
{
if (SLAVE_LINK_IS_XGMII(slave))
return;
netcp_sgmii_reset(SGMII_BASE(priv, slave->slave_num), slave->slave_num);
netcp_sgmii_config(SGMII_BASE(priv, slave->slave_num), slave->slave_num,
slave->link_interface);
}
static int gbe_slave_open(struct gbe_intf *gbe_intf)
{
struct gbe_priv *priv = gbe_intf->gbe_dev;
struct gbe_slave *slave = gbe_intf->slave;
phy_interface_t phy_mode;
bool has_phy = false;
void (*hndlr)(struct net_device *) = gbe_adjust_link;
gbe_sgmii_config(priv, slave);
gbe_port_reset(slave);
gbe_sgmii_rtreset(priv, slave, false);
gbe_port_config(priv, slave, priv->rx_packet_max);
gbe_set_slave_mac(slave, gbe_intf);
cpsw_ale_control_set(priv->ale, slave->port_num,
ALE_PORT_STATE, ALE_PORT_STATE_FORWARD);
cpsw_ale_add_mcast(priv->ale, gbe_intf->ndev->broadcast,
1 << slave->port_num, 0, 0, ALE_MCAST_FWD_2);
if (slave->link_interface == SGMII_LINK_MAC_PHY) {
has_phy = true;
phy_mode = PHY_INTERFACE_MODE_SGMII;
slave->phy_port_t = PORT_MII;
} else if (slave->link_interface == XGMII_LINK_MAC_PHY) {
has_phy = true;
phy_mode = PHY_INTERFACE_MODE_NA;
slave->phy_port_t = PORT_FIBRE;
}
if (has_phy) {
if (priv->ss_version == XGBE_SS_VERSION_10)
hndlr = xgbe_adjust_link;
slave->phy = of_phy_connect(gbe_intf->ndev,
slave->phy_node,
hndlr, 0,
phy_mode);
if (!slave->phy) {
dev_err(priv->dev, "phy not found on slave %d\n",
slave->slave_num);
return -ENODEV;
}
dev_dbg(priv->dev, "phy found: id is: 0x%s\n",
phydev_name(slave->phy));
phy_start(slave->phy);
}
return 0;
}
static void gbe_init_host_port(struct gbe_priv *priv)
{
int bypass_en = 1;
if (IS_SS_ID_NU(priv) || IS_SS_ID_XGBE(priv))
writel(HOST_TX_PRI_MAP_DEFAULT,
GBE_REG_ADDR(priv, host_port_regs, tx_pri_map));
writel(NETCP_MAX_FRAME_SIZE, GBE_REG_ADDR(priv, host_port_regs,
rx_maxlen));
cpsw_ale_start(priv->ale);
if (priv->enable_ale)
bypass_en = 0;
cpsw_ale_control_set(priv->ale, 0, ALE_BYPASS, bypass_en);
cpsw_ale_control_set(priv->ale, 0, ALE_NO_PORT_VLAN, 1);
cpsw_ale_control_set(priv->ale, priv->host_port,
ALE_PORT_STATE, ALE_PORT_STATE_FORWARD);
cpsw_ale_control_set(priv->ale, 0,
ALE_PORT_UNKNOWN_VLAN_MEMBER,
GBE_PORT_MASK(priv->ale_ports));
cpsw_ale_control_set(priv->ale, 0,
ALE_PORT_UNKNOWN_MCAST_FLOOD,
GBE_PORT_MASK(priv->ale_ports - 1));
cpsw_ale_control_set(priv->ale, 0,
ALE_PORT_UNKNOWN_REG_MCAST_FLOOD,
GBE_PORT_MASK(priv->ale_ports));
cpsw_ale_control_set(priv->ale, 0,
ALE_PORT_UNTAGGED_EGRESS,
GBE_PORT_MASK(priv->ale_ports));
}
static void gbe_add_mcast_addr(struct gbe_intf *gbe_intf, u8 *addr)
{
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
u16 vlan_id;
cpsw_ale_add_mcast(gbe_dev->ale, addr,
GBE_PORT_MASK(gbe_dev->ale_ports), 0, 0,
ALE_MCAST_FWD_2);
for_each_set_bit(vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
cpsw_ale_add_mcast(gbe_dev->ale, addr,
GBE_PORT_MASK(gbe_dev->ale_ports),
ALE_VLAN, vlan_id, ALE_MCAST_FWD_2);
}
}
static void gbe_add_ucast_addr(struct gbe_intf *gbe_intf, u8 *addr)
{
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
u16 vlan_id;
cpsw_ale_add_ucast(gbe_dev->ale, addr, gbe_dev->host_port, 0, 0);
for_each_set_bit(vlan_id, gbe_intf->active_vlans, VLAN_N_VID)
cpsw_ale_add_ucast(gbe_dev->ale, addr, gbe_dev->host_port,
ALE_VLAN, vlan_id);
}
static void gbe_del_mcast_addr(struct gbe_intf *gbe_intf, u8 *addr)
{
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
u16 vlan_id;
cpsw_ale_del_mcast(gbe_dev->ale, addr, 0, 0, 0);
for_each_set_bit(vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
cpsw_ale_del_mcast(gbe_dev->ale, addr, 0, ALE_VLAN, vlan_id);
}
}
static void gbe_del_ucast_addr(struct gbe_intf *gbe_intf, u8 *addr)
{
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
u16 vlan_id;
cpsw_ale_del_ucast(gbe_dev->ale, addr, gbe_dev->host_port, 0, 0);
for_each_set_bit(vlan_id, gbe_intf->active_vlans, VLAN_N_VID) {
cpsw_ale_del_ucast(gbe_dev->ale, addr, gbe_dev->host_port,
ALE_VLAN, vlan_id);
}
}
static int gbe_add_addr(void *intf_priv, struct netcp_addr *naddr)
{
struct gbe_intf *gbe_intf = intf_priv;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
dev_dbg(gbe_dev->dev, "ethss adding address %pM, type %d\n",
naddr->addr, naddr->type);
switch (naddr->type) {
case ADDR_MCAST:
case ADDR_BCAST:
gbe_add_mcast_addr(gbe_intf, naddr->addr);
break;
case ADDR_UCAST:
case ADDR_DEV:
gbe_add_ucast_addr(gbe_intf, naddr->addr);
break;
case ADDR_ANY:
default:
break;
}
return 0;
}
static int gbe_del_addr(void *intf_priv, struct netcp_addr *naddr)
{
struct gbe_intf *gbe_intf = intf_priv;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
dev_dbg(gbe_dev->dev, "ethss deleting address %pM, type %d\n",
naddr->addr, naddr->type);
switch (naddr->type) {
case ADDR_MCAST:
case ADDR_BCAST:
gbe_del_mcast_addr(gbe_intf, naddr->addr);
break;
case ADDR_UCAST:
case ADDR_DEV:
gbe_del_ucast_addr(gbe_intf, naddr->addr);
break;
case ADDR_ANY:
default:
break;
}
return 0;
}
static int gbe_add_vid(void *intf_priv, int vid)
{
struct gbe_intf *gbe_intf = intf_priv;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
set_bit(vid, gbe_intf->active_vlans);
cpsw_ale_add_vlan(gbe_dev->ale, vid,
GBE_PORT_MASK(gbe_dev->ale_ports),
GBE_MASK_NO_PORTS,
GBE_PORT_MASK(gbe_dev->ale_ports),
GBE_PORT_MASK(gbe_dev->ale_ports - 1));
return 0;
}
static int gbe_del_vid(void *intf_priv, int vid)
{
struct gbe_intf *gbe_intf = intf_priv;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
cpsw_ale_del_vlan(gbe_dev->ale, vid, 0);
clear_bit(vid, gbe_intf->active_vlans);
return 0;
}
static void gbe_txtstamp(void *context, struct sk_buff *skb)
{
struct gbe_intf *gbe_intf = context;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
cpts_tx_timestamp(gbe_dev->cpts, skb);
}
static bool gbe_need_txtstamp(struct gbe_intf *gbe_intf,
const struct netcp_packet *p_info)
{
struct sk_buff *skb = p_info->skb;
unsigned int class = ptp_classify_raw(skb);
if (class == PTP_CLASS_NONE)
return false;
switch (class) {
case PTP_CLASS_V1_IPV4:
case PTP_CLASS_V1_IPV6:
case PTP_CLASS_V2_IPV4:
case PTP_CLASS_V2_IPV6:
case PTP_CLASS_V2_L2:
case (PTP_CLASS_V2_VLAN | PTP_CLASS_L2):
case (PTP_CLASS_V2_VLAN | PTP_CLASS_IPV4):
case (PTP_CLASS_V2_VLAN | PTP_CLASS_IPV6):
return true;
}
return false;
}
static int gbe_txtstamp_mark_pkt(struct gbe_intf *gbe_intf,
struct netcp_packet *p_info)
{
struct phy_device *phydev = p_info->skb->dev->phydev;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
if (!(skb_shinfo(p_info->skb)->tx_flags & SKBTX_HW_TSTAMP) ||
!cpts_is_tx_enabled(gbe_dev->cpts))
return 0;
if (phydev && HAS_PHY_TXTSTAMP(phydev)) {
skb_shinfo(p_info->skb)->tx_flags |= SKBTX_IN_PROGRESS;
return 0;
}
if (gbe_need_txtstamp(gbe_intf, p_info)) {
p_info->txtstamp = gbe_txtstamp;
p_info->ts_context = (void *)gbe_intf;
skb_shinfo(p_info->skb)->tx_flags |= SKBTX_IN_PROGRESS;
}
return 0;
}
static int gbe_rxtstamp(struct gbe_intf *gbe_intf, struct netcp_packet *p_info)
{
struct phy_device *phydev = p_info->skb->dev->phydev;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
if (p_info->rxtstamp_complete)
return 0;
if (phydev && HAS_PHY_RXTSTAMP(phydev)) {
p_info->rxtstamp_complete = true;
return 0;
}
cpts_rx_timestamp(gbe_dev->cpts, p_info->skb);
p_info->rxtstamp_complete = true;
return 0;
}
static int gbe_hwtstamp_get(struct gbe_intf *gbe_intf, struct ifreq *ifr)
{
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
struct cpts *cpts = gbe_dev->cpts;
struct hwtstamp_config cfg;
if (!cpts)
return -EOPNOTSUPP;
cfg.flags = 0;
cfg.tx_type = cpts_is_tx_enabled(cpts) ?
HWTSTAMP_TX_ON : HWTSTAMP_TX_OFF;
cfg.rx_filter = (cpts_is_rx_enabled(cpts) ?
cpts->rx_enable : HWTSTAMP_FILTER_NONE);
return copy_to_user(ifr->ifr_data, &cfg, sizeof(cfg)) ? -EFAULT : 0;
}
static void gbe_hwtstamp(struct gbe_intf *gbe_intf)
{
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
struct gbe_slave *slave = gbe_intf->slave;
u32 ts_en, seq_id, ctl;
if (!cpts_is_rx_enabled(gbe_dev->cpts) &&
!cpts_is_tx_enabled(gbe_dev->cpts)) {
writel(0, GBE_REG_ADDR(slave, port_regs, ts_ctl));
return;
}
seq_id = (30 << TS_SEQ_ID_OFS_SHIFT) | ETH_P_1588;
ts_en = EVENT_MSG_BITS << TS_MSG_TYPE_EN_SHIFT;
ctl = ETH_P_1588 | TS_TTL_NONZERO |
(slave->ts_ctl.dst_port_map << TS_CTL_DST_PORT_SHIFT) |
(slave->ts_ctl.uni ? TS_UNI_EN :
slave->ts_ctl.maddr_map << TS_CTL_MADDR_SHIFT);
if (cpts_is_tx_enabled(gbe_dev->cpts))
ts_en |= (TS_TX_ANX_ALL_EN | TS_TX_VLAN_LT1_EN);
if (cpts_is_rx_enabled(gbe_dev->cpts))
ts_en |= (TS_RX_ANX_ALL_EN | TS_RX_VLAN_LT1_EN);
writel(ts_en, GBE_REG_ADDR(slave, port_regs, ts_ctl));
writel(seq_id, GBE_REG_ADDR(slave, port_regs, ts_seq_ltype));
writel(ctl, GBE_REG_ADDR(slave, port_regs, ts_ctl_ltype2));
}
static int gbe_hwtstamp_set(struct gbe_intf *gbe_intf, struct ifreq *ifr)
{
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
struct cpts *cpts = gbe_dev->cpts;
struct hwtstamp_config cfg;
if (!cpts)
return -EOPNOTSUPP;
if (copy_from_user(&cfg, ifr->ifr_data, sizeof(cfg)))
return -EFAULT;
if (cfg.flags)
return -EINVAL;
switch (cfg.tx_type) {
case HWTSTAMP_TX_OFF:
cpts_tx_enable(cpts, 0);
break;
case HWTSTAMP_TX_ON:
cpts_tx_enable(cpts, 1);
break;
default:
return -ERANGE;
}
switch (cfg.rx_filter) {
case HWTSTAMP_FILTER_NONE:
cpts_rx_enable(cpts, 0);
break;
case HWTSTAMP_FILTER_ALL:
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
cpts_rx_enable(cpts, HWTSTAMP_FILTER_PTP_V1_L4_EVENT);
cfg.rx_filter = HWTSTAMP_FILTER_PTP_V1_L4_EVENT;
break;
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
cpts_rx_enable(cpts, HWTSTAMP_FILTER_PTP_V2_EVENT);
cfg.rx_filter = HWTSTAMP_FILTER_PTP_V2_EVENT;
break;
default:
return -ERANGE;
}
gbe_hwtstamp(gbe_intf);
return copy_to_user(ifr->ifr_data, &cfg, sizeof(cfg)) ? -EFAULT : 0;
}
static void gbe_register_cpts(struct gbe_priv *gbe_dev)
{
if (!gbe_dev->cpts)
return;
if (gbe_dev->cpts_registered > 0)
goto done;
if (cpts_register(gbe_dev->cpts)) {
dev_err(gbe_dev->dev, "error registering cpts device\n");
return;
}
done:
++gbe_dev->cpts_registered;
}
static void gbe_unregister_cpts(struct gbe_priv *gbe_dev)
{
if (!gbe_dev->cpts || (gbe_dev->cpts_registered <= 0))
return;
if (--gbe_dev->cpts_registered)
return;
cpts_unregister(gbe_dev->cpts);
}
static inline int gbe_txtstamp_mark_pkt(struct gbe_intf *gbe_intf,
struct netcp_packet *p_info)
{
return 0;
}
static inline int gbe_rxtstamp(struct gbe_intf *gbe_intf,
struct netcp_packet *p_info)
{
return 0;
}
static inline int gbe_hwtstamp(struct gbe_intf *gbe_intf,
struct ifreq *ifr, int cmd)
{
return -EOPNOTSUPP;
}
static inline void gbe_register_cpts(struct gbe_priv *gbe_dev)
{
}
static inline void gbe_unregister_cpts(struct gbe_priv *gbe_dev)
{
}
static inline int gbe_hwtstamp_get(struct gbe_intf *gbe_intf, struct ifreq *req)
{
return -EOPNOTSUPP;
}
static inline int gbe_hwtstamp_set(struct gbe_intf *gbe_intf, struct ifreq *req)
{
return -EOPNOTSUPP;
}
static int gbe_ioctl(void *intf_priv, struct ifreq *req, int cmd)
{
struct gbe_intf *gbe_intf = intf_priv;
struct phy_device *phy = gbe_intf->slave->phy;
if (!phy || !phy->drv->hwtstamp) {
switch (cmd) {
case SIOCGHWTSTAMP:
return gbe_hwtstamp_get(gbe_intf, req);
case SIOCSHWTSTAMP:
return gbe_hwtstamp_set(gbe_intf, req);
}
}
if (phy)
return phy_mii_ioctl(phy, req, cmd);
return -EOPNOTSUPP;
}
static void netcp_ethss_timer(unsigned long arg)
{
struct gbe_priv *gbe_dev = (struct gbe_priv *)arg;
struct gbe_intf *gbe_intf;
struct gbe_slave *slave;
for_each_intf(gbe_intf, gbe_dev) {
if (!gbe_intf->slave->open)
continue;
netcp_ethss_update_link_state(gbe_dev, gbe_intf->slave,
gbe_intf->ndev);
}
for_each_sec_slave(slave, gbe_dev) {
netcp_ethss_update_link_state(gbe_dev, slave, NULL);
}
spin_lock(&gbe_dev->hw_stats_lock);
if (gbe_dev->ss_version == GBE_SS_VERSION_14)
gbe_update_stats_ver14(gbe_dev, NULL);
else
gbe_update_stats(gbe_dev, NULL);
spin_unlock(&gbe_dev->hw_stats_lock);
gbe_dev->timer.expires = jiffies + GBE_TIMER_INTERVAL;
add_timer(&gbe_dev->timer);
}
static int gbe_txhook(int order, void *data, struct netcp_packet *p_info)
{
struct gbe_intf *gbe_intf = data;
p_info->tx_pipe = &gbe_intf->tx_pipe;
return gbe_txtstamp_mark_pkt(gbe_intf, p_info);
}
static int gbe_rxhook(int order, void *data, struct netcp_packet *p_info)
{
struct gbe_intf *gbe_intf = data;
return gbe_rxtstamp(gbe_intf, p_info);
}
static int gbe_open(void *intf_priv, struct net_device *ndev)
{
struct gbe_intf *gbe_intf = intf_priv;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_slave *slave = gbe_intf->slave;
int port_num = slave->port_num;
u32 reg, val;
int ret;
reg = readl(GBE_REG_ADDR(gbe_dev, switch_regs, id_ver));
dev_dbg(gbe_dev->dev, "initializing gbe version %d.%d (%d) GBE identification value 0x%x\n",
GBE_MAJOR_VERSION(reg), GBE_MINOR_VERSION(reg),
GBE_RTL_VERSION(reg), GBE_IDENT(reg));
if ((gbe_dev->ss_version == XGBE_SS_VERSION_10) || IS_SS_ID_MU(gbe_dev))
gbe_intf->tx_pipe.flags = SWITCH_TO_PORT_IN_TAGINFO;
if (gbe_dev->enable_ale)
gbe_intf->tx_pipe.switch_to_port = 0;
else
gbe_intf->tx_pipe.switch_to_port = port_num;
dev_dbg(gbe_dev->dev,
"opened TX channel %s: %p with to port %d, flags %d\n",
gbe_intf->tx_pipe.dma_chan_name,
gbe_intf->tx_pipe.dma_channel,
gbe_intf->tx_pipe.switch_to_port,
gbe_intf->tx_pipe.flags);
gbe_slave_stop(gbe_intf);
writel(0, GBE_REG_ADDR(gbe_dev, switch_regs, ptype));
val = GBE_CTL_P0_ENABLE;
if (IS_SS_ID_MU(gbe_dev)) {
val |= ETH_SW_CTL_P0_TX_CRC_REMOVE;
netcp->hw_cap = ETH_SW_CAN_REMOVE_ETH_FCS;
}
writel(val, GBE_REG_ADDR(gbe_dev, switch_regs, control));
writel(gbe_dev->stats_en_mask, GBE_REG_ADDR(gbe_dev, switch_regs,
stat_port_en));
ret = gbe_slave_open(gbe_intf);
if (ret)
goto fail;
netcp_register_txhook(netcp, GBE_TXHOOK_ORDER, gbe_txhook, gbe_intf);
netcp_register_rxhook(netcp, GBE_RXHOOK_ORDER, gbe_rxhook, gbe_intf);
slave->open = true;
netcp_ethss_update_link_state(gbe_dev, slave, ndev);
gbe_register_cpts(gbe_dev);
return 0;
fail:
gbe_slave_stop(gbe_intf);
return ret;
}
static int gbe_close(void *intf_priv, struct net_device *ndev)
{
struct gbe_intf *gbe_intf = intf_priv;
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
gbe_unregister_cpts(gbe_dev);
gbe_slave_stop(gbe_intf);
netcp_unregister_rxhook(netcp, GBE_RXHOOK_ORDER, gbe_rxhook, gbe_intf);
netcp_unregister_txhook(netcp, GBE_TXHOOK_ORDER, gbe_txhook, gbe_intf);
gbe_intf->slave->open = false;
atomic_set(&gbe_intf->slave->link_state, NETCP_LINK_STATE_INVALID);
return 0;
}
static void init_slave_ts_ctl(struct gbe_slave *slave)
{
slave->ts_ctl.uni = 1;
slave->ts_ctl.dst_port_map =
(TS_CTL_DST_PORT >> TS_CTL_DST_PORT_SHIFT) & 0x3;
slave->ts_ctl.maddr_map =
(TS_CTL_MADDR_ALL >> TS_CTL_MADDR_SHIFT) & 0x1f;
}
static void init_slave_ts_ctl(struct gbe_slave *slave)
{
}
static int init_slave(struct gbe_priv *gbe_dev, struct gbe_slave *slave,
struct device_node *node)
{
int port_reg_num;
u32 port_reg_ofs, emac_reg_ofs;
u32 port_reg_blk_sz, emac_reg_blk_sz;
if (of_property_read_u32(node, "slave-port", &slave->slave_num)) {
dev_err(gbe_dev->dev, "missing slave-port parameter\n");
return -EINVAL;
}
if (of_property_read_u32(node, "link-interface",
&slave->link_interface)) {
dev_warn(gbe_dev->dev,
"missing link-interface value defaulting to 1G mac-phy link\n");
slave->link_interface = SGMII_LINK_MAC_PHY;
}
slave->open = false;
if ((slave->link_interface == SGMII_LINK_MAC_PHY) ||
(slave->link_interface == XGMII_LINK_MAC_PHY))
slave->phy_node = of_parse_phandle(node, "phy-handle", 0);
slave->port_num = gbe_get_slave_port(gbe_dev, slave->slave_num);
if (slave->link_interface >= XGMII_LINK_MAC_PHY)
slave->mac_control = GBE_DEF_10G_MAC_CONTROL;
else
slave->mac_control = GBE_DEF_1G_MAC_CONTROL;
port_reg_num = slave->slave_num;
if (gbe_dev->ss_version == GBE_SS_VERSION_14) {
if (slave->slave_num > 1) {
port_reg_ofs = GBE13_SLAVE_PORT2_OFFSET;
port_reg_num -= 2;
} else {
port_reg_ofs = GBE13_SLAVE_PORT_OFFSET;
}
emac_reg_ofs = GBE13_EMAC_OFFSET;
port_reg_blk_sz = 0x30;
emac_reg_blk_sz = 0x40;
} else if (IS_SS_ID_MU(gbe_dev)) {
port_reg_ofs = GBENU_SLAVE_PORT_OFFSET;
emac_reg_ofs = GBENU_EMAC_OFFSET;
port_reg_blk_sz = 0x1000;
emac_reg_blk_sz = 0x1000;
} else if (gbe_dev->ss_version == XGBE_SS_VERSION_10) {
port_reg_ofs = XGBE10_SLAVE_PORT_OFFSET;
emac_reg_ofs = XGBE10_EMAC_OFFSET;
port_reg_blk_sz = 0x30;
emac_reg_blk_sz = 0x40;
} else {
dev_err(gbe_dev->dev, "unknown ethss(0x%x)\n",
gbe_dev->ss_version);
return -EINVAL;
}
slave->port_regs = gbe_dev->switch_regs + port_reg_ofs +
(port_reg_blk_sz * port_reg_num);
slave->emac_regs = gbe_dev->switch_regs + emac_reg_ofs +
(emac_reg_blk_sz * slave->slave_num);
if (gbe_dev->ss_version == GBE_SS_VERSION_14) {
GBE_SET_REG_OFS(slave, port_regs, port_vlan);
GBE_SET_REG_OFS(slave, port_regs, tx_pri_map);
GBE_SET_REG_OFS(slave, port_regs, sa_lo);
GBE_SET_REG_OFS(slave, port_regs, sa_hi);
GBE_SET_REG_OFS(slave, port_regs, ts_ctl);
GBE_SET_REG_OFS(slave, port_regs, ts_seq_ltype);
GBE_SET_REG_OFS(slave, port_regs, ts_vlan);
GBE_SET_REG_OFS(slave, port_regs, ts_ctl_ltype2);
GBE_SET_REG_OFS(slave, port_regs, ts_ctl2);
GBE_SET_REG_OFS(slave, emac_regs, mac_control);
GBE_SET_REG_OFS(slave, emac_regs, soft_reset);
GBE_SET_REG_OFS(slave, emac_regs, rx_maxlen);
} else if (IS_SS_ID_MU(gbe_dev)) {
GBENU_SET_REG_OFS(slave, port_regs, port_vlan);
GBENU_SET_REG_OFS(slave, port_regs, tx_pri_map);
GBENU_SET_REG_OFS(slave, port_regs, sa_lo);
GBENU_SET_REG_OFS(slave, port_regs, sa_hi);
GBENU_SET_REG_OFS(slave, port_regs, ts_ctl);
GBENU_SET_REG_OFS(slave, port_regs, ts_seq_ltype);
GBENU_SET_REG_OFS(slave, port_regs, ts_vlan);
GBENU_SET_REG_OFS(slave, port_regs, ts_ctl_ltype2);
GBENU_SET_REG_OFS(slave, port_regs, ts_ctl2);
GBENU_SET_REG_OFS(slave, port_regs, rx_maxlen);
GBENU_SET_REG_OFS(slave, emac_regs, mac_control);
GBENU_SET_REG_OFS(slave, emac_regs, soft_reset);
} else if (gbe_dev->ss_version == XGBE_SS_VERSION_10) {
XGBE_SET_REG_OFS(slave, port_regs, port_vlan);
XGBE_SET_REG_OFS(slave, port_regs, tx_pri_map);
XGBE_SET_REG_OFS(slave, port_regs, sa_lo);
XGBE_SET_REG_OFS(slave, port_regs, sa_hi);
XGBE_SET_REG_OFS(slave, port_regs, ts_ctl);
XGBE_SET_REG_OFS(slave, port_regs, ts_seq_ltype);
XGBE_SET_REG_OFS(slave, port_regs, ts_vlan);
XGBE_SET_REG_OFS(slave, port_regs, ts_ctl_ltype2);
XGBE_SET_REG_OFS(slave, port_regs, ts_ctl2);
XGBE_SET_REG_OFS(slave, emac_regs, mac_control);
XGBE_SET_REG_OFS(slave, emac_regs, soft_reset);
XGBE_SET_REG_OFS(slave, emac_regs, rx_maxlen);
}
atomic_set(&slave->link_state, NETCP_LINK_STATE_INVALID);
init_slave_ts_ctl(slave);
return 0;
}
static void init_secondary_ports(struct gbe_priv *gbe_dev,
struct device_node *node)
{
struct device *dev = gbe_dev->dev;
phy_interface_t phy_mode;
struct gbe_priv **priv;
struct device_node *port;
struct gbe_slave *slave;
bool mac_phy_link = false;
for_each_child_of_node(node, port) {
slave = devm_kzalloc(dev, sizeof(*slave), GFP_KERNEL);
if (!slave) {
dev_err(dev,
"memomry alloc failed for secondary port(%s), skipping...\n",
port->name);
continue;
}
if (init_slave(gbe_dev, slave, port)) {
dev_err(dev,
"Failed to initialize secondary port(%s), skipping...\n",
port->name);
devm_kfree(dev, slave);
continue;
}
gbe_sgmii_config(gbe_dev, slave);
gbe_port_reset(slave);
gbe_port_config(gbe_dev, slave, gbe_dev->rx_packet_max);
list_add_tail(&slave->slave_list, &gbe_dev->secondary_slaves);
gbe_dev->num_slaves++;
if ((slave->link_interface == SGMII_LINK_MAC_PHY) ||
(slave->link_interface == XGMII_LINK_MAC_PHY))
mac_phy_link = true;
slave->open = true;
if (gbe_dev->num_slaves >= gbe_dev->max_num_slaves) {
of_node_put(port);
break;
}
}
if (!mac_phy_link)
return;
gbe_dev->dummy_ndev = alloc_netdev(sizeof(gbe_dev), "dummy",
NET_NAME_UNKNOWN, ether_setup);
if (!gbe_dev->dummy_ndev) {
dev_err(dev,
"Failed to allocate dummy netdev for secondary ports, skipping phy_connect()...\n");
return;
}
priv = netdev_priv(gbe_dev->dummy_ndev);
*priv = gbe_dev;
if (slave->link_interface == SGMII_LINK_MAC_PHY) {
phy_mode = PHY_INTERFACE_MODE_SGMII;
slave->phy_port_t = PORT_MII;
} else {
phy_mode = PHY_INTERFACE_MODE_NA;
slave->phy_port_t = PORT_FIBRE;
}
for_each_sec_slave(slave, gbe_dev) {
if ((slave->link_interface != SGMII_LINK_MAC_PHY) &&
(slave->link_interface != XGMII_LINK_MAC_PHY))
continue;
slave->phy =
of_phy_connect(gbe_dev->dummy_ndev,
slave->phy_node,
gbe_adjust_link_sec_slaves,
0, phy_mode);
if (!slave->phy) {
dev_err(dev, "phy not found for slave %d\n",
slave->slave_num);
slave->phy = NULL;
} else {
dev_dbg(dev, "phy found: id is: 0x%s\n",
phydev_name(slave->phy));
phy_start(slave->phy);
}
}
}
static void free_secondary_ports(struct gbe_priv *gbe_dev)
{
struct gbe_slave *slave;
while (!list_empty(&gbe_dev->secondary_slaves)) {
slave = first_sec_slave(gbe_dev);
if (slave->phy)
phy_disconnect(slave->phy);
list_del(&slave->slave_list);
}
if (gbe_dev->dummy_ndev)
free_netdev(gbe_dev->dummy_ndev);
}
static int set_xgbe_ethss10_priv(struct gbe_priv *gbe_dev,
struct device_node *node)
{
struct resource res;
void __iomem *regs;
int ret, i;
ret = of_address_to_resource(node, XGBE_SS_REG_INDEX, &res);
if (ret) {
dev_err(gbe_dev->dev,
"Can't xlate xgbe of node(%s) ss address at %d\n",
node->name, XGBE_SS_REG_INDEX);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev, "Failed to map xgbe ss register base\n");
return PTR_ERR(regs);
}
gbe_dev->ss_regs = regs;
ret = of_address_to_resource(node, XGBE_SM_REG_INDEX, &res);
if (ret) {
dev_err(gbe_dev->dev,
"Can't xlate xgbe of node(%s) sm address at %d\n",
node->name, XGBE_SM_REG_INDEX);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev, "Failed to map xgbe sm register base\n");
return PTR_ERR(regs);
}
gbe_dev->switch_regs = regs;
ret = of_address_to_resource(node, XGBE_SERDES_REG_INDEX, &res);
if (ret) {
dev_err(gbe_dev->dev,
"Can't xlate xgbe serdes of node(%s) address at %d\n",
node->name, XGBE_SERDES_REG_INDEX);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev, "Failed to map xgbe serdes register base\n");
return PTR_ERR(regs);
}
gbe_dev->xgbe_serdes_regs = regs;
gbe_dev->num_stats_mods = gbe_dev->max_num_ports;
gbe_dev->et_stats = xgbe10_et_stats;
gbe_dev->num_et_stats = ARRAY_SIZE(xgbe10_et_stats);
gbe_dev->hw_stats = devm_kzalloc(gbe_dev->dev,
gbe_dev->num_et_stats * sizeof(u64),
GFP_KERNEL);
if (!gbe_dev->hw_stats) {
dev_err(gbe_dev->dev, "hw_stats memory allocation failed\n");
return -ENOMEM;
}
gbe_dev->hw_stats_prev =
devm_kzalloc(gbe_dev->dev,
gbe_dev->num_et_stats * sizeof(u32),
GFP_KERNEL);
if (!gbe_dev->hw_stats_prev) {
dev_err(gbe_dev->dev,
"hw_stats_prev memory allocation failed\n");
return -ENOMEM;
}
gbe_dev->ss_version = XGBE_SS_VERSION_10;
gbe_dev->sgmii_port_regs = gbe_dev->ss_regs +
XGBE10_SGMII_MODULE_OFFSET;
gbe_dev->host_port_regs = gbe_dev->ss_regs + XGBE10_HOST_PORT_OFFSET;
for (i = 0; i < gbe_dev->max_num_ports; i++)
gbe_dev->hw_stats_regs[i] = gbe_dev->switch_regs +
XGBE10_HW_STATS_OFFSET + (GBE_HW_STATS_REG_MAP_SZ * i);
gbe_dev->ale_reg = gbe_dev->switch_regs + XGBE10_ALE_OFFSET;
gbe_dev->cpts_reg = gbe_dev->switch_regs + XGBE10_CPTS_OFFSET;
gbe_dev->ale_ports = gbe_dev->max_num_ports;
gbe_dev->host_port = XGBE10_HOST_PORT_NUM;
gbe_dev->ale_entries = XGBE10_NUM_ALE_ENTRIES;
gbe_dev->stats_en_mask = (1 << (gbe_dev->max_num_ports)) - 1;
XGBE_SET_REG_OFS(gbe_dev, ss_regs, id_ver);
XGBE_SET_REG_OFS(gbe_dev, ss_regs, control);
XGBE_SET_REG_OFS(gbe_dev, switch_regs, id_ver);
XGBE_SET_REG_OFS(gbe_dev, switch_regs, control);
XGBE_SET_REG_OFS(gbe_dev, switch_regs, ptype);
XGBE_SET_REG_OFS(gbe_dev, switch_regs, stat_port_en);
XGBE_SET_REG_OFS(gbe_dev, switch_regs, flow_control);
XGBE_SET_REG_OFS(gbe_dev, host_port_regs, port_vlan);
XGBE_SET_REG_OFS(gbe_dev, host_port_regs, tx_pri_map);
XGBE_SET_REG_OFS(gbe_dev, host_port_regs, rx_maxlen);
return 0;
}
static int get_gbe_resource_version(struct gbe_priv *gbe_dev,
struct device_node *node)
{
struct resource res;
void __iomem *regs;
int ret;
ret = of_address_to_resource(node, GBE_SS_REG_INDEX, &res);
if (ret) {
dev_err(gbe_dev->dev,
"Can't translate of node(%s) of gbe ss address at %d\n",
node->name, GBE_SS_REG_INDEX);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev, "Failed to map gbe register base\n");
return PTR_ERR(regs);
}
gbe_dev->ss_regs = regs;
gbe_dev->ss_version = readl(gbe_dev->ss_regs);
return 0;
}
static int set_gbe_ethss14_priv(struct gbe_priv *gbe_dev,
struct device_node *node)
{
struct resource res;
void __iomem *regs;
int i, ret;
ret = of_address_to_resource(node, GBE_SGMII34_REG_INDEX, &res);
if (ret) {
dev_err(gbe_dev->dev,
"Can't translate of gbe node(%s) address at index %d\n",
node->name, GBE_SGMII34_REG_INDEX);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev,
"Failed to map gbe sgmii port34 register base\n");
return PTR_ERR(regs);
}
gbe_dev->sgmii_port34_regs = regs;
ret = of_address_to_resource(node, GBE_SM_REG_INDEX, &res);
if (ret) {
dev_err(gbe_dev->dev,
"Can't translate of gbe node(%s) address at index %d\n",
node->name, GBE_SM_REG_INDEX);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev,
"Failed to map gbe switch module register base\n");
return PTR_ERR(regs);
}
gbe_dev->switch_regs = regs;
gbe_dev->num_stats_mods = gbe_dev->max_num_slaves;
gbe_dev->et_stats = gbe13_et_stats;
gbe_dev->num_et_stats = ARRAY_SIZE(gbe13_et_stats);
gbe_dev->hw_stats = devm_kzalloc(gbe_dev->dev,
gbe_dev->num_et_stats * sizeof(u64),
GFP_KERNEL);
if (!gbe_dev->hw_stats) {
dev_err(gbe_dev->dev, "hw_stats memory allocation failed\n");
return -ENOMEM;
}
gbe_dev->hw_stats_prev =
devm_kzalloc(gbe_dev->dev,
gbe_dev->num_et_stats * sizeof(u32),
GFP_KERNEL);
if (!gbe_dev->hw_stats_prev) {
dev_err(gbe_dev->dev,
"hw_stats_prev memory allocation failed\n");
return -ENOMEM;
}
gbe_dev->sgmii_port_regs = gbe_dev->ss_regs + GBE13_SGMII_MODULE_OFFSET;
gbe_dev->host_port_regs = gbe_dev->switch_regs + GBE13_HOST_PORT_OFFSET;
for (i = 0; i < gbe_dev->max_num_slaves; i++) {
gbe_dev->hw_stats_regs[i] =
gbe_dev->switch_regs + GBE13_HW_STATS_OFFSET +
(GBE_HW_STATS_REG_MAP_SZ * (i & 0x1));
}
gbe_dev->cpts_reg = gbe_dev->switch_regs + GBE13_CPTS_OFFSET;
gbe_dev->ale_reg = gbe_dev->switch_regs + GBE13_ALE_OFFSET;
gbe_dev->ale_ports = gbe_dev->max_num_ports;
gbe_dev->host_port = GBE13_HOST_PORT_NUM;
gbe_dev->ale_entries = GBE13_NUM_ALE_ENTRIES;
gbe_dev->stats_en_mask = GBE13_REG_VAL_STAT_ENABLE_ALL;
GBE_SET_REG_OFS(gbe_dev, ss_regs, id_ver);
GBE_SET_REG_OFS(gbe_dev, switch_regs, id_ver);
GBE_SET_REG_OFS(gbe_dev, switch_regs, control);
GBE_SET_REG_OFS(gbe_dev, switch_regs, soft_reset);
GBE_SET_REG_OFS(gbe_dev, switch_regs, stat_port_en);
GBE_SET_REG_OFS(gbe_dev, switch_regs, ptype);
GBE_SET_REG_OFS(gbe_dev, switch_regs, flow_control);
GBE_SET_REG_OFS(gbe_dev, host_port_regs, port_vlan);
GBE_SET_REG_OFS(gbe_dev, host_port_regs, rx_maxlen);
return 0;
}
static int set_gbenu_ethss_priv(struct gbe_priv *gbe_dev,
struct device_node *node)
{
struct resource res;
void __iomem *regs;
int i, ret;
gbe_dev->num_stats_mods = gbe_dev->max_num_ports;
gbe_dev->et_stats = gbenu_et_stats;
if (IS_SS_ID_NU(gbe_dev))
gbe_dev->num_et_stats = GBENU_ET_STATS_HOST_SIZE +
(gbe_dev->max_num_slaves * GBENU_ET_STATS_PORT_SIZE);
else
gbe_dev->num_et_stats = GBENU_ET_STATS_HOST_SIZE +
GBENU_ET_STATS_PORT_SIZE;
gbe_dev->hw_stats = devm_kzalloc(gbe_dev->dev,
gbe_dev->num_et_stats * sizeof(u64),
GFP_KERNEL);
if (!gbe_dev->hw_stats) {
dev_err(gbe_dev->dev, "hw_stats memory allocation failed\n");
return -ENOMEM;
}
gbe_dev->hw_stats_prev =
devm_kzalloc(gbe_dev->dev,
gbe_dev->num_et_stats * sizeof(u32),
GFP_KERNEL);
if (!gbe_dev->hw_stats_prev) {
dev_err(gbe_dev->dev,
"hw_stats_prev memory allocation failed\n");
return -ENOMEM;
}
ret = of_address_to_resource(node, GBENU_SM_REG_INDEX, &res);
if (ret) {
dev_err(gbe_dev->dev,
"Can't translate of gbenu node(%s) addr at index %d\n",
node->name, GBENU_SM_REG_INDEX);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev,
"Failed to map gbenu switch module register base\n");
return PTR_ERR(regs);
}
gbe_dev->switch_regs = regs;
gbe_dev->sgmii_port_regs = gbe_dev->ss_regs + GBENU_SGMII_MODULE_OFFSET;
gbe_dev->sgmii_port34_regs = gbe_dev->sgmii_port_regs +
(2 * GBENU_SGMII_MODULE_SIZE);
gbe_dev->host_port_regs = gbe_dev->switch_regs + GBENU_HOST_PORT_OFFSET;
for (i = 0; i < (gbe_dev->max_num_ports); i++)
gbe_dev->hw_stats_regs[i] = gbe_dev->switch_regs +
GBENU_HW_STATS_OFFSET + (GBENU_HW_STATS_REG_MAP_SZ * i);
gbe_dev->cpts_reg = gbe_dev->switch_regs + GBENU_CPTS_OFFSET;
gbe_dev->ale_reg = gbe_dev->switch_regs + GBENU_ALE_OFFSET;
gbe_dev->ale_ports = gbe_dev->max_num_ports;
gbe_dev->host_port = GBENU_HOST_PORT_NUM;
gbe_dev->stats_en_mask = (1 << (gbe_dev->max_num_ports)) - 1;
GBENU_SET_REG_OFS(gbe_dev, ss_regs, id_ver);
GBENU_SET_REG_OFS(gbe_dev, switch_regs, id_ver);
GBENU_SET_REG_OFS(gbe_dev, switch_regs, control);
GBENU_SET_REG_OFS(gbe_dev, switch_regs, stat_port_en);
GBENU_SET_REG_OFS(gbe_dev, switch_regs, ptype);
GBENU_SET_REG_OFS(gbe_dev, host_port_regs, port_vlan);
GBENU_SET_REG_OFS(gbe_dev, host_port_regs, rx_maxlen);
GBENU_SET_REG_OFS(gbe_dev, host_port_regs, tx_pri_map);
return 0;
}
static int gbe_probe(struct netcp_device *netcp_device, struct device *dev,
struct device_node *node, void **inst_priv)
{
struct device_node *interfaces, *interface;
struct device_node *secondary_ports;
struct cpsw_ale_params ale_params;
struct gbe_priv *gbe_dev;
u32 slave_num;
int i, ret = 0;
if (!node) {
dev_err(dev, "device tree info unavailable\n");
return -ENODEV;
}
gbe_dev = devm_kzalloc(dev, sizeof(struct gbe_priv), GFP_KERNEL);
if (!gbe_dev)
return -ENOMEM;
if (of_device_is_compatible(node, "ti,netcp-gbe-5") ||
of_device_is_compatible(node, "ti,netcp-gbe")) {
gbe_dev->max_num_slaves = 4;
} else if (of_device_is_compatible(node, "ti,netcp-gbe-9")) {
gbe_dev->max_num_slaves = 8;
} else if (of_device_is_compatible(node, "ti,netcp-gbe-2")) {
gbe_dev->max_num_slaves = 1;
} else if (of_device_is_compatible(node, "ti,netcp-xgbe")) {
gbe_dev->max_num_slaves = 2;
} else {
dev_err(dev, "device tree node for unknown device\n");
return -EINVAL;
}
gbe_dev->max_num_ports = gbe_dev->max_num_slaves + 1;
gbe_dev->dev = dev;
gbe_dev->netcp_device = netcp_device;
gbe_dev->rx_packet_max = NETCP_MAX_FRAME_SIZE;
spin_lock_init(&gbe_dev->hw_stats_lock);
if (of_find_property(node, "enable-ale", NULL)) {
gbe_dev->enable_ale = true;
dev_info(dev, "ALE enabled\n");
} else {
gbe_dev->enable_ale = false;
dev_dbg(dev, "ALE bypass enabled*\n");
}
ret = of_property_read_u32(node, "tx-queue",
&gbe_dev->tx_queue_id);
if (ret < 0) {
dev_err(dev, "missing tx_queue parameter\n");
gbe_dev->tx_queue_id = GBE_TX_QUEUE;
}
ret = of_property_read_string(node, "tx-channel",
&gbe_dev->dma_chan_name);
if (ret < 0) {
dev_err(dev, "missing \"tx-channel\" parameter\n");
return -EINVAL;
}
if (!strcmp(node->name, "gbe")) {
ret = get_gbe_resource_version(gbe_dev, node);
if (ret)
return ret;
dev_dbg(dev, "ss_version: 0x%08x\n", gbe_dev->ss_version);
if (gbe_dev->ss_version == GBE_SS_VERSION_14)
ret = set_gbe_ethss14_priv(gbe_dev, node);
else if (IS_SS_ID_MU(gbe_dev))
ret = set_gbenu_ethss_priv(gbe_dev, node);
else
ret = -ENODEV;
} else if (!strcmp(node->name, "xgbe")) {
ret = set_xgbe_ethss10_priv(gbe_dev, node);
if (ret)
return ret;
ret = netcp_xgbe_serdes_init(gbe_dev->xgbe_serdes_regs,
gbe_dev->ss_regs);
} else {
dev_err(dev, "unknown GBE node(%s)\n", node->name);
ret = -ENODEV;
}
if (ret)
return ret;
interfaces = of_get_child_by_name(node, "interfaces");
if (!interfaces)
dev_err(dev, "could not find interfaces\n");
ret = netcp_txpipe_init(&gbe_dev->tx_pipe, netcp_device,
gbe_dev->dma_chan_name, gbe_dev->tx_queue_id);
if (ret)
return ret;
ret = netcp_txpipe_open(&gbe_dev->tx_pipe);
if (ret)
return ret;
INIT_LIST_HEAD(&gbe_dev->gbe_intf_head);
for_each_child_of_node(interfaces, interface) {
ret = of_property_read_u32(interface, "slave-port", &slave_num);
if (ret) {
dev_err(dev, "missing slave-port parameter, skipping interface configuration for %s\n",
interface->name);
continue;
}
gbe_dev->num_slaves++;
if (gbe_dev->num_slaves >= gbe_dev->max_num_slaves) {
of_node_put(interface);
break;
}
}
of_node_put(interfaces);
if (!gbe_dev->num_slaves)
dev_warn(dev, "No network interface configured\n");
secondary_ports = of_get_child_by_name(node, "secondary-slave-ports");
INIT_LIST_HEAD(&gbe_dev->secondary_slaves);
if (secondary_ports && (gbe_dev->num_slaves < gbe_dev->max_num_slaves))
init_secondary_ports(gbe_dev, secondary_ports);
of_node_put(secondary_ports);
if (!gbe_dev->num_slaves) {
dev_err(dev,
"No network interface or secondary ports configured\n");
ret = -ENODEV;
goto free_sec_ports;
}
memset(&ale_params, 0, sizeof(ale_params));
ale_params.dev = gbe_dev->dev;
ale_params.ale_regs = gbe_dev->ale_reg;
ale_params.ale_ageout = GBE_DEFAULT_ALE_AGEOUT;
ale_params.ale_entries = gbe_dev->ale_entries;
ale_params.ale_ports = gbe_dev->ale_ports;
if (IS_SS_ID_MU(gbe_dev)) {
ale_params.major_ver_mask = 0x7;
ale_params.nu_switch_ale = true;
}
gbe_dev->ale = cpsw_ale_create(&ale_params);
if (!gbe_dev->ale) {
dev_err(gbe_dev->dev, "error initializing ale engine\n");
ret = -ENODEV;
goto free_sec_ports;
} else {
dev_dbg(gbe_dev->dev, "Created a gbe ale engine\n");
}
gbe_dev->cpts = cpts_create(gbe_dev->dev, gbe_dev->cpts_reg, node);
if (IS_ENABLED(CONFIG_TI_CPTS) && IS_ERR(gbe_dev->cpts)) {
ret = PTR_ERR(gbe_dev->cpts);
goto free_sec_ports;
}
gbe_init_host_port(gbe_dev);
spin_lock_bh(&gbe_dev->hw_stats_lock);
for (i = 0; i < gbe_dev->num_stats_mods; i++) {
if (gbe_dev->ss_version == GBE_SS_VERSION_14)
gbe_reset_mod_stats_ver14(gbe_dev, i);
else
gbe_reset_mod_stats(gbe_dev, i);
}
spin_unlock_bh(&gbe_dev->hw_stats_lock);
init_timer(&gbe_dev->timer);
gbe_dev->timer.data = (unsigned long)gbe_dev;
gbe_dev->timer.function = netcp_ethss_timer;
gbe_dev->timer.expires = jiffies + GBE_TIMER_INTERVAL;
add_timer(&gbe_dev->timer);
*inst_priv = gbe_dev;
return 0;
free_sec_ports:
free_secondary_ports(gbe_dev);
return ret;
}
static int gbe_attach(void *inst_priv, struct net_device *ndev,
struct device_node *node, void **intf_priv)
{
struct gbe_priv *gbe_dev = inst_priv;
struct gbe_intf *gbe_intf;
int ret;
if (!node) {
dev_err(gbe_dev->dev, "interface node not available\n");
return -ENODEV;
}
gbe_intf = devm_kzalloc(gbe_dev->dev, sizeof(*gbe_intf), GFP_KERNEL);
if (!gbe_intf)
return -ENOMEM;
gbe_intf->ndev = ndev;
gbe_intf->dev = gbe_dev->dev;
gbe_intf->gbe_dev = gbe_dev;
gbe_intf->slave = devm_kzalloc(gbe_dev->dev,
sizeof(*gbe_intf->slave),
GFP_KERNEL);
if (!gbe_intf->slave) {
ret = -ENOMEM;
goto fail;
}
if (init_slave(gbe_dev, gbe_intf->slave, node)) {
ret = -ENODEV;
goto fail;
}
gbe_intf->tx_pipe = gbe_dev->tx_pipe;
ndev->ethtool_ops = &keystone_ethtool_ops;
list_add_tail(&gbe_intf->gbe_intf_list, &gbe_dev->gbe_intf_head);
*intf_priv = gbe_intf;
return 0;
fail:
if (gbe_intf->slave)
devm_kfree(gbe_dev->dev, gbe_intf->slave);
if (gbe_intf)
devm_kfree(gbe_dev->dev, gbe_intf);
return ret;
}
static int gbe_release(void *intf_priv)
{
struct gbe_intf *gbe_intf = intf_priv;
gbe_intf->ndev->ethtool_ops = NULL;
list_del(&gbe_intf->gbe_intf_list);
devm_kfree(gbe_intf->dev, gbe_intf->slave);
devm_kfree(gbe_intf->dev, gbe_intf);
return 0;
}
static int gbe_remove(struct netcp_device *netcp_device, void *inst_priv)
{
struct gbe_priv *gbe_dev = inst_priv;
del_timer_sync(&gbe_dev->timer);
cpts_release(gbe_dev->cpts);
cpsw_ale_stop(gbe_dev->ale);
cpsw_ale_destroy(gbe_dev->ale);
netcp_txpipe_close(&gbe_dev->tx_pipe);
free_secondary_ports(gbe_dev);
if (!list_empty(&gbe_dev->gbe_intf_head))
dev_alert(gbe_dev->dev,
"unreleased ethss interfaces present\n");
return 0;
}
static int __init keystone_gbe_init(void)
{
int ret;
ret = netcp_register_module(&gbe_module);
if (ret)
return ret;
ret = netcp_register_module(&xgbe_module);
if (ret)
return ret;
return 0;
}
static void __exit keystone_gbe_exit(void)
{
netcp_unregister_module(&gbe_module);
netcp_unregister_module(&xgbe_module);
}
