int iwl4965_eeprom_acquire_semaphore(struct iwl_priv *priv)
{
u16 count;
int ret;
for (count = 0; count < EEPROM_SEM_RETRY_LIMIT; count++) {
iwl_legacy_set_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM);
ret = iwl_poll_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM,
CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM,
EEPROM_SEM_TIMEOUT);
if (ret >= 0) {
IWL_DEBUG_IO(priv,
"Acquired semaphore after %d tries.\n",
count+1);
return ret;
}
}
return ret;
}
void iwl4965_eeprom_release_semaphore(struct iwl_priv *priv)
{
iwl_legacy_clear_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM);
}
int iwl4965_eeprom_check_version(struct iwl_priv *priv)
{
u16 eeprom_ver;
u16 calib_ver;
eeprom_ver = iwl_legacy_eeprom_query16(priv, EEPROM_VERSION);
calib_ver = iwl_legacy_eeprom_query16(priv,
EEPROM_4965_CALIB_VERSION_OFFSET);
if (eeprom_ver < priv->cfg->eeprom_ver ||
calib_ver < priv->cfg->eeprom_calib_ver)
goto err;
IWL_INFO(priv, "device EEPROM VER=0x%x, CALIB=0x%x\n",
eeprom_ver, calib_ver);
return 0;
err:
IWL_ERR(priv, "Unsupported (too old) EEPROM VER=0x%x < 0x%x "
"CALIB=0x%x < 0x%x\n",
eeprom_ver, priv->cfg->eeprom_ver,
calib_ver, priv->cfg->eeprom_calib_ver);
return -EINVAL;
}
void iwl4965_eeprom_get_mac(const struct iwl_priv *priv, u8 *mac)
{
const u8 *addr = iwl_legacy_eeprom_query_addr(priv,
EEPROM_MAC_ADDRESS);
memcpy(mac, addr, ETH_ALEN);
}
