int
uf_sme_init(unifi_priv_t *priv)
{
int i, j;
CsrWifiRouterTransportInit(priv);
priv->smepriv = priv;
init_waitqueue_head(&priv->sme_request_wq);
priv->filter_tclas_ies = NULL;
memset(&priv->packet_filters, 0, sizeof(uf_cfg_bcast_packet_filter_t));
#ifdef CSR_SUPPORT_WEXT
priv->ignore_bssid_join = FALSE;
priv->mib_data.length = 0;
uf_sme_wext_set_defaults(priv);
#endif
priv->sta_ip_address = 0xFFFFFFFF;
priv->wifi_on_state = wifi_on_unspecified;
sema_init(&priv->sme_sem, 1);
memset(&priv->sme_reply, 0, sizeof(sme_reply_t));
priv->ta_ind_work.in_use = 0;
priv->ta_sample_ind_work.in_use = 0;
priv->CSR_WIFI_SME_IFACEQUEUE = 0xFFFF;
for (i = 0; i < MAX_MA_UNIDATA_IND_FILTERS; i++) {
priv->sme_unidata_ind_filters[i].in_use = 0;
}
INIT_WORK(&priv->ta_ind_work.task, uf_ta_ind_wq);
INIT_WORK(&priv->ta_sample_ind_work.task, uf_ta_sample_ind_wq);
#ifdef CSR_SUPPORT_WEXT
INIT_WORK(&priv->sme_config_task, uf_sme_config_wq);
#endif
for (i = 0; i < CSR_WIFI_NUM_INTERFACES; i++) {
netInterface_priv_t *interfacePriv = priv->interfacePriv[i];
interfacePriv->m4_sent = FALSE;
interfacePriv->m4_bulk_data.net_buf_length = 0;
interfacePriv->m4_bulk_data.data_length = 0;
interfacePriv->m4_bulk_data.os_data_ptr = interfacePriv->m4_bulk_data.os_net_buf_ptr = NULL;
memset(&interfacePriv->controlled_data_port, 0, sizeof(unifi_port_config_t));
interfacePriv->controlled_data_port.entries_in_use = 1;
interfacePriv->controlled_data_port.port_cfg[0].in_use = TRUE;
interfacePriv->controlled_data_port.port_cfg[0].port_action = CSR_WIFI_ROUTER_CTRL_PORT_ACTION_8021X_PORT_CLOSED_DISCARD;
interfacePriv->controlled_data_port.overide_action = UF_DATA_PORT_OVERIDE;
memset(&interfacePriv->uncontrolled_data_port, 0, sizeof(unifi_port_config_t));
interfacePriv->uncontrolled_data_port.entries_in_use = 1;
interfacePriv->uncontrolled_data_port.port_cfg[0].in_use = TRUE;
interfacePriv->uncontrolled_data_port.port_cfg[0].port_action = CSR_WIFI_ROUTER_CTRL_PORT_ACTION_8021X_PORT_CLOSED_DISCARD;
interfacePriv->uncontrolled_data_port.overide_action = UF_DATA_PORT_OVERIDE;
for(j = 1; j < UNIFI_MAX_CONNECTIONS; j++) {
interfacePriv->controlled_data_port.port_cfg[j].in_use = FALSE;
interfacePriv->controlled_data_port.port_cfg[j].port_action = CSR_WIFI_ROUTER_CTRL_PORT_ACTION_8021X_PORT_CLOSED_DISCARD;
interfacePriv->uncontrolled_data_port.port_cfg[j].in_use = FALSE;
interfacePriv->uncontrolled_data_port.port_cfg[j].port_action = CSR_WIFI_ROUTER_CTRL_PORT_ACTION_8021X_PORT_CLOSED_DISCARD;
}
INIT_LIST_HEAD(&interfacePriv->genericMgtFrames);
INIT_LIST_HEAD(&interfacePriv->genericMulticastOrBroadCastMgtFrames);
INIT_LIST_HEAD(&interfacePriv->genericMulticastOrBroadCastFrames);
for(j = 0; j < UNIFI_MAX_CONNECTIONS; j++) {
interfacePriv->staInfo[j] = NULL;
}
interfacePriv->num_stations_joined = 0;
interfacePriv->sta_activity_check_enabled = FALSE;
}
return 0;
}
void
uf_sme_deinit(unifi_priv_t *priv)
{
int i,j;
u8 ba_session_idx;
ba_session_rx_struct *ba_session_rx = NULL;
ba_session_tx_struct *ba_session_tx = NULL;
CsrWifiRouterCtrlStaInfo_t *staInfo = NULL;
netInterface_priv_t *interfacePriv = NULL;
if (priv->packet_filters.tclas_ies_length) {
priv->packet_filters.tclas_ies_length = 0;
kfree(priv->filter_tclas_ies);
priv->filter_tclas_ies = NULL;
}
for (i = 0; i < MAX_MA_UNIDATA_IND_FILTERS; i++) {
priv->sme_unidata_ind_filters[i].in_use = 0;
}
for (i = 0; i < CSR_WIFI_NUM_INTERFACES; i++) {
down(&priv->ba_mutex);
for(ba_session_idx=0; ba_session_idx < MAX_SUPPORTED_BA_SESSIONS_RX; ba_session_idx++){
ba_session_rx = priv->interfacePriv[i]->ba_session_rx[ba_session_idx];
if(ba_session_rx) {
blockack_session_stop(priv,
i,
CSR_WIFI_ROUTER_CTRL_BLOCK_ACK_RECIPIENT,
ba_session_rx->tID,
ba_session_rx->macAddress);
}
}
for(ba_session_idx=0; ba_session_idx < MAX_SUPPORTED_BA_SESSIONS_TX; ba_session_idx++){
ba_session_tx = priv->interfacePriv[i]->ba_session_tx[ba_session_idx];
if(ba_session_tx) {
blockack_session_stop(priv,
i,
CSR_WIFI_ROUTER_CTRL_BLOCK_ACK_ORIGINATOR,
ba_session_tx->tID,
ba_session_tx->macAddress);
}
}
up(&priv->ba_mutex);
interfacePriv = priv->interfacePriv[i];
if(interfacePriv){
for(j = 0; j < UNIFI_MAX_CONNECTIONS; j++) {
if ((staInfo=interfacePriv->staInfo[j]) != NULL) {
unifi_trace(priv, UDBG1, "uf_sme_deinit: Canceling work queue for STA with AID: %d\n", staInfo->aid);
cancel_work_sync(&staInfo->send_disconnected_ind_task);
staInfo->nullDataHostTag = INVALID_HOST_TAG;
}
}
if (interfacePriv->sta_activity_check_enabled){
interfacePriv->sta_activity_check_enabled = FALSE;
del_timer_sync(&interfacePriv->sta_activity_check_timer);
}
}
CsrWifiRouterCtrlInterfaceReset(priv, i);
priv->interfacePriv[i]->interfaceMode = CSR_WIFI_ROUTER_CTRL_MODE_NONE;
}
}
void
unifi_ta_indicate_protocol(void *ospriv,
CsrWifiRouterCtrlTrafficPacketType packet_type,
CsrWifiRouterCtrlProtocolDirection direction,
const CsrWifiMacAddress *src_addr)
{
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
if (priv->ta_ind_work.in_use) {
unifi_warning(priv,
"unifi_ta_indicate_protocol: workqueue item still in use, not sending\n");
return;
}
if (CSR_WIFI_ROUTER_CTRL_PROTOCOL_DIRECTION_RX == direction)
{
u16 interfaceTag = 0;
CsrWifiRouterCtrlTrafficProtocolIndSend(priv->CSR_WIFI_SME_IFACEQUEUE,0,
interfaceTag,
packet_type,
direction,
*src_addr);
}
else
{
priv->ta_ind_work.packet_type = packet_type;
priv->ta_ind_work.direction = direction;
priv->ta_ind_work.src_addr = *src_addr;
queue_work(priv->unifi_workqueue, &priv->ta_ind_work.task);
}
}
void
unifi_ta_indicate_sampling(void *ospriv, CsrWifiRouterCtrlTrafficStats *stats)
{
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
if (!priv) {
return;
}
if (priv->ta_sample_ind_work.in_use) {
unifi_warning(priv,
"unifi_ta_indicate_sampling: workqueue item still in use, not sending\n");
return;
}
priv->ta_sample_ind_work.stats = *stats;
queue_work(priv->unifi_workqueue, &priv->ta_sample_ind_work.task);
}
void
unifi_ta_indicate_l4stats(void *ospriv,
u32 rxTcpThroughput,
u32 txTcpThroughput,
u32 rxUdpThroughput,
u32 txUdpThroughput)
{
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
if (!priv) {
return;
}
priv->rxTcpThroughput = rxTcpThroughput;
priv->txTcpThroughput = txTcpThroughput;
priv->rxUdpThroughput = rxUdpThroughput;
priv->txUdpThroughput = txUdpThroughput;
}
