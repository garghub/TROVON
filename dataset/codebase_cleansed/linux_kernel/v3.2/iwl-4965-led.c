static int
iwl4965_send_led_cmd(struct iwl_priv *priv, struct iwl_led_cmd *led_cmd)
{
struct iwl_host_cmd cmd = {
.id = REPLY_LEDS_CMD,
.len = sizeof(struct iwl_led_cmd),
.data = led_cmd,
.flags = CMD_ASYNC,
.callback = NULL,
};
u32 reg;
reg = iwl_read32(priv, CSR_LED_REG);
if (reg != (reg & CSR_LED_BSM_CTRL_MSK))
iwl_write32(priv, CSR_LED_REG, reg & CSR_LED_BSM_CTRL_MSK);
return iwl_legacy_send_cmd(priv, &cmd);
}
void iwl4965_led_enable(struct iwl_priv *priv)
{
iwl_write32(priv, CSR_LED_REG, CSR_LED_REG_TRUN_ON);
}
