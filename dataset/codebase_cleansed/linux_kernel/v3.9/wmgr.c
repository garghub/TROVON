void vMgrObjectInit(struct vnt_private *pDevice)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
int ii;
pMgmt->pbyPSPacketPool = &pMgmt->byPSPacketPool[0];
pMgmt->pbyMgmtPacketPool = &pMgmt->byMgmtPacketPool[0];
pMgmt->uCurrChannel = pDevice->uChannel;
for (ii = 0; ii < WLAN_BSSID_LEN; ii++)
pMgmt->abyDesireBSSID[ii] = 0xFF;
pMgmt->sAssocInfo.AssocInfo.Length = sizeof(NDIS_802_11_ASSOCIATION_INFORMATION);
pMgmt->byCSSPK = KEY_CTL_NONE;
pMgmt->byCSSGK = KEY_CTL_NONE;
pMgmt->wIBSSBeaconPeriod = DEFAULT_IBSS_BI;
BSSvClearBSSList((void *) pDevice, false);
init_timer(&pMgmt->sTimerSecondCallback);
pMgmt->sTimerSecondCallback.data = (unsigned long)pDevice;
pMgmt->sTimerSecondCallback.function = (TimerFunction)BSSvSecondCallBack;
pMgmt->sTimerSecondCallback.expires = RUN_AT(HZ);
init_timer(&pDevice->sTimerCommand);
pDevice->sTimerCommand.data = (unsigned long)pDevice;
pDevice->sTimerCommand.function = (TimerFunction)vRunCommand;
pDevice->sTimerCommand.expires = RUN_AT(HZ);
init_timer(&pDevice->sTimerTxData);
pDevice->sTimerTxData.data = (unsigned long)pDevice;
pDevice->sTimerTxData.function = (TimerFunction)BSSvSecondTxData;
pDevice->sTimerTxData.expires = RUN_AT(10*HZ);
pDevice->fTxDataInSleep = false;
pDevice->IsTxDataTrigger = false;
pDevice->nTxDataTimeCout = 0;
pDevice->cbFreeCmdQueue = CMD_Q_SIZE;
pDevice->uCmdDequeueIdx = 0;
pDevice->uCmdEnqueueIdx = 0;
pDevice->eCommandState = WLAN_CMD_IDLE;
pDevice->bCmdRunning = false;
pDevice->bCmdClear = false;
return;
}
void vMgrAssocBeginSta(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, PCMD_STATUS pStatus)
{
struct vnt_tx_mgmt *pTxPacket;
pMgmt->wCurrCapInfo = 0;
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_ESS(1);
if (pDevice->bEncryptionEnable) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_PRIVACY(1);
}
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTPREAMBLE(1);
if (pMgmt->wListenInterval == 0)
pMgmt->wListenInterval = 1;
if (pMgmt->eCurrentPHYMode == PHY_TYPE_11G) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTPREAMBLE(1);
if (pDevice->bShortSlotTime == true)
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTSLOTTIME(1);
} else if (pMgmt->eCurrentPHYMode == PHY_TYPE_11B) {
if (pDevice->byPreambleType == 1) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTPREAMBLE(1);
}
}
if (pMgmt->b11hEnable == true)
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SPECTRUMMNG(1);
pTxPacket = s_MgrMakeAssocRequest
(
pDevice,
pMgmt,
pMgmt->abyCurrBSSID,
pMgmt->wCurrCapInfo,
pMgmt->wListenInterval,
(PWLAN_IE_SSID)pMgmt->abyCurrSSID,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates
);
if (pTxPacket != NULL ){
*pStatus = csMgmt_xmit(pDevice, pTxPacket);
if (*pStatus == CMD_STATUS_PENDING) {
pMgmt->eCurrState = WMAC_STATE_ASSOCPENDING;
*pStatus = CMD_STATUS_SUCCESS;
}
}
else
*pStatus = CMD_STATUS_RESOURCES;
return ;
}
void vMgrReAssocBeginSta(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, PCMD_STATUS pStatus)
{
struct vnt_tx_mgmt *pTxPacket;
pMgmt->wCurrCapInfo = 0;
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_ESS(1);
if (pDevice->bEncryptionEnable) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_PRIVACY(1);
}
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTPREAMBLE(1);
if (pMgmt->wListenInterval == 0)
pMgmt->wListenInterval = 1;
if (pMgmt->eCurrentPHYMode == PHY_TYPE_11G) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTPREAMBLE(1);
if (pDevice->bShortSlotTime == true)
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTSLOTTIME(1);
} else if (pMgmt->eCurrentPHYMode == PHY_TYPE_11B) {
if (pDevice->byPreambleType == 1) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTPREAMBLE(1);
}
}
if (pMgmt->b11hEnable == true)
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SPECTRUMMNG(1);
pTxPacket = s_MgrMakeReAssocRequest
(
pDevice,
pMgmt,
pMgmt->abyCurrBSSID,
pMgmt->wCurrCapInfo,
pMgmt->wListenInterval,
(PWLAN_IE_SSID)pMgmt->abyCurrSSID,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates
);
if (pTxPacket != NULL ){
*pStatus = csMgmt_xmit(pDevice, pTxPacket);
if (*pStatus != CMD_STATUS_PENDING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Reassociation tx failed.\n");
}
else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Reassociation tx sending.\n");
}
}
return ;
}
void vMgrDisassocBeginSta(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, u8 *abyDestAddress, u16 wReason,
PCMD_STATUS pStatus)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
WLAN_FR_DISASSOC sFrame;
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_DISASSOC_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_DISASSOC_FR_MAXLEN;
vMgrEncodeDisassociation(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_DISASSOC)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, abyDestAddress, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*(sFrame.pwReason) = cpu_to_le16(wReason);
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
*pStatus = csMgmt_xmit(pDevice, pTxPacket);
if (*pStatus == CMD_STATUS_PENDING) {
pMgmt->eCurrState = WMAC_STATE_IDLE;
*pStatus = CMD_STATUS_SUCCESS;
}
return;
}
static void s_vMgrRxAssocRequest(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket,
u32 uNodeIndex)
{
WLAN_FR_ASSOCREQ sFrame;
CMD_STATUS Status;
struct vnt_tx_mgmt *pTxPacket;
u16 wAssocStatus = 0;
u16 wAssocAID = 0;
u32 uRateLen = WLAN_RATES_MAXLEN;
u8 abyCurrSuppRates[WLAN_IEHDR_LEN + WLAN_RATES_MAXLEN + 1];
u8 abyCurrExtSuppRates[WLAN_IEHDR_LEN + WLAN_RATES_MAXLEN + 1];
if (pMgmt->eCurrMode != WMAC_MODE_ESS_AP)
return;
if (!uNodeIndex)
return;
memset(&sFrame, 0, sizeof(WLAN_FR_ASSOCREQ));
memset(abyCurrSuppRates, 0, WLAN_IEHDR_LEN + WLAN_RATES_MAXLEN + 1);
memset(abyCurrExtSuppRates, 0, WLAN_IEHDR_LEN + WLAN_RATES_MAXLEN + 1);
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeAssocRequest(&sFrame);
if (pMgmt->sNodeDBTable[uNodeIndex].eNodeState >= NODE_AUTH) {
pMgmt->sNodeDBTable[uNodeIndex].eNodeState = NODE_ASSOC;
pMgmt->sNodeDBTable[uNodeIndex].wCapInfo = cpu_to_le16(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].wListenInterval = cpu_to_le16(*sFrame.pwListenInterval);
pMgmt->sNodeDBTable[uNodeIndex].bPSEnable =
WLAN_GET_FC_PWRMGT(sFrame.pHdr->sA3.wFrameCtl) ? true : false;
if (pDevice->byBBType == BB_TYPE_11B) {
uRateLen = WLAN_RATES_MAXLEN_11B;
}
abyCurrSuppRates[0] = WLAN_EID_SUPP_RATES;
abyCurrSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)sFrame.pSuppRates,
(PWLAN_IE_SUPP_RATES)abyCurrSuppRates,
uRateLen);
abyCurrExtSuppRates[0] = WLAN_EID_EXTSUPP_RATES;
if (pDevice->byBBType == BB_TYPE_11G) {
abyCurrExtSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)sFrame.pExtSuppRates,
(PWLAN_IE_SUPP_RATES)abyCurrExtSuppRates,
uRateLen);
} else {
abyCurrExtSuppRates[1] = 0;
}
RATEvParseMaxRate((void *)pDevice,
(PWLAN_IE_SUPP_RATES)abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)abyCurrExtSuppRates,
false,
&(pMgmt->sNodeDBTable[uNodeIndex].wMaxBasicRate),
&(pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate),
&(pMgmt->sNodeDBTable[uNodeIndex].wSuppRate),
&(pMgmt->sNodeDBTable[uNodeIndex].byTopCCKBasicRate),
&(pMgmt->sNodeDBTable[uNodeIndex].byTopOFDMBasicRate)
);
pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate =
pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate;
pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble =
WLAN_GET_CAP_INFO_SHORTPREAMBLE(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].bShortSlotTime =
WLAN_GET_CAP_INFO_SHORTSLOTTIME(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].wAID = (WORD)uNodeIndex;
wAssocStatus = WLAN_MGMT_STATUS_SUCCESS;
wAssocAID = (WORD)uNodeIndex;
if(pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate > RATE_11M)
pMgmt->sNodeDBTable[uNodeIndex].bERPExist = true;
if (pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate <= RATE_11M) {
pDevice->bProtectMode = true;
pDevice->bNonERPPresent = true;
}
if (pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble == false) {
pDevice->bBarkerPreambleMd = true;
}
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "Associate AID= %d \n", wAssocAID);
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "MAC=%2.2X:%2.2X:%2.2X:%2.2X:%2.2X:%2.2X \n",
sFrame.pHdr->sA3.abyAddr2[0],
sFrame.pHdr->sA3.abyAddr2[1],
sFrame.pHdr->sA3.abyAddr2[2],
sFrame.pHdr->sA3.abyAddr2[3],
sFrame.pHdr->sA3.abyAddr2[4],
sFrame.pHdr->sA3.abyAddr2[5]
) ;
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "Max Support rate = %d \n",
pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate);
}
pTxPacket = s_MgrMakeAssocResponse
(
pDevice,
pMgmt,
pMgmt->wCurrCapInfo,
wAssocStatus,
wAssocAID,
sFrame.pHdr->sA3.abyAddr2,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates
);
if (pTxPacket != NULL ){
if (pDevice->bEnableHostapd) {
return;
}
Status = csMgmt_xmit(pDevice, pTxPacket);
if (Status != CMD_STATUS_PENDING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Assoc response tx failed\n");
}
else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Assoc response tx sending..\n");
}
}
return;
}
static void s_vMgrRxReAssocRequest(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket,
u32 uNodeIndex)
{
WLAN_FR_REASSOCREQ sFrame;
CMD_STATUS Status;
struct vnt_tx_mgmt *pTxPacket;
u16 wAssocStatus = 0;
u16 wAssocAID = 0;
u32 uRateLen = WLAN_RATES_MAXLEN;
u8 abyCurrSuppRates[WLAN_IEHDR_LEN + WLAN_RATES_MAXLEN + 1];
u8 abyCurrExtSuppRates[WLAN_IEHDR_LEN + WLAN_RATES_MAXLEN + 1];
if (pMgmt->eCurrMode != WMAC_MODE_ESS_AP)
return;
if (!uNodeIndex)
return;
memset(&sFrame, 0, sizeof(WLAN_FR_REASSOCREQ));
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeReassocRequest(&sFrame);
if (pMgmt->sNodeDBTable[uNodeIndex].eNodeState >= NODE_AUTH) {
pMgmt->sNodeDBTable[uNodeIndex].eNodeState = NODE_ASSOC;
pMgmt->sNodeDBTable[uNodeIndex].wCapInfo = cpu_to_le16(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].wListenInterval = cpu_to_le16(*sFrame.pwListenInterval);
pMgmt->sNodeDBTable[uNodeIndex].bPSEnable =
WLAN_GET_FC_PWRMGT(sFrame.pHdr->sA3.wFrameCtl) ? true : false;
if (pDevice->byBBType == BB_TYPE_11B) {
uRateLen = WLAN_RATES_MAXLEN_11B;
}
abyCurrSuppRates[0] = WLAN_EID_SUPP_RATES;
abyCurrSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)sFrame.pSuppRates,
(PWLAN_IE_SUPP_RATES)abyCurrSuppRates,
uRateLen);
abyCurrExtSuppRates[0] = WLAN_EID_EXTSUPP_RATES;
if (pDevice->byBBType == BB_TYPE_11G) {
abyCurrExtSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)sFrame.pExtSuppRates,
(PWLAN_IE_SUPP_RATES)abyCurrExtSuppRates,
uRateLen);
} else {
abyCurrExtSuppRates[1] = 0;
}
RATEvParseMaxRate((void *)pDevice,
(PWLAN_IE_SUPP_RATES)abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)abyCurrExtSuppRates,
false,
&(pMgmt->sNodeDBTable[uNodeIndex].wMaxBasicRate),
&(pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate),
&(pMgmt->sNodeDBTable[uNodeIndex].wSuppRate),
&(pMgmt->sNodeDBTable[uNodeIndex].byTopCCKBasicRate),
&(pMgmt->sNodeDBTable[uNodeIndex].byTopOFDMBasicRate)
);
pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate =
pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate;
pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble =
WLAN_GET_CAP_INFO_SHORTPREAMBLE(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].bShortSlotTime =
WLAN_GET_CAP_INFO_SHORTSLOTTIME(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].wAID = (WORD)uNodeIndex;
wAssocStatus = WLAN_MGMT_STATUS_SUCCESS;
wAssocAID = (WORD)uNodeIndex;
if(pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate > RATE_11M)
pMgmt->sNodeDBTable[uNodeIndex].bERPExist = true;
if (pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate <= RATE_11M) {
pDevice->bProtectMode = true;
pDevice->bNonERPPresent = true;
}
if (pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble == false) {
pDevice->bBarkerPreambleMd = true;
}
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "Rx ReAssociate AID= %d \n", wAssocAID);
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "MAC=%2.2X:%2.2X:%2.2X:%2.2X:%2.2X:%2.2X \n",
sFrame.pHdr->sA3.abyAddr2[0],
sFrame.pHdr->sA3.abyAddr2[1],
sFrame.pHdr->sA3.abyAddr2[2],
sFrame.pHdr->sA3.abyAddr2[3],
sFrame.pHdr->sA3.abyAddr2[4],
sFrame.pHdr->sA3.abyAddr2[5]
) ;
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "Max Support rate = %d \n",
pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate);
}
pTxPacket = s_MgrMakeReAssocResponse
(
pDevice,
pMgmt,
pMgmt->wCurrCapInfo,
wAssocStatus,
wAssocAID,
sFrame.pHdr->sA3.abyAddr2,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates
);
if (pTxPacket != NULL ){
if (pDevice->bEnableHostapd) {
return;
}
Status = csMgmt_xmit(pDevice, pTxPacket);
if (Status != CMD_STATUS_PENDING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:ReAssoc response tx failed\n");
}
else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:ReAssoc response tx sending..\n");
}
}
return;
}
static void s_vMgrRxAssocResponse(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket,
int bReAssocType)
{
WLAN_FR_ASSOCRESP sFrame;
PWLAN_IE_SSID pItemSSID;
u8 *pbyIEs;
if (pMgmt->eCurrState == WMAC_STATE_ASSOCPENDING ||
pMgmt->eCurrState == WMAC_STATE_ASSOC) {
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeAssocResponse(&sFrame);
if ((sFrame.pwCapInfo == NULL)
|| (sFrame.pwStatus == NULL)
|| (sFrame.pwAid == NULL)
|| (sFrame.pSuppRates == NULL)) {
DBG_PORT80(0xCC);
return;
}
pMgmt->sAssocInfo.AssocInfo.ResponseFixedIEs.Capabilities = *(sFrame.pwCapInfo);
pMgmt->sAssocInfo.AssocInfo.ResponseFixedIEs.StatusCode = *(sFrame.pwStatus);
pMgmt->sAssocInfo.AssocInfo.ResponseFixedIEs.AssociationId = *(sFrame.pwAid);
pMgmt->sAssocInfo.AssocInfo.AvailableResponseFixedIEs |= 0x07;
pMgmt->sAssocInfo.AssocInfo.ResponseIELength = sFrame.len - 24 - 6;
pMgmt->sAssocInfo.AssocInfo.OffsetResponseIEs = pMgmt->sAssocInfo.AssocInfo.OffsetRequestIEs + pMgmt->sAssocInfo.AssocInfo.RequestIELength;
pbyIEs = pMgmt->sAssocInfo.abyIEs;
pbyIEs += pMgmt->sAssocInfo.AssocInfo.RequestIELength;
memcpy(pbyIEs, (sFrame.pBuf + 24 +6), pMgmt->sAssocInfo.AssocInfo.ResponseIELength);
if (cpu_to_le16((*(sFrame.pwStatus))) == WLAN_MGMT_STATUS_SUCCESS ){
pMgmt->wCurrAID = cpu_to_le16((*(sFrame.pwAid)));
if ( (pMgmt->wCurrAID >> 14) != (BIT0 | BIT1) )
{
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "AID from AP, has two msb clear.\n");
}
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "Association Successful, AID=%d.\n", pMgmt->wCurrAID & ~(BIT14|BIT15));
pMgmt->eCurrState = WMAC_STATE_ASSOC;
BSSvUpdateAPNode((void *) pDevice,
sFrame.pwCapInfo,
sFrame.pSuppRates,
sFrame.pExtSuppRates);
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyCurrSSID;
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "Link with AP(SSID): %s\n", pItemSSID->abySSID);
pDevice->bLinkPass = true;
ControlvMaskByte(pDevice,MESSAGE_REQUEST_MACREG,MAC_REG_PAPEDELAY,LEDSTS_STS,LEDSTS_INTER);
{
BYTE buf[512];
size_t len;
union iwreq_data wrqu;
int we_event;
memset(buf, 0, 512);
len = pMgmt->sAssocInfo.AssocInfo.RequestIELength;
if(len) {
memcpy(buf, pMgmt->sAssocInfo.abyIEs, len);
memset(&wrqu, 0, sizeof (wrqu));
wrqu.data.length = len;
we_event = IWEVASSOCREQIE;
PRINT_K("wireless_send_event--->IWEVASSOCREQIE\n");
wireless_send_event(pDevice->dev, we_event, &wrqu, buf);
}
memset(buf, 0, 512);
len = pMgmt->sAssocInfo.AssocInfo.ResponseIELength;
if(len) {
memcpy(buf, pbyIEs, len);
memset(&wrqu, 0, sizeof (wrqu));
wrqu.data.length = len;
we_event = IWEVASSOCRESPIE;
PRINT_K("wireless_send_event--->IWEVASSOCRESPIE\n");
wireless_send_event(pDevice->dev, we_event, &wrqu, buf);
}
memset(&wrqu, 0, sizeof (wrqu));
memcpy(wrqu.ap_addr.sa_data, &pMgmt->abyCurrBSSID[0], ETH_ALEN);
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
PRINT_K("wireless_send_event--->SIOCGIWAP(associated)\n");
wireless_send_event(pDevice->dev, SIOCGIWAP, &wrqu, NULL);
}
}
else {
if (bReAssocType) {
pMgmt->eCurrState = WMAC_STATE_IDLE;
}
else {
pMgmt->eCurrState = WMAC_STATE_AUTH;
}
s_vMgrLogStatus(pMgmt,cpu_to_le16((*(sFrame.pwStatus))));
}
}
pDevice->bwextstep0 = false;
pDevice->bwextstep1 = false;
pDevice->bwextstep2 = false;
pDevice->bwextstep3 = false;
pDevice->bWPASuppWextEnabled = false;
if(pMgmt->eCurrState == WMAC_STATE_ASSOC)
timer_expire(pDevice->sTimerCommand, 0);
return;
}
void vMgrAuthenBeginSta(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, PCMD_STATUS pStatus)
{
WLAN_FR_AUTHEN sFrame;
struct vnt_tx_mgmt *pTxPacket =
(struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_AUTHEN_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_AUTHEN_FR_MAXLEN;
vMgrEncodeAuthen(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_AUTHEN)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pMgmt->abyCurrBSSID, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
if (pMgmt->bShareKeyAlgorithm)
*(sFrame.pwAuthAlgorithm) = cpu_to_le16(WLAN_AUTH_ALG_SHAREDKEY);
else
*(sFrame.pwAuthAlgorithm) = cpu_to_le16(WLAN_AUTH_ALG_OPENSYSTEM);
*(sFrame.pwAuthSequence) = cpu_to_le16(1);
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
*pStatus = csMgmt_xmit(pDevice, pTxPacket);
if (*pStatus == CMD_STATUS_PENDING){
pMgmt->eCurrState = WMAC_STATE_AUTHPENDING;
*pStatus = CMD_STATUS_SUCCESS;
}
return ;
}
void vMgrDeAuthenBeginSta(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, u8 *abyDestAddress, u16 wReason,
PCMD_STATUS pStatus)
{
WLAN_FR_DEAUTHEN sFrame;
struct vnt_tx_mgmt *pTxPacket =
(struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_DEAUTHEN_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_DEAUTHEN_FR_MAXLEN;
vMgrEncodeDeauthen(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_DEAUTHEN)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, abyDestAddress, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*(sFrame.pwReason) = cpu_to_le16(wReason);
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
*pStatus = csMgmt_xmit(pDevice, pTxPacket);
if (*pStatus == CMD_STATUS_PENDING){
*pStatus = CMD_STATUS_SUCCESS;
}
return ;
}
static void s_vMgrRxAuthentication(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket)
{
WLAN_FR_AUTHEN sFrame;
if (!(pMgmt->eCurrMode == WMAC_MODE_ESS_AP ||
pMgmt->eCurrState == WMAC_STATE_AUTHPENDING)) {
return;
}
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeAuthen(&sFrame);
switch (cpu_to_le16((*(sFrame.pwAuthSequence )))){
case 1:
s_vMgrRxAuthenSequence_1(pDevice,pMgmt, &sFrame);
break;
case 2:
s_vMgrRxAuthenSequence_2(pDevice, pMgmt, &sFrame);
break;
case 3:
s_vMgrRxAuthenSequence_3(pDevice, pMgmt, &sFrame);
break;
case 4:
s_vMgrRxAuthenSequence_4(pDevice, pMgmt, &sFrame);
break;
default:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Auth Sequence error, seq = %d\n",
cpu_to_le16((*(sFrame.pwAuthSequence))));
break;
}
return;
}
static void s_vMgrRxAuthenSequence_1(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, PWLAN_FR_AUTHEN pFrame)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
u32 uNodeIndex;
WLAN_FR_AUTHEN sFrame;
PSKeyItem pTransmitKey;
if (!BSSbIsSTAInNodeDB(pDevice, pFrame->pHdr->sA3.abyAddr2,
&uNodeIndex)) {
BSSvCreateOneNode(pDevice, &uNodeIndex);
memcpy(pMgmt->sNodeDBTable[uNodeIndex].abyMACAddr,
pFrame->pHdr->sA3.abyAddr2, WLAN_ADDR_LEN);
}
if (pMgmt->bShareKeyAlgorithm) {
pMgmt->sNodeDBTable[uNodeIndex].eNodeState = NODE_KNOWN;
pMgmt->sNodeDBTable[uNodeIndex].byAuthSequence = 1;
}
else {
pMgmt->sNodeDBTable[uNodeIndex].eNodeState = NODE_AUTH;
}
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_AUTHEN_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_AUTHEN_FR_MAXLEN;
vMgrEncodeAuthen(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_AUTHEN)|
WLAN_SET_FC_ISWEP(0)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pFrame->pHdr->sA3.abyAddr2, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*(sFrame.pwAuthAlgorithm) = *(pFrame->pwAuthAlgorithm);
*(sFrame.pwAuthSequence) = cpu_to_le16(2);
if (cpu_to_le16(*(pFrame->pwAuthAlgorithm)) == WLAN_AUTH_ALG_SHAREDKEY) {
if (pMgmt->bShareKeyAlgorithm)
*(sFrame.pwStatus) = cpu_to_le16(WLAN_MGMT_STATUS_SUCCESS);
else
*(sFrame.pwStatus) = cpu_to_le16(WLAN_MGMT_STATUS_UNSUPPORTED_AUTHALG);
}
else {
if (pMgmt->bShareKeyAlgorithm)
*(sFrame.pwStatus) = cpu_to_le16(WLAN_MGMT_STATUS_UNSUPPORTED_AUTHALG);
else
*(sFrame.pwStatus) = cpu_to_le16(WLAN_MGMT_STATUS_SUCCESS);
}
if (pMgmt->bShareKeyAlgorithm &&
(cpu_to_le16(*(sFrame.pwStatus)) == WLAN_MGMT_STATUS_SUCCESS)) {
sFrame.pChallenge = (PWLAN_IE_CHALLENGE)(sFrame.pBuf + sFrame.len);
sFrame.len += WLAN_CHALLENGE_IE_LEN;
sFrame.pChallenge->byElementID = WLAN_EID_CHALLENGE;
sFrame.pChallenge->len = WLAN_CHALLENGE_LEN;
memset(pMgmt->abyChallenge, 0, WLAN_CHALLENGE_LEN);
if(KeybGetTransmitKey(&(pDevice->sKey), pDevice->abyBroadcastAddr, GROUP_KEY, &pTransmitKey) == true) {
rc4_init(&pDevice->SBox, pDevice->abyPRNG, pTransmitKey->uKeyLength+3);
rc4_encrypt(&pDevice->SBox, pMgmt->abyChallenge, pMgmt->abyChallenge, WLAN_CHALLENGE_LEN);
}
memcpy(sFrame.pChallenge->abyChallenge, pMgmt->abyChallenge , WLAN_CHALLENGE_LEN);
}
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
if (pDevice->bEnableHostapd) {
return;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Authreq_reply sequence_1 tx.. \n");
if (csMgmt_xmit(pDevice, pTxPacket) != CMD_STATUS_PENDING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Authreq_reply sequence_1 tx failed.\n");
}
return;
}
static void s_vMgrRxAuthenSequence_2(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, PWLAN_FR_AUTHEN pFrame)
{
WLAN_FR_AUTHEN sFrame;
struct vnt_tx_mgmt *pTxPacket = NULL;
switch (cpu_to_le16((*(pFrame->pwAuthAlgorithm))))
{
case WLAN_AUTH_ALG_OPENSYSTEM:
if ( cpu_to_le16((*(pFrame->pwStatus))) == WLAN_MGMT_STATUS_SUCCESS ){
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "802.11 Authen (OPEN) Successful.\n");
pMgmt->eCurrState = WMAC_STATE_AUTH;
timer_expire(pDevice->sTimerCommand, 0);
}
else {
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "802.11 Authen (OPEN) Failed.\n");
s_vMgrLogStatus(pMgmt, cpu_to_le16((*(pFrame->pwStatus))));
pMgmt->eCurrState = WMAC_STATE_IDLE;
}
if (pDevice->eCommandState == WLAN_AUTHENTICATE_WAIT) {
}
break;
case WLAN_AUTH_ALG_SHAREDKEY:
if (cpu_to_le16((*(pFrame->pwStatus))) == WLAN_MGMT_STATUS_SUCCESS) {
pTxPacket = (struct vnt_tx_mgmt *)
pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_AUTHEN_FR_MAXLEN);
pTxPacket->p80211Header
= (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_AUTHEN_FR_MAXLEN;
vMgrEncodeAuthen(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_AUTHEN)|
WLAN_SET_FC_ISWEP(1)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*(sFrame.pwAuthAlgorithm) = *(pFrame->pwAuthAlgorithm);
*(sFrame.pwAuthSequence) = cpu_to_le16(3);
*(sFrame.pwStatus) = cpu_to_le16(WLAN_MGMT_STATUS_SUCCESS);
sFrame.pChallenge = (PWLAN_IE_CHALLENGE)(sFrame.pBuf + sFrame.len);
sFrame.len += WLAN_CHALLENGE_IE_LEN;
sFrame.pChallenge->byElementID = WLAN_EID_CHALLENGE;
sFrame.pChallenge->len = WLAN_CHALLENGE_LEN;
memcpy( sFrame.pChallenge->abyChallenge, pFrame->pChallenge->abyChallenge, WLAN_CHALLENGE_LEN);
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
if (csMgmt_xmit(pDevice, pTxPacket) != CMD_STATUS_PENDING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Auth_reply sequence_2 tx failed.\n");
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Auth_reply sequence_2 tx ...\n");
}
else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:rx Auth_reply sequence_2 status error ...\n");
if ( pDevice->eCommandState == WLAN_AUTHENTICATE_WAIT ) {
}
s_vMgrLogStatus(pMgmt, cpu_to_le16((*(pFrame->pwStatus))));
}
break;
default:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt: rx auth.seq = 2 unknown AuthAlgorithm=%d\n", cpu_to_le16((*(pFrame->pwAuthAlgorithm))));
break;
}
return;
}
static void s_vMgrRxAuthenSequence_3(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, PWLAN_FR_AUTHEN pFrame)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
u32 uStatusCode = 0 ;
u32 uNodeIndex = 0;
WLAN_FR_AUTHEN sFrame;
if (!WLAN_GET_FC_ISWEP(pFrame->pHdr->sA3.wFrameCtl)) {
uStatusCode = WLAN_MGMT_STATUS_CHALLENGE_FAIL;
goto reply;
}
if (BSSbIsSTAInNodeDB(pDevice, pFrame->pHdr->sA3.abyAddr2, &uNodeIndex)) {
if (pMgmt->sNodeDBTable[uNodeIndex].byAuthSequence != 1) {
uStatusCode = WLAN_MGMT_STATUS_RX_AUTH_NOSEQ;
goto reply;
}
if (memcmp(pMgmt->abyChallenge, pFrame->pChallenge->abyChallenge, WLAN_CHALLENGE_LEN) != 0) {
uStatusCode = WLAN_MGMT_STATUS_CHALLENGE_FAIL;
goto reply;
}
}
else {
uStatusCode = WLAN_MGMT_STATUS_UNSPEC_FAILURE;
goto reply;
}
if (uNodeIndex) {
pMgmt->sNodeDBTable[uNodeIndex].eNodeState = NODE_AUTH;
pMgmt->sNodeDBTable[uNodeIndex].byAuthSequence = 0;
}
uStatusCode = WLAN_MGMT_STATUS_SUCCESS;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Challenge text check ok..\n");
reply:
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_AUTHEN_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_AUTHEN_FR_MAXLEN;
vMgrEncodeAuthen(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_AUTHEN)|
WLAN_SET_FC_ISWEP(0)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pFrame->pHdr->sA3.abyAddr2, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*(sFrame.pwAuthAlgorithm) = *(pFrame->pwAuthAlgorithm);
*(sFrame.pwAuthSequence) = cpu_to_le16(4);
*(sFrame.pwStatus) = cpu_to_le16(uStatusCode);
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
if (pDevice->bEnableHostapd) {
return;
}
if (csMgmt_xmit(pDevice, pTxPacket) != CMD_STATUS_PENDING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Authreq_reply sequence_4 tx failed.\n");
}
return;
}
static void s_vMgrRxAuthenSequence_4(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, PWLAN_FR_AUTHEN pFrame)
{
if ( cpu_to_le16((*(pFrame->pwStatus))) == WLAN_MGMT_STATUS_SUCCESS ){
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "802.11 Authen (SHAREDKEY) Successful.\n");
pMgmt->eCurrState = WMAC_STATE_AUTH;
timer_expire(pDevice->sTimerCommand, 0);
}
else{
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO "802.11 Authen (SHAREDKEY) Failed.\n");
s_vMgrLogStatus(pMgmt, cpu_to_le16((*(pFrame->pwStatus))) );
pMgmt->eCurrState = WMAC_STATE_IDLE;
}
if ( pDevice->eCommandState == WLAN_AUTHENTICATE_WAIT ) {
}
}
static void s_vMgrRxDisassociation(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket)
{
WLAN_FR_DISASSOC sFrame;
u32 uNodeIndex = 0;
CMD_STATUS CmdStatus;
if ( pMgmt->eCurrMode == WMAC_MODE_ESS_AP ){
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
if (BSSbIsSTAInNodeDB(pDevice, pRxPacket->p80211Header->sA3.abyAddr2, &uNodeIndex)) {
BSSvRemoveOneNode(pDevice, uNodeIndex);
}
else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Rx disassoc, sta not found\n");
}
}
else if (pMgmt->eCurrMode == WMAC_MODE_ESS_STA ){
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeDisassociation(&sFrame);
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "AP disassociated me, reason=%d.\n", cpu_to_le16(*(sFrame.pwReason)));
pDevice->fWPA_Authened = false;
if (pMgmt->eCurrState == WMAC_STATE_ASSOC) {
pDevice->bLinkPass = false;
pMgmt->sNodeDBTable[0].bActive = false;
pDevice->byReAssocCount = 0;
pMgmt->eCurrState = WMAC_STATE_AUTH;
pDevice->eCommandState = WLAN_ASSOCIATE_WAIT;
vMgrReAssocBeginSta(pDevice, pMgmt, &CmdStatus);
if(CmdStatus == CMD_STATUS_PENDING) {
pDevice->byReAssocCount ++;
return;
}
}
{
union iwreq_data wrqu;
memset(&wrqu, 0, sizeof (wrqu));
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
PRINT_K("wireless_send_event--->SIOCGIWAP(disassociated)\n");
wireless_send_event(pDevice->dev, SIOCGIWAP, &wrqu, NULL);
}
}
return;
}
static void s_vMgrRxDeauthentication(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket)
{
WLAN_FR_DEAUTHEN sFrame;
u32 uNodeIndex = 0;
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP ){
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
if (BSSbIsSTAInNodeDB(pDevice, pRxPacket->p80211Header->sA3.abyAddr2, &uNodeIndex)) {
BSSvRemoveOneNode(pDevice, uNodeIndex);
}
else {
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Rx deauth, sta not found\n");
}
}
else {
if (pMgmt->eCurrMode == WMAC_MODE_ESS_STA ) {
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeDeauthen(&sFrame);
pDevice->fWPA_Authened = false;
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "AP deauthed me, reason=%d.\n", cpu_to_le16((*(sFrame.pwReason))));
if (!compare_ether_addr(sFrame.pHdr->sA3.abyAddr3,
pMgmt->abyCurrBSSID)) {
if (pMgmt->eCurrState >= WMAC_STATE_AUTHPENDING) {
pMgmt->sNodeDBTable[0].bActive = false;
pMgmt->eCurrMode = WMAC_MODE_STANDBY;
pMgmt->eCurrState = WMAC_STATE_IDLE;
netif_stop_queue(pDevice->dev);
pDevice->bLinkPass = false;
ControlvMaskByte(pDevice,MESSAGE_REQUEST_MACREG,MAC_REG_PAPEDELAY,LEDSTS_STS,LEDSTS_SLOW);
}
}
{
union iwreq_data wrqu;
memset(&wrqu, 0, sizeof (wrqu));
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
PRINT_K("wireless_send_event--->SIOCGIWAP(disauthen)\n");
wireless_send_event(pDevice->dev, SIOCGIWAP, &wrqu, NULL);
}
}
};
return;
}
static int ChannelExceedZoneType(struct vnt_private *pDevice, u8 byCurrChannel)
{
int exceed = false;
switch(pDevice->byZoneType) {
case 0x00:
if((byCurrChannel<1) ||(byCurrChannel>11))
exceed = true;
break;
case 0x01:
case 0x02:
if((byCurrChannel<1) ||(byCurrChannel>13))
exceed = true;
break;
default:
break;
}
return exceed;
}
static void s_vMgrRxBeacon(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket,
int bInScan)
{
PKnownBSS pBSSList;
WLAN_FR_BEACON sFrame;
u64 qwTSFOffset;
int bIsBSSIDEqual = false;
int bIsSSIDEqual = false;
int bTSFLargeDiff = false;
int bTSFOffsetPostive = false;
int bUpdateTSF = false;
int bIsAPBeacon = false;
int bIsChannelEqual = false;
u32 uLocateByteIndex;
u8 byTIMBitOn = 0;
u16 wAIDNumber = 0;
u32 uNodeIndex;
u64 qwTimestamp, qwLocalTSF;
u64 qwCurrTSF;
u16 wStartIndex = 0;
u16 wAIDIndex = 0;
u8 byCurrChannel = pRxPacket->byRxChannel;
ERPObject sERP;
u32 uRateLen = WLAN_RATES_MAXLEN;
int bChannelHit = false;
u8 byOldPreambleType;
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP)
return;
memset(&sFrame, 0, sizeof(WLAN_FR_BEACON));
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeBeacon(&sFrame);
if ((sFrame.pwBeaconInterval == NULL)
|| (sFrame.pwCapInfo == NULL)
|| (sFrame.pSSID == NULL)
|| (sFrame.pSuppRates == NULL)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Rx beacon frame error\n");
return;
}
if( byCurrChannel > CB_MAX_CHANNEL_24G )
{
if (sFrame.pDSParms != NULL) {
if (byCurrChannel == RFaby11aChannelIndex[sFrame.pDSParms->byCurrChannel-1])
bChannelHit = true;
byCurrChannel = RFaby11aChannelIndex[sFrame.pDSParms->byCurrChannel-1];
} else {
bChannelHit = true;
}
} else {
if (sFrame.pDSParms != NULL) {
if (byCurrChannel == sFrame.pDSParms->byCurrChannel)
bChannelHit = true;
byCurrChannel = sFrame.pDSParms->byCurrChannel;
} else {
bChannelHit = true;
}
}
if(ChannelExceedZoneType(pDevice,byCurrChannel)==true)
return;
if (sFrame.pERP != NULL) {
sERP.byERP = sFrame.pERP->byContext;
sERP.bERPExist = true;
} else {
sERP.bERPExist = false;
sERP.byERP = 0;
}
pBSSList = BSSpAddrIsInBSSList((void *) pDevice,
sFrame.pHdr->sA3.abyAddr3,
sFrame.pSSID);
if (pBSSList == NULL) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Beacon/insert: RxChannel = : %d\n", byCurrChannel);
BSSbInsertToBSSList((void *) pDevice,
sFrame.pHdr->sA3.abyAddr3,
*sFrame.pqwTimestamp,
*sFrame.pwBeaconInterval,
*sFrame.pwCapInfo,
byCurrChannel,
sFrame.pSSID,
sFrame.pSuppRates,
sFrame.pExtSuppRates,
&sERP,
sFrame.pRSN,
sFrame.pRSNWPA,
sFrame.pIE_Country,
sFrame.pIE_Quiet,
sFrame.len - WLAN_HDR_ADDR3_LEN,
sFrame.pHdr->sA4.abyAddr4,
(void *) pRxPacket);
}
else {
BSSbUpdateToBSSList((void *) pDevice,
*sFrame.pqwTimestamp,
*sFrame.pwBeaconInterval,
*sFrame.pwCapInfo,
byCurrChannel,
bChannelHit,
sFrame.pSSID,
sFrame.pSuppRates,
sFrame.pExtSuppRates,
&sERP,
sFrame.pRSN,
sFrame.pRSNWPA,
sFrame.pIE_Country,
sFrame.pIE_Quiet,
pBSSList,
sFrame.len - WLAN_HDR_ADDR3_LEN,
sFrame.pHdr->sA4.abyAddr4,
(void *) pRxPacket);
}
if (bInScan) {
return;
}
if(byCurrChannel == (BYTE)pMgmt->uCurrChannel)
bIsChannelEqual = true;
if (bIsChannelEqual && (pMgmt->eCurrMode == WMAC_MODE_ESS_AP)) {
if (sERP.bERPExist) {
if (WLAN_GET_ERP_USE_PROTECTION(sERP.byERP)){
pDevice->byERPFlag |= WLAN_SET_ERP_USE_PROTECTION(1);
pDevice->wUseProtectCntDown = USE_PROTECT_PERIOD;
}
}
else {
pDevice->byERPFlag |= WLAN_SET_ERP_USE_PROTECTION(1);
pDevice->wUseProtectCntDown = USE_PROTECT_PERIOD;
}
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
if(!WLAN_GET_CAP_INFO_SHORTPREAMBLE(*sFrame.pwCapInfo))
pDevice->byERPFlag |= WLAN_SET_ERP_BARKER_MODE(1);
if(!sERP.bERPExist)
pDevice->byERPFlag |= WLAN_SET_ERP_NONERP_PRESENT(1);
}
}
if (memcmp(sFrame.pHdr->sA3.abyAddr3,
pMgmt->abyCurrBSSID,
WLAN_BSSID_LEN) == 0) {
bIsBSSIDEqual = true;
pDevice->uCurrRSSI = pRxPacket->uRSSI;
pDevice->byCurrSQ = pRxPacket->bySQ;
if (pMgmt->sNodeDBTable[0].uInActiveCount != 0) {
pMgmt->sNodeDBTable[0].uInActiveCount = 0;
}
}
if (sFrame.pSSID->len == ((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->len) {
if (memcmp(sFrame.pSSID->abySSID,
((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->abySSID,
sFrame.pSSID->len
) == 0) {
bIsSSIDEqual = true;
}
}
if ((WLAN_GET_CAP_INFO_ESS(*sFrame.pwCapInfo)== true) &&
(bIsBSSIDEqual == true) &&
(bIsSSIDEqual == true) &&
(pMgmt->eCurrMode == WMAC_MODE_ESS_STA) &&
(pMgmt->eCurrState == WMAC_STATE_ASSOC)) {
bIsAPBeacon = true;
if (pBSSList != NULL) {
if ((pBSSList->sERP.bERPExist == true) && (pDevice->byBBType == BB_TYPE_11G)) {
if ((pBSSList->sERP.byERP & WLAN_EID_ERP_USE_PROTECTION) != pDevice->bProtectMode) {
pDevice->bProtectMode = (pBSSList->sERP.byERP & WLAN_EID_ERP_USE_PROTECTION);
if (pDevice->bProtectMode) {
MACvEnableProtectMD(pDevice);
} else {
MACvDisableProtectMD(pDevice);
}
vUpdateIFS(pDevice);
}
if ((pBSSList->sERP.byERP & WLAN_EID_ERP_NONERP_PRESENT) != pDevice->bNonERPPresent) {
pDevice->bNonERPPresent = (pBSSList->sERP.byERP & WLAN_EID_ERP_USE_PROTECTION);
}
if ((pBSSList->sERP.byERP & WLAN_EID_ERP_BARKER_MODE) != pDevice->bBarkerPreambleMd) {
pDevice->bBarkerPreambleMd = (pBSSList->sERP.byERP & WLAN_EID_ERP_BARKER_MODE);
if (pDevice->bBarkerPreambleMd) {
MACvEnableBarkerPreambleMd(pDevice);
} else {
MACvDisableBarkerPreambleMd(pDevice);
}
}
}
if (WLAN_GET_CAP_INFO_SHORTSLOTTIME(pBSSList->wCapInfo) != pDevice->bShortSlotTime) {
bool bShortSlotTime;
bShortSlotTime = WLAN_GET_CAP_INFO_SHORTSLOTTIME(pBSSList->wCapInfo);
if (pDevice->byBBType == BB_TYPE_11A) {
bShortSlotTime = true;
}
else if (pDevice->byBBType == BB_TYPE_11B) {
bShortSlotTime = false;
}
if (bShortSlotTime != pDevice->bShortSlotTime) {
pDevice->bShortSlotTime = bShortSlotTime;
BBvSetShortSlotTime(pDevice);
vUpdateIFS(pDevice);
}
}
byOldPreambleType = pDevice->byPreambleType;
if (WLAN_GET_CAP_INFO_SHORTPREAMBLE(pBSSList->wCapInfo)) {
pDevice->byPreambleType = pDevice->byShortPreamble;
}
else {
pDevice->byPreambleType = 0;
}
if (pDevice->byPreambleType != byOldPreambleType)
CARDvSetRSPINF(pDevice, (BYTE)pDevice->byBBType);
if (pBSSList->eNetworkTypeInUse == PHY_TYPE_11B) {
uRateLen = WLAN_RATES_MAXLEN_11B;
}
pMgmt->abyCurrSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)pBSSList->abySuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
uRateLen);
pMgmt->abyCurrExtSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)pBSSList->abyExtSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates,
uRateLen);
RATEvParseMaxRate((void *)pDevice,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates,
true,
&(pMgmt->sNodeDBTable[0].wMaxBasicRate),
&(pMgmt->sNodeDBTable[0].wMaxSuppRate),
&(pMgmt->sNodeDBTable[0].wSuppRate),
&(pMgmt->sNodeDBTable[0].byTopCCKBasicRate),
&(pMgmt->sNodeDBTable[0].byTopOFDMBasicRate)
);
}
}
if (WLAN_GET_CAP_INFO_ESS(*sFrame.pwCapInfo)) {
if (sFrame.pCFParms->wCFPDurRemaining > 0) {
}
}
qwTimestamp = cpu_to_le64(*sFrame.pqwTimestamp);
qwLocalTSF = pRxPacket->qwLocalTSF;
if (qwTimestamp >= qwLocalTSF)
bTSFOffsetPostive = true;
else
bTSFOffsetPostive = false;
if (bTSFOffsetPostive) {
qwTSFOffset = CARDqGetTSFOffset(pRxPacket->byRxRate, (qwTimestamp), (qwLocalTSF));
}
else {
qwTSFOffset = CARDqGetTSFOffset(pRxPacket->byRxRate, (qwLocalTSF), (qwTimestamp));
}
if (qwTSFOffset > TRIVIAL_SYNC_DIFFERENCE)
bTSFLargeDiff = true;
if (bIsAPBeacon == true) {
if (bTSFLargeDiff)
bUpdateTSF = true;
if ((pDevice->bEnablePSMode == true) && (sFrame.pTIM)) {
pMgmt->bMulticastTIM = WLAN_MGMT_IS_MULTICAST_TIM(sFrame.pTIM->byBitMapCtl) ? true : false ;
pMgmt->byDTIMCount = sFrame.pTIM->byDTIMCount;
pMgmt->byDTIMPeriod = sFrame.pTIM->byDTIMPeriod;
wAIDNumber = pMgmt->wCurrAID & ~(BIT14|BIT15);
wStartIndex = WLAN_MGMT_GET_TIM_OFFSET(sFrame.pTIM->byBitMapCtl) << 1;
wAIDIndex = (wAIDNumber >> 3);
if ((wAIDNumber > 0) && (wAIDIndex >= wStartIndex)) {
uLocateByteIndex = wAIDIndex - wStartIndex;
if (sFrame.pTIM->len >= (uLocateByteIndex + 4)) {
byTIMBitOn = (0x01) << ((wAIDNumber) % 8);
pMgmt->bInTIM = sFrame.pTIM->byVirtBitMap[uLocateByteIndex] & byTIMBitOn ? true : false;
}
else {
pMgmt->bInTIM = false;
};
}
else {
pMgmt->bInTIM = false;
};
if (pMgmt->bInTIM ||
(pMgmt->bMulticastTIM && (pMgmt->byDTIMCount == 0))) {
pMgmt->bInTIMWake = true;
if (pMgmt->bInTIM)
PSvSendPSPOLL(pDevice);
}
else {
pMgmt->bInTIMWake = false;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "BCN: Not In TIM..\n");
if (pDevice->bPWBitOn == false) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "BCN: Send Null Packet\n");
if (PSbSendNullPacket(pDevice))
pDevice->bPWBitOn = true;
}
if(PSbConsiderPowerDown(pDevice, false, false)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "BCN: Power down now...\n");
}
}
}
}
if ((pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) && !bIsAPBeacon && bIsChannelEqual) {
if (bIsBSSIDEqual) {
if (pMgmt->sNodeDBTable[0].uInActiveCount != 0)
pMgmt->sNodeDBTable[0].uInActiveCount = 0;
if (bTSFLargeDiff && bTSFOffsetPostive &&
(pMgmt->eCurrState == WMAC_STATE_JOINTED))
bUpdateTSF = true;
if (BSSbIsSTAInNodeDB(pDevice, sFrame.pHdr->sA3.abyAddr2, &uNodeIndex)) {
pMgmt->abyCurrSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)sFrame.pSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
WLAN_RATES_MAXLEN_11B);
RATEvParseMaxRate((void *)pDevice,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
NULL,
true,
&(pMgmt->sNodeDBTable[uNodeIndex].wMaxBasicRate),
&(pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate),
&(pMgmt->sNodeDBTable[uNodeIndex].wSuppRate),
&(pMgmt->sNodeDBTable[uNodeIndex].byTopCCKBasicRate),
&(pMgmt->sNodeDBTable[uNodeIndex].byTopOFDMBasicRate)
);
pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble = WLAN_GET_CAP_INFO_SHORTPREAMBLE(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].bShortSlotTime = WLAN_GET_CAP_INFO_SHORTSLOTTIME(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].uInActiveCount = 0;
}
else {
BSSvCreateOneNode(pDevice, &uNodeIndex);
pMgmt->abyCurrSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)sFrame.pSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
WLAN_RATES_MAXLEN_11B);
RATEvParseMaxRate((void *)pDevice,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
NULL,
true,
&(pMgmt->sNodeDBTable[uNodeIndex].wMaxBasicRate),
&(pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate),
&(pMgmt->sNodeDBTable[uNodeIndex].wSuppRate),
&(pMgmt->sNodeDBTable[uNodeIndex].byTopCCKBasicRate),
&(pMgmt->sNodeDBTable[uNodeIndex].byTopOFDMBasicRate)
);
memcpy(pMgmt->sNodeDBTable[uNodeIndex].abyMACAddr, sFrame.pHdr->sA3.abyAddr2, WLAN_ADDR_LEN);
pMgmt->sNodeDBTable[uNodeIndex].bShortPreamble = WLAN_GET_CAP_INFO_SHORTPREAMBLE(*sFrame.pwCapInfo);
pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate = pMgmt->sNodeDBTable[uNodeIndex].wMaxSuppRate;
}
if (pMgmt->eCurrState == WMAC_STATE_STARTED) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Current IBSS State: [Started]........to: [Jointed] \n");
pMgmt->eCurrState = WMAC_STATE_JOINTED;
pDevice->bLinkPass = true;
ControlvMaskByte(pDevice,MESSAGE_REQUEST_MACREG,MAC_REG_PAPEDELAY,LEDSTS_STS,LEDSTS_INTER);
if (netif_queue_stopped(pDevice->dev)){
netif_wake_queue(pDevice->dev);
}
pMgmt->sNodeDBTable[0].bActive = true;
pMgmt->sNodeDBTable[0].uInActiveCount = 0;
}
}
else if (bIsSSIDEqual) {
if (bTSFLargeDiff && bTSFOffsetPostive) {
memcpy(pMgmt->abyCurrBSSID, sFrame.pHdr->sA3.abyAddr3, WLAN_BSSID_LEN);
memcpy(pDevice->abyBSSID, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
pMgmt->wCurrATIMWindow = cpu_to_le16(sFrame.pIBSSParms->wATIMWindow);
pMgmt->wCurrBeaconPeriod = cpu_to_le16(*sFrame.pwBeaconInterval);
pMgmt->abyCurrSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)sFrame.pSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
WLAN_RATES_MAXLEN_11B);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Rejoining to Other Adhoc group with same SSID........\n");
MACvWriteBeaconInterval(pDevice, pMgmt->wCurrBeaconPeriod);
CARDvAdjustTSF(pDevice, pRxPacket->byRxRate, qwTimestamp, pRxPacket->qwLocalTSF);
CARDvUpdateNextTBTT(pDevice, qwTimestamp, pMgmt->wCurrBeaconPeriod);
MACvWriteBSSIDAddress(pDevice, pMgmt->abyCurrBSSID);
byOldPreambleType = pDevice->byPreambleType;
if (WLAN_GET_CAP_INFO_SHORTPREAMBLE(*sFrame.pwCapInfo)) {
pDevice->byPreambleType = pDevice->byShortPreamble;
}
else {
pDevice->byPreambleType = 0;
}
if (pDevice->byPreambleType != byOldPreambleType)
CARDvSetRSPINF(pDevice, (BYTE)pDevice->byBBType);
bMgrPrepareBeaconToSend((void *) pDevice, pMgmt);
}
}
}
if (bUpdateTSF) {
CARDbGetCurrentTSF(pDevice, &qwCurrTSF);
CARDvAdjustTSF(pDevice, pRxPacket->byRxRate, qwTimestamp , pRxPacket->qwLocalTSF);
CARDbGetCurrentTSF(pDevice, &qwCurrTSF);
CARDvUpdateNextTBTT(pDevice, qwTimestamp, pMgmt->wCurrBeaconPeriod);
}
return;
}
void vMgrCreateOwnIBSS(struct vnt_private *pDevice, PCMD_STATUS pStatus)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
u16 wMaxBasicRate;
u16 wMaxSuppRate;
u8 byTopCCKBasicRate;
u8 byTopOFDMBasicRate;
u64 qwCurrTSF = 0;
int ii;
u8 abyRATE[] = {0x82, 0x84, 0x8B, 0x96, 0x24, 0x30, 0x48, 0x6C, 0x0C,
0x12, 0x18, 0x60};
u8 abyCCK_RATE[] = {0x82, 0x84, 0x8B, 0x96};
u8 abyOFDM_RATE[] = {0x0C, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C};
u16 wSuppRate;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Create Basic Service Set .......\n");
if (pMgmt->eConfigMode == WMAC_CONFIG_IBSS_STA) {
if ((pMgmt->eAuthenMode == WMAC_AUTH_WPANONE) &&
(pDevice->eEncryptionStatus != Ndis802_11Encryption2Enabled) &&
(pDevice->eEncryptionStatus != Ndis802_11Encryption3Enabled)) {
*pStatus = CMD_STATUS_FAILURE;
return;
}
}
pMgmt->abyCurrSuppRates[0] = WLAN_EID_SUPP_RATES;
pMgmt->abyCurrExtSuppRates[0] = WLAN_EID_EXTSUPP_RATES;
if (pMgmt->eConfigMode == WMAC_CONFIG_AP) {
pMgmt->eCurrentPHYMode = pMgmt->byAPBBType;
} else {
if (pDevice->byBBType == BB_TYPE_11G)
pMgmt->eCurrentPHYMode = PHY_TYPE_11G;
if (pDevice->byBBType == BB_TYPE_11B)
pMgmt->eCurrentPHYMode = PHY_TYPE_11B;
if (pDevice->byBBType == BB_TYPE_11A)
pMgmt->eCurrentPHYMode = PHY_TYPE_11A;
}
if (pMgmt->eCurrentPHYMode != PHY_TYPE_11A) {
pMgmt->abyCurrSuppRates[1] = WLAN_RATES_MAXLEN_11B;
pMgmt->abyCurrExtSuppRates[1] = 0;
for (ii = 0; ii < 4; ii++)
pMgmt->abyCurrSuppRates[2+ii] = abyRATE[ii];
} else {
pMgmt->abyCurrSuppRates[1] = 8;
pMgmt->abyCurrExtSuppRates[1] = 0;
for (ii = 0; ii < 8; ii++)
pMgmt->abyCurrSuppRates[2+ii] = abyRATE[ii];
}
if (pMgmt->eCurrentPHYMode == PHY_TYPE_11G) {
pMgmt->abyCurrSuppRates[1] = 8;
pMgmt->abyCurrExtSuppRates[1] = 4;
for (ii = 0; ii < 4; ii++)
pMgmt->abyCurrSuppRates[2+ii] = abyCCK_RATE[ii];
for (ii = 4; ii < 8; ii++)
pMgmt->abyCurrSuppRates[2+ii] = abyOFDM_RATE[ii-4];
for (ii = 0; ii < 4; ii++)
pMgmt->abyCurrExtSuppRates[2+ii] = abyOFDM_RATE[ii+4];
}
pDevice->bProtectMode = 0;
MACvDisableProtectMD(pDevice);
pDevice->bBarkerPreambleMd = 0;
MACvDisableBarkerPreambleMd(pDevice);
if (pMgmt->wIBSSBeaconPeriod == 0)
pMgmt->wIBSSBeaconPeriod = DEFAULT_IBSS_BI;
MACvWriteBeaconInterval(pDevice, pMgmt->wIBSSBeaconPeriod);
CARDbGetCurrentTSF(pDevice, &qwCurrTSF);
CARDbClearCurrentTSF(pDevice);
MACvRegBitsOn(pDevice,MAC_REG_TFTCTL,TFTCTL_TSFCNTREN);
CARDvSetFirstNextTBTT(pDevice, pMgmt->wIBSSBeaconPeriod);
pMgmt->uIBSSChannel = pDevice->uChannel;
if (pMgmt->uIBSSChannel == 0)
pMgmt->uIBSSChannel = DEFAULT_IBSS_CHANNEL;
CARDbSetMediaChannel(pDevice, pMgmt->uIBSSChannel);
pMgmt->uCurrChannel = pMgmt->uIBSSChannel;
pDevice->byPreambleType = pDevice->byShortPreamble;
RATEvParseMaxRate((void *)pDevice,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates, true,
&wMaxBasicRate, &wMaxSuppRate, &wSuppRate,
&byTopCCKBasicRate, &byTopOFDMBasicRate);
if (pDevice->byBBType == BB_TYPE_11A) {
pDevice->bShortSlotTime = true;
} else {
pDevice->bShortSlotTime = false;
}
BBvSetShortSlotTime(pDevice);
CARDvSetBSSMode(pDevice);
if (pMgmt->eConfigMode == WMAC_CONFIG_AP) {
MACvRegBitsOn(pDevice, MAC_REG_HOSTCR, HOSTCR_AP);
pMgmt->eCurrMode = WMAC_MODE_ESS_AP;
}
if (pMgmt->eConfigMode == WMAC_CONFIG_IBSS_STA) {
MACvRegBitsOn(pDevice, MAC_REG_HOSTCR, HOSTCR_ADHOC);
pMgmt->eCurrMode = WMAC_MODE_IBSS_STA;
}
pMgmt->eCurrState = WMAC_STATE_STARTED;
pMgmt->wCurrBeaconPeriod = pMgmt->wIBSSBeaconPeriod;
pMgmt->uCurrChannel = pMgmt->uIBSSChannel;
pMgmt->wCurrATIMWindow = pMgmt->wIBSSATIMWindow;
pDevice->uCurrRSSI = 0;
pDevice->byCurrSQ = 0;
memcpy(pMgmt->abyDesireSSID,pMgmt->abyAdHocSSID,
((PWLAN_IE_SSID)pMgmt->abyAdHocSSID)->len + WLAN_IEHDR_LEN);
memset(pMgmt->abyCurrSSID, 0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
memcpy(pMgmt->abyCurrSSID,
pMgmt->abyDesireSSID,
((PWLAN_IE_SSID)pMgmt->abyDesireSSID)->len + WLAN_IEHDR_LEN
);
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
memcpy(pMgmt->abyCurrBSSID, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO"AP beacon created BSSID:"
"%pM\n", pMgmt->abyCurrBSSID);
}
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
pMgmt->abyCurrBSSID[5] = (u8)(qwCurrTSF & 0x000000ff);
pMgmt->abyCurrBSSID[4] = (u8)((qwCurrTSF & 0x0000ff00) >> 8);
pMgmt->abyCurrBSSID[3] = (u8)((qwCurrTSF & 0x00ff0000) >> 16);
pMgmt->abyCurrBSSID[2] = (u8)((qwCurrTSF & 0x00000ff0) >> 4);
pMgmt->abyCurrBSSID[1] = (u8)((qwCurrTSF & 0x000ff000) >> 12);
pMgmt->abyCurrBSSID[0] = (u8)((qwCurrTSF & 0x0ff00000) >> 20);
pMgmt->abyCurrBSSID[5] ^= pMgmt->abyMACAddr[0];
pMgmt->abyCurrBSSID[4] ^= pMgmt->abyMACAddr[1];
pMgmt->abyCurrBSSID[3] ^= pMgmt->abyMACAddr[2];
pMgmt->abyCurrBSSID[2] ^= pMgmt->abyMACAddr[3];
pMgmt->abyCurrBSSID[1] ^= pMgmt->abyMACAddr[4];
pMgmt->abyCurrBSSID[0] ^= pMgmt->abyMACAddr[5];
pMgmt->abyCurrBSSID[0] &= ~IEEE_ADDR_GROUP;
pMgmt->abyCurrBSSID[0] |= IEEE_ADDR_UNIVERSAL;
DBG_PRT(MSG_LEVEL_INFO, KERN_INFO"Adhoc beacon created bssid:"
"%pM\n", pMgmt->abyCurrBSSID);
}
MACvWriteBSSIDAddress(pDevice, pMgmt->abyCurrBSSID);
memcpy(pDevice->abyBSSID, pMgmt->abyCurrBSSID, WLAN_ADDR_LEN);
MACvRegBitsOn(pDevice, MAC_REG_RCR, RCR_BSSID);
pDevice->byRxMode |= RCR_BSSID;
pMgmt->bCurrBSSIDFilterOn = true;
pMgmt->wCurrCapInfo = 0;
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_ESS(1);
pMgmt->byDTIMPeriod = DEFAULT_DTIM_PERIOD;
pMgmt->byDTIMCount = pMgmt->byDTIMPeriod - 1;
pDevice->eOPMode = OP_MODE_AP;
}
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_IBSS(1);
pDevice->eOPMode = OP_MODE_ADHOC;
}
if (pDevice->bEncryptionEnable) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_PRIVACY(1);
if (pMgmt->eAuthenMode == WMAC_AUTH_WPANONE) {
if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) {
pMgmt->byCSSPK = KEY_CTL_CCMP;
pMgmt->byCSSGK = KEY_CTL_CCMP;
} else if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) {
pMgmt->byCSSPK = KEY_CTL_TKIP;
pMgmt->byCSSGK = KEY_CTL_TKIP;
} else {
pMgmt->byCSSPK = KEY_CTL_NONE;
pMgmt->byCSSGK = KEY_CTL_WEP;
}
} else {
pMgmt->byCSSPK = KEY_CTL_WEP;
pMgmt->byCSSGK = KEY_CTL_WEP;
}
}
pMgmt->byERPContext = 0;
if (pDevice->byPreambleType == 1) {
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_SHORTPREAMBLE(1);
} else {
pMgmt->wCurrCapInfo &= (~WLAN_SET_CAP_INFO_SHORTPREAMBLE(1));
}
pMgmt->eCurrState = WMAC_STATE_STARTED;
if (bMgrPrepareBeaconToSend((void *) pDevice, pMgmt))
*pStatus = CMD_STATUS_SUCCESS;
return;
}
void vMgrJoinBSSBegin(struct vnt_private *pDevice, PCMD_STATUS pStatus)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
PKnownBSS pCurr = NULL;
int ii, uu;
PWLAN_IE_SUPP_RATES pItemRates = NULL;
PWLAN_IE_SUPP_RATES pItemExtRates = NULL;
PWLAN_IE_SSID pItemSSID;
u32 uRateLen = WLAN_RATES_MAXLEN;
u16 wMaxBasicRate = RATE_1M;
u16 wMaxSuppRate = RATE_1M;
u16 wSuppRate;
u8 byTopCCKBasicRate = RATE_1M;
u8 byTopOFDMBasicRate = RATE_1M;
u8 bShortSlotTime = false;
for (ii = 0; ii < MAX_BSS_NUM; ii++) {
if (pMgmt->sBSSList[ii].bActive == true)
break;
}
if (ii == MAX_BSS_NUM) {
*pStatus = CMD_STATUS_RESOURCES;
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "BSS finding:BSS list is empty.\n");
return;
}
pCurr = BSSpSearchBSSList(pDevice,
pMgmt->abyDesireBSSID,
pMgmt->abyDesireSSID,
pDevice->eConfigPHYMode
);
if (pCurr == NULL){
*pStatus = CMD_STATUS_RESOURCES;
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyDesireSSID;
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Scanning [%s] not found, disconnected !\n", pItemSSID->abySSID);
return;
}
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "AP(BSS) finding:Found a AP(BSS)..\n");
if (WLAN_GET_CAP_INFO_ESS(cpu_to_le16(pCurr->wCapInfo))){
if ((pMgmt->eAuthenMode == WMAC_AUTH_WPA) ||
(pMgmt->eAuthenMode == WMAC_AUTH_WPAPSK)) {
}
Encyption_Rebuild(pDevice, pCurr);
s_vMgrSynchBSS(pDevice,
WMAC_MODE_ESS_STA,
pCurr,
pStatus
);
if (*pStatus == CMD_STATUS_SUCCESS){
pMgmt->uCurrChannel = pCurr->uChannel;
memset(pMgmt->abyCurrSuppRates, 0 , WLAN_IEHDR_LEN + WLAN_RATES_MAXLEN + 1);
memset(pMgmt->abyCurrExtSuppRates, 0 , WLAN_IEHDR_LEN + WLAN_RATES_MAXLEN + 1);
if (pCurr->eNetworkTypeInUse == PHY_TYPE_11B) {
uRateLen = WLAN_RATES_MAXLEN_11B;
}
pItemRates = (PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates;
pItemExtRates = (PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates;
pItemRates->byElementID = WLAN_EID_SUPP_RATES;
pItemRates->len = RATEuSetIE((PWLAN_IE_SUPP_RATES)pCurr->abySuppRates,
pItemRates,
uRateLen);
pItemExtRates->byElementID = WLAN_EID_EXTSUPP_RATES;
pItemExtRates->len = RATEuSetIE((PWLAN_IE_SUPP_RATES)pCurr->abyExtSuppRates,
pItemExtRates,
uRateLen);
if ((pItemExtRates->len > 0) && (pItemRates->len < 8)) {
for (ii = 0; ii < (unsigned int) (8 - pItemRates->len); ) {
pItemRates->abyRates[pItemRates->len + ii] =
pItemExtRates->abyRates[ii];
ii++;
if (pItemExtRates->len <= ii)
break;
}
pItemRates->len += (BYTE)ii;
if (pItemExtRates->len - ii > 0) {
pItemExtRates->len -= (BYTE)ii;
for (uu = 0; uu < pItemExtRates->len; uu ++) {
pItemExtRates->abyRates[uu] = pItemExtRates->abyRates[uu + ii];
}
} else {
pItemExtRates->len = 0;
}
}
RATEvParseMaxRate((void *)pDevice, pItemRates, pItemExtRates, true,
&wMaxBasicRate, &wMaxSuppRate, &wSuppRate,
&byTopCCKBasicRate, &byTopOFDMBasicRate);
vUpdateIFS(pDevice);
pMgmt->wCurrBeaconPeriod = pCurr->wBeaconInterval;
memset(pMgmt->abyCurrSSID, 0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
memcpy(pMgmt->abyCurrBSSID, pCurr->abyBSSID, WLAN_BSSID_LEN);
memcpy(pMgmt->abyCurrSSID, pCurr->abySSID, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
pMgmt->eCurrMode = WMAC_MODE_ESS_STA;
pMgmt->eCurrState = WMAC_STATE_JOINTED;
pDevice->eOPMode = OP_MODE_INFRASTRUCTURE;
memcpy(pDevice->abyBSSID, pCurr->abyBSSID, WLAN_BSSID_LEN);
if (pMgmt->eAuthenMode == WMAC_AUTH_WPA2) {
bool bResult = bAdd_PMKID_Candidate((void *) pDevice,
pMgmt->abyCurrBSSID,
&pCurr->sRSNCapObj);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"bAdd_PMKID_Candidate: 1(%d)\n", bResult);
if (bResult == false) {
vFlush_PMKID_Candidate((void *) pDevice);
DBG_PRT(MSG_LEVEL_DEBUG,
KERN_INFO "vFlush_PMKID_Candidate: 4\n");
bAdd_PMKID_Candidate((void *) pDevice,
pMgmt->abyCurrBSSID,
&pCurr->sRSNCapObj);
}
}
if (WLAN_GET_CAP_INFO_SHORTPREAMBLE(pCurr->wCapInfo)) {
pDevice->byPreambleType = pDevice->byShortPreamble;
}
else {
pDevice->byPreambleType = 0;
}
CARDvSetRSPINF(pDevice, (BYTE)pDevice->byBBType);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Join ESS\n");
if (pCurr->eNetworkTypeInUse == PHY_TYPE_11G) {
if ((pCurr->sERP.byERP & WLAN_EID_ERP_USE_PROTECTION) != pDevice->bProtectMode) {
pDevice->bProtectMode = (pCurr->sERP.byERP & WLAN_EID_ERP_USE_PROTECTION);
if (pDevice->bProtectMode) {
MACvEnableProtectMD(pDevice);
} else {
MACvDisableProtectMD(pDevice);
}
vUpdateIFS(pDevice);
}
if ((pCurr->sERP.byERP & WLAN_EID_ERP_NONERP_PRESENT) != pDevice->bNonERPPresent) {
pDevice->bNonERPPresent = (pCurr->sERP.byERP & WLAN_EID_ERP_USE_PROTECTION);
}
if ((pCurr->sERP.byERP & WLAN_EID_ERP_BARKER_MODE) != pDevice->bBarkerPreambleMd) {
pDevice->bBarkerPreambleMd = (pCurr->sERP.byERP & WLAN_EID_ERP_BARKER_MODE);
if (pDevice->bBarkerPreambleMd) {
MACvEnableBarkerPreambleMd(pDevice);
} else {
MACvDisableBarkerPreambleMd(pDevice);
}
}
}
if (WLAN_GET_CAP_INFO_SHORTSLOTTIME(pCurr->wCapInfo) != pDevice->bShortSlotTime) {
if (pDevice->byBBType == BB_TYPE_11A) {
bShortSlotTime = true;
}
else if (pDevice->byBBType == BB_TYPE_11B) {
bShortSlotTime = false;
}
else {
bShortSlotTime = WLAN_GET_CAP_INFO_SHORTSLOTTIME(pCurr->wCapInfo);
}
if (bShortSlotTime != pDevice->bShortSlotTime) {
pDevice->bShortSlotTime = bShortSlotTime;
BBvSetShortSlotTime(pDevice);
vUpdateIFS(pDevice);
}
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"End of Join AP -- A/B/G Action\n");
}
else {
pMgmt->eCurrState = WMAC_STATE_IDLE;
};
}
else {
if (pMgmt->eAuthenMode == WMAC_AUTH_WPANONE) {
if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) {
} else if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) {
} else {
pMgmt->eCurrState = WMAC_STATE_IDLE;
return;
}
}
s_vMgrSynchBSS(pDevice,
WMAC_MODE_IBSS_STA,
pCurr,
pStatus
);
if (*pStatus == CMD_STATUS_SUCCESS){
pMgmt->uCurrChannel = pCurr->uChannel;
pMgmt->abyCurrSuppRates[0] = WLAN_EID_SUPP_RATES;
pMgmt->abyCurrSuppRates[1] = RATEuSetIE((PWLAN_IE_SUPP_RATES)pCurr->abySuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
WLAN_RATES_MAXLEN_11B);
RATEvParseMaxRate((void *)pDevice,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
NULL, true, &wMaxBasicRate, &wMaxSuppRate, &wSuppRate,
&byTopCCKBasicRate, &byTopOFDMBasicRate);
vUpdateIFS(pDevice);
pMgmt->wCurrCapInfo = pCurr->wCapInfo;
pMgmt->wCurrBeaconPeriod = pCurr->wBeaconInterval;
memset(pMgmt->abyCurrSSID, 0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN);
memcpy(pMgmt->abyCurrBSSID, pCurr->abyBSSID, WLAN_BSSID_LEN);
memcpy(pMgmt->abyCurrSSID, pCurr->abySSID, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN);
pMgmt->eCurrMode = WMAC_MODE_IBSS_STA;
pMgmt->eCurrState = WMAC_STATE_STARTED;
pDevice->eOPMode = OP_MODE_ADHOC;
pDevice->bLinkPass = true;
ControlvMaskByte(pDevice,MESSAGE_REQUEST_MACREG,MAC_REG_PAPEDELAY,LEDSTS_STS,LEDSTS_INTER);
memcpy(pDevice->abyBSSID, pCurr->abyBSSID, WLAN_BSSID_LEN);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Join IBSS ok:%pM\n",
pMgmt->abyCurrBSSID);
if (WLAN_GET_CAP_INFO_SHORTPREAMBLE(pCurr->wCapInfo)) {
pDevice->byPreambleType = pDevice->byShortPreamble;
}
else {
pDevice->byPreambleType = 0;
}
CARDvSetRSPINF(pDevice, (BYTE)pDevice->byBBType);
bMgrPrepareBeaconToSend((void *) pDevice, pMgmt);
}
else {
pMgmt->eCurrState = WMAC_STATE_IDLE;
};
};
return;
}
static void s_vMgrSynchBSS(struct vnt_private *pDevice, u32 uBSSMode,
PKnownBSS pCurr, PCMD_STATUS pStatus)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
u8 abyCurrSuppRatesG[] = {WLAN_EID_SUPP_RATES,
8, 0x02, 0x04, 0x0B, 0x16, 0x24, 0x30, 0x48, 0x6C};
u8 abyCurrExtSuppRatesG[] = {WLAN_EID_EXTSUPP_RATES,
4, 0x0C, 0x12, 0x18, 0x60};
u8 abyCurrSuppRatesA[] = {WLAN_EID_SUPP_RATES,
8, 0x0C, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C};
u8 abyCurrSuppRatesB[] = {WLAN_EID_SUPP_RATES,
4, 0x02, 0x04, 0x0B, 0x16};
*pStatus = CMD_STATUS_FAILURE;
if (s_bCipherMatch(pCurr,
pDevice->eEncryptionStatus,
&(pMgmt->byCSSPK),
&(pMgmt->byCSSGK)) == false) {
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "s_bCipherMatch Fail .......\n");
return;
}
pMgmt->pCurrBSS = pCurr;
if(pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
MACvRegBitsOff(pDevice, MAC_REG_TCR, TCR_AUTOBCNTX);
}
pDevice->bCCK = true;
pDevice->bProtectMode = false;
MACvDisableProtectMD(pDevice);
pDevice->bBarkerPreambleMd = false;
MACvDisableBarkerPreambleMd(pDevice);
pDevice->bNonERPPresent = false;
pDevice->byPreambleType = 0;
pDevice->wBasicRate = 0;
CARDbAddBasicRate((void *)pDevice, RATE_1M);
CARDvAdjustTSF(pDevice, pCurr->byRxRate, pCurr->qwBSSTimestamp, pCurr->qwLocalTSF);
MACvWriteBeaconInterval(pDevice, pCurr->wBeaconInterval);
CARDvSetFirstNextTBTT(pDevice, pCurr->wBeaconInterval);
MACvWriteBSSIDAddress(pDevice, pCurr->abyBSSID);
memcpy(pMgmt->abyCurrBSSID, pCurr->abyBSSID, 6);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Sync:set CurrBSSID address = "
"%pM\n", pMgmt->abyCurrBSSID);
if (pCurr->eNetworkTypeInUse == PHY_TYPE_11A) {
if ((pDevice->eConfigPHYMode == PHY_TYPE_11A) ||
(pDevice->eConfigPHYMode == PHY_TYPE_AUTO)) {
pDevice->byBBType = BB_TYPE_11A;
pMgmt->eCurrentPHYMode = PHY_TYPE_11A;
pDevice->bShortSlotTime = true;
BBvSetShortSlotTime(pDevice);
CARDvSetBSSMode(pDevice);
} else {
return;
}
} else if (pCurr->eNetworkTypeInUse == PHY_TYPE_11B) {
if ((pDevice->eConfigPHYMode == PHY_TYPE_11B) ||
(pDevice->eConfigPHYMode == PHY_TYPE_11G) ||
(pDevice->eConfigPHYMode == PHY_TYPE_AUTO)) {
pDevice->byBBType = BB_TYPE_11B;
pMgmt->eCurrentPHYMode = PHY_TYPE_11B;
pDevice->bShortSlotTime = false;
BBvSetShortSlotTime(pDevice);
CARDvSetBSSMode(pDevice);
} else {
return;
}
} else {
if ((pDevice->eConfigPHYMode == PHY_TYPE_11G) ||
(pDevice->eConfigPHYMode == PHY_TYPE_AUTO)) {
pDevice->byBBType = BB_TYPE_11G;
pMgmt->eCurrentPHYMode = PHY_TYPE_11G;
pDevice->bShortSlotTime = true;
BBvSetShortSlotTime(pDevice);
CARDvSetBSSMode(pDevice);
} else if (pDevice->eConfigPHYMode == PHY_TYPE_11B) {
pDevice->byBBType = BB_TYPE_11B;
pDevice->bShortSlotTime = false;
BBvSetShortSlotTime(pDevice);
CARDvSetBSSMode(pDevice);
} else {
return;
}
}
if (uBSSMode == WMAC_MODE_ESS_STA) {
MACvRegBitsOff(pDevice, MAC_REG_HOSTCR, HOSTCR_ADHOC);
MACvRegBitsOn(pDevice, MAC_REG_RCR, RCR_BSSID);
pDevice->byRxMode |= RCR_BSSID;
pMgmt->bCurrBSSIDFilterOn = true;
}
CARDbSetMediaChannel(pDevice, pCurr->uChannel);
pMgmt->uCurrChannel = pCurr->uChannel;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "<----s_bSynchBSS Set Channel [%d]\n", pCurr->uChannel);
if ((pDevice->bUpdateBBVGA) &&
(pDevice->byBBVGACurrent != pDevice->abyBBVGA[0])) {
pDevice->byBBVGACurrent = pDevice->abyBBVGA[0];
BBvSetVGAGainOffset(pDevice, pDevice->byBBVGACurrent);
BBvSetShortSlotTime(pDevice);
}
if (uBSSMode == WMAC_MODE_IBSS_STA) {
MACvRegBitsOn(pDevice, MAC_REG_HOSTCR, HOSTCR_ADHOC);
MACvRegBitsOn(pDevice, MAC_REG_RCR, RCR_BSSID);
pDevice->byRxMode |= RCR_BSSID;
pMgmt->bCurrBSSIDFilterOn = true;
}
if (pDevice->byBBType == BB_TYPE_11A) {
memcpy(pMgmt->abyCurrSuppRates, &abyCurrSuppRatesA[0], sizeof(abyCurrSuppRatesA));
pMgmt->abyCurrExtSuppRates[1] = 0;
} else if (pDevice->byBBType == BB_TYPE_11B) {
memcpy(pMgmt->abyCurrSuppRates, &abyCurrSuppRatesB[0], sizeof(abyCurrSuppRatesB));
pMgmt->abyCurrExtSuppRates[1] = 0;
} else {
memcpy(pMgmt->abyCurrSuppRates, &abyCurrSuppRatesG[0], sizeof(abyCurrSuppRatesG));
memcpy(pMgmt->abyCurrExtSuppRates, &abyCurrExtSuppRatesG[0], sizeof(abyCurrExtSuppRatesG));
}
pMgmt->byERPContext = pCurr->sERP.byERP;
*pStatus = CMD_STATUS_SUCCESS;
return;
}
static void Encyption_Rebuild(struct vnt_private *pDevice, PKnownBSS pCurr)
{
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
if ((pMgmt->eAuthenMode == WMAC_AUTH_WPAPSK) ||
(pMgmt->eAuthenMode == WMAC_AUTH_WPA2PSK)) {
if (pCurr->bWPAValid == true) {
pMgmt->eAuthenMode = WMAC_AUTH_WPAPSK;
if(pCurr->abyPKType[0] == WPA_TKIP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption2Enabled;
PRINT_K("Encyption_Rebuild--->ssid reset config to [WPAPSK-TKIP]\n");
}
else if(pCurr->abyPKType[0] == WPA_AESCCMP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption3Enabled;
PRINT_K("Encyption_Rebuild--->ssid reset config to [WPAPSK-AES]\n");
}
}
else if(pCurr->bWPA2Valid == true) {
pMgmt->eAuthenMode = WMAC_AUTH_WPA2PSK;
if(pCurr->abyCSSPK[0] == WLAN_11i_CSS_TKIP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption2Enabled;
PRINT_K("Encyption_Rebuild--->ssid reset config to [WPA2PSK-TKIP]\n");
}
else if(pCurr->abyCSSPK[0] == WLAN_11i_CSS_CCMP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption3Enabled;
PRINT_K("Encyption_Rebuild--->ssid reset config to [WPA2PSK-AES]\n");
}
}
}
return;
}
static void s_vMgrFormatTIM(struct vnt_manager *pMgmt, PWLAN_IE_TIM pTIM)
{
u8 byMask[8] = {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80};
u8 byMap;
int ii, jj;
int bStartFound = false;
int bMulticast = false;
u16 wStartIndex = 0;
u16 wEndIndex = 0;
for (ii = 0; ii < (MAX_NODE_NUM + 1); ii++) {
byMap = pMgmt->abyPSTxMap[ii];
if (!ii) {
bMulticast = (byMap & byMask[0]) != 0;
if(bMulticast) {
pMgmt->sNodeDBTable[0].bRxPSPoll = true;
}
byMap = 0;
}
if (byMap) {
if (!bStartFound) {
bStartFound = true;
wStartIndex = (WORD)ii;
}
wEndIndex = (WORD)ii;
}
}
wStartIndex &= ~BIT0;
wEndIndex = ((wEndIndex + 1) & ~BIT0);
pTIM->len = 3 + (wEndIndex - wStartIndex) + 1;
pTIM->byDTIMCount = pMgmt->byDTIMCount;
pTIM->byDTIMPeriod = pMgmt->byDTIMPeriod;
pTIM->byBitMapCtl = (bMulticast ? TIM_MULTICAST_MASK : 0) |
(((wStartIndex >> 1) << 1) & TIM_BITMAPOFFSET_MASK);
for (ii = wStartIndex, jj =0 ; ii <= wEndIndex; ii++, jj++) {
pTIM->byVirtBitMap[jj] = pMgmt->abyPSTxMap[ii];
}
pTIM->byVirtBitMap[0] &= ~BIT0;
}
static struct vnt_tx_mgmt *s_MgrMakeBeacon(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, u16 wCurrCapInfo, u16 wCurrBeaconPeriod,
u32 uCurrChannel, u16 wCurrATIMWinodw, PWLAN_IE_SSID pCurrSSID,
u8 *pCurrBSSID, PWLAN_IE_SUPP_RATES pCurrSuppRates,
PWLAN_IE_SUPP_RATES pCurrExtSuppRates)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
WLAN_FR_BEACON sFrame;
u8 abyBroadcastAddr[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_BEACON_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_BEACON_FR_MAXLEN;
vMgrEncodeBeacon(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_BEACON)
));
if (pDevice->bEnablePSMode) {
sFrame.pHdr->sA3.wFrameCtl |= cpu_to_le16((WORD)WLAN_SET_FC_PWRMGT(1));
}
memcpy( sFrame.pHdr->sA3.abyAddr1, abyBroadcastAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pCurrBSSID, WLAN_BSSID_LEN);
*sFrame.pwBeaconInterval = cpu_to_le16(wCurrBeaconPeriod);
*sFrame.pwCapInfo = cpu_to_le16(wCurrCapInfo);
sFrame.pSSID = (PWLAN_IE_SSID)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSSID,
pCurrSSID,
((PWLAN_IE_SSID)pCurrSSID)->len + WLAN_IEHDR_LEN
);
sFrame.pSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SUPP_RATES)pCurrSuppRates)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSuppRates,
pCurrSuppRates,
((PWLAN_IE_SUPP_RATES)pCurrSuppRates)->len + WLAN_IEHDR_LEN
);
if (pDevice->byBBType != BB_TYPE_11A) {
sFrame.pDSParms = (PWLAN_IE_DS_PARMS)(sFrame.pBuf + sFrame.len);
sFrame.len += (1) + WLAN_IEHDR_LEN;
sFrame.pDSParms->byElementID = WLAN_EID_DS_PARMS;
sFrame.pDSParms->len = 1;
sFrame.pDSParms->byCurrChannel = (BYTE)uCurrChannel;
}
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
sFrame.pTIM = (PWLAN_IE_TIM)(sFrame.pBuf + sFrame.len);
sFrame.pTIM->byElementID = WLAN_EID_TIM;
s_vMgrFormatTIM(pMgmt, sFrame.pTIM);
sFrame.len += (WLAN_IEHDR_LEN + sFrame.pTIM->len);
}
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
sFrame.pIBSSParms = (PWLAN_IE_IBSS_PARMS)(sFrame.pBuf + sFrame.len);
sFrame.len += (2) + WLAN_IEHDR_LEN;
sFrame.pIBSSParms->byElementID = WLAN_EID_IBSS_PARMS;
sFrame.pIBSSParms->len = 2;
sFrame.pIBSSParms->wATIMWindow = wCurrATIMWinodw;
if (pMgmt->eAuthenMode == WMAC_AUTH_WPANONE) {
sFrame.pRSNWPA = (PWLAN_IE_RSN_EXT)(sFrame.pBuf + sFrame.len);
sFrame.pRSNWPA->byElementID = WLAN_EID_RSN_WPA;
sFrame.pRSNWPA->len = 12;
sFrame.pRSNWPA->abyOUI[0] = 0x00;
sFrame.pRSNWPA->abyOUI[1] = 0x50;
sFrame.pRSNWPA->abyOUI[2] = 0xf2;
sFrame.pRSNWPA->abyOUI[3] = 0x01;
sFrame.pRSNWPA->wVersion = 1;
sFrame.pRSNWPA->abyMulticast[0] = 0x00;
sFrame.pRSNWPA->abyMulticast[1] = 0x50;
sFrame.pRSNWPA->abyMulticast[2] = 0xf2;
if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled)
sFrame.pRSNWPA->abyMulticast[3] = 0x04;
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled)
sFrame.pRSNWPA->abyMulticast[3] = 0x02;
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption1Enabled)
sFrame.pRSNWPA->abyMulticast[3] = 0x01;
else
sFrame.pRSNWPA->abyMulticast[3] = 0x00;
sFrame.pRSNWPA->wPKCount = 0;
*((PWORD)(sFrame.pBuf + sFrame.len + sFrame.pRSNWPA->len))=0;
sFrame.pRSNWPA->len +=2;
*((PWORD)(sFrame.pBuf + sFrame.len + sFrame.pRSNWPA->len))=0;
sFrame.pRSNWPA->len +=2;
sFrame.len += sFrame.pRSNWPA->len + WLAN_IEHDR_LEN;
}
}
if (pMgmt->eCurrentPHYMode == PHY_TYPE_11G) {
sFrame.pERP = (PWLAN_IE_ERP)(sFrame.pBuf + sFrame.len);
sFrame.len += 1 + WLAN_IEHDR_LEN;
sFrame.pERP->byElementID = WLAN_EID_ERP;
sFrame.pERP->len = 1;
sFrame.pERP->byContext = 0;
if (pDevice->bProtectMode == true)
sFrame.pERP->byContext |= WLAN_EID_ERP_USE_PROTECTION;
if (pDevice->bNonERPPresent == true)
sFrame.pERP->byContext |= WLAN_EID_ERP_NONERP_PRESENT;
if (pDevice->bBarkerPreambleMd == true)
sFrame.pERP->byContext |= WLAN_EID_ERP_BARKER_MODE;
}
if (((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len != 0) {
sFrame.pExtSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pExtSuppRates,
pCurrExtSuppRates,
((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len + WLAN_IEHDR_LEN
);
}
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) && (pDevice->bEnableHostapd == true)) {
if (pMgmt->eAuthenMode == WMAC_AUTH_WPANONE) {
if (pMgmt->wWPAIELen != 0) {
sFrame.pRSN = (PWLAN_IE_RSN)(sFrame.pBuf + sFrame.len);
memcpy(sFrame.pRSN, pMgmt->abyWPAIE, pMgmt->wWPAIELen);
sFrame.len += pMgmt->wWPAIELen;
}
}
}
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
return pTxPacket;
}
struct vnt_tx_mgmt *s_MgrMakeProbeResponse(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, u16 wCurrCapInfo, u16 wCurrBeaconPeriod,
u32 uCurrChannel, u16 wCurrATIMWinodw, u8 *pDstAddr,
PWLAN_IE_SSID pCurrSSID, u8 *pCurrBSSID,
PWLAN_IE_SUPP_RATES pCurrSuppRates,
PWLAN_IE_SUPP_RATES pCurrExtSuppRates, u8 byPHYType)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
WLAN_FR_PROBERESP sFrame;
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_PROBERESP_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_PROBERESP_FR_MAXLEN;
vMgrEncodeProbeResponse(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_PROBERESP)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pDstAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pCurrBSSID, WLAN_BSSID_LEN);
*sFrame.pwBeaconInterval = cpu_to_le16(wCurrBeaconPeriod);
*sFrame.pwCapInfo = cpu_to_le16(wCurrCapInfo);
if (byPHYType == BB_TYPE_11B) {
*sFrame.pwCapInfo &= cpu_to_le16((WORD)~(WLAN_SET_CAP_INFO_SHORTSLOTTIME(1)));
}
sFrame.pSSID = (PWLAN_IE_SSID)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSSID,
pCurrSSID,
((PWLAN_IE_SSID)pCurrSSID)->len + WLAN_IEHDR_LEN
);
sFrame.pSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SUPP_RATES)pCurrSuppRates)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSuppRates,
pCurrSuppRates,
((PWLAN_IE_SUPP_RATES)pCurrSuppRates)->len + WLAN_IEHDR_LEN
);
if (pDevice->byBBType != BB_TYPE_11A) {
sFrame.pDSParms = (PWLAN_IE_DS_PARMS)(sFrame.pBuf + sFrame.len);
sFrame.len += (1) + WLAN_IEHDR_LEN;
sFrame.pDSParms->byElementID = WLAN_EID_DS_PARMS;
sFrame.pDSParms->len = 1;
sFrame.pDSParms->byCurrChannel = (BYTE)uCurrChannel;
}
if (pMgmt->eCurrMode != WMAC_MODE_ESS_AP) {
sFrame.pIBSSParms = (PWLAN_IE_IBSS_PARMS)(sFrame.pBuf + sFrame.len);
sFrame.len += (2) + WLAN_IEHDR_LEN;
sFrame.pIBSSParms->byElementID = WLAN_EID_IBSS_PARMS;
sFrame.pIBSSParms->len = 2;
sFrame.pIBSSParms->wATIMWindow = 0;
}
if (pDevice->byBBType == BB_TYPE_11G) {
sFrame.pERP = (PWLAN_IE_ERP)(sFrame.pBuf + sFrame.len);
sFrame.len += 1 + WLAN_IEHDR_LEN;
sFrame.pERP->byElementID = WLAN_EID_ERP;
sFrame.pERP->len = 1;
sFrame.pERP->byContext = 0;
if (pDevice->bProtectMode == true)
sFrame.pERP->byContext |= WLAN_EID_ERP_USE_PROTECTION;
if (pDevice->bNonERPPresent == true)
sFrame.pERP->byContext |= WLAN_EID_ERP_NONERP_PRESENT;
if (pDevice->bBarkerPreambleMd == true)
sFrame.pERP->byContext |= WLAN_EID_ERP_BARKER_MODE;
}
if (((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len != 0) {
sFrame.pExtSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pExtSuppRates,
pCurrExtSuppRates,
((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len + WLAN_IEHDR_LEN
);
}
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) && (pDevice->bEnableHostapd == true)) {
if (pMgmt->eAuthenMode == WMAC_AUTH_WPANONE) {
if (pMgmt->wWPAIELen != 0) {
sFrame.pRSN = (PWLAN_IE_RSN)(sFrame.pBuf + sFrame.len);
memcpy(sFrame.pRSN, pMgmt->abyWPAIE, pMgmt->wWPAIELen);
sFrame.len += pMgmt->wWPAIELen;
}
}
}
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
return pTxPacket;
}
struct vnt_tx_mgmt *s_MgrMakeAssocRequest(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, u8 *pDAddr, u16 wCurrCapInfo,
u16 wListenInterval,
PWLAN_IE_SSID pCurrSSID,
PWLAN_IE_SUPP_RATES pCurrRates,
PWLAN_IE_SUPP_RATES pCurrExtSuppRates)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
WLAN_FR_ASSOCREQ sFrame;
u8 *pbyIEs;
u8 *pbyRSN;
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_ASSOCREQ_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_ASSOCREQ_FR_MAXLEN;
vMgrEncodeAssocRequest(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_ASSOCREQ)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pDAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*(sFrame.pwCapInfo) = cpu_to_le16(wCurrCapInfo);
*(sFrame.pwListenInterval) = cpu_to_le16(wListenInterval);
sFrame.pSSID = (PWLAN_IE_SSID)(sFrame.pBuf + sFrame.len);
sFrame.len += pCurrSSID->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSSID, pCurrSSID, pCurrSSID->len + WLAN_IEHDR_LEN);
pMgmt->sAssocInfo.AssocInfo.RequestIELength = pCurrSSID->len + WLAN_IEHDR_LEN;
pMgmt->sAssocInfo.AssocInfo.OffsetRequestIEs = sizeof(NDIS_802_11_ASSOCIATION_INFORMATION);
pbyIEs = pMgmt->sAssocInfo.abyIEs;
memcpy(pbyIEs, pCurrSSID, pCurrSSID->len + WLAN_IEHDR_LEN);
pbyIEs += pCurrSSID->len + WLAN_IEHDR_LEN;
sFrame.pSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
if ((pDevice->byBBType == BB_TYPE_11B) && (pCurrRates->len > 4))
sFrame.len += 4 + WLAN_IEHDR_LEN;
else
sFrame.len += pCurrRates->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSuppRates, pCurrRates, pCurrRates->len + WLAN_IEHDR_LEN);
if ((pDevice->byBBType == BB_TYPE_11G) && (pCurrExtSuppRates->len > 0)) {
sFrame.pExtSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += pCurrExtSuppRates->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pExtSuppRates, pCurrExtSuppRates, pCurrExtSuppRates->len + WLAN_IEHDR_LEN);
}
pMgmt->sAssocInfo.AssocInfo.RequestIELength += pCurrRates->len + WLAN_IEHDR_LEN;
memcpy(pbyIEs, pCurrRates, pCurrRates->len + WLAN_IEHDR_LEN);
pbyIEs += pCurrRates->len + WLAN_IEHDR_LEN;
if (((pMgmt->eAuthenMode == WMAC_AUTH_WPA) ||
(pMgmt->eAuthenMode == WMAC_AUTH_WPAPSK) ||
(pMgmt->eAuthenMode == WMAC_AUTH_WPANONE)) &&
(pMgmt->pCurrBSS != NULL)) {
sFrame.pRSNWPA = (PWLAN_IE_RSN_EXT)(sFrame.pBuf + sFrame.len);
sFrame.pRSNWPA->byElementID = WLAN_EID_RSN_WPA;
sFrame.pRSNWPA->len = 16;
sFrame.pRSNWPA->abyOUI[0] = 0x00;
sFrame.pRSNWPA->abyOUI[1] = 0x50;
sFrame.pRSNWPA->abyOUI[2] = 0xf2;
sFrame.pRSNWPA->abyOUI[3] = 0x01;
sFrame.pRSNWPA->wVersion = 1;
sFrame.pRSNWPA->abyMulticast[0] = 0x00;
sFrame.pRSNWPA->abyMulticast[1] = 0x50;
sFrame.pRSNWPA->abyMulticast[2] = 0xf2;
if (pMgmt->byCSSGK == KEY_CTL_WEP) {
sFrame.pRSNWPA->abyMulticast[3] = pMgmt->pCurrBSS->byGKType;
} else if (pMgmt->byCSSGK == KEY_CTL_TKIP) {
sFrame.pRSNWPA->abyMulticast[3] = WPA_TKIP;
} else if (pMgmt->byCSSGK == KEY_CTL_CCMP) {
sFrame.pRSNWPA->abyMulticast[3] = WPA_AESCCMP;
} else {
sFrame.pRSNWPA->abyMulticast[3] = WPA_NONE;
}
sFrame.pRSNWPA->wPKCount = 1;
sFrame.pRSNWPA->PKSList[0].abyOUI[0] = 0x00;
sFrame.pRSNWPA->PKSList[0].abyOUI[1] = 0x50;
sFrame.pRSNWPA->PKSList[0].abyOUI[2] = 0xf2;
if (pMgmt->byCSSPK == KEY_CTL_TKIP) {
sFrame.pRSNWPA->PKSList[0].abyOUI[3] = WPA_TKIP;
} else if (pMgmt->byCSSPK == KEY_CTL_CCMP) {
sFrame.pRSNWPA->PKSList[0].abyOUI[3] = WPA_AESCCMP;
} else {
sFrame.pRSNWPA->PKSList[0].abyOUI[3] = WPA_NONE;
}
pbyRSN = (PBYTE)(sFrame.pBuf + sFrame.len + 2 + sFrame.pRSNWPA->len);
*pbyRSN++=0x01;
*pbyRSN++=0x00;
*pbyRSN++=0x00;
*pbyRSN++=0x50;
*pbyRSN++=0xf2;
if (pMgmt->eAuthenMode == WMAC_AUTH_WPAPSK) {
*pbyRSN++=WPA_AUTH_PSK;
}
else if (pMgmt->eAuthenMode == WMAC_AUTH_WPA) {
*pbyRSN++=WPA_AUTH_IEEE802_1X;
}
else {
*pbyRSN++=WPA_NONE;
}
sFrame.pRSNWPA->len +=6;
*pbyRSN++=0x00;
*pbyRSN++=0x00;
sFrame.pRSNWPA->len +=2;
sFrame.len += sFrame.pRSNWPA->len + WLAN_IEHDR_LEN;
pMgmt->sAssocInfo.AssocInfo.RequestIELength += sFrame.pRSNWPA->len + WLAN_IEHDR_LEN;
memcpy(pbyIEs, sFrame.pRSNWPA, sFrame.pRSNWPA->len + WLAN_IEHDR_LEN);
pbyIEs += sFrame.pRSNWPA->len + WLAN_IEHDR_LEN;
} else if (((pMgmt->eAuthenMode == WMAC_AUTH_WPA2) ||
(pMgmt->eAuthenMode == WMAC_AUTH_WPA2PSK)) &&
(pMgmt->pCurrBSS != NULL)) {
unsigned int ii;
PWORD pwPMKID;
sFrame.pRSN = (PWLAN_IE_RSN)(sFrame.pBuf + sFrame.len);
sFrame.pRSN->byElementID = WLAN_EID_RSN;
sFrame.pRSN->len = 6;
sFrame.pRSN->wVersion = 1;
sFrame.pRSN->abyRSN[0] = 0x00;
sFrame.pRSN->abyRSN[1] = 0x0F;
sFrame.pRSN->abyRSN[2] = 0xAC;
if (pMgmt->byCSSGK == KEY_CTL_WEP) {
sFrame.pRSN->abyRSN[3] = pMgmt->pCurrBSS->byCSSGK;
} else if (pMgmt->byCSSGK == KEY_CTL_TKIP) {
sFrame.pRSN->abyRSN[3] = WLAN_11i_CSS_TKIP;
} else if (pMgmt->byCSSGK == KEY_CTL_CCMP) {
sFrame.pRSN->abyRSN[3] = WLAN_11i_CSS_CCMP;
} else {
sFrame.pRSN->abyRSN[3] = WLAN_11i_CSS_UNKNOWN;
}
sFrame.pRSN->abyRSN[4] = 1;
sFrame.pRSN->abyRSN[5] = 0;
sFrame.pRSN->abyRSN[6] = 0x00;
sFrame.pRSN->abyRSN[7] = 0x0F;
sFrame.pRSN->abyRSN[8] = 0xAC;
if (pMgmt->byCSSPK == KEY_CTL_TKIP) {
sFrame.pRSN->abyRSN[9] = WLAN_11i_CSS_TKIP;
} else if (pMgmt->byCSSPK == KEY_CTL_CCMP) {
sFrame.pRSN->abyRSN[9] = WLAN_11i_CSS_CCMP;
} else if (pMgmt->byCSSPK == KEY_CTL_NONE) {
sFrame.pRSN->abyRSN[9] = WLAN_11i_CSS_USE_GROUP;
} else {
sFrame.pRSN->abyRSN[9] = WLAN_11i_CSS_UNKNOWN;
}
sFrame.pRSN->len += 6;
sFrame.pRSN->abyRSN[10] = 1;
sFrame.pRSN->abyRSN[11] = 0;
sFrame.pRSN->abyRSN[12] = 0x00;
sFrame.pRSN->abyRSN[13] = 0x0F;
sFrame.pRSN->abyRSN[14] = 0xAC;
if (pMgmt->eAuthenMode == WMAC_AUTH_WPA2PSK) {
sFrame.pRSN->abyRSN[15] = WLAN_11i_AKMSS_PSK;
} else if (pMgmt->eAuthenMode == WMAC_AUTH_WPA2) {
sFrame.pRSN->abyRSN[15] = WLAN_11i_AKMSS_802_1X;
} else {
sFrame.pRSN->abyRSN[15] = WLAN_11i_AKMSS_UNKNOWN;
}
sFrame.pRSN->len +=6;
if (pMgmt->pCurrBSS->sRSNCapObj.bRSNCapExist == true) {
memcpy(&sFrame.pRSN->abyRSN[16], &pMgmt->pCurrBSS->sRSNCapObj.wRSNCap, 2);
} else {
sFrame.pRSN->abyRSN[16] = 0;
sFrame.pRSN->abyRSN[17] = 0;
}
sFrame.pRSN->len +=2;
if ((pDevice->gsPMKID.BSSIDInfoCount > 0) && (pDevice->bRoaming == true) && (pMgmt->eAuthenMode == WMAC_AUTH_WPA2)) {
pbyRSN = &sFrame.pRSN->abyRSN[18];
pwPMKID = (PWORD)pbyRSN;
*pwPMKID = 0;
pbyRSN += 2;
for (ii = 0; ii < pDevice->gsPMKID.BSSIDInfoCount; ii++) {
if (!memcmp(&pDevice->gsPMKID.BSSIDInfo[ii].BSSID[0],
pMgmt->abyCurrBSSID,
ETH_ALEN)) {
(*pwPMKID)++;
memcpy(pbyRSN,
pDevice->gsPMKID.BSSIDInfo[ii].PMKID,
16);
pbyRSN += 16;
}
}
if (*pwPMKID != 0) {
sFrame.pRSN->len += (2 + (*pwPMKID)*16);
}
}
sFrame.len += sFrame.pRSN->len + WLAN_IEHDR_LEN;
pMgmt->sAssocInfo.AssocInfo.RequestIELength += sFrame.pRSN->len + WLAN_IEHDR_LEN;
memcpy(pbyIEs, sFrame.pRSN, sFrame.pRSN->len + WLAN_IEHDR_LEN);
pbyIEs += sFrame.pRSN->len + WLAN_IEHDR_LEN;
}
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
return pTxPacket;
}
struct vnt_tx_mgmt *s_MgrMakeReAssocRequest(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, u8 *pDAddr, u16 wCurrCapInfo,
u16 wListenInterval, PWLAN_IE_SSID pCurrSSID,
PWLAN_IE_SUPP_RATES pCurrRates,
PWLAN_IE_SUPP_RATES pCurrExtSuppRates)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
WLAN_FR_REASSOCREQ sFrame;
u8 *pbyIEs;
u8 *pbyRSN;
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_REASSOCREQ_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_REASSOCREQ_FR_MAXLEN;
vMgrEncodeReassocRequest(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_REASSOCREQ)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pDAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*(sFrame.pwCapInfo) = cpu_to_le16(wCurrCapInfo);
*(sFrame.pwListenInterval) = cpu_to_le16(wListenInterval);
memcpy(sFrame.pAddrCurrAP, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
sFrame.pSSID = (PWLAN_IE_SSID)(sFrame.pBuf + sFrame.len);
sFrame.len += pCurrSSID->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSSID, pCurrSSID, pCurrSSID->len + WLAN_IEHDR_LEN);
pMgmt->sAssocInfo.AssocInfo.RequestIELength = pCurrSSID->len + WLAN_IEHDR_LEN;
pMgmt->sAssocInfo.AssocInfo.OffsetRequestIEs = sizeof(NDIS_802_11_ASSOCIATION_INFORMATION);
pbyIEs = pMgmt->sAssocInfo.abyIEs;
memcpy(pbyIEs, pCurrSSID, pCurrSSID->len + WLAN_IEHDR_LEN);
pbyIEs += pCurrSSID->len + WLAN_IEHDR_LEN;
sFrame.pSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += pCurrRates->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSuppRates, pCurrRates, pCurrRates->len + WLAN_IEHDR_LEN);
if ((pMgmt->eCurrentPHYMode == PHY_TYPE_11G) && (pCurrExtSuppRates->len > 0)) {
sFrame.pExtSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += pCurrExtSuppRates->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pExtSuppRates, pCurrExtSuppRates, pCurrExtSuppRates->len + WLAN_IEHDR_LEN);
}
pMgmt->sAssocInfo.AssocInfo.RequestIELength += pCurrRates->len + WLAN_IEHDR_LEN;
memcpy(pbyIEs, pCurrRates, pCurrRates->len + WLAN_IEHDR_LEN);
pbyIEs += pCurrRates->len + WLAN_IEHDR_LEN;
if (((pMgmt->eAuthenMode == WMAC_AUTH_WPA) ||
(pMgmt->eAuthenMode == WMAC_AUTH_WPAPSK) ||
(pMgmt->eAuthenMode == WMAC_AUTH_WPANONE)) &&
(pMgmt->pCurrBSS != NULL)) {
sFrame.pRSNWPA = (PWLAN_IE_RSN_EXT)(sFrame.pBuf + sFrame.len);
sFrame.pRSNWPA->byElementID = WLAN_EID_RSN_WPA;
sFrame.pRSNWPA->len = 16;
sFrame.pRSNWPA->abyOUI[0] = 0x00;
sFrame.pRSNWPA->abyOUI[1] = 0x50;
sFrame.pRSNWPA->abyOUI[2] = 0xf2;
sFrame.pRSNWPA->abyOUI[3] = 0x01;
sFrame.pRSNWPA->wVersion = 1;
sFrame.pRSNWPA->abyMulticast[0] = 0x00;
sFrame.pRSNWPA->abyMulticast[1] = 0x50;
sFrame.pRSNWPA->abyMulticast[2] = 0xf2;
if (pMgmt->byCSSGK == KEY_CTL_WEP) {
sFrame.pRSNWPA->abyMulticast[3] = pMgmt->pCurrBSS->byGKType;
} else if (pMgmt->byCSSGK == KEY_CTL_TKIP) {
sFrame.pRSNWPA->abyMulticast[3] = WPA_TKIP;
} else if (pMgmt->byCSSGK == KEY_CTL_CCMP) {
sFrame.pRSNWPA->abyMulticast[3] = WPA_AESCCMP;
} else {
sFrame.pRSNWPA->abyMulticast[3] = WPA_NONE;
}
sFrame.pRSNWPA->wPKCount = 1;
sFrame.pRSNWPA->PKSList[0].abyOUI[0] = 0x00;
sFrame.pRSNWPA->PKSList[0].abyOUI[1] = 0x50;
sFrame.pRSNWPA->PKSList[0].abyOUI[2] = 0xf2;
if (pMgmt->byCSSPK == KEY_CTL_TKIP) {
sFrame.pRSNWPA->PKSList[0].abyOUI[3] = WPA_TKIP;
} else if (pMgmt->byCSSPK == KEY_CTL_CCMP) {
sFrame.pRSNWPA->PKSList[0].abyOUI[3] = WPA_AESCCMP;
} else {
sFrame.pRSNWPA->PKSList[0].abyOUI[3] = WPA_NONE;
}
pbyRSN = (PBYTE)(sFrame.pBuf + sFrame.len + 2 + sFrame.pRSNWPA->len);
*pbyRSN++=0x01;
*pbyRSN++=0x00;
*pbyRSN++=0x00;
*pbyRSN++=0x50;
*pbyRSN++=0xf2;
if (pMgmt->eAuthenMode == WMAC_AUTH_WPAPSK) {
*pbyRSN++=WPA_AUTH_PSK;
} else if (pMgmt->eAuthenMode == WMAC_AUTH_WPA) {
*pbyRSN++=WPA_AUTH_IEEE802_1X;
} else {
*pbyRSN++=WPA_NONE;
}
sFrame.pRSNWPA->len +=6;
*pbyRSN++=0x00;
*pbyRSN++=0x00;
sFrame.pRSNWPA->len +=2;
sFrame.len += sFrame.pRSNWPA->len + WLAN_IEHDR_LEN;
pMgmt->sAssocInfo.AssocInfo.RequestIELength += sFrame.pRSNWPA->len + WLAN_IEHDR_LEN;
memcpy(pbyIEs, sFrame.pRSNWPA, sFrame.pRSNWPA->len + WLAN_IEHDR_LEN);
pbyIEs += sFrame.pRSNWPA->len + WLAN_IEHDR_LEN;
} else if (((pMgmt->eAuthenMode == WMAC_AUTH_WPA2) ||
(pMgmt->eAuthenMode == WMAC_AUTH_WPA2PSK)) &&
(pMgmt->pCurrBSS != NULL)) {
unsigned int ii;
PWORD pwPMKID;
sFrame.pRSN = (PWLAN_IE_RSN)(sFrame.pBuf + sFrame.len);
sFrame.pRSN->byElementID = WLAN_EID_RSN;
sFrame.pRSN->len = 6;
sFrame.pRSN->wVersion = 1;
sFrame.pRSN->abyRSN[0] = 0x00;
sFrame.pRSN->abyRSN[1] = 0x0F;
sFrame.pRSN->abyRSN[2] = 0xAC;
if (pMgmt->byCSSGK == KEY_CTL_WEP) {
sFrame.pRSN->abyRSN[3] = pMgmt->pCurrBSS->byCSSGK;
} else if (pMgmt->byCSSGK == KEY_CTL_TKIP) {
sFrame.pRSN->abyRSN[3] = WLAN_11i_CSS_TKIP;
} else if (pMgmt->byCSSGK == KEY_CTL_CCMP) {
sFrame.pRSN->abyRSN[3] = WLAN_11i_CSS_CCMP;
} else {
sFrame.pRSN->abyRSN[3] = WLAN_11i_CSS_UNKNOWN;
}
sFrame.pRSN->abyRSN[4] = 1;
sFrame.pRSN->abyRSN[5] = 0;
sFrame.pRSN->abyRSN[6] = 0x00;
sFrame.pRSN->abyRSN[7] = 0x0F;
sFrame.pRSN->abyRSN[8] = 0xAC;
if (pMgmt->byCSSPK == KEY_CTL_TKIP) {
sFrame.pRSN->abyRSN[9] = WLAN_11i_CSS_TKIP;
} else if (pMgmt->byCSSPK == KEY_CTL_CCMP) {
sFrame.pRSN->abyRSN[9] = WLAN_11i_CSS_CCMP;
} else if (pMgmt->byCSSPK == KEY_CTL_NONE) {
sFrame.pRSN->abyRSN[9] = WLAN_11i_CSS_USE_GROUP;
} else {
sFrame.pRSN->abyRSN[9] = WLAN_11i_CSS_UNKNOWN;
}
sFrame.pRSN->len += 6;
sFrame.pRSN->abyRSN[10] = 1;
sFrame.pRSN->abyRSN[11] = 0;
sFrame.pRSN->abyRSN[12] = 0x00;
sFrame.pRSN->abyRSN[13] = 0x0F;
sFrame.pRSN->abyRSN[14] = 0xAC;
if (pMgmt->eAuthenMode == WMAC_AUTH_WPA2PSK) {
sFrame.pRSN->abyRSN[15] = WLAN_11i_AKMSS_PSK;
} else if (pMgmt->eAuthenMode == WMAC_AUTH_WPA2) {
sFrame.pRSN->abyRSN[15] = WLAN_11i_AKMSS_802_1X;
} else {
sFrame.pRSN->abyRSN[15] = WLAN_11i_AKMSS_UNKNOWN;
}
sFrame.pRSN->len +=6;
if (pMgmt->pCurrBSS->sRSNCapObj.bRSNCapExist == true) {
memcpy(&sFrame.pRSN->abyRSN[16], &pMgmt->pCurrBSS->sRSNCapObj.wRSNCap, 2);
} else {
sFrame.pRSN->abyRSN[16] = 0;
sFrame.pRSN->abyRSN[17] = 0;
}
sFrame.pRSN->len +=2;
if ((pDevice->gsPMKID.BSSIDInfoCount > 0) && (pDevice->bRoaming == true) && (pMgmt->eAuthenMode == WMAC_AUTH_WPA2)) {
pbyRSN = &sFrame.pRSN->abyRSN[18];
pwPMKID = (PWORD)pbyRSN;
*pwPMKID = 0;
pbyRSN += 2;
for (ii = 0; ii < pDevice->gsPMKID.BSSIDInfoCount; ii++) {
if (!memcmp(&pDevice->gsPMKID.BSSIDInfo[ii].BSSID[0],
pMgmt->abyCurrBSSID,
ETH_ALEN)) {
(*pwPMKID)++;
memcpy(pbyRSN,
pDevice->gsPMKID.BSSIDInfo[ii].PMKID,
16);
pbyRSN += 16;
}
}
if (*pwPMKID != 0) {
sFrame.pRSN->len += (2 + (*pwPMKID)*16);
}
}
sFrame.len += sFrame.pRSN->len + WLAN_IEHDR_LEN;
pMgmt->sAssocInfo.AssocInfo.RequestIELength += sFrame.pRSN->len + WLAN_IEHDR_LEN;
memcpy(pbyIEs, sFrame.pRSN, sFrame.pRSN->len + WLAN_IEHDR_LEN);
pbyIEs += sFrame.pRSN->len + WLAN_IEHDR_LEN;
}
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
return pTxPacket;
}
struct vnt_tx_mgmt *s_MgrMakeAssocResponse(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, u16 wCurrCapInfo, u16 wAssocStatus,
u16 wAssocAID, u8 *pDstAddr, PWLAN_IE_SUPP_RATES pCurrSuppRates,
PWLAN_IE_SUPP_RATES pCurrExtSuppRates)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
WLAN_FR_ASSOCRESP sFrame;
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_ASSOCREQ_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_REASSOCRESP_FR_MAXLEN;
vMgrEncodeAssocResponse(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_ASSOCRESP)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pDstAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*sFrame.pwCapInfo = cpu_to_le16(wCurrCapInfo);
*sFrame.pwStatus = cpu_to_le16(wAssocStatus);
*sFrame.pwAid = cpu_to_le16((WORD)(wAssocAID | BIT14 | BIT15));
sFrame.pSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SUPP_RATES)pCurrSuppRates)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSuppRates,
pCurrSuppRates,
((PWLAN_IE_SUPP_RATES)pCurrSuppRates)->len + WLAN_IEHDR_LEN
);
if (((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len != 0) {
sFrame.pExtSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pExtSuppRates,
pCurrExtSuppRates,
((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len + WLAN_IEHDR_LEN
);
}
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
return pTxPacket;
}
struct vnt_tx_mgmt *s_MgrMakeReAssocResponse(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, u16 wCurrCapInfo, u16 wAssocStatus,
u16 wAssocAID, u8 *pDstAddr, PWLAN_IE_SUPP_RATES pCurrSuppRates,
PWLAN_IE_SUPP_RATES pCurrExtSuppRates)
{
struct vnt_tx_mgmt *pTxPacket = NULL;
WLAN_FR_REASSOCRESP sFrame;
pTxPacket = (struct vnt_tx_mgmt *)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(struct vnt_tx_mgmt)
+ WLAN_ASSOCREQ_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((u8 *)pTxPacket
+ sizeof(struct vnt_tx_mgmt));
sFrame.pBuf = (PBYTE)pTxPacket->p80211Header;
sFrame.len = WLAN_REASSOCRESP_FR_MAXLEN;
vMgrEncodeReassocResponse(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_REASSOCRESP)
));
memcpy( sFrame.pHdr->sA3.abyAddr1, pDstAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy( sFrame.pHdr->sA3.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
*sFrame.pwCapInfo = cpu_to_le16(wCurrCapInfo);
*sFrame.pwStatus = cpu_to_le16(wAssocStatus);
*sFrame.pwAid = cpu_to_le16((WORD)(wAssocAID | BIT14 | BIT15));
sFrame.pSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SUPP_RATES)pCurrSuppRates)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSuppRates,
pCurrSuppRates,
((PWLAN_IE_SUPP_RATES)pCurrSuppRates)->len + WLAN_IEHDR_LEN
);
if (((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len != 0) {
sFrame.pExtSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += ((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pExtSuppRates,
pCurrExtSuppRates,
((PWLAN_IE_SUPP_RATES)pCurrExtSuppRates)->len + WLAN_IEHDR_LEN
);
}
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
return pTxPacket;
}
static void s_vMgrRxProbeResponse(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket)
{
PKnownBSS pBSSList = NULL;
WLAN_FR_PROBERESP sFrame;
u8 byCurrChannel = pRxPacket->byRxChannel;
ERPObject sERP;
int bChannelHit = true;
memset(&sFrame, 0, sizeof(WLAN_FR_PROBERESP));
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeProbeResponse(&sFrame);
if ((sFrame.pqwTimestamp == NULL)
|| (sFrame.pwBeaconInterval == NULL)
|| (sFrame.pwCapInfo == NULL)
|| (sFrame.pSSID == NULL)
|| (sFrame.pSuppRates == NULL)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Probe resp:Fail addr:[%p]\n",
pRxPacket->p80211Header);
DBG_PORT80(0xCC);
return;
}
if(sFrame.pSSID->len == 0)
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Rx Probe resp: SSID len = 0 \n");
if( byCurrChannel > CB_MAX_CHANNEL_24G )
{
if (sFrame.pDSParms) {
if (byCurrChannel ==
RFaby11aChannelIndex[sFrame.pDSParms->byCurrChannel-1])
bChannelHit = true;
byCurrChannel =
RFaby11aChannelIndex[sFrame.pDSParms->byCurrChannel-1];
} else {
bChannelHit = true;
}
} else {
if (sFrame.pDSParms) {
if (byCurrChannel == sFrame.pDSParms->byCurrChannel)
bChannelHit = true;
byCurrChannel = sFrame.pDSParms->byCurrChannel;
} else {
bChannelHit = true;
}
}
if(ChannelExceedZoneType(pDevice,byCurrChannel)==true)
return;
if (sFrame.pERP) {
sERP.byERP = sFrame.pERP->byContext;
sERP.bERPExist = true;
} else {
sERP.bERPExist = false;
sERP.byERP = 0;
}
pBSSList = BSSpAddrIsInBSSList((void *) pDevice,
sFrame.pHdr->sA3.abyAddr3,
sFrame.pSSID);
if (pBSSList) {
BSSbUpdateToBSSList((void *) pDevice,
*sFrame.pqwTimestamp,
*sFrame.pwBeaconInterval,
*sFrame.pwCapInfo,
byCurrChannel,
bChannelHit,
sFrame.pSSID,
sFrame.pSuppRates,
sFrame.pExtSuppRates,
&sERP,
sFrame.pRSN,
sFrame.pRSNWPA,
sFrame.pIE_Country,
sFrame.pIE_Quiet,
pBSSList,
sFrame.len - WLAN_HDR_ADDR3_LEN,
sFrame.pHdr->sA4.abyAddr4,
(void *) pRxPacket);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Probe resp/insert: RxChannel = : %d\n", byCurrChannel);
BSSbInsertToBSSList((void *) pDevice,
sFrame.pHdr->sA3.abyAddr3,
*sFrame.pqwTimestamp,
*sFrame.pwBeaconInterval,
*sFrame.pwCapInfo,
byCurrChannel,
sFrame.pSSID,
sFrame.pSuppRates,
sFrame.pExtSuppRates,
&sERP,
sFrame.pRSN,
sFrame.pRSNWPA,
sFrame.pIE_Country,
sFrame.pIE_Quiet,
sFrame.len - WLAN_HDR_ADDR3_LEN,
sFrame.pHdr->sA4.abyAddr4,
(void *) pRxPacket);
}
return;
}
static void s_vMgrRxProbeRequest(struct vnt_private *pDevice,
struct vnt_manager *pMgmt, struct vnt_rx_mgmt *pRxPacket)
{
WLAN_FR_PROBEREQ sFrame;
CMD_STATUS Status;
struct vnt_tx_mgmt *pTxPacket;
u8 byPHYType = BB_TYPE_11B;
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) ||
((pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) && pDevice->bBeaconSent)) {
memset(&sFrame, 0, sizeof(WLAN_FR_PROBEREQ));
sFrame.len = pRxPacket->cbMPDULen;
sFrame.pBuf = (PBYTE)pRxPacket->p80211Header;
vMgrDecodeProbeRequest(&sFrame);
if (sFrame.pSSID->len != 0) {
if (sFrame.pSSID->len != ((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->len)
return;
if (memcmp(sFrame.pSSID->abySSID,
((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->abySSID,
((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->len) != 0) {
return;
}
}
if ((sFrame.pSuppRates->len > 4) || (sFrame.pExtSuppRates != NULL)) {
byPHYType = BB_TYPE_11G;
}
pTxPacket = s_MgrMakeProbeResponse
(
pDevice,
pMgmt,
pMgmt->wCurrCapInfo,
pMgmt->wCurrBeaconPeriod,
pMgmt->uCurrChannel,
0,
sFrame.pHdr->sA3.abyAddr2,
(PWLAN_IE_SSID)pMgmt->abyCurrSSID,
(PBYTE)pMgmt->abyCurrBSSID,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates,
byPHYType
);
if (pTxPacket != NULL ){
Status = csMgmt_xmit(pDevice, pTxPacket);
if (Status != CMD_STATUS_PENDING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Mgt:Probe response tx failed\n");
}
else {
}
}
}
return;
}
void vMgrRxManagePacket(struct vnt_private *pDevice, struct vnt_manager *pMgmt,
struct vnt_rx_mgmt *pRxPacket)
{
int bInScan = false;
u32 uNodeIndex = 0;
NODE_STATE eNodeState = 0;
CMD_STATUS Status;
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
if (BSSbIsSTAInNodeDB(pDevice, pRxPacket->p80211Header->sA3.abyAddr2, &uNodeIndex))
eNodeState = pMgmt->sNodeDBTable[uNodeIndex].eNodeState;
}
switch( WLAN_GET_FC_FSTYPE((pRxPacket->p80211Header->sA3.wFrameCtl)) ){
case WLAN_FSTYPE_ASSOCREQ:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx assocreq\n");
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) &&
(eNodeState < NODE_AUTH)) {
vMgrDeAuthenBeginSta(pDevice,
pMgmt,
pRxPacket->p80211Header->sA3.abyAddr2,
(6),
&Status
);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "wmgr: send vMgrDeAuthenBeginSta 1\n");
}
else {
s_vMgrRxAssocRequest(pDevice, pMgmt, pRxPacket, uNodeIndex);
}
break;
case WLAN_FSTYPE_ASSOCRESP:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx assocresp1\n");
s_vMgrRxAssocResponse(pDevice, pMgmt, pRxPacket, false);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx assocresp2\n");
break;
case WLAN_FSTYPE_REASSOCREQ:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx reassocreq\n");
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) &&
(eNodeState < NODE_AUTH)) {
vMgrDeAuthenBeginSta(pDevice,
pMgmt,
pRxPacket->p80211Header->sA3.abyAddr2,
(6),
&Status
);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "wmgr: send vMgrDeAuthenBeginSta 2\n");
}
s_vMgrRxReAssocRequest(pDevice, pMgmt, pRxPacket, uNodeIndex);
break;
case WLAN_FSTYPE_REASSOCRESP:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx reassocresp\n");
s_vMgrRxAssocResponse(pDevice, pMgmt, pRxPacket, true);
break;
case WLAN_FSTYPE_PROBEREQ:
s_vMgrRxProbeRequest(pDevice, pMgmt, pRxPacket);
break;
case WLAN_FSTYPE_PROBERESP:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx proberesp\n");
s_vMgrRxProbeResponse(pDevice, pMgmt, pRxPacket);
break;
case WLAN_FSTYPE_BEACON:
if (pMgmt->eScanState != WMAC_NO_SCANNING) {
bInScan = true;
}
s_vMgrRxBeacon(pDevice, pMgmt, pRxPacket, bInScan);
break;
case WLAN_FSTYPE_ATIM:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx atim\n");
break;
case WLAN_FSTYPE_DISASSOC:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx disassoc\n");
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_AP) &&
(eNodeState < NODE_AUTH)) {
vMgrDeAuthenBeginSta(pDevice,
pMgmt,
pRxPacket->p80211Header->sA3.abyAddr2,
(6),
&Status
);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "wmgr: send vMgrDeAuthenBeginSta 3\n");
}
s_vMgrRxDisassociation(pDevice, pMgmt, pRxPacket);
break;
case WLAN_FSTYPE_AUTHEN:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx authen\n");
s_vMgrRxAuthentication(pDevice, pMgmt, pRxPacket);
break;
case WLAN_FSTYPE_DEAUTHEN:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx deauthen\n");
s_vMgrRxDeauthentication(pDevice, pMgmt, pRxPacket);
break;
default:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "rx unknown mgmt\n");
}
return;
}
int bMgrPrepareBeaconToSend(struct vnt_private *pDevice,
struct vnt_manager *pMgmt)
{
struct vnt_tx_mgmt *pTxPacket;
if (pDevice->bEncryptionEnable || pDevice->bEnable8021x){
pMgmt->wCurrCapInfo |= WLAN_SET_CAP_INFO_PRIVACY(1);
}
else {
pMgmt->wCurrCapInfo &= ~WLAN_SET_CAP_INFO_PRIVACY(1);
}
pTxPacket = s_MgrMakeBeacon
(
pDevice,
pMgmt,
pMgmt->wCurrCapInfo,
pMgmt->wCurrBeaconPeriod,
pMgmt->uCurrChannel,
pMgmt->wCurrATIMWindow,
(PWLAN_IE_SSID)pMgmt->abyCurrSSID,
(PBYTE)pMgmt->abyCurrBSSID,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrSuppRates,
(PWLAN_IE_SUPP_RATES)pMgmt->abyCurrExtSuppRates
);
if ((pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) &&
(pMgmt->abyCurrBSSID[0] == 0))
return false;
csBeacon_xmit(pDevice, pTxPacket);
MACvRegBitsOn(pDevice, MAC_REG_TCR, TCR_AUTOBCNTX);
return true;
}
static void s_vMgrLogStatus(struct vnt_manager *pMgmt, u16 wStatus)
{
switch( wStatus ){
case WLAN_MGMT_STATUS_UNSPEC_FAILURE:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Unspecified error.\n");
break;
case WLAN_MGMT_STATUS_CAPS_UNSUPPORTED:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Can't support all requested capabilities.\n");
break;
case WLAN_MGMT_STATUS_REASSOC_NO_ASSOC:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Reassoc denied, can't confirm original Association.\n");
break;
case WLAN_MGMT_STATUS_ASSOC_DENIED_UNSPEC:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Assoc denied, undefine in spec\n");
break;
case WLAN_MGMT_STATUS_UNSUPPORTED_AUTHALG:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Peer doesn't support authen algorithm.\n");
break;
case WLAN_MGMT_STATUS_RX_AUTH_NOSEQ:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Authen frame received out of sequence.\n");
break;
case WLAN_MGMT_STATUS_CHALLENGE_FAIL:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Authen rejected, challenge failure.\n");
break;
case WLAN_MGMT_STATUS_AUTH_TIMEOUT:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Authen rejected, timeout waiting for next frame.\n");
break;
case WLAN_MGMT_STATUS_ASSOC_DENIED_BUSY:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Assoc denied, AP too busy.\n");
break;
case WLAN_MGMT_STATUS_ASSOC_DENIED_RATES:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Assoc denied, we haven't enough basic rates.\n");
break;
case WLAN_MGMT_STATUS_ASSOC_DENIED_SHORTPREAMBLE:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Assoc denied, we do not support short preamble.\n");
break;
case WLAN_MGMT_STATUS_ASSOC_DENIED_PBCC:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Assoc denied, we do not support PBCC.\n");
break;
case WLAN_MGMT_STATUS_ASSOC_DENIED_AGILITY:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Status code == Assoc denied, we do not support channel agility.\n");
break;
default:
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO "Unknown status code %d.\n", wStatus);
break;
}
}
int bAdd_PMKID_Candidate(struct vnt_private *pDevice, u8 *pbyBSSID,
PSRSNCapObject psRSNCapObj)
{
PPMKID_CANDIDATE pCandidateList;
int ii = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"bAdd_PMKID_Candidate START: (%d)\n", (int)pDevice->gsPMKIDCandidate.NumCandidates);
if ((pDevice == NULL) || (pbyBSSID == NULL) || (psRSNCapObj == NULL))
return false;
if (pDevice->gsPMKIDCandidate.NumCandidates >= MAX_PMKIDLIST)
return false;
for (ii = 0; ii < pDevice->gsPMKIDCandidate.NumCandidates; ii++) {
pCandidateList = &pDevice->gsPMKIDCandidate.CandidateList[ii];
if (!memcmp(pCandidateList->BSSID, pbyBSSID, ETH_ALEN)) {
if ((psRSNCapObj->bRSNCapExist == true)
&& (psRSNCapObj->wRSNCap & BIT0)) {
pCandidateList->Flags |=
NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED;
} else {
pCandidateList->Flags &=
~(NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED);
}
return true;
}
}
pCandidateList = &pDevice->gsPMKIDCandidate.CandidateList[pDevice->gsPMKIDCandidate.NumCandidates];
if ((psRSNCapObj->bRSNCapExist == true) && (psRSNCapObj->wRSNCap & BIT0)) {
pCandidateList->Flags |= NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED;
} else {
pCandidateList->Flags &= ~(NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED);
}
memcpy(pCandidateList->BSSID, pbyBSSID, ETH_ALEN);
pDevice->gsPMKIDCandidate.NumCandidates++;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"NumCandidates:%d\n", (int)pDevice->gsPMKIDCandidate.NumCandidates);
return true;
}
void vFlush_PMKID_Candidate(struct vnt_private *pDevice)
{
if (pDevice == NULL)
return;
memset(&pDevice->gsPMKIDCandidate, 0, sizeof(SPMKIDCandidateEvent));
return;
}
static bool
s_bCipherMatch (
PKnownBSS pBSSNode,
NDIS_802_11_ENCRYPTION_STATUS EncStatus,
PBYTE pbyCCSPK,
PBYTE pbyCCSGK
)
{
BYTE byMulticastCipher = KEY_CTL_INVALID;
BYTE byCipherMask = 0x00;
int i;
if (pBSSNode == NULL)
return false;
if ((WLAN_GET_CAP_INFO_PRIVACY(pBSSNode->wCapInfo) != 0) &&
(EncStatus == Ndis802_11Encryption1Enabled)) {
byMulticastCipher = KEY_CTL_WEP;
}
if ((WLAN_GET_CAP_INFO_PRIVACY(pBSSNode->wCapInfo) != 0) &&
(pBSSNode->bWPA2Valid == true) &&
((EncStatus == Ndis802_11Encryption3Enabled) ||
(EncStatus == Ndis802_11Encryption2Enabled))) {
if ((pBSSNode->byCSSGK == WLAN_11i_CSS_WEP40) ||
(pBSSNode->byCSSGK == WLAN_11i_CSS_WEP104)) {
byMulticastCipher = KEY_CTL_WEP;
} else if (pBSSNode->byCSSGK == WLAN_11i_CSS_TKIP) {
byMulticastCipher = KEY_CTL_TKIP;
} else if (pBSSNode->byCSSGK == WLAN_11i_CSS_CCMP) {
byMulticastCipher = KEY_CTL_CCMP;
} else {
byMulticastCipher = KEY_CTL_INVALID;
}
for (i = 0; i < pBSSNode->wCSSPKCount; i++) {
if ((pBSSNode->abyCSSPK[i] == WLAN_11i_CSS_WEP40) ||
(pBSSNode->abyCSSPK[i] == WLAN_11i_CSS_WEP104)) {
byCipherMask |= 0x01;
} else if (pBSSNode->abyCSSPK[i] == WLAN_11i_CSS_TKIP) {
byCipherMask |= 0x02;
} else if (pBSSNode->abyCSSPK[i] == WLAN_11i_CSS_CCMP) {
byCipherMask |= 0x04;
} else if (pBSSNode->abyCSSPK[i] == WLAN_11i_CSS_USE_GROUP) {
byCipherMask = 0;
i = pBSSNode->wCSSPKCount;
}
}
} else if ((WLAN_GET_CAP_INFO_PRIVACY(pBSSNode->wCapInfo) != 0) &&
(pBSSNode->bWPAValid == true) &&
((EncStatus == Ndis802_11Encryption2Enabled) || (EncStatus == Ndis802_11Encryption3Enabled))) {
if ((pBSSNode->byGKType == WPA_WEP40) ||
(pBSSNode->byGKType == WPA_WEP104)) {
byMulticastCipher = KEY_CTL_WEP;
} else if (pBSSNode->byGKType == WPA_TKIP) {
byMulticastCipher = KEY_CTL_TKIP;
} else if (pBSSNode->byGKType == WPA_AESCCMP) {
byMulticastCipher = KEY_CTL_CCMP;
} else {
byMulticastCipher = KEY_CTL_INVALID;
}
for (i = 0; i < pBSSNode->wPKCount; i++) {
if (pBSSNode->abyPKType[i] == WPA_TKIP) {
byCipherMask |= 0x02;
} else if (pBSSNode->abyPKType[i] == WPA_AESCCMP) {
byCipherMask |= 0x04;
} else if (pBSSNode->abyPKType[i] == WPA_NONE) {
byCipherMask = 0;
i = pBSSNode->wPKCount;
}
}
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"%d, %d, %d, %d, EncStatus:%d\n",
byMulticastCipher, byCipherMask, pBSSNode->bWPAValid, pBSSNode->bWPA2Valid, EncStatus);
if (EncStatus == Ndis802_11Encryption1Enabled) {
if ((byMulticastCipher == KEY_CTL_WEP) &&
(byCipherMask == 0)) {
*pbyCCSGK = KEY_CTL_WEP;
*pbyCCSPK = KEY_CTL_NONE;
return true;
} else {
return false;
}
} else if (EncStatus == Ndis802_11Encryption2Enabled) {
if ((byMulticastCipher == KEY_CTL_TKIP) &&
(byCipherMask == 0)) {
*pbyCCSGK = KEY_CTL_TKIP;
*pbyCCSPK = KEY_CTL_NONE;
return true;
} else if ((byMulticastCipher == KEY_CTL_WEP) &&
((byCipherMask & 0x02) != 0)) {
*pbyCCSGK = KEY_CTL_WEP;
*pbyCCSPK = KEY_CTL_TKIP;
return true;
} else if ((byMulticastCipher == KEY_CTL_TKIP) &&
((byCipherMask & 0x02) != 0)) {
*pbyCCSGK = KEY_CTL_TKIP;
*pbyCCSPK = KEY_CTL_TKIP;
return true;
} else {
return false;
}
} else if (EncStatus == Ndis802_11Encryption3Enabled) {
if ((byMulticastCipher == KEY_CTL_CCMP) &&
(byCipherMask == 0)) {
return false;
} else if ((byMulticastCipher == KEY_CTL_WEP) &&
((byCipherMask & 0x04) != 0)) {
*pbyCCSGK = KEY_CTL_WEP;
*pbyCCSPK = KEY_CTL_CCMP;
return true;
} else if ((byMulticastCipher == KEY_CTL_TKIP) &&
((byCipherMask & 0x04) != 0)) {
*pbyCCSGK = KEY_CTL_TKIP;
*pbyCCSPK = KEY_CTL_CCMP;
return true;
} else if ((byMulticastCipher == KEY_CTL_CCMP) &&
((byCipherMask & 0x04) != 0)) {
*pbyCCSGK = KEY_CTL_CCMP;
*pbyCCSPK = KEY_CTL_CCMP;
return true;
} else {
return false;
}
}
return true;
}
