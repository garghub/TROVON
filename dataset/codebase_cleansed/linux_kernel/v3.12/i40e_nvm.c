i40e_status i40e_init_nvm(struct i40e_hw *hw)
{
struct i40e_nvm_info *nvm = &hw->nvm;
i40e_status ret_code = 0;
u32 fla, gens;
u8 sr_size;
gens = rd32(hw, I40E_GLNVM_GENS);
sr_size = ((gens & I40E_GLNVM_GENS_SR_SIZE_MASK) >>
I40E_GLNVM_GENS_SR_SIZE_SHIFT);
nvm->sr_size = (1 << sr_size) * I40E_SR_WORDS_IN_1KB;
fla = rd32(hw, I40E_GLNVM_FLA);
if (fla & I40E_GLNVM_FLA_LOCKED_MASK) {
nvm->timeout = I40E_MAX_NVM_TIMEOUT;
nvm->blank_nvm_mode = false;
} else {
nvm->blank_nvm_mode = true;
ret_code = I40E_ERR_NVM_BLANK_MODE;
hw_dbg(hw, "NVM init error: unsupported blank mode.\n");
}
return ret_code;
}
i40e_status i40e_acquire_nvm(struct i40e_hw *hw,
enum i40e_aq_resource_access_type access)
{
i40e_status ret_code = 0;
u64 gtime, timeout;
u64 time = 0;
if (hw->nvm.blank_nvm_mode)
goto i40e_i40e_acquire_nvm_exit;
ret_code = i40e_aq_request_resource(hw, I40E_NVM_RESOURCE_ID, access,
0, &time, NULL);
gtime = rd32(hw, I40E_GLVFGEN_TIMER);
hw->nvm.hw_semaphore_timeout = I40E_MS_TO_GTIME(time) + gtime;
if (ret_code) {
if (time > I40E_MAX_NVM_TIMEOUT)
timeout = I40E_MS_TO_GTIME(I40E_MAX_NVM_TIMEOUT)
+ gtime;
else
timeout = hw->nvm.hw_semaphore_timeout;
while (gtime < timeout) {
usleep_range(10000, 20000);
ret_code = i40e_aq_request_resource(hw,
I40E_NVM_RESOURCE_ID,
access, 0, &time,
NULL);
if (!ret_code) {
hw->nvm.hw_semaphore_timeout =
I40E_MS_TO_GTIME(time) + gtime;
break;
}
gtime = rd32(hw, I40E_GLVFGEN_TIMER);
}
if (ret_code) {
hw->nvm.hw_semaphore_timeout = 0;
hw->nvm.hw_semaphore_wait =
I40E_MS_TO_GTIME(time) + gtime;
hw_dbg(hw, "NVM acquire timed out, wait %llu ms before trying again.\n",
time);
}
}
i40e_i40e_acquire_nvm_exit:
return ret_code;
}
void i40e_release_nvm(struct i40e_hw *hw)
{
if (!hw->nvm.blank_nvm_mode)
i40e_aq_release_resource(hw, I40E_NVM_RESOURCE_ID, 0, NULL);
}
static i40e_status i40e_poll_sr_srctl_done_bit(struct i40e_hw *hw)
{
i40e_status ret_code = I40E_ERR_TIMEOUT;
u32 srctl, wait_cnt;
for (wait_cnt = 0; wait_cnt < I40E_SRRD_SRCTL_ATTEMPTS; wait_cnt++) {
srctl = rd32(hw, I40E_GLNVM_SRCTL);
if (srctl & I40E_GLNVM_SRCTL_DONE_MASK) {
ret_code = 0;
break;
}
udelay(5);
}
if (ret_code == I40E_ERR_TIMEOUT)
hw_dbg(hw, "Done bit in GLNVM_SRCTL not set");
return ret_code;
}
static i40e_status i40e_read_nvm_srctl(struct i40e_hw *hw, u16 offset,
u16 *data)
{
i40e_status ret_code = I40E_ERR_TIMEOUT;
u32 sr_reg;
if (offset >= hw->nvm.sr_size) {
hw_dbg(hw, "NVM read error: Offset beyond Shadow RAM limit.\n");
ret_code = I40E_ERR_PARAM;
goto read_nvm_exit;
}
ret_code = i40e_poll_sr_srctl_done_bit(hw);
if (!ret_code) {
sr_reg = (u32)(offset << I40E_GLNVM_SRCTL_ADDR_SHIFT) |
(1 << I40E_GLNVM_SRCTL_START_SHIFT);
wr32(hw, I40E_GLNVM_SRCTL, sr_reg);
ret_code = i40e_poll_sr_srctl_done_bit(hw);
if (!ret_code) {
sr_reg = rd32(hw, I40E_GLNVM_SRDATA);
*data = (u16)((sr_reg &
I40E_GLNVM_SRDATA_RDDATA_MASK)
>> I40E_GLNVM_SRDATA_RDDATA_SHIFT);
}
}
if (ret_code)
hw_dbg(hw, "NVM read error: Couldn't access Shadow RAM address: 0x%x\n",
offset);
read_nvm_exit:
return ret_code;
}
i40e_status i40e_read_nvm_word(struct i40e_hw *hw, u16 offset,
u16 *data)
{
i40e_status ret_code = 0;
ret_code = i40e_acquire_nvm(hw, I40E_RESOURCE_READ);
if (!ret_code) {
ret_code = i40e_read_nvm_srctl(hw, offset, data);
i40e_release_nvm(hw);
}
return ret_code;
}
i40e_status i40e_read_nvm_buffer(struct i40e_hw *hw, u16 offset,
u16 *words, u16 *data)
{
i40e_status ret_code = 0;
u16 index, word;
u32 time;
ret_code = i40e_acquire_nvm(hw, I40E_RESOURCE_READ);
if (!ret_code) {
for (word = 0; word < *words; word++) {
index = offset + word;
ret_code = i40e_read_nvm_srctl(hw, index, &data[word]);
if (ret_code)
break;
time = rd32(hw, I40E_GLVFGEN_TIMER);
if (time >= hw->nvm.hw_semaphore_timeout) {
ret_code = I40E_ERR_TIMEOUT;
hw_dbg(hw, "NVM read error: timeout.\n");
break;
}
}
*words = word;
i40e_release_nvm(hw);
}
return ret_code;
}
static i40e_status i40e_calc_nvm_checksum(struct i40e_hw *hw,
u16 *checksum)
{
i40e_status ret_code = 0;
u16 pcie_alt_module = 0;
u16 checksum_local = 0;
u16 vpd_module = 0;
u16 word = 0;
u32 i = 0;
ret_code = i40e_read_nvm_srctl(hw, I40E_SR_VPD_PTR, &vpd_module);
if (ret_code) {
ret_code = I40E_ERR_NVM_CHECKSUM;
goto i40e_calc_nvm_checksum_exit;
}
ret_code = i40e_read_nvm_srctl(hw, I40E_SR_PCIE_ALT_AUTO_LOAD_PTR,
&pcie_alt_module);
if (ret_code) {
ret_code = I40E_ERR_NVM_CHECKSUM;
goto i40e_calc_nvm_checksum_exit;
}
for (i = 0; i < hw->nvm.sr_size; i++) {
if (i == I40E_SR_SW_CHECKSUM_WORD)
i++;
if (i == (u32)vpd_module) {
i += (I40E_SR_VPD_MODULE_MAX_SIZE / 2);
if (i >= hw->nvm.sr_size)
break;
}
if (i == (u32)pcie_alt_module) {
i += (I40E_SR_PCIE_ALT_MODULE_MAX_SIZE / 2);
if (i >= hw->nvm.sr_size)
break;
}
ret_code = i40e_read_nvm_srctl(hw, (u16)i, &word);
if (ret_code) {
ret_code = I40E_ERR_NVM_CHECKSUM;
goto i40e_calc_nvm_checksum_exit;
}
checksum_local += word;
}
*checksum = (u16)I40E_SR_SW_CHECKSUM_BASE - checksum_local;
i40e_calc_nvm_checksum_exit:
return ret_code;
}
i40e_status i40e_validate_nvm_checksum(struct i40e_hw *hw,
u16 *checksum)
{
i40e_status ret_code = 0;
u16 checksum_sr = 0;
u16 checksum_local;
ret_code = i40e_acquire_nvm(hw, I40E_RESOURCE_READ);
if (ret_code)
goto i40e_validate_nvm_checksum_exit;
ret_code = i40e_calc_nvm_checksum(hw, &checksum_local);
if (ret_code)
goto i40e_validate_nvm_checksum_free;
i40e_read_nvm_srctl(hw, I40E_SR_SW_CHECKSUM_WORD, &checksum_sr);
if (checksum_local != checksum_sr)
ret_code = I40E_ERR_NVM_CHECKSUM;
if (checksum)
*checksum = checksum_local;
i40e_validate_nvm_checksum_free:
i40e_release_nvm(hw);
i40e_validate_nvm_checksum_exit:
return ret_code;
}
