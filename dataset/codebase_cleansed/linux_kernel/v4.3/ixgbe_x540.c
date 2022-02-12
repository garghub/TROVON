enum ixgbe_media_type ixgbe_get_media_type_X540(struct ixgbe_hw *hw)
{
return ixgbe_media_type_copper;
}
s32 ixgbe_get_invariants_X540(struct ixgbe_hw *hw)
{
struct ixgbe_mac_info *mac = &hw->mac;
struct ixgbe_phy_info *phy = &hw->phy;
if (!ixgbe_mng_present(hw))
phy->ops.set_phy_power = ixgbe_set_copper_phy_power;
mac->mcft_size = IXGBE_X540_MC_TBL_SIZE;
mac->vft_size = IXGBE_X540_VFT_TBL_SIZE;
mac->num_rar_entries = IXGBE_X540_RAR_ENTRIES;
mac->rx_pb_size = IXGBE_X540_RX_PB_SIZE;
mac->max_rx_queues = IXGBE_X540_MAX_RX_QUEUES;
mac->max_tx_queues = IXGBE_X540_MAX_TX_QUEUES;
mac->max_msix_vectors = ixgbe_get_pcie_msix_count_generic(hw);
return 0;
}
s32 ixgbe_setup_mac_link_X540(struct ixgbe_hw *hw, ixgbe_link_speed speed,
bool autoneg_wait_to_complete)
{
return hw->phy.ops.setup_link_speed(hw, speed,
autoneg_wait_to_complete);
}
s32 ixgbe_reset_hw_X540(struct ixgbe_hw *hw)
{
s32 status;
u32 ctrl, i;
status = hw->mac.ops.stop_adapter(hw);
if (status)
return status;
ixgbe_clear_tx_pending(hw);
mac_reset_top:
ctrl = IXGBE_CTRL_RST;
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
msleep(100);
if (hw->mac.flags & IXGBE_FLAGS_DOUBLE_RESET_REQUIRED) {
hw->mac.flags &= ~IXGBE_FLAGS_DOUBLE_RESET_REQUIRED;
goto mac_reset_top;
}
IXGBE_WRITE_REG(hw, IXGBE_RXPBSIZE(0), 384 << IXGBE_RXPBSIZE_SHIFT);
hw->mac.ops.get_mac_addr(hw, hw->mac.perm_addr);
hw->mac.num_rar_entries = IXGBE_X540_MAX_TX_QUEUES;
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
s32 ixgbe_start_hw_X540(struct ixgbe_hw *hw)
{
s32 ret_val;
ret_val = ixgbe_start_hw_generic(hw);
if (ret_val)
return ret_val;
return ixgbe_start_hw_gen2(hw);
}
s32 ixgbe_init_eeprom_params_X540(struct ixgbe_hw *hw)
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
static s32 ixgbe_read_eerd_X540(struct ixgbe_hw *hw, u16 offset, u16 *data)
{
s32 status;
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM))
return IXGBE_ERR_SWFW_SYNC;
status = ixgbe_read_eerd_generic(hw, offset, data);
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
return status;
}
static s32 ixgbe_read_eerd_buffer_X540(struct ixgbe_hw *hw,
u16 offset, u16 words, u16 *data)
{
s32 status;
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM))
return IXGBE_ERR_SWFW_SYNC;
status = ixgbe_read_eerd_buffer_generic(hw, offset, words, data);
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
return status;
}
static s32 ixgbe_write_eewr_X540(struct ixgbe_hw *hw, u16 offset, u16 data)
{
s32 status;
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM))
return IXGBE_ERR_SWFW_SYNC;
status = ixgbe_write_eewr_generic(hw, offset, data);
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
return status;
}
static s32 ixgbe_write_eewr_buffer_X540(struct ixgbe_hw *hw,
u16 offset, u16 words, u16 *data)
{
s32 status;
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM))
return IXGBE_ERR_SWFW_SYNC;
status = ixgbe_write_eewr_buffer_generic(hw, offset, words, data);
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
return status;
}
static s32 ixgbe_calc_eeprom_checksum_X540(struct ixgbe_hw *hw)
{
u16 i;
u16 j;
u16 checksum = 0;
u16 length = 0;
u16 pointer = 0;
u16 word = 0;
u16 checksum_last_word = IXGBE_EEPROM_CHECKSUM;
u16 ptr_start = IXGBE_PCIE_ANALOG_PTR;
for (i = 0; i < checksum_last_word; i++) {
if (ixgbe_read_eerd_generic(hw, i, &word)) {
hw_dbg(hw, "EEPROM read failed\n");
return IXGBE_ERR_EEPROM;
}
checksum += word;
}
for (i = ptr_start; i < IXGBE_FW_PTR; i++) {
if (i == IXGBE_PHY_PTR || i == IXGBE_OPTION_ROM_PTR)
continue;
if (ixgbe_read_eerd_generic(hw, i, &pointer)) {
hw_dbg(hw, "EEPROM read failed\n");
break;
}
if (pointer == 0xFFFF || pointer == 0 ||
pointer >= hw->eeprom.word_size)
continue;
if (ixgbe_read_eerd_generic(hw, pointer, &length)) {
hw_dbg(hw, "EEPROM read failed\n");
return IXGBE_ERR_EEPROM;
break;
}
if (length == 0xFFFF || length == 0 ||
(pointer + length) >= hw->eeprom.word_size)
continue;
for (j = pointer + 1; j <= pointer + length; j++) {
if (ixgbe_read_eerd_generic(hw, j, &word)) {
hw_dbg(hw, "EEPROM read failed\n");
return IXGBE_ERR_EEPROM;
}
checksum += word;
}
}
checksum = (u16)IXGBE_EEPROM_SUM - checksum;
return (s32)checksum;
}
static s32 ixgbe_validate_eeprom_checksum_X540(struct ixgbe_hw *hw,
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
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM))
return IXGBE_ERR_SWFW_SYNC;
status = hw->eeprom.ops.calc_checksum(hw);
if (status < 0)
goto out;
checksum = (u16)(status & 0xffff);
status = ixgbe_read_eerd_generic(hw, IXGBE_EEPROM_CHECKSUM,
&read_checksum);
if (status)
goto out;
if (read_checksum != checksum) {
hw_dbg(hw, "Invalid EEPROM checksum");
status = IXGBE_ERR_EEPROM_CHECKSUM;
}
if (checksum_val)
*checksum_val = checksum;
out:
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
return status;
}
static s32 ixgbe_update_eeprom_checksum_X540(struct ixgbe_hw *hw)
{
s32 status;
u16 checksum;
status = hw->eeprom.ops.read(hw, 0, &checksum);
if (status) {
hw_dbg(hw, "EEPROM read failed\n");
return status;
}
if (hw->mac.ops.acquire_swfw_sync(hw, IXGBE_GSSR_EEP_SM))
return IXGBE_ERR_SWFW_SYNC;
status = hw->eeprom.ops.calc_checksum(hw);
if (status < 0)
goto out;
checksum = (u16)(status & 0xffff);
status = ixgbe_write_eewr_generic(hw, IXGBE_EEPROM_CHECKSUM, checksum);
if (status)
goto out;
status = ixgbe_update_flash_X540(hw);
out:
hw->mac.ops.release_swfw_sync(hw, IXGBE_GSSR_EEP_SM);
return status;
}
static s32 ixgbe_update_flash_X540(struct ixgbe_hw *hw)
{
u32 flup;
s32 status;
status = ixgbe_poll_flash_update_done_X540(hw);
if (status == IXGBE_ERR_EEPROM) {
hw_dbg(hw, "Flash update time out\n");
return status;
}
flup = IXGBE_READ_REG(hw, IXGBE_EEC(hw)) | IXGBE_EEC_FLUP;
IXGBE_WRITE_REG(hw, IXGBE_EEC(hw), flup);
status = ixgbe_poll_flash_update_done_X540(hw);
if (status == 0)
hw_dbg(hw, "Flash update complete\n");
else
hw_dbg(hw, "Flash update time out\n");
if (hw->revision_id == 0) {
flup = IXGBE_READ_REG(hw, IXGBE_EEC(hw));
if (flup & IXGBE_EEC_SEC1VAL) {
flup |= IXGBE_EEC_FLUP;
IXGBE_WRITE_REG(hw, IXGBE_EEC(hw), flup);
}
status = ixgbe_poll_flash_update_done_X540(hw);
if (status == 0)
hw_dbg(hw, "Flash update complete\n");
else
hw_dbg(hw, "Flash update time out\n");
}
return status;
}
static s32 ixgbe_poll_flash_update_done_X540(struct ixgbe_hw *hw)
{
u32 i;
u32 reg;
for (i = 0; i < IXGBE_FLUDONE_ATTEMPTS; i++) {
reg = IXGBE_READ_REG(hw, IXGBE_EEC(hw));
if (reg & IXGBE_EEC_FLUDONE)
return 0;
udelay(5);
}
return IXGBE_ERR_EEPROM;
}
s32 ixgbe_acquire_swfw_sync_X540(struct ixgbe_hw *hw, u32 mask)
{
u32 swfw_sync;
u32 swmask = mask;
u32 fwmask = mask << 5;
u32 hwmask = 0;
u32 timeout = 200;
u32 i;
if (swmask == IXGBE_GSSR_EEP_SM)
hwmask = IXGBE_GSSR_FLASH_SM;
for (i = 0; i < timeout; i++) {
if (ixgbe_get_swfw_sync_semaphore(hw))
return IXGBE_ERR_SWFW_SYNC;
swfw_sync = IXGBE_READ_REG(hw, IXGBE_SWFW_SYNC(hw));
if (!(swfw_sync & (fwmask | swmask | hwmask))) {
swfw_sync |= swmask;
IXGBE_WRITE_REG(hw, IXGBE_SWFW_SYNC(hw), swfw_sync);
ixgbe_release_swfw_sync_semaphore(hw);
break;
} else {
ixgbe_release_swfw_sync_semaphore(hw);
usleep_range(5000, 10000);
}
}
if (i >= timeout) {
swfw_sync = IXGBE_READ_REG(hw, IXGBE_SWFW_SYNC(hw));
if (swfw_sync & (fwmask | hwmask)) {
if (ixgbe_get_swfw_sync_semaphore(hw))
return IXGBE_ERR_SWFW_SYNC;
swfw_sync |= swmask;
IXGBE_WRITE_REG(hw, IXGBE_SWFW_SYNC(hw), swfw_sync);
ixgbe_release_swfw_sync_semaphore(hw);
}
}
usleep_range(5000, 10000);
return 0;
}
void ixgbe_release_swfw_sync_X540(struct ixgbe_hw *hw, u32 mask)
{
u32 swfw_sync;
u32 swmask = mask;
ixgbe_get_swfw_sync_semaphore(hw);
swfw_sync = IXGBE_READ_REG(hw, IXGBE_SWFW_SYNC(hw));
swfw_sync &= ~swmask;
IXGBE_WRITE_REG(hw, IXGBE_SWFW_SYNC(hw), swfw_sync);
ixgbe_release_swfw_sync_semaphore(hw);
usleep_range(5000, 10000);
}
static s32 ixgbe_get_swfw_sync_semaphore(struct ixgbe_hw *hw)
{
u32 timeout = 2000;
u32 i;
u32 swsm;
for (i = 0; i < timeout; i++) {
swsm = IXGBE_READ_REG(hw, IXGBE_SWSM(hw));
if (!(swsm & IXGBE_SWSM_SMBI))
break;
usleep_range(50, 100);
}
if (i == timeout) {
hw_dbg(hw,
"Software semaphore SMBI between device drivers not granted.\n");
return IXGBE_ERR_EEPROM;
}
for (i = 0; i < timeout; i++) {
swsm = IXGBE_READ_REG(hw, IXGBE_SWFW_SYNC(hw));
if (!(swsm & IXGBE_SWFW_REGSMP))
return 0;
usleep_range(50, 100);
}
return IXGBE_ERR_EEPROM;
}
static void ixgbe_release_swfw_sync_semaphore(struct ixgbe_hw *hw)
{
u32 swsm;
swsm = IXGBE_READ_REG(hw, IXGBE_SWFW_SYNC(hw));
swsm &= ~IXGBE_SWFW_REGSMP;
IXGBE_WRITE_REG(hw, IXGBE_SWFW_SYNC(hw), swsm);
swsm = IXGBE_READ_REG(hw, IXGBE_SWSM(hw));
swsm &= ~IXGBE_SWSM_SMBI;
IXGBE_WRITE_REG(hw, IXGBE_SWSM(hw), swsm);
IXGBE_WRITE_FLUSH(hw);
}
s32 ixgbe_blink_led_start_X540(struct ixgbe_hw *hw, u32 index)
{
u32 macc_reg;
u32 ledctl_reg;
ixgbe_link_speed speed;
bool link_up;
hw->mac.ops.check_link(hw, &speed, &link_up, false);
if (!link_up) {
macc_reg = IXGBE_READ_REG(hw, IXGBE_MACC);
macc_reg |= IXGBE_MACC_FLU | IXGBE_MACC_FSV_10G | IXGBE_MACC_FS;
IXGBE_WRITE_REG(hw, IXGBE_MACC, macc_reg);
}
ledctl_reg = IXGBE_READ_REG(hw, IXGBE_LEDCTL);
ledctl_reg &= ~IXGBE_LED_MODE_MASK(index);
ledctl_reg |= IXGBE_LED_BLINK(index);
IXGBE_WRITE_REG(hw, IXGBE_LEDCTL, ledctl_reg);
IXGBE_WRITE_FLUSH(hw);
return 0;
}
s32 ixgbe_blink_led_stop_X540(struct ixgbe_hw *hw, u32 index)
{
u32 macc_reg;
u32 ledctl_reg;
ledctl_reg = IXGBE_READ_REG(hw, IXGBE_LEDCTL);
ledctl_reg &= ~IXGBE_LED_MODE_MASK(index);
ledctl_reg |= IXGBE_LED_LINK_ACTIVE << IXGBE_LED_MODE_SHIFT(index);
ledctl_reg &= ~IXGBE_LED_BLINK(index);
IXGBE_WRITE_REG(hw, IXGBE_LEDCTL, ledctl_reg);
macc_reg = IXGBE_READ_REG(hw, IXGBE_MACC);
macc_reg &= ~(IXGBE_MACC_FLU | IXGBE_MACC_FSV_10G | IXGBE_MACC_FS);
IXGBE_WRITE_REG(hw, IXGBE_MACC, macc_reg);
IXGBE_WRITE_FLUSH(hw);
return 0;
}
