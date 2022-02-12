const char *ath9k_hw_wow_event_to_string(u32 wow_event)
{
if (wow_event & AH_WOW_MAGIC_PATTERN_EN)
return "Magic pattern";
if (wow_event & AH_WOW_USER_PATTERN_EN)
return "User pattern";
if (wow_event & AH_WOW_LINK_CHANGE)
return "Link change";
if (wow_event & AH_WOW_BEACON_MISS)
return "Beacon miss";
return "unknown reason";
}
static void ath9k_hw_config_serdes_wow_sleep(struct ath_hw *ah)
{
int i;
for (i = 0; i < ah->iniPcieSerdesWow.ia_rows; i++)
REG_WRITE(ah, INI_RA(&ah->iniPcieSerdesWow, i, 0),
INI_RA(&ah->iniPcieSerdesWow, i, 1));
usleep_range(1000, 1500);
}
static void ath9k_hw_set_powermode_wow_sleep(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
REG_SET_BIT(ah, AR_STA_ID1, AR_STA_ID1_PWR_SAV);
REG_WRITE(ah, AR_CR, AR_CR_RXD);
if (!ath9k_hw_wait(ah, AR_CR, AR_CR_RXE, 0, AH_WAIT_TIMEOUT)) {
ath_err(common, "Failed to stop Rx DMA in 10ms AR_CR=0x%08x AR_DIAG_SW=0x%08x\n",
REG_READ(ah, AR_CR), REG_READ(ah, AR_DIAG_SW));
return;
} else {
if (!AR_SREV_9300_20_OR_LATER(ah))
REG_WRITE(ah, AR_RXDP, 0x0);
}
if (AR_SREV_9280_20(ah))
return;
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
if (!(AR_SREV_9300_20_OR_LATER(ah)))
ctl[0] += (KAL_ANTENNA_MODE << 25);
ctl[1] = 0;
ctl[3] = 0xb;
ctl[4] = 0;
ctl[7] = (ah->txchainmask) << 2;
if (AR_SREV_9300_20_OR_LATER(ah))
ctl[2] = 0xf << 16;
else
ctl[2] = 0x7 << 16;
for (i = 0; i < KAL_NUM_DESC_WORDS; i++)
REG_WRITE(ah, (AR_WOW_KA_DESC_WORD2 + i * 4), ctl[i]);
if (AR_SREV_9300_20_OR_LATER(ah))
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
void ath9k_hw_wow_apply_pattern(struct ath_hw *ah, u8 *user_pattern,
u8 *user_mask, int pattern_count,
int pattern_len)
{
int i;
u32 pattern_val, mask_val;
u32 set, clr;
if (pattern_count >= MAX_NUM_PATTERN)
return;
REG_SET_BIT(ah, AR_WOW_PATTERN, BIT(pattern_count));
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
ah->wow_event_mask |= BIT(pattern_count + AR_WOW_PAT_FOUND_SHIFT);
if (!AR_SREV_9285_12_OR_LATER(ah))
return;
if (pattern_count < 4) {
set = (pattern_len & AR_WOW_LENGTH_MAX) <<
AR_WOW_LEN1_SHIFT(pattern_count);
clr = AR_WOW_LENGTH1_MASK(pattern_count);
REG_RMW(ah, AR_WOW_LENGTH1, set, clr);
} else {
set = (pattern_len & AR_WOW_LENGTH_MAX) <<
AR_WOW_LEN2_SHIFT(pattern_count);
clr = AR_WOW_LENGTH2_MASK(pattern_count);
REG_RMW(ah, AR_WOW_LENGTH2, set, clr);
}
}
u32 ath9k_hw_wow_wakeup(struct ath_hw *ah)
{
u32 wow_status = 0;
u32 val = 0, rval;
rval = REG_READ(ah, AR_WOW_PATTERN);
val = AR_WOW_STATUS(rval);
val &= ah->wow_event_mask;
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
if (!AR_SREV_9300_20_OR_LATER(ah)) {
REG_SET_BIT(ah, AR_WA, AR_WA_UNTIE_RESET_EN |
AR_WA_POR_SHORT | AR_WA_RESET_EN);
}
REG_WRITE(ah, AR_RSSI_THR, INIT_RSSI_THR);
if (AR_SREV_9280_20_OR_LATER(ah) && ah->is_pciexpress)
ath9k_hw_configpcipowersave(ah, false);
ah->wow_event_mask = 0;
return wow_status;
}
void ath9k_hw_wow_enable(struct ath_hw *ah, u32 pattern_enable)
{
u32 wow_event_mask;
u32 set, clr;
wow_event_mask = ah->wow_event_mask;
if (ah->is_pciexpress) {
if (AR_SREV_9300_20_OR_LATER(ah)) {
set = AR_WA_RESET_EN | AR_WA_POR_SHORT;
clr = AR_WA_UNTIE_RESET_EN | AR_WA_D3_L1_DISABLE;
REG_RMW(ah, AR_WA, set, clr);
} else {
if (AR_SREV_9285(ah) || AR_SREV_9287(ah))
set = AR9285_WA_DEFAULT;
else
set = AR9280_WA_DEFAULT;
if (ah->config.pcie_waen & AR_WA_D3_L1_DISABLE)
set |= AR_WA_D3_L1_DISABLE;
clr = AR_WA_UNTIE_RESET_EN;
set |= AR_WA_RESET_EN | AR_WA_POR_SHORT;
REG_RMW(ah, AR_WA, set, clr);
if (AR_SREV_9285_12_OR_LATER(ah))
ath9k_hw_config_serdes_wow_sleep(ah);
}
}
set = AR_PMCTRL_HOST_PME_EN | AR_PMCTRL_PWR_PM_CTRL_ENA |
AR_PMCTRL_AUX_PWR_DET | AR_PMCTRL_WOW_PME_CLR;
REG_SET_BIT(ah, AR_PCIE_PM_CTRL, set);
clr = AR_PMCTRL_WOW_PME_CLR;
REG_CLR_BIT(ah, AR_PCIE_PM_CTRL, clr);
set = AR_WOW_BACK_OFF_SHIFT(AR_WOW_PAT_BACKOFF);
REG_SET_BIT(ah, AR_WOW_PATTERN, set);
set = AR_WOW_AIFS_CNT(AR_WOW_CNT_AIFS_CNT) |
AR_WOW_SLOT_CNT(AR_WOW_CNT_SLOT_CNT) |
AR_WOW_KEEP_ALIVE_CNT(AR_WOW_CNT_KA_CNT);
REG_SET_BIT(ah, AR_WOW_COUNT, set);
if (pattern_enable & AH_WOW_BEACON_MISS)
set = AR_WOW_BEACON_TIMO;
else
set = AR_WOW_BEACON_TIMO_MAX;
REG_WRITE(ah, AR_WOW_BCN_TIMO, set);
if (!pattern_enable || AR_SREV_9280(ah))
set = AR_WOW_KEEP_ALIVE_NEVER;
else
set = KAL_TIMEOUT * 32;
REG_WRITE(ah, AR_WOW_KEEP_ALIVE_TIMO, set);
set = KAL_DELAY * 1000;
REG_WRITE(ah, AR_WOW_KEEP_ALIVE_DELAY, set);
ath9k_wow_create_keep_alive_pattern(ah);
set = 0;
clr = AR_WOW_KEEP_ALIVE_AUTO_DIS;
if (pattern_enable & AH_WOW_LINK_CHANGE)
wow_event_mask |= AR_WOW_KEEP_ALIVE_FAIL;
else
set = AR_WOW_KEEP_ALIVE_FAIL_DIS;
set = AR_WOW_KEEP_ALIVE_FAIL_DIS;
REG_RMW(ah, AR_WOW_KEEP_ALIVE, set, clr);
REG_RMW_FIELD(ah, AR_RSSI_THR, AR_RSSI_THR_BM_THR,
AR_WOW_BMISSTHRESHOLD);
set = 0;
clr = 0;
if (pattern_enable & AH_WOW_BEACON_MISS) {
set = AR_WOW_BEACON_FAIL_EN;
wow_event_mask |= AR_WOW_BEACON_FAIL;
} else {
clr = AR_WOW_BEACON_FAIL_EN;
}
REG_RMW(ah, AR_WOW_BCN_EN, set, clr);
set = 0;
clr = 0;
if (pattern_enable & AH_WOW_MAGIC_PATTERN_EN) {
set = AR_WOW_MAGIC_EN;
wow_event_mask |= AR_WOW_MAGIC_PAT_FOUND;
} else {
clr = AR_WOW_MAGIC_EN;
}
set |= AR_WOW_MAC_INTR_EN;
REG_RMW(ah, AR_WOW_PATTERN, set, clr);
if (AR_SREV_9285_12_OR_LATER(ah))
REG_WRITE(ah, AR_WOW_PATTERN_MATCH_LT_256B,
AR_WOW_PATTERN_SUPPORTED);
clr = 0;
set = AR_PMCTRL_PWR_STATE_D1D3 | AR_PMCTRL_HOST_PME_EN |
AR_PMCTRL_PWR_PM_CTRL_ENA;
if (AR_SREV_9300_20_OR_LATER(ah))
clr = AR_PCIE_PM_CTRL_ENA;
REG_RMW(ah, AR_PCIE_PM_CTRL, set, clr);
if (AR_SREV_9462(ah) || AR_SREV_9565(ah)) {
clr = AR_PMCTRL_PWR_STATE_D1D3;
REG_CLR_BIT(ah, AR_PCIE_PM_CTRL, clr);
set = AR_PMCTRL_PWR_STATE_D1D3_REAL;
REG_SET_BIT(ah, AR_PCIE_PM_CTRL, set);
}
REG_CLR_BIT(ah, AR_STA_ID1, AR_STA_ID1_PRESERVE_SEQNUM);
if (AR_SREV_9300_20_OR_LATER(ah)) {
set = BIT(13);
REG_SET_BIT(ah, AR_PCIE_PHY_REG3, set);
clr = BIT(5);
REG_CLR_BIT(ah, AR_PCU_MISC_MODE3, clr);
}
ath9k_hw_set_powermode_wow_sleep(ah);
ah->wow_event_mask = wow_event_mask;
}
