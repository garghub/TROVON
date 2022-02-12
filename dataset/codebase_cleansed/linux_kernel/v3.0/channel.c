BOOL
ChannelValid(unsigned int CountryCode, unsigned int ChannelIndex)
{
BOOL bValid;
bValid = FALSE;
if ((ChannelIndex > CB_MAX_CHANNEL) ||
(ChannelIndex == 0))
{
bValid = FALSE;
goto exit;
}
bValid = sChannelTbl[ChannelIndex].bValid;
exit:
return (bValid);
}
BOOL
CHvChannelGetList (
unsigned int uCountryCodeIdx,
PBYTE pbyChannelTable
)
{
if (uCountryCodeIdx >= CCODE_MAX) {
return (FALSE);
}
memcpy(pbyChannelTable, ChannelRuleTab[uCountryCodeIdx].bChannelIdxList, CB_MAX_CHANNEL);
return (TRUE);
}
void CHvInitChannelTable(void *pDeviceHandler)
{
PSDevice pDevice = (PSDevice) pDeviceHandler;
BOOL bMultiBand = FALSE;
unsigned int ii;
for (ii = 1; ii <= CB_MAX_CHANNEL; ii++)
sChannelTbl[ii].bValid = FALSE;
switch (pDevice->byRFType) {
case RF_AL2230:
case RF_AL2230S:
case RF_VT3226:
case RF_VT3226D0:
bMultiBand = FALSE;
break;
case RF_AIROHA7230:
case RF_VT3342A0:
default :
bMultiBand = TRUE;
break;
}
if ((pDevice->dwDiagRefCount != 0) ||
(pDevice->b11hEable == TRUE)) {
if (bMultiBand == TRUE) {
for (ii = 0; ii < CB_MAX_CHANNEL; ii++) {
sChannelTbl[ii+1].bValid = TRUE;
}
for (ii = 0; ii < CB_MAX_CHANNEL_24G; ii++) {
}
} else {
for (ii = 0; ii < CB_MAX_CHANNEL_24G; ii++) {
sChannelTbl[ii+1].bValid = TRUE;
}
}
} else if (pDevice->byZoneType <= CCODE_MAX) {
if (bMultiBand == TRUE) {
for (ii = 0; ii < CB_MAX_CHANNEL; ii++) {
if (ChannelRuleTab[pDevice->byZoneType].bChannelIdxList[ii] != 0) {
sChannelTbl[ii+1].bValid = TRUE;
}
}
} else {
for (ii = 0; ii < CB_MAX_CHANNEL_24G; ii++) {
if (ChannelRuleTab[pDevice->byZoneType].bChannelIdxList[ii] != 0) {
sChannelTbl[ii+1].bValid = TRUE;
}
}
}
}
DBG_PRT(MSG_LEVEL_NOTICE, KERN_INFO"Zone=[%d][%c][%c]!!\n",pDevice->byZoneType,ChannelRuleTab[pDevice->byZoneType].chCountryCode[0],ChannelRuleTab[pDevice->byZoneType].chCountryCode[1]);
for (ii = 0; ii < CB_MAX_CHANNEL; ii++) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Channel[%d] is [%d]\n",sChannelTbl[ii].byChannelNumber,sChannelTbl[ii+1].bValid);
}
}
BYTE CHbyGetChannelMapping(BYTE byChannelNumber)
{
BYTE ii;
BYTE byCHMapping = 0;
for (ii = 1; ii <= CB_MAX_CHANNEL; ii++) {
if (sChannelTbl[ii].byChannelNumber == byChannelNumber)
byCHMapping = ii;
}
return byCHMapping;
}
