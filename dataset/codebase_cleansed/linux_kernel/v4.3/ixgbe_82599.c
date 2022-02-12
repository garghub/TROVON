bool ixgbe_mng_enabled(struct ixgbe_hw *hw)
{
u32 fwsm, manc, factps;
fwsm = IXGBE_READ_REG(hw, IXGBE_FWSM(hw));
if ((fwsm & IXGBE_FWSM_MODE_MASK) != IXGBE_FWSM_FW_MODE_PT)
return false;
manc = IXGBE_READ_REG(hw, IXGBE_MANC);
if (!(manc & IXGBE_MANC_RCV_TCO_EN))
return false;
factps = IXGBE_READ_REG(hw, IXGBE_FACTPS(hw));
if (factps & IXGBE_FACTPS_MNGCG)
return false;
return true;
}
static void ixgbe_init_mac_link_ops_82599(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
if ((mac->ops.get_media_type(hw) == ixgbe_media_type_fiber) &&
!ixgbe_mng_enabled(hw)) {
mac->ops.disable_tx_laser =
&ixgbe_disable_tx_laser_multispeed_fiber;
mac->ops.enable_tx_laser =
&ixgbe_enable_tx_laser_multispeed_fiber;
mac->ops.flap_tx_laser = &ixgbe_flap_tx_laser_multispeed_fiber;
} else {
mac->ops.disable_tx_laser = NULL;
mac->ops.enable_tx_laser = NULL;
mac->ops.flap_tx_laser = NULL;
}
if (hw->phy.multispeed_fiber) {
mac->ops.setup_link = &ixgbe_setup_mac_link_multispeed_fiber;
} else {
if ((mac->ops.get_media_type(hw) ==
ixgbe_media_type_backplane) &&
(hw->phy.smart_speed == ixgbe_smart_speed_auto ||
hw->phy.smart_speed == ixgbe_smart_speed_on) &&
!ixgbe_verify_lesm_fw_enabled_82599(hw))
mac->ops.setup_link = &ixgbe_setup_mac_link_smartspeed;
else
mac->ops.setup_link = &ixgbe_setup_mac_link_82599;
}
}
static s32 ixgbe_setup_sfp_modules_82599(struct ixgbe_hw *hw)
{
s32 ret_val;
u16 list_offset, data_offset, data_value;
if (hw->phy.sfp_type != ixgbe_sfp_type_unknown) {
ixgbe_init_mac_link_ops_82599(hw);
hw->phy.ops.reset = NULL;
ret_val = ixgbe_get_sfp_init_sequence_offsets(hw, &list_offset,
&data_offset);
if (ret_val)
return ret_val;
ret_val = hw->mac.ops.acquire_swfw_sync(hw,
IXGBE_GSSR_MAC_CSR_SM);
if (ret_val)
return IXGBE_ERR_SWFW_SYNC;
if (hw->eeprom.ops.read(hw, ++data_offset, &data_value))
goto setup_sfp_err;
while (data_value != 0xffff) {
IXGBE_WRITE_REG(hw, IXGBE_CORECTL, data_value);
IXGBE_WRITE_FLUSH(hw);
if (hw->eeprom.ops.read(hw, ++data_offset, &data_value))
goto setup_sfp_err;
}
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_MAC_CSR_SM);
usleep_range(hw->eeprom.semaphore_delay * 1000,
hw->eeprom.semaphore_delay * 2000);
ret_val = hw->mac.ops.prot_autoc_write(hw,
hw->mac.orig_autoc | IXGBE_AUTOC_LMS_10G_SERIAL,
false);
if (ret_val) {
hw_dbg(hw, " sfp module setup not complete\n");
return IXGBE_ERR_SFP_SETUP_NOT_COMPLETE;
}
}
return 0;
setup_sfp_err:
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_MAC_CSR_SM);
usleep_range(hw->eeprom.semaphore_delay * 1000,
hw->eeprom.semaphore_delay * 2000);
hw_err(hw, "eeprom read at offset %d failed\n", data_offset);
return IXGBE_ERR_SFP_SETUP_NOT_COMPLETE;
}
static s32 prot_autoc_read_82599(struct ixgbe_hw *hw, bool *locked,
u32 *reg_val)
{
s32 ret_val;
*locked = false;
if (ixgbe_verify_lesm_fw_enabled_82599(hw)) {
ret_val = hw->mac.ops.acquire_swfw_sync(hw,
IXGBE_GSSR_MAC_CSR_SM);
if (ret_val)
return IXGBE_ERR_SWFW_SYNC;
*locked = true;
}
*reg_val = IXGBE_READ_REG(hw, IXGBE_AUTOC);
return 0;
}
static s32 prot_autoc_write_82599(struct ixgbe_hw *hw, u32 autoc, bool locked)
{
s32 ret_val = 0;
if (ixgbe_check_reset_blocked(hw))
goto out;
if (!locked && ixgbe_verify_lesm_fw_enabled_82599(hw)) {
ret_val = hw->mac.ops.acquire_swfw_sync(hw,
IXGBE_GSSR_MAC_CSR_SM);
if (ret_val)
return IXGBE_ERR_SWFW_SYNC;
locked = true;
}
IXGBE_WRITE_REG(hw, IXGBE_AUTOC, autoc);
ret_val = ixgbe_reset_pipeline_82599(hw);
out:
if (locked)
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_MAC_CSR_SM);
return ret_val;
}
static s32 ixgbe_get_invariants_82599(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
ixgbe_init_mac_link_ops_82599(hw);
mac->mcft_size = IXGBE_82599_MC_TBL_SIZE;
mac->vft_size = IXGBE_82599_VFT_TBL_SIZE;
mac->num_rar_entries = IXGBE_82599_RAR_ENTRIES;
mac->rx_pb_size = IXGBE_82599_RX_PB_SIZE;
mac->max_rx_queues = IXGBE_82599_MAX_RX_QUEUES;
mac->max_tx_queues = IXGBE_82599_MAX_TX_QUEUES;
mac->max_msix_vectors = ixgbe_get_pcie_msix_count_generic(hw);
return 0;
}
static s32 ixgbe_init_phy_ops_82599(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
struct ixgbe_phy_info *phy = &hw->phy;
s32 ret_val;
u32 esdp;
if (hw->device_id == IXGBE_DEV_ID_82599_QSFP_SF_QP) {
hw->phy.qsfp_shared_i2c_bus = true;
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
esdp |= IXGBE_ESDP_SDP0_DIR;
esdp &= ~IXGBE_ESDP_SDP1_DIR;
esdp &= ~IXGBE_ESDP_SDP0;
esdp &= ~IXGBE_ESDP_SDP0_NATIVE;
esdp &= ~IXGBE_ESDP_SDP1_NATIVE;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_FLUSH(hw);
phy->ops.read_i2c_byte = &ixgbe_read_i2c_byte_82599;
phy->ops.write_i2c_byte = &ixgbe_write_i2c_byte_82599;
}
ret_val = phy->ops.identify(hw);
ixgbe_init_mac_link_ops_82599(hw);
if (mac->ops.get_media_type(hw) == ixgbe_media_type_copper) {
mac->ops.setup_link = &ixgbe_setup_copper_link_82599;
mac->ops.get_link_capabilities =
&ixgbe_get_copper_link_capabilities_generic;
}
switch (hw->phy.type) {
case ixgbe_phy_tn:
phy->ops.check_link = &ixgbe_check_phy_link_tnx;
phy->ops.setup_link = &ixgbe_setup_phy_link_tnx;
phy->ops.get_firmware_version =
&ixgbe_get_phy_firmware_version_tnx;
break;
default:
break;
}
return ret_val;
}
static s32 ixgbe_get_link_capabilities_82599(struct ixgbe_hw *hw,
ixgbe_link_speed *speed,
bool *autoneg)
{
u32 autoc = 0;
if (hw->phy.sfp_type == ixgbe_sfp_type_1g_cu_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_cu_core1 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_lx_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_lx_core1 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_sx_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_sx_core1) {
*speed = IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = true;
return 0;
}
if (hw->mac.orig_link_settings_stored)
autoc = hw->mac.orig_autoc;
else
autoc = IXGBE_READ_REG(hw, IXGBE_AUTOC);
switch (autoc & IXGBE_AUTOC_LMS_MASK) {
case IXGBE_AUTOC_LMS_1G_LINK_NO_AN:
*speed = IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = false;
break;
case IXGBE_AUTOC_LMS_10G_LINK_NO_AN:
*speed = IXGBE_LINK_SPEED_10GB_FULL;
*autoneg = false;
break;
case IXGBE_AUTOC_LMS_1G_AN:
*speed = IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = true;
break;
case IXGBE_AUTOC_LMS_10G_SERIAL:
*speed = IXGBE_LINK_SPEED_10GB_FULL;
*autoneg = false;
break;
case IXGBE_AUTOC_LMS_KX4_KX_KR:
case IXGBE_AUTOC_LMS_KX4_KX_KR_1G_AN:
*speed = IXGBE_LINK_SPEED_UNKNOWN;
if (autoc & IXGBE_AUTOC_KR_SUPP)
*speed |= IXGBE_LINK_SPEED_10GB_FULL;
if (autoc & IXGBE_AUTOC_KX4_SUPP)
*speed |= IXGBE_LINK_SPEED_10GB_FULL;
if (autoc & IXGBE_AUTOC_KX_SUPP)
*speed |= IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = true;
break;
case IXGBE_AUTOC_LMS_KX4_KX_KR_SGMII:
*speed = IXGBE_LINK_SPEED_100_FULL;
if (autoc & IXGBE_AUTOC_KR_SUPP)
*speed |= IXGBE_LINK_SPEED_10GB_FULL;
if (autoc & IXGBE_AUTOC_KX4_SUPP)
*speed |= IXGBE_LINK_SPEED_10GB_FULL;
if (autoc & IXGBE_AUTOC_KX_SUPP)
*speed |= IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = true;
break;
case IXGBE_AUTOC_LMS_SGMII_1G_100M:
*speed = IXGBE_LINK_SPEED_1GB_FULL | IXGBE_LINK_SPEED_100_FULL;
*autoneg = false;
break;
default:
return IXGBE_ERR_LINK_SETUP;
}
if (hw->phy.multispeed_fiber) {
*speed |= IXGBE_LINK_SPEED_10GB_FULL |
IXGBE_LINK_SPEED_1GB_FULL;
if (hw->phy.media_type == ixgbe_media_type_fiber_qsfp)
*autoneg = false;
else
*autoneg = true;
}
return 0;
}
static enum ixgbe_media_type ixgbe_get_media_type_82599(struct ixgbe_hw *hw)
{
switch (hw->phy.type) {
case ixgbe_phy_cu_unknown:
case ixgbe_phy_tn:
return ixgbe_media_type_copper;
default:
break;
}
switch (hw->device_id) {
case IXGBE_DEV_ID_82599_KX4:
case IXGBE_DEV_ID_82599_KX4_MEZZ:
case IXGBE_DEV_ID_82599_COMBO_BACKPLANE:
case IXGBE_DEV_ID_82599_KR:
case IXGBE_DEV_ID_82599_BACKPLANE_FCOE:
case IXGBE_DEV_ID_82599_XAUI_LOM:
return ixgbe_media_type_backplane;
case IXGBE_DEV_ID_82599_SFP:
case IXGBE_DEV_ID_82599_SFP_FCOE:
case IXGBE_DEV_ID_82599_SFP_EM:
case IXGBE_DEV_ID_82599_SFP_SF2:
case IXGBE_DEV_ID_82599_SFP_SF_QP:
case IXGBE_DEV_ID_82599EN_SFP:
return ixgbe_media_type_fiber;
case IXGBE_DEV_ID_82599_CX4:
return ixgbe_media_type_cx4;
case IXGBE_DEV_ID_82599_T3_LOM:
return ixgbe_media_type_copper;
case IXGBE_DEV_ID_82599_LS:
return ixgbe_media_type_fiber_lco;
case IXGBE_DEV_ID_82599_QSFP_SF_QP:
return ixgbe_media_type_fiber_qsfp;
default:
return ixgbe_media_type_unknown;
}
}
static void ixgbe_stop_mac_link_on_d3_82599(struct ixgbe_hw *hw)
{
u32 autoc2_reg;
u16 ee_ctrl_2 = 0;
hw->eeprom.ops.read(hw, IXGBE_EEPROM_CTRL_2, &ee_ctrl_2);
if (!ixgbe_mng_present(hw) && !hw->wol_enabled &&
ee_ctrl_2 & IXGBE_EEPROM_CCD_BIT) {
autoc2_reg = IXGBE_READ_REG(hw, IXGBE_AUTOC2);
autoc2_reg |= IXGBE_AUTOC2_LINK_DISABLE_ON_D3_MASK;
IXGBE_WRITE_REG(hw, IXGBE_AUTOC2, autoc2_reg);
}
}
static s32 ixgbe_start_mac_link_82599(struct ixgbe_hw *hw,
bool autoneg_wait_to_complete)
{
u32 autoc_reg;
u32 links_reg;
u32 i;
s32 status = 0;
bool got_lock = false;
if (ixgbe_verify_lesm_fw_enabled_82599(hw)) {
status = hw->mac.ops.acquire_swfw_sync(hw,
IXGBE_GSSR_MAC_CSR_SM);
if (status)
return status;
got_lock = true;
}
ixgbe_reset_pipeline_82599(hw);
if (got_lock)
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_MAC_CSR_SM);
if (autoneg_wait_to_complete) {
autoc_reg = IXGBE_READ_REG(hw, IXGBE_AUTOC);
if ((autoc_reg & IXGBE_AUTOC_LMS_MASK) ==
IXGBE_AUTOC_LMS_KX4_KX_KR ||
(autoc_reg & IXGBE_AUTOC_LMS_MASK) ==
IXGBE_AUTOC_LMS_KX4_KX_KR_1G_AN ||
(autoc_reg & IXGBE_AUTOC_LMS_MASK) ==
IXGBE_AUTOC_LMS_KX4_KX_KR_SGMII) {
links_reg = 0;
for (i = 0; i < IXGBE_AUTO_NEG_TIME; i++) {
links_reg = IXGBE_READ_REG(hw, IXGBE_LINKS);
if (links_reg & IXGBE_LINKS_KX_AN_COMP)
break;
msleep(100);
}
if (!(links_reg & IXGBE_LINKS_KX_AN_COMP)) {
status = IXGBE_ERR_AUTONEG_NOT_COMPLETE;
hw_dbg(hw, "Autoneg did not complete.\n");
}
}
}
msleep(50);
return status;
}
static void ixgbe_disable_tx_laser_multispeed_fiber(struct ixgbe_hw *hw)
{
u32 esdp_reg = IXGBE_READ_REG(hw, IXGBE_ESDP);
if (ixgbe_check_reset_blocked(hw))
return;
esdp_reg |= IXGBE_ESDP_SDP3;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp_reg);
IXGBE_WRITE_FLUSH(hw);
udelay(100);
}
static void ixgbe_enable_tx_laser_multispeed_fiber(struct ixgbe_hw *hw)
{
u32 esdp_reg = IXGBE_READ_REG(hw, IXGBE_ESDP);
esdp_reg &= ~IXGBE_ESDP_SDP3;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp_reg);
IXGBE_WRITE_FLUSH(hw);
msleep(100);
}
static void ixgbe_flap_tx_laser_multispeed_fiber(struct ixgbe_hw *hw)
{
if (ixgbe_check_reset_blocked(hw))
return;
if (hw->mac.autotry_restart) {
ixgbe_disable_tx_laser_multispeed_fiber(hw);
ixgbe_enable_tx_laser_multispeed_fiber(hw);
hw->mac.autotry_restart = false;
}
}
static s32 ixgbe_setup_mac_link_multispeed_fiber(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
bool autoneg_wait_to_complete)
{
s32 status = 0;
ixgbe_link_speed link_speed = IXGBE_LINK_SPEED_UNKNOWN;
ixgbe_link_speed highest_link_speed = IXGBE_LINK_SPEED_UNKNOWN;
u32 speedcnt = 0;
u32 esdp_reg = IXGBE_READ_REG(hw, IXGBE_ESDP);
u32 i = 0;
bool link_up = false;
bool autoneg = false;
status = hw->mac.ops.get_link_capabilities(hw, &link_speed,
&autoneg);
if (status != 0)
return status;
speed &= link_speed;
if (speed & IXGBE_LINK_SPEED_10GB_FULL) {
speedcnt++;
highest_link_speed = IXGBE_LINK_SPEED_10GB_FULL;
status = hw->mac.ops.check_link(hw, &link_speed, &link_up,
false);
if (status != 0)
return status;
if ((link_speed == IXGBE_LINK_SPEED_10GB_FULL) && link_up)
goto out;
switch (hw->phy.media_type) {
case ixgbe_media_type_fiber:
esdp_reg |= (IXGBE_ESDP_SDP5_DIR | IXGBE_ESDP_SDP5);
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp_reg);
IXGBE_WRITE_FLUSH(hw);
break;
case ixgbe_media_type_fiber_qsfp:
break;
default:
hw_dbg(hw, "Unexpected media type.\n");
break;
}
msleep(40);
status = ixgbe_setup_mac_link_82599(hw,
IXGBE_LINK_SPEED_10GB_FULL,
autoneg_wait_to_complete);
if (status != 0)
return status;
if (hw->mac.ops.flap_tx_laser)
hw->mac.ops.flap_tx_laser(hw);
for (i = 0; i < 5; i++) {
msleep(100);
status = hw->mac.ops.check_link(hw, &link_speed,
&link_up, false);
if (status != 0)
return status;
if (link_up)
goto out;
}
}
if (speed & IXGBE_LINK_SPEED_1GB_FULL) {
speedcnt++;
if (highest_link_speed == IXGBE_LINK_SPEED_UNKNOWN)
highest_link_speed = IXGBE_LINK_SPEED_1GB_FULL;
status = hw->mac.ops.check_link(hw, &link_speed, &link_up,
false);
if (status != 0)
return status;
if ((link_speed == IXGBE_LINK_SPEED_1GB_FULL) && link_up)
goto out;
switch (hw->phy.media_type) {
case ixgbe_media_type_fiber:
esdp_reg &= ~IXGBE_ESDP_SDP5;
esdp_reg |= IXGBE_ESDP_SDP5_DIR;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp_reg);
IXGBE_WRITE_FLUSH(hw);
break;
case ixgbe_media_type_fiber_qsfp:
break;
default:
hw_dbg(hw, "Unexpected media type.\n");
break;
}
msleep(40);
status = ixgbe_setup_mac_link_82599(hw,
IXGBE_LINK_SPEED_1GB_FULL,
autoneg_wait_to_complete);
if (status != 0)
return status;
if (hw->mac.ops.flap_tx_laser)
hw->mac.ops.flap_tx_laser(hw);
msleep(100);
status = hw->mac.ops.check_link(hw, &link_speed, &link_up,
false);
if (status != 0)
return status;
if (link_up)
goto out;
}
if (speedcnt > 1)
status = ixgbe_setup_mac_link_multispeed_fiber(hw,
highest_link_speed,
autoneg_wait_to_complete);
out:
hw->phy.autoneg_advertised = 0;
if (speed & IXGBE_LINK_SPEED_10GB_FULL)
hw->phy.autoneg_advertised |= IXGBE_LINK_SPEED_10GB_FULL;
if (speed & IXGBE_LINK_SPEED_1GB_FULL)
hw->phy.autoneg_advertised |= IXGBE_LINK_SPEED_1GB_FULL;
return status;
}
static s32 ixgbe_setup_mac_link_smartspeed(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
bool autoneg_wait_to_complete)
{
s32 status = 0;
ixgbe_link_speed link_speed = IXGBE_LINK_SPEED_UNKNOWN;
s32 i, j;
bool link_up = false;
u32 autoc_reg = IXGBE_READ_REG(hw, IXGBE_AUTOC);
hw->phy.autoneg_advertised = 0;
if (speed & IXGBE_LINK_SPEED_10GB_FULL)
hw->phy.autoneg_advertised |= IXGBE_LINK_SPEED_10GB_FULL;
if (speed & IXGBE_LINK_SPEED_1GB_FULL)
hw->phy.autoneg_advertised |= IXGBE_LINK_SPEED_1GB_FULL;
if (speed & IXGBE_LINK_SPEED_100_FULL)
hw->phy.autoneg_advertised |= IXGBE_LINK_SPEED_100_FULL;
hw->phy.smart_speed_active = false;
for (j = 0; j < IXGBE_SMARTSPEED_MAX_RETRIES; j++) {
status = ixgbe_setup_mac_link_82599(hw, speed,
autoneg_wait_to_complete);
if (status != 0)
goto out;
for (i = 0; i < 5; i++) {
mdelay(100);
status = hw->mac.ops.check_link(hw, &link_speed,
&link_up, false);
if (status != 0)
goto out;
if (link_up)
goto out;
}
}
if (((autoc_reg & IXGBE_AUTOC_KR_SUPP) == 0) ||
((autoc_reg & IXGBE_AUTOC_KX4_KX_SUPP_MASK) == 0))
goto out;
hw->phy.smart_speed_active = true;
status = ixgbe_setup_mac_link_82599(hw, speed,
autoneg_wait_to_complete);
if (status != 0)
goto out;
for (i = 0; i < 6; i++) {
mdelay(100);
status = hw->mac.ops.check_link(hw, &link_speed,
&link_up, false);
if (status != 0)
goto out;
if (link_up)
goto out;
}
hw->phy.smart_speed_active = false;
status = ixgbe_setup_mac_link_82599(hw, speed,
autoneg_wait_to_complete);
out:
if (link_up && (link_speed == IXGBE_LINK_SPEED_1GB_FULL))
hw_dbg(hw, "Smartspeed has downgraded the link speed from the maximum advertised\n");
return status;
}
static s32 ixgbe_setup_mac_link_82599(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
bool autoneg_wait_to_complete)
{
bool autoneg = false;
s32 status;
u32 pma_pmd_1g, link_mode, links_reg, i;
u32 autoc2 = IXGBE_READ_REG(hw, IXGBE_AUTOC2);
u32 pma_pmd_10g_serial = autoc2 & IXGBE_AUTOC2_10G_SERIAL_PMA_PMD_MASK;
ixgbe_link_speed link_capabilities = IXGBE_LINK_SPEED_UNKNOWN;
u32 current_autoc = IXGBE_READ_REG(hw, IXGBE_AUTOC);
u32 orig_autoc = 0;
u32 autoc = current_autoc;
status = hw->mac.ops.get_link_capabilities(hw, &link_capabilities,
&autoneg);
if (status)
return status;
speed &= link_capabilities;
if (speed == IXGBE_LINK_SPEED_UNKNOWN)
return IXGBE_ERR_LINK_SETUP;
if (hw->mac.orig_link_settings_stored)
orig_autoc = hw->mac.orig_autoc;
else
orig_autoc = autoc;
link_mode = autoc & IXGBE_AUTOC_LMS_MASK;
pma_pmd_1g = autoc & IXGBE_AUTOC_1G_PMA_PMD_MASK;
if (link_mode == IXGBE_AUTOC_LMS_KX4_KX_KR ||
link_mode == IXGBE_AUTOC_LMS_KX4_KX_KR_1G_AN ||
link_mode == IXGBE_AUTOC_LMS_KX4_KX_KR_SGMII) {
autoc &= ~(IXGBE_AUTOC_KX4_KX_SUPP_MASK | IXGBE_AUTOC_KR_SUPP);
if (speed & IXGBE_LINK_SPEED_10GB_FULL) {
if (orig_autoc & IXGBE_AUTOC_KX4_SUPP)
autoc |= IXGBE_AUTOC_KX4_SUPP;
if ((orig_autoc & IXGBE_AUTOC_KR_SUPP) &&
(hw->phy.smart_speed_active == false))
autoc |= IXGBE_AUTOC_KR_SUPP;
}
if (speed & IXGBE_LINK_SPEED_1GB_FULL)
autoc |= IXGBE_AUTOC_KX_SUPP;
} else if ((pma_pmd_1g == IXGBE_AUTOC_1G_SFI) &&
(link_mode == IXGBE_AUTOC_LMS_1G_LINK_NO_AN ||
link_mode == IXGBE_AUTOC_LMS_1G_AN)) {
if ((speed == IXGBE_LINK_SPEED_10GB_FULL) &&
(pma_pmd_10g_serial == IXGBE_AUTOC2_10G_SFI)) {
autoc &= ~IXGBE_AUTOC_LMS_MASK;
autoc |= IXGBE_AUTOC_LMS_10G_SERIAL;
}
} else if ((pma_pmd_10g_serial == IXGBE_AUTOC2_10G_SFI) &&
(link_mode == IXGBE_AUTOC_LMS_10G_SERIAL)) {
if ((speed == IXGBE_LINK_SPEED_1GB_FULL) &&
(pma_pmd_1g == IXGBE_AUTOC_1G_SFI)) {
autoc &= ~IXGBE_AUTOC_LMS_MASK;
if (autoneg)
autoc |= IXGBE_AUTOC_LMS_1G_AN;
else
autoc |= IXGBE_AUTOC_LMS_1G_LINK_NO_AN;
}
}
if (autoc != current_autoc) {
status = hw->mac.ops.prot_autoc_write(hw, autoc, false);
if (status)
return status;
if (autoneg_wait_to_complete) {
if (link_mode == IXGBE_AUTOC_LMS_KX4_KX_KR ||
link_mode == IXGBE_AUTOC_LMS_KX4_KX_KR_1G_AN ||
link_mode == IXGBE_AUTOC_LMS_KX4_KX_KR_SGMII) {
links_reg = 0;
for (i = 0; i < IXGBE_AUTO_NEG_TIME; i++) {
links_reg =
IXGBE_READ_REG(hw, IXGBE_LINKS);
if (links_reg & IXGBE_LINKS_KX_AN_COMP)
break;
msleep(100);
}
if (!(links_reg & IXGBE_LINKS_KX_AN_COMP)) {
status =
IXGBE_ERR_AUTONEG_NOT_COMPLETE;
hw_dbg(hw, "Autoneg did not complete.\n");
}
}
}
msleep(50);
}
return status;
}
static s32 ixgbe_setup_copper_link_82599(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
bool autoneg_wait_to_complete)
{
s32 status;
status = hw->phy.ops.setup_link_speed(hw, speed,
autoneg_wait_to_complete);
ixgbe_start_mac_link_82599(hw, autoneg_wait_to_complete);
return status;
}
static s32 ixgbe_reset_hw_82599(struct ixgbe_hw *hw)
{
ixgbe_link_speed link_speed;
s32 status;
u32 ctrl, i, autoc, autoc2;
u32 curr_lms;
bool link_up = false;
status = hw->mac.ops.stop_adapter(hw);
if (status)
return status;
ixgbe_clear_tx_pending(hw);
status = hw->phy.ops.init(hw);
if (status == IXGBE_ERR_SFP_NOT_SUPPORTED)
return status;
if (hw->phy.sfp_setup_needed) {
status = hw->mac.ops.setup_sfp(hw);
hw->phy.sfp_setup_needed = false;
}
if (status == IXGBE_ERR_SFP_NOT_SUPPORTED)
return status;
if (hw->phy.reset_disable == false && hw->phy.ops.reset != NULL)
hw->phy.ops.reset(hw);
curr_lms = IXGBE_READ_REG(hw, IXGBE_AUTOC) & IXGBE_AUTOC_LMS_MASK;
mac_reset_top:
ctrl = IXGBE_CTRL_LNK_RST;
if (!hw->force_full_reset) {
hw->mac.ops.check_link(hw, &link_speed, &link_up, false);
if (link_up)
ctrl = IXGBE_CTRL_RST;
}
ctrl |= IXGBE_READ_REG(hw, IXGBE_CTRL);
IXGBE_WRITE_REG(hw, IXGBE_CTRL, ctrl);
IXGBE_WRITE_FLUSH(hw);
for (i = 0; i < 10; i++) {
udelay(1);
ctrl = IXGBE_READ_REG(hw, IXGBE_CTRL);
if (!(ctrl & IXGBE_CTRL_RST_MASK))
break;
}
if (ctrl & IXGBE_CTRL_RST_MASK) {
status = IXGBE_ERR_RESET_FAILED;
hw_dbg(hw, "Reset polling failed to complete.\n");
}
msleep(50);
if (hw->mac.flags & IXGBE_FLAGS_DOUBLE_RESET_REQUIRED) {
hw->mac.flags &= ~IXGBE_FLAGS_DOUBLE_RESET_REQUIRED;
goto mac_reset_top;
}
autoc = IXGBE_READ_REG(hw, IXGBE_AUTOC);
autoc2 = IXGBE_READ_REG(hw, IXGBE_AUTOC2);
if (autoc2 & IXGBE_AUTOC2_LINK_DISABLE_MASK) {
autoc2 &= ~IXGBE_AUTOC2_LINK_DISABLE_MASK;
IXGBE_WRITE_REG(hw, IXGBE_AUTOC2, autoc2);
IXGBE_WRITE_FLUSH(hw);
}
if (hw->mac.orig_link_settings_stored == false) {
hw->mac.orig_autoc = autoc;
hw->mac.orig_autoc2 = autoc2;
hw->mac.orig_link_settings_stored = true;
} else {
if ((hw->phy.multispeed_fiber && ixgbe_mng_enabled(hw)) ||
hw->wol_enabled)
hw->mac.orig_autoc =
(hw->mac.orig_autoc & ~IXGBE_AUTOC_LMS_MASK) |
curr_lms;
if (autoc != hw->mac.orig_autoc) {
status = hw->mac.ops.prot_autoc_write(hw,
hw->mac.orig_autoc,
false);
if (status)
return status;
}
if ((autoc2 & IXGBE_AUTOC2_UPPER_MASK) !=
(hw->mac.orig_autoc2 & IXGBE_AUTOC2_UPPER_MASK)) {
autoc2 &= ~IXGBE_AUTOC2_UPPER_MASK;
autoc2 |= (hw->mac.orig_autoc2 &
IXGBE_AUTOC2_UPPER_MASK);
IXGBE_WRITE_REG(hw, IXGBE_AUTOC2, autoc2);
}
}
hw->mac.ops.get_mac_addr(hw, hw->mac.perm_addr);
hw->mac.num_rar_entries = 128;
hw->mac.ops.init_rx_addrs(hw);
hw->mac.ops.get_san_mac_addr(hw, hw->mac.san_addr);
if (is_valid_ether_addr(hw->mac.san_addr)) {
hw->mac.ops.set_rar(hw, hw->mac.num_rar_entries - 1,
hw->mac.san_addr, 0, IXGBE_RAH_AV);
hw->mac.san_mac_rar_index = hw->mac.num_rar_entries - 1;
hw->mac.num_rar_entries--;
}
hw->mac.ops.get_wwn_prefix(hw, &hw->mac.wwnn_prefix,
&hw->mac.wwpn_prefix);
return status;
}
static s32 ixgbe_fdir_check_cmd_complete(struct ixgbe_hw *hw, u32 *fdircmd)
{
int i;
for (i = 0; i < IXGBE_FDIRCMD_CMD_POLL; i++) {
*fdircmd = IXGBE_READ_REG(hw, IXGBE_FDIRCMD);
if (!(*fdircmd & IXGBE_FDIRCMD_CMD_MASK))
return 0;
udelay(10);
}
return IXGBE_ERR_FDIR_CMD_INCOMPLETE;
}
s32 ixgbe_reinit_fdir_tables_82599(struct ixgbe_hw *hw)
{
int i;
u32 fdirctrl = IXGBE_READ_REG(hw, IXGBE_FDIRCTRL);
u32 fdircmd;
s32 err;
fdirctrl &= ~IXGBE_FDIRCTRL_INIT_DONE;
err = ixgbe_fdir_check_cmd_complete(hw, &fdircmd);
if (err) {
hw_dbg(hw, "Flow Director previous command did not complete, aborting table re-initialization.\n");
return err;
}
IXGBE_WRITE_REG(hw, IXGBE_FDIRFREE, 0);
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_FDIRCMD,
(IXGBE_READ_REG(hw, IXGBE_FDIRCMD) |
IXGBE_FDIRCMD_CLEARHT));
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_FDIRCMD,
(IXGBE_READ_REG(hw, IXGBE_FDIRCMD) &
~IXGBE_FDIRCMD_CLEARHT));
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_FDIRHASH, 0x00);
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_FDIRCTRL, fdirctrl);
IXGBE_WRITE_FLUSH(hw);
for (i = 0; i < IXGBE_FDIR_INIT_DONE_POLL; i++) {
if (IXGBE_READ_REG(hw, IXGBE_FDIRCTRL) &
IXGBE_FDIRCTRL_INIT_DONE)
break;
usleep_range(1000, 2000);
}
if (i >= IXGBE_FDIR_INIT_DONE_POLL) {
hw_dbg(hw, "Flow Director Signature poll time exceeded!\n");
return IXGBE_ERR_FDIR_REINIT_FAILED;
}
IXGBE_READ_REG(hw, IXGBE_FDIRUSTAT);
IXGBE_READ_REG(hw, IXGBE_FDIRFSTAT);
IXGBE_READ_REG(hw, IXGBE_FDIRMATCH);
IXGBE_READ_REG(hw, IXGBE_FDIRMISS);
IXGBE_READ_REG(hw, IXGBE_FDIRLEN);
return 0;
}
static void ixgbe_fdir_enable_82599(struct ixgbe_hw *hw, u32 fdirctrl)
{
int i;
IXGBE_WRITE_REG(hw, IXGBE_FDIRHKEY, IXGBE_ATR_BUCKET_HASH_KEY);
IXGBE_WRITE_REG(hw, IXGBE_FDIRSKEY, IXGBE_ATR_SIGNATURE_HASH_KEY);
IXGBE_WRITE_REG(hw, IXGBE_FDIRCTRL, fdirctrl);
IXGBE_WRITE_FLUSH(hw);
for (i = 0; i < IXGBE_FDIR_INIT_DONE_POLL; i++) {
if (IXGBE_READ_REG(hw, IXGBE_FDIRCTRL) &
IXGBE_FDIRCTRL_INIT_DONE)
break;
usleep_range(1000, 2000);
}
if (i >= IXGBE_FDIR_INIT_DONE_POLL)
hw_dbg(hw, "Flow Director poll time exceeded!\n");
}
s32 ixgbe_init_fdir_signature_82599(struct ixgbe_hw *hw, u32 fdirctrl)
{
fdirctrl |= (0x6 << IXGBE_FDIRCTRL_FLEX_SHIFT) |
(0xA << IXGBE_FDIRCTRL_MAX_LENGTH_SHIFT) |
(4 << IXGBE_FDIRCTRL_FULL_THRESH_SHIFT);
ixgbe_fdir_enable_82599(hw, fdirctrl);
return 0;
}
s32 ixgbe_init_fdir_perfect_82599(struct ixgbe_hw *hw, u32 fdirctrl)
{
fdirctrl |= IXGBE_FDIRCTRL_PERFECT_MATCH |
(IXGBE_FDIR_DROP_QUEUE << IXGBE_FDIRCTRL_DROP_Q_SHIFT) |
(0x6 << IXGBE_FDIRCTRL_FLEX_SHIFT) |
(0xA << IXGBE_FDIRCTRL_MAX_LENGTH_SHIFT) |
(4 << IXGBE_FDIRCTRL_FULL_THRESH_SHIFT);
ixgbe_fdir_enable_82599(hw, fdirctrl);
return 0;
}
static u32 ixgbe_atr_compute_sig_hash_82599(union ixgbe_atr_hash_dword input,
union ixgbe_atr_hash_dword common)
{
u32 hi_hash_dword, lo_hash_dword, flow_vm_vlan;
u32 sig_hash = 0, bucket_hash = 0, common_hash = 0;
flow_vm_vlan = ntohl(input.dword);
hi_hash_dword = ntohl(common.dword);
lo_hash_dword = (hi_hash_dword >> 16) | (hi_hash_dword << 16);
hi_hash_dword ^= flow_vm_vlan ^ (flow_vm_vlan >> 16);
IXGBE_COMPUTE_SIG_HASH_ITERATION(0);
lo_hash_dword ^= flow_vm_vlan ^ (flow_vm_vlan << 16);
IXGBE_COMPUTE_SIG_HASH_ITERATION(1);
IXGBE_COMPUTE_SIG_HASH_ITERATION(2);
IXGBE_COMPUTE_SIG_HASH_ITERATION(3);
IXGBE_COMPUTE_SIG_HASH_ITERATION(4);
IXGBE_COMPUTE_SIG_HASH_ITERATION(5);
IXGBE_COMPUTE_SIG_HASH_ITERATION(6);
IXGBE_COMPUTE_SIG_HASH_ITERATION(7);
IXGBE_COMPUTE_SIG_HASH_ITERATION(8);
IXGBE_COMPUTE_SIG_HASH_ITERATION(9);
IXGBE_COMPUTE_SIG_HASH_ITERATION(10);
IXGBE_COMPUTE_SIG_HASH_ITERATION(11);
IXGBE_COMPUTE_SIG_HASH_ITERATION(12);
IXGBE_COMPUTE_SIG_HASH_ITERATION(13);
IXGBE_COMPUTE_SIG_HASH_ITERATION(14);
IXGBE_COMPUTE_SIG_HASH_ITERATION(15);
bucket_hash ^= common_hash;
bucket_hash &= IXGBE_ATR_HASH_MASK;
sig_hash ^= common_hash << 16;
sig_hash &= IXGBE_ATR_HASH_MASK << 16;
return sig_hash ^ bucket_hash;
}
s32 ixgbe_fdir_add_signature_filter_82599(struct ixgbe_hw *hw,
union ixgbe_atr_hash_dword input,
union ixgbe_atr_hash_dword common,
u8 queue)
{
u64 fdirhashcmd;
u8 flow_type;
bool tunnel;
u32 fdircmd;
tunnel = !!(input.formatted.flow_type & IXGBE_ATR_L4TYPE_TUNNEL_MASK);
flow_type = input.formatted.flow_type &
(IXGBE_ATR_L4TYPE_TUNNEL_MASK - 1);
switch (flow_type) {
case IXGBE_ATR_FLOW_TYPE_TCPV4:
case IXGBE_ATR_FLOW_TYPE_UDPV4:
case IXGBE_ATR_FLOW_TYPE_SCTPV4:
case IXGBE_ATR_FLOW_TYPE_TCPV6:
case IXGBE_ATR_FLOW_TYPE_UDPV6:
case IXGBE_ATR_FLOW_TYPE_SCTPV6:
break;
default:
hw_dbg(hw, " Error on flow type input\n");
return IXGBE_ERR_CONFIG;
}
fdircmd = IXGBE_FDIRCMD_CMD_ADD_FLOW | IXGBE_FDIRCMD_FILTER_UPDATE |
IXGBE_FDIRCMD_LAST | IXGBE_FDIRCMD_QUEUE_EN;
fdircmd |= (u32)flow_type << IXGBE_FDIRCMD_FLOW_TYPE_SHIFT;
fdircmd |= (u32)queue << IXGBE_FDIRCMD_RX_QUEUE_SHIFT;
if (tunnel)
fdircmd |= IXGBE_FDIRCMD_TUNNEL_FILTER;
fdirhashcmd = (u64)fdircmd << 32;
fdirhashcmd |= ixgbe_atr_compute_sig_hash_82599(input, common);
IXGBE_WRITE_REG64(hw, IXGBE_FDIRHASH, fdirhashcmd);
hw_dbg(hw, "Tx Queue=%x hash=%x\n", queue, (u32)fdirhashcmd);
return 0;
}
void ixgbe_atr_compute_perfect_hash_82599(union ixgbe_atr_input *input,
union ixgbe_atr_input *input_mask)
{
u32 hi_hash_dword, lo_hash_dword, flow_vm_vlan;
u32 bucket_hash = 0, hi_dword = 0;
int i;
for (i = 0; i <= 10; i++)
input->dword_stream[i] &= input_mask->dword_stream[i];
flow_vm_vlan = ntohl(input->dword_stream[0]);
for (i = 1; i <= 10; i++)
hi_dword ^= input->dword_stream[i];
hi_hash_dword = ntohl(hi_dword);
lo_hash_dword = (hi_hash_dword >> 16) | (hi_hash_dword << 16);
hi_hash_dword ^= flow_vm_vlan ^ (flow_vm_vlan >> 16);
IXGBE_COMPUTE_BKT_HASH_ITERATION(0);
lo_hash_dword ^= flow_vm_vlan ^ (flow_vm_vlan << 16);
for (i = 1; i <= 15; i++)
IXGBE_COMPUTE_BKT_HASH_ITERATION(i);
input->formatted.bkt_hash = bucket_hash & 0x1FFF;
}
static u32 ixgbe_get_fdirtcpm_82599(union ixgbe_atr_input *input_mask)
{
u32 mask = ntohs(input_mask->formatted.dst_port);
mask <<= IXGBE_FDIRTCPM_DPORTM_SHIFT;
mask |= ntohs(input_mask->formatted.src_port);
mask = ((mask & 0x55555555) << 1) | ((mask & 0xAAAAAAAA) >> 1);
mask = ((mask & 0x33333333) << 2) | ((mask & 0xCCCCCCCC) >> 2);
mask = ((mask & 0x0F0F0F0F) << 4) | ((mask & 0xF0F0F0F0) >> 4);
return ((mask & 0x00FF00FF) << 8) | ((mask & 0xFF00FF00) >> 8);
}
s32 ixgbe_fdir_set_input_mask_82599(struct ixgbe_hw *hw,
union ixgbe_atr_input *input_mask)
{
u32 fdirm = IXGBE_FDIRM_DIPv6;
u32 fdirtcpm;
if (input_mask->formatted.bkt_hash)
hw_dbg(hw, " bucket hash should always be 0 in mask\n");
switch (input_mask->formatted.vm_pool & 0x7F) {
case 0x0:
fdirm |= IXGBE_FDIRM_POOL;
case 0x7F:
break;
default:
hw_dbg(hw, " Error on vm pool mask\n");
return IXGBE_ERR_CONFIG;
}
switch (input_mask->formatted.flow_type & IXGBE_ATR_L4TYPE_MASK) {
case 0x0:
fdirm |= IXGBE_FDIRM_L4P;
if (input_mask->formatted.dst_port ||
input_mask->formatted.src_port) {
hw_dbg(hw, " Error on src/dst port mask\n");
return IXGBE_ERR_CONFIG;
}
case IXGBE_ATR_L4TYPE_MASK:
break;
default:
hw_dbg(hw, " Error on flow type mask\n");
return IXGBE_ERR_CONFIG;
}
switch (ntohs(input_mask->formatted.vlan_id) & 0xEFFF) {
case 0x0000:
fdirm |= IXGBE_FDIRM_VLANID;
case 0x0FFF:
fdirm |= IXGBE_FDIRM_VLANP;
break;
case 0xE000:
fdirm |= IXGBE_FDIRM_VLANID;
case 0xEFFF:
break;
default:
hw_dbg(hw, " Error on VLAN mask\n");
return IXGBE_ERR_CONFIG;
}
switch (input_mask->formatted.flex_bytes & 0xFFFF) {
case 0x0000:
fdirm |= IXGBE_FDIRM_FLEX;
case 0xFFFF:
break;
default:
hw_dbg(hw, " Error on flexible byte mask\n");
return IXGBE_ERR_CONFIG;
}
IXGBE_WRITE_REG(hw, IXGBE_FDIRM, fdirm);
fdirtcpm = ixgbe_get_fdirtcpm_82599(input_mask);
IXGBE_WRITE_REG(hw, IXGBE_FDIRTCPM, ~fdirtcpm);
IXGBE_WRITE_REG(hw, IXGBE_FDIRUDPM, ~fdirtcpm);
IXGBE_WRITE_REG_BE32(hw, IXGBE_FDIRSIP4M,
~input_mask->formatted.src_ip[0]);
IXGBE_WRITE_REG_BE32(hw, IXGBE_FDIRDIP4M,
~input_mask->formatted.dst_ip[0]);
return 0;
}
s32 ixgbe_fdir_write_perfect_filter_82599(struct ixgbe_hw *hw,
union ixgbe_atr_input *input,
u16 soft_id, u8 queue)
{
u32 fdirport, fdirvlan, fdirhash, fdircmd;
s32 err;
IXGBE_WRITE_REG_BE32(hw, IXGBE_FDIRSIPv6(0),
input->formatted.src_ip[0]);
IXGBE_WRITE_REG_BE32(hw, IXGBE_FDIRSIPv6(1),
input->formatted.src_ip[1]);
IXGBE_WRITE_REG_BE32(hw, IXGBE_FDIRSIPv6(2),
input->formatted.src_ip[2]);
IXGBE_WRITE_REG_BE32(hw, IXGBE_FDIRIPSA, input->formatted.src_ip[0]);
IXGBE_WRITE_REG_BE32(hw, IXGBE_FDIRIPDA, input->formatted.dst_ip[0]);
fdirport = ntohs(input->formatted.dst_port);
fdirport <<= IXGBE_FDIRPORT_DESTINATION_SHIFT;
fdirport |= ntohs(input->formatted.src_port);
IXGBE_WRITE_REG(hw, IXGBE_FDIRPORT, fdirport);
fdirvlan = IXGBE_STORE_AS_BE16(input->formatted.flex_bytes);
fdirvlan <<= IXGBE_FDIRVLAN_FLEX_SHIFT;
fdirvlan |= ntohs(input->formatted.vlan_id);
IXGBE_WRITE_REG(hw, IXGBE_FDIRVLAN, fdirvlan);
fdirhash = input->formatted.bkt_hash;
fdirhash |= soft_id << IXGBE_FDIRHASH_SIG_SW_INDEX_SHIFT;
IXGBE_WRITE_REG(hw, IXGBE_FDIRHASH, fdirhash);
IXGBE_WRITE_FLUSH(hw);
fdircmd = IXGBE_FDIRCMD_CMD_ADD_FLOW | IXGBE_FDIRCMD_FILTER_UPDATE |
IXGBE_FDIRCMD_LAST | IXGBE_FDIRCMD_QUEUE_EN;
if (queue == IXGBE_FDIR_DROP_QUEUE)
fdircmd |= IXGBE_FDIRCMD_DROP;
fdircmd |= input->formatted.flow_type << IXGBE_FDIRCMD_FLOW_TYPE_SHIFT;
fdircmd |= (u32)queue << IXGBE_FDIRCMD_RX_QUEUE_SHIFT;
fdircmd |= (u32)input->formatted.vm_pool << IXGBE_FDIRCMD_VT_POOL_SHIFT;
IXGBE_WRITE_REG(hw, IXGBE_FDIRCMD, fdircmd);
err = ixgbe_fdir_check_cmd_complete(hw, &fdircmd);
if (err) {
hw_dbg(hw, "Flow Director command did not complete!\n");
return err;
}
return 0;
}
s32 ixgbe_fdir_erase_perfect_filter_82599(struct ixgbe_hw *hw,
union ixgbe_atr_input *input,
u16 soft_id)
{
u32 fdirhash;
u32 fdircmd;
s32 err;
fdirhash = input->formatted.bkt_hash;
fdirhash |= soft_id << IXGBE_FDIRHASH_SIG_SW_INDEX_SHIFT;
IXGBE_WRITE_REG(hw, IXGBE_FDIRHASH, fdirhash);
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_FDIRCMD, IXGBE_FDIRCMD_CMD_QUERY_REM_FILT);
err = ixgbe_fdir_check_cmd_complete(hw, &fdircmd);
if (err) {
hw_dbg(hw, "Flow Director command did not complete!\n");
return err;
}
if (fdircmd & IXGBE_FDIRCMD_FILTER_VALID) {
IXGBE_WRITE_REG(hw, IXGBE_FDIRHASH, fdirhash);
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_FDIRCMD,
IXGBE_FDIRCMD_CMD_REMOVE_FLOW);
}
return 0;
}
static s32 ixgbe_read_analog_reg8_82599(struct ixgbe_hw *hw, u32 reg, u8 *val)
{
u32 core_ctl;
IXGBE_WRITE_REG(hw, IXGBE_CORECTL, IXGBE_CORECTL_WRITE_CMD |
(reg << 8));
IXGBE_WRITE_FLUSH(hw);
udelay(10);
core_ctl = IXGBE_READ_REG(hw, IXGBE_CORECTL);
*val = (u8)core_ctl;
return 0;
}
static s32 ixgbe_write_analog_reg8_82599(struct ixgbe_hw *hw, u32 reg, u8 val)
{
u32 core_ctl;
core_ctl = (reg << 8) | val;
IXGBE_WRITE_REG(hw, IXGBE_CORECTL, core_ctl);
IXGBE_WRITE_FLUSH(hw);
udelay(10);
return 0;
}
static s32 ixgbe_start_hw_82599(struct ixgbe_hw *hw)
{
s32 ret_val = 0;
ret_val = ixgbe_start_hw_generic(hw);
if (ret_val)
return ret_val;
ret_val = ixgbe_start_hw_gen2(hw);
if (ret_val)
return ret_val;
hw->mac.autotry_restart = true;
if (ret_val)
return ret_val;
return ixgbe_verify_fw_version_82599(hw);
}
static s32 ixgbe_identify_phy_82599(struct ixgbe_hw *hw)
{
s32 status;
status = ixgbe_identify_phy_generic(hw);
if (status) {
if (hw->mac.ops.get_media_type(hw) == ixgbe_media_type_copper)
return status;
status = ixgbe_identify_module_generic(hw);
}
if (hw->phy.type == ixgbe_phy_unknown) {
hw->phy.type = ixgbe_phy_none;
status = 0;
}
if (hw->phy.type == ixgbe_phy_sfp_unsupported)
return IXGBE_ERR_SFP_NOT_SUPPORTED;
return status;
}
static s32 ixgbe_enable_rx_dma_82599(struct ixgbe_hw *hw, u32 regval)
{
hw->mac.ops.disable_rx_buff(hw);
if (regval & IXGBE_RXCTRL_RXEN)
hw->mac.ops.enable_rx(hw);
else
hw->mac.ops.disable_rx(hw);
hw->mac.ops.enable_rx_buff(hw);
return 0;
}
static s32 ixgbe_verify_fw_version_82599(struct ixgbe_hw *hw)
{
s32 status = IXGBE_ERR_EEPROM_VERSION;
u16 fw_offset, fw_ptp_cfg_offset;
u16 offset;
u16 fw_version = 0;
if (hw->phy.media_type != ixgbe_media_type_fiber)
return 0;
offset = IXGBE_FW_PTR;
if (hw->eeprom.ops.read(hw, offset, &fw_offset))
goto fw_version_err;
if (fw_offset == 0 || fw_offset == 0xFFFF)
return IXGBE_ERR_EEPROM_VERSION;
offset = fw_offset + IXGBE_FW_PASSTHROUGH_PATCH_CONFIG_PTR;
if (hw->eeprom.ops.read(hw, offset, &fw_ptp_cfg_offset))
goto fw_version_err;
if (fw_ptp_cfg_offset == 0 || fw_ptp_cfg_offset == 0xFFFF)
return IXGBE_ERR_EEPROM_VERSION;
offset = fw_ptp_cfg_offset + IXGBE_FW_PATCH_VERSION_4;
if (hw->eeprom.ops.read(hw, offset, &fw_version))
goto fw_version_err;
if (fw_version > 0x5)
status = 0;
return status;
fw_version_err:
hw_err(hw, "eeprom read at offset %d failed\n", offset);
return IXGBE_ERR_EEPROM_VERSION;
}
static bool ixgbe_verify_lesm_fw_enabled_82599(struct ixgbe_hw *hw)
{
u16 fw_offset, fw_lesm_param_offset, fw_lesm_state;
s32 status;
status = hw->eeprom.ops.read(hw, IXGBE_FW_PTR, &fw_offset);
if (status || fw_offset == 0 || fw_offset == 0xFFFF)
return false;
status = hw->eeprom.ops.read(hw, (fw_offset +
IXGBE_FW_LESM_PARAMETERS_PTR),
&fw_lesm_param_offset);
if (status ||
fw_lesm_param_offset == 0 || fw_lesm_param_offset == 0xFFFF)
return false;
status = hw->eeprom.ops.read(hw, (fw_lesm_param_offset +
IXGBE_FW_LESM_STATE_1),
&fw_lesm_state);
if (!status && (fw_lesm_state & IXGBE_FW_LESM_STATE_ENABLED))
return true;
return false;
}
static s32 ixgbe_read_eeprom_buffer_82599(struct ixgbe_hw *hw, u16 offset,
u16 words, u16 *data)
{
struct ixgbe_eeprom_info *eeprom = &hw->eeprom;
if (eeprom->type == ixgbe_eeprom_spi &&
offset + (words - 1) <= IXGBE_EERD_MAX_ADDR)
return ixgbe_read_eerd_buffer_generic(hw, offset, words, data);
return ixgbe_read_eeprom_buffer_bit_bang_generic(hw, offset, words,
data);
}
static s32 ixgbe_read_eeprom_82599(struct ixgbe_hw *hw,
u16 offset, u16 *data)
{
struct ixgbe_eeprom_info *eeprom = &hw->eeprom;
if (eeprom->type == ixgbe_eeprom_spi && offset <= IXGBE_EERD_MAX_ADDR)
return ixgbe_read_eerd_generic(hw, offset, data);
return ixgbe_read_eeprom_bit_bang_generic(hw, offset, data);
}
static s32 ixgbe_reset_pipeline_82599(struct ixgbe_hw *hw)
{
s32 ret_val;
u32 anlp1_reg = 0;
u32 i, autoc_reg, autoc2_reg;
autoc2_reg = IXGBE_READ_REG(hw, IXGBE_AUTOC2);
if (autoc2_reg & IXGBE_AUTOC2_LINK_DISABLE_MASK) {
autoc2_reg &= ~IXGBE_AUTOC2_LINK_DISABLE_MASK;
IXGBE_WRITE_REG(hw, IXGBE_AUTOC2, autoc2_reg);
IXGBE_WRITE_FLUSH(hw);
}
autoc_reg = IXGBE_READ_REG(hw, IXGBE_AUTOC);
autoc_reg |= IXGBE_AUTOC_AN_RESTART;
IXGBE_WRITE_REG(hw, IXGBE_AUTOC,
autoc_reg ^ (0x4 << IXGBE_AUTOC_LMS_SHIFT));
for (i = 0; i < 10; i++) {
usleep_range(4000, 8000);
anlp1_reg = IXGBE_READ_REG(hw, IXGBE_ANLP1);
if (anlp1_reg & IXGBE_ANLP1_AN_STATE_MASK)
break;
}
if (!(anlp1_reg & IXGBE_ANLP1_AN_STATE_MASK)) {
hw_dbg(hw, "auto negotiation not completed\n");
ret_val = IXGBE_ERR_RESET_FAILED;
goto reset_pipeline_out;
}
ret_val = 0;
reset_pipeline_out:
IXGBE_WRITE_REG(hw, IXGBE_AUTOC, autoc_reg);
IXGBE_WRITE_FLUSH(hw);
return ret_val;
}
static s32 ixgbe_read_i2c_byte_82599(struct ixgbe_hw *hw, u8 byte_offset,
u8 dev_addr, u8 *data)
{
u32 esdp;
s32 status;
s32 timeout = 200;
if (hw->phy.qsfp_shared_i2c_bus == true) {
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
esdp |= IXGBE_ESDP_SDP0;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_FLUSH(hw);
while (timeout) {
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
if (esdp & IXGBE_ESDP_SDP1)
break;
usleep_range(5000, 10000);
timeout--;
}
if (!timeout) {
hw_dbg(hw, "Driver can't access resource, acquiring I2C bus timeout.\n");
status = IXGBE_ERR_I2C;
goto release_i2c_access;
}
}
status = ixgbe_read_i2c_byte_generic(hw, byte_offset, dev_addr, data);
release_i2c_access:
if (hw->phy.qsfp_shared_i2c_bus == true) {
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
esdp &= ~IXGBE_ESDP_SDP0;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_FLUSH(hw);
}
return status;
}
static s32 ixgbe_write_i2c_byte_82599(struct ixgbe_hw *hw, u8 byte_offset,
u8 dev_addr, u8 data)
{
u32 esdp;
s32 status;
s32 timeout = 200;
if (hw->phy.qsfp_shared_i2c_bus == true) {
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
esdp |= IXGBE_ESDP_SDP0;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_FLUSH(hw);
while (timeout) {
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
if (esdp & IXGBE_ESDP_SDP1)
break;
usleep_range(5000, 10000);
timeout--;
}
if (!timeout) {
hw_dbg(hw, "Driver can't access resource, acquiring I2C bus timeout.\n");
status = IXGBE_ERR_I2C;
goto release_i2c_access;
}
}
status = ixgbe_write_i2c_byte_generic(hw, byte_offset, dev_addr, data);
release_i2c_access:
if (hw->phy.qsfp_shared_i2c_bus == true) {
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
esdp &= ~IXGBE_ESDP_SDP0;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_FLUSH(hw);
}
return status;
}
