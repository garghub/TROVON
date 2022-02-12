static s32 ixgbe_get_invariants_X550_x(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
struct ixgbe_phy_info *phy = &hw->phy;
ixgbe_get_invariants_X540(hw);
if (mac->ops.get_media_type(hw) != ixgbe_media_type_copper)
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
static s32 ixgbe_identify_phy_x550em(struct ixgbe_hw *hw)
{
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_X_SFP:
hw->phy.phy_semaphore_mask = IXGBE_GSSR_SHARED_I2C_SM;
ixgbe_setup_mux_ctl(hw);
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
eeprom->word_size = 1 << (eeprom_size +
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
usleep_range(10, 20);
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
static s32 ixgbe_read_ee_hostif_data_X550(struct ixgbe_hw *hw, u16 offset,
u16 *data)
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
static s32 ixgbe_read_ee_hostif_buffer_X550(struct ixgbe_hw *hw,
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
s32 status = 0;
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM) == 0) {
status = ixgbe_read_ee_hostif_data_X550(hw, offset, data);
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
} else {
status = IXGBE_ERR_SWFW_SYNC;
}
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
status = ixgbe_host_interface_command(hw, (u32 *)&buffer,
sizeof(buffer),
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
status = ixgbe_host_interface_command(hw, (u32 *)&buffer,
sizeof(buffer),
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
fw_cmd.port_number = (u8)hw->bus.lan_id;
status = ixgbe_host_interface_command(hw, (u32 *)&fw_cmd,
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
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
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
if (!(hw->phy.nw_mng_if_sel & IXGBE_NW_MNG_IF_SEL_INT_PHY_MODE)) {
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
u16 autoneg_status;
if (hw->mac.ops.get_media_type(hw) != ixgbe_media_type_copper)
return IXGBE_ERR_CONFIG;
status = ixgbe_check_mac_link_generic(hw, speed, link_up,
link_up_wait_to_complete);
if (status || !(*link_up))
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_STATUS,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
&autoneg_status);
if (status)
return status;
if (!(autoneg_status & IXGBE_MDIO_AUTO_NEG_LINK_STATUS))
*link_up = false;
return 0;
}
static void ixgbe_init_mac_link_ops_X550em(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
switch (mac->ops.get_media_type(hw)) {
case ixgbe_media_type_fiber:
mac->ops.disable_tx_laser = NULL;
mac->ops.enable_tx_laser = NULL;
mac->ops.flap_tx_laser = NULL;
break;
case ixgbe_media_type_copper:
mac->ops.setup_link = ixgbe_setup_mac_link_t_X550em;
mac->ops.check_link = ixgbe_check_link_t_X550em;
break;
default:
break;
}
}
static s32 ixgbe_setup_sfp_modules_X550em(struct ixgbe_hw *hw)
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
static s32 ixgbe_get_link_capabilities_X550em(struct ixgbe_hw *hw,
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
static s32 ixgbe_get_lasi_ext_t_x550em(struct ixgbe_hw *hw, bool *lsc)
{
u32 status;
u16 reg;
*lsc = false;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_CHIP_STD_INT_FLAG,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
&reg);
if (status || !(reg & IXGBE_MDIO_GLOBAL_VEN_ALM_INT_EN))
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_VEN_FLAG,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
&reg);
if (status || !(reg & (IXGBE_MDIO_GLOBAL_AN_VEN_ALM_INT_EN |
IXGBE_MDIO_GLOBAL_ALARM_1_INT)))
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_ALARM_1,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
&reg);
if (status)
return status;
if (reg & IXGBE_MDIO_GLOBAL_ALM_1_HI_TMP_FAIL) {
ixgbe_set_copper_phy_power(hw, false);
return IXGBE_ERR_OVERTEMP;
}
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_CHIP_STD_INT_FLAG,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE, &reg);
if (status || !(reg & IXGBE_MDIO_GLOBAL_STD_ALM2_INT))
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_VENDOR_TX_ALARM2,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE, &reg);
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
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_PMA_TX_VEN_LASI_INT_MASK,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE, &reg);
if (status)
return status;
reg |= IXGBE_MDIO_PMA_TX_VEN_LASI_INT_EN;
status = hw->phy.ops.write_reg(hw, IXGBE_MDIO_PMA_TX_VEN_LASI_INT_MASK,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE, reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_INT_MASK,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
&reg);
if (status)
return status;
reg |= IXGBE_MDIO_GLOBAL_INT_HI_TEMP_EN;
status = hw->phy.ops.write_reg(hw, IXGBE_MDIO_GLOBAL_INT_MASK,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_VEN_MASK,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
&reg);
if (status)
return status;
reg |= (IXGBE_MDIO_GLOBAL_AN_VEN_ALM_INT_EN |
IXGBE_MDIO_GLOBAL_ALARM_1_INT);
status = hw->phy.ops.write_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_VEN_MASK,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_STD_MASK,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
&reg);
if (status)
return status;
reg |= IXGBE_MDIO_GLOBAL_VEN_ALM_INT_EN;
status = hw->phy.ops.write_reg(hw, IXGBE_MDIO_GLOBAL_INT_CHIP_STD_MASK,
IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE,
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
if (lsc)
return phy->ops.setup_internal_link(hw);
return 0;
}
static s32 ixgbe_setup_kr_speed_x550em(struct ixgbe_hw *hw,
ixgbe_link_speed speed)
{
s32 status;
u32 reg_val;
status = ixgbe_read_iosf_sb_reg_x550(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, &reg_val);
if (status)
return status;
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_ENABLE;
reg_val &= ~(IXGBE_KRM_LINK_CTRL_1_TETH_AN_FEC_REQ |
IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_FEC);
reg_val &= ~(IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KR |
IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KX);
if (speed & IXGBE_LINK_SPEED_10GB_FULL)
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KR;
if (speed & IXGBE_LINK_SPEED_1GB_FULL)
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KX;
reg_val |= IXGBE_KRM_LINK_CTRL_1_TETH_AN_RESTART;
status = ixgbe_write_iosf_sb_reg_x550(hw,
IXGBE_KRM_LINK_CTRL_1(hw->bus.lan_id),
IXGBE_SB_IOSF_TARGET_KR_PHY, reg_val);
return status;
}
static s32 ixgbe_setup_kx4_x550em(struct ixgbe_hw *hw)
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
static s32 ixgbe_setup_kr_x550em(struct ixgbe_hw *hw)
{
return ixgbe_setup_kr_speed_x550em(hw, hw->phy.autoneg_advertised);
}
static s32 ixgbe_ext_phy_t_x550em_get_link(struct ixgbe_hw *hw, bool *link_up)
{
u32 ret;
u16 autoneg_status;
*link_up = false;
ret = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_STATUS,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
&autoneg_status);
if (ret)
return ret;
ret = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_STATUS,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
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
status = ixgbe_ext_phy_t_x550em_get_link(hw, &link_up);
if (status)
return status;
if (!link_up)
return 0;
status = hw->phy.ops.read_reg(hw, IXGBE_MDIO_AUTO_NEG_VENDOR_STAT,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
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
static s32 ixgbe_get_lcd_t_x550em(struct ixgbe_hw *hw,
ixgbe_link_speed *lcd_speed)
{
u16 an_lp_status;
s32 status;
u16 word = hw->eeprom.ctrl_word_3;
*lcd_speed = IXGBE_LINK_SPEED_UNKNOWN;
status = hw->phy.ops.read_reg(hw, IXGBE_AUTO_NEG_LP_STATUS,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
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
static s32 ixgbe_enter_lplu_t_x550em(struct ixgbe_hw *hw)
{
u16 an_10g_cntl_reg, autoneg_reg, speed;
s32 status;
ixgbe_link_speed lcd_speed;
u32 save_autoneg;
bool link_up;
if (IXGBE_FUSES0_REV1 & IXGBE_READ_REG(hw, IXGBE_FUSES0_GROUP(0)))
return 0;
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
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
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
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
&autoneg_reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw, IXGBE_MII_10GBASE_T_AUTONEG_CTRL_REG,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
&an_10g_cntl_reg);
if (status)
return status;
status = hw->phy.ops.read_reg(hw,
IXGBE_MII_AUTONEG_VENDOR_PROVISION_1_REG,
IXGBE_MDIO_AUTO_NEG_DEV_TYPE,
&autoneg_reg);
if (status)
return status;
save_autoneg = hw->phy.autoneg_advertised;
status = hw->mac.ops.setup_link(hw, lcd_speed, false);
hw->phy.autoneg_advertised = save_autoneg;
return status;
}
static s32 ixgbe_init_phy_ops_X550em(struct ixgbe_hw *hw)
{
struct ixgbe_phy_info *phy = &hw->phy;
ixgbe_link_speed speed;
s32 ret_val;
hw->mac.ops.set_lan_id(hw);
if (hw->mac.ops.get_media_type(hw) == ixgbe_media_type_fiber) {
phy->phy_semaphore_mask = IXGBE_GSSR_SHARED_I2C_SM;
ixgbe_setup_mux_ctl(hw);
phy->nw_mng_if_sel = IXGBE_READ_REG(hw, IXGBE_NW_MNG_IF_SEL);
if (phy->nw_mng_if_sel & IXGBE_NW_MNG_IF_SEL_INT_PHY_MODE) {
speed = IXGBE_LINK_SPEED_10GB_FULL |
IXGBE_LINK_SPEED_1GB_FULL;
ret_val = ixgbe_setup_kr_speed_x550em(hw, speed);
}
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
phy->nw_mng_if_sel = IXGBE_READ_REG(hw, IXGBE_NW_MNG_IF_SEL);
if (!(phy->nw_mng_if_sel & IXGBE_NW_MNG_IF_SEL_INT_PHY_MODE)) {
phy->ops.setup_internal_link =
ixgbe_setup_internal_phy_t_x550em;
} else {
speed = IXGBE_LINK_SPEED_10GB_FULL |
IXGBE_LINK_SPEED_1GB_FULL;
ret_val = ixgbe_setup_kr_speed_x550em(hw, speed);
}
if (!(IXGBE_FUSES0_REV1 & IXGBE_READ_REG(hw,
IXGBE_FUSES0_GROUP(0))))
phy->ops.enter_lplu = ixgbe_enter_lplu_t_x550em;
phy->ops.handle_lasi = ixgbe_handle_lasi_ext_t_x550em;
phy->ops.reset = ixgbe_reset_phy_t_X550em;
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
static s32 ixgbe_init_ext_t_x550em(struct ixgbe_hw *hw)
{
s32 status;
u16 reg;
status = hw->phy.ops.read_reg(hw,
IXGBE_MDIO_TX_VENDOR_ALARMS_3,
IXGBE_MDIO_PMA_PMD_DEV_TYPE,
&reg);
if (status)
return status;
if (reg & IXGBE_MDIO_TX_VENDOR_ALARMS_3_RST_MASK) {
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
if (status)
return status;
}
return status;
}
static s32 ixgbe_reset_hw_X550em(struct ixgbe_hw *hw)
{
ixgbe_link_speed link_speed;
s32 status;
u32 ctrl = 0;
u32 i;
u32 hlreg0;
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
if (hw->device_id == IXGBE_DEV_ID_X550EM_X_10G_T) {
hlreg0 = IXGBE_READ_REG(hw, IXGBE_HLREG0);
hlreg0 &= ~IXGBE_HLREG0_MDCSPD;
IXGBE_WRITE_REG(hw, IXGBE_HLREG0, hlreg0);
}
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
pfvfspoof |= (1 << vf_target_shift);
else
pfvfspoof &= ~(1 << vf_target_shift);
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
