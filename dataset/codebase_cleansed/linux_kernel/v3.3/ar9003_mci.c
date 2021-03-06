static void ar9003_mci_reset_req_wakeup(struct ath_hw *ah)
{
if (!AR_SREV_9462_20(ah))
return;
REG_RMW_FIELD(ah, AR_MCI_COMMAND2,
AR_MCI_COMMAND2_RESET_REQ_WAKEUP, 1);
udelay(1);
REG_RMW_FIELD(ah, AR_MCI_COMMAND2,
AR_MCI_COMMAND2_RESET_REQ_WAKEUP, 0);
}
static int ar9003_mci_wait_for_interrupt(struct ath_hw *ah, u32 address,
u32 bit_position, int time_out)
{
struct ath_common *common = ath9k_hw_common(ah);
while (time_out) {
if (REG_READ(ah, address) & bit_position) {
REG_WRITE(ah, address, bit_position);
if (address == AR_MCI_INTERRUPT_RX_MSG_RAW) {
if (bit_position &
AR_MCI_INTERRUPT_RX_MSG_REQ_WAKE)
ar9003_mci_reset_req_wakeup(ah);
if (bit_position &
(AR_MCI_INTERRUPT_RX_MSG_SYS_SLEEPING |
AR_MCI_INTERRUPT_RX_MSG_SYS_WAKING))
REG_WRITE(ah, AR_MCI_INTERRUPT_RAW,
AR_MCI_INTERRUPT_REMOTE_SLEEP_UPDATE);
REG_WRITE(ah, AR_MCI_INTERRUPT_RAW,
AR_MCI_INTERRUPT_RX_MSG);
}
break;
}
udelay(10);
time_out -= 10;
if (time_out < 0)
break;
}
if (time_out <= 0) {
ath_dbg(common, MCI,
"MCI Wait for Reg 0x%08x = 0x%08x timeout\n",
address, bit_position);
ath_dbg(common, MCI,
"MCI INT_RAW = 0x%08x, RX_MSG_RAW = 0x%08x\n",
REG_READ(ah, AR_MCI_INTERRUPT_RAW),
REG_READ(ah, AR_MCI_INTERRUPT_RX_MSG_RAW));
time_out = 0;
}
return time_out;
}
void ar9003_mci_remote_reset(struct ath_hw *ah, bool wait_done)
{
u32 payload[4] = { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff00};
if (!ATH9K_HW_CAP_MCI)
return;
ar9003_mci_send_message(ah, MCI_REMOTE_RESET, 0, payload, 16,
wait_done, false);
udelay(5);
}
void ar9003_mci_send_lna_transfer(struct ath_hw *ah, bool wait_done)
{
u32 payload = 0x00000000;
if (!ATH9K_HW_CAP_MCI)
return;
ar9003_mci_send_message(ah, MCI_LNA_TRANS, 0, &payload, 1,
wait_done, false);
}
static void ar9003_mci_send_req_wake(struct ath_hw *ah, bool wait_done)
{
ar9003_mci_send_message(ah, MCI_REQ_WAKE, MCI_FLAG_DISABLE_TIMESTAMP,
NULL, 0, wait_done, false);
udelay(5);
}
void ar9003_mci_send_sys_waking(struct ath_hw *ah, bool wait_done)
{
if (!ATH9K_HW_CAP_MCI)
return;
ar9003_mci_send_message(ah, MCI_SYS_WAKING, MCI_FLAG_DISABLE_TIMESTAMP,
NULL, 0, wait_done, false);
}
static void ar9003_mci_send_lna_take(struct ath_hw *ah, bool wait_done)
{
u32 payload = 0x70000000;
ar9003_mci_send_message(ah, MCI_LNA_TAKE, 0, &payload, 1,
wait_done, false);
}
static void ar9003_mci_send_sys_sleeping(struct ath_hw *ah, bool wait_done)
{
ar9003_mci_send_message(ah, MCI_SYS_SLEEPING,
MCI_FLAG_DISABLE_TIMESTAMP,
NULL, 0, wait_done, false);
}
static void ar9003_mci_send_coex_version_query(struct ath_hw *ah,
bool wait_done)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 payload[4] = {0, 0, 0, 0};
if (!mci->bt_version_known &&
(mci->bt_state != MCI_BT_SLEEP)) {
ath_dbg(common, MCI, "MCI Send Coex version query\n");
MCI_GPM_SET_TYPE_OPCODE(payload,
MCI_GPM_COEX_AGENT, MCI_GPM_COEX_VERSION_QUERY);
ar9003_mci_send_message(ah, MCI_GPM, 0, payload, 16,
wait_done, true);
}
}
static void ar9003_mci_send_coex_version_response(struct ath_hw *ah,
bool wait_done)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 payload[4] = {0, 0, 0, 0};
ath_dbg(common, MCI, "MCI Send Coex version response\n");
MCI_GPM_SET_TYPE_OPCODE(payload, MCI_GPM_COEX_AGENT,
MCI_GPM_COEX_VERSION_RESPONSE);
*(((u8 *)payload) + MCI_GPM_COEX_B_MAJOR_VERSION) =
mci->wlan_ver_major;
*(((u8 *)payload) + MCI_GPM_COEX_B_MINOR_VERSION) =
mci->wlan_ver_minor;
ar9003_mci_send_message(ah, MCI_GPM, 0, payload, 16, wait_done, true);
}
static void ar9003_mci_send_coex_wlan_channels(struct ath_hw *ah,
bool wait_done)
{
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 *payload = &mci->wlan_channels[0];
if ((mci->wlan_channels_update == true) &&
(mci->bt_state != MCI_BT_SLEEP)) {
MCI_GPM_SET_TYPE_OPCODE(payload,
MCI_GPM_COEX_AGENT, MCI_GPM_COEX_WLAN_CHANNELS);
ar9003_mci_send_message(ah, MCI_GPM, 0, payload, 16,
wait_done, true);
MCI_GPM_SET_TYPE_OPCODE(payload, 0xff, 0xff);
}
}
static void ar9003_mci_send_coex_bt_status_query(struct ath_hw *ah,
bool wait_done, u8 query_type)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 payload[4] = {0, 0, 0, 0};
bool query_btinfo = !!(query_type & (MCI_GPM_COEX_QUERY_BT_ALL_INFO |
MCI_GPM_COEX_QUERY_BT_TOPOLOGY));
if (mci->bt_state != MCI_BT_SLEEP) {
ath_dbg(common, MCI, "MCI Send Coex BT Status Query 0x%02X\n",
query_type);
MCI_GPM_SET_TYPE_OPCODE(payload,
MCI_GPM_COEX_AGENT, MCI_GPM_COEX_STATUS_QUERY);
*(((u8 *)payload) + MCI_GPM_COEX_B_BT_BITMAP) = query_type;
if (!ar9003_mci_send_message(ah, MCI_GPM, 0, payload, 16,
wait_done, true)) {
if (query_btinfo) {
mci->need_flush_btinfo = true;
ath_dbg(common, MCI,
"MCI send bt_status_query fail, set flush flag again\n");
}
}
if (query_btinfo)
mci->query_bt = false;
}
}
void ar9003_mci_send_coex_halt_bt_gpm(struct ath_hw *ah, bool halt,
bool wait_done)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 payload[4] = {0, 0, 0, 0};
if (!ATH9K_HW_CAP_MCI)
return;
ath_dbg(common, MCI, "MCI Send Coex %s BT GPM\n",
(halt) ? "halt" : "unhalt");
MCI_GPM_SET_TYPE_OPCODE(payload,
MCI_GPM_COEX_AGENT, MCI_GPM_COEX_HALT_BT_GPM);
if (halt) {
mci->query_bt = true;
mci->unhalt_bt_gpm = true;
mci->need_flush_btinfo = true;
*(((u8 *)payload) + MCI_GPM_COEX_B_HALT_STATE) =
MCI_GPM_COEX_BT_GPM_HALT;
} else
*(((u8 *)payload) + MCI_GPM_COEX_B_HALT_STATE) =
MCI_GPM_COEX_BT_GPM_UNHALT;
ar9003_mci_send_message(ah, MCI_GPM, 0, payload, 16, wait_done, true);
}
static void ar9003_mci_prep_interface(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 saved_mci_int_en;
u32 mci_timeout = 150;
mci->bt_state = MCI_BT_SLEEP;
saved_mci_int_en = REG_READ(ah, AR_MCI_INTERRUPT_EN);
REG_WRITE(ah, AR_MCI_INTERRUPT_EN, 0);
REG_WRITE(ah, AR_MCI_INTERRUPT_RX_MSG_RAW,
REG_READ(ah, AR_MCI_INTERRUPT_RX_MSG_RAW));
REG_WRITE(ah, AR_MCI_INTERRUPT_RAW,
REG_READ(ah, AR_MCI_INTERRUPT_RAW));
ath_dbg(common, MCI, "MCI Reset sequence start\n");
ath_dbg(common, MCI, "MCI send REMOTE_RESET\n");
ar9003_mci_remote_reset(ah, true);
if (AR_SREV_9462_10(ah))
udelay(252);
ath_dbg(common, MCI, "MCI Send REQ_WAKE to remoter(BT)\n");
ar9003_mci_send_req_wake(ah, true);
if (ar9003_mci_wait_for_interrupt(ah, AR_MCI_INTERRUPT_RX_MSG_RAW,
AR_MCI_INTERRUPT_RX_MSG_SYS_WAKING, 500)) {
ath_dbg(common, MCI, "MCI SYS_WAKING from remote(BT)\n");
mci->bt_state = MCI_BT_AWAKE;
if (AR_SREV_9462_10(ah))
udelay(10);
ath_dbg(common, MCI, "MCI send SW SYS_WAKING to remote BT\n");
ar9003_mci_send_sys_waking(ah, true);
udelay(10);
REG_WRITE(ah, AR_MCI_BT_PRI0, 0xFFFFFFFF);
REG_WRITE(ah, AR_MCI_BT_PRI1, 0xFFFFFFFF);
REG_WRITE(ah, AR_MCI_BT_PRI2, 0xFFFFFFFF);
REG_WRITE(ah, AR_MCI_BT_PRI3, 0xFFFFFFFF);
REG_WRITE(ah, AR_MCI_BT_PRI, 0X000000FF);
REG_WRITE(ah, AR_MCI_INTERRUPT_RX_MSG_RAW,
AR_MCI_INTERRUPT_RX_MSG_CONT_RST);
REG_WRITE(ah, AR_MCI_INTERRUPT_RAW,
AR_MCI_INTERRUPT_BT_PRI);
if (AR_SREV_9462_10(ah) || mci->is_2g) {
ath_dbg(common, MCI, "MCI send LNA_TRANS to BT\n");
ar9003_mci_send_lna_transfer(ah, true);
udelay(5);
}
if (AR_SREV_9462_10(ah) || (mci->is_2g &&
!mci->update_2g5g)) {
if (ar9003_mci_wait_for_interrupt(ah,
AR_MCI_INTERRUPT_RX_MSG_RAW,
AR_MCI_INTERRUPT_RX_MSG_LNA_INFO,
mci_timeout))
ath_dbg(common, MCI,
"MCI WLAN has control over the LNA & BT obeys it\n");
else
ath_dbg(common, MCI,
"MCI BT didn't respond to LNA_TRANS\n");
}
if (AR_SREV_9462_10(ah)) {
ath_dbg(common, MCI,
"MCI another remote_reset to deassert clk_req\n");
ar9003_mci_remote_reset(ah, true);
udelay(252);
}
}
if ((mci->bt_state == MCI_BT_AWAKE) &&
(REG_READ_FIELD(ah, AR_MCI_INTERRUPT_RX_MSG_RAW,
AR_MCI_INTERRUPT_RX_MSG_SYS_WAKING)) &&
(REG_READ_FIELD(ah, AR_MCI_INTERRUPT_RX_MSG_RAW,
AR_MCI_INTERRUPT_RX_MSG_SYS_SLEEPING) == 0)) {
REG_WRITE(ah, AR_MCI_INTERRUPT_RX_MSG_RAW,
AR_MCI_INTERRUPT_RX_MSG_SYS_WAKING);
REG_WRITE(ah, AR_MCI_INTERRUPT_RAW,
AR_MCI_INTERRUPT_REMOTE_SLEEP_UPDATE);
}
REG_WRITE(ah, AR_MCI_INTERRUPT_EN, saved_mci_int_en);
}
void ar9003_mci_disable_interrupt(struct ath_hw *ah)
{
if (!ATH9K_HW_CAP_MCI)
return;
REG_WRITE(ah, AR_MCI_INTERRUPT_EN, 0);
REG_WRITE(ah, AR_MCI_INTERRUPT_RX_MSG_EN, 0);
}
void ar9003_mci_enable_interrupt(struct ath_hw *ah)
{
if (!ATH9K_HW_CAP_MCI)
return;
REG_WRITE(ah, AR_MCI_INTERRUPT_EN, AR_MCI_INTERRUPT_DEFAULT);
REG_WRITE(ah, AR_MCI_INTERRUPT_RX_MSG_EN,
AR_MCI_INTERRUPT_RX_MSG_DEFAULT);
}
bool ar9003_mci_check_int(struct ath_hw *ah, u32 ints)
{
u32 intr;
if (!ATH9K_HW_CAP_MCI)
return false;
intr = REG_READ(ah, AR_MCI_INTERRUPT_RX_MSG_RAW);
return ((intr & ints) == ints);
}
void ar9003_mci_get_interrupt(struct ath_hw *ah, u32 *raw_intr,
u32 *rx_msg_intr)
{
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
if (!ATH9K_HW_CAP_MCI)
return;
*raw_intr = mci->raw_intr;
*rx_msg_intr = mci->rx_msg_intr;
mci->raw_intr = 0;
mci->rx_msg_intr = 0;
}
void ar9003_mci_2g5g_changed(struct ath_hw *ah, bool is_2g)
{
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
if (!ATH9K_HW_CAP_MCI)
return;
if (!mci->update_2g5g &&
(mci->is_2g != is_2g))
mci->update_2g5g = true;
mci->is_2g = is_2g;
}
static bool ar9003_mci_is_gpm_valid(struct ath_hw *ah, u32 msg_index)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 *payload;
u32 recv_type, offset;
if (msg_index == MCI_GPM_INVALID)
return false;
offset = msg_index << 4;
payload = (u32 *)(mci->gpm_buf + offset);
recv_type = MCI_GPM_TYPE(payload);
if (recv_type == MCI_GPM_RSVD_PATTERN) {
ath_dbg(common, MCI, "MCI Skip RSVD GPM\n");
return false;
}
return true;
}
static void ar9003_mci_observation_set_up(struct ath_hw *ah)
{
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
if (mci->config & ATH_MCI_CONFIG_MCI_OBS_MCI) {
ath9k_hw_cfg_output(ah, 3,
AR_GPIO_OUTPUT_MUX_AS_MCI_WLAN_DATA);
ath9k_hw_cfg_output(ah, 2, AR_GPIO_OUTPUT_MUX_AS_MCI_WLAN_CLK);
ath9k_hw_cfg_output(ah, 1, AR_GPIO_OUTPUT_MUX_AS_MCI_BT_DATA);
ath9k_hw_cfg_output(ah, 0, AR_GPIO_OUTPUT_MUX_AS_MCI_BT_CLK);
} else if (mci->config & ATH_MCI_CONFIG_MCI_OBS_TXRX) {
ath9k_hw_cfg_output(ah, 3, AR_GPIO_OUTPUT_MUX_AS_WL_IN_TX);
ath9k_hw_cfg_output(ah, 2, AR_GPIO_OUTPUT_MUX_AS_WL_IN_RX);
ath9k_hw_cfg_output(ah, 1, AR_GPIO_OUTPUT_MUX_AS_BT_IN_TX);
ath9k_hw_cfg_output(ah, 0, AR_GPIO_OUTPUT_MUX_AS_BT_IN_RX);
ath9k_hw_cfg_output(ah, 5, AR_GPIO_OUTPUT_MUX_AS_OUTPUT);
} else if (mci->config & ATH_MCI_CONFIG_MCI_OBS_BT) {
ath9k_hw_cfg_output(ah, 3, AR_GPIO_OUTPUT_MUX_AS_BT_IN_TX);
ath9k_hw_cfg_output(ah, 2, AR_GPIO_OUTPUT_MUX_AS_BT_IN_RX);
ath9k_hw_cfg_output(ah, 1, AR_GPIO_OUTPUT_MUX_AS_MCI_BT_DATA);
ath9k_hw_cfg_output(ah, 0, AR_GPIO_OUTPUT_MUX_AS_MCI_BT_CLK);
} else
return;
REG_SET_BIT(ah, AR_GPIO_INPUT_EN_VAL, AR_GPIO_JTAG_DISABLE);
if (AR_SREV_9462_20_OR_LATER(ah)) {
REG_RMW_FIELD(ah, AR_PHY_GLB_CONTROL,
AR_GLB_DS_JTAG_DISABLE, 1);
REG_RMW_FIELD(ah, AR_PHY_GLB_CONTROL,
AR_GLB_WLAN_UART_INTF_EN, 0);
REG_SET_BIT(ah, AR_GLB_GPIO_CONTROL,
ATH_MCI_CONFIG_MCI_OBS_GPIO);
}
REG_RMW_FIELD(ah, AR_BTCOEX_CTRL2, AR_BTCOEX_CTRL2_GPIO_OBS_SEL, 0);
REG_RMW_FIELD(ah, AR_BTCOEX_CTRL2, AR_BTCOEX_CTRL2_MAC_BB_OBS_SEL, 1);
REG_WRITE(ah, AR_OBS, 0x4b);
REG_RMW_FIELD(ah, AR_DIAG_SW, AR_DIAG_OBS_PT_SEL1, 0x03);
REG_RMW_FIELD(ah, AR_DIAG_SW, AR_DIAG_OBS_PT_SEL2, 0x01);
REG_RMW_FIELD(ah, AR_MACMISC, AR_MACMISC_MISC_OBS_BUS_LSB, 0x02);
REG_RMW_FIELD(ah, AR_MACMISC, AR_MACMISC_MISC_OBS_BUS_MSB, 0x03);
REG_RMW_FIELD(ah, AR_PHY_TEST_CTL_STATUS,
AR_PHY_TEST_CTL_DEBUGPORT_SEL, 0x07);
}
static bool ar9003_mci_send_coex_bt_flags(struct ath_hw *ah, bool wait_done,
u8 opcode, u32 bt_flags)
{
struct ath_common *common = ath9k_hw_common(ah);
u32 pld[4] = {0, 0, 0, 0};
MCI_GPM_SET_TYPE_OPCODE(pld,
MCI_GPM_COEX_AGENT, MCI_GPM_COEX_BT_UPDATE_FLAGS);
*(((u8 *)pld) + MCI_GPM_COEX_B_BT_FLAGS_OP) = opcode;
*(((u8 *)pld) + MCI_GPM_COEX_W_BT_FLAGS + 0) = bt_flags & 0xFF;
*(((u8 *)pld) + MCI_GPM_COEX_W_BT_FLAGS + 1) = (bt_flags >> 8) & 0xFF;
*(((u8 *)pld) + MCI_GPM_COEX_W_BT_FLAGS + 2) = (bt_flags >> 16) & 0xFF;
*(((u8 *)pld) + MCI_GPM_COEX_W_BT_FLAGS + 3) = (bt_flags >> 24) & 0xFF;
ath_dbg(common, MCI,
"MCI BT_MCI_FLAGS: Send Coex BT Update Flags %s 0x%08x\n",
opcode == MCI_GPM_COEX_BT_FLAGS_READ ? "READ" :
opcode == MCI_GPM_COEX_BT_FLAGS_SET ? "SET" : "CLEAR",
bt_flags);
return ar9003_mci_send_message(ah, MCI_GPM, 0, pld, 16,
wait_done, true);
}
void ar9003_mci_reset(struct ath_hw *ah, bool en_int, bool is_2g,
bool is_full_sleep)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 regval, thresh;
if (!ATH9K_HW_CAP_MCI)
return;
ath_dbg(common, MCI, "MCI full_sleep = %d, is_2g = %d\n",
is_full_sleep, is_2g);
if (!mci->gpm_addr && !mci->sched_addr) {
ath_dbg(common, MCI,
"MCI GPM and schedule buffers are not allocated\n");
return;
}
if (REG_READ(ah, AR_BTCOEX_CTRL) == 0xdeadbeef) {
ath_dbg(common, MCI, "MCI it's deadbeef, quit mci_reset\n");
return;
}
REG_WRITE(ah, AR_MCI_GPM_0, mci->gpm_addr);
REG_WRITE(ah, AR_MCI_GPM_1, mci->gpm_len);
REG_WRITE(ah, AR_MCI_SCHD_TABLE_0, mci->sched_addr);
regval = SM(1, AR_BTCOEX_CTRL_AR9462_MODE) |
SM(1, AR_BTCOEX_CTRL_WBTIMER_EN) |
SM(1, AR_BTCOEX_CTRL_PA_SHARED) |
SM(1, AR_BTCOEX_CTRL_LNA_SHARED) |
SM(2, AR_BTCOEX_CTRL_NUM_ANTENNAS) |
SM(3, AR_BTCOEX_CTRL_RX_CHAIN_MASK) |
SM(0, AR_BTCOEX_CTRL_1_CHAIN_ACK) |
SM(0, AR_BTCOEX_CTRL_1_CHAIN_BCN) |
SM(0, AR_BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_EN);
if (is_2g && (AR_SREV_9462_20(ah)) &&
!(mci->config & ATH_MCI_CONFIG_DISABLE_OSLA)) {
regval |= SM(1, AR_BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_EN);
ath_dbg(common, MCI, "MCI sched one step look ahead\n");
if (!(mci->config &
ATH_MCI_CONFIG_DISABLE_AGGR_THRESH)) {
thresh = MS(mci->config,
ATH_MCI_CONFIG_AGGR_THRESH);
thresh &= 7;
regval |= SM(1,
AR_BTCOEX_CTRL_TIME_TO_NEXT_BT_THRESH_EN);
regval |= SM(thresh, AR_BTCOEX_CTRL_AGGR_THRESH);
REG_RMW_FIELD(ah, AR_MCI_SCHD_TABLE_2,
AR_MCI_SCHD_TABLE_2_HW_BASED, 1);
REG_RMW_FIELD(ah, AR_MCI_SCHD_TABLE_2,
AR_MCI_SCHD_TABLE_2_MEM_BASED, 1);
} else
ath_dbg(common, MCI, "MCI sched aggr thresh: off\n");
} else
ath_dbg(common, MCI, "MCI SCHED one step look ahead off\n");
if (AR_SREV_9462_10(ah))
regval |= SM(1, AR_BTCOEX_CTRL_SPDT_ENABLE_10);
REG_WRITE(ah, AR_BTCOEX_CTRL, regval);
if (AR_SREV_9462_20(ah)) {
REG_SET_BIT(ah, AR_PHY_GLB_CONTROL,
AR_BTCOEX_CTRL_SPDT_ENABLE);
REG_RMW_FIELD(ah, AR_BTCOEX_CTRL3,
AR_BTCOEX_CTRL3_CONT_INFO_TIMEOUT, 20);
}
REG_RMW_FIELD(ah, AR_BTCOEX_CTRL2, AR_BTCOEX_CTRL2_RX_DEWEIGHT, 1);
REG_RMW_FIELD(ah, AR_PCU_MISC, AR_PCU_BT_ANT_PREVENT_RX, 0);
thresh = MS(mci->config, ATH_MCI_CONFIG_CLK_DIV);
REG_RMW_FIELD(ah, AR_MCI_TX_CTRL, AR_MCI_TX_CTRL_CLK_DIV, thresh);
REG_SET_BIT(ah, AR_BTCOEX_CTRL, AR_BTCOEX_CTRL_MCI_MODE_EN);
regval = REG_READ(ah, AR_MCI_COMMAND2);
regval |= SM(1, AR_MCI_COMMAND2_RESET_TX);
REG_WRITE(ah, AR_MCI_COMMAND2, regval);
udelay(1);
regval &= ~SM(1, AR_MCI_COMMAND2_RESET_TX);
REG_WRITE(ah, AR_MCI_COMMAND2, regval);
if (is_full_sleep) {
ar9003_mci_mute_bt(ah);
udelay(100);
}
regval |= SM(1, AR_MCI_COMMAND2_RESET_RX);
REG_WRITE(ah, AR_MCI_COMMAND2, regval);
udelay(1);
regval &= ~SM(1, AR_MCI_COMMAND2_RESET_RX);
REG_WRITE(ah, AR_MCI_COMMAND2, regval);
ar9003_mci_state(ah, MCI_STATE_INIT_GPM_OFFSET, NULL);
REG_WRITE(ah, AR_MCI_MSG_ATTRIBUTES_TABLE,
(SM(0xe801, AR_MCI_MSG_ATTRIBUTES_TABLE_INVALID_HDR) |
SM(0x0000, AR_MCI_MSG_ATTRIBUTES_TABLE_CHECKSUM)));
REG_CLR_BIT(ah, AR_MCI_TX_CTRL,
AR_MCI_TX_CTRL_DISABLE_LNA_UPDATE);
if (AR_SREV_9462_20_OR_LATER(ah))
ar9003_mci_observation_set_up(ah);
mci->ready = true;
ar9003_mci_prep_interface(ah);
if (en_int)
ar9003_mci_enable_interrupt(ah);
}
void ar9003_mci_mute_bt(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
if (!ATH9K_HW_CAP_MCI)
return;
REG_WRITE(ah, AR_MCI_MSG_ATTRIBUTES_TABLE, 0xffff0000);
REG_WRITE(ah, AR_BTCOEX_WL_WEIGHTS0, 0xffffffff);
REG_WRITE(ah, AR_BTCOEX_WL_WEIGHTS1, 0xffffffff);
REG_WRITE(ah, AR_BTCOEX_WL_WEIGHTS2, 0xffffffff);
REG_WRITE(ah, AR_BTCOEX_WL_WEIGHTS3, 0xffffffff);
REG_SET_BIT(ah, AR_MCI_TX_CTRL, AR_MCI_TX_CTRL_DISABLE_LNA_UPDATE);
udelay(10);
ath_dbg(common, MCI, "MCI Send LNA take\n");
ar9003_mci_send_lna_take(ah, true);
udelay(5);
ath_dbg(common, MCI, "MCI Send sys sleeping\n");
ar9003_mci_send_sys_sleeping(ah, true);
}
void ar9003_mci_sync_bt_state(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 cur_bt_state;
if (!ATH9K_HW_CAP_MCI)
return;
cur_bt_state = ar9003_mci_state(ah, MCI_STATE_REMOTE_SLEEP, NULL);
if (mci->bt_state != cur_bt_state) {
ath_dbg(common, MCI,
"MCI BT state mismatches. old: %d, new: %d\n",
mci->bt_state, cur_bt_state);
mci->bt_state = cur_bt_state;
}
if (mci->bt_state != MCI_BT_SLEEP) {
ar9003_mci_send_coex_version_query(ah, true);
ar9003_mci_send_coex_wlan_channels(ah, true);
if (mci->unhalt_bt_gpm == true) {
ath_dbg(common, MCI, "MCI unhalt BT GPM\n");
ar9003_mci_send_coex_halt_bt_gpm(ah, false, true);
}
}
}
static void ar9003_mci_send_2g5g_status(struct ath_hw *ah, bool wait_done)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 new_flags, to_set, to_clear;
if (AR_SREV_9462_20(ah) &&
mci->update_2g5g &&
(mci->bt_state != MCI_BT_SLEEP)) {
if (mci->is_2g) {
new_flags = MCI_2G_FLAGS;
to_clear = MCI_2G_FLAGS_CLEAR_MASK;
to_set = MCI_2G_FLAGS_SET_MASK;
} else {
new_flags = MCI_5G_FLAGS;
to_clear = MCI_5G_FLAGS_CLEAR_MASK;
to_set = MCI_5G_FLAGS_SET_MASK;
}
ath_dbg(common, MCI,
"MCI BT_MCI_FLAGS: %s 0x%08x clr=0x%08x, set=0x%08x\n",
mci->is_2g ? "2G" : "5G", new_flags, to_clear, to_set);
if (to_clear)
ar9003_mci_send_coex_bt_flags(ah, wait_done,
MCI_GPM_COEX_BT_FLAGS_CLEAR, to_clear);
if (to_set)
ar9003_mci_send_coex_bt_flags(ah, wait_done,
MCI_GPM_COEX_BT_FLAGS_SET, to_set);
}
if (AR_SREV_9462_10(ah) && (mci->bt_state != MCI_BT_SLEEP))
mci->update_2g5g = false;
}
static void ar9003_mci_queue_unsent_gpm(struct ath_hw *ah, u8 header,
u32 *payload, bool queue)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u8 type, opcode;
if (queue) {
if (payload)
ath_dbg(common, MCI,
"MCI ERROR: Send fail: %02x: %02x %02x %02x\n",
header,
*(((u8 *)payload) + 4),
*(((u8 *)payload) + 5),
*(((u8 *)payload) + 6));
else
ath_dbg(common, MCI, "MCI ERROR: Send fail: %02x\n",
header);
}
if (header != MCI_GPM)
return;
type = MCI_GPM_TYPE(payload);
opcode = MCI_GPM_OPCODE(payload);
if (type != MCI_GPM_COEX_AGENT)
return;
switch (opcode) {
case MCI_GPM_COEX_BT_UPDATE_FLAGS:
if (AR_SREV_9462_10(ah))
break;
if (*(((u8 *)payload) + MCI_GPM_COEX_B_BT_FLAGS_OP) ==
MCI_GPM_COEX_BT_FLAGS_READ)
break;
mci->update_2g5g = queue;
if (queue)
ath_dbg(common, MCI,
"MCI BT_MCI_FLAGS: 2G5G status <queued> %s\n",
mci->is_2g ? "2G" : "5G");
else
ath_dbg(common, MCI,
"MCI BT_MCI_FLAGS: 2G5G status <sent> %s\n",
mci->is_2g ? "2G" : "5G");
break;
case MCI_GPM_COEX_WLAN_CHANNELS:
mci->wlan_channels_update = queue;
if (queue)
ath_dbg(common, MCI, "MCI WLAN channel map <queued>\n");
else
ath_dbg(common, MCI, "MCI WLAN channel map <sent>\n");
break;
case MCI_GPM_COEX_HALT_BT_GPM:
if (*(((u8 *)payload) + MCI_GPM_COEX_B_HALT_STATE) ==
MCI_GPM_COEX_BT_GPM_UNHALT) {
mci->unhalt_bt_gpm = queue;
if (queue)
ath_dbg(common, MCI,
"MCI UNHALT BT GPM <queued>\n");
else {
mci->halted_bt_gpm = false;
ath_dbg(common, MCI,
"MCI UNHALT BT GPM <sent>\n");
}
}
if (*(((u8 *)payload) + MCI_GPM_COEX_B_HALT_STATE) ==
MCI_GPM_COEX_BT_GPM_HALT) {
mci->halted_bt_gpm = !queue;
if (queue)
ath_dbg(common, MCI,
"MCI HALT BT GPM <not sent>\n");
else
ath_dbg(common, MCI,
"MCI UNHALT BT GPM <sent>\n");
}
break;
default:
break;
}
}
void ar9003_mci_2g5g_switch(struct ath_hw *ah, bool wait_done)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
if (!ATH9K_HW_CAP_MCI)
return;
if (mci->update_2g5g) {
if (mci->is_2g) {
ar9003_mci_send_2g5g_status(ah, true);
ath_dbg(common, MCI, "MCI Send LNA trans\n");
ar9003_mci_send_lna_transfer(ah, true);
udelay(5);
REG_CLR_BIT(ah, AR_MCI_TX_CTRL,
AR_MCI_TX_CTRL_DISABLE_LNA_UPDATE);
if (AR_SREV_9462_20(ah)) {
REG_CLR_BIT(ah, AR_PHY_GLB_CONTROL,
AR_BTCOEX_CTRL_BT_OWN_SPDT_CTRL);
if (!(mci->config &
ATH_MCI_CONFIG_DISABLE_OSLA)) {
REG_SET_BIT(ah, AR_BTCOEX_CTRL,
AR_BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_EN);
}
}
} else {
ath_dbg(common, MCI, "MCI Send LNA take\n");
ar9003_mci_send_lna_take(ah, true);
udelay(5);
REG_SET_BIT(ah, AR_MCI_TX_CTRL,
AR_MCI_TX_CTRL_DISABLE_LNA_UPDATE);
if (AR_SREV_9462_20(ah)) {
REG_SET_BIT(ah, AR_PHY_GLB_CONTROL,
AR_BTCOEX_CTRL_BT_OWN_SPDT_CTRL);
REG_CLR_BIT(ah, AR_BTCOEX_CTRL,
AR_BTCOEX_CTRL_ONE_STEP_LOOK_AHEAD_EN);
}
ar9003_mci_send_2g5g_status(ah, true);
}
}
}
bool ar9003_mci_send_message(struct ath_hw *ah, u8 header, u32 flag,
u32 *payload, u8 len, bool wait_done,
bool check_bt)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
bool msg_sent = false;
u32 regval;
u32 saved_mci_int_en;
int i;
if (!ATH9K_HW_CAP_MCI)
return false;
saved_mci_int_en = REG_READ(ah, AR_MCI_INTERRUPT_EN);
regval = REG_READ(ah, AR_BTCOEX_CTRL);
if ((regval == 0xdeadbeef) || !(regval & AR_BTCOEX_CTRL_MCI_MODE_EN)) {
ath_dbg(common, MCI,
"MCI Not sending 0x%x. MCI is not enabled. full_sleep = %d\n",
header,
(ah->power_mode == ATH9K_PM_FULL_SLEEP) ? 1 : 0);
ar9003_mci_queue_unsent_gpm(ah, header, payload, true);
return false;
} else if (check_bt && (mci->bt_state == MCI_BT_SLEEP)) {
ath_dbg(common, MCI,
"MCI Don't send message 0x%x. BT is in sleep state\n",
header);
ar9003_mci_queue_unsent_gpm(ah, header, payload, true);
return false;
}
if (wait_done)
REG_WRITE(ah, AR_MCI_INTERRUPT_EN, 0);
REG_WRITE(ah, AR_MCI_INTERRUPT_RAW,
(AR_MCI_INTERRUPT_SW_MSG_DONE |
AR_MCI_INTERRUPT_MSG_FAIL_MASK));
if (payload) {
for (i = 0; (i * 4) < len; i++)
REG_WRITE(ah, (AR_MCI_TX_PAYLOAD0 + i * 4),
*(payload + i));
}
REG_WRITE(ah, AR_MCI_COMMAND0,
(SM((flag & MCI_FLAG_DISABLE_TIMESTAMP),
AR_MCI_COMMAND0_DISABLE_TIMESTAMP) |
SM(len, AR_MCI_COMMAND0_LEN) |
SM(header, AR_MCI_COMMAND0_HEADER)));
if (wait_done &&
!(ar9003_mci_wait_for_interrupt(ah, AR_MCI_INTERRUPT_RAW,
AR_MCI_INTERRUPT_SW_MSG_DONE, 500)))
ar9003_mci_queue_unsent_gpm(ah, header, payload, true);
else {
ar9003_mci_queue_unsent_gpm(ah, header, payload, false);
msg_sent = true;
}
if (wait_done)
REG_WRITE(ah, AR_MCI_INTERRUPT_EN, saved_mci_int_en);
return msg_sent;
}
void ar9003_mci_setup(struct ath_hw *ah, u32 gpm_addr, void *gpm_buf,
u16 len, u32 sched_addr)
{
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
void *sched_buf = (void *)((char *) gpm_buf + (sched_addr - gpm_addr));
if (!ATH9K_HW_CAP_MCI)
return;
mci->gpm_addr = gpm_addr;
mci->gpm_buf = gpm_buf;
mci->gpm_len = len;
mci->sched_addr = sched_addr;
mci->sched_buf = sched_buf;
ar9003_mci_reset(ah, true, true, true);
}
void ar9003_mci_cleanup(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
if (!ATH9K_HW_CAP_MCI)
return;
REG_WRITE(ah, AR_BTCOEX_CTRL, 0x00);
ath_dbg(common, MCI, "MCI ar9003_mci_cleanup\n");
ar9003_mci_disable_interrupt(ah);
}
static void ar9003_mci_process_gpm_extra(struct ath_hw *ah, u8 gpm_type,
u8 gpm_opcode, u32 *p_gpm)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u8 *p_data = (u8 *) p_gpm;
if (gpm_type != MCI_GPM_COEX_AGENT)
return;
switch (gpm_opcode) {
case MCI_GPM_COEX_VERSION_QUERY:
ath_dbg(common, MCI, "MCI Recv GPM COEX Version Query\n");
ar9003_mci_send_coex_version_response(ah, true);
break;
case MCI_GPM_COEX_VERSION_RESPONSE:
ath_dbg(common, MCI, "MCI Recv GPM COEX Version Response\n");
mci->bt_ver_major =
*(p_data + MCI_GPM_COEX_B_MAJOR_VERSION);
mci->bt_ver_minor =
*(p_data + MCI_GPM_COEX_B_MINOR_VERSION);
mci->bt_version_known = true;
ath_dbg(common, MCI, "MCI BT Coex version: %d.%d\n",
mci->bt_ver_major, mci->bt_ver_minor);
break;
case MCI_GPM_COEX_STATUS_QUERY:
ath_dbg(common, MCI,
"MCI Recv GPM COEX Status Query = 0x%02X\n",
*(p_data + MCI_GPM_COEX_B_WLAN_BITMAP));
mci->wlan_channels_update = true;
ar9003_mci_send_coex_wlan_channels(ah, true);
break;
case MCI_GPM_COEX_BT_PROFILE_INFO:
mci->query_bt = true;
ath_dbg(common, MCI, "MCI Recv GPM COEX BT_Profile_Info\n");
break;
case MCI_GPM_COEX_BT_STATUS_UPDATE:
mci->query_bt = true;
ath_dbg(common, MCI,
"MCI Recv GPM COEX BT_Status_Update SEQ=%d (drop&query)\n",
*(p_gpm + 3));
break;
default:
break;
}
}
u32 ar9003_mci_wait_for_gpm(struct ath_hw *ah, u8 gpm_type,
u8 gpm_opcode, int time_out)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 *p_gpm = NULL, mismatch = 0, more_data;
u32 offset;
u8 recv_type = 0, recv_opcode = 0;
bool b_is_bt_cal_done = (gpm_type == MCI_GPM_BT_CAL_DONE);
if (!ATH9K_HW_CAP_MCI)
return 0;
more_data = time_out ? MCI_GPM_NOMORE : MCI_GPM_MORE;
while (time_out > 0) {
if (p_gpm) {
MCI_GPM_RECYCLE(p_gpm);
p_gpm = NULL;
}
if (more_data != MCI_GPM_MORE)
time_out = ar9003_mci_wait_for_interrupt(ah,
AR_MCI_INTERRUPT_RX_MSG_RAW,
AR_MCI_INTERRUPT_RX_MSG_GPM,
time_out);
if (!time_out)
break;
offset = ar9003_mci_state(ah,
MCI_STATE_NEXT_GPM_OFFSET, &more_data);
if (offset == MCI_GPM_INVALID)
continue;
p_gpm = (u32 *) (mci->gpm_buf + offset);
recv_type = MCI_GPM_TYPE(p_gpm);
recv_opcode = MCI_GPM_OPCODE(p_gpm);
if (MCI_GPM_IS_CAL_TYPE(recv_type)) {
if (recv_type == gpm_type) {
if ((gpm_type == MCI_GPM_BT_CAL_DONE) &&
!b_is_bt_cal_done) {
gpm_type = MCI_GPM_BT_CAL_GRANT;
ath_dbg(common, MCI,
"MCI Recv BT_CAL_DONE wait BT_CAL_GRANT\n");
continue;
}
break;
}
} else if ((recv_type == gpm_type) &&
(recv_opcode == gpm_opcode))
break;
if ((gpm_type == MCI_GPM_BT_CAL_GRANT) &&
(recv_type == MCI_GPM_BT_CAL_REQ)) {
u32 payload[4] = {0, 0, 0, 0};
gpm_type = MCI_GPM_BT_CAL_DONE;
ath_dbg(common, MCI,
"MCI Rcv BT_CAL_REQ, send WLAN_CAL_GRANT\n");
MCI_GPM_SET_CAL_TYPE(payload,
MCI_GPM_WLAN_CAL_GRANT);
ar9003_mci_send_message(ah, MCI_GPM, 0, payload, 16,
false, false);
ath_dbg(common, MCI, "MCI now wait for BT_CAL_DONE\n");
continue;
} else {
ath_dbg(common, MCI, "MCI GPM subtype not match 0x%x\n",
*(p_gpm + 1));
mismatch++;
ar9003_mci_process_gpm_extra(ah, recv_type,
recv_opcode, p_gpm);
}
}
if (p_gpm) {
MCI_GPM_RECYCLE(p_gpm);
p_gpm = NULL;
}
if (time_out <= 0) {
time_out = 0;
ath_dbg(common, MCI,
"MCI GPM received timeout, mismatch = %d\n", mismatch);
} else
ath_dbg(common, MCI, "MCI Receive GPM type=0x%x, code=0x%x\n",
gpm_type, gpm_opcode);
while (more_data == MCI_GPM_MORE) {
ath_dbg(common, MCI, "MCI discard remaining GPM\n");
offset = ar9003_mci_state(ah, MCI_STATE_NEXT_GPM_OFFSET,
&more_data);
if (offset == MCI_GPM_INVALID)
break;
p_gpm = (u32 *) (mci->gpm_buf + offset);
recv_type = MCI_GPM_TYPE(p_gpm);
recv_opcode = MCI_GPM_OPCODE(p_gpm);
if (!MCI_GPM_IS_CAL_TYPE(recv_type))
ar9003_mci_process_gpm_extra(ah, recv_type,
recv_opcode, p_gpm);
MCI_GPM_RECYCLE(p_gpm);
}
return time_out;
}
u32 ar9003_mci_state(struct ath_hw *ah, u32 state_type, u32 *p_data)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_hw_mci *mci = &ah->btcoex_hw.mci;
u32 value = 0, more_gpm = 0, gpm_ptr;
u8 query_type;
if (!ATH9K_HW_CAP_MCI)
return 0;
switch (state_type) {
case MCI_STATE_ENABLE:
if (mci->ready) {
value = REG_READ(ah, AR_BTCOEX_CTRL);
if ((value == 0xdeadbeef) || (value == 0xffffffff))
value = 0;
}
value &= AR_BTCOEX_CTRL_MCI_MODE_EN;
break;
case MCI_STATE_INIT_GPM_OFFSET:
value = MS(REG_READ(ah, AR_MCI_GPM_1), AR_MCI_GPM_WRITE_PTR);
ath_dbg(common, MCI, "MCI GPM initial WRITE_PTR=%d\n", value);
mci->gpm_idx = value;
break;
case MCI_STATE_NEXT_GPM_OFFSET:
case MCI_STATE_LAST_GPM_OFFSET:
REG_WRITE(ah, AR_MCI_INTERRUPT_RX_MSG_RAW,
AR_MCI_INTERRUPT_RX_MSG_GPM);
gpm_ptr = MS(REG_READ(ah, AR_MCI_GPM_1), AR_MCI_GPM_WRITE_PTR);
value = gpm_ptr;
if (value == 0)
value = mci->gpm_len - 1;
else if (value >= mci->gpm_len) {
if (value != 0xFFFF) {
value = 0;
ath_dbg(common, MCI,
"MCI GPM offset out of range\n");
}
} else
value--;
if (value == 0xFFFF) {
value = MCI_GPM_INVALID;
more_gpm = MCI_GPM_NOMORE;
ath_dbg(common, MCI,
"MCI GPM ptr invalid @ptr=%d, offset=%d, more=GPM_NOMORE\n",
gpm_ptr, value);
} else if (state_type == MCI_STATE_NEXT_GPM_OFFSET) {
if (gpm_ptr == mci->gpm_idx) {
value = MCI_GPM_INVALID;
more_gpm = MCI_GPM_NOMORE;
ath_dbg(common, MCI,
"MCI GPM message not available @ptr=%d, @offset=%d, more=GPM_NOMORE\n",
gpm_ptr, value);
} else {
for (;;) {
u32 temp_index;
if (value != mci->gpm_idx)
more_gpm = MCI_GPM_MORE;
else
more_gpm = MCI_GPM_NOMORE;
temp_index = mci->gpm_idx;
mci->gpm_idx++;
if (mci->gpm_idx >=
mci->gpm_len)
mci->gpm_idx = 0;
ath_dbg(common, MCI,
"MCI GPM message got ptr=%d, @offset=%d, more=%d\n",
gpm_ptr, temp_index,
(more_gpm == MCI_GPM_MORE));
if (ar9003_mci_is_gpm_valid(ah,
temp_index)) {
value = temp_index;
break;
}
if (more_gpm == MCI_GPM_NOMORE) {
value = MCI_GPM_INVALID;
break;
}
}
}
if (p_data)
*p_data = more_gpm;
}
if (value != MCI_GPM_INVALID)
value <<= 4;
break;
case MCI_STATE_LAST_SCHD_MSG_OFFSET:
value = MS(REG_READ(ah, AR_MCI_RX_STATUS),
AR_MCI_RX_LAST_SCHD_MSG_INDEX);
value <<= 4;
break;
case MCI_STATE_REMOTE_SLEEP:
value = MS(REG_READ(ah, AR_MCI_RX_STATUS),
AR_MCI_RX_REMOTE_SLEEP) ?
MCI_BT_SLEEP : MCI_BT_AWAKE;
break;
case MCI_STATE_CONT_RSSI_POWER:
value = MS(mci->cont_status, AR_MCI_CONT_RSSI_POWER);
break;
case MCI_STATE_CONT_PRIORITY:
value = MS(mci->cont_status, AR_MCI_CONT_RRIORITY);
break;
case MCI_STATE_CONT_TXRX:
value = MS(mci->cont_status, AR_MCI_CONT_TXRX);
break;
case MCI_STATE_BT:
value = mci->bt_state;
break;
case MCI_STATE_SET_BT_SLEEP:
mci->bt_state = MCI_BT_SLEEP;
break;
case MCI_STATE_SET_BT_AWAKE:
mci->bt_state = MCI_BT_AWAKE;
ar9003_mci_send_coex_version_query(ah, true);
ar9003_mci_send_coex_wlan_channels(ah, true);
if (mci->unhalt_bt_gpm) {
ath_dbg(common, MCI, "MCI unhalt BT GPM\n");
ar9003_mci_send_coex_halt_bt_gpm(ah, false, true);
}
ar9003_mci_2g5g_switch(ah, true);
break;
case MCI_STATE_SET_BT_CAL_START:
mci->bt_state = MCI_BT_CAL_START;
break;
case MCI_STATE_SET_BT_CAL:
mci->bt_state = MCI_BT_CAL;
break;
case MCI_STATE_RESET_REQ_WAKE:
ar9003_mci_reset_req_wakeup(ah);
mci->update_2g5g = true;
if ((AR_SREV_9462_20_OR_LATER(ah)) &&
(mci->config & ATH_MCI_CONFIG_MCI_OBS_MASK)) {
if ((REG_READ(ah, AR_GLB_GPIO_CONTROL) &
ATH_MCI_CONFIG_MCI_OBS_GPIO) !=
ATH_MCI_CONFIG_MCI_OBS_GPIO) {
ath_dbg(common, MCI,
"MCI reconfigure observation\n");
ar9003_mci_observation_set_up(ah);
}
}
break;
case MCI_STATE_SEND_WLAN_COEX_VERSION:
ar9003_mci_send_coex_version_response(ah, true);
break;
case MCI_STATE_SET_BT_COEX_VERSION:
if (!p_data)
ath_dbg(common, MCI,
"MCI Set BT Coex version with NULL data!!\n");
else {
mci->bt_ver_major = (*p_data >> 8) & 0xff;
mci->bt_ver_minor = (*p_data) & 0xff;
mci->bt_version_known = true;
ath_dbg(common, MCI, "MCI BT version set: %d.%d\n",
mci->bt_ver_major, mci->bt_ver_minor);
}
break;
case MCI_STATE_SEND_WLAN_CHANNELS:
if (p_data) {
if (((mci->wlan_channels[1] & 0xffff0000) ==
(*(p_data + 1) & 0xffff0000)) &&
(mci->wlan_channels[2] == *(p_data + 2)) &&
(mci->wlan_channels[3] == *(p_data + 3)))
break;
mci->wlan_channels[0] = *p_data++;
mci->wlan_channels[1] = *p_data++;
mci->wlan_channels[2] = *p_data++;
mci->wlan_channels[3] = *p_data++;
}
mci->wlan_channels_update = true;
ar9003_mci_send_coex_wlan_channels(ah, true);
break;
case MCI_STATE_SEND_VERSION_QUERY:
ar9003_mci_send_coex_version_query(ah, true);
break;
case MCI_STATE_SEND_STATUS_QUERY:
query_type = (AR_SREV_9462_10(ah)) ?
MCI_GPM_COEX_QUERY_BT_ALL_INFO :
MCI_GPM_COEX_QUERY_BT_TOPOLOGY;
ar9003_mci_send_coex_bt_status_query(ah, true, query_type);
break;
case MCI_STATE_NEED_FLUSH_BT_INFO:
value = (!mci->unhalt_bt_gpm &&
mci->need_flush_btinfo) ? 1 : 0;
if (p_data)
mci->need_flush_btinfo =
(*p_data != 0) ? true : false;
break;
case MCI_STATE_RECOVER_RX:
ath_dbg(common, MCI, "MCI hw RECOVER_RX\n");
ar9003_mci_prep_interface(ah);
mci->query_bt = true;
mci->need_flush_btinfo = true;
ar9003_mci_send_coex_wlan_channels(ah, true);
ar9003_mci_2g5g_switch(ah, true);
break;
case MCI_STATE_NEED_FTP_STOMP:
value = !(mci->config & ATH_MCI_CONFIG_DISABLE_FTP_STOMP);
break;
case MCI_STATE_NEED_TUNING:
value = !(mci->config & ATH_MCI_CONFIG_DISABLE_TUNING);
break;
default:
break;
}
return value;
}
