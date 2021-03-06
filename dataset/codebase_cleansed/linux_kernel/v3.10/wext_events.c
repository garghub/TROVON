void
wext_send_assoc_event(unifi_priv_t *priv, unsigned char *bssid,
unsigned char *req_ie, int req_ie_len,
unsigned char *resp_ie, int resp_ie_len,
unsigned char *scan_ie, unsigned int scan_ie_len)
{
#if WIRELESS_EXT > 17
union iwreq_data wrqu;
if (req_ie_len == 0) req_ie = NULL;
wrqu.data.length = req_ie_len;
wrqu.data.flags = 0;
wireless_send_event(priv->netdev[CSR_WIFI_INTERFACE_IN_USE], IWEVASSOCREQIE, &wrqu, req_ie);
if (resp_ie_len == 0) resp_ie = NULL;
wrqu.data.length = resp_ie_len;
wrqu.data.flags = 0;
wireless_send_event(priv->netdev[CSR_WIFI_INTERFACE_IN_USE], IWEVASSOCRESPIE, &wrqu, resp_ie);
if (scan_ie_len > 0) {
wrqu.data.length = scan_ie_len;
wrqu.data.flags = 0;
wireless_send_event(priv->netdev[CSR_WIFI_INTERFACE_IN_USE], IWEVGENIE, &wrqu, scan_ie);
}
memcpy(&wrqu.ap_addr.sa_data, bssid, ETH_ALEN);
wireless_send_event(priv->netdev[CSR_WIFI_INTERFACE_IN_USE], SIOCGIWAP, &wrqu, NULL);
#endif
}
void
wext_send_disassoc_event(unifi_priv_t *priv)
{
#if WIRELESS_EXT > 17
union iwreq_data wrqu;
memset(wrqu.ap_addr.sa_data, 0, ETH_ALEN);
wireless_send_event(priv->netdev[CSR_WIFI_INTERFACE_IN_USE], SIOCGIWAP, &wrqu, NULL);
#endif
}
void
wext_send_scan_results_event(unifi_priv_t *priv)
{
#if WIRELESS_EXT > 17
union iwreq_data wrqu;
wrqu.data.length = 0;
wrqu.data.flags = 0;
wireless_send_event(priv->netdev[CSR_WIFI_INTERFACE_IN_USE], SIOCGIWSCAN, &wrqu, NULL);
#endif
}
static inline void
_send_michaelmicfailure_event(struct net_device *dev,
int count, const unsigned char *macaddr,
int key_type, int key_idx,
unsigned char *tsc)
{
union iwreq_data wrqu;
struct iw_michaelmicfailure mmf;
memset(&mmf, 0, sizeof(mmf));
mmf.flags = key_idx & IW_MICFAILURE_KEY_ID;
if (key_type == CSR_GROUP) {
mmf.flags |= IW_MICFAILURE_GROUP;
} else {
mmf.flags |= IW_MICFAILURE_PAIRWISE;
}
mmf.flags |= ((count << 5) & IW_MICFAILURE_COUNT);
mmf.src_addr.sa_family = ARPHRD_ETHER;
memcpy(mmf.src_addr.sa_data, macaddr, ETH_ALEN);
memcpy(mmf.tsc, tsc, IW_ENCODE_SEQ_MAX_SIZE);
memset(&wrqu, 0, sizeof(wrqu));
wrqu.data.length = sizeof(mmf);
wireless_send_event(dev, IWEVMICHAELMICFAILURE, &wrqu, (char *)&mmf);
}
static inline void
_send_michaelmicfailure_event(struct net_device *dev,
int count, const unsigned char *macaddr,
int key_type, int key_idx,
unsigned char *tsc)
{
union iwreq_data wrqu;
char buf[128];
sprintf(buf,
"MLME-MICHAELMICFAILURE.indication(keyid=%d %scast addr=%pM)",
key_idx, (key_type == CSR_GROUP) ? "broad" : "uni", macaddr);
memset(&wrqu, 0, sizeof(wrqu));
wrqu.data.length = strlen(buf);
wireless_send_event(dev, IWEVCUSTOM, &wrqu, buf);
}
static inline void
_send_michaelmicfailure_event(struct net_device *dev,
int count, const unsigned char *macaddr,
int key_type, int key_idx,
unsigned char *tsc)
{
}
void
wext_send_michaelmicfailure_event(unifi_priv_t *priv,
u16 count,
CsrWifiMacAddress address,
CsrWifiSmeKeyType keyType,
u16 interfaceTag)
{
unsigned char tsc[8] = {0};
if (interfaceTag >= CSR_WIFI_NUM_INTERFACES) {
unifi_error(priv, "wext_send_michaelmicfailure_event bad interfaceTag\n");
return;
}
_send_michaelmicfailure_event(priv->netdev[interfaceTag],
count,
address.a,
keyType,
0,
tsc);
}
void
wext_send_pmkid_candidate_event(unifi_priv_t *priv, CsrWifiMacAddress bssid, u8 preauth_allowed, u16 interfaceTag)
{
#if WIRELESS_EXT > 17
union iwreq_data wrqu;
struct iw_pmkid_cand pmkid_cand;
if (interfaceTag >= CSR_WIFI_NUM_INTERFACES) {
unifi_error(priv, "wext_send_pmkid_candidate_event bad interfaceTag\n");
return;
}
memset(&pmkid_cand, 0, sizeof(pmkid_cand));
if (preauth_allowed) {
pmkid_cand.flags |= IW_PMKID_CAND_PREAUTH;
}
pmkid_cand.bssid.sa_family = ARPHRD_ETHER;
memcpy(pmkid_cand.bssid.sa_data, bssid.a, ETH_ALEN);
pmkid_cand.index = 1;
memset(&wrqu, 0, sizeof(wrqu));
wrqu.data.length = sizeof(pmkid_cand);
wireless_send_event(priv->netdev[interfaceTag], IWEVPMKIDCAND, &wrqu, (char *)&pmkid_cand);
#endif
}
void
wext_send_started_event(unifi_priv_t *priv)
{
#if WIRELESS_EXT > 17
union iwreq_data wrqu;
char data[] = "STARTED";
wrqu.data.length = sizeof(data);
wrqu.data.flags = 0;
wireless_send_event(priv->netdev[CSR_WIFI_INTERFACE_IN_USE], IWEVCUSTOM, &wrqu, data);
#endif
}
