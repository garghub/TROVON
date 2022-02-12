static s32 ixgbe_identify_phy_x550em(struct ixgbe_hw *hw)
{
u32 esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_X_SFP:
hw->phy.phy_semaphore_mask = IXGBE_GSSR_SHARED_I2C_SM;
if (hw->bus.lan_id) {
esdp &= ~(IXGBE_ESDP_SDP1_NATIVE | IXGBE_ESDP_SDP1);
esdp |= IXGBE_ESDP_SDP1_DIR;
}
esdp &= ~(IXGBE_ESDP_SDP0_NATIVE | IXGBE_ESDP_SDP0_DIR);
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
return ixgbe_identify_module_generic(hw);
case IXGBE_DEV_ID_X550EM_X_KX4:
hw->phy.type = ixgbe_phy_x550em_kx4;
break;
case IXGBE_DEV_ID_X550EM_X_KR:
hw->phy.type = ixgbe_phy_x550em_kr;
break;
case IXGBE_DEV_ID_X550EM_X_1G_T:
case IXGBE_DEV_ID_X550EM_X_10G_T:
return ixgbe_identify_phy_generic(hw);
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
s32 ixgbe_init_eeprom_params_X550(struct ixgbe_hw *hw)
{
struct ixgbe_eeprom_info *eeprom = &hw->eeprom;
u32 eec;
u16 eeprom_size;
if (eeprom->type == ixgbe_eeprom_uninitialized) {
eeprom->semaphore_delay = 10;
eeprom->type = ixgbe_flash;
eec = IXGBE_READ_REG(hw, IXGBE_EEC);
eeprom_size = (u16)((eec & IXGBE_EEC_SIZE) >>
IXGBE_EEC_SIZE_SHIFT);
eeprom->word_size = 1 << (eeprom_size +
IXGBE_EEPROM_WORD_SIZE_SHIFT);
hw_dbg(hw, "Eeprom params: type = %d, size = %d\n",
eeprom->type, eeprom->word_size);
}
return 0;
}
s32 ixgbe_read_iosf_sb_reg_x550(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u32 *data)
{
u32 i, command, error;
command = ((reg_addr << IXGBE_SB_IOSF_CTRL_ADDR_SHIFT) |
(device_type << IXGBE_SB_IOSF_CTRL_TARGET_SELECT_SHIFT));
IXGBE_WRITE_REG(hw, IXGBE_SB_IOSF_INDIRECT_CTRL, command);
for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
usleep_range(10, 20);
command = IXGBE_READ_REG(hw, IXGBE_SB_IOSF_INDIRECT_CTRL);
if ((command & IXGBE_SB_IOSF_CTRL_BUSY) == 0)
break;
}
if ((command & IXGBE_SB_IOSF_CTRL_RESP_STAT_MASK) != 0) {
error = (command & IXGBE_SB_IOSF_CTRL_CMPL_ERR_MASK) >>
IXGBE_SB_IOSF_CTRL_CMPL_ERR_SHIFT;
hw_dbg(hw, "Failed to read, error %x\n", error);
return IXGBE_ERR_PHY;
}
if (i == IXGBE_MDIO_COMMAND_TIMEOUT) {
hw_dbg(hw, "Read timed out\n");
return IXGBE_ERR_PHY;
}
*data = IXGBE_READ_REG(hw, IXGBE_SB_IOSF_INDIRECT_DATA);
return 0;
}
s32 ixgbe_read_ee_hostif_data_X550(struct ixgbe_hw *hw, u16 offset, u16 *data)
{
s32 status;
struct ixgbe_hic_read_shadow_ram buffer;
buffer.hdr.req.cmd = FW_READ_SHADOW_RAM_CMD;
buffer.hdr.req.buf_lenh = 0;
buffer.hdr.req.buf_lenl = FW_READ_SHADOW_RAM_LEN;
buffer.hdr.req.checksum = FW_DEFAULT_CHECKSUM;
buffer.address = cpu_to_be32(offset * 2);
buffer.length = cpu_to_be16(sizeof(u16));
status = ixgbe_host_interface_command(hw, (u32 *)&buffer,
sizeof(buffer),
IXGBE_HI_COMMAND_TIMEOUT, false);
if (status)
return status;
*data = (u16)IXGBE_READ_REG_ARRAY(hw, IXGBE_FLEX_MNG,
FW_NVM_DATA_OFFSET);
return 0;
}
s32 ixgbe_read_ee_hostif_buffer_X550(struct ixgbe_hw *hw,
u16 offset, u16 words, u16 *data)
{
struct ixgbe_hic_read_shadow_ram buffer;
u32 current_word = 0;
u16 words_to_read;
s32 status;
u32 i;
status = hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
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
status = ixgbe_host_interface_command(hw, (u32 *)&buffer,
sizeof(buffer),
IXGBE_HI_COMMAND_TIMEOUT,
false);
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
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
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
s32 ixgbe_calc_checksum_X550(struct ixgbe_hw *hw, u16 *buffer, u32 buffer_size)
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
s32 ixgbe_calc_eeprom_checksum_X550(struct ixgbe_hw *hw)
{
return ixgbe_calc_checksum_X550(hw, NULL, 0);
}
s32 ixgbe_read_ee_hostif_X550(struct ixgbe_hw *hw, u16 offset, u16 *data)
{
s32 status = 0;
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM) == 0) {
status = ixgbe_read_ee_hostif_data_X550(hw, offset, data);
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
} else {
status = IXGBE_ERR_SWFW_SYNC;
}
return status;
}
s32 ixgbe_validate_eeprom_checksum_X550(struct ixgbe_hw *hw, u16 *checksum_val)
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
s32 ixgbe_write_ee_hostif_data_X550(struct ixgbe_hw *hw, u16 offset, u16 data)
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
status = ixgbe_host_interface_command(hw, (u32 *)&buffer,
sizeof(buffer),
IXGBE_HI_COMMAND_TIMEOUT, false);
return status;
}
s32 ixgbe_write_ee_hostif_X550(struct ixgbe_hw *hw, u16 offset, u16 data)
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
s32 ixgbe_update_flash_X550(struct ixgbe_hw *hw)
{
s32 status = 0;
union ixgbe_hic_hdr2 buffer;
buffer.req.cmd = FW_SHADOW_RAM_DUMP_CMD;
buffer.req.buf_lenh = 0;
buffer.req.buf_lenl = FW_SHADOW_RAM_DUMP_LEN;
buffer.req.checksum = FW_DEFAULT_CHECKSUM;
status = ixgbe_host_interface_command(hw, (u32 *)&buffer,
sizeof(buffer),
IXGBE_HI_COMMAND_TIMEOUT, false);
return status;
}
s32 ixgbe_update_eeprom_checksum_X550(struct ixgbe_hw *hw)
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
s32 ixgbe_write_ee_hostif_buffer_X550(struct ixgbe_hw *hw,
u16 offset, u16 words, u16 *data)
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
void ixgbe_init_mac_link_ops_X550em(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
if (hw->device_id == IXGBE_DEV_ID_X550EM_X_SFP) {
mac->ops.disable_tx_laser = NULL;
mac->ops.enable_tx_laser = NULL;
mac->ops.flap_tx_laser = NULL;
}
}
s32 ixgbe_setup_sfp_modules_X550em(struct ixgbe_hw *hw)
{
bool setup_linear;
u16 reg_slice, edc_mode;
s32 ret_val;
switch (hw->phy.sfp_type) {
case ixgbe_sfp_type_unknown:
return 0;
case ixgbe_sfp_type_not_present:
return IXGBE_ERR_SFP_NOT_PRESENT;
case ixgbe_sfp_type_da_cu_core0:
case ixgbe_sfp_type_da_cu_core1:
setup_linear = true;
break;
case ixgbe_sfp_type_srlr_core0:
case ixgbe_sfp_type_srlr_core1:
case ixgbe_sfp_type_da_act_lmt_core0:
case ixgbe_sfp_type_da_act_lmt_core1:
case ixgbe_sfp_type_1g_sx_core0:
case ixgbe_sfp_type_1g_sx_core1:
setup_linear = false;
break;
default:
return IXGBE_ERR_SFP_NOT_SUPPORTED;
}
ixgbe_init_mac_link_ops_X550em(hw);
hw->phy.ops.reset = NULL;
reg_slice = IXGBE_CS4227_SPARE24_LSB + (hw->bus.lan_id << 12);
if (setup_linear)
edc_mode = (IXGBE_CS4227_EDC_MODE_CX1 << 1) | 0x1;
else
edc_mode = (IXGBE_CS4227_EDC_MODE_SR << 1) | 0x1;
ret_val = hw->phy.ops.write_i2c_combined(hw, IXGBE_CS4227, reg_slice,
edc_mode);
if (ret_val)
ret_val = hw->phy.ops.write_i2c_combined(hw, 0x80, reg_slice,
edc_mode);
return ret_val;
}
s32 ixgbe_get_link_capabilities_X550em(struct ixgbe_hw *hw,
ixgbe_link_speed *speed,
bool *autoneg)
{
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
*speed = IXGBE_LINK_SPEED_10GB_FULL |
IXGBE_LINK_SPEED_1GB_FULL;
*autoneg = true;
}
return 0;
}
s32 ixgbe_write_iosf_sb_reg_x550(struct ixgbe_hw *hw, u32 reg_addr,
u32 device_type, u32 data)
{
u32 i, command, error;
command = ((reg_addr << IXGBE_SB_IOSF_CTRL_ADDR_SHIFT) |
(device_type << IXGBE_SB_IOSF_CTRL_TARGET_SELECT_SHIFT));
IXGBE_WRITE_REG(hw, IXGBE_SB_IOSF_INDIRECT_CTRL, command);
IXGBE_WRITE_REG(hw, IXGBE_SB_IOSF_INDIRECT_DATA, data);
for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
usleep_range(10, 20);
command = IXGBE_READ_REG(hw, IXGBE_SB_IOSF_INDIRECT_CTRL);
if ((command & IXGBE_SB_IOSF_CTRL_BUSY) == 0)
break;
}
if ((command & IXGBE_SB_IOSF_CTRL_RESP_STAT_MASK) != 0) {
error = (command & IXGBE_SB_IOSF_CTRL_CMPL_ERR_MASK) >>
IXGBE_SB_IOSF_CTRL_CMPL_ERR_SHIFT;
hw_dbg(hw, "Failed to write, error %x\n", error);
return IXGBE_ERR_PHY;
}
if (i == IXGBE_MDIO_COMMAND_TIMEOUT) {
hw_dbg(hw, "Write timed out\n");
return IXGBE_ERR_PHY;
}
return 0;
}
static s32 ixgbe_setup_ixfi_x550em(struct ixgbe_hw *hw, ixgbe_link_speed *speed)
{
s32 status;
u32 reg_val;
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
IXGBE_KRM_RX_TRN_LINKUP_CTRL(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
if (status)
return status;
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
if (status)
return status;
status = ixgbe_read_iosf_sb_reg_x550(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_RESTART;
status = ixgbe_write_iosf_sb_reg_x550(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
return status;
}
s32 ixgbe_setup_kx4_x550em(struct ixgbe_hw *hw)
{
s32 status;
u32 reg_val;
status = ixgbe_read_iosf_sb_reg_x550(hw, IXGBE_KX4_LINK_CNTL_1,
IXGBE_SB_IOSF_TARGET_KX4_PCS0 +
hw->bus.lan_id, &reg_val);
if (status)
return status;
reg_val &= ~(IXGBE_KX4_LINK_CNTL_1_TETH_AN_CAP_KX4 |
IXGBE_KX4_LINK_CNTL_1_TETH_AN_CAP_KX);
reg_val |= IXGBE_KX4_LINK_CNTL_1_TETH_AN_ENABLE;
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_10GB_FULL)
reg_val |= IXGBE_KX4_LINK_CNTL_1_TETH_AN_CAP_KX4;
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_1GB_FULL)
reg_val |= IXGBE_KX4_LINK_CNTL_1_TETH_AN_CAP_KX;
reg_val |= IXGBE_KX4_LINK_CNTL_1_TETH_AN_RESTART;
status = ixgbe_write_iosf_sb_reg_x550(hw, IXGBE_KX4_LINK_CNTL_1,
IXGBE_SB_IOSF_TARGET_KX4_PCS0 +
hw->bus.lan_id, reg_val);
return status;
}
s32 ixgbe_setup_kr_x550em(struct ixgbe_hw *hw)
{
s32 status;
u32 reg_val;
status = ixgbe_read_iosf_sb_reg_x550(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_ENABLE;
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_FEC_REQ;
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_FEC;
reg_val &= ~(IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KR |
IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KX);
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_10GB_FULL)
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KR;
if (hw->phy.autoneg_advertised & IXGBE_LINK_SPEED_1GB_FULL)
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KX;
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_RESTART;
status = ixgbe_write_iosf_sb_reg_x550(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
return status;
}
s32 ixgbe_setup_internal_phy_x550em(struct ixgbe_hw *hw)
{
u32 status;
u16 lasi, autoneg_status, speed;
ixgbe_link_speed force_speed;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_XENPAK_LASI_STATUS,
IXGBE_MDIO_PMA_PMD_DEV_TYPE, &lasi);
if (status)
return status;
if (!(lasi & IXGBE_XENPAK_LASI_LINK_STATUS_ALARM))
return 0;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_STATUS,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
&autoneg_status);
if (status)
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_STATUS,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
&autoneg_status);
if (status)
return status;
if (!(autoneg_status & IXGBE_MDIO_AUTO_NEG_LINK_STATUS))
return IXGBE_ERR_INVALID_LINK_SETTINGS;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_VENDOR_STAT,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
&speed);
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
s32 ixgbe_init_phy_ops_X550em(struct ixgbe_hw *hw)
{
struct ixgbe_phy_info *phy = &hw->phy;
s32 ret_val;
u32 esdp;
if (hw->device_id == IXGBE_DEV_ID_X550EM_X_SFP) {
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
phy->phy_semaphore_mask = IXGBE_GSSR_SHARED_I2C_SM;
if (hw->bus.lan_id) {
esdp &= ~(IXGBE_ESDP_SDP1_NATIVE | IXGBE_ESDP_SDP1);
esdp |= IXGBE_ESDP_SDP1_DIR;
}
esdp &= ~(IXGBE_ESDP_SDP0_NATIVE | IXGBE_ESDP_SDP0_DIR);
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
}
ret_val = phy->ops.identify(hw);
ixgbe_init_mac_link_ops_X550em(hw);
if (phy->sfp_type != ixgbe_sfp_type_unknown)
phy->ops.reset = NULL;
switch (hw->phy.type) {
case ixgbe_phy_x550em_kx4:
phy->ops.setup_link = ixgbe_setup_kx4_x550em;
phy->ops.read_reg = ixgbe_read_phy_reg_x550em;
phy->ops.write_reg = ixgbe_write_phy_reg_x550em;
break;
case ixgbe_phy_x550em_kr:
phy->ops.setup_link = ixgbe_setup_kr_x550em;
phy->ops.read_reg = ixgbe_read_phy_reg_x550em;
phy->ops.write_reg = ixgbe_write_phy_reg_x550em;
break;
case ixgbe_phy_x550em_ext_t:
phy->ops.setup_internal_link = ixgbe_setup_internal_phy_x550em;
break;
default:
break;
}
return ret_val;
}
enum ixgbe_media_type ixgbe_get_media_type_X550em(struct ixgbe_hw *hw)
{
enum ixgbe_media_type media_type;
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_X_KR:
case IXGBE_DEV_ID_X550EM_X_KX4:
media_type = ixgbe_media_type_backplane;
break;
case IXGBE_DEV_ID_X550EM_X_SFP:
media_type = ixgbe_media_type_fiber;
break;
case IXGBE_DEV_ID_X550EM_X_1G_T:
case IXGBE_DEV_ID_X550EM_X_10G_T:
media_type = ixgbe_media_type_copper;
break;
default:
media_type = ixgbe_media_type_unknown;
break;
}
return media_type;
}
s32 ixgbe_init_ext_t_x550em(struct ixgbe_hw *hw)
{
u32 status;
u16 reg;
u32 retries = 2;
do {
if (retries < 1) {
hw_dbg(hw, "External PHY not yet finished resetting.");
return IXGBE_ERR_PHY;
}
retries--;
status = hw->phy.ops.read_reg(hw,
IXGBE_MDIO_TX_VENDOR_ALARMS_3,
IXGBE_MDIO_PMA_PMD_DEV_TYPE,
&reg);
if (status)
return status;
} while ((reg & IXGBE_MDIO_TX_VENDOR_ALARMS_3_RST_MASK) != 1);
status = hw->phy.ops.read_reg(hw,
IXGBE_MDIO_VENDOR_SPECIFIC_1_CONTROL,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
&reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw,
IXGBE_MDIO_PMD_STD_TX_DISABLE_CNTR,
IXGBE_MDIO_PMA_PMD_DEV_TYPE,
&reg);
if (status)
return status;
reg &= ~IXGBE_MDIO_PMD_GLOBAL_TX_DISABLE;
status = hw->phy.ops.write_reg(hw,
IXGBE_MDIO_PMD_STD_TX_DISABLE_CNTR,
IXGBE_MDIO_PMA_PMD_DEV_TYPE,
reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw,
IXGBE_MDIO_GLOBAL_RES_PR_10,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
&reg);
if (status)
return status;
reg &= ~IXGBE_MDIO_POWER_UP_STALL;
status = hw->phy.ops.write_reg(hw,
IXGBE_MDIO_GLOBAL_RES_PR_10,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
reg);
return status;
}
s32 ixgbe_reset_hw_X550em(struct ixgbe_hw *hw)
{
ixgbe_link_speed link_speed;
s32 status;
u32 ctrl = 0;
u32 i;
bool link_up = false;
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
hw->mac.ops.get_mac_addr(hw, hw->mac.perm_addr);
hw->mac.num_rar_entries = 128;
hw->mac.ops.init_rx_addrs(hw);
return status;
}
