uint r8712_is_cckrates_included(u8 *rate)
{
u32 i = 0;
while (rate[i] != 0) {
if ((((rate[i]) & 0x7f) == 2) || (((rate[i]) & 0x7f) == 4) ||
(((rate[i]) & 0x7f) == 11) || (((rate[i]) & 0x7f) == 22))
return true;
i++;
}
return false;
}
uint r8712_is_cckratesonly_included(u8 *rate)
{
u32 i = 0;
while (rate[i] != 0) {
if ((((rate[i]) & 0x7f) != 2) && (((rate[i]) & 0x7f) != 4) &&
(((rate[i]) & 0x7f) != 11) && (((rate[i]) & 0x7f) != 22))
return false;
i++;
}
return true;
}
u8 *r8712_set_ie(u8 *pbuf, sint index, uint len, u8 *source, uint *frlen)
{
*pbuf = (u8)index;
*(pbuf + 1) = (u8)len;
if (len > 0)
memcpy((void *)(pbuf + 2), (void *)source, len);
*frlen = *frlen + (len + 2);
return pbuf + len + 2;
}
u8 *r8712_get_ie(u8 *pbuf, sint index, sint *len, sint limit)
{
sint tmp, i;
u8 *p;
if (limit < 1)
return NULL;
p = pbuf;
i = 0;
*len = 0;
while (1) {
if (*p == index) {
*len = *(p + 1);
return p;
} else {
tmp = *(p + 1);
p += (tmp + 2);
i += (tmp + 2);
}
if (i >= limit)
break;
}
return NULL;
}
static void set_supported_rate(u8 *SupportedRates, uint mode)
{
memset(SupportedRates, 0, NDIS_802_11_LENGTH_RATES_EX);
switch (mode) {
case WIRELESS_11B:
memcpy(SupportedRates, WIFI_CCKRATES,
IEEE80211_CCK_RATE_LEN);
break;
case WIRELESS_11G:
case WIRELESS_11A:
memcpy(SupportedRates, WIFI_OFDMRATES,
IEEE80211_NUM_OFDM_RATESLEN);
break;
case WIRELESS_11BG:
memcpy(SupportedRates, WIFI_CCKRATES, IEEE80211_CCK_RATE_LEN);
memcpy(SupportedRates + IEEE80211_CCK_RATE_LEN, WIFI_OFDMRATES,
IEEE80211_NUM_OFDM_RATESLEN);
break;
}
}
static uint r8712_get_rateset_len(u8 *rateset)
{
uint i = 0;
while (1) {
if ((rateset[i]) == 0)
break;
if (i > 12)
break;
i++;
}
return i;
}
int r8712_generate_ie(struct registry_priv *pregistrypriv,
struct _adapter *padapter)
{
int sz = 0, rateLen;
struct wlan_bssid_ex *pdev_network = &pregistrypriv->dev_network;
u8 *ie = pdev_network->IEs;
struct ieee80211_ht_cap ht_capie;
struct ieee80211_ht_addt_info ht_addt_info;
unsigned char WMM_IE[] = {0x00, 0x50, 0xf2, 0x02, 0x00, 0x01, 0x00};
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct qos_priv *pqospriv = &pmlmepriv->qospriv;
sz += 8;
ie += sz;
*(u16 *)ie = cpu_to_le16((u16)pdev_network->Configuration.BeaconPeriod);
sz += 2;
ie += 2;
*(u16 *)ie = 0;
*(u16 *)ie |= cpu_to_le16(cap_IBSS);
if (pregistrypriv->preamble == PREAMBLE_SHORT)
*(u16 *)ie |= cpu_to_le16(cap_ShortPremble);
if (pdev_network->Privacy)
*(u16 *)ie |= cpu_to_le16(cap_Privacy);
sz += 2;
ie += 2;
ie = r8712_set_ie(ie, _SSID_IE_, pdev_network->Ssid.SsidLength,
pdev_network->Ssid.Ssid, &sz);
set_supported_rate(pdev_network->SupportedRates,
pregistrypriv->wireless_mode);
rateLen = r8712_get_rateset_len(pdev_network->SupportedRates);
if (rateLen > 8) {
ie = r8712_set_ie(ie, _SUPPORTEDRATES_IE_, 8,
pdev_network->SupportedRates, &sz);
ie = r8712_set_ie(ie, _EXT_SUPPORTEDRATES_IE_, (rateLen - 8),
(pdev_network->SupportedRates + 8), &sz);
} else
ie = r8712_set_ie(ie, _SUPPORTEDRATES_IE_,
rateLen, pdev_network->SupportedRates, &sz);
ie = r8712_set_ie(ie, _DSSET_IE_, 1,
(u8 *)&(pdev_network->Configuration.DSConfig), &sz);
ie = r8712_set_ie(ie, _IBSS_PARA_IE_, 2,
(u8 *)&(pdev_network->Configuration.ATIMWindow), &sz);
if (pregistrypriv->ht_enable == 1) {
if (pqospriv->qos_option == 0) {
ie = r8712_set_ie(ie, _VENDOR_SPECIFIC_IE_,
_WMM_IE_Length_, WMM_IE, &sz);
pqospriv->qos_option = 1;
}
memset(&ht_capie, 0, sizeof(struct ieee80211_ht_cap));
ht_capie.cap_info = IEEE80211_HT_CAP_SUP_WIDTH |
IEEE80211_HT_CAP_SGI_20 |
IEEE80211_HT_CAP_SGI_40 |
IEEE80211_HT_CAP_TX_STBC |
IEEE80211_HT_CAP_MAX_AMSDU |
IEEE80211_HT_CAP_DSSSCCK40;
ht_capie.ampdu_params_info = (IEEE80211_HT_CAP_AMPDU_FACTOR &
0x03) | (IEEE80211_HT_CAP_AMPDU_DENSITY & 0x00);
ie = r8712_set_ie(ie, _HT_CAPABILITY_IE_,
sizeof(struct ieee80211_ht_cap),
(unsigned char *)&ht_capie, &sz);
memset(&ht_addt_info, 0,
sizeof(struct ieee80211_ht_addt_info));
ht_addt_info.control_chan = pregistrypriv->channel;
ie = r8712_set_ie(ie, _HT_ADD_INFO_IE_,
sizeof(struct ieee80211_ht_addt_info),
(unsigned char *)&ht_addt_info, &sz);
}
return sz;
}
unsigned char *r8712_get_wpa_ie(unsigned char *pie, int *wpa_ie_len, int limit)
{
int len;
u16 val16;
unsigned char wpa_oui_type[] = {0x00, 0x50, 0xf2, 0x01};
u8 *pbuf = pie;
while (1) {
pbuf = r8712_get_ie(pbuf, _WPA_IE_ID_, &len, limit);
if (pbuf) {
if (memcmp((pbuf + 2), wpa_oui_type,
sizeof(wpa_oui_type)))
goto check_next_ie;
memcpy((u8 *)&val16, (pbuf + 6), sizeof(val16));
val16 = le16_to_cpu(val16);
if (val16 != 0x0001)
goto check_next_ie;
*wpa_ie_len = *(pbuf + 1);
return pbuf;
} else {
*wpa_ie_len = 0;
return NULL;
}
check_next_ie:
limit = limit - (pbuf - pie) - 2 - len;
if (limit <= 0)
break;
pbuf += (2 + len);
}
*wpa_ie_len = 0;
return NULL;
}
unsigned char *r8712_get_wpa2_ie(unsigned char *pie, int *rsn_ie_len, int limit)
{
return r8712_get_ie(pie, _WPA2_IE_ID_, rsn_ie_len, limit);
}
static int r8712_get_wpa_cipher_suite(u8 *s)
{
if (!memcmp(s, (void *)WPA_CIPHER_SUITE_NONE, WPA_SELECTOR_LEN))
return WPA_CIPHER_NONE;
if (!memcmp(s, (void *)WPA_CIPHER_SUITE_WEP40, WPA_SELECTOR_LEN))
return WPA_CIPHER_WEP40;
if (!memcmp(s, (void *)WPA_CIPHER_SUITE_TKIP, WPA_SELECTOR_LEN))
return WPA_CIPHER_TKIP;
if (!memcmp(s, (void *)WPA_CIPHER_SUITE_CCMP, WPA_SELECTOR_LEN))
return WPA_CIPHER_CCMP;
if (!memcmp(s, (void *)WPA_CIPHER_SUITE_WEP104, WPA_SELECTOR_LEN))
return WPA_CIPHER_WEP104;
return 0;
}
static int r8712_get_wpa2_cipher_suite(u8 *s)
{
if (!memcmp(s, (void *)RSN_CIPHER_SUITE_NONE, RSN_SELECTOR_LEN))
return WPA_CIPHER_NONE;
if (!memcmp(s, (void *)RSN_CIPHER_SUITE_WEP40, RSN_SELECTOR_LEN))
return WPA_CIPHER_WEP40;
if (!memcmp(s, (void *)RSN_CIPHER_SUITE_TKIP, RSN_SELECTOR_LEN))
return WPA_CIPHER_TKIP;
if (!memcmp(s, (void *)RSN_CIPHER_SUITE_CCMP, RSN_SELECTOR_LEN))
return WPA_CIPHER_CCMP;
if (!memcmp(s, (void *)RSN_CIPHER_SUITE_WEP104, RSN_SELECTOR_LEN))
return WPA_CIPHER_WEP104;
return 0;
}
int r8712_parse_wpa_ie(u8 *wpa_ie, int wpa_ie_len, int *group_cipher,
int *pairwise_cipher)
{
int i, ret = _SUCCESS;
int left, count;
u8 *pos;
if (wpa_ie_len <= 0) {
return _FAIL;
}
if ((*wpa_ie != _WPA_IE_ID_) || (*(wpa_ie + 1) != (u8)(wpa_ie_len - 2))
|| (memcmp(wpa_ie + 2, (void *)WPA_OUI_TYPE, WPA_SELECTOR_LEN)))
return _FAIL;
pos = wpa_ie;
pos += 8;
left = wpa_ie_len - 8;
if (left >= WPA_SELECTOR_LEN) {
*group_cipher = r8712_get_wpa_cipher_suite(pos);
pos += WPA_SELECTOR_LEN;
left -= WPA_SELECTOR_LEN;
} else if (left > 0)
return _FAIL;
if (left >= 2) {
count = le16_to_cpu(*(u16 *)pos);
pos += 2;
left -= 2;
if (count == 0 || left < count * WPA_SELECTOR_LEN)
return _FAIL;
for (i = 0; i < count; i++) {
*pairwise_cipher |= r8712_get_wpa_cipher_suite(pos);
pos += WPA_SELECTOR_LEN;
left -= WPA_SELECTOR_LEN;
}
} else if (left == 1)
return _FAIL;
return ret;
}
int r8712_parse_wpa2_ie(u8 *rsn_ie, int rsn_ie_len, int *group_cipher,
int *pairwise_cipher)
{
int i, ret = _SUCCESS;
int left, count;
u8 *pos;
if (rsn_ie_len <= 0) {
return _FAIL;
}
if ((*rsn_ie != _WPA2_IE_ID_) || (*(rsn_ie+1) != (u8)(rsn_ie_len - 2)))
return _FAIL;
pos = rsn_ie;
pos += 4;
left = rsn_ie_len - 4;
if (left >= RSN_SELECTOR_LEN) {
*group_cipher = r8712_get_wpa2_cipher_suite(pos);
pos += RSN_SELECTOR_LEN;
left -= RSN_SELECTOR_LEN;
} else if (left > 0)
return _FAIL;
if (left >= 2) {
count = le16_to_cpu(*(u16 *)pos);
pos += 2;
left -= 2;
if (count == 0 || left < count * RSN_SELECTOR_LEN)
return _FAIL;
for (i = 0; i < count; i++) {
*pairwise_cipher |= r8712_get_wpa2_cipher_suite(pos);
pos += RSN_SELECTOR_LEN;
left -= RSN_SELECTOR_LEN;
}
} else if (left == 1)
return _FAIL;
return ret;
}
int r8712_get_sec_ie(u8 *in_ie, uint in_len, u8 *rsn_ie, u16 *rsn_len,
u8 *wpa_ie, u16 *wpa_len)
{
u8 authmode, sec_idx;
u8 wpa_oui[4] = {0x0, 0x50, 0xf2, 0x01};
uint cnt;
cnt = (_TIMESTAMP_ + _BEACON_ITERVAL_ + _CAPABILITY_);
sec_idx = 0;
while (cnt < in_len) {
authmode = in_ie[cnt];
if ((authmode == _WPA_IE_ID_) &&
(!memcmp(&in_ie[cnt + 2], &wpa_oui[0], 4))) {
memcpy(wpa_ie, &in_ie[cnt], in_ie[cnt + 1] + 2);
*wpa_len = in_ie[cnt+1]+2;
cnt += in_ie[cnt + 1] + 2;
} else {
if (authmode == _WPA2_IE_ID_) {
memcpy(rsn_ie, &in_ie[cnt],
in_ie[cnt + 1] + 2);
*rsn_len = in_ie[cnt+1] + 2;
cnt += in_ie[cnt+1] + 2;
} else
cnt += in_ie[cnt+1] + 2;
}
}
return *rsn_len + *wpa_len;
}
int r8712_get_wps_ie(u8 *in_ie, uint in_len, u8 *wps_ie, uint *wps_ielen)
{
int match;
uint cnt;
u8 eid, wps_oui[4] = {0x0, 0x50, 0xf2, 0x04};
cnt = 12;
match = false;
while (cnt < in_len) {
eid = in_ie[cnt];
if ((eid == _WPA_IE_ID_) &&
(!memcmp(&in_ie[cnt+2], wps_oui, 4))) {
memcpy(wps_ie, &in_ie[cnt], in_ie[cnt+1]+2);
*wps_ielen = in_ie[cnt+1]+2;
cnt += in_ie[cnt+1]+2;
match = true;
break;
} else
cnt += in_ie[cnt+1]+2;
}
return match;
}
