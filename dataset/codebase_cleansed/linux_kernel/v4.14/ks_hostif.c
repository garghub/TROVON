static
inline u8 get_BYTE(struct ks_wlan_private *priv)
{
u8 data;
data = *(priv->rxp)++;
--(priv->rx_size);
return data;
}
static
inline u16 get_WORD(struct ks_wlan_private *priv)
{
u16 data;
data = (get_BYTE(priv) & 0xff);
data |= ((get_BYTE(priv) << 8) & 0xff00);
return data;
}
static
inline u32 get_DWORD(struct ks_wlan_private *priv)
{
u32 data;
data = (get_BYTE(priv) & 0xff);
data |= ((get_BYTE(priv) << 8) & 0x0000ff00);
data |= ((get_BYTE(priv) << 16) & 0x00ff0000);
data |= ((get_BYTE(priv) << 24) & 0xff000000);
return data;
}
static void ks_wlan_hw_wakeup_task(struct work_struct *work)
{
struct ks_wlan_private *priv;
int ps_status;
long time_left;
priv = container_of(work, struct ks_wlan_private, wakeup_work);
ps_status = atomic_read(&priv->psstatus.status);
if (ps_status == PS_SNOOZE) {
ks_wlan_hw_wakeup_request(priv);
time_left = wait_for_completion_interruptible_timeout(
&priv->psstatus.wakeup_wait,
msecs_to_jiffies(20));
if (time_left <= 0) {
DPRINTK(1, "wake up timeout or interrupted !!!\n");
schedule_work(&priv->wakeup_work);
return;
}
} else {
DPRINTK(1, "ps_status=%d\n", ps_status);
}
if (atomic_read(&priv->sme_task.count) > 0) {
DPRINTK(4, "sme task enable.\n");
tasklet_enable(&priv->sme_task);
}
}
static
int ks_wlan_do_power_save(struct ks_wlan_private *priv)
{
DPRINTK(4, "psstatus.status=%d\n", atomic_read(&priv->psstatus.status));
if (is_connect_status(priv->connect_status))
hostif_sme_enqueue(priv, SME_POW_MNGMT_REQUEST);
else
priv->dev_state = DEVICE_STATE_READY;
return 0;
}
static
int get_current_ap(struct ks_wlan_private *priv, struct link_ap_info_t *ap_info)
{
struct local_ap_t *ap;
union iwreq_data wrqu;
struct net_device *netdev = priv->net_dev;
DPRINTK(3, "\n");
ap = &priv->current_ap;
if (is_disconnect_status(priv->connect_status)) {
memset(ap, 0, sizeof(struct local_ap_t));
return -EPERM;
}
memcpy(ap->bssid, ap_info->bssid, ETH_ALEN);
memcpy(ap->ssid.body, priv->reg.ssid.body,
priv->reg.ssid.size);
ap->ssid.size = priv->reg.ssid.size;
memcpy(ap->rate_set.body, ap_info->rate_set.body,
ap_info->rate_set.size);
ap->rate_set.size = ap_info->rate_set.size;
if (ap_info->ext_rate_set.size != 0) {
memcpy(&ap->rate_set.body[ap->rate_set.size],
ap_info->ext_rate_set.body,
ap_info->ext_rate_set.size);
ap->rate_set.size += ap_info->ext_rate_set.size;
}
ap->channel = ap_info->ds_parameter.channel;
ap->rssi = ap_info->rssi;
ap->sq = ap_info->sq;
ap->noise = ap_info->noise;
ap->capability = le16_to_cpu(ap_info->capability);
if ((ap_info->rsn_mode & RSN_MODE_WPA2) &&
(priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)) {
ap->rsn_ie.id = 0x30;
if (ap_info->rsn.size <= RSN_IE_BODY_MAX) {
ap->rsn_ie.size = ap_info->rsn.size;
memcpy(ap->rsn_ie.body, ap_info->rsn.body,
ap_info->rsn.size);
} else {
ap->rsn_ie.size = RSN_IE_BODY_MAX;
memcpy(ap->rsn_ie.body, ap_info->rsn.body,
RSN_IE_BODY_MAX);
}
} else if ((ap_info->rsn_mode & RSN_MODE_WPA) &&
(priv->wpa.version == IW_AUTH_WPA_VERSION_WPA)) {
ap->wpa_ie.id = 0xdd;
if (ap_info->rsn.size <= RSN_IE_BODY_MAX) {
ap->wpa_ie.size = ap_info->rsn.size;
memcpy(ap->wpa_ie.body, ap_info->rsn.body,
ap_info->rsn.size);
} else {
ap->wpa_ie.size = RSN_IE_BODY_MAX;
memcpy(ap->wpa_ie.body, ap_info->rsn.body,
RSN_IE_BODY_MAX);
}
} else {
ap->rsn_ie.id = 0;
ap->rsn_ie.size = 0;
ap->wpa_ie.id = 0;
ap->wpa_ie.size = 0;
}
wrqu.data.length = 0;
wrqu.data.flags = 0;
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
if (is_connect_status(priv->connect_status)) {
memcpy(wrqu.ap_addr.sa_data,
priv->current_ap.bssid, ETH_ALEN);
DPRINTK(3,
"IWEVENT: connect bssid=%pM\n", wrqu.ap_addr.sa_data);
wireless_send_event(netdev, SIOCGIWAP, &wrqu, NULL);
}
DPRINTK(4, "\n Link AP\n");
DPRINTK(4, " bssid=%02X:%02X:%02X:%02X:%02X:%02X\n"
" essid=%s\n"
" rate_set=%02X,%02X,%02X,%02X,%02X,%02X,%02X,%02X\n"
" channel=%d\n"
" rssi=%d\n"
" sq=%d\n"
" capability=%04X\n",
ap->bssid[0], ap->bssid[1], ap->bssid[2],
ap->bssid[3], ap->bssid[4], ap->bssid[5],
&(ap->ssid.body[0]),
ap->rate_set.body[0], ap->rate_set.body[1],
ap->rate_set.body[2], ap->rate_set.body[3],
ap->rate_set.body[4], ap->rate_set.body[5],
ap->rate_set.body[6], ap->rate_set.body[7],
ap->channel, ap->rssi, ap->sq, ap->capability);
DPRINTK(4, "\n Link AP\n rsn.mode=%d\n rsn.size=%d\n",
ap_info->rsn_mode, ap_info->rsn.size);
DPRINTK(4, "\n ext_rate_set_size=%d\n rate_set_size=%d\n",
ap_info->ext_rate_set.size, ap_info->rate_set.size);
return 0;
}
static
int get_ap_information(struct ks_wlan_private *priv, struct ap_info_t *ap_info,
struct local_ap_t *ap)
{
unsigned char *bp;
int bsize, offset;
DPRINTK(3, "\n");
memset(ap, 0, sizeof(struct local_ap_t));
memcpy(ap->bssid, ap_info->bssid, ETH_ALEN);
ap->rssi = ap_info->rssi;
ap->sq = ap_info->sq;
ap->noise = ap_info->noise;
ap->capability = le16_to_cpu(ap_info->capability);
ap->channel = ap_info->ch_info;
bp = ap_info->body;
bsize = le16_to_cpu(ap_info->body_size);
offset = 0;
while (bsize > offset) {
switch (*bp) {
case 0:
if (*(bp + 1) <= SSID_MAX_SIZE) {
ap->ssid.size = *(bp + 1);
} else {
DPRINTK(1, "size over :: ssid size=%d\n",
*(bp + 1));
ap->ssid.size = SSID_MAX_SIZE;
}
memcpy(ap->ssid.body, bp + 2, ap->ssid.size);
break;
case 1:
case 50:
if ((*(bp + 1) + ap->rate_set.size) <=
RATE_SET_MAX_SIZE) {
memcpy(&ap->rate_set.body[ap->rate_set.size],
bp + 2, *(bp + 1));
ap->rate_set.size += *(bp + 1);
} else {
DPRINTK(1, "size over :: rate size=%d\n",
(*(bp + 1) + ap->rate_set.size));
memcpy(&ap->rate_set.body[ap->rate_set.size],
bp + 2,
RATE_SET_MAX_SIZE - ap->rate_set.size);
ap->rate_set.size +=
(RATE_SET_MAX_SIZE - ap->rate_set.size);
}
break;
case 3:
break;
case 48:
ap->rsn_ie.id = *bp;
if (*(bp + 1) <= RSN_IE_BODY_MAX) {
ap->rsn_ie.size = *(bp + 1);
} else {
DPRINTK(1, "size over :: rsn size=%d\n",
*(bp + 1));
ap->rsn_ie.size = RSN_IE_BODY_MAX;
}
memcpy(ap->rsn_ie.body, bp + 2, ap->rsn_ie.size);
break;
case 221:
if (memcmp(bp + 2, "\x00\x50\xf2\x01", 4) == 0) {
ap->wpa_ie.id = *bp;
if (*(bp + 1) <= RSN_IE_BODY_MAX) {
ap->wpa_ie.size = *(bp + 1);
} else {
DPRINTK(1,
"size over :: wpa size=%d\n",
*(bp + 1));
ap->wpa_ie.size = RSN_IE_BODY_MAX;
}
memcpy(ap->wpa_ie.body, bp + 2,
ap->wpa_ie.size);
}
break;
case 2:
case 4:
case 5:
case 6:
case 7:
case 42:
case 47:
break;
default:
DPRINTK(4, "unknown Element ID=%d\n", *bp);
break;
}
offset += 2;
offset += *(bp + 1);
bp += (*(bp + 1) + 2);
}
return 0;
}
static
int hostif_data_indication_wpa(struct ks_wlan_private *priv,
unsigned short auth_type)
{
struct ether_hdr *eth_hdr;
unsigned short eth_proto;
unsigned char recv_mic[8];
char buf[128];
unsigned long now;
struct mic_failure_t *mic_failure;
struct michael_mic_t michael_mic;
union iwreq_data wrqu;
unsigned int key_index = auth_type - 1;
struct wpa_key_t *key = &priv->wpa.key[key_index];
eth_hdr = (struct ether_hdr *)(priv->rxp);
eth_proto = ntohs(eth_hdr->h_proto);
if (eth_hdr->h_dest_snap != eth_hdr->h_source_snap) {
DPRINTK(1, "invalid data format\n");
priv->nstats.rx_errors++;
return -EINVAL;
}
if (((auth_type == TYPE_PMK1 &&
priv->wpa.pairwise_suite == IW_AUTH_CIPHER_TKIP) ||
(auth_type == TYPE_GMK1 &&
priv->wpa.group_suite == IW_AUTH_CIPHER_TKIP) ||
(auth_type == TYPE_GMK2 &&
priv->wpa.group_suite == IW_AUTH_CIPHER_TKIP)) &&
key->key_len) {
DPRINTK(4, "TKIP: protocol=%04X: size=%u\n",
eth_proto, priv->rx_size);
memcpy(&recv_mic[0], (priv->rxp) + ((priv->rx_size) - 8), 8);
priv->rx_size = priv->rx_size - 8;
if (auth_type > 0 && auth_type < 4) {
MichaelMICFunction(&michael_mic,
(uint8_t *)key->rx_mic_key,
(uint8_t *)priv->rxp,
(int)priv->rx_size,
(uint8_t)0,
(uint8_t *)michael_mic.Result);
}
if (memcmp(michael_mic.Result, recv_mic, 8) != 0) {
now = jiffies;
mic_failure = &priv->wpa.mic_failure;
if (mic_failure->last_failure_time &&
(now - mic_failure->last_failure_time) / HZ >= 60) {
mic_failure->failure = 0;
}
DPRINTK(4, "MIC FAILURE\n");
if (mic_failure->failure == 0) {
mic_failure->failure = 1;
mic_failure->counter = 0;
} else if (mic_failure->failure == 1) {
mic_failure->failure = 2;
mic_failure->counter =
(uint16_t)((now - mic_failure->last_failure_time) / HZ);
if (!mic_failure->counter)
mic_failure->counter = 1;
}
priv->wpa.mic_failure.last_failure_time = now;
sprintf(buf,
"MLME-MICHAELMICFAILURE.indication(keyid=%d %scast addr=%pM)",
key_index,
eth_hdr->h_dest[0] & 0x01 ? "broad" : "uni",
eth_hdr->h_source);
memset(&wrqu, 0, sizeof(wrqu));
wrqu.data.length = strlen(buf);
DPRINTK(4, "IWEVENT:MICHAELMICFAILURE\n");
wireless_send_event(priv->net_dev, IWEVCUSTOM, &wrqu,
buf);
return -EINVAL;
}
}
return 0;
}
static
void hostif_data_indication(struct ks_wlan_private *priv)
{
unsigned int rx_ind_size;
struct sk_buff *skb;
unsigned short auth_type;
unsigned char temp[256];
struct ether_hdr *eth_hdr;
unsigned short eth_proto;
struct ieee802_1x_hdr *aa1x_hdr;
size_t size;
int ret;
DPRINTK(3, "\n");
if (priv->rx_size <= ETH_HLEN) {
DPRINTK(3, "rx_size = %d\n", priv->rx_size);
priv->nstats.rx_errors++;
return;
}
auth_type = get_WORD(priv);
get_WORD(priv);
eth_hdr = (struct ether_hdr *)(priv->rxp);
eth_proto = ntohs(eth_hdr->h_proto);
DPRINTK(3, "ether protocol = %04X\n", eth_proto);
if (memcmp(&priv->eth_addr[0], eth_hdr->h_source, ETH_ALEN) == 0) {
DPRINTK(1, "invalid : source is own mac address !!\n");
DPRINTK(1,
"eth_hdrernet->h_dest=%02X:%02X:%02X:%02X:%02X:%02X\n",
eth_hdr->h_source[0], eth_hdr->h_source[1],
eth_hdr->h_source[2], eth_hdr->h_source[3],
eth_hdr->h_source[4], eth_hdr->h_source[5]);
priv->nstats.rx_errors++;
return;
}
if (auth_type != TYPE_DATA && priv->wpa.rsn_enabled) {
ret = hostif_data_indication_wpa(priv, auth_type);
if (ret)
return;
}
if ((priv->connect_status & FORCE_DISCONNECT) ||
priv->wpa.mic_failure.failure == 2) {
return;
}
switch (*(priv->rxp + 12)) {
case 0xAA:
rx_ind_size = priv->rx_size - 6;
skb = dev_alloc_skb(rx_ind_size);
if (!skb) {
priv->nstats.rx_dropped++;
return;
}
DPRINTK(4, "SNAP, rx_ind_size = %d\n", rx_ind_size);
size = ETH_ALEN * 2;
skb_put_data(skb, priv->rxp, size);
size = rx_ind_size - (ETH_ALEN * 2);
skb_put_data(skb, &eth_hdr->h_proto, size);
aa1x_hdr = (struct ieee802_1x_hdr *)(priv->rxp + ETHER_HDR_SIZE);
break;
case 0xF0:
rx_ind_size = (priv->rx_size + 2);
skb = dev_alloc_skb(rx_ind_size);
if (!skb) {
priv->nstats.rx_dropped++;
return;
}
DPRINTK(3, "NETBEUI/NetBIOS rx_ind_size=%d\n", rx_ind_size);
skb_put_data(skb, priv->rxp, 12);
temp[0] = (((rx_ind_size - 12) >> 8) & 0xff);
temp[1] = ((rx_ind_size - 12) & 0xff);
skb_put_data(skb, temp, 2);
skb_put_data(skb, priv->rxp + 12, rx_ind_size - 14);
aa1x_hdr = (struct ieee802_1x_hdr *)(priv->rxp + 14);
break;
default:
DPRINTK(2, "invalid data format\n");
priv->nstats.rx_errors++;
return;
}
if (aa1x_hdr->type == IEEE802_1X_TYPE_EAPOL_KEY &&
priv->wpa.rsn_enabled)
atomic_set(&priv->psstatus.snooze_guard, 1);
skb->dev = priv->net_dev;
skb->protocol = eth_type_trans(skb, skb->dev);
priv->nstats.rx_packets++;
priv->nstats.rx_bytes += rx_ind_size;
netif_rx(skb);
}
static
void hostif_mib_get_confirm(struct ks_wlan_private *priv)
{
struct net_device *dev = priv->net_dev;
u32 mib_status;
u32 mib_attribute;
u16 mib_val_size;
u16 mib_val_type;
DPRINTK(3, "\n");
mib_status = get_DWORD(priv);
mib_attribute = get_DWORD(priv);
mib_val_size = get_WORD(priv);
mib_val_type = get_WORD(priv);
if (mib_status) {
DPRINTK(1, "attribute=%08X, status=%08X\n", mib_attribute,
mib_status);
return;
}
switch (mib_attribute) {
case DOT11_MAC_ADDRESS:
DPRINTK(3, " mib_attribute=DOT11_MAC_ADDRESS\n");
hostif_sme_enqueue(priv, SME_GET_MAC_ADDRESS);
memcpy(priv->eth_addr, priv->rxp, ETH_ALEN);
priv->mac_address_valid = 1;
dev->dev_addr[0] = priv->eth_addr[0];
dev->dev_addr[1] = priv->eth_addr[1];
dev->dev_addr[2] = priv->eth_addr[2];
dev->dev_addr[3] = priv->eth_addr[3];
dev->dev_addr[4] = priv->eth_addr[4];
dev->dev_addr[5] = priv->eth_addr[5];
dev->dev_addr[6] = 0x00;
dev->dev_addr[7] = 0x00;
netdev_info(dev, "MAC ADDRESS = %pM\n", priv->eth_addr);
break;
case DOT11_PRODUCT_VERSION:
DPRINTK(3, " mib_attribute=DOT11_PRODUCT_VERSION\n");
priv->version_size = priv->rx_size;
memcpy(priv->firmware_version, priv->rxp, priv->rx_size);
priv->firmware_version[priv->rx_size] = '\0';
netdev_info(dev, "firmware ver. = %s\n",
priv->firmware_version);
hostif_sme_enqueue(priv, SME_GET_PRODUCT_VERSION);
complete(&priv->confirm_wait);
break;
case LOCAL_GAIN:
memcpy(&priv->gain, priv->rxp, sizeof(priv->gain));
DPRINTK(3, "tx_mode=%d, rx_mode=%d, tx_gain=%d, rx_gain=%d\n",
priv->gain.tx_mode, priv->gain.rx_mode,
priv->gain.tx_gain, priv->gain.rx_gain);
break;
case LOCAL_EEPROM_SUM:
memcpy(&priv->eeprom_sum, priv->rxp, sizeof(priv->eeprom_sum));
DPRINTK(1, "eeprom_sum.type=%x, eeprom_sum.result=%x\n",
priv->eeprom_sum.type, priv->eeprom_sum.result);
if (priv->eeprom_sum.type == 0) {
priv->eeprom_checksum = EEPROM_CHECKSUM_NONE;
} else if (priv->eeprom_sum.type == 1) {
if (priv->eeprom_sum.result == 0) {
priv->eeprom_checksum = EEPROM_NG;
netdev_info(dev, "LOCAL_EEPROM_SUM NG\n");
} else if (priv->eeprom_sum.result == 1) {
priv->eeprom_checksum = EEPROM_OK;
}
} else {
netdev_err(dev, "LOCAL_EEPROM_SUM error!\n");
}
break;
default:
DPRINTK(1, "mib_attribute=%08x\n", (unsigned int)mib_attribute);
break;
}
}
static
void hostif_mib_set_confirm(struct ks_wlan_private *priv)
{
u32 mib_status;
u32 mib_attribute;
DPRINTK(3, "\n");
mib_status = get_DWORD(priv);
mib_attribute = get_DWORD(priv);
if (mib_status) {
DPRINTK(1, "error :: attribute=%08X, status=%08X\n",
mib_attribute, mib_status);
}
switch (mib_attribute) {
case DOT11_RTS_THRESHOLD:
hostif_sme_enqueue(priv, SME_RTS_THRESHOLD_CONFIRM);
break;
case DOT11_FRAGMENTATION_THRESHOLD:
hostif_sme_enqueue(priv, SME_FRAGMENTATION_THRESHOLD_CONFIRM);
break;
case DOT11_WEP_DEFAULT_KEY_ID:
if (!priv->wpa.wpa_enabled)
hostif_sme_enqueue(priv, SME_WEP_INDEX_CONFIRM);
break;
case DOT11_WEP_DEFAULT_KEY_VALUE1:
DPRINTK(2, "DOT11_WEP_DEFAULT_KEY_VALUE1:mib_status=%d\n",
(int)mib_status);
if (priv->wpa.rsn_enabled)
hostif_sme_enqueue(priv, SME_SET_PMK_TSC);
else
hostif_sme_enqueue(priv, SME_WEP_KEY1_CONFIRM);
break;
case DOT11_WEP_DEFAULT_KEY_VALUE2:
DPRINTK(2, "DOT11_WEP_DEFAULT_KEY_VALUE2:mib_status=%d\n",
(int)mib_status);
if (priv->wpa.rsn_enabled)
hostif_sme_enqueue(priv, SME_SET_GMK1_TSC);
else
hostif_sme_enqueue(priv, SME_WEP_KEY2_CONFIRM);
break;
case DOT11_WEP_DEFAULT_KEY_VALUE3:
DPRINTK(2, "DOT11_WEP_DEFAULT_KEY_VALUE3:mib_status=%d\n",
(int)mib_status);
if (priv->wpa.rsn_enabled)
hostif_sme_enqueue(priv, SME_SET_GMK2_TSC);
else
hostif_sme_enqueue(priv, SME_WEP_KEY3_CONFIRM);
break;
case DOT11_WEP_DEFAULT_KEY_VALUE4:
DPRINTK(2, "DOT11_WEP_DEFAULT_KEY_VALUE4:mib_status=%d\n",
(int)mib_status);
if (!priv->wpa.rsn_enabled)
hostif_sme_enqueue(priv, SME_WEP_KEY4_CONFIRM);
break;
case DOT11_PRIVACY_INVOKED:
if (!priv->wpa.rsn_enabled)
hostif_sme_enqueue(priv, SME_WEP_FLAG_CONFIRM);
break;
case DOT11_RSN_ENABLED:
DPRINTK(2, "DOT11_RSN_ENABLED:mib_status=%d\n",
(int)mib_status);
hostif_sme_enqueue(priv, SME_RSN_ENABLED_CONFIRM);
break;
case LOCAL_RSN_MODE:
hostif_sme_enqueue(priv, SME_RSN_MODE_CONFIRM);
break;
case LOCAL_MULTICAST_ADDRESS:
hostif_sme_enqueue(priv, SME_MULTICAST_REQUEST);
break;
case LOCAL_MULTICAST_FILTER:
hostif_sme_enqueue(priv, SME_MULTICAST_CONFIRM);
break;
case LOCAL_CURRENTADDRESS:
priv->mac_address_valid = 1;
break;
case DOT11_RSN_CONFIG_MULTICAST_CIPHER:
DPRINTK(2, "DOT11_RSN_CONFIG_MULTICAST_CIPHER:mib_status=%d\n",
(int)mib_status);
hostif_sme_enqueue(priv, SME_RSN_MCAST_CONFIRM);
break;
case DOT11_RSN_CONFIG_UNICAST_CIPHER:
DPRINTK(2, "DOT11_RSN_CONFIG_UNICAST_CIPHER:mib_status=%d\n",
(int)mib_status);
hostif_sme_enqueue(priv, SME_RSN_UCAST_CONFIRM);
break;
case DOT11_RSN_CONFIG_AUTH_SUITE:
DPRINTK(2, "DOT11_RSN_CONFIG_AUTH_SUITE:mib_status=%d\n",
(int)mib_status);
hostif_sme_enqueue(priv, SME_RSN_AUTH_CONFIRM);
break;
case DOT11_PMK_TSC:
DPRINTK(2, "DOT11_PMK_TSC:mib_status=%d\n", (int)mib_status);
break;
case DOT11_GMK1_TSC:
DPRINTK(2, "DOT11_GMK1_TSC:mib_status=%d\n", (int)mib_status);
if (atomic_read(&priv->psstatus.snooze_guard))
atomic_set(&priv->psstatus.snooze_guard, 0);
break;
case DOT11_GMK2_TSC:
DPRINTK(2, "DOT11_GMK2_TSC:mib_status=%d\n", (int)mib_status);
if (atomic_read(&priv->psstatus.snooze_guard))
atomic_set(&priv->psstatus.snooze_guard, 0);
break;
case LOCAL_PMK:
DPRINTK(2, "LOCAL_PMK:mib_status=%d\n", (int)mib_status);
break;
case LOCAL_GAIN:
DPRINTK(2, "LOCAL_GAIN:mib_status=%d\n", (int)mib_status);
break;
#ifdef WPS
case LOCAL_WPS_ENABLE:
DPRINTK(2, "LOCAL_WPS_ENABLE:mib_status=%d\n", (int)mib_status);
break;
case LOCAL_WPS_PROBE_REQ:
DPRINTK(2, "LOCAL_WPS_PROBE_REQ:mib_status=%d\n",
(int)mib_status);
break;
#endif
case LOCAL_REGION:
DPRINTK(2, "LOCAL_REGION:mib_status=%d\n", (int)mib_status);
default:
break;
}
}
static
void hostif_power_mgmt_confirm(struct ks_wlan_private *priv)
{
DPRINTK(3, "\n");
if (priv->reg.power_mgmt > POWER_MGMT_ACTIVE &&
priv->reg.operation_mode == MODE_INFRASTRUCTURE) {
atomic_set(&priv->psstatus.confirm_wait, 0);
priv->dev_state = DEVICE_STATE_SLEEP;
ks_wlan_hw_power_save(priv);
} else {
priv->dev_state = DEVICE_STATE_READY;
}
}
static
void hostif_sleep_confirm(struct ks_wlan_private *priv)
{
DPRINTK(3, "\n");
atomic_set(&priv->sleepstatus.doze_request, 1);
queue_delayed_work(priv->wq, &priv->rw_dwork, 1);
}
static
void hostif_start_confirm(struct ks_wlan_private *priv)
{
#ifdef WPS
union iwreq_data wrqu;
wrqu.data.length = 0;
wrqu.data.flags = 0;
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
if (is_connect_status(priv->connect_status)) {
eth_zero_addr(wrqu.ap_addr.sa_data);
DPRINTK(3, "IWEVENT: disconnect\n");
wireless_send_event(priv->net_dev, SIOCGIWAP, &wrqu, NULL);
}
#endif
DPRINTK(3, " scan_ind_count=%d\n", priv->scan_ind_count);
hostif_sme_enqueue(priv, SME_START_CONFIRM);
}
static
void hostif_connect_indication(struct ks_wlan_private *priv)
{
unsigned short connect_code;
unsigned int tmp = 0;
unsigned int old_status = priv->connect_status;
struct net_device *netdev = priv->net_dev;
union iwreq_data wrqu0;
connect_code = get_WORD(priv);
switch (connect_code) {
case RESULT_CONNECT:
DPRINTK(3, "connect :: scan_ind_count=%d\n",
priv->scan_ind_count);
if (!(priv->connect_status & FORCE_DISCONNECT))
netif_carrier_on(netdev);
tmp = FORCE_DISCONNECT & priv->connect_status;
priv->connect_status = tmp + CONNECT_STATUS;
break;
case RESULT_DISCONNECT:
DPRINTK(3, "disconnect :: scan_ind_count=%d\n",
priv->scan_ind_count);
netif_carrier_off(netdev);
tmp = FORCE_DISCONNECT & priv->connect_status;
priv->connect_status = tmp + DISCONNECT_STATUS;
break;
default:
DPRINTK(1, "unknown connect_code=%d :: scan_ind_count=%d\n",
connect_code, priv->scan_ind_count);
netif_carrier_off(netdev);
tmp = FORCE_DISCONNECT & priv->connect_status;
priv->connect_status = tmp + DISCONNECT_STATUS;
break;
}
get_current_ap(priv, (struct link_ap_info_t *)priv->rxp);
if (is_connect_status(priv->connect_status) &&
is_disconnect_status(old_status)) {
atomic_set(&priv->psstatus.snooze_guard, 0);
atomic_set(&priv->psstatus.confirm_wait, 0);
}
ks_wlan_do_power_save(priv);
wrqu0.data.length = 0;
wrqu0.data.flags = 0;
wrqu0.ap_addr.sa_family = ARPHRD_ETHER;
if (is_disconnect_status(priv->connect_status) &&
is_connect_status(old_status)) {
eth_zero_addr(wrqu0.ap_addr.sa_data);
DPRINTK(3, "IWEVENT: disconnect\n");
DPRINTK(3, "disconnect :: scan_ind_count=%d\n",
priv->scan_ind_count);
wireless_send_event(netdev, SIOCGIWAP, &wrqu0, NULL);
}
priv->scan_ind_count = 0;
}
static
void hostif_scan_indication(struct ks_wlan_private *priv)
{
int i;
struct ap_info_t *ap_info;
DPRINTK(3, "scan_ind_count = %d\n", priv->scan_ind_count);
ap_info = (struct ap_info_t *)(priv->rxp);
if (priv->scan_ind_count) {
for (i = 0; i < priv->aplist.size; i++) {
if (memcmp(ap_info->bssid,
priv->aplist.ap[i].bssid, ETH_ALEN) != 0)
continue;
if (ap_info->frame_type == FRAME_TYPE_PROBE_RESP)
get_ap_information(priv, ap_info,
&priv->aplist.ap[i]);
return;
}
}
priv->scan_ind_count++;
if (priv->scan_ind_count < LOCAL_APLIST_MAX + 1) {
DPRINTK(4, " scan_ind_count=%d :: aplist.size=%d\n",
priv->scan_ind_count, priv->aplist.size);
get_ap_information(priv, (struct ap_info_t *)(priv->rxp),
&(priv->aplist.ap[priv->scan_ind_count - 1]));
priv->aplist.size = priv->scan_ind_count;
} else {
DPRINTK(4, " count over :: scan_ind_count=%d\n",
priv->scan_ind_count);
}
}
static
void hostif_stop_confirm(struct ks_wlan_private *priv)
{
unsigned int tmp = 0;
unsigned int old_status = priv->connect_status;
struct net_device *netdev = priv->net_dev;
union iwreq_data wrqu0;
DPRINTK(3, "\n");
if (priv->dev_state == DEVICE_STATE_SLEEP)
priv->dev_state = DEVICE_STATE_READY;
if (is_connect_status(priv->connect_status)) {
netif_carrier_off(netdev);
tmp = FORCE_DISCONNECT & priv->connect_status;
priv->connect_status = tmp | DISCONNECT_STATUS;
netdev_info(netdev, "IWEVENT: disconnect\n");
wrqu0.data.length = 0;
wrqu0.data.flags = 0;
wrqu0.ap_addr.sa_family = ARPHRD_ETHER;
if (is_disconnect_status(priv->connect_status) &&
is_connect_status(old_status)) {
eth_zero_addr(wrqu0.ap_addr.sa_data);
DPRINTK(3, "IWEVENT: disconnect\n");
netdev_info(netdev, "IWEVENT: disconnect\n");
DPRINTK(3, "disconnect :: scan_ind_count=%d\n",
priv->scan_ind_count);
wireless_send_event(netdev, SIOCGIWAP, &wrqu0, NULL);
}
priv->scan_ind_count = 0;
}
hostif_sme_enqueue(priv, SME_STOP_CONFIRM);
}
static
void hostif_ps_adhoc_set_confirm(struct ks_wlan_private *priv)
{
DPRINTK(3, "\n");
priv->infra_status = 0;
hostif_sme_enqueue(priv, SME_MODE_SET_CONFIRM);
}
static
void hostif_infrastructure_set_confirm(struct ks_wlan_private *priv)
{
u16 result_code;
DPRINTK(3, "\n");
result_code = get_WORD(priv);
DPRINTK(3, "result code = %d\n", result_code);
priv->infra_status = 1;
hostif_sme_enqueue(priv, SME_MODE_SET_CONFIRM);
}
static
void hostif_adhoc_set_confirm(struct ks_wlan_private *priv)
{
DPRINTK(3, "\n");
priv->infra_status = 1;
hostif_sme_enqueue(priv, SME_MODE_SET_CONFIRM);
}
static
void hostif_associate_indication(struct ks_wlan_private *priv)
{
struct association_request_t *assoc_req;
struct association_response_t *assoc_resp;
unsigned char *pb;
union iwreq_data wrqu;
char buf[IW_CUSTOM_MAX];
char *pbuf = &buf[0];
int i;
static const char associnfo_leader0[] = "ASSOCINFO(ReqIEs=";
static const char associnfo_leader1[] = " RespIEs=";
DPRINTK(3, "\n");
assoc_req = (struct association_request_t *)(priv->rxp);
assoc_resp = (struct association_response_t *)(assoc_req + 1);
pb = (unsigned char *)(assoc_resp + 1);
memset(&wrqu, 0, sizeof(wrqu));
memcpy(pbuf, associnfo_leader0, sizeof(associnfo_leader0) - 1);
wrqu.data.length += sizeof(associnfo_leader0) - 1;
pbuf += sizeof(associnfo_leader0) - 1;
for (i = 0; i < le16_to_cpu(assoc_req->req_ies_size); i++)
pbuf += sprintf(pbuf, "%02x", *(pb + i));
wrqu.data.length += (le16_to_cpu(assoc_req->req_ies_size)) * 2;
memcpy(pbuf, associnfo_leader1, sizeof(associnfo_leader1) - 1);
wrqu.data.length += sizeof(associnfo_leader1) - 1;
pbuf += sizeof(associnfo_leader1) - 1;
pb += le16_to_cpu(assoc_req->req_ies_size);
for (i = 0; i < le16_to_cpu(assoc_resp->resp_ies_size); i++)
pbuf += sprintf(pbuf, "%02x", *(pb + i));
wrqu.data.length += (le16_to_cpu(assoc_resp->resp_ies_size)) * 2;
pbuf += sprintf(pbuf, ")");
wrqu.data.length += 1;
DPRINTK(3, "IWEVENT:ASSOCINFO\n");
wireless_send_event(priv->net_dev, IWEVCUSTOM, &wrqu, buf);
}
static
void hostif_bss_scan_confirm(struct ks_wlan_private *priv)
{
unsigned int result_code;
struct net_device *dev = priv->net_dev;
union iwreq_data wrqu;
result_code = get_DWORD(priv);
DPRINTK(2, "result=%d :: scan_ind_count=%d\n", result_code,
priv->scan_ind_count);
priv->sme_i.sme_flag &= ~SME_AP_SCAN;
hostif_sme_enqueue(priv, SME_BSS_SCAN_CONFIRM);
wrqu.data.length = 0;
wrqu.data.flags = 0;
DPRINTK(3, "IWEVENT: SCAN CONFIRM\n");
wireless_send_event(dev, SIOCGIWSCAN, &wrqu, NULL);
priv->scan_ind_count = 0;
}
static
void hostif_phy_information_confirm(struct ks_wlan_private *priv)
{
struct iw_statistics *wstats = &priv->wstats;
unsigned char rssi, signal, noise;
unsigned char link_speed;
unsigned int transmitted_frame_count, received_fragment_count;
unsigned int failed_count, fcs_error_count;
DPRINTK(3, "\n");
rssi = get_BYTE(priv);
signal = get_BYTE(priv);
noise = get_BYTE(priv);
link_speed = get_BYTE(priv);
transmitted_frame_count = get_DWORD(priv);
received_fragment_count = get_DWORD(priv);
failed_count = get_DWORD(priv);
fcs_error_count = get_DWORD(priv);
DPRINTK(4, "phyinfo confirm rssi=%d signal=%d\n", rssi, signal);
priv->current_rate = (link_speed & RATE_MASK);
wstats->qual.qual = signal;
wstats->qual.level = 256 - rssi;
wstats->qual.noise = 0;
wstats->qual.updated = IW_QUAL_ALL_UPDATED | IW_QUAL_DBM;
DPRINTK(3, "\n rssi=%u\n"
" signal=%u\n"
" link_speed=%ux500Kbps\n"
" transmitted_frame_count=%u\n"
" received_fragment_count=%u\n"
" failed_count=%u\n"
" fcs_error_count=%u\n",
rssi, signal, link_speed, transmitted_frame_count,
received_fragment_count, failed_count, fcs_error_count);
complete(&priv->confirm_wait);
}
static
void hostif_mic_failure_confirm(struct ks_wlan_private *priv)
{
DPRINTK(3, "mic_failure=%u\n", priv->wpa.mic_failure.failure);
hostif_sme_enqueue(priv, SME_MIC_FAILURE_CONFIRM);
}
static
void hostif_event_check(struct ks_wlan_private *priv)
{
unsigned short event;
DPRINTK(4, "\n");
event = get_WORD(priv);
switch (event) {
case HIF_DATA_IND:
hostif_data_indication(priv);
break;
case HIF_MIB_GET_CONF:
hostif_mib_get_confirm(priv);
break;
case HIF_MIB_SET_CONF:
hostif_mib_set_confirm(priv);
break;
case HIF_POWER_MGMT_CONF:
hostif_power_mgmt_confirm(priv);
break;
case HIF_SLEEP_CONF:
hostif_sleep_confirm(priv);
break;
case HIF_START_CONF:
hostif_start_confirm(priv);
break;
case HIF_CONNECT_IND:
hostif_connect_indication(priv);
break;
case HIF_STOP_CONF:
hostif_stop_confirm(priv);
break;
case HIF_PS_ADH_SET_CONF:
hostif_ps_adhoc_set_confirm(priv);
break;
case HIF_INFRA_SET_CONF:
case HIF_INFRA_SET2_CONF:
hostif_infrastructure_set_confirm(priv);
break;
case HIF_ADH_SET_CONF:
case HIF_ADH_SET2_CONF:
hostif_adhoc_set_confirm(priv);
break;
case HIF_ASSOC_INFO_IND:
hostif_associate_indication(priv);
break;
case HIF_MIC_FAILURE_CONF:
hostif_mic_failure_confirm(priv);
break;
case HIF_SCAN_CONF:
hostif_bss_scan_confirm(priv);
break;
case HIF_PHY_INFO_CONF:
case HIF_PHY_INFO_IND:
hostif_phy_information_confirm(priv);
break;
case HIF_SCAN_IND:
hostif_scan_indication(priv);
break;
case HIF_AP_SET_CONF:
default:
netdev_err(priv->net_dev, "undefined event[%04X]\n", event);
complete(&priv->confirm_wait);
break;
}
priv->hostt.buff[priv->hostt.qtail] = event;
priv->hostt.qtail = (priv->hostt.qtail + 1) % SME_EVENT_BUFF_SIZE;
}
static void *hostif_generic_request(size_t size, int event)
{
struct hostif_hdr *p;
p = kzalloc(hif_align_size(size), KS_WLAN_MEM_FLAG);
if (!p)
return NULL;
p->size = cpu_to_le16((u16)(size - sizeof(p->size)));
p->event = cpu_to_le16(event);
return p;
}
int hostif_data_request(struct ks_wlan_private *priv, struct sk_buff *skb)
{
unsigned int skb_len = 0;
unsigned char *buffer = NULL;
unsigned int length = 0;
struct hostif_data_request_t *pp;
unsigned char *p;
int result = 0;
unsigned short eth_proto;
struct ether_hdr *eth_hdr;
struct michael_mic_t michael_mic;
unsigned short keyinfo = 0;
struct ieee802_1x_hdr *aa1x_hdr;
struct wpa_eapol_key *eap_key;
struct ethhdr *eth;
size_t size;
int ret;
skb_len = skb->len;
if (skb_len > ETH_FRAME_LEN) {
DPRINTK(1, "bad length skb_len=%d\n", skb_len);
ret = -EOVERFLOW;
goto err_kfree_skb;
}
if (is_disconnect_status(priv->connect_status) ||
(priv->connect_status & FORCE_DISCONNECT) ||
priv->wpa.mic_failure.stop) {
DPRINTK(3, " DISCONNECT\n");
if (netif_queue_stopped(priv->net_dev))
netif_wake_queue(priv->net_dev);
if (skb)
dev_kfree_skb(skb);
return 0;
}
if (atomic_read(&priv->psstatus.status) == PS_SNOOZE) {
if (!netif_queue_stopped(priv->net_dev))
netif_stop_queue(priv->net_dev);
}
size = sizeof(*pp) + 6 + skb_len + 8;
pp = kmalloc(hif_align_size(size), KS_WLAN_MEM_FLAG);
if (!pp) {
ret = -ENOMEM;
goto err_kfree_skb;
}
p = (unsigned char *)pp->data;
buffer = skb->data;
length = skb->len;
eth = (struct ethhdr *)skb->data;
if (memcmp(&priv->eth_addr[0], eth->h_source, ETH_ALEN) != 0) {
DPRINTK(1, "invalid mac address !!\n");
DPRINTK(1, "ethernet->h_source=%pM\n", eth->h_source);
ret = -ENXIO;
goto err_kfree;
}
size = ETH_ALEN * 2;
memcpy(p, buffer, size);
p += size;
buffer += size;
length -= size;
if (*(buffer + 1) + (*buffer << 8) > 1500) {
*p++ = 0xAA;
*p++ = 0xAA;
*p++ = 0x03;
*p++ = 0x00;
*p++ = 0x00;
*p++ = 0x00;
skb_len += 6;
} else {
DPRINTK(4, "DIX\n");
buffer += 2;
length -= 2;
skb_len -= 2;
}
memcpy(p, buffer, length);
p += length;
eth_hdr = (struct ether_hdr *)&pp->data[0];
eth_proto = ntohs(eth_hdr->h_proto);
if (eth_proto == ETHER_PROTOCOL_TYPE_EAP &&
priv->wpa.mic_failure.failure > 0) {
aa1x_hdr = (struct ieee802_1x_hdr *)(eth_hdr + 1);
if (aa1x_hdr->type == IEEE802_1X_TYPE_EAPOL_KEY) {
eap_key = (struct wpa_eapol_key *)(aa1x_hdr + 1);
keyinfo = ntohs(eap_key->key_info);
}
}
if (priv->wpa.rsn_enabled && priv->wpa.key[0].key_len) {
if (eth_proto == ETHER_PROTOCOL_TYPE_EAP &&
priv->wpa.key[1].key_len == 0 &&
priv->wpa.key[2].key_len == 0 &&
priv->wpa.key[3].key_len == 0) {
pp->auth_type = cpu_to_le16((uint16_t)TYPE_AUTH);
} else {
if (priv->wpa.pairwise_suite == IW_AUTH_CIPHER_TKIP) {
MichaelMICFunction(&michael_mic,
(uint8_t *)priv->wpa.key[0].tx_mic_key,
(uint8_t *)&pp->data[0],
(int)skb_len,
(uint8_t)0,
(uint8_t *)michael_mic.Result);
memcpy(p, michael_mic.Result, 8);
length += 8;
skb_len += 8;
p += 8;
pp->auth_type =
cpu_to_le16((uint16_t)TYPE_DATA);
} else if (priv->wpa.pairwise_suite ==
IW_AUTH_CIPHER_CCMP) {
pp->auth_type =
cpu_to_le16((uint16_t)TYPE_DATA);
}
}
} else {
if (eth_proto == ETHER_PROTOCOL_TYPE_EAP)
pp->auth_type = cpu_to_le16((uint16_t)TYPE_AUTH);
else
pp->auth_type = cpu_to_le16((uint16_t)TYPE_DATA);
}
pp->header.size =
cpu_to_le16((uint16_t)
(sizeof(*pp) - sizeof(pp->header.size) + skb_len));
pp->header.event = cpu_to_le16((uint16_t)HIF_DATA_REQ);
result = ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp) + skb_len),
send_packet_complete, skb);
if (eth_proto == ETHER_PROTOCOL_TYPE_EAP &&
priv->wpa.mic_failure.failure > 0) {
if (keyinfo & WPA_KEY_INFO_ERROR &&
keyinfo & WPA_KEY_INFO_REQUEST) {
DPRINTK(3, " MIC ERROR Report SET : %04X\n", keyinfo);
hostif_sme_enqueue(priv, SME_MIC_FAILURE_REQUEST);
}
if (priv->wpa.mic_failure.failure == 2)
priv->wpa.mic_failure.stop = 1;
}
return result;
err_kfree:
kfree(pp);
err_kfree_skb:
dev_kfree_skb(skb);
return ret;
}
static
void hostif_mib_get_request(struct ks_wlan_private *priv,
unsigned long mib_attribute)
{
struct hostif_mib_get_request_t *pp;
DPRINTK(3, "\n");
pp = hostif_generic_request(sizeof(*pp), HIF_MIB_GET_REQ);
if (!pp)
return;
pp->mib_attribute = cpu_to_le32((uint32_t)mib_attribute);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static
void hostif_mib_set_request(struct ks_wlan_private *priv,
unsigned long mib_attribute, unsigned short size,
unsigned short type, void *vp)
{
struct hostif_mib_set_request_t *pp;
DPRINTK(3, "\n");
if (priv->dev_state < DEVICE_STATE_BOOT) {
DPRINTK(3, "DeviceRemove\n");
return;
}
pp = hostif_generic_request(sizeof(*pp), HIF_MIB_SET_REQ);
if (!pp)
return;
pp->mib_attribute = cpu_to_le32((uint32_t)mib_attribute);
pp->mib_value.size = cpu_to_le16((uint16_t)size);
pp->mib_value.type = cpu_to_le16((uint16_t)type);
memcpy(&pp->mib_value.body, vp, size);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp) + size), NULL, NULL);
}
static
void hostif_start_request(struct ks_wlan_private *priv, unsigned char mode)
{
struct hostif_start_request_t *pp;
DPRINTK(3, "\n");
pp = hostif_generic_request(sizeof(*pp), HIF_START_REQ);
if (!pp)
return;
pp->mode = cpu_to_le16((uint16_t)mode);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
priv->aplist.size = 0;
priv->scan_ind_count = 0;
}
static
void hostif_ps_adhoc_set_request(struct ks_wlan_private *priv)
{
struct hostif_ps_adhoc_set_request_t *pp;
u16 capability;
DPRINTK(3, "\n");
pp = hostif_generic_request(sizeof(*pp), HIF_PS_ADH_SET_REQ);
if (!pp)
return;
pp->phy_type = cpu_to_le16((uint16_t)(priv->reg.phy_type));
pp->cts_mode = cpu_to_le16((uint16_t)(priv->reg.cts_mode));
pp->scan_type = cpu_to_le16((uint16_t)(priv->reg.scan_type));
pp->channel = cpu_to_le16((uint16_t)(priv->reg.channel));
pp->rate_set.size = priv->reg.rate_set.size;
memcpy(&pp->rate_set.body[0], &priv->reg.rate_set.body[0],
priv->reg.rate_set.size);
capability = 0x0000;
if (priv->reg.preamble == SHORT_PREAMBLE) {
capability |= BSS_CAP_SHORT_PREAMBLE;
}
capability &= ~(BSS_CAP_PBCC);
if (priv->reg.phy_type != D_11B_ONLY_MODE) {
capability |= BSS_CAP_SHORT_SLOT_TIME;
capability &= ~(BSS_CAP_DSSS_OFDM);
}
pp->capability = cpu_to_le16((uint16_t)capability);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static
void hostif_infrastructure_set_request(struct ks_wlan_private *priv)
{
struct hostif_infrastructure_set_request_t *pp;
u16 capability;
DPRINTK(3, "ssid.size=%d\n", priv->reg.ssid.size);
pp = hostif_generic_request(sizeof(*pp), HIF_INFRA_SET_REQ);
if (!pp)
return;
pp->phy_type = cpu_to_le16((uint16_t)(priv->reg.phy_type));
pp->cts_mode = cpu_to_le16((uint16_t)(priv->reg.cts_mode));
pp->scan_type = cpu_to_le16((uint16_t)(priv->reg.scan_type));
pp->rate_set.size = priv->reg.rate_set.size;
memcpy(&pp->rate_set.body[0], &priv->reg.rate_set.body[0],
priv->reg.rate_set.size);
pp->ssid.size = priv->reg.ssid.size;
memcpy(&pp->ssid.body[0], &priv->reg.ssid.body[0], priv->reg.ssid.size);
capability = 0x0000;
if (priv->reg.preamble == SHORT_PREAMBLE) {
capability |= BSS_CAP_SHORT_PREAMBLE;
}
capability &= ~(BSS_CAP_PBCC);
if (priv->reg.phy_type != D_11B_ONLY_MODE) {
capability |= BSS_CAP_SHORT_SLOT_TIME;
capability &= ~(BSS_CAP_DSSS_OFDM);
}
pp->capability = cpu_to_le16((uint16_t)capability);
pp->beacon_lost_count =
cpu_to_le16((uint16_t)(priv->reg.beacon_lost_count));
pp->auth_type = cpu_to_le16((uint16_t)(priv->reg.authenticate_type));
pp->channel_list.body[0] = 1;
pp->channel_list.body[1] = 8;
pp->channel_list.body[2] = 2;
pp->channel_list.body[3] = 9;
pp->channel_list.body[4] = 3;
pp->channel_list.body[5] = 10;
pp->channel_list.body[6] = 4;
pp->channel_list.body[7] = 11;
pp->channel_list.body[8] = 5;
pp->channel_list.body[9] = 12;
pp->channel_list.body[10] = 6;
pp->channel_list.body[11] = 13;
pp->channel_list.body[12] = 7;
if (priv->reg.phy_type == D_11G_ONLY_MODE) {
pp->channel_list.size = 13;
} else {
pp->channel_list.body[13] = 14;
pp->channel_list.size = 14;
}
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static void hostif_infrastructure_set2_request(struct ks_wlan_private *priv)
{
struct hostif_infrastructure_set2_request_t *pp;
u16 capability;
DPRINTK(2, "ssid.size=%d\n", priv->reg.ssid.size);
pp = hostif_generic_request(sizeof(*pp), HIF_INFRA_SET2_REQ);
if (!pp)
return;
pp->phy_type = cpu_to_le16((uint16_t)(priv->reg.phy_type));
pp->cts_mode = cpu_to_le16((uint16_t)(priv->reg.cts_mode));
pp->scan_type = cpu_to_le16((uint16_t)(priv->reg.scan_type));
pp->rate_set.size = priv->reg.rate_set.size;
memcpy(&pp->rate_set.body[0], &priv->reg.rate_set.body[0],
priv->reg.rate_set.size);
pp->ssid.size = priv->reg.ssid.size;
memcpy(&pp->ssid.body[0], &priv->reg.ssid.body[0], priv->reg.ssid.size);
capability = 0x0000;
if (priv->reg.preamble == SHORT_PREAMBLE) {
capability |= BSS_CAP_SHORT_PREAMBLE;
}
capability &= ~(BSS_CAP_PBCC);
if (priv->reg.phy_type != D_11B_ONLY_MODE) {
capability |= BSS_CAP_SHORT_SLOT_TIME;
capability &= ~(BSS_CAP_DSSS_OFDM);
}
pp->capability = cpu_to_le16((uint16_t)capability);
pp->beacon_lost_count =
cpu_to_le16((uint16_t)(priv->reg.beacon_lost_count));
pp->auth_type = cpu_to_le16((uint16_t)(priv->reg.authenticate_type));
pp->channel_list.body[0] = 1;
pp->channel_list.body[1] = 8;
pp->channel_list.body[2] = 2;
pp->channel_list.body[3] = 9;
pp->channel_list.body[4] = 3;
pp->channel_list.body[5] = 10;
pp->channel_list.body[6] = 4;
pp->channel_list.body[7] = 11;
pp->channel_list.body[8] = 5;
pp->channel_list.body[9] = 12;
pp->channel_list.body[10] = 6;
pp->channel_list.body[11] = 13;
pp->channel_list.body[12] = 7;
if (priv->reg.phy_type == D_11G_ONLY_MODE) {
pp->channel_list.size = 13;
} else {
pp->channel_list.body[13] = 14;
pp->channel_list.size = 14;
}
memcpy(pp->bssid, priv->reg.bssid, ETH_ALEN);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static
void hostif_adhoc_set_request(struct ks_wlan_private *priv)
{
struct hostif_adhoc_set_request_t *pp;
u16 capability;
DPRINTK(3, "\n");
pp = hostif_generic_request(sizeof(*pp), HIF_ADH_SET_REQ);
if (!pp)
return;
pp->phy_type = cpu_to_le16((uint16_t)(priv->reg.phy_type));
pp->cts_mode = cpu_to_le16((uint16_t)(priv->reg.cts_mode));
pp->scan_type = cpu_to_le16((uint16_t)(priv->reg.scan_type));
pp->channel = cpu_to_le16((uint16_t)(priv->reg.channel));
pp->rate_set.size = priv->reg.rate_set.size;
memcpy(&pp->rate_set.body[0], &priv->reg.rate_set.body[0],
priv->reg.rate_set.size);
pp->ssid.size = priv->reg.ssid.size;
memcpy(&pp->ssid.body[0], &priv->reg.ssid.body[0], priv->reg.ssid.size);
capability = 0x0000;
if (priv->reg.preamble == SHORT_PREAMBLE) {
capability |= BSS_CAP_SHORT_PREAMBLE;
}
capability &= ~(BSS_CAP_PBCC);
if (priv->reg.phy_type != D_11B_ONLY_MODE) {
capability |= BSS_CAP_SHORT_SLOT_TIME;
capability &= ~(BSS_CAP_DSSS_OFDM);
}
pp->capability = cpu_to_le16((uint16_t)capability);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static
void hostif_adhoc_set2_request(struct ks_wlan_private *priv)
{
struct hostif_adhoc_set2_request_t *pp;
u16 capability;
DPRINTK(3, "\n");
pp = hostif_generic_request(sizeof(*pp), HIF_ADH_SET_REQ);
if (!pp)
return;
pp->phy_type = cpu_to_le16((uint16_t)(priv->reg.phy_type));
pp->cts_mode = cpu_to_le16((uint16_t)(priv->reg.cts_mode));
pp->scan_type = cpu_to_le16((uint16_t)(priv->reg.scan_type));
pp->rate_set.size = priv->reg.rate_set.size;
memcpy(&pp->rate_set.body[0], &priv->reg.rate_set.body[0],
priv->reg.rate_set.size);
pp->ssid.size = priv->reg.ssid.size;
memcpy(&pp->ssid.body[0], &priv->reg.ssid.body[0], priv->reg.ssid.size);
capability = 0x0000;
if (priv->reg.preamble == SHORT_PREAMBLE) {
capability |= BSS_CAP_SHORT_PREAMBLE;
}
capability &= ~(BSS_CAP_PBCC);
if (priv->reg.phy_type != D_11B_ONLY_MODE) {
capability |= BSS_CAP_SHORT_SLOT_TIME;
capability &= ~(BSS_CAP_DSSS_OFDM);
}
pp->capability = cpu_to_le16((uint16_t)capability);
pp->channel_list.body[0] = priv->reg.channel;
pp->channel_list.size = 1;
memcpy(pp->bssid, priv->reg.bssid, ETH_ALEN);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static
void hostif_stop_request(struct ks_wlan_private *priv)
{
struct hostif_stop_request_t *pp;
DPRINTK(3, "\n");
pp = hostif_generic_request(sizeof(*pp), HIF_STOP_REQ);
if (!pp)
return;
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static
void hostif_phy_information_request(struct ks_wlan_private *priv)
{
struct hostif_phy_information_request_t *pp;
DPRINTK(3, "\n");
pp = hostif_generic_request(sizeof(*pp), HIF_PHY_INFO_REQ);
if (!pp)
return;
if (priv->reg.phy_info_timer) {
pp->type = cpu_to_le16((uint16_t)TIME_TYPE);
pp->time = cpu_to_le16((uint16_t)(priv->reg.phy_info_timer));
} else {
pp->type = cpu_to_le16((uint16_t)NORMAL_TYPE);
pp->time = cpu_to_le16((uint16_t)0);
}
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static
void hostif_power_mgmt_request(struct ks_wlan_private *priv,
unsigned long mode, unsigned long wake_up,
unsigned long receive_dtims)
{
struct hostif_power_mgmt_request_t *pp;
DPRINTK(3, "mode=%lu wake_up=%lu receive_dtims=%lu\n", mode, wake_up,
receive_dtims);
pp = hostif_generic_request(sizeof(*pp), HIF_POWER_MGMT_REQ);
if (!pp)
return;
pp->mode = cpu_to_le32((uint32_t)mode);
pp->wake_up = cpu_to_le32((uint32_t)wake_up);
pp->receive_dtims = cpu_to_le32((uint32_t)receive_dtims);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static
void hostif_sleep_request(struct ks_wlan_private *priv,
enum sleep_mode_type mode)
{
struct hostif_sleep_request_t *pp;
DPRINTK(3, "mode=%lu\n", (long)mode);
if (mode == SLP_SLEEP) {
pp = hostif_generic_request(sizeof(*pp), HIF_SLEEP_REQ);
if (!pp)
return;
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL,
NULL);
} else if (mode == SLP_ACTIVE) {
atomic_set(&priv->sleepstatus.wakeup_request, 1);
queue_delayed_work(priv->wq, &priv->rw_dwork, 1);
} else {
DPRINTK(3, "invalid mode %ld\n", (long)mode);
return;
}
}
static
void hostif_bss_scan_request(struct ks_wlan_private *priv,
unsigned long scan_type, uint8_t *scan_ssid,
uint8_t scan_ssid_len)
{
struct hostif_bss_scan_request_t *pp;
DPRINTK(2, "\n");
pp = hostif_generic_request(sizeof(*pp), HIF_SCAN_REQ);
if (!pp)
return;
pp->scan_type = scan_type;
pp->ch_time_min = cpu_to_le32((uint32_t)110);
pp->ch_time_max = cpu_to_le32((uint32_t)130);
pp->channel_list.body[0] = 1;
pp->channel_list.body[1] = 8;
pp->channel_list.body[2] = 2;
pp->channel_list.body[3] = 9;
pp->channel_list.body[4] = 3;
pp->channel_list.body[5] = 10;
pp->channel_list.body[6] = 4;
pp->channel_list.body[7] = 11;
pp->channel_list.body[8] = 5;
pp->channel_list.body[9] = 12;
pp->channel_list.body[10] = 6;
pp->channel_list.body[11] = 13;
pp->channel_list.body[12] = 7;
if (priv->reg.phy_type == D_11G_ONLY_MODE) {
pp->channel_list.size = 13;
} else {
pp->channel_list.body[13] = 14;
pp->channel_list.size = 14;
}
pp->ssid.size = 0;
if (scan_ssid_len > 0 && scan_ssid_len <= 32) {
pp->ssid.size = scan_ssid_len;
memcpy(&pp->ssid.body[0], scan_ssid, scan_ssid_len);
}
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
priv->aplist.size = 0;
priv->scan_ind_count = 0;
}
static
void hostif_mic_failure_request(struct ks_wlan_private *priv,
unsigned short failure_count,
unsigned short timer)
{
struct hostif_mic_failure_request_t *pp;
DPRINTK(3, "count=%d :: timer=%d\n", failure_count, timer);
pp = hostif_generic_request(sizeof(*pp), HIF_MIC_FAILURE_REQ);
if (!pp)
return;
pp->failure_count = cpu_to_le16((uint16_t)failure_count);
pp->timer = cpu_to_le16((uint16_t)timer);
ps_confirm_wait_inc(priv);
ks_wlan_hw_tx(priv, pp, hif_align_size(sizeof(*pp)), NULL, NULL);
}
static void devio_rec_ind(struct ks_wlan_private *priv, unsigned char *p,
unsigned int size)
{
if (priv->device_open_status) {
spin_lock(&priv->dev_read_lock);
priv->dev_data[atomic_read(&priv->rec_count)] = p;
priv->dev_size[atomic_read(&priv->rec_count)] = size;
if (atomic_read(&priv->event_count) != DEVICE_STOCK_COUNT) {
atomic_inc(&priv->event_count);
}
atomic_inc(&priv->rec_count);
if (atomic_read(&priv->rec_count) == DEVICE_STOCK_COUNT)
atomic_set(&priv->rec_count, 0);
wake_up_interruptible_all(&priv->devread_wait);
spin_unlock(&priv->dev_read_lock);
}
}
void hostif_receive(struct ks_wlan_private *priv, unsigned char *p,
unsigned int size)
{
DPRINTK(4, "\n");
devio_rec_ind(priv, p, size);
priv->rxp = p;
priv->rx_size = size;
if (get_WORD(priv) == priv->rx_size) {
hostif_event_check(priv);
}
}
static
void hostif_sme_set_wep(struct ks_wlan_private *priv, int type)
{
__le32 val;
switch (type) {
case SME_WEP_INDEX_REQUEST:
val = cpu_to_le32((uint32_t)(priv->reg.wep_index));
hostif_mib_set_request(priv, DOT11_WEP_DEFAULT_KEY_ID,
sizeof(val), MIB_VALUE_TYPE_INT, &val);
break;
case SME_WEP_KEY1_REQUEST:
if (!priv->wpa.wpa_enabled)
hostif_mib_set_request(priv,
DOT11_WEP_DEFAULT_KEY_VALUE1,
priv->reg.wep_key[0].size,
MIB_VALUE_TYPE_OSTRING,
&priv->reg.wep_key[0].val[0]);
break;
case SME_WEP_KEY2_REQUEST:
if (!priv->wpa.wpa_enabled)
hostif_mib_set_request(priv,
DOT11_WEP_DEFAULT_KEY_VALUE2,
priv->reg.wep_key[1].size,
MIB_VALUE_TYPE_OSTRING,
&priv->reg.wep_key[1].val[0]);
break;
case SME_WEP_KEY3_REQUEST:
if (!priv->wpa.wpa_enabled)
hostif_mib_set_request(priv,
DOT11_WEP_DEFAULT_KEY_VALUE3,
priv->reg.wep_key[2].size,
MIB_VALUE_TYPE_OSTRING,
&priv->reg.wep_key[2].val[0]);
break;
case SME_WEP_KEY4_REQUEST:
if (!priv->wpa.wpa_enabled)
hostif_mib_set_request(priv,
DOT11_WEP_DEFAULT_KEY_VALUE4,
priv->reg.wep_key[3].size,
MIB_VALUE_TYPE_OSTRING,
&priv->reg.wep_key[3].val[0]);
break;
case SME_WEP_FLAG_REQUEST:
val = cpu_to_le32((uint32_t)(priv->reg.privacy_invoked));
hostif_mib_set_request(priv, DOT11_PRIVACY_INVOKED,
sizeof(val), MIB_VALUE_TYPE_BOOL, &val);
break;
}
}
static
void hostif_sme_set_rsn(struct ks_wlan_private *priv, int type)
{
struct wpa_suite_t wpa_suite;
struct rsn_mode_t rsn_mode;
__le32 val;
memset(&wpa_suite, 0, sizeof(wpa_suite));
switch (type) {
case SME_RSN_UCAST_REQUEST:
wpa_suite.size = cpu_to_le16((uint16_t)1);
switch (priv->wpa.pairwise_suite) {
case IW_AUTH_CIPHER_NONE:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_NONE, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_NONE, CIPHER_ID_LEN);
break;
case IW_AUTH_CIPHER_WEP40:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_WEP40, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_WEP40, CIPHER_ID_LEN);
break;
case IW_AUTH_CIPHER_TKIP:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_TKIP, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_TKIP, CIPHER_ID_LEN);
break;
case IW_AUTH_CIPHER_CCMP:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_CCMP, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_CCMP, CIPHER_ID_LEN);
break;
case IW_AUTH_CIPHER_WEP104:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_WEP104, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_WEP104, CIPHER_ID_LEN);
break;
}
hostif_mib_set_request(priv, DOT11_RSN_CONFIG_UNICAST_CIPHER,
sizeof(wpa_suite.size) +
CIPHER_ID_LEN *
le16_to_cpu(wpa_suite.size),
MIB_VALUE_TYPE_OSTRING, &wpa_suite);
break;
case SME_RSN_MCAST_REQUEST:
switch (priv->wpa.group_suite) {
case IW_AUTH_CIPHER_NONE:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_NONE, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_NONE, CIPHER_ID_LEN);
break;
case IW_AUTH_CIPHER_WEP40:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_WEP40, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_WEP40, CIPHER_ID_LEN);
break;
case IW_AUTH_CIPHER_TKIP:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_TKIP, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_TKIP, CIPHER_ID_LEN);
break;
case IW_AUTH_CIPHER_CCMP:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_CCMP, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_CCMP, CIPHER_ID_LEN);
break;
case IW_AUTH_CIPHER_WEP104:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA2_WEP104, CIPHER_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
CIPHER_ID_WPA_WEP104, CIPHER_ID_LEN);
break;
}
hostif_mib_set_request(priv, DOT11_RSN_CONFIG_MULTICAST_CIPHER,
CIPHER_ID_LEN, MIB_VALUE_TYPE_OSTRING,
&wpa_suite.suite[0][0]);
break;
case SME_RSN_AUTH_REQUEST:
wpa_suite.size = cpu_to_le16((uint16_t)1);
switch (priv->wpa.key_mgmt_suite) {
case IW_AUTH_KEY_MGMT_802_1X:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
KEY_MGMT_ID_WPA2_1X, KEY_MGMT_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
KEY_MGMT_ID_WPA_1X, KEY_MGMT_ID_LEN);
break;
case IW_AUTH_KEY_MGMT_PSK:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
KEY_MGMT_ID_WPA2_PSK, KEY_MGMT_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
KEY_MGMT_ID_WPA_PSK, KEY_MGMT_ID_LEN);
break;
case 0:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
KEY_MGMT_ID_WPA2_NONE, KEY_MGMT_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
KEY_MGMT_ID_WPA_NONE, KEY_MGMT_ID_LEN);
break;
case 4:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2)
memcpy(&wpa_suite.suite[0][0],
KEY_MGMT_ID_WPA2_WPANONE,
KEY_MGMT_ID_LEN);
else
memcpy(&wpa_suite.suite[0][0],
KEY_MGMT_ID_WPA_WPANONE,
KEY_MGMT_ID_LEN);
break;
}
hostif_mib_set_request(priv, DOT11_RSN_CONFIG_AUTH_SUITE,
sizeof(wpa_suite.size) +
KEY_MGMT_ID_LEN *
le16_to_cpu(wpa_suite.size),
MIB_VALUE_TYPE_OSTRING, &wpa_suite);
break;
case SME_RSN_ENABLED_REQUEST:
val = cpu_to_le32((uint32_t)(priv->wpa.rsn_enabled));
hostif_mib_set_request(priv, DOT11_RSN_ENABLED,
sizeof(val), MIB_VALUE_TYPE_BOOL, &val);
break;
case SME_RSN_MODE_REQUEST:
if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA2) {
rsn_mode.rsn_mode =
cpu_to_le32((uint32_t)RSN_MODE_WPA2);
rsn_mode.rsn_capability = cpu_to_le16((uint16_t)0);
} else if (priv->wpa.version == IW_AUTH_WPA_VERSION_WPA) {
rsn_mode.rsn_mode =
cpu_to_le32((uint32_t)RSN_MODE_WPA);
rsn_mode.rsn_capability = cpu_to_le16((uint16_t)0);
} else {
rsn_mode.rsn_mode =
cpu_to_le32((uint32_t)RSN_MODE_NONE);
rsn_mode.rsn_capability = cpu_to_le16((uint16_t)0);
}
hostif_mib_set_request(priv, LOCAL_RSN_MODE, sizeof(rsn_mode),
MIB_VALUE_TYPE_OSTRING, &rsn_mode);
break;
}
}
static
void hostif_sme_mode_setup(struct ks_wlan_private *priv)
{
unsigned char rate_size;
unsigned char rate_octet[RATE_SET_MAX_SIZE];
int i = 0;
if (priv->reg.tx_rate == TX_RATE_FULL_AUTO) {
if (priv->reg.phy_type == D_11B_ONLY_MODE) {
priv->reg.rate_set.body[3] = TX_RATE_11M;
priv->reg.rate_set.body[2] = TX_RATE_5M;
priv->reg.rate_set.body[1] = TX_RATE_2M | BASIC_RATE;
priv->reg.rate_set.body[0] = TX_RATE_1M | BASIC_RATE;
priv->reg.rate_set.size = 4;
} else {
priv->reg.rate_set.body[11] = TX_RATE_54M;
priv->reg.rate_set.body[10] = TX_RATE_48M;
priv->reg.rate_set.body[9] = TX_RATE_36M;
priv->reg.rate_set.body[8] = TX_RATE_18M;
priv->reg.rate_set.body[7] = TX_RATE_9M;
priv->reg.rate_set.body[6] = TX_RATE_24M | BASIC_RATE;
priv->reg.rate_set.body[5] = TX_RATE_12M | BASIC_RATE;
priv->reg.rate_set.body[4] = TX_RATE_6M | BASIC_RATE;
priv->reg.rate_set.body[3] = TX_RATE_11M | BASIC_RATE;
priv->reg.rate_set.body[2] = TX_RATE_5M | BASIC_RATE;
priv->reg.rate_set.body[1] = TX_RATE_2M | BASIC_RATE;
priv->reg.rate_set.body[0] = TX_RATE_1M | BASIC_RATE;
priv->reg.rate_set.size = 12;
}
}
if (priv->reg.phy_type == D_11B_ONLY_MODE) {
for (i = 0; i < priv->reg.rate_set.size; i++) {
if (!IS_11B_RATE(priv->reg.rate_set.body[i]))
break;
if ((priv->reg.rate_set.body[i] & RATE_MASK) >= TX_RATE_5M) {
rate_octet[i] = priv->reg.rate_set.body[i] &
RATE_MASK;
} else {
rate_octet[i] = priv->reg.rate_set.body[i];
}
}
} else {
for (i = 0; i < priv->reg.rate_set.size; i++) {
if (!IS_11BG_RATE(priv->reg.rate_set.body[i]))
break;
if (IS_OFDM_EXT_RATE(priv->reg.rate_set.body[i])) {
rate_octet[i] = priv->reg.rate_set.body[i] &
RATE_MASK;
} else {
rate_octet[i] = priv->reg.rate_set.body[i];
}
}
}
rate_size = i;
if (rate_size == 0) {
if (priv->reg.phy_type == D_11G_ONLY_MODE)
rate_octet[0] = TX_RATE_6M | BASIC_RATE;
else
rate_octet[0] = TX_RATE_2M | BASIC_RATE;
rate_size = 1;
}
priv->reg.rate_set.size = rate_size;
memcpy(&priv->reg.rate_set.body[0], &rate_octet[0], rate_size);
switch (priv->reg.operation_mode) {
case MODE_PSEUDO_ADHOC:
hostif_ps_adhoc_set_request(priv);
break;
case MODE_INFRASTRUCTURE:
if (!is_valid_ether_addr((u8 *)priv->reg.bssid)) {
hostif_infrastructure_set_request(priv);
} else {
hostif_infrastructure_set2_request(priv);
DPRINTK(2,
"Infra bssid = %pM\n", priv->reg.bssid);
}
break;
case MODE_ADHOC:
if (!is_valid_ether_addr((u8 *)priv->reg.bssid)) {
hostif_adhoc_set_request(priv);
} else {
hostif_adhoc_set2_request(priv);
DPRINTK(2,
"Adhoc bssid = %pM\n", priv->reg.bssid);
}
break;
default:
break;
}
}
static
void hostif_sme_multicast_set(struct ks_wlan_private *priv)
{
struct net_device *dev = priv->net_dev;
int mc_count;
struct netdev_hw_addr *ha;
char set_address[NIC_MAX_MCAST_LIST * ETH_ALEN];
__le32 filter_type;
int i = 0;
DPRINTK(3, "\n");
spin_lock(&priv->multicast_spin);
memset(set_address, 0, NIC_MAX_MCAST_LIST * ETH_ALEN);
if (dev->flags & IFF_PROMISC) {
filter_type = cpu_to_le32((uint32_t)MCAST_FILTER_PROMISC);
hostif_mib_set_request(priv, LOCAL_MULTICAST_FILTER,
sizeof(filter_type), MIB_VALUE_TYPE_BOOL,
&filter_type);
goto spin_unlock;
}
if ((netdev_mc_count(dev) > NIC_MAX_MCAST_LIST) ||
(dev->flags & IFF_ALLMULTI)) {
filter_type = cpu_to_le32((uint32_t)MCAST_FILTER_MCASTALL);
hostif_mib_set_request(priv, LOCAL_MULTICAST_FILTER,
sizeof(filter_type), MIB_VALUE_TYPE_BOOL,
&filter_type);
goto spin_unlock;
}
if (priv->sme_i.sme_flag & SME_MULTICAST) {
mc_count = netdev_mc_count(dev);
netdev_for_each_mc_addr(ha, dev) {
memcpy(&set_address[i * ETH_ALEN], ha->addr, ETH_ALEN);
i++;
}
priv->sme_i.sme_flag &= ~SME_MULTICAST;
hostif_mib_set_request(priv, LOCAL_MULTICAST_ADDRESS,
ETH_ALEN * mc_count,
MIB_VALUE_TYPE_OSTRING,
&set_address[0]);
} else {
filter_type = cpu_to_le32((uint32_t)MCAST_FILTER_MCAST);
priv->sme_i.sme_flag |= SME_MULTICAST;
hostif_mib_set_request(priv, LOCAL_MULTICAST_FILTER,
sizeof(filter_type), MIB_VALUE_TYPE_BOOL,
&filter_type);
}
spin_unlock:
spin_unlock(&priv->multicast_spin);
}
static
void hostif_sme_power_mgmt_set(struct ks_wlan_private *priv)
{
unsigned long mode, wake_up, receive_dtims;
DPRINTK(3, "\n");
switch (priv->reg.power_mgmt) {
case POWER_MGMT_ACTIVE:
mode = POWER_ACTIVE;
wake_up = 0;
receive_dtims = 0;
break;
case POWER_MGMT_SAVE1:
if (priv->reg.operation_mode == MODE_INFRASTRUCTURE) {
mode = POWER_SAVE;
wake_up = 0;
receive_dtims = 0;
} else {
mode = POWER_ACTIVE;
wake_up = 0;
receive_dtims = 0;
}
break;
case POWER_MGMT_SAVE2:
if (priv->reg.operation_mode == MODE_INFRASTRUCTURE) {
mode = POWER_SAVE;
wake_up = 0;
receive_dtims = 1;
} else {
mode = POWER_ACTIVE;
wake_up = 0;
receive_dtims = 0;
}
break;
default:
mode = POWER_ACTIVE;
wake_up = 0;
receive_dtims = 0;
break;
}
hostif_power_mgmt_request(priv, mode, wake_up, receive_dtims);
}
static
void hostif_sme_sleep_set(struct ks_wlan_private *priv)
{
DPRINTK(3, "\n");
switch (priv->sleep_mode) {
case SLP_SLEEP:
hostif_sleep_request(priv, priv->sleep_mode);
break;
case SLP_ACTIVE:
hostif_sleep_request(priv, priv->sleep_mode);
break;
default:
break;
}
}
static
void hostif_sme_set_key(struct ks_wlan_private *priv, int type)
{
__le32 val;
switch (type) {
case SME_SET_FLAG:
val = cpu_to_le32((uint32_t)(priv->reg.privacy_invoked));
hostif_mib_set_request(priv, DOT11_PRIVACY_INVOKED,
sizeof(val), MIB_VALUE_TYPE_BOOL, &val);
break;
case SME_SET_TXKEY:
val = cpu_to_le32((uint32_t)(priv->wpa.txkey));
hostif_mib_set_request(priv, DOT11_WEP_DEFAULT_KEY_ID,
sizeof(val), MIB_VALUE_TYPE_INT, &val);
break;
case SME_SET_KEY1:
hostif_mib_set_request(priv, DOT11_WEP_DEFAULT_KEY_VALUE1,
priv->wpa.key[0].key_len,
MIB_VALUE_TYPE_OSTRING,
&priv->wpa.key[0].key_val[0]);
break;
case SME_SET_KEY2:
hostif_mib_set_request(priv, DOT11_WEP_DEFAULT_KEY_VALUE2,
priv->wpa.key[1].key_len,
MIB_VALUE_TYPE_OSTRING,
&priv->wpa.key[1].key_val[0]);
break;
case SME_SET_KEY3:
hostif_mib_set_request(priv, DOT11_WEP_DEFAULT_KEY_VALUE3,
priv->wpa.key[2].key_len,
MIB_VALUE_TYPE_OSTRING,
&priv->wpa.key[2].key_val[0]);
break;
case SME_SET_KEY4:
hostif_mib_set_request(priv, DOT11_WEP_DEFAULT_KEY_VALUE4,
priv->wpa.key[3].key_len,
MIB_VALUE_TYPE_OSTRING,
&priv->wpa.key[3].key_val[0]);
break;
case SME_SET_PMK_TSC:
hostif_mib_set_request(priv, DOT11_PMK_TSC,
WPA_RX_SEQ_LEN, MIB_VALUE_TYPE_OSTRING,
&priv->wpa.key[0].rx_seq[0]);
break;
case SME_SET_GMK1_TSC:
hostif_mib_set_request(priv, DOT11_GMK1_TSC,
WPA_RX_SEQ_LEN, MIB_VALUE_TYPE_OSTRING,
&priv->wpa.key[1].rx_seq[0]);
break;
case SME_SET_GMK2_TSC:
hostif_mib_set_request(priv, DOT11_GMK2_TSC,
WPA_RX_SEQ_LEN, MIB_VALUE_TYPE_OSTRING,
&priv->wpa.key[2].rx_seq[0]);
break;
}
}
static
void hostif_sme_set_pmksa(struct ks_wlan_private *priv)
{
struct pmk_cache_t {
__le16 size;
struct {
u8 bssid[ETH_ALEN];
u8 pmkid[IW_PMKID_LEN];
} __packed list[PMK_LIST_MAX];
} __packed pmkcache;
struct pmk_t *pmk;
int i;
DPRINTK(4, "pmklist.size=%d\n", priv->pmklist.size);
i = 0;
list_for_each_entry(pmk, &priv->pmklist.head, list) {
if (i < PMK_LIST_MAX) {
memcpy(pmkcache.list[i].bssid, pmk->bssid, ETH_ALEN);
memcpy(pmkcache.list[i].pmkid, pmk->pmkid,
IW_PMKID_LEN);
i++;
}
}
pmkcache.size = cpu_to_le16((uint16_t)(priv->pmklist.size));
hostif_mib_set_request(priv, LOCAL_PMK,
sizeof(priv->pmklist.size) + (ETH_ALEN +
IW_PMKID_LEN) *
(priv->pmklist.size), MIB_VALUE_TYPE_OSTRING,
&pmkcache);
}
static
void hostif_sme_execute(struct ks_wlan_private *priv, int event)
{
__le32 val;
DPRINTK(3, "event=%d\n", event);
switch (event) {
case SME_START:
if (priv->dev_state == DEVICE_STATE_BOOT)
hostif_mib_get_request(priv, DOT11_MAC_ADDRESS);
break;
case SME_MULTICAST_REQUEST:
hostif_sme_multicast_set(priv);
break;
case SME_MACADDRESS_SET_REQUEST:
hostif_mib_set_request(priv, LOCAL_CURRENTADDRESS, ETH_ALEN,
MIB_VALUE_TYPE_OSTRING,
&priv->eth_addr[0]);
break;
case SME_BSS_SCAN_REQUEST:
hostif_bss_scan_request(priv, priv->reg.scan_type,
priv->scan_ssid, priv->scan_ssid_len);
break;
case SME_POW_MNGMT_REQUEST:
hostif_sme_power_mgmt_set(priv);
break;
case SME_PHY_INFO_REQUEST:
hostif_phy_information_request(priv);
break;
case SME_MIC_FAILURE_REQUEST:
if (priv->wpa.mic_failure.failure == 1) {
hostif_mic_failure_request(priv,
priv->wpa.mic_failure.failure - 1,
0);
} else if (priv->wpa.mic_failure.failure == 2) {
hostif_mic_failure_request(priv,
priv->wpa.mic_failure.failure - 1,
priv->wpa.mic_failure.counter);
} else {
DPRINTK(4, "SME_MIC_FAILURE_REQUEST: failure count=%u error?\n",
priv->wpa.mic_failure.failure);
}
break;
case SME_MIC_FAILURE_CONFIRM:
if (priv->wpa.mic_failure.failure == 2) {
if (priv->wpa.mic_failure.stop)
priv->wpa.mic_failure.stop = 0;
priv->wpa.mic_failure.failure = 0;
hostif_start_request(priv, priv->reg.operation_mode);
}
break;
case SME_GET_MAC_ADDRESS:
if (priv->dev_state == DEVICE_STATE_BOOT)
hostif_mib_get_request(priv, DOT11_PRODUCT_VERSION);
break;
case SME_GET_PRODUCT_VERSION:
if (priv->dev_state == DEVICE_STATE_BOOT)
priv->dev_state = DEVICE_STATE_PREINIT;
break;
case SME_STOP_REQUEST:
hostif_stop_request(priv);
break;
case SME_RTS_THRESHOLD_REQUEST:
val = cpu_to_le32((uint32_t)(priv->reg.rts));
hostif_mib_set_request(priv, DOT11_RTS_THRESHOLD,
sizeof(val), MIB_VALUE_TYPE_INT, &val);
break;
case SME_FRAGMENTATION_THRESHOLD_REQUEST:
val = cpu_to_le32((uint32_t)(priv->reg.fragment));
hostif_mib_set_request(priv, DOT11_FRAGMENTATION_THRESHOLD,
sizeof(val), MIB_VALUE_TYPE_INT, &val);
break;
case SME_WEP_INDEX_REQUEST:
case SME_WEP_KEY1_REQUEST:
case SME_WEP_KEY2_REQUEST:
case SME_WEP_KEY3_REQUEST:
case SME_WEP_KEY4_REQUEST:
case SME_WEP_FLAG_REQUEST:
hostif_sme_set_wep(priv, event);
break;
case SME_RSN_UCAST_REQUEST:
case SME_RSN_MCAST_REQUEST:
case SME_RSN_AUTH_REQUEST:
case SME_RSN_ENABLED_REQUEST:
case SME_RSN_MODE_REQUEST:
hostif_sme_set_rsn(priv, event);
break;
case SME_SET_FLAG:
case SME_SET_TXKEY:
case SME_SET_KEY1:
case SME_SET_KEY2:
case SME_SET_KEY3:
case SME_SET_KEY4:
case SME_SET_PMK_TSC:
case SME_SET_GMK1_TSC:
case SME_SET_GMK2_TSC:
hostif_sme_set_key(priv, event);
break;
case SME_SET_PMKSA:
hostif_sme_set_pmksa(priv);
break;
#ifdef WPS
case SME_WPS_ENABLE_REQUEST:
hostif_mib_set_request(priv, LOCAL_WPS_ENABLE,
sizeof(priv->wps.wps_enabled),
MIB_VALUE_TYPE_INT,
&priv->wps.wps_enabled);
break;
case SME_WPS_PROBE_REQUEST:
hostif_mib_set_request(priv, LOCAL_WPS_PROBE_REQ,
priv->wps.ielen,
MIB_VALUE_TYPE_OSTRING, priv->wps.ie);
break;
#endif
case SME_MODE_SET_REQUEST:
hostif_sme_mode_setup(priv);
break;
case SME_SET_GAIN:
hostif_mib_set_request(priv, LOCAL_GAIN,
sizeof(priv->gain),
MIB_VALUE_TYPE_OSTRING, &priv->gain);
break;
case SME_GET_GAIN:
hostif_mib_get_request(priv, LOCAL_GAIN);
break;
case SME_GET_EEPROM_CKSUM:
priv->eeprom_checksum = EEPROM_FW_NOT_SUPPORT;
hostif_mib_get_request(priv, LOCAL_EEPROM_SUM);
break;
case SME_START_REQUEST:
hostif_start_request(priv, priv->reg.operation_mode);
break;
case SME_START_CONFIRM:
atomic_set(&priv->psstatus.snooze_guard, 0);
atomic_set(&priv->psstatus.confirm_wait, 0);
if (priv->dev_state == DEVICE_STATE_PREINIT)
priv->dev_state = DEVICE_STATE_INIT;
complete(&priv->confirm_wait);
break;
case SME_SLEEP_REQUEST:
hostif_sme_sleep_set(priv);
break;
case SME_SET_REGION:
val = cpu_to_le32((uint32_t)(priv->region));
hostif_mib_set_request(priv, LOCAL_REGION,
sizeof(val), MIB_VALUE_TYPE_INT, &val);
break;
case SME_MULTICAST_CONFIRM:
case SME_BSS_SCAN_CONFIRM:
case SME_POW_MNGMT_CONFIRM:
case SME_PHY_INFO_CONFIRM:
case SME_STOP_CONFIRM:
case SME_RTS_THRESHOLD_CONFIRM:
case SME_FRAGMENTATION_THRESHOLD_CONFIRM:
case SME_WEP_INDEX_CONFIRM:
case SME_WEP_KEY1_CONFIRM:
case SME_WEP_KEY2_CONFIRM:
case SME_WEP_KEY3_CONFIRM:
case SME_WEP_KEY4_CONFIRM:
case SME_WEP_FLAG_CONFIRM:
case SME_RSN_UCAST_CONFIRM:
case SME_RSN_MCAST_CONFIRM:
case SME_RSN_AUTH_CONFIRM:
case SME_RSN_ENABLED_CONFIRM:
case SME_RSN_MODE_CONFIRM:
case SME_MODE_SET_CONFIRM:
break;
case SME_TERMINATE:
default:
break;
}
}
static
void hostif_sme_task(unsigned long dev)
{
struct ks_wlan_private *priv = (struct ks_wlan_private *)dev;
DPRINTK(3, "\n");
if (priv->dev_state < DEVICE_STATE_BOOT)
return;
if (cnt_smeqbody(priv) <= 0)
return;
hostif_sme_execute(priv, priv->sme_i.event_buff[priv->sme_i.qhead]);
inc_smeqhead(priv);
if (cnt_smeqbody(priv) > 0)
tasklet_schedule(&priv->sme_task);
}
void hostif_sme_enqueue(struct ks_wlan_private *priv, unsigned short event)
{
DPRINTK(3, "\n");
if (cnt_smeqbody(priv) < (SME_EVENT_BUFF_SIZE - 1)) {
priv->sme_i.event_buff[priv->sme_i.qtail] = event;
inc_smeqtail(priv);
#ifdef KS_WLAN_DEBUG
if (priv->sme_i.max_event_count < cnt_smeqbody(priv))
priv->sme_i.max_event_count = cnt_smeqbody(priv);
#endif
} else {
netdev_err(priv->net_dev, "sme queue buffer overflow\n");
}
tasklet_schedule(&priv->sme_task);
}
int hostif_init(struct ks_wlan_private *priv)
{
int i;
DPRINTK(3, "\n");
priv->aplist.size = 0;
for (i = 0; i < LOCAL_APLIST_MAX; i++)
memset(&priv->aplist.ap[i], 0, sizeof(struct local_ap_t));
priv->infra_status = 0;
priv->current_rate = 4;
priv->connect_status = DISCONNECT_STATUS;
spin_lock_init(&priv->multicast_spin);
spin_lock_init(&priv->dev_read_lock);
init_waitqueue_head(&priv->devread_wait);
priv->dev_count = 0;
atomic_set(&priv->event_count, 0);
atomic_set(&priv->rec_count, 0);
atomic_set(&priv->psstatus.status, PS_NONE);
atomic_set(&priv->psstatus.confirm_wait, 0);
atomic_set(&priv->psstatus.snooze_guard, 0);
init_completion(&priv->psstatus.wakeup_wait);
INIT_WORK(&priv->wakeup_work, ks_wlan_hw_wakeup_task);
memset(&priv->wpa, 0, sizeof(priv->wpa));
priv->wpa.rsn_enabled = 0;
priv->wpa.mic_failure.failure = 0;
priv->wpa.mic_failure.last_failure_time = 0;
priv->wpa.mic_failure.stop = 0;
memset(&priv->pmklist, 0, sizeof(priv->pmklist));
INIT_LIST_HEAD(&priv->pmklist.head);
for (i = 0; i < PMK_LIST_MAX; i++)
INIT_LIST_HEAD(&priv->pmklist.pmk[i].list);
priv->sme_i.sme_status = SME_IDLE;
priv->sme_i.qhead = 0;
priv->sme_i.qtail = 0;
#ifdef KS_WLAN_DEBUG
priv->sme_i.max_event_count = 0;
#endif
spin_lock_init(&priv->sme_i.sme_spin);
priv->sme_i.sme_flag = 0;
tasklet_init(&priv->sme_task, hostif_sme_task, (unsigned long)priv);
return 0;
}
void hostif_exit(struct ks_wlan_private *priv)
{
tasklet_kill(&priv->sme_task);
}
