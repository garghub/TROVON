static
void
vAdHocBeaconStop(PSDevice pDevice)
{
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
bool bStop;
bStop = false;
if ((pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) &&
(pMgmt->eCurrState >= WMAC_STATE_STARTED)) {
if ((pMgmt->uIBSSChannel <= CB_MAX_CHANNEL_24G) &&
(pMgmt->uScanChannel > CB_MAX_CHANNEL_24G)) {
bStop = true;
}
if (pMgmt->uIBSSChannel > CB_MAX_CHANNEL_24G) {
bStop = true;
}
}
if (bStop) {
MACvRegBitsOff(pDevice->PortOffset, MAC_REG_TCR, TCR_AUTOBCNTX);
}
}
static
void
vAdHocBeaconRestart(PSDevice pDevice)
{
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
if ((pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) &&
(pMgmt->eCurrState >= WMAC_STATE_STARTED)) {
MACvRegBitsOn(pDevice->PortOffset, MAC_REG_TCR, TCR_AUTOBCNTX);
}
}
static
void
s_vProbeChannel(
PSDevice pDevice
)
{
unsigned char abyCurrSuppRatesG[] = {WLAN_EID_SUPP_RATES, 8, 0x02, 0x04, 0x0B, 0x16, 0x24, 0x30, 0x48, 0x6C};
unsigned char abyCurrExtSuppRatesG[] = {WLAN_EID_EXTSUPP_RATES, 4, 0x0C, 0x12, 0x18, 0x60};
unsigned char abyCurrSuppRatesA[] = {WLAN_EID_SUPP_RATES, 8, 0x0C, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C};
unsigned char abyCurrSuppRatesB[] = {WLAN_EID_SUPP_RATES, 4, 0x02, 0x04, 0x0B, 0x16};
unsigned char *pbyRate;
PSTxMgmtPacket pTxPacket;
PSMgmtObject pMgmt = pDevice->pMgmt;
unsigned int ii;
if (pDevice->eCurrentPHYType == PHY_TYPE_11A) {
pbyRate = &abyCurrSuppRatesA[0];
} else if (pDevice->eCurrentPHYType == PHY_TYPE_11B) {
pbyRate = &abyCurrSuppRatesB[0];
} else {
pbyRate = &abyCurrSuppRatesG[0];
}
pTxPacket = s_MgrMakeProbeRequest
(
pDevice,
pMgmt,
pMgmt->abyScanBSSID,
(PWLAN_IE_SSID)pMgmt->abyScanSSID,
(PWLAN_IE_SUPP_RATES)pbyRate,
(PWLAN_IE_SUPP_RATES)abyCurrExtSuppRatesG
);
if (pTxPacket != NULL) {
for (ii = 0; ii < 2; ii++) {
if (csMgmt_xmit(pDevice, pTxPacket) != CMD_STATUS_PENDING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Probe request sending fail.. \n");
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Probe request is sending.. \n");
}
}
}
}
PSTxMgmtPacket
s_MgrMakeProbeRequest(
PSDevice pDevice,
PSMgmtObject pMgmt,
unsigned char *pScanBSSID,
PWLAN_IE_SSID pSSID,
PWLAN_IE_SUPP_RATES pCurrRates,
PWLAN_IE_SUPP_RATES pCurrExtSuppRates
)
{
PSTxMgmtPacket pTxPacket = NULL;
WLAN_FR_PROBEREQ sFrame;
pTxPacket = (PSTxMgmtPacket)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(STxMgmtPacket) + WLAN_PROBEREQ_FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((unsigned char *)pTxPacket + sizeof(STxMgmtPacket));
sFrame.pBuf = (unsigned char *)pTxPacket->p80211Header;
sFrame.len = WLAN_PROBEREQ_FR_MAXLEN;
vMgrEncodeProbeRequest(&sFrame);
sFrame.pHdr->sA3.wFrameCtl = cpu_to_le16(
(
WLAN_SET_FC_FTYPE(WLAN_TYPE_MGR) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_PROBEREQ)
));
memcpy(sFrame.pHdr->sA3.abyAddr1, pScanBSSID, WLAN_ADDR_LEN);
memcpy(sFrame.pHdr->sA3.abyAddr2, pMgmt->abyMACAddr, WLAN_ADDR_LEN);
memcpy(sFrame.pHdr->sA3.abyAddr3, pScanBSSID, WLAN_BSSID_LEN);
sFrame.pSSID = (PWLAN_IE_SSID)(sFrame.pBuf + sFrame.len);
sFrame.len += pSSID->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSSID, pSSID, pSSID->len + WLAN_IEHDR_LEN);
sFrame.pSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += pCurrRates->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pSuppRates, pCurrRates, pCurrRates->len + WLAN_IEHDR_LEN);
if (pDevice->eCurrentPHYType == PHY_TYPE_11G) {
sFrame.pExtSuppRates = (PWLAN_IE_SUPP_RATES)(sFrame.pBuf + sFrame.len);
sFrame.len += pCurrExtSuppRates->len + WLAN_IEHDR_LEN;
memcpy(sFrame.pExtSuppRates, pCurrExtSuppRates, pCurrExtSuppRates->len + WLAN_IEHDR_LEN);
}
pTxPacket->cbMPDULen = sFrame.len;
pTxPacket->cbPayloadLen = sFrame.len - WLAN_HDR_ADDR3_LEN;
return pTxPacket;
}
void
vCommandTimerWait(
void *hDeviceContext,
unsigned int MSecond
)
{
PSDevice pDevice = (PSDevice)hDeviceContext;
init_timer(&pDevice->sTimerCommand);
pDevice->sTimerCommand.data = (unsigned long) pDevice;
pDevice->sTimerCommand.function = (TimerFunction)vCommandTimer;
pDevice->sTimerCommand.expires = (unsigned int)RUN_AT((MSecond * HZ) >> 10);
add_timer(&pDevice->sTimerCommand);
return;
}
void
vCommandTimer(
void *hDeviceContext
)
{
PSDevice pDevice = (PSDevice)hDeviceContext;
PSMgmtObject pMgmt = pDevice->pMgmt;
PWLAN_IE_SSID pItemSSID;
PWLAN_IE_SSID pItemSSIDCurr;
CMD_STATUS Status;
unsigned int ii;
unsigned char byMask[8] = {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80};
struct sk_buff *skb;
if (pDevice->dwDiagRefCount != 0)
return;
if (pDevice->bCmdRunning != true)
return;
spin_lock_irq(&pDevice->lock);
switch (pDevice->eCommandState) {
case WLAN_CMD_SCAN_START:
pDevice->byReAssocCount = 0;
if (pDevice->bRadioOff == true) {
s_bCommandComplete(pDevice);
spin_unlock_irq(&pDevice->lock);
return;
}
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
s_bCommandComplete(pDevice);
CARDbSetBSSID(pMgmt->pAdapter, pMgmt->abyCurrBSSID, OP_MODE_AP);
spin_unlock_irq(&pDevice->lock);
return;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCommandState= WLAN_CMD_SCAN_START\n");
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyScanSSID;
if (pDevice->iTDUsed[TYPE_AC0DMA] != 0) {
spin_unlock_irq(&pDevice->lock);
vCommandTimerWait((void *)pDevice, 10);
return;
}
if (pMgmt->uScanChannel == 0) {
pMgmt->uScanChannel = pDevice->byMinChannel;
}
if (pMgmt->uScanChannel > pDevice->byMaxChannel) {
pMgmt->eScanState = WMAC_NO_SCANNING;
set_channel(pMgmt->pAdapter, pMgmt->uCurrChannel);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Scanning, set back to channel: [%d]\n", pMgmt->uCurrChannel);
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
CARDbSetBSSID(pMgmt->pAdapter, pMgmt->abyCurrBSSID, OP_MODE_ADHOC);
} else {
CARDbSetBSSID(pMgmt->pAdapter, pMgmt->abyCurrBSSID, OP_MODE_INFRASTRUCTURE);
}
vAdHocBeaconRestart(pDevice);
s_bCommandComplete(pDevice);
} else {
if (!is_channel_valid(pMgmt->uScanChannel)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Invalid channel pMgmt->uScanChannel = %d \n", pMgmt->uScanChannel);
s_bCommandComplete(pDevice);
spin_unlock_irq(&pDevice->lock);
return;
}
if (pMgmt->uScanChannel == pDevice->byMinChannel) {
pMgmt->abyScanBSSID[0] = 0xFF;
pMgmt->abyScanBSSID[1] = 0xFF;
pMgmt->abyScanBSSID[2] = 0xFF;
pMgmt->abyScanBSSID[3] = 0xFF;
pMgmt->abyScanBSSID[4] = 0xFF;
pMgmt->abyScanBSSID[5] = 0xFF;
pItemSSID->byElementID = WLAN_EID_SSID;
pMgmt->eScanState = WMAC_IS_SCANNING;
}
vAdHocBeaconStop(pDevice);
if (set_channel(pMgmt->pAdapter, pMgmt->uScanChannel) == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "SCAN Channel: %d\n", pMgmt->uScanChannel);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "SET SCAN Channel Fail: %d\n", pMgmt->uScanChannel);
}
CARDbSetBSSID(pMgmt->pAdapter, pMgmt->abyCurrBSSID, OP_MODE_UNKNOWN);
pMgmt->uScanChannel++;
if (!is_channel_valid(pMgmt->uScanChannel) &&
pMgmt->uScanChannel <= pDevice->byMaxChannel) {
pMgmt->uScanChannel = pDevice->byMaxChannel + 1;
pMgmt->eCommandState = WLAN_CMD_SCAN_END;
}
if ((pMgmt->b11hEnable == false) ||
(pMgmt->uScanChannel < CB_MAX_CHANNEL_24G)) {
s_vProbeChannel(pDevice);
spin_unlock_irq(&pDevice->lock);
vCommandTimerWait((void *)pDevice, WCMD_ACTIVE_SCAN_TIME);
return;
} else {
spin_unlock_irq(&pDevice->lock);
vCommandTimerWait((void *)pDevice, WCMD_PASSIVE_SCAN_TIME);
return;
}
}
break;
case WLAN_CMD_SCAN_END:
set_channel(pMgmt->pAdapter, pMgmt->uCurrChannel);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Scanning, set back to channel: [%d]\n", pMgmt->uCurrChannel);
if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
CARDbSetBSSID(pMgmt->pAdapter, pMgmt->abyCurrBSSID, OP_MODE_ADHOC);
} else {
CARDbSetBSSID(pMgmt->pAdapter, pMgmt->abyCurrBSSID, OP_MODE_INFRASTRUCTURE);
}
pMgmt->eScanState = WMAC_NO_SCANNING;
vAdHocBeaconRestart(pDevice);
#ifdef WPA_SUPPLICANT_DRIVER_WEXT_SUPPORT
if (pMgmt->eScanType == WMAC_SCAN_PASSIVE)
{
union iwreq_data wrqu;
memset(&wrqu, 0, sizeof(wrqu));
wireless_send_event(pDevice->dev, SIOCGIWSCAN, &wrqu, NULL);
}
#endif
s_bCommandComplete(pDevice);
break;
case WLAN_CMD_DISASSOCIATE_START:
pDevice->byReAssocCount = 0;
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_STA) &&
(pMgmt->eCurrState != WMAC_STATE_ASSOC)) {
s_bCommandComplete(pDevice);
spin_unlock_irq(&pDevice->lock);
return;
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Send Disassociation Packet..\n");
vMgrDisassocBeginSta((void *)pDevice, pMgmt, pMgmt->abyCurrBSSID, (8), &Status);
pDevice->bLinkPass = false;
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyCurrSSID;
pItemSSID->len = 0;
memset(pItemSSID->abySSID, 0, WLAN_SSID_MAXLEN);
pMgmt->eCurrState = WMAC_STATE_IDLE;
pMgmt->sNodeDBTable[0].bActive = false;
}
netif_stop_queue(pDevice->dev);
pDevice->eCommandState = WLAN_DISASSOCIATE_WAIT;
if (pDevice->iTDUsed[TYPE_TXDMA0] != 0) {
vCommandTimerWait((void *)pDevice, 10);
spin_unlock_irq(&pDevice->lock);
return;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " CARDbRadioPowerOff\n");
s_bCommandComplete(pDevice);
break;
case WLAN_DISASSOCIATE_WAIT:
if (pDevice->iTDUsed[TYPE_TXDMA0] != 0) {
vCommandTimerWait((void *)pDevice, 10);
spin_unlock_irq(&pDevice->lock);
return;
}
s_bCommandComplete(pDevice);
break;
case WLAN_CMD_SSID_START:
pDevice->byReAssocCount = 0;
if (pDevice->bRadioOff == true) {
s_bCommandComplete(pDevice);
spin_unlock_irq(&pDevice->lock);
return;
}
printk("chester-abyDesireSSID=%s\n", ((PWLAN_IE_SSID)pMgmt->abyDesireSSID)->abySSID);
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyDesireSSID;
pItemSSIDCurr = (PWLAN_IE_SSID)pMgmt->abyCurrSSID;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " cmd: desire ssid = %s\n", pItemSSID->abySSID);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " cmd: curr ssid = %s\n", pItemSSIDCurr->abySSID);
if (pMgmt->eCurrState == WMAC_STATE_ASSOC) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " Cmd pMgmt->eCurrState == WMAC_STATE_ASSOC\n");
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " pItemSSID->len =%d\n", pItemSSID->len);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " pItemSSIDCurr->len = %d\n", pItemSSIDCurr->len);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " desire ssid = %s\n", pItemSSID->abySSID);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " curr ssid = %s\n", pItemSSIDCurr->abySSID);
}
if ((pMgmt->eCurrState == WMAC_STATE_ASSOC) ||
((pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) && (pMgmt->eCurrState == WMAC_STATE_JOINTED))) {
if (pItemSSID->len == pItemSSIDCurr->len) {
if (memcmp(pItemSSID->abySSID, pItemSSIDCurr->abySSID, pItemSSID->len) == 0) {
s_bCommandComplete(pDevice);
spin_unlock_irq(&pDevice->lock);
return;
}
}
netif_stop_queue(pDevice->dev);
pDevice->bLinkPass = false;
}
pMgmt->eCurrState = WMAC_STATE_IDLE;
pMgmt->eCurrMode = WMAC_MODE_STANDBY;
PSvDisablePowerSaving((void *)pDevice);
BSSvClearNodeDBTable(pDevice, 0);
vMgrJoinBSSBegin((void *)pDevice, &Status);
if ((pMgmt->eCurrMode == WMAC_MODE_ESS_STA) && (pMgmt->eCurrState == WMAC_STATE_JOINTED)) {
if (pMgmt->eCurrState >= WMAC_STATE_AUTH) {
vMgrDeAuthenBeginSta((void *)pDevice, pMgmt, pMgmt->abyCurrBSSID, (3), &Status);
}
vMgrAuthenBeginSta((void *)pDevice, pMgmt, &Status);
if (Status == CMD_STATUS_SUCCESS) {
pDevice->byLinkWaitCount = 0;
pDevice->eCommandState = WLAN_AUTHENTICATE_WAIT;
vCommandTimerWait((void *)pDevice, AUTHENTICATE_TIMEOUT);
spin_unlock_irq(&pDevice->lock);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " Set eCommandState = WLAN_AUTHENTICATE_WAIT\n");
return;
}
}
else if (pMgmt->eCurrMode == WMAC_MODE_IBSS_STA) {
if (pMgmt->eCurrState == WMAC_STATE_JOINTED) {
if (netif_queue_stopped(pDevice->dev)) {
netif_wake_queue(pDevice->dev);
}
pDevice->bLinkPass = true;
pMgmt->sNodeDBTable[0].bActive = true;
pMgmt->sNodeDBTable[0].uInActiveCount = 0;
bClearBSSID_SCAN(pDevice);
} else {
vMgrCreateOwnIBSS((void *)pDevice, &Status);
if (Status != CMD_STATUS_SUCCESS) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " WLAN_CMD_IBSS_CREATE fail ! \n");
}
BSSvAddMulticastNode(pDevice);
}
}
else if (pMgmt->eCurrMode == WMAC_MODE_STANDBY) {
if (pMgmt->eConfigMode == WMAC_CONFIG_IBSS_STA ||
pMgmt->eConfigMode == WMAC_CONFIG_AUTO) {
vMgrCreateOwnIBSS((void *)pDevice, &Status);
if (Status != CMD_STATUS_SUCCESS) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " WLAN_CMD_IBSS_CREATE fail ! \n");
}
BSSvAddMulticastNode(pDevice);
if (netif_queue_stopped(pDevice->dev)) {
netif_wake_queue(pDevice->dev);
}
pDevice->bLinkPass = true;
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Disconnect SSID none\n");
#ifdef WPA_SUPPLICANT_DRIVER_WEXT_SUPPORT
{
union iwreq_data wrqu;
memset(&wrqu, 0, sizeof(wrqu));
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
printk("wireless_send_event--->SIOCGIWAP(disassociated:vMgrJoinBSSBegin Fail !!)\n");
wireless_send_event(pDevice->dev, SIOCGIWAP, &wrqu, NULL);
}
#endif
}
}
s_bCommandComplete(pDevice);
break;
case WLAN_AUTHENTICATE_WAIT:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCommandState == WLAN_AUTHENTICATE_WAIT\n");
if (pMgmt->eCurrState == WMAC_STATE_AUTH) {
pDevice->byLinkWaitCount = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCurrState == WMAC_STATE_AUTH\n");
vMgrAssocBeginSta((void *)pDevice, pMgmt, &Status);
if (Status == CMD_STATUS_SUCCESS) {
pDevice->byLinkWaitCount = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCommandState = WLAN_ASSOCIATE_WAIT\n");
pDevice->eCommandState = WLAN_ASSOCIATE_WAIT;
vCommandTimerWait((void *)pDevice, ASSOCIATE_TIMEOUT);
spin_unlock_irq(&pDevice->lock);
return;
}
}
else if (pMgmt->eCurrState < WMAC_STATE_AUTHPENDING) {
printk("WLAN_AUTHENTICATE_WAIT:Authen Fail???\n");
} else if (pDevice->byLinkWaitCount <= 4) {
pDevice->byLinkWaitCount++;
printk("WLAN_AUTHENTICATE_WAIT:wait %d times!!\n", pDevice->byLinkWaitCount);
spin_unlock_irq(&pDevice->lock);
vCommandTimerWait((void *)pDevice, AUTHENTICATE_TIMEOUT/2);
return;
}
pDevice->byLinkWaitCount = 0;
s_bCommandComplete(pDevice);
break;
case WLAN_ASSOCIATE_WAIT:
if (pMgmt->eCurrState == WMAC_STATE_ASSOC) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCurrState == WMAC_STATE_ASSOC\n");
if (pDevice->ePSMode != WMAC_POWER_CAM) {
PSvEnablePowerSaving((void *)pDevice, pMgmt->wListenInterval);
}
if (pMgmt->eAuthenMode >= WMAC_AUTH_WPA) {
KeybRemoveAllKey(&(pDevice->sKey), pDevice->abyBSSID, pDevice->PortOffset);
}
pDevice->bLinkPass = true;
pDevice->byLinkWaitCount = 0;
pDevice->byReAssocCount = 0;
bClearBSSID_SCAN(pDevice);
if (pDevice->byFOETuning) {
BBvSetFOE(pDevice->PortOffset);
PSbSendNullPacket(pDevice);
}
if (netif_queue_stopped(pDevice->dev)) {
netif_wake_queue(pDevice->dev);
}
#ifdef TxInSleep
if (pDevice->IsTxDataTrigger != false) {
del_timer(&pDevice->sTimerTxData);
init_timer(&pDevice->sTimerTxData);
pDevice->sTimerTxData.data = (unsigned long) pDevice;
pDevice->sTimerTxData.function = (TimerFunction)BSSvSecondTxData;
pDevice->sTimerTxData.expires = RUN_AT(10*HZ);
pDevice->fTxDataInSleep = false;
pDevice->nTxDataTimeCout = 0;
} else {
}
pDevice->IsTxDataTrigger = true;
add_timer(&pDevice->sTimerTxData);
#endif
} else if (pMgmt->eCurrState < WMAC_STATE_ASSOCPENDING) {
printk("WLAN_ASSOCIATE_WAIT:Association Fail???\n");
} else if (pDevice->byLinkWaitCount <= 4) {
pDevice->byLinkWaitCount++;
printk("WLAN_ASSOCIATE_WAIT:wait %d times!!\n", pDevice->byLinkWaitCount);
spin_unlock_irq(&pDevice->lock);
vCommandTimerWait((void *)pDevice, ASSOCIATE_TIMEOUT/2);
return;
}
pDevice->byLinkWaitCount = 0;
s_bCommandComplete(pDevice);
break;
case WLAN_CMD_AP_MODE_START:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCommandState == WLAN_CMD_AP_MODE_START\n");
if (pMgmt->eConfigMode == WMAC_CONFIG_AP) {
del_timer(&pMgmt->sTimerSecondCallback);
pMgmt->eCurrState = WMAC_STATE_IDLE;
pMgmt->eCurrMode = WMAC_MODE_STANDBY;
pDevice->bLinkPass = false;
if (pDevice->bEnableHostWEP == true)
BSSvClearNodeDBTable(pDevice, 1);
else
BSSvClearNodeDBTable(pDevice, 0);
pDevice->uAssocCount = 0;
pMgmt->eCurrState = WMAC_STATE_IDLE;
pDevice->bFixRate = false;
vMgrCreateOwnIBSS((void *)pDevice, &Status);
if (Status != CMD_STATUS_SUCCESS) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " vMgrCreateOwnIBSS fail ! \n");
}
MACvRegBitsOff(pDevice->PortOffset, MAC_REG_RCR, RCR_UNICAST);
pDevice->byRxMode &= ~RCR_UNICAST;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "wcmd: rx_mode = %x\n", pDevice->byRxMode);
BSSvAddMulticastNode(pDevice);
if (netif_queue_stopped(pDevice->dev)) {
netif_wake_queue(pDevice->dev);
}
pDevice->bLinkPass = true;
add_timer(&pMgmt->sTimerSecondCallback);
}
s_bCommandComplete(pDevice);
break;
case WLAN_CMD_TX_PSPACKET_START:
if (pMgmt->sNodeDBTable[0].bRxPSPoll) {
while ((skb = skb_dequeue(&pMgmt->sNodeDBTable[0].sTxPSQueue)) != NULL) {
if (skb_queue_empty(&pMgmt->sNodeDBTable[0].sTxPSQueue)) {
pMgmt->abyPSTxMap[0] &= ~byMask[0];
pDevice->bMoreData = false;
} else {
pDevice->bMoreData = true;
}
if (!device_dma0_xmit(pDevice, skb, 0)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Multicast ps tx fail \n");
}
pMgmt->sNodeDBTable[0].wEnQueueCnt--;
}
}
for (ii = 1; ii < (MAX_NODE_NUM + 1); ii++) {
if (pMgmt->sNodeDBTable[ii].bActive &&
pMgmt->sNodeDBTable[ii].bRxPSPoll) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Index=%d Enqueu Cnt= %d\n",
ii, pMgmt->sNodeDBTable[ii].wEnQueueCnt);
while ((skb = skb_dequeue(&pMgmt->sNodeDBTable[ii].sTxPSQueue)) != NULL) {
if (skb_queue_empty(&pMgmt->sNodeDBTable[ii].sTxPSQueue)) {
pMgmt->abyPSTxMap[pMgmt->sNodeDBTable[ii].wAID >> 3] &=
~byMask[pMgmt->sNodeDBTable[ii].wAID & 7];
pDevice->bMoreData = false;
} else {
pDevice->bMoreData = true;
}
if (!device_dma0_xmit(pDevice, skb, ii)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "sta ps tx fail \n");
}
pMgmt->sNodeDBTable[ii].wEnQueueCnt--;
if (pMgmt->sNodeDBTable[ii].bPSEnable)
break;
}
if (skb_queue_empty(&pMgmt->sNodeDBTable[ii].sTxPSQueue)) {
pMgmt->abyPSTxMap[pMgmt->sNodeDBTable[ii].wAID >> 3] &=
~byMask[pMgmt->sNodeDBTable[ii].wAID & 7];
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Index=%d PS queue clear \n", ii);
}
pMgmt->sNodeDBTable[ii].bRxPSPoll = false;
}
}
s_bCommandComplete(pDevice);
break;
case WLAN_CMD_RADIO_START:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCommandState == WLAN_CMD_RADIO_START\n");
if (pDevice->bRadioCmd == true)
CARDbRadioPowerOn(pDevice);
else
CARDbRadioPowerOff(pDevice);
s_bCommandComplete(pDevice);
break;
case WLAN_CMD_CHECK_BBSENSITIVITY_CHANGE:
if (pDevice->iTDUsed[TYPE_AC0DMA] != 0) {
vCommandTimerWait((void *)pDevice, 10);
spin_unlock_irq(&pDevice->lock);
return;
}
if (pDevice->iTDUsed[TYPE_TXDMA0] != 0) {
vCommandTimerWait((void *)pDevice, 10);
spin_unlock_irq(&pDevice->lock);
return;
}
pDevice->byBBVGACurrent = pDevice->byBBVGANew;
BBvSetVGAGainOffset(pDevice, pDevice->byBBVGACurrent);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "SetVGAGainOffset %02X\n", pDevice->byBBVGACurrent);
s_bCommandComplete(pDevice);
break;
default:
s_bCommandComplete(pDevice);
break;
}
spin_unlock_irq(&pDevice->lock);
return;
}
static
bool
s_bCommandComplete(
PSDevice pDevice
)
{
PWLAN_IE_SSID pSSID;
bool bRadioCmd = false;
bool bForceSCAN = true;
PSMgmtObject pMgmt = pDevice->pMgmt;
pDevice->eCommandState = WLAN_CMD_IDLE;
if (pDevice->cbFreeCmdQueue == CMD_Q_SIZE) {
pDevice->bCmdRunning = false;
return true;
} else {
pDevice->eCommand = pDevice->eCmdQueue[pDevice->uCmdDequeueIdx].eCmd;
pSSID = (PWLAN_IE_SSID)pDevice->eCmdQueue[pDevice->uCmdDequeueIdx].abyCmdDesireSSID;
bRadioCmd = pDevice->eCmdQueue[pDevice->uCmdDequeueIdx].bRadioCmd;
bForceSCAN = pDevice->eCmdQueue[pDevice->uCmdDequeueIdx].bForceSCAN;
ADD_ONE_WITH_WRAP_AROUND(pDevice->uCmdDequeueIdx, CMD_Q_SIZE);
pDevice->cbFreeCmdQueue++;
pDevice->bCmdRunning = true;
switch (pDevice->eCommand) {
case WLAN_CMD_BSSID_SCAN:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCommandState= WLAN_CMD_BSSID_SCAN\n");
pDevice->eCommandState = WLAN_CMD_SCAN_START;
pMgmt->uScanChannel = 0;
if (pSSID->len != 0) {
memcpy(pMgmt->abyScanSSID, pSSID, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
} else {
memset(pMgmt->abyScanSSID, 0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
}
break;
case WLAN_CMD_SSID:
pDevice->eCommandState = WLAN_CMD_SSID_START;
if (pSSID->len > WLAN_SSID_MAXLEN)
pSSID->len = WLAN_SSID_MAXLEN;
if (pSSID->len != 0)
memcpy(pDevice->pMgmt->abyDesireSSID, pSSID, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "eCommandState= WLAN_CMD_SSID_START\n");
break;
case WLAN_CMD_DISASSOCIATE:
pDevice->eCommandState = WLAN_CMD_DISASSOCIATE_START;
break;
case WLAN_CMD_RX_PSPOLL:
pDevice->eCommandState = WLAN_CMD_TX_PSPACKET_START;
break;
case WLAN_CMD_RUN_AP:
pDevice->eCommandState = WLAN_CMD_AP_MODE_START;
break;
case WLAN_CMD_RADIO:
pDevice->eCommandState = WLAN_CMD_RADIO_START;
pDevice->bRadioCmd = bRadioCmd;
break;
case WLAN_CMD_CHANGE_BBSENSITIVITY:
pDevice->eCommandState = WLAN_CMD_CHECK_BBSENSITIVITY_CHANGE;
break;
default:
break;
}
vCommandTimerWait((void *)pDevice, 0);
}
return true;
}
bool bScheduleCommand(
void *hDeviceContext,
CMD_CODE eCommand,
unsigned char *pbyItem0
)
{
PSDevice pDevice = (PSDevice)hDeviceContext;
if (pDevice->cbFreeCmdQueue == 0) {
return false;
}
pDevice->eCmdQueue[pDevice->uCmdEnqueueIdx].eCmd = eCommand;
pDevice->eCmdQueue[pDevice->uCmdEnqueueIdx].bForceSCAN = true;
memset(pDevice->eCmdQueue[pDevice->uCmdEnqueueIdx].abyCmdDesireSSID, 0 , WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
if (pbyItem0 != NULL) {
switch (eCommand) {
case WLAN_CMD_BSSID_SCAN:
memcpy(pDevice->eCmdQueue[pDevice->uCmdEnqueueIdx].abyCmdDesireSSID,
pbyItem0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
pDevice->eCmdQueue[pDevice->uCmdEnqueueIdx].bForceSCAN = false;
break;
case WLAN_CMD_SSID:
memcpy(pDevice->eCmdQueue[pDevice->uCmdEnqueueIdx].abyCmdDesireSSID,
pbyItem0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
break;
case WLAN_CMD_DISASSOCIATE:
pDevice->eCmdQueue[pDevice->uCmdEnqueueIdx].bNeedRadioOFF = *((int *)pbyItem0);
break;
case WLAN_CMD_RX_PSPOLL:
break;
case WLAN_CMD_RADIO:
pDevice->eCmdQueue[pDevice->uCmdEnqueueIdx].bRadioCmd = *((int *)pbyItem0);
break;
case WLAN_CMD_CHANGE_BBSENSITIVITY:
pDevice->eCommandState = WLAN_CMD_CHECK_BBSENSITIVITY_CHANGE;
break;
default:
break;
}
}
ADD_ONE_WITH_WRAP_AROUND(pDevice->uCmdEnqueueIdx, CMD_Q_SIZE);
pDevice->cbFreeCmdQueue--;
if (pDevice->bCmdRunning == false) {
s_bCommandComplete(pDevice);
} else {
}
return true;
}
bool bClearBSSID_SCAN(
void *hDeviceContext
)
{
PSDevice pDevice = (PSDevice)hDeviceContext;
unsigned int uCmdDequeueIdx = pDevice->uCmdDequeueIdx;
unsigned int ii;
if ((pDevice->cbFreeCmdQueue < CMD_Q_SIZE) && (uCmdDequeueIdx != pDevice->uCmdEnqueueIdx)) {
for (ii = 0; ii < (CMD_Q_SIZE - pDevice->cbFreeCmdQueue); ii++) {
if (pDevice->eCmdQueue[uCmdDequeueIdx].eCmd == WLAN_CMD_BSSID_SCAN)
pDevice->eCmdQueue[uCmdDequeueIdx].eCmd = WLAN_CMD_IDLE;
ADD_ONE_WITH_WRAP_AROUND(uCmdDequeueIdx, CMD_Q_SIZE);
if (uCmdDequeueIdx == pDevice->uCmdEnqueueIdx)
break;
}
}
return true;
}
void
vResetCommandTimer(
void *hDeviceContext
)
{
PSDevice pDevice = (PSDevice)hDeviceContext;
del_timer(&pDevice->sTimerCommand);
init_timer(&pDevice->sTimerCommand);
pDevice->sTimerCommand.data = (unsigned long) pDevice;
pDevice->sTimerCommand.function = (TimerFunction)vCommandTimer;
pDevice->sTimerCommand.expires = RUN_AT(HZ);
pDevice->cbFreeCmdQueue = CMD_Q_SIZE;
pDevice->uCmdDequeueIdx = 0;
pDevice->uCmdEnqueueIdx = 0;
pDevice->eCommandState = WLAN_CMD_IDLE;
pDevice->bCmdRunning = false;
pDevice->bCmdClear = false;
}
void
BSSvSecondTxData(
void *hDeviceContext
)
{
PSDevice pDevice = (PSDevice)hDeviceContext;
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
pDevice->nTxDataTimeCout++;
if (pDevice->nTxDataTimeCout < 4)
{
pDevice->sTimerTxData.expires = RUN_AT(10*HZ);
add_timer(&pDevice->sTimerTxData);
return;
}
spin_lock_irq(&pDevice->lock);
#if 1
if (((pDevice->bLinkPass == true) && (pMgmt->eAuthenMode < WMAC_AUTH_WPA)) ||
(pDevice->fWPA_Authened == true)) {
#else
if (pDevice->bLinkPass == true) {
#endif
pDevice->fTxDataInSleep = true;
PSbSendNullPacket(pDevice);
pDevice->fTxDataInSleep = false;
}
spin_unlock_irq(&pDevice->lock);
pDevice->sTimerTxData.expires = RUN_AT(10*HZ);
add_timer(&pDevice->sTimerTxData);
return;
}
