void
s_vResetCounter(
PKnownNodeDB psNodeDBTable
)
{
unsigned char ii;
for (ii = 0; ii <= MAX_RATE; ii++) {
psNodeDBTable->uTxOk[ii] = 0;
psNodeDBTable->uTxFail[ii] = 0;
}
}
unsigned char
DATARATEbyGetRateIdx(
unsigned char byRate
)
{
unsigned char ii;
byRate = byRate & 0x7F;
for (ii = 0; ii < MAX_RATE; ii++) {
if (acbyIERate[ii] == byRate)
return ii;
}
return 0;
}
unsigned short
wGetRateIdx(
unsigned char byRate
)
{
unsigned short ii;
byRate = byRate & 0x7F;
for (ii = 0; ii < MAX_RATE; ii++) {
if (acbyIERate[ii] == byRate)
return ii;
}
return 0;
}
void
RATEvParseMaxRate(
void *pDeviceHandler,
PWLAN_IE_SUPP_RATES pItemRates,
PWLAN_IE_SUPP_RATES pItemExtRates,
bool bUpdateBasicRate,
unsigned short *pwMaxBasicRate,
unsigned short *pwMaxSuppRate,
unsigned short *pwSuppRate,
unsigned char *pbyTopCCKRate,
unsigned char *pbyTopOFDMRate
)
{
PSDevice pDevice = (PSDevice) pDeviceHandler;
unsigned int ii;
unsigned char byHighSuppRate = 0;
unsigned char byRate = 0;
unsigned short wOldBasicRate = pDevice->wBasicRate;
unsigned int uRateLen;
if (pItemRates == NULL)
return;
*pwSuppRate = 0;
uRateLen = pItemRates->len;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "ParseMaxRate Len: %d\n", uRateLen);
if (pDevice->eCurrentPHYType != PHY_TYPE_11B) {
if (uRateLen > WLAN_RATES_MAXLEN)
uRateLen = WLAN_RATES_MAXLEN;
} else {
if (uRateLen > WLAN_RATES_MAXLEN_11B)
uRateLen = WLAN_RATES_MAXLEN_11B;
}
for (ii = 0; ii < uRateLen; ii++) {
byRate = (unsigned char)(pItemRates->abyRates[ii]);
if (WLAN_MGMT_IS_BASICRATE(byRate) && bUpdateBasicRate) {
CARDbAddBasicRate((void *)pDevice, wGetRateIdx(byRate));
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "ParseMaxRate AddBasicRate: %d\n", wGetRateIdx(byRate));
}
byRate = (unsigned char)(pItemRates->abyRates[ii]&0x7F);
if (byHighSuppRate == 0)
byHighSuppRate = byRate;
if (byRate > byHighSuppRate)
byHighSuppRate = byRate;
*pwSuppRate |= (1<<wGetRateIdx(byRate));
}
if ((pItemExtRates != NULL) && (pItemExtRates->byElementID == WLAN_EID_EXTSUPP_RATES) &&
(pDevice->eCurrentPHYType != PHY_TYPE_11B)) {
unsigned int uExtRateLen = pItemExtRates->len;
if (uExtRateLen > WLAN_RATES_MAXLEN)
uExtRateLen = WLAN_RATES_MAXLEN;
for (ii = 0; ii < uExtRateLen; ii++) {
byRate = (unsigned char)(pItemExtRates->abyRates[ii]);
if (WLAN_MGMT_IS_BASICRATE(pItemExtRates->abyRates[ii])) {
CARDbAddBasicRate((void *)pDevice, wGetRateIdx(byRate));
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "ParseMaxRate AddBasicRate: %d\n", wGetRateIdx(byRate));
}
byRate = (unsigned char)(pItemExtRates->abyRates[ii]&0x7F);
if (byHighSuppRate == 0)
byHighSuppRate = byRate;
if (byRate > byHighSuppRate)
byHighSuppRate = byRate;
*pwSuppRate |= (1<<wGetRateIdx(byRate));
}
}
if ((pDevice->byPacketType == PK_TYPE_11GB) && CARDbIsOFDMinBasicRate((void *)pDevice))
pDevice->byPacketType = PK_TYPE_11GA;
*pbyTopCCKRate = pDevice->byTopCCKBasicRate;
*pbyTopOFDMRate = pDevice->byTopOFDMBasicRate;
*pwMaxSuppRate = wGetRateIdx(byHighSuppRate);
if ((pDevice->byPacketType == PK_TYPE_11B) || (pDevice->byPacketType == PK_TYPE_11GB))
*pwMaxBasicRate = pDevice->byTopCCKBasicRate;
else
*pwMaxBasicRate = pDevice->byTopOFDMBasicRate;
if (wOldBasicRate != pDevice->wBasicRate)
CARDvSetRSPINF((void *)pDevice, pDevice->eCurrentPHYType);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Exit ParseMaxRate\n");
}
void
RATEvTxRateFallBack(
void *pDeviceHandler,
PKnownNodeDB psNodeDBTable
)
{
PSDevice pDevice = (PSDevice) pDeviceHandler;
unsigned short wIdxDownRate = 0;
unsigned int ii;
bool bAutoRate[MAX_RATE] = {true, true, true, true, false, false, true, true, true, true, true, true};
unsigned long dwThroughputTbl[MAX_RATE] = {10, 20, 55, 110, 60, 90, 120, 180, 240, 360, 480, 540};
unsigned long dwThroughput = 0;
unsigned short wIdxUpRate = 0;
unsigned long dwTxDiff = 0;
if (pDevice->pMgmt->eScanState != WMAC_NO_SCANNING)
return;
psNodeDBTable->uTimeCount++;
if (psNodeDBTable->uTxFail[MAX_RATE] > psNodeDBTable->uTxOk[MAX_RATE])
dwTxDiff = psNodeDBTable->uTxFail[MAX_RATE] - psNodeDBTable->uTxOk[MAX_RATE];
if ((psNodeDBTable->uTxOk[MAX_RATE] < AUTORATE_TXOK_CNT) &&
(dwTxDiff < AUTORATE_TXFAIL_CNT) &&
(psNodeDBTable->uTimeCount < AUTORATE_TIMEOUT)) {
return;
}
if (psNodeDBTable->uTimeCount >= AUTORATE_TIMEOUT)
psNodeDBTable->uTimeCount = 0;
for (ii = 0; ii < MAX_RATE; ii++) {
if (psNodeDBTable->wSuppRate & (0x0001<<ii)) {
if (bAutoRate[ii])
wIdxUpRate = (unsigned short) ii;
} else {
bAutoRate[ii] = false;
}
}
for (ii = 0; ii <= psNodeDBTable->wTxDataRate; ii++) {
if ((psNodeDBTable->uTxOk[ii] != 0) ||
(psNodeDBTable->uTxFail[ii] != 0)) {
dwThroughputTbl[ii] *= psNodeDBTable->uTxOk[ii];
if (ii < RATE_11M)
psNodeDBTable->uTxFail[ii] *= 4;
dwThroughputTbl[ii] /= (psNodeDBTable->uTxOk[ii] + psNodeDBTable->uTxFail[ii]);
}
}
dwThroughput = dwThroughputTbl[psNodeDBTable->wTxDataRate];
wIdxDownRate = psNodeDBTable->wTxDataRate;
for (ii = psNodeDBTable->wTxDataRate; ii > 0;) {
ii--;
if ((dwThroughputTbl[ii] > dwThroughput) && bAutoRate[ii]) {
dwThroughput = dwThroughputTbl[ii];
wIdxDownRate = (unsigned short) ii;
}
}
psNodeDBTable->wTxDataRate = wIdxDownRate;
if (psNodeDBTable->uTxOk[MAX_RATE]) {
if (psNodeDBTable->uTxOk[MAX_RATE] >
(psNodeDBTable->uTxFail[MAX_RATE] * 4)) {
psNodeDBTable->wTxDataRate = wIdxUpRate;
}
} else {
if (psNodeDBTable->uTxFail[MAX_RATE] == 0)
psNodeDBTable->wTxDataRate = wIdxUpRate;
}
TxRate_iwconfig = psNodeDBTable->wTxDataRate;
s_vResetCounter(psNodeDBTable);
}
unsigned char
RATEuSetIE(
PWLAN_IE_SUPP_RATES pSrcRates,
PWLAN_IE_SUPP_RATES pDstRates,
unsigned int uRateLen
)
{
unsigned int ii, uu, uRateCnt = 0;
if ((pSrcRates == NULL) || (pDstRates == NULL))
return 0;
if (pSrcRates->len == 0)
return 0;
for (ii = 0; ii < uRateLen; ii++) {
for (uu = 0; uu < pSrcRates->len; uu++) {
if ((pSrcRates->abyRates[uu] & 0x7F) == acbyIERate[ii]) {
pDstRates->abyRates[uRateCnt++] = pSrcRates->abyRates[uu];
break;
}
}
}
return (unsigned char)uRateCnt;
}
