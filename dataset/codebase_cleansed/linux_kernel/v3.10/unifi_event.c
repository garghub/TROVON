static void send_to_client(unifi_priv_t *priv, ul_client_t *client,
int receiver_id,
unsigned char *sigdata, int siglen,
const bulk_data_param_t *bulkdata)
{
if (client && client->event_hook) {
client->event_hook(client, sigdata, siglen, bulkdata, UDI_TO_HOST);
}
}
static void
unifi_process_receive_event(void *ospriv,
u8 *sigdata, u32 siglen,
const bulk_data_param_t *bulkdata)
{
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
int i, receiver_id;
int client_id;
s16 signal_id;
u8 pktIndToSme = FALSE, freeBulkData = FALSE;
unifi_trace(priv, UDBG5, "unifi_process_receive_event: "
"%04x %04x %04x %04x %04x %04x %04x %04x (%d)\n",
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*0) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*1) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*2) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*3) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*4) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*5) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*6) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*7) & 0xFFFF,
siglen);
receiver_id = CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)) & 0xFF00;
client_id = (receiver_id & 0x0F00) >> UDI_SENDER_ID_SHIFT;
signal_id = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sigdata);
if (signal_id == CSR_MA_PACKET_INDICATION_ID)
{
#define CSR_MA_PACKET_INDICATION_INTERFACETAG_OFFSET 14
u8 interfaceTag;
netInterface_priv_t *interfacePriv;
interfaceTag = (CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sigdata + CSR_MA_PACKET_INDICATION_INTERFACETAG_OFFSET)) & 0xff;
interfacePriv = priv->interfacePriv[interfaceTag];
#ifdef CSR_SUPPORT_SME
if (interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_IBSS)
{
u8 *saddr;
saddr = (u8 *) bulkdata->d[0].os_data_ptr + MAC_HEADER_ADDR2_OFFSET;
unifi_trace(priv, UDBG5,
"Updating sta activity in IBSS interfaceTag %x Src Addr %x:%x:%x:%x:%x:%x\n",
interfaceTag, saddr[0], saddr[1], saddr[2], saddr[3], saddr[4], saddr[5]);
uf_update_sta_activity(priv, interfaceTag, saddr);
}
#endif
pktIndToSme = check_routing_pkt_data_ind(priv, sigdata, bulkdata, &freeBulkData, interfacePriv);
unifi_trace(priv, UDBG6, "RX: packet entry point to driver from HIP,pkt to SME ?(%s) \n", (pktIndToSme)? "YES":"NO");
}
if (pktIndToSme)
{
if(sigdata != NULL && bulkdata != NULL){
send_to_client(priv, priv->sme_cli, receiver_id, sigdata, siglen, bulkdata);
}
else{
unifi_error(priv, "unifi_receive_event2: sigdata or Bulkdata is NULL \n");
}
#ifdef CSR_NATIVE_LINUX
send_to_client(priv, priv->wext_client,
receiver_id,
sigdata, siglen, bulkdata);
#endif
}
else
{
if (!receiver_id) {
if(signal_id == CSR_MA_VIF_AVAILABILITY_INDICATION_ID) {
uf_process_ma_vif_availibility_ind(priv, sigdata, siglen);
}
else if (signal_id != CSR_MA_PACKET_INDICATION_ID) {
send_to_client(priv, priv->sme_cli, receiver_id, sigdata, siglen, bulkdata);
#ifdef CSR_NATIVE_LINUX
send_to_client(priv, priv->wext_client,
receiver_id,
sigdata, siglen, bulkdata);
#endif
}
else
{
#if (defined(CSR_SUPPORT_SME) && defined(CSR_WIFI_SECURITY_WAPI_ENABLE))
#define CSR_MA_PACKET_INDICATION_RECEPTION_STATUS_OFFSET sizeof(CSR_SIGNAL_PRIMITIVE_HEADER) + 22
netInterface_priv_t *interfacePriv;
u8 interfaceTag;
u16 receptionStatus = CSR_RX_SUCCESS;
interfaceTag = (CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sigdata + CSR_MA_PACKET_INDICATION_INTERFACETAG_OFFSET)) & 0xff;
interfacePriv = priv->interfacePriv[interfaceTag];
receptionStatus = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sigdata + CSR_MA_PACKET_INDICATION_RECEPTION_STATUS_OFFSET);
if ((!freeBulkData) &&
(interfacePriv->interfaceMode == CSR_WIFI_ROUTER_CTRL_MODE_STA) &&
(receptionStatus == CSR_MICHAEL_MIC_ERROR) &&
((priv->wapi_multicast_filter == 1)
#ifdef CSR_WIFI_SECURITY_WAPI_SW_ENCRYPTION
|| (priv->wapi_unicast_filter == 1)
#endif
))
{
CSR_SIGNAL signal;
u8 *destAddr;
CsrResult res;
u16 interfaceTag = 0;
u8 isMcastPkt = TRUE;
unifi_trace(priv, UDBG6, "Received a WAPI data packet when the Unicast/Multicast filter is set\n");
res = read_unpack_signal(sigdata, &signal);
if (res) {
unifi_error(priv, "Received unknown or corrupted signal (0x%x).\n",
CSR_GET_UINT16_FROM_LITTLE_ENDIAN(sigdata));
return;
}
destAddr = (u8 *) bulkdata->d[0].os_data_ptr + MAC_HEADER_ADDR1_OFFSET;
isMcastPkt = (destAddr[0] & 0x01) ? TRUE : FALSE;
unifi_trace(priv, UDBG6,
"1.MPDU type: (%s), 2.Multicast filter: (%s), 3. Unicast filter: (%s)\n",
((isMcastPkt) ? "Multiast":"Unicast"),
((priv->wapi_multicast_filter) ? "Enabled":"Disabled"),
((priv->wapi_unicast_filter) ? "Enabled":"Disabled"));
if (((isMcastPkt) && (priv->wapi_multicast_filter == 1))
#ifdef CSR_WIFI_SECURITY_WAPI_SW_ENCRYPTION
|| ((!isMcastPkt) && (priv->wapi_unicast_filter == 1))
#endif
)
{
unifi_trace(priv, UDBG4, "Sending the WAPI MPDU for MIC check\n");
CsrWifiRouterCtrlWapiRxMicCheckIndSend(priv->CSR_WIFI_SME_IFACEQUEUE, 0, interfaceTag, siglen, sigdata, bulkdata->d[0].data_length, (u8*)bulkdata->d[0].os_data_ptr);
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++) {
if (bulkdata->d[i].data_length != 0) {
unifi_net_data_free(priv, (void *)&bulkdata->d[i]);
}
}
return;
}
}
#endif
}
}
if(!freeBulkData){
if ((client_id < MAX_UDI_CLIENTS) &&
(&priv->ul_clients[client_id] != priv->logging_client)) {
unifi_trace(priv, UDBG6, "Call the registered clients handler callback func\n");
send_to_client(priv, &priv->ul_clients[client_id],
receiver_id,
sigdata, siglen, bulkdata);
}
}
}
switch (signal_id)
{
#ifdef UNIFI_SNIFF_ARPHRD
case CSR_MA_SNIFFDATA_INDICATION_ID:
#endif
break;
case CSR_MA_PACKET_INDICATION_ID:
if (!freeBulkData)
{
break;
}
default:
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++) {
if (bulkdata->d[i].data_length != 0) {
unifi_net_data_free(priv, (void *)&bulkdata->d[i]);
}
}
}
}
static u8 signal_buffer_is_full(unifi_priv_t* priv)
{
return (((priv->rxSignalBuffer.writePointer + 1)% priv->rxSignalBuffer.size) == (priv->rxSignalBuffer.readPointer));
}
void unifi_rx_queue_flush(void *ospriv)
{
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
unifi_trace(priv, UDBG4, "rx_wq_handler: RdPtr = %d WritePtr = %d\n",
priv->rxSignalBuffer.readPointer,priv->rxSignalBuffer.writePointer);
if(priv != NULL) {
u8 readPointer = priv->rxSignalBuffer.readPointer;
while (readPointer != priv->rxSignalBuffer.writePointer)
{
rx_buff_struct_t *buf = &priv->rxSignalBuffer.rx_buff[readPointer];
unifi_trace(priv, UDBG6, "rx_wq_handler: RdPtr = %d WritePtr = %d\n",
readPointer,priv->rxSignalBuffer.writePointer);
unifi_process_receive_event(priv, buf->bufptr, buf->sig_len, &buf->data_ptrs);
readPointer ++;
if(readPointer >= priv->rxSignalBuffer.size) {
readPointer = 0;
}
}
priv->rxSignalBuffer.readPointer = readPointer;
}
}
void rx_wq_handler(struct work_struct *work)
{
unifi_priv_t *priv = container_of(work, unifi_priv_t, rx_work_struct);
unifi_rx_queue_flush(priv);
}
void
unifi_receive_event(void *ospriv,
u8 *sigdata, u32 siglen,
const bulk_data_param_t *bulkdata)
{
#ifdef CSR_WIFI_RX_PATH_SPLIT
unifi_priv_t *priv = (unifi_priv_t*)ospriv;
u8 writePointer;
int i;
rx_buff_struct_t * rx_buff;
unifi_trace(priv, UDBG5, "unifi_receive_event: "
"%04x %04x %04x %04x %04x %04x %04x %04x (%d)\n",
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*0) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*1) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*2) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*3) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*4) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*5) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*6) & 0xFFFF,
CSR_GET_UINT16_FROM_LITTLE_ENDIAN((sigdata) + sizeof(s16)*7) & 0xFFFF, siglen);
if(signal_buffer_is_full(priv)) {
unifi_error(priv,"TO HOST signal queue FULL dropping the PDU\n");
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++) {
if (bulkdata->d[i].data_length != 0) {
unifi_net_data_free(priv, (void *)&bulkdata->d[i]);
}
}
return;
}
writePointer = priv->rxSignalBuffer.writePointer;
rx_buff = &priv->rxSignalBuffer.rx_buff[writePointer];
memcpy(rx_buff->bufptr,sigdata,siglen);
rx_buff->sig_len = siglen;
rx_buff->data_ptrs = *bulkdata;
writePointer++;
if(writePointer >= priv->rxSignalBuffer.size) {
writePointer =0;
}
unifi_trace(priv, UDBG4, "unifi_receive_event:writePtr = %d\n",priv->rxSignalBuffer.writePointer);
priv->rxSignalBuffer.writePointer = writePointer;
#ifndef CSR_WIFI_RX_PATH_SPLIT_DONT_USE_WQ
queue_work(priv->rx_workqueue, &priv->rx_work_struct);
#endif
#else
unifi_process_receive_event(ospriv, sigdata, siglen, bulkdata);
#endif
}
