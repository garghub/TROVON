static bool s_bRxMSRReq(PSMgmtObject pMgmt, PWLAN_FRAME_MSRREQ pMSRReq,
unsigned int uLength)
{
size_t uNumOfEIDs = 0;
bool bResult = true;
if (uLength <= WLAN_A3FR_MAXLEN)
memcpy(pMgmt->abyCurrentMSRReq, pMSRReq, uLength);
uNumOfEIDs = ((uLength - offsetof(WLAN_FRAME_MSRREQ,
sMSRReqEIDs))/
(sizeof(WLAN_IE_MEASURE_REQ)));
pMgmt->pCurrMeasureEIDRep = &(((PWLAN_FRAME_MSRREP)
(pMgmt->abyCurrentMSRRep))->sMSRRepEIDs[0]);
pMgmt->uLengthOfRepEIDs = 0;
bResult = CARDbStartMeasure(pMgmt->pAdapter,
((PWLAN_FRAME_MSRREQ)
(pMgmt->abyCurrentMSRReq))->sMSRReqEIDs,
uNumOfEIDs
);
return bResult;
}
static bool s_bRxTPCReq(PSMgmtObject pMgmt,
PWLAN_FRAME_TPCREQ pTPCReq,
unsigned char byRate,
unsigned char byRSSI)
{
PWLAN_FRAME_TPCREP pFrame;
PSTxMgmtPacket pTxPacket = NULL;
pTxPacket = (PSTxMgmtPacket)pMgmt->pbyMgmtPacketPool;
memset(pTxPacket, 0, sizeof(STxMgmtPacket) + WLAN_A3FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((unsigned char *)pTxPacket +
sizeof(STxMgmtPacket));
pFrame = (PWLAN_FRAME_TPCREP)((unsigned char *)pTxPacket +
sizeof(STxMgmtPacket));
pFrame->Header.wFrameCtl = (WLAN_SET_FC_FTYPE(WLAN_FTYPE_MGMT) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_ACTION)
);
memcpy(pFrame->Header.abyAddr1,
pTPCReq->Header.abyAddr2,
WLAN_ADDR_LEN);
memcpy(pFrame->Header.abyAddr2,
CARDpGetCurrentAddress(pMgmt->pAdapter),
WLAN_ADDR_LEN);
memcpy(pFrame->Header.abyAddr3,
pMgmt->abyCurrBSSID,
WLAN_BSSID_LEN);
pFrame->byCategory = 0;
pFrame->byAction = 3;
pFrame->byDialogToken = ((PWLAN_FRAME_MSRREQ)
(pMgmt->abyCurrentMSRReq))->byDialogToken;
pFrame->sTPCRepEIDs.byElementID = WLAN_EID_TPC_REP;
pFrame->sTPCRepEIDs.len = 2;
pFrame->sTPCRepEIDs.byTxPower = CARDbyGetTransmitPower(pMgmt->pAdapter);
switch (byRate) {
case RATE_54M:
pFrame->sTPCRepEIDs.byLinkMargin = 65 - byRSSI;
break;
case RATE_48M:
pFrame->sTPCRepEIDs.byLinkMargin = 66 - byRSSI;
break;
case RATE_36M:
pFrame->sTPCRepEIDs.byLinkMargin = 70 - byRSSI;
break;
case RATE_24M:
pFrame->sTPCRepEIDs.byLinkMargin = 74 - byRSSI;
break;
case RATE_18M:
pFrame->sTPCRepEIDs.byLinkMargin = 77 - byRSSI;
break;
case RATE_12M:
pFrame->sTPCRepEIDs.byLinkMargin = 79 - byRSSI;
break;
case RATE_9M:
pFrame->sTPCRepEIDs.byLinkMargin = 81 - byRSSI;
break;
case RATE_6M:
default:
pFrame->sTPCRepEIDs.byLinkMargin = 82 - byRSSI;
break;
}
pTxPacket->cbMPDULen = sizeof(WLAN_FRAME_TPCREP);
pTxPacket->cbPayloadLen = sizeof(WLAN_FRAME_TPCREP) -
WLAN_HDR_ADDR3_LEN;
if (csMgmt_xmit(pMgmt->pAdapter, pTxPacket) != CMD_STATUS_PENDING)
return false;
return true;
}
bool
IEEE11hbMgrRxAction(void *pMgmtHandle, void *pRxPacket)
{
PSMgmtObject pMgmt = (PSMgmtObject) pMgmtHandle;
PWLAN_FRAME_ACTION pAction = NULL;
unsigned int uLength = 0;
PWLAN_IE_CH_SW pChannelSwitch = NULL;
uLength = ((PSRxMgmtPacket)pRxPacket)->cbMPDULen;
if (uLength > WLAN_A3FR_MAXLEN)
return false;
pAction = (PWLAN_FRAME_ACTION)
(((PSRxMgmtPacket)pRxPacket)->p80211Header);
if (pAction->byCategory == 0) {
switch (pAction->byAction) {
case ACTION_MSRREQ:
return s_bRxMSRReq(pMgmt,
(PWLAN_FRAME_MSRREQ)
pAction,
uLength);
break;
case ACTION_MSRREP:
break;
case ACTION_TPCREQ:
return s_bRxTPCReq(pMgmt,
(PWLAN_FRAME_TPCREQ) pAction,
((PSRxMgmtPacket)pRxPacket)->byRxRate,
(unsigned char)
((PSRxMgmtPacket)pRxPacket)->uRSSI);
break;
case ACTION_TPCREP:
break;
case ACTION_CHSW:
pChannelSwitch = (PWLAN_IE_CH_SW) (pAction->abyVars);
if ((pChannelSwitch->byElementID == WLAN_EID_CH_SWITCH)
&& (pChannelSwitch->len == 3)) {
CARDbChannelSwitch(pMgmt->pAdapter,
pChannelSwitch->byMode,
get_channel_mapping(pMgmt->pAdapter,
pChannelSwitch->byChannel,
pMgmt->eCurrentPHYMode),
pChannelSwitch->byCount);
}
break;
default:
DBG_PRT(MSG_LEVEL_DEBUG,
KERN_INFO "Unknown Action = %d\n",
pAction->byAction);
break;
}
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Unknown Category = %d\n",
pAction->byCategory);
pAction->byCategory |= 0x80;
return true;
}
return true;
}
bool IEEE11hbMSRRepTx(void *pMgmtHandle)
{
PSMgmtObject pMgmt = (PSMgmtObject) pMgmtHandle;
PWLAN_FRAME_MSRREP pMSRRep = (PWLAN_FRAME_MSRREP)
(pMgmt->abyCurrentMSRRep + sizeof(STxMgmtPacket));
size_t uLength = 0;
PSTxMgmtPacket pTxPacket = NULL;
pTxPacket = (PSTxMgmtPacket)pMgmt->abyCurrentMSRRep;
memset(pTxPacket, 0, sizeof(STxMgmtPacket) + WLAN_A3FR_MAXLEN);
pTxPacket->p80211Header = (PUWLAN_80211HDR)((unsigned char *)pTxPacket +
sizeof(STxMgmtPacket));
pMSRRep->Header.wFrameCtl = (WLAN_SET_FC_FTYPE(WLAN_FTYPE_MGMT) |
WLAN_SET_FC_FSTYPE(WLAN_FSTYPE_ACTION)
);
memcpy(pMSRRep->Header.abyAddr1, ((PWLAN_FRAME_MSRREQ)
(pMgmt->abyCurrentMSRReq))->Header.abyAddr2, WLAN_ADDR_LEN);
memcpy(pMSRRep->Header.abyAddr2,
CARDpGetCurrentAddress(pMgmt->pAdapter), WLAN_ADDR_LEN);
memcpy(pMSRRep->Header.abyAddr3, pMgmt->abyCurrBSSID, WLAN_BSSID_LEN);
pMSRRep->byCategory = 0;
pMSRRep->byAction = 1;
pMSRRep->byDialogToken = ((PWLAN_FRAME_MSRREQ)
(pMgmt->abyCurrentMSRReq))->byDialogToken;
uLength = pMgmt->uLengthOfRepEIDs + offsetof(WLAN_FRAME_MSRREP,
sMSRRepEIDs);
pTxPacket->cbMPDULen = uLength;
pTxPacket->cbPayloadLen = uLength - WLAN_HDR_ADDR3_LEN;
if (csMgmt_xmit(pMgmt->pAdapter, pTxPacket) != CMD_STATUS_PENDING)
return false;
return true;
}
