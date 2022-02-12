static void pch_gbe_plat_get_bus_info(struct pch_gbe_hw *hw)
{
hw->bus.type = pch_gbe_bus_type_pci_express;
hw->bus.speed = pch_gbe_bus_speed_2500;
hw->bus.width = pch_gbe_bus_width_pcie_x1;
}
static s32 pch_gbe_plat_init_hw(struct pch_gbe_hw *hw)
{
s32 ret_val;
ret_val = pch_gbe_phy_get_id(hw);
if (ret_val) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "pch_gbe_phy_get_id error\n");
return ret_val;
}
pch_gbe_phy_init_setting(hw);
#ifdef PCH_GBE_MAC_IFOP_RGMII
pch_gbe_phy_set_rgmii(hw);
#endif
return ret_val;
}
static void pch_gbe_plat_init_function_pointers(struct pch_gbe_hw *hw)
{
hw->phy.reset_delay_us = PCH_GBE_PHY_RESET_DELAY_US;
hw->func = &pch_gbe_ops;
}
s32 pch_gbe_hal_setup_init_funcs(struct pch_gbe_hw *hw)
{
if (!hw->reg) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "ERROR: Registers not mapped\n");
return -ENOSYS;
}
pch_gbe_plat_init_function_pointers(hw);
return 0;
}
void pch_gbe_hal_get_bus_info(struct pch_gbe_hw *hw)
{
if (!hw->func->get_bus_info) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "ERROR: configuration\n");
return;
}
hw->func->get_bus_info(hw);
}
s32 pch_gbe_hal_init_hw(struct pch_gbe_hw *hw)
{
if (!hw->func->init_hw) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "ERROR: configuration\n");
return -ENOSYS;
}
return hw->func->init_hw(hw);
}
s32 pch_gbe_hal_read_phy_reg(struct pch_gbe_hw *hw, u32 offset,
u16 *data)
{
if (!hw->func->read_phy_reg)
return 0;
return hw->func->read_phy_reg(hw, offset, data);
}
s32 pch_gbe_hal_write_phy_reg(struct pch_gbe_hw *hw, u32 offset,
u16 data)
{
if (!hw->func->write_phy_reg)
return 0;
return hw->func->write_phy_reg(hw, offset, data);
}
void pch_gbe_hal_phy_hw_reset(struct pch_gbe_hw *hw)
{
if (!hw->func->reset_phy) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "ERROR: configuration\n");
return;
}
hw->func->reset_phy(hw);
}
void pch_gbe_hal_phy_sw_reset(struct pch_gbe_hw *hw)
{
if (!hw->func->sw_reset_phy) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "ERROR: configuration\n");
return;
}
hw->func->sw_reset_phy(hw);
}
s32 pch_gbe_hal_read_mac_addr(struct pch_gbe_hw *hw)
{
if (!hw->func->read_mac_addr) {
struct pch_gbe_adapter *adapter = pch_gbe_hw_to_adapter(hw);
netdev_err(adapter->netdev, "ERROR: configuration\n");
return -ENOSYS;
}
return hw->func->read_mac_addr(hw);
}
void pch_gbe_hal_power_up_phy(struct pch_gbe_hw *hw)
{
if (hw->func->power_up_phy)
hw->func->power_up_phy(hw);
}
void pch_gbe_hal_power_down_phy(struct pch_gbe_hw *hw)
{
if (hw->func->power_down_phy)
hw->func->power_down_phy(hw);
}
