static void ath_detect_bt_priority(struct ath9k_htc_priv *priv)
{
struct ath_btcoex *btcoex = &priv->btcoex;
struct ath_hw *ah = priv->ah;
if (ath9k_hw_gpio_get(ah, ah->btcoex_hw.btpriority_gpio))
btcoex->bt_priority_cnt++;
if (time_after(jiffies, btcoex->bt_priority_time +
msecs_to_jiffies(ATH_BT_PRIORITY_TIME_THRESHOLD))) {
priv->op_flags &= ~(OP_BT_PRIORITY_DETECTED | OP_BT_SCAN);
if (btcoex->bt_priority_cnt >= ATH_BT_CNT_SCAN_THRESHOLD) {
ath_dbg(ath9k_hw_common(ah), ATH_DBG_BTCOEX,
"BT scan detected\n");
priv->op_flags |= (OP_BT_SCAN |
OP_BT_PRIORITY_DETECTED);
} else if (btcoex->bt_priority_cnt >= ATH_BT_CNT_THRESHOLD) {
ath_dbg(ath9k_hw_common(ah), ATH_DBG_BTCOEX,
"BT priority traffic detected\n");
priv->op_flags |= OP_BT_PRIORITY_DETECTED;
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
bool is_btscan;
int ret;
ath_detect_bt_priority(priv);
is_btscan = !!(priv->op_flags & OP_BT_SCAN);
ret = ath9k_htc_update_cap_target(priv,
!!(priv->op_flags & OP_BT_PRIORITY_DETECTED));
if (ret) {
ath_err(common, "Unable to set BTCOEX parameters\n");
return;
}
ath9k_hw_btcoex_bt_stomp(priv->ah, is_btscan ? ATH_BTCOEX_STOMP_ALL :
btcoex->bt_stomp_type);
timer_period = is_btscan ? btcoex->btscan_no_stomp :
btcoex->btcoex_no_stomp;
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
bool is_btscan = priv->op_flags & OP_BT_SCAN;
ath_dbg(common, ATH_DBG_BTCOEX,
"time slice work for bt and wlan\n");
if (btcoex->bt_stomp_type == ATH_BTCOEX_STOMP_LOW || is_btscan)
ath9k_hw_btcoex_bt_stomp(ah, ATH_BTCOEX_STOMP_NONE);
else if (btcoex->bt_stomp_type == ATH_BTCOEX_STOMP_ALL)
ath9k_hw_btcoex_bt_stomp(ah, ATH_BTCOEX_STOMP_LOW);
}
void ath_htc_init_btcoex_work(struct ath9k_htc_priv *priv)
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
void ath_htc_resume_btcoex_work(struct ath9k_htc_priv *priv)
{
struct ath_btcoex *btcoex = &priv->btcoex;
struct ath_hw *ah = priv->ah;
ath_dbg(ath9k_hw_common(ah), ATH_DBG_BTCOEX, "Starting btcoex work\n");
btcoex->bt_priority_cnt = 0;
btcoex->bt_priority_time = jiffies;
priv->op_flags &= ~(OP_BT_PRIORITY_DETECTED | OP_BT_SCAN);
ieee80211_queue_delayed_work(priv->hw, &priv->coex_period_work, 0);
}
void ath_htc_cancel_btcoex_work(struct ath9k_htc_priv *priv)
{
cancel_delayed_work_sync(&priv->coex_period_work);
cancel_delayed_work_sync(&priv->duty_cycle_work);
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
ath9k_hw_cfg_output(priv->ah, priv->ah->led_pin,
AR_GPIO_OUTPUT_MUX_AS_OUTPUT);
ath9k_hw_set_gpio(priv->ah, priv->ah->led_pin, 1);
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
void ath9k_htc_radio_enable(struct ieee80211_hw *hw)
{
struct ath9k_htc_priv *priv = hw->priv;
struct ath_hw *ah = priv->ah;
struct ath_common *common = ath9k_hw_common(ah);
int ret;
u8 cmd_rsp;
if (!ah->curchan)
ah->curchan = ath9k_cmn_get_curchannel(hw, ah);
ret = ath9k_hw_reset(ah, ah->curchan, ah->caldata, false);
if (ret) {
ath_err(common,
"Unable to reset hardware; reset status %d (freq %u MHz)\n",
ret, ah->curchan->channel);
}
ath9k_cmn_update_txpow(ah, priv->curtxpow, priv->txpowlimit,
&priv->curtxpow);
WMI_CMD(WMI_START_RECV_CMDID);
ath9k_host_rx_init(priv);
htc_start(priv->htc);
spin_lock_bh(&priv->tx.tx_lock);
priv->tx.flags &= ~ATH9K_HTC_OP_TX_QUEUES_STOP;
spin_unlock_bh(&priv->tx.tx_lock);
ieee80211_wake_queues(hw);
WMI_CMD(WMI_ENABLE_INTR_CMDID);
ath9k_hw_cfg_output(ah, ah->led_pin,
AR_GPIO_OUTPUT_MUX_AS_OUTPUT);
ath9k_hw_set_gpio(ah, ah->led_pin, 0);
}
void ath9k_htc_radio_disable(struct ieee80211_hw *hw)
{
struct ath9k_htc_priv *priv = hw->priv;
struct ath_hw *ah = priv->ah;
struct ath_common *common = ath9k_hw_common(ah);
int ret;
u8 cmd_rsp;
ath9k_htc_ps_wakeup(priv);
ath9k_hw_set_gpio(ah, ah->led_pin, 1);
ath9k_hw_cfg_gpio_input(ah, ah->led_pin);
WMI_CMD(WMI_DISABLE_INTR_CMDID);
ieee80211_stop_queues(hw);
ath9k_htc_tx_drain(priv);
WMI_CMD(WMI_DRAIN_TXQ_ALL_CMDID);
WMI_CMD(WMI_STOP_RECV_CMDID);
ath9k_wmi_event_drain(priv);
ath9k_hw_disable_mib_counters(ah);
if (!ah->curchan)
ah->curchan = ath9k_cmn_get_curchannel(hw, ah);
ret = ath9k_hw_reset(ah, ah->curchan, ah->caldata, false);
if (ret) {
ath_err(common,
"Unable to reset hardware; reset status %d (freq %u MHz)\n",
ret, ah->curchan->channel);
}
ath9k_hw_phy_disable(ah);
ath9k_htc_ps_restore(priv);
ath9k_htc_setpower(priv, ATH9K_PM_FULL_SLEEP);
}
