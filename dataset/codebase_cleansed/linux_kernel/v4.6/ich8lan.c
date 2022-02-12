static inline u16 __er16flash(struct e1000_hw *hw, unsigned long reg)
{
return readw(hw->flash_address + reg);
}
static inline u32 __er32flash(struct e1000_hw *hw, unsigned long reg)
{
return readl(hw->flash_address + reg);
}
static inline void __ew16flash(struct e1000_hw *hw, unsigned long reg, u16 val)
{
writew(val, hw->flash_address + reg);
}
static inline void __ew32flash(struct e1000_hw *hw, unsigned long reg, u32 val)
{
writel(val, hw->flash_address + reg);
}
static bool e1000_phy_is_accessible_pchlan(struct e1000_hw *hw)
{
u16 phy_reg = 0;
u32 phy_id = 0;
s32 ret_val = 0;
u16 retry_count;
u32 mac_reg = 0;
for (retry_count = 0; retry_count < 2; retry_count++) {
ret_val = e1e_rphy_locked(hw, MII_PHYSID1, &phy_reg);
if (ret_val || (phy_reg == 0xFFFF))
continue;
phy_id = (u32)(phy_reg << 16);
ret_val = e1e_rphy_locked(hw, MII_PHYSID2, &phy_reg);
if (ret_val || (phy_reg == 0xFFFF)) {
phy_id = 0;
continue;
}
phy_id |= (u32)(phy_reg & PHY_REVISION_MASK);
break;
}
if (hw->phy.id) {
if (hw->phy.id == phy_id)
goto out;
} else if (phy_id) {
hw->phy.id = phy_id;
hw->phy.revision = (u32)(phy_reg & ~PHY_REVISION_MASK);
goto out;
}
if (hw->mac.type < e1000_pch_lpt) {
hw->phy.ops.release(hw);
ret_val = e1000_set_mdio_slow_mode_hv(hw);
if (!ret_val)
ret_val = e1000e_get_phy_id(hw);
hw->phy.ops.acquire(hw);
}
if (ret_val)
return false;
out:
if ((hw->mac.type == e1000_pch_lpt) || (hw->mac.type == e1000_pch_spt)) {
if (!(er32(FWSM) & E1000_ICH_FWSM_FW_VALID)) {
e1e_rphy_locked(hw, CV_SMB_CTRL, &phy_reg);
phy_reg &= ~CV_SMB_CTRL_FORCE_SMBUS;
e1e_wphy_locked(hw, CV_SMB_CTRL, phy_reg);
mac_reg = er32(CTRL_EXT);
mac_reg &= ~E1000_CTRL_EXT_FORCE_SMBUS;
ew32(CTRL_EXT, mac_reg);
}
}
return true;
}
static void e1000_toggle_lanphypc_pch_lpt(struct e1000_hw *hw)
{
u32 mac_reg;
mac_reg = er32(FEXTNVM3);
mac_reg &= ~E1000_FEXTNVM3_PHY_CFG_COUNTER_MASK;
mac_reg |= E1000_FEXTNVM3_PHY_CFG_COUNTER_50MSEC;
ew32(FEXTNVM3, mac_reg);
mac_reg = er32(CTRL);
mac_reg |= E1000_CTRL_LANPHYPC_OVERRIDE;
mac_reg &= ~E1000_CTRL_LANPHYPC_VALUE;
ew32(CTRL, mac_reg);
e1e_flush();
usleep_range(10, 20);
mac_reg &= ~E1000_CTRL_LANPHYPC_OVERRIDE;
ew32(CTRL, mac_reg);
e1e_flush();
if (hw->mac.type < e1000_pch_lpt) {
msleep(50);
} else {
u16 count = 20;
do {
usleep_range(5000, 10000);
} while (!(er32(CTRL_EXT) & E1000_CTRL_EXT_LPCD) && count--);
msleep(30);
}
}
static s32 e1000_init_phy_workarounds_pchlan(struct e1000_hw *hw)
{
struct e1000_adapter *adapter = hw->adapter;
u32 mac_reg, fwsm = er32(FWSM);
s32 ret_val;
e1000_gate_hw_phy_config_ich8lan(hw, true);
hw->dev_spec.ich8lan.ulp_state = e1000_ulp_state_unknown;
e1000_disable_ulp_lpt_lp(hw, true);
ret_val = hw->phy.ops.acquire(hw);
if (ret_val) {
e_dbg("Failed to initialize PHY flow\n");
goto out;
}
switch (hw->mac.type) {
case e1000_pch_lpt:
case e1000_pch_spt:
if (e1000_phy_is_accessible_pchlan(hw))
break;
mac_reg = er32(CTRL_EXT);
mac_reg |= E1000_CTRL_EXT_FORCE_SMBUS;
ew32(CTRL_EXT, mac_reg);
msleep(50);
case e1000_pch2lan:
if (e1000_phy_is_accessible_pchlan(hw))
break;
case e1000_pchlan:
if ((hw->mac.type == e1000_pchlan) &&
(fwsm & E1000_ICH_FWSM_FW_VALID))
break;
if (hw->phy.ops.check_reset_block(hw)) {
e_dbg("Required LANPHYPC toggle blocked by ME\n");
ret_val = -E1000_ERR_PHY;
break;
}
e1000_toggle_lanphypc_pch_lpt(hw);
if (hw->mac.type >= e1000_pch_lpt) {
if (e1000_phy_is_accessible_pchlan(hw))
break;
mac_reg = er32(CTRL_EXT);
mac_reg &= ~E1000_CTRL_EXT_FORCE_SMBUS;
ew32(CTRL_EXT, mac_reg);
if (e1000_phy_is_accessible_pchlan(hw))
break;
ret_val = -E1000_ERR_PHY;
}
break;
default:
break;
}
hw->phy.ops.release(hw);
if (!ret_val) {
if (hw->phy.ops.check_reset_block(hw)) {
e_err("Reset blocked by ME\n");
goto out;
}
ret_val = e1000e_phy_hw_reset_generic(hw);
if (ret_val)
goto out;
ret_val = hw->phy.ops.check_reset_block(hw);
if (ret_val)
e_err("ME blocked access to PHY after reset\n");
}
out:
if ((hw->mac.type == e1000_pch2lan) &&
!(fwsm & E1000_ICH_FWSM_FW_VALID)) {
usleep_range(10000, 20000);
e1000_gate_hw_phy_config_ich8lan(hw, false);
}
return ret_val;
}
static s32 e1000_init_phy_params_pchlan(struct e1000_hw *hw)
{
struct e1000_phy_info *phy = &hw->phy;
s32 ret_val;
phy->addr = 1;
phy->reset_delay_us = 100;
phy->ops.set_page = e1000_set_page_igp;
phy->ops.read_reg = e1000_read_phy_reg_hv;
phy->ops.read_reg_locked = e1000_read_phy_reg_hv_locked;
phy->ops.read_reg_page = e1000_read_phy_reg_page_hv;
phy->ops.set_d0_lplu_state = e1000_set_lplu_state_pchlan;
phy->ops.set_d3_lplu_state = e1000_set_lplu_state_pchlan;
phy->ops.write_reg = e1000_write_phy_reg_hv;
phy->ops.write_reg_locked = e1000_write_phy_reg_hv_locked;
phy->ops.write_reg_page = e1000_write_phy_reg_page_hv;
phy->ops.power_up = e1000_power_up_phy_copper;
phy->ops.power_down = e1000_power_down_phy_copper_ich8lan;
phy->autoneg_mask = AUTONEG_ADVERTISE_SPEED_DEFAULT;
phy->id = e1000_phy_unknown;
ret_val = e1000_init_phy_workarounds_pchlan(hw);
if (ret_val)
return ret_val;
if (phy->id == e1000_phy_unknown)
switch (hw->mac.type) {
default:
ret_val = e1000e_get_phy_id(hw);
if (ret_val)
return ret_val;
if ((phy->id != 0) && (phy->id != PHY_REVISION_MASK))
break;
case e1000_pch2lan:
case e1000_pch_lpt:
case e1000_pch_spt:
ret_val = e1000_set_mdio_slow_mode_hv(hw);
if (ret_val)
return ret_val;
ret_val = e1000e_get_phy_id(hw);
if (ret_val)
return ret_val;
break;
}
phy->type = e1000e_get_phy_type_from_id(phy->id);
switch (phy->type) {
case e1000_phy_82577:
case e1000_phy_82579:
case e1000_phy_i217:
phy->ops.check_polarity = e1000_check_polarity_82577;
phy->ops.force_speed_duplex =
e1000_phy_force_speed_duplex_82577;
phy->ops.get_cable_length = e1000_get_cable_length_82577;
phy->ops.get_info = e1000_get_phy_info_82577;
phy->ops.commit = e1000e_phy_sw_reset;
break;
case e1000_phy_82578:
phy->ops.check_polarity = e1000_check_polarity_m88;
phy->ops.force_speed_duplex = e1000e_phy_force_speed_duplex_m88;
phy->ops.get_cable_length = e1000e_get_cable_length_m88;
phy->ops.get_info = e1000e_get_phy_info_m88;
break;
default:
ret_val = -E1000_ERR_PHY;
break;
}
return ret_val;
}
static s32 e1000_init_phy_params_ich8lan(struct e1000_hw *hw)
{
struct e1000_phy_info *phy = &hw->phy;
s32 ret_val;
u16 i = 0;
phy->addr = 1;
phy->reset_delay_us = 100;
phy->ops.power_up = e1000_power_up_phy_copper;
phy->ops.power_down = e1000_power_down_phy_copper_ich8lan;
ret_val = e1000e_determine_phy_address(hw);
if (ret_val) {
phy->ops.write_reg = e1000e_write_phy_reg_bm;
phy->ops.read_reg = e1000e_read_phy_reg_bm;
ret_val = e1000e_determine_phy_address(hw);
if (ret_val) {
e_dbg("Cannot determine PHY addr. Erroring out\n");
return ret_val;
}
}
phy->id = 0;
while ((e1000_phy_unknown == e1000e_get_phy_type_from_id(phy->id)) &&
(i++ < 100)) {
usleep_range(1000, 2000);
ret_val = e1000e_get_phy_id(hw);
if (ret_val)
return ret_val;
}
switch (phy->id) {
case IGP03E1000_E_PHY_ID:
phy->type = e1000_phy_igp_3;
phy->autoneg_mask = AUTONEG_ADVERTISE_SPEED_DEFAULT;
phy->ops.read_reg_locked = e1000e_read_phy_reg_igp_locked;
phy->ops.write_reg_locked = e1000e_write_phy_reg_igp_locked;
phy->ops.get_info = e1000e_get_phy_info_igp;
phy->ops.check_polarity = e1000_check_polarity_igp;
phy->ops.force_speed_duplex = e1000e_phy_force_speed_duplex_igp;
break;
case IFE_E_PHY_ID:
case IFE_PLUS_E_PHY_ID:
case IFE_C_E_PHY_ID:
phy->type = e1000_phy_ife;
phy->autoneg_mask = E1000_ALL_NOT_GIG;
phy->ops.get_info = e1000_get_phy_info_ife;
phy->ops.check_polarity = e1000_check_polarity_ife;
phy->ops.force_speed_duplex = e1000_phy_force_speed_duplex_ife;
break;
case BME1000_E_PHY_ID:
phy->type = e1000_phy_bm;
phy->autoneg_mask = AUTONEG_ADVERTISE_SPEED_DEFAULT;
phy->ops.read_reg = e1000e_read_phy_reg_bm;
phy->ops.write_reg = e1000e_write_phy_reg_bm;
phy->ops.commit = e1000e_phy_sw_reset;
phy->ops.get_info = e1000e_get_phy_info_m88;
phy->ops.check_polarity = e1000_check_polarity_m88;
phy->ops.force_speed_duplex = e1000e_phy_force_speed_duplex_m88;
break;
default:
return -E1000_ERR_PHY;
}
return 0;
}
static s32 e1000_init_nvm_params_ich8lan(struct e1000_hw *hw)
{
struct e1000_nvm_info *nvm = &hw->nvm;
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u32 gfpreg, sector_base_addr, sector_end_addr;
u16 i;
u32 nvm_size;
nvm->type = e1000_nvm_flash_sw;
if (hw->mac.type == e1000_pch_spt) {
nvm->flash_base_addr = 0;
nvm_size = (((er32(STRAP) >> 1) & 0x1F) + 1)
* NVM_SIZE_MULTIPLIER;
nvm->flash_bank_size = nvm_size / 2;
nvm->flash_bank_size /= sizeof(u16);
hw->flash_address = hw->hw_addr + E1000_FLASH_BASE_ADDR;
} else {
if (!hw->flash_address) {
e_dbg("ERROR: Flash registers not mapped\n");
return -E1000_ERR_CONFIG;
}
gfpreg = er32flash(ICH_FLASH_GFPREG);
sector_base_addr = gfpreg & FLASH_GFPREG_BASE_MASK;
sector_end_addr = ((gfpreg >> 16) & FLASH_GFPREG_BASE_MASK) + 1;
nvm->flash_base_addr = sector_base_addr
<< FLASH_SECTOR_ADDR_SHIFT;
nvm->flash_bank_size = ((sector_end_addr - sector_base_addr)
<< FLASH_SECTOR_ADDR_SHIFT);
nvm->flash_bank_size /= 2;
nvm->flash_bank_size /= sizeof(u16);
}
nvm->word_size = E1000_ICH8_SHADOW_RAM_WORDS;
for (i = 0; i < nvm->word_size; i++) {
dev_spec->shadow_ram[i].modified = false;
dev_spec->shadow_ram[i].value = 0xFFFF;
}
return 0;
}
static s32 e1000_init_mac_params_ich8lan(struct e1000_hw *hw)
{
struct e1000_mac_info *mac = &hw->mac;
hw->phy.media_type = e1000_media_type_copper;
mac->mta_reg_count = 32;
mac->rar_entry_count = E1000_ICH_RAR_ENTRIES;
if (mac->type == e1000_ich8lan)
mac->rar_entry_count--;
mac->has_fwsm = true;
mac->arc_subsystem_valid = false;
mac->adaptive_ifs = true;
switch (mac->type) {
case e1000_ich8lan:
case e1000_ich9lan:
case e1000_ich10lan:
mac->ops.check_mng_mode = e1000_check_mng_mode_ich8lan;
mac->ops.id_led_init = e1000e_id_led_init_generic;
mac->ops.blink_led = e1000e_blink_led_generic;
mac->ops.setup_led = e1000e_setup_led_generic;
mac->ops.cleanup_led = e1000_cleanup_led_ich8lan;
mac->ops.led_on = e1000_led_on_ich8lan;
mac->ops.led_off = e1000_led_off_ich8lan;
break;
case e1000_pch2lan:
mac->rar_entry_count = E1000_PCH2_RAR_ENTRIES;
mac->ops.rar_set = e1000_rar_set_pch2lan;
case e1000_pch_lpt:
case e1000_pch_spt:
case e1000_pchlan:
mac->ops.check_mng_mode = e1000_check_mng_mode_pchlan;
mac->ops.id_led_init = e1000_id_led_init_pchlan;
mac->ops.setup_led = e1000_setup_led_pchlan;
mac->ops.cleanup_led = e1000_cleanup_led_pchlan;
mac->ops.led_on = e1000_led_on_pchlan;
mac->ops.led_off = e1000_led_off_pchlan;
break;
default:
break;
}
if ((mac->type == e1000_pch_lpt) || (mac->type == e1000_pch_spt)) {
mac->rar_entry_count = E1000_PCH_LPT_RAR_ENTRIES;
mac->ops.rar_set = e1000_rar_set_pch_lpt;
mac->ops.setup_physical_interface =
e1000_setup_copper_link_pch_lpt;
mac->ops.rar_get_count = e1000_rar_get_count_pch_lpt;
}
if (mac->type == e1000_ich8lan)
e1000e_set_kmrn_lock_loss_workaround_ich8lan(hw, true);
return 0;
}
static s32 __e1000_access_emi_reg_locked(struct e1000_hw *hw, u16 address,
u16 *data, bool read)
{
s32 ret_val;
ret_val = e1e_wphy_locked(hw, I82579_EMI_ADDR, address);
if (ret_val)
return ret_val;
if (read)
ret_val = e1e_rphy_locked(hw, I82579_EMI_DATA, data);
else
ret_val = e1e_wphy_locked(hw, I82579_EMI_DATA, *data);
return ret_val;
}
s32 e1000_read_emi_reg_locked(struct e1000_hw *hw, u16 addr, u16 *data)
{
return __e1000_access_emi_reg_locked(hw, addr, data, true);
}
s32 e1000_write_emi_reg_locked(struct e1000_hw *hw, u16 addr, u16 data)
{
return __e1000_access_emi_reg_locked(hw, addr, &data, false);
}
s32 e1000_set_eee_pchlan(struct e1000_hw *hw)
{
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
s32 ret_val;
u16 lpa, pcs_status, adv, adv_addr, lpi_ctrl, data;
switch (hw->phy.type) {
case e1000_phy_82579:
lpa = I82579_EEE_LP_ABILITY;
pcs_status = I82579_EEE_PCS_STATUS;
adv_addr = I82579_EEE_ADVERTISEMENT;
break;
case e1000_phy_i217:
lpa = I217_EEE_LP_ABILITY;
pcs_status = I217_EEE_PCS_STATUS;
adv_addr = I217_EEE_ADVERTISEMENT;
break;
default:
return 0;
}
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
ret_val = e1e_rphy_locked(hw, I82579_LPI_CTRL, &lpi_ctrl);
if (ret_val)
goto release;
lpi_ctrl &= ~I82579_LPI_CTRL_ENABLE_MASK;
if (!dev_spec->eee_disable) {
ret_val = e1000_read_emi_reg_locked(hw, lpa,
&dev_spec->eee_lp_ability);
if (ret_val)
goto release;
ret_val = e1000_read_emi_reg_locked(hw, adv_addr, &adv);
if (ret_val)
goto release;
if (adv & dev_spec->eee_lp_ability & I82579_EEE_1000_SUPPORTED)
lpi_ctrl |= I82579_LPI_CTRL_1000_ENABLE;
if (adv & dev_spec->eee_lp_ability & I82579_EEE_100_SUPPORTED) {
e1e_rphy_locked(hw, MII_LPA, &data);
if (data & LPA_100FULL)
lpi_ctrl |= I82579_LPI_CTRL_100_ENABLE;
else
dev_spec->eee_lp_ability &=
~I82579_EEE_100_SUPPORTED;
}
}
if (hw->phy.type == e1000_phy_82579) {
ret_val = e1000_read_emi_reg_locked(hw, I82579_LPI_PLL_SHUT,
&data);
if (ret_val)
goto release;
data &= ~I82579_LPI_100_PLL_SHUT;
ret_val = e1000_write_emi_reg_locked(hw, I82579_LPI_PLL_SHUT,
data);
}
ret_val = e1000_read_emi_reg_locked(hw, pcs_status, &data);
if (ret_val)
goto release;
ret_val = e1e_wphy_locked(hw, I82579_LPI_CTRL, lpi_ctrl);
release:
hw->phy.ops.release(hw);
return ret_val;
}
static s32 e1000_k1_workaround_lpt_lp(struct e1000_hw *hw, bool link)
{
u32 fextnvm6 = er32(FEXTNVM6);
u32 status = er32(STATUS);
s32 ret_val = 0;
u16 reg;
if (link && (status & E1000_STATUS_SPEED_1000)) {
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
ret_val =
e1000e_read_kmrn_reg_locked(hw, E1000_KMRNCTRLSTA_K1_CONFIG,
&reg);
if (ret_val)
goto release;
ret_val =
e1000e_write_kmrn_reg_locked(hw,
E1000_KMRNCTRLSTA_K1_CONFIG,
reg &
~E1000_KMRNCTRLSTA_K1_ENABLE);
if (ret_val)
goto release;
usleep_range(10, 20);
ew32(FEXTNVM6, fextnvm6 | E1000_FEXTNVM6_REQ_PLL_CLK);
ret_val =
e1000e_write_kmrn_reg_locked(hw,
E1000_KMRNCTRLSTA_K1_CONFIG,
reg);
release:
hw->phy.ops.release(hw);
} else {
fextnvm6 &= ~E1000_FEXTNVM6_REQ_PLL_CLK;
if ((hw->phy.revision > 5) || !link ||
((status & E1000_STATUS_SPEED_100) &&
(status & E1000_STATUS_FD)))
goto update_fextnvm6;
ret_val = e1e_rphy(hw, I217_INBAND_CTRL, &reg);
if (ret_val)
return ret_val;
reg &= ~I217_INBAND_CTRL_LINK_STAT_TX_TIMEOUT_MASK;
if (status & E1000_STATUS_SPEED_100) {
reg |= 5 << I217_INBAND_CTRL_LINK_STAT_TX_TIMEOUT_SHIFT;
fextnvm6 &= ~E1000_FEXTNVM6_ENABLE_K1_ENTRY_CONDITION;
} else {
reg |= 50 <<
I217_INBAND_CTRL_LINK_STAT_TX_TIMEOUT_SHIFT;
fextnvm6 |= E1000_FEXTNVM6_ENABLE_K1_ENTRY_CONDITION;
}
ret_val = e1e_wphy(hw, I217_INBAND_CTRL, reg);
if (ret_val)
return ret_val;
update_fextnvm6:
ew32(FEXTNVM6, fextnvm6);
}
return ret_val;
}
static s32 e1000_platform_pm_pch_lpt(struct e1000_hw *hw, bool link)
{
u32 reg = link << (E1000_LTRV_REQ_SHIFT + E1000_LTRV_NOSNOOP_SHIFT) |
link << E1000_LTRV_REQ_SHIFT | E1000_LTRV_SEND;
u16 lat_enc = 0;
if (link) {
u16 speed, duplex, scale = 0;
u16 max_snoop, max_nosnoop;
u16 max_ltr_enc;
u64 value;
u32 rxa;
if (!hw->adapter->max_frame_size) {
e_dbg("max_frame_size not set.\n");
return -E1000_ERR_CONFIG;
}
hw->mac.ops.get_link_up_info(hw, &speed, &duplex);
if (!speed) {
e_dbg("Speed not set.\n");
return -E1000_ERR_CONFIG;
}
rxa = er32(PBA) & E1000_PBA_RXA_MASK;
rxa *= 512;
value = (rxa > hw->adapter->max_frame_size) ?
(rxa - hw->adapter->max_frame_size) * (16000 / speed) :
0;
while (value > PCI_LTR_VALUE_MASK) {
scale++;
value = DIV_ROUND_UP(value, (1 << 5));
}
if (scale > E1000_LTRV_SCALE_MAX) {
e_dbg("Invalid LTR latency scale %d\n", scale);
return -E1000_ERR_CONFIG;
}
lat_enc = (u16)((scale << PCI_LTR_SCALE_SHIFT) | value);
pci_read_config_word(hw->adapter->pdev, E1000_PCI_LTR_CAP_LPT,
&max_snoop);
pci_read_config_word(hw->adapter->pdev,
E1000_PCI_LTR_CAP_LPT + 2, &max_nosnoop);
max_ltr_enc = max_t(u16, max_snoop, max_nosnoop);
if (lat_enc > max_ltr_enc)
lat_enc = max_ltr_enc;
}
reg |= lat_enc | (lat_enc << E1000_LTRV_NOSNOOP_SHIFT);
ew32(LTRV, reg);
return 0;
}
s32 e1000_enable_ulp_lpt_lp(struct e1000_hw *hw, bool to_sx)
{
u32 mac_reg;
s32 ret_val = 0;
u16 phy_reg;
u16 oem_reg = 0;
if ((hw->mac.type < e1000_pch_lpt) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_LPT_I217_LM) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_LPT_I217_V) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_I218_LM2) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_I218_V2) ||
(hw->dev_spec.ich8lan.ulp_state == e1000_ulp_state_on))
return 0;
if (er32(FWSM) & E1000_ICH_FWSM_FW_VALID) {
mac_reg = er32(H2ME);
mac_reg |= E1000_H2ME_ULP | E1000_H2ME_ENFORCE_SETTINGS;
ew32(H2ME, mac_reg);
goto out;
}
if (!to_sx) {
int i = 0;
while (!(er32(FEXT) & E1000_FEXT_PHY_CABLE_DISCONNECTED)) {
if (er32(STATUS) & E1000_STATUS_LU)
return -E1000_ERR_PHY;
if (i++ == 100)
break;
msleep(50);
}
e_dbg("CABLE_DISCONNECTED %s set after %dmsec\n",
(er32(FEXT) &
E1000_FEXT_PHY_CABLE_DISCONNECTED) ? "" : "not", i * 50);
}
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
goto out;
ret_val = e1000_read_phy_reg_hv_locked(hw, CV_SMB_CTRL, &phy_reg);
if (ret_val)
goto release;
phy_reg |= CV_SMB_CTRL_FORCE_SMBUS;
e1000_write_phy_reg_hv_locked(hw, CV_SMB_CTRL, phy_reg);
mac_reg = er32(CTRL_EXT);
mac_reg |= E1000_CTRL_EXT_FORCE_SMBUS;
ew32(CTRL_EXT, mac_reg);
if ((hw->phy.type == e1000_phy_i217) && (hw->phy.revision == 6)) {
ret_val = e1000_read_phy_reg_hv_locked(hw, HV_OEM_BITS,
&oem_reg);
if (ret_val)
goto release;
phy_reg = oem_reg;
phy_reg |= HV_OEM_BITS_LPLU | HV_OEM_BITS_GBE_DIS;
ret_val = e1000_write_phy_reg_hv_locked(hw, HV_OEM_BITS,
phy_reg);
if (ret_val)
goto release;
}
ret_val = e1000_read_phy_reg_hv_locked(hw, I218_ULP_CONFIG1, &phy_reg);
if (ret_val)
goto release;
phy_reg |= (I218_ULP_CONFIG1_RESET_TO_SMBUS |
I218_ULP_CONFIG1_DISABLE_SMB_PERST);
if (to_sx) {
if (er32(WUFC) & E1000_WUFC_LNKC)
phy_reg |= I218_ULP_CONFIG1_WOL_HOST;
else
phy_reg &= ~I218_ULP_CONFIG1_WOL_HOST;
phy_reg |= I218_ULP_CONFIG1_STICKY_ULP;
phy_reg &= ~I218_ULP_CONFIG1_INBAND_EXIT;
} else {
phy_reg |= I218_ULP_CONFIG1_INBAND_EXIT;
phy_reg &= ~I218_ULP_CONFIG1_STICKY_ULP;
phy_reg &= ~I218_ULP_CONFIG1_WOL_HOST;
}
e1000_write_phy_reg_hv_locked(hw, I218_ULP_CONFIG1, phy_reg);
mac_reg = er32(FEXTNVM7);
mac_reg |= E1000_FEXTNVM7_DISABLE_SMB_PERST;
ew32(FEXTNVM7, mac_reg);
phy_reg |= I218_ULP_CONFIG1_START;
e1000_write_phy_reg_hv_locked(hw, I218_ULP_CONFIG1, phy_reg);
if ((hw->phy.type == e1000_phy_i217) && (hw->phy.revision == 6) &&
to_sx && (er32(STATUS) & E1000_STATUS_LU)) {
ret_val = e1000_write_phy_reg_hv_locked(hw, HV_OEM_BITS,
oem_reg);
if (ret_val)
goto release;
}
release:
hw->phy.ops.release(hw);
out:
if (ret_val)
e_dbg("Error in ULP enable flow: %d\n", ret_val);
else
hw->dev_spec.ich8lan.ulp_state = e1000_ulp_state_on;
return ret_val;
}
static s32 e1000_disable_ulp_lpt_lp(struct e1000_hw *hw, bool force)
{
s32 ret_val = 0;
u32 mac_reg;
u16 phy_reg;
int i = 0;
if ((hw->mac.type < e1000_pch_lpt) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_LPT_I217_LM) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_LPT_I217_V) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_I218_LM2) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_I218_V2) ||
(hw->dev_spec.ich8lan.ulp_state == e1000_ulp_state_off))
return 0;
if (er32(FWSM) & E1000_ICH_FWSM_FW_VALID) {
if (force) {
mac_reg = er32(H2ME);
mac_reg &= ~E1000_H2ME_ULP;
mac_reg |= E1000_H2ME_ENFORCE_SETTINGS;
ew32(H2ME, mac_reg);
}
while (er32(FWSM) & E1000_FWSM_ULP_CFG_DONE) {
if (i++ == 30) {
ret_val = -E1000_ERR_PHY;
goto out;
}
usleep_range(10000, 20000);
}
e_dbg("ULP_CONFIG_DONE cleared after %dmsec\n", i * 10);
if (force) {
mac_reg = er32(H2ME);
mac_reg &= ~E1000_H2ME_ENFORCE_SETTINGS;
ew32(H2ME, mac_reg);
} else {
mac_reg = er32(H2ME);
mac_reg &= ~E1000_H2ME_ULP;
ew32(H2ME, mac_reg);
}
goto out;
}
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
goto out;
if (force)
e1000_toggle_lanphypc_pch_lpt(hw);
ret_val = e1000_read_phy_reg_hv_locked(hw, CV_SMB_CTRL, &phy_reg);
if (ret_val) {
mac_reg = er32(CTRL_EXT);
mac_reg |= E1000_CTRL_EXT_FORCE_SMBUS;
ew32(CTRL_EXT, mac_reg);
msleep(50);
ret_val = e1000_read_phy_reg_hv_locked(hw, CV_SMB_CTRL,
&phy_reg);
if (ret_val)
goto release;
}
phy_reg &= ~CV_SMB_CTRL_FORCE_SMBUS;
e1000_write_phy_reg_hv_locked(hw, CV_SMB_CTRL, phy_reg);
mac_reg = er32(CTRL_EXT);
mac_reg &= ~E1000_CTRL_EXT_FORCE_SMBUS;
ew32(CTRL_EXT, mac_reg);
ret_val = e1000_read_phy_reg_hv_locked(hw, HV_PM_CTRL, &phy_reg);
if (ret_val)
goto release;
phy_reg |= HV_PM_CTRL_K1_ENABLE;
e1000_write_phy_reg_hv_locked(hw, HV_PM_CTRL, phy_reg);
ret_val = e1000_read_phy_reg_hv_locked(hw, I218_ULP_CONFIG1, &phy_reg);
if (ret_val)
goto release;
phy_reg &= ~(I218_ULP_CONFIG1_IND |
I218_ULP_CONFIG1_STICKY_ULP |
I218_ULP_CONFIG1_RESET_TO_SMBUS |
I218_ULP_CONFIG1_WOL_HOST |
I218_ULP_CONFIG1_INBAND_EXIT |
I218_ULP_CONFIG1_EN_ULP_LANPHYPC |
I218_ULP_CONFIG1_DIS_CLR_STICKY_ON_PERST |
I218_ULP_CONFIG1_DISABLE_SMB_PERST);
e1000_write_phy_reg_hv_locked(hw, I218_ULP_CONFIG1, phy_reg);
phy_reg |= I218_ULP_CONFIG1_START;
e1000_write_phy_reg_hv_locked(hw, I218_ULP_CONFIG1, phy_reg);
mac_reg = er32(FEXTNVM7);
mac_reg &= ~E1000_FEXTNVM7_DISABLE_SMB_PERST;
ew32(FEXTNVM7, mac_reg);
release:
hw->phy.ops.release(hw);
if (force) {
e1000_phy_hw_reset(hw);
msleep(50);
}
out:
if (ret_val)
e_dbg("Error in ULP disable flow: %d\n", ret_val);
else
hw->dev_spec.ich8lan.ulp_state = e1000_ulp_state_off;
return ret_val;
}
static s32 e1000_check_for_copper_link_ich8lan(struct e1000_hw *hw)
{
struct e1000_mac_info *mac = &hw->mac;
s32 ret_val, tipg_reg = 0;
u16 emi_addr, emi_val = 0;
bool link;
u16 phy_reg;
if (!mac->get_link_status)
return 0;
ret_val = e1000e_phy_has_link_generic(hw, 1, 0, &link);
if (ret_val)
return ret_val;
if (hw->mac.type == e1000_pchlan) {
ret_val = e1000_k1_gig_workaround_hv(hw, link);
if (ret_val)
return ret_val;
}
if (((hw->mac.type == e1000_pch2lan) ||
(hw->mac.type == e1000_pch_lpt) ||
(hw->mac.type == e1000_pch_spt)) && link) {
u16 speed, duplex;
e1000e_get_speed_and_duplex_copper(hw, &speed, &duplex);
tipg_reg = er32(TIPG);
tipg_reg &= ~E1000_TIPG_IPGT_MASK;
if (duplex == HALF_DUPLEX && speed == SPEED_10) {
tipg_reg |= 0xFF;
emi_val = 0;
} else if (hw->mac.type == e1000_pch_spt &&
duplex == FULL_DUPLEX && speed != SPEED_1000) {
tipg_reg |= 0xC;
emi_val = 1;
} else {
tipg_reg |= 0x08;
emi_val = 1;
}
ew32(TIPG, tipg_reg);
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
if (hw->mac.type == e1000_pch2lan)
emi_addr = I82579_RX_CONFIG;
else
emi_addr = I217_RX_CONFIG;
ret_val = e1000_write_emi_reg_locked(hw, emi_addr, emi_val);
if (hw->mac.type == e1000_pch_lpt ||
hw->mac.type == e1000_pch_spt) {
u16 phy_reg;
e1e_rphy_locked(hw, I217_PLL_CLOCK_GATE_REG, &phy_reg);
phy_reg &= ~I217_PLL_CLOCK_GATE_MASK;
if (speed == SPEED_100 || speed == SPEED_10)
phy_reg |= 0x3E8;
else
phy_reg |= 0xFA;
e1e_wphy_locked(hw, I217_PLL_CLOCK_GATE_REG, phy_reg);
}
hw->phy.ops.release(hw);
if (ret_val)
return ret_val;
if (hw->mac.type == e1000_pch_spt) {
u16 data;
u16 ptr_gap;
if (speed == SPEED_1000) {
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
ret_val = e1e_rphy_locked(hw,
PHY_REG(776, 20),
&data);
if (ret_val) {
hw->phy.ops.release(hw);
return ret_val;
}
ptr_gap = (data & (0x3FF << 2)) >> 2;
if (ptr_gap < 0x18) {
data &= ~(0x3FF << 2);
data |= (0x18 << 2);
ret_val =
e1e_wphy_locked(hw,
PHY_REG(776, 20),
data);
}
hw->phy.ops.release(hw);
if (ret_val)
return ret_val;
} else {
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
ret_val = e1e_wphy_locked(hw,
PHY_REG(776, 20),
0xC023);
hw->phy.ops.release(hw);
if (ret_val)
return ret_val;
}
}
}
if ((hw->mac.type == e1000_pch_lpt) || (hw->mac.type == e1000_pch_spt)) {
u32 mac_reg;
mac_reg = er32(FEXTNVM4);
mac_reg &= ~E1000_FEXTNVM4_BEACON_DURATION_MASK;
mac_reg |= E1000_FEXTNVM4_BEACON_DURATION_8USEC;
ew32(FEXTNVM4, mac_reg);
}
if ((hw->adapter->pdev->device == E1000_DEV_ID_PCH_LPTLP_I218_LM) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_LPTLP_I218_V) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_I218_LM3) ||
(hw->adapter->pdev->device == E1000_DEV_ID_PCH_I218_V3)) {
ret_val = e1000_k1_workaround_lpt_lp(hw, link);
if (ret_val)
return ret_val;
}
if ((hw->mac.type == e1000_pch_lpt) ||
(hw->mac.type == e1000_pch_spt)) {
ret_val = e1000_platform_pm_pch_lpt(hw, link);
if (ret_val)
return ret_val;
}
hw->dev_spec.ich8lan.eee_lp_ability = 0;
if (hw->mac.type == e1000_pch_spt) {
u32 pcieanacfg = er32(PCIEANACFG);
u32 fextnvm6 = er32(FEXTNVM6);
if (pcieanacfg & E1000_FEXTNVM6_K1_OFF_ENABLE)
fextnvm6 |= E1000_FEXTNVM6_K1_OFF_ENABLE;
else
fextnvm6 &= ~E1000_FEXTNVM6_K1_OFF_ENABLE;
ew32(FEXTNVM6, fextnvm6);
}
if (!link)
return 0;
mac->get_link_status = false;
switch (hw->mac.type) {
case e1000_pch2lan:
ret_val = e1000_k1_workaround_lv(hw);
if (ret_val)
return ret_val;
case e1000_pchlan:
if (hw->phy.type == e1000_phy_82578) {
ret_val = e1000_link_stall_workaround_hv(hw);
if (ret_val)
return ret_val;
}
e1e_rphy(hw, HV_KMRN_FIFO_CTRLSTA, &phy_reg);
phy_reg &= ~HV_KMRN_FIFO_CTRLSTA_PREAMBLE_MASK;
if ((er32(STATUS) & E1000_STATUS_FD) != E1000_STATUS_FD)
phy_reg |= (1 << HV_KMRN_FIFO_CTRLSTA_PREAMBLE_SHIFT);
e1e_wphy(hw, HV_KMRN_FIFO_CTRLSTA, phy_reg);
break;
default:
break;
}
e1000e_check_downshift(hw);
if (hw->phy.type > e1000_phy_82579) {
ret_val = e1000_set_eee_pchlan(hw);
if (ret_val)
return ret_val;
}
if (!mac->autoneg)
return -E1000_ERR_CONFIG;
mac->ops.config_collision_dist(hw);
ret_val = e1000e_config_fc_after_link_up(hw);
if (ret_val)
e_dbg("Error configuring flow control\n");
return ret_val;
}
static s32 e1000_get_variants_ich8lan(struct e1000_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
s32 rc;
rc = e1000_init_mac_params_ich8lan(hw);
if (rc)
return rc;
rc = e1000_init_nvm_params_ich8lan(hw);
if (rc)
return rc;
switch (hw->mac.type) {
case e1000_ich8lan:
case e1000_ich9lan:
case e1000_ich10lan:
rc = e1000_init_phy_params_ich8lan(hw);
break;
case e1000_pchlan:
case e1000_pch2lan:
case e1000_pch_lpt:
case e1000_pch_spt:
rc = e1000_init_phy_params_pchlan(hw);
break;
default:
break;
}
if (rc)
return rc;
if ((adapter->hw.phy.type == e1000_phy_ife) ||
((adapter->hw.mac.type >= e1000_pch2lan) &&
(!(er32(CTRL_EXT) & E1000_CTRL_EXT_LSECCK)))) {
adapter->flags &= ~FLAG_HAS_JUMBO_FRAMES;
adapter->max_hw_frame_size = VLAN_ETH_FRAME_LEN + ETH_FCS_LEN;
hw->mac.ops.blink_led = NULL;
}
if ((adapter->hw.mac.type == e1000_ich8lan) &&
(adapter->hw.phy.type != e1000_phy_ife))
adapter->flags |= FLAG_LSC_GIG_SPEED_DROP;
if ((adapter->hw.mac.type == e1000_pch2lan) &&
(er32(FWSM) & E1000_ICH_FWSM_FW_VALID))
adapter->flags2 |= FLAG2_PCIM2PCI_ARBITER_WA;
return 0;
}
static s32 e1000_acquire_nvm_ich8lan(struct e1000_hw __always_unused *hw)
{
mutex_lock(&nvm_mutex);
return 0;
}
static void e1000_release_nvm_ich8lan(struct e1000_hw __always_unused *hw)
{
mutex_unlock(&nvm_mutex);
}
static s32 e1000_acquire_swflag_ich8lan(struct e1000_hw *hw)
{
u32 extcnf_ctrl, timeout = PHY_CFG_TIMEOUT;
s32 ret_val = 0;
if (test_and_set_bit(__E1000_ACCESS_SHARED_RESOURCE,
&hw->adapter->state)) {
e_dbg("contention for Phy access\n");
return -E1000_ERR_PHY;
}
while (timeout) {
extcnf_ctrl = er32(EXTCNF_CTRL);
if (!(extcnf_ctrl & E1000_EXTCNF_CTRL_SWFLAG))
break;
mdelay(1);
timeout--;
}
if (!timeout) {
e_dbg("SW has already locked the resource.\n");
ret_val = -E1000_ERR_CONFIG;
goto out;
}
timeout = SW_FLAG_TIMEOUT;
extcnf_ctrl |= E1000_EXTCNF_CTRL_SWFLAG;
ew32(EXTCNF_CTRL, extcnf_ctrl);
while (timeout) {
extcnf_ctrl = er32(EXTCNF_CTRL);
if (extcnf_ctrl & E1000_EXTCNF_CTRL_SWFLAG)
break;
mdelay(1);
timeout--;
}
if (!timeout) {
e_dbg("Failed to acquire the semaphore, FW or HW has it: FWSM=0x%8.8x EXTCNF_CTRL=0x%8.8x)\n",
er32(FWSM), extcnf_ctrl);
extcnf_ctrl &= ~E1000_EXTCNF_CTRL_SWFLAG;
ew32(EXTCNF_CTRL, extcnf_ctrl);
ret_val = -E1000_ERR_CONFIG;
goto out;
}
out:
if (ret_val)
clear_bit(__E1000_ACCESS_SHARED_RESOURCE, &hw->adapter->state);
return ret_val;
}
static void e1000_release_swflag_ich8lan(struct e1000_hw *hw)
{
u32 extcnf_ctrl;
extcnf_ctrl = er32(EXTCNF_CTRL);
if (extcnf_ctrl & E1000_EXTCNF_CTRL_SWFLAG) {
extcnf_ctrl &= ~E1000_EXTCNF_CTRL_SWFLAG;
ew32(EXTCNF_CTRL, extcnf_ctrl);
} else {
e_dbg("Semaphore unexpectedly released by sw/fw/hw\n");
}
clear_bit(__E1000_ACCESS_SHARED_RESOURCE, &hw->adapter->state);
}
static bool e1000_check_mng_mode_ich8lan(struct e1000_hw *hw)
{
u32 fwsm;
fwsm = er32(FWSM);
return (fwsm & E1000_ICH_FWSM_FW_VALID) &&
((fwsm & E1000_FWSM_MODE_MASK) ==
(E1000_ICH_MNG_IAMT_MODE << E1000_FWSM_MODE_SHIFT));
}
static bool e1000_check_mng_mode_pchlan(struct e1000_hw *hw)
{
u32 fwsm;
fwsm = er32(FWSM);
return (fwsm & E1000_ICH_FWSM_FW_VALID) &&
(fwsm & (E1000_ICH_MNG_IAMT_MODE << E1000_FWSM_MODE_SHIFT));
}
static int e1000_rar_set_pch2lan(struct e1000_hw *hw, u8 *addr, u32 index)
{
u32 rar_low, rar_high;
rar_low = ((u32)addr[0] |
((u32)addr[1] << 8) |
((u32)addr[2] << 16) | ((u32)addr[3] << 24));
rar_high = ((u32)addr[4] | ((u32)addr[5] << 8));
if (rar_low || rar_high)
rar_high |= E1000_RAH_AV;
if (index == 0) {
ew32(RAL(index), rar_low);
e1e_flush();
ew32(RAH(index), rar_high);
e1e_flush();
return 0;
}
if (index < (u32)(hw->mac.rar_entry_count)) {
s32 ret_val;
ret_val = e1000_acquire_swflag_ich8lan(hw);
if (ret_val)
goto out;
ew32(SHRAL(index - 1), rar_low);
e1e_flush();
ew32(SHRAH(index - 1), rar_high);
e1e_flush();
e1000_release_swflag_ich8lan(hw);
if ((er32(SHRAL(index - 1)) == rar_low) &&
(er32(SHRAH(index - 1)) == rar_high))
return 0;
e_dbg("SHRA[%d] might be locked by ME - FWSM=0x%8.8x\n",
(index - 1), er32(FWSM));
}
out:
e_dbg("Failed to write receive address at index %d\n", index);
return -E1000_ERR_CONFIG;
}
static u32 e1000_rar_get_count_pch_lpt(struct e1000_hw *hw)
{
u32 wlock_mac;
u32 num_entries;
wlock_mac = er32(FWSM) & E1000_FWSM_WLOCK_MAC_MASK;
wlock_mac >>= E1000_FWSM_WLOCK_MAC_SHIFT;
switch (wlock_mac) {
case 0:
num_entries = hw->mac.rar_entry_count;
break;
case 1:
num_entries = 1;
break;
default:
num_entries = wlock_mac + 1;
break;
}
return num_entries;
}
static int e1000_rar_set_pch_lpt(struct e1000_hw *hw, u8 *addr, u32 index)
{
u32 rar_low, rar_high;
u32 wlock_mac;
rar_low = ((u32)addr[0] | ((u32)addr[1] << 8) |
((u32)addr[2] << 16) | ((u32)addr[3] << 24));
rar_high = ((u32)addr[4] | ((u32)addr[5] << 8));
if (rar_low || rar_high)
rar_high |= E1000_RAH_AV;
if (index == 0) {
ew32(RAL(index), rar_low);
e1e_flush();
ew32(RAH(index), rar_high);
e1e_flush();
return 0;
}
if (index < hw->mac.rar_entry_count) {
wlock_mac = er32(FWSM) & E1000_FWSM_WLOCK_MAC_MASK;
wlock_mac >>= E1000_FWSM_WLOCK_MAC_SHIFT;
if (wlock_mac == 1)
goto out;
if ((wlock_mac == 0) || (index <= wlock_mac)) {
s32 ret_val;
ret_val = e1000_acquire_swflag_ich8lan(hw);
if (ret_val)
goto out;
ew32(SHRAL_PCH_LPT(index - 1), rar_low);
e1e_flush();
ew32(SHRAH_PCH_LPT(index - 1), rar_high);
e1e_flush();
e1000_release_swflag_ich8lan(hw);
if ((er32(SHRAL_PCH_LPT(index - 1)) == rar_low) &&
(er32(SHRAH_PCH_LPT(index - 1)) == rar_high))
return 0;
}
}
out:
e_dbg("Failed to write receive address at index %d\n", index);
return -E1000_ERR_CONFIG;
}
static s32 e1000_check_reset_block_ich8lan(struct e1000_hw *hw)
{
bool blocked = false;
int i = 0;
while ((blocked = !(er32(FWSM) & E1000_ICH_FWSM_RSPCIPHY)) &&
(i++ < 30))
usleep_range(10000, 20000);
return blocked ? E1000_BLK_PHY_RESET : 0;
}
static s32 e1000_write_smbus_addr(struct e1000_hw *hw)
{
u16 phy_data;
u32 strap = er32(STRAP);
u32 freq = (strap & E1000_STRAP_SMT_FREQ_MASK) >>
E1000_STRAP_SMT_FREQ_SHIFT;
s32 ret_val;
strap &= E1000_STRAP_SMBUS_ADDRESS_MASK;
ret_val = e1000_read_phy_reg_hv_locked(hw, HV_SMB_ADDR, &phy_data);
if (ret_val)
return ret_val;
phy_data &= ~HV_SMB_ADDR_MASK;
phy_data |= (strap >> E1000_STRAP_SMBUS_ADDRESS_SHIFT);
phy_data |= HV_SMB_ADDR_PEC_EN | HV_SMB_ADDR_VALID;
if (hw->phy.type == e1000_phy_i217) {
if (freq--) {
phy_data &= ~HV_SMB_ADDR_FREQ_MASK;
phy_data |= (freq & (1 << 0)) <<
HV_SMB_ADDR_FREQ_LOW_SHIFT;
phy_data |= (freq & (1 << 1)) <<
(HV_SMB_ADDR_FREQ_HIGH_SHIFT - 1);
} else {
e_dbg("Unsupported SMB frequency in PHY\n");
}
}
return e1000_write_phy_reg_hv_locked(hw, HV_SMB_ADDR, phy_data);
}
static s32 e1000_sw_lcd_config_ich8lan(struct e1000_hw *hw)
{
struct e1000_phy_info *phy = &hw->phy;
u32 i, data, cnf_size, cnf_base_addr, sw_cfg_mask;
s32 ret_val = 0;
u16 word_addr, reg_data, reg_addr, phy_page = 0;
switch (hw->mac.type) {
case e1000_ich8lan:
if (phy->type != e1000_phy_igp_3)
return ret_val;
if ((hw->adapter->pdev->device == E1000_DEV_ID_ICH8_IGP_AMT) ||
(hw->adapter->pdev->device == E1000_DEV_ID_ICH8_IGP_C)) {
sw_cfg_mask = E1000_FEXTNVM_SW_CONFIG;
break;
}
case e1000_pchlan:
case e1000_pch2lan:
case e1000_pch_lpt:
case e1000_pch_spt:
sw_cfg_mask = E1000_FEXTNVM_SW_CONFIG_ICH8M;
break;
default:
return ret_val;
}
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
data = er32(FEXTNVM);
if (!(data & sw_cfg_mask))
goto release;
data = er32(EXTCNF_CTRL);
if ((hw->mac.type < e1000_pch2lan) &&
(data & E1000_EXTCNF_CTRL_LCD_WRITE_ENABLE))
goto release;
cnf_size = er32(EXTCNF_SIZE);
cnf_size &= E1000_EXTCNF_SIZE_EXT_PCIE_LENGTH_MASK;
cnf_size >>= E1000_EXTCNF_SIZE_EXT_PCIE_LENGTH_SHIFT;
if (!cnf_size)
goto release;
cnf_base_addr = data & E1000_EXTCNF_CTRL_EXT_CNF_POINTER_MASK;
cnf_base_addr >>= E1000_EXTCNF_CTRL_EXT_CNF_POINTER_SHIFT;
if (((hw->mac.type == e1000_pchlan) &&
!(data & E1000_EXTCNF_CTRL_OEM_WRITE_ENABLE)) ||
(hw->mac.type > e1000_pchlan)) {
ret_val = e1000_write_smbus_addr(hw);
if (ret_val)
goto release;
data = er32(LEDCTL);
ret_val = e1000_write_phy_reg_hv_locked(hw, HV_LED_CONFIG,
(u16)data);
if (ret_val)
goto release;
}
word_addr = (u16)(cnf_base_addr << 1);
for (i = 0; i < cnf_size; i++) {
ret_val = e1000_read_nvm(hw, (word_addr + i * 2), 1, &reg_data);
if (ret_val)
goto release;
ret_val = e1000_read_nvm(hw, (word_addr + i * 2 + 1),
1, &reg_addr);
if (ret_val)
goto release;
if (reg_addr == IGP01E1000_PHY_PAGE_SELECT) {
phy_page = reg_data;
continue;
}
reg_addr &= PHY_REG_MASK;
reg_addr |= phy_page;
ret_val = e1e_wphy_locked(hw, (u32)reg_addr, reg_data);
if (ret_val)
goto release;
}
release:
hw->phy.ops.release(hw);
return ret_val;
}
static s32 e1000_k1_gig_workaround_hv(struct e1000_hw *hw, bool link)
{
s32 ret_val = 0;
u16 status_reg = 0;
bool k1_enable = hw->dev_spec.ich8lan.nvm_k1_enabled;
if (hw->mac.type != e1000_pchlan)
return 0;
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
if (link) {
if (hw->phy.type == e1000_phy_82578) {
ret_val = e1e_rphy_locked(hw, BM_CS_STATUS,
&status_reg);
if (ret_val)
goto release;
status_reg &= (BM_CS_STATUS_LINK_UP |
BM_CS_STATUS_RESOLVED |
BM_CS_STATUS_SPEED_MASK);
if (status_reg == (BM_CS_STATUS_LINK_UP |
BM_CS_STATUS_RESOLVED |
BM_CS_STATUS_SPEED_1000))
k1_enable = false;
}
if (hw->phy.type == e1000_phy_82577) {
ret_val = e1e_rphy_locked(hw, HV_M_STATUS, &status_reg);
if (ret_val)
goto release;
status_reg &= (HV_M_STATUS_LINK_UP |
HV_M_STATUS_AUTONEG_COMPLETE |
HV_M_STATUS_SPEED_MASK);
if (status_reg == (HV_M_STATUS_LINK_UP |
HV_M_STATUS_AUTONEG_COMPLETE |
HV_M_STATUS_SPEED_1000))
k1_enable = false;
}
ret_val = e1e_wphy_locked(hw, PHY_REG(770, 19), 0x0100);
if (ret_val)
goto release;
} else {
ret_val = e1e_wphy_locked(hw, PHY_REG(770, 19), 0x4100);
if (ret_val)
goto release;
}
ret_val = e1000_configure_k1_ich8lan(hw, k1_enable);
release:
hw->phy.ops.release(hw);
return ret_val;
}
s32 e1000_configure_k1_ich8lan(struct e1000_hw *hw, bool k1_enable)
{
s32 ret_val;
u32 ctrl_reg = 0;
u32 ctrl_ext = 0;
u32 reg = 0;
u16 kmrn_reg = 0;
ret_val = e1000e_read_kmrn_reg_locked(hw, E1000_KMRNCTRLSTA_K1_CONFIG,
&kmrn_reg);
if (ret_val)
return ret_val;
if (k1_enable)
kmrn_reg |= E1000_KMRNCTRLSTA_K1_ENABLE;
else
kmrn_reg &= ~E1000_KMRNCTRLSTA_K1_ENABLE;
ret_val = e1000e_write_kmrn_reg_locked(hw, E1000_KMRNCTRLSTA_K1_CONFIG,
kmrn_reg);
if (ret_val)
return ret_val;
usleep_range(20, 40);
ctrl_ext = er32(CTRL_EXT);
ctrl_reg = er32(CTRL);
reg = ctrl_reg & ~(E1000_CTRL_SPD_1000 | E1000_CTRL_SPD_100);
reg |= E1000_CTRL_FRCSPD;
ew32(CTRL, reg);
ew32(CTRL_EXT, ctrl_ext | E1000_CTRL_EXT_SPD_BYPS);
e1e_flush();
usleep_range(20, 40);
ew32(CTRL, ctrl_reg);
ew32(CTRL_EXT, ctrl_ext);
e1e_flush();
usleep_range(20, 40);
return 0;
}
static s32 e1000_oem_bits_config_ich8lan(struct e1000_hw *hw, bool d0_state)
{
s32 ret_val = 0;
u32 mac_reg;
u16 oem_reg;
if (hw->mac.type < e1000_pchlan)
return ret_val;
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
if (hw->mac.type == e1000_pchlan) {
mac_reg = er32(EXTCNF_CTRL);
if (mac_reg & E1000_EXTCNF_CTRL_OEM_WRITE_ENABLE)
goto release;
}
mac_reg = er32(FEXTNVM);
if (!(mac_reg & E1000_FEXTNVM_SW_CONFIG_ICH8M))
goto release;
mac_reg = er32(PHY_CTRL);
ret_val = e1e_rphy_locked(hw, HV_OEM_BITS, &oem_reg);
if (ret_val)
goto release;
oem_reg &= ~(HV_OEM_BITS_GBE_DIS | HV_OEM_BITS_LPLU);
if (d0_state) {
if (mac_reg & E1000_PHY_CTRL_GBE_DISABLE)
oem_reg |= HV_OEM_BITS_GBE_DIS;
if (mac_reg & E1000_PHY_CTRL_D0A_LPLU)
oem_reg |= HV_OEM_BITS_LPLU;
} else {
if (mac_reg & (E1000_PHY_CTRL_GBE_DISABLE |
E1000_PHY_CTRL_NOND0A_GBE_DISABLE))
oem_reg |= HV_OEM_BITS_GBE_DIS;
if (mac_reg & (E1000_PHY_CTRL_D0A_LPLU |
E1000_PHY_CTRL_NOND0A_LPLU))
oem_reg |= HV_OEM_BITS_LPLU;
}
if ((d0_state || (hw->mac.type != e1000_pchlan)) &&
!hw->phy.ops.check_reset_block(hw))
oem_reg |= HV_OEM_BITS_RESTART_AN;
ret_val = e1e_wphy_locked(hw, HV_OEM_BITS, oem_reg);
release:
hw->phy.ops.release(hw);
return ret_val;
}
static s32 e1000_set_mdio_slow_mode_hv(struct e1000_hw *hw)
{
s32 ret_val;
u16 data;
ret_val = e1e_rphy(hw, HV_KMRN_MODE_CTRL, &data);
if (ret_val)
return ret_val;
data |= HV_KMRN_MDIO_SLOW;
ret_val = e1e_wphy(hw, HV_KMRN_MODE_CTRL, data);
return ret_val;
}
static s32 e1000_hv_phy_workarounds_ich8lan(struct e1000_hw *hw)
{
s32 ret_val = 0;
u16 phy_data;
if (hw->mac.type != e1000_pchlan)
return 0;
if (hw->phy.type == e1000_phy_82577) {
ret_val = e1000_set_mdio_slow_mode_hv(hw);
if (ret_val)
return ret_val;
}
if (((hw->phy.type == e1000_phy_82577) &&
((hw->phy.revision == 1) || (hw->phy.revision == 2))) ||
((hw->phy.type == e1000_phy_82578) && (hw->phy.revision == 1))) {
ret_val = e1e_wphy(hw, PHY_REG(769, 25), 0x4431);
if (ret_val)
return ret_val;
ret_val = e1e_wphy(hw, HV_KMRN_FIFO_CTRLSTA, 0xA204);
if (ret_val)
return ret_val;
}
if (hw->phy.type == e1000_phy_82578) {
if (hw->phy.revision < 2) {
e1000e_phy_sw_reset(hw);
ret_val = e1e_wphy(hw, MII_BMCR, 0x3140);
}
}
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
hw->phy.addr = 1;
ret_val = e1000e_write_phy_reg_mdic(hw, IGP01E1000_PHY_PAGE_SELECT, 0);
hw->phy.ops.release(hw);
if (ret_val)
return ret_val;
ret_val = e1000_k1_gig_workaround_hv(hw, true);
if (ret_val)
return ret_val;
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
ret_val = e1e_rphy_locked(hw, BM_PORT_GEN_CFG, &phy_data);
if (ret_val)
goto release;
ret_val = e1e_wphy_locked(hw, BM_PORT_GEN_CFG, phy_data & 0x00FF);
if (ret_val)
goto release;
ret_val = e1000_write_emi_reg_locked(hw, I82577_MSE_THRESHOLD, 0x0034);
release:
hw->phy.ops.release(hw);
return ret_val;
}
void e1000_copy_rx_addrs_to_phy_ich8lan(struct e1000_hw *hw)
{
u32 mac_reg;
u16 i, phy_reg = 0;
s32 ret_val;
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return;
ret_val = e1000_enable_phy_wakeup_reg_access_bm(hw, &phy_reg);
if (ret_val)
goto release;
for (i = 0; i < (hw->mac.rar_entry_count); i++) {
mac_reg = er32(RAL(i));
hw->phy.ops.write_reg_page(hw, BM_RAR_L(i),
(u16)(mac_reg & 0xFFFF));
hw->phy.ops.write_reg_page(hw, BM_RAR_M(i),
(u16)((mac_reg >> 16) & 0xFFFF));
mac_reg = er32(RAH(i));
hw->phy.ops.write_reg_page(hw, BM_RAR_H(i),
(u16)(mac_reg & 0xFFFF));
hw->phy.ops.write_reg_page(hw, BM_RAR_CTRL(i),
(u16)((mac_reg & E1000_RAH_AV)
>> 16));
}
e1000_disable_phy_wakeup_reg_access_bm(hw, &phy_reg);
release:
hw->phy.ops.release(hw);
}
s32 e1000_lv_jumbo_workaround_ich8lan(struct e1000_hw *hw, bool enable)
{
s32 ret_val = 0;
u16 phy_reg, data;
u32 mac_reg;
u16 i;
if (hw->mac.type < e1000_pch2lan)
return 0;
e1e_rphy(hw, PHY_REG(769, 20), &phy_reg);
ret_val = e1e_wphy(hw, PHY_REG(769, 20), phy_reg | (1 << 14));
if (ret_val)
return ret_val;
if (enable) {
for (i = 0; i < hw->mac.rar_entry_count; i++) {
u8 mac_addr[ETH_ALEN] = { 0 };
u32 addr_high, addr_low;
addr_high = er32(RAH(i));
if (!(addr_high & E1000_RAH_AV))
continue;
addr_low = er32(RAL(i));
mac_addr[0] = (addr_low & 0xFF);
mac_addr[1] = ((addr_low >> 8) & 0xFF);
mac_addr[2] = ((addr_low >> 16) & 0xFF);
mac_addr[3] = ((addr_low >> 24) & 0xFF);
mac_addr[4] = (addr_high & 0xFF);
mac_addr[5] = ((addr_high >> 8) & 0xFF);
ew32(PCH_RAICC(i), ~ether_crc_le(ETH_ALEN, mac_addr));
}
e1000_copy_rx_addrs_to_phy_ich8lan(hw);
mac_reg = er32(FFLT_DBG);
mac_reg &= ~(1 << 14);
mac_reg |= (7 << 15);
ew32(FFLT_DBG, mac_reg);
mac_reg = er32(RCTL);
mac_reg |= E1000_RCTL_SECRC;
ew32(RCTL, mac_reg);
ret_val = e1000e_read_kmrn_reg(hw,
E1000_KMRNCTRLSTA_CTRL_OFFSET,
&data);
if (ret_val)
return ret_val;
ret_val = e1000e_write_kmrn_reg(hw,
E1000_KMRNCTRLSTA_CTRL_OFFSET,
data | (1 << 0));
if (ret_val)
return ret_val;
ret_val = e1000e_read_kmrn_reg(hw,
E1000_KMRNCTRLSTA_HD_CTRL,
&data);
if (ret_val)
return ret_val;
data &= ~(0xF << 8);
data |= (0xB << 8);
ret_val = e1000e_write_kmrn_reg(hw,
E1000_KMRNCTRLSTA_HD_CTRL,
data);
if (ret_val)
return ret_val;
e1e_rphy(hw, PHY_REG(769, 23), &data);
data &= ~(0x7F << 5);
data |= (0x37 << 5);
ret_val = e1e_wphy(hw, PHY_REG(769, 23), data);
if (ret_val)
return ret_val;
e1e_rphy(hw, PHY_REG(769, 16), &data);
data &= ~(1 << 13);
ret_val = e1e_wphy(hw, PHY_REG(769, 16), data);
if (ret_val)
return ret_val;
e1e_rphy(hw, PHY_REG(776, 20), &data);
data &= ~(0x3FF << 2);
data |= (E1000_TX_PTR_GAP << 2);
ret_val = e1e_wphy(hw, PHY_REG(776, 20), data);
if (ret_val)
return ret_val;
ret_val = e1e_wphy(hw, PHY_REG(776, 23), 0xF100);
if (ret_val)
return ret_val;
e1e_rphy(hw, HV_PM_CTRL, &data);
ret_val = e1e_wphy(hw, HV_PM_CTRL, data | (1 << 10));
if (ret_val)
return ret_val;
} else {
mac_reg = er32(FFLT_DBG);
mac_reg &= ~(0xF << 14);
ew32(FFLT_DBG, mac_reg);
mac_reg = er32(RCTL);
mac_reg &= ~E1000_RCTL_SECRC;
ew32(RCTL, mac_reg);
ret_val = e1000e_read_kmrn_reg(hw,
E1000_KMRNCTRLSTA_CTRL_OFFSET,
&data);
if (ret_val)
return ret_val;
ret_val = e1000e_write_kmrn_reg(hw,
E1000_KMRNCTRLSTA_CTRL_OFFSET,
data & ~(1 << 0));
if (ret_val)
return ret_val;
ret_val = e1000e_read_kmrn_reg(hw,
E1000_KMRNCTRLSTA_HD_CTRL,
&data);
if (ret_val)
return ret_val;
data &= ~(0xF << 8);
data |= (0xB << 8);
ret_val = e1000e_write_kmrn_reg(hw,
E1000_KMRNCTRLSTA_HD_CTRL,
data);
if (ret_val)
return ret_val;
e1e_rphy(hw, PHY_REG(769, 23), &data);
data &= ~(0x7F << 5);
ret_val = e1e_wphy(hw, PHY_REG(769, 23), data);
if (ret_val)
return ret_val;
e1e_rphy(hw, PHY_REG(769, 16), &data);
data |= (1 << 13);
ret_val = e1e_wphy(hw, PHY_REG(769, 16), data);
if (ret_val)
return ret_val;
e1e_rphy(hw, PHY_REG(776, 20), &data);
data &= ~(0x3FF << 2);
data |= (0x8 << 2);
ret_val = e1e_wphy(hw, PHY_REG(776, 20), data);
if (ret_val)
return ret_val;
ret_val = e1e_wphy(hw, PHY_REG(776, 23), 0x7E00);
if (ret_val)
return ret_val;
e1e_rphy(hw, HV_PM_CTRL, &data);
ret_val = e1e_wphy(hw, HV_PM_CTRL, data & ~(1 << 10));
if (ret_val)
return ret_val;
}
return e1e_wphy(hw, PHY_REG(769, 20), phy_reg & ~(1 << 14));
}
static s32 e1000_lv_phy_workarounds_ich8lan(struct e1000_hw *hw)
{
s32 ret_val = 0;
if (hw->mac.type != e1000_pch2lan)
return 0;
ret_val = e1000_set_mdio_slow_mode_hv(hw);
if (ret_val)
return ret_val;
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
ret_val = e1000_write_emi_reg_locked(hw, I82579_MSE_THRESHOLD, 0x0034);
if (ret_val)
goto release;
ret_val = e1000_write_emi_reg_locked(hw, I82579_MSE_LINK_DOWN, 0x0005);
release:
hw->phy.ops.release(hw);
return ret_val;
}
static s32 e1000_k1_workaround_lv(struct e1000_hw *hw)
{
s32 ret_val = 0;
u16 status_reg = 0;
if (hw->mac.type != e1000_pch2lan)
return 0;
ret_val = e1e_rphy(hw, HV_M_STATUS, &status_reg);
if (ret_val)
return ret_val;
if ((status_reg & (HV_M_STATUS_LINK_UP | HV_M_STATUS_AUTONEG_COMPLETE))
== (HV_M_STATUS_LINK_UP | HV_M_STATUS_AUTONEG_COMPLETE)) {
if (status_reg &
(HV_M_STATUS_SPEED_1000 | HV_M_STATUS_SPEED_100)) {
u16 pm_phy_reg;
ret_val = e1e_rphy(hw, HV_PM_CTRL, &pm_phy_reg);
if (ret_val)
return ret_val;
pm_phy_reg &= ~HV_PM_CTRL_K1_ENABLE;
ret_val = e1e_wphy(hw, HV_PM_CTRL, pm_phy_reg);
if (ret_val)
return ret_val;
} else {
u32 mac_reg;
mac_reg = er32(FEXTNVM4);
mac_reg &= ~E1000_FEXTNVM4_BEACON_DURATION_MASK;
mac_reg |= E1000_FEXTNVM4_BEACON_DURATION_16USEC;
ew32(FEXTNVM4, mac_reg);
}
}
return ret_val;
}
static void e1000_gate_hw_phy_config_ich8lan(struct e1000_hw *hw, bool gate)
{
u32 extcnf_ctrl;
if (hw->mac.type < e1000_pch2lan)
return;
extcnf_ctrl = er32(EXTCNF_CTRL);
if (gate)
extcnf_ctrl |= E1000_EXTCNF_CTRL_GATE_PHY_CFG;
else
extcnf_ctrl &= ~E1000_EXTCNF_CTRL_GATE_PHY_CFG;
ew32(EXTCNF_CTRL, extcnf_ctrl);
}
static void e1000_lan_init_done_ich8lan(struct e1000_hw *hw)
{
u32 data, loop = E1000_ICH8_LAN_INIT_TIMEOUT;
do {
data = er32(STATUS);
data &= E1000_STATUS_LAN_INIT_DONE;
usleep_range(100, 200);
} while ((!data) && --loop);
if (loop == 0)
e_dbg("LAN_INIT_DONE not set, increase timeout\n");
data = er32(STATUS);
data &= ~E1000_STATUS_LAN_INIT_DONE;
ew32(STATUS, data);
}
static s32 e1000_post_phy_reset_ich8lan(struct e1000_hw *hw)
{
s32 ret_val = 0;
u16 reg;
if (hw->phy.ops.check_reset_block(hw))
return 0;
usleep_range(10000, 20000);
switch (hw->mac.type) {
case e1000_pchlan:
ret_val = e1000_hv_phy_workarounds_ich8lan(hw);
if (ret_val)
return ret_val;
break;
case e1000_pch2lan:
ret_val = e1000_lv_phy_workarounds_ich8lan(hw);
if (ret_val)
return ret_val;
break;
default:
break;
}
if (hw->mac.type >= e1000_pchlan) {
e1e_rphy(hw, BM_PORT_GEN_CFG, &reg);
reg &= ~BM_WUC_HOST_WU_BIT;
e1e_wphy(hw, BM_PORT_GEN_CFG, reg);
}
ret_val = e1000_sw_lcd_config_ich8lan(hw);
if (ret_val)
return ret_val;
ret_val = e1000_oem_bits_config_ich8lan(hw, true);
if (hw->mac.type == e1000_pch2lan) {
if (!(er32(FWSM) & E1000_ICH_FWSM_FW_VALID)) {
usleep_range(10000, 20000);
e1000_gate_hw_phy_config_ich8lan(hw, false);
}
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return ret_val;
ret_val = e1000_write_emi_reg_locked(hw,
I82579_LPI_UPDATE_TIMER,
0x1387);
hw->phy.ops.release(hw);
}
return ret_val;
}
static s32 e1000_phy_hw_reset_ich8lan(struct e1000_hw *hw)
{
s32 ret_val = 0;
if ((hw->mac.type == e1000_pch2lan) &&
!(er32(FWSM) & E1000_ICH_FWSM_FW_VALID))
e1000_gate_hw_phy_config_ich8lan(hw, true);
ret_val = e1000e_phy_hw_reset_generic(hw);
if (ret_val)
return ret_val;
return e1000_post_phy_reset_ich8lan(hw);
}
static s32 e1000_set_lplu_state_pchlan(struct e1000_hw *hw, bool active)
{
s32 ret_val;
u16 oem_reg;
ret_val = e1e_rphy(hw, HV_OEM_BITS, &oem_reg);
if (ret_val)
return ret_val;
if (active)
oem_reg |= HV_OEM_BITS_LPLU;
else
oem_reg &= ~HV_OEM_BITS_LPLU;
if (!hw->phy.ops.check_reset_block(hw))
oem_reg |= HV_OEM_BITS_RESTART_AN;
return e1e_wphy(hw, HV_OEM_BITS, oem_reg);
}
static s32 e1000_set_d0_lplu_state_ich8lan(struct e1000_hw *hw, bool active)
{
struct e1000_phy_info *phy = &hw->phy;
u32 phy_ctrl;
s32 ret_val = 0;
u16 data;
if (phy->type == e1000_phy_ife)
return 0;
phy_ctrl = er32(PHY_CTRL);
if (active) {
phy_ctrl |= E1000_PHY_CTRL_D0A_LPLU;
ew32(PHY_CTRL, phy_ctrl);
if (phy->type != e1000_phy_igp_3)
return 0;
if (hw->mac.type == e1000_ich8lan)
e1000e_gig_downshift_workaround_ich8lan(hw);
ret_val = e1e_rphy(hw, IGP01E1000_PHY_PORT_CONFIG, &data);
if (ret_val)
return ret_val;
data &= ~IGP01E1000_PSCFR_SMART_SPEED;
ret_val = e1e_wphy(hw, IGP01E1000_PHY_PORT_CONFIG, data);
if (ret_val)
return ret_val;
} else {
phy_ctrl &= ~E1000_PHY_CTRL_D0A_LPLU;
ew32(PHY_CTRL, phy_ctrl);
if (phy->type != e1000_phy_igp_3)
return 0;
if (phy->smart_speed == e1000_smart_speed_on) {
ret_val = e1e_rphy(hw, IGP01E1000_PHY_PORT_CONFIG,
&data);
if (ret_val)
return ret_val;
data |= IGP01E1000_PSCFR_SMART_SPEED;
ret_val = e1e_wphy(hw, IGP01E1000_PHY_PORT_CONFIG,
data);
if (ret_val)
return ret_val;
} else if (phy->smart_speed == e1000_smart_speed_off) {
ret_val = e1e_rphy(hw, IGP01E1000_PHY_PORT_CONFIG,
&data);
if (ret_val)
return ret_val;
data &= ~IGP01E1000_PSCFR_SMART_SPEED;
ret_val = e1e_wphy(hw, IGP01E1000_PHY_PORT_CONFIG,
data);
if (ret_val)
return ret_val;
}
}
return 0;
}
static s32 e1000_set_d3_lplu_state_ich8lan(struct e1000_hw *hw, bool active)
{
struct e1000_phy_info *phy = &hw->phy;
u32 phy_ctrl;
s32 ret_val = 0;
u16 data;
phy_ctrl = er32(PHY_CTRL);
if (!active) {
phy_ctrl &= ~E1000_PHY_CTRL_NOND0A_LPLU;
ew32(PHY_CTRL, phy_ctrl);
if (phy->type != e1000_phy_igp_3)
return 0;
if (phy->smart_speed == e1000_smart_speed_on) {
ret_val = e1e_rphy(hw, IGP01E1000_PHY_PORT_CONFIG,
&data);
if (ret_val)
return ret_val;
data |= IGP01E1000_PSCFR_SMART_SPEED;
ret_val = e1e_wphy(hw, IGP01E1000_PHY_PORT_CONFIG,
data);
if (ret_val)
return ret_val;
} else if (phy->smart_speed == e1000_smart_speed_off) {
ret_val = e1e_rphy(hw, IGP01E1000_PHY_PORT_CONFIG,
&data);
if (ret_val)
return ret_val;
data &= ~IGP01E1000_PSCFR_SMART_SPEED;
ret_val = e1e_wphy(hw, IGP01E1000_PHY_PORT_CONFIG,
data);
if (ret_val)
return ret_val;
}
} else if ((phy->autoneg_advertised == E1000_ALL_SPEED_DUPLEX) ||
(phy->autoneg_advertised == E1000_ALL_NOT_GIG) ||
(phy->autoneg_advertised == E1000_ALL_10_SPEED)) {
phy_ctrl |= E1000_PHY_CTRL_NOND0A_LPLU;
ew32(PHY_CTRL, phy_ctrl);
if (phy->type != e1000_phy_igp_3)
return 0;
if (hw->mac.type == e1000_ich8lan)
e1000e_gig_downshift_workaround_ich8lan(hw);
ret_val = e1e_rphy(hw, IGP01E1000_PHY_PORT_CONFIG, &data);
if (ret_val)
return ret_val;
data &= ~IGP01E1000_PSCFR_SMART_SPEED;
ret_val = e1e_wphy(hw, IGP01E1000_PHY_PORT_CONFIG, data);
}
return ret_val;
}
static s32 e1000_valid_nvm_bank_detect_ich8lan(struct e1000_hw *hw, u32 *bank)
{
u32 eecd;
struct e1000_nvm_info *nvm = &hw->nvm;
u32 bank1_offset = nvm->flash_bank_size * sizeof(u16);
u32 act_offset = E1000_ICH_NVM_SIG_WORD * 2 + 1;
u32 nvm_dword = 0;
u8 sig_byte = 0;
s32 ret_val;
switch (hw->mac.type) {
case e1000_pch_spt:
bank1_offset = nvm->flash_bank_size;
act_offset = E1000_ICH_NVM_SIG_WORD;
*bank = 0;
ret_val = e1000_read_flash_dword_ich8lan(hw, act_offset,
&nvm_dword);
if (ret_val)
return ret_val;
sig_byte = (u8)((nvm_dword & 0xFF00) >> 8);
if ((sig_byte & E1000_ICH_NVM_VALID_SIG_MASK) ==
E1000_ICH_NVM_SIG_VALUE) {
*bank = 0;
return 0;
}
ret_val = e1000_read_flash_dword_ich8lan(hw, act_offset +
bank1_offset,
&nvm_dword);
if (ret_val)
return ret_val;
sig_byte = (u8)((nvm_dword & 0xFF00) >> 8);
if ((sig_byte & E1000_ICH_NVM_VALID_SIG_MASK) ==
E1000_ICH_NVM_SIG_VALUE) {
*bank = 1;
return 0;
}
e_dbg("ERROR: No valid NVM bank present\n");
return -E1000_ERR_NVM;
case e1000_ich8lan:
case e1000_ich9lan:
eecd = er32(EECD);
if ((eecd & E1000_EECD_SEC1VAL_VALID_MASK) ==
E1000_EECD_SEC1VAL_VALID_MASK) {
if (eecd & E1000_EECD_SEC1VAL)
*bank = 1;
else
*bank = 0;
return 0;
}
e_dbg("Unable to determine valid NVM bank via EEC - reading flash signature\n");
default:
*bank = 0;
ret_val = e1000_read_flash_byte_ich8lan(hw, act_offset,
&sig_byte);
if (ret_val)
return ret_val;
if ((sig_byte & E1000_ICH_NVM_VALID_SIG_MASK) ==
E1000_ICH_NVM_SIG_VALUE) {
*bank = 0;
return 0;
}
ret_val = e1000_read_flash_byte_ich8lan(hw, act_offset +
bank1_offset,
&sig_byte);
if (ret_val)
return ret_val;
if ((sig_byte & E1000_ICH_NVM_VALID_SIG_MASK) ==
E1000_ICH_NVM_SIG_VALUE) {
*bank = 1;
return 0;
}
e_dbg("ERROR: No valid NVM bank present\n");
return -E1000_ERR_NVM;
}
}
static s32 e1000_read_nvm_spt(struct e1000_hw *hw, u16 offset, u16 words,
u16 *data)
{
struct e1000_nvm_info *nvm = &hw->nvm;
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u32 act_offset;
s32 ret_val = 0;
u32 bank = 0;
u32 dword = 0;
u16 offset_to_read;
u16 i;
if ((offset >= nvm->word_size) || (words > nvm->word_size - offset) ||
(words == 0)) {
e_dbg("nvm parameter(s) out of bounds\n");
ret_val = -E1000_ERR_NVM;
goto out;
}
nvm->ops.acquire(hw);
ret_val = e1000_valid_nvm_bank_detect_ich8lan(hw, &bank);
if (ret_val) {
e_dbg("Could not detect valid bank, assuming bank 0\n");
bank = 0;
}
act_offset = (bank) ? nvm->flash_bank_size : 0;
act_offset += offset;
ret_val = 0;
for (i = 0; i < words; i += 2) {
if (words - i == 1) {
if (dev_spec->shadow_ram[offset + i].modified) {
data[i] =
dev_spec->shadow_ram[offset + i].value;
} else {
offset_to_read = act_offset + i -
((act_offset + i) % 2);
ret_val =
e1000_read_flash_dword_ich8lan(hw,
offset_to_read,
&dword);
if (ret_val)
break;
if ((act_offset + i) % 2 == 0)
data[i] = (u16)(dword & 0xFFFF);
else
data[i] = (u16)((dword >> 16) & 0xFFFF);
}
} else {
offset_to_read = act_offset + i;
if (!(dev_spec->shadow_ram[offset + i].modified) ||
!(dev_spec->shadow_ram[offset + i + 1].modified)) {
ret_val =
e1000_read_flash_dword_ich8lan(hw,
offset_to_read,
&dword);
if (ret_val)
break;
}
if (dev_spec->shadow_ram[offset + i].modified)
data[i] =
dev_spec->shadow_ram[offset + i].value;
else
data[i] = (u16)(dword & 0xFFFF);
if (dev_spec->shadow_ram[offset + i].modified)
data[i + 1] =
dev_spec->shadow_ram[offset + i + 1].value;
else
data[i + 1] = (u16)(dword >> 16 & 0xFFFF);
}
}
nvm->ops.release(hw);
out:
if (ret_val)
e_dbg("NVM read error: %d\n", ret_val);
return ret_val;
}
static s32 e1000_read_nvm_ich8lan(struct e1000_hw *hw, u16 offset, u16 words,
u16 *data)
{
struct e1000_nvm_info *nvm = &hw->nvm;
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u32 act_offset;
s32 ret_val = 0;
u32 bank = 0;
u16 i, word;
if ((offset >= nvm->word_size) || (words > nvm->word_size - offset) ||
(words == 0)) {
e_dbg("nvm parameter(s) out of bounds\n");
ret_val = -E1000_ERR_NVM;
goto out;
}
nvm->ops.acquire(hw);
ret_val = e1000_valid_nvm_bank_detect_ich8lan(hw, &bank);
if (ret_val) {
e_dbg("Could not detect valid bank, assuming bank 0\n");
bank = 0;
}
act_offset = (bank) ? nvm->flash_bank_size : 0;
act_offset += offset;
ret_val = 0;
for (i = 0; i < words; i++) {
if (dev_spec->shadow_ram[offset + i].modified) {
data[i] = dev_spec->shadow_ram[offset + i].value;
} else {
ret_val = e1000_read_flash_word_ich8lan(hw,
act_offset + i,
&word);
if (ret_val)
break;
data[i] = word;
}
}
nvm->ops.release(hw);
out:
if (ret_val)
e_dbg("NVM read error: %d\n", ret_val);
return ret_val;
}
static s32 e1000_flash_cycle_init_ich8lan(struct e1000_hw *hw)
{
union ich8_hws_flash_status hsfsts;
s32 ret_val = -E1000_ERR_NVM;
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
if (!hsfsts.hsf_status.fldesvalid) {
e_dbg("Flash descriptor invalid. SW Sequencing must be used.\n");
return -E1000_ERR_NVM;
}
hsfsts.hsf_status.flcerr = 1;
hsfsts.hsf_status.dael = 1;
if (hw->mac.type == e1000_pch_spt)
ew32flash(ICH_FLASH_HSFSTS, hsfsts.regval & 0xFFFF);
else
ew16flash(ICH_FLASH_HSFSTS, hsfsts.regval);
if (!hsfsts.hsf_status.flcinprog) {
hsfsts.hsf_status.flcdone = 1;
if (hw->mac.type == e1000_pch_spt)
ew32flash(ICH_FLASH_HSFSTS, hsfsts.regval & 0xFFFF);
else
ew16flash(ICH_FLASH_HSFSTS, hsfsts.regval);
ret_val = 0;
} else {
s32 i;
for (i = 0; i < ICH_FLASH_READ_COMMAND_TIMEOUT; i++) {
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
if (!hsfsts.hsf_status.flcinprog) {
ret_val = 0;
break;
}
udelay(1);
}
if (!ret_val) {
hsfsts.hsf_status.flcdone = 1;
if (hw->mac.type == e1000_pch_spt)
ew32flash(ICH_FLASH_HSFSTS,
hsfsts.regval & 0xFFFF);
else
ew16flash(ICH_FLASH_HSFSTS, hsfsts.regval);
} else {
e_dbg("Flash controller busy, cannot get access\n");
}
}
return ret_val;
}
static s32 e1000_flash_cycle_ich8lan(struct e1000_hw *hw, u32 timeout)
{
union ich8_hws_flash_ctrl hsflctl;
union ich8_hws_flash_status hsfsts;
u32 i = 0;
if (hw->mac.type == e1000_pch_spt)
hsflctl.regval = er32flash(ICH_FLASH_HSFSTS) >> 16;
else
hsflctl.regval = er16flash(ICH_FLASH_HSFCTL);
hsflctl.hsf_ctrl.flcgo = 1;
if (hw->mac.type == e1000_pch_spt)
ew32flash(ICH_FLASH_HSFSTS, hsflctl.regval << 16);
else
ew16flash(ICH_FLASH_HSFCTL, hsflctl.regval);
do {
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
if (hsfsts.hsf_status.flcdone)
break;
udelay(1);
} while (i++ < timeout);
if (hsfsts.hsf_status.flcdone && !hsfsts.hsf_status.flcerr)
return 0;
return -E1000_ERR_NVM;
}
static s32 e1000_read_flash_dword_ich8lan(struct e1000_hw *hw, u32 offset,
u32 *data)
{
offset <<= 1;
return e1000_read_flash_data32_ich8lan(hw, offset, data);
}
static s32 e1000_read_flash_word_ich8lan(struct e1000_hw *hw, u32 offset,
u16 *data)
{
offset <<= 1;
return e1000_read_flash_data_ich8lan(hw, offset, 2, data);
}
static s32 e1000_read_flash_byte_ich8lan(struct e1000_hw *hw, u32 offset,
u8 *data)
{
s32 ret_val;
u16 word = 0;
if (hw->mac.type == e1000_pch_spt)
return -E1000_ERR_NVM;
else
ret_val = e1000_read_flash_data_ich8lan(hw, offset, 1, &word);
if (ret_val)
return ret_val;
*data = (u8)word;
return 0;
}
static s32 e1000_read_flash_data_ich8lan(struct e1000_hw *hw, u32 offset,
u8 size, u16 *data)
{
union ich8_hws_flash_status hsfsts;
union ich8_hws_flash_ctrl hsflctl;
u32 flash_linear_addr;
u32 flash_data = 0;
s32 ret_val = -E1000_ERR_NVM;
u8 count = 0;
if (size < 1 || size > 2 || offset > ICH_FLASH_LINEAR_ADDR_MASK)
return -E1000_ERR_NVM;
flash_linear_addr = ((ICH_FLASH_LINEAR_ADDR_MASK & offset) +
hw->nvm.flash_base_addr);
do {
udelay(1);
ret_val = e1000_flash_cycle_init_ich8lan(hw);
if (ret_val)
break;
hsflctl.regval = er16flash(ICH_FLASH_HSFCTL);
hsflctl.hsf_ctrl.fldbcount = size - 1;
hsflctl.hsf_ctrl.flcycle = ICH_CYCLE_READ;
ew16flash(ICH_FLASH_HSFCTL, hsflctl.regval);
ew32flash(ICH_FLASH_FADDR, flash_linear_addr);
ret_val =
e1000_flash_cycle_ich8lan(hw,
ICH_FLASH_READ_COMMAND_TIMEOUT);
if (!ret_val) {
flash_data = er32flash(ICH_FLASH_FDATA0);
if (size == 1)
*data = (u8)(flash_data & 0x000000FF);
else if (size == 2)
*data = (u16)(flash_data & 0x0000FFFF);
break;
} else {
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
if (hsfsts.hsf_status.flcerr) {
continue;
} else if (!hsfsts.hsf_status.flcdone) {
e_dbg("Timeout error - flash cycle did not complete.\n");
break;
}
}
} while (count++ < ICH_FLASH_CYCLE_REPEAT_COUNT);
return ret_val;
}
static s32 e1000_read_flash_data32_ich8lan(struct e1000_hw *hw, u32 offset,
u32 *data)
{
union ich8_hws_flash_status hsfsts;
union ich8_hws_flash_ctrl hsflctl;
u32 flash_linear_addr;
s32 ret_val = -E1000_ERR_NVM;
u8 count = 0;
if (offset > ICH_FLASH_LINEAR_ADDR_MASK ||
hw->mac.type != e1000_pch_spt)
return -E1000_ERR_NVM;
flash_linear_addr = ((ICH_FLASH_LINEAR_ADDR_MASK & offset) +
hw->nvm.flash_base_addr);
do {
udelay(1);
ret_val = e1000_flash_cycle_init_ich8lan(hw);
if (ret_val)
break;
hsflctl.regval = er32flash(ICH_FLASH_HSFSTS) >> 16;
hsflctl.hsf_ctrl.fldbcount = sizeof(u32) - 1;
hsflctl.hsf_ctrl.flcycle = ICH_CYCLE_READ;
ew32flash(ICH_FLASH_HSFSTS, (u32)hsflctl.regval << 16);
ew32flash(ICH_FLASH_FADDR, flash_linear_addr);
ret_val =
e1000_flash_cycle_ich8lan(hw,
ICH_FLASH_READ_COMMAND_TIMEOUT);
if (!ret_val) {
*data = er32flash(ICH_FLASH_FDATA0);
break;
} else {
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
if (hsfsts.hsf_status.flcerr) {
continue;
} else if (!hsfsts.hsf_status.flcdone) {
e_dbg("Timeout error - flash cycle did not complete.\n");
break;
}
}
} while (count++ < ICH_FLASH_CYCLE_REPEAT_COUNT);
return ret_val;
}
static s32 e1000_write_nvm_ich8lan(struct e1000_hw *hw, u16 offset, u16 words,
u16 *data)
{
struct e1000_nvm_info *nvm = &hw->nvm;
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u16 i;
if ((offset >= nvm->word_size) || (words > nvm->word_size - offset) ||
(words == 0)) {
e_dbg("nvm parameter(s) out of bounds\n");
return -E1000_ERR_NVM;
}
nvm->ops.acquire(hw);
for (i = 0; i < words; i++) {
dev_spec->shadow_ram[offset + i].modified = true;
dev_spec->shadow_ram[offset + i].value = data[i];
}
nvm->ops.release(hw);
return 0;
}
static s32 e1000_update_nvm_checksum_spt(struct e1000_hw *hw)
{
struct e1000_nvm_info *nvm = &hw->nvm;
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u32 i, act_offset, new_bank_offset, old_bank_offset, bank;
s32 ret_val;
u32 dword = 0;
ret_val = e1000e_update_nvm_checksum_generic(hw);
if (ret_val)
goto out;
if (nvm->type != e1000_nvm_flash_sw)
goto out;
nvm->ops.acquire(hw);
ret_val = e1000_valid_nvm_bank_detect_ich8lan(hw, &bank);
if (ret_val) {
e_dbg("Could not detect valid bank, assuming bank 0\n");
bank = 0;
}
if (bank == 0) {
new_bank_offset = nvm->flash_bank_size;
old_bank_offset = 0;
ret_val = e1000_erase_flash_bank_ich8lan(hw, 1);
if (ret_val)
goto release;
} else {
old_bank_offset = nvm->flash_bank_size;
new_bank_offset = 0;
ret_val = e1000_erase_flash_bank_ich8lan(hw, 0);
if (ret_val)
goto release;
}
for (i = 0; i < E1000_ICH8_SHADOW_RAM_WORDS; i += 2) {
ret_val = e1000_read_flash_dword_ich8lan(hw,
i + old_bank_offset,
&dword);
if (dev_spec->shadow_ram[i].modified) {
dword &= 0xffff0000;
dword |= (dev_spec->shadow_ram[i].value & 0xffff);
}
if (dev_spec->shadow_ram[i + 1].modified) {
dword &= 0x0000ffff;
dword |= ((dev_spec->shadow_ram[i + 1].value & 0xffff)
<< 16);
}
if (ret_val)
break;
if (i == E1000_ICH_NVM_SIG_WORD - 1)
dword |= E1000_ICH_NVM_SIG_MASK << 16;
act_offset = (i + new_bank_offset) << 1;
usleep_range(100, 200);
act_offset = i + new_bank_offset;
ret_val = e1000_retry_write_flash_dword_ich8lan(hw, act_offset,
dword);
if (ret_val)
break;
}
if (ret_val) {
e_dbg("Flash commit failed.\n");
goto release;
}
act_offset = new_bank_offset + E1000_ICH_NVM_SIG_WORD;
--act_offset;
ret_val = e1000_read_flash_dword_ich8lan(hw, act_offset, &dword);
if (ret_val)
goto release;
dword &= 0xBFFFFFFF;
ret_val = e1000_retry_write_flash_dword_ich8lan(hw, act_offset, dword);
if (ret_val)
goto release;
act_offset = (old_bank_offset + E1000_ICH_NVM_SIG_WORD) * 2 + 1;
act_offset = old_bank_offset + E1000_ICH_NVM_SIG_WORD - 1;
ret_val = e1000_read_flash_dword_ich8lan(hw, act_offset, &dword);
if (ret_val)
goto release;
dword &= 0x00FFFFFF;
ret_val = e1000_retry_write_flash_dword_ich8lan(hw, act_offset, dword);
if (ret_val)
goto release;
for (i = 0; i < E1000_ICH8_SHADOW_RAM_WORDS; i++) {
dev_spec->shadow_ram[i].modified = false;
dev_spec->shadow_ram[i].value = 0xFFFF;
}
release:
nvm->ops.release(hw);
if (!ret_val) {
nvm->ops.reload(hw);
usleep_range(10000, 20000);
}
out:
if (ret_val)
e_dbg("NVM update error: %d\n", ret_val);
return ret_val;
}
static s32 e1000_update_nvm_checksum_ich8lan(struct e1000_hw *hw)
{
struct e1000_nvm_info *nvm = &hw->nvm;
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u32 i, act_offset, new_bank_offset, old_bank_offset, bank;
s32 ret_val;
u16 data = 0;
ret_val = e1000e_update_nvm_checksum_generic(hw);
if (ret_val)
goto out;
if (nvm->type != e1000_nvm_flash_sw)
goto out;
nvm->ops.acquire(hw);
ret_val = e1000_valid_nvm_bank_detect_ich8lan(hw, &bank);
if (ret_val) {
e_dbg("Could not detect valid bank, assuming bank 0\n");
bank = 0;
}
if (bank == 0) {
new_bank_offset = nvm->flash_bank_size;
old_bank_offset = 0;
ret_val = e1000_erase_flash_bank_ich8lan(hw, 1);
if (ret_val)
goto release;
} else {
old_bank_offset = nvm->flash_bank_size;
new_bank_offset = 0;
ret_val = e1000_erase_flash_bank_ich8lan(hw, 0);
if (ret_val)
goto release;
}
for (i = 0; i < E1000_ICH8_SHADOW_RAM_WORDS; i++) {
if (dev_spec->shadow_ram[i].modified) {
data = dev_spec->shadow_ram[i].value;
} else {
ret_val = e1000_read_flash_word_ich8lan(hw, i +
old_bank_offset,
&data);
if (ret_val)
break;
}
if (i == E1000_ICH_NVM_SIG_WORD)
data |= E1000_ICH_NVM_SIG_MASK;
act_offset = (i + new_bank_offset) << 1;
usleep_range(100, 200);
ret_val = e1000_retry_write_flash_byte_ich8lan(hw,
act_offset,
(u8)data);
if (ret_val)
break;
usleep_range(100, 200);
ret_val = e1000_retry_write_flash_byte_ich8lan(hw,
act_offset + 1,
(u8)(data >> 8));
if (ret_val)
break;
}
if (ret_val) {
e_dbg("Flash commit failed.\n");
goto release;
}
act_offset = new_bank_offset + E1000_ICH_NVM_SIG_WORD;
ret_val = e1000_read_flash_word_ich8lan(hw, act_offset, &data);
if (ret_val)
goto release;
data &= 0xBFFF;
ret_val = e1000_retry_write_flash_byte_ich8lan(hw,
act_offset * 2 + 1,
(u8)(data >> 8));
if (ret_val)
goto release;
act_offset = (old_bank_offset + E1000_ICH_NVM_SIG_WORD) * 2 + 1;
ret_val = e1000_retry_write_flash_byte_ich8lan(hw, act_offset, 0);
if (ret_val)
goto release;
for (i = 0; i < E1000_ICH8_SHADOW_RAM_WORDS; i++) {
dev_spec->shadow_ram[i].modified = false;
dev_spec->shadow_ram[i].value = 0xFFFF;
}
release:
nvm->ops.release(hw);
if (!ret_val) {
nvm->ops.reload(hw);
usleep_range(10000, 20000);
}
out:
if (ret_val)
e_dbg("NVM update error: %d\n", ret_val);
return ret_val;
}
static s32 e1000_validate_nvm_checksum_ich8lan(struct e1000_hw *hw)
{
s32 ret_val;
u16 data;
u16 word;
u16 valid_csum_mask;
switch (hw->mac.type) {
case e1000_pch_lpt:
case e1000_pch_spt:
word = NVM_COMPAT;
valid_csum_mask = NVM_COMPAT_VALID_CSUM;
break;
default:
word = NVM_FUTURE_INIT_WORD1;
valid_csum_mask = NVM_FUTURE_INIT_WORD1_VALID_CSUM;
break;
}
ret_val = e1000_read_nvm(hw, word, 1, &data);
if (ret_val)
return ret_val;
if (!(data & valid_csum_mask)) {
data |= valid_csum_mask;
ret_val = e1000_write_nvm(hw, word, 1, &data);
if (ret_val)
return ret_val;
ret_val = e1000e_update_nvm_checksum(hw);
if (ret_val)
return ret_val;
}
return e1000e_validate_nvm_checksum_generic(hw);
}
void e1000e_write_protect_nvm_ich8lan(struct e1000_hw *hw)
{
struct e1000_nvm_info *nvm = &hw->nvm;
union ich8_flash_protected_range pr0;
union ich8_hws_flash_status hsfsts;
u32 gfpreg;
nvm->ops.acquire(hw);
gfpreg = er32flash(ICH_FLASH_GFPREG);
pr0.regval = er32flash(ICH_FLASH_PR0);
pr0.range.base = gfpreg & FLASH_GFPREG_BASE_MASK;
pr0.range.limit = ((gfpreg >> 16) & FLASH_GFPREG_BASE_MASK);
pr0.range.wpe = true;
ew32flash(ICH_FLASH_PR0, pr0.regval);
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
hsfsts.hsf_status.flockdn = true;
ew32flash(ICH_FLASH_HSFSTS, hsfsts.regval);
nvm->ops.release(hw);
}
static s32 e1000_write_flash_data_ich8lan(struct e1000_hw *hw, u32 offset,
u8 size, u16 data)
{
union ich8_hws_flash_status hsfsts;
union ich8_hws_flash_ctrl hsflctl;
u32 flash_linear_addr;
u32 flash_data = 0;
s32 ret_val;
u8 count = 0;
if (hw->mac.type == e1000_pch_spt) {
if (size != 4 || offset > ICH_FLASH_LINEAR_ADDR_MASK)
return -E1000_ERR_NVM;
} else {
if (size < 1 || size > 2 || offset > ICH_FLASH_LINEAR_ADDR_MASK)
return -E1000_ERR_NVM;
}
flash_linear_addr = ((ICH_FLASH_LINEAR_ADDR_MASK & offset) +
hw->nvm.flash_base_addr);
do {
udelay(1);
ret_val = e1000_flash_cycle_init_ich8lan(hw);
if (ret_val)
break;
if (hw->mac.type == e1000_pch_spt)
hsflctl.regval = er32flash(ICH_FLASH_HSFSTS) >> 16;
else
hsflctl.regval = er16flash(ICH_FLASH_HSFCTL);
hsflctl.hsf_ctrl.fldbcount = size - 1;
hsflctl.hsf_ctrl.flcycle = ICH_CYCLE_WRITE;
if (hw->mac.type == e1000_pch_spt)
ew32flash(ICH_FLASH_HSFSTS, hsflctl.regval << 16);
else
ew16flash(ICH_FLASH_HSFCTL, hsflctl.regval);
ew32flash(ICH_FLASH_FADDR, flash_linear_addr);
if (size == 1)
flash_data = (u32)data & 0x00FF;
else
flash_data = (u32)data;
ew32flash(ICH_FLASH_FDATA0, flash_data);
ret_val =
e1000_flash_cycle_ich8lan(hw,
ICH_FLASH_WRITE_COMMAND_TIMEOUT);
if (!ret_val)
break;
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
if (hsfsts.hsf_status.flcerr)
continue;
if (!hsfsts.hsf_status.flcdone) {
e_dbg("Timeout error - flash cycle did not complete.\n");
break;
}
} while (count++ < ICH_FLASH_CYCLE_REPEAT_COUNT);
return ret_val;
}
static s32 e1000_write_flash_data32_ich8lan(struct e1000_hw *hw, u32 offset,
u32 data)
{
union ich8_hws_flash_status hsfsts;
union ich8_hws_flash_ctrl hsflctl;
u32 flash_linear_addr;
s32 ret_val;
u8 count = 0;
if (hw->mac.type == e1000_pch_spt) {
if (offset > ICH_FLASH_LINEAR_ADDR_MASK)
return -E1000_ERR_NVM;
}
flash_linear_addr = ((ICH_FLASH_LINEAR_ADDR_MASK & offset) +
hw->nvm.flash_base_addr);
do {
udelay(1);
ret_val = e1000_flash_cycle_init_ich8lan(hw);
if (ret_val)
break;
if (hw->mac.type == e1000_pch_spt)
hsflctl.regval = er32flash(ICH_FLASH_HSFSTS)
>> 16;
else
hsflctl.regval = er16flash(ICH_FLASH_HSFCTL);
hsflctl.hsf_ctrl.fldbcount = sizeof(u32) - 1;
hsflctl.hsf_ctrl.flcycle = ICH_CYCLE_WRITE;
if (hw->mac.type == e1000_pch_spt)
ew32flash(ICH_FLASH_HSFSTS, hsflctl.regval << 16);
else
ew16flash(ICH_FLASH_HSFCTL, hsflctl.regval);
ew32flash(ICH_FLASH_FADDR, flash_linear_addr);
ew32flash(ICH_FLASH_FDATA0, data);
ret_val =
e1000_flash_cycle_ich8lan(hw,
ICH_FLASH_WRITE_COMMAND_TIMEOUT);
if (!ret_val)
break;
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
if (hsfsts.hsf_status.flcerr)
continue;
if (!hsfsts.hsf_status.flcdone) {
e_dbg("Timeout error - flash cycle did not complete.\n");
break;
}
} while (count++ < ICH_FLASH_CYCLE_REPEAT_COUNT);
return ret_val;
}
static s32 e1000_write_flash_byte_ich8lan(struct e1000_hw *hw, u32 offset,
u8 data)
{
u16 word = (u16)data;
return e1000_write_flash_data_ich8lan(hw, offset, 1, word);
}
static s32 e1000_retry_write_flash_dword_ich8lan(struct e1000_hw *hw,
u32 offset, u32 dword)
{
s32 ret_val;
u16 program_retries;
offset <<= 1;
ret_val = e1000_write_flash_data32_ich8lan(hw, offset, dword);
if (!ret_val)
return ret_val;
for (program_retries = 0; program_retries < 100; program_retries++) {
e_dbg("Retrying Byte %8.8X at offset %u\n", dword, offset);
usleep_range(100, 200);
ret_val = e1000_write_flash_data32_ich8lan(hw, offset, dword);
if (!ret_val)
break;
}
if (program_retries == 100)
return -E1000_ERR_NVM;
return 0;
}
static s32 e1000_retry_write_flash_byte_ich8lan(struct e1000_hw *hw,
u32 offset, u8 byte)
{
s32 ret_val;
u16 program_retries;
ret_val = e1000_write_flash_byte_ich8lan(hw, offset, byte);
if (!ret_val)
return ret_val;
for (program_retries = 0; program_retries < 100; program_retries++) {
e_dbg("Retrying Byte %2.2X at offset %u\n", byte, offset);
usleep_range(100, 200);
ret_val = e1000_write_flash_byte_ich8lan(hw, offset, byte);
if (!ret_val)
break;
}
if (program_retries == 100)
return -E1000_ERR_NVM;
return 0;
}
static s32 e1000_erase_flash_bank_ich8lan(struct e1000_hw *hw, u32 bank)
{
struct e1000_nvm_info *nvm = &hw->nvm;
union ich8_hws_flash_status hsfsts;
union ich8_hws_flash_ctrl hsflctl;
u32 flash_linear_addr;
u32 flash_bank_size = nvm->flash_bank_size * 2;
s32 ret_val;
s32 count = 0;
s32 j, iteration, sector_size;
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
switch (hsfsts.hsf_status.berasesz) {
case 0:
sector_size = ICH_FLASH_SEG_SIZE_256;
iteration = flash_bank_size / ICH_FLASH_SEG_SIZE_256;
break;
case 1:
sector_size = ICH_FLASH_SEG_SIZE_4K;
iteration = 1;
break;
case 2:
sector_size = ICH_FLASH_SEG_SIZE_8K;
iteration = 1;
break;
case 3:
sector_size = ICH_FLASH_SEG_SIZE_64K;
iteration = 1;
break;
default:
return -E1000_ERR_NVM;
}
flash_linear_addr = hw->nvm.flash_base_addr;
flash_linear_addr += (bank) ? flash_bank_size : 0;
for (j = 0; j < iteration; j++) {
do {
u32 timeout = ICH_FLASH_ERASE_COMMAND_TIMEOUT;
ret_val = e1000_flash_cycle_init_ich8lan(hw);
if (ret_val)
return ret_val;
if (hw->mac.type == e1000_pch_spt)
hsflctl.regval =
er32flash(ICH_FLASH_HSFSTS) >> 16;
else
hsflctl.regval = er16flash(ICH_FLASH_HSFCTL);
hsflctl.hsf_ctrl.flcycle = ICH_CYCLE_ERASE;
if (hw->mac.type == e1000_pch_spt)
ew32flash(ICH_FLASH_HSFSTS,
hsflctl.regval << 16);
else
ew16flash(ICH_FLASH_HSFCTL, hsflctl.regval);
flash_linear_addr += (j * sector_size);
ew32flash(ICH_FLASH_FADDR, flash_linear_addr);
ret_val = e1000_flash_cycle_ich8lan(hw, timeout);
if (!ret_val)
break;
hsfsts.regval = er16flash(ICH_FLASH_HSFSTS);
if (hsfsts.hsf_status.flcerr)
continue;
else if (!hsfsts.hsf_status.flcdone)
return ret_val;
} while (++count < ICH_FLASH_CYCLE_REPEAT_COUNT);
}
return 0;
}
static s32 e1000_valid_led_default_ich8lan(struct e1000_hw *hw, u16 *data)
{
s32 ret_val;
ret_val = e1000_read_nvm(hw, NVM_ID_LED_SETTINGS, 1, data);
if (ret_val) {
e_dbg("NVM Read Error\n");
return ret_val;
}
if (*data == ID_LED_RESERVED_0000 || *data == ID_LED_RESERVED_FFFF)
*data = ID_LED_DEFAULT_ICH8LAN;
return 0;
}
static s32 e1000_id_led_init_pchlan(struct e1000_hw *hw)
{
struct e1000_mac_info *mac = &hw->mac;
s32 ret_val;
const u32 ledctl_on = E1000_LEDCTL_MODE_LINK_UP;
const u32 ledctl_off = E1000_LEDCTL_MODE_LINK_UP | E1000_PHY_LED0_IVRT;
u16 data, i, temp, shift;
ret_val = hw->nvm.ops.valid_led_default(hw, &data);
if (ret_val)
return ret_val;
mac->ledctl_default = er32(LEDCTL);
mac->ledctl_mode1 = mac->ledctl_default;
mac->ledctl_mode2 = mac->ledctl_default;
for (i = 0; i < 4; i++) {
temp = (data >> (i << 2)) & E1000_LEDCTL_LED0_MODE_MASK;
shift = (i * 5);
switch (temp) {
case ID_LED_ON1_DEF2:
case ID_LED_ON1_ON2:
case ID_LED_ON1_OFF2:
mac->ledctl_mode1 &= ~(E1000_PHY_LED0_MASK << shift);
mac->ledctl_mode1 |= (ledctl_on << shift);
break;
case ID_LED_OFF1_DEF2:
case ID_LED_OFF1_ON2:
case ID_LED_OFF1_OFF2:
mac->ledctl_mode1 &= ~(E1000_PHY_LED0_MASK << shift);
mac->ledctl_mode1 |= (ledctl_off << shift);
break;
default:
break;
}
switch (temp) {
case ID_LED_DEF1_ON2:
case ID_LED_ON1_ON2:
case ID_LED_OFF1_ON2:
mac->ledctl_mode2 &= ~(E1000_PHY_LED0_MASK << shift);
mac->ledctl_mode2 |= (ledctl_on << shift);
break;
case ID_LED_DEF1_OFF2:
case ID_LED_ON1_OFF2:
case ID_LED_OFF1_OFF2:
mac->ledctl_mode2 &= ~(E1000_PHY_LED0_MASK << shift);
mac->ledctl_mode2 |= (ledctl_off << shift);
break;
default:
break;
}
}
return 0;
}
static s32 e1000_get_bus_info_ich8lan(struct e1000_hw *hw)
{
struct e1000_bus_info *bus = &hw->bus;
s32 ret_val;
ret_val = e1000e_get_bus_info_pcie(hw);
if (bus->width == e1000_bus_width_unknown)
bus->width = e1000_bus_width_pcie_x1;
return ret_val;
}
static s32 e1000_reset_hw_ich8lan(struct e1000_hw *hw)
{
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u16 kum_cfg;
u32 ctrl, reg;
s32 ret_val;
ret_val = e1000e_disable_pcie_master(hw);
if (ret_val)
e_dbg("PCI-E Master disable polling has failed.\n");
e_dbg("Masking off all interrupts\n");
ew32(IMC, 0xffffffff);
ew32(RCTL, 0);
ew32(TCTL, E1000_TCTL_PSP);
e1e_flush();
usleep_range(10000, 20000);
if (hw->mac.type == e1000_ich8lan) {
ew32(PBA, E1000_PBA_8K);
ew32(PBS, E1000_PBS_16K);
}
if (hw->mac.type == e1000_pchlan) {
ret_val = e1000_read_nvm(hw, E1000_NVM_K1_CONFIG, 1, &kum_cfg);
if (ret_val)
return ret_val;
if (kum_cfg & E1000_NVM_K1_ENABLE)
dev_spec->nvm_k1_enabled = true;
else
dev_spec->nvm_k1_enabled = false;
}
ctrl = er32(CTRL);
if (!hw->phy.ops.check_reset_block(hw)) {
ctrl |= E1000_CTRL_PHY_RST;
if ((hw->mac.type == e1000_pch2lan) &&
!(er32(FWSM) & E1000_ICH_FWSM_FW_VALID))
e1000_gate_hw_phy_config_ich8lan(hw, true);
}
ret_val = e1000_acquire_swflag_ich8lan(hw);
e_dbg("Issuing a global reset to ich8lan\n");
ew32(CTRL, (ctrl | E1000_CTRL_RST));
msleep(20);
if (hw->mac.type == e1000_pch2lan) {
reg = er32(FEXTNVM3);
reg &= ~E1000_FEXTNVM3_PHY_CFG_COUNTER_MASK;
reg |= E1000_FEXTNVM3_PHY_CFG_COUNTER_50MSEC;
ew32(FEXTNVM3, reg);
}
if (!ret_val)
clear_bit(__E1000_ACCESS_SHARED_RESOURCE, &hw->adapter->state);
if (ctrl & E1000_CTRL_PHY_RST) {
ret_val = hw->phy.ops.get_cfg_done(hw);
if (ret_val)
return ret_val;
ret_val = e1000_post_phy_reset_ich8lan(hw);
if (ret_val)
return ret_val;
}
if (hw->mac.type == e1000_pchlan)
ew32(CRC_OFFSET, 0x65656565);
ew32(IMC, 0xffffffff);
er32(ICR);
reg = er32(KABGTXD);
reg |= E1000_KABGTXD_BGSQLBIAS;
ew32(KABGTXD, reg);
return 0;
}
static s32 e1000_init_hw_ich8lan(struct e1000_hw *hw)
{
struct e1000_mac_info *mac = &hw->mac;
u32 ctrl_ext, txdctl, snoop;
s32 ret_val;
u16 i;
e1000_initialize_hw_bits_ich8lan(hw);
ret_val = mac->ops.id_led_init(hw);
if (ret_val)
e_dbg("Error initializing identification LED\n");
e1000e_init_rx_addrs(hw, mac->rar_entry_count);
e_dbg("Zeroing the MTA\n");
for (i = 0; i < mac->mta_reg_count; i++)
E1000_WRITE_REG_ARRAY(hw, E1000_MTA, i, 0);
if (hw->phy.type == e1000_phy_82578) {
e1e_rphy(hw, BM_PORT_GEN_CFG, &i);
i &= ~BM_WUC_HOST_WU_BIT;
e1e_wphy(hw, BM_PORT_GEN_CFG, i);
ret_val = e1000_phy_hw_reset_ich8lan(hw);
if (ret_val)
return ret_val;
}
ret_val = mac->ops.setup_link(hw);
txdctl = er32(TXDCTL(0));
txdctl = ((txdctl & ~E1000_TXDCTL_WTHRESH) |
E1000_TXDCTL_FULL_TX_DESC_WB);
txdctl = ((txdctl & ~E1000_TXDCTL_PTHRESH) |
E1000_TXDCTL_MAX_TX_DESC_PREFETCH);
ew32(TXDCTL(0), txdctl);
txdctl = er32(TXDCTL(1));
txdctl = ((txdctl & ~E1000_TXDCTL_WTHRESH) |
E1000_TXDCTL_FULL_TX_DESC_WB);
txdctl = ((txdctl & ~E1000_TXDCTL_PTHRESH) |
E1000_TXDCTL_MAX_TX_DESC_PREFETCH);
ew32(TXDCTL(1), txdctl);
if (mac->type == e1000_ich8lan)
snoop = PCIE_ICH8_SNOOP_ALL;
else
snoop = (u32)~(PCIE_NO_SNOOP_ALL);
e1000e_set_pcie_no_snoop(hw, snoop);
ctrl_ext = er32(CTRL_EXT);
ctrl_ext |= E1000_CTRL_EXT_RO_DIS;
ew32(CTRL_EXT, ctrl_ext);
e1000_clear_hw_cntrs_ich8lan(hw);
return ret_val;
}
static void e1000_initialize_hw_bits_ich8lan(struct e1000_hw *hw)
{
u32 reg;
reg = er32(CTRL_EXT);
reg |= (1 << 22);
if (hw->mac.type >= e1000_pchlan)
reg |= E1000_CTRL_EXT_PHYPDEN;
ew32(CTRL_EXT, reg);
reg = er32(TXDCTL(0));
reg |= (1 << 22);
ew32(TXDCTL(0), reg);
reg = er32(TXDCTL(1));
reg |= (1 << 22);
ew32(TXDCTL(1), reg);
reg = er32(TARC(0));
if (hw->mac.type == e1000_ich8lan)
reg |= (1 << 28) | (1 << 29);
reg |= (1 << 23) | (1 << 24) | (1 << 26) | (1 << 27);
ew32(TARC(0), reg);
reg = er32(TARC(1));
if (er32(TCTL) & E1000_TCTL_MULR)
reg &= ~(1 << 28);
else
reg |= (1 << 28);
reg |= (1 << 24) | (1 << 26) | (1 << 30);
ew32(TARC(1), reg);
if (hw->mac.type == e1000_ich8lan) {
reg = er32(STATUS);
reg &= ~(1 << 31);
ew32(STATUS, reg);
}
reg = er32(RFCTL);
reg |= (E1000_RFCTL_NFSW_DIS | E1000_RFCTL_NFSR_DIS);
if (hw->mac.type == e1000_ich8lan)
reg |= (E1000_RFCTL_IPV6_EX_DIS | E1000_RFCTL_NEW_IPV6_EXT_DIS);
ew32(RFCTL, reg);
if ((hw->mac.type == e1000_pch_lpt) ||
(hw->mac.type == e1000_pch_spt)) {
reg = er32(PBECCSTS);
reg |= E1000_PBECCSTS_ECC_ENABLE;
ew32(PBECCSTS, reg);
reg = er32(CTRL);
reg |= E1000_CTRL_MEHE;
ew32(CTRL, reg);
}
}
static s32 e1000_setup_link_ich8lan(struct e1000_hw *hw)
{
s32 ret_val;
if (hw->phy.ops.check_reset_block(hw))
return 0;
if (hw->fc.requested_mode == e1000_fc_default) {
if (hw->mac.type == e1000_pchlan)
hw->fc.requested_mode = e1000_fc_rx_pause;
else
hw->fc.requested_mode = e1000_fc_full;
}
hw->fc.current_mode = hw->fc.requested_mode;
e_dbg("After fix-ups FlowControl is now = %x\n", hw->fc.current_mode);
ret_val = hw->mac.ops.setup_physical_interface(hw);
if (ret_val)
return ret_val;
ew32(FCTTV, hw->fc.pause_time);
if ((hw->phy.type == e1000_phy_82578) ||
(hw->phy.type == e1000_phy_82579) ||
(hw->phy.type == e1000_phy_i217) ||
(hw->phy.type == e1000_phy_82577)) {
ew32(FCRTV_PCH, hw->fc.refresh_time);
ret_val = e1e_wphy(hw, PHY_REG(BM_PORT_CTRL_PAGE, 27),
hw->fc.pause_time);
if (ret_val)
return ret_val;
}
return e1000e_set_fc_watermarks(hw);
}
static s32 e1000_setup_copper_link_ich8lan(struct e1000_hw *hw)
{
u32 ctrl;
s32 ret_val;
u16 reg_data;
ctrl = er32(CTRL);
ctrl |= E1000_CTRL_SLU;
ctrl &= ~(E1000_CTRL_FRCSPD | E1000_CTRL_FRCDPX);
ew32(CTRL, ctrl);
ret_val = e1000e_write_kmrn_reg(hw, E1000_KMRNCTRLSTA_TIMEOUTS, 0xFFFF);
if (ret_val)
return ret_val;
ret_val = e1000e_read_kmrn_reg(hw, E1000_KMRNCTRLSTA_INBAND_PARAM,
&reg_data);
if (ret_val)
return ret_val;
reg_data |= 0x3F;
ret_val = e1000e_write_kmrn_reg(hw, E1000_KMRNCTRLSTA_INBAND_PARAM,
reg_data);
if (ret_val)
return ret_val;
switch (hw->phy.type) {
case e1000_phy_igp_3:
ret_val = e1000e_copper_link_setup_igp(hw);
if (ret_val)
return ret_val;
break;
case e1000_phy_bm:
case e1000_phy_82578:
ret_val = e1000e_copper_link_setup_m88(hw);
if (ret_val)
return ret_val;
break;
case e1000_phy_82577:
case e1000_phy_82579:
ret_val = e1000_copper_link_setup_82577(hw);
if (ret_val)
return ret_val;
break;
case e1000_phy_ife:
ret_val = e1e_rphy(hw, IFE_PHY_MDIX_CONTROL, &reg_data);
if (ret_val)
return ret_val;
reg_data &= ~IFE_PMC_AUTO_MDIX;
switch (hw->phy.mdix) {
case 1:
reg_data &= ~IFE_PMC_FORCE_MDIX;
break;
case 2:
reg_data |= IFE_PMC_FORCE_MDIX;
break;
case 0:
default:
reg_data |= IFE_PMC_AUTO_MDIX;
break;
}
ret_val = e1e_wphy(hw, IFE_PHY_MDIX_CONTROL, reg_data);
if (ret_val)
return ret_val;
break;
default:
break;
}
return e1000e_setup_copper_link(hw);
}
static s32 e1000_setup_copper_link_pch_lpt(struct e1000_hw *hw)
{
u32 ctrl;
s32 ret_val;
ctrl = er32(CTRL);
ctrl |= E1000_CTRL_SLU;
ctrl &= ~(E1000_CTRL_FRCSPD | E1000_CTRL_FRCDPX);
ew32(CTRL, ctrl);
ret_val = e1000_copper_link_setup_82577(hw);
if (ret_val)
return ret_val;
return e1000e_setup_copper_link(hw);
}
static s32 e1000_get_link_up_info_ich8lan(struct e1000_hw *hw, u16 *speed,
u16 *duplex)
{
s32 ret_val;
ret_val = e1000e_get_speed_and_duplex_copper(hw, speed, duplex);
if (ret_val)
return ret_val;
if ((hw->mac.type == e1000_ich8lan) &&
(hw->phy.type == e1000_phy_igp_3) && (*speed == SPEED_1000)) {
ret_val = e1000_kmrn_lock_loss_workaround_ich8lan(hw);
}
return ret_val;
}
static s32 e1000_kmrn_lock_loss_workaround_ich8lan(struct e1000_hw *hw)
{
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u32 phy_ctrl;
s32 ret_val;
u16 i, data;
bool link;
if (!dev_spec->kmrn_lock_loss_workaround_enabled)
return 0;
ret_val = e1000e_phy_has_link_generic(hw, 1, 0, &link);
if (!link)
return 0;
for (i = 0; i < 10; i++) {
ret_val = e1e_rphy(hw, IGP3_KMRN_DIAG, &data);
if (ret_val)
return ret_val;
ret_val = e1e_rphy(hw, IGP3_KMRN_DIAG, &data);
if (ret_val)
return ret_val;
if (!(data & IGP3_KMRN_DIAG_PCS_LOCK_LOSS))
return 0;
e1000_phy_hw_reset(hw);
mdelay(5);
}
phy_ctrl = er32(PHY_CTRL);
phy_ctrl |= (E1000_PHY_CTRL_GBE_DISABLE |
E1000_PHY_CTRL_NOND0A_GBE_DISABLE);
ew32(PHY_CTRL, phy_ctrl);
e1000e_gig_downshift_workaround_ich8lan(hw);
return -E1000_ERR_PHY;
}
void e1000e_set_kmrn_lock_loss_workaround_ich8lan(struct e1000_hw *hw,
bool state)
{
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
if (hw->mac.type != e1000_ich8lan) {
e_dbg("Workaround applies to ICH8 only.\n");
return;
}
dev_spec->kmrn_lock_loss_workaround_enabled = state;
}
void e1000e_igp3_phy_powerdown_workaround_ich8lan(struct e1000_hw *hw)
{
u32 reg;
u16 data;
u8 retry = 0;
if (hw->phy.type != e1000_phy_igp_3)
return;
do {
reg = er32(PHY_CTRL);
reg |= (E1000_PHY_CTRL_GBE_DISABLE |
E1000_PHY_CTRL_NOND0A_GBE_DISABLE);
ew32(PHY_CTRL, reg);
if (hw->mac.type == e1000_ich8lan)
e1000e_gig_downshift_workaround_ich8lan(hw);
e1e_rphy(hw, IGP3_VR_CTRL, &data);
data &= ~IGP3_VR_CTRL_DEV_POWERDOWN_MODE_MASK;
e1e_wphy(hw, IGP3_VR_CTRL, data | IGP3_VR_CTRL_MODE_SHUTDOWN);
e1e_rphy(hw, IGP3_VR_CTRL, &data);
data &= IGP3_VR_CTRL_DEV_POWERDOWN_MODE_MASK;
if ((data == IGP3_VR_CTRL_MODE_SHUTDOWN) || retry)
break;
reg = er32(CTRL);
ew32(CTRL, reg | E1000_CTRL_PHY_RST);
retry++;
} while (retry);
}
void e1000e_gig_downshift_workaround_ich8lan(struct e1000_hw *hw)
{
s32 ret_val;
u16 reg_data;
if ((hw->mac.type != e1000_ich8lan) || (hw->phy.type == e1000_phy_ife))
return;
ret_val = e1000e_read_kmrn_reg(hw, E1000_KMRNCTRLSTA_DIAG_OFFSET,
&reg_data);
if (ret_val)
return;
reg_data |= E1000_KMRNCTRLSTA_DIAG_NELPBK;
ret_val = e1000e_write_kmrn_reg(hw, E1000_KMRNCTRLSTA_DIAG_OFFSET,
reg_data);
if (ret_val)
return;
reg_data &= ~E1000_KMRNCTRLSTA_DIAG_NELPBK;
e1000e_write_kmrn_reg(hw, E1000_KMRNCTRLSTA_DIAG_OFFSET, reg_data);
}
void e1000_suspend_workarounds_ich8lan(struct e1000_hw *hw)
{
struct e1000_dev_spec_ich8lan *dev_spec = &hw->dev_spec.ich8lan;
u32 phy_ctrl;
s32 ret_val;
phy_ctrl = er32(PHY_CTRL);
phy_ctrl |= E1000_PHY_CTRL_GBE_DISABLE;
if (hw->phy.type == e1000_phy_i217) {
u16 phy_reg, device_id = hw->adapter->pdev->device;
if ((device_id == E1000_DEV_ID_PCH_LPTLP_I218_LM) ||
(device_id == E1000_DEV_ID_PCH_LPTLP_I218_V) ||
(device_id == E1000_DEV_ID_PCH_I218_LM3) ||
(device_id == E1000_DEV_ID_PCH_I218_V3) ||
(hw->mac.type == e1000_pch_spt)) {
u32 fextnvm6 = er32(FEXTNVM6);
ew32(FEXTNVM6, fextnvm6 & ~E1000_FEXTNVM6_REQ_PLL_CLK);
}
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
goto out;
if (!dev_spec->eee_disable) {
u16 eee_advert;
ret_val =
e1000_read_emi_reg_locked(hw,
I217_EEE_ADVERTISEMENT,
&eee_advert);
if (ret_val)
goto release;
if ((eee_advert & I82579_EEE_100_SUPPORTED) &&
(dev_spec->eee_lp_ability &
I82579_EEE_100_SUPPORTED) &&
(hw->phy.autoneg_advertised & ADVERTISE_100_FULL)) {
phy_ctrl &= ~(E1000_PHY_CTRL_D0A_LPLU |
E1000_PHY_CTRL_NOND0A_LPLU);
e1e_rphy_locked(hw,
I217_LPI_GPIO_CTRL, &phy_reg);
phy_reg |= I217_LPI_GPIO_CTRL_AUTO_EN_LPI;
e1e_wphy_locked(hw,
I217_LPI_GPIO_CTRL, phy_reg);
}
}
if (!(er32(FWSM) & E1000_ICH_FWSM_FW_VALID)) {
e1e_rphy_locked(hw, I217_PROXY_CTRL, &phy_reg);
phy_reg |= I217_PROXY_CTRL_AUTO_DISABLE;
e1e_wphy_locked(hw, I217_PROXY_CTRL, phy_reg);
e1e_rphy_locked(hw, I217_SxCTRL, &phy_reg);
phy_reg |= I217_SxCTRL_ENABLE_LPI_RESET;
e1e_wphy_locked(hw, I217_SxCTRL, phy_reg);
e1e_rphy_locked(hw, I217_MEMPWR, &phy_reg);
phy_reg &= ~I217_MEMPWR_DISABLE_SMB_RELEASE;
e1e_wphy_locked(hw, I217_MEMPWR, phy_reg);
}
e1e_rphy_locked(hw, I217_CGFREG, &phy_reg);
phy_reg |= I217_CGFREG_ENABLE_MTA_RESET;
e1e_wphy_locked(hw, I217_CGFREG, phy_reg);
release:
hw->phy.ops.release(hw);
}
out:
ew32(PHY_CTRL, phy_ctrl);
if (hw->mac.type == e1000_ich8lan)
e1000e_gig_downshift_workaround_ich8lan(hw);
if (hw->mac.type >= e1000_pchlan) {
e1000_oem_bits_config_ich8lan(hw, false);
if (hw->mac.type == e1000_pchlan)
e1000e_phy_hw_reset_generic(hw);
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return;
e1000_write_smbus_addr(hw);
hw->phy.ops.release(hw);
}
}
void e1000_resume_workarounds_pchlan(struct e1000_hw *hw)
{
s32 ret_val;
if (hw->mac.type < e1000_pch2lan)
return;
ret_val = e1000_init_phy_workarounds_pchlan(hw);
if (ret_val) {
e_dbg("Failed to init PHY flow ret_val=%d\n", ret_val);
return;
}
if (hw->phy.type == e1000_phy_i217) {
u16 phy_reg;
ret_val = hw->phy.ops.acquire(hw);
if (ret_val) {
e_dbg("Failed to setup iRST\n");
return;
}
e1e_rphy_locked(hw, I217_LPI_GPIO_CTRL, &phy_reg);
phy_reg &= ~I217_LPI_GPIO_CTRL_AUTO_EN_LPI;
e1e_wphy_locked(hw, I217_LPI_GPIO_CTRL, phy_reg);
if (!(er32(FWSM) & E1000_ICH_FWSM_FW_VALID)) {
ret_val = e1e_rphy_locked(hw, I217_MEMPWR, &phy_reg);
if (ret_val)
goto release;
phy_reg |= I217_MEMPWR_DISABLE_SMB_RELEASE;
e1e_wphy_locked(hw, I217_MEMPWR, phy_reg);
e1e_wphy_locked(hw, I217_PROXY_CTRL, 0);
}
ret_val = e1e_rphy_locked(hw, I217_CGFREG, &phy_reg);
if (ret_val)
goto release;
phy_reg &= ~I217_CGFREG_ENABLE_MTA_RESET;
e1e_wphy_locked(hw, I217_CGFREG, phy_reg);
release:
if (ret_val)
e_dbg("Error %d in resume workarounds\n", ret_val);
hw->phy.ops.release(hw);
}
}
static s32 e1000_cleanup_led_ich8lan(struct e1000_hw *hw)
{
if (hw->phy.type == e1000_phy_ife)
return e1e_wphy(hw, IFE_PHY_SPECIAL_CONTROL_LED, 0);
ew32(LEDCTL, hw->mac.ledctl_default);
return 0;
}
static s32 e1000_led_on_ich8lan(struct e1000_hw *hw)
{
if (hw->phy.type == e1000_phy_ife)
return e1e_wphy(hw, IFE_PHY_SPECIAL_CONTROL_LED,
(IFE_PSCL_PROBE_MODE | IFE_PSCL_PROBE_LEDS_ON));
ew32(LEDCTL, hw->mac.ledctl_mode2);
return 0;
}
static s32 e1000_led_off_ich8lan(struct e1000_hw *hw)
{
if (hw->phy.type == e1000_phy_ife)
return e1e_wphy(hw, IFE_PHY_SPECIAL_CONTROL_LED,
(IFE_PSCL_PROBE_MODE |
IFE_PSCL_PROBE_LEDS_OFF));
ew32(LEDCTL, hw->mac.ledctl_mode1);
return 0;
}
static s32 e1000_setup_led_pchlan(struct e1000_hw *hw)
{
return e1e_wphy(hw, HV_LED_CONFIG, (u16)hw->mac.ledctl_mode1);
}
static s32 e1000_cleanup_led_pchlan(struct e1000_hw *hw)
{
return e1e_wphy(hw, HV_LED_CONFIG, (u16)hw->mac.ledctl_default);
}
static s32 e1000_led_on_pchlan(struct e1000_hw *hw)
{
u16 data = (u16)hw->mac.ledctl_mode2;
u32 i, led;
if (!(er32(STATUS) & E1000_STATUS_LU)) {
for (i = 0; i < 3; i++) {
led = (data >> (i * 5)) & E1000_PHY_LED0_MASK;
if ((led & E1000_PHY_LED0_MODE_MASK) !=
E1000_LEDCTL_MODE_LINK_UP)
continue;
if (led & E1000_PHY_LED0_IVRT)
data &= ~(E1000_PHY_LED0_IVRT << (i * 5));
else
data |= (E1000_PHY_LED0_IVRT << (i * 5));
}
}
return e1e_wphy(hw, HV_LED_CONFIG, data);
}
static s32 e1000_led_off_pchlan(struct e1000_hw *hw)
{
u16 data = (u16)hw->mac.ledctl_mode1;
u32 i, led;
if (!(er32(STATUS) & E1000_STATUS_LU)) {
for (i = 0; i < 3; i++) {
led = (data >> (i * 5)) & E1000_PHY_LED0_MASK;
if ((led & E1000_PHY_LED0_MODE_MASK) !=
E1000_LEDCTL_MODE_LINK_UP)
continue;
if (led & E1000_PHY_LED0_IVRT)
data &= ~(E1000_PHY_LED0_IVRT << (i * 5));
else
data |= (E1000_PHY_LED0_IVRT << (i * 5));
}
}
return e1e_wphy(hw, HV_LED_CONFIG, data);
}
static s32 e1000_get_cfg_done_ich8lan(struct e1000_hw *hw)
{
s32 ret_val = 0;
u32 bank = 0;
u32 status;
e1000e_get_cfg_done_generic(hw);
if (hw->mac.type >= e1000_ich10lan) {
e1000_lan_init_done_ich8lan(hw);
} else {
ret_val = e1000e_get_auto_rd_done(hw);
if (ret_val) {
e_dbg("Auto Read Done did not complete\n");
ret_val = 0;
}
}
status = er32(STATUS);
if (status & E1000_STATUS_PHYRA)
ew32(STATUS, status & ~E1000_STATUS_PHYRA);
else
e_dbg("PHY Reset Asserted not set - needs delay\n");
if (hw->mac.type <= e1000_ich9lan) {
if (!(er32(EECD) & E1000_EECD_PRES) &&
(hw->phy.type == e1000_phy_igp_3)) {
e1000e_phy_init_script_igp3(hw);
}
} else {
if (e1000_valid_nvm_bank_detect_ich8lan(hw, &bank)) {
e_dbg("EEPROM not present\n");
ret_val = -E1000_ERR_CONFIG;
}
}
return ret_val;
}
static void e1000_power_down_phy_copper_ich8lan(struct e1000_hw *hw)
{
if (!(hw->mac.ops.check_mng_mode(hw) ||
hw->phy.ops.check_reset_block(hw)))
e1000_power_down_phy_copper(hw);
}
static void e1000_clear_hw_cntrs_ich8lan(struct e1000_hw *hw)
{
u16 phy_data;
s32 ret_val;
e1000e_clear_hw_cntrs_base(hw);
er32(ALGNERRC);
er32(RXERRC);
er32(TNCRS);
er32(CEXTERR);
er32(TSCTC);
er32(TSCTFC);
er32(MGTPRC);
er32(MGTPDC);
er32(MGTPTC);
er32(IAC);
er32(ICRXOC);
if ((hw->phy.type == e1000_phy_82578) ||
(hw->phy.type == e1000_phy_82579) ||
(hw->phy.type == e1000_phy_i217) ||
(hw->phy.type == e1000_phy_82577)) {
ret_val = hw->phy.ops.acquire(hw);
if (ret_val)
return;
ret_val = hw->phy.ops.set_page(hw,
HV_STATS_PAGE << IGP_PAGE_SHIFT);
if (ret_val)
goto release;
hw->phy.ops.read_reg_page(hw, HV_SCC_UPPER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_SCC_LOWER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_ECOL_UPPER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_ECOL_LOWER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_MCC_UPPER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_MCC_LOWER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_LATECOL_UPPER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_LATECOL_LOWER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_COLC_UPPER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_COLC_LOWER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_DC_UPPER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_DC_LOWER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_TNCRS_UPPER, &phy_data);
hw->phy.ops.read_reg_page(hw, HV_TNCRS_LOWER, &phy_data);
release:
hw->phy.ops.release(hw);
}
}
