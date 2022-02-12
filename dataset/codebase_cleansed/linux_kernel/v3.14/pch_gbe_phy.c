s32 pch_gbe_phy_get_id(struct pch_gbe_hw *hw)
{
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
struct pch_gbe_phy_info *phy = &hw->phy;
s32 ret;
u16 phy_id1;
u16 phy_id2;
ret = pch_gbe_phy_read_reg_miic(hw, PHY_ID1, &phy_id1);
if (ret)
return ret;
ret = pch_gbe_phy_read_reg_miic(hw, PHY_ID2, &phy_id2);
if (ret)
return ret;
phy->id = (u32)phy_id1;
phy->id = ((phy->id << 6) | ((phy_id2 & 0xFC00) >> 10));
phy->revision = (u32) (phy_id2 & 0x000F);
netdev_dbg(adapter->netdev,
"phy->id : 0x%08x phy->revision : 0x%08x\n",
phy->id, phy->revision);
return 0;
}
s32 pch_gbe_phy_read_reg_miic(struct pch_gbe_hw *hw, u32 offset, u16 *data)
{
struct pch_gbe_phy_info *phy = &hw->phy;
if (offset > PHY_MAX_REG_ADDRESS) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "PHY Address %d is out of range\n",
offset);
return -EINVAL;
}
*data = pch_gbe_mac_ctrl_miim(hw, phy->addr, PCH_GBE_HAL_MIIM_READ,
offset, (u16)0);
return 0;
}
s32 pch_gbe_phy_write_reg_miic(struct pch_gbe_hw *hw, u32 offset, u16 data)
{
struct pch_gbe_phy_info *phy = &hw->phy;
if (offset > PHY_MAX_REG_ADDRESS) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "PHY Address %d is out of range\n",
offset);
return -EINVAL;
}
pch_gbe_mac_ctrl_miim(hw, phy->addr, PCH_GBE_HAL_MIIM_WRITE,
offset, data);
return 0;
}
void pch_gbe_phy_sw_reset(struct pch_gbe_hw *hw)
{
u16 phy_ctrl;
pch_gbe_phy_read_reg_miic(hw, PHY_CONTROL, &phy_ctrl);
phy_ctrl |= MII_CR_RESET;
pch_gbe_phy_write_reg_miic(hw, PHY_CONTROL, phy_ctrl);
udelay(1);
}
void pch_gbe_phy_hw_reset(struct pch_gbe_hw *hw)
{
pch_gbe_phy_write_reg_miic(hw, PHY_CONTROL, PHY_CONTROL_DEFAULT);
pch_gbe_phy_write_reg_miic(hw, PHY_AUTONEG_ADV,
PHY_AUTONEG_ADV_DEFAULT);
pch_gbe_phy_write_reg_miic(hw, PHY_NEXT_PAGE_TX,
PHY_NEXT_PAGE_TX_DEFAULT);
pch_gbe_phy_write_reg_miic(hw, PHY_1000T_CTRL, PHY_1000T_CTRL_DEFAULT);
pch_gbe_phy_write_reg_miic(hw, PHY_PHYSP_CONTROL,
PHY_PHYSP_CONTROL_DEFAULT);
}
void pch_gbe_phy_power_up(struct pch_gbe_hw *hw)
{
u16 mii_reg;
mii_reg = 0;
pch_gbe_phy_read_reg_miic(hw, PHY_CONTROL, &mii_reg);
mii_reg &= ~MII_CR_POWER_DOWN;
pch_gbe_phy_write_reg_miic(hw, PHY_CONTROL, mii_reg);
}
void pch_gbe_phy_power_down(struct pch_gbe_hw *hw)
{
u16 mii_reg;
mii_reg = 0;
pch_gbe_phy_read_reg_miic(hw, PHY_CONTROL, &mii_reg);
mii_reg |= MII_CR_POWER_DOWN;
pch_gbe_phy_write_reg_miic(hw, PHY_CONTROL, mii_reg);
mdelay(1);
}
void pch_gbe_phy_set_rgmii(struct pch_gbe_hw *hw)
{
pch_gbe_phy_sw_reset(hw);
}
static int pch_gbe_phy_tx_clk_delay(struct pch_gbe_hw *hw)
{
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
u16 mii_reg;
int ret = 0;
switch (hw->phy.id) {
case PHY_AR803X_ID:
netdev_dbg(adapter->netdev,
"Configuring AR803X PHY for 2ns TX clock delay\n");
pch_gbe_phy_read_reg_miic(hw, PHY_AR8031_DBG_OFF, &mii_reg);
ret = pch_gbe_phy_write_reg_miic(hw, PHY_AR8031_DBG_OFF,
PHY_AR8031_SERDES);
if (ret)
break;
pch_gbe_phy_read_reg_miic(hw, PHY_AR8031_DBG_DAT, &mii_reg);
mii_reg |= PHY_AR8031_SERDES_TX_CLK_DLY;
ret = pch_gbe_phy_write_reg_miic(hw, PHY_AR8031_DBG_DAT,
mii_reg);
break;
default:
netdev_err(adapter->netdev,
"Unknown PHY (%x), could not set TX clock delay\n",
hw->phy.id);
return -EINVAL;
}
if (ret)
netdev_err(adapter->netdev,
"Could not configure tx clock delay for PHY\n");
return ret;
}
void pch_gbe_phy_init_setting(struct pch_gbe_hw *hw)
{
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
struct ethtool_cmd cmd = { .cmd = ETHTOOL_GSET };
int ret;
u16 mii_reg;
ret = mii_ethtool_gset(&adapter->mii, &cmd);
if (ret)
netdev_err(adapter->netdev, "Error: mii_ethtool_gset\n");
ethtool_cmd_speed_set(&cmd, hw->mac.link_speed);
cmd.duplex = hw->mac.link_duplex;
cmd.advertising = hw->phy.autoneg_advertised;
cmd.autoneg = hw->mac.autoneg;
pch_gbe_phy_write_reg_miic(hw, MII_BMCR, BMCR_RESET);
ret = mii_ethtool_sset(&adapter->mii, &cmd);
if (ret)
netdev_err(adapter->netdev, "Error: mii_ethtool_sset\n");
pch_gbe_phy_sw_reset(hw);
pch_gbe_phy_read_reg_miic(hw, PHY_PHYSP_CONTROL, &mii_reg);
mii_reg |= PHYSP_CTRL_ASSERT_CRS_TX;
pch_gbe_phy_write_reg_miic(hw, PHY_PHYSP_CONTROL, mii_reg);
if (adapter->pdata && adapter->pdata->phy_tx_clk_delay)
pch_gbe_phy_tx_clk_delay(hw);
}
int pch_gbe_phy_disable_hibernate(struct pch_gbe_hw *hw)
{
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
u16 mii_reg;
int ret = 0;
switch (hw->phy.id) {
case PHY_AR803X_ID:
netdev_dbg(adapter->netdev,
"Disabling hibernation for AR803X PHY\n");
ret = pch_gbe_phy_write_reg_miic(hw, PHY_AR8031_DBG_OFF,
PHY_AR8031_HIBERNATE);
if (ret)
break;
pch_gbe_phy_read_reg_miic(hw, PHY_AR8031_DBG_DAT, &mii_reg);
mii_reg &= ~PHY_AR8031_PS_HIB_EN;
ret = pch_gbe_phy_write_reg_miic(hw, PHY_AR8031_DBG_DAT,
mii_reg);
break;
default:
netdev_err(adapter->netdev,
"Unknown PHY (%x), could not disable hibernation\n",
hw->phy.id);
return -EINVAL;
}
if (ret)
netdev_err(adapter->netdev,
"Could not disable PHY hibernation\n");
return ret;
}
