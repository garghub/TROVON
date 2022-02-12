static void ath9k_hw_set_powermode_wow_sleep(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
REG_SET_BIT(ah, AR_STA_ID1, AR_STA_ID1_PWR_SAV);
REG_WRITE(ah, AR_CR, AR_CR_RXD);
if (!ath9k_hw_wait(ah, AR_CR, AR_CR_RXE, 0, AH_WAIT_TIMEOUT)) {
ath_err(common, "Failed to stop Rx DMA in 10ms AR_CR=0x%08x AR_DIAG_SW=0x%08x\n",
REG_READ(ah, AR_CR), REG_READ(ah, AR_DIAG_SW));
return;
}
if (AR_SREV_9462(ah) || AR_SREV_9565(ah)) {
if (!REG_READ(ah, AR_MAC_PCU_GEN_TIMER_TSF_SEL))
REG_CLR_BIT(ah, AR_DIRECT_CONNECT, AR_DC_TSF2_ENABLE);
} else if (AR_SREV_9485(ah)){
if (!(REG_READ(ah, AR_NDP2_TIMER_MODE) &
AR_GEN_TIMERS2_MODE_ENABLE_MASK))
REG_CLR_BIT(ah, AR_DIRECT_CONNECT, AR_DC_TSF2_ENABLE);
}
REG_WRITE(ah, AR_RTC_FORCE_WAKE, AR_RTC_FORCE_WAKE_ON_INT);
}
static void ath9k_wow_create_keep_alive_pattern(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
u8 sta_mac_addr[ETH_ALEN], ap_mac_addr[ETH_ALEN];
u32 ctl[13] = {0};
u32 data_word[KAL_NUM_DATA_WORDS];
u8 i;
u32 wow_ka_data_word0;
memcpy(sta_mac_addr, common->macaddr, ETH_ALEN);
memcpy(ap_mac_addr, common->curbssid, ETH_ALEN);
ctl[0] = (KAL_FRAME_LEN | (MAX_RATE_POWER << 16));
ctl[1] = 0;
ctl[4] = 0;
ctl[7] = (ah->txchainmask) << 2;
ctl[2] = 0xf << 16;
if (IS_CHAN_2GHZ(ah->curchan))
ctl[3] = 0x1b;
else
ctl[3] = 0xb;
for (i = 0; i < KAL_NUM_DESC_WORDS; i++)
REG_WRITE(ah, (AR_WOW_KA_DESC_WORD2 + i * 4), ctl[i]);
REG_WRITE(ah, (AR_WOW_KA_DESC_WORD2 + i * 4), ctl[i]);
data_word[0] = (KAL_FRAME_TYPE << 2) | (KAL_FRAME_SUB_TYPE << 4) |
(KAL_TO_DS << 8) | (KAL_DURATION_ID << 16);
data_word[1] = (ap_mac_addr[3] << 24) | (ap_mac_addr[2] << 16) |
(ap_mac_addr[1] << 8) | (ap_mac_addr[0]);
data_word[2] = (sta_mac_addr[1] << 24) | (sta_mac_addr[0] << 16) |
(ap_mac_addr[5] << 8) | (ap_mac_addr[4]);
data_word[3] = (sta_mac_addr[5] << 24) | (sta_mac_addr[4] << 16) |
(sta_mac_addr[3] << 8) | (sta_mac_addr[2]);
data_word[4] = (ap_mac_addr[3] << 24) | (ap_mac_addr[2] << 16) |
(ap_mac_addr[1] << 8) | (ap_mac_addr[0]);
data_word[5] = (ap_mac_addr[5] << 8) | (ap_mac_addr[4]);
if (AR_SREV_9462_20(ah)) {
REG_WRITE(ah, (AR_WOW_KA_DESC_WORD2 + (12 * 4)), 0);
wow_ka_data_word0 = AR_WOW_TXBUF(13);
} else {
wow_ka_data_word0 = AR_WOW_TXBUF(12);
}
for (i = 0; i < KAL_NUM_DATA_WORDS; i++)
REG_WRITE(ah, (wow_ka_data_word0 + i*4), data_word[i]);
}
int ath9k_hw_wow_apply_pattern(struct ath_hw *ah, u8 *user_pattern,
u8 *user_mask, int pattern_count,
int pattern_len)
{
int i;
u32 pattern_val, mask_val;
u32 set, clr;
if (pattern_count >= ah->wow.max_patterns)
return -ENOSPC;
if (pattern_count < MAX_NUM_PATTERN_LEGACY)
REG_SET_BIT(ah, AR_WOW_PATTERN, BIT(pattern_count));
else
REG_SET_BIT(ah, AR_MAC_PCU_WOW4, BIT(pattern_count - 8));
for (i = 0; i < MAX_PATTERN_SIZE; i += 4) {
memcpy(&pattern_val, user_pattern, 4);
REG_WRITE(ah, (AR_WOW_TB_PATTERN(pattern_count) + i),
pattern_val);
user_pattern += 4;
}
for (i = 0; i < MAX_PATTERN_MASK_SIZE; i += 4) {
memcpy(&mask_val, user_mask, 4);
REG_WRITE(ah, (AR_WOW_TB_MASK(pattern_count) + i), mask_val);
user_mask += 4;
}
if (pattern_count < MAX_NUM_PATTERN_LEGACY)
ah->wow.wow_event_mask |=
BIT(pattern_count + AR_WOW_PAT_FOUND_SHIFT);
else
ah->wow.wow_event_mask2 |=
BIT((pattern_count - 8) + AR_WOW_PAT_FOUND_SHIFT);
if (pattern_count < 4) {
set = (pattern_len & AR_WOW_LENGTH_MAX) <<
AR_WOW_LEN1_SHIFT(pattern_count);
clr = AR_WOW_LENGTH1_MASK(pattern_count);
REG_RMW(ah, AR_WOW_LENGTH1, set, clr);
} else if (pattern_count < 8) {
set = (pattern_len & AR_WOW_LENGTH_MAX) <<
AR_WOW_LEN2_SHIFT(pattern_count);
clr = AR_WOW_LENGTH2_MASK(pattern_count);
REG_RMW(ah, AR_WOW_LENGTH2, set, clr);
} else if (pattern_count < 12) {
set = (pattern_len & AR_WOW_LENGTH_MAX) <<
AR_WOW_LEN3_SHIFT(pattern_count);
clr = AR_WOW_LENGTH3_MASK(pattern_count);
REG_RMW(ah, AR_WOW_LENGTH3, set, clr);
} else if (pattern_count < MAX_NUM_PATTERN) {
set = (pattern_len & AR_WOW_LENGTH_MAX) <<
AR_WOW_LEN4_SHIFT(pattern_count);
clr = AR_WOW_LENGTH4_MASK(pattern_count);
REG_RMW(ah, AR_WOW_LENGTH4, set, clr);
}
return 0;
}
u32 ath9k_hw_wow_wakeup(struct ath_hw *ah)
{
u32 wow_status = 0;
u32 val = 0, rval;
rval = REG_READ(ah, AR_WOW_PATTERN);
val = AR_WOW_STATUS(rval);
val &= ah->wow.wow_event_mask;
if (val) {
if (val & AR_WOW_MAGIC_PAT_FOUND)
wow_status |= AH_WOW_MAGIC_PATTERN_EN;
if (AR_WOW_PATTERN_FOUND(val))
wow_status |= AH_WOW_USER_PATTERN_EN;
if (val & AR_WOW_KEEP_ALIVE_FAIL)
wow_status |= AH_WOW_LINK_CHANGE;
if (val & AR_WOW_BEACON_FAIL)
wow_status |= AH_WOW_BEACON_MISS;
}
REG_RMW(ah, AR_PCIE_PM_CTRL, AR_PMCTRL_WOW_PME_CLR,
AR_PMCTRL_PWR_STATE_D1D3);
REG_WRITE(ah, AR_WOW_PATTERN,
AR_WOW_CLEAR_EVENTS(REG_READ(ah, AR_WOW_PATTERN)));
REG_WRITE(ah, AR_RSSI_THR, INIT_RSSI_THR);
if (ah->is_pciexpress)
ath9k_hw_configpcipowersave(ah, false);
ah->wow.wow_event_mask = 0;
return wow_status;
}
static void ath9k_hw_wow_set_arwr_reg(struct ath_hw *ah)
{
u32 wa_reg;
if (!ah->is_pciexpress)
return;
wa_reg = REG_READ(ah, AR_WA);
wa_reg &= ~AR_WA_UNTIE_RESET_EN;
wa_reg |= AR_WA_RESET_EN;
wa_reg |= AR_WA_POR_SHORT;
REG_WRITE(ah, AR_WA, wa_reg);
}
void ath9k_hw_wow_enable(struct ath_hw *ah, u32 pattern_enable)
{
u32 wow_event_mask;
u32 keep_alive, magic_pattern, host_pm_ctrl;
wow_event_mask = ah->wow.wow_event_mask;
REG_SET_BIT(ah, AR_PCIE_PM_CTRL, AR_PMCTRL_HOST_PME_EN |
AR_PMCTRL_PWR_PM_CTRL_ENA |
AR_PMCTRL_AUX_PWR_DET |
AR_PMCTRL_WOW_PME_CLR);
REG_CLR_BIT(ah, AR_PCIE_PM_CTRL, AR_PMCTRL_WOW_PME_CLR);
REG_SET_BIT(ah, AR_WOW_PATTERN,
AR_WOW_BACK_OFF_SHIFT(AR_WOW_PAT_BACKOFF));
REG_SET_BIT(ah, AR_WOW_COUNT, AR_WOW_AIFS_CNT(AR_WOW_CNT_AIFS_CNT) |
AR_WOW_SLOT_CNT(AR_WOW_CNT_SLOT_CNT) |
AR_WOW_KEEP_ALIVE_CNT(AR_WOW_CNT_KA_CNT));
if (pattern_enable & AH_WOW_BEACON_MISS)
REG_WRITE(ah, AR_WOW_BCN_TIMO, AR_WOW_BEACON_TIMO);
else
REG_WRITE(ah, AR_WOW_BCN_TIMO, AR_WOW_BEACON_TIMO_MAX);
if (!pattern_enable)
REG_WRITE(ah, AR_WOW_KEEP_ALIVE_TIMO, AR_WOW_KEEP_ALIVE_NEVER);
else
REG_WRITE(ah, AR_WOW_KEEP_ALIVE_TIMO, KAL_TIMEOUT * 32);
REG_WRITE(ah, AR_WOW_KEEP_ALIVE_DELAY, KAL_DELAY * 1000);
ath9k_wow_create_keep_alive_pattern(ah);
keep_alive = REG_READ(ah, AR_WOW_KEEP_ALIVE);
keep_alive &= ~AR_WOW_KEEP_ALIVE_AUTO_DIS;
if (pattern_enable & AH_WOW_LINK_CHANGE) {
keep_alive &= ~AR_WOW_KEEP_ALIVE_FAIL_DIS;
wow_event_mask |= AR_WOW_KEEP_ALIVE_FAIL;
} else {
keep_alive |= AR_WOW_KEEP_ALIVE_FAIL_DIS;
}
REG_WRITE(ah, AR_WOW_KEEP_ALIVE, keep_alive);
REG_RMW_FIELD(ah, AR_RSSI_THR, AR_RSSI_THR_BM_THR,
AR_WOW_BMISSTHRESHOLD);
if (pattern_enable & AH_WOW_BEACON_MISS) {
wow_event_mask |= AR_WOW_BEACON_FAIL;
REG_SET_BIT(ah, AR_WOW_BCN_EN, AR_WOW_BEACON_FAIL_EN);
} else {
REG_CLR_BIT(ah, AR_WOW_BCN_EN, AR_WOW_BEACON_FAIL_EN);
}
magic_pattern = REG_READ(ah, AR_WOW_PATTERN);
magic_pattern |= AR_WOW_MAC_INTR_EN;
if (pattern_enable & AH_WOW_MAGIC_PATTERN_EN) {
magic_pattern |= AR_WOW_MAGIC_EN;
wow_event_mask |= AR_WOW_MAGIC_PAT_FOUND;
} else {
magic_pattern &= ~AR_WOW_MAGIC_EN;
}
REG_WRITE(ah, AR_WOW_PATTERN, magic_pattern);
REG_WRITE(ah, AR_WOW_PATTERN_MATCH_LT_256B,
AR_WOW_PATTERN_SUPPORTED);
host_pm_ctrl = REG_READ(ah, AR_PCIE_PM_CTRL);
host_pm_ctrl |= AR_PMCTRL_PWR_STATE_D1D3 |
AR_PMCTRL_HOST_PME_EN |
AR_PMCTRL_PWR_PM_CTRL_ENA;
host_pm_ctrl &= ~AR_PCIE_PM_CTRL_ENA;
if (AR_SREV_9462(ah)) {
host_pm_ctrl &= ~AR_PMCTRL_PWR_STATE_D1D3;
host_pm_ctrl |= AR_PMCTRL_PWR_STATE_D1D3_REAL;
}
REG_WRITE(ah, AR_PCIE_PM_CTRL, host_pm_ctrl);
REG_CLR_BIT(ah, AR_STA_ID1, AR_STA_ID1_PRESERVE_SEQNUM);
REG_SET_BIT(ah, AR_PCIE_PHY_REG3, BIT(13));
ath9k_hw_wow_set_arwr_reg(ah);
REG_CLR_BIT(ah, AR_PCU_MISC_MODE3, BIT(5));
ath9k_hw_set_powermode_wow_sleep(ah);
ah->wow.wow_event_mask = wow_event_mask;
}
