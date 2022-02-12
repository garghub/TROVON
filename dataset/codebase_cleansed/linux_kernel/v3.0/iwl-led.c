static inline u8 iwl_legacy_blink_compensation(struct iwl_priv *priv,
u8 time, u16 compensation)
{
if (!compensation) {
IWL_ERR(priv, "undefined blink compensation: "
"use pre-defined blinking time\n");
return time;
}
return (u8)((time * compensation) >> 6);
}
static int iwl_legacy_led_cmd(struct iwl_priv *priv,
unsigned long on,
unsigned long off)
{
struct iwl_led_cmd led_cmd = {
.id = IWL_LED_LINK,
.interval = IWL_DEF_LED_INTRVL
};
int ret;
if (!test_bit(STATUS_READY, &priv->status))
return -EBUSY;
if (priv->blink_on == on && priv->blink_off == off)
return 0;
if (off == 0) {
on = IWL_LED_SOLID;
}
IWL_DEBUG_LED(priv, "Led blink time compensation=%u\n",
priv->cfg->base_params->led_compensation);
led_cmd.on = iwl_legacy_blink_compensation(priv, on,
priv->cfg->base_params->led_compensation);
led_cmd.off = iwl_legacy_blink_compensation(priv, off,
priv->cfg->base_params->led_compensation);
ret = priv->cfg->ops->led->cmd(priv, &led_cmd);
if (!ret) {
priv->blink_on = on;
priv->blink_off = off;
}
return ret;
}
static void iwl_legacy_led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct iwl_priv *priv = container_of(led_cdev, struct iwl_priv, led);
unsigned long on = 0;
if (brightness > 0)
on = IWL_LED_SOLID;
iwl_legacy_led_cmd(priv, on, 0);
}
static int iwl_legacy_led_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct iwl_priv *priv = container_of(led_cdev, struct iwl_priv, led);
return iwl_legacy_led_cmd(priv, *delay_on, *delay_off);
}
void iwl_legacy_leds_init(struct iwl_priv *priv)
{
int mode = led_mode;
int ret;
if (mode == IWL_LED_DEFAULT)
mode = priv->cfg->led_mode;
priv->led.name = kasprintf(GFP_KERNEL, "%s-led",
wiphy_name(priv->hw->wiphy));
priv->led.brightness_set = iwl_legacy_led_brightness_set;
priv->led.blink_set = iwl_legacy_led_blink_set;
priv->led.max_brightness = 1;
switch (mode) {
case IWL_LED_DEFAULT:
WARN_ON(1);
break;
case IWL_LED_BLINK:
priv->led.default_trigger =
ieee80211_create_tpt_led_trigger(priv->hw,
IEEE80211_TPT_LEDTRIG_FL_CONNECTED,
iwl_blink, ARRAY_SIZE(iwl_blink));
break;
case IWL_LED_RF_STATE:
priv->led.default_trigger =
ieee80211_get_radio_led_name(priv->hw);
break;
}
ret = led_classdev_register(&priv->pci_dev->dev, &priv->led);
if (ret) {
kfree(priv->led.name);
return;
}
priv->led_registered = true;
}
void iwl_legacy_leds_exit(struct iwl_priv *priv)
{
if (!priv->led_registered)
return;
led_classdev_unregister(&priv->led);
kfree(priv->led.name);
}
