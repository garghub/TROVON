void init_hal_dm(struct r8192_priv *priv)
{
priv->undecorated_smoothed_pwdb = -1;
dm_init_dynamic_txpower(priv);
init_rate_adaptive(priv);
dm_dig_init(priv);
dm_init_edca_turbo(priv);
dm_init_bandwidth_autoswitch(priv);
dm_init_fsync(priv);
dm_init_rxpath_selection(priv);
dm_init_ctstoself(priv);
INIT_DELAYED_WORK(&priv->gpio_change_rf_wq, dm_gpio_change_rf_callback);
}
void deinit_hal_dm(struct r8192_priv *priv)
{
dm_deInit_fsync(priv);
}
void hal_dm_watchdog(struct r8192_priv *priv)
{
dm_check_rate_adaptive(priv);
dm_dynamic_txpower(priv);
dm_check_txrateandretrycount(priv);
dm_check_txpower_tracking(priv);
dm_ctrl_initgain_byrssi(priv);
dm_check_edca_turbo(priv);
dm_bandwidth_autoswitch(priv);
dm_check_rfctrl_gpio(priv);
dm_check_rx_path_selection(priv);
dm_check_fsync(priv);
dm_send_rssi_tofw(priv);
dm_ctstoself(priv);
}
void init_rate_adaptive(struct r8192_priv *priv)
{
prate_adaptive pra = &priv->rate_adaptive;
pra->ratr_state = DM_RATR_STA_MAX;
pra->high2low_rssi_thresh_for_ra = RateAdaptiveTH_High;
pra->low2high_rssi_thresh_for_ra20M = RateAdaptiveTH_Low_20M+5;
pra->low2high_rssi_thresh_for_ra40M = RateAdaptiveTH_Low_40M+5;
pra->high_rssi_thresh_for_ra = RateAdaptiveTH_High+5;
pra->low_rssi_thresh_for_ra20M = RateAdaptiveTH_Low_20M;
pra->low_rssi_thresh_for_ra40M = RateAdaptiveTH_Low_40M;
if(priv->CustomerID == RT_CID_819x_Netcore)
pra->ping_rssi_enable = 1;
else
pra->ping_rssi_enable = 0;
pra->ping_rssi_thresh_for_ra = 15;
if (priv->rf_type == RF_2T4R)
{
pra->upper_rssi_threshold_ratr = 0x8f0f0000;
pra->middle_rssi_threshold_ratr = 0x8f0ff000;
pra->low_rssi_threshold_ratr = 0x8f0ff001;
pra->low_rssi_threshold_ratr_40M = 0x8f0ff005;
pra->low_rssi_threshold_ratr_20M = 0x8f0ff001;
pra->ping_rssi_ratr = 0x0000000d;
}
else if (priv->rf_type == RF_1T2R)
{
pra->upper_rssi_threshold_ratr = 0x000f0000;
pra->middle_rssi_threshold_ratr = 0x000ff000;
pra->low_rssi_threshold_ratr = 0x000ff001;
pra->low_rssi_threshold_ratr_40M = 0x000ff005;
pra->low_rssi_threshold_ratr_20M = 0x000ff001;
pra->ping_rssi_ratr = 0x0000000d;
}
}
static void dm_check_rate_adaptive(struct r8192_priv *priv)
{
PRT_HIGH_THROUGHPUT pHTInfo = priv->ieee80211->pHTInfo;
prate_adaptive pra = (prate_adaptive)&priv->rate_adaptive;
u32 currentRATR, targetRATR = 0;
u32 LowRSSIThreshForRA = 0, HighRSSIThreshForRA = 0;
bool bshort_gi_enabled = false;
static u8 ping_rssi_state=0;
if(!priv->up)
{
RT_TRACE(COMP_RATE, "<---- dm_check_rate_adaptive(): driver is going to unload\n");
return;
}
if(pra->rate_adaptive_disabled)
return;
if( !(priv->ieee80211->mode == WIRELESS_MODE_N_24G ||
priv->ieee80211->mode == WIRELESS_MODE_N_5G))
return;
if( priv->ieee80211->state == IEEE80211_LINKED )
{
bshort_gi_enabled = (pHTInfo->bCurTxBW40MHz && pHTInfo->bCurShortGI40MHz) ||
(!pHTInfo->bCurTxBW40MHz && pHTInfo->bCurShortGI20MHz);
pra->upper_rssi_threshold_ratr =
(pra->upper_rssi_threshold_ratr & (~BIT31)) | ((bshort_gi_enabled)? BIT31:0) ;
pra->middle_rssi_threshold_ratr =
(pra->middle_rssi_threshold_ratr & (~BIT31)) | ((bshort_gi_enabled)? BIT31:0) ;
if (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
{
pra->low_rssi_threshold_ratr =
(pra->low_rssi_threshold_ratr_40M & (~BIT31)) | ((bshort_gi_enabled)? BIT31:0) ;
}
else
{
pra->low_rssi_threshold_ratr =
(pra->low_rssi_threshold_ratr_20M & (~BIT31)) | ((bshort_gi_enabled)? BIT31:0) ;
}
pra->ping_rssi_ratr =
(pra->ping_rssi_ratr & (~BIT31)) | ((bshort_gi_enabled)? BIT31:0) ;
if (pra->ratr_state == DM_RATR_STA_HIGH)
{
HighRSSIThreshForRA = pra->high2low_rssi_thresh_for_ra;
LowRSSIThreshForRA = (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)?
(pra->low_rssi_thresh_for_ra40M):(pra->low_rssi_thresh_for_ra20M);
}
else if (pra->ratr_state == DM_RATR_STA_LOW)
{
HighRSSIThreshForRA = pra->high_rssi_thresh_for_ra;
LowRSSIThreshForRA = (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)?
(pra->low2high_rssi_thresh_for_ra40M):(pra->low2high_rssi_thresh_for_ra20M);
}
else
{
HighRSSIThreshForRA = pra->high_rssi_thresh_for_ra;
LowRSSIThreshForRA = (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)?
(pra->low_rssi_thresh_for_ra40M):(pra->low_rssi_thresh_for_ra20M);
}
if(priv->undecorated_smoothed_pwdb >= (long)HighRSSIThreshForRA)
{
pra->ratr_state = DM_RATR_STA_HIGH;
targetRATR = pra->upper_rssi_threshold_ratr;
}else if(priv->undecorated_smoothed_pwdb >= (long)LowRSSIThreshForRA)
{
pra->ratr_state = DM_RATR_STA_MIDDLE;
targetRATR = pra->middle_rssi_threshold_ratr;
}else
{
pra->ratr_state = DM_RATR_STA_LOW;
targetRATR = pra->low_rssi_threshold_ratr;
}
if(pra->ping_rssi_enable)
{
if(priv->undecorated_smoothed_pwdb < (long)(pra->ping_rssi_thresh_for_ra+5))
{
if( (priv->undecorated_smoothed_pwdb < (long)pra->ping_rssi_thresh_for_ra) ||
ping_rssi_state )
{
pra->ratr_state = DM_RATR_STA_LOW;
targetRATR = pra->ping_rssi_ratr;
ping_rssi_state = 1;
}
}
else
{
ping_rssi_state = 0;
}
}
if(priv->ieee80211->GetHalfNmodeSupportByAPsHandler(priv->ieee80211))
targetRATR &= 0xf00fffff;
currentRATR = read_nic_dword(priv, RATR0);
if( targetRATR != currentRATR )
{
u32 ratr_value;
ratr_value = targetRATR;
RT_TRACE(COMP_RATE,"currentRATR = %x, targetRATR = %x\n", currentRATR, targetRATR);
if(priv->rf_type == RF_1T2R)
{
ratr_value &= ~(RATE_ALL_OFDM_2SS);
}
write_nic_dword(priv, RATR0, ratr_value);
write_nic_byte(priv, UFWP, 1);
pra->last_ratr = targetRATR;
}
}
else
{
pra->ratr_state = DM_RATR_STA_MAX;
}
}
static void dm_init_bandwidth_autoswitch(struct r8192_priv *priv)
{
priv->ieee80211->bandwidth_auto_switch.threshold_20Mhzto40Mhz = BW_AUTO_SWITCH_LOW_HIGH;
priv->ieee80211->bandwidth_auto_switch.threshold_40Mhzto20Mhz = BW_AUTO_SWITCH_HIGH_LOW;
priv->ieee80211->bandwidth_auto_switch.bforced_tx20Mhz = false;
priv->ieee80211->bandwidth_auto_switch.bautoswitch_enable = false;
}
static void dm_bandwidth_autoswitch(struct r8192_priv *priv)
{
if(priv->CurrentChannelBW == HT_CHANNEL_WIDTH_20 ||!priv->ieee80211->bandwidth_auto_switch.bautoswitch_enable){
return;
}else{
if(priv->ieee80211->bandwidth_auto_switch.bforced_tx20Mhz == false){
if(priv->undecorated_smoothed_pwdb <= priv->ieee80211->bandwidth_auto_switch.threshold_40Mhzto20Mhz)
priv->ieee80211->bandwidth_auto_switch.bforced_tx20Mhz = true;
}else{
if(priv->undecorated_smoothed_pwdb >= priv->ieee80211->bandwidth_auto_switch.threshold_20Mhzto40Mhz)
priv->ieee80211->bandwidth_auto_switch.bforced_tx20Mhz = false;
}
}
}
static void dm_TXPowerTrackingCallback_TSSI(struct r8192_priv *priv)
{
bool bHighpowerstate, viviflag = FALSE;
DCMD_TXCMD_T tx_cmd;
u8 powerlevelOFDM24G;
int i =0, j = 0, k = 0;
u8 RF_Type, tmp_report[5]={0, 0, 0, 0, 0};
u32 Value;
u8 Pwr_Flag;
u16 Avg_TSSI_Meas, TSSI_13dBm, Avg_TSSI_Meas_from_driver=0;
u32 delta=0;
RT_TRACE(COMP_POWER_TRACKING,"%s()\n",__FUNCTION__);
write_nic_byte(priv, Pw_Track_Flag, 0);
write_nic_byte(priv, FW_Busy_Flag, 0);
priv->ieee80211->bdynamic_txpower_enable = false;
bHighpowerstate = priv->bDynamicTxHighPower;
powerlevelOFDM24G = (u8)(priv->Pwr_Track>>24);
RF_Type = priv->rf_type;
Value = (RF_Type<<8) | powerlevelOFDM24G;
RT_TRACE(COMP_POWER_TRACKING, "powerlevelOFDM24G = %x\n", powerlevelOFDM24G);
for(j = 0; j<=30; j++)
{
tx_cmd.Op = TXCMD_SET_TX_PWR_TRACKING;
tx_cmd.Length = 4;
tx_cmd.Value = Value;
cmpk_message_handle_tx(priv, (u8*)&tx_cmd, DESC_PACKET_TYPE_INIT, sizeof(DCMD_TXCMD_T));
mdelay(1);
for(i = 0;i <= 30; i++)
{
Pwr_Flag = read_nic_byte(priv, Pw_Track_Flag);
if (Pwr_Flag == 0)
{
mdelay(1);
continue;
}
Avg_TSSI_Meas = read_nic_word(priv, Tssi_Mea_Value);
if(Avg_TSSI_Meas == 0)
{
write_nic_byte(priv, Pw_Track_Flag, 0);
write_nic_byte(priv, FW_Busy_Flag, 0);
return;
}
for(k = 0;k < 5; k++)
{
if(k !=4)
tmp_report[k] = read_nic_byte(priv, Tssi_Report_Value1+k);
else
tmp_report[k] = read_nic_byte(priv, Tssi_Report_Value2);
RT_TRACE(COMP_POWER_TRACKING, "TSSI_report_value = %d\n", tmp_report[k]);
}
for(k = 0;k < 5; k++)
{
if(tmp_report[k] <= 20)
{
viviflag =TRUE;
break;
}
}
if(viviflag ==TRUE)
{
write_nic_byte(priv, Pw_Track_Flag, 0);
viviflag = FALSE;
RT_TRACE(COMP_POWER_TRACKING, "we filted this data\n");
for(k = 0;k < 5; k++)
tmp_report[k] = 0;
break;
}
for(k = 0;k < 5; k++)
{
Avg_TSSI_Meas_from_driver += tmp_report[k];
}
Avg_TSSI_Meas_from_driver = Avg_TSSI_Meas_from_driver*100/5;
RT_TRACE(COMP_POWER_TRACKING, "Avg_TSSI_Meas_from_driver = %d\n", Avg_TSSI_Meas_from_driver);
TSSI_13dBm = priv->TSSI_13dBm;
RT_TRACE(COMP_POWER_TRACKING, "TSSI_13dBm = %d\n", TSSI_13dBm);
if(Avg_TSSI_Meas_from_driver > TSSI_13dBm)
delta = Avg_TSSI_Meas_from_driver - TSSI_13dBm;
else
delta = TSSI_13dBm - Avg_TSSI_Meas_from_driver;
if(delta <= E_FOR_TX_POWER_TRACK)
{
priv->ieee80211->bdynamic_txpower_enable = TRUE;
write_nic_byte(priv, Pw_Track_Flag, 0);
write_nic_byte(priv, FW_Busy_Flag, 0);
RT_TRACE(COMP_POWER_TRACKING, "tx power track is done\n");
RT_TRACE(COMP_POWER_TRACKING, "priv->rfa_txpowertrackingindex = %d\n", priv->rfa_txpowertrackingindex);
RT_TRACE(COMP_POWER_TRACKING, "priv->rfa_txpowertrackingindex_real = %d\n", priv->rfa_txpowertrackingindex_real);
RT_TRACE(COMP_POWER_TRACKING, "priv->CCKPresentAttentuation_difference = %d\n", priv->CCKPresentAttentuation_difference);
RT_TRACE(COMP_POWER_TRACKING, "priv->CCKPresentAttentuation = %d\n", priv->CCKPresentAttentuation);
return;
}
else
{
if(Avg_TSSI_Meas_from_driver < TSSI_13dBm - E_FOR_TX_POWER_TRACK)
{
if (RF_Type == RF_2T4R)
{
if((priv->rfa_txpowertrackingindex > 0) &&(priv->rfc_txpowertrackingindex > 0))
{
priv->rfa_txpowertrackingindex--;
if(priv->rfa_txpowertrackingindex_real > 4)
{
priv->rfa_txpowertrackingindex_real--;
rtl8192_setBBreg(priv, rOFDM0_XATxIQImbalance, bMaskDWord, priv->txbbgain_table[priv->rfa_txpowertrackingindex_real].txbbgain_value);
}
priv->rfc_txpowertrackingindex--;
if(priv->rfc_txpowertrackingindex_real > 4)
{
priv->rfc_txpowertrackingindex_real--;
rtl8192_setBBreg(priv, rOFDM0_XCTxIQImbalance, bMaskDWord, priv->txbbgain_table[priv->rfc_txpowertrackingindex_real].txbbgain_value);
}
}
else
{
rtl8192_setBBreg(priv, rOFDM0_XATxIQImbalance, bMaskDWord, priv->txbbgain_table[4].txbbgain_value);
rtl8192_setBBreg(priv, rOFDM0_XCTxIQImbalance, bMaskDWord, priv->txbbgain_table[4].txbbgain_value);
}
}
else
{
if(priv->rfc_txpowertrackingindex > 0)
{
priv->rfc_txpowertrackingindex--;
if(priv->rfc_txpowertrackingindex_real > 4)
{
priv->rfc_txpowertrackingindex_real--;
rtl8192_setBBreg(priv, rOFDM0_XCTxIQImbalance, bMaskDWord, priv->txbbgain_table[priv->rfc_txpowertrackingindex_real].txbbgain_value);
}
}
else
rtl8192_setBBreg(priv, rOFDM0_XCTxIQImbalance, bMaskDWord, priv->txbbgain_table[4].txbbgain_value);
}
}
else
{
if (RF_Type == RF_2T4R)
{
if((priv->rfa_txpowertrackingindex < TxBBGainTableLength - 1) &&(priv->rfc_txpowertrackingindex < TxBBGainTableLength - 1))
{
priv->rfa_txpowertrackingindex++;
priv->rfa_txpowertrackingindex_real++;
rtl8192_setBBreg(priv, rOFDM0_XATxIQImbalance, bMaskDWord, priv->txbbgain_table[priv->rfa_txpowertrackingindex_real].txbbgain_value);
priv->rfc_txpowertrackingindex++;
priv->rfc_txpowertrackingindex_real++;
rtl8192_setBBreg(priv, rOFDM0_XCTxIQImbalance, bMaskDWord, priv->txbbgain_table[priv->rfc_txpowertrackingindex_real].txbbgain_value);
}
else
{
rtl8192_setBBreg(priv, rOFDM0_XATxIQImbalance, bMaskDWord, priv->txbbgain_table[TxBBGainTableLength - 1].txbbgain_value);
rtl8192_setBBreg(priv, rOFDM0_XCTxIQImbalance, bMaskDWord, priv->txbbgain_table[TxBBGainTableLength - 1].txbbgain_value);
}
}
else
{
if(priv->rfc_txpowertrackingindex < (TxBBGainTableLength - 1))
{
priv->rfc_txpowertrackingindex++;
priv->rfc_txpowertrackingindex_real++;
rtl8192_setBBreg(priv, rOFDM0_XCTxIQImbalance, bMaskDWord, priv->txbbgain_table[priv->rfc_txpowertrackingindex_real].txbbgain_value);
}
else
rtl8192_setBBreg(priv, rOFDM0_XCTxIQImbalance, bMaskDWord, priv->txbbgain_table[TxBBGainTableLength - 1].txbbgain_value);
}
}
if (RF_Type == RF_2T4R)
priv->CCKPresentAttentuation_difference
= priv->rfa_txpowertrackingindex - priv->rfa_txpowertracking_default;
else
priv->CCKPresentAttentuation_difference
= priv->rfc_txpowertrackingindex - priv->rfc_txpowertracking_default;
if(priv->CurrentChannelBW == HT_CHANNEL_WIDTH_20)
priv->CCKPresentAttentuation
= priv->CCKPresentAttentuation_20Mdefault + priv->CCKPresentAttentuation_difference;
else
priv->CCKPresentAttentuation
= priv->CCKPresentAttentuation_40Mdefault + priv->CCKPresentAttentuation_difference;
if(priv->CCKPresentAttentuation > (CCKTxBBGainTableLength-1))
priv->CCKPresentAttentuation = CCKTxBBGainTableLength-1;
if(priv->CCKPresentAttentuation < 0)
priv->CCKPresentAttentuation = 0;
if(1)
{
if(priv->ieee80211->current_network.channel == 14 && !priv->bcck_in_ch14)
{
priv->bcck_in_ch14 = TRUE;
dm_cck_txpower_adjust(priv, priv->bcck_in_ch14);
}
else if(priv->ieee80211->current_network.channel != 14 && priv->bcck_in_ch14)
{
priv->bcck_in_ch14 = FALSE;
dm_cck_txpower_adjust(priv, priv->bcck_in_ch14);
}
else
dm_cck_txpower_adjust(priv, priv->bcck_in_ch14);
}
RT_TRACE(COMP_POWER_TRACKING, "priv->rfa_txpowertrackingindex = %d\n", priv->rfa_txpowertrackingindex);
RT_TRACE(COMP_POWER_TRACKING, "priv->rfa_txpowertrackingindex_real = %d\n", priv->rfa_txpowertrackingindex_real);
RT_TRACE(COMP_POWER_TRACKING, "priv->CCKPresentAttentuation_difference = %d\n", priv->CCKPresentAttentuation_difference);
RT_TRACE(COMP_POWER_TRACKING, "priv->CCKPresentAttentuation = %d\n", priv->CCKPresentAttentuation);
if (priv->CCKPresentAttentuation_difference <= -12||priv->CCKPresentAttentuation_difference >= 24)
{
priv->ieee80211->bdynamic_txpower_enable = TRUE;
write_nic_byte(priv, Pw_Track_Flag, 0);
write_nic_byte(priv, FW_Busy_Flag, 0);
RT_TRACE(COMP_POWER_TRACKING, "tx power track--->limited\n");
return;
}
}
write_nic_byte(priv, Pw_Track_Flag, 0);
Avg_TSSI_Meas_from_driver = 0;
for(k = 0;k < 5; k++)
tmp_report[k] = 0;
break;
}
write_nic_byte(priv, FW_Busy_Flag, 0);
}
priv->ieee80211->bdynamic_txpower_enable = TRUE;
write_nic_byte(priv, Pw_Track_Flag, 0);
}
static void dm_TXPowerTrackingCallback_ThermalMeter(struct r8192_priv *priv)
{
#define ThermalMeterVal 9
u32 tmpRegA, TempCCk;
u8 tmpOFDMindex, tmpCCKindex, tmpCCK20Mindex, tmpCCK40Mindex, tmpval;
int i =0, CCKSwingNeedUpdate=0;
if(!priv->btxpower_trackingInit)
{
tmpRegA = rtl8192_QueryBBReg(priv, rOFDM0_XATxIQImbalance, bMaskDWord);
for(i=0; i<OFDM_Table_Length; i++)
{
if(tmpRegA == OFDMSwingTable[i])
{
priv->OFDM_index= (u8)i;
RT_TRACE(COMP_POWER_TRACKING, "Initial reg0x%x = 0x%x, OFDM_index=0x%x\n",
rOFDM0_XATxIQImbalance, tmpRegA, priv->OFDM_index);
}
}
TempCCk = rtl8192_QueryBBReg(priv, rCCK0_TxFilter1, bMaskByte2);
for(i=0 ; i<CCK_Table_length ; i++)
{
if(TempCCk == (u32)CCKSwingTable_Ch1_Ch13[i][0])
{
priv->CCK_index =(u8) i;
RT_TRACE(COMP_POWER_TRACKING, "Initial reg0x%x = 0x%x, CCK_index=0x%x\n",
rCCK0_TxFilter1, TempCCk, priv->CCK_index);
break;
}
}
priv->btxpower_trackingInit = TRUE;
return;
}
tmpRegA = rtl8192_phy_QueryRFReg(priv, RF90_PATH_A, 0x12, 0x078);
RT_TRACE(COMP_POWER_TRACKING, "Readback ThermalMeterA = %d\n", tmpRegA);
if(tmpRegA < 3 || tmpRegA > 13)
return;
if(tmpRegA >= 12)
tmpRegA = 12;
RT_TRACE(COMP_POWER_TRACKING, "Valid ThermalMeterA = %d\n", tmpRegA);
priv->ThermalMeter[0] = ThermalMeterVal;
priv->ThermalMeter[1] = ThermalMeterVal;
if(priv->ThermalMeter[0] >= (u8)tmpRegA)
{
tmpOFDMindex = tmpCCK20Mindex = 6+(priv->ThermalMeter[0]-(u8)tmpRegA);
tmpCCK40Mindex = tmpCCK20Mindex - 6;
if(tmpOFDMindex >= OFDM_Table_Length)
tmpOFDMindex = OFDM_Table_Length-1;
if(tmpCCK20Mindex >= CCK_Table_length)
tmpCCK20Mindex = CCK_Table_length-1;
if(tmpCCK40Mindex >= CCK_Table_length)
tmpCCK40Mindex = CCK_Table_length-1;
}
else
{
tmpval = ((u8)tmpRegA - priv->ThermalMeter[0]);
if(tmpval >= 6)
tmpOFDMindex = tmpCCK20Mindex = 0;
else
tmpOFDMindex = tmpCCK20Mindex = 6 - tmpval;
tmpCCK40Mindex = 0;
}
if(priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
tmpCCKindex = tmpCCK40Mindex;
else
tmpCCKindex = tmpCCK20Mindex;
priv->Record_CCK_20Mindex = tmpCCK20Mindex;
priv->Record_CCK_40Mindex = tmpCCK40Mindex;
RT_TRACE(COMP_POWER_TRACKING, "Record_CCK_20Mindex / Record_CCK_40Mindex = %d / %d.\n",
priv->Record_CCK_20Mindex, priv->Record_CCK_40Mindex);
if(priv->ieee80211->current_network.channel == 14 && !priv->bcck_in_ch14)
{
priv->bcck_in_ch14 = TRUE;
CCKSwingNeedUpdate = 1;
}
else if(priv->ieee80211->current_network.channel != 14 && priv->bcck_in_ch14)
{
priv->bcck_in_ch14 = FALSE;
CCKSwingNeedUpdate = 1;
}
if(priv->CCK_index != tmpCCKindex)
{
priv->CCK_index = tmpCCKindex;
CCKSwingNeedUpdate = 1;
}
if(CCKSwingNeedUpdate)
{
dm_cck_txpower_adjust(priv, priv->bcck_in_ch14);
}
if(priv->OFDM_index != tmpOFDMindex)
{
priv->OFDM_index = tmpOFDMindex;
rtl8192_setBBreg(priv, rOFDM0_XATxIQImbalance, bMaskDWord, OFDMSwingTable[priv->OFDM_index]);
RT_TRACE(COMP_POWER_TRACKING, "Update OFDMSwing[%d] = 0x%x\n",
priv->OFDM_index, OFDMSwingTable[priv->OFDM_index]);
}
priv->txpower_count = 0;
}
void dm_txpower_trackingcallback(struct work_struct *work)
{
struct delayed_work *dwork = container_of(work,struct delayed_work,work);
struct r8192_priv *priv = container_of(dwork,struct r8192_priv,txpower_tracking_wq);
if(priv->IC_Cut >= IC_VersionCut_D)
dm_TXPowerTrackingCallback_TSSI(priv);
else
dm_TXPowerTrackingCallback_ThermalMeter(priv);
}
static void dm_InitializeTXPowerTracking_TSSI(struct r8192_priv *priv)
{
priv->txbbgain_table = rtl8192_txbbgain_table;
priv->cck_txbbgain_table = rtl8192_cck_txbbgain_table;
priv->cck_txbbgain_ch14_table = rtl8192_cck_txbbgain_ch14_table;
priv->btxpower_tracking = TRUE;
priv->txpower_count = 0;
priv->btxpower_trackingInit = FALSE;
}
static void dm_InitializeTXPowerTracking_ThermalMeter(struct r8192_priv *priv)
{
if(priv->ieee80211->FwRWRF)
priv->btxpower_tracking = TRUE;
else
priv->btxpower_tracking = FALSE;
priv->txpower_count = 0;
priv->btxpower_trackingInit = FALSE;
}
void dm_initialize_txpower_tracking(struct r8192_priv *priv)
{
if(priv->IC_Cut >= IC_VersionCut_D)
dm_InitializeTXPowerTracking_TSSI(priv);
else
dm_InitializeTXPowerTracking_ThermalMeter(priv);
}
static void dm_CheckTXPowerTracking_TSSI(struct r8192_priv *priv)
{
static u32 tx_power_track_counter = 0;
RT_TRACE(COMP_POWER_TRACKING,"%s()\n",__FUNCTION__);
if(read_nic_byte(priv, 0x11e) ==1)
return;
if(!priv->btxpower_tracking)
return;
tx_power_track_counter++;
if (tx_power_track_counter > 90) {
queue_delayed_work(priv->priv_wq,&priv->txpower_tracking_wq,0);
tx_power_track_counter =0;
}
}
static void dm_CheckTXPowerTracking_ThermalMeter(struct r8192_priv *priv)
{
static u8 TM_Trigger=0;
if(!priv->btxpower_tracking)
return;
else
{
if(priv->txpower_count <= 2)
{
priv->txpower_count++;
return;
}
}
if(!TM_Trigger)
{
rtl8192_phy_SetRFReg(priv, RF90_PATH_A, 0x02, bMask12Bits, 0x4d);
rtl8192_phy_SetRFReg(priv, RF90_PATH_A, 0x02, bMask12Bits, 0x4f);
rtl8192_phy_SetRFReg(priv, RF90_PATH_A, 0x02, bMask12Bits, 0x4d);
rtl8192_phy_SetRFReg(priv, RF90_PATH_A, 0x02, bMask12Bits, 0x4f);
TM_Trigger = 1;
return;
}
else {
queue_delayed_work(priv->priv_wq,&priv->txpower_tracking_wq,0);
TM_Trigger = 0;
}
}
static void dm_check_txpower_tracking(struct r8192_priv *priv)
{
if(priv->IC_Cut >= IC_VersionCut_D)
dm_CheckTXPowerTracking_TSSI(priv);
else
dm_CheckTXPowerTracking_ThermalMeter(priv);
}
static void dm_CCKTxPowerAdjust_TSSI(struct r8192_priv *priv, bool bInCH14)
{
u32 TempVal;
TempVal = 0;
if(!bInCH14){
TempVal = (u32)(priv->cck_txbbgain_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[0] +
(priv->cck_txbbgain_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[1]<<8)) ;
rtl8192_setBBreg(priv, rCCK0_TxFilter1, bMaskHWord, TempVal);
TempVal = 0;
TempVal = (u32)(priv->cck_txbbgain_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[2] +
(priv->cck_txbbgain_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[3]<<8) +
(priv->cck_txbbgain_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[4]<<16 )+
(priv->cck_txbbgain_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[5]<<24));
rtl8192_setBBreg(priv, rCCK0_TxFilter2, bMaskDWord, TempVal);
TempVal = 0;
TempVal = (u32)(priv->cck_txbbgain_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[6] +
(priv->cck_txbbgain_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[7]<<8)) ;
rtl8192_setBBreg(priv, rCCK0_DebugPort, bMaskLWord, TempVal);
}
else
{
TempVal = (u32)(priv->cck_txbbgain_ch14_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[0] +
(priv->cck_txbbgain_ch14_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[1]<<8)) ;
rtl8192_setBBreg(priv, rCCK0_TxFilter1, bMaskHWord, TempVal);
TempVal = 0;
TempVal = (u32)(priv->cck_txbbgain_ch14_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[2] +
(priv->cck_txbbgain_ch14_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[3]<<8) +
(priv->cck_txbbgain_ch14_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[4]<<16 )+
(priv->cck_txbbgain_ch14_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[5]<<24));
rtl8192_setBBreg(priv, rCCK0_TxFilter2, bMaskDWord, TempVal);
TempVal = 0;
TempVal = (u32)(priv->cck_txbbgain_ch14_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[6] +
(priv->cck_txbbgain_ch14_table[(u8)(priv->CCKPresentAttentuation)].ccktxbb_valuearray[7]<<8)) ;
rtl8192_setBBreg(priv, rCCK0_DebugPort, bMaskLWord, TempVal);
}
}
static void dm_CCKTxPowerAdjust_ThermalMeter(struct r8192_priv *priv,
bool bInCH14)
{
u32 TempVal;
TempVal = 0;
if(!bInCH14)
{
TempVal = CCKSwingTable_Ch1_Ch13[priv->CCK_index][0] +
(CCKSwingTable_Ch1_Ch13[priv->CCK_index][1]<<8) ;
rtl8192_setBBreg(priv, rCCK0_TxFilter1, bMaskHWord, TempVal);
RT_TRACE(COMP_POWER_TRACKING, "CCK not chnl 14, reg 0x%x = 0x%x\n",
rCCK0_TxFilter1, TempVal);
TempVal = 0;
TempVal = CCKSwingTable_Ch1_Ch13[priv->CCK_index][2] +
(CCKSwingTable_Ch1_Ch13[priv->CCK_index][3]<<8) +
(CCKSwingTable_Ch1_Ch13[priv->CCK_index][4]<<16 )+
(CCKSwingTable_Ch1_Ch13[priv->CCK_index][5]<<24);
rtl8192_setBBreg(priv, rCCK0_TxFilter2, bMaskDWord, TempVal);
RT_TRACE(COMP_POWER_TRACKING, "CCK not chnl 14, reg 0x%x = 0x%x\n",
rCCK0_TxFilter2, TempVal);
TempVal = 0;
TempVal = CCKSwingTable_Ch1_Ch13[priv->CCK_index][6] +
(CCKSwingTable_Ch1_Ch13[priv->CCK_index][7]<<8) ;
rtl8192_setBBreg(priv, rCCK0_DebugPort, bMaskLWord, TempVal);
RT_TRACE(COMP_POWER_TRACKING, "CCK not chnl 14, reg 0x%x = 0x%x\n",
rCCK0_DebugPort, TempVal);
}
else
{
TempVal = CCKSwingTable_Ch14[priv->CCK_index][0] +
(CCKSwingTable_Ch14[priv->CCK_index][1]<<8) ;
rtl8192_setBBreg(priv, rCCK0_TxFilter1, bMaskHWord, TempVal);
RT_TRACE(COMP_POWER_TRACKING, "CCK chnl 14, reg 0x%x = 0x%x\n",
rCCK0_TxFilter1, TempVal);
TempVal = 0;
TempVal = CCKSwingTable_Ch14[priv->CCK_index][2] +
(CCKSwingTable_Ch14[priv->CCK_index][3]<<8) +
(CCKSwingTable_Ch14[priv->CCK_index][4]<<16 )+
(CCKSwingTable_Ch14[priv->CCK_index][5]<<24);
rtl8192_setBBreg(priv, rCCK0_TxFilter2, bMaskDWord, TempVal);
RT_TRACE(COMP_POWER_TRACKING, "CCK chnl 14, reg 0x%x = 0x%x\n",
rCCK0_TxFilter2, TempVal);
TempVal = 0;
TempVal = CCKSwingTable_Ch14[priv->CCK_index][6] +
(CCKSwingTable_Ch14[priv->CCK_index][7]<<8) ;
rtl8192_setBBreg(priv, rCCK0_DebugPort, bMaskLWord, TempVal);
RT_TRACE(COMP_POWER_TRACKING,"CCK chnl 14, reg 0x%x = 0x%x\n",
rCCK0_DebugPort, TempVal);
}
}
void dm_cck_txpower_adjust(struct r8192_priv *priv, bool binch14)
{
if(priv->IC_Cut >= IC_VersionCut_D)
dm_CCKTxPowerAdjust_TSSI(priv, binch14);
else
dm_CCKTxPowerAdjust_ThermalMeter(priv, binch14);
}
static void dm_dig_init(struct r8192_priv *priv)
{
dm_digtable.dig_enable_flag = true;
dm_digtable.dig_algorithm = DIG_ALGO_BY_RSSI;
dm_digtable.dbg_mode = DM_DBG_OFF;
dm_digtable.dig_algorithm_switch = 0;
dm_digtable.dig_state = DM_STA_DIG_MAX;
dm_digtable.dig_highpwr_state = DM_STA_DIG_MAX;
dm_digtable.initialgain_lowerbound_state = false;
dm_digtable.rssi_low_thresh = DM_DIG_THRESH_LOW;
dm_digtable.rssi_high_thresh = DM_DIG_THRESH_HIGH;
dm_digtable.rssi_high_power_lowthresh = DM_DIG_HIGH_PWR_THRESH_LOW;
dm_digtable.rssi_high_power_highthresh = DM_DIG_HIGH_PWR_THRESH_HIGH;
dm_digtable.rssi_val = 50;
dm_digtable.backoff_val = DM_DIG_BACKOFF;
dm_digtable.rx_gain_range_max = DM_DIG_MAX;
if(priv->CustomerID == RT_CID_819x_Netcore)
dm_digtable.rx_gain_range_min = DM_DIG_MIN_Netcore;
else
dm_digtable.rx_gain_range_min = DM_DIG_MIN;
}
static void dm_ctrl_initgain_byrssi(struct r8192_priv *priv)
{
if (dm_digtable.dig_enable_flag == false)
return;
if(dm_digtable.dig_algorithm == DIG_ALGO_BY_FALSE_ALARM)
dm_ctrl_initgain_byrssi_by_fwfalse_alarm(priv);
else if(dm_digtable.dig_algorithm == DIG_ALGO_BY_RSSI)
dm_ctrl_initgain_byrssi_by_driverrssi(priv);
}
static void dm_ctrl_initgain_byrssi_by_driverrssi(struct r8192_priv *priv)
{
u8 i;
static u8 fw_dig=0;
if (dm_digtable.dig_enable_flag == false)
return;
if(dm_digtable.dig_algorithm_switch)
fw_dig = 0;
if(fw_dig <= 3)
{
for(i=0; i<3; i++)
rtl8192_setBBreg(priv, UFWP, bMaskByte1, 0x8);
fw_dig++;
dm_digtable.dig_state = DM_STA_DIG_OFF;
}
if(priv->ieee80211->state == IEEE80211_LINKED)
dm_digtable.cur_connect_state = DIG_CONNECT;
else
dm_digtable.cur_connect_state = DIG_DISCONNECT;
if(dm_digtable.dbg_mode == DM_DBG_OFF)
dm_digtable.rssi_val = priv->undecorated_smoothed_pwdb;
dm_initial_gain(priv);
dm_pd_th(priv);
dm_cs_ratio(priv);
if(dm_digtable.dig_algorithm_switch)
dm_digtable.dig_algorithm_switch = 0;
dm_digtable.pre_connect_state = dm_digtable.cur_connect_state;
}
static void dm_ctrl_initgain_byrssi_by_fwfalse_alarm(struct r8192_priv *priv)
{
static u32 reset_cnt = 0;
u8 i;
if (dm_digtable.dig_enable_flag == false)
return;
if(dm_digtable.dig_algorithm_switch)
{
dm_digtable.dig_state = DM_STA_DIG_MAX;
for(i=0; i<3; i++)
rtl8192_setBBreg(priv, UFWP, bMaskByte1, 0x1);
dm_digtable.dig_algorithm_switch = 0;
}
if (priv->ieee80211->state != IEEE80211_LINKED)
return;
if ((priv->undecorated_smoothed_pwdb > dm_digtable.rssi_low_thresh) &&
(priv->undecorated_smoothed_pwdb < dm_digtable.rssi_high_thresh))
{
return;
}
if ((priv->undecorated_smoothed_pwdb <= dm_digtable.rssi_low_thresh))
{
if (dm_digtable.dig_state == DM_STA_DIG_OFF &&
(priv->reset_count == reset_cnt))
{
return;
}
else
{
reset_cnt = priv->reset_count;
}
dm_digtable.dig_highpwr_state = DM_STA_DIG_MAX;
dm_digtable.dig_state = DM_STA_DIG_OFF;
rtl8192_setBBreg(priv, UFWP, bMaskByte1, 0x8);
write_nic_byte(priv, rOFDM0_XAAGCCore1, 0x17);
write_nic_byte(priv, rOFDM0_XBAGCCore1, 0x17);
write_nic_byte(priv, rOFDM0_XCAGCCore1, 0x17);
write_nic_byte(priv, rOFDM0_XDAGCCore1, 0x17);
if (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
{
write_nic_byte(priv, (rOFDM0_XATxAFE+3), 0x00);
}
else
write_nic_byte(priv, rOFDM0_RxDetector1, 0x42);
write_nic_byte(priv, 0xa0a, 0x08);
return;
}
if ((priv->undecorated_smoothed_pwdb >= dm_digtable.rssi_high_thresh) )
{
u8 reset_flag = 0;
if (dm_digtable.dig_state == DM_STA_DIG_ON &&
(priv->reset_count == reset_cnt))
{
dm_ctrl_initgain_byrssi_highpwr(priv);
return;
}
else
{
if (priv->reset_count != reset_cnt)
reset_flag = 1;
reset_cnt = priv->reset_count;
}
dm_digtable.dig_state = DM_STA_DIG_ON;
if (reset_flag == 1)
{
write_nic_byte(priv, rOFDM0_XAAGCCore1, 0x2c);
write_nic_byte(priv, rOFDM0_XBAGCCore1, 0x2c);
write_nic_byte(priv, rOFDM0_XCAGCCore1, 0x2c);
write_nic_byte(priv, rOFDM0_XDAGCCore1, 0x2c);
}
else
{
write_nic_byte(priv, rOFDM0_XAAGCCore1, 0x20);
write_nic_byte(priv, rOFDM0_XBAGCCore1, 0x20);
write_nic_byte(priv, rOFDM0_XCAGCCore1, 0x20);
write_nic_byte(priv, rOFDM0_XDAGCCore1, 0x20);
}
if (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
{
write_nic_byte(priv, (rOFDM0_XATxAFE+3), 0x20);
}
else
write_nic_byte(priv, rOFDM0_RxDetector1, 0x44);
write_nic_byte(priv, 0xa0a, 0xcd);
rtl8192_setBBreg(priv, UFWP, bMaskByte1, 0x1);
}
dm_ctrl_initgain_byrssi_highpwr(priv);
}
static void dm_ctrl_initgain_byrssi_highpwr(struct r8192_priv *priv)
{
static u32 reset_cnt_highpwr = 0;
if ((priv->undecorated_smoothed_pwdb > dm_digtable.rssi_high_power_lowthresh) &&
(priv->undecorated_smoothed_pwdb < dm_digtable.rssi_high_power_highthresh))
{
return;
}
if (priv->undecorated_smoothed_pwdb >= dm_digtable.rssi_high_power_highthresh)
{
if (dm_digtable.dig_highpwr_state == DM_STA_DIG_ON &&
(priv->reset_count == reset_cnt_highpwr))
return;
else
dm_digtable.dig_highpwr_state = DM_STA_DIG_ON;
if (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
{
write_nic_byte(priv, (rOFDM0_XATxAFE+3), 0x10);
}
else
write_nic_byte(priv, rOFDM0_RxDetector1, 0x43);
}
else
{
if (dm_digtable.dig_highpwr_state == DM_STA_DIG_OFF&&
(priv->reset_count == reset_cnt_highpwr))
return;
else
dm_digtable.dig_highpwr_state = DM_STA_DIG_OFF;
if (priv->undecorated_smoothed_pwdb < dm_digtable.rssi_high_power_lowthresh &&
priv->undecorated_smoothed_pwdb >= dm_digtable.rssi_high_thresh)
{
if (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
{
write_nic_byte(priv, (rOFDM0_XATxAFE+3), 0x20);
}
else
write_nic_byte(priv, rOFDM0_RxDetector1, 0x44);
}
}
reset_cnt_highpwr = priv->reset_count;
}
static void dm_initial_gain(struct r8192_priv *priv)
{
u8 initial_gain=0;
static u8 initialized=0, force_write=0;
static u32 reset_cnt=0;
if(dm_digtable.dig_algorithm_switch)
{
initialized = 0;
reset_cnt = 0;
}
if(dm_digtable.pre_connect_state == dm_digtable.cur_connect_state)
{
if(dm_digtable.cur_connect_state == DIG_CONNECT)
{
if((dm_digtable.rssi_val+10-dm_digtable.backoff_val) > dm_digtable.rx_gain_range_max)
dm_digtable.cur_ig_value = dm_digtable.rx_gain_range_max;
else if((dm_digtable.rssi_val+10-dm_digtable.backoff_val) < dm_digtable.rx_gain_range_min)
dm_digtable.cur_ig_value = dm_digtable.rx_gain_range_min;
else
dm_digtable.cur_ig_value = dm_digtable.rssi_val+10-dm_digtable.backoff_val;
}
else
{
if(dm_digtable.cur_ig_value == 0)
dm_digtable.cur_ig_value = priv->DefaultInitialGain[0];
else
dm_digtable.cur_ig_value = dm_digtable.pre_ig_value;
}
}
else
{
dm_digtable.cur_ig_value = priv->DefaultInitialGain[0];
dm_digtable.pre_ig_value = 0;
}
if(priv->reset_count != reset_cnt)
{
force_write = 1;
reset_cnt = priv->reset_count;
}
if(dm_digtable.pre_ig_value != read_nic_byte(priv, rOFDM0_XAAGCCore1))
force_write = 1;
{
if((dm_digtable.pre_ig_value != dm_digtable.cur_ig_value)
|| !initialized || force_write)
{
initial_gain = (u8)dm_digtable.cur_ig_value;
write_nic_byte(priv, rOFDM0_XAAGCCore1, initial_gain);
write_nic_byte(priv, rOFDM0_XBAGCCore1, initial_gain);
write_nic_byte(priv, rOFDM0_XCAGCCore1, initial_gain);
write_nic_byte(priv, rOFDM0_XDAGCCore1, initial_gain);
dm_digtable.pre_ig_value = dm_digtable.cur_ig_value;
initialized = 1;
force_write = 0;
}
}
}
static void dm_pd_th(struct r8192_priv *priv)
{
static u8 initialized=0, force_write=0;
static u32 reset_cnt = 0;
if(dm_digtable.dig_algorithm_switch)
{
initialized = 0;
reset_cnt = 0;
}
if(dm_digtable.pre_connect_state == dm_digtable.cur_connect_state)
{
if(dm_digtable.cur_connect_state == DIG_CONNECT)
{
if (dm_digtable.rssi_val >= dm_digtable.rssi_high_power_highthresh)
dm_digtable.curpd_thstate = DIG_PD_AT_HIGH_POWER;
else if ((dm_digtable.rssi_val <= dm_digtable.rssi_low_thresh))
dm_digtable.curpd_thstate = DIG_PD_AT_LOW_POWER;
else if ((dm_digtable.rssi_val >= dm_digtable.rssi_high_thresh) &&
(dm_digtable.rssi_val < dm_digtable.rssi_high_power_lowthresh))
dm_digtable.curpd_thstate = DIG_PD_AT_NORMAL_POWER;
else
dm_digtable.curpd_thstate = dm_digtable.prepd_thstate;
}
else
{
dm_digtable.curpd_thstate = DIG_PD_AT_LOW_POWER;
}
}
else
{
dm_digtable.curpd_thstate = DIG_PD_AT_LOW_POWER;
}
if(priv->reset_count != reset_cnt)
{
force_write = 1;
reset_cnt = priv->reset_count;
}
{
if((dm_digtable.prepd_thstate != dm_digtable.curpd_thstate) ||
(initialized<=3) || force_write)
{
if(dm_digtable.curpd_thstate == DIG_PD_AT_LOW_POWER)
{
if (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
{
write_nic_byte(priv, (rOFDM0_XATxAFE+3), 0x00);
}
else
write_nic_byte(priv, rOFDM0_RxDetector1, 0x42);
}
else if(dm_digtable.curpd_thstate == DIG_PD_AT_NORMAL_POWER)
{
if (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
{
write_nic_byte(priv, (rOFDM0_XATxAFE+3), 0x20);
}
else
write_nic_byte(priv, rOFDM0_RxDetector1, 0x44);
}
else if(dm_digtable.curpd_thstate == DIG_PD_AT_HIGH_POWER)
{
if (priv->CurrentChannelBW != HT_CHANNEL_WIDTH_20)
{
write_nic_byte(priv, (rOFDM0_XATxAFE+3), 0x10);
}
else
write_nic_byte(priv, rOFDM0_RxDetector1, 0x43);
}
dm_digtable.prepd_thstate = dm_digtable.curpd_thstate;
if(initialized <= 3)
initialized++;
force_write = 0;
}
}
}
static void dm_cs_ratio(struct r8192_priv *priv)
{
static u8 initialized=0,force_write=0;
static u32 reset_cnt = 0;
if(dm_digtable.dig_algorithm_switch)
{
initialized = 0;
reset_cnt = 0;
}
if(dm_digtable.pre_connect_state == dm_digtable.cur_connect_state)
{
if(dm_digtable.cur_connect_state == DIG_CONNECT)
{
if ((dm_digtable.rssi_val <= dm_digtable.rssi_low_thresh))
dm_digtable.curcs_ratio_state = DIG_CS_RATIO_LOWER;
else if ((dm_digtable.rssi_val >= dm_digtable.rssi_high_thresh) )
dm_digtable.curcs_ratio_state = DIG_CS_RATIO_HIGHER;
else
dm_digtable.curcs_ratio_state = dm_digtable.precs_ratio_state;
}
else
{
dm_digtable.curcs_ratio_state = DIG_CS_RATIO_LOWER;
}
}
else
{
dm_digtable.curcs_ratio_state = DIG_CS_RATIO_LOWER;
}
if(priv->reset_count != reset_cnt)
{
force_write = 1;
reset_cnt = priv->reset_count;
}
if((dm_digtable.precs_ratio_state != dm_digtable.curcs_ratio_state) ||
!initialized || force_write)
{
if(dm_digtable.curcs_ratio_state == DIG_CS_RATIO_LOWER)
{
write_nic_byte(priv, 0xa0a, 0x08);
}
else if(dm_digtable.curcs_ratio_state == DIG_CS_RATIO_HIGHER)
{
write_nic_byte(priv, 0xa0a, 0xcd);
}
dm_digtable.precs_ratio_state = dm_digtable.curcs_ratio_state;
initialized = 1;
force_write = 0;
}
}
void dm_init_edca_turbo(struct r8192_priv *priv)
{
priv->bcurrent_turbo_EDCA = false;
priv->ieee80211->bis_any_nonbepkts = false;
priv->bis_cur_rdlstate = false;
}
static void dm_check_edca_turbo(struct r8192_priv *priv)
{
PRT_HIGH_THROUGHPUT pHTInfo = priv->ieee80211->pHTInfo;
static unsigned long lastTxOkCnt = 0;
static unsigned long lastRxOkCnt = 0;
unsigned long curTxOkCnt = 0;
unsigned long curRxOkCnt = 0;
if(priv->ieee80211->state != IEEE80211_LINKED)
goto dm_CheckEdcaTurbo_EXIT;
if(priv->ieee80211->pHTInfo->IOTAction & HT_IOT_ACT_DISABLE_EDCA_TURBO)
goto dm_CheckEdcaTurbo_EXIT;
if(!priv->ieee80211->bis_any_nonbepkts)
{
curTxOkCnt = priv->stats.txbytesunicast - lastTxOkCnt;
curRxOkCnt = priv->stats.rxbytesunicast - lastRxOkCnt;
if(curRxOkCnt > 4*curTxOkCnt)
{
if(!priv->bis_cur_rdlstate || !priv->bcurrent_turbo_EDCA)
{
write_nic_dword(priv, EDCAPARA_BE, edca_setting_DL[pHTInfo->IOTPeer]);
priv->bis_cur_rdlstate = true;
}
}
else
{
if(priv->bis_cur_rdlstate || !priv->bcurrent_turbo_EDCA)
{
write_nic_dword(priv, EDCAPARA_BE, edca_setting_UL[pHTInfo->IOTPeer]);
priv->bis_cur_rdlstate = false;
}
}
priv->bcurrent_turbo_EDCA = true;
}
else
{
if(priv->bcurrent_turbo_EDCA)
{
{
u8 u1bAIFS;
u32 u4bAcParam;
struct ieee80211_qos_parameters *qos_parameters = &priv->ieee80211->current_network.qos_data.parameters;
u8 mode = priv->ieee80211->mode;
dm_init_edca_turbo(priv);
u1bAIFS = qos_parameters->aifs[0] * ((mode&(IEEE_G|IEEE_N_24G)) ?9:20) + aSifsTime;
u4bAcParam = ((((u32)(qos_parameters->tx_op_limit[0]))<< AC_PARAM_TXOP_LIMIT_OFFSET)|
(((u32)(qos_parameters->cw_max[0]))<< AC_PARAM_ECW_MAX_OFFSET)|
(((u32)(qos_parameters->cw_min[0]))<< AC_PARAM_ECW_MIN_OFFSET)|
((u32)u1bAIFS << AC_PARAM_AIFS_OFFSET));
printk("===>u4bAcParam:%x, ", u4bAcParam);
write_nic_dword(priv, EDCAPARA_BE, u4bAcParam);
{
PACI_AIFSN pAciAifsn = (PACI_AIFSN)&(qos_parameters->aifs[0]);
u8 AcmCtrl = read_nic_byte(priv, AcmHwCtrl );
if( pAciAifsn->f.ACM )
{
AcmCtrl |= AcmHw_BeqEn;
}
else
{
AcmCtrl &= (~AcmHw_BeqEn);
}
RT_TRACE( COMP_QOS,"SetHwReg8190pci(): [HW_VAR_ACM_CTRL] Write 0x%X\n", AcmCtrl ) ;
write_nic_byte(priv, AcmHwCtrl, AcmCtrl );
}
}
priv->bcurrent_turbo_EDCA = false;
}
}
dm_CheckEdcaTurbo_EXIT:
priv->ieee80211->bis_any_nonbepkts = false;
lastTxOkCnt = priv->stats.txbytesunicast;
lastRxOkCnt = priv->stats.rxbytesunicast;
}
static void dm_init_ctstoself(struct r8192_priv *priv)
{
priv->ieee80211->bCTSToSelfEnable = TRUE;
priv->ieee80211->CTSToSelfTH = CTSToSelfTHVal;
}
static void dm_ctstoself(struct r8192_priv *priv)
{
PRT_HIGH_THROUGHPUT pHTInfo = priv->ieee80211->pHTInfo;
static unsigned long lastTxOkCnt = 0;
static unsigned long lastRxOkCnt = 0;
unsigned long curTxOkCnt = 0;
unsigned long curRxOkCnt = 0;
if(priv->ieee80211->bCTSToSelfEnable != TRUE)
{
pHTInfo->IOTAction &= ~HT_IOT_ACT_FORCED_CTS2SELF;
return;
}
if(pHTInfo->IOTPeer == HT_IOT_PEER_BROADCOM)
{
curTxOkCnt = priv->stats.txbytesunicast - lastTxOkCnt;
curRxOkCnt = priv->stats.rxbytesunicast - lastRxOkCnt;
if(curRxOkCnt > 4*curTxOkCnt)
{
pHTInfo->IOTAction &= ~HT_IOT_ACT_FORCED_CTS2SELF;
}
else
{
pHTInfo->IOTAction |= HT_IOT_ACT_FORCED_CTS2SELF;
}
lastTxOkCnt = priv->stats.txbytesunicast;
lastRxOkCnt = priv->stats.rxbytesunicast;
}
}
static void dm_check_rfctrl_gpio(struct r8192_priv *priv)
{
queue_delayed_work(priv->priv_wq,&priv->gpio_change_rf_wq,0);
}
void dm_gpio_change_rf_callback(struct work_struct *work)
{
struct delayed_work *dwork = container_of(work,struct delayed_work,work);
struct r8192_priv *priv = container_of(dwork,struct r8192_priv,gpio_change_rf_wq);
u8 tmp1byte;
RT_RF_POWER_STATE eRfPowerStateToSet;
bool bActuallySet = false;
if (!priv->up) {
RT_TRACE((COMP_INIT | COMP_POWER | COMP_RF),"dm_gpio_change_rf_callback(): Callback function breaks out!!\n");
} else {
tmp1byte = read_nic_byte(priv, GPI);
eRfPowerStateToSet = (tmp1byte&BIT1) ? eRfOn : eRfOff;
if (priv->bHwRadioOff && (eRfPowerStateToSet == eRfOn)) {
RT_TRACE(COMP_RF, "gpiochangeRF - HW Radio ON\n");
priv->bHwRadioOff = false;
bActuallySet = true;
} else if ((!priv->bHwRadioOff) && (eRfPowerStateToSet == eRfOff)) {
RT_TRACE(COMP_RF, "gpiochangeRF - HW Radio OFF\n");
priv->bHwRadioOff = true;
bActuallySet = true;
}
if (bActuallySet) {
priv->bHwRfOffAction = 1;
MgntActSet_RF_State(priv, eRfPowerStateToSet, RF_CHANGE_BY_HW);
} else {
msleep(2000);
}
}
}
void dm_rf_pathcheck_workitemcallback(struct work_struct *work)
{
struct delayed_work *dwork = container_of(work,struct delayed_work,work);
struct r8192_priv *priv = container_of(dwork,struct r8192_priv,rfpath_check_wq);
u8 rfpath = 0, i;
rfpath = read_nic_byte(priv, 0xc04);
for (i = 0; i < RF90_PATH_MAX; i++)
{
if (rfpath & (0x01<<i))
priv->brfpath_rxenable[i] = 1;
else
priv->brfpath_rxenable[i] = 0;
}
if(!DM_RxPathSelTable.Enable)
return;
dm_rxpath_sel_byrssi(priv);
}
static void dm_init_rxpath_selection(struct r8192_priv *priv)
{
u8 i;
DM_RxPathSelTable.Enable = 1;
DM_RxPathSelTable.SS_TH_low = RxPathSelection_SS_TH_low;
DM_RxPathSelTable.diff_TH = RxPathSelection_diff_TH;
if(priv->CustomerID == RT_CID_819x_Netcore)
DM_RxPathSelTable.cck_method = CCK_Rx_Version_2;
else
DM_RxPathSelTable.cck_method = CCK_Rx_Version_1;
DM_RxPathSelTable.DbgMode = DM_DBG_OFF;
DM_RxPathSelTable.disabledRF = 0;
for(i=0; i<4; i++)
{
DM_RxPathSelTable.rf_rssi[i] = 50;
DM_RxPathSelTable.cck_pwdb_sta[i] = -64;
DM_RxPathSelTable.rf_enable_rssi_th[i] = 100;
}
}
static void dm_rxpath_sel_byrssi(struct r8192_priv *priv)
{
u8 i, max_rssi_index=0, min_rssi_index=0, sec_rssi_index=0, rf_num=0;
u8 tmp_max_rssi=0, tmp_min_rssi=0, tmp_sec_rssi=0;
u8 cck_default_Rx=0x2;
u8 cck_optional_Rx=0x3;
long tmp_cck_max_pwdb=0, tmp_cck_min_pwdb=0, tmp_cck_sec_pwdb=0;
u8 cck_rx_ver2_max_index=0, cck_rx_ver2_min_index=0, cck_rx_ver2_sec_index=0;
u8 cur_rf_rssi;
long cur_cck_pwdb;
static u8 disabled_rf_cnt=0, cck_Rx_Path_initialized=0;
u8 update_cck_rx_path;
if(priv->rf_type != RF_2T4R)
return;
if(!cck_Rx_Path_initialized)
{
DM_RxPathSelTable.cck_Rx_path = (read_nic_byte(priv, 0xa07)&0xf);
cck_Rx_Path_initialized = 1;
}
DM_RxPathSelTable.disabledRF = 0xf;
DM_RxPathSelTable.disabledRF &=~ (read_nic_byte(priv, 0xc04));
if(priv->ieee80211->mode == WIRELESS_MODE_B)
{
DM_RxPathSelTable.cck_method = CCK_Rx_Version_2;
}
for (i=0; i<RF90_PATH_MAX; i++)
{
if(!DM_RxPathSelTable.DbgMode)
DM_RxPathSelTable.rf_rssi[i] = priv->stats.rx_rssi_percentage[i];
if(priv->brfpath_rxenable[i])
{
rf_num++;
cur_rf_rssi = DM_RxPathSelTable.rf_rssi[i];
if(rf_num == 1)
{
max_rssi_index = min_rssi_index = sec_rssi_index = i;
tmp_max_rssi = tmp_min_rssi = tmp_sec_rssi = cur_rf_rssi;
}
else if(rf_num == 2)
{
if(cur_rf_rssi >= tmp_max_rssi)
{
tmp_max_rssi = cur_rf_rssi;
max_rssi_index = i;
}
else
{
tmp_sec_rssi = tmp_min_rssi = cur_rf_rssi;
sec_rssi_index = min_rssi_index = i;
}
}
else
{
if(cur_rf_rssi > tmp_max_rssi)
{
tmp_sec_rssi = tmp_max_rssi;
sec_rssi_index = max_rssi_index;
tmp_max_rssi = cur_rf_rssi;
max_rssi_index = i;
}
else if(cur_rf_rssi == tmp_max_rssi)
{
tmp_sec_rssi = cur_rf_rssi;
sec_rssi_index = i;
}
else if((cur_rf_rssi < tmp_max_rssi) &&(cur_rf_rssi > tmp_sec_rssi))
{
tmp_sec_rssi = cur_rf_rssi;
sec_rssi_index = i;
}
else if(cur_rf_rssi == tmp_sec_rssi)
{
if(tmp_sec_rssi == tmp_min_rssi)
{
tmp_sec_rssi = cur_rf_rssi;
sec_rssi_index = i;
}
else
{
}
}
else if((cur_rf_rssi < tmp_sec_rssi) && (cur_rf_rssi > tmp_min_rssi))
{
}
else if(cur_rf_rssi == tmp_min_rssi)
{
if(tmp_sec_rssi == tmp_min_rssi)
{
tmp_min_rssi = cur_rf_rssi;
min_rssi_index = i;
}
else
{
}
}
else if(cur_rf_rssi < tmp_min_rssi)
{
tmp_min_rssi = cur_rf_rssi;
min_rssi_index = i;
}
}
}
}
rf_num = 0;
if(DM_RxPathSelTable.cck_method == CCK_Rx_Version_2)
{
for (i=0; i<RF90_PATH_MAX; i++)
{
if(priv->brfpath_rxenable[i])
{
rf_num++;
cur_cck_pwdb = DM_RxPathSelTable.cck_pwdb_sta[i];
if(rf_num == 1)
{
cck_rx_ver2_max_index = cck_rx_ver2_min_index = cck_rx_ver2_sec_index = i;
tmp_cck_max_pwdb = tmp_cck_min_pwdb = tmp_cck_sec_pwdb = cur_cck_pwdb;
}
else if(rf_num == 2)
{
if(cur_cck_pwdb >= tmp_cck_max_pwdb)
{
tmp_cck_max_pwdb = cur_cck_pwdb;
cck_rx_ver2_max_index = i;
}
else
{
tmp_cck_sec_pwdb = tmp_cck_min_pwdb = cur_cck_pwdb;
cck_rx_ver2_sec_index = cck_rx_ver2_min_index = i;
}
}
else
{
if(cur_cck_pwdb > tmp_cck_max_pwdb)
{
tmp_cck_sec_pwdb = tmp_cck_max_pwdb;
cck_rx_ver2_sec_index = cck_rx_ver2_max_index;
tmp_cck_max_pwdb = cur_cck_pwdb;
cck_rx_ver2_max_index = i;
}
else if(cur_cck_pwdb == tmp_cck_max_pwdb)
{
tmp_cck_sec_pwdb = cur_cck_pwdb;
cck_rx_ver2_sec_index = i;
}
else if((cur_cck_pwdb < tmp_cck_max_pwdb) &&(cur_cck_pwdb > tmp_cck_sec_pwdb))
{
tmp_cck_sec_pwdb = cur_cck_pwdb;
cck_rx_ver2_sec_index = i;
}
else if(cur_cck_pwdb == tmp_cck_sec_pwdb)
{
if(tmp_cck_sec_pwdb == tmp_cck_min_pwdb)
{
tmp_cck_sec_pwdb = cur_cck_pwdb;
cck_rx_ver2_sec_index = i;
}
else
{
}
}
else if((cur_cck_pwdb < tmp_cck_sec_pwdb) && (cur_cck_pwdb > tmp_cck_min_pwdb))
{
}
else if(cur_cck_pwdb == tmp_cck_min_pwdb)
{
if(tmp_cck_sec_pwdb == tmp_cck_min_pwdb)
{
tmp_cck_min_pwdb = cur_cck_pwdb;
cck_rx_ver2_min_index = i;
}
else
{
}
}
else if(cur_cck_pwdb < tmp_cck_min_pwdb)
{
tmp_cck_min_pwdb = cur_cck_pwdb;
cck_rx_ver2_min_index = i;
}
}
}
}
}
update_cck_rx_path = 0;
if(DM_RxPathSelTable.cck_method == CCK_Rx_Version_2)
{
cck_default_Rx = cck_rx_ver2_max_index;
cck_optional_Rx = cck_rx_ver2_sec_index;
if(tmp_cck_max_pwdb != -64)
update_cck_rx_path = 1;
}
if(tmp_min_rssi < DM_RxPathSelTable.SS_TH_low && disabled_rf_cnt < 2)
{
if((tmp_max_rssi - tmp_min_rssi) >= DM_RxPathSelTable.diff_TH)
{
DM_RxPathSelTable.rf_enable_rssi_th[min_rssi_index] = tmp_max_rssi+5;
rtl8192_setBBreg(priv, rOFDM0_TRxPathEnable, 0x1<<min_rssi_index, 0x0);
rtl8192_setBBreg(priv, rOFDM1_TRxPathEnable, 0x1<<min_rssi_index, 0x0);
disabled_rf_cnt++;
}
if(DM_RxPathSelTable.cck_method == CCK_Rx_Version_1)
{
cck_default_Rx = max_rssi_index;
cck_optional_Rx = sec_rssi_index;
if(tmp_max_rssi)
update_cck_rx_path = 1;
}
}
if(update_cck_rx_path)
{
DM_RxPathSelTable.cck_Rx_path = (cck_default_Rx<<2)|(cck_optional_Rx);
rtl8192_setBBreg(priv, rCCK0_AFESetting, 0x0f000000, DM_RxPathSelTable.cck_Rx_path);
}
if(DM_RxPathSelTable.disabledRF)
{
for(i=0; i<4; i++)
{
if((DM_RxPathSelTable.disabledRF>>i) & 0x1)
{
if(tmp_max_rssi >= DM_RxPathSelTable.rf_enable_rssi_th[i])
{
rtl8192_setBBreg(priv, rOFDM0_TRxPathEnable, 0x1<<i, 0x1);
rtl8192_setBBreg(priv, rOFDM1_TRxPathEnable, 0x1<<i, 0x1);
DM_RxPathSelTable.rf_enable_rssi_th[i] = 100;
disabled_rf_cnt--;
}
}
}
}
}
static void dm_check_rx_path_selection(struct r8192_priv *priv)
{
queue_delayed_work(priv->priv_wq,&priv->rfpath_check_wq,0);
}
static void dm_init_fsync(struct r8192_priv *priv)
{
priv->ieee80211->fsync_time_interval = 500;
priv->ieee80211->fsync_rate_bitmap = 0x0f000800;
priv->ieee80211->fsync_rssi_threshold = 30;
priv->ieee80211->bfsync_enable = false;
priv->ieee80211->fsync_multiple_timeinterval = 3;
priv->ieee80211->fsync_firstdiff_ratethreshold= 100;
priv->ieee80211->fsync_seconddiff_ratethreshold= 200;
priv->ieee80211->fsync_state = Default_Fsync;
priv->framesyncMonitor = 1;
init_timer(&priv->fsync_timer);
priv->fsync_timer.data = (unsigned long)priv;
priv->fsync_timer.function = dm_fsync_timer_callback;
}
static void dm_deInit_fsync(struct r8192_priv *priv)
{
del_timer_sync(&priv->fsync_timer);
}
static void dm_fsync_timer_callback(unsigned long data)
{
struct r8192_priv *priv = (struct r8192_priv *)data;
u32 rate_index, rate_count = 0, rate_count_diff=0;
bool bSwitchFromCountDiff = false;
bool bDoubleTimeInterval = false;
if( priv->ieee80211->state == IEEE80211_LINKED &&
priv->ieee80211->bfsync_enable &&
(priv->ieee80211->pHTInfo->IOTAction & HT_IOT_ACT_CDD_FSYNC))
{
u32 rate_bitmap;
for(rate_index = 0; rate_index <= 27; rate_index++)
{
rate_bitmap = 1 << rate_index;
if(priv->ieee80211->fsync_rate_bitmap & rate_bitmap)
rate_count+= priv->stats.received_rate_histogram[1][rate_index];
}
if(rate_count < priv->rate_record)
rate_count_diff = 0xffffffff - rate_count + priv->rate_record;
else
rate_count_diff = rate_count - priv->rate_record;
if(rate_count_diff < priv->rateCountDiffRecord)
{
u32 DiffNum = priv->rateCountDiffRecord - rate_count_diff;
if(DiffNum >= priv->ieee80211->fsync_seconddiff_ratethreshold)
priv->ContiuneDiffCount++;
else
priv->ContiuneDiffCount = 0;
if(priv->ContiuneDiffCount >=2)
{
bSwitchFromCountDiff = true;
priv->ContiuneDiffCount = 0;
}
}
else
{
priv->ContiuneDiffCount = 0;
}
if(rate_count_diff <= priv->ieee80211->fsync_firstdiff_ratethreshold)
{
bSwitchFromCountDiff = true;
priv->ContiuneDiffCount = 0;
}
priv->rate_record = rate_count;
priv->rateCountDiffRecord = rate_count_diff;
RT_TRACE(COMP_HALDM, "rateRecord %d rateCount %d, rateCountdiff %d bSwitchFsync %d\n", priv->rate_record, rate_count, rate_count_diff , priv->bswitch_fsync);
if(priv->undecorated_smoothed_pwdb > priv->ieee80211->fsync_rssi_threshold && bSwitchFromCountDiff)
{
bDoubleTimeInterval = true;
priv->bswitch_fsync = !priv->bswitch_fsync;
if(priv->bswitch_fsync)
{
write_nic_byte(priv,0xC36, 0x1c);
write_nic_byte(priv, 0xC3e, 0x90);
}
else
{
write_nic_byte(priv, 0xC36, 0x5c);
write_nic_byte(priv, 0xC3e, 0x96);
}
}
else if(priv->undecorated_smoothed_pwdb <= priv->ieee80211->fsync_rssi_threshold)
{
if(priv->bswitch_fsync)
{
priv->bswitch_fsync = false;
write_nic_byte(priv, 0xC36, 0x5c);
write_nic_byte(priv, 0xC3e, 0x96);
}
}
if(bDoubleTimeInterval){
if(timer_pending(&priv->fsync_timer))
del_timer_sync(&priv->fsync_timer);
priv->fsync_timer.expires = jiffies + MSECS(priv->ieee80211->fsync_time_interval*priv->ieee80211->fsync_multiple_timeinterval);
add_timer(&priv->fsync_timer);
}
else{
if(timer_pending(&priv->fsync_timer))
del_timer_sync(&priv->fsync_timer);
priv->fsync_timer.expires = jiffies + MSECS(priv->ieee80211->fsync_time_interval);
add_timer(&priv->fsync_timer);
}
}
else
{
if(priv->bswitch_fsync)
{
priv->bswitch_fsync = false;
write_nic_byte(priv, 0xC36, 0x5c);
write_nic_byte(priv, 0xC3e, 0x96);
}
priv->ContiuneDiffCount = 0;
write_nic_dword(priv, rOFDM0_RxDetector2, 0x465c52cd);
}
RT_TRACE(COMP_HALDM, "ContiuneDiffCount %d\n", priv->ContiuneDiffCount);
RT_TRACE(COMP_HALDM, "rateRecord %d rateCount %d, rateCountdiff %d bSwitchFsync %d\n", priv->rate_record, rate_count, rate_count_diff , priv->bswitch_fsync);
}
static void dm_StartHWFsync(struct r8192_priv *priv)
{
RT_TRACE(COMP_HALDM, "%s\n", __FUNCTION__);
write_nic_dword(priv, rOFDM0_RxDetector2, 0x465c12cf);
write_nic_byte(priv, 0xc3b, 0x41);
}
static void dm_EndSWFsync(struct r8192_priv *priv)
{
RT_TRACE(COMP_HALDM, "%s\n", __FUNCTION__);
del_timer_sync(&(priv->fsync_timer));
if(priv->bswitch_fsync)
{
priv->bswitch_fsync = false;
write_nic_byte(priv, 0xC36, 0x40);
write_nic_byte(priv, 0xC3e, 0x96);
}
priv->ContiuneDiffCount = 0;
write_nic_dword(priv, rOFDM0_RxDetector2, 0x465c52cd);
}
static void dm_StartSWFsync(struct r8192_priv *priv)
{
u32 rateIndex;
u32 rateBitmap;
RT_TRACE(COMP_HALDM,"%s\n", __FUNCTION__);
priv->rate_record = 0;
priv->ContiuneDiffCount = 0;
priv->rateCountDiffRecord = 0;
priv->bswitch_fsync = false;
if(priv->ieee80211->mode == WIRELESS_MODE_N_24G)
{
priv->ieee80211->fsync_firstdiff_ratethreshold= 600;
priv->ieee80211->fsync_seconddiff_ratethreshold = 0xffff;
}
else
{
priv->ieee80211->fsync_firstdiff_ratethreshold= 200;
priv->ieee80211->fsync_seconddiff_ratethreshold = 200;
}
for(rateIndex = 0; rateIndex <= 27; rateIndex++)
{
rateBitmap = 1 << rateIndex;
if(priv->ieee80211->fsync_rate_bitmap & rateBitmap)
priv->rate_record += priv->stats.received_rate_histogram[1][rateIndex];
}
if(timer_pending(&priv->fsync_timer))
del_timer_sync(&priv->fsync_timer);
priv->fsync_timer.expires = jiffies + MSECS(priv->ieee80211->fsync_time_interval);
add_timer(&priv->fsync_timer);
write_nic_dword(priv, rOFDM0_RxDetector2, 0x465c12cd);
}
static void dm_EndHWFsync(struct r8192_priv *priv)
{
RT_TRACE(COMP_HALDM,"%s\n", __FUNCTION__);
write_nic_dword(priv, rOFDM0_RxDetector2, 0x465c52cd);
write_nic_byte(priv, 0xc3b, 0x49);
}
static void dm_check_fsync(struct r8192_priv *priv)
{
#define RegC38_Default 0
#define RegC38_NonFsync_Other_AP 1
#define RegC38_Fsync_AP_BCM 2
static u8 reg_c38_State=RegC38_Default;
static u32 reset_cnt=0;
RT_TRACE(COMP_HALDM, "RSSI %d TimeInterval %d MultipleTimeInterval %d\n", priv->ieee80211->fsync_rssi_threshold, priv->ieee80211->fsync_time_interval, priv->ieee80211->fsync_multiple_timeinterval);
RT_TRACE(COMP_HALDM, "RateBitmap 0x%x FirstDiffRateThreshold %d SecondDiffRateThreshold %d\n", priv->ieee80211->fsync_rate_bitmap, priv->ieee80211->fsync_firstdiff_ratethreshold, priv->ieee80211->fsync_seconddiff_ratethreshold);
if( priv->ieee80211->state == IEEE80211_LINKED &&
(priv->ieee80211->pHTInfo->IOTAction & HT_IOT_ACT_CDD_FSYNC))
{
if(priv->ieee80211->bfsync_enable == 0)
{
switch(priv->ieee80211->fsync_state)
{
case Default_Fsync:
dm_StartHWFsync(priv);
priv->ieee80211->fsync_state = HW_Fsync;
break;
case SW_Fsync:
dm_EndSWFsync(priv);
dm_StartHWFsync(priv);
priv->ieee80211->fsync_state = HW_Fsync;
break;
case HW_Fsync:
default:
break;
}
}
else
{
switch(priv->ieee80211->fsync_state)
{
case Default_Fsync:
dm_StartSWFsync(priv);
priv->ieee80211->fsync_state = SW_Fsync;
break;
case HW_Fsync:
dm_EndHWFsync(priv);
dm_StartSWFsync(priv);
priv->ieee80211->fsync_state = SW_Fsync;
break;
case SW_Fsync:
default:
break;
}
}
if(priv->framesyncMonitor)
{
if(reg_c38_State != RegC38_Fsync_AP_BCM)
{
write_nic_byte(priv, rOFDM0_RxDetector3, 0x95);
reg_c38_State = RegC38_Fsync_AP_BCM;
}
}
}
else
{
switch(priv->ieee80211->fsync_state)
{
case HW_Fsync:
dm_EndHWFsync(priv);
priv->ieee80211->fsync_state = Default_Fsync;
break;
case SW_Fsync:
dm_EndSWFsync(priv);
priv->ieee80211->fsync_state = Default_Fsync;
break;
case Default_Fsync:
default:
break;
}
if(priv->framesyncMonitor)
{
if(priv->ieee80211->state == IEEE80211_LINKED)
{
if(priv->undecorated_smoothed_pwdb <= RegC38_TH)
{
if(reg_c38_State != RegC38_NonFsync_Other_AP)
{
write_nic_byte(priv, rOFDM0_RxDetector3, 0x90);
reg_c38_State = RegC38_NonFsync_Other_AP;
}
}
else if(priv->undecorated_smoothed_pwdb >= (RegC38_TH+5))
{
if(reg_c38_State)
{
write_nic_byte(priv, rOFDM0_RxDetector3, priv->framesync);
reg_c38_State = RegC38_Default;
}
}
}
else
{
if(reg_c38_State)
{
write_nic_byte(priv, rOFDM0_RxDetector3, priv->framesync);
reg_c38_State = RegC38_Default;
}
}
}
}
if(priv->framesyncMonitor)
{
if(priv->reset_count != reset_cnt)
{
write_nic_byte(priv, rOFDM0_RxDetector3, priv->framesync);
reg_c38_State = RegC38_Default;
reset_cnt = priv->reset_count;
}
}
else
{
if(reg_c38_State)
{
write_nic_byte(priv, rOFDM0_RxDetector3, priv->framesync);
reg_c38_State = RegC38_Default;
}
}
}
static void dm_init_dynamic_txpower(struct r8192_priv *priv)
{
priv->ieee80211->bdynamic_txpower_enable = true;
priv->bLastDTPFlag_High = false;
priv->bLastDTPFlag_Low = false;
priv->bDynamicTxHighPower = false;
priv->bDynamicTxLowPower = false;
}
static void dm_dynamic_txpower(struct r8192_priv *priv)
{
unsigned int txhipower_threshhold=0;
unsigned int txlowpower_threshold=0;
if(priv->ieee80211->bdynamic_txpower_enable != true)
{
priv->bDynamicTxHighPower = false;
priv->bDynamicTxLowPower = false;
return;
}
if((priv->ieee80211->current_network.atheros_cap_exist ) && (priv->ieee80211->mode == IEEE_G)){
txhipower_threshhold = TX_POWER_ATHEROAP_THRESH_HIGH;
txlowpower_threshold = TX_POWER_ATHEROAP_THRESH_LOW;
}
else
{
txhipower_threshhold = TX_POWER_NEAR_FIELD_THRESH_HIGH;
txlowpower_threshold = TX_POWER_NEAR_FIELD_THRESH_LOW;
}
RT_TRACE(COMP_TXAGC, "priv->undecorated_smoothed_pwdb = %ld\n" , priv->undecorated_smoothed_pwdb);
if(priv->ieee80211->state == IEEE80211_LINKED)
{
if(priv->undecorated_smoothed_pwdb >= txhipower_threshhold)
{
priv->bDynamicTxHighPower = true;
priv->bDynamicTxLowPower = false;
}
else
{
if(priv->undecorated_smoothed_pwdb < txlowpower_threshold && priv->bDynamicTxHighPower == true)
{
priv->bDynamicTxHighPower = false;
}
if(priv->undecorated_smoothed_pwdb < 35)
{
priv->bDynamicTxLowPower = true;
}
else if(priv->undecorated_smoothed_pwdb >= 40)
{
priv->bDynamicTxLowPower = false;
}
}
}
else
{
priv->bDynamicTxHighPower = false;
priv->bDynamicTxLowPower = false;
}
if( (priv->bDynamicTxHighPower != priv->bLastDTPFlag_High ) ||
(priv->bDynamicTxLowPower != priv->bLastDTPFlag_Low ) )
{
RT_TRACE(COMP_TXAGC, "SetTxPowerLevel8190() channel = %d\n", priv->ieee80211->current_network.channel);
rtl8192_phy_setTxPower(priv, priv->ieee80211->current_network.channel);
}
priv->bLastDTPFlag_High = priv->bDynamicTxHighPower;
priv->bLastDTPFlag_Low = priv->bDynamicTxLowPower;
}
static void dm_check_txrateandretrycount(struct r8192_priv *priv)
{
struct ieee80211_device* ieee = priv->ieee80211;
ieee->softmac_stats.last_packet_rate = read_nic_byte(priv ,Initial_Tx_Rate_Reg);
ieee->softmac_stats.txretrycount = read_nic_dword(priv, Tx_Retry_Count_Reg);
}
static void dm_send_rssi_tofw(struct r8192_priv *priv)
{
write_nic_byte(priv, DRIVER_RSSI, (u8)priv->undecorated_smoothed_pwdb);
return;
}
