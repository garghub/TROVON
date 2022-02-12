static int
iwl4965_verify_inst_sparse(struct iwl_priv *priv, __le32 *image, u32 len)
{
u32 val;
int ret = 0;
u32 errcnt = 0;
u32 i;
IWL_DEBUG_INFO(priv, "ucode inst image size is %u\n", len);
for (i = 0; i < len; i += 100, image += 100/sizeof(u32)) {
iwl_legacy_write_direct32(priv, HBUS_TARG_MEM_RADDR,
i + IWL4965_RTC_INST_LOWER_BOUND);
val = _iwl_legacy_read_direct32(priv, HBUS_TARG_MEM_RDAT);
if (val != le32_to_cpu(*image)) {
ret = -EIO;
errcnt++;
if (errcnt >= 3)
break;
}
}
return ret;
}
static int iwl4965_verify_inst_full(struct iwl_priv *priv, __le32 *image,
u32 len)
{
u32 val;
u32 save_len = len;
int ret = 0;
u32 errcnt;
IWL_DEBUG_INFO(priv, "ucode inst image size is %u\n", len);
iwl_legacy_write_direct32(priv, HBUS_TARG_MEM_RADDR,
IWL4965_RTC_INST_LOWER_BOUND);
errcnt = 0;
for (; len > 0; len -= sizeof(u32), image++) {
val = _iwl_legacy_read_direct32(priv, HBUS_TARG_MEM_RDAT);
if (val != le32_to_cpu(*image)) {
IWL_ERR(priv, "uCode INST section is invalid at "
"offset 0x%x, is 0x%x, s/b 0x%x\n",
save_len - len, val, le32_to_cpu(*image));
ret = -EIO;
errcnt++;
if (errcnt >= 20)
break;
}
}
if (!errcnt)
IWL_DEBUG_INFO(priv,
"ucode image in INSTRUCTION memory is good\n");
return ret;
}
int iwl4965_verify_ucode(struct iwl_priv *priv)
{
__le32 *image;
u32 len;
int ret;
image = (__le32 *)priv->ucode_boot.v_addr;
len = priv->ucode_boot.len;
ret = iwl4965_verify_inst_sparse(priv, image, len);
if (!ret) {
IWL_DEBUG_INFO(priv, "Bootstrap uCode is good in inst SRAM\n");
return 0;
}
image = (__le32 *)priv->ucode_init.v_addr;
len = priv->ucode_init.len;
ret = iwl4965_verify_inst_sparse(priv, image, len);
if (!ret) {
IWL_DEBUG_INFO(priv, "Initialize uCode is good in inst SRAM\n");
return 0;
}
image = (__le32 *)priv->ucode_code.v_addr;
len = priv->ucode_code.len;
ret = iwl4965_verify_inst_sparse(priv, image, len);
if (!ret) {
IWL_DEBUG_INFO(priv, "Runtime uCode is good in inst SRAM\n");
return 0;
}
IWL_ERR(priv, "NO VALID UCODE IMAGE IN INSTRUCTION SRAM!!\n");
image = (__le32 *)priv->ucode_boot.v_addr;
len = priv->ucode_boot.len;
ret = iwl4965_verify_inst_full(priv, image, len);
return ret;
}
