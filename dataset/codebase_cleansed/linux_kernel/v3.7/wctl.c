BOOL WCTLbIsDuplicate (PSCache pCache, PS802_11Header pMACHeader)
{
unsigned int uIndex;
unsigned int ii;
PSCacheEntry pCacheEntry;
if (IS_FC_RETRY(pMACHeader)) {
uIndex = pCache->uInPtr;
for (ii = 0; ii < DUPLICATE_RX_CACHE_LENGTH; ii++) {
pCacheEntry = &(pCache->asCacheEntry[uIndex]);
if ((pCacheEntry->wFmSequence == pMACHeader->wSeqCtl) &&
(!compare_ether_addr(&(pCacheEntry->abyAddr2[0]),
&(pMACHeader->abyAddr2[0]))) &&
(LOBYTE(pCacheEntry->wFrameCtl) == LOBYTE(pMACHeader->wFrameCtl))
) {
return TRUE;
}
ADD_ONE_WITH_WRAP_AROUND(uIndex, DUPLICATE_RX_CACHE_LENGTH);
}
}
pCacheEntry = &pCache->asCacheEntry[pCache->uInPtr];
pCacheEntry->wFmSequence = pMACHeader->wSeqCtl;
memcpy(&(pCacheEntry->abyAddr2[0]), &(pMACHeader->abyAddr2[0]), ETH_ALEN);
pCacheEntry->wFrameCtl = pMACHeader->wFrameCtl;
ADD_ONE_WITH_WRAP_AROUND(pCache->uInPtr, DUPLICATE_RX_CACHE_LENGTH);
return FALSE;
}
unsigned int WCTLuSearchDFCB(PSDevice pDevice, PS802_11Header pMACHeader)
{
unsigned int ii;
for (ii = 0; ii < pDevice->cbDFCB; ii++) {
if ((pDevice->sRxDFCB[ii].bInUse == TRUE) &&
(!compare_ether_addr(&(pDevice->sRxDFCB[ii].abyAddr2[0]),
&(pMACHeader->abyAddr2[0])))) {
return ii;
}
}
return pDevice->cbDFCB;
}
unsigned int WCTLuInsertDFCB(PSDevice pDevice, PS802_11Header pMACHeader)
{
unsigned int ii;
if (pDevice->cbFreeDFCB == 0)
return(pDevice->cbDFCB);
for (ii = 0; ii < pDevice->cbDFCB; ii++) {
if (pDevice->sRxDFCB[ii].bInUse == FALSE) {
pDevice->cbFreeDFCB--;
pDevice->sRxDFCB[ii].uLifetime = pDevice->dwMaxReceiveLifetime;
pDevice->sRxDFCB[ii].bInUse = TRUE;
pDevice->sRxDFCB[ii].wSequence = (pMACHeader->wSeqCtl >> 4);
pDevice->sRxDFCB[ii].wFragNum = (pMACHeader->wSeqCtl & 0x000F);
memcpy(&(pDevice->sRxDFCB[ii].abyAddr2[0]),
&(pMACHeader->abyAddr2[0]),
ETH_ALEN);
return(ii);
}
}
return(pDevice->cbDFCB);
}
BOOL WCTLbHandleFragment(PSDevice pDevice, PS802_11Header pMACHeader,
unsigned int cbFrameLength, BOOL bWEP, BOOL bExtIV)
{
unsigned int uHeaderSize;
if (bWEP == TRUE) {
uHeaderSize = 28;
if (bExtIV)
uHeaderSize +=4;
}
else {
uHeaderSize = 24;
}
if (IS_FIRST_FRAGMENT_PKT(pMACHeader)) {
pDevice->uCurrentDFCBIdx = WCTLuSearchDFCB(pDevice, pMACHeader);
if (pDevice->uCurrentDFCBIdx < pDevice->cbDFCB) {
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].uLifetime = pDevice->dwMaxReceiveLifetime;
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].wSequence = (pMACHeader->wSeqCtl >> 4);
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].wFragNum = (pMACHeader->wSeqCtl & 0x000F);
}
else {
pDevice->uCurrentDFCBIdx = WCTLuInsertDFCB(pDevice, pMACHeader);
if (pDevice->uCurrentDFCBIdx == pDevice->cbDFCB) {
return(FALSE);
}
}
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].pbyRxBuffer = (PBYTE) (pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].skb->data + 8);
memcpy(pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].pbyRxBuffer, pMACHeader, cbFrameLength);
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].cbFrameLength = cbFrameLength;
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].pbyRxBuffer += cbFrameLength;
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].wFragNum++;
return(FALSE);
}
else {
pDevice->uCurrentDFCBIdx = WCTLuSearchDFCB(pDevice, pMACHeader);
if (pDevice->uCurrentDFCBIdx != pDevice->cbDFCB) {
if ((pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].wSequence == (pMACHeader->wSeqCtl >> 4)) &&
(pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].wFragNum == (pMACHeader->wSeqCtl & 0x000F)) &&
((pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].cbFrameLength + cbFrameLength - uHeaderSize) < 2346)) {
memcpy(pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].pbyRxBuffer, ((PBYTE) (pMACHeader) + uHeaderSize), (cbFrameLength - uHeaderSize));
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].cbFrameLength += (cbFrameLength - uHeaderSize);
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].pbyRxBuffer += (cbFrameLength - uHeaderSize);
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].wFragNum++;
}
else {
pDevice->cbFreeDFCB++;
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].bInUse = FALSE;
return(FALSE);
}
}
else {
return(FALSE);
}
if (IS_LAST_FRAGMENT_PKT(pMACHeader)) {
pDevice->cbFreeDFCB++;
pDevice->sRxDFCB[pDevice->uCurrentDFCBIdx].bInUse = FALSE;
return(TRUE);
}
return(FALSE);
}
}
