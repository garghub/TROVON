static INLINE void ReduceCredits(struct common_credit_state_info *pCredInfo,
struct htc_endpoint_credit_dist *pEpDist,
int Limit)
{
int credits;
pEpDist->TxCreditsAssigned = Limit;
if (pEpDist->TxCredits <= Limit) {
return;
}
credits = pEpDist->TxCredits - Limit;
pEpDist->TxCredits -= credits;
pCredInfo->CurrentFreeCredits += credits;
}
static void ar6000_credit_init(void *Context,
struct htc_endpoint_credit_dist *pEPList,
int TotalCredits)
{
struct htc_endpoint_credit_dist *pCurEpDist;
int count;
struct common_credit_state_info *pCredInfo = (struct common_credit_state_info *)Context;
pCredInfo->CurrentFreeCredits = TotalCredits;
pCredInfo->TotalAvailableCredits = TotalCredits;
pCurEpDist = pEPList;
while (pCurEpDist != NULL) {
pCurEpDist->TxCreditsMin = pCurEpDist->TxCreditsPerMaxMsg;
#ifdef CONFIG_GIVE_LOW_PRIORITY_STREAMS_MIN_CREDITS
if (TotalCredits > 4)
{
if ((pCurEpDist->ServiceID == WMI_DATA_BK_SVC) || (pCurEpDist->ServiceID == WMI_DATA_BE_SVC)){
GiveCredits(pCredInfo,pCurEpDist,pCurEpDist->TxCreditsMin);
SET_EP_ACTIVE(pCurEpDist);
}
}
#endif
if (pCurEpDist->ServiceID == WMI_CONTROL_SVC) {
GiveCredits(pCredInfo,pCurEpDist,pCurEpDist->TxCreditsMin);
SET_EP_ACTIVE(pCurEpDist);
} else if (pCurEpDist->ServiceID == WMI_DATA_BK_SVC) {
pCredInfo->pLowestPriEpDist = pCurEpDist;
}
pCurEpDist = pCurEpDist->pNext;
}
if (pCredInfo->CurrentFreeCredits <= 0) {
AR_DEBUG_PRINTF(ATH_LOG_INF, ("Not enough credits (%d) to do credit distributions \n", TotalCredits));
A_ASSERT(false);
return;
}
pCurEpDist = pEPList;
while (pCurEpDist != NULL) {
if (pCurEpDist->ServiceID == WMI_CONTROL_SVC) {
pCurEpDist->TxCreditsNorm = pCurEpDist->TxCreditsPerMaxMsg;
} else {
count = (pCredInfo->CurrentFreeCredits/pCurEpDist->TxCreditsPerMaxMsg) * pCurEpDist->TxCreditsPerMaxMsg;
count = (count * 3) >> 2;
count = max(count,pCurEpDist->TxCreditsPerMaxMsg);
pCurEpDist->TxCreditsNorm = count;
}
pCurEpDist = pCurEpDist->pNext;
}
}
static void ar6000_credit_distribute(void *Context,
struct htc_endpoint_credit_dist *pEPDistList,
HTC_CREDIT_DIST_REASON Reason)
{
struct htc_endpoint_credit_dist *pCurEpDist;
struct common_credit_state_info *pCredInfo = (struct common_credit_state_info *)Context;
switch (Reason) {
case HTC_CREDIT_DIST_SEND_COMPLETE :
pCurEpDist = pEPDistList;
while (pCurEpDist != NULL) {
if (pCurEpDist->TxCreditsToDist > 0) {
pCurEpDist->TxCredits += pCurEpDist->TxCreditsToDist;
pCurEpDist->TxCreditsToDist = 0;
if (pCurEpDist->TxCredits > pCurEpDist->TxCreditsAssigned) {
ReduceCredits(pCredInfo, pCurEpDist, pCurEpDist->TxCreditsAssigned);
}
if (pCurEpDist->TxCredits > pCurEpDist->TxCreditsNorm) {
ReduceCredits(pCredInfo, pCurEpDist, pCurEpDist->TxCreditsNorm);
}
if (!IS_EP_ACTIVE(pCurEpDist)) {
if (pCurEpDist->TxQueueDepth == 0) {
ReduceCredits(pCredInfo, pCurEpDist, 0);
}
}
}
pCurEpDist = pCurEpDist->pNext;
}
break;
case HTC_CREDIT_DIST_ACTIVITY_CHANGE :
RedistributeCredits(pCredInfo,pEPDistList);
break;
case HTC_CREDIT_DIST_SEEK_CREDITS :
SeekCredits(pCredInfo,pEPDistList);
break;
case HTC_DUMP_CREDIT_STATE :
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("Credit Distribution, total : %d, free : %d\n",
pCredInfo->TotalAvailableCredits, pCredInfo->CurrentFreeCredits));
break;
default:
break;
}
A_ASSERT(pCredInfo->CurrentFreeCredits <= pCredInfo->TotalAvailableCredits);
A_ASSERT(pCredInfo->CurrentFreeCredits >= 0);
}
static void RedistributeCredits(struct common_credit_state_info *pCredInfo,
struct htc_endpoint_credit_dist *pEPDistList)
{
struct htc_endpoint_credit_dist *pCurEpDist = pEPDistList;
while (pCurEpDist != NULL) {
#ifdef CONFIG_GIVE_LOW_PRIORITY_STREAMS_MIN_CREDITS
if ((pCurEpDist->ServiceID == WMI_DATA_BK_SVC) || (pCurEpDist->ServiceID == WMI_DATA_BE_SVC)) {
SET_EP_ACTIVE(pCurEpDist);
}
#endif
if (pCurEpDist->ServiceID != WMI_CONTROL_SVC) {
if (!IS_EP_ACTIVE(pCurEpDist)) {
if (pCurEpDist->TxQueueDepth == 0) {
ReduceCredits(pCredInfo, pCurEpDist, 0);
} else {
ReduceCredits(pCredInfo, pCurEpDist, pCurEpDist->TxCreditsMin);
}
}
}
pCurEpDist = pCurEpDist->pNext;
}
}
static void SeekCredits(struct common_credit_state_info *pCredInfo,
struct htc_endpoint_credit_dist *pEPDist)
{
struct htc_endpoint_credit_dist *pCurEpDist;
int credits = 0;
int need;
do {
if (pEPDist->ServiceID == WMI_CONTROL_SVC) {
break;
}
#ifdef CONFIG_GIVE_LOW_PRIORITY_STREAMS_MIN_CREDITS
if (pEPDist->ServiceID == WMI_DATA_VI_SVC) {
if ((pEPDist->TxCreditsAssigned >= pEPDist->TxCreditsNorm)) {
break;
}
}
if (pEPDist->ServiceID == WMI_DATA_VO_SVC) {
if ((pEPDist->TxCreditsAssigned >= pEPDist->TxCreditsNorm)) {
break;
}
}
#else
if (pEPDist->ServiceID == WMI_DATA_VI_SVC) {
if ((pEPDist->TxCreditsAssigned >= pEPDist->TxCreditsNorm) ||
(pCredInfo->CurrentFreeCredits <= pEPDist->TxCreditsPerMaxMsg)) {
break;
}
}
if (pEPDist->ServiceID == WMI_DATA_VO_SVC) {
if ((pEPDist->TxCreditsAssigned >= pEPDist->TxCreditsNorm) ||
(pCredInfo->CurrentFreeCredits <= pEPDist->TxCreditsPerMaxMsg)) {
break;
}
}
#endif
credits = min(pCredInfo->CurrentFreeCredits,pEPDist->TxCreditsSeek);
if (credits >= pEPDist->TxCreditsSeek) {
break;
}
pCurEpDist = pCredInfo->pLowestPriEpDist;
while (pCurEpDist != pEPDist) {
need = pEPDist->TxCreditsSeek - pCredInfo->CurrentFreeCredits;
if ((pCurEpDist->TxCreditsAssigned - need) >= pCurEpDist->TxCreditsMin) {
ReduceCredits(pCredInfo,
pCurEpDist,
pCurEpDist->TxCreditsAssigned - need);
if (pCredInfo->CurrentFreeCredits >= pEPDist->TxCreditsSeek) {
break;
}
}
pCurEpDist = pCurEpDist->pPrev;
}
credits = min(pCredInfo->CurrentFreeCredits,pEPDist->TxCreditsSeek);
} while (false);
if (credits) {
GiveCredits(pCredInfo, pEPDist, credits);
}
}
int ar6000_setup_credit_dist(HTC_HANDLE HTCHandle, struct common_credit_state_info *pCredInfo)
{
HTC_SERVICE_ID servicepriority[5];
A_MEMZERO(pCredInfo,sizeof(struct common_credit_state_info));
servicepriority[0] = WMI_CONTROL_SVC;
servicepriority[1] = WMI_DATA_VO_SVC;
servicepriority[2] = WMI_DATA_VI_SVC;
servicepriority[3] = WMI_DATA_BE_SVC;
servicepriority[4] = WMI_DATA_BK_SVC;
HTCSetCreditDistribution(HTCHandle,
pCredInfo,
ar6000_credit_distribute,
ar6000_credit_init,
servicepriority,
5);
return 0;
}
