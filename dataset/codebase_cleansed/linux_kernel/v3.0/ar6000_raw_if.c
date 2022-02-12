static int ar6000_connect_raw_service(struct ar6_softc *ar,
HTC_RAW_STREAM_ID StreamID)
{
int status;
struct htc_service_connect_resp response;
u8 streamNo;
struct htc_service_connect_req connect;
do {
A_MEMZERO(&connect,sizeof(connect));
streamNo = (u8)StreamID;
connect.pMetaData = &streamNo;
connect.MetaDataLength = sizeof(u8);
connect.EpCallbacks.pContext = ar;
connect.EpCallbacks.EpTxComplete = ar6000_htc_raw_write_cb;
connect.EpCallbacks.EpRecv = ar6000_htc_raw_read_cb;
connect.EpCallbacks.EpRecvRefill = NULL;
connect.EpCallbacks.EpSendFull = NULL;
connect.MaxSendQueueDepth = RAW_HTC_WRITE_BUFFERS_NUM;
connect.ServiceID = HTC_RAW_STREAMS_SVC;
A_MEMZERO(&response,sizeof(response));
status = HTCConnectService(ar->arHtcTarget,
&connect,
&response);
if (status) {
if (response.ConnectRespCode == HTC_SERVICE_NO_MORE_EP) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("HTC RAW , No more streams allowed \n"));
status = 0;
}
break;
}
arSetRawStream2EndpointIDMap(ar,StreamID,response.Endpoint);
AR_DEBUG_PRINTF(ATH_DEBUG_HTC_RAW,("HTC RAW : stream ID: %d, endpoint: %d\n",
StreamID, arRawStream2EndpointID(ar,StreamID)));
} while (false);
return status;
}
int ar6000_htc_raw_open(struct ar6_softc *ar)
{
int status;
int streamID, endPt, count2;
raw_htc_buffer *buffer;
HTC_SERVICE_ID servicepriority;
AR_RAW_HTC_T *arRaw = ar->arRawHtc;
if (!arRaw) {
arRaw = ar->arRawHtc = A_MALLOC(sizeof(AR_RAW_HTC_T));
if (arRaw) {
A_MEMZERO(arRaw, sizeof(AR_RAW_HTC_T));
}
}
A_ASSERT(ar->arHtcTarget != NULL);
if (!arRaw) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Faile to allocate memory for HTC RAW interface\n"));
return -ENOMEM;
}
status = HTCWaitTarget(ar->arHtcTarget);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("HTCWaitTarget failed (%d)\n", status));
return -ENODEV;
}
for (endPt = 0; endPt < ENDPOINT_MAX; endPt++) {
arRaw->arEp2RawMapping[endPt] = HTC_RAW_STREAM_NOT_MAPPED;
}
for (streamID = HTC_RAW_STREAM_0; streamID < HTC_RAW_STREAM_NUM_MAX; streamID++) {
sema_init(&arRaw->raw_htc_read_sem[streamID], 1);
sema_init(&arRaw->raw_htc_write_sem[streamID], 1);
init_waitqueue_head(&arRaw->raw_htc_read_queue[streamID]);
init_waitqueue_head(&arRaw->raw_htc_write_queue[streamID]);
status = ar6000_connect_raw_service(ar,streamID);
if (status) {
break;
}
if (arRawStream2EndpointID(ar,streamID) == 0) {
break;
}
for (count2 = 0; count2 < RAW_HTC_READ_BUFFERS_NUM; count2 ++) {
buffer = &arRaw->raw_htc_write_buffer[streamID][count2];
memset(buffer, 0, sizeof(raw_htc_buffer));
buffer = &arRaw->raw_htc_read_buffer[streamID][count2];
memset(buffer, 0, sizeof(raw_htc_buffer));
SET_HTC_PACKET_INFO_RX_REFILL(&buffer->HTCPacket,
buffer,
buffer->data,
HTC_RAW_BUFFER_SIZE,
arRawStream2EndpointID(ar,streamID));
if ((status = HTCAddReceivePkt(ar->arHtcTarget, &buffer->HTCPacket)) != 0)
{
BMIInit();
return -EIO;
}
}
for (count2 = 0; count2 < RAW_HTC_WRITE_BUFFERS_NUM; count2 ++) {
buffer = &arRaw->raw_htc_write_buffer[streamID][count2];
memset(buffer, 0, sizeof(raw_htc_buffer));
}
arRaw->read_buffer_available[streamID] = false;
arRaw->write_buffer_available[streamID] = true;
}
if (status) {
return -EIO;
}
AR_DEBUG_PRINTF(ATH_DEBUG_INFO,("HTC RAW, number of streams the target supports: %d \n", streamID));
servicepriority = HTC_RAW_STREAMS_SVC;
HTCSetCreditDistribution(ar->arHtcTarget,
ar,
NULL,
NULL,
&servicepriority,
1);
if ((status = HTCStart(ar->arHtcTarget)) != 0) {
BMIInit();
return -EIO;
}
(ar)->arRawIfInit = true;
return 0;
}
int ar6000_htc_raw_close(struct ar6_softc *ar)
{
A_PRINTF("ar6000_htc_raw_close called \n");
HTCStop(ar->arHtcTarget);
ar6000_reset_device(ar->arHifDevice, ar->arTargetType, true, false);
BMIInit();
return 0;
}
raw_htc_buffer *
get_filled_buffer(struct ar6_softc *ar, HTC_RAW_STREAM_ID StreamID)
{
int count;
raw_htc_buffer *busy;
AR_RAW_HTC_T *arRaw = ar->arRawHtc;
for (count = 0; count < RAW_HTC_READ_BUFFERS_NUM; count ++) {
busy = &arRaw->raw_htc_read_buffer[StreamID][count];
if (busy->length) {
break;
}
}
if (busy->length) {
arRaw->read_buffer_available[StreamID] = true;
} else {
arRaw->read_buffer_available[StreamID] = false;
}
return busy;
}
ssize_t ar6000_htc_raw_read(struct ar6_softc *ar, HTC_RAW_STREAM_ID StreamID,
char __user *buffer, size_t length)
{
int readPtr;
raw_htc_buffer *busy;
AR_RAW_HTC_T *arRaw = ar->arRawHtc;
if (arRawStream2EndpointID(ar,StreamID) == 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("StreamID(%d) not connected! \n", StreamID));
return -EFAULT;
}
if (down_interruptible(&arRaw->raw_htc_read_sem[StreamID])) {
return -ERESTARTSYS;
}
busy = get_filled_buffer(ar,StreamID);
while (!arRaw->read_buffer_available[StreamID]) {
up(&arRaw->raw_htc_read_sem[StreamID]);
AR_DEBUG_PRINTF(ATH_DEBUG_HTC_RAW,("Sleeping StreamID(%d) read process\n", StreamID));
if (wait_event_interruptible(arRaw->raw_htc_read_queue[StreamID],
arRaw->read_buffer_available[StreamID]))
{
return -EINTR;
}
if (down_interruptible(&arRaw->raw_htc_read_sem[StreamID])) {
return -ERESTARTSYS;
}
busy = get_filled_buffer(ar,StreamID);
}
readPtr = busy->currPtr;
if (length > busy->length - HTC_HEADER_LEN) {
length = busy->length - HTC_HEADER_LEN;
}
if (copy_to_user(buffer, &busy->data[readPtr], length)) {
up(&arRaw->raw_htc_read_sem[StreamID]);
return -EFAULT;
}
busy->currPtr += length;
if (busy->currPtr == busy->length)
{
busy->currPtr = 0;
busy->length = 0;
HTC_PACKET_RESET_RX(&busy->HTCPacket);
HTCAddReceivePkt(ar->arHtcTarget, &busy->HTCPacket);
}
arRaw->read_buffer_available[StreamID] = false;
up(&arRaw->raw_htc_read_sem[StreamID]);
return length;
}
static raw_htc_buffer *
get_free_buffer(struct ar6_softc *ar, HTC_ENDPOINT_ID StreamID)
{
int count;
raw_htc_buffer *free;
AR_RAW_HTC_T *arRaw = ar->arRawHtc;
free = NULL;
for (count = 0; count < RAW_HTC_WRITE_BUFFERS_NUM; count ++) {
free = &arRaw->raw_htc_write_buffer[StreamID][count];
if (free->length == 0) {
break;
}
}
if (!free->length) {
arRaw->write_buffer_available[StreamID] = true;
} else {
arRaw->write_buffer_available[StreamID] = false;
}
return free;
}
ssize_t ar6000_htc_raw_write(struct ar6_softc *ar, HTC_RAW_STREAM_ID StreamID,
char __user *buffer, size_t length)
{
int writePtr;
raw_htc_buffer *free;
AR_RAW_HTC_T *arRaw = ar->arRawHtc;
if (arRawStream2EndpointID(ar,StreamID) == 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("StreamID(%d) not connected! \n", StreamID));
return -EFAULT;
}
if (down_interruptible(&arRaw->raw_htc_write_sem[StreamID])) {
return -ERESTARTSYS;
}
free = get_free_buffer(ar,StreamID);
while (!arRaw->write_buffer_available[StreamID]) {
up(&arRaw->raw_htc_write_sem[StreamID]);
AR_DEBUG_PRINTF(ATH_DEBUG_HTC_RAW,("Sleeping StreamID(%d) write process\n", StreamID));
if (wait_event_interruptible(arRaw->raw_htc_write_queue[StreamID],
arRaw->write_buffer_available[StreamID]))
{
return -EINTR;
}
if (down_interruptible(&arRaw->raw_htc_write_sem[StreamID])) {
return -ERESTARTSYS;
}
free = get_free_buffer(ar,StreamID);
}
writePtr = HTC_HEADER_LEN;
if (length > (HTC_RAW_BUFFER_SIZE - HTC_HEADER_LEN)) {
length = HTC_RAW_BUFFER_SIZE - HTC_HEADER_LEN;
}
if (copy_from_user(&free->data[writePtr], buffer, length)) {
up(&arRaw->raw_htc_read_sem[StreamID]);
return -EFAULT;
}
free->length = length;
SET_HTC_PACKET_INFO_TX(&free->HTCPacket,
free,
&free->data[writePtr],
length,
arRawStream2EndpointID(ar,StreamID),
AR6K_DATA_PKT_TAG);
HTCSendPkt(ar->arHtcTarget,&free->HTCPacket);
arRaw->write_buffer_available[StreamID] = false;
up(&arRaw->raw_htc_write_sem[StreamID]);
return length;
}
