static void wpadev_setup(struct net_device *dev)
{
dev->type = ARPHRD_IEEE80211;
dev->hard_header_len = ETH_HLEN;
dev->mtu = 2048;
dev->addr_len = ETH_ALEN;
dev->tx_queue_len = 1000;
memset(dev->broadcast, 0xFF, ETH_ALEN);
dev->flags = IFF_BROADCAST|IFF_MULTICAST;
}
static int wpa_init_wpadev(struct vnt_private *pDevice)
{
struct vnt_private *wpadev_priv;
struct net_device *dev = pDevice->dev;
int ret = 0;
pDevice->wpadev = alloc_netdev(sizeof(*wpadev_priv), "vntwpa",
NET_NAME_UNKNOWN, wpadev_setup);
if (pDevice->wpadev == NULL)
return -ENOMEM;
wpadev_priv = netdev_priv(pDevice->wpadev);
*wpadev_priv = *pDevice;
eth_hw_addr_inherit(pDevice->wpadev, dev);
pDevice->wpadev->base_addr = dev->base_addr;
pDevice->wpadev->irq = dev->irq;
pDevice->wpadev->mem_start = dev->mem_start;
pDevice->wpadev->mem_end = dev->mem_end;
ret = register_netdev(pDevice->wpadev);
if (ret) {
pr_debug("%s: register_netdev(WPA) failed!\n", dev->name);
free_netdev(pDevice->wpadev);
return -1;
}
if (pDevice->skb == NULL) {
pDevice->skb = dev_alloc_skb((int)pDevice->rx_buf_sz);
if (pDevice->skb == NULL)
return -ENOMEM;
}
pr_debug("%s: Registered netdev %s for WPA management\n",
dev->name, pDevice->wpadev->name);
return 0;
}
static int wpa_release_wpadev(struct vnt_private *pDevice)
{
if (pDevice->skb) {
dev_kfree_skb(pDevice->skb);
pDevice->skb = NULL;
}
if (pDevice->wpadev) {
pr_debug("%s: Netdevice %s unregistered\n",
pDevice->dev->name, pDevice->wpadev->name);
unregister_netdev(pDevice->wpadev);
free_netdev(pDevice->wpadev);
pDevice->wpadev = NULL;
}
return 0;
}
int wpa_set_wpadev(struct vnt_private *pDevice, int val)
{
if (val)
return wpa_init_wpadev(pDevice);
else
return wpa_release_wpadev(pDevice);
}
int wpa_set_keys(struct vnt_private *pDevice, void *ctx,
bool fcpfkernel) __must_hold(&pDevice->lock
static int wpa_set_wpa(struct vnt_private *pDevice,
struct viawget_wpa_param *param)
{
PSMgmtObject pMgmt = pDevice->pMgmt;
pMgmt->eAuthenMode = WMAC_AUTH_OPEN;
pMgmt->bShareKeyAlgorithm = false;
return 0;
}
static int wpa_set_disassociate(struct vnt_private *pDevice,
struct viawget_wpa_param *param)
{
PSMgmtObject pMgmt = pDevice->pMgmt;
spin_lock_irq(&pDevice->lock);
if (pDevice->bLinkPass) {
if (!memcmp(param->addr, pMgmt->abyCurrBSSID, 6))
bScheduleCommand((void *)pDevice, WLAN_CMD_DISASSOCIATE, NULL);
}
spin_unlock_irq(&pDevice->lock);
return 0;
}
static int wpa_set_scan(struct vnt_private *pDevice,
struct viawget_wpa_param *param)
{
spin_lock_irq(&pDevice->lock);
BSSvClearBSSList((void *)pDevice, pDevice->bLinkPass);
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, NULL);
spin_unlock_irq(&pDevice->lock);
return 0;
}
static int wpa_get_bssid(struct vnt_private *pDevice,
struct viawget_wpa_param *param)
{
PSMgmtObject pMgmt = pDevice->pMgmt;
memcpy(param->u.wpa_associate.bssid, pMgmt->abyCurrBSSID , 6);
return 0;
}
static int wpa_get_ssid(struct vnt_private *pDevice,
struct viawget_wpa_param *param)
{
PSMgmtObject pMgmt = pDevice->pMgmt;
PWLAN_IE_SSID pItemSSID;
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyCurrSSID;
memcpy(param->u.wpa_associate.ssid, pItemSSID->abySSID , pItemSSID->len);
param->u.wpa_associate.ssid_len = pItemSSID->len;
return 0;
}
static int wpa_get_scan(struct vnt_private *pDevice,
struct viawget_wpa_param *param)
{
struct viawget_scan_result *scan_buf;
PSMgmtObject pMgmt = pDevice->pMgmt;
PWLAN_IE_SSID pItemSSID;
PKnownBSS pBSS;
unsigned char *pBuf;
int ret = 0;
u16 count = 0;
u16 ii, jj;
#if 1
unsigned char *ptempBSS;
ptempBSS = kmalloc(sizeof(KnownBSS), GFP_ATOMIC);
if (ptempBSS == NULL) {
pr_err("bubble sort kmalloc memory fail@@@\n");
ret = -ENOMEM;
return ret;
}
for (ii = 0; ii < MAX_BSS_NUM; ii++) {
for (jj = 0; jj < MAX_BSS_NUM - ii - 1; jj++) {
if ((pMgmt->sBSSList[jj].bActive != true) ||
((pMgmt->sBSSList[jj].uRSSI > pMgmt->sBSSList[jj + 1].uRSSI) && (pMgmt->sBSSList[jj + 1].bActive != false))) {
memcpy(ptempBSS, &pMgmt->sBSSList[jj], sizeof(KnownBSS));
memcpy(&pMgmt->sBSSList[jj], &pMgmt->sBSSList[jj + 1], sizeof(KnownBSS));
memcpy(&pMgmt->sBSSList[jj + 1], ptempBSS, sizeof(KnownBSS));
}
}
}
kfree(ptempBSS);
#endif
count = 0;
pBSS = &(pMgmt->sBSSList[0]);
for (ii = 0; ii < MAX_BSS_NUM; ii++) {
pBSS = &(pMgmt->sBSSList[ii]);
if (!pBSS->bActive)
continue;
count++;
}
pBuf = kcalloc(count, sizeof(struct viawget_scan_result), GFP_ATOMIC);
if (pBuf == NULL) {
ret = -ENOMEM;
return ret;
}
scan_buf = (struct viawget_scan_result *)pBuf;
pBSS = &(pMgmt->sBSSList[0]);
for (ii = 0, jj = 0; ii < MAX_BSS_NUM; ii++) {
pBSS = &(pMgmt->sBSSList[ii]);
if (pBSS->bActive) {
if (jj >= count)
break;
memcpy(scan_buf->bssid, pBSS->abyBSSID, WLAN_BSSID_LEN);
pItemSSID = (PWLAN_IE_SSID)pBSS->abySSID;
memcpy(scan_buf->ssid, pItemSSID->abySSID, pItemSSID->len);
scan_buf->ssid_len = pItemSSID->len;
scan_buf->freq = frequency_list[pBSS->uChannel-1];
scan_buf->caps = pBSS->wCapInfo;
if (pBSS->wWPALen != 0) {
scan_buf->wpa_ie_len = pBSS->wWPALen;
memcpy(scan_buf->wpa_ie, pBSS->byWPAIE, pBSS->wWPALen);
}
if (pBSS->wRSNLen != 0) {
scan_buf->rsn_ie_len = pBSS->wRSNLen;
memcpy(scan_buf->rsn_ie, pBSS->byRSNIE, pBSS->wRSNLen);
}
scan_buf = (struct viawget_scan_result *)((unsigned char *)scan_buf + sizeof(struct viawget_scan_result));
jj++;
}
}
if (jj < count)
count = jj;
if (copy_to_user(param->u.scan_results.buf, pBuf, sizeof(struct viawget_scan_result) * count))
ret = -EFAULT;
param->u.scan_results.scan_count = count;
pr_debug(" param->u.scan_results.scan_count = %d\n", count);
kfree(pBuf);
return ret;
}
static int wpa_set_associate(struct vnt_private *pDevice,
struct viawget_wpa_param *param)
{
PSMgmtObject pMgmt = pDevice->pMgmt;
PWLAN_IE_SSID pItemSSID;
unsigned char abyNullAddr[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char abyWPAIE[64];
bool bWepEnabled = false;
pr_debug("pairwise_suite = %d\n",
param->u.wpa_associate.pairwise_suite);
pr_debug("group_suite = %d\n", param->u.wpa_associate.group_suite);
pr_debug("key_mgmt_suite = %d\n",
param->u.wpa_associate.key_mgmt_suite);
pr_debug("auth_alg = %d\n", param->u.wpa_associate.auth_alg);
pr_debug("mode = %d\n", param->u.wpa_associate.mode);
pr_debug("wpa_ie_len = %d\n", param->u.wpa_associate.wpa_ie_len);
if (param->u.wpa_associate.wpa_ie_len) {
if (!param->u.wpa_associate.wpa_ie)
return -EINVAL;
if (param->u.wpa_associate.wpa_ie_len > sizeof(abyWPAIE))
return -EINVAL;
if (copy_from_user(&abyWPAIE[0], param->u.wpa_associate.wpa_ie, param->u.wpa_associate.wpa_ie_len))
return -EFAULT;
}
if (param->u.wpa_associate.mode == 1)
pMgmt->eConfigMode = WMAC_CONFIG_IBSS_STA;
else
pMgmt->eConfigMode = WMAC_CONFIG_ESS_STA;
memset(pMgmt->abyDesireSSID, 0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyDesireSSID;
pItemSSID->byElementID = WLAN_EID_SSID;
pItemSSID->len = param->u.wpa_associate.ssid_len;
memcpy(pItemSSID->abySSID, param->u.wpa_associate.ssid, pItemSSID->len);
if (memcmp(param->u.wpa_associate.bssid, &abyNullAddr[0], 6) != 0)
memcpy(pMgmt->abyDesireBSSID, param->u.wpa_associate.bssid, 6);
else
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, pItemSSID->abySSID);
if (param->u.wpa_associate.wpa_ie_len == 0) {
if (param->u.wpa_associate.auth_alg & AUTH_ALG_SHARED_KEY)
pMgmt->eAuthenMode = WMAC_AUTH_SHAREKEY;
else
pMgmt->eAuthenMode = WMAC_AUTH_OPEN;
} else if (abyWPAIE[0] == RSN_INFO_ELEM) {
if (param->u.wpa_associate.key_mgmt_suite == KEY_MGMT_PSK)
pMgmt->eAuthenMode = WMAC_AUTH_WPA2PSK;
else
pMgmt->eAuthenMode = WMAC_AUTH_WPA2;
} else {
if (param->u.wpa_associate.key_mgmt_suite == KEY_MGMT_WPA_NONE)
pMgmt->eAuthenMode = WMAC_AUTH_WPANONE;
else if (param->u.wpa_associate.key_mgmt_suite == KEY_MGMT_PSK)
pMgmt->eAuthenMode = WMAC_AUTH_WPAPSK;
else
pMgmt->eAuthenMode = WMAC_AUTH_WPA;
}
switch (param->u.wpa_associate.pairwise_suite) {
case CIPHER_CCMP:
pDevice->eEncryptionStatus = Ndis802_11Encryption3Enabled;
break;
case CIPHER_TKIP:
pDevice->eEncryptionStatus = Ndis802_11Encryption2Enabled;
break;
case CIPHER_WEP40:
case CIPHER_WEP104:
pDevice->eEncryptionStatus = Ndis802_11Encryption1Enabled;
bWepEnabled = true;
break;
case CIPHER_NONE:
if (param->u.wpa_associate.group_suite == CIPHER_CCMP)
pDevice->eEncryptionStatus = Ndis802_11Encryption3Enabled;
else
pDevice->eEncryptionStatus = Ndis802_11Encryption2Enabled;
break;
default:
pDevice->eEncryptionStatus = Ndis802_11EncryptionDisabled;
}
if (pMgmt->eAuthenMode == WMAC_AUTH_SHAREKEY) {
pDevice->eEncryptionStatus = Ndis802_11Encryption1Enabled;
pMgmt->bShareKeyAlgorithm = true;
} else if (pMgmt->eAuthenMode == WMAC_AUTH_OPEN) {
if (!bWepEnabled) pDevice->eEncryptionStatus = Ndis802_11EncryptionDisabled;
else pDevice->eEncryptionStatus = Ndis802_11Encryption1Enabled;
}
pDevice->eOldEncryptionStatus = pDevice->eEncryptionStatus;
if (pDevice->eEncryptionStatus != Ndis802_11EncryptionDisabled)
pDevice->bEncryptionEnable = true;
else
pDevice->bEncryptionEnable = false;
if (!((pMgmt->eAuthenMode == WMAC_AUTH_SHAREKEY) ||
((pMgmt->eAuthenMode == WMAC_AUTH_OPEN) && bWepEnabled)))
KeyvInitTable(&pDevice->sKey, pDevice->PortOffset);
spin_lock_irq(&pDevice->lock);
pDevice->bLinkPass = false;
memset(pMgmt->abyCurrBSSID, 0, 6);
pMgmt->eCurrState = WMAC_STATE_IDLE;
netif_stop_queue(pDevice->dev);
{
PKnownBSS pCurr = NULL;
pCurr = BSSpSearchBSSList(pDevice,
pMgmt->abyDesireBSSID,
pMgmt->abyDesireSSID,
pMgmt->eConfigPHYMode
);
if (pCurr == NULL) {
pr_debug("wpa_set_associate---->hidden mode site survey before associate.......\n");
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, pMgmt->abyDesireSSID);
}
}
bScheduleCommand((void *)pDevice, WLAN_CMD_SSID, NULL);
spin_unlock_irq(&pDevice->lock);
return 0;
}
int wpa_ioctl(struct vnt_private *pDevice, struct iw_point *p)
{
struct viawget_wpa_param *param;
int ret = 0;
int wpa_ioctl = 0;
if (p->length < sizeof(struct viawget_wpa_param) ||
p->length > VIAWGET_WPA_MAX_BUF_SIZE || !p->pointer)
return -EINVAL;
param = kmalloc((int)p->length, GFP_KERNEL);
if (param == NULL)
return -ENOMEM;
if (copy_from_user(param, p->pointer, p->length)) {
ret = -EFAULT;
goto out;
}
switch (param->cmd) {
case VIAWGET_SET_WPA:
ret = wpa_set_wpa(pDevice, param);
pr_debug("VIAWGET_SET_WPA\n");
break;
case VIAWGET_SET_KEY:
pr_debug("VIAWGET_SET_KEY\n");
spin_lock_irq(&pDevice->lock);
ret = wpa_set_keys(pDevice, param, false);
spin_unlock_irq(&pDevice->lock);
break;
case VIAWGET_SET_SCAN:
pr_debug("VIAWGET_SET_SCAN\n");
ret = wpa_set_scan(pDevice, param);
break;
case VIAWGET_GET_SCAN:
pr_debug("VIAWGET_GET_SCAN\n");
ret = wpa_get_scan(pDevice, param);
wpa_ioctl = 1;
break;
case VIAWGET_GET_SSID:
pr_debug("VIAWGET_GET_SSID\n");
ret = wpa_get_ssid(pDevice, param);
wpa_ioctl = 1;
break;
case VIAWGET_GET_BSSID:
pr_debug("VIAWGET_GET_BSSID\n");
ret = wpa_get_bssid(pDevice, param);
wpa_ioctl = 1;
break;
case VIAWGET_SET_ASSOCIATE:
pr_debug("VIAWGET_SET_ASSOCIATE\n");
ret = wpa_set_associate(pDevice, param);
break;
case VIAWGET_SET_DISASSOCIATE:
pr_debug("VIAWGET_SET_DISASSOCIATE\n");
ret = wpa_set_disassociate(pDevice, param);
break;
case VIAWGET_SET_DROP_UNENCRYPT:
pr_debug("VIAWGET_SET_DROP_UNENCRYPT\n");
break;
case VIAWGET_SET_DEAUTHENTICATE:
pr_debug("VIAWGET_SET_DEAUTHENTICATE\n");
break;
default:
pr_debug("wpa_ioctl: unknown cmd=%d\n",
param->cmd);
ret = -EOPNOTSUPP;
goto out;
}
if ((ret == 0) && wpa_ioctl) {
if (copy_to_user(p->pointer, param, p->length)) {
ret = -EFAULT;
goto out;
}
}
out:
kfree(param);
return ret;
}
