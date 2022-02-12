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
i40e_debug(hw, I40E_DEBUG_NVM, "NVM init error: unsupported blank mode.\n");
}
return ret_code;
}
i40e_status i40e_acquire_nvm(struct i40e_hw *hw,
enum i40e_aq_resource_access_type access)
{
i40e_status ret_code = 0;
u64 gtime, timeout;
u64 time_left = 0;
if (hw->nvm.blank_nvm_mode)
goto i40e_i40e_acquire_nvm_exit;
ret_code = i40e_aq_request_resource(hw, I40E_NVM_RESOURCE_ID, access,
0, &time_left, NULL);
gtime = rd32(hw, I40E_GLVFGEN_TIMER);
hw->nvm.hw_semaphore_timeout = I40E_MS_TO_GTIME(time_left) + gtime;
if (ret_code)
i40e_debug(hw, I40E_DEBUG_NVM,
"NVM acquire type %d failed time_left=%llu ret=%d aq_err=%d\n",
access, time_left, ret_code, hw->aq.asq_last_status);
if (ret_code && time_left) {
timeout = I40E_MS_TO_GTIME(I40E_MAX_NVM_TIMEOUT) + gtime;
while ((gtime < timeout) && time_left) {
usleep_range(10000, 20000);
gtime = rd32(hw, I40E_GLVFGEN_TIMER);
ret_code = i40e_aq_request_resource(hw,
I40E_NVM_RESOURCE_ID,
access, 0, &time_left,
NULL);
if (!ret_code) {
hw->nvm.hw_semaphore_timeout =
I40E_MS_TO_GTIME(time_left) + gtime;
break;
}
}
if (ret_code) {
hw->nvm.hw_semaphore_timeout = 0;
i40e_debug(hw, I40E_DEBUG_NVM,
"NVM acquire timed out, wait %llu ms before trying again. status=%d aq_err=%d\n",
time_left, ret_code, hw->aq.asq_last_status);
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
i40e_debug(hw, I40E_DEBUG_NVM, "Done bit in GLNVM_SRCTL not set");
return ret_code;
}
i40e_status i40e_read_nvm_word(struct i40e_hw *hw, u16 offset,
u16 *data)
{
i40e_status ret_code = I40E_ERR_TIMEOUT;
u32 sr_reg;
if (offset >= hw->nvm.sr_size) {
i40e_debug(hw, I40E_DEBUG_NVM,
"NVM read error: offset %d beyond Shadow RAM limit %d\n",
offset, hw->nvm.sr_size);
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
i40e_debug(hw, I40E_DEBUG_NVM,
"NVM read error: Couldn't access Shadow RAM address: 0x%x\n",
offset);
read_nvm_exit:
return ret_code;
}
i40e_status i40e_read_nvm_buffer(struct i40e_hw *hw, u16 offset,
u16 *words, u16 *data)
{
i40e_status ret_code = 0;
u16 index, word;
for (word = 0; word < *words; word++) {
index = offset + word;
ret_code = i40e_read_nvm_word(hw, index, &data[word]);
if (ret_code)
break;
}
*words = word;
return ret_code;
}
static i40e_status i40e_write_nvm_aq(struct i40e_hw *hw, u8 module_pointer,
u32 offset, u16 words, void *data,
bool last_command)
{
i40e_status ret_code = I40E_ERR_NVM;
if ((offset + words) > hw->nvm.sr_size)
i40e_debug(hw, I40E_DEBUG_NVM,
"NVM write error: offset %d beyond Shadow RAM limit %d\n",
(offset + words), hw->nvm.sr_size);
else if (words > I40E_SR_SECTOR_SIZE_IN_WORDS)
i40e_debug(hw, I40E_DEBUG_NVM,
"NVM write fail error: tried to write %d words, limit is %d.\n",
words, I40E_SR_SECTOR_SIZE_IN_WORDS);
else if (((offset + (words - 1)) / I40E_SR_SECTOR_SIZE_IN_WORDS)
!= (offset / I40E_SR_SECTOR_SIZE_IN_WORDS))
i40e_debug(hw, I40E_DEBUG_NVM,
"NVM write error: cannot spread over two sectors in a single write offset=%d words=%d\n",
offset, words);
else
ret_code = i40e_aq_update_nvm(hw, module_pointer,
2 * offset,
2 * words,
data, last_command, NULL);
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
ret_code = i40e_read_nvm_word(hw, I40E_SR_VPD_PTR, &vpd_module);
if (ret_code) {
ret_code = I40E_ERR_NVM_CHECKSUM;
goto i40e_calc_nvm_checksum_exit;
}
ret_code = i40e_read_nvm_word(hw, I40E_SR_PCIE_ALT_AUTO_LOAD_PTR,
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
ret_code = i40e_read_nvm_word(hw, (u16)i, &word);
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
i40e_status i40e_update_nvm_checksum(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
u16 checksum;
ret_code = i40e_calc_nvm_checksum(hw, &checksum);
if (!ret_code)
ret_code = i40e_write_nvm_aq(hw, 0x00, I40E_SR_SW_CHECKSUM_WORD,
1, &checksum, true);
return ret_code;
}
i40e_status i40e_validate_nvm_checksum(struct i40e_hw *hw,
u16 *checksum)
{
i40e_status ret_code = 0;
u16 checksum_sr = 0;
u16 checksum_local = 0;
ret_code = i40e_calc_nvm_checksum(hw, &checksum_local);
if (ret_code)
goto i40e_validate_nvm_checksum_exit;
i40e_read_nvm_word(hw, I40E_SR_SW_CHECKSUM_WORD, &checksum_sr);
if (checksum_local != checksum_sr)
ret_code = I40E_ERR_NVM_CHECKSUM;
if (checksum)
*checksum = checksum_local;
i40e_validate_nvm_checksum_exit:
return ret_code;
}
static inline u8 i40e_nvmupd_get_module(u32 val)
{
return (u8)(val & I40E_NVM_MOD_PNT_MASK);
}
static inline u8 i40e_nvmupd_get_transaction(u32 val)
{
return (u8)((val & I40E_NVM_TRANS_MASK) >> I40E_NVM_TRANS_SHIFT);
}
i40e_status i40e_nvmupd_command(struct i40e_hw *hw,
struct i40e_nvm_access *cmd,
u8 *bytes, int *errno)
{
i40e_status status;
*errno = 0;
switch (hw->nvmupd_state) {
case I40E_NVMUPD_STATE_INIT:
status = i40e_nvmupd_state_init(hw, cmd, bytes, errno);
break;
case I40E_NVMUPD_STATE_READING:
status = i40e_nvmupd_state_reading(hw, cmd, bytes, errno);
break;
case I40E_NVMUPD_STATE_WRITING:
status = i40e_nvmupd_state_writing(hw, cmd, bytes, errno);
break;
default:
i40e_debug(hw, I40E_DEBUG_NVM,
"NVMUPD: no such state %d\n", hw->nvmupd_state);
status = I40E_NOT_SUPPORTED;
*errno = -ESRCH;
break;
}
return status;
}
static i40e_status i40e_nvmupd_state_init(struct i40e_hw *hw,
struct i40e_nvm_access *cmd,
u8 *bytes, int *errno)
{
i40e_status status = 0;
enum i40e_nvmupd_cmd upd_cmd;
upd_cmd = i40e_nvmupd_validate_command(hw, cmd, errno);
switch (upd_cmd) {
case I40E_NVMUPD_READ_SA:
status = i40e_acquire_nvm(hw, I40E_RESOURCE_READ);
if (status) {
*errno = i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status);
} else {
status = i40e_nvmupd_nvm_read(hw, cmd, bytes, errno);
i40e_release_nvm(hw);
}
break;
case I40E_NVMUPD_READ_SNT:
status = i40e_acquire_nvm(hw, I40E_RESOURCE_READ);
if (status) {
*errno = i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status);
} else {
status = i40e_nvmupd_nvm_read(hw, cmd, bytes, errno);
if (status)
i40e_release_nvm(hw);
else
hw->nvmupd_state = I40E_NVMUPD_STATE_READING;
}
break;
case I40E_NVMUPD_WRITE_ERA:
status = i40e_acquire_nvm(hw, I40E_RESOURCE_WRITE);
if (status) {
*errno = i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status);
} else {
status = i40e_nvmupd_nvm_erase(hw, cmd, errno);
if (status)
i40e_release_nvm(hw);
else
hw->aq.nvm_release_on_done = true;
}
break;
case I40E_NVMUPD_WRITE_SA:
status = i40e_acquire_nvm(hw, I40E_RESOURCE_WRITE);
if (status) {
*errno = i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status);
} else {
status = i40e_nvmupd_nvm_write(hw, cmd, bytes, errno);
if (status)
i40e_release_nvm(hw);
else
hw->aq.nvm_release_on_done = true;
}
break;
case I40E_NVMUPD_WRITE_SNT:
status = i40e_acquire_nvm(hw, I40E_RESOURCE_WRITE);
if (status) {
*errno = i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status);
} else {
status = i40e_nvmupd_nvm_write(hw, cmd, bytes, errno);
if (status)
i40e_release_nvm(hw);
else
hw->nvmupd_state = I40E_NVMUPD_STATE_WRITING;
}
break;
case I40E_NVMUPD_CSUM_SA:
status = i40e_acquire_nvm(hw, I40E_RESOURCE_WRITE);
if (status) {
*errno = i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status);
} else {
status = i40e_update_nvm_checksum(hw);
if (status) {
*errno = hw->aq.asq_last_status ?
i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status) :
-EIO;
i40e_release_nvm(hw);
} else {
hw->aq.nvm_release_on_done = true;
}
}
break;
default:
i40e_debug(hw, I40E_DEBUG_NVM,
"NVMUPD: bad cmd %s in init state\n",
i40e_nvm_update_state_str[upd_cmd]);
status = I40E_ERR_NVM;
*errno = -ESRCH;
break;
}
return status;
}
static i40e_status i40e_nvmupd_state_reading(struct i40e_hw *hw,
struct i40e_nvm_access *cmd,
u8 *bytes, int *errno)
{
i40e_status status;
enum i40e_nvmupd_cmd upd_cmd;
upd_cmd = i40e_nvmupd_validate_command(hw, cmd, errno);
switch (upd_cmd) {
case I40E_NVMUPD_READ_SA:
case I40E_NVMUPD_READ_CON:
status = i40e_nvmupd_nvm_read(hw, cmd, bytes, errno);
break;
case I40E_NVMUPD_READ_LCB:
status = i40e_nvmupd_nvm_read(hw, cmd, bytes, errno);
i40e_release_nvm(hw);
hw->nvmupd_state = I40E_NVMUPD_STATE_INIT;
break;
default:
i40e_debug(hw, I40E_DEBUG_NVM,
"NVMUPD: bad cmd %s in reading state.\n",
i40e_nvm_update_state_str[upd_cmd]);
status = I40E_NOT_SUPPORTED;
*errno = -ESRCH;
break;
}
return status;
}
static i40e_status i40e_nvmupd_state_writing(struct i40e_hw *hw,
struct i40e_nvm_access *cmd,
u8 *bytes, int *errno)
{
i40e_status status;
enum i40e_nvmupd_cmd upd_cmd;
bool retry_attempt = false;
upd_cmd = i40e_nvmupd_validate_command(hw, cmd, errno);
retry:
switch (upd_cmd) {
case I40E_NVMUPD_WRITE_CON:
status = i40e_nvmupd_nvm_write(hw, cmd, bytes, errno);
break;
case I40E_NVMUPD_WRITE_LCB:
status = i40e_nvmupd_nvm_write(hw, cmd, bytes, errno);
if (!status)
hw->aq.nvm_release_on_done = true;
hw->nvmupd_state = I40E_NVMUPD_STATE_INIT;
break;
case I40E_NVMUPD_CSUM_CON:
status = i40e_update_nvm_checksum(hw);
if (status) {
*errno = hw->aq.asq_last_status ?
i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status) :
-EIO;
hw->nvmupd_state = I40E_NVMUPD_STATE_INIT;
}
break;
case I40E_NVMUPD_CSUM_LCB:
status = i40e_update_nvm_checksum(hw);
if (status)
*errno = hw->aq.asq_last_status ?
i40e_aq_rc_to_posix(status,
hw->aq.asq_last_status) :
-EIO;
else
hw->aq.nvm_release_on_done = true;
hw->nvmupd_state = I40E_NVMUPD_STATE_INIT;
break;
default:
i40e_debug(hw, I40E_DEBUG_NVM,
"NVMUPD: bad cmd %s in writing state.\n",
i40e_nvm_update_state_str[upd_cmd]);
status = I40E_NOT_SUPPORTED;
*errno = -ESRCH;
break;
}
if (status && (hw->aq.asq_last_status == I40E_AQ_RC_EBUSY) &&
!retry_attempt) {
i40e_status old_status = status;
u32 old_asq_status = hw->aq.asq_last_status;
u32 gtime;
gtime = rd32(hw, I40E_GLVFGEN_TIMER);
if (gtime >= hw->nvm.hw_semaphore_timeout) {
i40e_debug(hw, I40E_DEBUG_ALL,
"NVMUPD: write semaphore expired (%d >= %lld), retrying\n",
gtime, hw->nvm.hw_semaphore_timeout);
i40e_release_nvm(hw);
status = i40e_acquire_nvm(hw, I40E_RESOURCE_WRITE);
if (status) {
i40e_debug(hw, I40E_DEBUG_ALL,
"NVMUPD: write semaphore reacquire failed aq_err = %d\n",
hw->aq.asq_last_status);
status = old_status;
hw->aq.asq_last_status = old_asq_status;
} else {
retry_attempt = true;
goto retry;
}
}
}
return status;
}
static enum i40e_nvmupd_cmd i40e_nvmupd_validate_command(struct i40e_hw *hw,
struct i40e_nvm_access *cmd,
int *errno)
{
enum i40e_nvmupd_cmd upd_cmd;
u8 transaction, module;
upd_cmd = I40E_NVMUPD_INVALID;
transaction = i40e_nvmupd_get_transaction(cmd->config);
module = i40e_nvmupd_get_module(cmd->config);
if ((cmd->data_size < 1) ||
(cmd->data_size > I40E_NVMUPD_MAX_DATA)) {
i40e_debug(hw, I40E_DEBUG_NVM,
"i40e_nvmupd_validate_command data_size %d\n",
cmd->data_size);
*errno = -EFAULT;
return I40E_NVMUPD_INVALID;
}
switch (cmd->command) {
case I40E_NVM_READ:
switch (transaction) {
case I40E_NVM_CON:
upd_cmd = I40E_NVMUPD_READ_CON;
break;
case I40E_NVM_SNT:
upd_cmd = I40E_NVMUPD_READ_SNT;
break;
case I40E_NVM_LCB:
upd_cmd = I40E_NVMUPD_READ_LCB;
break;
case I40E_NVM_SA:
upd_cmd = I40E_NVMUPD_READ_SA;
break;
}
break;
case I40E_NVM_WRITE:
switch (transaction) {
case I40E_NVM_CON:
upd_cmd = I40E_NVMUPD_WRITE_CON;
break;
case I40E_NVM_SNT:
upd_cmd = I40E_NVMUPD_WRITE_SNT;
break;
case I40E_NVM_LCB:
upd_cmd = I40E_NVMUPD_WRITE_LCB;
break;
case I40E_NVM_SA:
upd_cmd = I40E_NVMUPD_WRITE_SA;
break;
case I40E_NVM_ERA:
upd_cmd = I40E_NVMUPD_WRITE_ERA;
break;
case I40E_NVM_CSUM:
upd_cmd = I40E_NVMUPD_CSUM_CON;
break;
case (I40E_NVM_CSUM|I40E_NVM_SA):
upd_cmd = I40E_NVMUPD_CSUM_SA;
break;
case (I40E_NVM_CSUM|I40E_NVM_LCB):
upd_cmd = I40E_NVMUPD_CSUM_LCB;
break;
}
break;
}
i40e_debug(hw, I40E_DEBUG_NVM, "%s state %d nvm_release_on_hold %d\n",
i40e_nvm_update_state_str[upd_cmd],
hw->nvmupd_state,
hw->aq.nvm_release_on_done);
if (upd_cmd == I40E_NVMUPD_INVALID) {
*errno = -EFAULT;
i40e_debug(hw, I40E_DEBUG_NVM,
"i40e_nvmupd_validate_command returns %d errno %d\n",
upd_cmd, *errno);
}
return upd_cmd;
}
static i40e_status i40e_nvmupd_nvm_read(struct i40e_hw *hw,
struct i40e_nvm_access *cmd,
u8 *bytes, int *errno)
{
i40e_status status;
u8 module, transaction;
bool last;
transaction = i40e_nvmupd_get_transaction(cmd->config);
module = i40e_nvmupd_get_module(cmd->config);
last = (transaction == I40E_NVM_LCB) || (transaction == I40E_NVM_SA);
status = i40e_aq_read_nvm(hw, module, cmd->offset, (u16)cmd->data_size,
bytes, last, NULL);
if (status) {
i40e_debug(hw, I40E_DEBUG_NVM,
"i40e_nvmupd_nvm_read mod 0x%x off 0x%x len 0x%x\n",
module, cmd->offset, cmd->data_size);
i40e_debug(hw, I40E_DEBUG_NVM,
"i40e_nvmupd_nvm_read status %d aq %d\n",
status, hw->aq.asq_last_status);
*errno = i40e_aq_rc_to_posix(status, hw->aq.asq_last_status);
}
return status;
}
static i40e_status i40e_nvmupd_nvm_erase(struct i40e_hw *hw,
struct i40e_nvm_access *cmd,
int *errno)
{
i40e_status status = 0;
u8 module, transaction;
bool last;
transaction = i40e_nvmupd_get_transaction(cmd->config);
module = i40e_nvmupd_get_module(cmd->config);
last = (transaction & I40E_NVM_LCB);
status = i40e_aq_erase_nvm(hw, module, cmd->offset, (u16)cmd->data_size,
last, NULL);
if (status) {
i40e_debug(hw, I40E_DEBUG_NVM,
"i40e_nvmupd_nvm_erase mod 0x%x off 0x%x len 0x%x\n",
module, cmd->offset, cmd->data_size);
i40e_debug(hw, I40E_DEBUG_NVM,
"i40e_nvmupd_nvm_erase status %d aq %d\n",
status, hw->aq.asq_last_status);
*errno = i40e_aq_rc_to_posix(status, hw->aq.asq_last_status);
}
return status;
}
static i40e_status i40e_nvmupd_nvm_write(struct i40e_hw *hw,
struct i40e_nvm_access *cmd,
u8 *bytes, int *errno)
{
i40e_status status = 0;
u8 module, transaction;
bool last;
transaction = i40e_nvmupd_get_transaction(cmd->config);
module = i40e_nvmupd_get_module(cmd->config);
last = (transaction & I40E_NVM_LCB);
status = i40e_aq_update_nvm(hw, module, cmd->offset,
(u16)cmd->data_size, bytes, last, NULL);
if (status) {
i40e_debug(hw, I40E_DEBUG_NVM,
"i40e_nvmupd_nvm_write mod 0x%x off 0x%x len 0x%x\n",
module, cmd->offset, cmd->data_size);
i40e_debug(hw, I40E_DEBUG_NVM,
"i40e_nvmupd_nvm_write status %d aq %d\n",
status, hw->aq.asq_last_status);
*errno = i40e_aq_rc_to_posix(status, hw->aq.asq_last_status);
}
return status;
}
