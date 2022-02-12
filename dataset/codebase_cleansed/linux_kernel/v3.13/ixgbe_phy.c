s32 ixgbe_identify_phy_generic(struct ixgbe_hw *hw)
{
s32 status = IXGBE_ERR_PHY_ADDR_INVALID;
u32 phy_addr;
u16 ext_ability = 0;
if (hw->phy.type == ixgbe_phy_unknown) {
for (phy_addr = 0; phy_addr < IXGBE_MAX_PHY_ADDR; phy_addr++) {
hw->phy.mdio.prtad = phy_addr;
if (mdio45_probe(&hw->phy.mdio, phy_addr) == 0) {
ixgbe_get_phy_id(hw);
hw->phy.type =
ixgbe_get_phy_type_from_id(hw->phy.id);
if (hw->phy.type == ixgbe_phy_unknown) {
hw->phy.ops.read_reg(hw,
MDIO_PMA_EXTABLE,
MDIO_MMD_PMAPMD,
&ext_ability);
if (ext_ability &
(MDIO_PMA_EXTABLE_10GBT |
MDIO_PMA_EXTABLE_1000BT))
hw->phy.type =
ixgbe_phy_cu_unknown;
else
hw->phy.type =
ixgbe_phy_generic;
}
status = 0;
break;
}
}
if (status != 0)
hw->phy.mdio.prtad = 0;
} else {
status = 0;
}
return status;
}
static s32 ixgbe_get_phy_id(struct ixgbe_hw *hw)
{
u32 status;
u16 phy_id_high = 0;
u16 phy_id_low = 0;
status = hw->phy.ops.read_reg(hw, MDIO_DEVID1, MDIO_MMD_PMAPMD,
&phy_id_high);
if (status == 0) {
hw->phy.id = (u32)(phy_id_high << 16);
status = hw->phy.ops.read_reg(hw, MDIO_DEVID2, MDIO_MMD_PMAPMD,
&phy_id_low);
hw->phy.id |= (u32)(phy_id_low & IXGBE_PHY_REVISION_MASK);
hw->phy.revision = (u32)(phy_id_low & ~IXGBE_PHY_REVISION_MASK);
}
return status;
}
static enum ixgbe_phy_type ixgbe_get_phy_type_from_id(u32 phy_id)
{
enum ixgbe_phy_type phy_type;
switch (phy_id) {
case TN1010_PHY_ID:
phy_type = ixgbe_phy_tn;
break;
case X540_PHY_ID:
phy_type = ixgbe_phy_aq;
break;
case QT2022_PHY_ID:
phy_type = ixgbe_phy_qt;
break;
case ATH_PHY_ID:
phy_type = ixgbe_phy_nl;
break;
default:
phy_type = ixgbe_phy_unknown;
break;
}
return phy_type;
}
s32 ixgbe_reset_phy_generic(struct ixgbe_hw *hw)
{
u32 i;
u16 ctrl = 0;
s32 status = 0;
if (hw->phy.type == ixgbe_phy_unknown)
status = ixgbe_identify_phy_generic(hw);
if (status != 0 || hw->phy.type == ixgbe_phy_none)
goto out;
if (!hw->phy.reset_if_overtemp &&
(IXGBE_ERR_OVERTEMP == hw->phy.ops.check_overtemp(hw)))
goto out;
hw->phy.ops.write_reg(hw, MDIO_CTRL1,
MDIO_MMD_PHYXS,
MDIO_CTRL1_RESET);
for (i = 0; i < 30; i++) {
msleep(100);
hw->phy.ops.read_reg(hw, MDIO_CTRL1,
MDIO_MMD_PHYXS, &ctrl);
if (!(ctrl & MDIO_CTRL1_RESET)) {
udelay(2);
break;
}
}
if (ctrl & MDIO_CTRL1_RESET) {
status = IXGBE_ERR_RESET_FAILED;
hw_dbg(hw, "PHY reset polling failed to complete.\n");
}
out:
return status;
}
s32 ixgbe_read_phy_reg_mdi(struct ixgbe_hw *hw, u32 reg_addr, u32 device_type,
u16 *phy_data)
{
u32 i, data, command;
command = ((reg_addr << IXGBE_MSCA_NP_ADDR_SHIFT) |
(device_type << IXGBE_MSCA_DEV_TYPE_SHIFT) |
(hw->phy.mdio.prtad << IXGBE_MSCA_PHY_ADDR_SHIFT) |
(IXGBE_MSCA_ADDR_CYCLE | IXGBE_MSCA_MDI_COMMAND));
IXGBE_WRITE_REG(hw, IXGBE_MSCA, command);
for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
udelay(10);
command = IXGBE_READ_REG(hw, IXGBE_MSCA);
if ((command & IXGBE_MSCA_MDI_COMMAND) == 0)
break;
}
if ((command & IXGBE_MSCA_MDI_COMMAND) != 0) {
hw_dbg(hw, "PHY address command did not complete.\n");
return IXGBE_ERR_PHY;
}
command = ((reg_addr << IXGBE_MSCA_NP_ADDR_SHIFT) |
(device_type << IXGBE_MSCA_DEV_TYPE_SHIFT) |
(hw->phy.mdio.prtad << IXGBE_MSCA_PHY_ADDR_SHIFT) |
(IXGBE_MSCA_READ | IXGBE_MSCA_MDI_COMMAND));
IXGBE_WRITE_REG(hw, IXGBE_MSCA, command);
for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
udelay(10);
command = IXGBE_READ_REG(hw, IXGBE_MSCA);
if ((command & IXGBE_MSCA_MDI_COMMAND) == 0)
break;
}
if ((command & IXGBE_MSCA_MDI_COMMAND) != 0) {
hw_dbg(hw, "PHY read command didn't complete\n");
return IXGBE_ERR_PHY;
}
data = IXGBE_READ_REG(hw, IXGBE_MSRWD);
data >>= IXGBE_MSRWD_READ_DATA_SHIFT;
*phy_data = (u16)(data);
return 0;
}
s32 ixgbe_read_phy_reg_generic(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u16 *phy_data)
{
s32 status;
u16 gssr;
if (IXGBE_READ_REG(hw, IXGBE_STATUS) & IXGBE_STATUS_LAN_ID_1)
gssr = IXGBE_GSSR_PHY1_SM;
else
gssr = IXGBE_GSSR_PHY0_SM;
if (hw->mac.ops.acquire_swfw_sync(hw, gssr) == 0) {
status = ixgbe_read_phy_reg_mdi(hw, reg_addr, device_type,
phy_data);
hw->mac.ops.release_swfw_sync(hw, gssr);
} else {
status = IXGBE_ERR_SWFW_SYNC;
}
return status;
}
s32 ixgbe_write_phy_reg_mdi(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u16 phy_data)
{
u32 i, command;
IXGBE_WRITE_REG(hw, IXGBE_MSRWD, (u32)phy_data);
command = ((reg_addr << IXGBE_MSCA_NP_ADDR_SHIFT) |
(device_type << IXGBE_MSCA_DEV_TYPE_SHIFT) |
(hw->phy.mdio.prtad << IXGBE_MSCA_PHY_ADDR_SHIFT) |
(IXGBE_MSCA_ADDR_CYCLE | IXGBE_MSCA_MDI_COMMAND));
IXGBE_WRITE_REG(hw, IXGBE_MSCA, command);
for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
udelay(10);
command = IXGBE_READ_REG(hw, IXGBE_MSCA);
if ((command & IXGBE_MSCA_MDI_COMMAND) == 0)
break;
}
if ((command & IXGBE_MSCA_MDI_COMMAND) != 0) {
hw_dbg(hw, "PHY address cmd didn't complete\n");
return IXGBE_ERR_PHY;
}
command = ((reg_addr << IXGBE_MSCA_NP_ADDR_SHIFT) |
(device_type << IXGBE_MSCA_DEV_TYPE_SHIFT) |
(hw->phy.mdio.prtad << IXGBE_MSCA_PHY_ADDR_SHIFT) |
(IXGBE_MSCA_WRITE | IXGBE_MSCA_MDI_COMMAND));
IXGBE_WRITE_REG(hw, IXGBE_MSCA, command);
for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
udelay(10);
command = IXGBE_READ_REG(hw, IXGBE_MSCA);
if ((command & IXGBE_MSCA_MDI_COMMAND) == 0)
break;
}
if ((command & IXGBE_MSCA_MDI_COMMAND) != 0) {
hw_dbg(hw, "PHY write cmd didn't complete\n");
return IXGBE_ERR_PHY;
}
return 0;
}
s32 ixgbe_write_phy_reg_generic(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u16 phy_data)
{
s32 status;
u16 gssr;
if (IXGBE_READ_REG(hw, IXGBE_STATUS) & IXGBE_STATUS_LAN_ID_1)
gssr = IXGBE_GSSR_PHY1_SM;
else
gssr = IXGBE_GSSR_PHY0_SM;
if (hw->mac.ops.acquire_swfw_sync(hw, gssr) == 0) {
status = ixgbe_write_phy_reg_mdi(hw, reg_addr, device_type,
phy_data);
hw->mac.ops.release_swfw_sync(hw, gssr);
} else {
status = IXGBE_ERR_SWFW_SYNC;
}
return status;
}
s32 ixgbe_setup_phy_link_generic(struct ixgbe_hw *hw)
{
s32 status = 0;
u32 time_out;
u32 max_time_out = 10;
u16 autoneg_reg = IXGBE_MII_AUTONEG_REG;
bool autoneg = false;
ixgbe_link_speed speed;
ixgbe_get_copper_link_capabilities_generic(hw, &speed, &autoneg);
if (speed & IXGBE_LINK_SPEED_10GB_FULL) {
hw->phy.ops.read_reg(hw, MDIO_AN_10GBT_CTRL,
MDIO_MMD_AN,
&autoneg_reg);
autoneg_reg &= ~MDIO_AN_10GBT_CTRL_ADV10G;
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_10GB_FULL)
autoneg_reg |= MDIO_AN_10GBT_CTRL_ADV10G;
hw->phy.ops.write_reg(hw, MDIO_AN_10GBT_CTRL,
MDIO_MMD_AN,
autoneg_reg);
}
if (speed & IXGBE_LINK_SPEED_1GB_FULL) {
hw->phy.ops.read_reg(hw,
IXGBE_MII_AUTONEG_VENDOR_PROVISION_1_REG,
MDIO_MMD_AN,
&autoneg_reg);
autoneg_reg &= ~IXGBE_MII_1GBASE_T_ADVERTISE;
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_1GB_FULL)
autoneg_reg |= IXGBE_MII_1GBASE_T_ADVERTISE;
hw->phy.ops.write_reg(hw,
IXGBE_MII_AUTONEG_VENDOR_PROVISION_1_REG,
MDIO_MMD_AN,
autoneg_reg);
}
if (speed & IXGBE_LINK_SPEED_100_FULL) {
hw->phy.ops.read_reg(hw, MDIO_AN_ADVERTISE,
MDIO_MMD_AN,
&autoneg_reg);
autoneg_reg &= ~(ADVERTISE_100FULL |
ADVERTISE_100HALF);
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_100_FULL)
autoneg_reg |= ADVERTISE_100FULL;
hw->phy.ops.write_reg(hw, MDIO_AN_ADVERTISE,
MDIO_MMD_AN,
autoneg_reg);
}
hw->phy.ops.read_reg(hw, MDIO_CTRL1,
MDIO_MMD_AN, &autoneg_reg);
autoneg_reg |= MDIO_AN_CTRL1_RESTART;
hw->phy.ops.write_reg(hw, MDIO_CTRL1,
MDIO_MMD_AN, autoneg_reg);
for (time_out = 0; time_out < max_time_out; time_out++) {
udelay(10);
status = hw->phy.ops.read_reg(hw, MDIO_STAT1,
MDIO_MMD_AN,
&autoneg_reg);
autoneg_reg &= MDIO_AN_STAT1_COMPLETE;
if (autoneg_reg == MDIO_AN_STAT1_COMPLETE) {
break;
}
}
if (time_out == max_time_out) {
status = IXGBE_ERR_LINK_SETUP;
hw_dbg(hw, "ixgbe_setup_phy_link_generic: time out");
}
return status;
}
s32 ixgbe_setup_phy_link_speed_generic(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
bool autoneg_wait_to_complete)
{
hw->phy.autoneg_advertised = 0;
if (speed & IXGBE_LINK_SPEED_10GB_FULL)
hw->phy.autoneg_advertised |= IXGBE_LINK_SPEED_10GB_FULL;
if (speed & IXGBE_LINK_SPEED_1GB_FULL)
hw->phy.autoneg_advertised |= IXGBE_LINK_SPEED_1GB_FULL;
if (speed & IXGBE_LINK_SPEED_100_FULL)
hw->phy.autoneg_advertised |= IXGBE_LINK_SPEED_100_FULL;
hw->phy.ops.setup_link(hw);
return 0;
}
s32 ixgbe_get_copper_link_capabilities_generic(struct ixgbe_hw *hw,
ixgbe_link_speed *speed,
bool *autoneg)
{
s32 status = IXGBE_ERR_LINK_SETUP;
u16 speed_ability;
*speed = 0;
*autoneg = true;
status = hw->phy.ops.read_reg(hw, MDIO_SPEED, MDIO_MMD_PMAPMD,
&speed_ability);
if (status == 0) {
if (speed_ability & MDIO_SPEED_10G)
*speed |= IXGBE_LINK_SPEED_10GB_FULL;
if (speed_ability & MDIO_PMA_SPEED_1000)
*speed |= IXGBE_LINK_SPEED_1GB_FULL;
if (speed_ability & MDIO_PMA_SPEED_100)
*speed |= IXGBE_LINK_SPEED_100_FULL;
}
return status;
}
s32 ixgbe_check_phy_link_tnx(struct ixgbe_hw *hw, ixgbe_link_speed *speed,
bool *link_up)
{
s32 status = 0;
u32 time_out;
u32 max_time_out = 10;
u16 phy_link = 0;
u16 phy_speed = 0;
u16 phy_data = 0;
*link_up = false;
*speed = IXGBE_LINK_SPEED_10GB_FULL;
for (time_out = 0; time_out < max_time_out; time_out++) {
udelay(10);
status = hw->phy.ops.read_reg(hw,
MDIO_STAT1,
MDIO_MMD_VEND1,
&phy_data);
phy_link = phy_data &
IXGBE_MDIO_VENDOR_SPECIFIC_1_LINK_STATUS;
phy_speed = phy_data &
IXGBE_MDIO_VENDOR_SPECIFIC_1_SPEED_STATUS;
if (phy_link == IXGBE_MDIO_VENDOR_SPECIFIC_1_LINK_STATUS) {
*link_up = true;
if (phy_speed ==
IXGBE_MDIO_VENDOR_SPECIFIC_1_SPEED_STATUS)
*speed = IXGBE_LINK_SPEED_1GB_FULL;
break;
}
}
return status;
}
s32 ixgbe_setup_phy_link_tnx(struct ixgbe_hw *hw)
{
s32 status = 0;
u32 time_out;
u32 max_time_out = 10;
u16 autoneg_reg = IXGBE_MII_AUTONEG_REG;
bool autoneg = false;
ixgbe_link_speed speed;
ixgbe_get_copper_link_capabilities_generic(hw, &speed, &autoneg);
if (speed & IXGBE_LINK_SPEED_10GB_FULL) {
hw->phy.ops.read_reg(hw, MDIO_AN_10GBT_CTRL,
MDIO_MMD_AN,
&autoneg_reg);
autoneg_reg &= ~MDIO_AN_10GBT_CTRL_ADV10G;
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_10GB_FULL)
autoneg_reg |= MDIO_AN_10GBT_CTRL_ADV10G;
hw->phy.ops.write_reg(hw, MDIO_AN_10GBT_CTRL,
MDIO_MMD_AN,
autoneg_reg);
}
if (speed & IXGBE_LINK_SPEED_1GB_FULL) {
hw->phy.ops.read_reg(hw, IXGBE_MII_AUTONEG_XNP_TX_REG,
MDIO_MMD_AN,
&autoneg_reg);
autoneg_reg &= ~IXGBE_MII_1GBASE_T_ADVERTISE_XNP_TX;
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_1GB_FULL)
autoneg_reg |= IXGBE_MII_1GBASE_T_ADVERTISE_XNP_TX;
hw->phy.ops.write_reg(hw, IXGBE_MII_AUTONEG_XNP_TX_REG,
MDIO_MMD_AN,
autoneg_reg);
}
if (speed & IXGBE_LINK_SPEED_100_FULL) {
hw->phy.ops.read_reg(hw, MDIO_AN_ADVERTISE,
MDIO_MMD_AN,
&autoneg_reg);
autoneg_reg &= ~(ADVERTISE_100FULL |
ADVERTISE_100HALF);
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_100_FULL)
autoneg_reg |= ADVERTISE_100FULL;
hw->phy.ops.write_reg(hw, MDIO_AN_ADVERTISE,
MDIO_MMD_AN,
autoneg_reg);
}
hw->phy.ops.read_reg(hw, MDIO_CTRL1,
MDIO_MMD_AN, &autoneg_reg);
autoneg_reg |= MDIO_AN_CTRL1_RESTART;
hw->phy.ops.write_reg(hw, MDIO_CTRL1,
MDIO_MMD_AN, autoneg_reg);
for (time_out = 0; time_out < max_time_out; time_out++) {
udelay(10);
status = hw->phy.ops.read_reg(hw, MDIO_STAT1,
MDIO_MMD_AN,
&autoneg_reg);
autoneg_reg &= MDIO_AN_STAT1_COMPLETE;
if (autoneg_reg == MDIO_AN_STAT1_COMPLETE)
break;
}
if (time_out == max_time_out) {
status = IXGBE_ERR_LINK_SETUP;
hw_dbg(hw, "ixgbe_setup_phy_link_tnx: time out");
}
return status;
}
s32 ixgbe_get_phy_firmware_version_tnx(struct ixgbe_hw *hw,
u16 *firmware_version)
{
s32 status = 0;
status = hw->phy.ops.read_reg(hw, TNX_FW_REV,
MDIO_MMD_VEND1,
firmware_version);
return status;
}
s32 ixgbe_get_phy_firmware_version_generic(struct ixgbe_hw *hw,
u16 *firmware_version)
{
s32 status = 0;
status = hw->phy.ops.read_reg(hw, AQ_FW_REV,
MDIO_MMD_VEND1,
firmware_version);
return status;
}
s32 ixgbe_reset_phy_nl(struct ixgbe_hw *hw)
{
u16 phy_offset, control, eword, edata, block_crc;
bool end_data = false;
u16 list_offset, data_offset;
u16 phy_data = 0;
s32 ret_val = 0;
u32 i;
hw->phy.ops.read_reg(hw, MDIO_CTRL1, MDIO_MMD_PHYXS, &phy_data);
hw->phy.ops.write_reg(hw, MDIO_CTRL1, MDIO_MMD_PHYXS,
(phy_data | MDIO_CTRL1_RESET));
for (i = 0; i < 100; i++) {
hw->phy.ops.read_reg(hw, MDIO_CTRL1, MDIO_MMD_PHYXS,
&phy_data);
if ((phy_data & MDIO_CTRL1_RESET) == 0)
break;
usleep_range(10000, 20000);
}
if ((phy_data & MDIO_CTRL1_RESET) != 0) {
hw_dbg(hw, "PHY reset did not complete.\n");
ret_val = IXGBE_ERR_PHY;
goto out;
}
ret_val = ixgbe_get_sfp_init_sequence_offsets(hw, &list_offset,
&data_offset);
if (ret_val != 0)
goto out;
ret_val = hw->eeprom.ops.read(hw, data_offset, &block_crc);
data_offset++;
while (!end_data) {
ret_val = hw->eeprom.ops.read(hw, data_offset, &eword);
if (ret_val)
goto err_eeprom;
control = (eword & IXGBE_CONTROL_MASK_NL) >>
IXGBE_CONTROL_SHIFT_NL;
edata = eword & IXGBE_DATA_MASK_NL;
switch (control) {
case IXGBE_DELAY_NL:
data_offset++;
hw_dbg(hw, "DELAY: %d MS\n", edata);
usleep_range(edata * 1000, edata * 2000);
break;
case IXGBE_DATA_NL:
hw_dbg(hw, "DATA:\n");
data_offset++;
ret_val = hw->eeprom.ops.read(hw, data_offset++,
&phy_offset);
if (ret_val)
goto err_eeprom;
for (i = 0; i < edata; i++) {
ret_val = hw->eeprom.ops.read(hw, data_offset,
&eword);
if (ret_val)
goto err_eeprom;
hw->phy.ops.write_reg(hw, phy_offset,
MDIO_MMD_PMAPMD, eword);
hw_dbg(hw, "Wrote %4.4x to %4.4x\n", eword,
phy_offset);
data_offset++;
phy_offset++;
}
break;
case IXGBE_CONTROL_NL:
data_offset++;
hw_dbg(hw, "CONTROL:\n");
if (edata == IXGBE_CONTROL_EOL_NL) {
hw_dbg(hw, "EOL\n");
end_data = true;
} else if (edata == IXGBE_CONTROL_SOL_NL) {
hw_dbg(hw, "SOL\n");
} else {
hw_dbg(hw, "Bad control value\n");
ret_val = IXGBE_ERR_PHY;
goto out;
}
break;
default:
hw_dbg(hw, "Bad control type\n");
ret_val = IXGBE_ERR_PHY;
goto out;
}
}
out:
return ret_val;
err_eeprom:
hw_err(hw, "eeprom read at offset %d failed\n", data_offset);
return IXGBE_ERR_PHY;
}
s32 ixgbe_identify_module_generic(struct ixgbe_hw *hw)
{
s32 status = IXGBE_ERR_SFP_NOT_PRESENT;
switch (hw->mac.ops.get_media_type(hw)) {
case ixgbe_media_type_fiber:
status = ixgbe_identify_sfp_module_generic(hw);
break;
case ixgbe_media_type_fiber_qsfp:
status = ixgbe_identify_qsfp_module_generic(hw);
break;
default:
hw->phy.sfp_type = ixgbe_sfp_type_not_present;
status = IXGBE_ERR_SFP_NOT_PRESENT;
break;
}
return status;
}
s32 ixgbe_identify_sfp_module_generic(struct ixgbe_hw *hw)
{
struct ixgbe_adapter *adapter = hw->back;
s32 status = IXGBE_ERR_PHY_ADDR_INVALID;
u32 vendor_oui = 0;
enum ixgbe_sfp_type stored_sfp_type = hw->phy.sfp_type;
u8 identifier = 0;
u8 comp_codes_1g = 0;
u8 comp_codes_10g = 0;
u8 oui_bytes[3] = {0, 0, 0};
u8 cable_tech = 0;
u8 cable_spec = 0;
u16 enforce_sfp = 0;
if (hw->mac.ops.get_media_type(hw) != ixgbe_media_type_fiber) {
hw->phy.sfp_type = ixgbe_sfp_type_not_present;
status = IXGBE_ERR_SFP_NOT_PRESENT;
goto out;
}
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_IDENTIFIER,
&identifier);
if (status != 0)
goto err_read_i2c_eeprom;
hw->mac.ops.set_lan_id(hw);
if (identifier != IXGBE_SFF_IDENTIFIER_SFP) {
hw->phy.type = ixgbe_phy_sfp_unsupported;
status = IXGBE_ERR_SFP_NOT_SUPPORTED;
} else {
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_1GBE_COMP_CODES,
&comp_codes_1g);
if (status != 0)
goto err_read_i2c_eeprom;
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_10GBE_COMP_CODES,
&comp_codes_10g);
if (status != 0)
goto err_read_i2c_eeprom;
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_CABLE_TECHNOLOGY,
&cable_tech);
if (status != 0)
goto err_read_i2c_eeprom;
if (hw->mac.type == ixgbe_mac_82598EB) {
if (cable_tech & IXGBE_SFF_DA_PASSIVE_CABLE)
hw->phy.sfp_type = ixgbe_sfp_type_da_cu;
else if (comp_codes_10g & IXGBE_SFF_10GBASESR_CAPABLE)
hw->phy.sfp_type = ixgbe_sfp_type_sr;
else if (comp_codes_10g & IXGBE_SFF_10GBASELR_CAPABLE)
hw->phy.sfp_type = ixgbe_sfp_type_lr;
else
hw->phy.sfp_type = ixgbe_sfp_type_unknown;
} else if (hw->mac.type == ixgbe_mac_82599EB) {
if (cable_tech & IXGBE_SFF_DA_PASSIVE_CABLE) {
if (hw->bus.lan_id == 0)
hw->phy.sfp_type =
ixgbe_sfp_type_da_cu_core0;
else
hw->phy.sfp_type =
ixgbe_sfp_type_da_cu_core1;
} else if (cable_tech & IXGBE_SFF_DA_ACTIVE_CABLE) {
hw->phy.ops.read_i2c_eeprom(
hw, IXGBE_SFF_CABLE_SPEC_COMP,
&cable_spec);
if (cable_spec &
IXGBE_SFF_DA_SPEC_ACTIVE_LIMITING) {
if (hw->bus.lan_id == 0)
hw->phy.sfp_type =
ixgbe_sfp_type_da_act_lmt_core0;
else
hw->phy.sfp_type =
ixgbe_sfp_type_da_act_lmt_core1;
} else {
hw->phy.sfp_type =
ixgbe_sfp_type_unknown;
}
} else if (comp_codes_10g &
(IXGBE_SFF_10GBASESR_CAPABLE |
IXGBE_SFF_10GBASELR_CAPABLE)) {
if (hw->bus.lan_id == 0)
hw->phy.sfp_type =
ixgbe_sfp_type_srlr_core0;
else
hw->phy.sfp_type =
ixgbe_sfp_type_srlr_core1;
} else if (comp_codes_1g & IXGBE_SFF_1GBASET_CAPABLE) {
if (hw->bus.lan_id == 0)
hw->phy.sfp_type =
ixgbe_sfp_type_1g_cu_core0;
else
hw->phy.sfp_type =
ixgbe_sfp_type_1g_cu_core1;
} else if (comp_codes_1g & IXGBE_SFF_1GBASESX_CAPABLE) {
if (hw->bus.lan_id == 0)
hw->phy.sfp_type =
ixgbe_sfp_type_1g_sx_core0;
else
hw->phy.sfp_type =
ixgbe_sfp_type_1g_sx_core1;
} else if (comp_codes_1g & IXGBE_SFF_1GBASELX_CAPABLE) {
if (hw->bus.lan_id == 0)
hw->phy.sfp_type =
ixgbe_sfp_type_1g_lx_core0;
else
hw->phy.sfp_type =
ixgbe_sfp_type_1g_lx_core1;
} else {
hw->phy.sfp_type = ixgbe_sfp_type_unknown;
}
}
if (hw->phy.sfp_type != stored_sfp_type)
hw->phy.sfp_setup_needed = true;
hw->phy.multispeed_fiber = false;
if (((comp_codes_1g & IXGBE_SFF_1GBASESX_CAPABLE) &&
(comp_codes_10g & IXGBE_SFF_10GBASESR_CAPABLE)) ||
((comp_codes_1g & IXGBE_SFF_1GBASELX_CAPABLE) &&
(comp_codes_10g & IXGBE_SFF_10GBASELR_CAPABLE)))
hw->phy.multispeed_fiber = true;
if (hw->phy.type != ixgbe_phy_nl) {
hw->phy.id = identifier;
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_VENDOR_OUI_BYTE0,
&oui_bytes[0]);
if (status != 0)
goto err_read_i2c_eeprom;
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_VENDOR_OUI_BYTE1,
&oui_bytes[1]);
if (status != 0)
goto err_read_i2c_eeprom;
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_VENDOR_OUI_BYTE2,
&oui_bytes[2]);
if (status != 0)
goto err_read_i2c_eeprom;
vendor_oui =
((oui_bytes[0] << IXGBE_SFF_VENDOR_OUI_BYTE0_SHIFT) |
(oui_bytes[1] << IXGBE_SFF_VENDOR_OUI_BYTE1_SHIFT) |
(oui_bytes[2] << IXGBE_SFF_VENDOR_OUI_BYTE2_SHIFT));
switch (vendor_oui) {
case IXGBE_SFF_VENDOR_OUI_TYCO:
if (cable_tech & IXGBE_SFF_DA_PASSIVE_CABLE)
hw->phy.type =
ixgbe_phy_sfp_passive_tyco;
break;
case IXGBE_SFF_VENDOR_OUI_FTL:
if (cable_tech & IXGBE_SFF_DA_ACTIVE_CABLE)
hw->phy.type = ixgbe_phy_sfp_ftl_active;
else
hw->phy.type = ixgbe_phy_sfp_ftl;
break;
case IXGBE_SFF_VENDOR_OUI_AVAGO:
hw->phy.type = ixgbe_phy_sfp_avago;
break;
case IXGBE_SFF_VENDOR_OUI_INTEL:
hw->phy.type = ixgbe_phy_sfp_intel;
break;
default:
if (cable_tech & IXGBE_SFF_DA_PASSIVE_CABLE)
hw->phy.type =
ixgbe_phy_sfp_passive_unknown;
else if (cable_tech & IXGBE_SFF_DA_ACTIVE_CABLE)
hw->phy.type =
ixgbe_phy_sfp_active_unknown;
else
hw->phy.type = ixgbe_phy_sfp_unknown;
break;
}
}
if (cable_tech & (IXGBE_SFF_DA_PASSIVE_CABLE |
IXGBE_SFF_DA_ACTIVE_CABLE)) {
status = 0;
goto out;
}
if (comp_codes_10g == 0 &&
!(hw->phy.sfp_type == ixgbe_sfp_type_1g_cu_core1 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_cu_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_lx_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_lx_core1 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_sx_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_sx_core1)) {
hw->phy.type = ixgbe_phy_sfp_unsupported;
status = IXGBE_ERR_SFP_NOT_SUPPORTED;
goto out;
}
if (hw->mac.type == ixgbe_mac_82598EB) {
status = 0;
goto out;
}
hw->mac.ops.get_device_caps(hw, &enforce_sfp);
if (!(enforce_sfp & IXGBE_DEVICE_CAPS_ALLOW_ANY_SFP) &&
!(hw->phy.sfp_type == ixgbe_sfp_type_1g_cu_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_cu_core1 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_lx_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_lx_core1 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_sx_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_sx_core1)) {
if (hw->phy.type == ixgbe_phy_sfp_intel) {
status = 0;
} else {
if (hw->allow_unsupported_sfp) {
e_warn(drv, "WARNING: Intel (R) Network Connections are quality tested using Intel (R) Ethernet Optics. Using untested modules is not supported and may cause unstable operation or damage to the module or the adapter. Intel Corporation is not responsible for any harm caused by using untested modules.");
status = 0;
} else {
hw_dbg(hw,
"SFP+ module not supported\n");
hw->phy.type =
ixgbe_phy_sfp_unsupported;
status = IXGBE_ERR_SFP_NOT_SUPPORTED;
}
}
} else {
status = 0;
}
}
out:
return status;
err_read_i2c_eeprom:
hw->phy.sfp_type = ixgbe_sfp_type_not_present;
if (hw->phy.type != ixgbe_phy_nl) {
hw->phy.id = 0;
hw->phy.type = ixgbe_phy_unknown;
}
return IXGBE_ERR_SFP_NOT_PRESENT;
}
static s32 ixgbe_identify_qsfp_module_generic(struct ixgbe_hw *hw)
{
struct ixgbe_adapter *adapter = hw->back;
s32 status = IXGBE_ERR_PHY_ADDR_INVALID;
u32 vendor_oui = 0;
enum ixgbe_sfp_type stored_sfp_type = hw->phy.sfp_type;
u8 identifier = 0;
u8 comp_codes_1g = 0;
u8 comp_codes_10g = 0;
u8 oui_bytes[3] = {0, 0, 0};
u16 enforce_sfp = 0;
u8 connector = 0;
u8 cable_length = 0;
u8 device_tech = 0;
bool active_cable = false;
if (hw->mac.ops.get_media_type(hw) != ixgbe_media_type_fiber_qsfp) {
hw->phy.sfp_type = ixgbe_sfp_type_not_present;
status = IXGBE_ERR_SFP_NOT_PRESENT;
goto out;
}
status = hw->phy.ops.read_i2c_eeprom(hw, IXGBE_SFF_IDENTIFIER,
&identifier);
if (status != 0)
goto err_read_i2c_eeprom;
if (identifier != IXGBE_SFF_IDENTIFIER_QSFP_PLUS) {
hw->phy.type = ixgbe_phy_sfp_unsupported;
status = IXGBE_ERR_SFP_NOT_SUPPORTED;
goto out;
}
hw->phy.id = identifier;
hw->mac.ops.set_lan_id(hw);
status = hw->phy.ops.read_i2c_eeprom(hw, IXGBE_SFF_QSFP_10GBE_COMP,
&comp_codes_10g);
if (status != 0)
goto err_read_i2c_eeprom;
status = hw->phy.ops.read_i2c_eeprom(hw, IXGBE_SFF_QSFP_1GBE_COMP,
&comp_codes_1g);
if (status != 0)
goto err_read_i2c_eeprom;
if (comp_codes_10g & IXGBE_SFF_QSFP_DA_PASSIVE_CABLE) {
hw->phy.type = ixgbe_phy_qsfp_passive_unknown;
if (hw->bus.lan_id == 0)
hw->phy.sfp_type = ixgbe_sfp_type_da_cu_core0;
else
hw->phy.sfp_type = ixgbe_sfp_type_da_cu_core1;
} else if (comp_codes_10g & (IXGBE_SFF_10GBASESR_CAPABLE |
IXGBE_SFF_10GBASELR_CAPABLE)) {
if (hw->bus.lan_id == 0)
hw->phy.sfp_type = ixgbe_sfp_type_srlr_core0;
else
hw->phy.sfp_type = ixgbe_sfp_type_srlr_core1;
} else {
if (comp_codes_10g & IXGBE_SFF_QSFP_DA_ACTIVE_CABLE)
active_cable = true;
if (!active_cable) {
hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_QSFP_CONNECTOR,
&connector);
hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_QSFP_CABLE_LENGTH,
&cable_length);
hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_QSFP_DEVICE_TECH,
&device_tech);
if ((connector ==
IXGBE_SFF_QSFP_CONNECTOR_NOT_SEPARABLE) &&
(cable_length > 0) &&
((device_tech >> 4) ==
IXGBE_SFF_QSFP_TRANSMITER_850NM_VCSEL))
active_cable = true;
}
if (active_cable) {
hw->phy.type = ixgbe_phy_qsfp_active_unknown;
if (hw->bus.lan_id == 0)
hw->phy.sfp_type =
ixgbe_sfp_type_da_act_lmt_core0;
else
hw->phy.sfp_type =
ixgbe_sfp_type_da_act_lmt_core1;
} else {
hw->phy.type = ixgbe_phy_sfp_unsupported;
status = IXGBE_ERR_SFP_NOT_SUPPORTED;
goto out;
}
}
if (hw->phy.sfp_type != stored_sfp_type)
hw->phy.sfp_setup_needed = true;
hw->phy.multispeed_fiber = false;
if (((comp_codes_1g & IXGBE_SFF_1GBASESX_CAPABLE) &&
(comp_codes_10g & IXGBE_SFF_10GBASESR_CAPABLE)) ||
((comp_codes_1g & IXGBE_SFF_1GBASELX_CAPABLE) &&
(comp_codes_10g & IXGBE_SFF_10GBASELR_CAPABLE)))
hw->phy.multispeed_fiber = true;
if (comp_codes_10g & (IXGBE_SFF_10GBASESR_CAPABLE |
IXGBE_SFF_10GBASELR_CAPABLE)) {
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_QSFP_VENDOR_OUI_BYTE0,
&oui_bytes[0]);
if (status != 0)
goto err_read_i2c_eeprom;
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_QSFP_VENDOR_OUI_BYTE1,
&oui_bytes[1]);
if (status != 0)
goto err_read_i2c_eeprom;
status = hw->phy.ops.read_i2c_eeprom(hw,
IXGBE_SFF_QSFP_VENDOR_OUI_BYTE2,
&oui_bytes[2]);
if (status != 0)
goto err_read_i2c_eeprom;
vendor_oui =
((oui_bytes[0] << IXGBE_SFF_VENDOR_OUI_BYTE0_SHIFT) |
(oui_bytes[1] << IXGBE_SFF_VENDOR_OUI_BYTE1_SHIFT) |
(oui_bytes[2] << IXGBE_SFF_VENDOR_OUI_BYTE2_SHIFT));
if (vendor_oui == IXGBE_SFF_VENDOR_OUI_INTEL)
hw->phy.type = ixgbe_phy_qsfp_intel;
else
hw->phy.type = ixgbe_phy_qsfp_unknown;
hw->mac.ops.get_device_caps(hw, &enforce_sfp);
if (!(enforce_sfp & IXGBE_DEVICE_CAPS_ALLOW_ANY_SFP)) {
if (hw->phy.type == ixgbe_phy_qsfp_intel) {
status = 0;
} else {
if (hw->allow_unsupported_sfp == true) {
e_warn(drv, "WARNING: Intel (R) Network Connections are quality tested using Intel (R) Ethernet Optics. Using untested modules is not supported and may cause unstable operation or damage to the module or the adapter. Intel Corporation is not responsible for any harm caused by using untested modules.\n");
status = 0;
} else {
hw_dbg(hw,
"QSFP module not supported\n");
hw->phy.type =
ixgbe_phy_sfp_unsupported;
status = IXGBE_ERR_SFP_NOT_SUPPORTED;
}
}
} else {
status = 0;
}
}
out:
return status;
err_read_i2c_eeprom:
hw->phy.sfp_type = ixgbe_sfp_type_not_present;
hw->phy.id = 0;
hw->phy.type = ixgbe_phy_unknown;
return IXGBE_ERR_SFP_NOT_PRESENT;
}
s32 ixgbe_get_sfp_init_sequence_offsets(struct ixgbe_hw *hw,
u16 *list_offset,
u16 *data_offset)
{
u16 sfp_id;
u16 sfp_type = hw->phy.sfp_type;
if (hw->phy.sfp_type == ixgbe_sfp_type_unknown)
return IXGBE_ERR_SFP_NOT_SUPPORTED;
if (hw->phy.sfp_type == ixgbe_sfp_type_not_present)
return IXGBE_ERR_SFP_NOT_PRESENT;
if ((hw->device_id == IXGBE_DEV_ID_82598_SR_DUAL_PORT_EM) &&
(hw->phy.sfp_type == ixgbe_sfp_type_da_cu))
return IXGBE_ERR_SFP_NOT_SUPPORTED;
if (sfp_type == ixgbe_sfp_type_da_act_lmt_core0 ||
sfp_type == ixgbe_sfp_type_1g_lx_core0 ||
sfp_type == ixgbe_sfp_type_1g_cu_core0 ||
sfp_type == ixgbe_sfp_type_1g_sx_core0)
sfp_type = ixgbe_sfp_type_srlr_core0;
else if (sfp_type == ixgbe_sfp_type_da_act_lmt_core1 ||
sfp_type == ixgbe_sfp_type_1g_lx_core1 ||
sfp_type == ixgbe_sfp_type_1g_cu_core1 ||
sfp_type == ixgbe_sfp_type_1g_sx_core1)
sfp_type = ixgbe_sfp_type_srlr_core1;
if (hw->eeprom.ops.read(hw, IXGBE_PHY_INIT_OFFSET_NL, list_offset)) {
hw_err(hw, "eeprom read at %d failed\n",
IXGBE_PHY_INIT_OFFSET_NL);
return IXGBE_ERR_SFP_NO_INIT_SEQ_PRESENT;
}
if ((!*list_offset) || (*list_offset == 0xFFFF))
return IXGBE_ERR_SFP_NO_INIT_SEQ_PRESENT;
(*list_offset)++;
if (hw->eeprom.ops.read(hw, *list_offset, &sfp_id))
goto err_phy;
while (sfp_id != IXGBE_PHY_INIT_END_NL) {
if (sfp_id == sfp_type) {
(*list_offset)++;
if (hw->eeprom.ops.read(hw, *list_offset, data_offset))
goto err_phy;
if ((!*data_offset) || (*data_offset == 0xFFFF)) {
hw_dbg(hw, "SFP+ module not supported\n");
return IXGBE_ERR_SFP_NOT_SUPPORTED;
} else {
break;
}
} else {
(*list_offset) += 2;
if (hw->eeprom.ops.read(hw, *list_offset, &sfp_id))
goto err_phy;
}
}
if (sfp_id == IXGBE_PHY_INIT_END_NL) {
hw_dbg(hw, "No matching SFP+ module found\n");
return IXGBE_ERR_SFP_NOT_SUPPORTED;
}
return 0;
err_phy:
hw_err(hw, "eeprom read at offset %d failed\n", *list_offset);
return IXGBE_ERR_PHY;
}
s32 ixgbe_read_i2c_eeprom_generic(struct ixgbe_hw *hw, u8 byte_offset,
u8 *eeprom_data)
{
return hw->phy.ops.read_i2c_byte(hw, byte_offset,
IXGBE_I2C_EEPROM_DEV_ADDR,
eeprom_data);
}
s32 ixgbe_read_i2c_sff8472_generic(struct ixgbe_hw *hw, u8 byte_offset,
u8 *sff8472_data)
{
return hw->phy.ops.read_i2c_byte(hw, byte_offset,
IXGBE_I2C_EEPROM_DEV_ADDR2,
sff8472_data);
}
s32 ixgbe_write_i2c_eeprom_generic(struct ixgbe_hw *hw, u8 byte_offset,
u8 eeprom_data)
{
return hw->phy.ops.write_i2c_byte(hw, byte_offset,
IXGBE_I2C_EEPROM_DEV_ADDR,
eeprom_data);
}
s32 ixgbe_read_i2c_byte_generic(struct ixgbe_hw *hw, u8 byte_offset,
u8 dev_addr, u8 *data)
{
s32 status = 0;
u32 max_retry = 10;
u32 retry = 0;
u16 swfw_mask = 0;
bool nack = true;
*data = 0;
if (IXGBE_READ_REG(hw, IXGBE_STATUS) & IXGBE_STATUS_LAN_ID_1)
swfw_mask = IXGBE_GSSR_PHY1_SM;
else
swfw_mask = IXGBE_GSSR_PHY0_SM;
do {
if (hw->mac.ops.acquire_swfw_sync(hw, swfw_mask) != 0) {
status = IXGBE_ERR_SWFW_SYNC;
goto read_byte_out;
}
ixgbe_i2c_start(hw);
status = ixgbe_clock_out_i2c_byte(hw, dev_addr);
if (status != 0)
goto fail;
status = ixgbe_get_i2c_ack(hw);
if (status != 0)
goto fail;
status = ixgbe_clock_out_i2c_byte(hw, byte_offset);
if (status != 0)
goto fail;
status = ixgbe_get_i2c_ack(hw);
if (status != 0)
goto fail;
ixgbe_i2c_start(hw);
status = ixgbe_clock_out_i2c_byte(hw, (dev_addr | 0x1));
if (status != 0)
goto fail;
status = ixgbe_get_i2c_ack(hw);
if (status != 0)
goto fail;
status = ixgbe_clock_in_i2c_byte(hw, data);
if (status != 0)
goto fail;
status = ixgbe_clock_out_i2c_bit(hw, nack);
if (status != 0)
goto fail;
ixgbe_i2c_stop(hw);
break;
fail:
ixgbe_i2c_bus_clear(hw);
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
msleep(100);
retry++;
if (retry < max_retry)
hw_dbg(hw, "I2C byte read error - Retrying.\n");
else
hw_dbg(hw, "I2C byte read error.\n");
} while (retry < max_retry);
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
read_byte_out:
return status;
}
s32 ixgbe_write_i2c_byte_generic(struct ixgbe_hw *hw, u8 byte_offset,
u8 dev_addr, u8 data)
{
s32 status = 0;
u32 max_retry = 1;
u32 retry = 0;
u16 swfw_mask = 0;
if (IXGBE_READ_REG(hw, IXGBE_STATUS) & IXGBE_STATUS_LAN_ID_1)
swfw_mask = IXGBE_GSSR_PHY1_SM;
else
swfw_mask = IXGBE_GSSR_PHY0_SM;
if (hw->mac.ops.acquire_swfw_sync(hw, swfw_mask) != 0) {
status = IXGBE_ERR_SWFW_SYNC;
goto write_byte_out;
}
do {
ixgbe_i2c_start(hw);
status = ixgbe_clock_out_i2c_byte(hw, dev_addr);
if (status != 0)
goto fail;
status = ixgbe_get_i2c_ack(hw);
if (status != 0)
goto fail;
status = ixgbe_clock_out_i2c_byte(hw, byte_offset);
if (status != 0)
goto fail;
status = ixgbe_get_i2c_ack(hw);
if (status != 0)
goto fail;
status = ixgbe_clock_out_i2c_byte(hw, data);
if (status != 0)
goto fail;
status = ixgbe_get_i2c_ack(hw);
if (status != 0)
goto fail;
ixgbe_i2c_stop(hw);
break;
fail:
ixgbe_i2c_bus_clear(hw);
retry++;
if (retry < max_retry)
hw_dbg(hw, "I2C byte write error - Retrying.\n");
else
hw_dbg(hw, "I2C byte write error.\n");
} while (retry < max_retry);
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
write_byte_out:
return status;
}
static void ixgbe_i2c_start(struct ixgbe_hw *hw)
{
u32 i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
ixgbe_set_i2c_data(hw, &i2cctl, 1);
ixgbe_raise_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_SU_STA);
ixgbe_set_i2c_data(hw, &i2cctl, 0);
udelay(IXGBE_I2C_T_HD_STA);
ixgbe_lower_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_LOW);
}
static void ixgbe_i2c_stop(struct ixgbe_hw *hw)
{
u32 i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
ixgbe_set_i2c_data(hw, &i2cctl, 0);
ixgbe_raise_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_SU_STO);
ixgbe_set_i2c_data(hw, &i2cctl, 1);
udelay(IXGBE_I2C_T_BUF);
}
static s32 ixgbe_clock_in_i2c_byte(struct ixgbe_hw *hw, u8 *data)
{
s32 i;
bool bit = false;
for (i = 7; i >= 0; i--) {
ixgbe_clock_in_i2c_bit(hw, &bit);
*data |= bit << i;
}
return 0;
}
static s32 ixgbe_clock_out_i2c_byte(struct ixgbe_hw *hw, u8 data)
{
s32 status = 0;
s32 i;
u32 i2cctl;
bool bit = false;
for (i = 7; i >= 0; i--) {
bit = (data >> i) & 0x1;
status = ixgbe_clock_out_i2c_bit(hw, bit);
if (status != 0)
break;
}
i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
i2cctl |= IXGBE_I2C_DATA_OUT;
IXGBE_WRITE_REG(hw, IXGBE_I2CCTL, i2cctl);
IXGBE_WRITE_FLUSH(hw);
return status;
}
static s32 ixgbe_get_i2c_ack(struct ixgbe_hw *hw)
{
s32 status = 0;
u32 i = 0;
u32 i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
u32 timeout = 10;
bool ack = true;
ixgbe_raise_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_HIGH);
for (i = 0; i < timeout; i++) {
i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
ack = ixgbe_get_i2c_data(&i2cctl);
udelay(1);
if (ack == 0)
break;
}
if (ack == 1) {
hw_dbg(hw, "I2C ack was not received.\n");
status = IXGBE_ERR_I2C;
}
ixgbe_lower_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_LOW);
return status;
}
static s32 ixgbe_clock_in_i2c_bit(struct ixgbe_hw *hw, bool *data)
{
u32 i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
ixgbe_raise_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_HIGH);
i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
*data = ixgbe_get_i2c_data(&i2cctl);
ixgbe_lower_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_LOW);
return 0;
}
static s32 ixgbe_clock_out_i2c_bit(struct ixgbe_hw *hw, bool data)
{
s32 status;
u32 i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
status = ixgbe_set_i2c_data(hw, &i2cctl, data);
if (status == 0) {
ixgbe_raise_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_HIGH);
ixgbe_lower_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_LOW);
} else {
status = IXGBE_ERR_I2C;
hw_dbg(hw, "I2C data was not set to %X\n", data);
}
return status;
}
static void ixgbe_raise_i2c_clk(struct ixgbe_hw *hw, u32 *i2cctl)
{
u32 i = 0;
u32 timeout = IXGBE_I2C_CLOCK_STRETCHING_TIMEOUT;
u32 i2cctl_r = 0;
for (i = 0; i < timeout; i++) {
*i2cctl |= IXGBE_I2C_CLK_OUT;
IXGBE_WRITE_REG(hw, IXGBE_I2CCTL, *i2cctl);
IXGBE_WRITE_FLUSH(hw);
udelay(IXGBE_I2C_T_RISE);
i2cctl_r = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
if (i2cctl_r & IXGBE_I2C_CLK_IN)
break;
}
}
static void ixgbe_lower_i2c_clk(struct ixgbe_hw *hw, u32 *i2cctl)
{
*i2cctl &= ~IXGBE_I2C_CLK_OUT;
IXGBE_WRITE_REG(hw, IXGBE_I2CCTL, *i2cctl);
IXGBE_WRITE_FLUSH(hw);
udelay(IXGBE_I2C_T_FALL);
}
static s32 ixgbe_set_i2c_data(struct ixgbe_hw *hw, u32 *i2cctl, bool data)
{
s32 status = 0;
if (data)
*i2cctl |= IXGBE_I2C_DATA_OUT;
else
*i2cctl &= ~IXGBE_I2C_DATA_OUT;
IXGBE_WRITE_REG(hw, IXGBE_I2CCTL, *i2cctl);
IXGBE_WRITE_FLUSH(hw);
udelay(IXGBE_I2C_T_RISE + IXGBE_I2C_T_FALL + IXGBE_I2C_T_SU_DATA);
*i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
if (data != ixgbe_get_i2c_data(i2cctl)) {
status = IXGBE_ERR_I2C;
hw_dbg(hw, "Error - I2C data was not set to %X.\n", data);
}
return status;
}
static bool ixgbe_get_i2c_data(u32 *i2cctl)
{
bool data;
if (*i2cctl & IXGBE_I2C_DATA_IN)
data = true;
else
data = false;
return data;
}
static void ixgbe_i2c_bus_clear(struct ixgbe_hw *hw)
{
u32 i2cctl = IXGBE_READ_REG(hw, IXGBE_I2CCTL);
u32 i;
ixgbe_i2c_start(hw);
ixgbe_set_i2c_data(hw, &i2cctl, 1);
for (i = 0; i < 9; i++) {
ixgbe_raise_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_HIGH);
ixgbe_lower_i2c_clk(hw, &i2cctl);
udelay(IXGBE_I2C_T_LOW);
}
ixgbe_i2c_start(hw);
ixgbe_i2c_stop(hw);
}
s32 ixgbe_tn_check_overtemp(struct ixgbe_hw *hw)
{
s32 status = 0;
u16 phy_data = 0;
if (hw->device_id != IXGBE_DEV_ID_82599_T3_LOM)
goto out;
hw->phy.ops.read_reg(hw, IXGBE_TN_LASI_STATUS_REG,
MDIO_MMD_PMAPMD, &phy_data);
if (!(phy_data & IXGBE_TN_LASI_STATUS_TEMP_ALARM))
goto out;
status = IXGBE_ERR_OVERTEMP;
out:
return status;
}
