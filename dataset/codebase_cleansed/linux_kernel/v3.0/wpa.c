void
WPA_ClearRSN(
PKnownBSS pBSSList
)
{
int ii;
pBSSList->byGKType = WPA_TKIP;
for (ii=0; ii < 4; ii ++)
pBSSList->abyPKType[ii] = WPA_TKIP;
pBSSList->wPKCount = 0;
for (ii=0; ii < 4; ii ++)
pBSSList->abyAuthType[ii] = WPA_AUTH_IEEE802_1X;
pBSSList->wAuthCount = 0;
pBSSList->byDefaultK_as_PK = 0;
pBSSList->byReplayIdx = 0;
pBSSList->sRSNCapObj.bRSNCapExist = FALSE;
pBSSList->sRSNCapObj.wRSNCap = 0;
pBSSList->bWPAValid = FALSE;
}
void
WPA_ParseRSN(
PKnownBSS pBSSList,
PWLAN_IE_RSN_EXT pRSN
)
{
PWLAN_IE_RSN_AUTH pIE_RSN_Auth = NULL;
int i, j, m, n = 0;
PBYTE pbyCaps;
WPA_ClearRSN(pBSSList);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"WPA_ParseRSN: [%d]\n", pRSN->len);
if ((pRSN->len >= 6)
&& (pRSN->byElementID == WLAN_EID_RSN_WPA) && !memcmp(pRSN->abyOUI, abyOUI01, 4)
&& (pRSN->wVersion == 1)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"Legal RSN\n");
if (pRSN->len >= 10)
{
if ( !memcmp(pRSN->abyMulticast, abyOUI01, 4))
pBSSList->byGKType = WPA_WEP40;
else if ( !memcmp(pRSN->abyMulticast, abyOUI02, 4))
pBSSList->byGKType = WPA_TKIP;
else if ( !memcmp(pRSN->abyMulticast, abyOUI03, 4))
pBSSList->byGKType = WPA_AESWRAP;
else if ( !memcmp(pRSN->abyMulticast, abyOUI04, 4))
pBSSList->byGKType = WPA_AESCCMP;
else if ( !memcmp(pRSN->abyMulticast, abyOUI05, 4))
pBSSList->byGKType = WPA_WEP104;
else
pBSSList->byGKType = WPA_NONE;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"byGKType: %x\n", pBSSList->byGKType);
}
if (pRSN->len >= 12)
{
j = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"wPKCount: %d, sizeof(pBSSList->abyPKType): %zu\n", pRSN->wPKCount, sizeof(pBSSList->abyPKType));
for (i = 0; (i < pRSN->wPKCount) &&
(j < sizeof(pBSSList->abyPKType)/sizeof(BYTE)); i++) {
if(pRSN->len >= 12+i*4+4) {
if ( !memcmp(pRSN->PKSList[i].abyOUI, abyOUI00, 4))
pBSSList->abyPKType[j++] = WPA_NONE;
else if ( !memcmp(pRSN->PKSList[i].abyOUI, abyOUI02, 4))
pBSSList->abyPKType[j++] = WPA_TKIP;
else if ( !memcmp(pRSN->PKSList[i].abyOUI, abyOUI03, 4))
pBSSList->abyPKType[j++] = WPA_AESWRAP;
else if ( !memcmp(pRSN->PKSList[i].abyOUI, abyOUI04, 4))
pBSSList->abyPKType[j++] = WPA_AESCCMP;
else
;
}
else
break;
}
pBSSList->wPKCount = (WORD)j;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"wPKCount: %d\n", pBSSList->wPKCount);
}
m = pRSN->wPKCount;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"m: %d\n", m);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"14+m*4: %d\n", 14+m*4);
if (pRSN->len >= 14+m*4) {
pIE_RSN_Auth = (PWLAN_IE_RSN_AUTH) pRSN->PKSList[m].abyOUI;
j = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"wAuthCount: %d, sizeof(pBSSList->abyAuthType): %zu\n",
pIE_RSN_Auth->wAuthCount, sizeof(pBSSList->abyAuthType));
for (i = 0; (i < pIE_RSN_Auth->wAuthCount) &&
(j < sizeof(pBSSList->abyAuthType)/sizeof(BYTE)); i++) {
if(pRSN->len >= 14+4+(m+i)*4) {
if ( !memcmp(pIE_RSN_Auth->AuthKSList[i].abyOUI, abyOUI01, 4))
pBSSList->abyAuthType[j++] = WPA_AUTH_IEEE802_1X;
else if ( !memcmp(pIE_RSN_Auth->AuthKSList[i].abyOUI, abyOUI02, 4))
pBSSList->abyAuthType[j++] = WPA_AUTH_PSK;
else
;
}
else
break;
}
if(j > 0)
pBSSList->wAuthCount = (WORD)j;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"wAuthCount: %d\n", pBSSList->wAuthCount);
}
if (pIE_RSN_Auth != NULL) {
n = pIE_RSN_Auth->wAuthCount;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"n: %d\n", n);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO"14+4+(m+n)*4: %d\n", 14+4+(m+n)*4);
if(pRSN->len+2 >= 14+4+(m+n)*4) {
pbyCaps = (PBYTE)pIE_RSN_Auth->AuthKSList[n].abyOUI;
pBSSList->byDefaultK_as_PK = (*pbyCaps) & WPA_GROUPFLAG;
pBSSList->byReplayIdx = 2 << ((*pbyCaps >> WPA_REPLAYBITSSHIFT) & WPA_REPLAYBITS);
pBSSList->sRSNCapObj.bRSNCapExist = TRUE;
pBSSList->sRSNCapObj.wRSNCap = *(PWORD)pbyCaps;
}
}
pBSSList->bWPAValid = TRUE;
}
}
BOOL
WPA_SearchRSN(
BYTE byCmd,
BYTE byEncrypt,
PKnownBSS pBSSList
)
{
int ii;
BYTE byPKType = WPA_NONE;
if (pBSSList->bWPAValid == FALSE)
return FALSE;
switch(byCmd) {
case 0:
if (byEncrypt != pBSSList->byGKType)
return FALSE;
if (pBSSList->wPKCount > 0) {
for (ii = 0; ii < pBSSList->wPKCount; ii ++) {
if (pBSSList->abyPKType[ii] == WPA_AESCCMP)
byPKType = WPA_AESCCMP;
else if ((pBSSList->abyPKType[ii] == WPA_TKIP) && (byPKType != WPA_AESCCMP))
byPKType = WPA_TKIP;
else if ((pBSSList->abyPKType[ii] == WPA_WEP40) && (byPKType != WPA_AESCCMP) && (byPKType != WPA_TKIP))
byPKType = WPA_WEP40;
else if ((pBSSList->abyPKType[ii] == WPA_WEP104) && (byPKType != WPA_AESCCMP) && (byPKType != WPA_TKIP))
byPKType = WPA_WEP104;
}
if (byEncrypt != byPKType)
return FALSE;
}
return TRUE;
break;
default:
break;
}
return FALSE;
}
BOOL
WPAb_Is_RSN(
PWLAN_IE_RSN_EXT pRSN
)
{
if (pRSN == NULL)
return FALSE;
if ((pRSN->len >= 6) &&
(pRSN->byElementID == WLAN_EID_RSN_WPA) && !memcmp(pRSN->abyOUI, abyOUI01, 4) &&
(pRSN->wVersion == 1)) {
return TRUE;
}
else
return FALSE;
}
