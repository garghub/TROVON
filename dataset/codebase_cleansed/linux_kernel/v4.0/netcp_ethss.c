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
static void keystone_get_stat_strings(struct net_device *ndev,
uint32_t stringset, uint8_t *data)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_intf *gbe_intf;
struct gbe_priv *gbe_dev;
int i;
gbe_intf = netcp_module_get_intf_data(&gbe_module, netcp);
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
gbe_intf = netcp_module_get_intf_data(&gbe_module, netcp);
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
static void gbe_update_stats(struct gbe_priv *gbe_dev, uint64_t *data)
{
void __iomem *base = NULL;
u32 __iomem *p;
u32 tmp = 0;
int i;
for (i = 0; i < gbe_dev->num_et_stats; i++) {
base = gbe_dev->hw_stats_regs[gbe_dev->et_stats[i].type];
p = base + gbe_dev->et_stats[i].offset;
tmp = readl(p);
gbe_dev->hw_stats[i] = gbe_dev->hw_stats[i] + tmp;
if (data)
data[i] = gbe_dev->hw_stats[i];
writel(tmp, p);
}
}
static void gbe_update_stats_ver14(struct gbe_priv *gbe_dev, uint64_t *data)
{
void __iomem *gbe_statsa = gbe_dev->hw_stats_regs[0];
void __iomem *gbe_statsb = gbe_dev->hw_stats_regs[1];
u64 *hw_stats = &gbe_dev->hw_stats[0];
void __iomem *base = NULL;
u32 __iomem *p;
u32 tmp = 0, val, pair_size = (gbe_dev->num_et_stats / 2);
int i, j, pair;
for (pair = 0; pair < 2; pair++) {
val = readl(GBE_REG_ADDR(gbe_dev, switch_regs, stat_port_en));
if (pair == 0)
val &= ~GBE_STATS_CD_SEL;
else
val |= GBE_STATS_CD_SEL;
writel(val, GBE_REG_ADDR(gbe_dev, switch_regs, stat_port_en));
for (i = 0; i < pair_size; i++) {
j = pair * pair_size + i;
switch (gbe_dev->et_stats[j].type) {
case GBE_STATSA_MODULE:
case GBE_STATSC_MODULE:
base = gbe_statsa;
break;
case GBE_STATSB_MODULE:
case GBE_STATSD_MODULE:
base = gbe_statsb;
break;
}
p = base + gbe_dev->et_stats[j].offset;
tmp = readl(p);
hw_stats[j] += tmp;
if (data)
data[j] = hw_stats[j];
writel(tmp, p);
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
gbe_intf = netcp_module_get_intf_data(&gbe_module, netcp);
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
static int keystone_get_settings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct phy_device *phy = ndev->phydev;
struct gbe_intf *gbe_intf;
int ret;
if (!phy)
return -EINVAL;
gbe_intf = netcp_module_get_intf_data(&gbe_module, netcp);
if (!gbe_intf)
return -EINVAL;
if (!gbe_intf->slave)
return -EINVAL;
ret = phy_ethtool_gset(phy, cmd);
if (!ret)
cmd->port = gbe_intf->slave->phy_port_t;
return ret;
}
static int keystone_set_settings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct netcp_intf *netcp = netdev_priv(ndev);
struct phy_device *phy = ndev->phydev;
struct gbe_intf *gbe_intf;
u32 features = cmd->advertising & cmd->supported;
if (!phy)
return -EINVAL;
gbe_intf = netcp_module_get_intf_data(&gbe_module, netcp);
if (!gbe_intf)
return -EINVAL;
if (!gbe_intf->slave)
return -EINVAL;
if (cmd->port != gbe_intf->slave->phy_port_t) {
if ((cmd->port == PORT_TP) && !(features & ADVERTISED_TP))
return -EINVAL;
if ((cmd->port == PORT_AUI) && !(features & ADVERTISED_AUI))
return -EINVAL;
if ((cmd->port == PORT_BNC) && !(features & ADVERTISED_BNC))
return -EINVAL;
if ((cmd->port == PORT_MII) && !(features & ADVERTISED_MII))
return -EINVAL;
if ((cmd->port == PORT_FIBRE) && !(features & ADVERTISED_FIBRE))
return -EINVAL;
}
gbe_intf->slave->phy_port_t = cmd->port;
return phy_ethtool_sset(phy, cmd);
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
if (ndev && slave->open)
netif_carrier_on(ndev);
} else {
writel(mac_control, GBE_REG_ADDR(slave, emac_regs,
mac_control));
cpsw_ale_control_set(gbe_dev->ale, slave->port_num,
ALE_PORT_STATE,
ALE_PORT_STATE_DISABLE);
if (ndev)
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
if (!SLAVE_LINK_IS_XGMII(slave))
sgmii_link_state = netcp_sgmii_get_port_link(SGMII_BASE(sp),
sp);
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
u32 xgmii_mode;
if (max_rx_len > NETCP_MAX_FRAME_SIZE)
max_rx_len = NETCP_MAX_FRAME_SIZE;
if ((gbe_dev->ss_version == XGBE_SS_VERSION_10) &&
(slave->link_interface >= XGMII_LINK_MAC_PHY)) {
xgmii_mode = readl(GBE_REG_ADDR(gbe_dev, ss_regs, control));
xgmii_mode |= (1 << slave->slave_num);
writel(xgmii_mode, GBE_REG_ADDR(gbe_dev, ss_regs, control));
}
writel(max_rx_len, GBE_REG_ADDR(slave, emac_regs, rx_maxlen));
writel(slave->mac_control, GBE_REG_ADDR(slave, emac_regs, mac_control));
}
static void gbe_slave_stop(struct gbe_intf *intf)
{
struct gbe_priv *gbe_dev = intf->gbe_dev;
struct gbe_slave *slave = intf->slave;
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
void __iomem *sgmii_port_regs;
sgmii_port_regs = priv->sgmii_port_regs;
if ((priv->ss_version == GBE_SS_VERSION_14) && (slave->slave_num >= 2))
sgmii_port_regs = priv->sgmii_port34_regs;
if (!SLAVE_LINK_IS_XGMII(slave)) {
netcp_sgmii_reset(sgmii_port_regs, slave->slave_num);
netcp_sgmii_config(sgmii_port_regs, slave->slave_num,
slave->link_interface);
}
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
dev_name(&slave->phy->dev));
phy_start(slave->phy);
phy_read_status(slave->phy);
}
return 0;
}
static void gbe_init_host_port(struct gbe_priv *priv)
{
int bypass_en = 1;
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
static int gbe_ioctl(void *intf_priv, struct ifreq *req, int cmd)
{
struct gbe_intf *gbe_intf = intf_priv;
struct phy_device *phy = gbe_intf->slave->phy;
int ret = -EOPNOTSUPP;
if (phy)
ret = phy_mii_ioctl(phy, req, cmd);
return ret;
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
spin_lock_bh(&gbe_dev->hw_stats_lock);
if (gbe_dev->ss_version == GBE_SS_VERSION_14)
gbe_update_stats_ver14(gbe_dev, NULL);
else
gbe_update_stats(gbe_dev, NULL);
spin_unlock_bh(&gbe_dev->hw_stats_lock);
gbe_dev->timer.expires = jiffies + GBE_TIMER_INTERVAL;
add_timer(&gbe_dev->timer);
}
static int gbe_tx_hook(int order, void *data, struct netcp_packet *p_info)
{
struct gbe_intf *gbe_intf = data;
p_info->tx_pipe = &gbe_intf->tx_pipe;
return 0;
}
static int gbe_open(void *intf_priv, struct net_device *ndev)
{
struct gbe_intf *gbe_intf = intf_priv;
struct gbe_priv *gbe_dev = gbe_intf->gbe_dev;
struct netcp_intf *netcp = netdev_priv(ndev);
struct gbe_slave *slave = gbe_intf->slave;
int port_num = slave->port_num;
u32 reg;
int ret;
reg = readl(GBE_REG_ADDR(gbe_dev, switch_regs, id_ver));
dev_dbg(gbe_dev->dev, "initializing gbe version %d.%d (%d) GBE identification value 0x%x\n",
GBE_MAJOR_VERSION(reg), GBE_MINOR_VERSION(reg),
GBE_RTL_VERSION(reg), GBE_IDENT(reg));
if (gbe_dev->enable_ale)
gbe_intf->tx_pipe.dma_psflags = 0;
else
gbe_intf->tx_pipe.dma_psflags = port_num;
dev_dbg(gbe_dev->dev, "opened TX channel %s: %p with psflags %d\n",
gbe_intf->tx_pipe.dma_chan_name,
gbe_intf->tx_pipe.dma_channel,
gbe_intf->tx_pipe.dma_psflags);
gbe_slave_stop(gbe_intf);
writel(0, GBE_REG_ADDR(gbe_dev, switch_regs, ptype));
writel(GBE_CTL_P0_ENABLE, GBE_REG_ADDR(gbe_dev, switch_regs, control));
writel(GBE_REG_VAL_STAT_ENABLE_ALL, GBE_REG_ADDR(gbe_dev, switch_regs,
stat_port_en));
ret = gbe_slave_open(gbe_intf);
if (ret)
goto fail;
netcp_register_txhook(netcp, GBE_TXHOOK_ORDER, gbe_tx_hook,
gbe_intf);
slave->open = true;
netcp_ethss_update_link_state(gbe_dev, slave, ndev);
return 0;
fail:
gbe_slave_stop(gbe_intf);
return ret;
}
static int gbe_close(void *intf_priv, struct net_device *ndev)
{
struct gbe_intf *gbe_intf = intf_priv;
struct netcp_intf *netcp = netdev_priv(ndev);
gbe_slave_stop(gbe_intf);
netcp_unregister_txhook(netcp, GBE_TXHOOK_ORDER, gbe_tx_hook,
gbe_intf);
gbe_intf->slave->open = false;
atomic_set(&gbe_intf->slave->link_state, NETCP_LINK_STATE_INVALID);
return 0;
}
static int init_slave(struct gbe_priv *gbe_dev, struct gbe_slave *slave,
struct device_node *node)
{
int port_reg_num;
u32 port_reg_ofs, emac_reg_ofs;
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
} else if (gbe_dev->ss_version == XGBE_SS_VERSION_10) {
port_reg_ofs = XGBE10_SLAVE_PORT_OFFSET;
} else {
dev_err(gbe_dev->dev, "unknown ethss(0x%x)\n",
gbe_dev->ss_version);
return -EINVAL;
}
if (gbe_dev->ss_version == GBE_SS_VERSION_14)
emac_reg_ofs = GBE13_EMAC_OFFSET;
else if (gbe_dev->ss_version == XGBE_SS_VERSION_10)
emac_reg_ofs = XGBE10_EMAC_OFFSET;
slave->port_regs = gbe_dev->ss_regs + port_reg_ofs +
(0x30 * port_reg_num);
slave->emac_regs = gbe_dev->ss_regs + emac_reg_ofs +
(0x40 * slave->slave_num);
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
dev_name(&slave->phy->dev));
phy_start(slave->phy);
phy_read_status(slave->phy);
}
}
}
static void free_secondary_ports(struct gbe_priv *gbe_dev)
{
struct gbe_slave *slave;
for (;;) {
slave = first_sec_slave(gbe_dev);
if (!slave)
break;
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
ret = of_address_to_resource(node, 0, &res);
if (ret) {
dev_err(gbe_dev->dev, "Can't translate of node(%s) address for xgbe subsystem regs\n",
node->name);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev, "Failed to map xgbe register base\n");
return PTR_ERR(regs);
}
gbe_dev->ss_regs = regs;
ret = of_address_to_resource(node, XGBE_SERDES_REG_INDEX, &res);
if (ret) {
dev_err(gbe_dev->dev, "Can't translate of node(%s) address for xgbe serdes regs\n",
node->name);
return ret;
}
regs = devm_ioremap_resource(gbe_dev->dev, &res);
if (IS_ERR(regs)) {
dev_err(gbe_dev->dev, "Failed to map xgbe serdes register base\n");
return PTR_ERR(regs);
}
gbe_dev->xgbe_serdes_regs = regs;
gbe_dev->hw_stats = devm_kzalloc(gbe_dev->dev,
XGBE10_NUM_STAT_ENTRIES *
(XGBE10_NUM_SLAVES + 1) * sizeof(u64),
GFP_KERNEL);
if (!gbe_dev->hw_stats) {
dev_err(gbe_dev->dev, "hw_stats memory allocation failed\n");
return -ENOMEM;
}
gbe_dev->ss_version = XGBE_SS_VERSION_10;
gbe_dev->sgmii_port_regs = gbe_dev->ss_regs +
XGBE10_SGMII_MODULE_OFFSET;
gbe_dev->switch_regs = gbe_dev->ss_regs + XGBE10_SWITCH_MODULE_OFFSET;
gbe_dev->host_port_regs = gbe_dev->ss_regs + XGBE10_HOST_PORT_OFFSET;
for (i = 0; i < XGBE10_NUM_HW_STATS_MOD; i++)
gbe_dev->hw_stats_regs[i] = gbe_dev->ss_regs +
XGBE10_HW_STATS_OFFSET + (GBE_HW_STATS_REG_MAP_SZ * i);
gbe_dev->ale_reg = gbe_dev->ss_regs + XGBE10_ALE_OFFSET;
gbe_dev->ale_ports = XGBE10_NUM_ALE_PORTS;
gbe_dev->host_port = XGBE10_HOST_PORT_NUM;
gbe_dev->ale_entries = XGBE10_NUM_ALE_ENTRIES;
gbe_dev->et_stats = xgbe10_et_stats;
gbe_dev->num_et_stats = ARRAY_SIZE(xgbe10_et_stats);
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
ret = of_address_to_resource(node, 0, &res);
if (ret) {
dev_err(gbe_dev->dev, "Can't translate of node(%s) address\n",
node->name);
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
void __iomem *regs;
int i;
gbe_dev->hw_stats = devm_kzalloc(gbe_dev->dev,
GBE13_NUM_HW_STAT_ENTRIES *
GBE13_NUM_SLAVES * sizeof(u64),
GFP_KERNEL);
if (!gbe_dev->hw_stats) {
dev_err(gbe_dev->dev, "hw_stats memory allocation failed\n");
return -ENOMEM;
}
regs = gbe_dev->ss_regs;
gbe_dev->sgmii_port_regs = regs + GBE13_SGMII_MODULE_OFFSET;
gbe_dev->sgmii_port34_regs = regs + GBE13_SGMII34_MODULE_OFFSET;
gbe_dev->switch_regs = regs + GBE13_SWITCH_MODULE_OFFSET;
gbe_dev->host_port_regs = regs + GBE13_HOST_PORT_OFFSET;
for (i = 0; i < GBE13_NUM_HW_STATS_MOD; i++)
gbe_dev->hw_stats_regs[i] = regs + GBE13_HW_STATS_OFFSET +
(GBE_HW_STATS_REG_MAP_SZ * i);
gbe_dev->ale_reg = regs + GBE13_ALE_OFFSET;
gbe_dev->ale_ports = GBE13_NUM_ALE_PORTS;
gbe_dev->host_port = GBE13_HOST_PORT_NUM;
gbe_dev->ale_entries = GBE13_NUM_ALE_ENTRIES;
gbe_dev->et_stats = gbe13_et_stats;
gbe_dev->num_et_stats = ARRAY_SIZE(gbe13_et_stats);
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
static int gbe_probe(struct netcp_device *netcp_device, struct device *dev,
struct device_node *node, void **inst_priv)
{
struct device_node *interfaces, *interface;
struct device_node *secondary_ports;
struct cpsw_ale_params ale_params;
struct gbe_priv *gbe_dev;
u32 slave_num;
int ret = 0;
if (!node) {
dev_err(dev, "device tree info unavailable\n");
return -ENODEV;
}
gbe_dev = devm_kzalloc(dev, sizeof(struct gbe_priv), GFP_KERNEL);
if (!gbe_dev)
return -ENOMEM;
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
ret = -ENODEV;
goto quit;
}
if (!strcmp(node->name, "gbe")) {
ret = get_gbe_resource_version(gbe_dev, node);
if (ret)
goto quit;
ret = set_gbe_ethss14_priv(gbe_dev, node);
if (ret)
goto quit;
} else if (!strcmp(node->name, "xgbe")) {
ret = set_xgbe_ethss10_priv(gbe_dev, node);
if (ret)
goto quit;
ret = netcp_xgbe_serdes_init(gbe_dev->xgbe_serdes_regs,
gbe_dev->ss_regs);
if (ret)
goto quit;
} else {
dev_err(dev, "unknown GBE node(%s)\n", node->name);
ret = -ENODEV;
goto quit;
}
interfaces = of_get_child_by_name(node, "interfaces");
if (!interfaces)
dev_err(dev, "could not find interfaces\n");
ret = netcp_txpipe_init(&gbe_dev->tx_pipe, netcp_device,
gbe_dev->dma_chan_name, gbe_dev->tx_queue_id);
if (ret)
goto quit;
ret = netcp_txpipe_open(&gbe_dev->tx_pipe);
if (ret)
goto quit;
INIT_LIST_HEAD(&gbe_dev->gbe_intf_head);
for_each_child_of_node(interfaces, interface) {
ret = of_property_read_u32(interface, "slave-port", &slave_num);
if (ret) {
dev_err(dev, "missing slave-port parameter, skipping interface configuration for %s\n",
interface->name);
continue;
}
gbe_dev->num_slaves++;
}
if (!gbe_dev->num_slaves)
dev_warn(dev, "No network interface configured\n");
secondary_ports = of_get_child_by_name(node, "secondary-slave-ports");
INIT_LIST_HEAD(&gbe_dev->secondary_slaves);
if (secondary_ports)
init_secondary_ports(gbe_dev, secondary_ports);
of_node_put(secondary_ports);
if (!gbe_dev->num_slaves) {
dev_err(dev, "No network interface or secondary ports configured\n");
ret = -ENODEV;
goto quit;
}
memset(&ale_params, 0, sizeof(ale_params));
ale_params.dev = gbe_dev->dev;
ale_params.ale_regs = gbe_dev->ale_reg;
ale_params.ale_ageout = GBE_DEFAULT_ALE_AGEOUT;
ale_params.ale_entries = gbe_dev->ale_entries;
ale_params.ale_ports = gbe_dev->ale_ports;
gbe_dev->ale = cpsw_ale_create(&ale_params);
if (!gbe_dev->ale) {
dev_err(gbe_dev->dev, "error initializing ale engine\n");
ret = -ENODEV;
goto quit;
} else {
dev_dbg(gbe_dev->dev, "Created a gbe ale engine\n");
}
gbe_init_host_port(gbe_dev);
init_timer(&gbe_dev->timer);
gbe_dev->timer.data = (unsigned long)gbe_dev;
gbe_dev->timer.function = netcp_ethss_timer;
gbe_dev->timer.expires = jiffies + GBE_TIMER_INTERVAL;
add_timer(&gbe_dev->timer);
*inst_priv = gbe_dev;
return 0;
quit:
if (gbe_dev->hw_stats)
devm_kfree(dev, gbe_dev->hw_stats);
cpsw_ale_destroy(gbe_dev->ale);
if (gbe_dev->ss_regs)
devm_iounmap(dev, gbe_dev->ss_regs);
of_node_put(interfaces);
devm_kfree(dev, gbe_dev);
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
cpsw_ale_stop(gbe_dev->ale);
cpsw_ale_destroy(gbe_dev->ale);
netcp_txpipe_close(&gbe_dev->tx_pipe);
free_secondary_ports(gbe_dev);
if (!list_empty(&gbe_dev->gbe_intf_head))
dev_alert(gbe_dev->dev, "unreleased ethss interfaces present\n");
devm_kfree(gbe_dev->dev, gbe_dev->hw_stats);
devm_iounmap(gbe_dev->dev, gbe_dev->ss_regs);
memset(gbe_dev, 0x00, sizeof(*gbe_dev));
devm_kfree(gbe_dev->dev, gbe_dev);
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
