int ieee80211_wx_set_freq(struct ieee80211_device *ieee, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct iw_freq *fwrq = & wrqu->freq;
down(&ieee->wx_sem);
if(ieee->iw_mode == IW_MODE_INFRA){
ret = -EOPNOTSUPP;
goto out;
}
if (fwrq->e == 1) {
if ((fwrq->m >= (int) 2.412e8 &&
fwrq->m <= (int) 2.487e8)) {
int f = fwrq->m / 100000;
int c = 0;
while ((c < 14) && (f != ieee80211_wlan_frequencies[c]))
c++;
fwrq->e = 0;
fwrq->m = c + 1;
}
}
if (fwrq->e > 0 || fwrq->m > 14 || fwrq->m < 1 ){
ret = -EOPNOTSUPP;
goto out;
}else {
ieee->current_network.channel = fwrq->m;
ieee->set_chan(ieee->dev, ieee->current_network.channel);
if(ieee->iw_mode == IW_MODE_ADHOC || ieee->iw_mode == IW_MODE_MASTER)
if(ieee->state == IEEE80211_LINKED){
ieee80211_stop_send_beacons(ieee);
ieee80211_start_send_beacons(ieee);
}
}
ret = 0;
out:
up(&ieee->wx_sem);
return ret;
}
int ieee80211_wx_get_freq(struct ieee80211_device *ieee,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct iw_freq *fwrq = & wrqu->freq;
if (ieee->current_network.channel == 0)
return -1;
fwrq->m = ieee->current_network.channel;
fwrq->e = 0;
return 0;
}
int ieee80211_wx_get_wap(struct ieee80211_device *ieee,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
unsigned long flags;
wrqu->ap_addr.sa_family = ARPHRD_ETHER;
if (ieee->iw_mode == IW_MODE_MONITOR)
return -1;
spin_lock_irqsave(&ieee->lock, flags);
if (ieee->state != IEEE80211_LINKED &&
ieee->state != IEEE80211_LINKED_SCANNING &&
ieee->wap_set == 0)
memset(wrqu->ap_addr.sa_data, 0, ETH_ALEN);
else
memcpy(wrqu->ap_addr.sa_data,
ieee->current_network.bssid, ETH_ALEN);
spin_unlock_irqrestore(&ieee->lock, flags);
return 0;
}
int ieee80211_wx_set_wap(struct ieee80211_device *ieee,
struct iw_request_info *info,
union iwreq_data *awrq,
char *extra)
{
int ret = 0;
unsigned long flags;
short ifup = ieee->proto_started;
struct sockaddr *temp = (struct sockaddr *)awrq;
ieee->sync_scan_hurryup = 1;
down(&ieee->wx_sem);
if (ieee->iw_mode == IW_MODE_MASTER){
ret = -1;
goto out;
}
if (temp->sa_family != ARPHRD_ETHER){
ret = -EINVAL;
goto out;
}
if (ifup)
ieee80211_stop_protocol(ieee);
spin_lock_irqsave(&ieee->lock, flags);
memcpy(ieee->current_network.bssid, temp->sa_data, ETH_ALEN);
ieee->wap_set = !is_zero_ether_addr(temp->sa_data);
spin_unlock_irqrestore(&ieee->lock, flags);
if (ifup)
ieee80211_start_protocol(ieee);
out:
up(&ieee->wx_sem);
return ret;
}
int ieee80211_wx_get_essid(struct ieee80211_device *ieee, struct iw_request_info *a,union iwreq_data *wrqu,char *b)
{
int len,ret = 0;
unsigned long flags;
if (ieee->iw_mode == IW_MODE_MONITOR)
return -1;
spin_lock_irqsave(&ieee->lock, flags);
if (ieee->current_network.ssid[0] == '\0' ||
ieee->current_network.ssid_len == 0){
ret = -1;
goto out;
}
if (ieee->state != IEEE80211_LINKED &&
ieee->state != IEEE80211_LINKED_SCANNING &&
ieee->ssid_set == 0){
ret = -1;
goto out;
}
len = ieee->current_network.ssid_len;
wrqu->essid.length = len;
strncpy(b,ieee->current_network.ssid,len);
wrqu->essid.flags = 1;
out:
spin_unlock_irqrestore(&ieee->lock, flags);
return ret;
}
int ieee80211_wx_set_rate(struct ieee80211_device *ieee,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
u32 target_rate = wrqu->bitrate.value;
if(target_rate == -1){
ieee->rate = 110;
} else {
ieee->rate = target_rate/100000;
}
return 0;
}
int ieee80211_wx_get_rate(struct ieee80211_device *ieee,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
wrqu->bitrate.value = ieee->rate * 100000;
return 0;
}
int ieee80211_wx_set_mode(struct ieee80211_device *ieee, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
ieee->sync_scan_hurryup = 1;
down(&ieee->wx_sem);
if (wrqu->mode == ieee->iw_mode)
goto out;
if (wrqu->mode == IW_MODE_MONITOR){
ieee->dev->type = ARPHRD_IEEE80211;
}else{
ieee->dev->type = ARPHRD_ETHER;
}
if (!ieee->proto_started){
ieee->iw_mode = wrqu->mode;
}else{
ieee80211_stop_protocol(ieee);
ieee->iw_mode = wrqu->mode;
ieee80211_start_protocol(ieee);
}
out:
up(&ieee->wx_sem);
return 0;
}
void ieee80211_wx_sync_scan_wq(struct work_struct *work)
{
struct ieee80211_device *ieee = container_of(work, struct ieee80211_device, wx_sync_scan_wq);
short chan;
chan = ieee->current_network.channel;
if (ieee->data_hard_stop)
ieee->data_hard_stop(ieee->dev);
ieee80211_stop_send_beacons(ieee);
ieee->state = IEEE80211_LINKED_SCANNING;
ieee->link_change(ieee->dev);
ieee80211_start_scan_syncro(ieee);
ieee->set_chan(ieee->dev, chan);
ieee->state = IEEE80211_LINKED;
ieee->link_change(ieee->dev);
if (ieee->data_hard_resume)
ieee->data_hard_resume(ieee->dev);
if(ieee->iw_mode == IW_MODE_ADHOC || ieee->iw_mode == IW_MODE_MASTER)
ieee80211_start_send_beacons(ieee);
up(&ieee->wx_sem);
}
int ieee80211_wx_set_scan(struct ieee80211_device *ieee, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret = 0;
down(&ieee->wx_sem);
if (ieee->iw_mode == IW_MODE_MONITOR || !(ieee->proto_started)){
ret = -1;
goto out;
}
if ( ieee->state == IEEE80211_LINKED){
queue_work(ieee->wq, &ieee->wx_sync_scan_wq);
return 0;
}
out:
up(&ieee->wx_sem);
return ret;
}
int ieee80211_wx_set_essid(struct ieee80211_device *ieee,
struct iw_request_info *a,
union iwreq_data *wrqu, char *extra)
{
int ret=0,len;
short proto_started;
unsigned long flags;
ieee->sync_scan_hurryup = 1;
down(&ieee->wx_sem);
proto_started = ieee->proto_started;
if (wrqu->essid.length > IW_ESSID_MAX_SIZE){
ret= -E2BIG;
goto out;
}
if (ieee->iw_mode == IW_MODE_MONITOR){
ret= -1;
goto out;
}
if(proto_started)
ieee80211_stop_protocol(ieee);
spin_lock_irqsave(&ieee->lock, flags);
if (wrqu->essid.flags && wrqu->essid.length) {
len = (wrqu->essid.length < IW_ESSID_MAX_SIZE) ? (wrqu->essid.length) : IW_ESSID_MAX_SIZE;
memset(ieee->current_network.ssid, 0, ieee->current_network.ssid_len);
strncpy(ieee->current_network.ssid, extra, len);
ieee->current_network.ssid_len = len;
ieee->ssid_set = 1;
if(len == 0){
memset(ieee->current_network.bssid, 0, ETH_ALEN);
ieee->current_network.capability = 0;
}
}
else{
ieee->ssid_set = 0;
ieee->current_network.ssid[0] = '\0';
ieee->current_network.ssid_len = 0;
}
spin_unlock_irqrestore(&ieee->lock, flags);
if (proto_started)
ieee80211_start_protocol(ieee);
out:
up(&ieee->wx_sem);
return ret;
}
int ieee80211_wx_get_mode(struct ieee80211_device *ieee, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
wrqu->mode = ieee->iw_mode;
return 0;
}
int ieee80211_wx_set_rawtx(struct ieee80211_device *ieee,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int *parms = (int *)extra;
int enable = (parms[0] > 0);
short prev = ieee->raw_tx;
down(&ieee->wx_sem);
if(enable)
ieee->raw_tx = 1;
else
ieee->raw_tx = 0;
printk(KERN_INFO"raw TX is %s\n",
ieee->raw_tx ? "enabled" : "disabled");
if(ieee->iw_mode == IW_MODE_MONITOR)
{
if(prev == 0 && ieee->raw_tx){
if (ieee->data_hard_resume)
ieee->data_hard_resume(ieee->dev);
netif_carrier_on(ieee->dev);
}
if(prev && ieee->raw_tx == 1)
netif_carrier_off(ieee->dev);
}
up(&ieee->wx_sem);
return 0;
}
int ieee80211_wx_get_name(struct ieee80211_device *ieee,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
strlcpy(wrqu->name, "802.11", IFNAMSIZ);
if(ieee->modulation & IEEE80211_CCK_MODULATION){
strlcat(wrqu->name, "b", IFNAMSIZ);
if(ieee->modulation & IEEE80211_OFDM_MODULATION)
strlcat(wrqu->name, "/g", IFNAMSIZ);
}else if(ieee->modulation & IEEE80211_OFDM_MODULATION)
strlcat(wrqu->name, "g", IFNAMSIZ);
if((ieee->state == IEEE80211_LINKED) ||
(ieee->state == IEEE80211_LINKED_SCANNING))
strlcat(wrqu->name," link", IFNAMSIZ);
else if(ieee->state != IEEE80211_NOLINK)
strlcat(wrqu->name," .....", IFNAMSIZ);
return 0;
}
int ieee80211_wx_set_power(struct ieee80211_device *ieee,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret = 0;
if(
(!ieee->sta_wake_up) ||
(!ieee->ps_request_tx_ack) ||
(!ieee->enter_sleep_state) ||
(!ieee->ps_is_queue_empty)){
printk("ERROR. PS mode tried to be use but driver missed a callback\n\n");
return -1;
}
down(&ieee->wx_sem);
if (wrqu->power.disabled){
ieee->ps = IEEE80211_PS_DISABLED;
goto exit;
}
switch (wrqu->power.flags & IW_POWER_MODE) {
case IW_POWER_UNICAST_R:
ieee->ps = IEEE80211_PS_UNICAST;
break;
case IW_POWER_ALL_R:
ieee->ps = IEEE80211_PS_UNICAST | IEEE80211_PS_MBCAST;
break;
case IW_POWER_ON:
ieee->ps = IEEE80211_PS_DISABLED;
break;
default:
ret = -EINVAL;
goto exit;
}
if (wrqu->power.flags & IW_POWER_TIMEOUT) {
ieee->ps_timeout = wrqu->power.value / 1000;
printk("Timeout %d\n",ieee->ps_timeout);
}
if (wrqu->power.flags & IW_POWER_PERIOD) {
ret = -EOPNOTSUPP;
goto exit;
}
exit:
up(&ieee->wx_sem);
return ret;
}
int ieee80211_wx_get_power(struct ieee80211_device *ieee,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret =0;
down(&ieee->wx_sem);
if(ieee->ps == IEEE80211_PS_DISABLED){
wrqu->power.disabled = 1;
goto exit;
}
wrqu->power.disabled = 0;
wrqu->power.flags = IW_POWER_TIMEOUT;
wrqu->power.value = ieee->ps_timeout * 1000;
if (ieee->ps & IEEE80211_PS_MBCAST)
wrqu->power.flags |= IW_POWER_ALL_R;
else
wrqu->power.flags |= IW_POWER_UNICAST_R;
exit:
up(&ieee->wx_sem);
return ret;
}
