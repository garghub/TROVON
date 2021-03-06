static void rtl92d_dm_false_alarm_counter_statistics(struct ieee80211_hw *hw)
{
u32 ret_value;
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct false_alarm_statistics *falsealm_cnt = &(rtlpriv->falsealm_cnt);
unsigned long flag = 0;
rtl_set_bbreg(hw, ROFDM0_LSTF, BIT(31), 1);
rtl_set_bbreg(hw, ROFDM1_LSTF, BIT(31), 1);
ret_value = rtl_get_bbreg(hw, ROFDM0_FRAMESYNC, MASKDWORD);
falsealm_cnt->cnt_fast_fsync_fail = (ret_value & 0xffff);
falsealm_cnt->cnt_sb_search_fail = ((ret_value & 0xffff0000) >> 16);
ret_value = rtl_get_bbreg(hw, ROFDM_PHYCOUNTER1, MASKDWORD);
falsealm_cnt->cnt_parity_fail = ((ret_value & 0xffff0000) >> 16);
ret_value = rtl_get_bbreg(hw, ROFDM_PHYCOUNTER2, MASKDWORD);
falsealm_cnt->cnt_rate_illegal = (ret_value & 0xffff);
falsealm_cnt->cnt_crc8_fail = ((ret_value & 0xffff0000) >> 16);
ret_value = rtl_get_bbreg(hw, ROFDM_PHYCOUNTER3, MASKDWORD);
falsealm_cnt->cnt_mcs_fail = (ret_value & 0xffff);
falsealm_cnt->cnt_ofdm_fail = falsealm_cnt->cnt_parity_fail +
falsealm_cnt->cnt_rate_illegal +
falsealm_cnt->cnt_crc8_fail +
falsealm_cnt->cnt_mcs_fail +
falsealm_cnt->cnt_fast_fsync_fail +
falsealm_cnt->cnt_sb_search_fail;
if (rtlpriv->rtlhal.current_bandtype != BAND_ON_5G) {
rtl92d_acquire_cckandrw_pagea_ctl(hw, &flag);
ret_value = rtl_get_bbreg(hw, RCCK0_FACOUNTERLOWER, MASKBYTE0);
falsealm_cnt->cnt_cck_fail = ret_value;
ret_value = rtl_get_bbreg(hw, RCCK0_FACOUNTERUPPER, MASKBYTE3);
falsealm_cnt->cnt_cck_fail += (ret_value & 0xff) << 8;
rtl92d_release_cckandrw_pagea_ctl(hw, &flag);
} else {
falsealm_cnt->cnt_cck_fail = 0;
}
falsealm_cnt->cnt_all = falsealm_cnt->cnt_fast_fsync_fail +
falsealm_cnt->cnt_sb_search_fail +
falsealm_cnt->cnt_parity_fail +
falsealm_cnt->cnt_rate_illegal +
falsealm_cnt->cnt_crc8_fail +
falsealm_cnt->cnt_mcs_fail +
falsealm_cnt->cnt_cck_fail;
rtl_set_bbreg(hw, ROFDM1_LSTF, 0x08000000, 1);
rtl_set_bbreg(hw, ROFDM1_LSTF, 0x08000000, 0);
rtl_set_bbreg(hw, ROFDM0_LSTF, BIT(31), 0);
rtl_set_bbreg(hw, ROFDM1_LSTF, BIT(31), 0);
if (rtlpriv->rtlhal.current_bandtype != BAND_ON_5G) {
rtl92d_acquire_cckandrw_pagea_ctl(hw, &flag);
rtl_set_bbreg(hw, RCCK0_FALSEALARMREPORT, 0x0000c000, 0);
rtl_set_bbreg(hw, RCCK0_FALSEALARMREPORT, 0x0000c000, 2);
rtl92d_release_cckandrw_pagea_ctl(hw, &flag);
}
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"Cnt_Fast_Fsync_fail = %x, Cnt_SB_Search_fail = %x\n",
falsealm_cnt->cnt_fast_fsync_fail,
falsealm_cnt->cnt_sb_search_fail);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"Cnt_Parity_Fail = %x, Cnt_Rate_Illegal = %x, Cnt_Crc8_fail = %x, Cnt_Mcs_fail = %x\n",
falsealm_cnt->cnt_parity_fail,
falsealm_cnt->cnt_rate_illegal,
falsealm_cnt->cnt_crc8_fail,
falsealm_cnt->cnt_mcs_fail);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"Cnt_Ofdm_fail = %x, Cnt_Cck_fail = %x, Cnt_all = %x\n",
falsealm_cnt->cnt_ofdm_fail,
falsealm_cnt->cnt_cck_fail,
falsealm_cnt->cnt_all);
}
static void rtl92d_dm_find_minimum_rssi(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct dig_t *de_digtable = &rtlpriv->dm_digtable;
struct rtl_mac *mac = rtl_mac(rtlpriv);
if ((mac->link_state < MAC80211_LINKED) &&
(rtlpriv->dm.UNDEC_SM_PWDB == 0)) {
de_digtable->min_undec_pwdb_for_dm = 0;
RT_TRACE(rtlpriv, COMP_BB_POWERSAVING, DBG_LOUD,
"Not connected to any\n");
}
if (mac->link_state >= MAC80211_LINKED) {
if (mac->opmode == NL80211_IFTYPE_AP ||
mac->opmode == NL80211_IFTYPE_ADHOC) {
de_digtable->min_undec_pwdb_for_dm =
rtlpriv->dm.UNDEC_SM_PWDB;
RT_TRACE(rtlpriv, COMP_BB_POWERSAVING, DBG_LOUD,
"AP Client PWDB = 0x%lx\n",
rtlpriv->dm.UNDEC_SM_PWDB);
} else {
de_digtable->min_undec_pwdb_for_dm =
rtlpriv->dm.undec_sm_pwdb;
RT_TRACE(rtlpriv, COMP_BB_POWERSAVING, DBG_LOUD,
"STA Default Port PWDB = 0x%x\n",
de_digtable->min_undec_pwdb_for_dm);
}
} else {
de_digtable->min_undec_pwdb_for_dm = rtlpriv->dm.UNDEC_SM_PWDB;
RT_TRACE(rtlpriv, COMP_BB_POWERSAVING, DBG_LOUD,
"AP Ext Port or disconnect PWDB = 0x%x\n",
de_digtable->min_undec_pwdb_for_dm);
}
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "MinUndecoratedPWDBForDM =%d\n",
de_digtable->min_undec_pwdb_for_dm);
}
static void rtl92d_dm_cck_packet_detection_thresh(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct dig_t *de_digtable = &rtlpriv->dm_digtable;
unsigned long flag = 0;
if (de_digtable->cursta_cstate == DIG_STA_CONNECT) {
if (de_digtable->pre_cck_pd_state == CCK_PD_STAGE_LOWRSSI) {
if (de_digtable->min_undec_pwdb_for_dm <= 25)
de_digtable->cur_cck_pd_state =
CCK_PD_STAGE_LOWRSSI;
else
de_digtable->cur_cck_pd_state =
CCK_PD_STAGE_HIGHRSSI;
} else {
if (de_digtable->min_undec_pwdb_for_dm <= 20)
de_digtable->cur_cck_pd_state =
CCK_PD_STAGE_LOWRSSI;
else
de_digtable->cur_cck_pd_state =
CCK_PD_STAGE_HIGHRSSI;
}
} else {
de_digtable->cur_cck_pd_state = CCK_PD_STAGE_LOWRSSI;
}
if (de_digtable->pre_cck_pd_state != de_digtable->cur_cck_pd_state) {
if (de_digtable->cur_cck_pd_state == CCK_PD_STAGE_LOWRSSI) {
rtl92d_acquire_cckandrw_pagea_ctl(hw, &flag);
rtl_set_bbreg(hw, RCCK0_CCA, MASKBYTE2, 0x83);
rtl92d_release_cckandrw_pagea_ctl(hw, &flag);
} else {
rtl92d_acquire_cckandrw_pagea_ctl(hw, &flag);
rtl_set_bbreg(hw, RCCK0_CCA, MASKBYTE2, 0xcd);
rtl92d_release_cckandrw_pagea_ctl(hw, &flag);
}
de_digtable->pre_cck_pd_state = de_digtable->cur_cck_pd_state;
}
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "CurSTAConnectState=%s\n",
de_digtable->cursta_cstate == DIG_STA_CONNECT ?
"DIG_STA_CONNECT " : "DIG_STA_DISCONNECT");
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "CCKPDStage=%s\n",
de_digtable->cur_cck_pd_state == CCK_PD_STAGE_LOWRSSI ?
"Low RSSI " : "High RSSI ");
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "is92d single phy =%x\n",
IS_92D_SINGLEPHY(rtlpriv->rtlhal.version));
}
void rtl92d_dm_write_dig(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct dig_t *de_digtable = &rtlpriv->dm_digtable;
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"cur_igvalue = 0x%x, pre_igvalue = 0x%x, back_val = %d\n",
de_digtable->cur_igvalue, de_digtable->pre_igvalue,
de_digtable->back_val);
if (de_digtable->dig_enable_flag == false) {
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "DIG is disabled\n");
de_digtable->pre_igvalue = 0x17;
return;
}
if (de_digtable->pre_igvalue != de_digtable->cur_igvalue) {
rtl_set_bbreg(hw, ROFDM0_XAAGCCORE1, 0x7f,
de_digtable->cur_igvalue);
rtl_set_bbreg(hw, ROFDM0_XBAGCCORE1, 0x7f,
de_digtable->cur_igvalue);
de_digtable->pre_igvalue = de_digtable->cur_igvalue;
}
}
static void rtl92d_early_mode_enabled(struct rtl_priv *rtlpriv)
{
struct dig_t *de_digtable = &rtlpriv->dm_digtable;
if ((rtlpriv->mac80211.link_state >= MAC80211_LINKED) &&
(rtlpriv->mac80211.vendor == PEER_CISCO)) {
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "IOT_PEER = CISCO\n");
if (de_digtable->last_min_undec_pwdb_for_dm >= 50
&& de_digtable->min_undec_pwdb_for_dm < 50) {
rtl_write_byte(rtlpriv, REG_EARLY_MODE_CONTROL, 0x00);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"Early Mode Off\n");
} else if (de_digtable->last_min_undec_pwdb_for_dm <= 55 &&
de_digtable->min_undec_pwdb_for_dm > 55) {
rtl_write_byte(rtlpriv, REG_EARLY_MODE_CONTROL, 0x0f);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"Early Mode On\n");
}
} else if (!(rtl_read_byte(rtlpriv, REG_EARLY_MODE_CONTROL) & 0xf)) {
rtl_write_byte(rtlpriv, REG_EARLY_MODE_CONTROL, 0x0f);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "Early Mode On\n");
}
}
static void rtl92d_dm_dig(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct dig_t *de_digtable = &rtlpriv->dm_digtable;
u8 value_igi = de_digtable->cur_igvalue;
struct false_alarm_statistics *falsealm_cnt = &(rtlpriv->falsealm_cnt);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "==>\n");
if (rtlpriv->rtlhal.earlymode_enable) {
rtl92d_early_mode_enabled(rtlpriv);
de_digtable->last_min_undec_pwdb_for_dm =
de_digtable->min_undec_pwdb_for_dm;
}
if (!rtlpriv->dm.dm_initialgain_enable)
return;
if (rtlpriv->mac80211.opmode != NL80211_IFTYPE_STATION)
return;
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "progress\n");
if (rtlpriv->mac80211.link_state >= MAC80211_LINKED)
de_digtable->cursta_cstate = DIG_STA_CONNECT;
else
de_digtable->cursta_cstate = DIG_STA_DISCONNECT;
if (falsealm_cnt->cnt_all < DM_DIG_FA_TH0)
value_igi--;
else if (falsealm_cnt->cnt_all < DM_DIG_FA_TH1)
value_igi += 0;
else if (falsealm_cnt->cnt_all < DM_DIG_FA_TH2)
value_igi++;
else if (falsealm_cnt->cnt_all >= DM_DIG_FA_TH2)
value_igi += 2;
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"dm_DIG() Before: large_fa_hit=%d, forbidden_igi=%x\n",
de_digtable->large_fa_hit, de_digtable->forbidden_igi);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"dm_DIG() Before: Recover_cnt=%d, rx_gain_min=%x\n",
de_digtable->recover_cnt, de_digtable->rx_gain_min);
if (falsealm_cnt->cnt_all > 10000) {
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"dm_DIG(): Abnormally false alarm case\n");
de_digtable->large_fa_hit++;
if (de_digtable->forbidden_igi < de_digtable->cur_igvalue) {
de_digtable->forbidden_igi = de_digtable->cur_igvalue;
de_digtable->large_fa_hit = 1;
}
if (de_digtable->large_fa_hit >= 3) {
if ((de_digtable->forbidden_igi + 1) > DM_DIG_MAX)
de_digtable->rx_gain_min = DM_DIG_MAX;
else
de_digtable->rx_gain_min =
(de_digtable->forbidden_igi + 1);
de_digtable->recover_cnt = 3600;
}
} else {
if (de_digtable->recover_cnt != 0) {
de_digtable->recover_cnt--;
} else {
if (de_digtable->large_fa_hit == 0) {
if ((de_digtable->forbidden_igi - 1) <
DM_DIG_FA_LOWER) {
de_digtable->forbidden_igi =
DM_DIG_FA_LOWER;
de_digtable->rx_gain_min =
DM_DIG_FA_LOWER;
} else {
de_digtable->forbidden_igi--;
de_digtable->rx_gain_min =
(de_digtable->forbidden_igi + 1);
}
} else if (de_digtable->large_fa_hit == 3) {
de_digtable->large_fa_hit = 0;
}
}
}
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"dm_DIG() After: large_fa_hit=%d, forbidden_igi=%x\n",
de_digtable->large_fa_hit, de_digtable->forbidden_igi);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD,
"dm_DIG() After: recover_cnt=%d, rx_gain_min=%x\n",
de_digtable->recover_cnt, de_digtable->rx_gain_min);
if (value_igi > DM_DIG_MAX)
value_igi = DM_DIG_MAX;
else if (value_igi < de_digtable->rx_gain_min)
value_igi = de_digtable->rx_gain_min;
de_digtable->cur_igvalue = value_igi;
rtl92d_dm_write_dig(hw);
if (rtlpriv->rtlhal.current_bandtype != BAND_ON_5G)
rtl92d_dm_cck_packet_detection_thresh(hw);
RT_TRACE(rtlpriv, COMP_DIG, DBG_LOUD, "<<==\n");
}
static void rtl92d_dm_init_dynamic_txpower(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
rtlpriv->dm.dynamic_txpower_enable = true;
rtlpriv->dm.last_dtp_lvl = TXHIGHPWRLEVEL_NORMAL;
rtlpriv->dm.dynamic_txhighpower_lvl = TXHIGHPWRLEVEL_NORMAL;
}
static void rtl92d_dm_dynamic_txpower(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_phy *rtlphy = &(rtlpriv->phy);
struct rtl_hal *rtlhal = rtl_hal(rtlpriv);
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
long undec_sm_pwdb;
if ((!rtlpriv->dm.dynamic_txpower_enable)
|| rtlpriv->dm.dm_flag & HAL_DM_HIPWR_DISABLE) {
rtlpriv->dm.dynamic_txhighpower_lvl = TXHIGHPWRLEVEL_NORMAL;
return;
}
if ((mac->link_state < MAC80211_LINKED) &&
(rtlpriv->dm.UNDEC_SM_PWDB == 0)) {
RT_TRACE(rtlpriv, COMP_POWER, DBG_TRACE,
"Not connected to any\n");
rtlpriv->dm.dynamic_txhighpower_lvl = TXHIGHPWRLEVEL_NORMAL;
rtlpriv->dm.last_dtp_lvl = TXHIGHPWRLEVEL_NORMAL;
return;
}
if (mac->link_state >= MAC80211_LINKED) {
if (mac->opmode == NL80211_IFTYPE_ADHOC) {
undec_sm_pwdb =
rtlpriv->dm.UNDEC_SM_PWDB;
RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
"IBSS Client PWDB = 0x%lx\n",
undec_sm_pwdb);
} else {
undec_sm_pwdb =
rtlpriv->dm.undec_sm_pwdb;
RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
"STA Default Port PWDB = 0x%lx\n",
undec_sm_pwdb);
}
} else {
undec_sm_pwdb =
rtlpriv->dm.UNDEC_SM_PWDB;
RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
"AP Ext Port PWDB = 0x%lx\n",
undec_sm_pwdb);
}
if (rtlhal->current_bandtype == BAND_ON_5G) {
if (undec_sm_pwdb >= 0x33) {
rtlpriv->dm.dynamic_txhighpower_lvl =
TXHIGHPWRLEVEL_LEVEL2;
RT_TRACE(rtlpriv, COMP_HIPWR, DBG_LOUD,
"5G:TxHighPwrLevel_Level2 (TxPwr=0x0)\n");
} else if ((undec_sm_pwdb < 0x33)
&& (undec_sm_pwdb >= 0x2b)) {
rtlpriv->dm.dynamic_txhighpower_lvl =
TXHIGHPWRLEVEL_LEVEL1;
RT_TRACE(rtlpriv, COMP_HIPWR, DBG_LOUD,
"5G:TxHighPwrLevel_Level1 (TxPwr=0x10)\n");
} else if (undec_sm_pwdb < 0x2b) {
rtlpriv->dm.dynamic_txhighpower_lvl =
TXHIGHPWRLEVEL_NORMAL;
RT_TRACE(rtlpriv, COMP_HIPWR, DBG_LOUD,
"5G:TxHighPwrLevel_Normal\n");
}
} else {
if (undec_sm_pwdb >=
TX_POWER_NEAR_FIELD_THRESH_LVL2) {
rtlpriv->dm.dynamic_txhighpower_lvl =
TXHIGHPWRLEVEL_LEVEL2;
RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
"TXHIGHPWRLEVEL_LEVEL1 (TxPwr=0x0)\n");
} else
if ((undec_sm_pwdb <
(TX_POWER_NEAR_FIELD_THRESH_LVL2 - 3))
&& (undec_sm_pwdb >=
TX_POWER_NEAR_FIELD_THRESH_LVL1)) {
rtlpriv->dm.dynamic_txhighpower_lvl =
TXHIGHPWRLEVEL_LEVEL1;
RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
"TXHIGHPWRLEVEL_LEVEL1 (TxPwr=0x10)\n");
} else if (undec_sm_pwdb <
(TX_POWER_NEAR_FIELD_THRESH_LVL1 - 5)) {
rtlpriv->dm.dynamic_txhighpower_lvl =
TXHIGHPWRLEVEL_NORMAL;
RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
"TXHIGHPWRLEVEL_NORMAL\n");
}
}
if ((rtlpriv->dm.dynamic_txhighpower_lvl != rtlpriv->dm.last_dtp_lvl)) {
RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
"PHY_SetTxPowerLevel8192S() Channel = %d\n",
rtlphy->current_channel);
rtl92d_phy_set_txpower_level(hw, rtlphy->current_channel);
}
rtlpriv->dm.last_dtp_lvl = rtlpriv->dm.dynamic_txhighpower_lvl;
}
static void rtl92d_dm_pwdb_monitor(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
if (rtlpriv->mac80211.opmode != NL80211_IFTYPE_STATION)
return;
if (rtlpriv->dm.useramask) {
u32 temp = rtlpriv->dm.undec_sm_pwdb;
temp <<= 16;
temp |= 0x100;
rtl92d_fill_h2c_cmd(hw, H2C_RSSI_REPORT, 3, (u8 *) (&temp));
} else {
rtl_write_byte(rtlpriv, 0x4fe,
(u8) rtlpriv->dm.undec_sm_pwdb);
}
}
void rtl92d_dm_init_edca_turbo(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
rtlpriv->dm.current_turbo_edca = false;
rtlpriv->dm.is_any_nonbepkts = false;
rtlpriv->dm.is_cur_rdlstate = false;
}
static void rtl92d_dm_check_edca_turbo(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
static u64 last_txok_cnt;
static u64 last_rxok_cnt;
u64 cur_txok_cnt;
u64 cur_rxok_cnt;
u32 edca_be_ul = 0x5ea42b;
u32 edca_be_dl = 0x5ea42b;
if (mac->link_state != MAC80211_LINKED) {
rtlpriv->dm.current_turbo_edca = false;
goto exit;
}
if ((!rtlpriv->dm.disable_framebursting) &&
(rtlpriv->sec.pairwise_enc_algorithm == WEP40_ENCRYPTION ||
rtlpriv->sec.pairwise_enc_algorithm == WEP104_ENCRYPTION ||
rtlpriv->sec.pairwise_enc_algorithm == TKIP_ENCRYPTION)) {
if (!(edca_be_ul & 0xffff0000))
edca_be_ul |= 0x005e0000;
if (!(edca_be_dl & 0xffff0000))
edca_be_dl |= 0x005e0000;
}
if ((!rtlpriv->dm.is_any_nonbepkts) &&
(!rtlpriv->dm.disable_framebursting)) {
cur_txok_cnt = rtlpriv->stats.txbytesunicast - last_txok_cnt;
cur_rxok_cnt = rtlpriv->stats.rxbytesunicast - last_rxok_cnt;
if (cur_rxok_cnt > 4 * cur_txok_cnt) {
if (!rtlpriv->dm.is_cur_rdlstate ||
!rtlpriv->dm.current_turbo_edca) {
rtl_write_dword(rtlpriv, REG_EDCA_BE_PARAM,
edca_be_dl);
rtlpriv->dm.is_cur_rdlstate = true;
}
} else {
if (rtlpriv->dm.is_cur_rdlstate ||
!rtlpriv->dm.current_turbo_edca) {
rtl_write_dword(rtlpriv, REG_EDCA_BE_PARAM,
edca_be_ul);
rtlpriv->dm.is_cur_rdlstate = false;
}
}
rtlpriv->dm.current_turbo_edca = true;
} else {
if (rtlpriv->dm.current_turbo_edca) {
u8 tmp = AC0_BE;
rtlpriv->cfg->ops->set_hw_reg(hw, HW_VAR_AC_PARAM,
&tmp);
rtlpriv->dm.current_turbo_edca = false;
}
}
exit:
rtlpriv->dm.is_any_nonbepkts = false;
last_txok_cnt = rtlpriv->stats.txbytesunicast;
last_rxok_cnt = rtlpriv->stats.rxbytesunicast;
}
static void rtl92d_dm_rxgain_tracking_thermalmeter(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
u8 index_mapping[RX_INDEX_MAPPING_NUM] = {
0x0f, 0x0f, 0x0d, 0x0c, 0x0b,
0x0a, 0x09, 0x08, 0x07, 0x06,
0x05, 0x04, 0x04, 0x03, 0x02
};
int i;
u32 u4tmp;
u4tmp = (index_mapping[(rtlpriv->efuse.eeprom_thermalmeter -
rtlpriv->dm.thermalvalue_rxgain)]) << 12;
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"===> Rx Gain %x\n", u4tmp);
for (i = RF90_PATH_A; i < rtlpriv->phy.num_total_rfpath; i++)
rtl_set_rfreg(hw, i, 0x3C, RFREG_OFFSET_MASK,
(rtlpriv->phy.reg_rf3c[i] & (~(0xF000))) | u4tmp);
}
static void rtl92d_bandtype_2_4G(struct ieee80211_hw *hw, long *temp_cckg,
u8 *cck_index_old)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
int i;
unsigned long flag = 0;
long temp_cck;
rtl92d_acquire_cckandrw_pagea_ctl(hw, &flag);
temp_cck = rtl_get_bbreg(hw, RCCK0_TXFILTER2,
MASKDWORD) & MASKCCK;
rtl92d_release_cckandrw_pagea_ctl(hw, &flag);
for (i = 0; i < CCK_TABLE_LENGTH; i++) {
if (rtlpriv->dm.cck_inch14) {
if (!memcmp((void *)&temp_cck,
(void *)&cckswing_table_ch14[i][2], 4)) {
*cck_index_old = (u8) i;
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"Initial reg0x%x = 0x%lx, cck_index=0x%x, ch 14 %d\n",
RCCK0_TXFILTER2, temp_cck,
*cck_index_old,
rtlpriv->dm.cck_inch14);
break;
}
} else {
if (!memcmp((void *) &temp_cck,
&cckswing_table_ch1ch13[i][2], 4)) {
*cck_index_old = (u8) i;
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"Initial reg0x%x = 0x%lx, cck_index = 0x%x, ch14 %d\n",
RCCK0_TXFILTER2, temp_cck,
*cck_index_old,
rtlpriv->dm.cck_inch14);
break;
}
}
}
*temp_cckg = temp_cck;
}
static void rtl92d_bandtype_5G(struct rtl_hal *rtlhal, u8 *ofdm_index,
bool *internal_pa, u8 thermalvalue, u8 delta,
u8 rf, struct rtl_efuse *rtlefuse,
struct rtl_priv *rtlpriv, struct rtl_phy *rtlphy,
u8 index_mapping[5][INDEX_MAPPING_NUM],
u8 index_mapping_pa[8][INDEX_MAPPING_NUM])
{
int i;
u8 index;
u8 offset = 0;
for (i = 0; i < rf; i++) {
if (rtlhal->macphymode == DUALMAC_DUALPHY &&
rtlhal->interfaceindex == 1)
*internal_pa = rtlefuse->internal_pa_5g[1];
else
*internal_pa = rtlefuse->internal_pa_5g[i];
if (*internal_pa) {
if (rtlhal->interfaceindex == 1 || i == rf)
offset = 4;
else
offset = 0;
if (rtlphy->current_channel >= 100 &&
rtlphy->current_channel <= 165)
offset += 2;
} else {
if (rtlhal->interfaceindex == 1 || i == rf)
offset = 2;
else
offset = 0;
}
if (thermalvalue > rtlefuse->eeprom_thermalmeter)
offset++;
if (*internal_pa) {
if (delta > INDEX_MAPPING_NUM - 1)
index = index_mapping_pa[offset]
[INDEX_MAPPING_NUM - 1];
else
index =
index_mapping_pa[offset][delta];
} else {
if (delta > INDEX_MAPPING_NUM - 1)
index =
index_mapping[offset][INDEX_MAPPING_NUM - 1];
else
index = index_mapping[offset][delta];
}
if (thermalvalue > rtlefuse->eeprom_thermalmeter) {
if (*internal_pa && thermalvalue > 0x12) {
ofdm_index[i] = rtlpriv->dm.ofdm_index[i] -
((delta / 2) * 3 + (delta % 2));
} else {
ofdm_index[i] -= index;
}
} else {
ofdm_index[i] += index;
}
}
}
static void rtl92d_dm_txpower_tracking_callback_thermalmeter(
struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
struct rtl_phy *rtlphy = &(rtlpriv->phy);
struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
u8 thermalvalue, delta, delta_lck, delta_iqk, delta_rxgain;
u8 offset, thermalvalue_avg_count = 0;
u32 thermalvalue_avg = 0;
bool internal_pa = false;
long ele_a = 0, ele_d, temp_cck, val_x, value32;
long val_y, ele_c = 0;
u8 ofdm_index[3];
s8 cck_index = 0;
u8 ofdm_index_old[3] = {0, 0, 0};
s8 cck_index_old = 0;
u8 index;
int i;
bool is2t = IS_92D_SINGLEPHY(rtlhal->version);
u8 ofdm_min_index = 6, ofdm_min_index_internal_pa = 3, rf;
u8 indexforchannel =
rtl92d_get_rightchnlplace_for_iqk(rtlphy->current_channel);
u8 index_mapping[5][INDEX_MAPPING_NUM] = {
{0, 1, 3, 6, 8, 9, 11, 13, 14, 16, 17, 18, 18},
{0, 2, 4, 5, 7, 10, 12, 14, 16, 18, 18, 18, 18},
{0, 2, 3, 6, 8, 9, 11, 13, 14, 16, 17, 18, 18},
{0, 2, 4, 5, 7, 10, 13, 16, 16, 18, 18, 18, 18},
{0, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 10},
};
u8 index_mapping_internal_pa[8][INDEX_MAPPING_NUM] = {
{0, 1, 2, 4, 6, 7, 9, 11, 12, 14, 15, 16, 16},
{0, 2, 4, 5, 7, 10, 12, 14, 16, 18, 18, 18, 18},
{0, 1, 2, 3, 5, 6, 8, 10, 11, 13, 14, 15, 15},
{0, 2, 4, 5, 7, 10, 12, 14, 16, 18, 18, 18, 18},
{0, 1, 2, 4, 6, 7, 9, 11, 12, 14, 15, 16, 16},
{0, 2, 4, 5, 7, 10, 13, 16, 16, 18, 18, 18, 18},
{0, 1, 2, 3, 5, 6, 8, 9, 10, 12, 13, 14, 14},
{0, 2, 4, 5, 7, 10, 13, 16, 16, 18, 18, 18, 18},
};
rtlpriv->dm.txpower_trackinginit = true;
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD, "\n");
thermalvalue = (u8) rtl_get_rfreg(hw, RF90_PATH_A, RF_T_METER, 0xf800);
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"Readback Thermal Meter = 0x%x pre thermal meter 0x%x eeprom_thermalmeter 0x%x\n",
thermalvalue,
rtlpriv->dm.thermalvalue, rtlefuse->eeprom_thermalmeter);
rtl92d_phy_ap_calibrate(hw, (thermalvalue -
rtlefuse->eeprom_thermalmeter));
if (is2t)
rf = 2;
else
rf = 1;
if (thermalvalue) {
ele_d = rtl_get_bbreg(hw, ROFDM0_XATxIQIMBALANCE,
MASKDWORD) & MASKOFDM_D;
for (i = 0; i < OFDM_TABLE_SIZE_92D; i++) {
if (ele_d == (ofdmswing_table[i] & MASKOFDM_D)) {
ofdm_index_old[0] = (u8) i;
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"Initial pathA ele_d reg0x%x = 0x%lx, ofdm_index=0x%x\n",
ROFDM0_XATxIQIMBALANCE,
ele_d, ofdm_index_old[0]);
break;
}
}
if (is2t) {
ele_d = rtl_get_bbreg(hw, ROFDM0_XBTxIQIMBALANCE,
MASKDWORD) & MASKOFDM_D;
for (i = 0; i < OFDM_TABLE_SIZE_92D; i++) {
if (ele_d ==
(ofdmswing_table[i] & MASKOFDM_D)) {
ofdm_index_old[1] = (u8) i;
RT_TRACE(rtlpriv, COMP_POWER_TRACKING,
DBG_LOUD,
"Initial pathB ele_d reg 0x%x = 0x%lx, ofdm_index = 0x%x\n",
ROFDM0_XBTxIQIMBALANCE, ele_d,
ofdm_index_old[1]);
break;
}
}
}
if (rtlhal->current_bandtype == BAND_ON_2_4G) {
rtl92d_bandtype_2_4G(hw, &temp_cck, &cck_index_old);
} else {
temp_cck = 0x090e1317;
cck_index_old = 12;
}
if (!rtlpriv->dm.thermalvalue) {
rtlpriv->dm.thermalvalue =
rtlefuse->eeprom_thermalmeter;
rtlpriv->dm.thermalvalue_lck = thermalvalue;
rtlpriv->dm.thermalvalue_iqk = thermalvalue;
rtlpriv->dm.thermalvalue_rxgain =
rtlefuse->eeprom_thermalmeter;
for (i = 0; i < rf; i++)
rtlpriv->dm.ofdm_index[i] = ofdm_index_old[i];
rtlpriv->dm.cck_index = cck_index_old;
}
if (rtlhal->reloadtxpowerindex) {
for (i = 0; i < rf; i++)
rtlpriv->dm.ofdm_index[i] = ofdm_index_old[i];
rtlpriv->dm.cck_index = cck_index_old;
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"reload ofdm index for band switch\n");
}
rtlpriv->dm.thermalvalue_avg
[rtlpriv->dm.thermalvalue_avg_index] = thermalvalue;
rtlpriv->dm.thermalvalue_avg_index++;
if (rtlpriv->dm.thermalvalue_avg_index == AVG_THERMAL_NUM)
rtlpriv->dm.thermalvalue_avg_index = 0;
for (i = 0; i < AVG_THERMAL_NUM; i++) {
if (rtlpriv->dm.thermalvalue_avg[i]) {
thermalvalue_avg +=
rtlpriv->dm.thermalvalue_avg[i];
thermalvalue_avg_count++;
}
}
if (thermalvalue_avg_count)
thermalvalue = (u8) (thermalvalue_avg /
thermalvalue_avg_count);
if (rtlhal->reloadtxpowerindex) {
delta = (thermalvalue > rtlefuse->eeprom_thermalmeter) ?
(thermalvalue - rtlefuse->eeprom_thermalmeter) :
(rtlefuse->eeprom_thermalmeter - thermalvalue);
rtlhal->reloadtxpowerindex = false;
rtlpriv->dm.done_txpower = false;
} else if (rtlpriv->dm.done_txpower) {
delta = (thermalvalue > rtlpriv->dm.thermalvalue) ?
(thermalvalue - rtlpriv->dm.thermalvalue) :
(rtlpriv->dm.thermalvalue - thermalvalue);
} else {
delta = (thermalvalue > rtlefuse->eeprom_thermalmeter) ?
(thermalvalue - rtlefuse->eeprom_thermalmeter) :
(rtlefuse->eeprom_thermalmeter - thermalvalue);
}
delta_lck = (thermalvalue > rtlpriv->dm.thermalvalue_lck) ?
(thermalvalue - rtlpriv->dm.thermalvalue_lck) :
(rtlpriv->dm.thermalvalue_lck - thermalvalue);
delta_iqk = (thermalvalue > rtlpriv->dm.thermalvalue_iqk) ?
(thermalvalue - rtlpriv->dm.thermalvalue_iqk) :
(rtlpriv->dm.thermalvalue_iqk - thermalvalue);
delta_rxgain =
(thermalvalue > rtlpriv->dm.thermalvalue_rxgain) ?
(thermalvalue - rtlpriv->dm.thermalvalue_rxgain) :
(rtlpriv->dm.thermalvalue_rxgain - thermalvalue);
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"Readback Thermal Meter = 0x%x pre thermal meter 0x%x eeprom_thermalmeter 0x%x delta 0x%x delta_lck 0x%x delta_iqk 0x%x\n",
thermalvalue, rtlpriv->dm.thermalvalue,
rtlefuse->eeprom_thermalmeter, delta, delta_lck,
delta_iqk);
if ((delta_lck > rtlefuse->delta_lck) &&
(rtlefuse->delta_lck != 0)) {
rtlpriv->dm.thermalvalue_lck = thermalvalue;
rtl92d_phy_lc_calibrate(hw);
}
if (delta > 0 && rtlpriv->dm.txpower_track_control) {
rtlpriv->dm.done_txpower = true;
delta = (thermalvalue > rtlefuse->eeprom_thermalmeter) ?
(thermalvalue - rtlefuse->eeprom_thermalmeter) :
(rtlefuse->eeprom_thermalmeter - thermalvalue);
if (rtlhal->current_bandtype == BAND_ON_2_4G) {
offset = 4;
if (delta > INDEX_MAPPING_NUM - 1)
index = index_mapping[offset]
[INDEX_MAPPING_NUM - 1];
else
index = index_mapping[offset][delta];
if (thermalvalue > rtlpriv->dm.thermalvalue) {
for (i = 0; i < rf; i++)
ofdm_index[i] -= delta;
cck_index -= delta;
} else {
for (i = 0; i < rf; i++)
ofdm_index[i] += index;
cck_index += index;
}
} else if (rtlhal->current_bandtype == BAND_ON_5G) {
rtl92d_bandtype_5G(rtlhal, ofdm_index,
&internal_pa, thermalvalue,
delta, rf, rtlefuse, rtlpriv,
rtlphy, index_mapping,
index_mapping_internal_pa);
}
if (is2t) {
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"temp OFDM_A_index=0x%x, OFDM_B_index = 0x%x,cck_index=0x%x\n",
rtlpriv->dm.ofdm_index[0],
rtlpriv->dm.ofdm_index[1],
rtlpriv->dm.cck_index);
} else {
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"temp OFDM_A_index=0x%x,cck_index = 0x%x\n",
rtlpriv->dm.ofdm_index[0],
rtlpriv->dm.cck_index);
}
for (i = 0; i < rf; i++) {
if (ofdm_index[i] > OFDM_TABLE_SIZE_92D - 1)
ofdm_index[i] = OFDM_TABLE_SIZE_92D - 1;
else if (ofdm_index[i] < ofdm_min_index)
ofdm_index[i] = ofdm_min_index;
}
if (rtlhal->current_bandtype == BAND_ON_2_4G) {
if (cck_index > CCK_TABLE_SIZE - 1) {
cck_index = CCK_TABLE_SIZE - 1;
} else if (internal_pa ||
rtlhal->current_bandtype ==
BAND_ON_2_4G) {
if (ofdm_index[i] <
ofdm_min_index_internal_pa)
ofdm_index[i] =
ofdm_min_index_internal_pa;
} else if (cck_index < 0) {
cck_index = 0;
}
}
if (is2t) {
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"new OFDM_A_index=0x%x, OFDM_B_index = 0x%x, cck_index=0x%x\n",
ofdm_index[0], ofdm_index[1],
cck_index);
} else {
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"new OFDM_A_index=0x%x,cck_index = 0x%x\n",
ofdm_index[0], cck_index);
}
ele_d = (ofdmswing_table[(u8) ofdm_index[0]] &
0xFFC00000) >> 22;
val_x = rtlphy->iqk_matrix
[indexforchannel].value[0][0];
val_y = rtlphy->iqk_matrix
[indexforchannel].value[0][1];
if (val_x != 0) {
if ((val_x & 0x00000200) != 0)
val_x = val_x | 0xFFFFFC00;
ele_a =
((val_x * ele_d) >> 8) & 0x000003FF;
if ((val_y & 0x00000200) != 0)
val_y = val_y | 0xFFFFFC00;
ele_c = ((val_y * ele_d) >> 8) & 0x000003FF;
value32 = (ele_d << 22) | ((ele_c & 0x3F) <<
16) | ele_a;
rtl_set_bbreg(hw, ROFDM0_XATxIQIMBALANCE,
MASKDWORD, value32);
value32 = (ele_c & 0x000003C0) >> 6;
rtl_set_bbreg(hw, ROFDM0_XCTxAFE, MASKH4BITS,
value32);
value32 = ((val_x * ele_d) >> 7) & 0x01;
rtl_set_bbreg(hw, ROFDM0_ECCATHRESHOLD, BIT(24),
value32);
} else {
rtl_set_bbreg(hw, ROFDM0_XATxIQIMBALANCE,
MASKDWORD,
ofdmswing_table
[(u8)ofdm_index[0]]);
rtl_set_bbreg(hw, ROFDM0_XCTxAFE, MASKH4BITS,
0x00);
rtl_set_bbreg(hw, ROFDM0_ECCATHRESHOLD,
BIT(24), 0x00);
}
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"TxPwrTracking for interface %d path A: X = 0x%lx, Y = 0x%lx ele_A = 0x%lx ele_C = 0x%lx ele_D = 0x%lx 0xe94 = 0x%lx 0xe9c = 0x%lx\n",
rtlhal->interfaceindex,
val_x, val_y, ele_a, ele_c, ele_d,
val_x, val_y);
if (cck_index >= CCK_TABLE_SIZE)
cck_index = CCK_TABLE_SIZE - 1;
if (cck_index < 0)
cck_index = 0;
if (rtlhal->current_bandtype == BAND_ON_2_4G) {
if (!rtlpriv->dm.cck_inch14) {
rtl_write_byte(rtlpriv, 0xa22,
cckswing_table_ch1ch13
[(u8)cck_index][0]);
rtl_write_byte(rtlpriv, 0xa23,
cckswing_table_ch1ch13
[(u8)cck_index][1]);
rtl_write_byte(rtlpriv, 0xa24,
cckswing_table_ch1ch13
[(u8)cck_index][2]);
rtl_write_byte(rtlpriv, 0xa25,
cckswing_table_ch1ch13
[(u8)cck_index][3]);
rtl_write_byte(rtlpriv, 0xa26,
cckswing_table_ch1ch13
[(u8)cck_index][4]);
rtl_write_byte(rtlpriv, 0xa27,
cckswing_table_ch1ch13
[(u8)cck_index][5]);
rtl_write_byte(rtlpriv, 0xa28,
cckswing_table_ch1ch13
[(u8)cck_index][6]);
rtl_write_byte(rtlpriv, 0xa29,
cckswing_table_ch1ch13
[(u8)cck_index][7]);
} else {
rtl_write_byte(rtlpriv, 0xa22,
cckswing_table_ch14
[(u8)cck_index][0]);
rtl_write_byte(rtlpriv, 0xa23,
cckswing_table_ch14
[(u8)cck_index][1]);
rtl_write_byte(rtlpriv, 0xa24,
cckswing_table_ch14
[(u8)cck_index][2]);
rtl_write_byte(rtlpriv, 0xa25,
cckswing_table_ch14
[(u8)cck_index][3]);
rtl_write_byte(rtlpriv, 0xa26,
cckswing_table_ch14
[(u8)cck_index][4]);
rtl_write_byte(rtlpriv, 0xa27,
cckswing_table_ch14
[(u8)cck_index][5]);
rtl_write_byte(rtlpriv, 0xa28,
cckswing_table_ch14
[(u8)cck_index][6]);
rtl_write_byte(rtlpriv, 0xa29,
cckswing_table_ch14
[(u8)cck_index][7]);
}
}
if (is2t) {
ele_d = (ofdmswing_table[(u8) ofdm_index[1]] &
0xFFC00000) >> 22;
val_x = rtlphy->iqk_matrix
[indexforchannel].value[0][4];
val_y = rtlphy->iqk_matrix
[indexforchannel].value[0][5];
if (val_x != 0) {
if ((val_x & 0x00000200) != 0)
val_x = val_x | 0xFFFFFC00;
ele_a = ((val_x * ele_d) >> 8) &
0x000003FF;
if ((val_y & 0x00000200) != 0)
val_y =
val_y | 0xFFFFFC00;
ele_c =
((val_y *
ele_d) >> 8) & 0x00003FF;
value32 = (ele_d << 22) |
((ele_c & 0x3F) << 16) |
ele_a;
rtl_set_bbreg(hw,
ROFDM0_XBTxIQIMBALANCE,
MASKDWORD, value32);
value32 = (ele_c & 0x000003C0) >> 6;
rtl_set_bbreg(hw, ROFDM0_XDTxAFE,
MASKH4BITS, value32);
value32 = ((val_x * ele_d) >> 7) & 0x01;
rtl_set_bbreg(hw, ROFDM0_ECCATHRESHOLD,
BIT(28), value32);
} else {
rtl_set_bbreg(hw,
ROFDM0_XBTxIQIMBALANCE,
MASKDWORD,
ofdmswing_table
[(u8) ofdm_index[1]]);
rtl_set_bbreg(hw, ROFDM0_XDTxAFE,
MASKH4BITS, 0x00);
rtl_set_bbreg(hw, ROFDM0_ECCATHRESHOLD,
BIT(28), 0x00);
}
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"TxPwrTracking path B: X = 0x%lx, Y = 0x%lx ele_A = 0x%lx ele_C = 0x%lx ele_D = 0x%lx 0xeb4 = 0x%lx 0xebc = 0x%lx\n",
val_x, val_y, ele_a, ele_c,
ele_d, val_x, val_y);
}
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"TxPwrTracking 0xc80 = 0x%x, 0xc94 = 0x%x RF 0x24 = 0x%x\n",
rtl_get_bbreg(hw, 0xc80, MASKDWORD),
rtl_get_bbreg(hw, 0xc94, MASKDWORD),
rtl_get_rfreg(hw, RF90_PATH_A, 0x24,
RFREG_OFFSET_MASK));
}
if ((delta_iqk > rtlefuse->delta_iqk) &&
(rtlefuse->delta_iqk != 0)) {
rtl92d_phy_reset_iqk_result(hw);
rtlpriv->dm.thermalvalue_iqk = thermalvalue;
rtl92d_phy_iq_calibrate(hw);
}
if (delta_rxgain > 0 && rtlhal->current_bandtype == BAND_ON_5G
&& thermalvalue <= rtlefuse->eeprom_thermalmeter) {
rtlpriv->dm.thermalvalue_rxgain = thermalvalue;
rtl92d_dm_rxgain_tracking_thermalmeter(hw);
}
if (rtlpriv->dm.txpower_track_control)
rtlpriv->dm.thermalvalue = thermalvalue;
}
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD, "<===\n");
}
static void rtl92d_dm_initialize_txpower_tracking(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
rtlpriv->dm.txpower_tracking = true;
rtlpriv->dm.txpower_trackinginit = false;
rtlpriv->dm.txpower_track_control = true;
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"pMgntInfo->txpower_tracking = %d\n",
rtlpriv->dm.txpower_tracking);
}
void rtl92d_dm_check_txpower_tracking_thermal_meter(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
if (!rtlpriv->dm.txpower_tracking)
return;
if (!rtlpriv->dm.tm_trigger) {
rtl_set_rfreg(hw, RF90_PATH_A, RF_T_METER, BIT(17) |
BIT(16), 0x03);
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"Trigger 92S Thermal Meter!!\n");
rtlpriv->dm.tm_trigger = 1;
return;
} else {
RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
"Schedule TxPowerTracking direct call!!\n");
rtl92d_dm_txpower_tracking_callback_thermalmeter(hw);
rtlpriv->dm.tm_trigger = 0;
}
}
void rtl92d_dm_init_rate_adaptive_mask(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rate_adaptive *ra = &(rtlpriv->ra);
ra->ratr_state = DM_RATR_STA_INIT;
ra->pre_ratr_state = DM_RATR_STA_INIT;
if (rtlpriv->dm.dm_type == DM_TYPE_BYDRIVER)
rtlpriv->dm.useramask = true;
else
rtlpriv->dm.useramask = false;
}
void rtl92d_dm_init(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
rtlpriv->dm.dm_type = DM_TYPE_BYDRIVER;
rtl_dm_diginit(hw, 0x20);
rtlpriv->dm_digtable.rx_gain_max = DM_DIG_FA_UPPER;
rtlpriv->dm_digtable.rx_gain_min = DM_DIG_FA_LOWER;
rtl92d_dm_init_dynamic_txpower(hw);
rtl92d_dm_init_edca_turbo(hw);
rtl92d_dm_init_rate_adaptive_mask(hw);
rtl92d_dm_initialize_txpower_tracking(hw);
}
void rtl92d_dm_watchdog(struct ieee80211_hw *hw)
{
struct rtl_ps_ctl *ppsc = rtl_psc(rtl_priv(hw));
bool fw_current_inpsmode = false;
bool fwps_awake = true;
if ((ppsc->rfpwr_state == ERFON) && ((!fw_current_inpsmode) &&
fwps_awake) && (!ppsc->rfchange_inprogress)) {
rtl92d_dm_pwdb_monitor(hw);
rtl92d_dm_false_alarm_counter_statistics(hw);
rtl92d_dm_find_minimum_rssi(hw);
rtl92d_dm_dig(hw);
rtl92d_dm_dynamic_txpower(hw);
rtl92d_dm_check_edca_turbo(hw);
}
}
