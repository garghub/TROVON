static int iwl_eeprom_acquire_semaphore(struct iwl_trans *trans)
{
u16 count;
int ret;
for (count = 0; count < EEPROM_SEM_RETRY_LIMIT; count++) {
iwl_set_bit(trans, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM);
ret = iwl_poll_bit(trans, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM,
CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM,
EEPROM_SEM_TIMEOUT);
if (ret >= 0) {
IWL_DEBUG_EEPROM(trans->dev,
"Acquired semaphore after %d tries.\n",
count+1);
return ret;
}
}
return ret;
}
static void iwl_eeprom_release_semaphore(struct iwl_trans *trans)
{
iwl_clear_bit(trans, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM);
}
static int iwl_eeprom_verify_signature(struct iwl_trans *trans, bool nvm_is_otp)
{
u32 gp = iwl_read32(trans, CSR_EEPROM_GP) & CSR_EEPROM_GP_VALID_MSK;
IWL_DEBUG_EEPROM(trans->dev, "EEPROM signature=0x%08x\n", gp);
switch (gp) {
case CSR_EEPROM_GP_BAD_SIG_EEP_GOOD_SIG_OTP:
if (!nvm_is_otp) {
IWL_ERR(trans, "EEPROM with bad signature: 0x%08x\n",
gp);
return -ENOENT;
}
return 0;
case CSR_EEPROM_GP_GOOD_SIG_EEP_LESS_THAN_4K:
case CSR_EEPROM_GP_GOOD_SIG_EEP_MORE_THAN_4K:
if (nvm_is_otp) {
IWL_ERR(trans, "OTP with bad signature: 0x%08x\n", gp);
return -ENOENT;
}
return 0;
case CSR_EEPROM_GP_BAD_SIGNATURE_BOTH_EEP_AND_OTP:
default:
IWL_ERR(trans,
"bad EEPROM/OTP signature, type=%s, EEPROM_GP=0x%08x\n",
nvm_is_otp ? "OTP" : "EEPROM", gp);
return -ENOENT;
}
}
static void iwl_set_otp_access_absolute(struct iwl_trans *trans)
{
iwl_read32(trans, CSR_OTP_GP_REG);
iwl_clear_bit(trans, CSR_OTP_GP_REG,
CSR_OTP_GP_REG_OTP_ACCESS_MODE);
}
static int iwl_nvm_is_otp(struct iwl_trans *trans)
{
u32 otpgp;
switch (trans->hw_rev & CSR_HW_REV_TYPE_MSK) {
case CSR_HW_REV_TYPE_NONE:
IWL_ERR(trans, "Unknown hardware type\n");
return -EIO;
case CSR_HW_REV_TYPE_5300:
case CSR_HW_REV_TYPE_5350:
case CSR_HW_REV_TYPE_5100:
case CSR_HW_REV_TYPE_5150:
return 0;
default:
otpgp = iwl_read32(trans, CSR_OTP_GP_REG);
if (otpgp & CSR_OTP_GP_REG_DEVICE_SELECT)
return 1;
return 0;
}
}
static int iwl_init_otp_access(struct iwl_trans *trans)
{
int ret;
iwl_write32(trans, CSR_GP_CNTRL,
iwl_read32(trans, CSR_GP_CNTRL) |
CSR_GP_CNTRL_REG_FLAG_INIT_DONE);
ret = iwl_poll_bit(trans, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_CLOCK_READY,
CSR_GP_CNTRL_REG_FLAG_MAC_CLOCK_READY,
25000);
if (ret < 0) {
IWL_ERR(trans, "Time out access OTP\n");
} else {
iwl_set_bits_prph(trans, APMG_PS_CTRL_REG,
APMG_PS_CTRL_VAL_RESET_REQ);
udelay(5);
iwl_clear_bits_prph(trans, APMG_PS_CTRL_REG,
APMG_PS_CTRL_VAL_RESET_REQ);
if (trans->cfg->base_params->shadow_ram_support)
iwl_set_bit(trans, CSR_DBG_LINK_PWR_MGMT_REG,
CSR_RESET_LINK_PWR_MGMT_DISABLED);
}
return ret;
}
static int iwl_read_otp_word(struct iwl_trans *trans, u16 addr,
__le16 *eeprom_data)
{
int ret = 0;
u32 r;
u32 otpgp;
iwl_write32(trans, CSR_EEPROM_REG,
CSR_EEPROM_REG_MSK_ADDR & (addr << 1));
ret = iwl_poll_bit(trans, CSR_EEPROM_REG,
CSR_EEPROM_REG_READ_VALID_MSK,
CSR_EEPROM_REG_READ_VALID_MSK,
IWL_EEPROM_ACCESS_TIMEOUT);
if (ret < 0) {
IWL_ERR(trans, "Time out reading OTP[%d]\n", addr);
return ret;
}
r = iwl_read32(trans, CSR_EEPROM_REG);
otpgp = iwl_read32(trans, CSR_OTP_GP_REG);
if (otpgp & CSR_OTP_GP_REG_ECC_UNCORR_STATUS_MSK) {
iwl_set_bit(trans, CSR_OTP_GP_REG,
CSR_OTP_GP_REG_ECC_UNCORR_STATUS_MSK);
IWL_ERR(trans, "Uncorrectable OTP ECC error, abort OTP read\n");
return -EINVAL;
}
if (otpgp & CSR_OTP_GP_REG_ECC_CORR_STATUS_MSK) {
iwl_set_bit(trans, CSR_OTP_GP_REG,
CSR_OTP_GP_REG_ECC_CORR_STATUS_MSK);
IWL_ERR(trans, "Correctable OTP ECC error, continue read\n");
}
*eeprom_data = cpu_to_le16(r >> 16);
return 0;
}
static bool iwl_is_otp_empty(struct iwl_trans *trans)
{
u16 next_link_addr = 0;
__le16 link_value;
bool is_empty = false;
if (!iwl_read_otp_word(trans, next_link_addr, &link_value)) {
if (!link_value) {
IWL_ERR(trans, "OTP is empty\n");
is_empty = true;
}
} else {
IWL_ERR(trans, "Unable to read first block of OTP list.\n");
is_empty = true;
}
return is_empty;
}
static int iwl_find_otp_image(struct iwl_trans *trans,
u16 *validblockaddr)
{
u16 next_link_addr = 0, valid_addr;
__le16 link_value = 0;
int usedblocks = 0;
iwl_set_otp_access_absolute(trans);
if (iwl_is_otp_empty(trans))
return -EINVAL;
do {
valid_addr = next_link_addr;
next_link_addr = le16_to_cpu(link_value) * sizeof(u16);
IWL_DEBUG_EEPROM(trans->dev, "OTP blocks %d addr 0x%x\n",
usedblocks, next_link_addr);
if (iwl_read_otp_word(trans, next_link_addr, &link_value))
return -EINVAL;
if (!link_value) {
*validblockaddr = valid_addr;
*validblockaddr += 2;
return 0;
}
usedblocks++;
} while (usedblocks <= trans->cfg->base_params->max_ll_items);
IWL_DEBUG_EEPROM(trans->dev, "OTP has no valid blocks\n");
return -EINVAL;
}
int iwl_read_eeprom(struct iwl_trans *trans, u8 **eeprom, size_t *eeprom_size)
{
__le16 *e;
u32 gp = iwl_read32(trans, CSR_EEPROM_GP);
int sz;
int ret;
u16 addr;
u16 validblockaddr = 0;
u16 cache_addr = 0;
int nvm_is_otp;
if (!eeprom || !eeprom_size)
return -EINVAL;
nvm_is_otp = iwl_nvm_is_otp(trans);
if (nvm_is_otp < 0)
return nvm_is_otp;
sz = trans->cfg->base_params->eeprom_size;
IWL_DEBUG_EEPROM(trans->dev, "NVM size = %d\n", sz);
e = kmalloc(sz, GFP_KERNEL);
if (!e)
return -ENOMEM;
ret = iwl_eeprom_verify_signature(trans, nvm_is_otp);
if (ret < 0) {
IWL_ERR(trans, "EEPROM not found, EEPROM_GP=0x%08x\n", gp);
goto err_free;
}
ret = iwl_eeprom_acquire_semaphore(trans);
if (ret < 0) {
IWL_ERR(trans, "Failed to acquire EEPROM semaphore.\n");
goto err_free;
}
if (nvm_is_otp) {
ret = iwl_init_otp_access(trans);
if (ret) {
IWL_ERR(trans, "Failed to initialize OTP access.\n");
goto err_unlock;
}
iwl_write32(trans, CSR_EEPROM_GP,
iwl_read32(trans, CSR_EEPROM_GP) &
~CSR_EEPROM_GP_IF_OWNER_MSK);
iwl_set_bit(trans, CSR_OTP_GP_REG,
CSR_OTP_GP_REG_ECC_CORR_STATUS_MSK |
CSR_OTP_GP_REG_ECC_UNCORR_STATUS_MSK);
if (!trans->cfg->base_params->shadow_ram_support) {
ret = iwl_find_otp_image(trans, &validblockaddr);
if (ret)
goto err_unlock;
}
for (addr = validblockaddr; addr < validblockaddr + sz;
addr += sizeof(u16)) {
__le16 eeprom_data;
ret = iwl_read_otp_word(trans, addr, &eeprom_data);
if (ret)
goto err_unlock;
e[cache_addr / 2] = eeprom_data;
cache_addr += sizeof(u16);
}
} else {
for (addr = 0; addr < sz; addr += sizeof(u16)) {
u32 r;
iwl_write32(trans, CSR_EEPROM_REG,
CSR_EEPROM_REG_MSK_ADDR & (addr << 1));
ret = iwl_poll_bit(trans, CSR_EEPROM_REG,
CSR_EEPROM_REG_READ_VALID_MSK,
CSR_EEPROM_REG_READ_VALID_MSK,
IWL_EEPROM_ACCESS_TIMEOUT);
if (ret < 0) {
IWL_ERR(trans,
"Time out reading EEPROM[%d]\n", addr);
goto err_unlock;
}
r = iwl_read32(trans, CSR_EEPROM_REG);
e[addr / 2] = cpu_to_le16(r >> 16);
}
}
IWL_DEBUG_EEPROM(trans->dev, "NVM Type: %s\n",
nvm_is_otp ? "OTP" : "EEPROM");
iwl_eeprom_release_semaphore(trans);
*eeprom_size = sz;
*eeprom = (u8 *)e;
return 0;
err_unlock:
iwl_eeprom_release_semaphore(trans);
err_free:
kfree(e);
return ret;
}
