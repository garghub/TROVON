static void _update_buffered_pkt_params_after_alignment(unifi_priv_t *priv, bulk_data_param_t *bulkdata,
tx_buffered_packets_t* buffered_pkt)
{
struct sk_buff *skb ;
u32 align_offset;
if (priv == NULL || bulkdata == NULL || buffered_pkt == NULL){
return;
}
skb = (struct sk_buff*)bulkdata->d[0].os_net_buf_ptr;
align_offset = (u32)(long)(bulkdata->d[0].os_data_ptr) & (CSR_WIFI_ALIGN_BYTES-1);
if(align_offset){
skb_pull(skb,align_offset);
}
buffered_pkt->bulkdata.os_data_ptr = bulkdata->d[0].os_data_ptr;
buffered_pkt->bulkdata.data_length = bulkdata->d[0].data_length;
buffered_pkt->bulkdata.os_net_buf_ptr = bulkdata->d[0].os_net_buf_ptr;
buffered_pkt->bulkdata.net_buf_length = bulkdata->d[0].net_buf_length;
}
void
unifi_frame_ma_packet_req(unifi_priv_t *priv, CSR_PRIORITY priority,
CSR_RATE TransmitRate, CSR_CLIENT_TAG hostTag,
u16 interfaceTag, CSR_TRANSMISSION_CONTROL transmissionControl,
CSR_PROCESS_ID leSenderProcessId, u8 *peerMacAddress,
CSR_SIGNAL *signal)
{
CSR_MA_PACKET_REQUEST *req = &signal->u.MaPacketRequest;
netInterface_priv_t *interfacePriv;
u8 ba_session_idx = 0;
ba_session_tx_struct *ba_session = NULL;
u8 *ba_addr = NULL;
interfacePriv = priv->interfacePriv[interfaceTag];
unifi_trace(priv, UDBG5,
"In unifi_frame_ma_packet_req, Frame for Peer: %pMF\n",
peerMacAddress);
signal->SignalPrimitiveHeader.SignalId = CSR_MA_PACKET_REQUEST_ID;
signal->SignalPrimitiveHeader.ReceiverProcessId = 0;
signal->SignalPrimitiveHeader.SenderProcessId = leSenderProcessId;
req->Priority = priority;
unifi_trace(priv, UDBG3, "Tx Frame with Priority: 0x%x\n", req->Priority);
req->TransmitRate = TransmitRate;
req->TransmissionControl = transmissionControl;
req->VirtualInterfaceIdentifier =
uf_get_vif_identifier(interfacePriv->interfaceMode,interfaceTag);
memcpy(req->Ra.x, peerMacAddress, ETH_ALEN);
if (hostTag == 0xffffffff) {
req->HostTag = interfacePriv->tag++;
req->HostTag |= 0x40000000;
unifi_trace(priv, UDBG3, "new host tag assigned = 0x%x\n", req->HostTag);
interfacePriv->tag &= 0x0fffffff;
} else {
req->HostTag = hostTag;
unifi_trace(priv, UDBG3, "host tag got from SME = 0x%x\n", req->HostTag);
}
if(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP ||
interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO){
ba_addr = peerMacAddress;
}else{
ba_addr = interfacePriv->bssid.a;
}
for (ba_session_idx=0; ba_session_idx < MAX_SUPPORTED_BA_SESSIONS_TX; ba_session_idx++){
ba_session = interfacePriv->ba_session_tx[ba_session_idx];
if (ba_session){
if ((!memcmp(ba_session->macAddress.a, ba_addr, ETH_ALEN)) && (ba_session->tID == priority)){
req->TransmissionControl |= CSR_ALLOW_BA;
break;
}
}
}
unifi_trace(priv, UDBG5, "leaving unifi_frame_ma_packet_req\n");
}
static
int frame_and_send_queued_pdu(unifi_priv_t* priv,tx_buffered_packets_t* buffered_pkt,
CsrWifiRouterCtrlStaInfo_t *staRecord,u8 moreData , u8 eosp)
{
CSR_SIGNAL signal;
bulk_data_param_t bulkdata;
int result;
u8 toDs, fromDs, macHeaderLengthInBytes = MAC_HEADER_SIZE;
u8 *qc;
u16 *fc = (u16*)(buffered_pkt->bulkdata.os_data_ptr);
unsigned long lock_flags;
unifi_trace(priv, UDBG3, "frame_and_send_queued_pdu with moreData: %d , EOSP: %d\n",moreData,eosp);
unifi_frame_ma_packet_req(priv, buffered_pkt->priority, buffered_pkt->rate, buffered_pkt->hostTag,
buffered_pkt->interfaceTag, buffered_pkt->transmissionControl,
buffered_pkt->leSenderProcessId, buffered_pkt->peerMacAddress.a, &signal);
bulkdata.d[0].os_data_ptr = buffered_pkt->bulkdata.os_data_ptr;
bulkdata.d[0].data_length = buffered_pkt->bulkdata.data_length;
bulkdata.d[0].os_net_buf_ptr = buffered_pkt->bulkdata.os_net_buf_ptr;
bulkdata.d[0].net_buf_length = buffered_pkt->bulkdata.net_buf_length;
bulkdata.d[1].os_data_ptr = NULL;
bulkdata.d[1].data_length = 0;
bulkdata.d[1].os_net_buf_ptr =0;
bulkdata.d[1].net_buf_length =0;
if(moreData) {
*fc |= cpu_to_le16(IEEE802_11_FC_MOREDATA_MASK);
} else {
*fc &= cpu_to_le16(~IEEE802_11_FC_MOREDATA_MASK);
}
if((staRecord != NULL)&& (staRecord->wmmOrQosEnabled == TRUE))
{
unifi_trace(priv, UDBG3, "frame_and_send_queued_pdu WMM Enabled: %d \n",staRecord->wmmOrQosEnabled);
toDs = (*fc & cpu_to_le16(IEEE802_11_FC_TO_DS_MASK))?1 : 0;
fromDs = (*fc & cpu_to_le16(IEEE802_11_FC_FROM_DS_MASK))? 1: 0;
switch(le16_to_cpu(*fc) & IEEE80211_FC_SUBTYPE_MASK)
{
case IEEE802_11_FC_TYPE_QOS_DATA & IEEE80211_FC_SUBTYPE_MASK:
case IEEE802_11_FC_TYPE_QOS_NULL & IEEE80211_FC_SUBTYPE_MASK:
if (fromDs && toDs) {
macHeaderLengthInBytes += (QOS_CONTROL_HEADER_SIZE + 6);
} else {
macHeaderLengthInBytes += QOS_CONTROL_HEADER_SIZE;
}
if (*fc & cpu_to_le16(IEEE80211_FC_ORDER_MASK)) {
macHeaderLengthInBytes += HT_CONTROL_HEADER_SIZE;
qc = (u8*)(buffered_pkt->bulkdata.os_data_ptr + (macHeaderLengthInBytes-6));
} else {
qc = (u8*)(buffered_pkt->bulkdata.os_data_ptr + (macHeaderLengthInBytes-2));
}
*qc = eosp ? *qc | (1 << 4) : *qc & (~(1 << 4));
break;
default:
if (fromDs && toDs)
macHeaderLengthInBytes += 6;
}
}
result = ul_send_signal_unpacked(priv, &signal, &bulkdata);
if(result){
_update_buffered_pkt_params_after_alignment(priv, &bulkdata,buffered_pkt);
}
if (result != -ENOSPC) {
if (!priv->noOfPktQueuedInDriver) {
unifi_error(priv, "packets queued in driver 0 still decrementing\n");
} else {
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
priv->noOfPktQueuedInDriver--;
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
}
if (staRecord) {
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
if (!staRecord->noOfPktQueued) {
unifi_error(priv, "packets queued in driver per station is 0 still decrementing\n");
} else {
staRecord->noOfPktQueued--;
}
if (result){
if (staRecord->nullDataHostTag == buffered_pkt->hostTag){
staRecord->nullDataHostTag = INVALID_HOST_TAG;
}
}
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
}
}
return result;
}
static
void set_eosp_transmit_ctrl(unifi_priv_t *priv, struct list_head *txList)
{
tx_buffered_packets_t *tx_q_item = NULL;
struct list_head *listHead;
struct list_head *placeHolder;
unsigned long lock_flags;
unifi_trace(priv, UDBG5, "entering set_eosp_transmit_ctrl\n");
if (list_empty(txList)) {
unifi_warning(priv, "In set_eosp_transmit_ctrl, the list is empty\n");
return;
}
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_for_each_prev_safe(listHead, placeHolder, txList) {
tx_q_item = list_entry(listHead, tx_buffered_packets_t, q);
tx_q_item->transmissionControl |= TRANSMISSION_CONTROL_EOSP_MASK;
tx_q_item->transmissionControl = (tx_q_item->transmissionControl & ~(CSR_NO_CONFIRM_REQUIRED));
unifi_trace(priv, UDBG1,
"set_eosp_transmit_ctrl Transmission Control = 0x%x hostTag = 0x%x \n",tx_q_item->transmissionControl,tx_q_item->hostTag);
unifi_trace(priv,UDBG3,"in set_eosp_transmit_ctrl no.of buffered frames %d\n",priv->noOfPktQueuedInDriver);
break;
}
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
unifi_trace(priv, UDBG1,"List Empty %d\n",list_empty(txList));
unifi_trace(priv, UDBG5, "leaving set_eosp_transmit_ctrl\n");
return;
}
static
void send_vif_availibility_rsp(unifi_priv_t *priv,CSR_VIF_IDENTIFIER vif,CSR_RESULT_CODE resultCode)
{
CSR_SIGNAL signal;
CSR_MA_VIF_AVAILABILITY_RESPONSE *rsp;
bulk_data_param_t *bulkdata = NULL;
int r;
unifi_trace(priv, UDBG3, "send_vif_availibility_rsp : invoked with resultCode = %d \n", resultCode);
memset(&signal,0,sizeof(CSR_SIGNAL));
rsp = &signal.u.MaVifAvailabilityResponse;
rsp->VirtualInterfaceIdentifier = vif;
rsp->ResultCode = resultCode;
signal.SignalPrimitiveHeader.SignalId = CSR_MA_VIF_AVAILABILITY_RESPONSE_ID;
signal.SignalPrimitiveHeader.ReceiverProcessId = 0;
signal.SignalPrimitiveHeader.SenderProcessId = priv->netdev_client->sender_id;
r = ul_send_signal_unpacked(priv, &signal, bulkdata);
if(r) {
unifi_error(priv,"Availibility response sending failed %x status %d\n",vif,r);
}
else {
unifi_trace(priv, UDBG3, "send_vif_availibility_rsp : status = %d \n", r);
}
}
static
void verify_and_accomodate_tx_packet(unifi_priv_t *priv)
{
tx_buffered_packets_t *tx_q_item;
unsigned long lock_flags;
struct list_head *listHead, *list;
struct list_head *placeHolder;
u8 i, j,eospFramedeleted=0;
u8 thresholdExcedeDueToBroadcast = TRUE;
netInterface_priv_t *interfacePriv = priv->interfacePriv[0];
CsrWifiRouterCtrlStaInfo_t *staInfo = NULL;
unifi_trace(priv, UDBG3, "entering verify_and_accomodate_tx_packet\n");
for(i = 0; i < UNIFI_MAX_CONNECTIONS; i++) {
staInfo = interfacePriv->staInfo[i];
if (staInfo && (staInfo->noOfPktQueued >= CSR_WIFI_DRIVER_MAX_PKT_QUEUING_THRESHOLD_PER_PEER)) {
unifi_trace(priv,UDBG3,"number of station pkts queued= %d for sta id = %d\n", staInfo->noOfPktQueued, staInfo->aid);
for(j = 0; j < MAX_ACCESS_CATOGORY; j++) {
list = &staInfo->dataPdu[j];
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_for_each_safe(listHead, placeHolder, list) {
tx_q_item = list_entry(listHead, tx_buffered_packets_t, q);
list_del(listHead);
thresholdExcedeDueToBroadcast = FALSE;
unifi_net_data_free(priv, &tx_q_item->bulkdata);
kfree(tx_q_item);
tx_q_item = NULL;
if (!priv->noOfPktQueuedInDriver) {
unifi_error(priv, "packets queued in driver 0 still decrementing in %s\n", __FUNCTION__);
} else {
priv->noOfPktQueuedInDriver--;
}
if (!staInfo->noOfPktQueued) {
unifi_error(priv, "packets queued in driver per station is 0 still decrementing in %s\n", __FUNCTION__);
} else {
spin_lock(&priv->staRecord_lock);
staInfo->noOfPktQueued--;
spin_unlock(&priv->staRecord_lock);
}
break;
}
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
}
}
}
if (thresholdExcedeDueToBroadcast && interfacePriv->noOfbroadcastPktQueued > CSR_WIFI_DRIVER_MINIMUM_BROADCAST_PKT_THRESHOLD ) {
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_for_each_safe(listHead, placeHolder, &interfacePriv->genericMulticastOrBroadCastFrames) {
tx_q_item = list_entry(listHead, tx_buffered_packets_t, q);
if(eospFramedeleted){
tx_q_item->transmissionControl |= TRANSMISSION_CONTROL_EOSP_MASK;
tx_q_item->transmissionControl = (tx_q_item->transmissionControl & ~(CSR_NO_CONFIRM_REQUIRED));
unifi_trace(priv, UDBG1,"updating eosp for next packet hostTag:= 0x%x ",tx_q_item->hostTag);
eospFramedeleted =0;
break;
}
if(tx_q_item->transmissionControl & TRANSMISSION_CONTROL_EOSP_MASK ){
eospFramedeleted = 1;
}
unifi_trace(priv,UDBG1, "freeing of multicast packets ToC = 0x%x hostTag = 0x%x \n",tx_q_item->transmissionControl,tx_q_item->hostTag);
list_del(listHead);
unifi_net_data_free(priv, &tx_q_item->bulkdata);
kfree(tx_q_item);
priv->noOfPktQueuedInDriver--;
spin_lock(&priv->staRecord_lock);
interfacePriv->noOfbroadcastPktQueued--;
spin_unlock(&priv->staRecord_lock);
if(!eospFramedeleted){
break;
}
}
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
}
unifi_trace(priv, UDBG3, "leaving verify_and_accomodate_tx_packet\n");
}
static
CsrResult enque_tx_data_pdu(unifi_priv_t *priv, bulk_data_param_t *bulkdata,
struct list_head *list, CSR_SIGNAL *signal,
u8 requeueOnSamePos)
{
CSR_MA_PACKET_REQUEST *req = &signal->u.MaPacketRequest;
tx_buffered_packets_t *tx_q_item;
unsigned long lock_flags;
unifi_trace(priv, UDBG5, "entering enque_tx_data_pdu\n");
if(!list) {
unifi_error(priv,"List is not specified\n");
return CSR_RESULT_FAILURE;
}
if (priv->noOfPktQueuedInDriver >= CSR_WIFI_DRIVER_SUPPORT_FOR_MAX_PKT_QUEUEING) {
unifi_trace(priv,UDBG3,"number of pkts queued= %d \n", priv->noOfPktQueuedInDriver);
verify_and_accomodate_tx_packet(priv);
}
tx_q_item = (tx_buffered_packets_t *)kmalloc(sizeof(tx_buffered_packets_t), GFP_ATOMIC);
if (tx_q_item == NULL) {
unifi_error(priv,
"Failed to allocate %d bytes for tx packet record\n",
sizeof(tx_buffered_packets_t));
func_exit();
return CSR_RESULT_FAILURE;
}
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
INIT_LIST_HEAD(&tx_q_item->q);
tx_q_item->bulkdata.os_data_ptr = bulkdata->d[0].os_data_ptr;
tx_q_item->bulkdata.data_length = bulkdata->d[0].data_length;
tx_q_item->bulkdata.os_net_buf_ptr = bulkdata->d[0].os_net_buf_ptr;
tx_q_item->bulkdata.net_buf_length = bulkdata->d[0].net_buf_length;
tx_q_item->interfaceTag = req->VirtualInterfaceIdentifier & 0xff;
tx_q_item->hostTag = req->HostTag;
tx_q_item->leSenderProcessId = signal->SignalPrimitiveHeader.SenderProcessId;
tx_q_item->transmissionControl = req->TransmissionControl;
tx_q_item->priority = req->Priority;
tx_q_item->rate = req->TransmitRate;
memcpy(tx_q_item->peerMacAddress.a, req->Ra.x, ETH_ALEN);
if (requeueOnSamePos) {
list_add(&tx_q_item->q, list);
} else {
list_add_tail(&tx_q_item->q, list);
}
priv->noOfPktQueuedInDriver++;
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
unifi_trace(priv, UDBG5, "leaving enque_tx_data_pdu\n");
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_reque_ma_packet_request (void *ospriv, u32 host_tag,
u16 txStatus, bulk_data_desc_t *bulkDataDesc)
{
CsrResult status = CSR_RESULT_SUCCESS;
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
netInterface_priv_t *interfacePriv;
struct list_head *list = NULL;
CsrWifiRouterCtrlStaInfo_t *staRecord = NULL;
bulk_data_param_t bulkData;
CSR_SIGNAL signal;
CSR_PRIORITY priority = 0;
u16 interfaceTag = 0;
unifi_TrafficQueue priority_q;
u16 frameControl = 0, frameType = 0;
unsigned long lock_flags;
interfacePriv = priv->interfacePriv[interfaceTag];
if(!((interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP) ||
(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO))) {
return CSR_RESULT_FAILURE;
}
unifi_trace(priv, UDBG6, "unifi_reque_ma_packet_request: host_tag = 0x%x\n", host_tag);
staRecord = CsrWifiRouterCtrlGetStationRecordFromPeerMacAddress(priv,
(((u8 *) bulkDataDesc->os_data_ptr) + 4),
interfaceTag);
if (NULL == staRecord) {
unifi_trace(priv, UDBG5, "unifi_reque_ma_packet_request: Invalid STA record \n");
return CSR_RESULT_FAILURE;
}
if (CSR_TX_RETRY_LIMIT == txStatus || CSR_TX_NO_BSS == txStatus) {
if (staRecord->timSet == CSR_WIFI_TIM_RESET || staRecord->timSet == CSR_WIFI_TIM_RESETTING)
{
unifi_trace(priv, UDBG2, "unifi_reque_ma_packet_request: CFM failed with Retry Limit or No BSS-->update TIM\n");
if (!staRecord->timRequestPendingFlag) {
update_tim(priv, staRecord->aid, 1, interfaceTag, staRecord->assignedHandle);
}
else {
staRecord->updateTimReqQueued = 1;
unifi_trace(priv, UDBG6, "unifi_reque_ma_packet_request: One more UpdateTim Request(:%d)Queued for AID %x\n",
staRecord->updateTimReqQueued, staRecord->aid);
}
}
return CSR_RESULT_FAILURE;
}
else if ((CSR_TX_LIFETIME == txStatus) || (CSR_TX_BLOCK_ACK_TIMEOUT == txStatus) ||
(CSR_TX_FAIL_TRANSMISSION_VIF_INTERRUPTED == txStatus) ||
(CSR_TX_REJECTED_PEER_STATION_SLEEPING == txStatus) ||
(CSR_TX_REJECTED_DTIM_STARTED == txStatus)) {
frameControl = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(bulkDataDesc->os_data_ptr);
frameType = ((frameControl & IEEE80211_FC_TYPE_MASK) >> FRAME_CONTROL_TYPE_FIELD_OFFSET);
if (IEEE802_11_FRAMETYPE_MANAGEMENT == frameType) {
return CSR_RESULT_FAILURE;
}
else if (IEEE802_11_FRAMETYPE_DATA == frameType) {
if ((((frameControl & IEEE80211_FC_SUBTYPE_MASK) >> FRAME_CONTROL_SUBTYPE_FIELD_OFFSET) == QOS_DATA_NULL) ||
(((frameControl & IEEE80211_FC_SUBTYPE_MASK) >> FRAME_CONTROL_SUBTYPE_FIELD_OFFSET)== DATA_NULL )) {
return CSR_RESULT_FAILURE;
}
}
if (TRUE == staRecord->wmmOrQosEnabled) {
u16 qosControl = 0;
u8 dataFrameType = 0;
dataFrameType =((frameControl & IEEE80211_FC_SUBTYPE_MASK) >> 4);
if (dataFrameType == QOS_DATA) {
if((frameControl & IEEE802_11_FC_TO_DS_MASK) && (frameControl & IEEE802_11_FC_FROM_DS_MASK)) {
qosControl= CSR_GET_UINT16_FROM_LITTLE_ENDIAN(bulkDataDesc->os_data_ptr + 30);
}
else {
qosControl = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(bulkDataDesc->os_data_ptr + 24);
}
}
priority = (CSR_PRIORITY)(qosControl & IEEE802_11_QC_TID_MASK);
if (priority < CSR_QOS_UP0 || priority > CSR_QOS_UP7) {
unifi_trace(priv, UDBG5, "unifi_reque_ma_packet_request: Invalid priority:%x \n", priority);
return CSR_RESULT_FAILURE;
}
}
else {
priority = CSR_CONTENTION;
}
bulkData.d[0].os_data_ptr = bulkDataDesc->os_data_ptr;
bulkData.d[0].data_length = bulkDataDesc->data_length;
bulkData.d[0].os_net_buf_ptr = bulkDataDesc->os_net_buf_ptr;
bulkData.d[0].net_buf_length = bulkDataDesc->net_buf_length;
bulkData.d[1].os_data_ptr = NULL;
bulkData.d[1].os_net_buf_ptr = NULL;
bulkData.d[1].data_length = bulkData.d[1].net_buf_length = 0;
memset(&signal, 0, sizeof(CSR_SIGNAL));
unifi_frame_ma_packet_req(priv, priority, 0, host_tag,
interfaceTag, CSR_NO_CONFIRM_REQUIRED,
priv->netdev_client->sender_id,
staRecord->peerMacAddress.a, &signal);
priority_q = unifi_frame_priority_to_queue(priority);
list = &staRecord->dataPdu[priority_q];
status = enque_tx_data_pdu(priv, &bulkData, list, &signal, TRUE);
if (!status) {
spin_lock_irqsave(&priv->staRecord_lock, lock_flags);
staRecord->noOfPktQueued++;
spin_unlock_irqrestore(&priv->staRecord_lock, lock_flags);
}
}
else {
return CSR_RESULT_FAILURE;
}
return status;
}
static void is_all_ac_deliver_enabled_and_moredata(CsrWifiRouterCtrlStaInfo_t *staRecord, u8 *allDeliveryEnabled, u8 *dataAvailable)
{
u8 i;
*allDeliveryEnabled = TRUE;
for (i = 0 ;i < MAX_ACCESS_CATOGORY; i++) {
if (!IS_DELIVERY_ENABLED(staRecord->powersaveMode[i])) {
*allDeliveryEnabled = FALSE;
break;
}
}
if (*allDeliveryEnabled) {
*dataAvailable = (!list_empty(&staRecord->dataPdu[0]) || !list_empty(&staRecord->dataPdu[1])
||!list_empty(&staRecord->dataPdu[2]) ||!list_empty(&staRecord->dataPdu[3])
||!list_empty(&staRecord->mgtFrames));
}
}
void uf_handle_tim_cfm(unifi_priv_t *priv, CSR_MLME_SET_TIM_CONFIRM *cfm, u16 receiverProcessId)
{
u8 handle = CSR_WIFI_GET_STATION_HANDLE_FROM_RECEIVER_ID(receiverProcessId);
u8 timSetStatus = CSR_WIFI_GET_TIMSET_STATE_FROM_RECEIVER_ID(receiverProcessId);
u16 interfaceTag = (cfm->VirtualInterfaceIdentifier & 0xff);
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
CsrWifiRouterCtrlStaInfo_t *staRecord = NULL;
u16 timSetValue = 0;
static u8 retryCount = 0;
unsigned long lock_flags;
unifi_trace(priv, UDBG3, "entering %s, handle = %x, timSetStatus = %x\n", __FUNCTION__, handle, timSetStatus);
if (interfaceTag >= CSR_WIFI_NUM_INTERFACES) {
unifi_warning(priv, "bad interfaceTag = %x\n", interfaceTag);
return;
}
if ((handle != CSR_WIFI_BROADCAST_OR_MULTICAST_HANDLE) && (handle >= UNIFI_MAX_CONNECTIONS)) {
unifi_warning(priv, "bad station Handle = %x\n", handle);
return;
}
if (handle != CSR_WIFI_BROADCAST_OR_MULTICAST_HANDLE) {
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
if ((staRecord = ((CsrWifiRouterCtrlStaInfo_t *) (interfacePriv->staInfo[handle]))) == NULL) {
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
unifi_warning(priv, "uf_handle_tim_cfm: station record is NULL handle = %x\n", handle);
return;
}
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
}
switch(timSetStatus)
{
case CSR_WIFI_TIM_SETTING:
timSetValue = CSR_WIFI_TIM_SET;
break;
case CSR_WIFI_TIM_RESETTING:
timSetValue = CSR_WIFI_TIM_RESET;
break;
default:
unifi_warning(priv, "timSet state is %x: Debug\n", timSetStatus);
return;
}
switch(cfm->ResultCode)
{
case CSR_RC_SUCCESS:
if (handle != CSR_WIFI_BROADCAST_OR_MULTICAST_HANDLE) {
if (timSetStatus == staRecord->timSet) {
staRecord->timSet = timSetValue;
retryCount = 0;
unifi_trace(priv, UDBG2, "tim (%s) successfully in firmware\n", (timSetValue)?"SET":"RESET");
} else {
unifi_trace(priv, UDBG3, "receiver processID = %x, success: request & confirm states are not matching in TIM cfm: Debug status = %x, staRecord->timSet = %x, handle = %x\n",
receiverProcessId, timSetStatus, staRecord->timSet, handle);
}
staRecord->timRequestPendingFlag = FALSE;
if (0xFF != staRecord->updateTimReqQueued)
{
if (staRecord->timSet != staRecord->updateTimReqQueued)
{
unifi_trace(priv, UDBG2, "uf_handle_tim_cfm : Processing Queued UpdateTimReq \n");
update_tim(priv, staRecord->aid, staRecord->updateTimReqQueued, interfaceTag, handle);
staRecord->updateTimReqQueued = 0xFF;
}
}
} else {
interfacePriv->bcTimSet = timSetValue;
retryCount = 0;
unifi_trace(priv, UDBG3, "tim (%s) successfully for broadcast frame in firmware\n", (timSetValue)?"SET":"RESET");
interfacePriv->bcTimSetReqPendingFlag = FALSE;
if (0xFF != interfacePriv->bcTimSetReqQueued)
{
if (interfacePriv->bcTimSet != interfacePriv->bcTimSetReqQueued)
{
unifi_trace(priv, UDBG2, "uf_handle_tim_cfm : Processing Queued UpdateDTimReq \n");
update_tim(priv, 0, interfacePriv->bcTimSetReqQueued, interfaceTag, 0xFFFFFFFF);
interfacePriv->bcTimSetReqQueued = 0xFF;
}
}
}
break;
case CSR_RC_INVALID_PARAMETERS:
case CSR_RC_INSUFFICIENT_RESOURCE:
if (retryCount > UNIFI_MAX_RETRY_LIMIT) {
u8 moreData = FALSE;
retryCount = 0;
if(staRecord) {
if(!staRecord->wmmOrQosEnabled) {
moreData = (!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION]) ||
!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_VO]) ||
!list_empty(&staRecord->mgtFrames));
} else {
u8 allDeliveryEnabled = 0, dataAvailable = 0;
is_all_ac_deliver_enabled_and_moredata(staRecord, &allDeliveryEnabled, &dataAvailable);
moreData = (uf_is_more_data_for_non_delivery_ac(staRecord) || (allDeliveryEnabled && dataAvailable));
}
if (moreData) {
staRecord->timSet = CSR_WIFI_TIM_RESET;
} else {
staRecord->timSet = CSR_WIFI_TIM_SET;
}
} else {
moreData = (!list_empty(&interfacePriv->genericMulticastOrBroadCastMgtFrames) ||
!list_empty(&interfacePriv->genericMulticastOrBroadCastFrames));
if (moreData) {
update_tim(priv, 0, CSR_WIFI_TIM_SET, interfaceTag, 0xFFFFFFFF);
} else {
update_tim(priv, 0, CSR_WIFI_TIM_RESET, interfaceTag, 0xFFFFFFFF);
}
}
unifi_error(priv, "no of error's for TIM setting crossed the Limit: verify\n");
return;
}
retryCount++;
if (handle != CSR_WIFI_BROADCAST_OR_MULTICAST_HANDLE) {
if (timSetStatus == staRecord->timSet) {
unifi_warning(priv, "tim request failed, retry for AID = %x\n", staRecord->aid);
update_tim(priv, staRecord->aid, timSetValue, interfaceTag, handle);
} else {
unifi_trace(priv, UDBG1, "failure: request & confirm states are not matching in TIM cfm: Debug status = %x, staRecord->timSet = %x\n",
timSetStatus, staRecord->timSet);
}
} else {
unifi_warning(priv, "tim request failed, retry for broadcast frames\n");
update_tim(priv, 0, timSetValue, interfaceTag, 0xFFFFFFFF);
}
break;
default:
unifi_warning(priv, "tim update request failed resultcode = %x\n", cfm->ResultCode);
}
unifi_trace(priv, UDBG2, "leaving %s\n", __FUNCTION__);
}
void update_tim(unifi_priv_t * priv, u16 aid, u8 setTim, u16 interfaceTag, u32 handle)
{
CSR_SIGNAL signal;
s32 r;
CSR_MLME_SET_TIM_REQUEST *req = &signal.u.MlmeSetTimRequest;
bulk_data_param_t *bulkdata = NULL;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
u8 senderIdLsb = 0;
CsrWifiRouterCtrlStaInfo_t *staRecord = NULL;
u32 oldTimSetStatus = 0, timSetStatus = 0;
unifi_trace(priv, UDBG5, "entering the update_tim routine\n");
if (handle == 0xFFFFFFFF) {
handle &= CSR_WIFI_BROADCAST_OR_MULTICAST_HANDLE;
if (setTim == interfacePriv->bcTimSet)
{
unifi_trace(priv, UDBG3, "update_tim, Drop:Hdl=%x, timval=%d, globalTim=%d\n", handle, setTim, interfacePriv->bcTimSet);
return;
}
} else if ((handle != 0xFFFFFFFF) && (handle >= UNIFI_MAX_CONNECTIONS)) {
unifi_warning(priv, "bad station Handle = %x\n", handle);
return;
}
if (setTim) {
timSetStatus = CSR_WIFI_TIM_SETTING;
} else {
timSetStatus = CSR_WIFI_TIM_RESETTING;
}
if (handle != CSR_WIFI_BROADCAST_OR_MULTICAST_HANDLE) {
if ((staRecord = ((CsrWifiRouterCtrlStaInfo_t *) (interfacePriv->staInfo[handle]))) == NULL) {
unifi_warning(priv, "station record is NULL in update_tim: handle = %x :debug\n", handle);
return;
}
oldTimSetStatus = staRecord->timSet;
staRecord->timSet = timSetStatus;
}
senderIdLsb = CSR_WIFI_PACK_SENDER_ID_LSB_FOR_TIM_REQ(handle, timSetStatus);
memset(&signal, 0, sizeof(CSR_SIGNAL));
signal.SignalPrimitiveHeader.SignalId = CSR_MLME_SET_TIM_REQUEST_ID;
signal.SignalPrimitiveHeader.ReceiverProcessId = 0;
CSR_COPY_UINT16_TO_LITTLE_ENDIAN(((priv->netdev_client->sender_id & 0xff00) | senderIdLsb),
(u8*)&signal.SignalPrimitiveHeader.SenderProcessId);
req->VirtualInterfaceIdentifier = uf_get_vif_identifier(interfacePriv->interfaceMode,interfaceTag);
req->AssociationId = aid;
req->TimValue = setTim;
unifi_trace(priv, UDBG2, "update_tim:AID %x,senderIdLsb = 0x%x, handle = 0x%x, timSetStatus = %x, sender proceesID = %x \n",
aid,senderIdLsb, handle, timSetStatus, signal.SignalPrimitiveHeader.SenderProcessId);
r = ul_send_signal_unpacked(priv, &signal, bulkdata);
if (r) {
unifi_error(priv, "Error queueing CSR_MLME_SET_TIM_REQUEST signal\n");
if (staRecord) {
staRecord->timSet = oldTimSetStatus ;
}
else
{
interfacePriv->bcTimSet = !setTim;
}
}
else {
if (staRecord) {
staRecord->timRequestPendingFlag = TRUE;
}
else
{
interfacePriv->bcTimSetReqPendingFlag = TRUE;
}
}
unifi_trace(priv, UDBG5, "leaving the update_tim routine\n");
}
static
void process_peer_active_transition(unifi_priv_t * priv,
CsrWifiRouterCtrlStaInfo_t *staRecord,
u16 interfaceTag)
{
int r,i;
u8 spaceAvail[4] = {TRUE,TRUE,TRUE,TRUE};
tx_buffered_packets_t * buffered_pkt = NULL;
unsigned long lock_flags;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
unifi_trace(priv, UDBG5, "entering process_peer_active_transition\n");
if(IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag)) {
unifi_trace(priv,UDBG2, "Multicast transmission is going on so resume unicast transmission after DTIM over\n");
if (!staRecord->timRequestPendingFlag){
if((staRecord->timSet == CSR_WIFI_TIM_SET) || (staRecord->timSet == CSR_WIFI_TIM_SETTING)){
update_tim(priv, staRecord->aid, 0, interfaceTag, staRecord->assignedHandle);
}
}
else
{
staRecord->updateTimReqQueued = 0;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", staRecord->updateTimReqQueued,
staRecord->aid);
}
return;
}
while((buffered_pkt=dequeue_tx_data_pdu(priv, &staRecord->mgtFrames))) {
buffered_pkt->transmissionControl &=
~(TRANSMISSION_CONTROL_TRIGGER_MASK|TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staRecord,0,FALSE)) == -ENOSPC) {
unifi_trace(priv, UDBG2, "p_p_a_t:(ENOSPC) Mgt Frame queueing \n");
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staRecord->mgtFrames);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[3]=(u8)(staRecord->assignedHandle);
spaceAvail[3] = FALSE;
break;
} else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
}
if (!staRecord->timRequestPendingFlag) {
if (staRecord->txSuspend) {
if(staRecord->timSet == CSR_WIFI_TIM_SET) {
update_tim(priv,staRecord->aid,0,interfaceTag, staRecord->assignedHandle);
}
return;
}
}
else
{
staRecord->updateTimReqQueued = 0;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", staRecord->updateTimReqQueued,
staRecord->aid);
}
for(i=3;i>=0;i--) {
if(!spaceAvail[i])
continue;
unifi_trace(priv, UDBG6, "p_p_a_t:data pkt sending for AC %d \n",i);
while((buffered_pkt=dequeue_tx_data_pdu(priv, &staRecord->dataPdu[i]))) {
buffered_pkt->transmissionControl &=
~(TRANSMISSION_CONTROL_TRIGGER_MASK|TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staRecord,0,FALSE)) == -ENOSPC) {
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staRecord->dataPdu[i]);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[i]=(u8)(staRecord->assignedHandle);
break;
} else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
}
}
if (!staRecord->timRequestPendingFlag){
if((staRecord->timSet == CSR_WIFI_TIM_SET) || (staRecord->timSet == CSR_WIFI_TIM_SETTING)) {
unifi_trace(priv, UDBG3, "p_p_a_t:resetting tim .....\n");
update_tim(priv,staRecord->aid,0,interfaceTag, staRecord->assignedHandle);
}
}
else
{
staRecord->updateTimReqQueued = 0;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", staRecord->updateTimReqQueued,
staRecord->aid);
}
unifi_trace(priv, UDBG5, "leaving process_peer_active_transition\n");
}
void uf_process_ma_pkt_cfm_for_ap(unifi_priv_t *priv,u16 interfaceTag, const CSR_MA_PACKET_CONFIRM *pkt_cfm)
{
netInterface_priv_t *interfacePriv;
u8 i;
CsrWifiRouterCtrlStaInfo_t *staRecord = NULL;
interfacePriv = priv->interfacePriv[interfaceTag];
if(pkt_cfm->HostTag == interfacePriv->multicastPduHostTag) {
unifi_trace(priv,UDBG2,"CFM for marked Multicast Tag = %x\n",interfacePriv->multicastPduHostTag);
interfacePriv->multicastPduHostTag = 0xffffffff;
resume_suspended_uapsd(priv,interfaceTag);
resume_unicast_buffered_frames(priv,interfaceTag);
if(list_empty(&interfacePriv->genericMulticastOrBroadCastMgtFrames) &&
list_empty(&interfacePriv->genericMulticastOrBroadCastFrames)) {
unifi_trace(priv,UDBG1,"Resetting multicastTIM");
if (!interfacePriv->bcTimSetReqPendingFlag)
{
update_tim(priv,0,CSR_WIFI_TIM_RESET,interfaceTag, 0xFFFFFFFF);
}
else
{
interfacePriv->bcTimSetReqQueued = CSR_WIFI_TIM_RESET;
unifi_trace(priv, UDBG2, "uf_process_ma_pkt_cfm_for_ap : One more UpdateDTim Request(%d) Queued \n",
interfacePriv->bcTimSetReqQueued);
}
}
return;
}
for(i =0; i < UNIFI_MAX_CONNECTIONS; i++) {
staRecord = (CsrWifiRouterCtrlStaInfo_t *) (interfacePriv->staInfo[i]);
if (staRecord && (staRecord->nullDataHostTag == pkt_cfm->HostTag)) {
unifi_trace(priv, UDBG1, "CFM for Inactive probe Null frame (tag = %x, status = %d)\n",
pkt_cfm->HostTag,
pkt_cfm->TransmissionStatus
);
staRecord->nullDataHostTag = INVALID_HOST_TAG;
if(pkt_cfm->TransmissionStatus == CSR_TX_RETRY_LIMIT){
CsrTime now;
CsrTime inactive_time;
unifi_trace(priv, UDBG1, "Nulldata to probe STA ALIVE Failed with retry limit\n");
if (staRecord->activity_flag){
return;
}
now = CsrTimeGet(NULL);
if (staRecord->lastActivity > now)
{
inactive_time = CsrTimeAdd((CsrTime)CsrTimeSub(CSR_SCHED_TIME_MAX, staRecord->lastActivity),
now);
}
else
{
inactive_time = (CsrTime)CsrTimeSub(now, staRecord->lastActivity);
}
if (inactive_time >= STA_INACTIVE_TIMEOUT_VAL)
{
struct list_head send_cfm_list;
u8 j;
INIT_LIST_HEAD(&send_cfm_list);
uf_prepare_send_cfm_list_for_queued_pkts(priv,
&send_cfm_list,
&(staRecord->mgtFrames));
uf_flush_list(priv, &(staRecord->mgtFrames));
for(j = 0; j < MAX_ACCESS_CATOGORY; j++){
uf_prepare_send_cfm_list_for_queued_pkts(priv,
&send_cfm_list,
&(staRecord->dataPdu[j]));
uf_flush_list(priv,&(staRecord->dataPdu[j]));
}
send_auto_ma_packet_confirm(priv, staRecord->interfacePriv, &send_cfm_list);
unifi_warning(priv, "uf_process_ma_pkt_cfm_for_ap: Router Disconnected IND Peer (%x-%x-%x-%x-%x-%x)\n",
staRecord->peerMacAddress.a[0],
staRecord->peerMacAddress.a[1],
staRecord->peerMacAddress.a[2],
staRecord->peerMacAddress.a[3],
staRecord->peerMacAddress.a[4],
staRecord->peerMacAddress.a[5]);
CsrWifiRouterCtrlConnectedIndSend(priv->CSR_WIFI_SME_IFACEQUEUE,
0,
staRecord->interfacePriv->InterfaceTag,
staRecord->peerMacAddress,
CSR_WIFI_ROUTER_CTRL_PEER_DISCONNECTED);
}
}
else if (pkt_cfm->TransmissionStatus == CSR_TX_SUCCESSFUL)
{
staRecord->activity_flag = TRUE;
}
}
}
}
u16 uf_get_vif_identifier (CsrWifiRouterCtrlMode mode, u16 tag)
{
switch(mode)
{
case CSR_WIFI_ROUTER_CTRL_MODE_STA:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PCLI:
return (0x02<<8|tag);
case CSR_WIFI_ROUTER_CTRL_MODE_AP:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PGO:
return (0x03<<8|tag);
case CSR_WIFI_ROUTER_CTRL_MODE_IBSS:
return (0x01<<8|tag);
case CSR_WIFI_ROUTER_CTRL_MODE_MONITOR:
return (0x04<<8|tag);
case CSR_WIFI_ROUTER_CTRL_MODE_AMP:
return (0x05<<8|tag);
default:
return tag;
}
}
static int update_macheader(unifi_priv_t *priv, struct sk_buff *skb,
struct sk_buff *newSkb, CSR_PRIORITY *priority,
bulk_data_param_t *bulkdata, u16 interfaceTag,
u8 macHeaderLengthInBytes,
u8 qosDestination)
{
u16 *fc = NULL;
u8 direction = 0, toDs, fromDs;
u8 *bufPtr = NULL;
u8 sa[ETH_ALEN], da[ETH_ALEN];
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
int headroom;
u8 macHeaderBuf[IEEE802_11_DATA_FRAME_MAC_HEADER_SIZE] = {0};
unifi_trace(priv, UDBG5, "entering the update_macheader function\n");
memcpy(macHeaderBuf, skb->data, macHeaderLengthInBytes);
skb_pull(skb, macHeaderLengthInBytes);
headroom = skb_headroom(skb);
fc = (u16*) macHeaderBuf;
toDs = (*fc & cpu_to_le16(IEEE802_11_FC_TO_DS_MASK))?1 : 0;
fromDs = (*fc & cpu_to_le16(IEEE802_11_FC_FROM_DS_MASK))? 1: 0;
unifi_trace(priv, UDBG5, "In update_macheader function, fromDs = %x, toDs = %x\n", fromDs, toDs);
direction = ((fromDs | (toDs << 1)) & 0x3);
memcpy(da, macHeaderBuf+4+toDs*12, ETH_ALEN);
memcpy(sa, macHeaderBuf+10+fromDs*(6+toDs*8), ETH_ALEN);
unifi_trace(priv, UDBG3, "update_macheader:direction = %x\n", direction);
switch(direction)
{
case 2:
*fc &= cpu_to_le16(~IEEE802_11_FC_TO_DS_MASK);
*fc |= cpu_to_le16(IEEE802_11_FC_FROM_DS_MASK);
memcpy(macHeaderBuf + 4, da, ETH_ALEN);
memcpy(macHeaderBuf + 10, &interfacePriv->bssid, ETH_ALEN);
memcpy(macHeaderBuf + 16, sa, ETH_ALEN);
break;
case 3:
unifi_trace(priv, UDBG3, "when both the toDs & fromDS set, NOT SUPPORTED\n");
break;
default:
unifi_trace(priv, UDBG3, "problem in decoding packet in update_macheader \n");
return -1;
}
switch(le16_to_cpu(*fc) & IEEE80211_FC_SUBTYPE_MASK)
{
case IEEE802_11_FC_TYPE_QOS_DATA & IEEE80211_FC_SUBTYPE_MASK:
if (!qosDestination) {
if (*fc & cpu_to_le16(IEEE80211_FC_ORDER_MASK)) {
macHeaderLengthInBytes -= 6;
} else {
macHeaderLengthInBytes -= 2;
}
*fc &= cpu_to_le16(~IEEE80211_FC_SUBTYPE_MASK);
*fc |= cpu_to_le16(IEEE802_11_FC_TYPE_DATA);
if (headroom < macHeaderLengthInBytes) {
unifi_trace(priv, UDBG1, " sufficient headroom not there to push updated mac header \n");
return -1;
}
bufPtr = (u8 *) skb_push(skb, macHeaderLengthInBytes);
bulkdata->d[0].os_data_ptr = skb->data;
bulkdata->d[0].os_net_buf_ptr = (unsigned char*)skb;
bulkdata->d[0].data_length = skb->len;
} else {
u8 qc;
if (*fc & cpu_to_le16(IEEE80211_FC_ORDER_MASK)) {
qc = *((u8*)(macHeaderBuf + (macHeaderLengthInBytes - 4 - 2)));
} else {
qc = *((u8*)(macHeaderBuf + (macHeaderLengthInBytes - 2)));
}
if ((qc & IEEE802_11_QC_TID_MASK) > 7) {
*priority = 7;
} else {
*priority = qc & IEEE802_11_QC_TID_MASK;
}
unifi_trace(priv, UDBG1, "Incoming packet priority from QSTA is %x\n", *priority);
if (headroom < macHeaderLengthInBytes) {
unifi_trace(priv, UDBG3, " sufficient headroom not there to push updated mac header \n");
return -1;
}
bufPtr = (u8 *) skb_push(skb, macHeaderLengthInBytes);
}
break;
default:
{
bulk_data_param_t data_ptrs;
CsrResult csrResult;
unifi_trace(priv, UDBG5, "normal Data packet, NO QOS \n");
if (qosDestination) {
u8 qc = 0;
unifi_trace(priv, UDBG3, "destination is QOS station \n");
*priority = CSR_QOS_UP0;
qc |= CSR_QOS_UP0;
if (da[0] & 0x1) {
qc |= 1 << 5;
}
macHeaderLengthInBytes += 2;
*fc &= cpu_to_le16(~IEEE80211_FC_SUBTYPE_MASK);
*fc |= cpu_to_le16(IEEE802_11_FC_TYPE_QOS_DATA);
macHeaderBuf[macHeaderLengthInBytes - 2] = qc;
macHeaderBuf[macHeaderLengthInBytes - 1] = 0;
if (headroom < macHeaderLengthInBytes) {
csrResult = unifi_net_data_malloc(priv, &data_ptrs.d[0], skb->len + macHeaderLengthInBytes);
if (csrResult != CSR_RESULT_SUCCESS) {
unifi_error(priv, " failed to allocate request_data. in update_macheader func\n");
return -1;
}
newSkb = (struct sk_buff *)(data_ptrs.d[0].os_net_buf_ptr);
newSkb->len = skb->len + macHeaderLengthInBytes;
memcpy((void*)data_ptrs.d[0].os_data_ptr + macHeaderLengthInBytes,
skb->data, skb->len);
bulkdata->d[0].os_data_ptr = newSkb->data;
bulkdata->d[0].os_net_buf_ptr = (unsigned char*)newSkb;
bulkdata->d[0].data_length = newSkb->len;
bufPtr = (u8*)data_ptrs.d[0].os_data_ptr;
kfree_skb(skb);
} else {
bufPtr = (u8*)skb_push(skb, macHeaderLengthInBytes);
bulkdata->d[0].os_data_ptr = skb->data;
bulkdata->d[0].os_net_buf_ptr = (unsigned char*)skb;
bulkdata->d[0].data_length = skb->len;
}
} else {
unifi_trace(priv, UDBG3, "destination is not a QSTA\n");
if (headroom < macHeaderLengthInBytes) {
csrResult = unifi_net_data_malloc(priv, &data_ptrs.d[0], skb->len + macHeaderLengthInBytes);
if (csrResult != CSR_RESULT_SUCCESS) {
unifi_error(priv, " failed to allocate request_data. in update_macheader func\n");
return -1;
}
newSkb = (struct sk_buff *)(data_ptrs.d[0].os_net_buf_ptr);
newSkb->len = skb->len + macHeaderLengthInBytes;
memcpy((void*)data_ptrs.d[0].os_data_ptr + macHeaderLengthInBytes,
skb->data, skb->len);
bulkdata->d[0].os_data_ptr = newSkb->data;
bulkdata->d[0].os_net_buf_ptr = (unsigned char*)newSkb;
bulkdata->d[0].data_length = newSkb->len;
bufPtr = (u8*)data_ptrs.d[0].os_data_ptr;
kfree_skb(skb);
} else {
bufPtr = (u8*)skb_push(skb, macHeaderLengthInBytes);
bulkdata->d[0].os_data_ptr = skb->data;
bulkdata->d[0].os_net_buf_ptr = (unsigned char*)skb;
bulkdata->d[0].data_length = skb->len;
}
}
}
}
unifi_trace(priv, UDBG5, "updated Mac Header: %d \n",macHeaderLengthInBytes);
memcpy(bufPtr, macHeaderBuf, macHeaderLengthInBytes);
unifi_trace(priv, UDBG5, "leaving the update_macheader function\n");
return 0;
}
int
uf_ap_process_data_pdu(unifi_priv_t *priv, struct sk_buff *skb,
struct ethhdr *ehdr, CsrWifiRouterCtrlStaInfo_t * srcStaInfo,
const CSR_SIGNAL *signal,
bulk_data_param_t *bulkdata,
u8 macHeaderLengthInBytes)
{
const CSR_MA_PACKET_INDICATION *ind = &(signal->u.MaPacketIndication);
u16 interfaceTag = (ind->VirtualInterfaceIdentifier & 0x00ff);
struct sk_buff *newSkb = NULL;
struct sk_buff *skbPtr = skb;
u8 sendToNetdev = FALSE;
u8 qosDestination = FALSE;
CSR_PRIORITY priority = CSR_CONTENTION;
CsrWifiRouterCtrlStaInfo_t *dstStaInfo = NULL;
netInterface_priv_t *interfacePriv;
unifi_trace(priv, UDBG5, "entering uf_ap_process_data_pdu %d\n",macHeaderLengthInBytes);
if (interfaceTag >= CSR_WIFI_NUM_INTERFACES) {
unifi_trace(priv, UDBG1, "Interface Tag is Invalid in uf_ap_process_data_pdu\n");
unifi_net_data_free(priv, &bulkdata->d[0]);
return 0;
}
interfacePriv = priv->interfacePriv[interfaceTag];
if((interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO) &&
(interfacePriv->intraBssEnabled == FALSE)) {
unifi_trace(priv, UDBG2, "uf_ap_process_data_pdu:P2P GO intrabssEnabled?= %d\n", interfacePriv->intraBssEnabled);
dstStaInfo = CsrWifiRouterCtrlGetStationRecordFromPeerMacAddress(priv, ehdr->h_dest, interfaceTag);
if (dstStaInfo) {
unifi_net_data_free(priv, &bulkdata->d[0]);
return 0;
}
return -1;
}
if(!memcmp(ehdr->h_dest, interfacePriv->bssid.a, ETH_ALEN)) {
unifi_trace(priv, UDBG4, "destination address is csr_ap\n");
return -1;
}
dstStaInfo = CsrWifiRouterCtrlGetStationRecordFromPeerMacAddress(priv, ehdr->h_dest, interfaceTag);
if(!dstStaInfo) {
if (!(ehdr->h_dest[0] & 0x1)) {
unifi_trace(priv, UDBG3, "unicast frame & destination record not exist, send to netdev proto = %x\n", htons(skb->protocol));
return -1;
} else {
unifi_trace(priv, UDBG5, "skb_copy, in uf_ap_process_data_pdu, protocol = %x\n", htons(skb->protocol));
skbPtr = skb_copy(skb, GFP_KERNEL);
if(skbPtr == NULL) {
unifi_notice(priv, "broacast/multicast frame can't be sent in BSS No memeory: proto = %x\n", htons(skb->protocol));
return -1;
}
sendToNetdev = TRUE;
}
} else {
if (uf_process_station_records_for_sending_data(priv, interfaceTag, srcStaInfo, dstStaInfo)) {
unifi_notice(priv, "uf_ap_process_data_pdu: station record validation failed \n");
interfacePriv->stats.rx_errors++;
unifi_net_data_free(priv, &bulkdata->d[0]);
return 0;
}
}
if(sendToNetdev) {
qosDestination = FALSE;
} else if(dstStaInfo && (dstStaInfo->wmmOrQosEnabled == TRUE)) {
qosDestination = TRUE;
}
unifi_trace(priv, UDBG3, "uf_ap_process_data_pdu QoS destination = %s\n", (qosDestination)? "TRUE": "FALSE");
if (update_macheader(priv, skbPtr, newSkb, &priority, bulkdata, interfaceTag, macHeaderLengthInBytes, qosDestination)) {
interfacePriv->stats.rx_errors++;
unifi_notice(priv, "(Packet Drop) failed to update the Mac header in uf_ap_process_data_pdu\n");
if (sendToNetdev) {
bulkdata->d[0].os_data_ptr = skbPtr->data;
bulkdata->d[0].os_net_buf_ptr = (unsigned char*)skbPtr;
bulkdata->d[0].data_length = skbPtr->len;
unifi_net_data_free(priv, &bulkdata->d[0]);
}
return -1;
}
unifi_trace(priv, UDBG3, "Mac Header updated...calling uf_process_ma_packet_req \n");
if (uf_process_ma_packet_req(priv, ehdr->h_dest, 0xffffffff, interfaceTag, CSR_NO_CONFIRM_REQUIRED, (CSR_RATE)0,priority, priv->netdev_client->sender_id, bulkdata)) {
if (sendToNetdev) {
unifi_trace(priv, UDBG1, "In uf_ap_process_data_pdu, (Packet Drop) uf_process_ma_packet_req failed. freeing skb_copy data (original data sent to Netdev)\n");
bulkdata->d[0].os_data_ptr = skbPtr->data;
bulkdata->d[0].os_net_buf_ptr = (unsigned char*)skbPtr;
bulkdata->d[0].data_length = skbPtr->len;
unifi_net_data_free(priv, &bulkdata->d[0]);
} else {
unifi_trace(priv, UDBG1, "In uf_ap_process_data_pdu, (Packet Drop). Unicast data so freeing original skb \n");
unifi_net_data_free(priv, &bulkdata->d[0]);
}
}
unifi_trace(priv, UDBG5, "leaving uf_ap_process_data_pdu\n");
if (sendToNetdev) {
unifi_trace(priv, UDBG4, "Packet will be routed to NetDev\n");
return -1;
}
return 0;
}
CsrResult uf_process_ma_packet_req(unifi_priv_t *priv,
u8 *peerMacAddress,
CSR_CLIENT_TAG hostTag,
u16 interfaceTag,
CSR_TRANSMISSION_CONTROL transmissionControl,
CSR_RATE TransmitRate,
CSR_PRIORITY priority,
CSR_PROCESS_ID leSenderProcessId,
bulk_data_param_t *bulkdata)
{
CsrResult status = CSR_RESULT_SUCCESS;
CSR_SIGNAL signal;
int result;
#ifdef CSR_SUPPORT_SME
CsrWifiRouterCtrlStaInfo_t *staRecord = NULL;
const u8 *macHdrLocation = bulkdata->d[0].os_data_ptr;
CsrWifiPacketType pktType;
int frameType = 0;
u8 queuePacketDozing = FALSE;
u32 priority_q;
u16 frmCtrl;
struct list_head * list = NULL;
u8 setBcTim=FALSE;
netInterface_priv_t *interfacePriv;
u8 requeueOnSamePos = FALSE;
u32 handle = 0xFFFFFFFF;
unsigned long lock_flags;
unifi_trace(priv, UDBG5,
"entering uf_process_ma_packet_req, peer: %pMF\n",
peerMacAddress);
if (interfaceTag >= CSR_WIFI_NUM_INTERFACES) {
unifi_error(priv, "interfaceTag >= CSR_WIFI_NUM_INTERFACES, interfacetag = %d\n", interfaceTag);
return CSR_RESULT_FAILURE;
}
interfacePriv = priv->interfacePriv[interfaceTag];
if ((staRecord = CsrWifiRouterCtrlGetStationRecordFromPeerMacAddress(priv, peerMacAddress, interfaceTag))) {
handle = staRecord->assignedHandle;
}
unifi_frame_ma_packet_req(priv, priority, TransmitRate, hostTag,
interfaceTag, transmissionControl, leSenderProcessId,
peerMacAddress, &signal);
switch(interfacePriv->interfaceMode)
{
case CSR_WIFI_ROUTER_CTRL_MODE_AP:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PGO:
break;
default:
unifi_trace(priv, UDBG5, "In %s, interface mode is %x \n", __FUNCTION__, interfacePriv->interfaceMode);
if (interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_NONE) {
unifi_warning(priv, "In %s, interface mode NONE \n", __FUNCTION__);
}
if ((result = ul_send_signal_unpacked(priv, &signal, bulkdata))) {
status = CSR_RESULT_FAILURE;
}
return status;
}
priority_q = unifi_frame_priority_to_queue((CSR_PRIORITY) priority);
if (staRecord && (staRecord->currentPeerState ==
CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_POWER_SAVE)) {
queuePacketDozing = TRUE;
}
if (*peerMacAddress & 0x1) {
pktType = CSR_WIFI_MULTICAST_PDU;
} else {
pktType = CSR_WIFI_UNICAST_PDU;
}
frmCtrl = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(macHdrLocation);
frameType = ((frmCtrl & 0x000c) >> FRAME_CONTROL_TYPE_FIELD_OFFSET);
switch(frameType)
{
case IEEE802_11_FRAMETYPE_MANAGEMENT:
switch(pktType)
{
case CSR_WIFI_UNICAST_PDU:
unifi_trace(priv, UDBG5, "management unicast PDU in uf_process_ma_packet_req \n");
if (!staRecord) {
if (list_empty(&interfacePriv->genericMgtFrames)) {
#ifdef CSR_SUPPORT_SME
if(!(IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag))) {
#endif
unifi_trace(priv, UDBG3, "genericMgtFrames list is empty uf_process_ma_packet_req \n");
result = ul_send_signal_unpacked(priv, &signal, bulkdata);
if(result == -ENOSPC) {
unifi_trace(priv, UDBG1, "(ENOSPC) Sending genericMgtFrames Failed so buffering\n");
list = &interfacePriv->genericMgtFrames;
requeueOnSamePos = TRUE;
}
#ifdef CSR_SUPPORT_SME
}else{
list = &interfacePriv->genericMgtFrames;
unifi_trace(priv, UDBG3, "genericMgtFrames queue empty and dtim started\n hosttag is 0x%x,\n",signal.u.MaPacketRequest.HostTag);
update_eosp_to_head_of_broadcast_list_head(priv,interfaceTag);
}
#endif
} else {
list = &interfacePriv->genericMgtFrames;
unifi_trace(priv, UDBG2, "genericMgtFrames queue not empty\n");
}
} else {
if (queuePacketDozing || !list_empty(&staRecord->mgtFrames) || IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag)) {
list = &staRecord->mgtFrames;
unifi_trace(priv, UDBG1, "staRecord->MgtFrames list empty? = %s, handle = %d, queuePacketDozing = %d\n",
(list_empty(&staRecord->mgtFrames))? "YES": "NO", staRecord->assignedHandle, queuePacketDozing);
if(IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag)){
update_eosp_to_head_of_broadcast_list_head(priv,interfaceTag);
}
} else {
unifi_trace(priv, UDBG5, "staRecord->mgtFrames list is empty uf_process_ma_packet_req \n");
result = ul_send_signal_unpacked(priv, &signal, bulkdata);
if(result == -ENOSPC) {
list = &staRecord->mgtFrames;
requeueOnSamePos = TRUE;
unifi_trace(priv, UDBG1, "(ENOSPC) Sending MgtFrames Failed handle = %d so buffering\n",staRecord->assignedHandle);
priv->pausedStaHandle[0]=(u8)(staRecord->assignedHandle);
} else if (result) {
status = CSR_RESULT_FAILURE;
}
}
}
break;
case CSR_WIFI_MULTICAST_PDU:
unifi_trace(priv, UDBG5, "management multicast/broadcast PDU in uf_process_ma_packet_req 'QUEUE it' \n");
list = &interfacePriv->genericMulticastOrBroadCastMgtFrames;
if((interfacePriv->interfaceMode != CSR_WIFI_ROUTER_CTRL_MODE_IBSS) &&
(list_empty(&interfacePriv->genericMulticastOrBroadCastMgtFrames))) {
setBcTim=TRUE;
}
break;
default:
unifi_error(priv, "condition never meets: packet type unrecognized\n");
}
break;
case IEEE802_11_FRAMETYPE_DATA:
switch(pktType)
{
case CSR_WIFI_UNICAST_PDU:
unifi_trace(priv, UDBG5, "data unicast PDU in uf_process_ma_packet_req \n");
if(!staRecord) {
unifi_error(priv, "In %s unicast but staRecord = NULL\n", __FUNCTION__);
return CSR_RESULT_FAILURE;
} else if (queuePacketDozing || isRouterBufferEnabled(priv,priority_q)|| !list_empty(&staRecord->dataPdu[priority_q]) || IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag)) {
unifi_trace(priv, UDBG2, "Enqueued to staRecord->dataPdu[%d] queuePacketDozing=%d,\
Buffering enabled = %d \n", priority_q,queuePacketDozing,isRouterBufferEnabled(priv,priority_q));
list = &staRecord->dataPdu[priority_q];
} else {
unifi_trace(priv, UDBG5, "staRecord->dataPdu[%d] list is empty uf_process_ma_packet_req \n", priority_q);
result = ul_send_signal_unpacked(priv, &signal, bulkdata);
if(result == -ENOSPC) {
unifi_trace(priv, UDBG1, "(ENOSPC) Sending Unicast DataPDU to queue %d Failed so buffering\n",priority_q);
requeueOnSamePos = TRUE;
list = &staRecord->dataPdu[priority_q];
priv->pausedStaHandle[priority_q]=(u8)(staRecord->assignedHandle);
if(!isRouterBufferEnabled(priv,priority_q)) {
unifi_error(priv,"Buffering Not enabled for queue %d \n",priority_q);
}
} else if (result) {
status = CSR_RESULT_FAILURE;
}
}
break;
case CSR_WIFI_MULTICAST_PDU:
unifi_trace(priv, UDBG5, "data multicast/broadcast PDU in uf_process_ma_packet_req \n");
list = &interfacePriv->genericMulticastOrBroadCastFrames;
if(list_empty(&interfacePriv->genericMulticastOrBroadCastFrames)) {
setBcTim = TRUE;
}
break;
default:
unifi_error(priv, "condition never meets: packet type un recognized\n");
}
break;
default:
unifi_error(priv, "unrecognized frame type\n");
}
if(list) {
status = enque_tx_data_pdu(priv, bulkdata,list, &signal,requeueOnSamePos);
if (staRecord && (pktType == CSR_WIFI_UNICAST_PDU) && (!status)) {
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
staRecord->noOfPktQueued++;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
}
else if ((pktType == CSR_WIFI_MULTICAST_PDU) && (!status))
{
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
interfacePriv->noOfbroadcastPktQueued++;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
}
}
if(setBcTim && !status) {
unifi_trace(priv, UDBG3, "tim set due to broadcast pkt\n");
if (!interfacePriv->bcTimSetReqPendingFlag)
{
update_tim(priv,0,CSR_WIFI_TIM_SET,interfaceTag, handle);
}
else
{
interfacePriv->bcTimSetReqQueued = CSR_WIFI_TIM_SET;
unifi_trace(priv, UDBG2, "uf_process_ma_packet_req : One more UpdateDTim Request(:%d) Queued \n",
interfacePriv->bcTimSetReqQueued);
}
} else if(staRecord && staRecord->currentPeerState ==
CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_POWER_SAVE) {
if(staRecord->timSet == CSR_WIFI_TIM_RESET || staRecord->timSet == CSR_WIFI_TIM_RESETTING) {
if(!staRecord->wmmOrQosEnabled) {
if(!list_empty(&staRecord->mgtFrames) ||
!list_empty(&staRecord->dataPdu[3]) ||
!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION])) {
unifi_trace(priv, UDBG3, "tim set due to unicast pkt & peer in powersave\n");
if (!staRecord->timRequestPendingFlag){
update_tim(priv,staRecord->aid,1,interfaceTag, handle);
}
else
{
staRecord->updateTimReqQueued = 1;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", staRecord->updateTimReqQueued,
staRecord->aid);
}
}
} else {
u8 allDeliveryEnabled = 0, dataAvailable = 0;
is_all_ac_deliver_enabled_and_moredata(staRecord, &allDeliveryEnabled, &dataAvailable);
if (uf_is_more_data_for_non_delivery_ac(staRecord) || (allDeliveryEnabled && dataAvailable)
|| (!list_empty(&staRecord->mgtFrames))) {
if (!staRecord->timRequestPendingFlag) {
update_tim(priv,staRecord->aid,1,interfaceTag, handle);
}
else
{
staRecord->updateTimReqQueued = 1;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", staRecord->updateTimReqQueued,
staRecord->aid);
}
}
}
}
}
if((list) && (pktType == CSR_WIFI_UNICAST_PDU && !queuePacketDozing) && !(isRouterBufferEnabled(priv,priority_q)) && !(IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag))) {
unifi_trace(priv, UDBG2, "buffering cleared for queue = %d So resending buffered frames\n",priority_q);
uf_send_buffered_frames(priv, priority_q);
}
unifi_trace(priv, UDBG5, "leaving uf_process_ma_packet_req \n");
return status;
#else
#ifdef CSR_NATIVE_LINUX
if (interfaceTag >= CSR_WIFI_NUM_INTERFACES) {
unifi_error(priv, "interfaceTag >= CSR_WIFI_NUM_INTERFACES, interfacetag = %d\n", interfaceTag);
return CSR_RESULT_FAILURE;
}
unifi_frame_ma_packet_req(priv, priority, TransmitRate, hostTag, interfaceTag,
transmissionControl, leSenderProcessId,
peerMacAddress, &signal);
result = ul_send_signal_unpacked(priv, &signal, bulkdata);
if (result) {
return CSR_RESULT_FAILURE;
}
#endif
return status;
#endif
}
s8 uf_get_protection_bit_from_interfacemode(unifi_priv_t *priv, u16 interfaceTag, const u8 *daddr)
{
s8 protection = 0;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
switch(interfacePriv->interfaceMode)
{
case CSR_WIFI_ROUTER_CTRL_MODE_STA:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PCLI:
case CSR_WIFI_ROUTER_CTRL_MODE_AMP:
case CSR_WIFI_ROUTER_CTRL_MODE_IBSS:
protection = interfacePriv->protect;
break;
case CSR_WIFI_ROUTER_CTRL_MODE_AP:
case CSR_WIFI_ROUTER_CTRL_MODE_P2PGO:
{
CsrWifiRouterCtrlStaInfo_t *dstStaInfo = NULL;
if (daddr[0] & 0x1) {
unifi_trace(priv, UDBG3, "broadcast/multicast packet in send_ma_pkt_request\n");
protection = interfacePriv->protect;
} else {
dstStaInfo = CsrWifiRouterCtrlGetStationRecordFromPeerMacAddress(priv, daddr, interfaceTag);
if (!dstStaInfo) {
unifi_trace(priv, UDBG3, "peer not found in station record in send_ma_pkt_request\n");
return -1;
}
protection = dstStaInfo->protection;
}
}
break;
default:
unifi_trace(priv, UDBG2, "mode unknown in send_ma_pkt_request\n");
}
return protection;
}
u8 send_multicast_frames(unifi_priv_t *priv, u16 interfaceTag)
{
int r;
tx_buffered_packets_t * buffered_pkt = NULL;
u8 moreData = FALSE;
u8 pduSent =0;
unsigned long lock_flags;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
u32 hostTag = 0xffffffff;
func_enter();
if(!isRouterBufferEnabled(priv,UNIFI_TRAFFIC_Q_VO)) {
while((interfacePriv->dtimActive)&& (buffered_pkt=dequeue_tx_data_pdu(priv,&interfacePriv->genericMulticastOrBroadCastMgtFrames))) {
buffered_pkt->transmissionControl |= (TRANSMISSION_CONTROL_TRIGGER_MASK);
moreData = (buffered_pkt->transmissionControl & TRANSMISSION_CONTROL_EOSP_MASK)?FALSE:TRUE;
unifi_trace(priv,UDBG2,"DTIM Occurred for interface:sending Mgt packet %d\n",interfaceTag);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,NULL,moreData,FALSE)) == -ENOSPC) {
unifi_trace(priv,UDBG1,"frame_and_send_queued_pdu failed with ENOSPC for host tag = %x\n", buffered_pkt->hostTag);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &interfacePriv->genericMulticastOrBroadCastMgtFrames);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
break;
} else {
unifi_trace(priv,UDBG1,"send_multicast_frames: Send genericMulticastOrBroadCastMgtFrames (%x, %x)\n",
buffered_pkt->hostTag,
r);
if(r) {
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
if(!moreData) {
interfacePriv->dtimActive = FALSE;
if(!r) {
hostTag = buffered_pkt->hostTag;
pduSent++;
} else {
send_vif_availibility_rsp(priv,uf_get_vif_identifier(interfacePriv->interfaceMode,interfaceTag),CSR_RC_UNSPECIFIED_FAILURE);
}
}
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
interfacePriv->noOfbroadcastPktQueued--;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
kfree(buffered_pkt);
}
}
}
if(!isRouterBufferEnabled(priv,UNIFI_TRAFFIC_Q_CONTENTION)) {
while((interfacePriv->dtimActive)&& (buffered_pkt=dequeue_tx_data_pdu(priv,&interfacePriv->genericMulticastOrBroadCastFrames))) {
buffered_pkt->transmissionControl |= TRANSMISSION_CONTROL_TRIGGER_MASK;
moreData = (buffered_pkt->transmissionControl & TRANSMISSION_CONTROL_EOSP_MASK)?FALSE:TRUE;
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,NULL,moreData,FALSE)) == -ENOSPC) {
buffered_pkt->transmissionControl &= ~(TRANSMISSION_CONTROL_TRIGGER_MASK);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &interfacePriv->genericMulticastOrBroadCastFrames);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
break;
} else {
if(r) {
unifi_trace(priv,UDBG1,"send_multicast_frames: Send genericMulticastOrBroadCastFrame failed (%x, %x)\n",
buffered_pkt->hostTag,
r);
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
if(!moreData) {
interfacePriv->dtimActive = FALSE;
if(!r) {
pduSent ++;
hostTag = buffered_pkt->hostTag;
} else {
send_vif_availibility_rsp(priv,uf_get_vif_identifier(interfacePriv->interfaceMode,interfaceTag),CSR_RC_UNSPECIFIED_FAILURE);
}
}
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
interfacePriv->noOfbroadcastPktQueued--;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
kfree(buffered_pkt);
}
}
}
if((interfacePriv->dtimActive == FALSE)) {
unifi_trace(priv,UDBG2,"send_multicast_frames: Recorded hostTag of EOSP packet: = 0x%x\n",hostTag);
interfacePriv->multicastPduHostTag = hostTag;
}
return pduSent;
}
void uf_process_ma_vif_availibility_ind(unifi_priv_t *priv,u8 *sigdata,
u32 siglen)
{
#ifdef CSR_SUPPORT_SME
CSR_SIGNAL signal;
CSR_MA_VIF_AVAILABILITY_INDICATION *ind;
int r;
u16 interfaceTag;
u8 pduSent =0;
CSR_RESULT_CODE resultCode = CSR_RC_SUCCESS;
netInterface_priv_t *interfacePriv;
func_enter();
unifi_trace(priv, UDBG3,
"uf_process_ma_vif_availibility_ind: Process signal 0x%.4X\n",
*((u16*)sigdata));
r = read_unpack_signal(sigdata, &signal);
if (r) {
unifi_error(priv,
"uf_process_ma_vif_availibility_ind: Received unknown signal 0x%.4X.\n",
CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sigdata));
func_exit();
return;
}
ind = &signal.u.MaVifAvailabilityIndication;
interfaceTag=ind->VirtualInterfaceIdentifier & 0xff;
if (interfaceTag >= CSR_WIFI_NUM_INTERFACES) {
unifi_error(priv, "in vif_availability_ind interfaceTag is wrong\n");
return;
}
interfacePriv = priv->interfacePriv[interfaceTag];
if(ind->Multicast) {
if(list_empty(&interfacePriv->genericMulticastOrBroadCastFrames) &&
list_empty(&interfacePriv->genericMulticastOrBroadCastMgtFrames)) {
unifi_notice(priv,"ma_vif_availibility_ind recevied for multicast but queues are empty%d\n",interfaceTag);
send_vif_availibility_rsp(priv,ind->VirtualInterfaceIdentifier,CSR_RC_NO_BUFFERED_BROADCAST_MULTICAST_FRAMES);
interfacePriv->dtimActive = FALSE;
if(interfacePriv->multicastPduHostTag == 0xffffffff) {
unifi_notice(priv,"ma_vif_availibility_ind recevied for multicast but queues are empty%d\n",interfaceTag);
if (!interfacePriv->bcTimSetReqPendingFlag)
{
update_tim(priv,0,CSR_WIFI_TIM_RESET,interfaceTag, 0xFFFFFFFF);
}
else
{
interfacePriv->bcTimSetReqQueued = CSR_WIFI_TIM_RESET;
unifi_trace(priv, UDBG2, "uf_process_ma_vif_availibility_ind : One more UpdateDTim Request(%d) Queued \n",
interfacePriv->bcTimSetReqQueued);
}
}
return;
}
if(interfacePriv->dtimActive) {
unifi_trace(priv,UDBG2,"DTIM Occurred for already active DTIM interface %d\n",interfaceTag);
return;
} else {
unifi_trace(priv,UDBG2,"DTIM Occurred for interface %d\n",interfaceTag);
if(list_empty(&interfacePriv->genericMulticastOrBroadCastFrames)) {
set_eosp_transmit_ctrl(priv,&interfacePriv->genericMulticastOrBroadCastMgtFrames);
} else {
set_eosp_transmit_ctrl(priv,&interfacePriv->genericMulticastOrBroadCastFrames);
}
}
interfacePriv->dtimActive = TRUE;
pduSent = send_multicast_frames(priv,interfaceTag);
}
else {
unifi_error(priv,"Interface switching is not supported %d\n",interfaceTag);
resultCode = CSR_RC_NOT_SUPPORTED;
send_vif_availibility_rsp(priv,ind->VirtualInterfaceIdentifier,CSR_RC_NOT_SUPPORTED);
}
#endif
}
static u8 uf_is_more_data_for_delivery_ac(unifi_priv_t *priv, CsrWifiRouterCtrlStaInfo_t *staRecord)
{
s8 i;
for(i=UNIFI_TRAFFIC_Q_VO; i >= UNIFI_TRAFFIC_Q_BK; i--)
{
if(((staRecord->powersaveMode[i]==CSR_WIFI_AC_DELIVERY_ONLY_ENABLE)
||(staRecord->powersaveMode[i]==CSR_WIFI_AC_TRIGGER_AND_DELIVERY_ENABLED))
&&(!list_empty(&staRecord->dataPdu[i]))) {
unifi_trace(priv,UDBG2,"uf_is_more_data_for_delivery_ac: Data Available AC = %d\n", i);
return TRUE;
}
}
unifi_trace(priv,UDBG2,"uf_is_more_data_for_delivery_ac: Data NOT Available \n");
return FALSE;
}
static u8 uf_is_more_data_for_usp_delivery(unifi_priv_t *priv, CsrWifiRouterCtrlStaInfo_t *staRecord, unifi_TrafficQueue queue)
{
s8 i;
for(i = queue; i >= UNIFI_TRAFFIC_Q_BK; i--)
{
if(((staRecord->powersaveMode[i]==CSR_WIFI_AC_DELIVERY_ONLY_ENABLE)
||(staRecord->powersaveMode[i]==CSR_WIFI_AC_TRIGGER_AND_DELIVERY_ENABLED))
&&(!list_empty(&staRecord->dataPdu[i]))) {
unifi_trace(priv,UDBG2,"uf_is_more_data_for_usp_delivery: Data Available AC = %d\n", i);
return TRUE;
}
}
unifi_trace(priv,UDBG2,"uf_is_more_data_for_usp_delivery: Data NOT Available \n");
return FALSE;
}
void uf_send_buffered_data_from_delivery_ac(unifi_priv_t *priv,
CsrWifiRouterCtrlStaInfo_t * staInfo,
u8 queue,
struct list_head *txList)
{
u16 interfaceTag = GET_ACTIVE_INTERFACE_TAG(priv);
tx_buffered_packets_t * buffered_pkt = NULL;
unsigned long lock_flags;
u8 eosp=FALSE;
s8 r =0;
u8 moreData = FALSE;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
unifi_trace(priv, UDBG2, "++uf_send_buffered_data_from_delivery_ac, active=%x\n", staInfo->uapsdActive);
if (queue > UNIFI_TRAFFIC_Q_VO)
{
return;
}
while((buffered_pkt=dequeue_tx_data_pdu(priv, txList))) {
if((IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag))) {
unifi_trace(priv, UDBG2, "uf_send_buffered_data_from_delivery_ac: DTIM Active, suspend UAPSD, staId: 0x%x\n",
staInfo->aid);
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
staInfo->uspSuspend = TRUE;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q,txList);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
break;
}
buffered_pkt->transmissionControl &=
~(TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
if((staInfo->wmmOrQosEnabled == TRUE)&&(staInfo->uapsdActive == TRUE)) {
buffered_pkt->transmissionControl = TRANSMISSION_CONTROL_TRIGGER_MASK;
moreData = (!list_empty(txList) || uf_is_more_data_for_usp_delivery(priv, staInfo, queue));
if(staInfo->noOfSpFramesSent == (staInfo->maxSpLength - 1)) {
moreData = FALSE;
}
if(moreData == FALSE) {
eosp = TRUE;
buffered_pkt->transmissionControl =
(TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
}
} else {
unifi_warning(priv, "uf_send_buffered_data_from_delivery_ac: non U-APSD !!! \n");
}
unifi_trace(priv,UDBG2,"uf_send_buffered_data_from_delivery_ac : MoreData:%d, EOSP:%d\n",moreData,eosp);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staInfo,moreData,eosp)) == -ENOSPC) {
unifi_trace(priv, UDBG2, "uf_send_buffered_data_from_delivery_ac: UASPD suspended, ENOSPC in hipQ=%x\n", queue);
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
staInfo->uspSuspend = TRUE;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q,txList);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[queue]=(u8)(staInfo->assignedHandle);
break;
} else {
if(r){
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
staInfo->noOfSpFramesSent++;
if((!moreData) || (staInfo->noOfSpFramesSent == staInfo->maxSpLength)) {
unifi_trace(priv, UDBG2, "uf_send_buffered_data_from_delivery_ac: Terminating USP\n");
staInfo->uapsdActive = FALSE;
staInfo->uspSuspend = FALSE;
staInfo->noOfSpFramesSent = 0;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
break;
}
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
}
}
unifi_trace(priv, UDBG2, "--uf_send_buffered_data_from_delivery_ac, active=%x\n", staInfo->uapsdActive);
}
void uf_send_buffered_data_from_ac(unifi_priv_t *priv,
CsrWifiRouterCtrlStaInfo_t * staInfo,
u8 queue,
struct list_head *txList)
{
tx_buffered_packets_t * buffered_pkt = NULL;
unsigned long lock_flags;
u8 eosp=FALSE;
u8 moreData = FALSE;
s8 r =0;
func_enter();
unifi_trace(priv,UDBG2,"uf_send_buffered_data_from_ac :\n");
while(!isRouterBufferEnabled(priv,queue) &&
((buffered_pkt=dequeue_tx_data_pdu(priv, txList))!=NULL)){
buffered_pkt->transmissionControl &=
~(TRANSMISSION_CONTROL_TRIGGER_MASK|TRANSMISSION_CONTROL_EOSP_MASK);
unifi_trace(priv,UDBG3,"uf_send_buffered_data_from_ac : MoreData:%d, EOSP:%d\n",moreData,eosp);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staInfo,moreData,eosp)) == -ENOSPC) {
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q,txList);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
if(staInfo != NULL){
priv->pausedStaHandle[queue]=(u8)(staInfo->assignedHandle);
}
unifi_trace(priv,UDBG3," uf_send_buffered_data_from_ac: PDU sending failed .. no space for queue %d \n",queue);
} else {
if(r){
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
}
func_exit();
}
void uf_send_buffered_frames(unifi_priv_t *priv,unifi_TrafficQueue q)
{
u16 interfaceTag = GET_ACTIVE_INTERFACE_TAG(priv);
u32 startIndex=0,endIndex=0;
CsrWifiRouterCtrlStaInfo_t * staInfo = NULL;
u8 queue;
u8 moreData = FALSE;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
if(!((interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_AP) ||
(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_P2PGO)))
return;
func_enter();
queue = (q<=3)?q:0;
if(interfacePriv->dtimActive) {
send_multicast_frames(priv,interfaceTag);
if(!interfacePriv->dtimActive) {
moreData = (!list_empty(&interfacePriv->genericMulticastOrBroadCastMgtFrames) ||
!list_empty(&interfacePriv->genericMulticastOrBroadCastFrames));
if(!moreData) {
if (!interfacePriv->bcTimSetReqPendingFlag)
{
update_tim(priv,0,CSR_WIFI_TIM_RESET,interfaceTag, 0XFFFFFFFF);
}
else
{
interfacePriv->bcTimSetReqQueued = CSR_WIFI_TIM_RESET;
unifi_trace(priv, UDBG2, "uf_send_buffered_frames : One more UpdateDTim Request(%d) Queued \n",
interfacePriv->bcTimSetReqQueued);
}
}
} else {
moreData = (!list_empty(&interfacePriv->genericMulticastOrBroadCastMgtFrames) ||
!list_empty(&interfacePriv->genericMulticastOrBroadCastFrames));
if(!moreData) {
unifi_error(priv,"ERROR: No More Data but DTIM is active sending Response\n");
send_vif_availibility_rsp(priv,uf_get_vif_identifier(interfacePriv->interfaceMode,interfaceTag),CSR_RC_NO_BUFFERED_BROADCAST_MULTICAST_FRAMES);
interfacePriv->dtimActive = FALSE;
}
}
func_exit();
return;
}
if(priv->pausedStaHandle[queue] > 7) {
priv->pausedStaHandle[queue] = 0;
}
if(queue == UNIFI_TRAFFIC_Q_VO) {
unifi_trace(priv,UDBG2,"uf_send_buffered_frames : trying mgt from queue=%d\n",queue);
for(startIndex= 0; startIndex < UNIFI_MAX_CONNECTIONS;startIndex++) {
staInfo = CsrWifiRouterCtrlGetStationRecordFromHandle(priv,startIndex,interfaceTag);
if(!staInfo ) {
continue;
} else if((staInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_POWER_SAVE)
&&(staInfo->uapsdActive == FALSE) ) {
continue;
}
if((staInfo != NULL)&&(staInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_ACTIVE)
&&(staInfo->uapsdActive == FALSE)){
if(!list_empty(&staInfo->mgtFrames)){
uf_send_buffered_data_from_ac(priv,staInfo, UNIFI_TRAFFIC_Q_VO, &staInfo->mgtFrames);
}
}
if(isRouterBufferEnabled(priv,queue)) {
unifi_notice(priv,"uf_send_buffered_frames : No space Left for queue = %d\n",queue);
break;
}
}
if(!list_empty(&interfacePriv->genericMgtFrames)) {
unifi_trace(priv,UDBG2,"uf_send_buffered_frames : trying generic mgt from queue=%d\n",queue);
uf_send_buffered_data_from_ac(priv,staInfo, UNIFI_TRAFFIC_Q_VO, &interfacePriv->genericMgtFrames);
}
}
unifi_trace(priv,UDBG2,"uf_send_buffered_frames : Resume called for Queue=%d\n",queue);
unifi_trace(priv,UDBG2,"uf_send_buffered_frames : start=%d end=%d\n",startIndex,endIndex);
startIndex = priv->pausedStaHandle[queue];
endIndex = (startIndex + UNIFI_MAX_CONNECTIONS -1) % UNIFI_MAX_CONNECTIONS;
while(startIndex != endIndex) {
staInfo = CsrWifiRouterCtrlGetStationRecordFromHandle(priv,startIndex,interfaceTag);
if(!staInfo) {
startIndex ++;
if(startIndex >= UNIFI_MAX_CONNECTIONS) {
startIndex = 0;
}
continue;
} else if((staInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_POWER_SAVE)
&&(staInfo->uapsdActive == FALSE)) {
startIndex ++;
if(startIndex >= UNIFI_MAX_CONNECTIONS) {
startIndex = 0;
}
continue;
}
unifi_trace(priv,UDBG2,"uf_send_buffered_frames : trying data from queue=%d\n",queue);
if((staInfo != NULL)&&(staInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_ACTIVE)
&&(staInfo->uapsdActive == FALSE)) {
if(!list_empty(&staInfo->dataPdu[queue])) {
uf_send_buffered_data_from_ac(priv, staInfo, queue, (&staInfo->dataPdu[queue]));
}
}
startIndex ++;
if(startIndex >= UNIFI_MAX_CONNECTIONS) {
startIndex = 0;
}
}
if(isRouterBufferEnabled(priv,queue)) {
priv->pausedStaHandle[queue] = endIndex;
} else {
priv->pausedStaHandle[queue] = 0;
}
unifi_trace(priv, UDBG4, "csrWifiHipSendBufferedFrames: UAPSD Resume Q=%x\n", queue);
resume_suspended_uapsd(priv, interfaceTag);
func_exit();
}
u8 uf_is_more_data_for_non_delivery_ac(CsrWifiRouterCtrlStaInfo_t *staRecord)
{
u8 i;
for(i=0;i<=3;i++)
{
if(((staRecord->powersaveMode[i]==CSR_WIFI_AC_TRIGGER_ONLY_ENABLED)
||(staRecord->powersaveMode[i]==CSR_WIFI_AC_LEGACY_POWER_SAVE))
&&(!list_empty(&staRecord->dataPdu[i]))){
return TRUE;
}
}
if(((staRecord->powersaveMode[UNIFI_TRAFFIC_Q_VO]==CSR_WIFI_AC_TRIGGER_ONLY_ENABLED)
||(staRecord->powersaveMode[UNIFI_TRAFFIC_Q_VO]==CSR_WIFI_AC_LEGACY_POWER_SAVE))
&&(!list_empty(&staRecord->mgtFrames))){
return TRUE;
}
return FALSE;
}
int uf_process_station_records_for_sending_data(unifi_priv_t *priv,u16 interfaceTag,
CsrWifiRouterCtrlStaInfo_t *srcStaInfo,
CsrWifiRouterCtrlStaInfo_t *dstStaInfo)
{
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
unifi_trace(priv, UDBG5, "entering uf_process_station_records_for_sending_data\n");
if (srcStaInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_DISCONNECTED) {
unifi_error(priv, "Peer State not connected AID = %x, handle = %x, control port state = %x\n",
srcStaInfo->aid, srcStaInfo->assignedHandle, srcStaInfo->peerControlledPort->port_action);
return -1;
}
switch (interfacePriv->interfaceMode)
{
case CSR_WIFI_ROUTER_CTRL_MODE_P2PGO:
case CSR_WIFI_ROUTER_CTRL_MODE_AP:
unifi_trace(priv, UDBG5, "mode is AP/P2PGO\n");
break;
default:
unifi_warning(priv, "mode is nor AP neither P2PGO, packet cant be xmit\n");
return -1;
}
switch(dstStaInfo->peerControlledPort->port_action)
{
case CSR_WIFI_ROUTER_CTRL_PORT_ACTION_8021X_PORT_CLOSED_DISCARD:
case CSR_WIFI_ROUTER_CTRL_PORT_ACTION_8021X_PORT_CLOSED_BLOCK:
unifi_trace(priv, UDBG5, "destination port is closed/blocked, discarding the packet\n");
return -1;
default:
unifi_trace(priv, UDBG5, "destination port state is open\n");
}
unifi_trace(priv, UDBG5, "leaving uf_process_station_records_for_sending_data\n");
return 0;
}
static void uf_handle_uspframes_delivery(unifi_priv_t * priv, CsrWifiRouterCtrlStaInfo_t *staInfo, u16 interfaceTag)
{
s8 i;
u8 allDeliveryEnabled = 0, dataAvailable = 0;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
unsigned long lock_flags;
unifi_trace(priv, UDBG2, " ++ uf_handle_uspframes_delivery, uapsd active=%x, suspended?=%x\n",
staInfo->uapsdActive, staInfo->uspSuspend);
if (!staInfo->uspSuspend && staInfo->uapsdActive)
{
unifi_notice(priv, "uf_handle_uspframes_delivery: U-APSD already active! STA=%x:%x:%x:%x:%x:%x\n",
staInfo->peerMacAddress.a[0], staInfo->peerMacAddress.a[1],
staInfo->peerMacAddress.a[2], staInfo->peerMacAddress.a[3],
staInfo->peerMacAddress.a[4], staInfo->peerMacAddress.a[5]);
return;
}
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
staInfo->uapsdActive = TRUE;
staInfo->uspSuspend = FALSE;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
if(((staInfo->powersaveMode[UNIFI_TRAFFIC_Q_VO]==CSR_WIFI_AC_TRIGGER_AND_DELIVERY_ENABLED)||
(staInfo->powersaveMode[UNIFI_TRAFFIC_Q_VO]==CSR_WIFI_AC_DELIVERY_ONLY_ENABLE))
&& (!list_empty(&staInfo->mgtFrames))) {
unifi_trace(priv, UDBG4, "uf_handle_uspframes_delivery: Sending buffered management frames\n");
uf_send_buffered_data_from_delivery_ac(priv, staInfo, UNIFI_TRAFFIC_Q_VO, &staInfo->mgtFrames);
}
if (!uf_is_more_data_for_delivery_ac(priv, staInfo)) {
if (!staInfo->uspSuspend) {
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
staInfo->uapsdActive = FALSE;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
unifi_trace(priv, UDBG2, "uf_handle_uspframes_delivery: sending QNull for trigger\n");
uf_send_qos_null(priv, interfaceTag, staInfo->peerMacAddress.a, (CSR_PRIORITY) staInfo->triggerFramePriority, staInfo);
staInfo->triggerFramePriority = CSR_QOS_UP0;
} else {
unifi_trace(priv, UDBG2, "uf_handle_uspframes_delivery: MgtQ xfer suspended\n");
}
} else {
for(i = UNIFI_TRAFFIC_Q_VO; i >= UNIFI_TRAFFIC_Q_BK; i--) {
if(((staInfo->powersaveMode[i]==CSR_WIFI_AC_DELIVERY_ONLY_ENABLE)
||(staInfo->powersaveMode[i]==CSR_WIFI_AC_TRIGGER_AND_DELIVERY_ENABLED))
&& (!list_empty(&staInfo->dataPdu[i]))) {
unifi_trace(priv, UDBG4, "uf_handle_uspframes_delivery: Buffered data frames from Queue (%d) for USP\n", i);
uf_send_buffered_data_from_delivery_ac(priv, staInfo, i, &staInfo->dataPdu[i]);
}
if ((!staInfo->uapsdActive) ||
(staInfo->uspSuspend && IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag))) {
unifi_trace(priv, UDBG2, "uf_handle_uspframes_delivery: suspend=%x, DTIM=%x, USP terminated=%s\n",
staInfo->uspSuspend, IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag),
staInfo->uapsdActive?"NO":"YES");
break;
}
}
}
is_all_ac_deliver_enabled_and_moredata(staInfo, &allDeliveryEnabled, &dataAvailable);
if ((allDeliveryEnabled && !dataAvailable)) {
if ((staInfo->timSet != CSR_WIFI_TIM_RESET) || (staInfo->timSet != CSR_WIFI_TIM_RESETTING)) {
staInfo->updateTimReqQueued = (u8) CSR_WIFI_TIM_RESET;
unifi_trace(priv, UDBG4, " --uf_handle_uspframes_delivery, UAPSD timset\n");
if (!staInfo->timRequestPendingFlag) {
update_tim(priv, staInfo->aid, 0, interfaceTag, staInfo->assignedHandle);
}
}
}
unifi_trace(priv, UDBG2, " --uf_handle_uspframes_delivery, uapsd active=%x, suspend?=%x\n",
staInfo->uapsdActive, staInfo->uspSuspend);
}
void uf_process_wmm_deliver_ac_uapsd(unifi_priv_t * priv,
CsrWifiRouterCtrlStaInfo_t * srcStaInfo,
u16 qosControl,
u16 interfaceTag)
{
CSR_PRIORITY priority;
unifi_TrafficQueue priority_q;
unsigned long lock_flags;
unifi_trace(priv, UDBG2, "++uf_process_wmm_deliver_ac_uapsd: uapsdactive?=%x\n", srcStaInfo->uapsdActive);
priority = (CSR_PRIORITY)(qosControl & IEEE802_11_QC_TID_MASK);
priority_q = unifi_frame_priority_to_queue((CSR_PRIORITY) priority);
if((srcStaInfo->powersaveMode[priority_q]==CSR_WIFI_AC_TRIGGER_ONLY_ENABLED)
||(srcStaInfo->powersaveMode[priority_q]==CSR_WIFI_AC_TRIGGER_AND_DELIVERY_ENABLED)) {
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
srcStaInfo->triggerFramePriority = priority;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
unifi_trace(priv, UDBG2, "uf_process_wmm_deliver_ac_uapsd: trigger frame, Begin U-APSD, triggerQ=%x\n", priority_q);
uf_handle_uspframes_delivery(priv, srcStaInfo, interfaceTag);
}
unifi_trace(priv, UDBG2, "--uf_process_wmm_deliver_ac_uapsd: uapsdactive?=%x\n", srcStaInfo->uapsdActive);
}
void uf_send_qos_null(unifi_priv_t * priv,u16 interfaceTag, const u8 *da,CSR_PRIORITY priority,CsrWifiRouterCtrlStaInfo_t * srcStaInfo)
{
bulk_data_param_t bulkdata;
CsrResult csrResult;
struct sk_buff *skb, *newSkb = NULL;
CsrWifiMacAddress peerAddress;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
CSR_TRANSMISSION_CONTROL transmissionControl = (TRANSMISSION_CONTROL_EOSP_MASK | TRANSMISSION_CONTROL_TRIGGER_MASK);
int r;
CSR_SIGNAL signal;
u32 priority_q;
CSR_RATE transmitRate = 0;
func_enter();
csrResult = unifi_net_data_malloc(priv, &bulkdata.d[0], MAC_HEADER_SIZE + QOS_CONTROL_HEADER_SIZE);
if (csrResult != CSR_RESULT_SUCCESS) {
unifi_error(priv, " failed to allocate request_data. in uf_send_qos_null func\n");
return ;
}
skb = (struct sk_buff *)(bulkdata.d[0].os_net_buf_ptr);
skb->len = 0;
bulkdata.d[0].os_data_ptr = skb->data;
bulkdata.d[0].os_net_buf_ptr = (unsigned char*)skb;
bulkdata.d[0].net_buf_length = bulkdata.d[0].data_length = skb->len;
bulkdata.d[1].os_data_ptr = NULL;
bulkdata.d[1].os_net_buf_ptr = NULL;
bulkdata.d[1].net_buf_length = bulkdata.d[1].data_length = 0;
if (prepare_and_add_macheader(priv, skb, newSkb, priority, &bulkdata, interfaceTag, da, interfacePriv->bssid.a, 0)) {
unifi_error(priv, "failed to create MAC header\n");
unifi_net_data_free(priv, &bulkdata.d[0]);
return;
}
memcpy(peerAddress.a, ((u8 *) bulkdata.d[0].os_data_ptr) + 4, ETH_ALEN);
priority_q = unifi_frame_priority_to_queue((CSR_PRIORITY) priority);
switch (interfacePriv->interfaceMode)
{
case CSR_WIFI_ROUTER_CTRL_MODE_AP:
transmitRate = 2;
break;
case CSR_WIFI_ROUTER_CTRL_MODE_P2PGO:
transmitRate = 12;
break;
default:
transmitRate = 0;
}
unifi_frame_ma_packet_req(priv, priority, transmitRate, 0xffffffff, interfaceTag,
transmissionControl, priv->netdev_client->sender_id,
peerAddress.a, &signal);
r = ul_send_signal_unpacked(priv, &signal, &bulkdata);
if(r) {
unifi_error(priv, "failed to send QOS data null packet result: %d\n",r);
unifi_net_data_free(priv, &bulkdata.d[0]);
}
func_exit();
return;
}
void uf_send_nulldata(unifi_priv_t * priv,u16 interfaceTag, const u8 *da,CSR_PRIORITY priority,CsrWifiRouterCtrlStaInfo_t * srcStaInfo)
{
bulk_data_param_t bulkdata;
CsrResult csrResult;
struct sk_buff *skb, *newSkb = NULL;
CsrWifiMacAddress peerAddress;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
CSR_TRANSMISSION_CONTROL transmissionControl = 0;
int r;
CSR_SIGNAL signal;
u32 priority_q;
CSR_RATE transmitRate = 0;
CSR_MA_PACKET_REQUEST *req = &signal.u.MaPacketRequest;
unsigned long lock_flags;
func_enter();
csrResult = unifi_net_data_malloc(priv, &bulkdata.d[0], MAC_HEADER_SIZE);
if (csrResult != CSR_RESULT_SUCCESS) {
unifi_error(priv, "uf_send_nulldata: Failed to allocate memory for NULL frame\n");
return ;
}
skb = (struct sk_buff *)(bulkdata.d[0].os_net_buf_ptr);
skb->len = 0;
bulkdata.d[0].os_data_ptr = skb->data;
bulkdata.d[0].os_net_buf_ptr = (unsigned char*)skb;
bulkdata.d[0].net_buf_length = bulkdata.d[0].data_length = skb->len;
bulkdata.d[1].os_data_ptr = NULL;
bulkdata.d[1].os_net_buf_ptr = NULL;
bulkdata.d[1].net_buf_length = bulkdata.d[1].data_length = 0;
if (prepare_and_add_macheader(priv, skb, newSkb, priority, &bulkdata, interfaceTag, da, interfacePriv->bssid.a, 0)) {
unifi_error(priv, "uf_send_nulldata: Failed to create MAC header\n");
unifi_net_data_free(priv, &bulkdata.d[0]);
return;
}
memcpy(peerAddress.a, ((u8 *) bulkdata.d[0].os_data_ptr) + 4, ETH_ALEN);
priority_q = unifi_frame_priority_to_queue((CSR_PRIORITY) priority);
transmissionControl &= ~(CSR_NO_CONFIRM_REQUIRED);
switch (interfacePriv->interfaceMode)
{
case CSR_WIFI_ROUTER_CTRL_MODE_AP:
transmitRate = 2;
break;
case CSR_WIFI_ROUTER_CTRL_MODE_P2PGO:
transmitRate = 12;
break;
default:
transmitRate = 0;
}
unifi_frame_ma_packet_req(priv, priority, transmitRate, INVALID_HOST_TAG, interfaceTag,
transmissionControl, priv->netdev_client->sender_id,
peerAddress.a, &signal);
srcStaInfo->nullDataHostTag = req->HostTag;
unifi_trace(priv, UDBG1, "uf_send_nulldata: STA AID = %d hostTag = %x\n", srcStaInfo->aid, req->HostTag);
r = ul_send_signal_unpacked(priv, &signal, &bulkdata);
if(r == -ENOSPC) {
unifi_trace(priv, UDBG1, "uf_send_nulldata: ENOSPC Requeue the Null frame\n");
enque_tx_data_pdu(priv, &bulkdata, &srcStaInfo->dataPdu[priority_q], &signal, 1);
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
srcStaInfo->noOfPktQueued++;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
}
if(r && r != -ENOSPC){
unifi_error(priv, "uf_send_nulldata: Failed to send Null frame Error = %d\n",r);
unifi_net_data_free(priv, &bulkdata.d[0]);
srcStaInfo->nullDataHostTag = INVALID_HOST_TAG;
}
func_exit();
return;
}
u8 uf_check_broadcast_bssid(unifi_priv_t *priv, const bulk_data_param_t *bulkdata)
{
u8 *bssid = NULL;
static const CsrWifiMacAddress broadcast_address = {{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
u8 toDs, fromDs;
toDs = (((bulkdata->d[0].os_data_ptr)[1]) & 0x01) ? 1 : 0;
fromDs =(((bulkdata->d[0].os_data_ptr)[1]) & 0x02) ? 1 : 0;
if (toDs && fromDs)
{
unifi_trace(priv, UDBG6, "Address 4 present, Don't try to find BSSID\n");
bssid = NULL;
}
else if((toDs == 0) && (fromDs ==0))
{
bssid = (u8 *) (bulkdata->d[0].os_data_ptr + 4 + (2 * ETH_ALEN));
}
else if(toDs)
{
bssid = (u8 *) (bulkdata->d[0].os_data_ptr + 4);
}
else if(fromDs)
{
bssid = (u8 *) (bulkdata->d[0].os_data_ptr + 4 + ETH_ALEN);
}
if (memcmp(broadcast_address.a, bssid, ETH_ALEN)== 0)
{
return TRUE;
}
else
{
return FALSE;
}
}
u8 uf_process_pm_bit_for_peer(unifi_priv_t * priv, CsrWifiRouterCtrlStaInfo_t * srcStaInfo,
u8 pmBit,u16 interfaceTag)
{
u8 moreData = FALSE;
u8 powerSaveChanged = FALSE;
unsigned long lock_flags;
unifi_trace(priv, UDBG3, "entering uf_process_pm_bit_for_peer\n");
if (pmBit) {
priv->allPeerDozing |= (0x01 << (srcStaInfo->assignedHandle));
} else {
priv->allPeerDozing &= ~(0x01 << (srcStaInfo->assignedHandle));
}
if(pmBit) {
if(srcStaInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_ACTIVE) {
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
srcStaInfo->currentPeerState =CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_POWER_SAVE;
powerSaveChanged = TRUE;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
} else {
return powerSaveChanged;
}
} else {
if(srcStaInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_POWER_SAVE) {
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
srcStaInfo->currentPeerState = CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_ACTIVE;
powerSaveChanged = TRUE;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
}else {
return powerSaveChanged;
}
}
if(srcStaInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_ACTIVE) {
unifi_trace(priv,UDBG3, "Peer with AID = %d is active now\n",srcStaInfo->aid);
process_peer_active_transition(priv,srcStaInfo,interfaceTag);
} else {
unifi_trace(priv,UDBG3, "Peer with AID = %d is in PS Now\n",srcStaInfo->aid);
if(!srcStaInfo->wmmOrQosEnabled) {
moreData = (!list_empty(&srcStaInfo->mgtFrames) ||
!list_empty(&srcStaInfo->dataPdu[UNIFI_TRAFFIC_Q_VO])||
!list_empty(&srcStaInfo->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION]));
if(moreData && (srcStaInfo->timSet == CSR_WIFI_TIM_RESET)) {
unifi_trace(priv, UDBG3, "This condition should not occur\n");
if (!srcStaInfo->timRequestPendingFlag){
update_tim(priv,srcStaInfo->aid,1,interfaceTag, srcStaInfo->assignedHandle);
}
else
{
srcStaInfo->updateTimReqQueued = 1;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", srcStaInfo->updateTimReqQueued,
srcStaInfo->aid);
}
}
} else {
u8 allDeliveryEnabled = 0, dataAvailable = 0;
unifi_trace(priv, UDBG5, "Qos in AP Mode\n");
is_all_ac_deliver_enabled_and_moredata(srcStaInfo, &allDeliveryEnabled, &dataAvailable);
moreData = (uf_is_more_data_for_non_delivery_ac(srcStaInfo) || (allDeliveryEnabled && dataAvailable));
if(moreData && (srcStaInfo->timSet == CSR_WIFI_TIM_RESET)) {
if (!srcStaInfo->timRequestPendingFlag){
update_tim(priv,srcStaInfo->aid,1,interfaceTag, srcStaInfo->assignedHandle);
}
else
{
srcStaInfo->updateTimReqQueued = 1;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", srcStaInfo->updateTimReqQueued,
srcStaInfo->aid);
}
}
}
}
unifi_trace(priv, UDBG3, "leaving uf_process_pm_bit_for_peer\n");
return powerSaveChanged;
}
void uf_process_ps_poll(unifi_priv_t *priv,u8* sa,u8* da,u8 pmBit,u16 interfaceTag)
{
CsrWifiRouterCtrlStaInfo_t *staRecord =
CsrWifiRouterCtrlGetStationRecordFromPeerMacAddress(priv, sa, interfaceTag);
tx_buffered_packets_t * buffered_pkt = NULL;
CsrWifiMacAddress peerMacAddress;
unsigned long lock_flags;
s8 r =0;
u8 moreData = FALSE;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
unifi_trace(priv, UDBG3, "entering uf_process_ps_poll\n");
if(!staRecord) {
memcpy(peerMacAddress.a,sa,ETH_ALEN);
unifi_trace(priv, UDBG3, "In uf_process_ps_poll, sta record not found:unexpected frame addr = %x:%x:%x:%x:%x:%x\n",
sa[0], sa[1],sa[2], sa[3], sa[4],sa[5]);
CsrWifiRouterCtrlUnexpectedFrameIndSend(priv->CSR_WIFI_SME_IFACEQUEUE,0,interfaceTag,peerMacAddress);
return;
}
uf_process_pm_bit_for_peer(priv,staRecord,pmBit,interfaceTag);
staRecord->activity_flag = TRUE;
if(!pmBit) {
unifi_notice (priv," PM bit reset in PS-POLL\n");
return;
}
if(IS_DTIM_ACTIVE(interfacePriv->dtimActive,interfacePriv->multicastPduHostTag)) {
unifi_notice (priv," multicast transmission is going on so don't take action on PS-POLL\n");
return;
}
if(!staRecord->wmmOrQosEnabled) {
if((buffered_pkt=dequeue_tx_data_pdu(priv, &staRecord->mgtFrames))) {
buffered_pkt->transmissionControl |= TRANSMISSION_CONTROL_TRIGGER_MASK;
moreData = (!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION]) ||
!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_VO]) ||
!list_empty(&staRecord->mgtFrames));
buffered_pkt->transmissionControl |= (TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staRecord,moreData,FALSE)) == -ENOSPC) {
buffered_pkt->transmissionControl &= ~(TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staRecord->mgtFrames);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
unifi_trace(priv, UDBG1, "(ENOSPC) PS-POLL received : PDU sending failed \n");
priv->pausedStaHandle[3]=(u8)(staRecord->assignedHandle);
} else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
} else if((buffered_pkt=dequeue_tx_data_pdu(priv, &staRecord->dataPdu[UNIFI_TRAFFIC_Q_VO]))) {
buffered_pkt->transmissionControl |= TRANSMISSION_CONTROL_TRIGGER_MASK;
moreData = (!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION]) ||
!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_VO]));
buffered_pkt->transmissionControl |= (TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staRecord,moreData,FALSE)) == -ENOSPC) {
buffered_pkt->transmissionControl &= ~(TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staRecord->dataPdu[UNIFI_TRAFFIC_Q_VO]);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[3]=(u8)(staRecord->assignedHandle);
unifi_trace(priv, UDBG1, "(ENOSPC) PS-POLL received : PDU sending failed \n");
} else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
} else if((buffered_pkt=dequeue_tx_data_pdu(priv, &staRecord->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION]))) {
buffered_pkt->transmissionControl |= TRANSMISSION_CONTROL_TRIGGER_MASK;
moreData = !list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION]);
buffered_pkt->transmissionControl |= (TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staRecord,moreData,FALSE)) == -ENOSPC) {
buffered_pkt->transmissionControl &= ~(TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staRecord->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION]);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[0]=(u8)(staRecord->assignedHandle);
unifi_trace(priv, UDBG1, "(ENOSPC) PS-POLL received : PDU sending failed \n");
} else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
} else {
}
moreData = (!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_VO]) ||
!list_empty(&staRecord->dataPdu[UNIFI_TRAFFIC_Q_CONTENTION]) ||
!list_empty(&staRecord->mgtFrames));
if(!moreData && (staRecord->timSet == CSR_WIFI_TIM_SET)) {
unifi_trace(priv, UDBG3, "more data = NULL, set tim to 0 in uf_process_ps_poll\n");
if (!staRecord->timRequestPendingFlag){
update_tim(priv,staRecord->aid,0,interfaceTag, staRecord->assignedHandle);
}
else
{
staRecord->updateTimReqQueued = 0;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", staRecord->updateTimReqQueued,
staRecord->aid);
}
}
} else {
u8 allDeliveryEnabled = 0, dataAvailable = 0;
unifi_trace(priv, UDBG3,"Qos Support station.Processing PS-Poll\n");
is_all_ac_deliver_enabled_and_moredata(staRecord, &allDeliveryEnabled, &dataAvailable);
if (allDeliveryEnabled) {
unifi_trace(priv, UDBG3, "uf_process_ps_poll: All ACs are delivery enable so Sending QOS Null in response of Ps-poll\n");
uf_send_qos_null(priv,interfaceTag,sa,CSR_QOS_UP0,staRecord);
return;
}
if (!list_empty(&staRecord->mgtFrames)) {
if ((buffered_pkt=dequeue_tx_data_pdu(priv, &staRecord->mgtFrames))) {
moreData = uf_is_more_data_for_non_delivery_ac(staRecord);
buffered_pkt->transmissionControl |= (TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staRecord,moreData,FALSE)) == -ENOSPC) {
buffered_pkt->transmissionControl &= ~(TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staRecord->mgtFrames);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[0]=(u8)(staRecord->assignedHandle);
unifi_trace(priv, UDBG1, "(ENOSPC) PS-POLL received : PDU sending failed \n");
} else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
} else {
unifi_error(priv, "uf_process_ps_poll: Mgt frame list empty!! \n");
}
} else {
s8 i;
for(i= 3; i>=0; i--) {
if (!IS_DELIVERY_ENABLED(staRecord->powersaveMode[i])) {
if((buffered_pkt=dequeue_tx_data_pdu(priv, &staRecord->dataPdu[i]))) {
moreData = uf_is_more_data_for_non_delivery_ac(staRecord);
buffered_pkt->transmissionControl |= (TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staRecord,moreData,FALSE)) == -ENOSPC) {
buffered_pkt->transmissionControl &= ~(TRANSMISSION_CONTROL_TRIGGER_MASK | TRANSMISSION_CONTROL_EOSP_MASK);
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staRecord->dataPdu[i]);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[0]=(u8)(staRecord->assignedHandle);
unifi_trace(priv, UDBG1, "(ENOSPC) PS-POLL received : PDU sending failed \n");
} else {
if(r) {
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
break;
}
}
}
}
is_all_ac_deliver_enabled_and_moredata(staRecord, &allDeliveryEnabled, &dataAvailable);
moreData = (uf_is_more_data_for_non_delivery_ac(staRecord) || (allDeliveryEnabled && dataAvailable));
if(!moreData && (staRecord->timSet == CSR_WIFI_TIM_SET)) {
unifi_trace(priv, UDBG3, "more data = NULL, set tim to 0 in uf_process_ps_poll\n");
if (!staRecord->timRequestPendingFlag){
update_tim(priv,staRecord->aid,0,interfaceTag, staRecord->assignedHandle);
}
else
{
staRecord->updateTimReqQueued = 0;
unifi_trace(priv, UDBG6, "update_tim : One more UpdateTim Request (Tim value:%d) Queued for AID %x\n", staRecord->updateTimReqQueued,
staRecord->aid);
}
}
}
unifi_trace(priv, UDBG3, "leaving uf_process_ps_poll\n");
}
void add_to_send_cfm_list(unifi_priv_t * priv,
tx_buffered_packets_t *tx_q_item,
struct list_head *frames_need_cfm_list)
{
tx_buffered_packets_t *send_cfm_list_item = NULL;
send_cfm_list_item = (tx_buffered_packets_t *) kmalloc(sizeof(tx_buffered_packets_t), GFP_ATOMIC);
if(send_cfm_list_item == NULL){
unifi_warning(priv, "%s: Failed to allocate memory for new list item \n");
return;
}
INIT_LIST_HEAD(&send_cfm_list_item->q);
send_cfm_list_item->hostTag = tx_q_item->hostTag;
send_cfm_list_item->interfaceTag = tx_q_item->interfaceTag;
send_cfm_list_item->transmissionControl = tx_q_item->transmissionControl;
send_cfm_list_item->leSenderProcessId = tx_q_item->leSenderProcessId;
send_cfm_list_item->rate = tx_q_item->rate;
memcpy(send_cfm_list_item->peerMacAddress.a, tx_q_item->peerMacAddress.a, ETH_ALEN);
send_cfm_list_item->priority = tx_q_item->priority;
list_add_tail(&send_cfm_list_item->q, frames_need_cfm_list);
}
void uf_prepare_send_cfm_list_for_queued_pkts(unifi_priv_t * priv,
struct list_head *frames_need_cfm_list,
struct list_head * list)
{
tx_buffered_packets_t *tx_q_item = NULL;
struct list_head *listHead;
struct list_head *placeHolder;
unsigned long lock_flags;
func_enter();
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_for_each_safe(listHead, placeHolder, list) {
tx_q_item = list_entry(listHead, tx_buffered_packets_t, q);
if(!tx_q_item) {
unifi_error(priv, "Entry should exist, otherwise it is a (BUG)\n");
continue;
}
if (!(tx_q_item->transmissionControl & CSR_NO_CONFIRM_REQUIRED) &&
(tx_q_item->leSenderProcessId != priv->netdev_client->sender_id)){
unifi_trace(priv, UDBG1, "%s: SenderProcessID=%x host tag=%x transmission control=%x\n",
__FUNCTION__,
tx_q_item->leSenderProcessId,
tx_q_item->hostTag,
tx_q_item->transmissionControl);
add_to_send_cfm_list(priv, tx_q_item, frames_need_cfm_list);
}
}
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
func_exit();
}
void uf_flush_list(unifi_priv_t * priv, struct list_head * list)
{
tx_buffered_packets_t *tx_q_item;
struct list_head *listHead;
struct list_head *placeHolder;
unsigned long lock_flags;
unifi_trace(priv, UDBG5, "entering the uf_flush_list \n");
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_for_each_safe(listHead, placeHolder, list) {
tx_q_item = list_entry(listHead, tx_buffered_packets_t, q);
if(!tx_q_item) {
unifi_error(priv, "entry should exists, otherwise crashes (bug)\n");
}
unifi_trace(priv, UDBG5,
"proccess_tx: in uf_flush_list peerMacAddress=%02X%02X%02X%02X%02X%02X senderProcessId=%x\n",
tx_q_item->peerMacAddress.a[0], tx_q_item->peerMacAddress.a[1],
tx_q_item->peerMacAddress.a[2], tx_q_item->peerMacAddress.a[3],
tx_q_item->peerMacAddress.a[4], tx_q_item->peerMacAddress.a[5],
tx_q_item->leSenderProcessId);
list_del(listHead);
unifi_net_data_free(priv, &tx_q_item->bulkdata);
kfree(tx_q_item);
tx_q_item = NULL;
if (!priv->noOfPktQueuedInDriver) {
unifi_error(priv, "packets queued in driver 0 still decrementing in %s\n", __FUNCTION__);
} else {
priv->noOfPktQueuedInDriver--;
}
}
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
}
tx_buffered_packets_t *dequeue_tx_data_pdu(unifi_priv_t *priv, struct list_head *txList)
{
tx_buffered_packets_t *tx_q_item = NULL;
struct list_head *listHead;
struct list_head *placeHolder;
unsigned long lock_flags;
unifi_trace(priv, UDBG5, "entering dequeue_tx_data_pdu\n");
if (list_empty(txList)) {
unifi_trace(priv, UDBG5, "In dequeue_tx_data_pdu, the list is empty\n");
return NULL;
}
if (priv->noOfPktQueuedInDriver == 0xFFFF) {
unifi_warning(priv, "no packet available in queue: debug");
return NULL;
}
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_for_each_safe(listHead, placeHolder, txList) {
tx_q_item = list_entry(listHead, tx_buffered_packets_t, q);
list_del(listHead);
break;
}
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
if (tx_q_item) {
unifi_trace(priv, UDBG5,
"proccess_tx: In dequeue_tx_data_pdu peerMacAddress=%02X%02X%02X%02X%02X%02X senderProcessId=%x\n",
tx_q_item->peerMacAddress.a[0], tx_q_item->peerMacAddress.a[1],
tx_q_item->peerMacAddress.a[2], tx_q_item->peerMacAddress.a[3],
tx_q_item->peerMacAddress.a[4], tx_q_item->peerMacAddress.a[5],
tx_q_item->leSenderProcessId);
}
unifi_trace(priv, UDBG5, "leaving dequeue_tx_data_pdu\n");
return tx_q_item;
}
CsrWifiRouterCtrlStaInfo_t *CsrWifiRouterCtrlGetStationRecordFromPeerMacAddress(unifi_priv_t *priv,
const u8 *peerMacAddress,
u16 interfaceTag)
{
u8 i;
netInterface_priv_t *interfacePriv;
unsigned long lock_flags;
if (interfaceTag >= CSR_WIFI_NUM_INTERFACES) {
unifi_error(priv, "interfaceTag is not proper, interfaceTag = %d\n", interfaceTag);
return NULL;
}
interfacePriv = priv->interfacePriv[interfaceTag];
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
for (i = 0; i < UNIFI_MAX_CONNECTIONS; i++) {
if (interfacePriv->staInfo[i]!= NULL) {
if (!memcmp(((CsrWifiRouterCtrlStaInfo_t *) (interfacePriv->staInfo[i]))->peerMacAddress.a, peerMacAddress, ETH_ALEN)) {
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
unifi_trace(priv, UDBG5, "peer entry found in station record\n");
return ((CsrWifiRouterCtrlStaInfo_t *) (interfacePriv->staInfo[i]));
}
}
}
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
unifi_trace(priv, UDBG5, "peer entry not found in station record\n");
return NULL;
}
CsrWifiRouterCtrlStaInfo_t * CsrWifiRouterCtrlGetStationRecordFromHandle(unifi_priv_t *priv,
u32 handle,
u16 interfaceTag)
{
netInterface_priv_t *interfacePriv;
if ((handle >= UNIFI_MAX_CONNECTIONS) || (interfaceTag >= CSR_WIFI_NUM_INTERFACES)) {
unifi_error(priv, "handle/interfaceTag is not proper, handle = %d, interfaceTag = %d\n", handle, interfaceTag);
return NULL;
}
interfacePriv = priv->interfacePriv[interfaceTag];
return ((CsrWifiRouterCtrlStaInfo_t *) (interfacePriv->staInfo[handle]));
}
void uf_check_inactivity(unifi_priv_t *priv, u16 interfaceTag, CsrTime currentTime)
{
u32 i;
CsrWifiRouterCtrlStaInfo_t *staInfo;
CsrTime elapsedTime;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
CsrWifiMacAddress peerMacAddress;
unsigned long lock_flags;
if (interfacePriv == NULL) {
unifi_trace(priv, UDBG3, "uf_check_inactivity: Interface priv is NULL \n");
return;
}
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
for(i = 0; i < UNIFI_MAX_CONNECTIONS; i++) {
staInfo = CsrWifiRouterCtrlGetStationRecordFromHandle(priv, i, interfaceTag);
if(!staInfo ) {
continue;
}
unifi_trace(priv, UDBG3, "Running Inactivity handler Time %xus station's last activity %xus\n",
currentTime, staInfo->lastActivity);
elapsedTime = (currentTime >= staInfo->lastActivity)?
(currentTime - staInfo->lastActivity):
(~((u32)0) - staInfo->lastActivity + currentTime);
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
if (elapsedTime > MAX_INACTIVITY_INTERVAL) {
memcpy((u8*)&peerMacAddress, (u8*)&staInfo->peerMacAddress, sizeof(CsrWifiMacAddress));
unifi_trace(priv, UDBG3, "Station %x:%x:%x:%x:%x:%x inactive since %xus\n sending Inactive Ind\n",
peerMacAddress.a[0], peerMacAddress.a[1],
peerMacAddress.a[2], peerMacAddress.a[3],
peerMacAddress.a[4], peerMacAddress.a[5],
elapsedTime);
CsrWifiRouterCtrlStaInactiveIndSend(priv->CSR_WIFI_SME_IFACEQUEUE, 0, interfaceTag, peerMacAddress);
}
}
interfacePriv->last_inactivity_check = currentTime;
}
void uf_update_sta_activity(unifi_priv_t *priv, u16 interfaceTag, const u8 *peerMacAddress)
{
CsrTime elapsedTime, currentTime;
CsrTime timeHi;
CsrWifiRouterCtrlStaInfo_t *staInfo;
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
unsigned long lock_flags;
if (interfacePriv == NULL) {
unifi_trace(priv, UDBG3, "uf_check_inactivity: Interface priv is NULL \n");
return;
}
currentTime = CsrTimeGet(&timeHi);
staInfo = CsrWifiRouterCtrlGetStationRecordFromPeerMacAddress(priv, peerMacAddress, interfaceTag);
if (staInfo == NULL) {
unifi_trace(priv, UDBG4, "Sta does not exist yet");
return;
}
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
staInfo->lastActivity = currentTime;
elapsedTime = (currentTime >= interfacePriv->last_inactivity_check)?
(currentTime - interfacePriv->last_inactivity_check):
(~((u32)0) - interfacePriv->last_inactivity_check + currentTime);
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
if (elapsedTime > INACTIVITY_CHECK_INTERVAL) {
uf_check_inactivity(priv, interfaceTag, currentTime);
}
}
void resume_unicast_buffered_frames(unifi_priv_t *priv, u16 interfaceTag)
{
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
u8 i;
int j;
tx_buffered_packets_t * buffered_pkt = NULL;
u8 hipslotFree[4] = {TRUE,TRUE,TRUE,TRUE};
int r;
unsigned long lock_flags;
func_enter();
while(!isRouterBufferEnabled(priv,3) &&
((buffered_pkt=dequeue_tx_data_pdu(priv,&interfacePriv->genericMgtFrames))!=NULL)) {
buffered_pkt->transmissionControl &=
~(TRANSMISSION_CONTROL_TRIGGER_MASK|TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,NULL,0,FALSE)) == -ENOSPC) {
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &interfacePriv->genericMgtFrames);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
hipslotFree[3]=FALSE;
break;
}else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
}
for(i = 0; i < UNIFI_MAX_CONNECTIONS; i++) {
CsrWifiRouterCtrlStaInfo_t *staInfo = interfacePriv->staInfo[i];
if(!hipslotFree[0] && !hipslotFree[1] && !hipslotFree[2] && !hipslotFree[3]) {
unifi_trace(priv, UDBG3, "(ENOSPC) in resume_unicast_buffered_frames:: hip slots are full \n");
break;
}
if (staInfo && (staInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_ACTIVE)) {
while((( TRUE == hipslotFree[3] ) && (buffered_pkt=dequeue_tx_data_pdu(priv, &staInfo->mgtFrames)))) {
buffered_pkt->transmissionControl &=
~(TRANSMISSION_CONTROL_TRIGGER_MASK|TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staInfo,0,FALSE)) == -ENOSPC) {
unifi_trace(priv, UDBG3, "(ENOSPC) in resume_unicast_buffered_frames:: hip slots are full for voice queue\n");
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staInfo->mgtFrames);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[3]=(u8)(staInfo->assignedHandle);
hipslotFree[3] = FALSE;
break;
} else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
}
for(j=3;j>=0;j--) {
if(!hipslotFree[j])
continue;
while((buffered_pkt=dequeue_tx_data_pdu(priv, &staInfo->dataPdu[j]))) {
buffered_pkt->transmissionControl &=
~(TRANSMISSION_CONTROL_TRIGGER_MASK|TRANSMISSION_CONTROL_EOSP_MASK);
if((r=frame_and_send_queued_pdu(priv,buffered_pkt,staInfo,0,FALSE)) == -ENOSPC) {
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_add(&buffered_pkt->q, &staInfo->dataPdu[j]);
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
priv->pausedStaHandle[j]=(u8)(staInfo->assignedHandle);
hipslotFree[j]=FALSE;
break;
} else {
if(r){
unifi_trace (priv, UDBG1, " HIP validation failure : PDU sending failed \n");
unifi_net_data_free(priv, &buffered_pkt->bulkdata);
}
kfree(buffered_pkt);
}
}
}
}
}
func_exit();
}
void update_eosp_to_head_of_broadcast_list_head(unifi_priv_t *priv,u16 interfaceTag)
{
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
unsigned long lock_flags;
struct list_head *listHead;
struct list_head *placeHolder;
tx_buffered_packets_t *tx_q_item;
func_enter();
if (interfacePriv->noOfbroadcastPktQueued) {
spin_lock_irqsave(&priv->tx_q_lock,lock_flags);
list_for_each_safe(listHead, placeHolder, &interfacePriv->genericMulticastOrBroadCastFrames) {
tx_q_item = list_entry(listHead, tx_buffered_packets_t, q);
tx_q_item->transmissionControl |= TRANSMISSION_CONTROL_EOSP_MASK;
tx_q_item->transmissionControl = (tx_q_item->transmissionControl & ~(CSR_NO_CONFIRM_REQUIRED));
unifi_trace(priv, UDBG1,"updating eosp for list Head hostTag:= 0x%x ",tx_q_item->hostTag);
break;
}
spin_unlock_irqrestore(&priv->tx_q_lock,lock_flags);
}
func_exit();
}
void resume_suspended_uapsd(unifi_priv_t* priv,u16 interfaceTag)
{
u8 startIndex;
CsrWifiRouterCtrlStaInfo_t * staInfo = NULL;
unsigned long lock_flags;
unifi_trace(priv, UDBG2, "++resume_suspended_uapsd: \n");
for(startIndex= 0; startIndex < UNIFI_MAX_CONNECTIONS;startIndex++) {
staInfo = CsrWifiRouterCtrlGetStationRecordFromHandle(priv,startIndex,interfaceTag);
if(!staInfo || !staInfo->wmmOrQosEnabled) {
continue;
} else if((staInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_POWER_SAVE)
&&staInfo->uapsdActive && staInfo->uspSuspend) {
uf_handle_uspframes_delivery(priv, staInfo, interfaceTag);
} else {
unifi_trace(priv, UDBG2, "resume_suspended_uapsd: PS state=%x, uapsdActive?=%x, suspend?=%x\n",
staInfo->currentPeerState, staInfo->uapsdActive, staInfo->uspSuspend);
if (staInfo->currentPeerState == CSR_WIFI_ROUTER_CTRL_PEER_CONNECTED_ACTIVE)
{
spin_lock_irqsave(&priv->staRecord_lock,lock_flags);
staInfo->uapsdActive = FALSE;
staInfo->uspSuspend = FALSE;
spin_unlock_irqrestore(&priv->staRecord_lock,lock_flags);
}
}
}
unifi_trace(priv, UDBG2, "--resume_suspended_uapsd:\n");
}
