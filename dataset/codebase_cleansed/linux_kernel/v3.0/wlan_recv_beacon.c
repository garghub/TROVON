static int __inline
iswpaoui(const u8 *frm)
{
return frm[1] > 3 && LE_READ_4(frm+2) == ((WPA_OUI_TYPE<<24)|WPA_OUI);
}
static int __inline
iswmmoui(const u8 *frm)
{
return frm[1] > 3 && LE_READ_4(frm+2) == ((WMM_OUI_TYPE<<24)|WMM_OUI);
}
static int __inline
isatherosoui(const u8 *frm)
{
return frm[1] > 3 && LE_READ_4(frm+2) == ((ATH_OUI_TYPE<<24)|ATH_OUI);
}
static int __inline
iswscoui(const u8 *frm)
{
return frm[1] > 3 && LE_READ_4(frm+2) == ((0x04<<24)|WPA_OUI);
}
int
wlan_parse_beacon(u8 *buf, int framelen, struct ieee80211_common_ie *cie)
{
u8 *frm, *efrm;
u8 elemid_ssid = false;
frm = buf;
efrm = (u8 *) (frm + framelen);
IEEE80211_VERIFY_LENGTH(efrm - frm, 12);
A_MEMZERO(cie, sizeof(*cie));
cie->ie_tstamp = frm; frm += 8;
cie->ie_beaconInt = A_LE2CPU16(*(u16 *)frm); frm += 2;
cie->ie_capInfo = A_LE2CPU16(*(u16 *)frm); frm += 2;
cie->ie_chan = 0;
while (frm < efrm) {
switch (*frm) {
case IEEE80211_ELEMID_SSID:
if (!elemid_ssid) {
cie->ie_ssid = frm;
elemid_ssid = true;
}
break;
case IEEE80211_ELEMID_RATES:
cie->ie_rates = frm;
break;
case IEEE80211_ELEMID_COUNTRY:
cie->ie_country = frm;
break;
case IEEE80211_ELEMID_FHPARMS:
break;
case IEEE80211_ELEMID_DSPARMS:
cie->ie_chan = frm[2];
break;
case IEEE80211_ELEMID_TIM:
cie->ie_tim = frm;
break;
case IEEE80211_ELEMID_IBSSPARMS:
break;
case IEEE80211_ELEMID_XRATES:
cie->ie_xrates = frm;
break;
case IEEE80211_ELEMID_ERP:
if (frm[1] != 1) {
return A_EINVAL;
}
cie->ie_erp = frm[2];
break;
case IEEE80211_ELEMID_RSN:
cie->ie_rsn = frm;
break;
case IEEE80211_ELEMID_HTCAP_ANA:
cie->ie_htcap = frm;
break;
case IEEE80211_ELEMID_HTINFO_ANA:
cie->ie_htop = frm;
break;
#ifdef WAPI_ENABLE
case IEEE80211_ELEMID_WAPI:
cie->ie_wapi = frm;
break;
#endif
case IEEE80211_ELEMID_VENDOR:
if (iswpaoui(frm)) {
cie->ie_wpa = frm;
} else if (iswmmoui(frm)) {
cie->ie_wmm = frm;
} else if (isatherosoui(frm)) {
cie->ie_ath = frm;
} else if(iswscoui(frm)) {
cie->ie_wsc = frm;
}
break;
default:
break;
}
frm += frm[1] + 2;
}
IEEE80211_VERIFY_ELEMENT(cie->ie_rates, IEEE80211_RATE_MAXSIZE);
IEEE80211_VERIFY_ELEMENT(cie->ie_ssid, IEEE80211_NWID_LEN);
return 0;
}
