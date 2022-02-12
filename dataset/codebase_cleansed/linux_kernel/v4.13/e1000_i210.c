static s32 igb_get_hw_semaphore_i210(struct e1000_hw *hw)
{
u32 swsm;
s32 timeout = hw->nvm.word_size + 1;
s32 i = 0;
while (i < timeout) {
swsm = rd32(E1000_SWSM);
if (!(swsm & E1000_SWSM_SMBI))
break;
udelay(50);
i++;
}
if (i == timeout) {
if (hw->dev_spec._82575.clear_semaphore_once) {
hw->dev_spec._82575.clear_semaphore_once = false;
igb_put_hw_semaphore(hw);
for (i = 0; i < timeout; i++) {
swsm = rd32(E1000_SWSM);
if (!(swsm & E1000_SWSM_SMBI))
break;
udelay(50);
}
}
if (i == timeout) {
hw_dbg("Driver can't access device - SMBI bit is set.\n");
return -E1000_ERR_NVM;
}
}
for (i = 0; i < timeout; i++) {
swsm = rd32(E1000_SWSM);
wr32(E1000_SWSM, swsm | E1000_SWSM_SWESMBI);
if (rd32(E1000_SWSM) & E1000_SWSM_SWESMBI)
break;
udelay(50);
}
if (i == timeout) {
igb_put_hw_semaphore(hw);
hw_dbg("Driver can't access the NVM\n");
return -E1000_ERR_NVM;
}
return 0;
}
static s32 igb_acquire_nvm_i210(struct e1000_hw *hw)
{
return igb_acquire_swfw_sync_i210(hw, E1000_SWFW_EEP_SM);
}
static void igb_release_nvm_i210(struct e1000_hw *hw)
{
igb_release_swfw_sync_i210(hw, E1000_SWFW_EEP_SM);
}
s32 igb_acquire_swfw_sync_i210(struct e1000_hw *hw, u16 mask)
{
u32 swfw_sync;
u32 swmask = mask;
u32 fwmask = mask << 16;
s32 ret_val = 0;
s32 i = 0, timeout = 200;
while (i < timeout) {
if (igb_get_hw_semaphore_i210(hw)) {
ret_val = -E1000_ERR_SWFW_SYNC;
goto out;
}
swfw_sync = rd32(E1000_SW_FW_SYNC);
if (!(swfw_sync & (fwmask | swmask)))
break;
igb_put_hw_semaphore(hw);
mdelay(5);
i++;
}
if (i == timeout) {
hw_dbg("Driver can't access resource, SW_FW_SYNC timeout.\n");
ret_val = -E1000_ERR_SWFW_SYNC;
goto out;
}
swfw_sync |= swmask;
wr32(E1000_SW_FW_SYNC, swfw_sync);
igb_put_hw_semaphore(hw);
out:
return ret_val;
}
void igb_release_swfw_sync_i210(struct e1000_hw *hw, u16 mask)
{
u32 swfw_sync;
while (igb_get_hw_semaphore_i210(hw))
;
swfw_sync = rd32(E1000_SW_FW_SYNC);
swfw_sync &= ~mask;
wr32(E1000_SW_FW_SYNC, swfw_sync);
igb_put_hw_semaphore(hw);
}
static s32 igb_read_nvm_srrd_i210(struct e1000_hw *hw, u16 offset, u16 words,
u16 *data)
{
s32 status = 0;
u16 i, count;
for (i = 0; i < words; i += E1000_EERD_EEWR_MAX_COUNT) {
count = (words - i) / E1000_EERD_EEWR_MAX_COUNT > 0 ?
E1000_EERD_EEWR_MAX_COUNT : (words - i);
if (!(hw->nvm.ops.acquire(hw))) {
status = igb_read_nvm_eerd(hw, offset, count,
data + i);
hw->nvm.ops.release(hw);
} else {
status = E1000_ERR_SWFW_SYNC;
}
if (status)
break;
}
return status;
}
static s32 igb_write_nvm_srwr(struct e1000_hw *hw, u16 offset, u16 words,
u16 *data)
{
struct e1000_nvm_info *nvm = &hw->nvm;
u32 i, k, eewr = 0;
u32 attempts = 100000;
s32 ret_val = 0;
if ((offset >= nvm->word_size) || (words > (nvm->word_size - offset)) ||
(words == 0)) {
hw_dbg("nvm parameter(s) out of bounds\n");
ret_val = -E1000_ERR_NVM;
goto out;
}
for (i = 0; i < words; i++) {
eewr = ((offset+i) << E1000_NVM_RW_ADDR_SHIFT) |
(data[i] << E1000_NVM_RW_REG_DATA) |
E1000_NVM_RW_REG_START;
wr32(E1000_SRWR, eewr);
for (k = 0; k < attempts; k++) {
if (E1000_NVM_RW_REG_DONE &
rd32(E1000_SRWR)) {
ret_val = 0;
break;
}
udelay(5);
}
if (ret_val) {
hw_dbg("Shadow RAM write EEWR timed out\n");
break;
}
}
out:
return ret_val;
}
static s32 igb_write_nvm_srwr_i210(struct e1000_hw *hw, u16 offset, u16 words,
u16 *data)
{
s32 status = 0;
u16 i, count;
for (i = 0; i < words; i += E1000_EERD_EEWR_MAX_COUNT) {
count = (words - i) / E1000_EERD_EEWR_MAX_COUNT > 0 ?
E1000_EERD_EEWR_MAX_COUNT : (words - i);
if (!(hw->nvm.ops.acquire(hw))) {
status = igb_write_nvm_srwr(hw, offset, count,
data + i);
hw->nvm.ops.release(hw);
} else {
status = E1000_ERR_SWFW_SYNC;
}
if (status)
break;
}
return status;
}
static s32 igb_read_invm_word_i210(struct e1000_hw *hw, u8 address, u16 *data)
{
s32 status = -E1000_ERR_INVM_VALUE_NOT_FOUND;
u32 invm_dword;
u16 i;
u8 record_type, word_address;
for (i = 0; i < E1000_INVM_SIZE; i++) {
invm_dword = rd32(E1000_INVM_DATA_REG(i));
record_type = INVM_DWORD_TO_RECORD_TYPE(invm_dword);
if (record_type == E1000_INVM_UNINITIALIZED_STRUCTURE)
break;
if (record_type == E1000_INVM_CSR_AUTOLOAD_STRUCTURE)
i += E1000_INVM_CSR_AUTOLOAD_DATA_SIZE_IN_DWORDS;
if (record_type == E1000_INVM_RSA_KEY_SHA256_STRUCTURE)
i += E1000_INVM_RSA_KEY_SHA256_DATA_SIZE_IN_DWORDS;
if (record_type == E1000_INVM_WORD_AUTOLOAD_STRUCTURE) {
word_address = INVM_DWORD_TO_WORD_ADDRESS(invm_dword);
if (word_address == address) {
*data = INVM_DWORD_TO_WORD_DATA(invm_dword);
hw_dbg("Read INVM Word 0x%02x = %x\n",
address, *data);
status = 0;
break;
}
}
}
if (status)
hw_dbg("Requested word 0x%02x not found in OTP\n", address);
return status;
}
static s32 igb_read_invm_i210(struct e1000_hw *hw, u16 offset,
u16 words __always_unused, u16 *data)
{
s32 ret_val = 0;
switch (offset) {
case NVM_MAC_ADDR:
ret_val = igb_read_invm_word_i210(hw, (u8)offset, &data[0]);
ret_val |= igb_read_invm_word_i210(hw, (u8)offset+1,
&data[1]);
ret_val |= igb_read_invm_word_i210(hw, (u8)offset+2,
&data[2]);
if (ret_val)
hw_dbg("MAC Addr not found in iNVM\n");
break;
case NVM_INIT_CTRL_2:
ret_val = igb_read_invm_word_i210(hw, (u8)offset, data);
if (ret_val) {
*data = NVM_INIT_CTRL_2_DEFAULT_I211;
ret_val = 0;
}
break;
case NVM_INIT_CTRL_4:
ret_val = igb_read_invm_word_i210(hw, (u8)offset, data);
if (ret_val) {
*data = NVM_INIT_CTRL_4_DEFAULT_I211;
ret_val = 0;
}
break;
case NVM_LED_1_CFG:
ret_val = igb_read_invm_word_i210(hw, (u8)offset, data);
if (ret_val) {
*data = NVM_LED_1_CFG_DEFAULT_I211;
ret_val = 0;
}
break;
case NVM_LED_0_2_CFG:
ret_val = igb_read_invm_word_i210(hw, (u8)offset, data);
if (ret_val) {
*data = NVM_LED_0_2_CFG_DEFAULT_I211;
ret_val = 0;
}
break;
case NVM_ID_LED_SETTINGS:
ret_val = igb_read_invm_word_i210(hw, (u8)offset, data);
if (ret_val) {
*data = ID_LED_RESERVED_FFFF;
ret_val = 0;
}
break;
case NVM_SUB_DEV_ID:
*data = hw->subsystem_device_id;
break;
case NVM_SUB_VEN_ID:
*data = hw->subsystem_vendor_id;
break;
case NVM_DEV_ID:
*data = hw->device_id;
break;
case NVM_VEN_ID:
*data = hw->vendor_id;
break;
default:
hw_dbg("NVM word 0x%02x is not mapped.\n", offset);
*data = NVM_RESERVED_WORD;
break;
}
return ret_val;
}
s32 igb_read_invm_version(struct e1000_hw *hw,
struct e1000_fw_version *invm_ver) {
u32 *record = NULL;
u32 *next_record = NULL;
u32 i = 0;
u32 invm_dword = 0;
u32 invm_blocks = E1000_INVM_SIZE - (E1000_INVM_ULT_BYTES_SIZE /
E1000_INVM_RECORD_SIZE_IN_BYTES);
u32 buffer[E1000_INVM_SIZE];
s32 status = -E1000_ERR_INVM_VALUE_NOT_FOUND;
u16 version = 0;
for (i = 0; i < E1000_INVM_SIZE; i++) {
invm_dword = rd32(E1000_INVM_DATA_REG(i));
buffer[i] = invm_dword;
}
for (i = 1; i < invm_blocks; i++) {
record = &buffer[invm_blocks - i];
next_record = &buffer[invm_blocks - i + 1];
if ((i == 1) && ((*record & E1000_INVM_VER_FIELD_ONE) == 0)) {
version = 0;
status = 0;
break;
}
else if ((i == 1) &&
((*record & E1000_INVM_VER_FIELD_TWO) == 0)) {
version = (*record & E1000_INVM_VER_FIELD_ONE) >> 3;
status = 0;
break;
}
else if ((((*record & E1000_INVM_VER_FIELD_ONE) == 0) &&
((*record & 0x3) == 0)) || (((*record & 0x3) != 0) &&
(i != 1))) {
version = (*next_record & E1000_INVM_VER_FIELD_TWO)
>> 13;
status = 0;
break;
}
else if (((*record & E1000_INVM_VER_FIELD_TWO) == 0) &&
((*record & 0x3) == 0)) {
version = (*record & E1000_INVM_VER_FIELD_ONE) >> 3;
status = 0;
break;
}
}
if (!status) {
invm_ver->invm_major = (version & E1000_INVM_MAJOR_MASK)
>> E1000_INVM_MAJOR_SHIFT;
invm_ver->invm_minor = version & E1000_INVM_MINOR_MASK;
}
for (i = 1; i < invm_blocks; i++) {
record = &buffer[invm_blocks - i];
next_record = &buffer[invm_blocks - i + 1];
if ((i == 1) && ((*record & E1000_INVM_IMGTYPE_FIELD) == 0)) {
invm_ver->invm_img_type = 0;
status = 0;
break;
}
else if ((((*record & 0x3) == 0) &&
((*record & E1000_INVM_IMGTYPE_FIELD) == 0)) ||
((((*record & 0x3) != 0) && (i != 1)))) {
invm_ver->invm_img_type =
(*next_record & E1000_INVM_IMGTYPE_FIELD) >> 23;
status = 0;
break;
}
}
return status;
}
static s32 igb_validate_nvm_checksum_i210(struct e1000_hw *hw)
{
s32 status = 0;
s32 (*read_op_ptr)(struct e1000_hw *, u16, u16, u16 *);
if (!(hw->nvm.ops.acquire(hw))) {
read_op_ptr = hw->nvm.ops.read;
hw->nvm.ops.read = igb_read_nvm_eerd;
status = igb_validate_nvm_checksum(hw);
hw->nvm.ops.read = read_op_ptr;
hw->nvm.ops.release(hw);
} else {
status = E1000_ERR_SWFW_SYNC;
}
return status;
}
static s32 igb_update_nvm_checksum_i210(struct e1000_hw *hw)
{
s32 ret_val = 0;
u16 checksum = 0;
u16 i, nvm_data;
ret_val = igb_read_nvm_eerd(hw, 0, 1, &nvm_data);
if (ret_val) {
hw_dbg("EEPROM read failed\n");
goto out;
}
if (!(hw->nvm.ops.acquire(hw))) {
for (i = 0; i < NVM_CHECKSUM_REG; i++) {
ret_val = igb_read_nvm_eerd(hw, i, 1, &nvm_data);
if (ret_val) {
hw->nvm.ops.release(hw);
hw_dbg("NVM Read Error while updating checksum.\n");
goto out;
}
checksum += nvm_data;
}
checksum = (u16) NVM_SUM - checksum;
ret_val = igb_write_nvm_srwr(hw, NVM_CHECKSUM_REG, 1,
&checksum);
if (ret_val) {
hw->nvm.ops.release(hw);
hw_dbg("NVM Write Error while updating checksum.\n");
goto out;
}
hw->nvm.ops.release(hw);
ret_val = igb_update_flash_i210(hw);
} else {
ret_val = -E1000_ERR_SWFW_SYNC;
}
out:
return ret_val;
}
static s32 igb_pool_flash_update_done_i210(struct e1000_hw *hw)
{
s32 ret_val = -E1000_ERR_NVM;
u32 i, reg;
for (i = 0; i < E1000_FLUDONE_ATTEMPTS; i++) {
reg = rd32(E1000_EECD);
if (reg & E1000_EECD_FLUDONE_I210) {
ret_val = 0;
break;
}
udelay(5);
}
return ret_val;
}
bool igb_get_flash_presence_i210(struct e1000_hw *hw)
{
u32 eec = 0;
bool ret_val = false;
eec = rd32(E1000_EECD);
if (eec & E1000_EECD_FLASH_DETECTED_I210)
ret_val = true;
return ret_val;
}
static s32 igb_update_flash_i210(struct e1000_hw *hw)
{
s32 ret_val = 0;
u32 flup;
ret_val = igb_pool_flash_update_done_i210(hw);
if (ret_val == -E1000_ERR_NVM) {
hw_dbg("Flash update time out\n");
goto out;
}
flup = rd32(E1000_EECD) | E1000_EECD_FLUPD_I210;
wr32(E1000_EECD, flup);
ret_val = igb_pool_flash_update_done_i210(hw);
if (ret_val)
hw_dbg("Flash update time out\n");
else
hw_dbg("Flash update complete\n");
out:
return ret_val;
}
s32 igb_valid_led_default_i210(struct e1000_hw *hw, u16 *data)
{
s32 ret_val;
ret_val = hw->nvm.ops.read(hw, NVM_ID_LED_SETTINGS, 1, data);
if (ret_val) {
hw_dbg("NVM Read Error\n");
goto out;
}
if (*data == ID_LED_RESERVED_0000 || *data == ID_LED_RESERVED_FFFF) {
switch (hw->phy.media_type) {
case e1000_media_type_internal_serdes:
*data = ID_LED_DEFAULT_I210_SERDES;
break;
case e1000_media_type_copper:
default:
*data = ID_LED_DEFAULT_I210;
break;
}
}
out:
return ret_val;
}
static s32 __igb_access_xmdio_reg(struct e1000_hw *hw, u16 address,
u8 dev_addr, u16 *data, bool read)
{
s32 ret_val = 0;
ret_val = hw->phy.ops.write_reg(hw, E1000_MMDAC, dev_addr);
if (ret_val)
return ret_val;
ret_val = hw->phy.ops.write_reg(hw, E1000_MMDAAD, address);
if (ret_val)
return ret_val;
ret_val = hw->phy.ops.write_reg(hw, E1000_MMDAC, E1000_MMDAC_FUNC_DATA |
dev_addr);
if (ret_val)
return ret_val;
if (read)
ret_val = hw->phy.ops.read_reg(hw, E1000_MMDAAD, data);
else
ret_val = hw->phy.ops.write_reg(hw, E1000_MMDAAD, *data);
if (ret_val)
return ret_val;
ret_val = hw->phy.ops.write_reg(hw, E1000_MMDAC, 0);
if (ret_val)
return ret_val;
return ret_val;
}
s32 igb_read_xmdio_reg(struct e1000_hw *hw, u16 addr, u8 dev_addr, u16 *data)
{
return __igb_access_xmdio_reg(hw, addr, dev_addr, data, true);
}
s32 igb_write_xmdio_reg(struct e1000_hw *hw, u16 addr, u8 dev_addr, u16 data)
{
return __igb_access_xmdio_reg(hw, addr, dev_addr, &data, false);
}
s32 igb_init_nvm_params_i210(struct e1000_hw *hw)
{
s32 ret_val = 0;
struct e1000_nvm_info *nvm = &hw->nvm;
nvm->ops.acquire = igb_acquire_nvm_i210;
nvm->ops.release = igb_release_nvm_i210;
nvm->ops.valid_led_default = igb_valid_led_default_i210;
if (igb_get_flash_presence_i210(hw)) {
hw->nvm.type = e1000_nvm_flash_hw;
nvm->ops.read = igb_read_nvm_srrd_i210;
nvm->ops.write = igb_write_nvm_srwr_i210;
nvm->ops.validate = igb_validate_nvm_checksum_i210;
nvm->ops.update = igb_update_nvm_checksum_i210;
} else {
hw->nvm.type = e1000_nvm_invm;
nvm->ops.read = igb_read_invm_i210;
nvm->ops.write = NULL;
nvm->ops.validate = NULL;
nvm->ops.update = NULL;
}
return ret_val;
}
s32 igb_pll_workaround_i210(struct e1000_hw *hw)
{
s32 ret_val;
u32 wuc, mdicnfg, ctrl, ctrl_ext, reg_val;
u16 nvm_word, phy_word, pci_word, tmp_nvm;
int i;
wuc = rd32(E1000_WUC);
mdicnfg = rd32(E1000_MDICNFG);
reg_val = mdicnfg & ~E1000_MDICNFG_EXT_MDIO;
wr32(E1000_MDICNFG, reg_val);
ret_val = igb_read_invm_word_i210(hw, E1000_INVM_AUTOLOAD,
&nvm_word);
if (ret_val)
nvm_word = E1000_INVM_DEFAULT_AL;
tmp_nvm = nvm_word | E1000_INVM_PLL_WO_VAL;
igb_write_phy_reg_82580(hw, I347AT4_PAGE_SELECT, E1000_PHY_PLL_FREQ_PAGE);
for (i = 0; i < E1000_MAX_PLL_TRIES; i++) {
igb_read_phy_reg_82580(hw, E1000_PHY_PLL_FREQ_REG, &phy_word);
if ((phy_word & E1000_PHY_PLL_UNCONF)
!= E1000_PHY_PLL_UNCONF) {
ret_val = 0;
break;
} else {
ret_val = -E1000_ERR_PHY;
}
ctrl = rd32(E1000_CTRL);
wr32(E1000_CTRL, ctrl|E1000_CTRL_PHY_RST);
ctrl_ext = rd32(E1000_CTRL_EXT);
ctrl_ext |= (E1000_CTRL_EXT_PHYPDEN | E1000_CTRL_EXT_SDLPE);
wr32(E1000_CTRL_EXT, ctrl_ext);
wr32(E1000_WUC, 0);
reg_val = (E1000_INVM_AUTOLOAD << 4) | (tmp_nvm << 16);
wr32(E1000_EEARBC_I210, reg_val);
igb_read_pci_cfg(hw, E1000_PCI_PMCSR, &pci_word);
pci_word |= E1000_PCI_PMCSR_D3;
igb_write_pci_cfg(hw, E1000_PCI_PMCSR, &pci_word);
usleep_range(1000, 2000);
pci_word &= ~E1000_PCI_PMCSR_D3;
igb_write_pci_cfg(hw, E1000_PCI_PMCSR, &pci_word);
reg_val = (E1000_INVM_AUTOLOAD << 4) | (nvm_word << 16);
wr32(E1000_EEARBC_I210, reg_val);
wr32(E1000_WUC, wuc);
}
igb_write_phy_reg_82580(hw, I347AT4_PAGE_SELECT, 0);
wr32(E1000_MDICNFG, mdicnfg);
return ret_val;
}
s32 igb_get_cfg_done_i210(struct e1000_hw *hw)
{
s32 timeout = PHY_CFG_TIMEOUT;
u32 mask = E1000_NVM_CFG_DONE_PORT_0;
while (timeout) {
if (rd32(E1000_EEMNGCTL_I210) & mask)
break;
usleep_range(1000, 2000);
timeout--;
}
if (!timeout)
hw_dbg("MNG configuration cycle has not completed.\n");
return 0;
}
