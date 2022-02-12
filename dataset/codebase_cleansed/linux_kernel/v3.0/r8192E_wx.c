static int r8192_wx_get_freq(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_freq(priv->ieee80211,a,wrqu,b);
}
static int r8192_wx_get_mode(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv=ieee80211_priv(dev);
return ieee80211_wx_get_mode(priv->ieee80211,a,wrqu,b);
}
static int r8192_wx_get_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_rate(priv->ieee80211,info,wrqu,extra);
}
static int r8192_wx_set_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_rate(priv->ieee80211,info,wrqu,extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_rts(priv->ieee80211,info,wrqu,extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_rts(priv->ieee80211,info,wrqu,extra);
}
static int r8192_wx_set_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_power(priv->ieee80211,info,wrqu,extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_power(priv->ieee80211,info,wrqu,extra);
}
static int r8192_wx_set_rawtx(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int ret;
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_rawtx(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_force_reset(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
printk("%s(): force reset ! extra is %d\n",__FUNCTION__, *extra);
priv->force_reset = *extra;
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_set_crcmon(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int *parms = (int *)extra;
int enable = (parms[0] > 0);
short prev = priv->crcmon;
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if(enable)
priv->crcmon=1;
else
priv->crcmon=0;
DMESG("bad CRC in monitor mode are %s",
priv->crcmon ? "accepted" : "rejected");
if(prev != priv->crcmon && priv->up){
}
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_set_mode(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
RT_RF_POWER_STATE rtState;
int ret;
if (priv->bHwRadioOff)
return 0;
rtState = priv->eRFPowerState;
down(&priv->wx_sem);
#ifdef ENABLE_IPS
if(wrqu->mode == IW_MODE_ADHOC){
if (priv->PowerSaveControl.bInactivePs) {
if(rtState == eRfOff){
if(priv->RfOffReason > RF_CHANGE_BY_IPS)
{
RT_TRACE(COMP_ERR, "%s(): RF is OFF.\n",__FUNCTION__);
up(&priv->wx_sem);
return -1;
}
else{
RT_TRACE(COMP_ERR, "%s(): IPSLeave\n",__FUNCTION__);
down(&priv->ieee80211->ips_sem);
IPSLeave(priv);
up(&priv->ieee80211->ips_sem);
}
}
}
}
#endif
ret = ieee80211_wx_set_mode(priv->ieee80211,a,wrqu,b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_scan(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device* ieee = priv->ieee80211;
RT_RF_POWER_STATE rtState;
int ret;
if (priv->bHwRadioOff)
return 0;
rtState = priv->eRFPowerState;
if(!priv->up) return -ENETDOWN;
if (priv->ieee80211->LinkDetectInfo.bBusyTraffic == true)
return -EAGAIN;
if (wrqu->data.flags & IW_SCAN_THIS_ESSID)
{
struct iw_scan_req* req = (struct iw_scan_req*)b;
if (req->essid_len)
{
ieee->current_network.ssid_len = req->essid_len;
memcpy(ieee->current_network.ssid, req->essid, req->essid_len);
}
}
down(&priv->wx_sem);
#ifdef ENABLE_IPS
priv->ieee80211->actscanning = true;
if(priv->ieee80211->state != IEEE80211_LINKED){
if (priv->PowerSaveControl.bInactivePs) {
if(rtState == eRfOff){
if(priv->RfOffReason > RF_CHANGE_BY_IPS)
{
RT_TRACE(COMP_ERR, "%s(): RF is OFF.\n",__FUNCTION__);
up(&priv->wx_sem);
return -1;
}
else{
down(&priv->ieee80211->ips_sem);
IPSLeave(priv);
up(&priv->ieee80211->ips_sem);
}
}
}
priv->ieee80211->scanning = 0;
ieee80211_softmac_scan_syncro(priv->ieee80211);
ret = 0;
}
else
#else
if(priv->ieee80211->state != IEEE80211_LINKED){
priv->ieee80211->scanning = 0;
ieee80211_softmac_scan_syncro(priv->ieee80211);
ret = 0;
}
else
#endif
ret = ieee80211_wx_set_scan(priv->ieee80211,a,wrqu,b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_scan(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
if(!priv->up) return -ENETDOWN;
down(&priv->wx_sem);
ret = ieee80211_wx_get_scan(priv->ieee80211,a,wrqu,b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_essid(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
RT_RF_POWER_STATE rtState;
int ret;
if (priv->bHwRadioOff)
return 0;
rtState = priv->eRFPowerState;
down(&priv->wx_sem);
#ifdef ENABLE_IPS
down(&priv->ieee80211->ips_sem);
IPSLeave(priv);
up(&priv->ieee80211->ips_sem);
#endif
ret = ieee80211_wx_set_essid(priv->ieee80211,a,wrqu,b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_essid(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_get_essid(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_freq(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_freq(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_name(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_name(priv->ieee80211, info, wrqu, extra);
}
static int r8192_wx_set_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
if (wrqu->frag.disabled)
priv->ieee80211->fts = DEFAULT_FRAG_THRESHOLD;
else {
if (wrqu->frag.value < MIN_FRAG_THRESHOLD ||
wrqu->frag.value > MAX_FRAG_THRESHOLD)
return -EINVAL;
priv->ieee80211->fts = wrqu->frag.value & ~0x1;
}
return 0;
}
static int r8192_wx_get_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
wrqu->frag.value = priv->ieee80211->fts;
wrqu->frag.fixed = 0;
wrqu->frag.disabled = (wrqu->frag.value == DEFAULT_FRAG_THRESHOLD);
return 0;
}
static int r8192_wx_set_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *awrq,
char *extra)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
#ifdef ENABLE_IPS
down(&priv->ieee80211->ips_sem);
IPSLeave(priv);
up(&priv->ieee80211->ips_sem);
#endif
ret = ieee80211_wx_set_wap(priv->ieee80211,info,awrq,extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_wap(priv->ieee80211,info,wrqu,extra);
}
static int r8192_wx_get_enc(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_encode(priv->ieee80211, info, wrqu, key);
}
static int r8192_wx_set_enc(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int ret;
struct ieee80211_device *ieee = priv->ieee80211;
u32 hwkey[4]={0,0,0,0};
u8 mask=0xff;
u32 key_idx=0;
u8 zero_addr[4][6] ={{0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x01},
{0x00,0x00,0x00,0x00,0x00,0x02},
{0x00,0x00,0x00,0x00,0x00,0x03} };
int i;
if (priv->bHwRadioOff)
return 0;
if(!priv->up) return -ENETDOWN;
priv->ieee80211->wx_set_enc = 1;
#ifdef ENABLE_IPS
down(&priv->ieee80211->ips_sem);
IPSLeave(priv);
up(&priv->ieee80211->ips_sem);
#endif
down(&priv->wx_sem);
RT_TRACE(COMP_SEC, "Setting SW wep key\n");
ret = ieee80211_wx_set_encode(priv->ieee80211,info,wrqu,key);
up(&priv->wx_sem);
if(wrqu->encoding.length!=0){
for(i=0 ; i<4 ; i++){
hwkey[i] |= key[4*i+0]&mask;
if(i==1&&(4*i+1)==wrqu->encoding.length) mask=0x00;
if(i==3&&(4*i+1)==wrqu->encoding.length) mask=0x00;
hwkey[i] |= (key[4*i+1]&mask)<<8;
hwkey[i] |= (key[4*i+2]&mask)<<16;
hwkey[i] |= (key[4*i+3]&mask)<<24;
}
#define CONF_WEP40 0x4
#define CONF_WEP104 0x14
switch(wrqu->encoding.flags & IW_ENCODE_INDEX){
case 0: key_idx = ieee->tx_keyidx; break;
case 1: key_idx = 0; break;
case 2: key_idx = 1; break;
case 3: key_idx = 2; break;
case 4: key_idx = 3; break;
default: break;
}
if(wrqu->encoding.length==0x5){
ieee->pairwise_key_type = KEY_TYPE_WEP40;
EnableHWSecurityConfig8192(priv);
setKey(priv, key_idx, key_idx, KEY_TYPE_WEP40,
zero_addr[key_idx], 0, hwkey);
}
else if(wrqu->encoding.length==0xd){
ieee->pairwise_key_type = KEY_TYPE_WEP104;
EnableHWSecurityConfig8192(priv);
setKey(priv, key_idx, key_idx, KEY_TYPE_WEP104,
zero_addr[key_idx], 0, hwkey);
}
else printk("wrong type in WEP, not WEP40 and WEP104\n");
}
priv->ieee80211->wx_set_enc = 0;
return ret;
}
static int r8192_wx_set_scan_type(struct net_device *dev, struct iw_request_info *aa, union
iwreq_data *wrqu, char *p){
struct r8192_priv *priv = ieee80211_priv(dev);
int *parms=(int*)p;
int mode=parms[0];
priv->ieee80211->active_scan = mode;
return 1;
}
static int r8192_wx_set_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int err = 0;
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if (wrqu->retry.flags & IW_RETRY_LIFETIME ||
wrqu->retry.disabled){
err = -EINVAL;
goto exit;
}
if (!(wrqu->retry.flags & IW_RETRY_LIMIT)){
err = -EINVAL;
goto exit;
}
if(wrqu->retry.value > R8180_MAX_RETRY){
err= -EINVAL;
goto exit;
}
if (wrqu->retry.flags & IW_RETRY_MAX) {
priv->retry_rts = wrqu->retry.value;
DMESG("Setting retry for RTS/CTS data to %d", wrqu->retry.value);
}else {
priv->retry_data = wrqu->retry.value;
DMESG("Setting retry for non RTS/CTS data to %d", wrqu->retry.value);
}
rtl8192_commit(priv);
exit:
up(&priv->wx_sem);
return err;
}
static int r8192_wx_get_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
wrqu->retry.disabled = 0;
if ((wrqu->retry.flags & IW_RETRY_TYPE) ==
IW_RETRY_LIFETIME)
return -EINVAL;
if (wrqu->retry.flags & IW_RETRY_MAX) {
wrqu->retry.flags = IW_RETRY_LIMIT & IW_RETRY_MAX;
wrqu->retry.value = priv->retry_rts;
} else {
wrqu->retry.flags = IW_RETRY_LIMIT & IW_RETRY_MIN;
wrqu->retry.value = priv->retry_data;
}
return 0;
}
static int r8192_wx_get_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
if(priv->rf_set_sens == NULL)
return -1;
wrqu->sens.value = priv->sens;
return 0;
}
static int r8192_wx_set_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
short err = 0;
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if(priv->rf_set_sens == NULL) {
err= -1;
goto exit;
}
if(priv->rf_set_sens(dev, wrqu->sens.value) == 0)
priv->sens = wrqu->sens.value;
else
err= -EINVAL;
exit:
up(&priv->wx_sem);
return err;
}
static int r8192_wx_set_enc_ext(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret=0;
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device* ieee = priv->ieee80211;
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
priv->ieee80211->wx_set_enc = 1;
#ifdef ENABLE_IPS
down(&priv->ieee80211->ips_sem);
IPSLeave(priv);
up(&priv->ieee80211->ips_sem);
#endif
ret = ieee80211_wx_set_encode_ext(ieee, info, wrqu, extra);
{
u8 broadcast_addr[6] = {0xff,0xff,0xff,0xff,0xff,0xff};
u8 zero[6] = {0};
u32 key[4] = {0};
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
struct iw_point *encoding = &wrqu->encoding;
u8 idx = 0, alg = 0, group = 0;
if ((encoding->flags & IW_ENCODE_DISABLED) ||
ext->alg == IW_ENCODE_ALG_NONE)
{
ieee->pairwise_key_type = ieee->group_key_type = KEY_TYPE_NA;
CamResetAllEntry(priv);
goto end_hw_sec;
}
alg = (ext->alg == IW_ENCODE_ALG_CCMP)?KEY_TYPE_CCMP:ext->alg;
idx = encoding->flags & IW_ENCODE_INDEX;
if (idx)
idx --;
group = ext->ext_flags & IW_ENCODE_EXT_GROUP_KEY;
if ((!group) || (IW_MODE_ADHOC == ieee->iw_mode) || (alg == KEY_TYPE_WEP40))
{
if ((ext->key_len == 13) && (alg == KEY_TYPE_WEP40) )
alg = KEY_TYPE_WEP104;
ieee->pairwise_key_type = alg;
EnableHWSecurityConfig8192(priv);
}
memcpy((u8*)key, ext->key, 16);
if ((alg & KEY_TYPE_WEP40) && (ieee->auth_mode !=2) )
{
if (ext->key_len == 13)
ieee->pairwise_key_type = alg = KEY_TYPE_WEP104;
setKey(priv, idx, idx, alg, zero, 0, key);
}
else if (group)
{
ieee->group_key_type = alg;
setKey(priv, idx, idx, alg, broadcast_addr, 0, key);
}
else
{
if ((ieee->pairwise_key_type == KEY_TYPE_CCMP) && ieee->pHTInfo->bCurrentHTSupport){
write_nic_byte(priv, 0x173, 1);
}
setKey(priv, 4, idx, alg,
(u8*)ieee->ap_mac_addr, 0, key);
}
}
end_hw_sec:
priv->ieee80211->wx_set_enc = 0;
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_auth(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *data, char *extra)
{
int ret=0;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_auth(priv->ieee80211, info, &(data->param), extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_mlme(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret=0;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_mlme(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_gen_ie(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *data, char *extra)
{
int ret=0;
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_gen_ie(priv->ieee80211, extra, data->data.length);
up(&priv->wx_sem);
return ret;
}
static int dummy(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu,char *b)
{
return -1;
}
static int r8192_wx_adapter_power_status(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
#ifdef ENABLE_LPS
PRT_POWER_SAVE_CONTROL pPSC = &priv->PowerSaveControl;
struct ieee80211_device* ieee = priv->ieee80211;
#endif
down(&priv->wx_sem);
#ifdef ENABLE_LPS
RT_TRACE(COMP_POWER, "%s(): %s\n",__FUNCTION__, (*extra == 6)?"DC power":"AC power");
if(*extra || priv->force_lps) {
priv->ps_force = false;
pPSC->bLeisurePs = true;
} else {
if(priv->ieee80211->state == IEEE80211_LINKED)
LeisurePSLeave(priv->ieee80211);
priv->ps_force = true;
pPSC->bLeisurePs = false;
ieee->ps = *extra;
}
#endif
up(&priv->wx_sem);
return 0;
}
static struct iw_statistics *r8192_get_wireless_stats(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device* ieee = priv->ieee80211;
struct iw_statistics* wstats = &priv->wstats;
int tmp_level = 0;
int tmp_qual = 0;
int tmp_noise = 0;
if(ieee->state < IEEE80211_LINKED)
{
wstats->qual.qual = 0;
wstats->qual.level = 0;
wstats->qual.noise = 0;
wstats->qual.updated = IW_QUAL_ALL_UPDATED | IW_QUAL_DBM;
return wstats;
}
tmp_level = (&ieee->current_network)->stats.rssi;
tmp_qual = (&ieee->current_network)->stats.signal;
tmp_noise = (&ieee->current_network)->stats.noise;
wstats->qual.level = tmp_level;
wstats->qual.qual = tmp_qual;
wstats->qual.noise = tmp_noise;
wstats->qual.updated = IW_QUAL_ALL_UPDATED | IW_QUAL_DBM;
return wstats;
}
