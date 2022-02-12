static int xgbe_mdio_read(struct mii_bus *mii, int prtad, int mmd_reg)
{
struct xgbe_prv_data *pdata = mii->priv;
struct xgbe_hw_if *hw_if = &pdata->hw_if;
int mmd_data;
DBGPR_MDIO("-->xgbe_mdio_read: prtad=%#x mmd_reg=%#x\n",
prtad, mmd_reg);
mmd_data = hw_if->read_mmd_regs(pdata, prtad, mmd_reg);
DBGPR_MDIO("<--xgbe_mdio_read: mmd_data=%#x\n", mmd_data);
return mmd_data;
}
static int xgbe_mdio_write(struct mii_bus *mii, int prtad, int mmd_reg,
u16 mmd_val)
{
struct xgbe_prv_data *pdata = mii->priv;
struct xgbe_hw_if *hw_if = &pdata->hw_if;
int mmd_data = mmd_val;
DBGPR_MDIO("-->xgbe_mdio_write: prtad=%#x mmd_reg=%#x mmd_data=%#x\n",
prtad, mmd_reg, mmd_data);
hw_if->write_mmd_regs(pdata, prtad, mmd_reg, mmd_data);
DBGPR_MDIO("<--xgbe_mdio_write\n");
return 0;
}
static void xgbe_adjust_link(struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct phy_device *phydev = pdata->phydev;
unsigned long flags;
int new_state = 0;
if (phydev == NULL)
return;
DBGPR_MDIO("-->xgbe_adjust_link: address=%d, newlink=%d, curlink=%d\n",
phydev->addr, phydev->link, pdata->phy_link);
spin_lock_irqsave(&pdata->lock, flags);
if (phydev->link) {
if (pdata->pause_autoneg) {
if (phydev->pause || phydev->asym_pause) {
pdata->tx_pause = 1;
pdata->rx_pause = 1;
} else {
pdata->tx_pause = 0;
pdata->rx_pause = 0;
}
}
if (pdata->tx_pause != pdata->phy_tx_pause) {
hw_if->config_tx_flow_control(pdata);
pdata->phy_tx_pause = pdata->tx_pause;
}
if (pdata->rx_pause != pdata->phy_rx_pause) {
hw_if->config_rx_flow_control(pdata);
pdata->phy_rx_pause = pdata->rx_pause;
}
if (phydev->speed != pdata->phy_speed) {
new_state = 1;
switch (phydev->speed) {
case SPEED_10000:
hw_if->set_xgmii_speed(pdata);
break;
case SPEED_2500:
hw_if->set_gmii_2500_speed(pdata);
break;
case SPEED_1000:
hw_if->set_gmii_speed(pdata);
break;
}
pdata->phy_speed = phydev->speed;
}
if (phydev->link != pdata->phy_link) {
new_state = 1;
pdata->phy_link = 1;
}
} else if (pdata->phy_link) {
new_state = 1;
pdata->phy_link = 0;
pdata->phy_speed = SPEED_UNKNOWN;
}
if (new_state)
phy_print_status(phydev);
spin_unlock_irqrestore(&pdata->lock, flags);
DBGPR_MDIO("<--xgbe_adjust_link\n");
}
void xgbe_dump_phy_registers(struct xgbe_prv_data *pdata)
{
struct device *dev = pdata->dev;
struct phy_device *phydev = pdata->mii->phy_map[XGBE_PRTAD];
int i;
dev_alert(dev, "\n************* PHY Reg dump **********************\n");
dev_alert(dev, "PCS Control Reg (%#04x) = %#04x\n", MDIO_CTRL1,
XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_CTRL1));
dev_alert(dev, "PCS Status Reg (%#04x) = %#04x\n", MDIO_STAT1,
XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_STAT1));
dev_alert(dev, "Phy Id (PHYS ID 1 %#04x)= %#04x\n", MDIO_DEVID1,
XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_DEVID1));
dev_alert(dev, "Phy Id (PHYS ID 2 %#04x)= %#04x\n", MDIO_DEVID2,
XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_DEVID2));
dev_alert(dev, "Devices in Package (%#04x)= %#04x\n", MDIO_DEVS1,
XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_DEVS1));
dev_alert(dev, "Devices in Package (%#04x)= %#04x\n", MDIO_DEVS2,
XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_DEVS2));
dev_alert(dev, "Auto-Neg Control Reg (%#04x) = %#04x\n", MDIO_CTRL1,
XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_CTRL1));
dev_alert(dev, "Auto-Neg Status Reg (%#04x) = %#04x\n", MDIO_STAT1,
XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_STAT1));
dev_alert(dev, "Auto-Neg Ad Reg 1 (%#04x) = %#04x\n",
MDIO_AN_ADVERTISE,
XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_ADVERTISE));
dev_alert(dev, "Auto-Neg Ad Reg 2 (%#04x) = %#04x\n",
MDIO_AN_ADVERTISE + 1,
XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 1));
dev_alert(dev, "Auto-Neg Ad Reg 3 (%#04x) = %#04x\n",
MDIO_AN_ADVERTISE + 2,
XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_ADVERTISE + 2));
dev_alert(dev, "Auto-Neg Completion Reg (%#04x) = %#04x\n",
MDIO_AN_COMP_STAT,
XMDIO_READ(pdata, MDIO_MMD_AN, MDIO_AN_COMP_STAT));
dev_alert(dev, "MMD Device Mask = %#x\n",
phydev->c45_ids.devices_in_package);
for (i = 0; i < ARRAY_SIZE(phydev->c45_ids.device_ids); i++)
dev_alert(dev, " MMD %d: ID = %#08x\n", i,
phydev->c45_ids.device_ids[i]);
dev_alert(dev, "\n*************************************************\n");
}
int xgbe_mdio_register(struct xgbe_prv_data *pdata)
{
struct net_device *netdev = pdata->netdev;
struct device_node *phy_node;
struct mii_bus *mii;
struct phy_device *phydev;
int ret = 0;
DBGPR("-->xgbe_mdio_register\n");
phy_node = of_parse_phandle(pdata->dev->of_node, "phy-handle", 0);
if (!phy_node) {
dev_err(pdata->dev, "unable to parse phy-handle\n");
return -EINVAL;
}
mii = mdiobus_alloc();
if (mii == NULL) {
dev_err(pdata->dev, "mdiobus_alloc failed\n");
ret = -ENOMEM;
goto err_node_get;
}
mii->name = XGBE_PHY_NAME;
mii->read = xgbe_mdio_read;
mii->write = xgbe_mdio_write;
snprintf(mii->id, sizeof(mii->id), "%s", pdata->mii_bus_id);
mii->priv = pdata;
mii->phy_mask = ~0;
mii->parent = pdata->dev;
ret = mdiobus_register(mii);
if (ret) {
dev_err(pdata->dev, "mdiobus_register failed\n");
goto err_mdiobus_alloc;
}
DBGPR(" mdiobus_register succeeded for %s\n", pdata->mii_bus_id);
phydev = get_phy_device(mii, XGBE_PRTAD, true);
if (IS_ERR(phydev) || !phydev ||
!phydev->c45_ids.device_ids[MDIO_MMD_PCS]) {
dev_err(pdata->dev, "get_phy_device failed\n");
ret = phydev ? PTR_ERR(phydev) : -ENOLINK;
goto err_mdiobus_register;
}
request_module(MDIO_MODULE_PREFIX MDIO_ID_FMT,
MDIO_ID_ARGS(phydev->c45_ids.device_ids[MDIO_MMD_PCS]));
of_node_get(phy_node);
phydev->dev.of_node = phy_node;
ret = phy_device_register(phydev);
if (ret) {
dev_err(pdata->dev, "phy_device_register failed\n");
of_node_put(phy_node);
goto err_phy_device;
}
pdata->phy_module = phydev->dev.driver ?
phydev->dev.driver->owner : NULL;
if (!try_module_get(pdata->phy_module)) {
dev_err(pdata->dev, "try_module_get failed\n");
ret = -EIO;
goto err_phy_device;
}
pdata->mii = mii;
pdata->mdio_mmd = MDIO_MMD_PCS;
pdata->phy_link = -1;
pdata->phy_speed = SPEED_UNKNOWN;
pdata->phy_tx_pause = pdata->tx_pause;
pdata->phy_rx_pause = pdata->rx_pause;
ret = phy_connect_direct(netdev, phydev, &xgbe_adjust_link,
pdata->phy_mode);
if (ret) {
netdev_err(netdev, "phy_connect_direct failed\n");
goto err_phy_device;
}
if (!phydev->drv || (phydev->drv->phy_id == 0)) {
netdev_err(netdev, "phy_id not valid\n");
ret = -ENODEV;
goto err_phy_connect;
}
DBGPR(" phy_connect_direct succeeded for PHY %s, link=%d\n",
dev_name(&phydev->dev), phydev->link);
phydev->autoneg = pdata->default_autoneg;
if (phydev->autoneg == AUTONEG_DISABLE) {
phydev->supported |= SUPPORTED_1000baseT_Full;
phydev->supported |= SUPPORTED_10000baseT_Full;
phydev->speed = pdata->default_speed;
phydev->duplex = DUPLEX_FULL;
phydev->advertising &= ~ADVERTISED_Autoneg;
}
pdata->phydev = phydev;
of_node_put(phy_node);
DBGPHY_REGS(pdata);
DBGPR("<--xgbe_mdio_register\n");
return 0;
err_phy_connect:
phy_disconnect(phydev);
err_phy_device:
phy_device_free(phydev);
err_mdiobus_register:
mdiobus_unregister(mii);
err_mdiobus_alloc:
mdiobus_free(mii);
err_node_get:
of_node_put(phy_node);
return ret;
}
void xgbe_mdio_unregister(struct xgbe_prv_data *pdata)
{
DBGPR("-->xgbe_mdio_unregister\n");
phy_disconnect(pdata->phydev);
pdata->phydev = NULL;
module_put(pdata->phy_module);
pdata->phy_module = NULL;
mdiobus_unregister(pdata->mii);
pdata->mii->priv = NULL;
mdiobus_free(pdata->mii);
pdata->mii = NULL;
DBGPR("<--xgbe_mdio_unregister\n");
}
