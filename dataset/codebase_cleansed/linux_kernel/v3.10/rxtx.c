static void *s_vGetFreeContext(struct vnt_private *pDevice)
{
PUSB_SEND_CONTEXT pContext = NULL;
PUSB_SEND_CONTEXT pReturnContext = NULL;
int ii;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"GetFreeContext()\n");
for (ii = 0; ii < pDevice->cbTD; ii++) {
pContext = pDevice->apTD[ii];
if (pContext->bBoolInUse == false) {
pContext->bBoolInUse = true;
pReturnContext = pContext;
break;
}
}
if ( ii == pDevice->cbTD ) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"No Free Tx Context\n");
}
return (void *) pReturnContext;
}
static void s_vSaveTxPktInfo(struct vnt_private *pDevice, u8 byPktNum,
u8 *pbyDestAddr, u16 wPktLength, u16 wFIFOCtl)
{
PSStatCounter pStatistic = &pDevice->scStatistic;
if (is_broadcast_ether_addr(pbyDestAddr))
pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni = TX_PKT_BROAD;
else if (is_multicast_ether_addr(pbyDestAddr))
pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni = TX_PKT_MULTI;
else
pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni = TX_PKT_UNI;
pStatistic->abyTxPktInfo[byPktNum].wLength = wPktLength;
pStatistic->abyTxPktInfo[byPktNum].wFIFOCtl = wFIFOCtl;
memcpy(pStatistic->abyTxPktInfo[byPktNum].abyDestAddr,
pbyDestAddr,
ETH_ALEN);
}
static void s_vFillTxKey(struct vnt_private *pDevice, u8 *pbyBuf,
u8 *pbyIVHead, PSKeyItem pTransmitKey, u8 *pbyHdrBuf,
u16 wPayloadLen, u8 *pMICHDR)
{
u32 *pdwIV = (u32 *)pbyIVHead;
u32 *pdwExtIV = (u32 *)((u8 *)pbyIVHead + 4);
u16 wValue;
struct ieee80211_hdr *pMACHeader = (struct ieee80211_hdr *)pbyHdrBuf;
u32 dwRevIVCounter;
if (pTransmitKey == NULL)
return;
dwRevIVCounter = cpu_to_le32(pDevice->dwIVCounter);
*pdwIV = pDevice->dwIVCounter;
pDevice->byKeyIndex = pTransmitKey->dwKeyIndex & 0xf;
if (pTransmitKey->byCipherSuite == KEY_CTL_WEP) {
if (pTransmitKey->uKeyLength == WLAN_WEP232_KEYLEN ){
memcpy(pDevice->abyPRNG, (u8 *)&(dwRevIVCounter), 3);
memcpy(pDevice->abyPRNG+3, pTransmitKey->abyKey, pTransmitKey->uKeyLength);
} else {
memcpy(pbyBuf, (u8 *)&(dwRevIVCounter), 3);
memcpy(pbyBuf+3, pTransmitKey->abyKey, pTransmitKey->uKeyLength);
if(pTransmitKey->uKeyLength == WLAN_WEP40_KEYLEN) {
memcpy(pbyBuf+8, (u8 *)&(dwRevIVCounter), 3);
memcpy(pbyBuf+11, pTransmitKey->abyKey, pTransmitKey->uKeyLength);
}
memcpy(pDevice->abyPRNG, pbyBuf, 16);
}
*pdwIV &= WEP_IV_MASK;
*pdwIV |= (u32)pDevice->byKeyIndex << 30;
*pdwIV = cpu_to_le32(*pdwIV);
pDevice->dwIVCounter++;
if (pDevice->dwIVCounter > WEP_IV_MASK) {
pDevice->dwIVCounter = 0;
}
} else if (pTransmitKey->byCipherSuite == KEY_CTL_TKIP) {
pTransmitKey->wTSC15_0++;
if (pTransmitKey->wTSC15_0 == 0) {
pTransmitKey->dwTSC47_16++;
}
TKIPvMixKey(pTransmitKey->abyKey, pDevice->abyCurrentNetAddr,
pTransmitKey->wTSC15_0, pTransmitKey->dwTSC47_16, pDevice->abyPRNG);
memcpy(pbyBuf, pDevice->abyPRNG, 16);
memcpy(pdwIV, pDevice->abyPRNG, 3);
*(pbyIVHead+3) = (u8)(((pDevice->byKeyIndex << 6) & 0xc0) | 0x20);
*pdwExtIV = cpu_to_le32(pTransmitKey->dwTSC47_16);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"vFillTxKey()---- pdwExtIV: %x\n",
*pdwExtIV);
} else if (pTransmitKey->byCipherSuite == KEY_CTL_CCMP) {
pTransmitKey->wTSC15_0++;
if (pTransmitKey->wTSC15_0 == 0) {
pTransmitKey->dwTSC47_16++;
}
memcpy(pbyBuf, pTransmitKey->abyKey, 16);
*pdwIV = 0;
*(pbyIVHead+3) = (u8)(((pDevice->byKeyIndex << 6) & 0xc0) | 0x20);
*pdwIV |= cpu_to_le16((u16)(pTransmitKey->wTSC15_0));
*pdwExtIV = cpu_to_le32(pTransmitKey->dwTSC47_16);
*pMICHDR = 0x59;
*((u8 *)(pMICHDR+1)) = 0;
memcpy(pMICHDR+2, &(pMACHeader->addr2[0]), 6);
*((u8 *)(pMICHDR+8)) = HIBYTE(HIWORD(pTransmitKey->dwTSC47_16));
*((u8 *)(pMICHDR+9)) = LOBYTE(HIWORD(pTransmitKey->dwTSC47_16));
*((u8 *)(pMICHDR+10)) = HIBYTE(LOWORD(pTransmitKey->dwTSC47_16));
*((u8 *)(pMICHDR+11)) = LOBYTE(LOWORD(pTransmitKey->dwTSC47_16));
*((u8 *)(pMICHDR+12)) = HIBYTE(pTransmitKey->wTSC15_0);
*((u8 *)(pMICHDR+13)) = LOBYTE(pTransmitKey->wTSC15_0);
*((u8 *)(pMICHDR+14)) = HIBYTE(wPayloadLen);
*((u8 *)(pMICHDR+15)) = LOBYTE(wPayloadLen);
*((u8 *)(pMICHDR+16)) = 0;
if (pDevice->bLongHeader) {
*((u8 *)(pMICHDR+17)) = 28;
} else {
*((u8 *)(pMICHDR+17)) = 22;
}
wValue = cpu_to_le16(pMACHeader->frame_control & 0xC78F);
memcpy(pMICHDR+18, (u8 *)&wValue, 2);
memcpy(pMICHDR+20, &(pMACHeader->addr1[0]), 6);
memcpy(pMICHDR+26, &(pMACHeader->addr2[0]), 6);
memcpy(pMICHDR+32, &(pMACHeader->addr3[0]), 6);
wValue = pMACHeader->seq_ctrl;
wValue &= 0x000F;
wValue = cpu_to_le16(wValue);
memcpy(pMICHDR+38, (u8 *)&wValue, 2);
if (pDevice->bLongHeader) {
memcpy(pMICHDR+40, &(pMACHeader->addr4[0]), 6);
}
}
}
static void s_vSWencryption(struct vnt_private *pDevice,
PSKeyItem pTransmitKey, u8 *pbyPayloadHead, u16 wPayloadSize)
{
u32 cbICVlen = 4;
u32 dwICV = 0xffffffff;
u32 *pdwICV;
if (pTransmitKey == NULL)
return;
if (pTransmitKey->byCipherSuite == KEY_CTL_WEP) {
dwICV = CRCdwGetCrc32Ex(pbyPayloadHead, wPayloadSize, dwICV);
pdwICV = (u32 *)(pbyPayloadHead + wPayloadSize);
*pdwICV = cpu_to_le32(~dwICV);
rc4_init(&pDevice->SBox, pDevice->abyPRNG, pTransmitKey->uKeyLength + 3);
rc4_encrypt(&pDevice->SBox, pbyPayloadHead, pbyPayloadHead, wPayloadSize+cbICVlen);
} else if (pTransmitKey->byCipherSuite == KEY_CTL_TKIP) {
dwICV = CRCdwGetCrc32Ex(pbyPayloadHead, wPayloadSize, dwICV);
pdwICV = (u32 *)(pbyPayloadHead + wPayloadSize);
*pdwICV = cpu_to_le32(~dwICV);
rc4_init(&pDevice->SBox, pDevice->abyPRNG, TKIP_KEY_LEN);
rc4_encrypt(&pDevice->SBox, pbyPayloadHead, pbyPayloadHead, wPayloadSize+cbICVlen);
}
}
static u32 s_uGetTxRsvTime(struct vnt_private *pDevice, u8 byPktType,
u32 cbFrameLength, u16 wRate, int bNeedAck)
{
u32 uDataTime, uAckTime;
uDataTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, cbFrameLength, wRate);
if (byPktType == PK_TYPE_11B) {
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, (u16)pDevice->byTopCCKBasicRate);
} else {
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, (u16)pDevice->byTopOFDMBasicRate);
}
if (bNeedAck) {
return (uDataTime + pDevice->uSIFS + uAckTime);
}
else {
return uDataTime;
}
}
static u32 s_uGetRTSCTSRsvTime(struct vnt_private *pDevice,
u8 byRTSRsvType, u8 byPktType, u32 cbFrameLength, u16 wCurrentRate)
{
u32 uRrvTime, uRTSTime, uCTSTime, uAckTime, uDataTime;
uRrvTime = uRTSTime = uCTSTime = uAckTime = uDataTime = 0;
uDataTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, cbFrameLength, wCurrentRate);
if (byRTSRsvType == 0) {
uRTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 20, pDevice->byTopCCKBasicRate);
uCTSTime = uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
}
else if (byRTSRsvType == 1){
uRTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 20, pDevice->byTopCCKBasicRate);
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
}
else if (byRTSRsvType == 2) {
uRTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 20, pDevice->byTopOFDMBasicRate);
uCTSTime = uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
}
else if (byRTSRsvType == 3) {
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
uRrvTime = uCTSTime + uAckTime + uDataTime + 2*pDevice->uSIFS;
return uRrvTime;
}
uRrvTime = uRTSTime + uCTSTime + uAckTime + uDataTime + 3*pDevice->uSIFS;
return uRrvTime;
}
static u32 s_uGetDataDuration(struct vnt_private *pDevice, u8 byDurType,
u32 cbFrameLength, u8 byPktType, u16 wRate, int bNeedAck,
u32 uFragIdx, u32 cbLastFragmentSize, u32 uMACfragNum,
u8 byFBOption)
{
int bLastFrag = 0;
u32 uAckTime = 0, uNextPktTime = 0;
if (uFragIdx == (uMACfragNum-1)) {
bLastFrag = 1;
}
switch (byDurType) {
case DATADUR_B:
if (((uMACfragNum == 1)) || (bLastFrag == 1)) {
if (bNeedAck) {
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
return (pDevice->uSIFS + uAckTime);
} else {
return 0;
}
}
else {
if (uFragIdx == (uMACfragNum-2)) {
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbLastFragmentSize, wRate, bNeedAck);
} else {
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wRate, bNeedAck);
}
if (bNeedAck) {
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
return (pDevice->uSIFS + uAckTime + uNextPktTime);
} else {
return (pDevice->uSIFS + uNextPktTime);
}
}
break;
case DATADUR_A:
if (((uMACfragNum==1)) || (bLastFrag==1)) {
if(bNeedAck){
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
return (pDevice->uSIFS + uAckTime);
} else {
return 0;
}
}
else {
if(uFragIdx == (uMACfragNum-2)){
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbLastFragmentSize, wRate, bNeedAck);
} else {
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wRate, bNeedAck);
}
if(bNeedAck){
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
return (pDevice->uSIFS + uAckTime + uNextPktTime);
} else {
return (pDevice->uSIFS + uNextPktTime);
}
}
break;
case DATADUR_A_F0:
if (((uMACfragNum==1)) || (bLastFrag==1)) {
if(bNeedAck){
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
return (pDevice->uSIFS + uAckTime);
} else {
return 0;
}
}
else {
if (byFBOption == AUTO_FB_0) {
if (wRate < RATE_18M)
wRate = RATE_18M;
else if (wRate > RATE_54M)
wRate = RATE_54M;
if(uFragIdx == (uMACfragNum-2)){
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbLastFragmentSize, wFB_Opt0[FB_RATE0][wRate-RATE_18M], bNeedAck);
} else {
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt0[FB_RATE0][wRate-RATE_18M], bNeedAck);
}
} else {
if (wRate < RATE_18M)
wRate = RATE_18M;
else if (wRate > RATE_54M)
wRate = RATE_54M;
if(uFragIdx == (uMACfragNum-2)){
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbLastFragmentSize, wFB_Opt1[FB_RATE0][wRate-RATE_18M], bNeedAck);
} else {
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt1[FB_RATE0][wRate-RATE_18M], bNeedAck);
}
}
if(bNeedAck){
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
return (pDevice->uSIFS + uAckTime + uNextPktTime);
} else {
return (pDevice->uSIFS + uNextPktTime);
}
}
break;
case DATADUR_A_F1:
if (((uMACfragNum==1)) || (bLastFrag==1)) {
if(bNeedAck){
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
return (pDevice->uSIFS + uAckTime);
} else {
return 0;
}
}
else {
if (byFBOption == AUTO_FB_0) {
if (wRate < RATE_18M)
wRate = RATE_18M;
else if (wRate > RATE_54M)
wRate = RATE_54M;
if(uFragIdx == (uMACfragNum-2)){
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbLastFragmentSize, wFB_Opt0[FB_RATE1][wRate-RATE_18M], bNeedAck);
} else {
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt0[FB_RATE1][wRate-RATE_18M], bNeedAck);
}
} else {
if (wRate < RATE_18M)
wRate = RATE_18M;
else if (wRate > RATE_54M)
wRate = RATE_54M;
if(uFragIdx == (uMACfragNum-2)){
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbLastFragmentSize, wFB_Opt1[FB_RATE1][wRate-RATE_18M], bNeedAck);
} else {
uNextPktTime = s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt1[FB_RATE1][wRate-RATE_18M], bNeedAck);
}
}
if(bNeedAck){
uAckTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
return (pDevice->uSIFS + uAckTime + uNextPktTime);
} else {
return (pDevice->uSIFS + uNextPktTime);
}
}
break;
default:
break;
}
ASSERT(false);
return 0;
}
static u32 s_uGetRTSCTSDuration(struct vnt_private *pDevice, u8 byDurType,
u32 cbFrameLength, u8 byPktType, u16 wRate, int bNeedAck,
u8 byFBOption)
{
u32 uCTSTime = 0, uDurTime = 0;
switch (byDurType) {
case RTSDUR_BB:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wRate, bNeedAck);
break;
case RTSDUR_BA:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wRate, bNeedAck);
break;
case RTSDUR_AA:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wRate, bNeedAck);
break;
case CTSDUR_BA:
uDurTime = pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wRate, bNeedAck);
break;
case RTSDUR_BA_F0:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
if ((byFBOption == AUTO_FB_0) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt0[FB_RATE0][wRate-RATE_18M], bNeedAck);
} else if ((byFBOption == AUTO_FB_1) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt1[FB_RATE0][wRate-RATE_18M], bNeedAck);
}
break;
case RTSDUR_AA_F0:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
if ((byFBOption == AUTO_FB_0) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt0[FB_RATE0][wRate-RATE_18M], bNeedAck);
} else if ((byFBOption == AUTO_FB_1) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt1[FB_RATE0][wRate-RATE_18M], bNeedAck);
}
break;
case RTSDUR_BA_F1:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopCCKBasicRate);
if ((byFBOption == AUTO_FB_0) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt0[FB_RATE1][wRate-RATE_18M], bNeedAck);
} else if ((byFBOption == AUTO_FB_1) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt1[FB_RATE1][wRate-RATE_18M], bNeedAck);
}
break;
case RTSDUR_AA_F1:
uCTSTime = BBuGetFrameTime(pDevice->byPreambleType, byPktType, 14, pDevice->byTopOFDMBasicRate);
if ((byFBOption == AUTO_FB_0) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt0[FB_RATE1][wRate-RATE_18M], bNeedAck);
} else if ((byFBOption == AUTO_FB_1) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = uCTSTime + 2*pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt1[FB_RATE1][wRate-RATE_18M], bNeedAck);
}
break;
case CTSDUR_BA_F0:
if ((byFBOption == AUTO_FB_0) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt0[FB_RATE0][wRate-RATE_18M], bNeedAck);
} else if ((byFBOption == AUTO_FB_1) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt1[FB_RATE0][wRate-RATE_18M], bNeedAck);
}
break;
case CTSDUR_BA_F1:
if ((byFBOption == AUTO_FB_0) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt0[FB_RATE1][wRate-RATE_18M], bNeedAck);
} else if ((byFBOption == AUTO_FB_1) && (wRate >= RATE_18M) && (wRate <=RATE_54M)) {
uDurTime = pDevice->uSIFS + s_uGetTxRsvTime(pDevice, byPktType, cbFrameLength, wFB_Opt1[FB_RATE1][wRate-RATE_18M], bNeedAck);
}
break;
default:
break;
}
return uDurTime;
}
static u32 s_uFillDataHead(struct vnt_private *pDevice,
u8 byPktType, u16 wCurrentRate, void *pTxDataHead, u32 cbFrameLength,
u32 uDMAIdx, int bNeedAck, u32 uFragIdx, u32 cbLastFragmentSize,
u32 uMACfragNum, u8 byFBOption)
{
if (pTxDataHead == NULL) {
return 0;
}
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
if ((uDMAIdx == TYPE_ATIMDMA) || (uDMAIdx == TYPE_BEACONDMA)) {
PSTxDataHead_ab pBuf = (PSTxDataHead_ab) pTxDataHead;
BBvCalculateParameter(pDevice, cbFrameLength, wCurrentRate, byPktType,
(u16 *)&(pBuf->wTransmitLength), (u8 *)&(pBuf->byServiceField), (u8 *)&(pBuf->bySignalField)
);
pBuf->wDuration = (u16)s_uGetDataDuration(pDevice, DATADUR_A, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx,
cbLastFragmentSize, uMACfragNum,
byFBOption);
if(uDMAIdx!=TYPE_ATIMDMA) {
pBuf->wTimeStampOff = wTimeStampOff[pDevice->byPreambleType%2][wCurrentRate%MAX_RATE];
}
return (pBuf->wDuration);
}
else {
if (byFBOption == AUTO_FB_NONE) {
PSTxDataHead_g pBuf = (PSTxDataHead_g)pTxDataHead;
BBvCalculateParameter(pDevice, cbFrameLength, wCurrentRate, byPktType,
(u16 *)&(pBuf->wTransmitLength_a), (u8 *)&(pBuf->byServiceField_a), (u8 *)&(pBuf->bySignalField_a)
);
BBvCalculateParameter(pDevice, cbFrameLength, pDevice->byTopCCKBasicRate, PK_TYPE_11B,
(u16 *)&(pBuf->wTransmitLength_b), (u8 *)&(pBuf->byServiceField_b), (u8 *)&(pBuf->bySignalField_b)
);
pBuf->wDuration_a = (u16)s_uGetDataDuration(pDevice, DATADUR_A, cbFrameLength,
byPktType, wCurrentRate, bNeedAck, uFragIdx,
cbLastFragmentSize, uMACfragNum,
byFBOption);
pBuf->wDuration_b = (u16)s_uGetDataDuration(pDevice, DATADUR_B, cbFrameLength,
PK_TYPE_11B, pDevice->byTopCCKBasicRate,
bNeedAck, uFragIdx, cbLastFragmentSize,
uMACfragNum, byFBOption);
pBuf->wTimeStampOff_a = wTimeStampOff[pDevice->byPreambleType%2][wCurrentRate%MAX_RATE];
pBuf->wTimeStampOff_b = wTimeStampOff[pDevice->byPreambleType%2][pDevice->byTopCCKBasicRate%MAX_RATE];
return (pBuf->wDuration_a);
} else {
PSTxDataHead_g_FB pBuf = (PSTxDataHead_g_FB)pTxDataHead;
BBvCalculateParameter(pDevice, cbFrameLength, wCurrentRate, byPktType,
(u16 *)&(pBuf->wTransmitLength_a), (u8 *)&(pBuf->byServiceField_a), (u8 *)&(pBuf->bySignalField_a)
);
BBvCalculateParameter(pDevice, cbFrameLength, pDevice->byTopCCKBasicRate, PK_TYPE_11B,
(u16 *)&(pBuf->wTransmitLength_b), (u8 *)&(pBuf->byServiceField_b), (u8 *)&(pBuf->bySignalField_b)
);
pBuf->wDuration_a = (u16)s_uGetDataDuration(pDevice, DATADUR_A, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx, cbLastFragmentSize, uMACfragNum, byFBOption);
pBuf->wDuration_b = (u16)s_uGetDataDuration(pDevice, DATADUR_B, cbFrameLength, PK_TYPE_11B,
pDevice->byTopCCKBasicRate, bNeedAck, uFragIdx, cbLastFragmentSize, uMACfragNum, byFBOption);
pBuf->wDuration_a_f0 = (u16)s_uGetDataDuration(pDevice, DATADUR_A_F0, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx, cbLastFragmentSize, uMACfragNum, byFBOption);
pBuf->wDuration_a_f1 = (u16)s_uGetDataDuration(pDevice, DATADUR_A_F1, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx, cbLastFragmentSize, uMACfragNum, byFBOption);
pBuf->wTimeStampOff_a = wTimeStampOff[pDevice->byPreambleType%2][wCurrentRate%MAX_RATE];
pBuf->wTimeStampOff_b = wTimeStampOff[pDevice->byPreambleType%2][pDevice->byTopCCKBasicRate%MAX_RATE];
return (pBuf->wDuration_a);
}
}
}
else if (byPktType == PK_TYPE_11A) {
if ((byFBOption != AUTO_FB_NONE) && (uDMAIdx != TYPE_ATIMDMA) && (uDMAIdx != TYPE_BEACONDMA)) {
PSTxDataHead_a_FB pBuf = (PSTxDataHead_a_FB)pTxDataHead;
BBvCalculateParameter(pDevice, cbFrameLength, wCurrentRate, byPktType,
(u16 *)&(pBuf->wTransmitLength), (u8 *)&(pBuf->byServiceField), (u8 *)&(pBuf->bySignalField)
);
pBuf->wDuration = (u16)s_uGetDataDuration(pDevice, DATADUR_A, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx, cbLastFragmentSize, uMACfragNum, byFBOption);
pBuf->wDuration_f0 = (u16)s_uGetDataDuration(pDevice, DATADUR_A_F0, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx, cbLastFragmentSize, uMACfragNum, byFBOption);
pBuf->wDuration_f1 = (u16)s_uGetDataDuration(pDevice, DATADUR_A_F1, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx, cbLastFragmentSize, uMACfragNum, byFBOption);
if(uDMAIdx!=TYPE_ATIMDMA) {
pBuf->wTimeStampOff = wTimeStampOff[pDevice->byPreambleType%2][wCurrentRate%MAX_RATE];
}
return (pBuf->wDuration);
} else {
PSTxDataHead_ab pBuf = (PSTxDataHead_ab)pTxDataHead;
BBvCalculateParameter(pDevice, cbFrameLength, wCurrentRate, byPktType,
(u16 *)&(pBuf->wTransmitLength), (u8 *)&(pBuf->byServiceField), (u8 *)&(pBuf->bySignalField)
);
pBuf->wDuration = (u16)s_uGetDataDuration(pDevice, DATADUR_A, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx,
cbLastFragmentSize, uMACfragNum,
byFBOption);
if(uDMAIdx!=TYPE_ATIMDMA) {
pBuf->wTimeStampOff = wTimeStampOff[pDevice->byPreambleType%2][wCurrentRate%MAX_RATE];
}
return (pBuf->wDuration);
}
}
else if (byPktType == PK_TYPE_11B) {
PSTxDataHead_ab pBuf = (PSTxDataHead_ab)pTxDataHead;
BBvCalculateParameter(pDevice, cbFrameLength, wCurrentRate, byPktType,
(u16 *)&(pBuf->wTransmitLength), (u8 *)&(pBuf->byServiceField), (u8 *)&(pBuf->bySignalField)
);
pBuf->wDuration = (u16)s_uGetDataDuration(pDevice, DATADUR_B, cbFrameLength, byPktType,
wCurrentRate, bNeedAck, uFragIdx,
cbLastFragmentSize, uMACfragNum,
byFBOption);
if (uDMAIdx != TYPE_ATIMDMA) {
pBuf->wTimeStampOff = wTimeStampOff[pDevice->byPreambleType%2][wCurrentRate%MAX_RATE];
}
return (pBuf->wDuration);
}
return 0;
}
static void s_vFillRTSHead(struct vnt_private *pDevice, u8 byPktType,
void *pvRTS, u32 cbFrameLength, int bNeedAck, int bDisCRC,
struct ethhdr *psEthHeader, u16 wCurrentRate, u8 byFBOption)
{
u32 uRTSFrameLen = 20;
u16 wLen = 0;
if (pvRTS == NULL)
return;
if (bDisCRC) {
uRTSFrameLen -= 4;
}
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
if (byFBOption == AUTO_FB_NONE) {
PSRTS_g pBuf = (PSRTS_g)pvRTS;
BBvCalculateParameter(pDevice, uRTSFrameLen, pDevice->byTopCCKBasicRate, PK_TYPE_11B,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField_b), (u8 *)&(pBuf->bySignalField_b)
);
pBuf->wTransmitLength_b = cpu_to_le16(wLen);
BBvCalculateParameter(pDevice, uRTSFrameLen, pDevice->byTopOFDMBasicRate, byPktType,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField_a), (u8 *)&(pBuf->bySignalField_a)
);
pBuf->wTransmitLength_a = cpu_to_le16(wLen);
pBuf->wDuration_bb = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_BB, cbFrameLength, PK_TYPE_11B, pDevice->byTopCCKBasicRate, bNeedAck, byFBOption));
pBuf->wDuration_aa = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_AA, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wDuration_ba = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_BA, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->Data.wDurationID = pBuf->wDuration_aa;
pBuf->Data.wFrameControl = TYPE_CTL_RTS;
if ((pDevice->eOPMode == OP_MODE_ADHOC) ||
(pDevice->eOPMode == OP_MODE_AP)) {
memcpy(&(pBuf->Data.abyRA[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
}
else {
memcpy(&(pBuf->Data.abyRA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
}
if (pDevice->eOPMode == OP_MODE_AP) {
memcpy(&(pBuf->Data.abyTA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
}
else {
memcpy(&(pBuf->Data.abyTA[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
}
}
else {
PSRTS_g_FB pBuf = (PSRTS_g_FB)pvRTS;
BBvCalculateParameter(pDevice, uRTSFrameLen, pDevice->byTopCCKBasicRate, PK_TYPE_11B,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField_b), (u8 *)&(pBuf->bySignalField_b)
);
pBuf->wTransmitLength_b = cpu_to_le16(wLen);
BBvCalculateParameter(pDevice, uRTSFrameLen, pDevice->byTopOFDMBasicRate, byPktType,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField_a), (u8 *)&(pBuf->bySignalField_a)
);
pBuf->wTransmitLength_a = cpu_to_le16(wLen);
pBuf->wDuration_bb = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_BB, cbFrameLength, PK_TYPE_11B, pDevice->byTopCCKBasicRate, bNeedAck, byFBOption));
pBuf->wDuration_aa = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_AA, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wDuration_ba = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_BA, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wRTSDuration_ba_f0 = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_BA_F0, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wRTSDuration_aa_f0 = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_AA_F0, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wRTSDuration_ba_f1 = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_BA_F1, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wRTSDuration_aa_f1 = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_AA_F1, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->Data.wDurationID = pBuf->wDuration_aa;
pBuf->Data.wFrameControl = TYPE_CTL_RTS;
if ((pDevice->eOPMode == OP_MODE_ADHOC) ||
(pDevice->eOPMode == OP_MODE_AP)) {
memcpy(&(pBuf->Data.abyRA[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
}
else {
memcpy(&(pBuf->Data.abyRA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
}
if (pDevice->eOPMode == OP_MODE_AP) {
memcpy(&(pBuf->Data.abyTA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
}
else {
memcpy(&(pBuf->Data.abyTA[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
}
}
}
else if (byPktType == PK_TYPE_11A) {
if (byFBOption == AUTO_FB_NONE) {
PSRTS_ab pBuf = (PSRTS_ab)pvRTS;
BBvCalculateParameter(pDevice, uRTSFrameLen, pDevice->byTopOFDMBasicRate, byPktType,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField), (u8 *)&(pBuf->bySignalField)
);
pBuf->wTransmitLength = cpu_to_le16(wLen);
pBuf->wDuration = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_AA, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->Data.wDurationID = pBuf->wDuration;
pBuf->Data.wFrameControl = TYPE_CTL_RTS;
if ((pDevice->eOPMode == OP_MODE_ADHOC) ||
(pDevice->eOPMode == OP_MODE_AP)) {
memcpy(&(pBuf->Data.abyRA[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
} else {
memcpy(&(pBuf->Data.abyRA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
}
if (pDevice->eOPMode == OP_MODE_AP) {
memcpy(&(pBuf->Data.abyTA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
} else {
memcpy(&(pBuf->Data.abyTA[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
}
}
else {
PSRTS_a_FB pBuf = (PSRTS_a_FB)pvRTS;
BBvCalculateParameter(pDevice, uRTSFrameLen, pDevice->byTopOFDMBasicRate, byPktType,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField), (u8 *)&(pBuf->bySignalField)
);
pBuf->wTransmitLength = cpu_to_le16(wLen);
pBuf->wDuration = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_AA, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wRTSDuration_f0 = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_AA_F0, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wRTSDuration_f1 = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_AA_F1, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->Data.wDurationID = pBuf->wDuration;
pBuf->Data.wFrameControl = TYPE_CTL_RTS;
if ((pDevice->eOPMode == OP_MODE_ADHOC) ||
(pDevice->eOPMode == OP_MODE_AP)) {
memcpy(&(pBuf->Data.abyRA[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
} else {
memcpy(&(pBuf->Data.abyRA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
}
if (pDevice->eOPMode == OP_MODE_AP) {
memcpy(&(pBuf->Data.abyTA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
} else {
memcpy(&(pBuf->Data.abyTA[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
}
}
}
else if (byPktType == PK_TYPE_11B) {
PSRTS_ab pBuf = (PSRTS_ab)pvRTS;
BBvCalculateParameter(pDevice, uRTSFrameLen, pDevice->byTopCCKBasicRate, PK_TYPE_11B,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField), (u8 *)&(pBuf->bySignalField)
);
pBuf->wTransmitLength = cpu_to_le16(wLen);
pBuf->wDuration = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, RTSDUR_BB, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->Data.wDurationID = pBuf->wDuration;
pBuf->Data.wFrameControl = TYPE_CTL_RTS;
if ((pDevice->eOPMode == OP_MODE_ADHOC) ||
(pDevice->eOPMode == OP_MODE_AP)) {
memcpy(&(pBuf->Data.abyRA[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
}
else {
memcpy(&(pBuf->Data.abyRA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
}
if (pDevice->eOPMode == OP_MODE_AP) {
memcpy(&(pBuf->Data.abyTA[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
} else {
memcpy(&(pBuf->Data.abyTA[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
}
}
}
static void s_vFillCTSHead(struct vnt_private *pDevice, u32 uDMAIdx,
u8 byPktType, void *pvCTS, u32 cbFrameLength, int bNeedAck,
int bDisCRC, u16 wCurrentRate, u8 byFBOption)
{
u32 uCTSFrameLen = 14;
u16 wLen = 0;
if (pvCTS == NULL) {
return;
}
if (bDisCRC) {
uCTSFrameLen -= 4;
}
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
if (byFBOption != AUTO_FB_NONE && uDMAIdx != TYPE_ATIMDMA && uDMAIdx != TYPE_BEACONDMA) {
PSCTS_FB pBuf = (PSCTS_FB)pvCTS;
BBvCalculateParameter(pDevice, uCTSFrameLen, pDevice->byTopCCKBasicRate, PK_TYPE_11B,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField_b), (u8 *)&(pBuf->bySignalField_b)
);
pBuf->wTransmitLength_b = cpu_to_le16(wLen);
pBuf->wDuration_ba = (u16)s_uGetRTSCTSDuration(pDevice, CTSDUR_BA, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption);
pBuf->wDuration_ba += pDevice->wCTSDuration;
pBuf->wDuration_ba = cpu_to_le16(pBuf->wDuration_ba);
pBuf->wCTSDuration_ba_f0 = (u16)s_uGetRTSCTSDuration(pDevice, CTSDUR_BA_F0, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption);
pBuf->wCTSDuration_ba_f0 += pDevice->wCTSDuration;
pBuf->wCTSDuration_ba_f0 = cpu_to_le16(pBuf->wCTSDuration_ba_f0);
pBuf->wCTSDuration_ba_f1 = (u16)s_uGetRTSCTSDuration(pDevice, CTSDUR_BA_F1, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption);
pBuf->wCTSDuration_ba_f1 += pDevice->wCTSDuration;
pBuf->wCTSDuration_ba_f1 = cpu_to_le16(pBuf->wCTSDuration_ba_f1);
pBuf->Data.wDurationID = pBuf->wDuration_ba;
pBuf->Data.wFrameControl = TYPE_CTL_CTS;
pBuf->Data.wReserved = 0x0000;
memcpy(&(pBuf->Data.abyRA[0]),
&(pDevice->abyCurrentNetAddr[0]),
ETH_ALEN);
} else {
PSCTS pBuf = (PSCTS)pvCTS;
BBvCalculateParameter(pDevice, uCTSFrameLen, pDevice->byTopCCKBasicRate, PK_TYPE_11B,
(u16 *)&(wLen), (u8 *)&(pBuf->byServiceField_b), (u8 *)&(pBuf->bySignalField_b)
);
pBuf->wTransmitLength_b = cpu_to_le16(wLen);
pBuf->wDuration_ba = cpu_to_le16((u16)s_uGetRTSCTSDuration(pDevice, CTSDUR_BA, cbFrameLength, byPktType, wCurrentRate, bNeedAck, byFBOption));
pBuf->wDuration_ba += pDevice->wCTSDuration;
pBuf->wDuration_ba = cpu_to_le16(pBuf->wDuration_ba);
pBuf->Data.wDurationID = pBuf->wDuration_ba;
pBuf->Data.wFrameControl = TYPE_CTL_CTS;
pBuf->Data.wReserved = 0x0000;
memcpy(&(pBuf->Data.abyRA[0]),
&(pDevice->abyCurrentNetAddr[0]),
ETH_ALEN);
}
}
}
static void s_vGenerateTxParameter(struct vnt_private *pDevice,
u8 byPktType, u16 wCurrentRate, void *pTxBufHead, void *pvRrvTime,
void *pvRTS, void *pvCTS, u32 cbFrameSize, int bNeedACK, u32 uDMAIdx,
struct ethhdr *psEthHeader)
{
u32 cbMACHdLen = WLAN_HDR_ADDR3_LEN;
u16 wFifoCtl;
int bDisCRC = false;
u8 byFBOption = AUTO_FB_NONE;
PSTxBufHead pFifoHead = (PSTxBufHead)pTxBufHead;
pFifoHead->wReserved = wCurrentRate;
wFifoCtl = pFifoHead->wFIFOCtl;
if (wFifoCtl & FIFOCTL_CRCDIS) {
bDisCRC = true;
}
if (wFifoCtl & FIFOCTL_AUTO_FB_0) {
byFBOption = AUTO_FB_0;
}
else if (wFifoCtl & FIFOCTL_AUTO_FB_1) {
byFBOption = AUTO_FB_1;
}
if (pDevice->bLongHeader)
cbMACHdLen = WLAN_HDR_ADDR3_LEN + 6;
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
if (pvRTS != NULL) {
if (pvRrvTime) {
PSRrvTime_gRTS pBuf = (PSRrvTime_gRTS)pvRrvTime;
pBuf->wRTSTxRrvTime_aa = cpu_to_le16((u16)s_uGetRTSCTSRsvTime(pDevice, 2, byPktType, cbFrameSize, wCurrentRate));
pBuf->wRTSTxRrvTime_ba = cpu_to_le16((u16)s_uGetRTSCTSRsvTime(pDevice, 1, byPktType, cbFrameSize, wCurrentRate));
pBuf->wRTSTxRrvTime_bb = cpu_to_le16((u16)s_uGetRTSCTSRsvTime(pDevice, 0, byPktType, cbFrameSize, wCurrentRate));
pBuf->wTxRrvTime_a = cpu_to_le16((u16) s_uGetTxRsvTime(pDevice, byPktType, cbFrameSize, wCurrentRate, bNeedACK));
pBuf->wTxRrvTime_b = cpu_to_le16((u16) s_uGetTxRsvTime(pDevice, PK_TYPE_11B, cbFrameSize, pDevice->byTopCCKBasicRate, bNeedACK));
}
s_vFillRTSHead(pDevice, byPktType, pvRTS, cbFrameSize, bNeedACK, bDisCRC, psEthHeader, wCurrentRate, byFBOption);
}
else {
if (pvRrvTime) {
PSRrvTime_gCTS pBuf = (PSRrvTime_gCTS)pvRrvTime;
pBuf->wTxRrvTime_a = cpu_to_le16((u16)s_uGetTxRsvTime(pDevice, byPktType, cbFrameSize, wCurrentRate, bNeedACK));
pBuf->wTxRrvTime_b = cpu_to_le16((u16)s_uGetTxRsvTime(pDevice, PK_TYPE_11B, cbFrameSize, pDevice->byTopCCKBasicRate, bNeedACK));
pBuf->wCTSTxRrvTime_ba = cpu_to_le16((u16)s_uGetRTSCTSRsvTime(pDevice, 3, byPktType, cbFrameSize, wCurrentRate));
}
s_vFillCTSHead(pDevice, uDMAIdx, byPktType, pvCTS, cbFrameSize, bNeedACK, bDisCRC, wCurrentRate, byFBOption);
}
}
else if (byPktType == PK_TYPE_11A) {
if (pvRTS != NULL) {
if (pvRrvTime) {
PSRrvTime_ab pBuf = (PSRrvTime_ab)pvRrvTime;
pBuf->wRTSTxRrvTime = cpu_to_le16((u16)s_uGetRTSCTSRsvTime(pDevice, 2, byPktType, cbFrameSize, wCurrentRate));
pBuf->wTxRrvTime = cpu_to_le16((u16)s_uGetTxRsvTime(pDevice, byPktType, cbFrameSize, wCurrentRate, bNeedACK));
}
s_vFillRTSHead(pDevice, byPktType, pvRTS, cbFrameSize, bNeedACK, bDisCRC, psEthHeader, wCurrentRate, byFBOption);
}
else if (pvRTS == NULL) {
if (pvRrvTime) {
PSRrvTime_ab pBuf = (PSRrvTime_ab)pvRrvTime;
pBuf->wTxRrvTime = cpu_to_le16((u16)s_uGetTxRsvTime(pDevice, PK_TYPE_11A, cbFrameSize, wCurrentRate, bNeedACK));
}
}
}
else if (byPktType == PK_TYPE_11B) {
if ((pvRTS != NULL)) {
if (pvRrvTime) {
PSRrvTime_ab pBuf = (PSRrvTime_ab)pvRrvTime;
pBuf->wRTSTxRrvTime = cpu_to_le16((u16)s_uGetRTSCTSRsvTime(pDevice, 0, byPktType, cbFrameSize, wCurrentRate));
pBuf->wTxRrvTime = cpu_to_le16((u16)s_uGetTxRsvTime(pDevice, PK_TYPE_11B, cbFrameSize, wCurrentRate, bNeedACK));
}
s_vFillRTSHead(pDevice, byPktType, pvRTS, cbFrameSize, bNeedACK, bDisCRC, psEthHeader, wCurrentRate, byFBOption);
}
else {
if (pvRrvTime) {
PSRrvTime_ab pBuf = (PSRrvTime_ab)pvRrvTime;
pBuf->wTxRrvTime = cpu_to_le16((u16)s_uGetTxRsvTime(pDevice, PK_TYPE_11B, cbFrameSize, wCurrentRate, bNeedACK));
}
}
}
}
static int s_bPacketToWirelessUsb(struct vnt_private *pDevice, u8 byPktType,
u8 *usbPacketBuf, int bNeedEncryption, u32 uSkbPacketLen, u32 uDMAIdx,
struct ethhdr *psEthHeader, u8 *pPacket, PSKeyItem pTransmitKey,
u32 uNodeIndex, u16 wCurrentRate, u32 *pcbHeaderLen, u32 *pcbTotalLen)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
u32 cbFrameSize, cbFrameBodySize;
PTX_BUFFER pTxBufHead;
u32 cb802_1_H_len;
u32 cbIVlen = 0, cbICVlen = 0, cbMIClen = 0, cbMACHdLen = 0;
u32 cbFCSlen = 4, cbMICHDR = 0;
int bNeedACK, bRTS;
u8 *pbyType, *pbyMacHdr, *pbyIVHead, *pbyPayloadHead, *pbyTxBufferAddr;
u8 abySNAP_RFC1042[ETH_ALEN] = {0xAA, 0xAA, 0x03, 0x00, 0x00, 0x00};
u8 abySNAP_Bridgetunnel[ETH_ALEN]
= {0xAA, 0xAA, 0x03, 0x00, 0x00, 0xF8};
u32 uDuration;
u32 cbHeaderLength = 0, uPadding = 0;
void *pvRrvTime;
PSMICHDRHead pMICHDR;
void *pvRTS;
void *pvCTS;
void *pvTxDataHd;
u8 byFBOption = AUTO_FB_NONE, byFragType;
u16 wTxBufSize;
u32 dwMICKey0, dwMICKey1, dwMIC_Priority, dwCRC;
u32 *pdwMIC_L, *pdwMIC_R;
int bSoftWEP = false;
pvRrvTime = pMICHDR = pvRTS = pvCTS = pvTxDataHd = NULL;
if (bNeedEncryption && pTransmitKey->pvKeyTable) {
if (((PSKeyTable)pTransmitKey->pvKeyTable)->bSoftWEP == true)
bSoftWEP = true;
}
pTxBufHead = (PTX_BUFFER) usbPacketBuf;
memset(pTxBufHead, 0, sizeof(TX_BUFFER));
if (ntohs(psEthHeader->h_proto) > ETH_DATA_LEN) {
if (pDevice->dwDiagRefCount == 0) {
cb802_1_H_len = 8;
} else {
cb802_1_H_len = 2;
}
} else {
cb802_1_H_len = 0;
}
cbFrameBodySize = uSkbPacketLen - ETH_HLEN + cb802_1_H_len;
pTxBufHead->wFIFOCtl |= (u16)(byPktType<<8);
if (pDevice->dwDiagRefCount != 0) {
bNeedACK = false;
pTxBufHead->wFIFOCtl = pTxBufHead->wFIFOCtl & (~FIFOCTL_NEEDACK);
} else {
if ((pDevice->eOPMode == OP_MODE_ADHOC) ||
(pDevice->eOPMode == OP_MODE_AP)) {
if (is_multicast_ether_addr(psEthHeader->h_dest)) {
bNeedACK = false;
pTxBufHead->wFIFOCtl =
pTxBufHead->wFIFOCtl & (~FIFOCTL_NEEDACK);
} else {
bNeedACK = true;
pTxBufHead->wFIFOCtl |= FIFOCTL_NEEDACK;
}
}
else {
bNeedACK = true;
pTxBufHead->wFIFOCtl |= FIFOCTL_NEEDACK;
}
}
pTxBufHead->wTimeStamp = DEFAULT_MSDU_LIFETIME_RES_64us;
if (pDevice->bLongHeader)
pTxBufHead->wFIFOCtl |= FIFOCTL_LHEAD;
if (pDevice->bSoftwareGenCrcErr) {
pTxBufHead->wFIFOCtl |= FIFOCTL_CRCDIS;
}
if (pDevice->bLongHeader) {
cbMACHdLen = WLAN_HDR_ADDR3_LEN + 6;
} else {
cbMACHdLen = WLAN_HDR_ADDR3_LEN;
}
pTxBufHead->wFragCtl |= (u16)(cbMACHdLen << 10);
if (pDevice->bGrpAckPolicy == true) {
pTxBufHead->wFIFOCtl |= FIFOCTL_GRPACK;
}
if (wCurrentRate >= RATE_18M) {
if (pDevice->byAutoFBCtrl == AUTO_FB_0) {
pTxBufHead->wFIFOCtl |= FIFOCTL_AUTO_FB_0;
byFBOption = AUTO_FB_0;
} else if (pDevice->byAutoFBCtrl == AUTO_FB_1) {
pTxBufHead->wFIFOCtl |= FIFOCTL_AUTO_FB_1;
byFBOption = AUTO_FB_1;
}
}
if (bSoftWEP != true) {
if ((bNeedEncryption) && (pTransmitKey != NULL)) {
if (pTransmitKey->byCipherSuite == KEY_CTL_WEP) {
pTxBufHead->wFragCtl |= FRAGCTL_LEGACY;
}
if (pTransmitKey->byCipherSuite == KEY_CTL_TKIP) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Tx Set wFragCtl == FRAGCTL_TKIP\n");
pTxBufHead->wFragCtl |= FRAGCTL_TKIP;
}
else if (pTransmitKey->byCipherSuite == KEY_CTL_CCMP) {
pTxBufHead->wFragCtl |= FRAGCTL_AES;
}
}
}
if ((bNeedEncryption) && (pTransmitKey != NULL)) {
if (pTransmitKey->byCipherSuite == KEY_CTL_WEP) {
cbIVlen = 4;
cbICVlen = 4;
}
else if (pTransmitKey->byCipherSuite == KEY_CTL_TKIP) {
cbIVlen = 8;
cbMIClen = 8;
cbICVlen = 4;
}
if (pTransmitKey->byCipherSuite == KEY_CTL_CCMP) {
cbIVlen = 8;
cbICVlen = 8;
cbMICHDR = sizeof(SMICHDRHead);
}
if (bSoftWEP == false) {
uPadding = 4 - (cbMACHdLen%4);
uPadding %= 4;
}
}
cbFrameSize = cbMACHdLen + cbIVlen + (cbFrameBodySize + cbMIClen) + cbICVlen + cbFCSlen;
if ( (bNeedACK == false) ||(cbFrameSize < pDevice->wRTSThreshold) ) {
bRTS = false;
} else {
bRTS = true;
pTxBufHead->wFIFOCtl |= (FIFOCTL_RTS | FIFOCTL_LRETRY);
}
pbyTxBufferAddr = (u8 *) &(pTxBufHead->adwTxKey[0]);
wTxBufSize = sizeof(STxBufHead);
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
if (byFBOption == AUTO_FB_NONE) {
if (bRTS == true) {
pvRrvTime = (PSRrvTime_gRTS) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gRTS));
pvRTS = (PSRTS_g) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gRTS) + cbMICHDR);
pvCTS = NULL;
pvTxDataHd = (PSTxDataHead_g) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gRTS) + cbMICHDR + sizeof(SRTS_g));
cbHeaderLength = wTxBufSize + sizeof(SRrvTime_gRTS) + cbMICHDR + sizeof(SRTS_g) + sizeof(STxDataHead_g);
}
else {
pvRrvTime = (PSRrvTime_gCTS) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS));
pvRTS = NULL;
pvCTS = (PSCTS) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR);
pvTxDataHd = (PSTxDataHead_g) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR + sizeof(SCTS));
cbHeaderLength = wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR + sizeof(SCTS) + sizeof(STxDataHead_g);
}
} else {
if (bRTS == true) {
pvRrvTime = (PSRrvTime_gRTS) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gRTS));
pvRTS = (PSRTS_g_FB) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gRTS) + cbMICHDR);
pvCTS = NULL;
pvTxDataHd = (PSTxDataHead_g_FB) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gRTS) + cbMICHDR + sizeof(SRTS_g_FB));
cbHeaderLength = wTxBufSize + sizeof(SRrvTime_gRTS) + cbMICHDR + sizeof(SRTS_g_FB) + sizeof(STxDataHead_g_FB);
}
else if (bRTS == false) {
pvRrvTime = (PSRrvTime_gCTS) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS));
pvRTS = NULL;
pvCTS = (PSCTS_FB) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR);
pvTxDataHd = (PSTxDataHead_g_FB) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR + sizeof(SCTS_FB));
cbHeaderLength = wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR + sizeof(SCTS_FB) + sizeof(STxDataHead_g_FB);
}
}
}
else {
if (byFBOption == AUTO_FB_NONE) {
if (bRTS == true) {
pvRrvTime = (PSRrvTime_ab) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab));
pvRTS = (PSRTS_ab) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR);
pvCTS = NULL;
pvTxDataHd = (PSTxDataHead_ab) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR + sizeof(SRTS_ab));
cbHeaderLength = wTxBufSize + sizeof(PSRrvTime_ab) + cbMICHDR + sizeof(SRTS_ab) + sizeof(STxDataHead_ab);
}
else if (bRTS == false) {
pvRrvTime = (PSRrvTime_ab) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab));
pvRTS = NULL;
pvCTS = NULL;
pvTxDataHd = (PSTxDataHead_ab) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR);
cbHeaderLength = wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR + sizeof(STxDataHead_ab);
}
} else {
if (bRTS == true) {
pvRrvTime = (PSRrvTime_ab) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab));
pvRTS = (PSRTS_a_FB) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR);
pvCTS = NULL;
pvTxDataHd = (PSTxDataHead_a_FB) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR + sizeof(SRTS_a_FB));
cbHeaderLength = wTxBufSize + sizeof(PSRrvTime_ab) + cbMICHDR + sizeof(SRTS_a_FB) + sizeof(STxDataHead_a_FB);
}
else if (bRTS == false) {
pvRrvTime = (PSRrvTime_ab) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab));
pvRTS = NULL;
pvCTS = NULL;
pvTxDataHd = (PSTxDataHead_a_FB) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR);
cbHeaderLength = wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR + sizeof(STxDataHead_a_FB);
}
}
}
pbyMacHdr = (u8 *)(pbyTxBufferAddr + cbHeaderLength);
pbyIVHead = (u8 *)(pbyMacHdr + cbMACHdLen + uPadding);
pbyPayloadHead = (u8 *)(pbyMacHdr + cbMACHdLen + uPadding + cbIVlen);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"No Fragmentation...\n");
byFragType = FRAGCTL_NONFRAG;
s_vGenerateTxParameter(pDevice, byPktType, wCurrentRate,
(void *)pbyTxBufferAddr, pvRrvTime, pvRTS, pvCTS,
cbFrameSize, bNeedACK, uDMAIdx, psEthHeader);
uDuration = s_uFillDataHead(pDevice, byPktType, wCurrentRate, pvTxDataHd, cbFrameSize, uDMAIdx, bNeedACK,
0, 0, 1, byFBOption);
s_vGenerateMACHeader(pDevice, pbyMacHdr, (u16)uDuration, psEthHeader, bNeedEncryption,
byFragType, uDMAIdx, 0);
if (bNeedEncryption == true) {
s_vFillTxKey(pDevice, (u8 *)(pTxBufHead->adwTxKey), pbyIVHead, pTransmitKey,
pbyMacHdr, (u16)cbFrameBodySize, (u8 *)pMICHDR);
if (pDevice->bEnableHostWEP) {
pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16 = pTransmitKey->dwTSC47_16;
pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0 = pTransmitKey->wTSC15_0;
}
}
if (ntohs(psEthHeader->h_proto) > ETH_DATA_LEN) {
if (pDevice->dwDiagRefCount == 0) {
if ((psEthHeader->h_proto == cpu_to_be16(ETH_P_IPX)) ||
(psEthHeader->h_proto == cpu_to_le16(0xF380))) {
memcpy((u8 *) (pbyPayloadHead),
abySNAP_Bridgetunnel, 6);
} else {
memcpy((u8 *) (pbyPayloadHead), &abySNAP_RFC1042[0], 6);
}
pbyType = (u8 *) (pbyPayloadHead + 6);
memcpy(pbyType, &(psEthHeader->h_proto), sizeof(u16));
} else {
memcpy((u8 *) (pbyPayloadHead), &(psEthHeader->h_proto), sizeof(u16));
}
}
if (pPacket != NULL) {
memcpy((pbyPayloadHead + cb802_1_H_len),
(pPacket + ETH_HLEN),
uSkbPacketLen - ETH_HLEN
);
} else {
memcpy((pbyPayloadHead + cb802_1_H_len), ((u8 *)psEthHeader) + ETH_HLEN, uSkbPacketLen - ETH_HLEN);
}
ASSERT(uLength == cbNdisBodySize);
if ((bNeedEncryption == true) && (pTransmitKey != NULL) && (pTransmitKey->byCipherSuite == KEY_CTL_TKIP)) {
if (pDevice->vnt_mgmt.eAuthenMode == WMAC_AUTH_WPANONE) {
dwMICKey0 = *(u32 *)(&pTransmitKey->abyKey[16]);
dwMICKey1 = *(u32 *)(&pTransmitKey->abyKey[20]);
}
else if ((pTransmitKey->dwKeyIndex & AUTHENTICATOR_KEY) != 0) {
dwMICKey0 = *(u32 *)(&pTransmitKey->abyKey[16]);
dwMICKey1 = *(u32 *)(&pTransmitKey->abyKey[20]);
}
else {
dwMICKey0 = *(u32 *)(&pTransmitKey->abyKey[24]);
dwMICKey1 = *(u32 *)(&pTransmitKey->abyKey[28]);
}
MIC_vInit(dwMICKey0, dwMICKey1);
MIC_vAppend((u8 *)&(psEthHeader->h_dest[0]), 12);
dwMIC_Priority = 0;
MIC_vAppend((u8 *)&dwMIC_Priority, 4);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"MIC KEY: %X, %X\n",
dwMICKey0, dwMICKey1);
MIC_vAppend(pbyPayloadHead, cbFrameBodySize);
pdwMIC_L = (u32 *)(pbyPayloadHead + cbFrameBodySize);
pdwMIC_R = (u32 *)(pbyPayloadHead + cbFrameBodySize + 4);
MIC_vGetMIC(pdwMIC_L, pdwMIC_R);
MIC_vUnInit();
if (pDevice->bTxMICFail == true) {
*pdwMIC_L = 0;
*pdwMIC_R = 0;
pDevice->bTxMICFail = false;
}
}
if (bSoftWEP == true) {
s_vSWencryption(pDevice, pTransmitKey, (pbyPayloadHead), (u16)(cbFrameBodySize + cbMIClen));
} else if ( ((pDevice->eEncryptionStatus == Ndis802_11Encryption1Enabled) && (bNeedEncryption == true)) ||
((pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) && (bNeedEncryption == true)) ||
((pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) && (bNeedEncryption == true)) ) {
cbFrameSize -= cbICVlen;
}
if (pDevice->bSoftwareGenCrcErr == true) {
unsigned int cbLen;
u32 * pdwCRC;
dwCRC = 0xFFFFFFFFL;
cbLen = cbFrameSize - cbFCSlen;
dwCRC = CRCdwGetCrc32Ex(pbyMacHdr, cbLen, dwCRC);
pdwCRC = (u32 *)(pbyMacHdr + cbLen);
*pdwCRC = ~dwCRC;
*pdwCRC -= 1;
} else {
cbFrameSize -= cbFCSlen;
}
*pcbHeaderLen = cbHeaderLength;
*pcbTotalLen = cbHeaderLength + cbFrameSize ;
pTxBufHead->wFragCtl |= (u16)byFragType;
return true;
}
static void s_vGenerateMACHeader(struct vnt_private *pDevice,
u8 *pbyBufferAddr, u16 wDuration, struct ethhdr *psEthHeader,
int bNeedEncrypt, u16 wFragType, u32 uDMAIdx, u32 uFragIdx)
{
struct ieee80211_hdr *pMACHeader = (struct ieee80211_hdr *)pbyBufferAddr;
memset(pMACHeader, 0, (sizeof(struct ieee80211_hdr)));
if (uDMAIdx == TYPE_ATIMDMA) {
pMACHeader->frame_control = TYPE_802_11_ATIM;
} else {
pMACHeader->frame_control = TYPE_802_11_DATA;
}
if (pDevice->eOPMode == OP_MODE_AP) {
memcpy(&(pMACHeader->addr1[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr2[0]), &(pDevice->abyBSSID[0]), ETH_ALEN);
memcpy(&(pMACHeader->addr3[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
pMACHeader->frame_control |= FC_FROMDS;
} else {
if (pDevice->eOPMode == OP_MODE_ADHOC) {
memcpy(&(pMACHeader->addr1[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr2[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr3[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
} else {
memcpy(&(pMACHeader->addr3[0]),
&(psEthHeader->h_dest[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr2[0]),
&(psEthHeader->h_source[0]),
ETH_ALEN);
memcpy(&(pMACHeader->addr1[0]),
&(pDevice->abyBSSID[0]),
ETH_ALEN);
pMACHeader->frame_control |= FC_TODS;
}
}
if (bNeedEncrypt)
pMACHeader->frame_control |= cpu_to_le16((u16)WLAN_SET_FC_ISWEP(1));
pMACHeader->duration_id = cpu_to_le16(wDuration);
if (pDevice->bLongHeader) {
PWLAN_80211HDR_A4 pMACA4Header = (PWLAN_80211HDR_A4) pbyBufferAddr;
pMACHeader->frame_control |= (FC_TODS | FC_FROMDS);
memcpy(pMACA4Header->abyAddr4, pDevice->abyBSSID, WLAN_ADDR_LEN);
}
pMACHeader->seq_ctrl = cpu_to_le16(pDevice->wSeqCounter << 4);
pMACHeader->seq_ctrl |= cpu_to_le16((u16)uFragIdx);
if ((wFragType == FRAGCTL_ENDFRAG) || (wFragType == FRAGCTL_NONFRAG)) {
pDevice->wSeqCounter++;
if (pDevice->wSeqCounter > 0x0fff)
pDevice->wSeqCounter = 0;
}
if ((wFragType == FRAGCTL_STAFRAG) || (wFragType == FRAGCTL_MIDFRAG)) {
pMACHeader->frame_control |= FC_MOREFRAG;
}
}
CMD_STATUS csMgmt_xmit(struct vnt_private *pDevice,
struct vnt_tx_mgmt *pPacket)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
PTX_BUFFER pTX_Buffer;
PSTxBufHead pTxBufHead;
PUSB_SEND_CONTEXT pContext;
struct ieee80211_hdr *pMACHeader;
PSCTS pCTS;
struct ethhdr sEthHeader;
u8 byPktType, *pbyTxBufferAddr;
void *pvRTS, *pvTxDataHd, *pvRrvTime, *pMICHDR;
u32 uDuration, cbReqCount, cbHeaderSize, cbFrameBodySize, cbFrameSize;
int bNeedACK, bIsPSPOLL = false;
u32 cbIVlen = 0, cbICVlen = 0, cbMIClen = 0, cbFCSlen = 4;
u32 uPadding = 0;
u16 wTxBufSize;
u32 cbMacHdLen;
u16 wCurrentRate = RATE_1M;
pContext = (PUSB_SEND_CONTEXT)s_vGetFreeContext(pDevice);
if (NULL == pContext) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ManagementSend TX...NO CONTEXT!\n");
return CMD_STATUS_RESOURCES;
}
pTX_Buffer = (PTX_BUFFER) (&pContext->Data[0]);
pbyTxBufferAddr = (u8 *)&(pTX_Buffer->adwTxKey[0]);
cbFrameBodySize = pPacket->cbPayloadLen;
pTxBufHead = (PSTxBufHead) pbyTxBufferAddr;
wTxBufSize = sizeof(STxBufHead);
memset(pTxBufHead, 0, wTxBufSize);
if (pDevice->byBBType == BB_TYPE_11A) {
wCurrentRate = RATE_6M;
byPktType = PK_TYPE_11A;
} else {
wCurrentRate = RATE_1M;
byPktType = PK_TYPE_11B;
}
if (pMgmt->eScanState != WMAC_NO_SCANNING) {
RFbSetPower(pDevice, wCurrentRate, pDevice->byCurrentCh);
} else {
RFbSetPower(pDevice, wCurrentRate, pMgmt->uCurrChannel);
}
pDevice->wCurrentRate = wCurrentRate;
if (byPktType == PK_TYPE_11A) {
pTxBufHead->wFIFOCtl = 0;
}
else if (byPktType == PK_TYPE_11B) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11B;
}
else if (byPktType == PK_TYPE_11GB) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11GB;
}
else if (byPktType == PK_TYPE_11GA) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11GA;
}
pTxBufHead->wFIFOCtl |= FIFOCTL_TMOEN;
pTxBufHead->wTimeStamp = cpu_to_le16(DEFAULT_MGN_LIFETIME_RES_64us);
if (is_multicast_ether_addr(pPacket->p80211Header->sA3.abyAddr1)) {
bNeedACK = false;
}
else {
bNeedACK = true;
pTxBufHead->wFIFOCtl |= FIFOCTL_NEEDACK;
};
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) ||
(pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) ) {
pTxBufHead->wFIFOCtl |= FIFOCTL_LRETRY;
}
pTxBufHead->wFIFOCtl |= (FIFOCTL_GENINT | FIFOCTL_ISDMA0);
if ((pPacket->p80211Header->sA4.wFrameCtl & TYPE_SUBTYPE_MASK) == TYPE_CTL_PSPOLL) {
bIsPSPOLL = true;
cbMacHdLen = WLAN_HDR_ADDR2_LEN;
} else {
cbMacHdLen = WLAN_HDR_ADDR3_LEN;
}
pTxBufHead->wFragCtl |= cpu_to_le16((u16)(cbMacHdLen << 10));
pDevice->bAES = false;
if (WLAN_GET_FC_ISWEP(pPacket->p80211Header->sA4.wFrameCtl) != 0) {
if (pDevice->eEncryptionStatus == Ndis802_11Encryption1Enabled) {
cbIVlen = 4;
cbICVlen = 4;
pTxBufHead->wFragCtl |= FRAGCTL_LEGACY;
}
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) {
cbIVlen = 8;
cbMIClen = 8;
cbICVlen = 4;
pTxBufHead->wFragCtl |= FRAGCTL_TKIP;
}
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) {
cbIVlen = 8;
cbICVlen = 8;
pTxBufHead->wFragCtl |= FRAGCTL_AES;
pDevice->bAES = true;
}
uPadding = 4 - (cbMacHdLen%4);
uPadding %= 4;
}
cbFrameSize = cbMacHdLen + cbFrameBodySize + cbIVlen + cbMIClen + cbICVlen + cbFCSlen;
if (pDevice->bGrpAckPolicy == true) {
pTxBufHead->wFIFOCtl |= FIFOCTL_GRPACK;
}
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
pvRrvTime = (PSRrvTime_gCTS) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = NULL;
pvRTS = NULL;
pCTS = (PSCTS) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS));
pvTxDataHd = (PSTxDataHead_g) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS) + sizeof(SCTS));
cbHeaderSize = wTxBufSize + sizeof(SRrvTime_gCTS) + sizeof(SCTS) + sizeof(STxDataHead_g);
}
else {
pvRrvTime = (PSRrvTime_ab) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = NULL;
pvRTS = NULL;
pCTS = NULL;
pvTxDataHd = (PSTxDataHead_ab) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab));
cbHeaderSize = wTxBufSize + sizeof(SRrvTime_ab) + sizeof(STxDataHead_ab);
}
memset((void *)(pbyTxBufferAddr + wTxBufSize), 0,
(cbHeaderSize - wTxBufSize));
memcpy(&(sEthHeader.h_dest[0]),
&(pPacket->p80211Header->sA3.abyAddr1[0]),
ETH_ALEN);
memcpy(&(sEthHeader.h_source[0]),
&(pPacket->p80211Header->sA3.abyAddr2[0]),
ETH_ALEN);
pTxBufHead->wFragCtl |= (u16)FRAGCTL_NONFRAG;
s_vGenerateTxParameter(pDevice, byPktType, wCurrentRate, pbyTxBufferAddr, pvRrvTime, pvRTS, pCTS,
cbFrameSize, bNeedACK, TYPE_TXDMA0, &sEthHeader);
uDuration = s_uFillDataHead(pDevice, byPktType, wCurrentRate, pvTxDataHd, cbFrameSize, TYPE_TXDMA0, bNeedACK,
0, 0, 1, AUTO_FB_NONE);
pMACHeader = (struct ieee80211_hdr *) (pbyTxBufferAddr + cbHeaderSize);
cbReqCount = cbHeaderSize + cbMacHdLen + uPadding + cbIVlen + cbFrameBodySize;
if (WLAN_GET_FC_ISWEP(pPacket->p80211Header->sA4.wFrameCtl) != 0) {
u8 * pbyIVHead;
u8 * pbyPayloadHead;
u8 * pbyBSSID;
PSKeyItem pTransmitKey = NULL;
pbyIVHead = (u8 *)(pbyTxBufferAddr + cbHeaderSize + cbMacHdLen + uPadding);
pbyPayloadHead = (u8 *)(pbyTxBufferAddr + cbHeaderSize + cbMacHdLen + uPadding + cbIVlen);
do {
if ((pDevice->eOPMode == OP_MODE_INFRASTRUCTURE) &&
(pDevice->bLinkPass == true)) {
pbyBSSID = pDevice->abyBSSID;
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, PAIRWISE_KEY, &pTransmitKey) == false) {
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Get GTK.\n");
break;
}
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Get PTK.\n");
break;
}
}
pbyBSSID = pDevice->abyBroadcastAddr;
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == false) {
pTransmitKey = NULL;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"KEY is NULL. OP Mode[%d]\n", pDevice->eOPMode);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Get GTK.\n");
}
} while(false);
s_vFillTxKey(pDevice, (u8 *)(pTxBufHead->adwTxKey), pbyIVHead, pTransmitKey,
(u8 *)pMACHeader, (u16)cbFrameBodySize, NULL);
memcpy(pMACHeader, pPacket->p80211Header, cbMacHdLen);
memcpy(pbyPayloadHead, ((u8 *)(pPacket->p80211Header) + cbMacHdLen),
cbFrameBodySize);
}
else {
memcpy(pMACHeader, pPacket->p80211Header, pPacket->cbMPDULen);
}
pMACHeader->seq_ctrl = cpu_to_le16(pDevice->wSeqCounter << 4);
pDevice->wSeqCounter++ ;
if (pDevice->wSeqCounter > 0x0fff)
pDevice->wSeqCounter = 0;
if (bIsPSPOLL) {
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
((PSTxDataHead_g)pvTxDataHd)->wDuration_a = cpu_to_le16(pPacket->p80211Header->sA2.wDurationID);
((PSTxDataHead_g)pvTxDataHd)->wDuration_b = cpu_to_le16(pPacket->p80211Header->sA2.wDurationID);
} else {
((PSTxDataHead_ab)pvTxDataHd)->wDuration = cpu_to_le16(pPacket->p80211Header->sA2.wDurationID);
}
}
pTX_Buffer->wTxByteCount = cpu_to_le16((u16)(cbReqCount));
pTX_Buffer->byPKTNO = (u8) (((wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->byType = 0x00;
pContext->pPacket = NULL;
pContext->Type = CONTEXT_MGMT_PACKET;
pContext->uBufLen = (u16)cbReqCount + 4;
if (WLAN_GET_FC_TODS(pMACHeader->frame_control) == 0) {
s_vSaveTxPktInfo(pDevice, (u8) (pTX_Buffer->byPKTNO & 0x0F), &(pMACHeader->addr1[0]), (u16)cbFrameSize, pTX_Buffer->wFIFOCtl);
}
else {
s_vSaveTxPktInfo(pDevice, (u8) (pTX_Buffer->byPKTNO & 0x0F), &(pMACHeader->addr3[0]), (u16)cbFrameSize, pTX_Buffer->wFIFOCtl);
}
PIPEnsSendBulkOut(pDevice,pContext);
return CMD_STATUS_PENDING;
}
CMD_STATUS csBeacon_xmit(struct vnt_private *pDevice,
struct vnt_tx_mgmt *pPacket)
{
u32 cbFrameSize = pPacket->cbMPDULen + WLAN_FCS_LEN;
u32 cbHeaderSize = 0;
u16 wTxBufSize = sizeof(STxShortBufHead);
PSTxShortBufHead pTxBufHead;
struct ieee80211_hdr *pMACHeader;
PSTxDataHead_ab pTxDataHead;
u16 wCurrentRate;
u32 cbFrameBodySize;
u32 cbReqCount;
PBEACON_BUFFER pTX_Buffer;
u8 *pbyTxBufferAddr;
PUSB_SEND_CONTEXT pContext;
CMD_STATUS status;
pContext = (PUSB_SEND_CONTEXT)s_vGetFreeContext(pDevice);
if (NULL == pContext) {
status = CMD_STATUS_RESOURCES;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ManagementSend TX...NO CONTEXT!\n");
return status ;
}
pTX_Buffer = (PBEACON_BUFFER) (&pContext->Data[0]);
pbyTxBufferAddr = (u8 *)&(pTX_Buffer->wFIFOCtl);
cbFrameBodySize = pPacket->cbPayloadLen;
pTxBufHead = (PSTxShortBufHead) pbyTxBufferAddr;
wTxBufSize = sizeof(STxShortBufHead);
memset(pTxBufHead, 0, wTxBufSize);
if (pDevice->byBBType == BB_TYPE_11A) {
wCurrentRate = RATE_6M;
pTxDataHead = (PSTxDataHead_ab) (pbyTxBufferAddr + wTxBufSize);
BBvCalculateParameter(pDevice, cbFrameSize, wCurrentRate, PK_TYPE_11A,
(u16 *)&(pTxDataHead->wTransmitLength), (u8 *)&(pTxDataHead->byServiceField), (u8 *)&(pTxDataHead->bySignalField)
);
pTxDataHead->wDuration = cpu_to_le16((u16)s_uGetDataDuration(pDevice, DATADUR_A, cbFrameSize, PK_TYPE_11A,
wCurrentRate, false, 0, 0, 1, AUTO_FB_NONE));
pTxDataHead->wTimeStampOff = wTimeStampOff[pDevice->byPreambleType%2][wCurrentRate%MAX_RATE];
cbHeaderSize = wTxBufSize + sizeof(STxDataHead_ab);
} else {
wCurrentRate = RATE_1M;
pTxBufHead->wFIFOCtl |= FIFOCTL_11B;
pTxDataHead = (PSTxDataHead_ab) (pbyTxBufferAddr + wTxBufSize);
BBvCalculateParameter(pDevice, cbFrameSize, wCurrentRate, PK_TYPE_11B,
(u16 *)&(pTxDataHead->wTransmitLength), (u8 *)&(pTxDataHead->byServiceField), (u8 *)&(pTxDataHead->bySignalField)
);
pTxDataHead->wDuration = cpu_to_le16((u16)s_uGetDataDuration(pDevice, DATADUR_B, cbFrameSize, PK_TYPE_11B,
wCurrentRate, false, 0, 0, 1, AUTO_FB_NONE));
pTxDataHead->wTimeStampOff = wTimeStampOff[pDevice->byPreambleType%2][wCurrentRate%MAX_RATE];
cbHeaderSize = wTxBufSize + sizeof(STxDataHead_ab);
}
pMACHeader = (struct ieee80211_hdr *)(pbyTxBufferAddr + cbHeaderSize);
memcpy(pMACHeader, pPacket->p80211Header, pPacket->cbMPDULen);
pMACHeader->duration_id = 0;
pMACHeader->seq_ctrl = cpu_to_le16(pDevice->wSeqCounter << 4);
pDevice->wSeqCounter++ ;
if (pDevice->wSeqCounter > 0x0fff)
pDevice->wSeqCounter = 0;
cbReqCount = cbHeaderSize + WLAN_HDR_ADDR3_LEN + cbFrameBodySize;
pTX_Buffer->wTxByteCount = (u16)cbReqCount;
pTX_Buffer->byPKTNO = (u8) (((wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->byType = 0x01;
pContext->pPacket = NULL;
pContext->Type = CONTEXT_MGMT_PACKET;
pContext->uBufLen = (u16)cbReqCount + 4;
PIPEnsSendBulkOut(pDevice,pContext);
return CMD_STATUS_PENDING;
}
void vDMA0_tx_80211(struct vnt_private *pDevice, struct sk_buff *skb)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
u8 byPktType;
u8 *pbyTxBufferAddr;
void *pvRTS, *pvCTS, *pvTxDataHd;
u32 uDuration, cbReqCount;
struct ieee80211_hdr *pMACHeader;
u32 cbHeaderSize, cbFrameBodySize;
int bNeedACK, bIsPSPOLL = false;
PSTxBufHead pTxBufHead;
u32 cbFrameSize;
u32 cbIVlen = 0, cbICVlen = 0, cbMIClen = 0, cbFCSlen = 4;
u32 uPadding = 0;
u32 cbMICHDR = 0, uLength = 0;
u32 dwMICKey0, dwMICKey1;
u32 dwMIC_Priority;
u32 *pdwMIC_L, *pdwMIC_R;
u16 wTxBufSize;
u32 cbMacHdLen;
struct ethhdr sEthHeader;
void *pvRrvTime, *pMICHDR;
u32 wCurrentRate = RATE_1M;
PUWLAN_80211HDR p80211Header;
u32 uNodeIndex = 0;
int bNodeExist = false;
SKeyItem STempKey;
PSKeyItem pTransmitKey = NULL;
u8 *pbyIVHead, *pbyPayloadHead, *pbyMacHdr;
u32 cbExtSuppRate = 0;
PTX_BUFFER pTX_Buffer;
PUSB_SEND_CONTEXT pContext;
pvRrvTime = pMICHDR = pvRTS = pvCTS = pvTxDataHd = NULL;
if(skb->len <= WLAN_HDR_ADDR3_LEN) {
cbFrameBodySize = 0;
}
else {
cbFrameBodySize = skb->len - WLAN_HDR_ADDR3_LEN;
}
p80211Header = (PUWLAN_80211HDR)skb->data;
pContext = (PUSB_SEND_CONTEXT)s_vGetFreeContext(pDevice);
if (NULL == pContext) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"DMA0 TX...NO CONTEXT!\n");
dev_kfree_skb_irq(skb);
return ;
}
pTX_Buffer = (PTX_BUFFER)(&pContext->Data[0]);
pbyTxBufferAddr = (u8 *)(&pTX_Buffer->adwTxKey[0]);
pTxBufHead = (PSTxBufHead) pbyTxBufferAddr;
wTxBufSize = sizeof(STxBufHead);
memset(pTxBufHead, 0, wTxBufSize);
if (pDevice->byBBType == BB_TYPE_11A) {
wCurrentRate = RATE_6M;
byPktType = PK_TYPE_11A;
} else {
wCurrentRate = RATE_1M;
byPktType = PK_TYPE_11B;
}
if (pMgmt->eScanState != WMAC_NO_SCANNING) {
RFbSetPower(pDevice, wCurrentRate, pDevice->byCurrentCh);
} else {
RFbSetPower(pDevice, wCurrentRate, pMgmt->uCurrChannel);
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"vDMA0_tx_80211: p80211Header->sA3.wFrameCtl = %x \n", p80211Header->sA3.wFrameCtl);
if (byPktType == PK_TYPE_11A) {
pTxBufHead->wFIFOCtl = 0;
}
else if (byPktType == PK_TYPE_11B) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11B;
}
else if (byPktType == PK_TYPE_11GB) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11GB;
}
else if (byPktType == PK_TYPE_11GA) {
pTxBufHead->wFIFOCtl |= FIFOCTL_11GA;
}
pTxBufHead->wFIFOCtl |= FIFOCTL_TMOEN;
pTxBufHead->wTimeStamp = cpu_to_le16(DEFAULT_MGN_LIFETIME_RES_64us);
if (is_multicast_ether_addr(p80211Header->sA3.abyAddr1)) {
bNeedACK = false;
if (pDevice->bEnableHostWEP) {
uNodeIndex = 0;
bNodeExist = true;
}
}
else {
if (pDevice->bEnableHostWEP) {
if (BSSbIsSTAInNodeDB(pDevice, (u8 *)(p80211Header->sA3.abyAddr1), &uNodeIndex))
bNodeExist = true;
}
bNeedACK = true;
pTxBufHead->wFIFOCtl |= FIFOCTL_NEEDACK;
};
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) ||
(pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) ) {
pTxBufHead->wFIFOCtl |= FIFOCTL_LRETRY;
}
pTxBufHead->wFIFOCtl |= (FIFOCTL_GENINT | FIFOCTL_ISDMA0);
if ((p80211Header->sA4.wFrameCtl & TYPE_SUBTYPE_MASK) == TYPE_CTL_PSPOLL) {
bIsPSPOLL = true;
cbMacHdLen = WLAN_HDR_ADDR2_LEN;
} else {
cbMacHdLen = WLAN_HDR_ADDR3_LEN;
}
if (WLAN_GET_FC_FSTYPE(p80211Header->sA4.wFrameCtl) == WLAN_FSTYPE_ASSOCRESP) {
if (((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len != 0) {
cbExtSuppRate += ((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len + WLAN_IEHDR_LEN;
}
if (((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates)->len != 0) {
cbExtSuppRate += ((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates)->len + WLAN_IEHDR_LEN;
}
if (cbExtSuppRate >0) {
cbFrameBodySize = WLAN_ASSOCRESP_OFF_SUPP_RATES;
}
}
pTxBufHead->wFragCtl |= cpu_to_le16((u16)cbMacHdLen << 10);
pDevice->bAES = false;
if (WLAN_GET_FC_ISWEP(p80211Header->sA4.wFrameCtl) != 0) {
if (pDevice->eEncryptionStatus == Ndis802_11Encryption1Enabled) {
cbIVlen = 4;
cbICVlen = 4;
pTxBufHead->wFragCtl |= FRAGCTL_LEGACY;
}
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) {
cbIVlen = 8;
cbMIClen = 8;
cbICVlen = 4;
pTxBufHead->wFragCtl |= FRAGCTL_TKIP;
}
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) {
cbIVlen = 8;
cbICVlen = 8;
cbMICHDR = sizeof(SMICHDRHead);
pTxBufHead->wFragCtl |= FRAGCTL_AES;
pDevice->bAES = true;
}
uPadding = 4 - (cbMacHdLen%4);
uPadding %= 4;
}
cbFrameSize = cbMacHdLen + cbFrameBodySize + cbIVlen + cbMIClen + cbICVlen + cbFCSlen + cbExtSuppRate;
if (pDevice->bGrpAckPolicy == true) {
pTxBufHead->wFIFOCtl |= FIFOCTL_GRPACK;
}
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
pvRrvTime = (PSRrvTime_gCTS) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS));
pvRTS = NULL;
pvCTS = (PSCTS) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR);
pvTxDataHd = (PSTxDataHead_g) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR + sizeof(SCTS));
cbHeaderSize = wTxBufSize + sizeof(SRrvTime_gCTS) + cbMICHDR + sizeof(SCTS) + sizeof(STxDataHead_g);
}
else {
pvRrvTime = (PSRrvTime_ab) (pbyTxBufferAddr + wTxBufSize);
pMICHDR = (PSMICHDRHead) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab));
pvRTS = NULL;
pvCTS = NULL;
pvTxDataHd = (PSTxDataHead_ab) (pbyTxBufferAddr + wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR);
cbHeaderSize = wTxBufSize + sizeof(SRrvTime_ab) + cbMICHDR + sizeof(STxDataHead_ab);
}
memset((void *)(pbyTxBufferAddr + wTxBufSize), 0,
(cbHeaderSize - wTxBufSize));
memcpy(&(sEthHeader.h_dest[0]),
&(p80211Header->sA3.abyAddr1[0]),
ETH_ALEN);
memcpy(&(sEthHeader.h_source[0]),
&(p80211Header->sA3.abyAddr2[0]),
ETH_ALEN);
pTxBufHead->wFragCtl |= (u16)FRAGCTL_NONFRAG;
s_vGenerateTxParameter(pDevice, byPktType, wCurrentRate, pbyTxBufferAddr, pvRrvTime, pvRTS, pvCTS,
cbFrameSize, bNeedACK, TYPE_TXDMA0, &sEthHeader);
uDuration = s_uFillDataHead(pDevice, byPktType, wCurrentRate, pvTxDataHd, cbFrameSize, TYPE_TXDMA0, bNeedACK,
0, 0, 1, AUTO_FB_NONE);
pMACHeader = (struct ieee80211_hdr *) (pbyTxBufferAddr + cbHeaderSize);
cbReqCount = cbHeaderSize + cbMacHdLen + uPadding + cbIVlen + (cbFrameBodySize + cbMIClen) + cbExtSuppRate;
pbyMacHdr = (u8 *)(pbyTxBufferAddr + cbHeaderSize);
pbyPayloadHead = (u8 *)(pbyMacHdr + cbMacHdLen + uPadding + cbIVlen);
pbyIVHead = (u8 *)(pbyMacHdr + cbMacHdLen + uPadding);
memcpy(pbyMacHdr, skb->data, cbMacHdLen);
pMACHeader->frame_control &= cpu_to_le16(0xfffc);
memcpy(pbyPayloadHead, (skb->data + cbMacHdLen), cbFrameBodySize);
if (WLAN_GET_FC_FSTYPE(p80211Header->sA4.wFrameCtl) == WLAN_FSTYPE_ASSOCRESP) {
if (cbExtSuppRate != 0) {
if (((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len != 0)
memcpy((pbyPayloadHead + cbFrameBodySize),
pMgmt->abyCurrSuppRates,
((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len + WLAN_IEHDR_LEN
);
if (((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates)->len != 0)
memcpy((pbyPayloadHead + cbFrameBodySize) + ((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates)->len + WLAN_IEHDR_LEN,
pMgmt->abyCurrExtSuppRates,
((PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates)->len + WLAN_IEHDR_LEN
);
}
}
if (WLAN_GET_FC_ISWEP(p80211Header->sA4.wFrameCtl) != 0) {
if (pDevice->bEnableHostWEP) {
pTransmitKey = &STempKey;
pTransmitKey->byCipherSuite = pMgmt->sNodeDBTable[uNodeIndex].byCipherSuite;
pTransmitKey->dwKeyIndex = pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex;
pTransmitKey->uKeyLength = pMgmt->sNodeDBTable[uNodeIndex].uWepKeyLength;
pTransmitKey->dwTSC47_16 = pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16;
pTransmitKey->wTSC15_0 = pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0;
memcpy(pTransmitKey->abyKey,
&pMgmt->sNodeDBTable[uNodeIndex].abyWepKey[0],
pTransmitKey->uKeyLength
);
}
if ((pTransmitKey != NULL) && (pTransmitKey->byCipherSuite == KEY_CTL_TKIP)) {
dwMICKey0 = *(u32 *)(&pTransmitKey->abyKey[16]);
dwMICKey1 = *(u32 *)(&pTransmitKey->abyKey[20]);
MIC_vInit(dwMICKey0, dwMICKey1);
MIC_vAppend((u8 *)&(sEthHeader.h_dest[0]), 12);
dwMIC_Priority = 0;
MIC_vAppend((u8 *)&dwMIC_Priority, 4);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"DMA0_tx_8021:MIC KEY:"\
" %X, %X\n", dwMICKey0, dwMICKey1);
uLength = cbHeaderSize + cbMacHdLen + uPadding + cbIVlen;
MIC_vAppend((pbyTxBufferAddr + uLength), cbFrameBodySize);
pdwMIC_L = (u32 *)(pbyTxBufferAddr + uLength + cbFrameBodySize);
pdwMIC_R = (u32 *)(pbyTxBufferAddr + uLength + cbFrameBodySize + 4);
MIC_vGetMIC(pdwMIC_L, pdwMIC_R);
MIC_vUnInit();
if (pDevice->bTxMICFail == true) {
*pdwMIC_L = 0;
*pdwMIC_R = 0;
pDevice->bTxMICFail = false;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"uLength: %d, %d\n", uLength, cbFrameBodySize);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"cbReqCount:%d, %d, %d, %d\n", cbReqCount, cbHeaderSize, uPadding, cbIVlen);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"MIC:%x, %x\n",
*pdwMIC_L, *pdwMIC_R);
}
s_vFillTxKey(pDevice, (u8 *)(pTxBufHead->adwTxKey), pbyIVHead, pTransmitKey,
pbyMacHdr, (u16)cbFrameBodySize, (u8 *)pMICHDR);
if (pDevice->bEnableHostWEP) {
pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16 = pTransmitKey->dwTSC47_16;
pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0 = pTransmitKey->wTSC15_0;
}
if ((pDevice->byLocalID <= REV_ID_VT3253_A1)) {
s_vSWencryption(pDevice, pTransmitKey, pbyPayloadHead, (u16)(cbFrameBodySize + cbMIClen));
}
}
pMACHeader->seq_ctrl = cpu_to_le16(pDevice->wSeqCounter << 4);
pDevice->wSeqCounter++ ;
if (pDevice->wSeqCounter > 0x0fff)
pDevice->wSeqCounter = 0;
if (bIsPSPOLL) {
if (byPktType == PK_TYPE_11GB || byPktType == PK_TYPE_11GA) {
((PSTxDataHead_g)pvTxDataHd)->wDuration_a = cpu_to_le16(p80211Header->sA2.wDurationID);
((PSTxDataHead_g)pvTxDataHd)->wDuration_b = cpu_to_le16(p80211Header->sA2.wDurationID);
} else {
((PSTxDataHead_ab)pvTxDataHd)->wDuration = cpu_to_le16(p80211Header->sA2.wDurationID);
}
}
pTX_Buffer->wTxByteCount = cpu_to_le16((u16)(cbReqCount));
pTX_Buffer->byPKTNO = (u8) (((wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->byType = 0x00;
pContext->pPacket = skb;
pContext->Type = CONTEXT_MGMT_PACKET;
pContext->uBufLen = (u16)cbReqCount + 4;
if (WLAN_GET_FC_TODS(pMACHeader->frame_control) == 0) {
s_vSaveTxPktInfo(pDevice, (u8) (pTX_Buffer->byPKTNO & 0x0F), &(pMACHeader->addr1[0]), (u16)cbFrameSize, pTX_Buffer->wFIFOCtl);
}
else {
s_vSaveTxPktInfo(pDevice, (u8) (pTX_Buffer->byPKTNO & 0x0F), &(pMACHeader->addr3[0]), (u16)cbFrameSize, pTX_Buffer->wFIFOCtl);
}
PIPEnsSendBulkOut(pDevice,pContext);
return ;
}
int nsDMA_tx_packet(struct vnt_private *pDevice,
u32 uDMAIdx, struct sk_buff *skb)
{
struct net_device_stats *pStats = &pDevice->stats;
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
u32 BytesToWrite = 0, uHeaderLen = 0;
u32 uNodeIndex = 0;
u8 byMask[8] = {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80};
u16 wAID;
u8 byPktType;
int bNeedEncryption = false;
PSKeyItem pTransmitKey = NULL;
SKeyItem STempKey;
int ii;
int bTKIP_UseGTK = false;
int bNeedDeAuth = false;
u8 *pbyBSSID;
int bNodeExist = false;
PUSB_SEND_CONTEXT pContext;
bool fConvertedPacket;
PTX_BUFFER pTX_Buffer;
u32 status;
u16 wKeepRate = pDevice->wCurrentRate;
int bTxeapol_key = false;
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
if (pDevice->uAssocCount == 0) {
dev_kfree_skb_irq(skb);
return 0;
}
if (is_multicast_ether_addr((u8 *)(skb->data))) {
uNodeIndex = 0;
bNodeExist = true;
if (pMgmt->sNodeDBTable[0].bPSEnable) {
skb_queue_tail(&(pMgmt->sNodeDBTable[0].sTxPSQueue), skb);
pMgmt->sNodeDBTable[0].wEnQueueCnt++;
pMgmt->abyPSTxMap[0] |= byMask[0];
return 0;
}
if (pDevice->byBBType != BB_TYPE_11A)
pDevice->wCurrentRate = RATE_2M;
else
pDevice->wCurrentRate = RATE_24M;
pDevice->byPreambleType = PREAMBLE_SHORT;
}else {
if (BSSbIsSTAInNodeDB(pDevice, (u8 *)(skb->data), &uNodeIndex)) {
if (pMgmt->sNodeDBTable[uNodeIndex].bPSEnable) {
skb_queue_tail(&pMgmt->sNodeDBTable[uNodeIndex].sTxPSQueue, skb);
pMgmt->sNodeDBTable[uNodeIndex].wEnQueueCnt++;
wAID = pMgmt->sNodeDBTable[uNodeIndex].wAID;
pMgmt->abyPSTxMap[wAID >> 3] |= byMask[wAID & 7];
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Set:pMgmt->abyPSTxMap[%d]= %d\n",
(wAID >> 3), pMgmt->abyPSTxMap[wAID >> 3]);
return 0;
}
pDevice->wCurrentRate = pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate;
if (pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble) {
pDevice->byPreambleType = pDevice->byShortPreamble;
}else {
pDevice->byPreambleType = PREAMBLE_LONG;
}
bNodeExist = true;
}
}
if (bNodeExist == false) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Unknown STA not found in node DB \n");
dev_kfree_skb_irq(skb);
return 0;
}
}
pContext = (PUSB_SEND_CONTEXT)s_vGetFreeContext(pDevice);
if (pContext == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG" pContext == NULL\n");
dev_kfree_skb_irq(skb);
return STATUS_RESOURCES;
}
memcpy(pDevice->sTxEthHeader.h_dest, (u8 *)(skb->data), ETH_HLEN);
{
u8 Protocol_Version;
u8 Packet_Type;
u8 Descriptor_type;
u16 Key_info;
Protocol_Version = skb->data[ETH_HLEN];
Packet_Type = skb->data[ETH_HLEN+1];
Descriptor_type = skb->data[ETH_HLEN+1+1+2];
Key_info = (skb->data[ETH_HLEN+1+1+2+1] << 8)|(skb->data[ETH_HLEN+1+1+2+2]);
if (pDevice->sTxEthHeader.h_proto == cpu_to_be16(ETH_P_PAE)) {
if (((Protocol_Version == 1) || (Protocol_Version == 2)) &&
(Packet_Type == 3)) {
bTxeapol_key = true;
if(!(Key_info & BIT3) &&
(Key_info & BIT8) && (Key_info & BIT9)) {
if(Descriptor_type==254) {
pDevice->fWPA_Authened = true;
PRINT_K("WPA ");
}
else {
pDevice->fWPA_Authened = true;
PRINT_K("WPA2(re-keying) ");
}
PRINT_K("Authentication completed!!\n");
}
else if((Key_info & BIT3) && (Descriptor_type==2) &&
(Key_info & BIT8) && (Key_info & BIT9)) {
pDevice->fWPA_Authened = true;
PRINT_K("WPA2 Authentication completed!!\n");
}
}
}
}
if (pDevice->bEncryptionEnable == true) {
bNeedEncryption = true;
do {
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_STA) &&
(pMgmt->eCurrState == WMAC_STATE_ASSOC)) {
pbyBSSID = pDevice->abyBSSID;
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, PAIRWISE_KEY, &pTransmitKey) == false) {
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == true) {
bTKIP_UseGTK = true;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Get GTK.\n");
break;
}
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Get PTK.\n");
break;
}
}else if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
pbyBSSID = pDevice->sTxEthHeader.h_dest;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"IBSS Serach Key: \n");
for (ii = 0; ii< 6; ii++)
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"%x \n", *(pbyBSSID+ii));
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"\n");
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, PAIRWISE_KEY, &pTransmitKey) == true)
break;
}
pbyBSSID = pDevice->abyBroadcastAddr;
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == false) {
pTransmitKey = NULL;
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"IBSS and KEY is NULL. [%d]\n", pMgmt->eCurrMode);
}
else
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"NOT IBSS and KEY is NULL. [%d]\n", pMgmt->eCurrMode);
} else {
bTKIP_UseGTK = true;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Get GTK.\n");
}
} while(false);
}
if (pDevice->bEnableHostWEP) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"acdma0: STA index %d\n", uNodeIndex);
if (pDevice->bEncryptionEnable == true) {
pTransmitKey = &STempKey;
pTransmitKey->byCipherSuite = pMgmt->sNodeDBTable[uNodeIndex].byCipherSuite;
pTransmitKey->dwKeyIndex = pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex;
pTransmitKey->uKeyLength = pMgmt->sNodeDBTable[uNodeIndex].uWepKeyLength;
pTransmitKey->dwTSC47_16 = pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16;
pTransmitKey->wTSC15_0 = pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0;
memcpy(pTransmitKey->abyKey,
&pMgmt->sNodeDBTable[uNodeIndex].abyWepKey[0],
pTransmitKey->uKeyLength
);
}
}
byPktType = (u8)pDevice->byPacketType;
if (pDevice->bFixRate) {
if (pDevice->byBBType == BB_TYPE_11B) {
if (pDevice->uConnectionRate >= RATE_11M) {
pDevice->wCurrentRate = RATE_11M;
} else {
pDevice->wCurrentRate = (u16)pDevice->uConnectionRate;
}
} else {
if ((pDevice->byBBType == BB_TYPE_11A) &&
(pDevice->uConnectionRate <= RATE_6M)) {
pDevice->wCurrentRate = RATE_6M;
} else {
if (pDevice->uConnectionRate >= RATE_54M)
pDevice->wCurrentRate = RATE_54M;
else
pDevice->wCurrentRate = (u16)pDevice->uConnectionRate;
}
}
}
else {
if (pDevice->eOPMode == OP_MODE_ADHOC) {
if (is_multicast_ether_addr(pDevice->sTxEthHeader.h_dest)) {
pDevice->wCurrentRate = pMgmt->sNodeDBTable[0].wTxDataRate;
pDevice->byPreambleType = pDevice->byShortPreamble;
}
else {
if (BSSbIsSTAInNodeDB(pDevice, &(pDevice->sTxEthHeader.h_dest[0]), &uNodeIndex)) {
pDevice->wCurrentRate = pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate;
if (pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble) {
pDevice->byPreambleType = pDevice->byShortPreamble;
}
else {
pDevice->byPreambleType = PREAMBLE_LONG;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Found Node Index is [%d] Tx Data Rate:[%d]\n",uNodeIndex, pDevice->wCurrentRate);
}
else {
if (pDevice->byBBType != BB_TYPE_11A)
pDevice->wCurrentRate = RATE_2M;
else
pDevice->wCurrentRate = RATE_24M;
pDevice->byPreambleType = PREAMBLE_SHORT;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Not Found Node use highest basic Rate.....\n");
}
}
}
if (pDevice->eOPMode == OP_MODE_INFRASTRUCTURE) {
pDevice->wCurrentRate = pMgmt->sNodeDBTable[0].wTxDataRate;
}
}
if (pDevice->sTxEthHeader.h_proto == cpu_to_be16(ETH_P_PAE)) {
if (pDevice->byBBType != BB_TYPE_11A) {
pDevice->wCurrentRate = RATE_1M;
pDevice->byACKRate = RATE_1M;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_6M;
} else {
pDevice->wCurrentRate = RATE_6M;
pDevice->byACKRate = RATE_6M;
pDevice->byTopCCKBasicRate = RATE_1M;
pDevice->byTopOFDMBasicRate = RATE_6M;
}
}
DBG_PRT(MSG_LEVEL_DEBUG,
KERN_INFO "dma_tx: pDevice->wCurrentRate = %d\n",
pDevice->wCurrentRate);
if (wKeepRate != pDevice->wCurrentRate) {
bScheduleCommand((void *) pDevice, WLAN_CMD_SETPOWER, NULL);
}
if (pDevice->wCurrentRate <= RATE_11M) {
byPktType = PK_TYPE_11B;
}
if (bNeedEncryption == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"ntohs Pkt Type=%04x\n", ntohs(pDevice->sTxEthHeader.h_proto));
if ((pDevice->sTxEthHeader.h_proto) == cpu_to_be16(ETH_P_PAE)) {
bNeedEncryption = false;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Pkt Type=%04x\n", (pDevice->sTxEthHeader.h_proto));
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_STA) && (pMgmt->eCurrState == WMAC_STATE_ASSOC)) {
if (pTransmitKey == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Don't Find TX KEY\n");
}
else {
if (bTKIP_UseGTK == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"error: KEY is GTK!!~~\n");
}
else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Find PTK [%X]\n",
pTransmitKey->dwKeyIndex);
bNeedEncryption = true;
}
}
}
if (pDevice->bEnableHostWEP) {
if ((uNodeIndex != 0) &&
(pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex & PAIRWISE_KEY)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Find PTK [%X]\n",
pTransmitKey->dwKeyIndex);
bNeedEncryption = true;
}
}
}
else {
if (pTransmitKey == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"return no tx key\n");
pContext->bBoolInUse = false;
dev_kfree_skb_irq(skb);
pStats->tx_dropped++;
return STATUS_FAILURE;
}
}
}
fConvertedPacket = s_bPacketToWirelessUsb(pDevice, byPktType,
(u8 *)(&pContext->Data[0]), bNeedEncryption,
skb->len, uDMAIdx, &pDevice->sTxEthHeader,
(u8 *)skb->data, pTransmitKey, uNodeIndex,
pDevice->wCurrentRate,
&uHeaderLen, &BytesToWrite
);
if (fConvertedPacket == false) {
pContext->bBoolInUse = false;
dev_kfree_skb_irq(skb);
return STATUS_FAILURE;
}
if ( pDevice->bEnablePSMode == true ) {
if ( !pDevice->bPSModeTxBurst ) {
bScheduleCommand((void *) pDevice,
WLAN_CMD_MAC_DISPOWERSAVING,
NULL);
pDevice->bPSModeTxBurst = true;
}
}
pTX_Buffer = (PTX_BUFFER)&(pContext->Data[0]);
pTX_Buffer->byPKTNO = (u8) (((pDevice->wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->wTxByteCount = (u16)BytesToWrite;
pContext->pPacket = skb;
pContext->Type = CONTEXT_DATA_PACKET;
pContext->uBufLen = (u16)BytesToWrite + 4 ;
s_vSaveTxPktInfo(pDevice, (u8) (pTX_Buffer->byPKTNO & 0x0F), &(pContext->sEthHeader.h_dest[0]), (u16) (BytesToWrite-uHeaderLen), pTX_Buffer->wFIFOCtl);
status = PIPEnsSendBulkOut(pDevice,pContext);
if (bNeedDeAuth == true) {
u16 wReason = WLAN_MGMT_REASON_MIC_FAILURE;
bScheduleCommand((void *) pDevice, WLAN_CMD_DEAUTH, (u8 *) &wReason);
}
if(status!=STATUS_PENDING) {
pContext->bBoolInUse = false;
dev_kfree_skb_irq(skb);
return STATUS_FAILURE;
}
else
return 0;
}
int bRelayPacketSend(struct vnt_private *pDevice, u8 *pbySkbData, u32 uDataLen,
u32 uNodeIndex)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
u32 BytesToWrite = 0, uHeaderLen = 0;
u8 byPktType = PK_TYPE_11B;
int bNeedEncryption = false;
SKeyItem STempKey;
PSKeyItem pTransmitKey = NULL;
u8 *pbyBSSID;
PUSB_SEND_CONTEXT pContext;
u8 byPktTyp;
int fConvertedPacket;
PTX_BUFFER pTX_Buffer;
u32 status;
u16 wKeepRate = pDevice->wCurrentRate;
pContext = (PUSB_SEND_CONTEXT)s_vGetFreeContext(pDevice);
if (NULL == pContext) {
return false;
}
memcpy(pDevice->sTxEthHeader.h_dest, (u8 *)pbySkbData, ETH_HLEN);
if (pDevice->bEncryptionEnable == true) {
bNeedEncryption = true;
pbyBSSID = pDevice->abyBroadcastAddr;
if(KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID, GROUP_KEY, &pTransmitKey) == false) {
pTransmitKey = NULL;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"KEY is NULL. [%d]\n", pMgmt->eCurrMode);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_DEBUG"Get GTK.\n");
}
}
if (pDevice->bEnableHostWEP) {
if (uNodeIndex < MAX_NODE_NUM + 1) {
pTransmitKey = &STempKey;
pTransmitKey->byCipherSuite = pMgmt->sNodeDBTable[uNodeIndex].byCipherSuite;
pTransmitKey->dwKeyIndex = pMgmt->sNodeDBTable[uNodeIndex].dwKeyIndex;
pTransmitKey->uKeyLength = pMgmt->sNodeDBTable[uNodeIndex].uWepKeyLength;
pTransmitKey->dwTSC47_16 = pMgmt->sNodeDBTable[uNodeIndex].dwTSC47_16;
pTransmitKey->wTSC15_0 = pMgmt->sNodeDBTable[uNodeIndex].wTSC15_0;
memcpy(pTransmitKey->abyKey,
&pMgmt->sNodeDBTable[uNodeIndex].abyWepKey[0],
pTransmitKey->uKeyLength
);
}
}
if ( bNeedEncryption && (pTransmitKey == NULL) ) {
pContext->bBoolInUse = false;
return false;
}
byPktTyp = (u8)pDevice->byPacketType;
if (pDevice->bFixRate) {
if (pDevice->byBBType == BB_TYPE_11B) {
if (pDevice->uConnectionRate >= RATE_11M) {
pDevice->wCurrentRate = RATE_11M;
} else {
pDevice->wCurrentRate = (u16)pDevice->uConnectionRate;
}
} else {
if ((pDevice->byBBType == BB_TYPE_11A) &&
(pDevice->uConnectionRate <= RATE_6M)) {
pDevice->wCurrentRate = RATE_6M;
} else {
if (pDevice->uConnectionRate >= RATE_54M)
pDevice->wCurrentRate = RATE_54M;
else
pDevice->wCurrentRate = (u16)pDevice->uConnectionRate;
}
}
}
else {
pDevice->wCurrentRate = pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate;
}
if (wKeepRate != pDevice->wCurrentRate) {
bScheduleCommand((void *) pDevice, WLAN_CMD_SETPOWER, NULL);
}
if (pDevice->wCurrentRate <= RATE_11M)
byPktType = PK_TYPE_11B;
BytesToWrite = uDataLen + ETH_FCS_LEN;
fConvertedPacket = s_bPacketToWirelessUsb(pDevice, byPktType,
(u8 *)(&pContext->Data[0]), bNeedEncryption,
uDataLen, TYPE_AC0DMA, &pDevice->sTxEthHeader,
pbySkbData, pTransmitKey, uNodeIndex,
pDevice->wCurrentRate,
&uHeaderLen, &BytesToWrite
);
if (fConvertedPacket == false) {
pContext->bBoolInUse = false;
return false;
}
pTX_Buffer = (PTX_BUFFER)&(pContext->Data[0]);
pTX_Buffer->byPKTNO = (u8) (((pDevice->wCurrentRate<<4) &0x00F0) | ((pDevice->wSeqCounter - 1) & 0x000F));
pTX_Buffer->wTxByteCount = (u16)BytesToWrite;
pContext->pPacket = NULL;
pContext->Type = CONTEXT_DATA_PACKET;
pContext->uBufLen = (u16)BytesToWrite + 4 ;
s_vSaveTxPktInfo(pDevice, (u8) (pTX_Buffer->byPKTNO & 0x0F), &(pContext->sEthHeader.h_dest[0]), (u16) (BytesToWrite-uHeaderLen), pTX_Buffer->wFIFOCtl);
status = PIPEnsSendBulkOut(pDevice,pContext);
return true;
}
