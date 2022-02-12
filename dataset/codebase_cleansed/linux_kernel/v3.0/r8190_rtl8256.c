void PHY_SetRF8256Bandwidth(struct r8192_priv *priv, HT_CHANNEL_WIDTH Bandwidth)
{
u8 eRFPath;
for(eRFPath = 0; eRFPath <priv->NumTotalRFPath; eRFPath++)
{
if (!rtl8192_phy_CheckIsLegalRFPath(priv, eRFPath))
continue;
switch(Bandwidth)
{
case HT_CHANNEL_WIDTH_20:
if(priv->card_8192_version == VERSION_8190_BD || priv->card_8192_version == VERSION_8190_BE)
{
rtl8192_phy_SetRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, 0x0b, bMask12Bits, 0x100);
rtl8192_phy_SetRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, 0x2c, bMask12Bits, 0x3d7);
rtl8192_phy_SetRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, 0x0e, bMask12Bits, 0x021);
}
else
{
RT_TRACE(COMP_ERR, "PHY_SetRF8256Bandwidth(): unknown hardware version\n");
}
break;
case HT_CHANNEL_WIDTH_20_40:
if(priv->card_8192_version == VERSION_8190_BD ||priv->card_8192_version == VERSION_8190_BE)
{
rtl8192_phy_SetRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, 0x0b, bMask12Bits, 0x300);
rtl8192_phy_SetRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, 0x2c, bMask12Bits, 0x3ff);
rtl8192_phy_SetRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, 0x0e, bMask12Bits, 0x0e1);
}
else
{
RT_TRACE(COMP_ERR, "PHY_SetRF8256Bandwidth(): unknown hardware version\n");
}
break;
default:
RT_TRACE(COMP_ERR, "PHY_SetRF8256Bandwidth(): unknown Bandwidth: %#X\n",Bandwidth );
break;
}
}
}
RT_STATUS PHY_RF8256_Config(struct r8192_priv *priv)
{
RT_STATUS rtStatus = RT_STATUS_SUCCESS;
priv->NumTotalRFPath = RTL819X_TOTAL_RF_PATH;
rtStatus = phy_RF8256_Config_ParaFile(priv);
return rtStatus;
}
RT_STATUS phy_RF8256_Config_ParaFile(struct r8192_priv *priv)
{
u32 u4RegValue = 0;
u8 eRFPath;
RT_STATUS rtStatus = RT_STATUS_SUCCESS;
BB_REGISTER_DEFINITION_T *pPhyReg;
u32 RegOffSetToBeCheck = 0x3;
u32 RegValueToBeCheck = 0x7f1;
u32 RF3_Final_Value = 0;
u8 ConstRetryTimes = 5, RetryTimes = 5;
u8 ret = 0;
for(eRFPath = (RF90_RADIO_PATH_E)RF90_PATH_A; eRFPath <priv->NumTotalRFPath; eRFPath++)
{
if (!rtl8192_phy_CheckIsLegalRFPath(priv, eRFPath))
continue;
pPhyReg = &priv->PHYRegDef[eRFPath];
switch(eRFPath)
{
case RF90_PATH_A:
case RF90_PATH_C:
u4RegValue = rtl8192_QueryBBReg(priv, pPhyReg->rfintfs, bRFSI_RFENV);
break;
case RF90_PATH_B :
case RF90_PATH_D:
u4RegValue = rtl8192_QueryBBReg(priv, pPhyReg->rfintfs, bRFSI_RFENV<<16);
break;
}
rtl8192_setBBreg(priv, pPhyReg->rfintfe, bRFSI_RFENV<<16, 0x1);
rtl8192_setBBreg(priv, pPhyReg->rfintfo, bRFSI_RFENV, 0x1);
rtl8192_setBBreg(priv, pPhyReg->rfHSSIPara2, b3WireAddressLength, 0x0);
rtl8192_setBBreg(priv, pPhyReg->rfHSSIPara2, b3WireDataLength, 0x0);
rtl8192_phy_SetRFReg(priv, (RF90_RADIO_PATH_E) eRFPath, 0x0, bMask12Bits, 0xbf);
rtStatus = rtl8192_phy_checkBBAndRF(priv, HW90_BLOCK_RF, (RF90_RADIO_PATH_E)eRFPath);
if(rtStatus!= RT_STATUS_SUCCESS)
{
RT_TRACE(COMP_ERR, "PHY_RF8256_Config():Check Radio[%d] Fail!!\n", eRFPath);
goto phy_RF8256_Config_ParaFile_Fail;
}
RetryTimes = ConstRetryTimes;
RF3_Final_Value = 0;
switch(eRFPath)
{
case RF90_PATH_A:
while(RF3_Final_Value!=RegValueToBeCheck && RetryTimes!=0)
{
ret = rtl8192_phy_ConfigRFWithHeaderFile(priv,(RF90_RADIO_PATH_E)eRFPath);
RF3_Final_Value = rtl8192_phy_QueryRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, RegOffSetToBeCheck, bMask12Bits);
RT_TRACE(COMP_RF, "RF %d %d register final value: %x\n", eRFPath, RegOffSetToBeCheck, RF3_Final_Value);
RetryTimes--;
}
break;
case RF90_PATH_B:
while(RF3_Final_Value!=RegValueToBeCheck && RetryTimes!=0)
{
ret = rtl8192_phy_ConfigRFWithHeaderFile(priv,(RF90_RADIO_PATH_E)eRFPath);
RF3_Final_Value = rtl8192_phy_QueryRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, RegOffSetToBeCheck, bMask12Bits);
RT_TRACE(COMP_RF, "RF %d %d register final value: %x\n", eRFPath, RegOffSetToBeCheck, RF3_Final_Value);
RetryTimes--;
}
break;
case RF90_PATH_C:
while(RF3_Final_Value!=RegValueToBeCheck && RetryTimes!=0)
{
ret = rtl8192_phy_ConfigRFWithHeaderFile(priv,(RF90_RADIO_PATH_E)eRFPath);
RF3_Final_Value = rtl8192_phy_QueryRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, RegOffSetToBeCheck, bMask12Bits);
RT_TRACE(COMP_RF, "RF %d %d register final value: %x\n", eRFPath, RegOffSetToBeCheck, RF3_Final_Value);
RetryTimes--;
}
break;
case RF90_PATH_D:
while(RF3_Final_Value!=RegValueToBeCheck && RetryTimes!=0)
{
ret = rtl8192_phy_ConfigRFWithHeaderFile(priv,(RF90_RADIO_PATH_E)eRFPath);
RF3_Final_Value = rtl8192_phy_QueryRFReg(priv, (RF90_RADIO_PATH_E)eRFPath, RegOffSetToBeCheck, bMask12Bits);
RT_TRACE(COMP_RF, "RF %d %d register final value: %x\n", eRFPath, RegOffSetToBeCheck, RF3_Final_Value);
RetryTimes--;
}
break;
}
;
switch(eRFPath)
{
case RF90_PATH_A:
case RF90_PATH_C:
rtl8192_setBBreg(priv, pPhyReg->rfintfs, bRFSI_RFENV, u4RegValue);
break;
case RF90_PATH_B :
case RF90_PATH_D:
rtl8192_setBBreg(priv, pPhyReg->rfintfs, bRFSI_RFENV<<16, u4RegValue);
break;
}
if(ret){
RT_TRACE(COMP_ERR, "phy_RF8256_Config_ParaFile():Radio[%d] Fail!!", eRFPath);
goto phy_RF8256_Config_ParaFile_Fail;
}
}
RT_TRACE(COMP_PHY, "PHY Initialization Success\n") ;
return RT_STATUS_SUCCESS;
phy_RF8256_Config_ParaFile_Fail:
RT_TRACE(COMP_ERR, "PHY Initialization failed\n") ;
return RT_STATUS_FAILURE;
}
void PHY_SetRF8256CCKTxPower(struct r8192_priv *priv, u8 powerlevel)
{
u32 TxAGC=0;
TxAGC = powerlevel;
if(priv->bDynamicTxLowPower == true)
{
if(priv->CustomerID == RT_CID_819x_Netcore)
TxAGC = 0x22;
else
TxAGC += priv->CckPwEnl;
}
if(TxAGC > 0x24)
TxAGC = 0x24;
rtl8192_setBBreg(priv, rTxAGC_CCK_Mcs32, bTxAGCRateCCK, TxAGC);
}
void PHY_SetRF8256OFDMTxPower(struct r8192_priv *priv, u8 powerlevel)
{
u32 writeVal, powerBase0, powerBase1, writeVal_tmp;
u8 index = 0;
u16 RegOffset[6] = {0xe00, 0xe04, 0xe10, 0xe14, 0xe18, 0xe1c};
u8 byte0, byte1, byte2, byte3;
powerBase0 = powerlevel + priv->LegacyHTTxPowerDiff;
powerBase0 = (powerBase0<<24) | (powerBase0<<16) |(powerBase0<<8) |powerBase0;
powerBase1 = powerlevel;
powerBase1 = (powerBase1<<24) | (powerBase1<<16) |(powerBase1<<8) |powerBase1;
for(index=0; index<6; index++)
{
writeVal = priv->MCSTxPowerLevelOriginalOffset[index] + ((index<2)?powerBase0:powerBase1);
byte0 = (u8)(writeVal & 0x7f);
byte1 = (u8)((writeVal & 0x7f00)>>8);
byte2 = (u8)((writeVal & 0x7f0000)>>16);
byte3 = (u8)((writeVal & 0x7f000000)>>24);
if(byte0 > 0x24)
byte0 = 0x24;
if(byte1 > 0x24)
byte1 = 0x24;
if(byte2 > 0x24)
byte2 = 0x24;
if(byte3 > 0x24)
byte3 = 0x24;
if(index == 3)
{
writeVal_tmp = (byte3<<24) | (byte2<<16) |(byte1<<8) |byte0;
priv->Pwr_Track = writeVal_tmp;
}
if(priv->bDynamicTxHighPower == true)
{
writeVal = 0x03030303;
}
else
{
writeVal = (byte3<<24) | (byte2<<16) |(byte1<<8) |byte0;
}
rtl8192_setBBreg(priv, RegOffset[index], 0x7f7f7f7f, writeVal);
}
}
static void r8192e_drain_tx_queues(struct r8192_priv *priv)
{
u8 i, QueueID;
for (QueueID = 0, i = 0; QueueID < MAX_TX_QUEUE; )
{
struct rtl8192_tx_ring *ring = &priv->tx_ring[QueueID];
if(skb_queue_len(&ring->queue) == 0)
{
QueueID++;
continue;
}
udelay(10);
i++;
if (i >= MAX_DOZE_WAITING_TIMES_9x)
{
RT_TRACE(COMP_POWER, "r8192e_drain_tx_queues() timeout queue %d\n", QueueID);
break;
}
}
}
static bool SetRFPowerState8190(struct r8192_priv *priv,
RT_RF_POWER_STATE eRFPowerState)
{
PRT_POWER_SAVE_CONTROL pPSC = &priv->PowerSaveControl;
bool bResult = true;
if (eRFPowerState == priv->eRFPowerState &&
priv->bHwRfOffAction == 0) {
bResult = false;
goto out;
}
switch( eRFPowerState )
{
case eRfOn:
if ((priv->eRFPowerState == eRfOff) &&
RT_IN_PS_LEVEL(pPSC, RT_RF_OFF_LEVL_HALT_NIC))
{
if (!NicIFEnableNIC(priv)) {
RT_TRACE(COMP_ERR, "%s(): NicIFEnableNIC failed\n",__FUNCTION__);
bResult = false;
goto out;
}
RT_CLEAR_PS_LEVEL(pPSC, RT_RF_OFF_LEVL_HALT_NIC);
} else {
write_nic_byte(priv, ANAPAR, 0x37);
mdelay(1);
rtl8192_setBBreg(priv, rFPGA0_AnalogParameter1, 0x4, 0x1);
priv->bHwRfOffAction = 0;
rtl8192_setBBreg(priv, rFPGA0_XA_RFInterfaceOE, BIT4, 0x1);
rtl8192_setBBreg(priv, rFPGA0_AnalogParameter4, 0x300, 0x3);
rtl8192_setBBreg(priv, rFPGA0_AnalogParameter1, 0x18, 0x3);
rtl8192_setBBreg(priv, rOFDM0_TRxPathEnable, 0x3, 0x3);
rtl8192_setBBreg(priv, rOFDM1_TRxPathEnable, 0x3, 0x3);
rtl8192_setBBreg(priv, rFPGA0_AnalogParameter1, 0x60, 0x3);
}
break;
case eRfSleep:
if(priv->eRFPowerState == eRfOff)
break;
r8192e_drain_tx_queues(priv);
PHY_SetRtl8192eRfOff(priv);
break;
case eRfOff:
r8192e_drain_tx_queues(priv);
if (pPSC->RegRfPsLevel & RT_RF_OFF_LEVL_HALT_NIC && !RT_IN_PS_LEVEL(pPSC, RT_RF_OFF_LEVL_HALT_NIC))
{
NicIFDisableNIC(priv);
RT_SET_PS_LEVEL(pPSC, RT_RF_OFF_LEVL_HALT_NIC);
}
else if (!(pPSC->RegRfPsLevel & RT_RF_OFF_LEVL_HALT_NIC))
{
PHY_SetRtl8192eRfOff(priv);
}
break;
default:
bResult = false;
RT_TRACE(COMP_ERR, "SetRFPowerState8190(): unknow state to set: 0x%X!!!\n", eRFPowerState);
break;
}
if(bResult)
{
priv->eRFPowerState = eRFPowerState;
}
out:
return bResult;
}
static void MgntDisconnectIBSS(struct r8192_priv *priv)
{
u8 i;
bool bFilterOutNonAssociatedBSSID = false;
priv->ieee80211->state = IEEE80211_NOLINK;
for(i=0;i<6;i++) priv->ieee80211->current_network.bssid[i]= 0x55;
priv->OpMode = RT_OP_MODE_NO_LINK;
write_nic_word(priv, BSSIDR, ((u16*)priv->ieee80211->current_network.bssid)[0]);
write_nic_dword(priv, BSSIDR+2, ((u32*)(priv->ieee80211->current_network.bssid+2))[0]);
{
RT_OP_MODE OpMode = priv->OpMode;
u8 btMsr = read_nic_byte(priv, MSR);
btMsr &= 0xfc;
switch(OpMode)
{
case RT_OP_MODE_INFRASTRUCTURE:
btMsr |= MSR_LINK_MANAGED;
break;
case RT_OP_MODE_IBSS:
btMsr |= MSR_LINK_ADHOC;
break;
case RT_OP_MODE_AP:
btMsr |= MSR_LINK_MASTER;
break;
default:
btMsr |= MSR_LINK_NONE;
break;
}
write_nic_byte(priv, MSR, btMsr);
}
ieee80211_stop_send_beacons(priv->ieee80211);
bFilterOutNonAssociatedBSSID = false;
{
u32 RegRCR, Type;
Type = bFilterOutNonAssociatedBSSID;
RegRCR = read_nic_dword(priv, RCR);
priv->ReceiveConfig = RegRCR;
if (Type == true)
RegRCR |= (RCR_CBSSID);
else if (Type == false)
RegRCR &= (~RCR_CBSSID);
{
write_nic_dword(priv, RCR, RegRCR);
priv->ReceiveConfig = RegRCR;
}
}
notify_wx_assoc_event(priv->ieee80211);
}
static void MlmeDisassociateRequest(struct r8192_priv *priv, u8 *asSta,
u8 asRsn)
{
u8 i;
RemovePeerTS(priv->ieee80211, asSta);
SendDisassociation( priv->ieee80211, asSta, asRsn );
if(memcpy(priv->ieee80211->current_network.bssid,asSta,6) == NULL)
{
priv->ieee80211->state = IEEE80211_NOLINK;
for(i=0;i<6;i++) priv->ieee80211->current_network.bssid[i] = 0x22;
priv->OpMode = RT_OP_MODE_NO_LINK;
{
RT_OP_MODE OpMode = priv->OpMode;
u8 btMsr = read_nic_byte(priv, MSR);
btMsr &= 0xfc;
switch(OpMode)
{
case RT_OP_MODE_INFRASTRUCTURE:
btMsr |= MSR_LINK_MANAGED;
break;
case RT_OP_MODE_IBSS:
btMsr |= MSR_LINK_ADHOC;
break;
case RT_OP_MODE_AP:
btMsr |= MSR_LINK_MASTER;
break;
default:
btMsr |= MSR_LINK_NONE;
break;
}
write_nic_byte(priv, MSR, btMsr);
}
ieee80211_disassociate(priv->ieee80211);
write_nic_word(priv, BSSIDR, ((u16*)priv->ieee80211->current_network.bssid)[0]);
write_nic_dword(priv, BSSIDR+2, ((u32*)(priv->ieee80211->current_network.bssid+2))[0]);
}
}
static void MgntDisconnectAP(struct r8192_priv *priv, u8 asRsn)
{
bool bFilterOutNonAssociatedBSSID = false;
u32 RegRCR, Type;
bFilterOutNonAssociatedBSSID = false;
Type = bFilterOutNonAssociatedBSSID;
RegRCR = read_nic_dword(priv, RCR);
priv->ReceiveConfig = RegRCR;
if (Type == true)
RegRCR |= (RCR_CBSSID);
else if (Type == false)
RegRCR &= (~RCR_CBSSID);
write_nic_dword(priv, RCR, RegRCR);
priv->ReceiveConfig = RegRCR;
MlmeDisassociateRequest(priv, priv->ieee80211->current_network.bssid, asRsn);
priv->ieee80211->state = IEEE80211_NOLINK;
}
static bool MgntDisconnect(struct r8192_priv *priv, u8 asRsn)
{
if( priv->ieee80211->state == IEEE80211_LINKED )
{
if( priv->ieee80211->iw_mode == IW_MODE_ADHOC )
{
MgntDisconnectIBSS(priv);
}
if( priv->ieee80211->iw_mode == IW_MODE_INFRA )
{
MgntDisconnectAP(priv, asRsn);
}
}
return true;
}
bool MgntActSet_RF_State(struct r8192_priv *priv, RT_RF_POWER_STATE StateToSet,
RT_RF_CHANGE_SOURCE ChangeSource)
{
bool bActionAllowed = false;
bool bConnectBySSID = false;
RT_RF_POWER_STATE rtState;
RT_TRACE(COMP_POWER, "===>MgntActSet_RF_State(): StateToSet(%d)\n",StateToSet);
spin_lock(&priv->rf_ps_lock);
rtState = priv->eRFPowerState;
switch(StateToSet)
{
case eRfOn:
priv->RfOffReason &= (~ChangeSource);
if (!priv->RfOffReason)
{
priv->RfOffReason = 0;
bActionAllowed = true;
if(rtState == eRfOff && ChangeSource >=RF_CHANGE_BY_HW )
{
bConnectBySSID = true;
}
}
else
RT_TRACE(COMP_POWER, "MgntActSet_RF_State - eRfon reject pMgntInfo->RfOffReason= 0x%x, ChangeSource=0x%X\n", priv->RfOffReason, ChangeSource);
break;
case eRfOff:
if (priv->RfOffReason > RF_CHANGE_BY_IPS)
{
MgntDisconnect(priv, disas_lv_ss);
}
priv->RfOffReason |= ChangeSource;
bActionAllowed = true;
break;
case eRfSleep:
priv->RfOffReason |= ChangeSource;
bActionAllowed = true;
break;
}
if (bActionAllowed)
{
RT_TRACE(COMP_POWER, "MgntActSet_RF_State(): Action is allowed.... StateToSet(%d), RfOffReason(%#X)\n", StateToSet, priv->RfOffReason);
SetRFPowerState8190(priv, StateToSet);
}
else
{
RT_TRACE(COMP_POWER, "MgntActSet_RF_State(): Action is rejected.... StateToSet(%d), ChangeSource(%#X), RfOffReason(%#X)\n", StateToSet, ChangeSource, priv->RfOffReason);
}
spin_unlock(&priv->rf_ps_lock);
RT_TRACE(COMP_POWER, "<===MgntActSet_RF_State()\n");
return bActionAllowed;
}
