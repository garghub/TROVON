static int
sme_init_request(unifi_priv_t *priv)
{
if (priv == NULL) {
unifi_error(priv, "sme_init_request: Invalid priv\n");
return -EIO;
}
unifi_trace(priv, UDBG5, "sme_init_request: wait sem\n");
if (down_interruptible(&priv->sme_sem)) {
unifi_error(priv, "sme_init_request: Failed to get SME semaphore\n");
return -EIO;
}
unifi_trace(priv, UDBG5, "sme_init_request: got sem: pending\n");
priv->sme_reply.request_status = SME_REQUEST_PENDING;
return 0;
}
void
uf_sme_complete_request(unifi_priv_t *priv, CsrResult reply_status, const char *func)
{
if (priv == NULL) {
unifi_error(priv, "sme_complete_request: Invalid priv\n");
return;
}
if (priv->sme_reply.request_status != SME_REQUEST_PENDING) {
unifi_notice(priv,
"sme_complete_request: request not pending %s (s:%d)\n",
(func ? func : ""), priv->sme_reply.request_status);
return;
}
unifi_trace(priv, UDBG5,
"sme_complete_request: completed %s (s:%d)\n",
(func ? func : ""), priv->sme_reply.request_status);
priv->sme_reply.request_status = SME_REQUEST_RECEIVED;
priv->sme_reply.reply_status = reply_status;
wake_up_interruptible(&priv->sme_request_wq);
return;
}
void
uf_sme_cancel_request(unifi_priv_t *priv, CsrResult reply_status)
{
if (priv == NULL) {
unifi_error(priv, "sme_cancel_request: Invalid priv\n");
return;
}
if (priv->sme_reply.request_status != SME_REQUEST_PENDING) {
unifi_trace(priv, UDBG5,
"sme_cancel_request: no request was pending (s:%d)\n",
priv->sme_reply.request_status);
return;
}
unifi_trace(priv, UDBG5,
"sme_cancel_request: request cancelled (s:%d)\n",
priv->sme_reply.request_status);
priv->sme_reply.request_status = SME_REQUEST_CANCELLED;
priv->sme_reply.reply_status = reply_status;
wake_up_interruptible(&priv->sme_request_wq);
return;
}
static int
_sme_wait_for_reply(unifi_priv_t *priv,
unsigned long timeout, const char *func)
{
long r;
unifi_trace(priv, UDBG5, "sme_wait_for_reply: %s sleep\n", func ? func : "");
r = wait_event_interruptible_timeout(priv->sme_request_wq,
(priv->sme_reply.request_status != SME_REQUEST_PENDING),
msecs_to_jiffies(timeout));
unifi_trace(priv, UDBG5, "sme_wait_for_reply: %s awake (%d)\n", func ? func : "", r);
if (r == -ERESTARTSYS) {
unifi_info(priv, "ERESTARTSYS in _sme_wait_for_reply\n");
up(&priv->sme_sem);
return r;
}
if (priv->sme_reply.request_status == SME_REQUEST_CANCELLED) {
unifi_trace(priv, UDBG5, "Cancelled waiting for SME to reply (%s s:%d, t:%d, r:%d)\n",
(func ? func : ""), priv->sme_reply.request_status, timeout, r);
up(&priv->sme_sem);
return -EIO;
}
if ((r == 0) && (priv->sme_reply.request_status != SME_REQUEST_RECEIVED)) {
unifi_notice(priv, "Timeout waiting for SME to reply (%s s:%d, t:%d)\n",
(func ? func : ""), priv->sme_reply.request_status, timeout);
priv->sme_reply.request_status = SME_REQUEST_TIMEDOUT;
up(&priv->sme_sem);
return -ETIMEDOUT;
}
unifi_trace(priv, UDBG5, "sme_wait_for_reply: %s received (%d)\n",
func ? func : "", r);
up(&priv->sme_sem);
return 0;
}
int sme_mgt_wifi_on(unifi_priv_t *priv)
{
u16 numElements;
CsrWifiSmeDataBlock* dataList;
#ifdef CSR_SUPPORT_WEXT_AP
int r;
#endif
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_wifi_on: invalid smepriv\n");
return -EIO;
}
if (priv->mib_data.length) {
numElements = 1;
dataList = &priv->mib_data;
} else {
numElements = 0;
dataList = NULL;
}
#ifdef CSR_SUPPORT_WEXT_AP
r = sme_init_request(priv);
if (r) {
return -EIO;
}
#endif
CsrWifiSmeWifiOnReqSend(0, priv->sta_mac_address, numElements, dataList);
#ifdef CSR_SUPPORT_WEXT_AP
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_LONG_TIMEOUT);
unifi_trace(priv, UDBG4,
"sme_mgt_wifi_on: unifi_mgt_wifi_oo_req <-- (r=%d, status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
return 0;
#endif
}
int sme_mgt_wifi_off(unifi_priv_t *priv)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_wifi_off: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeWifiOffReqSend(0);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_LONG_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_mgt_wifi_off: unifi_mgt_wifi_off_req <-- (r=%d, status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_mgt_key(unifi_priv_t *priv, CsrWifiSmeKey *sme_key,
CsrWifiSmeListAction action)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_key: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeKeyReqSend(0, CSR_WIFI_INTERFACE_IN_USE, action, *sme_key);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_mgt_scan_full(unifi_priv_t *priv,
CsrWifiSsid *specific_ssid,
int num_channels,
unsigned char *channel_list)
{
CsrWifiMacAddress bcastAddress = {{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }};
u8 is_active = (num_channels > 0) ? TRUE : FALSE;
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_scan_full: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_scan_full: -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
if (is_active) {
unifi_trace(priv, UDBG1,
"channel list - num_channels: %d, active scan\n",
num_channels);
}
CsrWifiSmeScanFullReqSend(0,
specific_ssid->length?1:0,
specific_ssid,
bcastAddress,
is_active,
CSR_WIFI_SME_BSS_TYPE_ANY_BSS,
CSR_WIFI_SME_SCAN_TYPE_ALL,
(u16)num_channels, channel_list,
0, NULL);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_LONG_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4, "sme_mgt_scan_full: <-- (status=%d)\n", priv->sme_reply.reply_status);
if (priv->sme_reply.reply_status == CSR_WIFI_RESULT_UNAVAILABLE) {
return 0;
} else {
return convert_sme_error(priv->sme_reply.reply_status);
}
}
int sme_mgt_scan_results_get_async(unifi_priv_t *priv,
struct iw_request_info *info,
char *scan_results,
long scan_results_len)
{
u16 scan_result_list_count;
CsrWifiSmeScanResult *scan_result_list;
CsrWifiSmeScanResult *scan_result;
int r;
int i;
char *current_ev = scan_results;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_scan_results_get_async: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeScanResultsGetReqSend(0);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_LONG_TIMEOUT);
if (r) {
return r;
}
scan_result_list_count = priv->sme_reply.reply_scan_results_count;
scan_result_list = priv->sme_reply.reply_scan_results;
unifi_trace(priv, UDBG2,
"scan_results: Scan returned %d, numElements=%d\n",
r, scan_result_list_count);
for (i = 0; i < scan_result_list_count; ++i) {
scan_result = &scan_result_list[i];
unifi_trace(priv, UDBG2, "Scan Result: %.*s\n",
scan_result->ssid.length,
scan_result->ssid.ssid);
r = unifi_translate_scan(priv->netdev[0], info,
current_ev,
scan_results + scan_results_len,
scan_result, i+1);
if (r < 0) {
kfree(scan_result_list);
priv->sme_reply.reply_scan_results_count = 0;
priv->sme_reply.reply_scan_results = NULL;
return r;
}
current_ev += r;
}
kfree(scan_result_list);
priv->sme_reply.reply_scan_results_count = 0;
priv->sme_reply.reply_scan_results = NULL;
unifi_trace(priv, UDBG2,
"scan_results: Scan translated to %d bytes\n",
current_ev - scan_results);
return (current_ev - scan_results);
}
int sme_mgt_connect(unifi_priv_t *priv)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_connect: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG2, "sme_mgt_connect: %.*s\n",
priv->connection_config.ssid.length,
priv->connection_config.ssid.ssid);
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeConnectReqSend(0, CSR_WIFI_INTERFACE_IN_USE, priv->connection_config);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (priv->sme_reply.reply_status) {
unifi_trace(priv, UDBG1, "sme_mgt_connect: failed with SME status %d\n",
priv->sme_reply.reply_status);
}
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_mgt_disconnect(unifi_priv_t *priv)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_disconnect: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeDisconnectReqSend(0, CSR_WIFI_INTERFACE_IN_USE);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4, "sme_mgt_disconnect: <-- (status=%d)\n", priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_mgt_pmkid(unifi_priv_t *priv,
CsrWifiSmeListAction action,
CsrWifiSmePmkidList *pmkid_list)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_pmkid: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmePmkidReqSend(0, CSR_WIFI_INTERFACE_IN_USE, action,
pmkid_list->pmkidsCount, pmkid_list->pmkids);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4, "sme_mgt_pmkid: <-- (status=%d)\n", priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_mgt_mib_get(unifi_priv_t *priv,
unsigned char *varbind, int *length)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_mib_get: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
priv->mib_cfm_buffer = varbind;
priv->mib_cfm_buffer_length = MAX_VARBIND_LENGTH;
CsrWifiSmeMibGetReqSend(0, *length, varbind);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
priv->mib_cfm_buffer_length = 0;
priv->mib_cfm_buffer = NULL;
return r;
}
*length = priv->mib_cfm_buffer_length;
priv->mib_cfm_buffer_length = 0;
priv->mib_cfm_buffer = NULL;
unifi_trace(priv, UDBG4, "sme_mgt_mib_get: <-- (status=%d)\n", priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_mgt_mib_set(unifi_priv_t *priv,
unsigned char *varbind, int length)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_mib_get: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeMibSetReqSend(0, length, varbind);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4, "sme_mgt_mib_set: <-- (status=%d)\n", priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_mgt_power_config_set(unifi_priv_t *priv, CsrWifiSmePowerConfig *powerConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_set_value_async: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmePowerConfigSetReqSend(0, *powerConfig);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_mgt_set_value_async: unifi_mgt_set_value_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_set_value: invalid smepriv\n");
return -EIO;
}
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtPowerConfigSetReq(priv->smepriv, *powerConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_sme_config_set(unifi_priv_t *priv, CsrWifiSmeStaConfig *staConfig, CsrWifiSmeDeviceConfig *deviceConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_sme_config_set: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeSmeStaConfigSetReqSend(0, CSR_WIFI_INTERFACE_IN_USE, *staConfig);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_mgt_sme_config_set: CsrWifiSmeSmeStaConfigSetReq <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeSmeCommonConfigSetReqSend(0, *deviceConfig);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_mgt_sme_config_set: CsrWifiSmeSmeCommonConfigSetReq <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_sme_config_set: invalid smepriv\n");
return -EIO;
}
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtSmeConfigSetReq(priv->smepriv, *staConfig);
status = CsrWifiSmeMgtDeviceConfigSetReq(priv->smepriv, *deviceConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_mib_config_set(unifi_priv_t *priv, CsrWifiSmeMibConfig *mibConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_mib_config_set: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeMibConfigSetReqSend(0, *mibConfig);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_mgt_mib_config_set: unifi_mgt_set_mib_config_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_mib_config_set: invalid smepriv\n");
return -EIO;
}
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtMibConfigSetReq(priv->smepriv, *mibConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_coex_config_set(unifi_priv_t *priv, CsrWifiSmeCoexConfig *coexConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_coex_config_set: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeCoexConfigSetReqSend(0, *coexConfig);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_mgt_coex_config_set: unifi_mgt_set_mib_config_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_coex_config_set: invalid smepriv\n");
return -EIO;
}
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtCoexConfigSetReq(priv->smepriv, *coexConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_host_config_set(unifi_priv_t *priv, CsrWifiSmeHostConfig *hostConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_host_config_set: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeHostConfigSetReqSend(0, CSR_WIFI_INTERFACE_IN_USE, *hostConfig);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_mgt_host_config_set: unifi_mgt_set_host_config_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_host_config_set: invalid smepriv\n");
return -EIO;
}
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtHostConfigSetReq(priv->smepriv, *hostConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_versions_get(unifi_priv_t *priv, CsrWifiSmeVersions *versions)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_versions_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_versions_get: unifi_mgt_versions_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeVersionsGetReqSend(0);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (versions != NULL) {
memcpy((unsigned char*)versions,
(unsigned char*)&priv->sme_reply.versions,
sizeof(CsrWifiSmeVersions));
}
unifi_trace(priv, UDBG4,
"sme_mgt_versions_get: unifi_mgt_versions_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtVersionsGetReq(priv->smepriv, versions);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_power_config_get(unifi_priv_t *priv, CsrWifiSmePowerConfig *powerConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_power_config_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_power_config_get: unifi_mgt_power_config_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmePowerConfigGetReqSend(0);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (powerConfig != NULL) {
memcpy((unsigned char*)powerConfig,
(unsigned char*)&priv->sme_reply.powerConfig,
sizeof(CsrWifiSmePowerConfig));
}
unifi_trace(priv, UDBG4,
"sme_mgt_get_versions: unifi_mgt_power_config_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtPowerConfigGetReq(priv->smepriv, powerConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_host_config_get(unifi_priv_t *priv, CsrWifiSmeHostConfig *hostConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_host_config_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_host_config_get: unifi_mgt_host_config_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeHostConfigGetReqSend(0, CSR_WIFI_INTERFACE_IN_USE);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (hostConfig != NULL) {
memcpy((unsigned char*)hostConfig,
(unsigned char*)&priv->sme_reply.hostConfig,
sizeof(CsrWifiSmeHostConfig));
}
unifi_trace(priv, UDBG4,
"sme_mgt_host_config_get: unifi_mgt_host_config_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtHostConfigGetReq(priv->smepriv, hostConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_sme_config_get(unifi_priv_t *priv, CsrWifiSmeStaConfig *staConfig, CsrWifiSmeDeviceConfig *deviceConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_sme_config_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_sme_config_get: unifi_mgt_sme_config_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeSmeCommonConfigGetReqSend(0);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (deviceConfig != NULL) {
memcpy((unsigned char*)deviceConfig,
(unsigned char*)&priv->sme_reply.deviceConfig,
sizeof(CsrWifiSmeDeviceConfig));
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeSmeStaConfigGetReqSend(0, CSR_WIFI_INTERFACE_IN_USE);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (staConfig != NULL) {
memcpy((unsigned char*)staConfig,
(unsigned char*)&priv->sme_reply.staConfig,
sizeof(CsrWifiSmeStaConfig));
}
unifi_trace(priv, UDBG4,
"sme_mgt_sme_config_get: unifi_mgt_sme_config_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtSmeConfigGetReq(priv->smepriv, staConfig);
status = CsrWifiSmeMgtDeviceConfigGetReq(priv->smepriv, deviceConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_coex_info_get(unifi_priv_t *priv, CsrWifiSmeCoexInfo *coexInfo)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_coex_info_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_coex_info_get: unifi_mgt_coex_info_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeCoexInfoGetReqSend(0);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (coexInfo != NULL) {
memcpy((unsigned char*)coexInfo,
(unsigned char*)&priv->sme_reply.coexInfo,
sizeof(CsrWifiSmeCoexInfo));
}
unifi_trace(priv, UDBG4,
"sme_mgt_coex_info_get: unifi_mgt_coex_info_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtCoexInfoGetReq(priv->smepriv, coexInfo);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_coex_config_get(unifi_priv_t *priv, CsrWifiSmeCoexConfig *coexConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_coex_config_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_coex_config_get: unifi_mgt_coex_config_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeCoexConfigGetReqSend(0);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (coexConfig != NULL) {
memcpy((unsigned char*)coexConfig,
(unsigned char*)&priv->sme_reply.coexConfig,
sizeof(CsrWifiSmeCoexConfig));
}
unifi_trace(priv, UDBG4,
"sme_mgt_coex_config_get: unifi_mgt_coex_config_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtCoexConfigGetReq(priv->smepriv, coexConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_mib_config_get(unifi_priv_t *priv, CsrWifiSmeMibConfig *mibConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_mib_config_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_mib_config_get: unifi_mgt_mib_config_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeMibConfigGetReqSend(0);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (mibConfig != NULL) {
memcpy((unsigned char*)mibConfig,
(unsigned char*)&priv->sme_reply.mibConfig,
sizeof(CsrWifiSmeMibConfig));
}
unifi_trace(priv, UDBG4,
"sme_mgt_mib_config_get: unifi_mgt_mib_config_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtMibConfigGetReq(priv->smepriv, mibConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_connection_info_get(unifi_priv_t *priv, CsrWifiSmeConnectionInfo *connectionInfo)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_connection_info_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_connection_info_get: unifi_mgt_connection_info_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeConnectionInfoGetReqSend(0, CSR_WIFI_INTERFACE_IN_USE);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (connectionInfo != NULL) {
memcpy((unsigned char*)connectionInfo,
(unsigned char*)&priv->sme_reply.connectionInfo,
sizeof(CsrWifiSmeConnectionInfo));
}
unifi_trace(priv, UDBG4,
"sme_mgt_connection_info_get: unifi_mgt_connection_info_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtConnectionInfoGetReq(priv->smepriv, connectionInfo);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_connection_config_get(unifi_priv_t *priv, CsrWifiSmeConnectionConfig *connectionConfig)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_connection_config_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_connection_config_get: unifi_mgt_connection_config_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeConnectionConfigGetReqSend(0, CSR_WIFI_INTERFACE_IN_USE);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (connectionConfig != NULL) {
memcpy((unsigned char*)connectionConfig,
(unsigned char*)&priv->sme_reply.connectionConfig,
sizeof(CsrWifiSmeConnectionConfig));
}
unifi_trace(priv, UDBG4,
"sme_mgt_connection_config_get: unifi_mgt_connection_config_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtConnectionConfigGetReq(priv->smepriv, connectionConfig);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_connection_stats_get(unifi_priv_t *priv, CsrWifiSmeConnectionStats *connectionStats)
{
#ifdef CSR_SME_USERSPACE
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_connection_stats_get: invalid smepriv\n");
return -EIO;
}
unifi_trace(priv, UDBG4, "sme_mgt_connection_stats_get: unifi_mgt_connection_stats_get_req -->\n");
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeConnectionStatsGetReqSend(0, CSR_WIFI_INTERFACE_IN_USE);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
if (connectionStats != NULL) {
memcpy((unsigned char*)connectionStats,
(unsigned char*)&priv->sme_reply.connectionStats,
sizeof(CsrWifiSmeConnectionStats));
}
unifi_trace(priv, UDBG4,
"sme_mgt_connection_stats_get: unifi_mgt_connection_stats_get_req <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
#else
CsrResult status;
CsrWifiSmeMgtClaimSyncAccess(priv->smepriv);
status = CsrWifiSmeMgtConnectionStatsGetReq(priv->smepriv, connectionStats);
CsrWifiSmeMgtReleaseSyncAccess(priv->smepriv);
return convert_sme_error(status);
#endif
}
int sme_mgt_packet_filter_set(unifi_priv_t *priv)
{
CsrWifiIp4Address ipAddress = {{0xFF, 0xFF, 0xFF, 0xFF }};
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_packet_filter_set: invalid smepriv\n");
return -EIO;
}
if (priv->packet_filters.arp_filter) {
ipAddress.a[0] = (priv->sta_ip_address ) & 0xFF;
ipAddress.a[1] = (priv->sta_ip_address >> 8) & 0xFF;
ipAddress.a[2] = (priv->sta_ip_address >> 16) & 0xFF;
ipAddress.a[3] = (priv->sta_ip_address >> 24) & 0xFF;
}
unifi_trace(priv, UDBG5,
"sme_mgt_packet_filter_set: IP address %d.%d.%d.%d\n",
ipAddress.a[0], ipAddress.a[1],
ipAddress.a[2], ipAddress.a[3]);
CsrWifiSmePacketFilterSetReqSend(0, CSR_WIFI_INTERFACE_IN_USE,
priv->packet_filters.tclas_ies_length,
priv->filter_tclas_ies,
priv->packet_filters.filter_mode,
ipAddress);
return 0;
}
int sme_mgt_tspec(unifi_priv_t *priv, CsrWifiSmeListAction action,
u32 tid, CsrWifiSmeDataBlock *tspec, CsrWifiSmeDataBlock *tclas)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_mgt_tspec: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiSmeTspecReqSend(0, CSR_WIFI_INTERFACE_IN_USE,
action, tid, TRUE, 0,
tspec->length, tspec->data,
tclas->length, tclas->data);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4, "sme_mgt_tspec: <-- (status=%d)\n", priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_sys_suspend(unifi_priv_t *priv)
{
int r;
CsrResult csrResult;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_sys_suspend: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiRouterCtrlSuspendIndSend(priv->CSR_WIFI_SME_IFACEQUEUE,0, 0, priv->wol_suspend);
r = sme_wait_for_reply(priv, UNIFI_SME_SYS_LONG_TIMEOUT);
if (r) {
unifi_notice(priv,
"suspend: SME did not reply %s, ",
(priv->ptest_mode | priv->wol_suspend) ? "leave powered" : "power off UniFi anyway\n");
if (!priv->ptest_mode) {
CsrSdioClaim(priv->sdio);
unifi_trace(priv, UDBG1, "Force deep sleep");
csrResult = unifi_force_low_power_mode(priv->card);
if (!priv->wol_suspend) {
unifi_trace(priv, UDBG1, "Power off\n");
CsrSdioPowerOff(priv->sdio);
}
CsrSdioRelease(priv->sdio);
}
}
if (priv->wol_suspend) {
unifi_trace(priv, UDBG1, "UniFi left powered for WOL\n");
if (csr_sdio_linux_remove_irq(priv->sdio)) {
unifi_notice(priv, "WOL csr_sdio_linux_remove_irq failed\n");
}
if (enable_wol == UNIFI_WOL_SDIO) {
unifi_trace(priv, UDBG1, "Enable card SDIO interrupt for SDIO WOL\n");
CsrSdioClaim(priv->sdio);
csrResult = CsrSdioInterruptEnable(priv->sdio);
CsrSdioRelease(priv->sdio);
if (csrResult != CSR_RESULT_SUCCESS) {
unifi_error(priv, "WOL CsrSdioInterruptEnable failed %d\n", csrResult);
}
} else {
unifi_trace(priv, UDBG1, "Disabled card SDIO interrupt for PIO WOL\n");
}
priv->bh_thread.block_thread = 1;
unifi_trace(priv, UDBG1, "unifi_suspend: suspended BH");
}
priv->init_progress = UNIFI_INIT_NONE;
unifi_trace(priv, UDBG1, "sme_sys_suspend: <-- (r=%d status=%d)\n", r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_sys_resume(unifi_priv_t *priv)
{
int r;
unifi_trace(priv, UDBG1, "sme_sys_resume %s\n", priv->wol_suspend ? "warm" : "");
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_sys_resume: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiRouterCtrlResumeIndSend(priv->CSR_WIFI_SME_IFACEQUEUE,0, priv->wol_suspend);
r = sme_wait_for_reply(priv, UNIFI_SME_SYS_LONG_TIMEOUT);
if (r) {
unifi_notice(priv,
"resume: SME did not reply, return success anyway\n");
}
return 0;
}
int sme_ap_stop(unifi_priv_t *priv,u16 interface_tag)
{
int r;
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_ap_stop: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiNmeApStopReqSend(0,interface_tag);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_ap_stop <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_ap_start(unifi_priv_t *priv,u16 interface_tag,
CsrWifiSmeApConfig_t * ap_config)
{
int r;
CsrWifiSmeApP2pGoConfig p2p_go_param;
memset(&p2p_go_param,0,sizeof(CsrWifiSmeApP2pGoConfig));
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_ap_start: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiNmeApStartReqSend(0,interface_tag,CSR_WIFI_AP_TYPE_LEGACY,FALSE,
ap_config->ssid,1,ap_config->channel,
ap_config->credentials,ap_config->max_connections,
p2p_go_param,FALSE);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
if (r) {
return r;
}
unifi_trace(priv, UDBG4,
"sme_ap_start <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
int sme_ap_config(unifi_priv_t *priv,
CsrWifiSmeApMacConfig *ap_mac_config,
CsrWifiNmeApConfig *group_security_config)
{
int r;
CsrWifiSmeApP2pGoConfig p2p_go_param;
memset(&p2p_go_param,0,sizeof(CsrWifiSmeApP2pGoConfig));
if (priv->smepriv == NULL) {
unifi_error(priv, "sme_ap_config: invalid smepriv\n");
return -EIO;
}
r = sme_init_request(priv);
if (r) {
return -EIO;
}
CsrWifiNmeApConfigSetReqSend(0,*group_security_config,
*ap_mac_config);
r = sme_wait_for_reply(priv, UNIFI_SME_MGT_SHORT_TIMEOUT);
unifi_trace(priv, UDBG4,
"sme_ap_config <-- (r=%d status=%d)\n",
r, priv->sme_reply.reply_status);
return convert_sme_error(priv->sme_reply.reply_status);
}
