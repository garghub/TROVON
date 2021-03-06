static void ath_detect_bt_priority(struct ath9k_htc_priv *priv)
{
struct ath_btcoex *btcoex = &priv->btcoex;
struct ath_hw *ah = priv->ah;
if (ath9k_hw_gpio_get(ah, ah->btcoex_hw.btpriority_gpio))
btcoex->bt_priority_cnt++;
if (time_after(jiffies, btcoex->bt_priority_time +
msecs_to_jiffies(ATH_BT_PRIORITY_TIME_THRESHOLD))) {
clear_bit(OP_BT_PRIORITY_DETECTED, &priv->op_flags);
clear_bit(OP_BT_SCAN, &priv->op_flags);
if (btcoex->bt_priority_cnt >= ATH_BT_CNT_SCAN_THRESHOLD) {
ath_dbg(ath9k_hw_common(ah), BTCOEX,
"BT scan detected\n");
set_bit(OP_BT_PRIORITY_DETECTED, &priv->op_flags);
set_bit(OP_BT_SCAN, &priv->op_flags);
} else if (btcoex->bt_priority_cnt >= ATH_BT_CNT_THRESHOLD) {
ath_dbg(ath9k_hw_common(ah), BTCOEX,
"BT priority traffic detected\n");
set_bit(OP_BT_PRIORITY_DETECTED, &priv->op_flags);
}
btcoex->bt_priority_cnt = 0;
btcoex->bt_priority_time = jiffies;
}
}
static void ath_btcoex_period_work(struct work_struct *work)
{
struct ath9k_htc_priv *priv = container_of(work, struct ath9k_htc_priv,
coex_period_work.work);
struct ath_btcoex *btcoex = &priv->btcoex;
struct ath_common *common = ath9k_hw_common(priv->ah);
u32 timer_period;
int ret;
ath_detect_bt_priority(priv);
ret = ath9k_htc_update_cap_target(priv,
test_bit(OP_BT_PRIORITY_DETECTED, &priv->op_flags));
if (ret) {
ath_err(common, "Unable to set BTCOEX parameters\n");
return;
}
ath9k_hw_btcoex_bt_stomp(priv->ah, test_bit(OP_BT_SCAN, &priv->op_flags) ?
ATH_BTCOEX_STOMP_ALL : btcoex->bt_stomp_type);
ath9k_hw_btcoex_enable(priv->ah);
timer_period = test_bit(OP_BT_SCAN, &priv->op_flags) ?
btcoex->btscan_no_stomp : btcoex->btcoex_no_stomp;
ieee80211_queue_delayed_work(priv->hw, &priv->duty_cycle_work,
msecs_to_jiffies(timer_period));
ieee80211_queue_delayed_work(priv->hw, &priv->coex_period_work,
msecs_to_jiffies(btcoex->btcoex_period));
}
static void ath_btcoex_duty_cycle_work(struct work_struct *work)
{
struct ath9k_htc_priv *priv = container_of(work, struct ath9k_htc_priv,
duty_cycle_work.work);
struct ath_hw *ah = priv->ah;
struct ath_btcoex *btcoex = &priv->btcoex;
struct ath_common *common = ath9k_hw_common(ah);
ath_dbg(common, BTCOEX, "time slice work for bt and wlan\n");
if (btcoex->bt_stomp_type == ATH_BTCOEX_STOMP_LOW ||
test_bit(OP_BT_SCAN, &priv->op_flags))
ath9k_hw_btcoex_bt_stomp(ah, ATH_BTCOEX_STOMP_NONE);
else if (btcoex->bt_stomp_type == ATH_BTCOEX_STOMP_ALL)
ath9k_hw_btcoex_bt_stomp(ah, ATH_BTCOEX_STOMP_LOW);
ath9k_hw_btcoex_enable(priv->ah);
}
static void ath_htc_init_btcoex_work(struct ath9k_htc_priv *priv)
{
struct ath_btcoex *btcoex = &priv->btcoex;
btcoex->btcoex_period = ATH_BTCOEX_DEF_BT_PERIOD;
btcoex->btcoex_no_stomp = (100 - ATH_BTCOEX_DEF_DUTY_CYCLE) *
btcoex->btcoex_period / 100;
btcoex->btscan_no_stomp = (100 - ATH_BTCOEX_BTSCAN_DUTY_CYCLE) *
btcoex->btcoex_period / 100;
INIT_DELAYED_WORK(&priv->coex_period_work, ath_btcoex_period_work);
INIT_DELAYED_WORK(&priv->duty_cycle_work, ath_btcoex_duty_cycle_work);
}
static void ath_htc_resume_btcoex_work(struct ath9k_htc_priv *priv)
{
struct ath_btcoex *btcoex = &priv->btcoex;
struct ath_hw *ah = priv->ah;
ath_dbg(ath9k_hw_common(ah), BTCOEX, "Starting btcoex work\n");
btcoex->bt_priority_cnt = 0;
btcoex->bt_priority_time = jiffies;
clear_bit(OP_BT_PRIORITY_DETECTED, &priv->op_flags);
clear_bit(OP_BT_SCAN, &priv->op_flags);
ieee80211_queue_delayed_work(priv->hw, &priv->coex_period_work, 0);
}
static void ath_htc_cancel_btcoex_work(struct ath9k_htc_priv *priv)
{
cancel_delayed_work_sync(&priv->coex_period_work);
cancel_delayed_work_sync(&priv->duty_cycle_work);
}
void ath9k_htc_start_btcoex(struct ath9k_htc_priv *priv)
{
struct ath_hw *ah = priv->ah;
if (ath9k_hw_get_btcoex_scheme(ah) == ATH_BTCOEX_CFG_3WIRE) {
ath9k_hw_btcoex_set_weight(ah, AR_BT_COEX_WGHT,
AR_STOMP_LOW_WLAN_WGHT, 0);
ath9k_hw_btcoex_enable(ah);
ath_htc_resume_btcoex_work(priv);
}
}
void ath9k_htc_stop_btcoex(struct ath9k_htc_priv *priv)
{
struct ath_hw *ah = priv->ah;
if (ah->btcoex_hw.enabled &&
ath9k_hw_get_btcoex_scheme(ah) != ATH_BTCOEX_CFG_NONE) {
if (ah->btcoex_hw.scheme == ATH_BTCOEX_CFG_3WIRE)
ath_htc_cancel_btcoex_work(priv);
ath9k_hw_btcoex_disable(ah);
}
}
void ath9k_htc_init_btcoex(struct ath9k_htc_priv *priv, char *product)
{
struct ath_hw *ah = priv->ah;
struct ath_common *common = ath9k_hw_common(ah);
int qnum;
if (!common->btcoex_enabled) {
ah->btcoex_hw.scheme = ATH_BTCOEX_CFG_NONE;
return;
}
if (product && strncmp(product, ATH_HTC_BTCOEX_PRODUCT_ID, 5) == 0) {
ah->btcoex_hw.scheme = ATH_BTCOEX_CFG_3WIRE;
}
switch (ath9k_hw_get_btcoex_scheme(priv->ah)) {
case ATH_BTCOEX_CFG_NONE:
break;
case ATH_BTCOEX_CFG_3WIRE:
priv->ah->btcoex_hw.btactive_gpio = 7;
priv->ah->btcoex_hw.btpriority_gpio = 6;
priv->ah->btcoex_hw.wlanactive_gpio = 8;
priv->btcoex.bt_stomp_type = ATH_BTCOEX_STOMP_LOW;
ath9k_hw_btcoex_init_3wire(priv->ah);
ath_htc_init_btcoex_work(priv);
qnum = priv->hwq_map[IEEE80211_AC_BE];
ath9k_hw_init_btcoex_hw(priv->ah, qnum);
break;
default:
WARN_ON(1);
break;
}
}
void ath9k_led_work(struct work_struct *work)
{
struct ath9k_htc_priv *priv = container_of(work,
struct ath9k_htc_priv,
led_work);
ath9k_hw_set_gpio(priv->ah, priv->ah->led_pin,
(priv->brightness == LED_OFF));
}
static void ath9k_led_brightness(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct ath9k_htc_priv *priv = container_of(led_cdev,
struct ath9k_htc_priv,
led_cdev);
priv->brightness = brightness;
ieee80211_queue_work(priv->hw, &priv->led_work);
}
void ath9k_deinit_leds(struct ath9k_htc_priv *priv)
{
if (!priv->led_registered)
return;
ath9k_led_brightness(&priv->led_cdev, LED_OFF);
led_classdev_unregister(&priv->led_cdev);
cancel_work_sync(&priv->led_work);
}
void ath9k_configure_leds(struct ath9k_htc_priv *priv)
{
ath9k_hw_cfg_output(priv->ah, priv->ah->led_pin,
AR_GPIO_OUTPUT_MUX_AS_OUTPUT);
ath9k_hw_set_gpio(priv->ah, priv->ah->led_pin, 1);
}
void ath9k_init_leds(struct ath9k_htc_priv *priv)
{
int ret;
if (AR_SREV_9287(priv->ah))
priv->ah->led_pin = ATH_LED_PIN_9287;
else if (AR_SREV_9271(priv->ah))
priv->ah->led_pin = ATH_LED_PIN_9271;
else if (AR_DEVID_7010(priv->ah))
priv->ah->led_pin = ATH_LED_PIN_7010;
else
priv->ah->led_pin = ATH_LED_PIN_DEF;
ath9k_configure_leds(priv);
snprintf(priv->led_name, sizeof(priv->led_name),
"ath9k_htc-%s", wiphy_name(priv->hw->wiphy));
priv->led_cdev.name = priv->led_name;
priv->led_cdev.brightness_set = ath9k_led_brightness;
ret = led_classdev_register(wiphy_dev(priv->hw->wiphy), &priv->led_cdev);
if (ret < 0)
return;
INIT_WORK(&priv->led_work, ath9k_led_work);
priv->led_registered = true;
return;
}
static bool ath_is_rfkill_set(struct ath9k_htc_priv *priv)
{
bool is_blocked;
ath9k_htc_ps_wakeup(priv);
is_blocked = ath9k_hw_gpio_get(priv->ah, priv->ah->rfkill_gpio) ==
priv->ah->rfkill_polarity;
ath9k_htc_ps_restore(priv);
return is_blocked;
}
void ath9k_htc_rfkill_poll_state(struct ieee80211_hw *hw)
{
struct ath9k_htc_priv *priv = hw->priv;
bool blocked = !!ath_is_rfkill_set(priv);
wiphy_rfkill_set_hw_state(hw->wiphy, blocked);
}
void ath9k_start_rfkill_poll(struct ath9k_htc_priv *priv)
{
if (priv->ah->caps.hw_caps & ATH9K_HW_CAP_RFSILENT)
wiphy_rfkill_start_polling(priv->hw->wiphy);
}
