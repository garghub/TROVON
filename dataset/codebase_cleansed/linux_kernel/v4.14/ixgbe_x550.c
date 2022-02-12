static s32 ixgbe_get_invariants_X550_x(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
struct ixgbe_phy_info *phy = &hw->phy;
struct ixgbe_link_info *link = &hw->link;
ixgbe_get_invariants_X540(hw);
if (mac->ops.get_media_type(hw) != ixgbe_media_type_copper)
phy->ops.set_phy_power = NULL;
link->addr = IXGBE_CS4227;
return 0;
}
static s32 ixgbe_get_invariants_X550_x_fw(struct ixgbe_hw *hw)
{
struct ixgbe_phy_info *phy = &hw->phy;
ixgbe_get_invariants_X540(hw);
phy->ops.set_phy_power = NULL;
return 0;
}
static s32 ixgbe_get_invariants_X550_a(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
struct ixgbe_phy_info *phy = &hw->phy;
ixgbe_get_invariants_X540(hw);
if (mac->ops.get_media_type(hw) != ixgbe_media_type_copper)
phy->ops.set_phy_power = NULL;
return 0;
}
static s32 ixgbe_get_invariants_X550_a_fw(struct ixgbe_hw *hw)
{
struct ixgbe_phy_info *phy = &hw->phy;
ixgbe_get_invariants_X540(hw);
phy->ops.set_phy_power = NULL;
return 0;
}
static void ixgbe_setup_mux_ctl(struct ixgbe_hw *hw)
{
u32 esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
if (hw->bus.lan_id) {
esdp &= ~(IXGBE_ESDP_SDP1_NATIVE | IXGBE_ESDP_SDP1);
esdp |= IXGBE_ESDP_SDP1_DIR;
}
esdp &= ~(IXGBE_ESDP_SDP0_NATIVE | IXGBE_ESDP_SDP0_DIR);
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_FLUSH(hw);
}
static s32 ixgbe_read_cs4227(struct ixgbe_hw *hw, u16 reg, u16 *value)
{
return hw->link.ops.read_link_unlocked(hw, hw->link.addr, reg, value);
}
static s32 ixgbe_write_cs4227(struct ixgbe_hw *hw, u16 reg, u16 value)
{
return hw->link.ops.write_link_unlocked(hw, hw->link.addr, reg, value);
}
static s32 ixgbe_read_pe(struct ixgbe_hw *hw, u8 reg, u8 *value)
{
s32 status;
status = ixgbe_read_i2c_byte_generic_unlocked(hw, reg, IXGBE_PE, value);
if (status)
hw_err(hw, "port expander access failed with %d\n", status);
return status;
}
static s32 ixgbe_write_pe(struct ixgbe_hw *hw, u8 reg, u8 value)
{
s32 status;
status = ixgbe_write_i2c_byte_generic_unlocked(hw, reg, IXGBE_PE,
value);
if (status)
hw_err(hw, "port expander access failed with %d\n", status);
return status;
}
static s32 ixgbe_reset_cs4227(struct ixgbe_hw *hw)
{
s32 status;
u32 retry;
u16 value;
u8 reg;
status = ixgbe_read_pe(hw, IXGBE_PE_OUTPUT, &reg);
if (status)
return status;
reg |= IXGBE_PE_BIT1;
status = ixgbe_write_pe(hw, IXGBE_PE_OUTPUT, reg);
if (status)
return status;
status = ixgbe_read_pe(hw, IXGBE_PE_CONFIG, &reg);
if (status)
return status;
reg &= ~IXGBE_PE_BIT1;
status = ixgbe_write_pe(hw, IXGBE_PE_CONFIG, reg);
if (status)
return status;
status = ixgbe_read_pe(hw, IXGBE_PE_OUTPUT, &reg);
if (status)
return status;
reg &= ~IXGBE_PE_BIT1;
status = ixgbe_write_pe(hw, IXGBE_PE_OUTPUT, reg);
if (status)
return status;
usleep_range(IXGBE_CS4227_RESET_HOLD, IXGBE_CS4227_RESET_HOLD + 100);
status = ixgbe_read_pe(hw, IXGBE_PE_OUTPUT, &reg);
if (status)
return status;
reg |= IXGBE_PE_BIT1;
status = ixgbe_write_pe(hw, IXGBE_PE_OUTPUT, reg);
if (status)
return status;
msleep(IXGBE_CS4227_RESET_DELAY);
for (retry = 0; retry < IXGBE_CS4227_RETRIES; retry++) {
status = ixgbe_read_cs4227(hw, IXGBE_CS4227_EFUSE_STATUS,
&value);
if (!status && value == IXGBE_CS4227_EEPROM_LOAD_OK)
break;
msleep(IXGBE_CS4227_CHECK_DELAY);
}
if (retry == IXGBE_CS4227_RETRIES) {
hw_err(hw, "CS4227 reset did not complete\n");
return IXGBE_ERR_PHY;
}
status = ixgbe_read_cs4227(hw, IXGBE_CS4227_EEPROM_STATUS, &value);
if (status || !(value & IXGBE_CS4227_EEPROM_LOAD_OK)) {
hw_err(hw, "CS4227 EEPROM did not load successfully\n");
return IXGBE_ERR_PHY;
}
return 0;
}
static void ixgbe_check_cs4227(struct ixgbe_hw *hw)
{
u32 swfw_mask = hw->phy.phy_semaphore_mask;
s32 status;
u16 value;
u8 retry;
for (retry = 0; retry < IXGBE_CS4227_RETRIES; retry++) {
status = hw->mac.ops.acquire_swfw_sync(hw, swfw_mask);
if (status) {
hw_err(hw, "semaphore failed with %d\n", status);
msleep(IXGBE_CS4227_CHECK_DELAY);
continue;
}
status = ixgbe_read_cs4227(hw, IXGBE_CS4227_SCRATCH, &value);
if (!status && value == IXGBE_CS4227_RESET_COMPLETE)
goto out;
if (status || value != IXGBE_CS4227_RESET_PENDING)
break;
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
msleep(IXGBE_CS4227_CHECK_DELAY);
}
if (retry == IXGBE_CS4227_RETRIES) {
status = hw->mac.ops.acquire_swfw_sync(hw, swfw_mask);
if (status) {
hw_err(hw, "semaphore failed with %d\n", status);
return;
}
}
status = ixgbe_reset_cs4227(hw);
if (status) {
hw_err(hw, "CS4227 reset failed: %d", status);
goto out;
}
ixgbe_write_cs4227(hw, IXGBE_CS4227_SCRATCH,
IXGBE_CS4227_RESET_PENDING);
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
usleep_range(10000, 12000);
status = hw->mac.ops.acquire_swfw_sync(hw, swfw_mask);
if (status) {
hw_err(hw, "semaphore failed with %d", status);
return;
}
status = ixgbe_write_cs4227(hw, IXGBE_CS4227_SCRATCH,
IXGBE_CS4227_RESET_COMPLETE);
out:
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
msleep(hw->eeprom.semaphore_delay);
}
static s32 ixgbe_identify_phy_x550em(struct ixgbe_hw *hw)
{
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_A_SFP:
if (hw->bus.lan_id)
hw->phy.phy_semaphore_mask = IXGBE_GSSR_PHY1_SM;
else
hw->phy.phy_semaphore_mask = IXGBE_GSSR_PHY0_SM;
return ixgbe_identify_module_generic(hw);
case IXGBE_DEV_ID_X550EM_X_SFP:
hw->phy.phy_semaphore_mask = IXGBE_GSSR_SHARED_I2C_SM;
ixgbe_setup_mux_ctl(hw);
ixgbe_check_cs4227(hw);
case IXGBE_DEV_ID_X550EM_A_SFP_N:
return ixgbe_identify_module_generic(hw);
case IXGBE_DEV_ID_X550EM_X_KX4:
hw->phy.type = ixgbe_phy_x550em_kx4;
break;
case IXGBE_DEV_ID_X550EM_X_XFI:
hw->phy.type = ixgbe_phy_x550em_xfi;
break;
case IXGBE_DEV_ID_X550EM_X_KR:
case IXGBE_DEV_ID_X550EM_A_KR:
case IXGBE_DEV_ID_X550EM_A_KR_L:
hw->phy.type = ixgbe_phy_x550em_kr;
break;
case IXGBE_DEV_ID_X550EM_A_10G_T:
if (hw->bus.lan_id)
hw->phy.phy_semaphore_mask = IXGBE_GSSR_PHY1_SM;
else
hw->phy.phy_semaphore_mask = IXGBE_GSSR_PHY0_SM;
case IXGBE_DEV_ID_X550EM_X_10G_T:
return ixgbe_identify_phy_generic(hw);
case IXGBE_DEV_ID_X550EM_X_1G_T:
hw->phy.type = ixgbe_phy_ext_1g_t;
break;
case IXGBE_DEV_ID_X550EM_A_1G_T:
case IXGBE_DEV_ID_X550EM_A_1G_T_L:
hw->phy.type = ixgbe_phy_fw;
hw->phy.ops.read_reg = NULL;
hw->phy.ops.write_reg = NULL;
if (hw->bus.lan_id)
hw->phy.phy_semaphore_mask |= IXGBE_GSSR_PHY1_SM;
else
hw->phy.phy_semaphore_mask |= IXGBE_GSSR_PHY0_SM;
break;
default:
break;
}
return 0;
}
static s32 ixgbe_read_phy_reg_x550em(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u16 *phy_data)
{
return IXGBE_NOT_IMPLEMENTED;
}
static s32 ixgbe_write_phy_reg_x550em(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u16 phy_data)
{
return IXGBE_NOT_IMPLEMENTED;
}
static s32 ixgbe_read_i2c_combined_generic(struct ixgbe_hw *hw, u8 addr,
u16 reg, u16 *val)
{
return ixgbe_read_i2c_combined_generic_int(hw, addr, reg, val, true);
}
static s32
ixgbe_read_i2c_combined_generic_unlocked(struct ixgbe_hw *hw, u8 addr,
u16 reg, u16 *val)
{
return ixgbe_read_i2c_combined_generic_int(hw, addr, reg, val, false);
}
static s32 ixgbe_write_i2c_combined_generic(struct ixgbe_hw *hw,
u8 addr, u16 reg, u16 val)
{
return ixgbe_write_i2c_combined_generic_int(hw, addr, reg, val, true);
}
static s32
ixgbe_write_i2c_combined_generic_unlocked(struct ixgbe_hw *hw,
u8 addr, u16 reg, u16 val)
{
return ixgbe_write_i2c_combined_generic_int(hw, addr, reg, val, false);
}
static s32 ixgbe_get_phy_id_fw(struct ixgbe_hw *hw)
{
u32 info[FW_PHY_ACT_DATA_COUNT] = { 0 };
u16 phy_speeds;
u16 phy_id_lo;
s32 rc;
u16 i;
if (hw->phy.id)
return 0;
rc = ixgbe_fw_phy_activity(hw, FW_PHY_ACT_GET_PHY_INFO, &info);
if (rc)
return rc;
hw->phy.speeds_supported = 0;
phy_speeds = info[0] & FW_PHY_INFO_SPEED_MASK;
for (i = 0; i < ARRAY_SIZE(ixgbe_fw_map); ++i) {
if (phy_speeds & ixgbe_fw_map[i].fw_speed)
hw->phy.speeds_supported |= ixgbe_fw_map[i].phy_speed;
}
hw->phy.id = info[0] & FW_PHY_INFO_ID_HI_MASK;
phy_id_lo = info[1] & FW_PHY_INFO_ID_LO_MASK;
hw->phy.id |= phy_id_lo & IXGBE_PHY_REVISION_MASK;
hw->phy.revision = phy_id_lo & ~IXGBE_PHY_REVISION_MASK;
if (!hw->phy.id || hw->phy.id == IXGBE_PHY_REVISION_MASK)
return IXGBE_ERR_PHY_ADDR_INVALID;
hw->phy.autoneg_advertised = hw->phy.speeds_supported;
hw->phy.eee_speeds_supported = IXGBE_LINK_SPEED_100_FULL |
IXGBE_LINK_SPEED_1GB_FULL;
hw->phy.eee_speeds_advertised = hw->phy.eee_speeds_supported;
return 0;
}
static s32 ixgbe_identify_phy_fw(struct ixgbe_hw *hw)
{
if (hw->bus.lan_id)
hw->phy.phy_semaphore_mask = IXGBE_GSSR_PHY1_SM;
else
hw->phy.phy_semaphore_mask = IXGBE_GSSR_PHY0_SM;
hw->phy.type = ixgbe_phy_fw;
hw->phy.ops.read_reg = NULL;
hw->phy.ops.write_reg = NULL;
return ixgbe_get_phy_id_fw(hw);
}
static s32 ixgbe_shutdown_fw_phy(struct ixgbe_hw *hw)
{
u32 setup[FW_PHY_ACT_DATA_COUNT] = { 0 };
setup[0] = FW_PHY_ACT_FORCE_LINK_DOWN_OFF;
return ixgbe_fw_phy_activity(hw, FW_PHY_ACT_FORCE_LINK_DOWN, &setup);
}
static s32 ixgbe_setup_fw_link(struct ixgbe_hw *hw)
{
u32 setup[FW_PHY_ACT_DATA_COUNT] = { 0 };
s32 rc;
u16 i;
if (hw->phy.reset_disable || ixgbe_check_reset_blocked(hw))
return 0;
if (hw->fc.strict_ieee && hw->fc.requested_mode == ixgbe_fc_rx_pause) {
hw_err(hw, "rx_pause not valid in strict IEEE mode\n");
return IXGBE_ERR_INVALID_LINK_SETTINGS;
}
switch (hw->fc.requested_mode) {
case ixgbe_fc_full:
setup[0] |= FW_PHY_ACT_SETUP_LINK_PAUSE_RXTX <<
FW_PHY_ACT_SETUP_LINK_PAUSE_SHIFT;
break;
case ixgbe_fc_rx_pause:
setup[0] |= FW_PHY_ACT_SETUP_LINK_PAUSE_RX <<
FW_PHY_ACT_SETUP_LINK_PAUSE_SHIFT;
break;
case ixgbe_fc_tx_pause:
setup[0] |= FW_PHY_ACT_SETUP_LINK_PAUSE_TX <<
FW_PHY_ACT_SETUP_LINK_PAUSE_SHIFT;
break;
default:
break;
}
for (i = 0; i < ARRAY_SIZE(ixgbe_fw_map); ++i) {
if (hw->phy.autoneg_advertised & ixgbe_fw_map[i].phy_speed)
setup[0] |= ixgbe_fw_map[i].fw_speed;
}
setup[0] |= FW_PHY_ACT_SETUP_LINK_HP | FW_PHY_ACT_SETUP_LINK_AN;
if (hw->phy.eee_speeds_advertised)
setup[0] |= FW_PHY_ACT_SETUP_LINK_EEE;
rc = ixgbe_fw_phy_activity(hw, FW_PHY_ACT_SETUP_LINK, &setup);
if (rc)
return rc;
if (setup[0] == FW_PHY_ACT_SETUP_LINK_RSP_DOWN)
return IXGBE_ERR_OVERTEMP;
return 0;
}
static s32 ixgbe_fc_autoneg_fw(struct ixgbe_hw *hw)
{
if (hw->fc.requested_mode == ixgbe_fc_default)
hw->fc.requested_mode = ixgbe_fc_full;
return ixgbe_setup_fw_link(hw);
}
static s32 ixgbe_init_eeprom_params_X550(struct ixgbe_hw *hw)
{
struct ixgbe_eeprom_info *eeprom = &hw->eeprom;
u32 eec;
u16 eeprom_size;
if (eeprom->type == ixgbe_eeprom_uninitialized) {
eeprom->semaphore_delay = 10;
eeprom->type = ixgbe_flash;
eec = IXGBE_READ_REG(hw, IXGBE_EEC(hw));
eeprom_size = (u16)((eec & IXGBE_EEC_SIZE) >>
IXGBE_EEC_SIZE_SHIFT);
eeprom->word_size = BIT(eeprom_size +
IXGBE_EEPROM_WORD_SIZE_SHIFT);
hw_dbg(hw, "Eeprom params: type = %d, size = %d\n",
eeprom->type, eeprom->word_size);
}
return 0;
}
static s32 ixgbe_iosf_wait(struct ixgbe_hw *hw, u32 *ctrl)
{
u32 i, command;
for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
command = IXGBE_READ_REG(hw, IXGBE_SB_IOSF_INDIRECT_CTRL);
if (!(command & IXGBE_SB_IOSF_CTRL_BUSY))
break;
udelay(10);
}
if (ctrl)
*ctrl = command;
if (i == IXGBE_MDIO_COMMAND_TIMEOUT) {
hw_dbg(hw, "IOSF wait timed out\n");
return IXGBE_ERR_PHY;
}
return 0;
}
static s32 ixgbe_read_iosf_sb_reg_x550(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u32 *data)
{
u32 gssr = IXGBE_GSSR_PHY1_SM | IXGBE_GSSR_PHY0_SM;
u32 command, error;
s32 ret;
ret = hw->mac.ops.acquire_swfw_sync(hw, gssr);
if (ret)
return ret;
ret = ixgbe_iosf_wait(hw, NULL);
if (ret)
goto out;
command = ((reg_addr << IXGBE_SB_IOSF_CTRL_ADDR_SHIFT) |
(device_type << IXGBE_SB_IOSF_CTRL_TARGET_SELECT_SHIFT));
IXGBE_WRITE_REG(hw, IXGBE_SB_IOSF_INDIRECT_CTRL, command);
ret = ixgbe_iosf_wait(hw, &command);
if ((command & IXGBE_SB_IOSF_CTRL_RESP_STAT_MASK) != 0) {
error = (command & IXGBE_SB_IOSF_CTRL_CMPL_ERR_MASK) >>
IXGBE_SB_IOSF_CTRL_CMPL_ERR_SHIFT;
hw_dbg(hw, "Failed to read, error %x\n", error);
return IXGBE_ERR_PHY;
}
if (!ret)
*data = IXGBE_READ_REG(hw, IXGBE_SB_IOSF_INDIRECT_DATA);
out:
hw->mac.ops.release_swfw_sync(hw, gssr);
return ret;
}
static s32 ixgbe_get_phy_token(struct ixgbe_hw *hw)
{
struct ixgbe_hic_phy_token_req token_cmd;
s32 status;
token_cmd.hdr.cmd = FW_PHY_TOKEN_REQ_CMD;
token_cmd.hdr.buf_len = FW_PHY_TOKEN_REQ_LEN;
token_cmd.hdr.cmd_or_resp.cmd_resv = 0;
token_cmd.hdr.checksum = FW_DEFAULT_CHECKSUM;
token_cmd.port_number = hw->bus.lan_id;
token_cmd.command_type = FW_PHY_TOKEN_REQ;
token_cmd.pad = 0;
status = ixgbe_host_interface_command(hw, &token_cmd, sizeof(token_cmd),
IXGBE_HI_COMMAND_TIMEOUT,
true);
if (status)
return status;
if (token_cmd.hdr.cmd_or_resp.ret_status == FW_PHY_TOKEN_OK)
return 0;
if (token_cmd.hdr.cmd_or_resp.ret_status != FW_PHY_TOKEN_RETRY)
return IXGBE_ERR_FW_RESP_INVALID;
return IXGBE_ERR_TOKEN_RETRY;
}
static s32 ixgbe_put_phy_token(struct ixgbe_hw *hw)
{
struct ixgbe_hic_phy_token_req token_cmd;
s32 status;
token_cmd.hdr.cmd = FW_PHY_TOKEN_REQ_CMD;
token_cmd.hdr.buf_len = FW_PHY_TOKEN_REQ_LEN;
token_cmd.hdr.cmd_or_resp.cmd_resv = 0;
token_cmd.hdr.checksum = FW_DEFAULT_CHECKSUM;
token_cmd.port_number = hw->bus.lan_id;
token_cmd.command_type = FW_PHY_TOKEN_REL;
token_cmd.pad = 0;
status = ixgbe_host_interface_command(hw, &token_cmd, sizeof(token_cmd),
IXGBE_HI_COMMAND_TIMEOUT,
true);
if (status)
return status;
if (token_cmd.hdr.cmd_or_resp.ret_status == FW_PHY_TOKEN_OK)
return 0;
return IXGBE_ERR_FW_RESP_INVALID;
}
static s32 ixgbe_write_iosf_sb_reg_x550a(struct ixgbe_hw *hw, u32 reg_addr,
__always_unused u32 device_type,
u32 data)
{
struct ixgbe_hic_internal_phy_req write_cmd;
memset(&write_cmd, 0, sizeof(write_cmd));
write_cmd.hdr.cmd = FW_INT_PHY_REQ_CMD;
write_cmd.hdr.buf_len = FW_INT_PHY_REQ_LEN;
write_cmd.hdr.checksum = FW_DEFAULT_CHECKSUM;
write_cmd.port_number = hw->bus.lan_id;
write_cmd.command_type = FW_INT_PHY_REQ_WRITE;
write_cmd.address = cpu_to_be16(reg_addr);
write_cmd.write_data = cpu_to_be32(data);
return ixgbe_host_interface_command(hw, &write_cmd, sizeof(write_cmd),
IXGBE_HI_COMMAND_TIMEOUT, false);
}
static s32 ixgbe_read_iosf_sb_reg_x550a(struct ixgbe_hw *hw, u32 reg_addr,
__always_unused u32 device_type,
u32 *data)
{
union {
struct ixgbe_hic_internal_phy_req cmd;
struct ixgbe_hic_internal_phy_resp rsp;
} hic;
s32 status;
memset(&hic, 0, sizeof(hic));
hic.cmd.hdr.cmd = FW_INT_PHY_REQ_CMD;
hic.cmd.hdr.buf_len = FW_INT_PHY_REQ_LEN;
hic.cmd.hdr.checksum = FW_DEFAULT_CHECKSUM;
hic.cmd.port_number = hw->bus.lan_id;
hic.cmd.command_type = FW_INT_PHY_REQ_READ;
hic.cmd.address = cpu_to_be16(reg_addr);
status = ixgbe_host_interface_command(hw, &hic.cmd, sizeof(hic.cmd),
IXGBE_HI_COMMAND_TIMEOUT, true);
*data = be32_to_cpu(hic.rsp.read_data);
return status;
}
static s32 ixgbe_read_ee_hostif_buffer_X550(struct ixgbe_hw *hw,
u16 offset, u16 words, u16 *data)
{
const u32 mask = IXGBE_GSSR_SW_MNG_SM | IXGBE_GSSR_EEP_SM;
struct ixgbe_hic_read_shadow_ram buffer;
u32 current_word = 0;
u16 words_to_read;
s32 status;
u32 i;
status = hw->mac.ops.acquire_swfw_sync(hw, mask);
if (status) {
hw_dbg(hw, "EEPROM read buffer - semaphore failed\n");
return status;
}
while (words) {
if (words > FW_MAX_READ_BUFFER_SIZE / 2)
words_to_read = FW_MAX_READ_BUFFER_SIZE / 2;
else
words_to_read = words;
buffer.hdr.req.cmd = FW_READ_SHADOW_RAM_CMD;
buffer.hdr.req.buf_lenh = 0;
buffer.hdr.req.buf_lenl = FW_READ_SHADOW_RAM_LEN;
buffer.hdr.req.checksum = FW_DEFAULT_CHECKSUM;
buffer.address = cpu_to_be32((offset + current_word) * 2);
buffer.length = cpu_to_be16(words_to_read * 2);
status = ixgbe_hic_unlocked(hw, (u32 *)&buffer, sizeof(buffer),
IXGBE_HI_COMMAND_TIMEOUT);
if (status) {
hw_dbg(hw, "Host interface command failed\n");
goto out;
}
for (i = 0; i < words_to_read; i++) {
u32 reg = IXGBE_FLEX_MNG + (FW_NVM_DATA_OFFSET << 2) +
2 * i;
u32 value = IXGBE_READ_REG(hw, reg);
data[current_word] = (u16)(value & 0xffff);
current_word++;
i++;
if (i < words_to_read) {
value >>= 16;
data[current_word] = (u16)(value & 0xffff);
current_word++;
}
}
words -= words_to_read;
}
out:
hw->mac.ops.release_swfw_sync(hw, mask);
return status;
}
static s32 ixgbe_checksum_ptr_x550(struct ixgbe_hw *hw, u16 ptr,
u16 size, u16 *csum, u16 *buffer,
u32 buffer_size)
{
u16 buf[256];
s32 status;
u16 length, bufsz, i, start;
u16 *local_buffer;
bufsz = sizeof(buf) / sizeof(buf[0]);
if (!buffer) {
status = ixgbe_read_ee_hostif_buffer_X550(hw, ptr, bufsz, buf);
if (status) {
hw_dbg(hw, "Failed to read EEPROM image\n");
return status;
}
local_buffer = buf;
} else {
if (buffer_size < ptr)
return IXGBE_ERR_PARAM;
local_buffer = &buffer[ptr];
}
if (size) {
start = 0;
length = size;
} else {
start = 1;
length = local_buffer[0];
if (length == 0xFFFF || length == 0 ||
(ptr + length) >= hw->eeprom.word_size)
return 0;
}
if (buffer && ((u32)start + (u32)length > buffer_size))
return IXGBE_ERR_PARAM;
for (i = start; length; i++, length--) {
if (i == bufsz && !buffer) {
ptr += bufsz;
i = 0;
if (length < bufsz)
bufsz = length;
status = ixgbe_read_ee_hostif_buffer_X550(hw, ptr,
bufsz, buf);
if (status) {
hw_dbg(hw, "Failed to read EEPROM image\n");
return status;
}
}
*csum += local_buffer[i];
}
return 0;
}
static s32 ixgbe_calc_checksum_X550(struct ixgbe_hw *hw, u16 *buffer,
u32 buffer_size)
{
u16 eeprom_ptrs[IXGBE_EEPROM_LAST_WORD + 1];
u16 *local_buffer;
s32 status;
u16 checksum = 0;
u16 pointer, i, size;
hw->eeprom.ops.init_params(hw);
if (!buffer) {
status = ixgbe_read_ee_hostif_buffer_X550(hw, 0,
IXGBE_EEPROM_LAST_WORD + 1,
eeprom_ptrs);
if (status) {
hw_dbg(hw, "Failed to read EEPROM image\n");
return status;
}
local_buffer = eeprom_ptrs;
} else {
if (buffer_size < IXGBE_EEPROM_LAST_WORD)
return IXGBE_ERR_PARAM;
local_buffer = buffer;
}
for (i = 0; i <= IXGBE_EEPROM_LAST_WORD; i++)
if (i != IXGBE_EEPROM_CHECKSUM)
checksum += local_buffer[i];
for (i = IXGBE_PCIE_ANALOG_PTR_X550; i < IXGBE_FW_PTR; i++) {
if (i == IXGBE_PHY_PTR || i == IXGBE_OPTION_ROM_PTR)
continue;
pointer = local_buffer[i];
if (pointer == 0xFFFF || pointer == 0 ||
pointer >= hw->eeprom.word_size)
continue;
switch (i) {
case IXGBE_PCIE_GENERAL_PTR:
size = IXGBE_IXGBE_PCIE_GENERAL_SIZE;
break;
case IXGBE_PCIE_CONFIG0_PTR:
case IXGBE_PCIE_CONFIG1_PTR:
size = IXGBE_PCIE_CONFIG_SIZE;
break;
default:
size = 0;
break;
}
status = ixgbe_checksum_ptr_x550(hw, pointer, size, &checksum,
buffer, buffer_size);
if (status)
return status;
}
checksum = (u16)IXGBE_EEPROM_SUM - checksum;
return (s32)checksum;
}
static s32 ixgbe_calc_eeprom_checksum_X550(struct ixgbe_hw *hw)
{
return ixgbe_calc_checksum_X550(hw, NULL, 0);
}
static s32 ixgbe_read_ee_hostif_X550(struct ixgbe_hw *hw, u16 offset, u16 *data)
{
const u32 mask = IXGBE_GSSR_SW_MNG_SM | IXGBE_GSSR_EEP_SM;
struct ixgbe_hic_read_shadow_ram buffer;
s32 status;
buffer.hdr.req.cmd = FW_READ_SHADOW_RAM_CMD;
buffer.hdr.req.buf_lenh = 0;
buffer.hdr.req.buf_lenl = FW_READ_SHADOW_RAM_LEN;
buffer.hdr.req.checksum = FW_DEFAULT_CHECKSUM;
buffer.address = cpu_to_be32(offset * 2);
buffer.length = cpu_to_be16(sizeof(u16));
status = hw->mac.ops.acquire_swfw_sync(hw, mask);
if (status)
return status;
status = ixgbe_hic_unlocked(hw, (u32 *)&buffer, sizeof(buffer),
IXGBE_HI_COMMAND_TIMEOUT);
if (!status) {
*data = (u16)IXGBE_READ_REG_ARRAY(hw, IXGBE_FLEX_MNG,
FW_NVM_DATA_OFFSET);
}
hw->mac.ops.release_swfw_sync(hw, mask);
return status;
}
static s32 ixgbe_validate_eeprom_checksum_X550(struct ixgbe_hw *hw,
u16 *checksum_val)
{
s32 status;
u16 checksum;
u16 read_checksum = 0;
status = hw->eeprom.ops.read(hw, 0, &checksum);
if (status) {
hw_dbg(hw, "EEPROM read failed\n");
return status;
}
status = hw->eeprom.ops.calc_checksum(hw);
if (status < 0)
return status;
checksum = (u16)(status & 0xffff);
status = ixgbe_read_ee_hostif_X550(hw, IXGBE_EEPROM_CHECKSUM,
&read_checksum);
if (status)
return status;
if (read_checksum != checksum) {
status = IXGBE_ERR_EEPROM_CHECKSUM;
hw_dbg(hw, "Invalid EEPROM checksum");
}
if (checksum_val)
*checksum_val = checksum;
return status;
}
static s32 ixgbe_write_ee_hostif_data_X550(struct ixgbe_hw *hw, u16 offset,
u16 data)
{
s32 status;
struct ixgbe_hic_write_shadow_ram buffer;
buffer.hdr.req.cmd = FW_WRITE_SHADOW_RAM_CMD;
buffer.hdr.req.buf_lenh = 0;
buffer.hdr.req.buf_lenl = FW_WRITE_SHADOW_RAM_LEN;
buffer.hdr.req.checksum = FW_DEFAULT_CHECKSUM;
buffer.length = cpu_to_be16(sizeof(u16));
buffer.data = data;
buffer.address = cpu_to_be32(offset * 2);
status = ixgbe_host_interface_command(hw, &buffer, sizeof(buffer),
IXGBE_HI_COMMAND_TIMEOUT, false);
return status;
}
static s32 ixgbe_write_ee_hostif_X550(struct ixgbe_hw *hw, u16 offset, u16 data)
{
s32 status = 0;
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM) == 0) {
status = ixgbe_write_ee_hostif_data_X550(hw, offset, data);
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
} else {
hw_dbg(hw, "write ee hostif failed to get semaphore");
status = IXGBE_ERR_SWFW_SYNC;
}
return status;
}
static s32 ixgbe_update_flash_X550(struct ixgbe_hw *hw)
{
s32 status = 0;
union ixgbe_hic_hdr2 buffer;
buffer.req.cmd = FW_SHADOW_RAM_DUMP_CMD;
buffer.req.buf_lenh = 0;
buffer.req.buf_lenl = FW_SHADOW_RAM_DUMP_LEN;
buffer.req.checksum = FW_DEFAULT_CHECKSUM;
status = ixgbe_host_interface_command(hw, &buffer, sizeof(buffer),
IXGBE_HI_COMMAND_TIMEOUT, false);
return status;
}
static s32 ixgbe_get_bus_info_X550em(struct ixgbe_hw *hw)
{
hw->bus.type = ixgbe_bus_type_internal;
hw->bus.width = ixgbe_bus_width_unknown;
hw->bus.speed = ixgbe_bus_speed_unknown;
hw->mac.ops.set_lan_id(hw);
return 0;
}
static void ixgbe_disable_rx_x550(struct ixgbe_hw *hw)
{
u32 rxctrl, pfdtxgswc;
s32 status;
struct ixgbe_hic_disable_rxen fw_cmd;
rxctrl = IXGBE_READ_REG(hw, IXGBE_RXCTRL);
if (rxctrl & IXGBE_RXCTRL_RXEN) {
pfdtxgswc = IXGBE_READ_REG(hw, IXGBE_PFDTXGSWC);
if (pfdtxgswc & IXGBE_PFDTXGSWC_VT_LBEN) {
pfdtxgswc &= ~IXGBE_PFDTXGSWC_VT_LBEN;
IXGBE_WRITE_REG(hw, IXGBE_PFDTXGSWC, pfdtxgswc);
hw->mac.set_lben = true;
} else {
hw->mac.set_lben = false;
}
fw_cmd.hdr.cmd = FW_DISABLE_RXEN_CMD;
fw_cmd.hdr.buf_len = FW_DISABLE_RXEN_LEN;
fw_cmd.hdr.checksum = FW_DEFAULT_CHECKSUM;
fw_cmd.port_number = hw->bus.lan_id;
status = ixgbe_host_interface_command(hw, &fw_cmd,
sizeof(struct ixgbe_hic_disable_rxen),
IXGBE_HI_COMMAND_TIMEOUT, true);
if (status) {
rxctrl = IXGBE_READ_REG(hw, IXGBE_RXCTRL);
if (rxctrl & IXGBE_RXCTRL_RXEN) {
rxctrl &= ~IXGBE_RXCTRL_RXEN;
IXGBE_WRITE_REG(hw, IXGBE_RXCTRL, rxctrl);
}
}
}
}
static s32 ixgbe_update_eeprom_checksum_X550(struct ixgbe_hw *hw)
{
s32 status;
u16 checksum = 0;
status = ixgbe_read_ee_hostif_X550(hw, 0, &checksum);
if (status) {
hw_dbg(hw, "EEPROM read failed\n");
return status;
}
status = ixgbe_calc_eeprom_checksum_X550(hw);
if (status < 0)
return status;
checksum = (u16)(status & 0xffff);
status = ixgbe_write_ee_hostif_X550(hw, IXGBE_EEPROM_CHECKSUM,
checksum);
if (status)
return status;
status = ixgbe_update_flash_X550(hw);
return status;
}
static s32 ixgbe_write_ee_hostif_buffer_X550(struct ixgbe_hw *hw,
u16 offset, u16 words,
u16 *data)
{
s32 status = 0;
u32 i = 0;
status = hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
if (status) {
hw_dbg(hw, "EEPROM write buffer - semaphore failed\n");
return status;
}
for (i = 0; i < words; i++) {
status = ixgbe_write_ee_hostif_data_X550(hw, offset + i,
data[i]);
if (status) {
hw_dbg(hw, "Eeprom buffered write failed\n");
break;
}
}
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
return status;
}
static s32 ixgbe_write_iosf_sb_reg_x550(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u32 data)
{
u32 gssr = IXGBE_GSSR_PHY1_SM | IXGBE_GSSR_PHY0_SM;
u32 command, error;
s32 ret;
ret = hw->mac.ops.acquire_swfw_sync(hw, gssr);
if (ret)
return ret;
ret = ixgbe_iosf_wait(hw, NULL);
if (ret)
goto out;
command = ((reg_addr << IXGBE_SB_IOSF_CTRL_ADDR_SHIFT) |
(device_type << IXGBE_SB_IOSF_CTRL_TARGET_SELECT_SHIFT));
IXGBE_WRITE_REG(hw, IXGBE_SB_IOSF_INDIRECT_CTRL, command);
IXGBE_WRITE_REG(hw, IXGBE_SB_IOSF_INDIRECT_DATA, data);
ret = ixgbe_iosf_wait(hw, &command);
if ((command & IXGBE_SB_IOSF_CTRL_RESP_STAT_MASK) != 0) {
error = (command & IXGBE_SB_IOSF_CTRL_CMPL_ERR_MASK) >>
IXGBE_SB_IOSF_CTRL_CMPL_ERR_SHIFT;
hw_dbg(hw, "Failed to write, error %x\n", error);
return IXGBE_ERR_PHY;
}
out:
hw->mac.ops.release_swfw_sync(hw, gssr);
return ret;
}
static s32 ixgbe_setup_ixfi_x550em_x(struct ixgbe_hw *hw)
{
s32 status;
u32 reg_val;
status = ixgbe_read_iosf_sb_reg_x550(hw,
IXGBE_KRM_RX_TRN_LINKUP_CTRL(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val |= IXGBE_KRM_RX_TRN_LINKUP_CTRL_CONV_WO_PROTOCOL;
status = ixgbe_write_iosf_sb_reg_x550(hw,
IXGBE_KRM_RX_TRN_LINKUP_CTRL(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
if (status)
return status;
status = ixgbe_read_iosf_sb_reg_x550(hw,
IXGBE_KRM_DSP_TXFFE_STATE_4(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val &= ~IXGBE_KRM_DSP_TXFFE_STATE_C0_EN;
reg_val &= ~IXGBE_KRM_DSP_TXFFE_STATE_CP1_CN1_EN;
reg_val &= ~IXGBE_KRM_DSP_TXFFE_STATE_CO_ADAPT_EN;
status = ixgbe_write_iosf_sb_reg_x550(hw,
IXGBE_KRM_DSP_TXFFE_STATE_4(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
if (status)
return status;
status = ixgbe_read_iosf_sb_reg_x550(hw,
IXGBE_KRM_DSP_TXFFE_STATE_5(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val &= ~IXGBE_KRM_DSP_TXFFE_STATE_C0_EN;
reg_val &= ~IXGBE_KRM_DSP_TXFFE_STATE_CP1_CN1_EN;
reg_val &= ~IXGBE_KRM_DSP_TXFFE_STATE_CO_ADAPT_EN;
status = ixgbe_write_iosf_sb_reg_x550(hw,
IXGBE_KRM_DSP_TXFFE_STATE_5(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
if (status)
return status;
status = ixgbe_read_iosf_sb_reg_x550(hw,
IXGBE_KRM_TX_COEFF_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val |= IXGBE_KRM_TX_COEFF_CTRL_1_OVRRD_EN;
reg_val |= IXGBE_KRM_TX_COEFF_CTRL_1_CZERO_EN;
reg_val |= IXGBE_KRM_TX_COEFF_CTRL_1_CPLUS1_OVRRD_EN;
reg_val |= IXGBE_KRM_TX_COEFF_CTRL_1_CMINUS1_OVRRD_EN;
status = ixgbe_write_iosf_sb_reg_x550(hw,
IXGBE_KRM_TX_COEFF_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
return status;
}
static s32 ixgbe_restart_an_internal_phy_x550em(struct ixgbe_hw *hw)
{
s32 status;
u32 link_ctrl;
status = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &link_ctrl);
if (status) {
hw_dbg(hw, "Auto-negotiation did not complete\n");
return status;
}
link_ctrl |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_RESTART;
status = hw->mac.ops.write_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, link_ctrl);
if (hw->mac.type == ixgbe_mac_x550em_a) {
u32 flx_mask_st20;
status = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &flx_mask_st20);
if (status) {
hw_dbg(hw, "Auto-negotiation did not complete\n");
return status;
}
flx_mask_st20 |= IXGBE_KRM_PMD_FLX_MASK_ST20_FW_AN_RESTART;
status = hw->mac.ops.write_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, flx_mask_st20);
}
return status;
}
static s32 ixgbe_setup_ixfi_x550em(struct ixgbe_hw *hw, ixgbe_link_speed *speed)
{
struct ixgbe_mac_info *mac = &hw->mac;
s32 status;
u32 reg_val;
if (mac->type != ixgbe_mac_X550EM_x)
return IXGBE_ERR_LINK_SETUP;
status = ixgbe_read_iosf_sb_reg_x550(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val &= ~IXGBE_KRM_LINK_CTRL_1_TETH_AN_ENABLE;
reg_val &= ~IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_MASK;
switch (*speed) {
case IXGBE_LINK_SPEED_10GB_FULL:
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_10G;
break;
case IXGBE_LINK_SPEED_1GB_FULL:
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_1G;
break;
default:
return IXGBE_ERR_LINK_SETUP;
}
status = ixgbe_write_iosf_sb_reg_x550(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
if (status)
return status;
if (hw->mac.type == ixgbe_mac_X550EM_x) {
status = ixgbe_setup_ixfi_x550em_x(hw);
if (status)
return status;
}
status = ixgbe_restart_an_internal_phy_x550em(hw);
return status;
}
static s32 ixgbe_supported_sfp_modules_X550em(struct ixgbe_hw *hw, bool *linear)
{
switch (hw->phy.sfp_type) {
case ixgbe_sfp_type_not_present:
return IXGBE_ERR_SFP_NOT_PRESENT;
case ixgbe_sfp_type_da_cu_core0:
case ixgbe_sfp_type_da_cu_core1:
*linear = true;
break;
case ixgbe_sfp_type_srlr_core0:
case ixgbe_sfp_type_srlr_core1:
case ixgbe_sfp_type_da_act_lmt_core0:
case ixgbe_sfp_type_da_act_lmt_core1:
case ixgbe_sfp_type_1g_sx_core0:
case ixgbe_sfp_type_1g_sx_core1:
case ixgbe_sfp_type_1g_lx_core0:
case ixgbe_sfp_type_1g_lx_core1:
*linear = false;
break;
case ixgbe_sfp_type_unknown:
case ixgbe_sfp_type_1g_cu_core0:
case ixgbe_sfp_type_1g_cu_core1:
default:
return IXGBE_ERR_SFP_NOT_SUPPORTED;
}
return 0;
}
static s32
ixgbe_setup_mac_link_sfp_x550em(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
__always_unused bool autoneg_wait_to_complete)
{
s32 status;
u16 reg_slice, reg_val;
bool setup_linear = false;
status = ixgbe_supported_sfp_modules_X550em(hw, &setup_linear);
if (status == IXGBE_ERR_SFP_NOT_PRESENT)
return 0;
if (status)
return status;
ixgbe_setup_kr_speed_x550em(hw, speed);
reg_slice = IXGBE_CS4227_LINE_SPARE24_LSB + (hw->bus.lan_id << 12);
if (setup_linear)
reg_val = (IXGBE_CS4227_EDC_MODE_CX1 << 1) | 0x1;
else
reg_val = (IXGBE_CS4227_EDC_MODE_SR << 1) | 0x1;
status = hw->link.ops.write_link(hw, hw->link.addr, reg_slice,
reg_val);
return status;
}
static s32 ixgbe_setup_sfi_x550a(struct ixgbe_hw *hw, ixgbe_link_speed *speed)
{
struct ixgbe_mac_info *mac = &hw->mac;
s32 status;
u32 reg_val;
status = mac->ops.read_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_AN_EN;
reg_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_AN37_EN;
reg_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_SGMII_EN;
reg_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_MASK;
switch (*speed) {
case IXGBE_LINK_SPEED_10GB_FULL:
reg_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_10G;
break;
case IXGBE_LINK_SPEED_1GB_FULL:
reg_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_1G;
break;
default:
return IXGBE_ERR_LINK_SETUP;
}
status = mac->ops.write_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
status = ixgbe_restart_an_internal_phy_x550em(hw);
return status;
}
static s32
ixgbe_setup_mac_link_sfp_n(struct ixgbe_hw *hw, ixgbe_link_speed speed,
__always_unused bool autoneg_wait_to_complete)
{
bool setup_linear = false;
u32 reg_phy_int;
s32 ret_val;
ret_val = ixgbe_supported_sfp_modules_X550em(hw, &setup_linear);
if (ret_val == IXGBE_ERR_SFP_NOT_PRESENT)
return 0;
if (ret_val)
return ret_val;
ret_val = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_phy_int);
if (ret_val)
return ret_val;
reg_phy_int &= IXGBE_KRM_PMD_FLX_MASK_ST20_SFI_10G_DA;
if (!setup_linear)
reg_phy_int |= IXGBE_KRM_PMD_FLX_MASK_ST20_SFI_10G_SR;
ret_val = hw->mac.ops.write_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_phy_int);
if (ret_val)
return ret_val;
return ixgbe_setup_sfi_x550a(hw, &speed);
}
static s32
ixgbe_setup_mac_link_sfp_x550a(struct ixgbe_hw *hw, ixgbe_link_speed speed,
__always_unused bool autoneg_wait_to_complete)
{
u32 reg_slice, slice_offset;
bool setup_linear = false;
u16 reg_phy_ext;
s32 ret_val;
ret_val = ixgbe_supported_sfp_modules_X550em(hw, &setup_linear);
if (ret_val == IXGBE_ERR_SFP_NOT_PRESENT)
return 0;
if (ret_val)
return ret_val;
ixgbe_setup_kr_speed_x550em(hw, speed);
if (hw->phy.mdio.prtad == MDIO_PRTAD_NONE)
return IXGBE_ERR_PHY_ADDR_INVALID;
ret_val = hw->phy.ops.read_reg(hw, IXGBE_CS4227_EFUSE_PDF_SKU,
IXGBE_MDIO_ZERO_DEV_TYPE, &reg_phy_ext);
if (ret_val)
return ret_val;
if (reg_phy_ext == IXGBE_CS4223_SKU_ID)
slice_offset = (hw->bus.lan_id +
(hw->bus.instance_id << 1)) << 12;
else
slice_offset = hw->bus.lan_id << 12;
reg_slice = IXGBE_CS4227_LINE_SPARE24_LSB + slice_offset;
ret_val = hw->phy.ops.read_reg(hw, reg_slice,
IXGBE_MDIO_ZERO_DEV_TYPE, &reg_phy_ext);
if (ret_val)
return ret_val;
reg_phy_ext &= ~((IXGBE_CS4227_EDC_MODE_CX1 << 1) |
(IXGBE_CS4227_EDC_MODE_SR << 1));
if (setup_linear)
reg_phy_ext = (IXGBE_CS4227_EDC_MODE_CX1 << 1) | 1;
else
reg_phy_ext = (IXGBE_CS4227_EDC_MODE_SR << 1) | 1;
ret_val = hw->phy.ops.write_reg(hw, reg_slice,
IXGBE_MDIO_ZERO_DEV_TYPE, reg_phy_ext);
if (ret_val)
return ret_val;
return hw->phy.ops.read_reg(hw, reg_slice,
IXGBE_MDIO_ZERO_DEV_TYPE, &reg_phy_ext);
}
static s32 ixgbe_setup_mac_link_t_X550em(struct ixgbe_hw *hw,
ixgbe_link_speed speed,
bool autoneg_wait)
{
s32 status;
ixgbe_link_speed force_speed;
if (speed & IXGBE_LINK_SPEED_10GB_FULL)
force_speed = IXGBE_LINK_SPEED_10GB_FULL;
else
force_speed = IXGBE_LINK_SPEED_1GB_FULL;
if (hw->mac.type == ixgbe_mac_X550EM_x &&
!(hw->phy.nw_mng_if_sel & IXGBE_NW_MNG_IF_SEL_INT_PHY_MODE)) {
status = ixgbe_setup_ixfi_x550em(hw, &force_speed);
if (status)
return status;
}
return hw->phy.ops.setup_link_speed(hw, speed, autoneg_wait);
}
static s32 ixgbe_check_link_t_X550em(struct ixgbe_hw *hw,
ixgbe_link_speed *speed,
bool *link_up,
bool link_up_wait_to_complete)
{
u32 status;
u16 i, autoneg_status;
if (hw->mac.ops.get_media_type(hw) != ixgbe_media_type_copper)
return IXGBE_ERR_CONFIG;
status = ixgbe_check_mac_link_generic(hw, speed, link_up,
link_up_wait_to_complete);
if (status || !(*link_up))
return status;
for (i = 0; i < 2; i++) {
status = hw->phy.ops.read_reg(hw, MDIO_STAT1, MDIO_MMD_AN,
&autoneg_status);
if (status)
return status;
}
if (!(autoneg_status & IXGBE_MDIO_AUTO_NEG_LINK_STATUS))
*link_up = false;
return 0;
}
static s32
ixgbe_setup_sgmii(struct ixgbe_hw *hw, __always_unused ixgbe_link_speed speed,
__always_unused bool autoneg_wait_to_complete)
{
struct ixgbe_mac_info *mac = &hw->mac;
u32 lval, sval, flx_val;
s32 rc;
rc = mac->ops.read_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &lval);
if (rc)
return rc;
lval &= ~IXGBE_KRM_LINK_CTRL_1_TETH_AN_ENABLE;
lval &= ~IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_MASK;
lval |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_SGMII_EN;
lval |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CLAUSE_37_EN;
lval |= IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_1G;
rc = mac->ops.write_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, lval);
if (rc)
return rc;
rc = mac->ops.read_iosf_sb_reg(hw,
IXGBE_KRM_SGMII_CTRL(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &sval);
if (rc)
return rc;
sval |= IXGBE_KRM_SGMII_CTRL_MAC_TAR_FORCE_10_D;
sval |= IXGBE_KRM_SGMII_CTRL_MAC_TAR_FORCE_100_D;
rc = mac->ops.write_iosf_sb_reg(hw,
IXGBE_KRM_SGMII_CTRL(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, sval);
if (rc)
return rc;
rc = mac->ops.read_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &flx_val);
if (rc)
return rc;
rc = mac->ops.read_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &flx_val);
if (rc)
return rc;
flx_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_MASK;
flx_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_1G;
flx_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_AN_EN;
flx_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_SGMII_EN;
flx_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_AN37_EN;
rc = mac->ops.write_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, flx_val);
if (rc)
return rc;
rc = ixgbe_restart_an_internal_phy_x550em(hw);
return rc;
}
static s32 ixgbe_setup_sgmii_fw(struct ixgbe_hw *hw, ixgbe_link_speed speed,
bool autoneg_wait)
{
struct ixgbe_mac_info *mac = &hw->mac;
u32 lval, sval, flx_val;
s32 rc;
rc = mac->ops.read_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &lval);
if (rc)
return rc;
lval &= ~IXGBE_KRM_LINK_CTRL_1_TETH_AN_ENABLE;
lval &= ~IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_MASK;
lval |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_SGMII_EN;
lval |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CLAUSE_37_EN;
lval &= ~IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_1G;
rc = mac->ops.write_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, lval);
if (rc)
return rc;
rc = mac->ops.read_iosf_sb_reg(hw,
IXGBE_KRM_SGMII_CTRL(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &sval);
if (rc)
return rc;
sval &= ~IXGBE_KRM_SGMII_CTRL_MAC_TAR_FORCE_10_D;
sval &= ~IXGBE_KRM_SGMII_CTRL_MAC_TAR_FORCE_100_D;
rc = mac->ops.write_iosf_sb_reg(hw,
IXGBE_KRM_SGMII_CTRL(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, sval);
if (rc)
return rc;
rc = mac->ops.write_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, lval);
if (rc)
return rc;
rc = mac->ops.read_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &flx_val);
if (rc)
return rc;
flx_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_MASK;
flx_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_AN;
flx_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_AN_EN;
flx_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_SGMII_EN;
flx_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_AN37_EN;
rc = mac->ops.write_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, flx_val);
if (rc)
return rc;
ixgbe_restart_an_internal_phy_x550em(hw);
return hw->phy.ops.setup_link_speed(hw, speed, autoneg_wait);
}
static void ixgbe_fc_autoneg_sgmii_x550em_a(struct ixgbe_hw *hw)
{
s32 status = IXGBE_ERR_FC_NOT_NEGOTIATED;
u32 info[FW_PHY_ACT_DATA_COUNT] = { 0 };
ixgbe_link_speed speed;
bool link_up;
if (hw->fc.disable_fc_autoneg)
goto out;
hw->mac.ops.check_link(hw, &speed, &link_up, false);
if (!link_up)
goto out;
status = ixgbe_fw_phy_activity(hw, FW_PHY_ACT_GET_LINK_INFO, &info);
if (status || !(info[0] & FW_PHY_ACT_GET_LINK_INFO_AN_COMPLETE)) {
status = IXGBE_ERR_FC_NOT_NEGOTIATED;
goto out;
}
status = ixgbe_negotiate_fc(hw, info[0], info[0],
FW_PHY_ACT_GET_LINK_INFO_FC_RX,
FW_PHY_ACT_GET_LINK_INFO_FC_TX,
FW_PHY_ACT_GET_LINK_INFO_LP_FC_RX,
FW_PHY_ACT_GET_LINK_INFO_LP_FC_TX);
out:
if (!status) {
hw->fc.fc_was_autonegged = true;
} else {
hw->fc.fc_was_autonegged = false;
hw->fc.current_mode = hw->fc.requested_mode;
}
}
static void ixgbe_init_mac_link_ops_X550em_a(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
switch (mac->ops.get_media_type(hw)) {
case ixgbe_media_type_fiber:
mac->ops.setup_fc = NULL;
mac->ops.fc_autoneg = ixgbe_fc_autoneg_fiber_x550em_a;
break;
case ixgbe_media_type_copper:
if (hw->device_id != IXGBE_DEV_ID_X550EM_A_1G_T &&
hw->device_id != IXGBE_DEV_ID_X550EM_A_1G_T_L) {
mac->ops.setup_link = ixgbe_setup_mac_link_t_X550em;
break;
}
mac->ops.fc_autoneg = ixgbe_fc_autoneg_sgmii_x550em_a;
mac->ops.setup_fc = ixgbe_fc_autoneg_fw;
mac->ops.setup_link = ixgbe_setup_sgmii_fw;
mac->ops.check_link = ixgbe_check_mac_link_generic;
break;
case ixgbe_media_type_backplane:
mac->ops.fc_autoneg = ixgbe_fc_autoneg_backplane_x550em_a;
mac->ops.setup_fc = ixgbe_setup_fc_backplane_x550em_a;
break;
default:
break;
}
}
static void ixgbe_init_mac_link_ops_X550em(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
mac->ops.setup_fc = ixgbe_setup_fc_x550em;
switch (mac->ops.get_media_type(hw)) {
case ixgbe_media_type_fiber:
mac->ops.disable_tx_laser = NULL;
mac->ops.enable_tx_laser = NULL;
mac->ops.flap_tx_laser = NULL;
mac->ops.setup_link = ixgbe_setup_mac_link_multispeed_fiber;
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_A_SFP_N:
mac->ops.setup_mac_link = ixgbe_setup_mac_link_sfp_n;
break;
case IXGBE_DEV_ID_X550EM_A_SFP:
mac->ops.setup_mac_link =
ixgbe_setup_mac_link_sfp_x550a;
break;
default:
mac->ops.setup_mac_link =
ixgbe_setup_mac_link_sfp_x550em;
break;
}
mac->ops.set_rate_select_speed =
ixgbe_set_soft_rate_select_speed;
break;
case ixgbe_media_type_copper:
if (hw->device_id == IXGBE_DEV_ID_X550EM_X_1G_T)
break;
mac->ops.setup_link = ixgbe_setup_mac_link_t_X550em;
mac->ops.setup_fc = ixgbe_setup_fc_generic;
mac->ops.check_link = ixgbe_check_link_t_X550em;
break;
case ixgbe_media_type_backplane:
if (hw->device_id == IXGBE_DEV_ID_X550EM_A_SGMII ||
hw->device_id == IXGBE_DEV_ID_X550EM_A_SGMII_L)
mac->ops.setup_link = ixgbe_setup_sgmii;
break;
default:
break;
}
if (hw->mac.type == ixgbe_mac_x550em_a)
ixgbe_init_mac_link_ops_X550em_a(hw);
}
static s32 ixgbe_setup_sfp_modules_X550em(struct ixgbe_hw *hw)
{
s32 status;
bool linear;
status = ixgbe_supported_sfp_modules_X550em(hw, &linear);
if (status)
return status;
ixgbe_init_mac_link_ops_X550em(hw);
hw->phy.ops.reset = NULL;
return 0;
}
static s32 ixgbe_get_link_capabilities_X550em(struct ixgbe_hw *hw,
ixgbe_link_speed *speed,
bool *autoneg)
{
if (hw->phy.type == ixgbe_phy_fw) {
*autoneg = true;
*speed = hw->phy.speeds_supported;
return 0;
}
if (hw->phy.media_type == ixgbe_media_type_fiber) {
*autoneg = false;
if (hw->phy.sfp_type == ixgbe_sfp_type_1g_sx_core0 ||
hw->phy.sfp_type == ixgbe_sfp_type_1g_sx_core1) {
*speed = IXGBE_LINK_SPEED_1GB_FULL;
return 0;
}
if (hw->phy.multispeed_fiber)
*speed = IXGBE_LINK_SPEED_10GB_FULL |
IXGBE_LINK_SPEED_1GB_FULL;
else
*speed = IXGBE_LINK_SPEED_10GB_FULL;
} else {
switch (hw->phy.type) {
case ixgbe_phy_x550em_kx4:
*speed = IXGBE_LINK_SPEED_1GB_FULL |
IXGBE_LINK_SPEED_2_5GB_FULL |
IXGBE_LINK_SPEED_10GB_FULL;
break;
case ixgbe_phy_x550em_xfi:
*speed = IXGBE_LINK_SPEED_1GB_FULL |
IXGBE_LINK_SPEED_10GB_FULL;
break;
case ixgbe_phy_ext_1g_t:
case ixgbe_phy_sgmii:
*speed = IXGBE_LINK_SPEED_1GB_FULL;
break;
case ixgbe_phy_x550em_kr:
if (hw->mac.type == ixgbe_mac_x550em_a) {
if (hw->phy.nw_mng_if_sel &
IXGBE_NW_MNG_IF_SEL_PHY_SPEED_2_5G) {
*speed = IXGBE_LINK_SPEED_2_5GB_FULL;
break;
} else if (hw->device_id ==
IXGBE_DEV_ID_X550EM_A_KR_L) {
*speed = IXGBE_LINK_SPEED_1GB_FULL;
break;
}
}
default:
*speed = IXGBE_LINK_SPEED_10GB_FULL |
IXGBE_LINK_SPEED_1GB_FULL;
break;
}
*autoneg = true;
}
return 0;
}
static s32 ixgbe_get_lasi_ext_t_x550em(struct ixgbe_hw *hw, bool *lsc)
{
u32 status;
u16 reg;
*lsc = false;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_CHIP_STD_INT_FLAG,
MDIO_MMD_VEND1,
&reg);
if (status || !(reg & IXGBE_MDIO_GLOBAL_VEN_ALM_INT_EN))
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_VEN_FLAG,
MDIO_MMD_VEND1,
&reg);
if (status || !(reg & (IXGBE_MDIO_GLOBAL_AN_VEN_ALM_INT_EN |
IXGBE_MDIO_GLOBAL_ALARM_1_INT)))
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_ALARM_1,
MDIO_MMD_VEND1,
&reg);
if (status)
return status;
if (reg & IXGBE_MDIO_GLOBAL_ALM_1_HI_TMP_FAIL) {
ixgbe_set_copper_phy_power(hw, false);
return IXGBE_ERR_OVERTEMP;
}
if (reg & IXGBE_MDIO_GLOBAL_ALM_1_DEV_FAULT) {
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_FAULT_MSG,
MDIO_MMD_VEND1,
&reg);
if (status)
return status;
if (reg == IXGBE_MDIO_GLOBAL_FAULT_MSG_HI_TMP) {
ixgbe_set_copper_phy_power(hw, false);
return IXGBE_ERR_OVERTEMP;
}
}
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_CHIP_STD_INT_FLAG,
MDIO_MMD_AN, &reg);
if (status || !(reg & IXGBE_MDIO_GLOBAL_STD_ALM2_INT))
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_VENDOR_TX_ALARM2,
MDIO_MMD_AN, &reg);
if (status)
return status;
if (reg & IXGBE_MDIO_AUTO_NEG_VEN_LSC)
*lsc = true;
return 0;
}
static s32 ixgbe_enable_lasi_ext_t_x550em(struct ixgbe_hw *hw)
{
u32 status;
u16 reg;
bool lsc;
status = ixgbe_get_lasi_ext_t_x550em(hw, &lsc);
if (hw->mac.type != ixgbe_mac_x550em_a) {
status = hw->phy.ops.read_reg(hw,
IXGBE_MDIO_PMA_TX_VEN_LASI_INT_MASK,
MDIO_MMD_AN, &reg);
if (status)
return status;
reg |= IXGBE_MDIO_PMA_TX_VEN_LASI_INT_EN;
status = hw->phy.ops.write_reg(hw,
IXGBE_MDIO_PMA_TX_VEN_LASI_INT_MASK,
MDIO_MMD_AN, reg);
if (status)
return status;
}
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_INT_MASK,
MDIO_MMD_VEND1,
&reg);
if (status)
return status;
reg |= (IXGBE_MDIO_GLOBAL_INT_HI_TEMP_EN |
IXGBE_MDIO_GLOBAL_INT_DEV_FAULT_EN);
status = hw->phy.ops.write_reg(hw, IXGBE_MDIO_GLOBAL_INT_MASK,
MDIO_MMD_VEND1,
reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_VEN_MASK,
MDIO_MMD_VEND1,
&reg);
if (status)
return status;
reg |= (IXGBE_MDIO_GLOBAL_AN_VEN_ALM_INT_EN |
IXGBE_MDIO_GLOBAL_ALARM_1_INT);
status = hw->phy.ops.write_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_VEN_MASK,
MDIO_MMD_VEND1,
reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_STD_MASK,
MDIO_MMD_VEND1,
&reg);
if (status)
return status;
reg |= IXGBE_MDIO_GLOBAL_VEN_ALM_INT_EN;
status = hw->phy.ops.write_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_STD_MASK,
MDIO_MMD_VEND1,
reg);
return status;
}
static s32 ixgbe_handle_lasi_ext_t_x550em(struct ixgbe_hw *hw)
{
struct ixgbe_phy_info *phy = &hw->phy;
bool lsc;
u32 status;
status = ixgbe_get_lasi_ext_t_x550em(hw, &lsc);
if (status)
return status;
if (lsc && phy->ops.setup_internal_link)
return phy->ops.setup_internal_link(hw);
return 0;
}
static s32 ixgbe_setup_kr_speed_x550em(struct ixgbe_hw *hw,
ixgbe_link_speed speed)
{
s32 status;
u32 reg_val;
status = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_ENABLE;
reg_val &= ~(IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KR |
IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KX);
if (speed & IXGBE_LINK_SPEED_10GB_FULL)
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KR;
if (speed & IXGBE_LINK_SPEED_1GB_FULL)
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KX;
status = hw->mac.ops.write_iosf_sb_reg(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
if (hw->mac.type == ixgbe_mac_x550em_a) {
status = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_MASK;
reg_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_AN;
reg_val |= IXGBE_KRM_PMD_FLX_MASK_ST20_AN_EN;
reg_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_AN37_EN;
reg_val &= ~IXGBE_KRM_PMD_FLX_MASK_ST20_SGMII_EN;
status = hw->mac.ops.write_iosf_sb_reg(hw,
IXGBE_KRM_PMD_FLX_MASK_ST20(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
}
return ixgbe_restart_an_internal_phy_x550em(hw);
}
static s32 ixgbe_setup_kr_x550em(struct ixgbe_hw *hw)
{
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_2_5GB_FULL)
return 0;
if (ixgbe_check_reset_blocked(hw))
return 0;
return ixgbe_setup_kr_speed_x550em(hw, hw->phy.autoneg_advertised);
}
static s32 ixgbe_ext_phy_t_x550em_get_link(struct ixgbe_hw *hw, bool *link_up)
{
u32 ret;
u16 autoneg_status;
*link_up = false;
ret = hw->phy.ops.read_reg(hw, MDIO_STAT1, MDIO_MMD_AN,
&autoneg_status);
if (ret)
return ret;
ret = hw->phy.ops.read_reg(hw, MDIO_STAT1, MDIO_MMD_AN,
&autoneg_status);
if (ret)
return ret;
*link_up = !!(autoneg_status & IXGBE_MDIO_AUTO_NEG_LINK_STATUS);
return 0;
}
static s32 ixgbe_setup_internal_phy_t_x550em(struct ixgbe_hw *hw)
{
ixgbe_link_speed force_speed;
bool link_up;
u32 status;
u16 speed;
if (hw->mac.ops.get_media_type(hw) != ixgbe_media_type_copper)
return IXGBE_ERR_CONFIG;
if (!(hw->mac.type == ixgbe_mac_X550EM_x &&
!(hw->phy.nw_mng_if_sel & IXGBE_NW_MNG_IF_SEL_INT_PHY_MODE))) {
speed = IXGBE_LINK_SPEED_10GB_FULL |
IXGBE_LINK_SPEED_1GB_FULL;
return ixgbe_setup_kr_speed_x550em(hw, speed);
}
status = ixgbe_ext_phy_t_x550em_get_link(hw, &link_up);
if (status)
return status;
if (!link_up)
return 0;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_VENDOR_STAT,
MDIO_MMD_AN,
&speed);
if (status)
return status;
status = ixgbe_ext_phy_t_x550em_get_link(hw, &link_up);
if (status)
return status;
if (!link_up)
return 0;
speed &= IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_MASK;
switch (speed) {
case IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_10GB_FULL:
force_speed = IXGBE_LINK_SPEED_10GB_FULL;
break;
case IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_1GB_FULL:
force_speed = IXGBE_LINK_SPEED_1GB_FULL;
break;
default:
return IXGBE_ERR_INVALID_LINK_SETTINGS;
}
return ixgbe_setup_ixfi_x550em(hw, &force_speed);
}
static s32 ixgbe_reset_phy_t_X550em(struct ixgbe_hw *hw)
{
s32 status;
status = ixgbe_reset_phy_generic(hw);
if (status)
return status;
return ixgbe_enable_lasi_ext_t_x550em(hw);
}
static s32 ixgbe_led_on_t_x550em(struct ixgbe_hw *hw, u32 led_idx)
{
u16 phy_data;
if (led_idx >= IXGBE_X557_MAX_LED_INDEX)
return IXGBE_ERR_PARAM;
hw->phy.ops.read_reg(hw, IXGBE_X557_LED_PROVISIONING + led_idx,
MDIO_MMD_VEND1, &phy_data);
phy_data |= IXGBE_X557_LED_MANUAL_SET_MASK;
hw->phy.ops.write_reg(hw, IXGBE_X557_LED_PROVISIONING + led_idx,
MDIO_MMD_VEND1, phy_data);
return 0;
}
static s32 ixgbe_led_off_t_x550em(struct ixgbe_hw *hw, u32 led_idx)
{
u16 phy_data;
if (led_idx >= IXGBE_X557_MAX_LED_INDEX)
return IXGBE_ERR_PARAM;
hw->phy.ops.read_reg(hw, IXGBE_X557_LED_PROVISIONING + led_idx,
MDIO_MMD_VEND1, &phy_data);
phy_data &= ~IXGBE_X557_LED_MANUAL_SET_MASK;
hw->phy.ops.write_reg(hw, IXGBE_X557_LED_PROVISIONING + led_idx,
MDIO_MMD_VEND1, phy_data);
return 0;
}
static s32 ixgbe_set_fw_drv_ver_x550(struct ixgbe_hw *hw, u8 maj, u8 min,
u8 build, u8 sub, u16 len,
const char *driver_ver)
{
struct ixgbe_hic_drv_info2 fw_cmd;
s32 ret_val;
int i;
if (!len || !driver_ver || (len > sizeof(fw_cmd.driver_string)))
return IXGBE_ERR_INVALID_ARGUMENT;
fw_cmd.hdr.cmd = FW_CEM_CMD_DRIVER_INFO;
fw_cmd.hdr.buf_len = FW_CEM_CMD_DRIVER_INFO_LEN + len;
fw_cmd.hdr.cmd_or_resp.cmd_resv = FW_CEM_CMD_RESERVED;
fw_cmd.port_num = (u8)hw->bus.func;
fw_cmd.ver_maj = maj;
fw_cmd.ver_min = min;
fw_cmd.ver_build = build;
fw_cmd.ver_sub = sub;
fw_cmd.hdr.checksum = 0;
memcpy(fw_cmd.driver_string, driver_ver, len);
fw_cmd.hdr.checksum = ixgbe_calculate_checksum((u8 *)&fw_cmd,
(FW_CEM_HDR_LEN + fw_cmd.hdr.buf_len));
for (i = 0; i <= FW_CEM_MAX_RETRIES; i++) {
ret_val = ixgbe_host_interface_command(hw, (u32 *)&fw_cmd,
sizeof(fw_cmd),
IXGBE_HI_COMMAND_TIMEOUT,
true);
if (ret_val)
continue;
if (fw_cmd.hdr.cmd_or_resp.ret_status !=
FW_CEM_RESP_STATUS_SUCCESS)
return IXGBE_ERR_HOST_INTERFACE_COMMAND;
return 0;
}
return ret_val;
}
static s32 ixgbe_get_lcd_t_x550em(struct ixgbe_hw *hw,
ixgbe_link_speed *lcd_speed)
{
u16 an_lp_status;
s32 status;
u16 word = hw->eeprom.ctrl_word_3;
*lcd_speed = IXGBE_LINK_SPEED_UNKNOWN;
status = hw->phy.ops.read_reg(hw, IXGBE_AUTO_NEG_LP_STATUS,
MDIO_MMD_AN,
&an_lp_status);
if (status)
return status;
if (an_lp_status & IXGBE_AUTO_NEG_LP_1000BASE_CAP) {
*lcd_speed = IXGBE_LINK_SPEED_1GB_FULL;
return status;
}
if ((hw->bus.lan_id && (word & NVM_INIT_CTRL_3_D10GMP_PORT1)) ||
(word & NVM_INIT_CTRL_3_D10GMP_PORT0))
return status;
*lcd_speed = IXGBE_LINK_SPEED_10GB_FULL;
return status;
}
static s32 ixgbe_setup_fc_x550em(struct ixgbe_hw *hw)
{
bool pause, asm_dir;
u32 reg_val;
s32 rc = 0;
if (hw->fc.strict_ieee && hw->fc.requested_mode == ixgbe_fc_rx_pause) {
hw_err(hw, "ixgbe_fc_rx_pause not valid in strict IEEE mode\n");
return IXGBE_ERR_INVALID_LINK_SETTINGS;
}
if (hw->fc.requested_mode == ixgbe_fc_default)
hw->fc.requested_mode = ixgbe_fc_full;
switch (hw->fc.requested_mode) {
case ixgbe_fc_none:
pause = false;
asm_dir = false;
break;
case ixgbe_fc_tx_pause:
pause = false;
asm_dir = true;
break;
case ixgbe_fc_rx_pause:
case ixgbe_fc_full:
pause = true;
asm_dir = true;
break;
default:
hw_err(hw, "Flow control param set incorrectly\n");
return IXGBE_ERR_CONFIG;
}
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_X_KR:
case IXGBE_DEV_ID_X550EM_A_KR:
case IXGBE_DEV_ID_X550EM_A_KR_L:
rc = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_AN_CNTL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY,
&reg_val);
if (rc)
return rc;
reg_val &= ~(IXGBE_KRM_AN_CNTL_1_SYM_PAUSE |
IXGBE_KRM_AN_CNTL_1_ASM_PAUSE);
if (pause)
reg_val |= IXGBE_KRM_AN_CNTL_1_SYM_PAUSE;
if (asm_dir)
reg_val |= IXGBE_KRM_AN_CNTL_1_ASM_PAUSE;
rc = hw->mac.ops.write_iosf_sb_reg(hw,
IXGBE_KRM_AN_CNTL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY,
reg_val);
hw->fc.disable_fc_autoneg = true;
break;
case IXGBE_DEV_ID_X550EM_X_XFI:
hw->fc.disable_fc_autoneg = true;
break;
default:
break;
}
return rc;
}
static void ixgbe_fc_autoneg_backplane_x550em_a(struct ixgbe_hw *hw)
{
u32 link_s1, lp_an_page_low, an_cntl_1;
s32 status = IXGBE_ERR_FC_NOT_NEGOTIATED;
ixgbe_link_speed speed;
bool link_up;
if (hw->fc.disable_fc_autoneg) {
hw_err(hw, "Flow control autoneg is disabled");
goto out;
}
hw->mac.ops.check_link(hw, &speed, &link_up, false);
if (!link_up) {
hw_err(hw, "The link is down");
goto out;
}
status = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_LINK_S1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &link_s1);
if (status || (link_s1 & IXGBE_KRM_LINK_S1_MAC_AN_COMPLETE) == 0) {
hw_dbg(hw, "Auto-Negotiation did not complete\n");
status = IXGBE_ERR_FC_NOT_NEGOTIATED;
goto out;
}
status = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_AN_CNTL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &an_cntl_1);
if (status) {
hw_dbg(hw, "Auto-Negotiation did not complete\n");
goto out;
}
status = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_LP_BASE_PAGE_HIGH(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &lp_an_page_low);
if (status) {
hw_dbg(hw, "Auto-Negotiation did not complete\n");
goto out;
}
status = ixgbe_negotiate_fc(hw, an_cntl_1, lp_an_page_low,
IXGBE_KRM_AN_CNTL_1_SYM_PAUSE,
IXGBE_KRM_AN_CNTL_1_ASM_PAUSE,
IXGBE_KRM_LP_BASE_PAGE_HIGH_SYM_PAUSE,
IXGBE_KRM_LP_BASE_PAGE_HIGH_ASM_PAUSE);
out:
if (!status) {
hw->fc.fc_was_autonegged = true;
} else {
hw->fc.fc_was_autonegged = false;
hw->fc.current_mode = hw->fc.requested_mode;
}
}
static void ixgbe_fc_autoneg_fiber_x550em_a(struct ixgbe_hw *hw)
{
hw->fc.fc_was_autonegged = false;
hw->fc.current_mode = hw->fc.requested_mode;
}
static s32 ixgbe_enter_lplu_t_x550em(struct ixgbe_hw *hw)
{
u16 an_10g_cntl_reg, autoneg_reg, speed;
s32 status;
ixgbe_link_speed lcd_speed;
u32 save_autoneg;
bool link_up;
if (ixgbe_check_reset_blocked(hw))
return 0;
status = ixgbe_ext_phy_t_x550em_get_link(hw, &link_up);
if (status)
return status;
status = hw->eeprom.ops.read(hw, NVM_INIT_CTRL_3,
&hw->eeprom.ctrl_word_3);
if (status)
return status;
if (!link_up || !(hw->eeprom.ctrl_word_3 & NVM_INIT_CTRL_3_LPLU) ||
!(hw->wol_enabled || ixgbe_mng_present(hw)))
return ixgbe_set_copper_phy_power(hw, false);
status = ixgbe_get_lcd_t_x550em(hw, &lcd_speed);
if (status)
return status;
if (lcd_speed == IXGBE_LINK_SPEED_UNKNOWN)
return ixgbe_set_copper_phy_power(hw, false);
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_VENDOR_STAT,
MDIO_MMD_AN,
&speed);
if (status)
return status;
status = ixgbe_ext_phy_t_x550em_get_link(hw, &link_up);
if (status)
return ixgbe_set_copper_phy_power(hw, false);
speed &= IXGBE_MDIO_AUTO_NEG_VEN_STAT_SPEED_MASK;
if (((speed == IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_1GB) &&
(lcd_speed == IXGBE_LINK_SPEED_1GB_FULL)) ||
((speed == IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_10GB) &&
(lcd_speed == IXGBE_LINK_SPEED_10GB_FULL)))
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_VENDOR_TX_ALARM,
MDIO_MMD_AN,
&autoneg_reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw, MDIO_AN_10GBT_CTRL,
MDIO_MMD_AN,
&an_10g_cntl_reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw,
IXGBE_MII_AUTONEG_VENDOR_PROVISION_1_REG,
MDIO_MMD_AN,
&autoneg_reg);
if (status)
return status;
save_autoneg = hw->phy.autoneg_advertised;
status = hw->mac.ops.setup_link(hw, lcd_speed, false);
hw->phy.autoneg_advertised = save_autoneg;
return status;
}
static s32 ixgbe_reset_phy_fw(struct ixgbe_hw *hw)
{
u32 store[FW_PHY_ACT_DATA_COUNT] = { 0 };
s32 rc;
if (hw->phy.reset_disable || ixgbe_check_reset_blocked(hw))
return 0;
rc = ixgbe_fw_phy_activity(hw, FW_PHY_ACT_PHY_SW_RESET, &store);
if (rc)
return rc;
memset(store, 0, sizeof(store));
rc = ixgbe_fw_phy_activity(hw, FW_PHY_ACT_INIT_PHY, &store);
if (rc)
return rc;
return ixgbe_setup_fw_link(hw);
}
static s32 ixgbe_check_overtemp_fw(struct ixgbe_hw *hw)
{
u32 store[FW_PHY_ACT_DATA_COUNT] = { 0 };
s32 rc;
rc = ixgbe_fw_phy_activity(hw, FW_PHY_ACT_GET_LINK_INFO, &store);
if (rc)
return rc;
if (store[0] & FW_PHY_ACT_GET_LINK_INFO_TEMP) {
ixgbe_shutdown_fw_phy(hw);
return IXGBE_ERR_OVERTEMP;
}
return 0;
}
static void ixgbe_read_mng_if_sel_x550em(struct ixgbe_hw *hw)
{
hw->phy.nw_mng_if_sel = IXGBE_READ_REG(hw, IXGBE_NW_MNG_IF_SEL);
if (hw->mac.type == ixgbe_mac_x550em_a &&
hw->phy.nw_mng_if_sel & IXGBE_NW_MNG_IF_SEL_MDIO_ACT) {
hw->phy.mdio.prtad = (hw->phy.nw_mng_if_sel &
IXGBE_NW_MNG_IF_SEL_MDIO_PHY_ADD) >>
IXGBE_NW_MNG_IF_SEL_MDIO_PHY_ADD_SHIFT;
}
}
static s32 ixgbe_init_phy_ops_X550em(struct ixgbe_hw *hw)
{
struct ixgbe_phy_info *phy = &hw->phy;
s32 ret_val;
hw->mac.ops.set_lan_id(hw);
ixgbe_read_mng_if_sel_x550em(hw);
if (hw->mac.ops.get_media_type(hw) == ixgbe_media_type_fiber) {
phy->phy_semaphore_mask = IXGBE_GSSR_SHARED_I2C_SM;
ixgbe_setup_mux_ctl(hw);
}
ret_val = phy->ops.identify(hw);
ixgbe_init_mac_link_ops_X550em(hw);
if (phy->sfp_type != ixgbe_sfp_type_unknown)
phy->ops.reset = NULL;
switch (hw->phy.type) {
case ixgbe_phy_x550em_kx4:
phy->ops.setup_link = NULL;
phy->ops.read_reg = ixgbe_read_phy_reg_x550em;
phy->ops.write_reg = ixgbe_write_phy_reg_x550em;
break;
case ixgbe_phy_x550em_kr:
phy->ops.setup_link = ixgbe_setup_kr_x550em;
phy->ops.read_reg = ixgbe_read_phy_reg_x550em;
phy->ops.write_reg = ixgbe_write_phy_reg_x550em;
break;
case ixgbe_phy_x550em_xfi:
phy->ops.setup_link = NULL;
phy->ops.read_reg = ixgbe_read_phy_reg_x550em;
phy->ops.write_reg = ixgbe_write_phy_reg_x550em;
break;
case ixgbe_phy_x550em_ext_t:
phy->nw_mng_if_sel = IXGBE_READ_REG(hw, IXGBE_NW_MNG_IF_SEL);
phy->ops.setup_internal_link =
ixgbe_setup_internal_phy_t_x550em;
if (hw->mac.type == ixgbe_mac_X550EM_x &&
!(IXGBE_READ_REG(hw, IXGBE_FUSES0_GROUP(0)) &
IXGBE_FUSES0_REV_MASK))
phy->ops.enter_lplu = ixgbe_enter_lplu_t_x550em;
phy->ops.handle_lasi = ixgbe_handle_lasi_ext_t_x550em;
phy->ops.reset = ixgbe_reset_phy_t_X550em;
break;
case ixgbe_phy_sgmii:
phy->ops.setup_link = NULL;
break;
case ixgbe_phy_fw:
phy->ops.setup_link = ixgbe_setup_fw_link;
phy->ops.reset = ixgbe_reset_phy_fw;
break;
case ixgbe_phy_ext_1g_t:
phy->ops.setup_link = NULL;
phy->ops.read_reg = NULL;
phy->ops.write_reg = NULL;
phy->ops.reset = NULL;
break;
default:
break;
}
return ret_val;
}
static enum ixgbe_media_type ixgbe_get_media_type_X550em(struct ixgbe_hw *hw)
{
enum ixgbe_media_type media_type;
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_A_SGMII:
case IXGBE_DEV_ID_X550EM_A_SGMII_L:
hw->phy.type = ixgbe_phy_sgmii;
case IXGBE_DEV_ID_X550EM_X_KR:
case IXGBE_DEV_ID_X550EM_X_KX4:
case IXGBE_DEV_ID_X550EM_X_XFI:
case IXGBE_DEV_ID_X550EM_A_KR:
case IXGBE_DEV_ID_X550EM_A_KR_L:
media_type = ixgbe_media_type_backplane;
break;
case IXGBE_DEV_ID_X550EM_X_SFP:
case IXGBE_DEV_ID_X550EM_A_SFP:
case IXGBE_DEV_ID_X550EM_A_SFP_N:
media_type = ixgbe_media_type_fiber;
break;
case IXGBE_DEV_ID_X550EM_X_1G_T:
case IXGBE_DEV_ID_X550EM_X_10G_T:
case IXGBE_DEV_ID_X550EM_A_10G_T:
case IXGBE_DEV_ID_X550EM_A_1G_T:
case IXGBE_DEV_ID_X550EM_A_1G_T_L:
media_type = ixgbe_media_type_copper;
break;
default:
media_type = ixgbe_media_type_unknown;
break;
}
return media_type;
}
static s32 ixgbe_init_ext_t_x550em(struct ixgbe_hw *hw)
{
s32 status;
u16 reg;
status = hw->phy.ops.read_reg(hw,
IXGBE_MDIO_TX_VENDOR_ALARMS_3,
MDIO_MMD_PMAPMD,
&reg);
if (status)
return status;
if (reg & IXGBE_MDIO_TX_VENDOR_ALARMS_3_RST_MASK) {
status = hw->phy.ops.read_reg(hw,
IXGBE_MDIO_GLOBAL_RES_PR_10,
MDIO_MMD_VEND1,
&reg);
if (status)
return status;
reg &= ~IXGBE_MDIO_POWER_UP_STALL;
status = hw->phy.ops.write_reg(hw,
IXGBE_MDIO_GLOBAL_RES_PR_10,
MDIO_MMD_VEND1,
reg);
if (status)
return status;
}
return status;
}
static void ixgbe_set_mdio_speed(struct ixgbe_hw *hw)
{
u32 hlreg0;
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_X_10G_T:
case IXGBE_DEV_ID_X550EM_A_SGMII:
case IXGBE_DEV_ID_X550EM_A_SGMII_L:
case IXGBE_DEV_ID_X550EM_A_10G_T:
case IXGBE_DEV_ID_X550EM_A_SFP:
hlreg0 = IXGBE_READ_REG(hw, IXGBE_HLREG0);
hlreg0 &= ~IXGBE_HLREG0_MDCSPD;
IXGBE_WRITE_REG(hw, IXGBE_HLREG0, hlreg0);
break;
case IXGBE_DEV_ID_X550EM_A_1G_T:
case IXGBE_DEV_ID_X550EM_A_1G_T_L:
hlreg0 = IXGBE_READ_REG(hw, IXGBE_HLREG0);
hlreg0 |= IXGBE_HLREG0_MDCSPD;
IXGBE_WRITE_REG(hw, IXGBE_HLREG0, hlreg0);
break;
default:
break;
}
}
static s32 ixgbe_reset_hw_X550em(struct ixgbe_hw *hw)
{
ixgbe_link_speed link_speed;
s32 status;
u32 ctrl = 0;
u32 i;
bool link_up = false;
u32 swfw_mask = hw->phy.phy_semaphore_mask;
status = hw->mac.ops.stop_adapter(hw);
if (status)
return status;
ixgbe_clear_tx_pending(hw);
status = hw->phy.ops.init(hw);
if (hw->phy.type == ixgbe_phy_x550em_ext_t) {
status = ixgbe_init_ext_t_x550em(hw);
if (status)
return status;
}
if (hw->phy.sfp_setup_needed) {
status = hw->mac.ops.setup_sfp(hw);
hw->phy.sfp_setup_needed = false;
}
if (!hw->phy.reset_disable && hw->phy.ops.reset)
hw->phy.ops.reset(hw);
mac_reset_top:
ctrl = IXGBE_CTRL_LNK_RST;
if (!hw->force_full_reset) {
hw->mac.ops.check_link(hw, &link_speed, &link_up, false);
if (link_up)
ctrl = IXGBE_CTRL_RST;
}
status = hw->mac.ops.acquire_swfw_sync(hw, swfw_mask);
if (status) {
hw_dbg(hw, "semaphore failed with %d", status);
return IXGBE_ERR_SWFW_SYNC;
}
ctrl |= IXGBE_READ_REG(hw, IXGBE_CTRL);
IXGBE_WRITE_REG(hw, IXGBE_CTRL, ctrl);
IXGBE_WRITE_FLUSH(hw);
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
usleep_range(1000, 1200);
for (i = 0; i < 10; i++) {
ctrl = IXGBE_READ_REG(hw, IXGBE_CTRL);
if (!(ctrl & IXGBE_CTRL_RST_MASK))
break;
udelay(1);
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
hw->mac.ops.get_mac_addr(hw, hw->mac.perm_addr);
hw->mac.num_rar_entries = 128;
hw->mac.ops.init_rx_addrs(hw);
ixgbe_set_mdio_speed(hw);
if (hw->device_id == IXGBE_DEV_ID_X550EM_X_SFP)
ixgbe_setup_mux_ctl(hw);
return status;
}
static void ixgbe_set_ethertype_anti_spoofing_X550(struct ixgbe_hw *hw,
bool enable, int vf)
{
int vf_target_reg = vf >> 3;
int vf_target_shift = vf % 8 + IXGBE_SPOOF_ETHERTYPEAS_SHIFT;
u32 pfvfspoof;
pfvfspoof = IXGBE_READ_REG(hw, IXGBE_PFVFSPOOF(vf_target_reg));
if (enable)
pfvfspoof |= BIT(vf_target_shift);
else
pfvfspoof &= ~BIT(vf_target_shift);
IXGBE_WRITE_REG(hw, IXGBE_PFVFSPOOF(vf_target_reg), pfvfspoof);
}
static void ixgbe_set_source_address_pruning_X550(struct ixgbe_hw *hw,
bool enable,
unsigned int pool)
{
u64 pfflp;
if (pool > 63)
return;
pfflp = (u64)IXGBE_READ_REG(hw, IXGBE_PFFLPL);
pfflp |= (u64)IXGBE_READ_REG(hw, IXGBE_PFFLPH) << 32;
if (enable)
pfflp |= (1ULL << pool);
else
pfflp &= ~(1ULL << pool);
IXGBE_WRITE_REG(hw, IXGBE_PFFLPL, (u32)pfflp);
IXGBE_WRITE_REG(hw, IXGBE_PFFLPH, (u32)(pfflp >> 32));
}
static s32 ixgbe_setup_fc_backplane_x550em_a(struct ixgbe_hw *hw)
{
s32 status = 0;
u32 an_cntl = 0;
if (hw->fc.strict_ieee && hw->fc.requested_mode == ixgbe_fc_rx_pause) {
hw_err(hw, "ixgbe_fc_rx_pause not valid in strict IEEE mode\n");
return IXGBE_ERR_INVALID_LINK_SETTINGS;
}
if (hw->fc.requested_mode == ixgbe_fc_default)
hw->fc.requested_mode = ixgbe_fc_full;
status = hw->mac.ops.read_iosf_sb_reg(hw,
IXGBE_KRM_AN_CNTL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &an_cntl);
if (status) {
hw_dbg(hw, "Auto-Negotiation did not complete\n");
return status;
}
switch (hw->fc.requested_mode) {
case ixgbe_fc_none:
an_cntl &= ~(IXGBE_KRM_AN_CNTL_1_SYM_PAUSE |
IXGBE_KRM_AN_CNTL_1_ASM_PAUSE);
break;
case ixgbe_fc_tx_pause:
an_cntl |= IXGBE_KRM_AN_CNTL_1_ASM_PAUSE;
an_cntl &= ~IXGBE_KRM_AN_CNTL_1_SYM_PAUSE;
break;
case ixgbe_fc_rx_pause:
case ixgbe_fc_full:
an_cntl |= IXGBE_KRM_AN_CNTL_1_SYM_PAUSE |
IXGBE_KRM_AN_CNTL_1_ASM_PAUSE;
break;
default:
hw_err(hw, "Flow control param set incorrectly\n");
return IXGBE_ERR_CONFIG;
}
status = hw->mac.ops.write_iosf_sb_reg(hw,
IXGBE_KRM_AN_CNTL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, an_cntl);
status = ixgbe_restart_an_internal_phy_x550em(hw);
return status;
}
static void ixgbe_set_mux(struct ixgbe_hw *hw, u8 state)
{
u32 esdp;
if (!hw->bus.lan_id)
return;
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
if (state)
esdp |= IXGBE_ESDP_SDP1;
else
esdp &= ~IXGBE_ESDP_SDP1;
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_FLUSH(hw);
}
static s32 ixgbe_acquire_swfw_sync_X550em(struct ixgbe_hw *hw, u32 mask)
{
s32 status;
status = ixgbe_acquire_swfw_sync_X540(hw, mask);
if (status)
return status;
if (mask & IXGBE_GSSR_I2C_MASK)
ixgbe_set_mux(hw, 1);
return 0;
}
static void ixgbe_release_swfw_sync_X550em(struct ixgbe_hw *hw, u32 mask)
{
if (mask & IXGBE_GSSR_I2C_MASK)
ixgbe_set_mux(hw, 0);
ixgbe_release_swfw_sync_X540(hw, mask);
}
static s32 ixgbe_acquire_swfw_sync_x550em_a(struct ixgbe_hw *hw, u32 mask)
{
u32 hmask = mask & ~IXGBE_GSSR_TOKEN_SM;
int retries = FW_PHY_TOKEN_RETRIES;
s32 status;
while (--retries) {
status = 0;
if (hmask)
status = ixgbe_acquire_swfw_sync_X540(hw, hmask);
if (status)
return status;
if (!(mask & IXGBE_GSSR_TOKEN_SM))
return 0;
status = ixgbe_get_phy_token(hw);
if (!status)
return 0;
if (hmask)
ixgbe_release_swfw_sync_X540(hw, hmask);
if (status != IXGBE_ERR_TOKEN_RETRY)
return status;
msleep(FW_PHY_TOKEN_DELAY);
}
return status;
}
static void ixgbe_release_swfw_sync_x550em_a(struct ixgbe_hw *hw, u32 mask)
{
u32 hmask = mask & ~IXGBE_GSSR_TOKEN_SM;
if (mask & IXGBE_GSSR_TOKEN_SM)
ixgbe_put_phy_token(hw);
if (hmask)
ixgbe_release_swfw_sync_X540(hw, hmask);
}
static s32 ixgbe_read_phy_reg_x550a(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u16 *phy_data)
{
u32 mask = hw->phy.phy_semaphore_mask | IXGBE_GSSR_TOKEN_SM;
s32 status;
if (hw->mac.ops.acquire_swfw_sync(hw, mask))
return IXGBE_ERR_SWFW_SYNC;
status = hw->phy.ops.read_reg_mdi(hw, reg_addr, device_type, phy_data);
hw->mac.ops.release_swfw_sync(hw, mask);
return status;
}
static s32 ixgbe_write_phy_reg_x550a(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u16 phy_data)
{
u32 mask = hw->phy.phy_semaphore_mask | IXGBE_GSSR_TOKEN_SM;
s32 status;
if (hw->mac.ops.acquire_swfw_sync(hw, mask))
return IXGBE_ERR_SWFW_SYNC;
status = ixgbe_write_phy_reg_mdi(hw, reg_addr, device_type, phy_data);
hw->mac.ops.release_swfw_sync(hw, mask);
return status;
}
