static int
wext_freq_to_channel(int m, int e)
{
int mhz;
mhz = m;
while (e < 6) {
mhz /= 10;
e++;
}
while (e > 6) {
mhz *= 10;
e--;
}
if (mhz >= 5000) {
return ((mhz - 5000) / 5);
}
if (mhz == 2482) {
return 14;
}
if (mhz >= 2407) {
return ((mhz - 2407) / 5);
}
return 0;
}
static int
channel_to_mhz(int ch, int dot11a)
{
if (ch == 0) return 0;
if (ch > 200) return 0;
if (dot11a) {
return (5000 + (5 * ch));
}
if (ch == 14) {
return 2484;
}
if ((ch < 14) && (ch > 0)) {
return (2407 + (5 * ch));
}
return 0;
}
void uf_sme_wext_ap_set_defaults(unifi_priv_t *priv)
{
memcpy(priv->ap_config.ssid.ssid,"defaultssid",sizeof("defaultssid"));
priv->ap_config.ssid.length = 8;
priv->ap_config.channel = 6;
priv->ap_config.if_index = 1;
priv->ap_config.credentials.authType = 0;
priv->ap_config.max_connections=8;
priv->group_sec_config.apGroupkeyTimeout = 0;
priv->group_sec_config.apStrictGtkRekey = 0;
priv->group_sec_config.apGmkTimeout = 0;
priv->group_sec_config.apResponseTimeout = 100;
priv->group_sec_config.apRetransLimit = 3;
priv->ap_mac_config.preamble = CSR_WIFI_SME_USE_LONG_PREAMBLE;
priv->ap_mac_config.shortSlotTimeEnabled = FALSE;
priv->ap_mac_config.ctsProtectionType=CSR_WIFI_SME_CTS_PROTECTION_AUTOMATIC;
priv->ap_mac_config.wmmEnabled = TRUE;
priv->ap_mac_config.wmmApParams[0].cwMin=4;
priv->ap_mac_config.wmmApParams[0].cwMax=10;
priv->ap_mac_config.wmmApParams[0].aifs=3;
priv->ap_mac_config.wmmApParams[0].txopLimit=0;
priv->ap_mac_config.wmmApParams[0].admissionControlMandatory=FALSE;
priv->ap_mac_config.wmmApParams[1].cwMin=4;
priv->ap_mac_config.wmmApParams[1].cwMax=10;
priv->ap_mac_config.wmmApParams[1].aifs=7;
priv->ap_mac_config.wmmApParams[1].txopLimit=0;
priv->ap_mac_config.wmmApParams[1].admissionControlMandatory=FALSE;
priv->ap_mac_config.wmmApParams[2].cwMin=3;
priv->ap_mac_config.wmmApParams[2].cwMax=4;
priv->ap_mac_config.wmmApParams[2].aifs=1;
priv->ap_mac_config.wmmApParams[2].txopLimit=94;
priv->ap_mac_config.wmmApParams[2].admissionControlMandatory=FALSE;
priv->ap_mac_config.wmmApParams[3].cwMin=2;
priv->ap_mac_config.wmmApParams[3].cwMax=3;
priv->ap_mac_config.wmmApParams[3].aifs=1;
priv->ap_mac_config.wmmApParams[3].txopLimit=47;
priv->ap_mac_config.wmmApParams[3].admissionControlMandatory=FALSE;
priv->ap_mac_config.wmmApBcParams[0].cwMin=4;
priv->ap_mac_config.wmmApBcParams[0].cwMax=10;
priv->ap_mac_config.wmmApBcParams[0].aifs=3;
priv->ap_mac_config.wmmApBcParams[0].txopLimit=0;
priv->ap_mac_config.wmmApBcParams[0].admissionControlMandatory=FALSE;
priv->ap_mac_config.wmmApBcParams[1].cwMin=4;
priv->ap_mac_config.wmmApBcParams[1].cwMax=10;
priv->ap_mac_config.wmmApBcParams[1].aifs=7;
priv->ap_mac_config.wmmApBcParams[1].txopLimit=0;
priv->ap_mac_config.wmmApBcParams[1].admissionControlMandatory=FALSE;
priv->ap_mac_config.wmmApBcParams[2].cwMin=3;
priv->ap_mac_config.wmmApBcParams[2].cwMax=4;
priv->ap_mac_config.wmmApBcParams[2].aifs=2;
priv->ap_mac_config.wmmApBcParams[2].txopLimit=94;
priv->ap_mac_config.wmmApBcParams[2].admissionControlMandatory=FALSE;
priv->ap_mac_config.wmmApBcParams[3].cwMin=2;
priv->ap_mac_config.wmmApBcParams[3].cwMax=3;
priv->ap_mac_config.wmmApBcParams[3].aifs=2;
priv->ap_mac_config.wmmApBcParams[3].txopLimit=47;
priv->ap_mac_config.wmmApBcParams[3].admissionControlMandatory=FALSE;
priv->ap_mac_config.accessType=CSR_WIFI_AP_ACCESS_TYPE_NONE;
priv->ap_mac_config.macAddressListCount=0;
priv->ap_mac_config.macAddressList=NULL;
priv->ap_mac_config.apHtParams.rxStbc=1;
priv->ap_mac_config.apHtParams.rifsModeAllowed=TRUE;
priv->ap_mac_config.apHtParams.greenfieldSupported=FALSE;
priv->ap_mac_config.apHtParams.shortGi20MHz=TRUE;
priv->ap_mac_config.apHtParams.htProtection=0;
priv->ap_mac_config.apHtParams.dualCtsProtection=FALSE;
priv->ap_mac_config.phySupportedBitmap =
(CSR_WIFI_SME_AP_PHY_SUPPORT_B|CSR_WIFI_SME_AP_PHY_SUPPORT_G|CSR_WIFI_SME_AP_PHY_SUPPORT_N);
priv->ap_mac_config.beaconInterval= 100;
priv->ap_mac_config.dtimPeriod=3;
priv->ap_mac_config.maxListenInterval=0x00ff;
priv->ap_mac_config.supportedRatesCount =
uf_configure_supported_rates(priv->ap_mac_config.supportedRates,priv->ap_mac_config.phySupportedBitmap);
}
void
uf_sme_wext_set_defaults(unifi_priv_t *priv)
{
memset(&priv->connection_config, 0, sizeof(CsrWifiSmeConnectionConfig));
priv->connection_config.bssType = CSR_WIFI_SME_BSS_TYPE_INFRASTRUCTURE;
priv->connection_config.authModeMask = CSR_WIFI_SME_AUTH_MODE_80211_OPEN;
priv->connection_config.encryptionModeMask = CSR_WIFI_SME_ENCRYPTION_CIPHER_NONE;
priv->connection_config.privacyMode = CSR_WIFI_SME_80211_PRIVACY_MODE_DISABLED;
priv->connection_config.wmmQosInfo = 0xFF;
priv->connection_config.ifIndex = CSR_WIFI_SME_RADIO_IF_BOTH;
priv->connection_config.adhocJoinOnly = FALSE;
priv->connection_config.adhocChannel = 6;
priv->wep_tx_key_index = 0;
priv->wext_wireless_stats.qual.qual = 0;
priv->wext_wireless_stats.qual.level = 0;
priv->wext_wireless_stats.qual.noise = 0;
priv->wext_wireless_stats.qual.updated = 0x70;
#ifdef CSR_SUPPORT_WEXT_AP
uf_sme_wext_ap_set_defaults(priv);
#endif
}
static int
iwprivsdefs(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int r;
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
CsrWifiSmeMibConfig mibConfig;
CsrWifiSmePowerConfig powerConfig;
unifi_trace(priv, UDBG1, "iwprivs80211defaults: reload defaults\n");
uf_sme_wext_set_defaults(priv);
r = sme_mgt_mib_config_get(priv, &mibConfig);
if (r) {
unifi_error(priv, "iwprivs80211defaults: Get CsrWifiSmeMibConfigValue failed.\n");
return r;
}
mibConfig.dot11RtsThreshold = 2347;
mibConfig.dot11FragmentationThreshold = 2346;
r = sme_mgt_mib_config_set(priv, &mibConfig);
if (r) {
unifi_error(priv, "iwprivs80211defaults: Set CsrWifiSmeMibConfigValue failed.\n");
return r;
}
powerConfig.powerSaveLevel = CSR_WIFI_SME_POWER_SAVE_LEVEL_LOW;
powerConfig.listenIntervalTu = 100;
powerConfig.rxDtims = 1;
r = sme_mgt_power_config_set(priv, &powerConfig);
if (r) {
unifi_error(priv, "iwprivs80211defaults: Set unifi_PowerConfigValue failed.\n");
return r;
}
return 0;
}
static int
iwprivs80211ps(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int r = 0;
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int ps_mode = (int)(*extra);
CsrWifiSmePowerConfig powerConfig;
unifi_trace(priv, UDBG1, "iwprivs80211ps: power save mode = %d\n", ps_mode);
r = sme_mgt_power_config_get(priv, &powerConfig);
if (r) {
unifi_error(priv, "iwprivs80211ps: Get unifi_PowerConfigValue failed.\n");
return r;
}
switch (ps_mode) {
case CSR_PMM_ACTIVE_MODE:
powerConfig.powerSaveLevel = CSR_WIFI_SME_POWER_SAVE_LEVEL_LOW;
break;
case CSR_PMM_POWER_SAVE:
powerConfig.powerSaveLevel = CSR_WIFI_SME_POWER_SAVE_LEVEL_HIGH;
break;
case CSR_PMM_FAST_POWER_SAVE:
powerConfig.powerSaveLevel = CSR_WIFI_SME_POWER_SAVE_LEVEL_MED;
break;
default:
powerConfig.powerSaveLevel = CSR_WIFI_SME_POWER_SAVE_LEVEL_AUTO;
break;
}
r = sme_mgt_power_config_set(priv, &powerConfig);
if (r) {
unifi_error(priv, "iwprivs80211ps: Set unifi_PowerConfigValue failed.\n");
}
return r;
}
static int
iwprivg80211ps(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
CsrWifiSmePowerConfig powerConfig;
int r;
r = sme_mgt_power_config_get(priv, &powerConfig);
if (r) {
unifi_error(priv, "iwprivg80211ps: Get 802.11 power mode failed.\n");
return r;
}
switch (powerConfig.powerSaveLevel) {
case CSR_WIFI_SME_POWER_SAVE_LEVEL_LOW:
snprintf(extra, IWPRIV_POWER_SAVE_MAX_STRING,
"Power save mode: %d (Active)",
powerConfig.powerSaveLevel);
break;
case CSR_WIFI_SME_POWER_SAVE_LEVEL_MED:
snprintf(extra, IWPRIV_POWER_SAVE_MAX_STRING,
"Power save mode: %d (Fast)",
powerConfig.powerSaveLevel);
break;
case CSR_WIFI_SME_POWER_SAVE_LEVEL_HIGH:
snprintf(extra, IWPRIV_POWER_SAVE_MAX_STRING,
"Power save mode: %d (Full)",
powerConfig.powerSaveLevel);
break;
case CSR_WIFI_SME_POWER_SAVE_LEVEL_AUTO:
snprintf(extra, IWPRIV_POWER_SAVE_MAX_STRING,
"Power save mode: %d (Auto)",
powerConfig.powerSaveLevel);
break;
default:
snprintf(extra, IWPRIV_POWER_SAVE_MAX_STRING,
"Power save mode: %d (Unknown)",
powerConfig.powerSaveLevel);
break;
}
wrqu->data.length = strlen(extra) + 1;
return 0;
}
static int
iwprivssmedebug(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE)
unifi_debug_buf_dump();
#endif
return 0;
}
static int hex_look_up(char x)
{
if(x>='0' && x<='9')
return (x-48);
if(x>= 'a' && x <= 'f')
return (x-87);
return -1;
}
static int power (int a, int b)
{
int i;
int num =1;
for(i=0;i<b;i++)
num *=a;
return num;
}
static int decode_parameter_from_string(unifi_priv_t* priv, char **str_ptr,
const char *token, int param_type,
void *dst, int param_max_len)
{
u8 int_str[7] = "0";
u32 param_str_len;
u8 *param_str_begin,*param_str_end;
u8 *orig_str = *str_ptr;
if (!strncmp(*str_ptr, token, strlen(token))) {
strsep(str_ptr, "=,");
param_str_begin = *str_ptr;
strsep(str_ptr, "=,");
if (*str_ptr == NULL) {
param_str_len = strlen(param_str_begin);
} else {
param_str_end = *str_ptr-1;
param_str_len = param_str_end - param_str_begin;
}
unifi_trace(priv,UDBG2,"'token:%s', len:%d, ", token, param_str_len);
if (param_str_len > param_max_len) {
unifi_notice(priv,"extracted param len:%d is > MAX:%d\n",param_str_len, param_max_len);
param_str_len = param_max_len;
}
switch (param_type) {
case PARAM_TYPE_INT:
{
u32 *pdst_int = dst,num =0;
int i,j=0;
if (param_str_len > sizeof(int_str)) {
param_str_len = sizeof(int_str);
}
memcpy(int_str, param_str_begin, param_str_len);
for(i = param_str_len; i>0;i--) {
if(int_str[i-1] >= '0' && int_str[i-1] <='9') {
num += ((int_str[i-1]-'0')*power(10,j));
j++;
} else {
unifi_error(priv,"decode_parameter_from_string:not a number %c\n",(int_str[i-1]));
return -1;
}
}
*pdst_int = num;
unifi_trace(priv,UDBG2,"decode_parameter_from_string:decoded int = %d\n",*pdst_int);
}
break;
default:
memcpy(dst, param_str_begin, param_str_len);
*((char *)dst + param_str_len) = 0;
unifi_trace(priv,UDBG2,"decode_parameter_from_string:decoded string = %s\n",(char *)dst);
break;
}
} else {
unifi_error(priv,"decode_parameter_from_string: Token:%s not found in %s \n",token,orig_str);
return -1;
}
return 0;
}
static int store_ap_advanced_config_from_string(unifi_priv_t *priv, char *param_str)
{
char * str_ptr=param_str;
int ret = 0,tmp_var;
char phy_mode[6];
CsrWifiSmeApMacConfig * ap_mac_config = &priv->ap_mac_config;
ret = decode_parameter_from_string(priv, &str_ptr, "BI=",
PARAM_TYPE_INT, &tmp_var, 5);
if(ret) {
unifi_error(priv,"store_ap_advanced_config_from_string: BI not found\n");
return -1;
}
ap_mac_config->beaconInterval = tmp_var;
ret = decode_parameter_from_string(priv, &str_ptr, "DTIM_PER=",
PARAM_TYPE_INT, &tmp_var, 5);
if(ret) {
unifi_error(priv,"store_ap_advanced_config_from_string: DTIM_PER not found\n");
return -1;
}
ap_mac_config->dtimPeriod = tmp_var;
ret = decode_parameter_from_string(priv, &str_ptr, "WMM=",
PARAM_TYPE_INT, &tmp_var, 5);
if(ret) {
unifi_error(priv,"store_ap_advanced_config_from_string: WMM not found\n");
return -1;
}
ap_mac_config->wmmEnabled = tmp_var;
ret = decode_parameter_from_string(priv, &str_ptr, "PHY=",
PARAM_TYPE_STRING, phy_mode, 5);
if(ret) {
unifi_error(priv,"store_ap_advanced_config_from_string: PHY not found\n");
} else {
if(strstr(phy_mode,"b")){
ap_mac_config->phySupportedBitmap = CSR_WIFI_SME_AP_PHY_SUPPORT_B;
}
if(strstr(phy_mode,"g")) {
ap_mac_config->phySupportedBitmap |= CSR_WIFI_SME_AP_PHY_SUPPORT_G;
}
if(strstr(phy_mode,"n")) {
ap_mac_config->phySupportedBitmap |= CSR_WIFI_SME_AP_PHY_SUPPORT_N;
}
ap_mac_config->supportedRatesCount =
uf_configure_supported_rates(ap_mac_config->supportedRates, ap_mac_config->phySupportedBitmap);
}
return ret;
}
static int store_ap_config_from_string( unifi_priv_t * priv,char *param_str)
{
char *str_ptr = param_str;
char sub_cmd[16];
char sec[CSR_WIFI_MAX_SEC_LEN];
char key[CSR_WIFI_MAX_KEY_LEN];
int ret = 0,tmp_var;
CsrWifiSmeApConfig_t *ap_config = &priv->ap_config;
CsrWifiSmeApMacConfig * ap_mac_config = &priv->ap_mac_config;
memset(sub_cmd, 0, sizeof(sub_cmd));
if(!strstr(param_str,"END")) {
unifi_error(priv,"store_ap_config_from_string:Invalid config string:%s\n",param_str);
return -1;
}
if (decode_parameter_from_string(priv,&str_ptr, "ASCII_CMD=",
PARAM_TYPE_STRING, sub_cmd, 6) != 0) {
return -1;
}
if (strncmp(sub_cmd, "AP_CFG", 6)) {
if(!strncmp(sub_cmd ,"ADVCFG", 6)) {
return store_ap_advanced_config_from_string(priv, str_ptr);
}
unifi_error(priv,"store_ap_config_from_string: sub_cmd:%s != 'AP_CFG or ADVCFG'!\n", sub_cmd);
return -1;
}
memset(ap_config, 0, sizeof(CsrWifiSmeApConfig_t));
ret = decode_parameter_from_string(priv,&str_ptr, "SSID=",
PARAM_TYPE_STRING, ap_config->ssid.ssid,
CSR_WIFI_MAX_SSID_LEN);
if(ret) {
unifi_error(priv,"store_ap_config_from_string: SSID not found\n");
return -1;
}
ap_config->ssid.length = strlen(ap_config->ssid.ssid);
ret = decode_parameter_from_string(priv, &str_ptr, "SEC=",
PARAM_TYPE_STRING, sec, CSR_WIFI_MAX_SEC_LEN);
if(ret) {
unifi_error(priv,"store_ap_config_from_string: SEC not found\n");
return -1;
}
ret = decode_parameter_from_string(priv,&str_ptr, "KEY=",
PARAM_TYPE_STRING, key, CSR_WIFI_MAX_KEY_LEN);
if(!strcasecmp(sec,"open")) {
unifi_trace(priv,UDBG2,"store_ap_config_from_string: security open");
ap_config->credentials.authType = CSR_WIFI_SME_AP_AUTH_TYPE_OPEN_SYSTEM;
if(ret) {
unifi_notice(priv,"store_ap_config_from_string: KEY not found:fine with Open\n");
}
}
else if(!strcasecmp(sec,"wpa2-psk")) {
int i,j=0;
CsrWifiNmeApAuthPers *pers =
((CsrWifiNmeApAuthPers *)&(ap_config->credentials.nmeAuthType.authTypePersonal));
u8 *psk = pers->authPers_credentials.psk.psk;
unifi_trace(priv,UDBG2,"store_ap_config_from_string: security WPA2");
if(ret) {
unifi_error(priv,"store_ap_config_from_string: KEY not found for WPA2\n");
return -1;
}
ap_config->credentials.authType = CSR_WIFI_SME_AP_AUTH_TYPE_PERSONAL;
pers->authSupport = CSR_WIFI_SME_RSN_AUTH_WPA2PSK;
pers->rsnCapabilities =0;
pers->wapiCapabilities =0;
pers->pskOrPassphrase=CSR_WIFI_NME_AP_CREDENTIAL_TYPE_PSK;
pers->authPers_credentials.psk.encryptionMode =
(CSR_WIFI_NME_ENCRYPTION_CIPHER_PAIRWISE_CCMP |CSR_WIFI_NME_ENCRYPTION_CIPHER_GROUP_CCMP) ;
for(i=0;i<32;i++){
psk[i] = (16*hex_look_up(key[j]))+hex_look_up(key[j+1]);
j+=2;
}
} else {
unifi_notice(priv,"store_ap_config_from_string: Unknown security: Assuming Open");
ap_config->credentials.authType = CSR_WIFI_SME_AP_AUTH_TYPE_OPEN_SYSTEM;
return -1;
}
ret = decode_parameter_from_string(priv,&str_ptr, "CHANNEL=", PARAM_TYPE_INT, &tmp_var, 5);
if(ret)
return -1;
ap_config->channel = tmp_var;
ret = decode_parameter_from_string(priv,&str_ptr, "PREAMBLE=", PARAM_TYPE_INT, &tmp_var, 5);
if(ret)
return -1;
ap_mac_config->preamble = tmp_var;
ret = decode_parameter_from_string(priv,&str_ptr, "MAX_SCB=", PARAM_TYPE_INT, &tmp_var, 5);
ap_config->max_connections = tmp_var;
return ret;
}
static int
iwprivsapstart(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int r;
unifi_trace(priv, UDBG1, "iwprivsapstart\n" );
r = sme_ap_start(priv,interfacePriv->InterfaceTag,&priv->ap_config);
if(r) {
unifi_error(priv,"iwprivsapstart AP START failed : %d\n",-r);
}
return r;
}
static int
iwprivsapconfig(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
char *cfg_str = NULL;
int r;
unifi_trace(priv, UDBG1, "iwprivsapconfig\n" );
if (wrqu->data.length != 0) {
char *str;
if (!(cfg_str = kmalloc(wrqu->data.length+1, GFP_KERNEL)))
{
return -ENOMEM;
}
if (copy_from_user(cfg_str, wrqu->data.pointer, wrqu->data.length)) {
kfree(cfg_str);
return -EFAULT;
}
cfg_str[wrqu->data.length] = 0;
unifi_trace(priv,UDBG2,"length:%d\n",wrqu->data.length);
unifi_trace(priv,UDBG2,"AP configuration string:%s\n",cfg_str);
str = cfg_str;
if ((r = store_ap_config_from_string(priv,str))) {
unifi_error(priv, "iwprivsapconfig:Failed to decode the string %d\n",r);
kfree(cfg_str);
return -EIO;
}
} else {
unifi_error(priv,"iwprivsapconfig argument length = 0 \n");
return -EIO;
}
r = sme_ap_config(priv, &priv->ap_mac_config, &priv->group_sec_config);
if(r) {
unifi_error(priv,"iwprivsapstop AP Config failed : %d\n",-r);
} else if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_trace(priv, UDBG1, "iwprivsapconfig: Starting the AP");
r = sme_ap_start(priv,interfacePriv->InterfaceTag,&priv->ap_config);
if(r) {
unifi_error(priv,"iwprivsapstart AP START failed : %d\n",-r);
}
}
kfree(cfg_str);
return r;
}
static int
iwprivsapstop(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int r;
u16 interface_tag = interfacePriv->InterfaceTag;
unifi_trace(priv, UDBG1, "iwprivsapstop\n" );
r = sme_ap_stop(priv,interface_tag);
if(r) {
unifi_error(priv,"iwprivsapstop AP STOP failed : %d\n",-r);
}
return r;
}
static int
iwprivsapfwreload(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
unifi_trace(priv, UDBG1, "iwprivsapfwreload\n" );
return 0;
}
static int
iwprivsstackstart(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
unifi_trace(priv, UDBG1, "iwprivsstackstart\n" );
return 0;
}
static int
iwprivsstackstop(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int r = 0;
u16 interface_tag = interfacePriv->InterfaceTag;
unifi_trace(priv, UDBG1, "iwprivsstackstop\n" );
switch(interfacePriv->interfaceMode) {
case CSR_WIFI_ROUTER_CTRL_MODE_STA:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PCLI:
case CSR_WIFI_ROUTER_CTRL_MODE_IBSS:
r = sme_mgt_disconnect(priv);
break;
case CSR_WIFI_ROUTER_CTRL_MODE_AP:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PGO:
r = sme_ap_stop(priv,interface_tag);
break;
default :
break;
}
if(r) {
unifi_error(priv,"iwprivsstackstop Stack stop failed : %d\n",-r);
}
return 0;
}
static int
iwprivsconfwapi(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
u8 enable;
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
func_enter();
unifi_trace(priv, UDBG1, "iwprivsconfwapi\n" );
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "iwprivsconfwapi: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
enable = *(u8*)(extra);
if (enable) {
priv->connection_config.authModeMask = CSR_WIFI_SME_AUTH_MODE_80211_OPEN;
priv->connection_config.authModeMask |= (CSR_WIFI_SME_AUTH_MODE_WAPI_WAIPSK | CSR_WIFI_SME_AUTH_MODE_WAPI_WAI);
priv->connection_config.encryptionModeMask |=
CSR_WIFI_SME_ENCRYPTION_CIPHER_PAIRWISE_SMS4 | CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_SMS4;
} else {
priv->connection_config.authModeMask &= ~(CSR_WIFI_SME_AUTH_MODE_WAPI_WAIPSK | CSR_WIFI_SME_AUTH_MODE_WAPI_WAI);
priv->connection_config.encryptionModeMask &=
~(CSR_WIFI_SME_ENCRYPTION_CIPHER_PAIRWISE_SMS4 | CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_SMS4);
}
func_exit();
return 0;
}
static int
iwprivswpikey(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int r = 0, i;
CsrWifiSmeKey key;
unifiio_wapi_key_t inKey;
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
func_enter();
unifi_trace(priv, UDBG1, "iwprivswpikey\n" );
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "iwprivswpikey: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
inKey = *(unifiio_wapi_key_t*)(extra);
if (inKey.unicastKey) {
key.keyType = CSR_WIFI_SME_KEY_TYPE_PAIRWISE;
} else {
key.keyType = CSR_WIFI_SME_KEY_TYPE_GROUP;
}
key.keyIndex = inKey.keyIndex;
for (i = 0; i < 16; i+= 2)
{
key.keyRsc[i/2] = inKey.keyRsc[i+1] << 8 | inKey.keyRsc[i];
}
memcpy(key.address.a, inKey.address, 6);
key.keyLength = 32;
memcpy(key.key, inKey.key, 32);
key.authenticator = 0;
key.wepTxKey = 0;
unifi_trace(priv, UDBG1, "keyType = %d, keyIndex = %d, wepTxKey = %d, keyRsc = %x:%x, auth = %d, address = %x:%x, "
"keylength = %d, key = %x:%x\n", key.keyType, key.keyIndex, key.wepTxKey,
key.keyRsc[0], key.keyRsc[7], key.authenticator,
key.address.a[0], key.address.a[5], key.keyLength, key.key[0],
key.key[15]);
r = sme_mgt_key(priv, &key, CSR_WIFI_SME_LIST_ACTION_ADD);
if (r) {
unifi_error(priv, "SETKEYS request was rejected with result %d\n", r);
return convert_sme_error(r);
}
func_exit();
return r;
}
static int
unifi_giwname(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
char *name = wrqu->name;
unifi_trace(priv, UDBG2, "unifi_giwname\n");
if (priv->if_index == CSR_INDEX_5G) {
strcpy(name, "IEEE 802.11-a");
} else {
strcpy(name, "IEEE 802.11-bgn");
}
return 0;
}
static int
unifi_siwfreq(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_freq *freq = (struct iw_freq *)wrqu;
func_enter();
unifi_trace(priv, UDBG2, "unifi_siwfreq\n");
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwfreq: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
if ((freq->e == 0) && (freq->m <= 1000)) {
priv->connection_config.adhocChannel = freq->m;
} else {
priv->connection_config.adhocChannel = wext_freq_to_channel(freq->m, freq->e);
}
func_exit();
return 0;
}
static int
unifi_giwfreq(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_freq *freq = (struct iw_freq *)wrqu;
int err = 0;
CsrWifiSmeConnectionInfo connectionInfo;
func_enter();
unifi_trace(priv, UDBG2, "unifi_giwfreq\n");
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_giwfreq: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
UF_RTNL_UNLOCK();
err = sme_mgt_connection_info_get(priv, &connectionInfo);
UF_RTNL_LOCK();
freq->m = channel_to_mhz(connectionInfo.channelNumber,
(connectionInfo.networkType80211 == CSR_WIFI_SME_RADIO_IF_GHZ_5_0));
freq->e = 6;
func_exit();
return convert_sme_error(err);
}
static int
unifi_siwmode(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
func_enter();
unifi_trace(priv, UDBG2, "unifi_siwmode\n");
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwmode: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
switch(wrqu->mode) {
case IW_MODE_ADHOC:
priv->connection_config.bssType = CSR_WIFI_SME_BSS_TYPE_ADHOC;
break;
case IW_MODE_INFRA:
priv->connection_config.bssType = CSR_WIFI_SME_BSS_TYPE_INFRASTRUCTURE;
break;
case IW_MODE_AUTO:
priv->connection_config.bssType = CSR_WIFI_SME_BSS_TYPE_ANY_BSS;
break;
default:
unifi_notice(priv, "Unknown IW MODE value.\n");
}
priv->connection_config.ssid.length = 0;
memset(priv->connection_config.bssid.a, 0xFF, ETH_ALEN);
func_exit();
return 0;
}
static int
unifi_giwmode(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int r = 0;
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
CsrWifiSmeConnectionConfig connectionConfig;
func_enter();
unifi_trace(priv, UDBG2, "unifi_giwmode\n");
CHECK_INITED(priv);
unifi_trace(priv, UDBG2, "unifi_giwmode: Exisitng mode = 0x%x\n",
interfacePriv->interfaceMode);
switch(interfacePriv->interfaceMode) {
case CSR_WIFI_ROUTER_CTRL_MODE_STA:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PCLI:
wrqu->mode = IW_MODE_INFRA;
break;
case CSR_WIFI_ROUTER_CTRL_MODE_AP:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PGO:
wrqu->mode = IW_MODE_MASTER;
break;
case CSR_WIFI_ROUTER_CTRL_MODE_IBSS:
wrqu->mode = IW_MODE_ADHOC;
break;
case CSR_WIFI_ROUTER_CTRL_MODE_P2P:
case CSR_WIFI_ROUTER_CTRL_MODE_NONE:
UF_RTNL_UNLOCK();
r = sme_mgt_connection_config_get(priv, &connectionConfig);
UF_RTNL_LOCK();
if (r == 0) {
switch(connectionConfig.bssType) {
case CSR_WIFI_SME_BSS_TYPE_ADHOC:
wrqu->mode = IW_MODE_ADHOC;
break;
case CSR_WIFI_SME_BSS_TYPE_INFRASTRUCTURE:
wrqu->mode = IW_MODE_INFRA;
break;
default:
wrqu->mode = IW_MODE_AUTO;
unifi_notice(priv, "Unknown IW MODE value.\n");
}
}
break;
default:
wrqu->mode = IW_MODE_AUTO;
unifi_notice(priv, "Unknown IW MODE value.\n");
}
unifi_trace(priv, UDBG4, "unifi_giwmode: mode = 0x%x\n", wrqu->mode);
func_exit();
return r;
}
static int
unifi_giwrange(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct iw_point *dwrq = &wrqu->data;
struct iw_range *range = (struct iw_range *) extra;
int i;
unifi_trace(NULL, UDBG2, "unifi_giwrange\n");
dwrq->length = sizeof(struct iw_range);
memset(range, 0, sizeof(*range));
range->min_nwid = 0x0000;
range->max_nwid = 0x0000;
range->max_qual.qual = 40;
range->max_qual.level = -120;
range->max_qual.noise = -120;
i = 0;
#if WIRELESS_EXT > 15
range->bitrate[i++] = 2 * 500000;
range->bitrate[i++] = 4 * 500000;
range->bitrate[i++] = 11 * 500000;
range->bitrate[i++] = 22 * 500000;
range->bitrate[i++] = 12 * 500000;
range->bitrate[i++] = 18 * 500000;
range->bitrate[i++] = 24 * 500000;
range->bitrate[i++] = 36 * 500000;
range->bitrate[i++] = 48 * 500000;
range->bitrate[i++] = 72 * 500000;
range->bitrate[i++] = 96 * 500000;
range->bitrate[i++] = 108 * 500000;
#else
range->bitrate[i++] = 2 * 500000;
range->bitrate[i++] = 4 * 500000;
range->bitrate[i++] = 11 * 500000;
range->bitrate[i++] = 22 * 500000;
range->bitrate[i++] = 24 * 500000;
range->bitrate[i++] = 48 * 500000;
range->bitrate[i++] = 96 * 500000;
range->bitrate[i++] = 108 * 500000;
#endif
range->num_bitrates = i;
range->max_encoding_tokens = NUM_WEPKEYS;
range->num_encoding_sizes = 2;
range->encoding_size[0] = 5;
range->encoding_size[1] = 13;
range->we_version_source = 20;
range->we_version_compiled = WIRELESS_EXT;
range->num_channels = 14;
range->num_frequency = 14;
for (i = 0; (i < range->num_frequency) && (i < IW_MAX_FREQUENCIES); i++) {
int chan = i + 1;
range->freq[i].i = chan;
range->freq[i].m = channel_to_mhz(chan, 0);
range->freq[i].e = 6;
}
if ((i+3) < IW_MAX_FREQUENCIES) {
range->freq[i].i = 36;
range->freq[i].m = channel_to_mhz(36, 1);
range->freq[i].e = 6;
range->freq[i+1].i = 40;
range->freq[i+1].m = channel_to_mhz(40, 1);
range->freq[i+1].e = 6;
range->freq[i+2].i = 44;
range->freq[i+2].m = channel_to_mhz(44, 1);
range->freq[i+2].e = 6;
range->freq[i+3].i = 48;
range->freq[i+3].m = channel_to_mhz(48, 1);
range->freq[i+3].e = 6;
}
#if WIRELESS_EXT > 16
range->event_capa[0] = (IW_EVENT_CAPA_K_0 |
IW_EVENT_CAPA_MASK(SIOCGIWTHRSPY) |
IW_EVENT_CAPA_MASK(SIOCGIWAP) |
IW_EVENT_CAPA_MASK(SIOCGIWSCAN));
range->event_capa[1] = IW_EVENT_CAPA_K_1;
range->event_capa[4] = (IW_EVENT_CAPA_MASK(IWEVTXDROP) |
IW_EVENT_CAPA_MASK(IWEVCUSTOM) |
IW_EVENT_CAPA_MASK(IWEVREGISTERED) |
IW_EVENT_CAPA_MASK(IWEVEXPIRED));
#endif
#if WIRELESS_EXT > 17
range->enc_capa = IW_ENC_CAPA_WPA | IW_ENC_CAPA_WPA2 |
IW_ENC_CAPA_CIPHER_TKIP | IW_ENC_CAPA_CIPHER_CCMP;
#endif
return 0;
}
static int
unifi_siwap(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int err = 0;
func_enter();
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwap: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
if (wrqu->ap_addr.sa_family != ARPHRD_ETHER) {
return -EINVAL;
}
unifi_trace(priv, UDBG1, "unifi_siwap: asked for %pM\n",
wrqu->ap_addr.sa_data);
if (is_zero_ether_addr(wrqu->ap_addr.sa_data)) {
priv->ignore_bssid_join = FALSE;
err = sme_mgt_disconnect(priv);
if (err) {
unifi_trace(priv, UDBG4, "unifi_siwap: Disconnect failed, status %d\n", err);
}
return 0;
}
if (priv->ignore_bssid_join) {
unifi_trace(priv, UDBG4, "unifi_siwap: ignoring second join\n");
priv->ignore_bssid_join = FALSE;
} else {
memcpy(priv->connection_config.bssid.a, wrqu->ap_addr.sa_data, ETH_ALEN);
unifi_trace(priv, UDBG1, "unifi_siwap: Joining %X:%X:%X:%X:%X:%X\n",
priv->connection_config.bssid.a[0],
priv->connection_config.bssid.a[1],
priv->connection_config.bssid.a[2],
priv->connection_config.bssid.a[3],
priv->connection_config.bssid.a[4],
priv->connection_config.bssid.a[5]);
err = sme_mgt_connect(priv);
if (err) {
unifi_error(priv, "unifi_siwap: Join failed, status %d\n", err);
func_exit();
return convert_sme_error(err);
}
}
func_exit();
return 0;
}
static int
unifi_giwap(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
CsrWifiSmeConnectionInfo connectionInfo;
int r = 0;
u8 *bssid;
func_enter();
CHECK_INITED(priv);
unifi_trace(priv, UDBG2, "unifi_giwap\n");
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "iwprivswpikey: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
UF_RTNL_UNLOCK();
r = sme_mgt_connection_info_get(priv, &connectionInfo);
UF_RTNL_LOCK();
if (r == 0) {
bssid = connectionInfo.bssid.a;
wrqu->ap_addr.sa_family = ARPHRD_ETHER;
unifi_trace(priv, UDBG4, "unifi_giwap: BSSID = %pM\n", bssid);
memcpy(wrqu->ap_addr.sa_data, bssid, ETH_ALEN);
} else {
memset(wrqu->ap_addr.sa_data, 0, ETH_ALEN);
}
func_exit();
return 0;
}
static int
unifi_siwscan(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int scantype;
int r;
CsrWifiSsid scan_ssid;
unsigned char *channel_list = NULL;
int chans_good = 0;
#if WIRELESS_EXT > 17
struct iw_point *data = &wrqu->data;
struct iw_scan_req *req = (struct iw_scan_req *) extra;
#endif
func_enter();
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwscan: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
scantype = UNIFI_SCAN_ACTIVE;
#if WIRELESS_EXT > 17
if (req) {
if ((req->num_channels > 0) && (req->num_channels < IW_MAX_FREQUENCIES)) {
channel_list = kmalloc(req->num_channels, GFP_KERNEL);
if (channel_list) {
int i;
for (i = 0; i < req->num_channels; i++) {
int ch = wext_freq_to_channel(req->channel_list[i].m,
req->channel_list[i].e);
if (ch) {
channel_list[chans_good++] = ch;
}
}
unifi_trace(priv, UDBG1,
"SIWSCAN: Scanning %d channels\n", chans_good);
} else {
unifi_error(priv, "SIWSCAN: Can't alloc channel_list (%d)\n",
req->num_channels);
}
}
}
if (req && (data->flags & IW_SCAN_THIS_ESSID)) {
memcpy(scan_ssid.ssid, req->essid, req->essid_len);
scan_ssid.length = req->essid_len;
unifi_trace(priv, UDBG1,
"SIWSCAN: Scanning for %.*s\n",
scan_ssid.length, scan_ssid.ssid);
} else
#endif
{
unifi_trace(priv, UDBG1, "SIWSCAN: Scanning for all APs\n");
scan_ssid.length = 0;
}
r = sme_mgt_scan_full(priv, &scan_ssid, chans_good, channel_list);
if (r) {
unifi_error(priv, "SIWSCAN: Scan returned error %d\n", r);
} else {
unifi_trace(priv, UDBG1, "SIWSCAN: Scan done\n");
wext_send_scan_results_event(priv);
}
if (channel_list) {
kfree(channel_list);
}
func_exit();
return r;
}
static const unsigned char *
unifi_find_info_element(int id, const unsigned char *info, int len)
{
const unsigned char *ie = info;
while (len > 1)
{
int e_id, e_len;
e_id = ie[0];
e_len = ie[1];
if (e_id == id)
{
return ie;
}
len -= (e_len + 2);
ie += (e_len + 2);
}
return NULL;
}
int
unifi_translate_scan(struct net_device *dev,
struct iw_request_info *info,
char *current_ev, char *end_buf,
CsrWifiSmeScanResult *scan_data,
int scan_index)
{
struct iw_event iwe;
unsigned char *info_elems;
int info_elem_len;
const unsigned char *elem;
u16 capabilities;
int signal, noise, snr;
char *start_buf = current_ev;
char *current_val;
int i, r;
info_elems = scan_data->informationElements;
info_elem_len = scan_data->informationElementsLength;
if (!scan_data->informationElementsLength || !scan_data->informationElements) {
unifi_error(NULL, "*** NULL SCAN IEs ***\n");
return -EIO;
}
capabilities = scan_data->capabilityInformation;
unifi_trace(NULL, UDBG5, "Capabilities: 0x%x\n", capabilities);
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWAP;
iwe.u.ap_addr.sa_family = ARPHRD_ETHER;
memcpy(iwe.u.ap_addr.sa_data, scan_data->bssid.a, ETH_ALEN);
iwe.len = IW_EV_ADDR_LEN;
r = uf_iwe_stream_add_event(info, start_buf, end_buf, &iwe, IW_EV_ADDR_LEN);
if (r < 0) {
return r;
}
start_buf += r;
elem = unifi_find_info_element(IE_SSID_ID, info_elems, info_elem_len);
if (elem) {
int e_len = elem[1];
const unsigned char *e_ptr = elem + 2;
unsigned char buf[33];
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWESSID;
iwe.u.essid.length = e_len;
if (iwe.u.essid.length > 32) {
iwe.u.essid.length = 32;
}
iwe.u.essid.flags = scan_index;
memcpy(buf, e_ptr, iwe.u.essid.length);
buf[iwe.u.essid.length] = '\0';
r = uf_iwe_stream_add_point(info, start_buf, end_buf, &iwe, buf);
if (r < 0) {
return r;
}
start_buf += r;
}
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWMODE;
if (scan_data->bssType == CSR_WIFI_SME_BSS_TYPE_INFRASTRUCTURE) {
iwe.u.mode = IW_MODE_INFRA;
} else {
iwe.u.mode = IW_MODE_ADHOC;
}
iwe.len = IW_EV_UINT_LEN;
r = uf_iwe_stream_add_event(info, start_buf, end_buf, &iwe, IW_EV_UINT_LEN);
if (r < 0) {
return r;
}
start_buf += r;
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWFREQ;
iwe.u.freq.m = scan_data->channelFrequency;
iwe.u.freq.e = 6;
r = uf_iwe_stream_add_event(info, start_buf, end_buf, &iwe, IW_EV_FREQ_LEN);
if (r < 0) {
return r;
}
start_buf += r;
iwe.cmd = IWEVQUAL;
signal = scan_data->rssi;
snr = (scan_data->snr > 0) ? scan_data->snr : 0;
snr = (snr < 255) ? snr : 255;
noise = signal - snr;
signal = (signal < 63) ? signal : 63;
signal = (signal > -192) ? signal : -192;
noise = (noise < 63) ? noise : 63;
noise = (noise > -192) ? noise : -192;
signal = ( signal < 0 ) ? signal + 0x100 : signal;
noise = ( noise < 0 ) ? noise + 0x100 : noise;
iwe.u.qual.level = (u8)signal;
iwe.u.qual.noise = (u8)noise;
iwe.u.qual.qual = snr;
iwe.u.qual.updated = 0;
#if WIRELESS_EXT > 16
iwe.u.qual.updated |= IW_QUAL_LEVEL_UPDATED | IW_QUAL_NOISE_UPDATED |
IW_QUAL_QUAL_UPDATED;
#if WIRELESS_EXT > 18
iwe.u.qual.updated |= IW_QUAL_DBM;
#endif
#endif
r = uf_iwe_stream_add_event(info, start_buf, end_buf, &iwe, IW_EV_QUAL_LEN);
if (r < 0) {
return r;
}
start_buf += r;
iwe.cmd = SIOCGIWENCODE;
if (capabilities & SIG_CAP_PRIVACY) {
iwe.u.data.flags = IW_ENCODE_ENABLED | IW_ENCODE_NOKEY;
} else {
iwe.u.data.flags = IW_ENCODE_DISABLED;
}
iwe.u.data.length = 0;
iwe.len = IW_EV_POINT_LEN + iwe.u.data.length;
r = uf_iwe_stream_add_point(info, start_buf, end_buf, &iwe, "");
if (r < 0) {
return r;
}
start_buf += r;
current_val = start_buf + IW_EV_LCP_LEN;
iwe.cmd = SIOCGIWRATE;
iwe.u.bitrate.fixed = iwe.u.bitrate.disabled = 0;
elem = unifi_find_info_element(IE_SUPPORTED_RATES_ID,
info_elems, info_elem_len);
if (elem) {
int e_len = elem[1];
const unsigned char *e_ptr = elem + 2;
for (i = 0; i < e_len; i++) {
if (e_ptr[i] == 0) {
break;
}
iwe.u.bitrate.value = ((e_ptr[i] & 0x7f) * 500000);
r = uf_iwe_stream_add_value(info, start_buf, current_val, end_buf, &iwe, IW_EV_PARAM_LEN);
if (r < 0) {
return r;
}
current_val +=r;
}
}
elem = unifi_find_info_element(IE_EXTENDED_SUPPORTED_RATES_ID,
info_elems, info_elem_len);
if (elem) {
int e_len = elem[1];
const unsigned char *e_ptr = elem + 2;
for (i = 0; i < e_len; i++) {
if (e_ptr[i] == 0) {
break;
}
iwe.u.bitrate.value = ((e_ptr[i] & 0x7f) * 500000);
r = uf_iwe_stream_add_value(info, start_buf, current_val, end_buf, &iwe, IW_EV_PARAM_LEN);
if (r < 0) {
return r;
}
current_val +=r;
}
}
if ((current_val - start_buf) > IW_EV_LCP_LEN) {
start_buf = current_val;
}
#if WIRELESS_EXT > 17
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = IWEVGENIE;
iwe.u.data.length = info_elem_len;
r = uf_iwe_stream_add_point(info, start_buf, end_buf, &iwe, info_elems);
if (r < 0) {
return r;
}
start_buf += r;
#endif
return (start_buf - current_ev);
}
static int
unifi_giwscan(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_point *dwrq = &wrqu->data;
int r;
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_giwscan: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
unifi_trace(priv, UDBG1,
"unifi_giwscan: buffer (%d bytes) \n",
dwrq->length);
UF_RTNL_UNLOCK();
r = sme_mgt_scan_results_get_async(priv, info, extra, dwrq->length);
UF_RTNL_LOCK();
if (r < 0) {
unifi_trace(priv, UDBG1,
"unifi_giwscan: buffer (%d bytes) not big enough.\n",
dwrq->length);
return r;
}
dwrq->length = r;
dwrq->flags = 0;
return 0;
}
static int
unifi_siwessid(struct net_device *dev, struct iw_request_info *info,
struct iw_point *data, char *essid)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int len;
int err = 0;
func_enter();
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwessid: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
len = 0;
if (data->flags & 1) {
len = data->length;
if (len > UNIFI_MAX_SSID_LEN) {
len = UNIFI_MAX_SSID_LEN;
}
}
#ifdef UNIFI_DEBUG
{
char essid_str[UNIFI_MAX_SSID_LEN+1];
int i;
for (i = 0; i < len; i++) {
essid_str[i] = (isprint(essid[i]) ? essid[i] : '?');
}
essid_str[i] = '\0';
unifi_trace(priv, UDBG1, "unifi_siwessid: asked for '%*s' (%d)\n", len, essid_str, len);
unifi_trace(priv, UDBG2, " with authModeMask = %d", priv->connection_config.authModeMask);
}
#endif
memset(priv->connection_config.bssid.a, 0xFF, ETH_ALEN);
if (len) {
if (essid[len - 1] == 0) {
len --;
}
memcpy(priv->connection_config.ssid.ssid, essid, len);
priv->connection_config.ssid.length = len;
} else {
priv->connection_config.ssid.length = 0;
}
UF_RTNL_UNLOCK();
err = sme_mgt_connect(priv);
UF_RTNL_LOCK();
if (err) {
unifi_error(priv, "unifi_siwessid: Join failed, status %d\n", err);
func_exit();
return convert_sme_error(err);
}
func_exit();
return 0;
}
static int
unifi_giwessid(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *essid)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_point *data = &wrqu->essid;
CsrWifiSmeConnectionInfo connectionInfo;
int r = 0;
func_enter();
unifi_trace(priv, UDBG2, "unifi_giwessid\n");
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_giwessid: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
UF_RTNL_UNLOCK();
r = sme_mgt_connection_info_get(priv, &connectionInfo);
UF_RTNL_LOCK();
if (r == 0) {
data->length = connectionInfo.ssid.length;
strncpy(essid,
connectionInfo.ssid.ssid,
data->length);
data->flags = 1;
unifi_trace(priv, UDBG2, "unifi_giwessid: %.*s\n",
data->length, essid);
}
func_exit();
return 0;
}
static int
unifi_siwrate(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_param *args = &wrqu->bitrate;
CsrWifiSmeMibConfig mibConfig;
int r;
func_enter();
CHECK_INITED(priv);
unifi_trace(priv, UDBG2, "unifi_siwrate\n");
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_get(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_siwrate: Get CsrWifiSmeMibConfigValue failed.\n");
return r;
}
mibConfig.unifiFixTxDataRate = 0;
if (args->value != -1) {
mibConfig.unifiFixTxDataRate = args->value / 500000;
}
if (args->fixed == 1) {
mibConfig.unifiFixMaxTxDataRate = 0;
} else {
mibConfig.unifiFixMaxTxDataRate = 1;
}
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_set(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_siwrate: Set CsrWifiSmeMibConfigValue failed.\n");
return r;
}
func_exit();
return 0;
}
static int
unifi_giwrate(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_param *args = &wrqu->bitrate;
int r;
int bitrate, flag;
CsrWifiSmeMibConfig mibConfig;
CsrWifiSmeConnectionStats connectionStats;
func_enter();
unifi_trace(priv, UDBG2, "unifi_giwrate\n");
CHECK_INITED(priv);
flag = 0;
bitrate = 0;
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_get(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_giwrate: Get CsrWifiSmeMibConfigValue failed.\n");
return r;
}
bitrate = mibConfig.unifiFixTxDataRate;
flag = mibConfig.unifiFixMaxTxDataRate;
if (bitrate == 0) {
UF_RTNL_UNLOCK();
r = sme_mgt_connection_stats_get(priv, &connectionStats);
UF_RTNL_LOCK();
if (r == 0) {
bitrate = connectionStats.unifiTxDataRate;
}
}
args->value = bitrate * 500000;
args->fixed = !flag;
func_exit();
return 0;
}
static int
unifi_siwrts(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int val = wrqu->rts.value;
int r = 0;
CsrWifiSmeMibConfig mibConfig;
unifi_trace(priv, UDBG2, "unifi_siwrts\n");
CHECK_INITED(priv);
if (wrqu->rts.disabled) {
val = 2347;
}
if ( (val < 0) || (val > 2347) )
{
return -EINVAL;
}
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_get(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_siwrts: Get CsrWifiSmeMibConfigValue failed.\n");
return r;
}
mibConfig.dot11RtsThreshold = val;
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_set(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_siwrts: Set CsrWifiSmeMibConfigValue failed.\n");
return r;
}
return 0;
}
static int
unifi_giwrts(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int r;
int rts_thresh;
CsrWifiSmeMibConfig mibConfig;
unifi_trace(priv, UDBG2, "unifi_giwrts\n");
CHECK_INITED(priv);
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_get(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_giwrts: Get CsrWifiSmeMibConfigValue failed.\n");
return r;
}
rts_thresh = mibConfig.dot11RtsThreshold;
if (rts_thresh > 2347) {
rts_thresh = 2347;
}
wrqu->rts.value = rts_thresh;
wrqu->rts.disabled = (rts_thresh == 2347);
wrqu->rts.fixed = 1;
return 0;
}
static int
unifi_siwfrag(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int val = wrqu->frag.value;
int r = 0;
CsrWifiSmeMibConfig mibConfig;
unifi_trace(priv, UDBG2, "unifi_siwfrag\n");
CHECK_INITED(priv);
if (wrqu->frag.disabled)
val = 2346;
if ( (val < 256) || (val > 2347) )
return -EINVAL;
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_get(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_siwfrag: Get CsrWifiSmeMibConfigValue failed.\n");
return r;
}
mibConfig.dot11FragmentationThreshold = (val & ~0x1);
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_set(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_siwfrag: Set CsrWifiSmeMibConfigValue failed.\n");
return r;
}
return 0;
}
static int
unifi_giwfrag(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int r;
int frag_thresh;
CsrWifiSmeMibConfig mibConfig;
unifi_trace(priv, UDBG2, "unifi_giwfrag\n");
CHECK_INITED(priv);
UF_RTNL_UNLOCK();
r = sme_mgt_mib_config_get(priv, &mibConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_giwfrag: Get CsrWifiSmeMibConfigValue failed.\n");
return r;
}
frag_thresh = mibConfig.dot11FragmentationThreshold;
wrqu->frag.value = frag_thresh;
wrqu->frag.disabled = (frag_thresh >= 2346);
wrqu->frag.fixed = 1;
return 0;
}
static int
unifi_siwencode(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_point *erq = &wrqu->encoding;
int index;
int rc = 0;
int privacy = -1;
CsrWifiSmeKey sme_key;
func_enter();
unifi_trace(priv, UDBG2, "unifi_siwencode\n");
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwencode: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
index = (erq->flags & IW_ENCODE_INDEX);
if ((index < 0) || (index > 4)) {
unifi_error(priv, "unifi_siwencode: Request to set an invalid key (index:%d)", index);
return -EINVAL;
}
if (erq->length > 0) {
if ((erq->length > LARGE_KEY_SIZE) || (erq->length < SMALL_KEY_SIZE)) {
unifi_error(priv, "unifi_siwencode: Request to set an invalid key (length:%d)",
erq->length);
return -EINVAL;
}
if ((index < 1) || (index > 4)) {
if (!priv->wep_tx_key_index) {
priv->wep_tx_key_index = 1;
}
index = priv->wep_tx_key_index;
}
if (!priv->wep_tx_key_index) {
priv->wep_tx_key_index = index;
}
unifi_trace(priv, UDBG1, "Tx key Index is %d\n", priv->wep_tx_key_index);
privacy = 1;
if ((erq->flags & IW_ENCODE_NOKEY) == 0) {
unifi_trace(priv, UDBG1, "New %s key (len=%d, index=%d)\n",
(priv->wep_tx_key_index == index) ? "tx" : "",
erq->length, index);
sme_key.wepTxKey = (priv->wep_tx_key_index == index);
if (priv->wep_tx_key_index == index) {
sme_key.keyType = CSR_WIFI_SME_KEY_TYPE_PAIRWISE;
} else {
sme_key.keyType = CSR_WIFI_SME_KEY_TYPE_GROUP;
}
sme_key.keyIndex = (index - 1);
sme_key.keyLength = erq->length;
sme_key.authenticator = 0;
memset(sme_key.address.a, 0xFF, ETH_ALEN);
memcpy(sme_key.key, extra, erq->length);
UF_RTNL_UNLOCK();
rc = sme_mgt_key(priv, &sme_key, CSR_WIFI_SME_LIST_ACTION_ADD);
UF_RTNL_LOCK();
if (rc) {
unifi_error(priv, "unifi_siwencode: Set key failed (%d)", rc);
return convert_sme_error(rc);
}
priv->wep_keys[index - 1].len = erq->length;
memcpy(priv->wep_keys[index - 1].key, extra, erq->length);
}
} else {
if (index != 0) {
unifi_trace(priv, UDBG1, "Tx key Index is %d\n", index - 1);
priv->wep_tx_key_index = index;
sme_key.wepTxKey = 1;
sme_key.keyType = CSR_WIFI_SME_KEY_TYPE_PAIRWISE;
sme_key.keyIndex = (index - 1);
sme_key.keyLength = 0;
sme_key.authenticator = 0;
UF_RTNL_UNLOCK();
rc = sme_mgt_key(priv, &sme_key, CSR_WIFI_SME_LIST_ACTION_ADD);
UF_RTNL_LOCK();
if (rc) {
unifi_error(priv, "unifi_siwencode: Set key failed (%d)", rc);
return convert_sme_error(rc);
}
privacy = 1;
}
}
if (erq->flags & IW_ENCODE_DISABLED) {
unifi_trace(priv, UDBG1, "disable WEP encryption\n");
privacy = 0;
priv->wep_tx_key_index = 0;
unifi_trace(priv, UDBG1, "IW_ENCODE_DISABLED: CSR_WIFI_SME_AUTH_MODE_80211_OPEN\n");
priv->connection_config.authModeMask = CSR_WIFI_SME_AUTH_MODE_80211_OPEN;
}
if (erq->flags & IW_ENCODE_RESTRICTED) {
unifi_trace(priv, UDBG1, "IW_ENCODE_RESTRICTED: CSR_WIFI_SME_AUTH_MODE_80211_SHARED\n");
priv->connection_config.authModeMask = CSR_WIFI_SME_AUTH_MODE_80211_SHARED;
privacy = 1;
}
if (erq->flags & IW_ENCODE_OPEN) {
unifi_trace(priv, UDBG1, "IW_ENCODE_OPEN: CSR_WIFI_SME_AUTH_MODE_80211_OPEN\n");
priv->connection_config.authModeMask = CSR_WIFI_SME_AUTH_MODE_80211_OPEN;
}
if (privacy != -1) {
priv->connection_config.privacyMode = privacy ? CSR_WIFI_SME_80211_PRIVACY_MODE_ENABLED : CSR_WIFI_SME_80211_PRIVACY_MODE_DISABLED;
priv->connection_config.encryptionModeMask = privacy ? (CSR_WIFI_SME_ENCRYPTION_CIPHER_PAIRWISE_WEP40 |
CSR_WIFI_SME_ENCRYPTION_CIPHER_PAIRWISE_WEP104 |
CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_WEP40 |
CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_WEP104) :
CSR_WIFI_SME_ENCRYPTION_CIPHER_NONE;
}
func_exit_r(rc);
return convert_sme_error(rc);
}
static int
unifi_giwencode(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_point *erq = &wrqu->encoding;
unifi_trace(priv, UDBG2, "unifi_giwencode\n");
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_giwencode: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
if (priv->connection_config.authModeMask == CSR_WIFI_SME_AUTH_MODE_80211_SHARED) {
erq->flags = IW_ENCODE_RESTRICTED;
}
else {
if (priv->connection_config.privacyMode == CSR_WIFI_SME_80211_PRIVACY_MODE_DISABLED) {
erq->flags = IW_ENCODE_DISABLED;
} else {
erq->flags = IW_ENCODE_OPEN;
}
}
erq->length = 0;
if (erq->flags != IW_ENCODE_DISABLED) {
int index = priv->wep_tx_key_index;
if ((index > 0) && (index <= NUM_WEPKEYS)) {
erq->flags |= (index & IW_ENCODE_INDEX);
erq->length = priv->wep_keys[index - 1].len;
memcpy(extra, priv->wep_keys[index - 1].key, erq->length);
} else {
unifi_notice(priv, "unifi_giwencode: Surprise, do not have a valid key index (%d)\n",
index);
}
}
return 0;
}
static int
unifi_siwpower(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct iw_param *args = &wrqu->power;
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int listen_interval, wake_for_dtim;
int r = 0;
CsrWifiSmePowerConfig powerConfig;
unifi_trace(priv, UDBG2, "unifi_siwpower\n");
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwpower: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
UF_RTNL_UNLOCK();
r = sme_mgt_power_config_get(priv, &powerConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_siwpower: Get unifi_PowerConfigValue failed.\n");
return r;
}
listen_interval = -1;
wake_for_dtim = -1;
if (args->disabled) {
powerConfig.powerSaveLevel = CSR_WIFI_SME_POWER_SAVE_LEVEL_LOW;
}
else
{
powerConfig.powerSaveLevel = CSR_WIFI_SME_POWER_SAVE_LEVEL_HIGH;
switch (args->flags & IW_POWER_TYPE) {
case 0:
break;
case IW_POWER_PERIOD:
listen_interval = args->value / 1000;
break;
default:
return -EINVAL;
}
switch (args->flags & IW_POWER_MODE) {
case 0:
break;
case IW_POWER_UNICAST_R:
wake_for_dtim = 0;
break;
case IW_POWER_ALL_R:
wake_for_dtim = 1;
break;
default:
return -EINVAL;
}
}
if (listen_interval > 0) {
powerConfig.listenIntervalTu = listen_interval;
unifi_trace(priv, UDBG4, "unifi_siwpower: new Listen Interval = %d.\n",
powerConfig.listenIntervalTu);
}
if (wake_for_dtim >= 0) {
powerConfig.rxDtims = wake_for_dtim;
}
UF_RTNL_UNLOCK();
r = sme_mgt_power_config_set(priv, &powerConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_siwpower: Set unifi_PowerConfigValue failed.\n");
return r;
}
return 0;
}
static int
unifi_giwpower(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct iw_param *args = &wrqu->power;
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
CsrWifiSmePowerConfig powerConfig;
int r;
unifi_trace(priv, UDBG2, "unifi_giwpower\n");
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_giwpower: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
args->flags = 0;
UF_RTNL_UNLOCK();
r = sme_mgt_power_config_get(priv, &powerConfig);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "unifi_giwpower: Get unifi_PowerConfigValue failed.\n");
return r;
}
unifi_trace(priv, UDBG4, "unifi_giwpower: mode=%d\n",
powerConfig.powerSaveLevel);
args->disabled = (powerConfig.powerSaveLevel == CSR_WIFI_SME_POWER_SAVE_LEVEL_LOW);
if (args->disabled) {
args->flags = 0;
return 0;
}
args->value = powerConfig.listenIntervalTu * 1000;
args->flags |= IW_POWER_PERIOD;
if (powerConfig.rxDtims) {
args->flags |= IW_POWER_ALL_R;
} else {
args->flags |= IW_POWER_UNICAST_R;
}
return 0;
}
static int
unifi_siwcommit(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
return 0;
}
static int
unifi_siwmlme(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_mlme *mlme = (struct iw_mlme *)extra;
func_enter();
unifi_trace(priv, UDBG2, "unifi_siwmlme\n");
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwmlme: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
switch (mlme->cmd) {
case IW_MLME_DEAUTH:
case IW_MLME_DISASSOC:
UF_RTNL_UNLOCK();
sme_mgt_disconnect(priv);
UF_RTNL_LOCK();
break;
default:
func_exit_r(-EOPNOTSUPP);
return -EOPNOTSUPP;
}
func_exit();
return 0;
}
static int
unifi_siwgenie(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int len;
func_enter();
unifi_trace(priv, UDBG2, "unifi_siwgenie\n");
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwgenie: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
if ( priv->connection_config.mlmeAssociateReqInformationElements) {
kfree( priv->connection_config.mlmeAssociateReqInformationElements);
}
priv->connection_config.mlmeAssociateReqInformationElementsLength = 0;
priv->connection_config.mlmeAssociateReqInformationElements = NULL;
len = wrqu->data.length;
if (len == 0) {
func_exit();
return 0;
}
priv->connection_config.mlmeAssociateReqInformationElements = kmalloc(len, GFP_KERNEL);
if (priv->connection_config.mlmeAssociateReqInformationElements == NULL) {
func_exit();
return -ENOMEM;
}
priv->connection_config.mlmeAssociateReqInformationElementsLength = len;
memcpy( priv->connection_config.mlmeAssociateReqInformationElements, extra, len);
func_exit();
return 0;
}
static int
unifi_giwgenie(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
int len;
func_enter();
unifi_trace(priv, UDBG2, "unifi_giwgenie\n");
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_giwgenie: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
len = priv->connection_config.mlmeAssociateReqInformationElementsLength;
if (len == 0) {
wrqu->data.length = 0;
return 0;
}
if (wrqu->data.length < len) {
return -E2BIG;
}
wrqu->data.length = len;
memcpy(extra, priv->connection_config.mlmeAssociateReqInformationElements, len);
func_exit();
return 0;
}
static int
_unifi_siwauth(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
CsrWifiSmeAuthModeMask new_auth;
func_enter();
unifi_trace(priv, UDBG2, "unifi_siwauth\n");
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwauth: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
switch (wrqu->param.flags & IW_AUTH_INDEX) {
case IW_AUTH_WPA_ENABLED:
unifi_trace(priv, UDBG1, "IW_AUTH_WPA_ENABLED: %d\n", wrqu->param.value);
if (wrqu->param.value == 0) {
unifi_trace(priv, UDBG5, "IW_AUTH_WPA_ENABLED: CSR_WIFI_SME_AUTH_MODE_80211_OPEN\n");
priv->connection_config.authModeMask = CSR_WIFI_SME_AUTH_MODE_80211_OPEN;
}
break;
case IW_AUTH_PRIVACY_INVOKED:
unifi_trace(priv, UDBG1, "IW_AUTH_PRIVACY_INVOKED: %d\n", wrqu->param.value);
priv->connection_config.privacyMode = wrqu->param.value ? CSR_WIFI_SME_80211_PRIVACY_MODE_ENABLED : CSR_WIFI_SME_80211_PRIVACY_MODE_DISABLED;
if (wrqu->param.value == CSR_WIFI_SME_80211_PRIVACY_MODE_DISABLED)
{
priv->connection_config.encryptionModeMask = CSR_WIFI_SME_ENCRYPTION_CIPHER_NONE;
}
break;
case IW_AUTH_80211_AUTH_ALG:
new_auth = 0;
if (wrqu->param.value & IW_AUTH_ALG_OPEN_SYSTEM) {
unifi_trace(priv, UDBG1, "IW_AUTH_80211_AUTH_ALG: %d (IW_AUTH_ALG_OPEN_SYSTEM)\n", wrqu->param.value);
new_auth |= CSR_WIFI_SME_AUTH_MODE_80211_OPEN;
}
if (wrqu->param.value & IW_AUTH_ALG_SHARED_KEY) {
unifi_trace(priv, UDBG1, "IW_AUTH_80211_AUTH_ALG: %d (IW_AUTH_ALG_SHARED_KEY)\n", wrqu->param.value);
new_auth |= CSR_WIFI_SME_AUTH_MODE_80211_SHARED;
}
if (wrqu->param.value & IW_AUTH_ALG_LEAP) {
unifi_trace(priv, UDBG1, "IW_AUTH_80211_AUTH_ALG: %d (IW_AUTH_ALG_LEAP)\n", wrqu->param.value);
new_auth |= CSR_WIFI_SME_AUTH_MODE_8021X_OTHER1X;
}
if (new_auth == 0) {
unifi_trace(priv, UDBG1, "IW_AUTH_80211_AUTH_ALG: invalid value %d\n",
wrqu->param.value);
return -EINVAL;
} else {
priv->connection_config.authModeMask = new_auth;
}
break;
case IW_AUTH_WPA_VERSION:
unifi_trace(priv, UDBG1, "IW_AUTH_WPA_VERSION: %d\n", wrqu->param.value);
priv->ignore_bssid_join = TRUE;
if (!(wrqu->param.value & IW_AUTH_WPA_VERSION_DISABLED)) {
priv->connection_config.authModeMask = CSR_WIFI_SME_AUTH_MODE_80211_OPEN;
if (wrqu->param.value & IW_AUTH_WPA_VERSION_WPA) {
unifi_trace(priv, UDBG4, "IW_AUTH_WPA_VERSION: WPA, WPA-PSK\n");
priv->connection_config.authModeMask |= (CSR_WIFI_SME_AUTH_MODE_8021X_WPA | CSR_WIFI_SME_AUTH_MODE_8021X_WPAPSK);
}
if (wrqu->param.value & IW_AUTH_WPA_VERSION_WPA2) {
unifi_trace(priv, UDBG4, "IW_AUTH_WPA_VERSION: WPA2, WPA2-PSK\n");
priv->connection_config.authModeMask |= (CSR_WIFI_SME_AUTH_MODE_8021X_WPA2 | CSR_WIFI_SME_AUTH_MODE_8021X_WPA2PSK);
}
}
break;
case IW_AUTH_CIPHER_PAIRWISE:
unifi_trace(priv, UDBG1, "IW_AUTH_CIPHER_PAIRWISE: %d\n", wrqu->param.value);
priv->connection_config.encryptionModeMask = CSR_WIFI_SME_ENCRYPTION_CIPHER_NONE;
if (wrqu->param.value & IW_AUTH_CIPHER_WEP40) {
priv->connection_config.encryptionModeMask |=
CSR_WIFI_SME_ENCRYPTION_CIPHER_PAIRWISE_WEP40 | CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_WEP40;
}
if (wrqu->param.value & IW_AUTH_CIPHER_WEP104) {
priv->connection_config.encryptionModeMask |=
CSR_WIFI_SME_ENCRYPTION_CIPHER_PAIRWISE_WEP104 | CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_WEP104;
}
if (wrqu->param.value & IW_AUTH_CIPHER_TKIP) {
priv->connection_config.encryptionModeMask |=
CSR_WIFI_SME_ENCRYPTION_CIPHER_PAIRWISE_TKIP | CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_TKIP;
}
if (wrqu->param.value & IW_AUTH_CIPHER_CCMP) {
priv->connection_config.encryptionModeMask |=
CSR_WIFI_SME_ENCRYPTION_CIPHER_PAIRWISE_CCMP | CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_CCMP;
}
break;
case IW_AUTH_CIPHER_GROUP:
unifi_trace(priv, UDBG1, "IW_AUTH_CIPHER_GROUP: %d\n", wrqu->param.value);
priv->connection_config.encryptionModeMask &= ~(CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_WEP40 |
CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_WEP104 |
CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_TKIP |
CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_CCMP);
if (wrqu->param.value & IW_AUTH_CIPHER_WEP40) {
priv->connection_config.encryptionModeMask |= CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_WEP40;
}
if (wrqu->param.value & IW_AUTH_CIPHER_WEP104) {
priv->connection_config.encryptionModeMask |= CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_WEP104;
}
if (wrqu->param.value & IW_AUTH_CIPHER_TKIP) {
priv->connection_config.encryptionModeMask |= CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_TKIP;
}
if (wrqu->param.value & IW_AUTH_CIPHER_CCMP) {
priv->connection_config.encryptionModeMask |= CSR_WIFI_SME_ENCRYPTION_CIPHER_GROUP_CCMP;
}
break;
case IW_AUTH_KEY_MGMT:
unifi_trace(priv, UDBG1, "IW_AUTH_KEY_MGMT: %d\n", wrqu->param.value);
if (priv->connection_config.authModeMask & (CSR_WIFI_SME_AUTH_MODE_8021X_WPA | CSR_WIFI_SME_AUTH_MODE_8021X_WPAPSK)) {
if (wrqu->param.value == IW_AUTH_KEY_MGMT_802_1X) {
priv->connection_config.authModeMask &= ~CSR_WIFI_SME_AUTH_MODE_8021X_WPAPSK;
}
if (wrqu->param.value == IW_AUTH_KEY_MGMT_PSK) {
priv->connection_config.authModeMask &= ~CSR_WIFI_SME_AUTH_MODE_8021X_WPA;
}
unifi_trace(priv, UDBG5, "IW_AUTH_KEY_MGMT: WPA: %d\n",
priv->connection_config.authModeMask);
}
if (priv->connection_config.authModeMask & (CSR_WIFI_SME_AUTH_MODE_8021X_WPA2 | CSR_WIFI_SME_AUTH_MODE_8021X_WPA2PSK)) {
if (wrqu->param.value == IW_AUTH_KEY_MGMT_802_1X) {
priv->connection_config.authModeMask &= ~CSR_WIFI_SME_AUTH_MODE_8021X_WPA2PSK;
}
if (wrqu->param.value == IW_AUTH_KEY_MGMT_PSK) {
priv->connection_config.authModeMask &= ~CSR_WIFI_SME_AUTH_MODE_8021X_WPA2;
}
unifi_trace(priv, UDBG5, "IW_AUTH_KEY_MGMT: WPA2: %d\n",
priv->connection_config.authModeMask);
}
break;
case IW_AUTH_TKIP_COUNTERMEASURES:
unifi_trace(priv, UDBG1, "IW_AUTH_TKIP_COUNTERMEASURES: %d\n", wrqu->param.value);
break;
case IW_AUTH_DROP_UNENCRYPTED:
unifi_trace(priv, UDBG1, "IW_AUTH_DROP_UNENCRYPTED: %d\n", wrqu->param.value);
break;
case IW_AUTH_RX_UNENCRYPTED_EAPOL:
unifi_trace(priv, UDBG1, "IW_AUTH_RX_UNENCRYPTED_EAPOL: %d\n", wrqu->param.value);
break;
case IW_AUTH_ROAMING_CONTROL:
unifi_trace(priv, UDBG1, "IW_AUTH_ROAMING_CONTROL: %d\n", wrqu->param.value);
break;
default:
unifi_trace(priv, UDBG1, "Unsupported auth param %d to 0x%X\n",
wrqu->param.flags & IW_AUTH_INDEX,
wrqu->param.value);
return -EOPNOTSUPP;
}
unifi_trace(priv, UDBG2, "authModeMask = %d", priv->connection_config.authModeMask);
func_exit();
return 0;
}
static int
unifi_siwauth(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int err = 0;
UF_RTNL_UNLOCK();
err = _unifi_siwauth(dev, info, wrqu, extra);
UF_RTNL_LOCK();
return err;
}
static int
unifi_giwauth(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
unifi_trace(NULL, UDBG2, "unifi_giwauth\n");
return -EOPNOTSUPP;
}
static int
_unifi_siwencodeext(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
int r = 0;
unsigned char *keydata;
unsigned char tkip_key[32];
int keyid;
unsigned char *a = (unsigned char *)ext->addr.sa_data;
CsrWifiSmeKey sme_key;
CsrWifiSmeKeyType key_type;
func_enter();
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwencodeext: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
unifi_trace(priv, UDBG1, "siwencodeext: flags=0x%X, alg=%d, ext_flags=0x%X, len=%d, index=%d,\n",
wrqu->encoding.flags, ext->alg, ext->ext_flags,
ext->key_len, (wrqu->encoding.flags & IW_ENCODE_INDEX));
unifi_trace(priv, UDBG3, " addr=%pM\n", a);
if ((ext->key_len == 0) && (ext->ext_flags & IW_ENCODE_EXT_SET_TX_KEY)) {
unifi_trace(priv, UDBG1, KERN_ERR "unifi_siwencodeext: NYI should change tx key id here!!\n");
return -ENOTSUPP;
}
memset(&sme_key, 0, sizeof(sme_key));
keydata = (unsigned char *)(ext + 1);
keyid = (wrqu->encoding.flags & IW_ENCODE_INDEX);
if (ext->alg == IW_ENCODE_ALG_NONE) {
unifi_trace(priv, UDBG1, "Deleting %s key %d\n",
(ext->ext_flags & IW_ENCODE_EXT_GROUP_KEY) ? "GROUP" : "PAIRWISE",
keyid);
if (ext->ext_flags & IW_ENCODE_EXT_GROUP_KEY) {
sme_key.keyType = CSR_WIFI_SME_KEY_TYPE_GROUP;
} else {
sme_key.keyType = CSR_WIFI_SME_KEY_TYPE_PAIRWISE;
}
sme_key.keyIndex = (keyid - 1);
sme_key.keyLength = 0;
sme_key.authenticator = 0;
memcpy(sme_key.address.a, a, ETH_ALEN);
UF_RTNL_UNLOCK();
r = sme_mgt_key(priv, &sme_key, CSR_WIFI_SME_LIST_ACTION_REMOVE);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "Delete key request was rejected with result %d\n", r);
return convert_sme_error(r);
}
return 0;
}
if (ext->alg == IW_ENCODE_ALG_WEP) {
if (!((ext->key_len == 5) || (ext->key_len == 13))) {
unifi_trace(priv, UDBG1, KERN_ERR "Invalid length for WEP key: %d\n", ext->key_len);
return -EINVAL;
}
unifi_trace(priv, UDBG1, "Setting WEP key %d tx:%d\n",
keyid, ext->ext_flags & IW_ENCODE_EXT_SET_TX_KEY);
if (ext->ext_flags & IW_ENCODE_EXT_SET_TX_KEY) {
sme_key.wepTxKey = TRUE;
sme_key.keyType = CSR_WIFI_SME_KEY_TYPE_PAIRWISE;
} else {
sme_key.wepTxKey = FALSE;
sme_key.keyType = CSR_WIFI_SME_KEY_TYPE_GROUP;
}
sme_key.keyIndex = (keyid - 1);
sme_key.keyLength = ext->key_len;
sme_key.authenticator = 0;
memset(sme_key.address.a, 0xFF, ETH_ALEN);
memcpy(sme_key.key, keydata, ext->key_len);
UF_RTNL_UNLOCK();
r = sme_mgt_key(priv, &sme_key, CSR_WIFI_SME_LIST_ACTION_ADD);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "siwencodeext: Set key failed (%d)", r);
return convert_sme_error(r);
}
return 0;
}
if (ext->key_len > 32) {
return -EINVAL;
}
if ((ext->alg == IW_ENCODE_ALG_TKIP) && (ext->key_len == 32)) {
memcpy(tkip_key, keydata, 16);
memcpy(tkip_key + 16, keydata + 24, 8);
memcpy(tkip_key + 24, keydata + 16, 8);
keydata = tkip_key;
}
key_type = (ext->ext_flags & IW_ENCODE_EXT_GROUP_KEY) ?
CSR_WIFI_SME_KEY_TYPE_GROUP :
CSR_WIFI_SME_KEY_TYPE_PAIRWISE;
sme_key.keyType = key_type;
sme_key.keyIndex = (keyid - 1);
sme_key.keyLength = ext->key_len;
sme_key.authenticator = 0;
memcpy(sme_key.address.a, ext->addr.sa_data, ETH_ALEN);
if (ext->ext_flags & IW_ENCODE_EXT_RX_SEQ_VALID) {
unifi_trace(priv, UDBG5, "RSC first 6 bytes = %*phC\n",
6, ext->rx_seq);
sme_key.keyRsc[0] = ext->rx_seq[1] << 8 | ext->rx_seq[0];
sme_key.keyRsc[1] = ext->rx_seq[3] << 8 | ext->rx_seq[2];
sme_key.keyRsc[2] = ext->rx_seq[5] << 8 | ext->rx_seq[4];
sme_key.keyRsc[3] = ext->rx_seq[7] << 8 | ext->rx_seq[6];
}
memcpy(sme_key.key, keydata, ext->key_len);
UF_RTNL_UNLOCK();
r = sme_mgt_key(priv, &sme_key, CSR_WIFI_SME_LIST_ACTION_ADD);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "SETKEYS request was rejected with result %d\n", r);
return convert_sme_error(r);
}
func_exit();
return r;
}
static int
unifi_siwencodeext(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int err = 0;
err = _unifi_siwencodeext(dev, info, wrqu, extra);
return err;
}
static int
unifi_giwencodeext(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
return -EOPNOTSUPP;
}
static int
unifi_siwpmksa(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
struct iw_pmksa *pmksa = (struct iw_pmksa *)extra;
CsrResult r = 0;
CsrWifiSmePmkidList pmkid_list;
CsrWifiSmePmkid pmkid;
CsrWifiSmeListAction action;
CHECK_INITED(priv);
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) {
unifi_error(priv, "unifi_siwpmksa: not permitted in Mode %d\n",
interfacePriv->interfaceMode);
return -EPERM;
}
unifi_trace(priv, UDBG1, "SIWPMKSA: cmd %d, %pM\n", pmksa->cmd,
pmksa->bssid.sa_data);
pmkid_list.pmkids = NULL;
switch (pmksa->cmd) {
case IW_PMKSA_ADD:
pmkid_list.pmkids = &pmkid;
action = CSR_WIFI_SME_LIST_ACTION_ADD;
pmkid_list.pmkidsCount = 1;
memcpy(pmkid.bssid.a, pmksa->bssid.sa_data, ETH_ALEN);
memcpy(pmkid.pmkid, pmksa->pmkid, UNIFI_PMKID_KEY_SIZE);
break;
case IW_PMKSA_REMOVE:
pmkid_list.pmkids = &pmkid;
action = CSR_WIFI_SME_LIST_ACTION_REMOVE;
pmkid_list.pmkidsCount = 1;
memcpy(pmkid.bssid.a, pmksa->bssid.sa_data, ETH_ALEN);
memcpy(pmkid.pmkid, pmksa->pmkid, UNIFI_PMKID_KEY_SIZE);
break;
case IW_PMKSA_FLUSH:
pmkid_list.pmkidsCount = 0;
action = CSR_WIFI_SME_LIST_ACTION_FLUSH;
break;
default:
unifi_notice(priv, "SIWPMKSA: Unknown command (0x%x)\n", pmksa->cmd);
return -EINVAL;
}
UF_RTNL_UNLOCK();
r = sme_mgt_pmkid(priv, action, &pmkid_list);
UF_RTNL_LOCK();
if (r) {
unifi_error(priv, "SIWPMKSA: Set PMKID's Failed.\n");
}
return r;
}
struct iw_statistics *
unifi_get_wireless_stats(struct net_device *dev)
{
netInterface_priv_t *interfacePriv = (netInterface_priv_t *)netdev_priv(dev);
unifi_priv_t *priv = interfacePriv->privPtr;
if (priv->init_progress != UNIFI_INIT_COMPLETED) {
return NULL;
}
return &priv->wext_wireless_stats;
}
