s32 pch_gbe_phy_get_id(struct pch_gbe_hw *hw)
{
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
pr_debug("phy->id : 0x%08x phy->revision : 0x%08x\n",
phy->id, phy->revision);
return 0;
}
s32 pch_gbe_phy_read_reg_miic(struct pch_gbe_hw *hw, u32 offset, u16 *data)
{
struct pch_gbe_phy_info *phy = &hw->phy;
if (offset > PHY_MAX_REG_ADDRESS) {
pr_err("PHY Address %d is out of range\n", offset);
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
pr_err("PHY Address %d is out of range\n", offset);
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
inline void pch_gbe_phy_set_rgmii(struct pch_gbe_hw *hw)
{
pch_gbe_phy_sw_reset(hw);
}
void pch_gbe_phy_init_setting(struct pch_gbe_hw *hw)
{
struct pch_gbe_adapter *adapter;
struct ethtool_cmd cmd = { .cmd = ETHTOOL_GSET };
int ret;
u16 mii_reg;
adapter = container_of(hw, struct pch_gbe_adapter, hw);
ret = mii_ethtool_gset(&adapter->mii, &cmd);
if (ret)
pr_err("Error: mii_ethtool_gset\n");
ethtool_cmd_speed_set(&cmd, hw->mac.link_speed);
cmd.duplex = hw->mac.link_duplex;
cmd.advertising = hw->phy.autoneg_advertised;
cmd.autoneg = hw->mac.autoneg;
pch_gbe_phy_write_reg_miic(hw, MII_BMCR, BMCR_RESET);
ret = mii_ethtool_sset(&adapter->mii, &cmd);
if (ret)
pr_err("Error: mii_ethtool_sset\n");
pch_gbe_phy_sw_reset(hw);
pch_gbe_phy_read_reg_miic(hw, PHY_PHYSP_CONTROL, &mii_reg);
mii_reg |= PHYSP_CTRL_ASSERT_CRS_TX;
pch_gbe_phy_write_reg_miic(hw, PHY_PHYSP_CONTROL, mii_reg);
}
