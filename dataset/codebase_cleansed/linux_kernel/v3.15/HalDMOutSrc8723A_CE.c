static void
odm_TXPowerTrackingCallback_ThermalMeter_92C(
struct rtw_adapter *Adapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
u8 ThermalValue = 0, delta, delta_LCK, delta_IQK, delta_HP;
int ele_A, ele_D, TempCCk, X, value32;
int Y, ele_C;
s8 OFDM_index[2], CCK_index = 0, OFDM_index_old[2] = {0};
s8 CCK_index_old = 0;
int i = 0;
bool is2T = IS_92C_SERIAL(pHalData->VersionID);
u8 OFDM_min_index = 6, rf;
u8 ThermalValue_HP_count = 0;
u32 ThermalValue_HP = 0;
s32 index_mapping_HP[index_mapping_HP_NUM] = {
0, 1, 3, 4, 6,
7, 9, 10, 12, 13,
15, 16, 18, 19, 21
};
s8 index_HP;
pdmpriv->TXPowerTrackingCallbackCnt++;
pdmpriv->bTXPowerTrackingInit = true;
if (pHalData->CurrentChannel == 14 && !pdmpriv->bCCKinCH14)
pdmpriv->bCCKinCH14 = true;
else if (pHalData->CurrentChannel != 14 && pdmpriv->bCCKinCH14)
pdmpriv->bCCKinCH14 = false;
ThermalValue = (u8)PHY_QueryRFReg(Adapter, RF_PATH_A, RF_T_METER,
0x1f);
rtl8723a_phy_ap_calibrate(Adapter, (ThermalValue -
pHalData->EEPROMThermalMeter));
if (is2T)
rf = 2;
else
rf = 1;
if (ThermalValue) {
ele_D = PHY_QueryBBReg(Adapter, rOFDM0_XATxIQImbalance,
bMaskDWord)&bMaskOFDM_D;
for (i = 0; i < OFDM_TABLE_SIZE_92C; i++) {
if (ele_D == (OFDMSwingTable23A[i]&bMaskOFDM_D)) {
OFDM_index_old[0] = (u8)i;
break;
}
}
if (is2T) {
ele_D = PHY_QueryBBReg(Adapter, rOFDM0_XBTxIQImbalance,
bMaskDWord)&bMaskOFDM_D;
for (i = 0; i < OFDM_TABLE_SIZE_92C; i++) {
if (ele_D == (OFDMSwingTable23A[i]&bMaskOFDM_D)) {
OFDM_index_old[1] = (u8)i;
break;
}
}
}
TempCCk = PHY_QueryBBReg(Adapter, rCCK0_TxFilter2,
bMaskDWord)&bMaskCCK;
for (i = 0 ; i < CCK_TABLE_SIZE ; i++) {
if (pdmpriv->bCCKinCH14) {
if (!memcmp(&TempCCk,
&CCKSwingTable_Ch1423A[i][2], 4)) {
CCK_index_old = (u8)i;
break;
}
} else {
if (!memcmp(&TempCCk,
&CCKSwingTable_Ch1_Ch1323A[i][2], 4)) {
CCK_index_old = (u8)i;
break;
}
}
}
if (!pdmpriv->ThermalValue) {
pdmpriv->ThermalValue = pHalData->EEPROMThermalMeter;
pdmpriv->ThermalValue_LCK = ThermalValue;
pdmpriv->ThermalValue_IQK = ThermalValue;
pdmpriv->ThermalValue_DPK = pHalData->EEPROMThermalMeter;
for (i = 0; i < rf; i++) {
pdmpriv->OFDM_index_HP[i] = OFDM_index_old[i];
pdmpriv->OFDM_index[i] = OFDM_index_old[i];
}
pdmpriv->CCK_index_HP = CCK_index_old;
pdmpriv->CCK_index = CCK_index_old;
}
if (pHalData->BoardType == BOARD_USB_High_PA) {
pdmpriv->ThermalValue_HP[pdmpriv->ThermalValue_HP_index] = ThermalValue;
pdmpriv->ThermalValue_HP_index++;
if (pdmpriv->ThermalValue_HP_index == HP_THERMAL_NUM)
pdmpriv->ThermalValue_HP_index = 0;
for (i = 0; i < HP_THERMAL_NUM; i++) {
if (pdmpriv->ThermalValue_HP[i]) {
ThermalValue_HP += pdmpriv->ThermalValue_HP[i];
ThermalValue_HP_count++;
}
}
if (ThermalValue_HP_count)
ThermalValue = (u8)(ThermalValue_HP / ThermalValue_HP_count);
}
delta = (ThermalValue > pdmpriv->ThermalValue) ?
(ThermalValue - pdmpriv->ThermalValue) :
(pdmpriv->ThermalValue - ThermalValue);
if (pHalData->BoardType == BOARD_USB_High_PA) {
if (pdmpriv->bDoneTxpower)
delta_HP = (ThermalValue > pdmpriv->ThermalValue) ?
(ThermalValue - pdmpriv->ThermalValue) :
(pdmpriv->ThermalValue - ThermalValue);
else
delta_HP = ThermalValue > pHalData->EEPROMThermalMeter ?
(ThermalValue - pHalData->EEPROMThermalMeter) :
(pHalData->EEPROMThermalMeter - ThermalValue);
} else {
delta_HP = 0;
}
delta_LCK = (ThermalValue > pdmpriv->ThermalValue_LCK) ?
(ThermalValue - pdmpriv->ThermalValue_LCK) :
(pdmpriv->ThermalValue_LCK - ThermalValue);
delta_IQK = (ThermalValue > pdmpriv->ThermalValue_IQK) ?
(ThermalValue - pdmpriv->ThermalValue_IQK) :
(pdmpriv->ThermalValue_IQK - ThermalValue);
if (delta_LCK > 1) {
pdmpriv->ThermalValue_LCK = ThermalValue;
rtl8723a_phy_lc_calibrate(Adapter);
}
if ((delta > 0 || delta_HP > 0) && pdmpriv->TxPowerTrackControl) {
if (pHalData->BoardType == BOARD_USB_High_PA) {
pdmpriv->bDoneTxpower = true;
delta_HP = ThermalValue > pHalData->EEPROMThermalMeter ?
(ThermalValue - pHalData->EEPROMThermalMeter) :
(pHalData->EEPROMThermalMeter - ThermalValue);
if (delta_HP > index_mapping_HP_NUM-1)
index_HP = index_mapping_HP[index_mapping_HP_NUM-1];
else
index_HP = index_mapping_HP[delta_HP];
if (ThermalValue > pHalData->EEPROMThermalMeter) {
for (i = 0; i < rf; i++)
OFDM_index[i] = pdmpriv->OFDM_index_HP[i] - index_HP;
CCK_index = pdmpriv->CCK_index_HP - index_HP;
} else {
for (i = 0; i < rf; i++)
OFDM_index[i] = pdmpriv->OFDM_index_HP[i] + index_HP;
CCK_index = pdmpriv->CCK_index_HP + index_HP;
}
delta_HP = (ThermalValue > pdmpriv->ThermalValue) ?
(ThermalValue - pdmpriv->ThermalValue) :
(pdmpriv->ThermalValue - ThermalValue);
} else {
if (ThermalValue > pdmpriv->ThermalValue) {
for (i = 0; i < rf; i++)
pdmpriv->OFDM_index[i] -= delta;
pdmpriv->CCK_index -= delta;
} else {
for (i = 0; i < rf; i++)
pdmpriv->OFDM_index[i] += delta;
pdmpriv->CCK_index += delta;
}
}
if (pHalData->BoardType != BOARD_USB_High_PA) {
if (ThermalValue > pHalData->EEPROMThermalMeter) {
for (i = 0; i < rf; i++)
OFDM_index[i] = pdmpriv->OFDM_index[i]+1;
CCK_index = pdmpriv->CCK_index+1;
} else {
for (i = 0; i < rf; i++)
OFDM_index[i] = pdmpriv->OFDM_index[i];
CCK_index = pdmpriv->CCK_index;
}
}
for (i = 0; i < rf; i++) {
if (OFDM_index[i] > (OFDM_TABLE_SIZE_92C-1))
OFDM_index[i] = (OFDM_TABLE_SIZE_92C-1);
else if (OFDM_index[i] < OFDM_min_index)
OFDM_index[i] = OFDM_min_index;
}
if (CCK_index > (CCK_TABLE_SIZE-1))
CCK_index = (CCK_TABLE_SIZE-1);
else if (CCK_index < 0)
CCK_index = 0;
}
if (pdmpriv->TxPowerTrackControl && (delta != 0 || delta_HP != 0)) {
ele_D = (OFDMSwingTable23A[OFDM_index[0]] & 0xFFC00000)>>22;
X = pdmpriv->RegE94;
Y = pdmpriv->RegE9C;
if (X != 0) {
if ((X & 0x00000200) != 0)
X = X | 0xFFFFFC00;
ele_A = ((X * ele_D)>>8)&0x000003FF;
if ((Y & 0x00000200) != 0)
Y = Y | 0xFFFFFC00;
ele_C = ((Y * ele_D)>>8)&0x000003FF;
value32 = (ele_D<<22)|((ele_C&0x3F)<<16)|ele_A;
PHY_SetBBReg(Adapter, rOFDM0_XATxIQImbalance, bMaskDWord, value32);
value32 = (ele_C&0x000003C0)>>6;
PHY_SetBBReg(Adapter, rOFDM0_XCTxAFE, bMaskH4Bits, value32);
value32 = ((X * ele_D)>>7)&0x01;
PHY_SetBBReg(Adapter, rOFDM0_ECCAThreshold, BIT31, value32);
value32 = ((Y * ele_D)>>7)&0x01;
PHY_SetBBReg(Adapter, rOFDM0_ECCAThreshold, BIT29, value32);
} else {
PHY_SetBBReg(Adapter, rOFDM0_XATxIQImbalance, bMaskDWord, OFDMSwingTable23A[OFDM_index[0]]);
PHY_SetBBReg(Adapter, rOFDM0_XCTxAFE, bMaskH4Bits, 0x00);
PHY_SetBBReg(Adapter, rOFDM0_ECCAThreshold, BIT31|BIT29, 0x00);
}
if (!pdmpriv->bCCKinCH14) {
rtw_write8(Adapter, 0xa22, CCKSwingTable_Ch1_Ch1323A[CCK_index][0]);
rtw_write8(Adapter, 0xa23, CCKSwingTable_Ch1_Ch1323A[CCK_index][1]);
rtw_write8(Adapter, 0xa24, CCKSwingTable_Ch1_Ch1323A[CCK_index][2]);
rtw_write8(Adapter, 0xa25, CCKSwingTable_Ch1_Ch1323A[CCK_index][3]);
rtw_write8(Adapter, 0xa26, CCKSwingTable_Ch1_Ch1323A[CCK_index][4]);
rtw_write8(Adapter, 0xa27, CCKSwingTable_Ch1_Ch1323A[CCK_index][5]);
rtw_write8(Adapter, 0xa28, CCKSwingTable_Ch1_Ch1323A[CCK_index][6]);
rtw_write8(Adapter, 0xa29, CCKSwingTable_Ch1_Ch1323A[CCK_index][7]);
} else {
rtw_write8(Adapter, 0xa22, CCKSwingTable_Ch1423A[CCK_index][0]);
rtw_write8(Adapter, 0xa23, CCKSwingTable_Ch1423A[CCK_index][1]);
rtw_write8(Adapter, 0xa24, CCKSwingTable_Ch1423A[CCK_index][2]);
rtw_write8(Adapter, 0xa25, CCKSwingTable_Ch1423A[CCK_index][3]);
rtw_write8(Adapter, 0xa26, CCKSwingTable_Ch1423A[CCK_index][4]);
rtw_write8(Adapter, 0xa27, CCKSwingTable_Ch1423A[CCK_index][5]);
rtw_write8(Adapter, 0xa28, CCKSwingTable_Ch1423A[CCK_index][6]);
rtw_write8(Adapter, 0xa29, CCKSwingTable_Ch1423A[CCK_index][7]);
}
if (is2T) {
ele_D = (OFDMSwingTable23A[(u8)OFDM_index[1]] & 0xFFC00000)>>22;
X = pdmpriv->RegEB4;
Y = pdmpriv->RegEBC;
if (X != 0) {
if ((X & 0x00000200) != 0)
X = X | 0xFFFFFC00;
ele_A = ((X * ele_D)>>8)&0x000003FF;
if ((Y & 0x00000200) != 0)
Y = Y | 0xFFFFFC00;
ele_C = ((Y * ele_D)>>8)&0x00003FF;
value32 = (ele_D<<22)|((ele_C&0x3F)<<16) | ele_A;
PHY_SetBBReg(Adapter, rOFDM0_XBTxIQImbalance, bMaskDWord, value32);
value32 = (ele_C&0x000003C0)>>6;
PHY_SetBBReg(Adapter, rOFDM0_XDTxAFE, bMaskH4Bits, value32);
value32 = ((X * ele_D)>>7)&0x01;
PHY_SetBBReg(Adapter, rOFDM0_ECCAThreshold, BIT27, value32);
value32 = ((Y * ele_D)>>7)&0x01;
PHY_SetBBReg(Adapter, rOFDM0_ECCAThreshold, BIT25, value32);
} else {
PHY_SetBBReg(Adapter, rOFDM0_XBTxIQImbalance, bMaskDWord, OFDMSwingTable23A[OFDM_index[1]]);
PHY_SetBBReg(Adapter, rOFDM0_XDTxAFE, bMaskH4Bits, 0x00);
PHY_SetBBReg(Adapter, rOFDM0_ECCAThreshold, BIT27|BIT25, 0x00);
}
}
}
if (delta_IQK > 3) {
pdmpriv->ThermalValue_IQK = ThermalValue;
rtl8723a_phy_iq_calibrate(Adapter, false);
}
if (pdmpriv->TxPowerTrackControl)
pdmpriv->ThermalValue = ThermalValue;
}
pdmpriv->TXPowercount = 0;
}
static void ODM_TXPowerTracking92CDirectCall(struct rtw_adapter *Adapter)
{
odm_TXPowerTrackingCallback_ThermalMeter_92C(Adapter);
}
static void odm_CheckTXPowerTracking_ThermalMeter(struct rtw_adapter *Adapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
struct dm_odm_t *podmpriv = &pHalData->odmpriv;
if (!(podmpriv->SupportAbility & ODM_RF_TX_PWR_TRACK))
return;
if (!pdmpriv->TM_Trigger) {
PHY_SetRFReg(Adapter, RF_PATH_A, RF_T_METER, bRFRegOffsetMask, 0x60);
pdmpriv->TM_Trigger = 1;
return;
} else {
ODM_TXPowerTracking92CDirectCall(Adapter);
pdmpriv->TM_Trigger = 0;
}
}
void rtl8723a_odm_check_tx_power_tracking(struct rtw_adapter *Adapter)
{
odm_CheckTXPowerTracking_ThermalMeter(Adapter);
}
static u8 _PHY_PathA_IQK(struct rtw_adapter *pAdapter, bool configPathB)
{
u32 regEAC, regE94, regE9C, regEA4;
u8 result = 0x00;
struct hal_data_8723a *pHalData = GET_HAL_DATA(pAdapter);
PHY_SetBBReg(pAdapter, rTx_IQK_Tone_A, bMaskDWord, 0x10008c1f);
PHY_SetBBReg(pAdapter, rRx_IQK_Tone_A, bMaskDWord, 0x10008c1f);
PHY_SetBBReg(pAdapter, rTx_IQK_PI_A, bMaskDWord, 0x82140102);
PHY_SetBBReg(pAdapter, rRx_IQK_PI_A, bMaskDWord, configPathB ? 0x28160202 :
IS_81xxC_VENDOR_UMC_B_CUT(pHalData->VersionID)?0x28160202:0x28160502);
if (configPathB) {
PHY_SetBBReg(pAdapter, rTx_IQK_Tone_B, bMaskDWord, 0x10008c22);
PHY_SetBBReg(pAdapter, rRx_IQK_Tone_B, bMaskDWord, 0x10008c22);
PHY_SetBBReg(pAdapter, rTx_IQK_PI_B, bMaskDWord, 0x82140102);
PHY_SetBBReg(pAdapter, rRx_IQK_PI_B, bMaskDWord, 0x28160202);
}
PHY_SetBBReg(pAdapter, rIQK_AGC_Rsp, bMaskDWord, 0x001028d1);
PHY_SetBBReg(pAdapter, rIQK_AGC_Pts, bMaskDWord, 0xf9000000);
PHY_SetBBReg(pAdapter, rIQK_AGC_Pts, bMaskDWord, 0xf8000000);
udelay(IQK_DELAY_TIME*1000);
regEAC = PHY_QueryBBReg(pAdapter, rRx_Power_After_IQK_A_2, bMaskDWord);
regE94 = PHY_QueryBBReg(pAdapter, rTx_Power_Before_IQK_A, bMaskDWord);
regE9C = PHY_QueryBBReg(pAdapter, rTx_Power_After_IQK_A, bMaskDWord);
regEA4 = PHY_QueryBBReg(pAdapter, rRx_Power_Before_IQK_A_2, bMaskDWord);
if (!(regEAC & BIT28) &&
(((regE94 & 0x03FF0000)>>16) != 0x142) &&
(((regE9C & 0x03FF0000)>>16) != 0x42))
result |= 0x01;
else
return result;
if (!(regEAC & BIT27) &&
(((regEA4 & 0x03FF0000)>>16) != 0x132) &&
(((regEAC & 0x03FF0000)>>16) != 0x36))
result |= 0x02;
else
DBG_8723A("Path A Rx IQK fail!!\n");
return result;
}
static u8 _PHY_PathB_IQK(struct rtw_adapter *pAdapter)
{
u32 regEAC, regEB4, regEBC, regEC4, regECC;
u8 result = 0x00;
PHY_SetBBReg(pAdapter, rIQK_AGC_Cont, bMaskDWord, 0x00000002);
PHY_SetBBReg(pAdapter, rIQK_AGC_Cont, bMaskDWord, 0x00000000);
udelay(IQK_DELAY_TIME*1000);
regEAC = PHY_QueryBBReg(pAdapter, rRx_Power_After_IQK_A_2, bMaskDWord);
regEB4 = PHY_QueryBBReg(pAdapter, rTx_Power_Before_IQK_B, bMaskDWord);
regEBC = PHY_QueryBBReg(pAdapter, rTx_Power_After_IQK_B, bMaskDWord);
regEC4 = PHY_QueryBBReg(pAdapter, rRx_Power_Before_IQK_B_2, bMaskDWord);
regECC = PHY_QueryBBReg(pAdapter, rRx_Power_After_IQK_B_2, bMaskDWord);
if (!(regEAC & BIT31) &&
(((regEB4 & 0x03FF0000)>>16) != 0x142) &&
(((regEBC & 0x03FF0000)>>16) != 0x42))
result |= 0x01;
else
return result;
if (!(regEAC & BIT30) &&
(((regEC4 & 0x03FF0000)>>16) != 0x132) &&
(((regECC & 0x03FF0000)>>16) != 0x36))
result |= 0x02;
else
DBG_8723A("Path B Rx IQK fail!!\n");
return result;
}
static void _PHY_PathAFillIQKMatrix(struct rtw_adapter *pAdapter,
bool bIQKOK,
int result[][8],
u8 final_candidate,
bool bTxOnly
)
{
u32 Oldval_0, X, TX0_A, reg;
s32 Y, TX0_C;
DBG_8723A("Path A IQ Calibration %s !\n", (bIQKOK)?"Success":"Failed");
if (final_candidate == 0xFF) {
return;
} else if (bIQKOK) {
Oldval_0 = (PHY_QueryBBReg(pAdapter, rOFDM0_XATxIQImbalance, bMaskDWord) >> 22) & 0x3FF;
X = result[final_candidate][0];
if ((X & 0x00000200) != 0)
X = X | 0xFFFFFC00;
TX0_A = (X * Oldval_0) >> 8;
PHY_SetBBReg(pAdapter, rOFDM0_XATxIQImbalance, 0x3FF, TX0_A);
PHY_SetBBReg(pAdapter, rOFDM0_ECCAThreshold, BIT(31), ((X * Oldval_0>>7) & 0x1));
Y = result[final_candidate][1];
if ((Y & 0x00000200) != 0)
Y = Y | 0xFFFFFC00;
TX0_C = (Y * Oldval_0) >> 8;
PHY_SetBBReg(pAdapter, rOFDM0_XCTxAFE, 0xF0000000, ((TX0_C&0x3C0)>>6));
PHY_SetBBReg(pAdapter, rOFDM0_XATxIQImbalance, 0x003F0000, (TX0_C&0x3F));
PHY_SetBBReg(pAdapter, rOFDM0_ECCAThreshold, BIT(29), ((Y * Oldval_0>>7) & 0x1));
if (bTxOnly) {
DBG_8723A("_PHY_PathAFillIQKMatrix only Tx OK\n");
return;
}
reg = result[final_candidate][2];
PHY_SetBBReg(pAdapter, rOFDM0_XARxIQImbalance, 0x3FF, reg);
reg = result[final_candidate][3] & 0x3F;
PHY_SetBBReg(pAdapter, rOFDM0_XARxIQImbalance, 0xFC00, reg);
reg = (result[final_candidate][3] >> 6) & 0xF;
PHY_SetBBReg(pAdapter, rOFDM0_RxIQExtAnta, 0xF0000000, reg);
}
}
static void _PHY_PathBFillIQKMatrix(struct rtw_adapter *pAdapter, bool bIQKOK, int result[][8], u8 final_candidate, bool bTxOnly)
{
u32 Oldval_1, X, TX1_A, reg;
s32 Y, TX1_C;
DBG_8723A("Path B IQ Calibration %s !\n", (bIQKOK)?"Success":"Failed");
if (final_candidate == 0xFF) {
return;
} else if (bIQKOK) {
Oldval_1 = (PHY_QueryBBReg(pAdapter, rOFDM0_XBTxIQImbalance, bMaskDWord) >> 22) & 0x3FF;
X = result[final_candidate][4];
if ((X & 0x00000200) != 0)
X = X | 0xFFFFFC00;
TX1_A = (X * Oldval_1) >> 8;
PHY_SetBBReg(pAdapter, rOFDM0_XBTxIQImbalance, 0x3FF, TX1_A);
PHY_SetBBReg(pAdapter, rOFDM0_ECCAThreshold, BIT(27), ((X * Oldval_1>>7) & 0x1));
Y = result[final_candidate][5];
if ((Y & 0x00000200) != 0)
Y = Y | 0xFFFFFC00;
TX1_C = (Y * Oldval_1) >> 8;
PHY_SetBBReg(pAdapter, rOFDM0_XDTxAFE, 0xF0000000, ((TX1_C&0x3C0)>>6));
PHY_SetBBReg(pAdapter, rOFDM0_XBTxIQImbalance, 0x003F0000, (TX1_C&0x3F));
PHY_SetBBReg(pAdapter, rOFDM0_ECCAThreshold, BIT(25), ((Y * Oldval_1>>7) & 0x1));
if (bTxOnly)
return;
reg = result[final_candidate][6];
PHY_SetBBReg(pAdapter, rOFDM0_XBRxIQImbalance, 0x3FF, reg);
reg = result[final_candidate][7] & 0x3F;
PHY_SetBBReg(pAdapter, rOFDM0_XBRxIQImbalance, 0xFC00, reg);
reg = (result[final_candidate][7] >> 6) & 0xF;
PHY_SetBBReg(pAdapter, rOFDM0_AGCRSSITable, 0x0000F000, reg);
}
}
static void _PHY_SaveADDARegisters(struct rtw_adapter *pAdapter, u32 *ADDAReg, u32 *ADDABackup, u32 RegisterNum)
{
u32 i;
for (i = 0 ; i < RegisterNum ; i++) {
ADDABackup[i] = PHY_QueryBBReg(pAdapter, ADDAReg[i], bMaskDWord);
}
}
static void _PHY_SaveMACRegisters(struct rtw_adapter *pAdapter, u32 *MACReg, u32 *MACBackup)
{
u32 i;
for (i = 0 ; i < (IQK_MAC_REG_NUM - 1); i++) {
MACBackup[i] = rtw_read8(pAdapter, MACReg[i]);
}
MACBackup[i] = rtw_read32(pAdapter, MACReg[i]);
}
static void _PHY_ReloadADDARegisters(struct rtw_adapter *pAdapter, u32 *ADDAReg, u32 *ADDABackup, u32 RegiesterNum)
{
u32 i;
for (i = 0 ; i < RegiesterNum ; i++) {
PHY_SetBBReg(pAdapter, ADDAReg[i], bMaskDWord, ADDABackup[i]);
}
}
static void _PHY_ReloadMACRegisters(struct rtw_adapter *pAdapter, u32 *MACReg, u32 *MACBackup)
{
u32 i;
for (i = 0 ; i < (IQK_MAC_REG_NUM - 1); i++) {
rtw_write8(pAdapter, MACReg[i], (u8)MACBackup[i]);
}
rtw_write32(pAdapter, MACReg[i], MACBackup[i]);
}
static void _PHY_PathADDAOn(struct rtw_adapter *pAdapter, u32 *ADDAReg, bool isPathAOn, bool is2T)
{
u32 pathOn;
u32 i;
pathOn = isPathAOn ? 0x04db25a4 : 0x0b1b25a4;
if (false == is2T) {
pathOn = 0x0bdb25a0;
PHY_SetBBReg(pAdapter, ADDAReg[0], bMaskDWord, 0x0b1b25a0);
} else {
PHY_SetBBReg(pAdapter, ADDAReg[0], bMaskDWord, pathOn);
}
for (i = 1 ; i < IQK_ADDA_REG_NUM ; i++)
PHY_SetBBReg(pAdapter, ADDAReg[i], bMaskDWord, pathOn);
}
static void _PHY_MACSettingCalibration(struct rtw_adapter *pAdapter, u32 *MACReg, u32 *MACBackup)
{
u32 i = 0;
rtw_write8(pAdapter, MACReg[i], 0x3F);
for (i = 1 ; i < (IQK_MAC_REG_NUM - 1); i++) {
rtw_write8(pAdapter, MACReg[i], (u8)(MACBackup[i]&(~BIT3)));
}
rtw_write8(pAdapter, MACReg[i], (u8)(MACBackup[i]&(~BIT5)));
}
static void _PHY_PathAStandBy(struct rtw_adapter *pAdapter)
{
PHY_SetBBReg(pAdapter, rFPGA0_IQK, bMaskDWord, 0x0);
PHY_SetBBReg(pAdapter, 0x840, bMaskDWord, 0x00010000);
PHY_SetBBReg(pAdapter, rFPGA0_IQK, bMaskDWord, 0x80800000);
}
static void _PHY_PIModeSwitch(struct rtw_adapter *pAdapter, bool PIMode)
{
u32 mode;
mode = PIMode ? 0x01000100 : 0x01000000;
PHY_SetBBReg(pAdapter, 0x820, bMaskDWord, mode);
PHY_SetBBReg(pAdapter, 0x828, bMaskDWord, mode);
}
static bool _PHY_SimularityCompare(struct rtw_adapter *pAdapter, int result[][8], u8 c1, u8 c2)
{
u32 i, j, diff, SimularityBitMap, bound = 0;
struct hal_data_8723a *pHalData = GET_HAL_DATA(pAdapter);
u8 final_candidate[2] = {0xFF, 0xFF};
bool bResult = true, is2T = IS_92C_SERIAL(pHalData->VersionID);
if (is2T)
bound = 8;
else
bound = 4;
SimularityBitMap = 0;
for (i = 0; i < bound; i++) {
diff = (result[c1][i] > result[c2][i]) ? (result[c1][i] - result[c2][i]) : (result[c2][i] - result[c1][i]);
if (diff > MAX_TOLERANCE) {
if ((i == 2 || i == 6) && !SimularityBitMap) {
if (result[c1][i]+result[c1][i+1] == 0)
final_candidate[(i/4)] = c2;
else if (result[c2][i]+result[c2][i+1] == 0)
final_candidate[(i/4)] = c1;
else
SimularityBitMap = SimularityBitMap|(1<<i);
} else {
SimularityBitMap = SimularityBitMap|(1<<i);
}
}
}
if (SimularityBitMap == 0) {
for (i = 0; i < (bound/4); i++) {
if (final_candidate[i] != 0xFF) {
for (j = i*4; j < (i+1)*4-2; j++)
result[3][j] = result[final_candidate[i]][j];
bResult = false;
}
}
return bResult;
} else if (!(SimularityBitMap & 0x0F)) {
for (i = 0; i < 4; i++)
result[3][i] = result[c1][i];
return false;
} else if (!(SimularityBitMap & 0xF0) && is2T) {
for (i = 4; i < 8; i++)
result[3][i] = result[c1][i];
return false;
} else {
return false;
}
}
static void _PHY_IQCalibrate(struct rtw_adapter *pAdapter, int result[][8], u8 t, bool is2T)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(pAdapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
u32 i;
u8 PathAOK, PathBOK;
u32 ADDA_REG[IQK_ADDA_REG_NUM] = {
rFPGA0_XCD_SwitchControl, rBlue_Tooth,
rRx_Wait_CCA, rTx_CCK_RFON,
rTx_CCK_BBON, rTx_OFDM_RFON,
rTx_OFDM_BBON, rTx_To_Rx,
rTx_To_Tx, rRx_CCK,
rRx_OFDM, rRx_Wait_RIFS,
rRx_TO_Rx, rStandby,
rSleep, rPMPD_ANAEN
};
u32 IQK_MAC_REG[IQK_MAC_REG_NUM] = {
REG_TXPAUSE, REG_BCN_CTRL,
REG_BCN_CTRL_1, REG_GPIO_MUXCFG
};
u32 IQK_BB_REG_92C[IQK_BB_REG_NUM] = {
rOFDM0_TRxPathEnable, rOFDM0_TRMuxPar,
rFPGA0_XCD_RFInterfaceSW, rConfig_AntA, rConfig_AntB,
rFPGA0_XAB_RFInterfaceSW, rFPGA0_XA_RFInterfaceOE,
rFPGA0_XB_RFInterfaceOE, rFPGA0_RFMOD
};
const u32 retryCount = 2;
u32 bbvalue;
if (t == 0) {
bbvalue = PHY_QueryBBReg(pAdapter, rFPGA0_RFMOD, bMaskDWord);
_PHY_SaveADDARegisters(pAdapter, ADDA_REG, pdmpriv->ADDA_backup, IQK_ADDA_REG_NUM);
_PHY_SaveMACRegisters(pAdapter, IQK_MAC_REG, pdmpriv->IQK_MAC_backup);
_PHY_SaveADDARegisters(pAdapter, IQK_BB_REG_92C, pdmpriv->IQK_BB_backup, IQK_BB_REG_NUM);
}
_PHY_PathADDAOn(pAdapter, ADDA_REG, true, is2T);
if (t == 0)
pdmpriv->bRfPiEnable = (u8)PHY_QueryBBReg(pAdapter, rFPGA0_XA_HSSIParameter1, BIT(8));
if (!pdmpriv->bRfPiEnable) {
_PHY_PIModeSwitch(pAdapter, true);
}
PHY_SetBBReg(pAdapter, rFPGA0_RFMOD, BIT24, 0x00);
PHY_SetBBReg(pAdapter, rOFDM0_TRxPathEnable, bMaskDWord, 0x03a05600);
PHY_SetBBReg(pAdapter, rOFDM0_TRMuxPar, bMaskDWord, 0x000800e4);
PHY_SetBBReg(pAdapter, rFPGA0_XCD_RFInterfaceSW, bMaskDWord, 0x22204000);
PHY_SetBBReg(pAdapter, rFPGA0_XAB_RFInterfaceSW, BIT10, 0x01);
PHY_SetBBReg(pAdapter, rFPGA0_XAB_RFInterfaceSW, BIT26, 0x01);
PHY_SetBBReg(pAdapter, rFPGA0_XA_RFInterfaceOE, BIT10, 0x00);
PHY_SetBBReg(pAdapter, rFPGA0_XB_RFInterfaceOE, BIT10, 0x00);
if (is2T) {
PHY_SetBBReg(pAdapter, rFPGA0_XA_LSSIParameter, bMaskDWord, 0x00010000);
PHY_SetBBReg(pAdapter, rFPGA0_XB_LSSIParameter, bMaskDWord, 0x00010000);
}
_PHY_MACSettingCalibration(pAdapter, IQK_MAC_REG, pdmpriv->IQK_MAC_backup);
PHY_SetBBReg(pAdapter, rConfig_AntA, bMaskDWord, 0x00080000);
if (is2T)
PHY_SetBBReg(pAdapter, rConfig_AntB, bMaskDWord, 0x00080000);
PHY_SetBBReg(pAdapter, rFPGA0_IQK, bMaskDWord, 0x80800000);
PHY_SetBBReg(pAdapter, rTx_IQK, bMaskDWord, 0x01007c00);
PHY_SetBBReg(pAdapter, rRx_IQK, bMaskDWord, 0x01004800);
for (i = 0 ; i < retryCount ; i++) {
PathAOK = _PHY_PathA_IQK(pAdapter, is2T);
if (PathAOK == 0x03) {
DBG_8723A("Path A IQK Success!!\n");
result[t][0] = (PHY_QueryBBReg(pAdapter, rTx_Power_Before_IQK_A, bMaskDWord)&0x3FF0000)>>16;
result[t][1] = (PHY_QueryBBReg(pAdapter, rTx_Power_After_IQK_A, bMaskDWord)&0x3FF0000)>>16;
result[t][2] = (PHY_QueryBBReg(pAdapter, rRx_Power_Before_IQK_A_2, bMaskDWord)&0x3FF0000)>>16;
result[t][3] = (PHY_QueryBBReg(pAdapter, rRx_Power_After_IQK_A_2, bMaskDWord)&0x3FF0000)>>16;
break;
} else if (i == (retryCount-1) && PathAOK == 0x01) {
DBG_8723A("Path A IQK Only Tx Success!!\n");
result[t][0] = (PHY_QueryBBReg(pAdapter, rTx_Power_Before_IQK_A, bMaskDWord)&0x3FF0000)>>16;
result[t][1] = (PHY_QueryBBReg(pAdapter, rTx_Power_After_IQK_A, bMaskDWord)&0x3FF0000)>>16;
}
}
if (0x00 == PathAOK) {
DBG_8723A("Path A IQK failed!!\n");
}
if (is2T) {
_PHY_PathAStandBy(pAdapter);
_PHY_PathADDAOn(pAdapter, ADDA_REG, false, is2T);
for (i = 0 ; i < retryCount ; i++) {
PathBOK = _PHY_PathB_IQK(pAdapter);
if (PathBOK == 0x03) {
DBG_8723A("Path B IQK Success!!\n");
result[t][4] = (PHY_QueryBBReg(pAdapter, rTx_Power_Before_IQK_B, bMaskDWord)&0x3FF0000)>>16;
result[t][5] = (PHY_QueryBBReg(pAdapter, rTx_Power_After_IQK_B, bMaskDWord)&0x3FF0000)>>16;
result[t][6] = (PHY_QueryBBReg(pAdapter, rRx_Power_Before_IQK_B_2, bMaskDWord)&0x3FF0000)>>16;
result[t][7] = (PHY_QueryBBReg(pAdapter, rRx_Power_After_IQK_B_2, bMaskDWord)&0x3FF0000)>>16;
break;
} else if (i == (retryCount - 1) && PathBOK == 0x01) {
DBG_8723A("Path B Only Tx IQK Success!!\n");
result[t][4] = (PHY_QueryBBReg(pAdapter, rTx_Power_Before_IQK_B, bMaskDWord)&0x3FF0000)>>16;
result[t][5] = (PHY_QueryBBReg(pAdapter, rTx_Power_After_IQK_B, bMaskDWord)&0x3FF0000)>>16;
}
}
if (0x00 == PathBOK) {
DBG_8723A("Path B IQK failed!!\n");
}
}
PHY_SetBBReg(pAdapter, rFPGA0_IQK, bMaskDWord, 0);
if (t != 0) {
if (!pdmpriv->bRfPiEnable) {
_PHY_PIModeSwitch(pAdapter, false);
}
_PHY_ReloadADDARegisters(pAdapter, ADDA_REG, pdmpriv->ADDA_backup, IQK_ADDA_REG_NUM);
_PHY_ReloadMACRegisters(pAdapter, IQK_MAC_REG, pdmpriv->IQK_MAC_backup);
_PHY_ReloadADDARegisters(pAdapter, IQK_BB_REG_92C, pdmpriv->IQK_BB_backup, IQK_BB_REG_NUM);
PHY_SetBBReg(pAdapter, rFPGA0_XA_LSSIParameter, bMaskDWord, 0x00032ed3);
if (is2T) {
PHY_SetBBReg(pAdapter, rFPGA0_XB_LSSIParameter, bMaskDWord, 0x00032ed3);
}
PHY_SetBBReg(pAdapter, rTx_IQK_Tone_A, bMaskDWord, 0x01008c00);
PHY_SetBBReg(pAdapter, rRx_IQK_Tone_A, bMaskDWord, 0x01008c00);
}
}
static void _PHY_LCCalibrate(struct rtw_adapter *pAdapter, bool is2T)
{
u8 tmpReg;
u32 RF_Amode = 0, RF_Bmode = 0, LC_Cal;
tmpReg = rtw_read8(pAdapter, 0xd03);
if ((tmpReg&0x70) != 0)
rtw_write8(pAdapter, 0xd03, tmpReg&0x8F);
else
rtw_write8(pAdapter, REG_TXPAUSE, 0xFF);
if ((tmpReg&0x70) != 0) {
RF_Amode = PHY_QueryRFReg(pAdapter, RF_PATH_A, RF_AC, bMask12Bits);
if (is2T)
RF_Bmode = PHY_QueryRFReg(pAdapter, RF_PATH_B, RF_AC, bMask12Bits);
PHY_SetRFReg(pAdapter, RF_PATH_A, RF_AC, bMask12Bits, (RF_Amode&0x8FFFF)|0x10000);
if (is2T)
PHY_SetRFReg(pAdapter, RF_PATH_B, RF_AC, bMask12Bits, (RF_Bmode&0x8FFFF)|0x10000);
}
LC_Cal = PHY_QueryRFReg(pAdapter, RF_PATH_A, RF_CHNLBW, bMask12Bits);
PHY_SetRFReg(pAdapter, RF_PATH_A, RF_CHNLBW, bMask12Bits, LC_Cal|0x08000);
msleep(100);
if ((tmpReg&0x70) != 0) {
rtw_write8(pAdapter, 0xd03, tmpReg);
PHY_SetRFReg(pAdapter, RF_PATH_A, RF_AC, bMask12Bits, RF_Amode);
if (is2T)
PHY_SetRFReg(pAdapter, RF_PATH_B, RF_AC, bMask12Bits, RF_Bmode);
} else {
rtw_write8(pAdapter, REG_TXPAUSE, 0x00);
}
}
void rtl8723a_phy_iq_calibrate(struct rtw_adapter *pAdapter, bool bReCovery)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(pAdapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
s32 result[4][8];
u8 i, final_candidate;
bool bPathAOK, bPathBOK;
s32 RegE94, RegE9C, RegEA4, RegEAC, RegEB4, RegEBC, RegEC4;
s32 RegECC, RegTmp = 0;
bool is12simular, is13simular, is23simular;
bool bStartContTx = false, bSingleTone = false;
bool bCarrierSuppression = false;
u32 IQK_BB_REG_92C[IQK_BB_REG_NUM] = {
rOFDM0_XARxIQImbalance, rOFDM0_XBRxIQImbalance,
rOFDM0_ECCAThreshold, rOFDM0_AGCRSSITable,
rOFDM0_XATxIQImbalance, rOFDM0_XBTxIQImbalance,
rOFDM0_XCTxAFE, rOFDM0_XDTxAFE,
rOFDM0_RxIQExtAnta
};
if (bStartContTx || bSingleTone || bCarrierSuppression)
return;
if (bReCovery) {
_PHY_ReloadADDARegisters(pAdapter, IQK_BB_REG_92C, pdmpriv->IQK_BB_backup_recover, 9);
return;
}
DBG_8723A("IQK:Start!!!\n");
for (i = 0; i < 8; i++) {
result[0][i] = 0;
result[1][i] = 0;
result[2][i] = 0;
result[3][i] = 0;
}
final_candidate = 0xff;
bPathAOK = false;
bPathBOK = false;
is12simular = false;
is23simular = false;
is13simular = false;
for (i = 0; i < 3; i++) {
if (IS_92C_SERIAL(pHalData->VersionID)) {
_PHY_IQCalibrate(pAdapter, result, i, true);
} else {
_PHY_IQCalibrate(pAdapter, result, i, false);
}
if (i == 1) {
is12simular = _PHY_SimularityCompare(pAdapter, result, 0, 1);
if (is12simular) {
final_candidate = 0;
break;
}
}
if (i == 2) {
is13simular = _PHY_SimularityCompare(pAdapter, result, 0, 2);
if (is13simular) {
final_candidate = 0;
break;
}
is23simular = _PHY_SimularityCompare(pAdapter, result, 1, 2);
if (is23simular) {
final_candidate = 1;
} else {
for (i = 0; i < 8; i++)
RegTmp += result[3][i];
if (RegTmp != 0)
final_candidate = 3;
else
final_candidate = 0xFF;
}
}
}
for (i = 0; i < 4; i++) {
RegE94 = result[i][0];
RegE9C = result[i][1];
RegEA4 = result[i][2];
RegEAC = result[i][3];
RegEB4 = result[i][4];
RegEBC = result[i][5];
RegEC4 = result[i][6];
RegECC = result[i][7];
}
if (final_candidate != 0xff) {
RegE94 = result[final_candidate][0];
pdmpriv->RegE94 = RegE94;
RegE9C = result[final_candidate][1];
pdmpriv->RegE9C = RegE9C;
RegEA4 = result[final_candidate][2];
RegEAC = result[final_candidate][3];
RegEB4 = result[final_candidate][4];
pdmpriv->RegEB4 = RegEB4;
RegEBC = result[final_candidate][5];
pdmpriv->RegEBC = RegEBC;
RegEC4 = result[final_candidate][6];
RegECC = result[final_candidate][7];
DBG_8723A("IQK: final_candidate is %x\n", final_candidate);
DBG_8723A("IQK: RegE94 =%x RegE9C =%x RegEA4 =%x RegEAC =%x RegEB4 =%x RegEBC =%x RegEC4 =%x RegECC =%x\n ",
RegE94, RegE9C, RegEA4, RegEAC, RegEB4, RegEBC, RegEC4, RegECC);
bPathAOK = bPathBOK = true;
} else {
RegE94 = RegEB4 = pdmpriv->RegE94 = pdmpriv->RegEB4 = 0x100;
RegE9C = RegEBC = pdmpriv->RegE9C = pdmpriv->RegEBC = 0x0;
}
if ((RegE94 != 0))
_PHY_PathAFillIQKMatrix(pAdapter, bPathAOK, result, final_candidate, (RegEA4 == 0));
if (IS_92C_SERIAL(pHalData->VersionID)) {
if ((RegEB4 != 0))
_PHY_PathBFillIQKMatrix(pAdapter, bPathBOK, result, final_candidate, (RegEC4 == 0));
}
_PHY_SaveADDARegisters(pAdapter, IQK_BB_REG_92C, pdmpriv->IQK_BB_backup_recover, 9);
}
void rtl8723a_phy_lc_calibrate(struct rtw_adapter *pAdapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(pAdapter);
struct mlme_ext_priv *pmlmeext = &pAdapter->mlmeextpriv;
bool bStartContTx = false, bSingleTone = false, bCarrierSuppression = false;
if (bStartContTx || bSingleTone || bCarrierSuppression)
return;
if (pmlmeext->sitesurvey_res.state == SCAN_PROCESS)
return;
if (IS_92C_SERIAL(pHalData->VersionID)) {
_PHY_LCCalibrate(pAdapter, true);
} else {
_PHY_LCCalibrate(pAdapter, false);
}
}
void
rtl8723a_phy_ap_calibrate(struct rtw_adapter *pAdapter, char delta)
{
}
