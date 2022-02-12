void
ul_init_clients(unifi_priv_t *priv)
{
int id;
ul_client_t *ul_clients;
sema_init(&priv->udi_logging_mutex, 1);
priv->logging_client = NULL;
ul_clients = priv->ul_clients;
for (id = 0; id < MAX_UDI_CLIENTS; id++) {
memset(&ul_clients[id], 0, sizeof(ul_client_t));
ul_clients[id].client_id = id;
ul_clients[id].sender_id = UDI_SENDER_ID_BASE + (id << UDI_SENDER_ID_SHIFT);
ul_clients[id].instance = -1;
ul_clients[id].event_hook = NULL;
INIT_LIST_HEAD(&ul_clients[id].udi_log);
init_waitqueue_head(&ul_clients[id].udi_wq);
sema_init(&ul_clients[id].udi_sem, 1);
ul_clients[id].wake_up_wq_id = 0;
ul_clients[id].seq_no = 0;
ul_clients[id].wake_seq_no = 0;
ul_clients[id].snap_filter.count = 0;
}
}
ul_client_t *
ul_register_client(unifi_priv_t *priv, unsigned int configuration,
udi_event_t udi_event_clbk)
{
unsigned char id, ref;
ul_client_t *ul_clients;
ul_clients = priv->ul_clients;
for (id = 0; id < MAX_UDI_CLIENTS; id++) {
if (ul_clients[id].udi_enabled == 0) {
ul_clients[id].instance = priv->instance;
ul_clients[id].udi_enabled = 1;
ul_clients[id].configuration = configuration;
ul_clients[id].reply_signal = kmalloc(sizeof(CSR_SIGNAL), GFP_KERNEL);
if (ul_clients[id].reply_signal == NULL) {
unifi_error(priv, "Failed to allocate reply signal for client.\n");
return NULL;
}
for (ref = 0; ref < UNIFI_MAX_DATA_REFERENCES; ref ++) {
ul_clients[id].reply_bulkdata[ref] = kmalloc(sizeof(bulk_data_t), GFP_KERNEL);
if (ul_clients[id].reply_bulkdata[ref] == NULL) {
for (; ref > 0; ref --) {
kfree(ul_clients[id].reply_bulkdata[ref - 1]);
}
kfree(ul_clients[id].reply_signal);
unifi_error(priv, "Failed to allocate bulk data buffers for client.\n");
return NULL;
}
}
ul_clients[id].event_hook = udi_event_clbk;
unifi_trace(priv, UDBG2, "UDI %d (0x%x) registered. configuration = 0x%x\n",
id, &ul_clients[id], configuration);
return &ul_clients[id];
}
}
return NULL;
}
int
ul_deregister_client(ul_client_t *ul_client)
{
struct list_head *pos, *n;
udi_log_t *logptr;
unifi_priv_t *priv = uf_find_instance(ul_client->instance);
int ref;
ul_client->instance = -1;
ul_client->event_hook = NULL;
ul_client->udi_enabled = 0;
unifi_trace(priv, UDBG5, "UDI (0x%x) deregistered.\n", ul_client);
kfree(ul_client->reply_signal);
for (ref = 0; ref < UNIFI_MAX_DATA_REFERENCES; ref ++) {
kfree(ul_client->reply_bulkdata[ref]);
}
if (ul_client->snap_filter.count) {
ul_client->snap_filter.count = 0;
kfree(ul_client->snap_filter.protocols);
}
down(&ul_client->udi_sem);
list_for_each_safe(pos, n, &ul_client->udi_log)
{
logptr = list_entry(pos, udi_log_t, q);
list_del(pos);
kfree(logptr);
}
up(&ul_client->udi_sem);
return 0;
}
void
logging_handler(void *ospriv,
u8 *sigdata, u32 signal_len,
const bulk_data_param_t *bulkdata,
enum udi_log_direction direction)
{
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
ul_client_t *client;
int dir;
dir = (direction == UDI_LOG_FROM_HOST) ? UDI_FROM_HOST : UDI_TO_HOST;
down(&priv->udi_logging_mutex);
client = priv->logging_client;
if (client != NULL) {
client->event_hook(client, sigdata, signal_len,
bulkdata, dir);
}
up(&priv->udi_logging_mutex);
}
void
ul_log_config_ind(unifi_priv_t *priv, u8 *conf_param, int len)
{
#ifdef CSR_SUPPORT_SME
if (priv->smepriv == NULL)
{
return;
}
if ((CONFIG_IND_ERROR == (*conf_param)) && (priv->wifi_on_state == wifi_on_in_progress)) {
unifi_notice(priv, "ul_log_config_ind: wifi on in progress, suppress error\n");
} else {
CsrWifiRouterCtrlWifiOffIndSend(priv->CSR_WIFI_SME_IFACEQUEUE,0, (CsrWifiRouterCtrlControlIndication)(*conf_param));
}
#ifdef CSR_WIFI_HIP_DEBUG_OFFLINE
unifi_debug_buf_dump();
#endif
#else
bulk_data_param_t bulkdata;
if (!priv) {
unifi_notice(NULL, "uf_sme_event_ind: NULL priv\n");
return;
}
bulkdata.d[0].data_length = 0;
bulkdata.d[1].data_length = 0;
sme_native_log_event(priv->sme_cli, conf_param, sizeof(u8),
&bulkdata, UDI_CONFIG_IND);
#endif
}
static void
free_bulkdata_buffers(unifi_priv_t *priv, bulk_data_param_t *bulkdata)
{
int i;
if (bulkdata) {
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; ++i) {
if (bulkdata->d[i].data_length != 0) {
unifi_net_data_free(priv, (bulk_data_desc_t *)(&bulkdata->d[i]));
}
}
}
}
static int
_align_bulk_data_buffers(unifi_priv_t *priv, u8 *signal,
bulk_data_param_t *bulkdata)
{
unsigned int i;
if ((bulkdata == NULL) || (CSR_WIFI_ALIGN_BYTES == 0)) {
return 0;
}
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++)
{
struct sk_buff *skb;
u32 align_offset = (u32)(long)(bulkdata->d[i].os_data_ptr) & (CSR_WIFI_ALIGN_BYTES-1);
if (align_offset)
{
skb = (struct sk_buff*)bulkdata->d[i].os_net_buf_ptr;
if (skb == NULL) {
unifi_warning(priv,
"_align_bulk_data_buffers: Align offset found (%d) but skb is NULL!\n",
align_offset);
return -EINVAL;
}
if (bulkdata->d[i].data_length == 0) {
unifi_warning(priv,
"_align_bulk_data_buffers: Align offset found (%d) but length is zero\n",
align_offset);
return CSR_RESULT_SUCCESS;
}
unifi_trace(priv, UDBG5,
"Align f-h buffer (0x%p) by %d bytes (skb->data: 0x%p)\n",
bulkdata->d[i].os_data_ptr, align_offset, skb->data);
if (unlikely(skb_headroom(skb) < align_offset))
{
struct sk_buff *tmp = skb;
unifi_trace(priv, UDBG5, "Headroom not enough - realloc it\n");
skb = skb_realloc_headroom(skb, align_offset);
if (skb == NULL) {
unifi_error(priv,
"_align_bulk_data_buffers: skb_realloc_headroom failed - signal is dropped\n");
return -EFAULT;
}
kfree_skb(tmp);
bulkdata->d[i].os_net_buf_ptr = (const unsigned char*)skb;
bulkdata->d[i].os_data_ptr = (const void*)skb->data;
}
skb_push(skb, align_offset);
}
signal[SIZEOF_SIGNAL_HEADER + (i * SIZEOF_DATAREF) + 1] = align_offset;
}
return 0;
}
int
ul_send_signal_unpacked(unifi_priv_t *priv, CSR_SIGNAL *sigptr,
bulk_data_param_t *bulkdata)
{
u8 sigbuf[UNIFI_PACKED_SIGBUF_SIZE];
u16 packed_siglen;
CsrResult csrResult;
unsigned long lock_flags;
int r;
csrResult = write_pack(sigptr, sigbuf, &packed_siglen);
if (csrResult != CSR_RESULT_SUCCESS) {
unifi_error(priv, "Malformed HIP signal in ul_send_signal_unpacked()\n");
return CsrHipResultToStatus(csrResult);
}
r = _align_bulk_data_buffers(priv, sigbuf, (bulk_data_param_t*)bulkdata);
if (r) {
return r;
}
spin_lock_irqsave(&priv->send_signal_lock, lock_flags);
csrResult = unifi_send_signal(priv->card, sigbuf, packed_siglen, bulkdata);
if (csrResult != CSR_RESULT_SUCCESS) {
spin_unlock_irqrestore(&priv->send_signal_lock, lock_flags);
return CsrHipResultToStatus(csrResult);
}
spin_unlock_irqrestore(&priv->send_signal_lock, lock_flags);
return 0;
}
static void
reset_driver_status(unifi_priv_t *priv)
{
priv->sta_wmm_capabilities = 0;
#ifdef CSR_NATIVE_LINUX
#ifdef CSR_SUPPORT_WEXT
priv->wext_conf.flag_associated = 0;
priv->wext_conf.block_controlled_port = CSR_WIFI_ROUTER_PORT_ACTION_8021X_PORT_OPEN;
priv->wext_conf.bss_wmm_capabilities = 0;
priv->wext_conf.disable_join_on_ssid_set = 0;
#endif
#endif
}
int
ul_send_signal_raw(unifi_priv_t *priv, unsigned char *sigptr, int siglen,
bulk_data_param_t *bulkdata)
{
CsrResult csrResult;
unsigned long lock_flags;
int r;
r = _align_bulk_data_buffers(priv, (u8*)sigptr, bulkdata);
if (r) {
return r;
}
spin_lock_irqsave(&priv->send_signal_lock, lock_flags);
csrResult = unifi_send_signal(priv->card, sigptr, siglen, bulkdata);
if (csrResult != CSR_RESULT_SUCCESS) {
free_bulkdata_buffers(priv, bulkdata);
spin_unlock_irqrestore(&priv->send_signal_lock, lock_flags);
return CsrHipResultToStatus(csrResult);
}
spin_unlock_irqrestore(&priv->send_signal_lock, lock_flags);
if (GET_SIGNAL_ID(sigptr) == CSR_MLME_RESET_REQUEST_ID) {
reset_driver_status(priv);
}
return 0;
}
