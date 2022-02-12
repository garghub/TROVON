BOOL IFRFbWriteEmbeded (PSDevice pDevice, DWORD dwData)
{
BYTE pbyData[4];
pbyData[0] = (BYTE)dwData;
pbyData[1] = (BYTE)(dwData>>8);
pbyData[2] = (BYTE)(dwData>>16);
pbyData[3] = (BYTE)(dwData>>24);
CONTROLnsRequestOut(pDevice,
MESSAGE_TYPE_WRITE_IFRF,
0,
0,
4,
pbyData
);
return TRUE;
}
BOOL RFbSetPower (
PSDevice pDevice,
unsigned int uRATE,
unsigned int uCH
)
{
BOOL bResult = TRUE;
BYTE byPwr = pDevice->byCCKPwr;
if (pDevice->dwDiagRefCount != 0) {
return TRUE;
}
switch (uRATE) {
case RATE_1M:
case RATE_2M:
case RATE_5M:
case RATE_11M:
byPwr = pDevice->abyCCKPwrTbl[uCH-1];
break;
case RATE_6M:
case RATE_9M:
case RATE_18M:
case RATE_24M:
case RATE_36M:
case RATE_48M:
case RATE_54M:
if (uCH > CB_MAX_CHANNEL_24G) {
byPwr = pDevice->abyOFDMAPwrTbl[uCH-15];
} else {
byPwr = pDevice->abyOFDMPwrTbl[uCH-1];
}
break;
}
bResult = RFbRawSetPower(pDevice, byPwr, uRATE);
return bResult;
}
BOOL RFbRawSetPower (
PSDevice pDevice,
BYTE byPwr,
unsigned int uRATE
)
{
BOOL bResult = TRUE;
if (pDevice->byCurPwr == byPwr)
return TRUE;
pDevice->byCurPwr = byPwr;
switch (pDevice->byRFType) {
case RF_AL2230 :
if (pDevice->byCurPwr >= AL2230_PWR_IDX_LEN)
return FALSE;
bResult &= IFRFbWriteEmbeded(pDevice, dwAL2230PowerTable[pDevice->byCurPwr]);
if (uRATE <= RATE_11M)
bResult &= IFRFbWriteEmbeded(pDevice, 0x0001B400+(BY_AL2230_REG_LEN<<3)+IFREGCTL_REGW);
else
bResult &= IFRFbWriteEmbeded(pDevice, 0x0005A400+(BY_AL2230_REG_LEN<<3)+IFREGCTL_REGW);
break;
case RF_AL2230S :
if (pDevice->byCurPwr >= AL2230_PWR_IDX_LEN)
return FALSE;
bResult &= IFRFbWriteEmbeded(pDevice, dwAL2230PowerTable[pDevice->byCurPwr]);
if (uRATE <= RATE_11M) {
bResult &= IFRFbWriteEmbeded(pDevice, 0x040C1400+(BY_AL2230_REG_LEN<<3)+IFREGCTL_REGW);
bResult &= IFRFbWriteEmbeded(pDevice, 0x00299B00+(BY_AL2230_REG_LEN<<3)+IFREGCTL_REGW);
}else {
bResult &= IFRFbWriteEmbeded(pDevice, 0x0005A400+(BY_AL2230_REG_LEN<<3)+IFREGCTL_REGW);
bResult &= IFRFbWriteEmbeded(pDevice, 0x00099B00+(BY_AL2230_REG_LEN<<3)+IFREGCTL_REGW);
}
break;
case RF_AIROHA7230:
{
DWORD dwMax7230Pwr;
if (uRATE <= RATE_11M) {
bResult &= IFRFbWriteEmbeded(pDevice, 0x111BB900+(BY_AL7230_REG_LEN<<3)+IFREGCTL_REGW);
}
else {
bResult &= IFRFbWriteEmbeded(pDevice, 0x221BB900+(BY_AL7230_REG_LEN<<3)+IFREGCTL_REGW);
}
if (pDevice->byCurPwr > AL7230_PWR_IDX_LEN) return FALSE;
dwMax7230Pwr = 0x080C0B00 | ( (pDevice->byCurPwr) << 12 ) |
(BY_AL7230_REG_LEN << 3 ) | IFREGCTL_REGW;
bResult &= IFRFbWriteEmbeded(pDevice, dwMax7230Pwr);
break;
}
break;
case RF_VT3226:
{
DWORD dwVT3226Pwr;
if (pDevice->byCurPwr >= VT3226_PWR_IDX_LEN)
return FALSE;
dwVT3226Pwr = ((0x3F-pDevice->byCurPwr) << 20 ) | ( 0x17 << 8 ) |
(BY_VT3226_REG_LEN << 3 ) | IFREGCTL_REGW;
bResult &= IFRFbWriteEmbeded(pDevice, dwVT3226Pwr);
break;
}
case RF_VT3226D0:
{
DWORD dwVT3226Pwr;
if (pDevice->byCurPwr >= VT3226_PWR_IDX_LEN)
return FALSE;
if (uRATE <= RATE_11M) {
dwVT3226Pwr = ((0x3F-pDevice->byCurPwr) << 20 ) | ( 0xE07 << 8 ) |
(BY_VT3226_REG_LEN << 3 ) | IFREGCTL_REGW;
bResult &= IFRFbWriteEmbeded(pDevice, dwVT3226Pwr);
bResult &= IFRFbWriteEmbeded(pDevice, 0x03C6A200+(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
if (pDevice->sMgmtObj.eScanState != WMAC_NO_SCANNING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"@@@@ RFbRawSetPower> 11B mode uCurrChannel[%d]\n", pDevice->sMgmtObj.uScanChannel);
bResult &= IFRFbWriteEmbeded(pDevice, dwVT3226D0LoCurrentTable[pDevice->sMgmtObj.uScanChannel-1]);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"@@@@ RFbRawSetPower> 11B mode uCurrChannel[%d]\n", pDevice->sMgmtObj.uCurrChannel);
bResult &= IFRFbWriteEmbeded(pDevice, dwVT3226D0LoCurrentTable[pDevice->sMgmtObj.uCurrChannel-1]);
}
bResult &= IFRFbWriteEmbeded(pDevice, 0x015C0800+(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"@@@@ RFbRawSetPower> 11G mode\n");
dwVT3226Pwr = ((0x3F-pDevice->byCurPwr) << 20 ) | ( 0x7 << 8 ) |
(BY_VT3226_REG_LEN << 3 ) | IFREGCTL_REGW;
bResult &= IFRFbWriteEmbeded(pDevice, dwVT3226Pwr);
bResult &= IFRFbWriteEmbeded(pDevice, 0x00C6A200+(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
bResult &= IFRFbWriteEmbeded(pDevice, 0x016BC600+(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
bResult &= IFRFbWriteEmbeded(pDevice, 0x00900800+(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
}
break;
}
case RF_VT3342A0:
{
DWORD dwVT3342Pwr;
if (pDevice->byCurPwr >= VT3342_PWR_IDX_LEN)
return FALSE;
dwVT3342Pwr = ((0x3F-pDevice->byCurPwr) << 20 ) | ( 0x27 << 8 ) |
(BY_VT3342_REG_LEN << 3 ) | IFREGCTL_REGW;
bResult &= IFRFbWriteEmbeded(pDevice, dwVT3342Pwr);
break;
}
default :
break;
}
return bResult;
}
void
RFvRSSITodBm (
PSDevice pDevice,
BYTE byCurrRSSI,
long * pldBm
)
{
BYTE byIdx = (((byCurrRSSI & 0xC0) >> 6) & 0x03);
signed long b = (byCurrRSSI & 0x3F);
signed long a = 0;
BYTE abyAIROHARF[4] = {0, 18, 0, 40};
switch (pDevice->byRFType) {
case RF_AL2230:
case RF_AL2230S:
case RF_AIROHA7230:
case RF_VT3226:
case RF_VT3226D0:
case RF_VT3342A0:
a = abyAIROHARF[byIdx];
break;
default:
break;
}
*pldBm = -1 * (a + b * 2);
}
void
RFbRFTableDownload (
PSDevice pDevice
)
{
WORD wLength1 = 0,wLength2 = 0 ,wLength3 = 0;
PBYTE pbyAddr1 = NULL,pbyAddr2 = NULL,pbyAddr3 = NULL;
WORD wLength,wValue;
BYTE abyArray[256];
switch ( pDevice->byRFType ) {
case RF_AL2230:
case RF_AL2230S:
wLength1 = CB_AL2230_INIT_SEQ * 3;
wLength2 = CB_MAX_CHANNEL_24G * 3;
wLength3 = CB_MAX_CHANNEL_24G * 3;
pbyAddr1 = &(abyAL2230InitTable[0][0]);
pbyAddr2 = &(abyAL2230ChannelTable0[0][0]);
pbyAddr3 = &(abyAL2230ChannelTable1[0][0]);
break;
case RF_AIROHA7230:
wLength1 = CB_AL7230_INIT_SEQ * 3;
wLength2 = CB_MAX_CHANNEL * 3;
wLength3 = CB_MAX_CHANNEL * 3;
pbyAddr1 = &(abyAL7230InitTable[0][0]);
pbyAddr2 = &(abyAL7230ChannelTable0[0][0]);
pbyAddr3 = &(abyAL7230ChannelTable1[0][0]);
break;
case RF_VT3226:
wLength1 = CB_VT3226_INIT_SEQ * 3;
wLength2 = CB_MAX_CHANNEL_24G * 3;
wLength3 = CB_MAX_CHANNEL_24G * 3;
pbyAddr1 = &(abyVT3226_InitTable[0][0]);
pbyAddr2 = &(abyVT3226_ChannelTable0[0][0]);
pbyAddr3 = &(abyVT3226_ChannelTable1[0][0]);
break;
case RF_VT3226D0:
wLength1 = CB_VT3226_INIT_SEQ * 3;
wLength2 = CB_MAX_CHANNEL_24G * 3;
wLength3 = CB_MAX_CHANNEL_24G * 3;
pbyAddr1 = &(abyVT3226D0_InitTable[0][0]);
pbyAddr2 = &(abyVT3226_ChannelTable0[0][0]);
pbyAddr3 = &(abyVT3226_ChannelTable1[0][0]);
break;
case RF_VT3342A0:
wLength1 = CB_VT3342_INIT_SEQ * 3;
wLength2 = CB_MAX_CHANNEL * 3;
wLength3 = CB_MAX_CHANNEL * 3;
pbyAddr1 = &(abyVT3342A0_InitTable[0][0]);
pbyAddr2 = &(abyVT3342_ChannelTable0[0][0]);
pbyAddr3 = &(abyVT3342_ChannelTable1[0][0]);
break;
}
memcpy(abyArray, pbyAddr1, wLength1);
CONTROLnsRequestOut(pDevice,
MESSAGE_TYPE_WRITE,
0,
MESSAGE_REQUEST_RF_INIT,
wLength1,
abyArray
);
wValue = 0;
while ( wLength2 > 0 ) {
if ( wLength2 >= 64 ) {
wLength = 64;
} else {
wLength = wLength2;
}
memcpy(abyArray, pbyAddr2, wLength);
CONTROLnsRequestOut(pDevice,
MESSAGE_TYPE_WRITE,
wValue,
MESSAGE_REQUEST_RF_CH0,
wLength,
abyArray);
wLength2 -= wLength;
wValue += wLength;
pbyAddr2 += wLength;
}
wValue = 0;
while ( wLength3 > 0 ) {
if ( wLength3 >= 64 ) {
wLength = 64;
} else {
wLength = wLength3;
}
memcpy(abyArray, pbyAddr3, wLength);
CONTROLnsRequestOut(pDevice,
MESSAGE_TYPE_WRITE,
wValue,
MESSAGE_REQUEST_RF_CH1,
wLength,
abyArray);
wLength3 -= wLength;
wValue += wLength;
pbyAddr3 += wLength;
}
if ( pDevice->byRFType == RF_AIROHA7230 ) {
wLength1 = CB_AL7230_INIT_SEQ * 3;
wLength2 = CB_MAX_CHANNEL * 3;
pbyAddr1 = &(abyAL7230InitTableAMode[0][0]);
pbyAddr2 = &(abyAL7230ChannelTable2[0][0]);
memcpy(abyArray, pbyAddr1, wLength1);
CONTROLnsRequestOut(pDevice,
MESSAGE_TYPE_WRITE,
0,
MESSAGE_REQUEST_RF_INIT2,
wLength1,
abyArray);
wValue = 0;
while ( wLength2 > 0 ) {
if ( wLength2 >= 64 ) {
wLength = 64;
} else {
wLength = wLength2;
}
memcpy(abyArray, pbyAddr2, wLength);
CONTROLnsRequestOut(pDevice,
MESSAGE_TYPE_WRITE,
wValue,
MESSAGE_REQUEST_RF_CH2,
wLength,
abyArray);
wLength2 -= wLength;
wValue += wLength;
pbyAddr2 += wLength;
}
}
}
BOOL s_bVT3226D0_11bLoCurrentAdjust(
PSDevice pDevice,
BYTE byChannel,
BOOL b11bMode)
{
BOOL bResult;
bResult = TRUE;
if( b11bMode )
bResult &= IFRFbWriteEmbeded(pDevice, dwVT3226D0LoCurrentTable[byChannel-1]);
else
bResult &= IFRFbWriteEmbeded(pDevice, 0x016BC600+(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
return bResult;
}
