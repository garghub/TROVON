bool ROUTEbRelay(struct vnt_private *pDevice, unsigned char *pbySkbData,
unsigned int uDataLen, unsigned int uNodeIndex)
{
PSMgmtObject pMgmt = pDevice->pMgmt;
PSTxDesc pHeadTD, pLastTD;
unsigned int cbFrameBodySize;
unsigned int uMACfragNum;
unsigned char byPktType;
bool bNeedEncryption = false;
SKeyItem STempKey;
PSKeyItem pTransmitKey = NULL;
unsigned int cbHeaderSize;
unsigned int ii;
unsigned char *pbyBSSID;
if (AVAIL_TD(pDevice, TYPE_AC0DMA) <= 0) {
pr_debug("Relay can't allocate TD1..\n");
return false;
}
pHeadTD = pDevice->apCurrTD[TYPE_AC0DMA];
pHeadTD->m_td1TD1.byTCR = (TCR_EDP | TCR_STP);
memcpy(pDevice->sTxEthHeader.abyDstAddr, pbySkbData, ETH_HLEN);
cbFrameBodySize = uDataLen - ETH_HLEN;
if (ntohs(pDevice->sTxEthHeader.wType) > ETH_DATA_LEN)
cbFrameBodySize += 8;
if (pDevice->bEncryptionEnable == true) {
bNeedEncryption = true;
pbyBSSID = pDevice->abyBroadcastAddr;
if (KeybGetTransmitKey(&(pDevice->sKey), pbyBSSID,
GROUP_KEY, &pTransmitKey) == false) {
pTransmitKey = NULL;
pr_debug("KEY is NULL. [%d]\n",
pDevice->pMgmt->eCurrMode);
} else {
pr_debug("Get GTK\n");
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
pTransmitKey->uKeyLength);
}
}
uMACfragNum = cbGetFragCount(pDevice, pTransmitKey,
cbFrameBodySize, &pDevice->sTxEthHeader);
if (uMACfragNum > AVAIL_TD(pDevice, TYPE_AC0DMA))
return false;
byPktType = pDevice->byPacketType;
if (pDevice->bFixRate) {
if (pDevice->eCurrentPHYType == PHY_TYPE_11B) {
if (pDevice->uConnectionRate >= RATE_11M)
pDevice->wCurrentRate = RATE_11M;
else
pDevice->wCurrentRate = pDevice->uConnectionRate;
} else {
if ((pDevice->eCurrentPHYType == PHY_TYPE_11A) &&
(pDevice->uConnectionRate <= RATE_6M)) {
pDevice->wCurrentRate = RATE_6M;
} else {
if (pDevice->uConnectionRate >= RATE_54M)
pDevice->wCurrentRate = RATE_54M;
else
pDevice->wCurrentRate = pDevice->uConnectionRate;
}
}
} else {
pDevice->wCurrentRate = pDevice->pMgmt->sNodeDBTable[uNodeIndex].wTxDataRate;
}
if (pDevice->wCurrentRate <= RATE_11M)
byPktType = PK_TYPE_11B;
vGenerateFIFOHeader(pDevice, byPktType, pDevice->pbyTmpBuff,
bNeedEncryption, cbFrameBodySize, TYPE_AC0DMA,
pHeadTD, &pDevice->sTxEthHeader, pbySkbData,
pTransmitKey, uNodeIndex, &uMACfragNum,
&cbHeaderSize);
if (MACbIsRegBitsOn(pDevice->PortOffset, MAC_REG_PSCTL, PSCTL_PS)) {
MACbPSWakeup(pDevice->PortOffset);
}
pDevice->bPWBitOn = false;
pLastTD = pHeadTD;
for (ii = 0; ii < uMACfragNum; ii++) {
wmb();
pHeadTD->m_td0TD0.f1Owner = OWNED_BY_NIC;
wmb();
if (ii == (uMACfragNum - 1))
pLastTD = pHeadTD;
pHeadTD = pHeadTD->next;
}
pLastTD->pTDInfo->skb = NULL;
pLastTD->pTDInfo->byFlags = 0;
pDevice->apCurrTD[TYPE_AC0DMA] = pHeadTD;
MACvTransmitAC0(pDevice->PortOffset);
return true;
}
