void Dot11d_Init(struct ieee80211_device *ieee)
{
PRT_DOT11D_INFO pDot11dInfo = GET_DOT11D_INFO(ieee);
pDot11dInfo->bEnabled = 0;
pDot11dInfo->State = DOT11D_STATE_NONE;
pDot11dInfo->CountryIeLen = 0;
memset(pDot11dInfo->channel_map, 0, MAX_CHANNEL_NUMBER+1);
memset(pDot11dInfo->MaxTxPwrDbmList, 0xFF, MAX_CHANNEL_NUMBER+1);
RESET_CIE_WATCHDOG(ieee);
netdev_info(ieee->dev, "Dot11d_Init()\n");
}
void Dot11d_Reset(struct ieee80211_device *ieee)
{
u32 i;
PRT_DOT11D_INFO pDot11dInfo = GET_DOT11D_INFO(ieee);
memset(pDot11dInfo->channel_map, 0, MAX_CHANNEL_NUMBER+1);
memset(pDot11dInfo->MaxTxPwrDbmList, 0xFF, MAX_CHANNEL_NUMBER+1);
for (i = 1; i <= 11; i++)
(pDot11dInfo->channel_map)[i] = 1;
for (i = 12; i <= 14; i++)
(pDot11dInfo->channel_map)[i] = 2;
pDot11dInfo->State = DOT11D_STATE_NONE;
pDot11dInfo->CountryIeLen = 0;
RESET_CIE_WATCHDOG(ieee);
}
void Dot11d_UpdateCountryIe(struct ieee80211_device *dev, u8 *pTaddr,
u16 CoutryIeLen, u8 *pCoutryIe)
{
PRT_DOT11D_INFO pDot11dInfo = GET_DOT11D_INFO(dev);
u8 i, j, NumTriples, MaxChnlNum;
PCHNL_TXPOWER_TRIPLE pTriple;
memset(pDot11dInfo->channel_map, 0, MAX_CHANNEL_NUMBER+1);
memset(pDot11dInfo->MaxTxPwrDbmList, 0xFF, MAX_CHANNEL_NUMBER+1);
MaxChnlNum = 0;
NumTriples = (CoutryIeLen - 3) / 3;
pTriple = (PCHNL_TXPOWER_TRIPLE)(pCoutryIe + 3);
for (i = 0; i < NumTriples; i++) {
if (MaxChnlNum >= pTriple->FirstChnl) {
netdev_err(dev->dev, "Dot11d_UpdateCountryIe(): Invalid country IE, skip it........1\n");
return;
}
if (MAX_CHANNEL_NUMBER < (pTriple->FirstChnl + pTriple->NumChnls)) {
netdev_err(dev->dev, "Dot11d_UpdateCountryIe(): Invalid country IE, skip it........2\n");
return;
}
for (j = 0; j < pTriple->NumChnls; j++) {
pDot11dInfo->channel_map[pTriple->FirstChnl + j] = 1;
pDot11dInfo->MaxTxPwrDbmList[pTriple->FirstChnl + j] = pTriple->MaxTxPowerInDbm;
MaxChnlNum = pTriple->FirstChnl + j;
}
pTriple = (PCHNL_TXPOWER_TRIPLE)((u8 *)pTriple + 3);
}
netdev_info(dev->dev, "Channel List:");
for (i = 1; i <= MAX_CHANNEL_NUMBER; i++)
if (pDot11dInfo->channel_map[i] > 0)
netdev_info(dev->dev, " %d", i);
netdev_info(dev->dev, "\n");
UPDATE_CIE_SRC(dev, pTaddr);
pDot11dInfo->CountryIeLen = CoutryIeLen;
memcpy(pDot11dInfo->CountryIeBuf, pCoutryIe, CoutryIeLen);
pDot11dInfo->State = DOT11D_STATE_LEARNED;
}
u8 DOT11D_GetMaxTxPwrInDbm(struct ieee80211_device *dev, u8 Channel)
{
PRT_DOT11D_INFO pDot11dInfo = GET_DOT11D_INFO(dev);
u8 MaxTxPwrInDbm = 255;
if (MAX_CHANNEL_NUMBER < Channel) {
netdev_err(dev->dev, "DOT11D_GetMaxTxPwrInDbm(): Invalid Channel\n");
return MaxTxPwrInDbm;
}
if (pDot11dInfo->channel_map[Channel])
MaxTxPwrInDbm = pDot11dInfo->MaxTxPwrDbmList[Channel];
return MaxTxPwrInDbm;
}
void DOT11D_ScanComplete(struct ieee80211_device *dev)
{
PRT_DOT11D_INFO pDot11dInfo = GET_DOT11D_INFO(dev);
switch (pDot11dInfo->State) {
case DOT11D_STATE_LEARNED:
pDot11dInfo->State = DOT11D_STATE_DONE;
break;
case DOT11D_STATE_DONE:
if (GET_CIE_WATCHDOG(dev) == 0) {
Dot11d_Reset(dev);
}
break;
case DOT11D_STATE_NONE:
break;
}
}
int IsLegalChannel(struct ieee80211_device *dev, u8 channel)
{
PRT_DOT11D_INFO pDot11dInfo = GET_DOT11D_INFO(dev);
if (MAX_CHANNEL_NUMBER < channel) {
netdev_err(dev->dev, "IsLegalChannel(): Invalid Channel\n");
return 0;
}
if (pDot11dInfo->channel_map[channel] > 0)
return 1;
return 0;
}
int ToLegalChannel(struct ieee80211_device *dev, u8 channel)
{
PRT_DOT11D_INFO pDot11dInfo = GET_DOT11D_INFO(dev);
u8 default_chn = 0;
u32 i = 0;
for (i = 1; i <= MAX_CHANNEL_NUMBER; i++) {
if (pDot11dInfo->channel_map[i] > 0) {
default_chn = i;
break;
}
}
if (MAX_CHANNEL_NUMBER < channel) {
netdev_err(dev->dev, "IsLegalChannel(): Invalid Channel\n");
return default_chn;
}
if (pDot11dInfo->channel_map[channel] > 0)
return channel;
return default_chn;
}
