void ath9k_hw_init_btcoex_hw(struct ath_hw *ah, int qnum)
{
struct ath_btcoex_hw *btcoex_hw = &ah->btcoex_hw;
const struct ath_btcoex_config ath_bt_config = {
.bt_time_extend = 0,
.bt_txstate_extend = true,
.bt_txframe_extend = true,
.bt_mode = ATH_BT_COEX_MODE_SLOTTED,
.bt_quiet_collision = true,
.bt_rxclear_polarity = true,
.bt_priority_time = 2,
.bt_first_slot_time = 5,
.bt_hold_rx_clear = true,
};
u32 i, idx;
bool rxclear_polarity = ath_bt_config.bt_rxclear_polarity;
if (AR_SREV_9300_20_OR_LATER(ah))
rxclear_polarity = !ath_bt_config.bt_rxclear_polarity;
btcoex_hw->bt_coex_mode =
(btcoex_hw->bt_coex_mode & AR_BT_QCU_THRESH) |
SM(ath_bt_config.bt_time_extend, AR_BT_TIME_EXTEND) |
SM(ath_bt_config.bt_txstate_extend, AR_BT_TXSTATE_EXTEND) |
SM(ath_bt_config.bt_txframe_extend, AR_BT_TX_FRAME_EXTEND) |
SM(ath_bt_config.bt_mode, AR_BT_MODE) |
SM(ath_bt_config.bt_quiet_collision, AR_BT_QUIET) |
SM(rxclear_polarity, AR_BT_RX_CLEAR_POLARITY) |
SM(ath_bt_config.bt_priority_time, AR_BT_PRIORITY_TIME) |
SM(ath_bt_config.bt_first_slot_time, AR_BT_FIRST_SLOT_TIME) |
SM(qnum, AR_BT_QCU_THRESH);
btcoex_hw->bt_coex_mode2 =
SM(ath_bt_config.bt_hold_rx_clear, AR_BT_HOLD_RX_CLEAR) |
SM(ATH_BTCOEX_BMISS_THRESH, AR_BT_BCN_MISS_THRESH) |
AR_BT_DISABLE_BT_ANT;
for (i = 0; i < 32; i++) {
idx = (debruijn32 << i) >> 27;
ah->hw_gen_timers.gen_timer_index[idx] = i;
}
}
void ath9k_hw_btcoex_init_2wire(struct ath_hw *ah)
{
struct ath_btcoex_hw *btcoex_hw = &ah->btcoex_hw;
REG_CLR_BIT(ah, AR_GPIO_INPUT_EN_VAL,
(AR_GPIO_INPUT_EN_VAL_BT_PRIORITY_DEF |
AR_GPIO_INPUT_EN_VAL_BT_FREQUENCY_DEF));
REG_SET_BIT(ah, AR_GPIO_INPUT_EN_VAL,
AR_GPIO_INPUT_EN_VAL_BT_ACTIVE_BB);
REG_RMW_FIELD(ah, AR_GPIO_INPUT_MUX1,
AR_GPIO_INPUT_MUX1_BT_ACTIVE,
btcoex_hw->btactive_gpio);
ath9k_hw_cfg_gpio_input(ah, btcoex_hw->btactive_gpio);
}
void ath9k_hw_btcoex_init_3wire(struct ath_hw *ah)
{
struct ath_btcoex_hw *btcoex_hw = &ah->btcoex_hw;
REG_SET_BIT(ah, AR_GPIO_INPUT_EN_VAL,
(AR_GPIO_INPUT_EN_VAL_BT_PRIORITY_BB |
AR_GPIO_INPUT_EN_VAL_BT_ACTIVE_BB));
REG_RMW_FIELD(ah, AR_GPIO_INPUT_MUX1,
AR_GPIO_INPUT_MUX1_BT_ACTIVE,
btcoex_hw->btactive_gpio);
REG_RMW_FIELD(ah, AR_GPIO_INPUT_MUX1,
AR_GPIO_INPUT_MUX1_BT_PRIORITY,
btcoex_hw->btpriority_gpio);
ath9k_hw_cfg_gpio_input(ah, btcoex_hw->btactive_gpio);
ath9k_hw_cfg_gpio_input(ah, btcoex_hw->btpriority_gpio);
}
static void ath9k_hw_btcoex_enable_2wire(struct ath_hw *ah)
{
struct ath_btcoex_hw *btcoex_hw = &ah->btcoex_hw;
ath9k_hw_cfg_output(ah, btcoex_hw->wlanactive_gpio,
AR_GPIO_OUTPUT_MUX_AS_TX_FRAME);
}
void ath9k_hw_btcoex_set_weight(struct ath_hw *ah,
u32 bt_weight,
u32 wlan_weight)
{
struct ath_btcoex_hw *btcoex_hw = &ah->btcoex_hw;
btcoex_hw->bt_coex_weights = SM(bt_weight, AR_BTCOEX_BT_WGHT) |
SM(wlan_weight, AR_BTCOEX_WL_WGHT);
}
static void ath9k_hw_btcoex_enable_3wire(struct ath_hw *ah)
{
struct ath_btcoex_hw *btcoex_hw = &ah->btcoex_hw;
u32 val;
REG_WRITE(ah, AR_BT_COEX_MODE, btcoex_hw->bt_coex_mode);
REG_WRITE(ah, AR_BT_COEX_MODE2, btcoex_hw->bt_coex_mode2);
if (AR_SREV_9300_20_OR_LATER(ah)) {
REG_WRITE(ah, AR_BT_COEX_WL_WEIGHTS0, ah->bt_coex_wlan_weight[0]);
REG_WRITE(ah, AR_BT_COEX_WL_WEIGHTS1, ah->bt_coex_wlan_weight[1]);
REG_WRITE(ah, AR_BT_COEX_BT_WEIGHTS0, ah->bt_coex_bt_weight[0]);
REG_WRITE(ah, AR_BT_COEX_BT_WEIGHTS1, ah->bt_coex_bt_weight[1]);
REG_WRITE(ah, AR_BT_COEX_BT_WEIGHTS2, ah->bt_coex_bt_weight[2]);
REG_WRITE(ah, AR_BT_COEX_BT_WEIGHTS3, ah->bt_coex_bt_weight[3]);
} else
REG_WRITE(ah, AR_BT_COEX_WEIGHT, btcoex_hw->bt_coex_weights);
if (AR_SREV_9271(ah)) {
val = REG_READ(ah, 0x50040);
val &= 0xFFFFFEFF;
REG_WRITE(ah, 0x50040, val);
}
REG_RMW_FIELD(ah, AR_QUIET1, AR_QUIET1_QUIET_ACK_CTS_ENABLE, 1);
REG_RMW_FIELD(ah, AR_PCU_MISC, AR_PCU_BT_ANT_PREVENT_RX, 0);
ath9k_hw_cfg_output(ah, btcoex_hw->wlanactive_gpio,
AR_GPIO_OUTPUT_MUX_AS_RX_CLEAR_EXTERNAL);
}
void ath9k_hw_btcoex_enable(struct ath_hw *ah)
{
struct ath_btcoex_hw *btcoex_hw = &ah->btcoex_hw;
switch (btcoex_hw->scheme) {
case ATH_BTCOEX_CFG_NONE:
break;
case ATH_BTCOEX_CFG_2WIRE:
ath9k_hw_btcoex_enable_2wire(ah);
break;
case ATH_BTCOEX_CFG_3WIRE:
ath9k_hw_btcoex_enable_3wire(ah);
break;
}
REG_RMW(ah, AR_GPIO_PDPU,
(0x2 << (btcoex_hw->btactive_gpio * 2)),
(0x3 << (btcoex_hw->btactive_gpio * 2)));
ah->btcoex_hw.enabled = true;
}
void ath9k_hw_btcoex_disable(struct ath_hw *ah)
{
struct ath_btcoex_hw *btcoex_hw = &ah->btcoex_hw;
ath9k_hw_set_gpio(ah, btcoex_hw->wlanactive_gpio, 0);
ath9k_hw_cfg_output(ah, btcoex_hw->wlanactive_gpio,
AR_GPIO_OUTPUT_MUX_AS_OUTPUT);
if (btcoex_hw->scheme == ATH_BTCOEX_CFG_3WIRE) {
REG_WRITE(ah, AR_BT_COEX_MODE, AR_BT_QUIET | AR_BT_MODE);
REG_WRITE(ah, AR_BT_COEX_MODE2, 0);
if (AR_SREV_9300_20_OR_LATER(ah)) {
REG_WRITE(ah, AR_BT_COEX_WL_WEIGHTS0, 0);
REG_WRITE(ah, AR_BT_COEX_WL_WEIGHTS1, 0);
REG_WRITE(ah, AR_BT_COEX_BT_WEIGHTS0, 0);
REG_WRITE(ah, AR_BT_COEX_BT_WEIGHTS1, 0);
REG_WRITE(ah, AR_BT_COEX_BT_WEIGHTS2, 0);
REG_WRITE(ah, AR_BT_COEX_BT_WEIGHTS3, 0);
} else
REG_WRITE(ah, AR_BT_COEX_WEIGHT, 0);
}
ah->btcoex_hw.enabled = false;
}
static void ar9003_btcoex_bt_stomp(struct ath_hw *ah,
enum ath_stomp_type stomp_type)
{
ah->bt_coex_bt_weight[0] = AR9300_BT_WGHT;
ah->bt_coex_bt_weight[1] = AR9300_BT_WGHT;
ah->bt_coex_bt_weight[2] = AR9300_BT_WGHT;
ah->bt_coex_bt_weight[3] = AR9300_BT_WGHT;
switch (stomp_type) {
case ATH_BTCOEX_STOMP_ALL:
ah->bt_coex_wlan_weight[0] = AR9300_STOMP_ALL_WLAN_WGHT0;
ah->bt_coex_wlan_weight[1] = AR9300_STOMP_ALL_WLAN_WGHT1;
break;
case ATH_BTCOEX_STOMP_LOW:
ah->bt_coex_wlan_weight[0] = AR9300_STOMP_LOW_WLAN_WGHT0;
ah->bt_coex_wlan_weight[1] = AR9300_STOMP_LOW_WLAN_WGHT1;
break;
case ATH_BTCOEX_STOMP_NONE:
ah->bt_coex_wlan_weight[0] = AR9300_STOMP_NONE_WLAN_WGHT0;
ah->bt_coex_wlan_weight[1] = AR9300_STOMP_NONE_WLAN_WGHT1;
break;
default:
ath_dbg(ath9k_hw_common(ah), ATH_DBG_BTCOEX,
"Invalid Stomptype\n");
break;
}
ath9k_hw_btcoex_enable(ah);
}
void ath9k_hw_btcoex_bt_stomp(struct ath_hw *ah,
enum ath_stomp_type stomp_type)
{
if (AR_SREV_9300_20_OR_LATER(ah)) {
ar9003_btcoex_bt_stomp(ah, stomp_type);
return;
}
switch (stomp_type) {
case ATH_BTCOEX_STOMP_ALL:
ath9k_hw_btcoex_set_weight(ah, AR_BT_COEX_WGHT,
AR_STOMP_ALL_WLAN_WGHT);
break;
case ATH_BTCOEX_STOMP_LOW:
ath9k_hw_btcoex_set_weight(ah, AR_BT_COEX_WGHT,
AR_STOMP_LOW_WLAN_WGHT);
break;
case ATH_BTCOEX_STOMP_NONE:
ath9k_hw_btcoex_set_weight(ah, AR_BT_COEX_WGHT,
AR_STOMP_NONE_WLAN_WGHT);
break;
default:
ath_dbg(ath9k_hw_common(ah), ATH_DBG_BTCOEX,
"Invalid Stomptype\n");
break;
}
ath9k_hw_btcoex_enable(ah);
}
