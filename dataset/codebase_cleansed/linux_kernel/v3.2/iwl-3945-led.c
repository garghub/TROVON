static int iwl3945_send_led_cmd(struct iwl_priv *priv,
struct iwl_led_cmd *led_cmd)
{
struct iwl_host_cmd cmd = {
.id = REPLY_LEDS_CMD,
.len = sizeof(struct iwl_led_cmd),
.data = led_cmd,
.flags = CMD_ASYNC,
.callback = NULL,
};
return iwl_legacy_send_cmd(priv, &cmd);
}
