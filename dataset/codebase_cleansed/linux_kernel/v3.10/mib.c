void STAvUpdateIsrStatCounter (PSStatCounter pStatistic, u8 byIsr0, u8 byIsr1)
{
if (byIsr0 == 0) {
pStatistic->ISRStat.dwIsrUnknown++;
return;
}
if (byIsr0 & ISR_ACTX)
pStatistic->ISRStat.dwIsrTx0OK++;
if (byIsr0 & ISR_BNTX)
pStatistic->ISRStat.dwIsrBeaconTxOK++;
if (byIsr0 & ISR_RXDMA0)
pStatistic->ISRStat.dwIsrRx0OK++;
if (byIsr0 & ISR_TBTT)
pStatistic->ISRStat.dwIsrTBTTInt++;
if (byIsr0 & ISR_SOFTTIMER)
pStatistic->ISRStat.dwIsrSTIMERInt++;
if (byIsr0 & ISR_WATCHDOG)
pStatistic->ISRStat.dwIsrWatchDog++;
if (byIsr1 & ISR_FETALERR)
pStatistic->ISRStat.dwIsrUnrecoverableError++;
if (byIsr1 & ISR_SOFTINT)
pStatistic->ISRStat.dwIsrSoftInterrupt++;
if (byIsr1 & ISR_MIBNEARFULL)
pStatistic->ISRStat.dwIsrMIBNearfull++;
if (byIsr1 & ISR_RXNOBUF)
pStatistic->ISRStat.dwIsrRxNoBuf++;
}
void STAvUpdateRDStatCounter(PSStatCounter pStatistic,
u8 byRSR, u8 byNewRSR,
u8 byRxSts, u8 byRxRate,
u8 * pbyBuffer, unsigned int cbFrameLength)
{
struct ieee80211_hdr *pHeader = (struct ieee80211_hdr *)pbyBuffer;
if (byRSR & RSR_ADDROK)
pStatistic->dwRsrADDROk++;
if (byRSR & RSR_CRCOK) {
pStatistic->dwRsrCRCOk++;
pStatistic->ullRsrOK++;
if (cbFrameLength >= ETH_ALEN) {
if (byRSR & RSR_ADDRBROAD) {
pStatistic->ullRxBroadcastFrames++;
pStatistic->ullRxBroadcastBytes +=
(unsigned long long) cbFrameLength;
}
else if (byRSR & RSR_ADDRMULTI) {
pStatistic->ullRxMulticastFrames++;
pStatistic->ullRxMulticastBytes +=
(unsigned long long) cbFrameLength;
}
else {
pStatistic->ullRxDirectedFrames++;
pStatistic->ullRxDirectedBytes +=
(unsigned long long) cbFrameLength;
}
}
}
if(byRxRate==22) {
pStatistic->CustomStat.ullRsr11M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr11MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "11M: ALL[%d], OK[%d]:[%02x]\n",
(signed int) pStatistic->CustomStat.ullRsr11M,
(signed int) pStatistic->CustomStat.ullRsr11MCRCOk, byRSR);
}
else if(byRxRate==11) {
pStatistic->CustomStat.ullRsr5M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr5MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " 5M: ALL[%d], OK[%d]:[%02x]\n",
(signed int) pStatistic->CustomStat.ullRsr5M,
(signed int) pStatistic->CustomStat.ullRsr5MCRCOk, byRSR);
}
else if(byRxRate==4) {
pStatistic->CustomStat.ullRsr2M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr2MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " 2M: ALL[%d], OK[%d]:[%02x]\n",
(signed int) pStatistic->CustomStat.ullRsr2M,
(signed int) pStatistic->CustomStat.ullRsr2MCRCOk, byRSR);
}
else if(byRxRate==2){
pStatistic->CustomStat.ullRsr1M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr1MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " 1M: ALL[%d], OK[%d]:[%02x]\n",
(signed int) pStatistic->CustomStat.ullRsr1M,
(signed int) pStatistic->CustomStat.ullRsr1MCRCOk, byRSR);
}
else if(byRxRate==12){
pStatistic->CustomStat.ullRsr6M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr6MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " 6M: ALL[%d], OK[%d]\n",
(signed int) pStatistic->CustomStat.ullRsr6M,
(signed int) pStatistic->CustomStat.ullRsr6MCRCOk);
}
else if(byRxRate==18){
pStatistic->CustomStat.ullRsr9M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr9MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " 9M: ALL[%d], OK[%d]\n",
(signed int) pStatistic->CustomStat.ullRsr9M,
(signed int) pStatistic->CustomStat.ullRsr9MCRCOk);
}
else if(byRxRate==24){
pStatistic->CustomStat.ullRsr12M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr12MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "12M: ALL[%d], OK[%d]\n",
(signed int) pStatistic->CustomStat.ullRsr12M,
(signed int) pStatistic->CustomStat.ullRsr12MCRCOk);
}
else if(byRxRate==36){
pStatistic->CustomStat.ullRsr18M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr18MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "18M: ALL[%d], OK[%d]\n",
(signed int) pStatistic->CustomStat.ullRsr18M,
(signed int) pStatistic->CustomStat.ullRsr18MCRCOk);
}
else if(byRxRate==48){
pStatistic->CustomStat.ullRsr24M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr24MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "24M: ALL[%d], OK[%d]\n",
(signed int) pStatistic->CustomStat.ullRsr24M,
(signed int) pStatistic->CustomStat.ullRsr24MCRCOk);
}
else if(byRxRate==72){
pStatistic->CustomStat.ullRsr36M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr36MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "36M: ALL[%d], OK[%d]\n",
(signed int) pStatistic->CustomStat.ullRsr36M,
(signed int) pStatistic->CustomStat.ullRsr36MCRCOk);
}
else if(byRxRate==96){
pStatistic->CustomStat.ullRsr48M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr48MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "48M: ALL[%d], OK[%d]\n",
(signed int) pStatistic->CustomStat.ullRsr48M,
(signed int) pStatistic->CustomStat.ullRsr48MCRCOk);
}
else if(byRxRate==108){
pStatistic->CustomStat.ullRsr54M++;
if(byRSR & RSR_CRCOK) {
pStatistic->CustomStat.ullRsr54MCRCOk++;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "54M: ALL[%d], OK[%d]\n",
(signed int) pStatistic->CustomStat.ullRsr54M,
(signed int) pStatistic->CustomStat.ullRsr54MCRCOk);
}
else {
DBG_PRT(MSG_LEVEL_DEBUG,
KERN_INFO "Unknown: Total[%d], CRCOK[%d]\n",
(signed int) pStatistic->dwRsrRxPacket+1,
(signed int)pStatistic->dwRsrCRCOk);
}
if (byRSR & RSR_BSSIDOK)
pStatistic->dwRsrBSSIDOk++;
if (byRSR & RSR_BCNSSIDOK)
pStatistic->dwRsrBCNSSIDOk++;
if (byRSR & RSR_IVLDLEN)
pStatistic->dwRsrLENErr++;
if (byRSR & RSR_IVLDTYP)
pStatistic->dwRsrTYPErr++;
if ((byRSR & (RSR_IVLDTYP | RSR_IVLDLEN)) || !(byRSR & RSR_CRCOK))
pStatistic->dwRsrErr++;
if (byNewRSR & NEWRSR_DECRYPTOK)
pStatistic->dwNewRsrDECRYPTOK++;
if (byNewRSR & NEWRSR_CFPIND)
pStatistic->dwNewRsrCFP++;
if (byNewRSR & NEWRSR_HWUTSF)
pStatistic->dwNewRsrUTSF++;
if (byNewRSR & NEWRSR_BCNHITAID)
pStatistic->dwNewRsrHITAID++;
if (byNewRSR & NEWRSR_BCNHITAID0)
pStatistic->dwNewRsrHITAID0++;
pStatistic->dwRsrRxPacket++;
pStatistic->dwRsrRxOctet += cbFrameLength;
if (IS_TYPE_DATA(pbyBuffer)) {
pStatistic->dwRsrRxData++;
} else if (IS_TYPE_MGMT(pbyBuffer)){
pStatistic->dwRsrRxManage++;
} else if (IS_TYPE_CONTROL(pbyBuffer)){
pStatistic->dwRsrRxControl++;
}
if (byRSR & RSR_ADDRBROAD)
pStatistic->dwRsrBroadcast++;
else if (byRSR & RSR_ADDRMULTI)
pStatistic->dwRsrMulticast++;
else
pStatistic->dwRsrDirected++;
if (WLAN_GET_FC_MOREFRAG(pHeader->frame_control))
pStatistic->dwRsrRxFragment++;
if (cbFrameLength < ETH_ZLEN + 4) {
pStatistic->dwRsrRunt++;
} else if (cbFrameLength == ETH_ZLEN + 4) {
pStatistic->dwRsrRxFrmLen64++;
}
else if ((65 <= cbFrameLength) && (cbFrameLength <= 127)) {
pStatistic->dwRsrRxFrmLen65_127++;
}
else if ((128 <= cbFrameLength) && (cbFrameLength <= 255)) {
pStatistic->dwRsrRxFrmLen128_255++;
}
else if ((256 <= cbFrameLength) && (cbFrameLength <= 511)) {
pStatistic->dwRsrRxFrmLen256_511++;
}
else if ((512 <= cbFrameLength) && (cbFrameLength <= 1023)) {
pStatistic->dwRsrRxFrmLen512_1023++;
} else if ((1024 <= cbFrameLength) &&
(cbFrameLength <= ETH_FRAME_LEN + 4)) {
pStatistic->dwRsrRxFrmLen1024_1518++;
} else if (cbFrameLength > ETH_FRAME_LEN + 4) {
pStatistic->dwRsrLong++;
}
}
void
STAvUpdateTDStatCounter (
PSStatCounter pStatistic,
u8 byPktNum,
u8 byRate,
u8 byTSR
)
{
u8 byRetyCnt;
pStatistic->dwTsrTxPacket++;
byRetyCnt = (byTSR & 0xF0) >> 4;
if (byRetyCnt != 0) {
pStatistic->dwTsrRetry++;
pStatistic->dwTsrTotalRetry += byRetyCnt;
pStatistic->dwTxFail[byRate]+= byRetyCnt;
pStatistic->dwTxFail[MAX_RATE] += byRetyCnt;
if ( byRetyCnt == 0x1)
pStatistic->dwTsrOnceRetry++;
else
pStatistic->dwTsrMoreThanOnceRetry++;
if (byRetyCnt <= 8)
pStatistic->dwTxRetryCount[byRetyCnt-1]++;
}
if ( !(byTSR & (TSR_TMO | TSR_RETRYTMO))) {
if (byRetyCnt < 2)
pStatistic->TxNoRetryOkCount ++;
else
pStatistic->TxRetryOkCount ++;
pStatistic->ullTsrOK++;
pStatistic->CustomStat.ullTsrAllOK++;
pStatistic->dwTxOk[byRate]++;
pStatistic->dwTxOk[MAX_RATE]++;
if ( pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni == TX_PKT_BROAD ) {
pStatistic->ullTxBroadcastFrames++;
pStatistic->ullTxBroadcastBytes += pStatistic->abyTxPktInfo[byPktNum].wLength;
} else if ( pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni == TX_PKT_MULTI ) {
pStatistic->ullTxMulticastFrames++;
pStatistic->ullTxMulticastBytes += pStatistic->abyTxPktInfo[byPktNum].wLength;
} else if ( pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni == TX_PKT_UNI ) {
pStatistic->ullTxDirectedFrames++;
pStatistic->ullTxDirectedBytes += pStatistic->abyTxPktInfo[byPktNum].wLength;
}
}
else {
pStatistic->TxFailCount ++;
pStatistic->dwTsrErr++;
if (byTSR & TSR_RETRYTMO)
pStatistic->dwTsrRetryTimeout++;
if (byTSR & TSR_TMO)
pStatistic->dwTsrTransmitTimeout++;
}
if ( pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni == TX_PKT_BROAD ) {
pStatistic->dwTsrBroadcast++;
} else if ( pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni == TX_PKT_MULTI ) {
pStatistic->dwTsrMulticast++;
} else if ( pStatistic->abyTxPktInfo[byPktNum].byBroadMultiUni == TX_PKT_UNI ) {
pStatistic->dwTsrDirected++;
}
}
void
STAvUpdate802_11Counter(
PSDot11Counters p802_11Counter,
PSStatCounter pStatistic,
u8 byRTSSuccess,
u8 byRTSFail,
u8 byACKFail,
u8 byFCSErr
)
{
p802_11Counter->MulticastTransmittedFrameCount =
(unsigned long long) (pStatistic->dwTsrBroadcast +
pStatistic->dwTsrMulticast);
p802_11Counter->FailedCount = (unsigned long long) (pStatistic->dwTsrErr);
p802_11Counter->RetryCount = (unsigned long long) (pStatistic->dwTsrRetry);
p802_11Counter->MultipleRetryCount =
(unsigned long long) (pStatistic->dwTsrMoreThanOnceRetry);
p802_11Counter->RTSSuccessCount += (unsigned long long) byRTSSuccess;
p802_11Counter->RTSFailureCount += (unsigned long long) byRTSFail;
p802_11Counter->ACKFailureCount += (unsigned long long) byACKFail;
p802_11Counter->FCSErrorCount += (unsigned long long) byFCSErr;
p802_11Counter->MulticastReceivedFrameCount =
(unsigned long long) (pStatistic->dwRsrBroadcast +
pStatistic->dwRsrMulticast);
}
void STAvUpdateUSBCounter(PSUSBCounter pUsbCounter, int ntStatus)
{
pUsbCounter->dwCrc++;
}
