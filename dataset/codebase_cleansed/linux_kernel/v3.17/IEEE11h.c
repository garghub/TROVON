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
