int
uf_sme_init(unifi_priv_t *priv)
{
sema_init(&priv->mlme_blocking_mutex, 1);
#ifdef CSR_SUPPORT_WEXT
{
int r = uf_init_wext_interface(priv);
if (r != 0) {
return r;
}
}
#endif
return 0;
}
void
uf_sme_deinit(unifi_priv_t *priv)
{
flush_workqueue(priv->unifi_workqueue);
#ifdef CSR_SUPPORT_WEXT
uf_deinit_wext_interface(priv);
#endif
}
int sme_mgt_wifi_on(unifi_priv_t *priv)
{
int r,i;
s32 csrResult;
if (priv == NULL) {
return -EINVAL;
}
for (i=0; i<CSR_WIFI_NUM_INTERFACES; i++) {
priv->interfacePriv[i]->interfaceMode = 0;
}
priv->interfacePriv[0]->interfaceMode = CSR_WIFI_ROUTER_CTRL_MODE_STA;
r = uf_request_firmware_files(priv, UNIFI_FW_STA);
if (r) {
unifi_error(priv, "sme_mgt_wifi_on: Failed to get f/w\n");
return r;
}
priv->bh_thread.block_thread = 1;
CsrSdioClaim(priv->sdio);
csrResult = CsrSdioPowerOn(priv->sdio);
CsrSdioRelease(priv->sdio);
if(csrResult != CSR_RESULT_SUCCESS && csrResult != CSR_SDIO_RESULT_NOT_RESET) {
return -EIO;
}
if (csrResult == CSR_RESULT_SUCCESS) {
r = uf_init_hw(priv);
if (r) {
return r;
}
}
priv->bh_thread.block_thread = 0;
csrResult = unifi_configure_low_power_mode(priv->card,
UNIFI_LOW_POWER_DISABLED,
UNIFI_PERIODIC_WAKE_HOST_DISABLED);
if (csrResult != CSR_RESULT_SUCCESS) {
unifi_warning(priv,
"sme_mgt_wifi_on: unifi_configure_low_power_mode() returned an error\n");
}
CsrSdioClaim(priv->sdio);
r = uf_init_bh(priv);
if (r) {
CsrSdioPowerOff(priv->sdio);
CsrSdioRelease(priv->sdio);
return r;
}
CsrSdioRelease(priv->sdio);
priv->init_progress = UNIFI_INIT_FW_DOWNLOADED;
return 0;
}
int
sme_sys_suspend(unifi_priv_t *priv)
{
const int interfaceNum = 0;
CsrResult csrResult;
uf_abort_mlme(priv);
priv->io_aborted = 0;
unifi_reset_state(priv, priv->netdev[interfaceNum]->dev_addr, 0);
netif_carrier_off(priv->netdev[interfaceNum]);
CsrSdioClaim(priv->sdio);
csrResult = unifi_force_low_power_mode(priv->card);
CsrSdioRelease(priv->sdio);
return 0;
}
int
sme_sys_resume(unifi_priv_t *priv)
{
#ifdef CSR_SUPPORT_WEXT
memset(priv->wext_conf.current_ssid, 0, UNIFI_MAX_SSID_LEN);
memset((void*)priv->wext_conf.current_bssid, 0, ETH_ALEN);
priv->wext_conf.capability = 0;
wext_send_disassoc_event(priv);
#endif
return 0;
}
void
sme_native_log_event(ul_client_t *pcli,
const u8 *sig_packed, int sig_len,
const bulk_data_param_t *bulkdata,
int dir)
{
unifi_priv_t *priv;
udi_log_t *logptr;
u8 *p;
int i, r;
int signal_len;
int total_len;
udi_msg_t *msgptr;
CSR_SIGNAL signal;
ul_client_t *client = pcli;
if (client == NULL) {
unifi_error(NULL, "sme_native_log_event: client has exited\n");
return;
}
priv = uf_find_instance(client->instance);
if (!priv) {
unifi_error(priv, "invalid priv\n");
return;
}
if ((sig_packed == NULL) || (sig_len <= 0)) {
return;
}
r = read_unpack_signal(sig_packed, &signal);
if (r == 0) {
signal_len = SigGetSize(&signal);
} else {
u16 receiver_id = CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sig_packed) + sizeof(u16)) & 0xFF00;
if (sig_len == 1) {
unifi_trace(priv, UDBG5,
"Control indication (0x%x) for native SME.\n",
*sig_packed);
*(u8*)&signal = *sig_packed;
signal_len = sig_len;
} else if (receiver_id == 0) {
unifi_trace(priv, UDBG5,
"Signal 0x%.4X with ReceiverId 0 for native SME.\n",
CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sig_packed));
*(u8*)&signal = *sig_packed;
signal_len = sig_len;
} else {
unifi_error(priv,
"sme_native_log_event - Received unknown signal 0x%.4X.\n",
CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sig_packed));
return;
}
}
unifi_trace(priv, UDBG3, "sme_native_log_event: signal 0x%.4X for %d\n",
signal.SignalPrimitiveHeader.SignalId,
client->client_id);
total_len = signal_len;
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++) {
total_len += bulkdata->d[i].data_length;
}
logptr = (udi_log_t *)kmalloc(sizeof(udi_log_t) + total_len, GFP_KERNEL);
if (logptr == NULL) {
unifi_error(priv,
"Failed to allocate %d bytes for a UDI log record\n",
sizeof(udi_log_t) + total_len);
return;
}
INIT_LIST_HEAD(&logptr->q);
msgptr = &logptr->msg;
msgptr->length = sizeof(udi_msg_t) + total_len;
msgptr->timestamp = jiffies_to_msecs(jiffies);
msgptr->direction = dir;
msgptr->signal_length = signal_len;
p = (u8 *)(msgptr + 1);
memcpy(p, &signal, signal_len);
p += signal_len;
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++) {
int len = bulkdata->d[i].data_length;
if (len > 0) {
if (bulkdata->d[i].os_data_ptr) {
memcpy(p, bulkdata->d[i].os_data_ptr, len);
} else {
memset(p, 0, len);
}
p += len;
}
}
down(&client->udi_sem);
list_add_tail(&logptr->q, &client->udi_log);
up(&client->udi_sem);
wake_up_interruptible(&client->udi_wq);
}
void
unifi_ta_indicate_protocol(void *ospriv,
CsrWifiRouterCtrlTrafficPacketType packet_type,
CsrWifiRouterCtrlProtocolDirection direction,
const CsrWifiMacAddress *src_addr)
{
}
void
unifi_ta_indicate_sampling(void *ospriv, CsrWifiRouterCtrlTrafficStats *stats)
{
}
void
unifi_ta_indicate_l4stats(void *ospriv,
u32 rxTcpThroughput,
u32 txTcpThroughput,
u32 rxUdpThroughput,
u32 txUdpThroughput)
{
}
void
uf_native_process_udi_signal(ul_client_t *pcli,
const u8 *packed_signal, int packed_signal_len,
const bulk_data_param_t *bulkdata, int dir)
{
}
void
sme_native_mlme_event_handler(ul_client_t *pcli,
const u8 *sig_packed, int sig_len,
const bulk_data_param_t *bulkdata,
int dir)
{
CSR_SIGNAL signal;
int signal_len;
unifi_priv_t *priv = uf_find_instance(pcli->instance);
int id, r;
if ((sig_packed == NULL) || (sig_len <= 0)) {
return;
}
r = read_unpack_signal(sig_packed, &signal);
if (r == 0) {
signal_len = SigGetSize(&signal);
} else {
unifi_error(priv,
"sme_native_mlme_event_handler - Received unknown signal 0x%.4X.\n",
CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sig_packed));
return;
}
id = signal.SignalPrimitiveHeader.SignalId;
unifi_trace(priv, UDBG4, "wext - Process signal 0x%.4X\n", id);
switch (id) {
case CSR_MA_PACKET_CONFIRM_ID:
case CSR_MLME_RESET_CONFIRM_ID:
case CSR_MLME_GET_CONFIRM_ID:
case CSR_MLME_SET_CONFIRM_ID:
case CSR_MLME_GET_NEXT_CONFIRM_ID:
case CSR_MLME_POWERMGT_CONFIRM_ID:
case CSR_MLME_SCAN_CONFIRM_ID:
case CSR_MLME_HL_SYNC_CONFIRM_ID:
case CSR_MLME_MEASURE_CONFIRM_ID:
case CSR_MLME_SETKEYS_CONFIRM_ID:
case CSR_MLME_DELETEKEYS_CONFIRM_ID:
case CSR_MLME_HL_SYNC_CANCEL_CONFIRM_ID:
case CSR_MLME_ADD_PERIODIC_CONFIRM_ID:
case CSR_MLME_DEL_PERIODIC_CONFIRM_ID:
case CSR_MLME_ADD_AUTONOMOUS_SCAN_CONFIRM_ID:
case CSR_MLME_DEL_AUTONOMOUS_SCAN_CONFIRM_ID:
case CSR_MLME_SET_PACKET_FILTER_CONFIRM_ID:
case CSR_MLME_STOP_MEASURE_CONFIRM_ID:
case CSR_MLME_PAUSE_AUTONOMOUS_SCAN_CONFIRM_ID:
case CSR_MLME_ADD_TRIGGERED_GET_CONFIRM_ID:
case CSR_MLME_DEL_TRIGGERED_GET_CONFIRM_ID:
case CSR_MLME_ADD_BLACKOUT_CONFIRM_ID:
case CSR_MLME_DEL_BLACKOUT_CONFIRM_ID:
case CSR_MLME_ADD_RX_TRIGGER_CONFIRM_ID:
case CSR_MLME_DEL_RX_TRIGGER_CONFIRM_ID:
case CSR_MLME_CONNECT_STATUS_CONFIRM_ID:
case CSR_MLME_MODIFY_BSS_PARAMETER_CONFIRM_ID:
case CSR_MLME_ADD_TEMPLATE_CONFIRM_ID:
case CSR_MLME_CONFIG_QUEUE_CONFIRM_ID:
case CSR_MLME_ADD_TSPEC_CONFIRM_ID:
case CSR_MLME_DEL_TSPEC_CONFIRM_ID:
case CSR_MLME_START_AGGREGATION_CONFIRM_ID:
case CSR_MLME_STOP_AGGREGATION_CONFIRM_ID:
case CSR_MLME_SM_START_CONFIRM_ID:
case CSR_MLME_LEAVE_CONFIRM_ID:
case CSR_MLME_SET_TIM_CONFIRM_ID:
case CSR_MLME_GET_KEY_SEQUENCE_CONFIRM_ID:
case CSR_MLME_SET_CHANNEL_CONFIRM_ID:
case CSR_MLME_ADD_MULTICAST_ADDRESS_CONFIRM_ID:
case CSR_DEBUG_GENERIC_CONFIRM_ID:
unifi_mlme_copy_reply_and_wakeup_client(pcli, &signal, signal_len, bulkdata);
break;
case CSR_MLME_CONNECTED_INDICATION_ID:
unifi_info(priv, "CSR_MLME_CONNECTED_INDICATION_ID ignored\n");
break;
default:
break;
}
}
int
unifi_reset_state(unifi_priv_t *priv, unsigned char *macaddr,
unsigned char set_default_mib)
{
int r = 0;
#ifdef CSR_SUPPORT_WEXT
priv->wext_conf.flag_associated = 0;
#endif
return r;
}
