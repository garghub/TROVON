static void setIqkMatrix_8723B(
PDM_ODM_T pDM_Odm,
u8 OFDM_index,
u8 RFPath,
s32 IqkResult_X,
s32 IqkResult_Y
)
{
s32 ele_A = 0, ele_D, ele_C = 0, value32;
if (OFDM_index >= OFDM_TABLE_SIZE)
OFDM_index = OFDM_TABLE_SIZE-1;
ele_D = (OFDMSwingTable_New[OFDM_index] & 0xFFC00000)>>22;
if ((IqkResult_X != 0) && (*(pDM_Odm->pBandType) == ODM_BAND_2_4G)) {
if ((IqkResult_X & 0x00000200) != 0)
IqkResult_X = IqkResult_X | 0xFFFFFC00;
ele_A = ((IqkResult_X * ele_D)>>8)&0x000003FF;
if ((IqkResult_Y & 0x00000200) != 0)
IqkResult_Y = IqkResult_Y | 0xFFFFFC00;
ele_C = ((IqkResult_Y * ele_D)>>8)&0x000003FF;
switch (RFPath) {
case ODM_RF_PATH_A:
value32 = (ele_D<<22)|((ele_C&0x3F)<<16)|ele_A;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XATxIQImbalance, bMaskDWord, value32);
value32 = (ele_C&0x000003C0)>>6;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XCTxAFE, bMaskH4Bits, value32);
value32 = ((IqkResult_X * ele_D)>>7)&0x01;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, BIT24, value32);
break;
case ODM_RF_PATH_B:
value32 = (ele_D<<22)|((ele_C&0x3F)<<16)|ele_A;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XBTxIQImbalance, bMaskDWord, value32);
value32 = (ele_C&0x000003C0)>>6;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XDTxAFE, bMaskH4Bits, value32);
value32 = ((IqkResult_X * ele_D)>>7)&0x01;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, BIT28, value32);
break;
default:
break;
}
} else {
switch (RFPath) {
case ODM_RF_PATH_A:
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XATxIQImbalance, bMaskDWord, OFDMSwingTable_New[OFDM_index]);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XCTxAFE, bMaskH4Bits, 0x00);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, BIT24, 0x00);
break;
case ODM_RF_PATH_B:
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XBTxIQImbalance, bMaskDWord, OFDMSwingTable_New[OFDM_index]);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XDTxAFE, bMaskH4Bits, 0x00);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, BIT28, 0x00);
break;
default:
break;
}
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("TxPwrTracking path B: X = 0x%x, Y = 0x%x ele_A = 0x%x ele_C = 0x%x ele_D = 0x%x 0xeb4 = 0x%x 0xebc = 0x%x\n",
(u32)IqkResult_X, (u32)IqkResult_Y, (u32)ele_A, (u32)ele_C, (u32)ele_D, (u32)IqkResult_X, (u32)IqkResult_Y));
}
static void setCCKFilterCoefficient(PDM_ODM_T pDM_Odm, u8 CCKSwingIndex)
{
if (!pDM_Odm->RFCalibrateInfo.bCCKinCH14) {
rtw_write8(pDM_Odm->Adapter, 0xa22, CCKSwingTable_Ch1_Ch13_New[CCKSwingIndex][0]);
rtw_write8(pDM_Odm->Adapter, 0xa23, CCKSwingTable_Ch1_Ch13_New[CCKSwingIndex][1]);
rtw_write8(pDM_Odm->Adapter, 0xa24, CCKSwingTable_Ch1_Ch13_New[CCKSwingIndex][2]);
rtw_write8(pDM_Odm->Adapter, 0xa25, CCKSwingTable_Ch1_Ch13_New[CCKSwingIndex][3]);
rtw_write8(pDM_Odm->Adapter, 0xa26, CCKSwingTable_Ch1_Ch13_New[CCKSwingIndex][4]);
rtw_write8(pDM_Odm->Adapter, 0xa27, CCKSwingTable_Ch1_Ch13_New[CCKSwingIndex][5]);
rtw_write8(pDM_Odm->Adapter, 0xa28, CCKSwingTable_Ch1_Ch13_New[CCKSwingIndex][6]);
rtw_write8(pDM_Odm->Adapter, 0xa29, CCKSwingTable_Ch1_Ch13_New[CCKSwingIndex][7]);
} else {
rtw_write8(pDM_Odm->Adapter, 0xa22, CCKSwingTable_Ch14_New[CCKSwingIndex][0]);
rtw_write8(pDM_Odm->Adapter, 0xa23, CCKSwingTable_Ch14_New[CCKSwingIndex][1]);
rtw_write8(pDM_Odm->Adapter, 0xa24, CCKSwingTable_Ch14_New[CCKSwingIndex][2]);
rtw_write8(pDM_Odm->Adapter, 0xa25, CCKSwingTable_Ch14_New[CCKSwingIndex][3]);
rtw_write8(pDM_Odm->Adapter, 0xa26, CCKSwingTable_Ch14_New[CCKSwingIndex][4]);
rtw_write8(pDM_Odm->Adapter, 0xa27, CCKSwingTable_Ch14_New[CCKSwingIndex][5]);
rtw_write8(pDM_Odm->Adapter, 0xa28, CCKSwingTable_Ch14_New[CCKSwingIndex][6]);
rtw_write8(pDM_Odm->Adapter, 0xa29, CCKSwingTable_Ch14_New[CCKSwingIndex][7]);
}
}
void DoIQK_8723B(
PDM_ODM_T pDM_Odm,
u8 DeltaThermalIndex,
u8 ThermalValue,
u8 Threshold
)
{
}
void ODM_TxPwrTrackSetPwr_8723B(
PDM_ODM_T pDM_Odm,
PWRTRACK_METHOD Method,
u8 RFPath,
u8 ChannelMappedIndex
)
{
struct adapter *Adapter = pDM_Odm->Adapter;
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
u8 PwrTrackingLimit_OFDM = 34;
u8 PwrTrackingLimit_CCK = 28;
u8 TxRate = 0xFF;
u8 Final_OFDM_Swing_Index = 0;
u8 Final_CCK_Swing_Index = 0;
{
u16 rate = *(pDM_Odm->pForcedDataRate);
if (!rate) {
if (pDM_Odm->TxRate != 0xFF)
TxRate = HwRateToMRate(pDM_Odm->TxRate);
} else
TxRate = (u8)rate;
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("===>ODM_TxPwrTrackSetPwr8723B\n"));
if (TxRate != 0xFF) {
if ((TxRate >= MGN_1M) && (TxRate <= MGN_11M))
PwrTrackingLimit_CCK = 28;
else if ((TxRate >= MGN_6M) && (TxRate <= MGN_48M))
PwrTrackingLimit_OFDM = 36;
else if (TxRate == MGN_54M)
PwrTrackingLimit_OFDM = 34;
else if ((TxRate >= MGN_MCS0) && (TxRate <= MGN_MCS2))
PwrTrackingLimit_OFDM = 38;
else if ((TxRate >= MGN_MCS3) && (TxRate <= MGN_MCS4))
PwrTrackingLimit_OFDM = 36;
else if ((TxRate >= MGN_MCS5) && (TxRate <= MGN_MCS7))
PwrTrackingLimit_OFDM = 34;
else
PwrTrackingLimit_OFDM = pDM_Odm->DefaultOfdmIndex;
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("TxRate = 0x%x, PwrTrackingLimit =%d\n", TxRate, PwrTrackingLimit_OFDM));
if (Method == TXAGC) {
struct adapter *Adapter = pDM_Odm->Adapter;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("odm_TxPwrTrackSetPwr8723B CH =%d\n", *(pDM_Odm->pChannel)));
pDM_Odm->Remnant_OFDMSwingIdx[RFPath] = pDM_Odm->Absolute_OFDMSwingIdx[RFPath];
pDM_Odm->Modify_TxAGC_Flag_PathA = true;
pDM_Odm->Modify_TxAGC_Flag_PathA_CCK = true;
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, CCK);
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, OFDM);
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, HT_MCS0_MCS7);
} else if (Method == BBSWING) {
Final_OFDM_Swing_Index = pDM_Odm->DefaultOfdmIndex + pDM_Odm->Absolute_OFDMSwingIdx[RFPath];
Final_CCK_Swing_Index = pDM_Odm->DefaultCckIndex + pDM_Odm->Absolute_OFDMSwingIdx[RFPath];
if (Final_OFDM_Swing_Index >= PwrTrackingLimit_OFDM)
Final_OFDM_Swing_Index = PwrTrackingLimit_OFDM;
else if (Final_OFDM_Swing_Index <= 0)
Final_OFDM_Swing_Index = 0;
if (Final_CCK_Swing_Index >= CCK_TABLE_SIZE)
Final_CCK_Swing_Index = CCK_TABLE_SIZE-1;
else if (pDM_Odm->BbSwingIdxCck <= 0)
Final_CCK_Swing_Index = 0;
setIqkMatrix_8723B(pDM_Odm, Final_OFDM_Swing_Index, RFPath,
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[ChannelMappedIndex].Value[0][0],
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[ChannelMappedIndex].Value[0][1]);
setCCKFilterCoefficient(pDM_Odm, Final_CCK_Swing_Index);
} else if (Method == MIX_MODE) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("pDM_Odm->DefaultOfdmIndex =%d, pDM_Odm->DefaultCCKIndex =%d, pDM_Odm->Absolute_OFDMSwingIdx[RFPath]=%d, RF_Path = %d\n",
pDM_Odm->DefaultOfdmIndex, pDM_Odm->DefaultCckIndex, pDM_Odm->Absolute_OFDMSwingIdx[RFPath], RFPath));
Final_OFDM_Swing_Index = pDM_Odm->DefaultOfdmIndex + pDM_Odm->Absolute_OFDMSwingIdx[RFPath];
Final_CCK_Swing_Index = pDM_Odm->DefaultCckIndex + pDM_Odm->Absolute_OFDMSwingIdx[RFPath];
if (Final_OFDM_Swing_Index > PwrTrackingLimit_OFDM) {
pDM_Odm->Remnant_OFDMSwingIdx[RFPath] = Final_OFDM_Swing_Index - PwrTrackingLimit_OFDM;
setIqkMatrix_8723B(pDM_Odm, PwrTrackingLimit_OFDM, RFPath,
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[ChannelMappedIndex].Value[0][0],
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[ChannelMappedIndex].Value[0][1]);
pDM_Odm->Modify_TxAGC_Flag_PathA = true;
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, OFDM);
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, HT_MCS0_MCS7);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("******Path_A Over BBSwing Limit , PwrTrackingLimit = %d , Remnant TxAGC Value = %d\n",
PwrTrackingLimit_OFDM, pDM_Odm->Remnant_OFDMSwingIdx[RFPath]));
} else if (Final_OFDM_Swing_Index <= 0) {
pDM_Odm->Remnant_OFDMSwingIdx[RFPath] = Final_OFDM_Swing_Index;
setIqkMatrix_8723B(pDM_Odm, 0, RFPath,
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[ChannelMappedIndex].Value[0][0],
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[ChannelMappedIndex].Value[0][1]);
pDM_Odm->Modify_TxAGC_Flag_PathA = true;
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, OFDM);
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, HT_MCS0_MCS7);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("******Path_A Lower then BBSwing lower bound 0 , Remnant TxAGC Value = %d\n",
pDM_Odm->Remnant_OFDMSwingIdx[RFPath]));
} else {
setIqkMatrix_8723B(pDM_Odm, Final_OFDM_Swing_Index, RFPath,
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[ChannelMappedIndex].Value[0][0],
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[ChannelMappedIndex].Value[0][1]);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("******Path_A Compensate with BBSwing , Final_OFDM_Swing_Index = %d\n", Final_OFDM_Swing_Index));
if (pDM_Odm->Modify_TxAGC_Flag_PathA) {
pDM_Odm->Remnant_OFDMSwingIdx[RFPath] = 0;
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, OFDM);
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, HT_MCS0_MCS7);
pDM_Odm->Modify_TxAGC_Flag_PathA = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("******Path_A pDM_Odm->Modify_TxAGC_Flag = false\n"));
}
}
if (Final_CCK_Swing_Index > PwrTrackingLimit_CCK) {
pDM_Odm->Remnant_CCKSwingIdx = Final_CCK_Swing_Index - PwrTrackingLimit_CCK;
setCCKFilterCoefficient(pDM_Odm, PwrTrackingLimit_CCK);
pDM_Odm->Modify_TxAGC_Flag_PathA_CCK = true;
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, CCK);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("******Path_A CCK Over Limit , PwrTrackingLimit_CCK = %d , pDM_Odm->Remnant_CCKSwingIdx = %d\n", PwrTrackingLimit_CCK, pDM_Odm->Remnant_CCKSwingIdx));
} else if (Final_CCK_Swing_Index <= 0) {
pDM_Odm->Remnant_CCKSwingIdx = Final_CCK_Swing_Index;
setCCKFilterCoefficient(pDM_Odm, 0);
pDM_Odm->Modify_TxAGC_Flag_PathA_CCK = true;
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, CCK);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("******Path_A CCK Under Limit , PwrTrackingLimit_CCK = %d , pDM_Odm->Remnant_CCKSwingIdx = %d\n", 0, pDM_Odm->Remnant_CCKSwingIdx));
} else {
setCCKFilterCoefficient(pDM_Odm, Final_CCK_Swing_Index);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("******Path_A CCK Compensate with BBSwing , Final_CCK_Swing_Index = %d\n", Final_CCK_Swing_Index));
if (pDM_Odm->Modify_TxAGC_Flag_PathA_CCK) {
pDM_Odm->Remnant_CCKSwingIdx = 0;
PHY_SetTxPowerIndexByRateSection(Adapter, RFPath, pHalData->CurrentChannel, CCK);
pDM_Odm->Modify_TxAGC_Flag_PathA_CCK = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,
("******Path_A pDM_Odm->Modify_TxAGC_Flag_CCK = false\n"));
}
}
} else
return;
}
static void GetDeltaSwingTable_8723B(
PDM_ODM_T pDM_Odm,
u8 **TemperatureUP_A,
u8 **TemperatureDOWN_A,
u8 **TemperatureUP_B,
u8 **TemperatureDOWN_B
)
{
struct adapter *Adapter = pDM_Odm->Adapter;
PODM_RF_CAL_T pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
u16 rate = *(pDM_Odm->pForcedDataRate);
u8 channel = pHalData->CurrentChannel;
if (1 <= channel && channel <= 14) {
if (IS_CCK_RATE(rate)) {
*TemperatureUP_A = pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_P;
*TemperatureDOWN_A = pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_N;
*TemperatureUP_B = pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_P;
*TemperatureDOWN_B = pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_N;
} else {
*TemperatureUP_A = pRFCalibrateInfo->DeltaSwingTableIdx_2GA_P;
*TemperatureDOWN_A = pRFCalibrateInfo->DeltaSwingTableIdx_2GA_N;
*TemperatureUP_B = pRFCalibrateInfo->DeltaSwingTableIdx_2GB_P;
*TemperatureDOWN_B = pRFCalibrateInfo->DeltaSwingTableIdx_2GB_N;
}
} else {
*TemperatureUP_A = (u8 *)DeltaSwingTableIdx_2GA_P_8188E;
*TemperatureDOWN_A = (u8 *)DeltaSwingTableIdx_2GA_N_8188E;
*TemperatureUP_B = (u8 *)DeltaSwingTableIdx_2GA_P_8188E;
*TemperatureDOWN_B = (u8 *)DeltaSwingTableIdx_2GA_N_8188E;
}
return;
}
void ConfigureTxpowerTrack_8723B(PTXPWRTRACK_CFG pConfig)
{
pConfig->SwingTableSize_CCK = CCK_TABLE_SIZE;
pConfig->SwingTableSize_OFDM = OFDM_TABLE_SIZE;
pConfig->Threshold_IQK = IQK_THRESHOLD;
pConfig->AverageThermalNum = AVG_THERMAL_NUM_8723B;
pConfig->RfPathCount = MAX_PATH_NUM_8723B;
pConfig->ThermalRegAddr = RF_T_METER_8723B;
pConfig->ODM_TxPwrTrackSetPwr = ODM_TxPwrTrackSetPwr_8723B;
pConfig->DoIQK = DoIQK_8723B;
pConfig->PHY_LCCalibrate = PHY_LCCalibrate_8723B;
pConfig->GetDeltaSwingTable = GetDeltaSwingTable_8723B;
}
static u8 phy_PathA_IQK_8723B(
struct adapter *padapter, bool configPathB, u8 RF_Path
)
{
u32 regEAC, regE94, regE9C, tmp, Path_SEL_BB ;
u8 result = 0x00;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
Path_SEL_BB = PHY_QueryBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A IQK!\n"));
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_WE_LUT, 0x80000, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_RCK_OS, bRFRegOffsetMask, 0x18000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G1, bRFRegOffsetMask, 0x0003f);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G2, bRFRegOffsetMask, 0xc7f87);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK, bMaskDWord, 0x01007c00);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK, bMaskDWord, 0x01004800);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_A, bMaskDWord, 0x18008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_A, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_A, bMaskDWord, 0x821303ea);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_A, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_B, bMaskDWord, 0x82110000);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_B, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Rsp, bMaskDWord, 0x00462911);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x808000);
if (configPathB || (RF_Path == 0))
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000000);
else
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00000800);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf9000000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf8000000);
mdelay(IQK_DELAY_TIME_8723B);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, Path_SEL_BB);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00001800);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
regEAC = PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_After_IQK_A_2, bMaskDWord);
regE94 = PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_Before_IQK_A, bMaskDWord);
regE9C = PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_After_IQK_A, bMaskDWord);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xeac = 0x%x\n", regEAC));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe94 = 0x%x, 0xe9c = 0x%x\n", regE94, regE9C));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe90(before IQK) = 0x%x, 0xe98(afer IQK) = 0x%x\n",
PHY_QueryBBReg(pDM_Odm->Adapter, 0xe90, bMaskDWord), PHY_QueryBBReg(pDM_Odm->Adapter, 0xe98, bMaskDWord)));
tmp = (regE9C & 0x03FF0000)>>16;
if ((tmp & 0x200) > 0)
tmp = 0x400 - tmp;
if (
!(regEAC & BIT28) &&
(((regE94 & 0x03FF0000)>>16) != 0x142) &&
(((regE9C & 0x03FF0000)>>16) != 0x42) &&
(((regE94 & 0x03FF0000)>>16) < 0x110) &&
(((regE94 & 0x03FF0000)>>16) > 0xf0) &&
(tmp < 0xf)
)
result |= 0x01;
else
return result;
return result;
}
static u8 phy_PathA_RxIQK8723B(
struct adapter *padapter, bool configPathB, u8 RF_Path
)
{
u32 regEAC, regE94, regE9C, regEA4, u4tmp, tmp, Path_SEL_BB;
u8 result = 0x00;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
Path_SEL_BB = PHY_QueryBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A RX IQK:Get TXIMR setting\n"));
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_WE_LUT, 0x80000, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_RCK_OS, bRFRegOffsetMask, 0x18000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G1, bRFRegOffsetMask, 0x0001f);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G2, bRFRegOffsetMask, 0xf7fb7);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x808000);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK, bMaskDWord, 0x01007c00);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK, bMaskDWord, 0x01004800);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_A, bMaskDWord, 0x18008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_A, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_A, bMaskDWord, 0x82130ff0);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_A, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_B, bMaskDWord, 0x82110000);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_B, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Rsp, bMaskDWord, 0x0046a911);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x808000);
if (configPathB || (RF_Path == 0))
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000000);
else
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00000800);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf9000000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf8000000);
mdelay(IQK_DELAY_TIME_8723B);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, Path_SEL_BB);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00001800);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
regEAC = PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_After_IQK_A_2, bMaskDWord);
regE94 = PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_Before_IQK_A, bMaskDWord);
regE9C = PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_After_IQK_A, bMaskDWord);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xeac = 0x%x\n", regEAC));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe94 = 0x%x, 0xe9c = 0x%x\n", regE94, regE9C));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe90(before IQK) = 0x%x, 0xe98(afer IQK) = 0x%x\n",
PHY_QueryBBReg(pDM_Odm->Adapter, 0xe90, bMaskDWord), PHY_QueryBBReg(pDM_Odm->Adapter, 0xe98, bMaskDWord)));
tmp = (regE9C & 0x03FF0000)>>16;
if ((tmp & 0x200) > 0)
tmp = 0x400 - tmp;
if (
!(regEAC & BIT28) &&
(((regE94 & 0x03FF0000)>>16) != 0x142) &&
(((regE9C & 0x03FF0000)>>16) != 0x42) &&
(((regE94 & 0x03FF0000)>>16) < 0x110) &&
(((regE94 & 0x03FF0000)>>16) > 0xf0) &&
(tmp < 0xf)
)
result |= 0x01;
else
return result;
u4tmp = 0x80007C00 | (regE94&0x3FF0000) | ((regE9C&0x3FF0000) >> 16);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK, bMaskDWord, u4tmp);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe40 = 0x%x u4tmp = 0x%x\n", PHY_QueryBBReg(pDM_Odm->Adapter, rTx_IQK, bMaskDWord), u4tmp));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A RX IQK\n"));
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_WE_LUT, 0x80000, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_RCK_OS, bRFRegOffsetMask, 0x18000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G1, bRFRegOffsetMask, 0x0001f);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G2, bRFRegOffsetMask, 0xf7d77);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xdf, bRFRegOffsetMask, 0xf80);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0x55, bRFRegOffsetMask, 0x4021f);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK, bMaskDWord, 0x01004800);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_A, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_A, bMaskDWord, 0x18008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_A, bMaskDWord, 0x82110000);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_A, bMaskDWord, 0x2813001f);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_B, bMaskDWord, 0x82110000);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_B, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Rsp, bMaskDWord, 0x0046a8d1);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x808000);
if (configPathB || (RF_Path == 0))
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000000);
else
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00000800);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf9000000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf8000000);
mdelay(IQK_DELAY_TIME_8723B);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, Path_SEL_BB);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00001800);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
regEAC = PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_After_IQK_A_2, bMaskDWord);
regEA4 = PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_Before_IQK_A_2, bMaskDWord);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xeac = 0x%x\n", regEAC));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xea4 = 0x%x, 0xeac = 0x%x\n", regEA4, regEAC));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xea0(before IQK) = 0x%x, 0xea8(afer IQK) = 0x%x\n",
PHY_QueryBBReg(pDM_Odm->Adapter, 0xea0, bMaskDWord), PHY_QueryBBReg(pDM_Odm->Adapter, 0xea8, bMaskDWord)));
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xdf, bRFRegOffsetMask, 0x780);
tmp = (regEAC & 0x03FF0000)>>16;
if ((tmp & 0x200) > 0)
tmp = 0x400 - tmp;
if (
!(regEAC & BIT27) &&
(((regEA4 & 0x03FF0000)>>16) != 0x132) &&
(((regEAC & 0x03FF0000)>>16) != 0x36) &&
(((regEA4 & 0x03FF0000)>>16) < 0x110) &&
(((regEA4 & 0x03FF0000)>>16) > 0xf0) &&
(tmp < 0xf)
)
result |= 0x02;
else
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A Rx IQK fail!!\n"));
return result;
}
static u8 phy_PathB_IQK_8723B(struct adapter *padapter)
{
u32 regEAC, regE94, regE9C, tmp, Path_SEL_BB;
u8 result = 0x00;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B IQK!\n"));
Path_SEL_BB = PHY_QueryBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xed, 0x20, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0x43, bRFRegOffsetMask, 0x30fc1);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK, bMaskDWord, 0x01007c00);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK, bMaskDWord, 0x01004800);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_A, bMaskDWord, 0x18008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_A, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_A, bMaskDWord, 0x821303ea);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_A, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_B, bMaskDWord, 0x82110000);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_B, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Rsp, bMaskDWord, 0x00462911);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x808000);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00000800);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf9000000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf8000000);
mdelay(IQK_DELAY_TIME_8723B);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, Path_SEL_BB);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00001800);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
regEAC = PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_After_IQK_A_2, bMaskDWord);
regE94 = PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_Before_IQK_A, bMaskDWord);
regE9C = PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_After_IQK_A, bMaskDWord);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xeac = 0x%x\n", regEAC));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe94 = 0x%x, 0xe9c = 0x%x\n", regE94, regE9C));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe90(before IQK) = 0x%x, 0xe98(afer IQK) = 0x%x\n",
PHY_QueryBBReg(pDM_Odm->Adapter, 0xe90, bMaskDWord), PHY_QueryBBReg(pDM_Odm->Adapter, 0xe98, bMaskDWord)));
tmp = (regE9C & 0x03FF0000)>>16;
if ((tmp & 0x200) > 0)
tmp = 0x400 - tmp;
if (
!(regEAC & BIT28) &&
(((regE94 & 0x03FF0000)>>16) != 0x142) &&
(((regE9C & 0x03FF0000)>>16) != 0x42) &&
(((regE94 & 0x03FF0000)>>16) < 0x110) &&
(((regE94 & 0x03FF0000)>>16) > 0xf0) &&
(tmp < 0xf)
)
result |= 0x01;
return result;
}
static u8 phy_PathB_RxIQK8723B(struct adapter *padapter, bool configPathB)
{
u32 regE94, regE9C, regEA4, regEAC, u4tmp, tmp, Path_SEL_BB;
u8 result = 0x00;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
Path_SEL_BB = PHY_QueryBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B RX IQK:Get TXIMR setting!\n"));
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_WE_LUT, 0x80000, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_RCK_OS, bRFRegOffsetMask, 0x18000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G1, bRFRegOffsetMask, 0x0001f);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G2, bRFRegOffsetMask, 0xf7fb7);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xed, 0x20, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0x43, bRFRegOffsetMask, 0x30fcd);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK, bMaskDWord, 0x01007c00);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK, bMaskDWord, 0x01004800);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_A, bMaskDWord, 0x18008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_A, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_A, bMaskDWord, 0x82130ff0);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_A, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_B, bMaskDWord, 0x82110000);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_B, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Rsp, bMaskDWord, 0x0046a911);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x808000);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00000800);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf9000000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf8000000);
mdelay(IQK_DELAY_TIME_8723B);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, Path_SEL_BB);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00001800);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
regEAC = PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_After_IQK_A_2, bMaskDWord);
regE94 = PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_Before_IQK_A, bMaskDWord);
regE9C = PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_After_IQK_A, bMaskDWord);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xeac = 0x%x\n", regEAC));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe94 = 0x%x, 0xe9c = 0x%x\n", regE94, regE9C));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe90(before IQK) = 0x%x, 0xe98(afer IQK) = 0x%x\n",
PHY_QueryBBReg(pDM_Odm->Adapter, 0xe90, bMaskDWord), PHY_QueryBBReg(pDM_Odm->Adapter, 0xe98, bMaskDWord)));
tmp = (regE9C & 0x03FF0000)>>16;
if ((tmp & 0x200) > 0)
tmp = 0x400 - tmp;
if (
!(regEAC & BIT28) &&
(((regE94 & 0x03FF0000)>>16) != 0x142) &&
(((regE9C & 0x03FF0000)>>16) != 0x42) &&
(((regE94 & 0x03FF0000)>>16) < 0x110) &&
(((regE94 & 0x03FF0000)>>16) > 0xf0) &&
(tmp < 0xf)
)
result |= 0x01;
else
return result;
u4tmp = 0x80007C00 | (regE94&0x3FF0000) | ((regE9C&0x3FF0000) >> 16);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK, bMaskDWord, u4tmp);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xe40 = 0x%x u4tmp = 0x%x\n", PHY_QueryBBReg(pDM_Odm->Adapter, rTx_IQK, bMaskDWord), u4tmp));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B RX IQK\n"));
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_WE_LUT, 0x80000, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_RCK_OS, bRFRegOffsetMask, 0x18000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G1, bRFRegOffsetMask, 0x0001f);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G2, bRFRegOffsetMask, 0xf7d77);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xed, 0x20, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0x43, bRFRegOffsetMask, 0x30ebd);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK, bMaskDWord, 0x01004800);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_A, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_A, bMaskDWord, 0x18008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_B, bMaskDWord, 0x38008c1c);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_A, bMaskDWord, 0x82110000);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_A, bMaskDWord, 0x2813001f);
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_PI_B, bMaskDWord, 0x82110000);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_PI_B, bMaskDWord, 0x28110000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Rsp, bMaskDWord, 0x0046a8d1);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x808000);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, 0x00000280);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00000800);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf9000000);
PHY_SetBBReg(pDM_Odm->Adapter, rIQK_AGC_Pts, bMaskDWord, 0xf8000000);
mdelay(IQK_DELAY_TIME_8723B);
PHY_SetBBReg(pDM_Odm->Adapter, 0x948, bMaskDWord, Path_SEL_BB);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, 0x00001800);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
regEAC = PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_After_IQK_A_2, bMaskDWord);
regEA4 = PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_Before_IQK_A_2, bMaskDWord);;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xeac = 0x%x\n", regEAC));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xea4 = 0x%x, 0xeac = 0x%x\n", regEA4, regEAC));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("0xea0(before IQK) = 0x%x, 0xea8(afer IQK) = 0x%x\n",
PHY_QueryBBReg(pDM_Odm->Adapter, 0xea0, bMaskDWord), PHY_QueryBBReg(pDM_Odm->Adapter, 0xea8, bMaskDWord)));
tmp = (regEAC & 0x03FF0000)>>16;
if ((tmp & 0x200) > 0)
tmp = 0x400 - tmp;
if (
!(regEAC & BIT27) &&
(((regEA4 & 0x03FF0000)>>16) != 0x132) &&
(((regEAC & 0x03FF0000)>>16) != 0x36) &&
(((regEA4 & 0x03FF0000)>>16) < 0x110) &&
(((regEA4 & 0x03FF0000)>>16) > 0xf0) &&
(tmp < 0xf)
)
result |= 0x02;
else
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B Rx IQK fail!!\n"));
return result;
}
static void _PHY_PathAFillIQKMatrix8723B(
struct adapter *padapter,
bool bIQKOK,
s32 result[][8],
u8 final_candidate,
bool bTxOnly
)
{
u32 Oldval_0, X, TX0_A, reg;
s32 Y, TX0_C;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
PODM_RF_CAL_T pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A IQ Calibration %s !\n", (bIQKOK)?"Success":"Failed"));
if (final_candidate == 0xFF)
return;
else if (bIQKOK) {
Oldval_0 = (PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_XATxIQImbalance, bMaskDWord) >> 22) & 0x3FF;
X = result[final_candidate][0];
if ((X & 0x00000200) != 0)
X = X | 0xFFFFFC00;
TX0_A = (X * Oldval_0) >> 8;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("X = 0x%x, TX0_A = 0x%x, Oldval_0 0x%x\n", X, TX0_A, Oldval_0));
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XATxIQImbalance, 0x3FF, TX0_A);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, BIT(31), ((X*Oldval_0>>7) & 0x1));
Y = result[final_candidate][1];
if ((Y & 0x00000200) != 0)
Y = Y | 0xFFFFFC00;
TX0_C = (Y * Oldval_0) >> 8;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Y = 0x%x, TX = 0x%x\n", Y, TX0_C));
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XCTxAFE, 0xF0000000, ((TX0_C&0x3C0)>>6));
pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC94][KEY] = rOFDM0_XCTxAFE;
pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC94][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_XCTxAFE, bMaskDWord);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XATxIQImbalance, 0x003F0000, (TX0_C&0x3F));
pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC80][KEY] = rOFDM0_XATxIQImbalance;
pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC80][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_XATxIQImbalance, bMaskDWord);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, BIT(29), ((Y*Oldval_0>>7) & 0x1));
pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC4C][KEY] = rOFDM0_ECCAThreshold;
pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC4C][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, bMaskDWord);
if (bTxOnly) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("_PHY_PathAFillIQKMatrix8723B only Tx OK\n"));
pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xCA0][KEY] = rOFDM0_RxIQExtAnta;
pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xCA0][VAL] = 0xfffffff & PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_RxIQExtAnta, bMaskDWord);
pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xC14][KEY] = rOFDM0_XARxIQImbalance;
pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xC14][VAL] = 0x40000100;
return;
}
reg = result[final_candidate][2];
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XARxIQImbalance, 0x3FF, reg);
reg = result[final_candidate][3] & 0x3F;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XARxIQImbalance, 0xFC00, reg);
pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xC14][KEY] = rOFDM0_XARxIQImbalance;
pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xC14][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_XARxIQImbalance, bMaskDWord);
reg = (result[final_candidate][3] >> 6) & 0xF;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_RxIQExtAnta, 0xF0000000, reg);
pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xCA0][KEY] = rOFDM0_RxIQExtAnta;
pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xCA0][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_RxIQExtAnta, bMaskDWord);
}
}
static void _PHY_PathBFillIQKMatrix8723B(
struct adapter *padapter,
bool bIQKOK,
s32 result[][8],
u8 final_candidate,
bool bTxOnly
)
{
u32 Oldval_1, X, TX1_A, reg;
s32 Y, TX1_C;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
PODM_RF_CAL_T pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B IQ Calibration %s !\n", (bIQKOK)?"Success":"Failed"));
if (final_candidate == 0xFF)
return;
else if (bIQKOK) {
Oldval_1 = (PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_XBTxIQImbalance, bMaskDWord) >> 22) & 0x3FF;
X = result[final_candidate][4];
if ((X & 0x00000200) != 0)
X = X | 0xFFFFFC00;
TX1_A = (X * Oldval_1) >> 8;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("X = 0x%x, TX1_A = 0x%x\n", X, TX1_A));
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XBTxIQImbalance, 0x3FF, TX1_A);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, BIT(27), ((X*Oldval_1>>7) & 0x1));
Y = result[final_candidate][5];
if ((Y & 0x00000200) != 0)
Y = Y | 0xFFFFFC00;
TX1_C = (Y * Oldval_1) >> 8;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Y = 0x%x, TX1_C = 0x%x\n", Y, TX1_C));
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XDTxAFE, 0xF0000000, ((TX1_C&0x3C0)>>6));
pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC94][KEY] = rOFDM0_XCTxAFE;
pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC94][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_XDTxAFE, bMaskDWord);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XBTxIQImbalance, 0x003F0000, (TX1_C&0x3F));
pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC80][KEY] = rOFDM0_XATxIQImbalance;
pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC80][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_XBTxIQImbalance, bMaskDWord);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, BIT(25), ((Y*Oldval_1>>7) & 0x1));
pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC4C][KEY] = rOFDM0_ECCAThreshold;
pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC4C][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_ECCAThreshold, bMaskDWord);
if (bTxOnly) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("_PHY_PathBFillIQKMatrix8723B only Tx OK\n"));
pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xC14][KEY] = rOFDM0_XARxIQImbalance;
pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xC14][VAL] = 0x40000100;
pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xCA0][KEY] = rOFDM0_RxIQExtAnta;
pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xCA0][VAL] = 0x0fffffff & PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_RxIQExtAnta, bMaskDWord);
return;
}
reg = result[final_candidate][6];
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XBRxIQImbalance, 0x3FF, reg);
reg = result[final_candidate][7] & 0x3F;
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_XBRxIQImbalance, 0xFC00, reg);
pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xC14][KEY] = rOFDM0_XARxIQImbalance;
pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xC14][VAL] = PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_XBRxIQImbalance, bMaskDWord);
reg = (result[final_candidate][7] >> 6) & 0xF;
pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xCA0][KEY] = rOFDM0_RxIQExtAnta;
pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xCA0][VAL] = (reg << 28)|(PHY_QueryBBReg(pDM_Odm->Adapter, rOFDM0_RxIQExtAnta, bMaskDWord)&0x0fffffff);
}
}
void ODM_SetIQCbyRFpath(PDM_ODM_T pDM_Odm, u32 RFpath)
{
PODM_RF_CAL_T pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);
if (
(pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC80][VAL] != 0x0) &&
(pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xC14][VAL] != 0x0) &&
(pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC80][VAL] != 0x0) &&
(pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xC14][VAL] != 0x0)
) {
if (RFpath) {
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC94][KEY], bMaskDWord, pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC94][VAL]);
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC80][KEY], bMaskDWord, pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC80][VAL]);
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC4C][KEY], bMaskDWord, pRFCalibrateInfo->TxIQC_8723B[PATH_S0][IDX_0xC4C][VAL]);
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xC14][KEY], bMaskDWord, pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xC14][VAL]);
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xCA0][KEY], bMaskDWord, pRFCalibrateInfo->RxIQC_8723B[PATH_S0][IDX_0xCA0][VAL]);
} else {
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC94][KEY], bMaskDWord, pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC94][VAL]);
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC80][KEY], bMaskDWord, pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC80][VAL]);
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC4C][KEY], bMaskDWord, pRFCalibrateInfo->TxIQC_8723B[PATH_S1][IDX_0xC4C][VAL]);
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xC14][KEY], bMaskDWord, pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xC14][VAL]);
PHY_SetBBReg(pDM_Odm->Adapter, pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xCA0][KEY], bMaskDWord, pRFCalibrateInfo->RxIQC_8723B[PATH_S1][IDX_0xCA0][VAL]);
}
}
}
static bool ODM_CheckPowerStatus(struct adapter *Adapter)
{
return true;
}
static void _PHY_SaveADDARegisters8723B(
struct adapter *padapter,
u32 *ADDAReg,
u32 *ADDABackup,
u32 RegisterNum
)
{
u32 i;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
if (ODM_CheckPowerStatus(padapter) == false)
return;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Save ADDA parameters.\n"));
for (i = 0 ; i < RegisterNum ; i++) {
ADDABackup[i] = PHY_QueryBBReg(pDM_Odm->Adapter, ADDAReg[i], bMaskDWord);
}
}
static void _PHY_SaveMACRegisters8723B(
struct adapter *padapter, u32 *MACReg, u32 *MACBackup
)
{
u32 i;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Save MAC parameters.\n"));
for (i = 0 ; i < (IQK_MAC_REG_NUM - 1); i++) {
MACBackup[i] = rtw_read8(pDM_Odm->Adapter, MACReg[i]);
}
MACBackup[i] = rtw_read32(pDM_Odm->Adapter, MACReg[i]);
}
static void _PHY_ReloadADDARegisters8723B(
struct adapter *padapter,
u32 *ADDAReg,
u32 *ADDABackup,
u32 RegiesterNum
)
{
u32 i;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Reload ADDA power saving parameters !\n"));
for (i = 0 ; i < RegiesterNum; i++) {
PHY_SetBBReg(pDM_Odm->Adapter, ADDAReg[i], bMaskDWord, ADDABackup[i]);
}
}
static void _PHY_ReloadMACRegisters8723B(
struct adapter *padapter, u32 *MACReg, u32 *MACBackup
)
{
u32 i;
for (i = 0 ; i < (IQK_MAC_REG_NUM - 1); i++) {
rtw_write8(padapter, MACReg[i], (u8)MACBackup[i]);
}
rtw_write32(padapter, MACReg[i], MACBackup[i]);
}
static void _PHY_PathADDAOn8723B(
struct adapter *padapter,
u32 *ADDAReg,
bool isPathAOn,
bool is2T
)
{
u32 pathOn;
u32 i;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("ADDA ON.\n"));
pathOn = isPathAOn ? 0x01c00014 : 0x01c00014;
if (false == is2T) {
pathOn = 0x01c00014;
PHY_SetBBReg(pDM_Odm->Adapter, ADDAReg[0], bMaskDWord, 0x01c00014);
} else {
PHY_SetBBReg(pDM_Odm->Adapter, ADDAReg[0], bMaskDWord, pathOn);
}
for (i = 1 ; i < IQK_ADDA_REG_NUM ; i++) {
PHY_SetBBReg(pDM_Odm->Adapter, ADDAReg[i], bMaskDWord, pathOn);
}
}
static void _PHY_MACSettingCalibration8723B(
struct adapter *padapter, u32 *MACReg, u32 *MACBackup
)
{
u32 i = 0;
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("MAC settings for Calibration.\n"));
rtw_write8(pDM_Odm->Adapter, MACReg[i], 0x3F);
for (i = 1 ; i < (IQK_MAC_REG_NUM - 1); i++) {
rtw_write8(pDM_Odm->Adapter, MACReg[i], (u8)(MACBackup[i]&(~BIT3)));
}
rtw_write8(pDM_Odm->Adapter, MACReg[i], (u8)(MACBackup[i]&(~BIT5)));
}
static bool phy_SimularityCompare_8723B(
struct adapter *padapter,
s32 result[][8],
u8 c1,
u8 c2
)
{
u32 i, j, diff, SimularityBitMap, bound = 0;
u8 final_candidate[2] = {0xFF, 0xFF};
bool bResult = true;
bool is2T = true;
s32 tmp1 = 0, tmp2 = 0;
if (is2T)
bound = 8;
else
bound = 4;
SimularityBitMap = 0;
for (i = 0; i < bound; i++) {
if ((i == 1) || (i == 3) || (i == 5) || (i == 7)) {
if ((result[c1][i] & 0x00000200) != 0)
tmp1 = result[c1][i] | 0xFFFFFC00;
else
tmp1 = result[c1][i];
if ((result[c2][i] & 0x00000200) != 0)
tmp2 = result[c2][i] | 0xFFFFFC00;
else
tmp2 = result[c2][i];
} else {
tmp1 = result[c1][i];
tmp2 = result[c2][i];
}
diff = (tmp1 > tmp2) ? (tmp1 - tmp2) : (tmp2 - tmp1);
if (diff > MAX_TOLERANCE) {
if ((i == 2 || i == 6) && !SimularityBitMap) {
if (result[c1][i]+result[c1][i+1] == 0)
final_candidate[(i/4)] = c2;
else if (result[c2][i]+result[c2][i+1] == 0)
final_candidate[(i/4)] = c1;
else
SimularityBitMap = SimularityBitMap|(1<<i);
} else
SimularityBitMap = SimularityBitMap|(1<<i);
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
} else {
if (!(SimularityBitMap & 0x03)) {
for (i = 0; i < 2; i++)
result[3][i] = result[c1][i];
}
if (!(SimularityBitMap & 0x0c)) {
for (i = 2; i < 4; i++)
result[3][i] = result[c1][i];
}
if (!(SimularityBitMap & 0x30)) {
for (i = 4; i < 6; i++)
result[3][i] = result[c1][i];
}
if (!(SimularityBitMap & 0xc0)) {
for (i = 6; i < 8; i++)
result[3][i] = result[c1][i];
}
return false;
}
}
static void phy_IQCalibrate_8723B(
struct adapter *padapter,
s32 result[][8],
u8 t,
bool is2T,
u8 RF_Path
)
{
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
u32 i;
u8 PathAOK, PathBOK;
u8 tmp0xc50 = (u8)PHY_QueryBBReg(pDM_Odm->Adapter, 0xC50, bMaskByte0);
u8 tmp0xc58 = (u8)PHY_QueryBBReg(pDM_Odm->Adapter, 0xC58, bMaskByte0);
u32 ADDA_REG[IQK_ADDA_REG_NUM] = {
rFPGA0_XCD_SwitchControl,
rBlue_Tooth,
rRx_Wait_CCA,
rTx_CCK_RFON,
rTx_CCK_BBON,
rTx_OFDM_RFON,
rTx_OFDM_BBON,
rTx_To_Rx,
rTx_To_Tx,
rRx_CCK,
rRx_OFDM,
rRx_Wait_RIFS,
rRx_TO_Rx,
rStandby,
rSleep,
rPMPD_ANAEN
};
u32 IQK_MAC_REG[IQK_MAC_REG_NUM] = {
REG_TXPAUSE,
REG_BCN_CTRL,
REG_BCN_CTRL_1,
REG_GPIO_MUXCFG
};
u32 IQK_BB_REG_92C[IQK_BB_REG_NUM] = {
rOFDM0_TRxPathEnable,
rOFDM0_TRMuxPar,
rFPGA0_XCD_RFInterfaceSW,
rConfig_AntA,
rConfig_AntB,
rFPGA0_XAB_RFInterfaceSW,
rFPGA0_XA_RFInterfaceOE,
rFPGA0_XB_RFInterfaceOE,
rCCK0_AFESetting
};
const u32 retryCount = 2;
if (t == 0) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQ Calibration for %s for %d times\n", (is2T ? "2T2R" : "1T1R"), t));
_PHY_SaveADDARegisters8723B(padapter, ADDA_REG, pDM_Odm->RFCalibrateInfo.ADDA_backup, IQK_ADDA_REG_NUM);
_PHY_SaveMACRegisters8723B(padapter, IQK_MAC_REG, pDM_Odm->RFCalibrateInfo.IQK_MAC_backup);
_PHY_SaveADDARegisters8723B(padapter, IQK_BB_REG_92C, pDM_Odm->RFCalibrateInfo.IQK_BB_backup, IQK_BB_REG_NUM);
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQ Calibration for %s for %d times\n", (is2T ? "2T2R" : "1T1R"), t));
_PHY_PathADDAOn8723B(padapter, ADDA_REG, true, is2T);
_PHY_MACSettingCalibration8723B(padapter, IQK_MAC_REG, pDM_Odm->RFCalibrateInfo.IQK_MAC_backup);
PHY_SetBBReg(pDM_Odm->Adapter, rCCK0_AFESetting, 0x0f000000, 0xf);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_TRxPathEnable, bMaskDWord, 0x03a05600);
PHY_SetBBReg(pDM_Odm->Adapter, rOFDM0_TRMuxPar, bMaskDWord, 0x000800e4);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_XCD_RFInterfaceSW, bMaskDWord, 0x22204000);
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_WE_LUT, 0x80000, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_RCK_OS, bRFRegOffsetMask, 0x30000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G1, bRFRegOffsetMask, 0x0001f);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G2, bRFRegOffsetMask, 0xf7fb7);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xed, 0x20, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0x43, bRFRegOffsetMask, 0x60fbd);
for (i = 0 ; i < retryCount ; i++) {
PathAOK = phy_PathA_IQK_8723B(padapter, is2T, RF_Path);
if (PathAOK == 0x01) {
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
pDM_Odm->RFCalibrateInfo.TxLOK[ODM_RF_PATH_A] = PHY_QueryRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0x8, bRFRegOffsetMask);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A Tx IQK Success!!\n"));
result[t][0] = (PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_Before_IQK_A, bMaskDWord)&0x3FF0000)>>16;
result[t][1] = (PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_After_IQK_A, bMaskDWord)&0x3FF0000)>>16;
break;
}
}
for (i = 0 ; i < retryCount ; i++) {
PathAOK = phy_PathA_RxIQK8723B(padapter, is2T, RF_Path);
if (PathAOK == 0x03) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A Rx IQK Success!!\n"));
result[t][2] = (PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_Before_IQK_A_2, bMaskDWord)&0x3FF0000)>>16;
result[t][3] = (PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_After_IQK_A_2, bMaskDWord)&0x3FF0000)>>16;
break;
} else {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A Rx IQK Fail!!\n"));
}
}
if (0x00 == PathAOK) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path A IQK failed!!\n"));
}
if (is2T) {
for (i = 0 ; i < retryCount ; i++) {
PathBOK = phy_PathB_IQK_8723B(padapter);
if (PathBOK == 0x01) {
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0x000000);
pDM_Odm->RFCalibrateInfo.TxLOK[ODM_RF_PATH_B] = PHY_QueryRFReg(pDM_Odm->Adapter, ODM_RF_PATH_B, 0x8, bRFRegOffsetMask);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B Tx IQK Success!!\n"));
result[t][4] = (PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_Before_IQK_A, bMaskDWord)&0x3FF0000)>>16;
result[t][5] = (PHY_QueryBBReg(pDM_Odm->Adapter, rTx_Power_After_IQK_A, bMaskDWord)&0x3FF0000)>>16;
break;
}
}
for (i = 0 ; i < retryCount ; i++) {
PathBOK = phy_PathB_RxIQK8723B(padapter, is2T);
if (PathBOK == 0x03) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B Rx IQK Success!!\n"));
result[t][6] = (PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_Before_IQK_A_2, bMaskDWord)&0x3FF0000)>>16;
result[t][7] = (PHY_QueryBBReg(pDM_Odm->Adapter, rRx_Power_After_IQK_A_2, bMaskDWord)&0x3FF0000)>>16;
break;
} else {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B Rx IQK Fail!!\n"));
}
}
if (0x00 == PathBOK) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("Path B IQK failed!!\n"));
}
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK:Back to BB mode, load original value!\n"));
PHY_SetBBReg(pDM_Odm->Adapter, rFPGA0_IQK, bMaskH3Bytes, 0);
if (t != 0) {
_PHY_ReloadADDARegisters8723B(padapter, ADDA_REG, pDM_Odm->RFCalibrateInfo.ADDA_backup, IQK_ADDA_REG_NUM);
_PHY_ReloadMACRegisters8723B(padapter, IQK_MAC_REG, pDM_Odm->RFCalibrateInfo.IQK_MAC_backup);
_PHY_ReloadADDARegisters8723B(padapter, IQK_BB_REG_92C, pDM_Odm->RFCalibrateInfo.IQK_BB_backup, IQK_BB_REG_NUM);
PHY_SetBBReg(pDM_Odm->Adapter, 0xc50, bMaskByte0, 0x50);
PHY_SetBBReg(pDM_Odm->Adapter, 0xc50, bMaskByte0, tmp0xc50);
if (is2T) {
PHY_SetBBReg(pDM_Odm->Adapter, 0xc58, bMaskByte0, 0x50);
PHY_SetBBReg(pDM_Odm->Adapter, 0xc58, bMaskByte0, tmp0xc58);
}
PHY_SetBBReg(pDM_Odm->Adapter, rTx_IQK_Tone_A, bMaskDWord, 0x01008c00);
PHY_SetBBReg(pDM_Odm->Adapter, rRx_IQK_Tone_A, bMaskDWord, 0x01008c00);
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("phy_IQCalibrate_8723B() <==\n"));
}
static void phy_LCCalibrate_8723B(PDM_ODM_T pDM_Odm, bool is2T)
{
u8 tmpReg;
u32 RF_Amode = 0, RF_Bmode = 0, LC_Cal;
struct adapter *padapter = pDM_Odm->Adapter;
tmpReg = rtw_read8(pDM_Odm->Adapter, 0xd03);
if ((tmpReg&0x70) != 0)
rtw_write8(pDM_Odm->Adapter, 0xd03, tmpReg&0x8F);
else
rtw_write8(pDM_Odm->Adapter, REG_TXPAUSE, 0xFF);
if ((tmpReg&0x70) != 0) {
RF_Amode = PHY_QueryRFReg(padapter, ODM_RF_PATH_A, RF_AC, bMask12Bits);
if (is2T)
RF_Bmode = PHY_QueryRFReg(padapter, ODM_RF_PATH_B, RF_AC, bMask12Bits);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_AC, bMask12Bits, (RF_Amode&0x8FFFF)|0x10000);
if (is2T)
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_B, RF_AC, bMask12Bits, (RF_Bmode&0x8FFFF)|0x10000);
}
LC_Cal = PHY_QueryRFReg(padapter, ODM_RF_PATH_A, RF_CHNLBW, bMask12Bits);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xB0, bRFRegOffsetMask, 0xDFBE0);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_CHNLBW, bMask12Bits, LC_Cal|0x08000);
mdelay(100);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xB0, bRFRegOffsetMask, 0xDFFE0);
if (pDM_Odm->SupportInterface == ODM_ITRF_SDIO && pDM_Odm->PackageType >= 0x2) {
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_CHNLBW, bMask12Bits, LC_Cal);
}
if ((tmpReg&0x70) != 0) {
rtw_write8(pDM_Odm->Adapter, 0xd03, tmpReg);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_AC, bMask12Bits, RF_Amode);
if (is2T)
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_B, RF_AC, bMask12Bits, RF_Bmode);
} else
rtw_write8(pDM_Odm->Adapter, REG_TXPAUSE, 0x00);
}
void PHY_IQCalibrate_8723B(
struct adapter *padapter,
bool bReCovery,
bool bRestore,
bool Is2ant,
u8 RF_Path
)
{
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
PDM_ODM_T pDM_Odm = &pHalData->odmpriv;
s32 result[4][8];
u8 i, final_candidate, Indexforchannel;
bool bPathAOK, bPathBOK;
s32 RegE94, RegE9C, RegEA4, RegEAC, RegEB4, RegEBC, RegEC4, RegECC, RegTmp = 0;
bool is12simular, is13simular, is23simular;
bool bSingleTone = false, bCarrierSuppression = false;
u32 IQK_BB_REG_92C[IQK_BB_REG_NUM] = {
rOFDM0_XARxIQImbalance,
rOFDM0_XBRxIQImbalance,
rOFDM0_ECCAThreshold,
rOFDM0_AGCRSSITable,
rOFDM0_XATxIQImbalance,
rOFDM0_XBTxIQImbalance,
rOFDM0_XCTxAFE,
rOFDM0_XDTxAFE,
rOFDM0_RxIQExtAnta
};
u32 GNT_BT_default;
u32 StartTime;
s32 ProgressingTime;
if (ODM_CheckPowerStatus(padapter) == false)
return;
if (!(pDM_Odm->SupportAbility & ODM_RF_CALIBRATION))
return;
if (bSingleTone || bCarrierSuppression)
return;
#if DISABLE_BB_RF
return;
#endif
if (pDM_Odm->RFCalibrateInfo.bIQKInProgress)
return;
pDM_Odm->RFCalibrateInfo.bIQKInProgress = true;
if (bRestore) {
u32 offset, data;
u8 path, bResult = SUCCESS;
PODM_RF_CAL_T pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);
path = (PHY_QueryBBReg(pDM_Odm->Adapter, rS0S1_PathSwitch, bMaskByte0) == 0x00) ? ODM_RF_PATH_A : ODM_RF_PATH_B;
for (i = 0; i < 3; ++i) {
offset = pRFCalibrateInfo->TxIQC_8723B[path][i][0];
data = pRFCalibrateInfo->TxIQC_8723B[path][i][1];
if ((offset == 0) || (data == 0)) {
DBG_871X(
"%s =>path:%s Restore TX IQK result failed\n",
__func__,
(path == ODM_RF_PATH_A)?"A":"B"
);
bResult = FAIL;
break;
}
PHY_SetBBReg(pDM_Odm->Adapter, offset, bMaskDWord, data);
}
for (i = 0; i < 2; ++i) {
offset = pRFCalibrateInfo->RxIQC_8723B[path][i][0];
data = pRFCalibrateInfo->RxIQC_8723B[path][i][1];
if ((offset == 0) || (data == 0)) {
DBG_871X(
"%s =>path:%s Restore RX IQK result failed\n",
__func__,
(path == ODM_RF_PATH_A)?"A":"B"
);
bResult = FAIL;
break;
}
PHY_SetBBReg(pDM_Odm->Adapter, offset, bMaskDWord, data);
}
if (pDM_Odm->RFCalibrateInfo.TxLOK[ODM_RF_PATH_A] == 0) {
DBG_871X("%s => Restore Path-A TxLOK result failed\n", __func__);
bResult = FAIL;
} else {
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXM_IDAC, bRFRegOffsetMask, pDM_Odm->RFCalibrateInfo.TxLOK[ODM_RF_PATH_A]);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_B, RF_TXM_IDAC, bRFRegOffsetMask, pDM_Odm->RFCalibrateInfo.TxLOK[ODM_RF_PATH_B]);
}
if (bResult == SUCCESS)
return;
}
if (bReCovery) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("PHY_IQCalibrate_8723B: Return due to bReCovery!\n"));
_PHY_ReloadADDARegisters8723B(padapter, IQK_BB_REG_92C, pDM_Odm->RFCalibrateInfo.IQK_BB_backup_recover, 9);
return;
}
StartTime = jiffies;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK:Start!!!\n"));
GNT_BT_default = PHY_QueryBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord);
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
phy_IQCalibrate_8723B(padapter, result, i, Is2ant, RF_Path);
if (i == 1) {
is12simular = phy_SimularityCompare_8723B(padapter, result, 0, 1);
if (is12simular) {
final_candidate = 0;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK: is12simular final_candidate is %x\n", final_candidate));
break;
}
}
if (i == 2) {
is13simular = phy_SimularityCompare_8723B(padapter, result, 0, 2);
if (is13simular) {
final_candidate = 0;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK: is13simular final_candidate is %x\n", final_candidate));
break;
}
is23simular = phy_SimularityCompare_8723B(padapter, result, 1, 2);
if (is23simular) {
final_candidate = 1;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK: is23simular final_candidate is %x\n", final_candidate));
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
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK: RegE94 =%x RegE9C =%x RegEA4 =%x RegEAC =%x RegEB4 =%x RegEBC =%x RegEC4 =%x RegECC =%x\n ", RegE94, RegE9C, RegEA4, RegEAC, RegEB4, RegEBC, RegEC4, RegECC));
}
if (final_candidate != 0xff) {
pDM_Odm->RFCalibrateInfo.RegE94 = RegE94 = result[final_candidate][0];
pDM_Odm->RFCalibrateInfo.RegE9C = RegE9C = result[final_candidate][1];
RegEA4 = result[final_candidate][2];
RegEAC = result[final_candidate][3];
pDM_Odm->RFCalibrateInfo.RegEB4 = RegEB4 = result[final_candidate][4];
pDM_Odm->RFCalibrateInfo.RegEBC = RegEBC = result[final_candidate][5];
RegEC4 = result[final_candidate][6];
RegECC = result[final_candidate][7];
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK: final_candidate is %x\n", final_candidate));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK: RegE94 =%x RegE9C =%x RegEA4 =%x RegEAC =%x RegEB4 =%x RegEBC =%x RegEC4 =%x RegECC =%x\n ", RegE94, RegE9C, RegEA4, RegEAC, RegEB4, RegEBC, RegEC4, RegECC));
bPathAOK = bPathBOK = true;
} else {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK: FAIL use default value\n"));
pDM_Odm->RFCalibrateInfo.RegE94 = pDM_Odm->RFCalibrateInfo.RegEB4 = 0x100;
pDM_Odm->RFCalibrateInfo.RegE9C = pDM_Odm->RFCalibrateInfo.RegEBC = 0x0;
}
{
if (RegE94 != 0)
_PHY_PathAFillIQKMatrix8723B(padapter, bPathAOK, result, final_candidate, (RegEA4 == 0));
}
{
if (RegEB4 != 0)
_PHY_PathBFillIQKMatrix8723B(padapter, bPathBOK, result, final_candidate, (RegEC4 == 0));
}
Indexforchannel = ODM_GetRightChnlPlaceforIQK(pHalData->CurrentChannel);
if (final_candidate < 4) {
for (i = 0; i < IQK_Matrix_REG_NUM; i++)
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[Indexforchannel].Value[0][i] = result[final_candidate][i];
pDM_Odm->RFCalibrateInfo.IQKMatrixRegSetting[Indexforchannel].bIQKDone = true;
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("\nIQK OK Indexforchannel %d.\n", Indexforchannel));
_PHY_SaveADDARegisters8723B(padapter, IQK_BB_REG_92C, pDM_Odm->RFCalibrateInfo.IQK_BB_backup_recover, 9);
PHY_SetBBReg(pDM_Odm->Adapter, 0x764, bMaskDWord, GNT_BT_default);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_WE_LUT, 0x80000, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_RCK_OS, bRFRegOffsetMask, 0x18000);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G1, bRFRegOffsetMask, 0x0001f);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_TXPA_G2, bRFRegOffsetMask, 0xe6177);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0xed, 0x20, 0x1);
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, 0x43, bRFRegOffsetMask, 0x300bd);
if (Is2ant) {
if (RF_Path == 0x0)
ODM_SetIQCbyRFpath(pDM_Odm, 0);
else
ODM_SetIQCbyRFpath(pDM_Odm, 1);
}
pDM_Odm->RFCalibrateInfo.bIQKInProgress = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK finished\n"));
ProgressingTime = jiffies_to_msecs(jiffies - StartTime);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("IQK ProgressingTime = %d\n", ProgressingTime));
}
void PHY_LCCalibrate_8723B(PDM_ODM_T pDM_Odm)
{
bool bSingleTone = false, bCarrierSuppression = false;
u32 timeout = 2000, timecount = 0;
u32 StartTime;
s32 ProgressingTime;
#if DISABLE_BB_RF
return;
#endif
if (!(pDM_Odm->SupportAbility & ODM_RF_CALIBRATION))
return;
if (bSingleTone || bCarrierSuppression)
return;
StartTime = jiffies;
while (*(pDM_Odm->pbScanInProcess) && timecount < timeout) {
mdelay(50);
timecount += 50;
}
pDM_Odm->RFCalibrateInfo.bLCKInProgress = true;
phy_LCCalibrate_8723B(pDM_Odm, false);
pDM_Odm->RFCalibrateInfo.bLCKInProgress = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("LCK:Finish!!!interface %d\n", pDM_Odm->InterfaceIndex));
ProgressingTime = jiffies_to_msecs(jiffies - StartTime);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_CALIBRATION, ODM_DBG_LOUD, ("LCK ProgressingTime = %d\n", ProgressingTime));
}
