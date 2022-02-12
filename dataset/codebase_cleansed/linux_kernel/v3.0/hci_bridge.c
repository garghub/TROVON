static inline void FreeBtOsBuf(struct ar6k_hci_bridge_info *pHcidevInfo, void *osbuf)
{
if (pHcidevInfo->HciNormalMode) {
bt_free_buffer(pHcidevInfo, (struct sk_buff *)osbuf);
} else {
A_NETBUF_FREE(osbuf);
}
}
static void FreeHTCStruct(struct ar6k_hci_bridge_info *pHcidevInfo, struct htc_packet *pPacket)
{
LOCK_BRIDGE(pHcidevInfo);
HTC_PACKET_ENQUEUE(&pHcidevInfo->HTCPacketStructHead,pPacket);
UNLOCK_BRIDGE(pHcidevInfo);
}
static struct htc_packet * AllocHTCStruct(struct ar6k_hci_bridge_info *pHcidevInfo)
{
struct htc_packet *pPacket = NULL;
LOCK_BRIDGE(pHcidevInfo);
pPacket = HTC_PACKET_DEQUEUE(&pHcidevInfo->HTCPacketStructHead);
UNLOCK_BRIDGE(pHcidevInfo);
return pPacket;
}
static void RefillRecvBuffers(struct ar6k_hci_bridge_info *pHcidevInfo,
HCI_TRANSPORT_PACKET_TYPE Type,
int NumBuffers)
{
int length, i;
void *osBuf = NULL;
struct htc_packet_queue queue;
struct htc_packet *pPacket;
INIT_HTC_PACKET_QUEUE(&queue);
if (Type == HCI_ACL_TYPE) {
if (pHcidevInfo->HciNormalMode) {
length = HCI_MAX_FRAME_SIZE;
} else {
length = MAX_ACL_RECV_LENGTH;
}
} else {
length = MAX_EVT_RECV_LENGTH;
}
length += pHcidevInfo->HCIProps.HeadRoom + pHcidevInfo->HCIProps.TailRoom;
length = BLOCK_ROUND_UP_PWR2(length,pHcidevInfo->HCIProps.IOBlockPad);
for (i = 0; i < NumBuffers; i++) {
if (pHcidevInfo->HciNormalMode) {
osBuf = bt_alloc_buffer(pHcidevInfo,length);
} else {
osBuf = A_NETBUF_ALLOC(length);
}
if (NULL == osBuf) {
break;
}
pPacket = AllocHTCStruct(pHcidevInfo);
if (NULL == pPacket) {
FreeBtOsBuf(pHcidevInfo,osBuf);
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Failed to alloc HTC struct \n"));
break;
}
SET_HTC_PACKET_INFO_RX_REFILL(pPacket,osBuf,A_NETBUF_DATA(osBuf),length,Type);
HTC_PACKET_ENQUEUE(&queue,pPacket);
}
if (i > 0) {
HCI_TransportAddReceivePkts(pHcidevInfo->pHCIDev, &queue);
}
}
static int ar6000_hci_transport_ready(HCI_TRANSPORT_HANDLE HCIHandle,
struct hci_transport_properties *pProps,
void *pContext)
{
struct ar6k_hci_bridge_info *pHcidevInfo = (struct ar6k_hci_bridge_info *)pContext;
int status;
u32 address, hci_uart_pwr_mgmt_params;
pHcidevInfo->pHCIDev = HCIHandle;
memcpy(&pHcidevInfo->HCIProps,pProps,sizeof(*pProps));
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_BRIDGE,("HCI ready (hci:0x%lX, headroom:%d, tailroom:%d blockpad:%d) \n",
(unsigned long)HCIHandle,
pHcidevInfo->HCIProps.HeadRoom,
pHcidevInfo->HCIProps.TailRoom,
pHcidevInfo->HCIProps.IOBlockPad));
#ifdef EXPORT_HCI_BRIDGE_INTERFACE
A_ASSERT((pProps->HeadRoom + pProps->TailRoom) <= (struct net_device *)(pHcidevInfo->HCITransHdl.netDevice)->hard_header_len);
#else
A_ASSERT((pProps->HeadRoom + pProps->TailRoom) <= pHcidevInfo->ar->arNetDev->hard_header_len);
#endif
RefillRecvBuffers(pHcidevInfo, HCI_ACL_TYPE, MAX_ACL_RECV_BUFS);
RefillRecvBuffers(pHcidevInfo, HCI_EVENT_TYPE, MAX_EVT_RECV_BUFS);
do {
status = HCI_TransportStart(pHcidevInfo->pHCIDev);
if (status) {
break;
}
if (!pHcidevInfo->HciNormalMode) {
break;
}
A_MDELAY(100);
A_MEMZERO(&ar3kconfig,sizeof(ar3kconfig));
ar3kconfig.pHCIDev = pHcidevInfo->pHCIDev;
ar3kconfig.pHCIProps = &pHcidevInfo->HCIProps;
#ifdef EXPORT_HCI_BRIDGE_INTERFACE
ar3kconfig.pHIFDevice = (struct hif_device *)(pHcidevInfo->HCITransHdl.hifDevice);
#else
ar3kconfig.pHIFDevice = pHcidevInfo->ar->arHifDevice;
#endif
ar3kconfig.pBtStackHCIDev = pHcidevInfo->pBtStackHCIDev;
if (ar3khcibaud != 0) {
ar3kconfig.Flags |= AR3K_CONFIG_FLAG_SET_AR3K_BAUD;
ar3kconfig.Flags |= AR3K_CONFIG_FLAG_AR3K_BAUD_CHANGE_DELAY;
ar3kconfig.AR3KBaudRate = ar3khcibaud;
}
if ((hciuartscale != 0) || (hciuartstep != 0)) {
ar3kconfig.AR6KScale = (u16)hciuartscale;
ar3kconfig.AR6KStep = (u16)hciuartstep;
ar3kconfig.Flags |= AR3K_CONFIG_FLAG_SET_AR6K_SCALE_STEP;
}
address = TARG_VTOP(pHcidevInfo->ar->arTargetType,
HOST_INTEREST_ITEM_ADDRESS(pHcidevInfo->ar, hi_hci_uart_pwr_mgmt_params));
status = ar6000_ReadRegDiag(pHcidevInfo->ar->arHifDevice, &address, &hci_uart_pwr_mgmt_params);
if (0 == status) {
ar3kconfig.PwrMgmtEnabled = (hci_uart_pwr_mgmt_params & 0x1);
ar3kconfig.IdleTimeout = (hci_uart_pwr_mgmt_params & 0xFFFF0000) >> 16;
ar3kconfig.WakeupTimeout = (hci_uart_pwr_mgmt_params & 0xFF00) >> 8;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HCI Bridge: failed to read hci_uart_pwr_mgmt_params! \n"));
}
memcpy(ar3kconfig.bdaddr,pHcidevInfo->ar->bdaddr,6);
status = AR3KConfigure(&ar3kconfig);
if (status) {
break;
}
if (ar3kconfig.PwrMgmtEnabled) {
status = HCI_TransportEnablePowerMgmt(pHcidevInfo->pHCIDev, true);
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HCI Bridge: failed to enable TLPM for AR6K! \n"));
}
}
status = bt_register_hci(pHcidevInfo);
} while (false);
return status;
}
static void ar6000_hci_transport_failure(void *pContext, int Status)
{
struct ar6k_hci_bridge_info *pHcidevInfo = (struct ar6k_hci_bridge_info *)pContext;
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HCI Bridge: transport failure! \n"));
if (pHcidevInfo->HciNormalMode) {
}
}
static void ar6000_hci_transport_removed(void *pContext)
{
struct ar6k_hci_bridge_info *pHcidevInfo = (struct ar6k_hci_bridge_info *)pContext;
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_BRIDGE, ("HCI Bridge: transport removed. \n"));
A_ASSERT(pHcidevInfo->pHCIDev != NULL);
HCI_TransportDetach(pHcidevInfo->pHCIDev);
bt_cleanup_hci(pHcidevInfo);
pHcidevInfo->pHCIDev = NULL;
}
static void ar6000_hci_send_complete(void *pContext, struct htc_packet *pPacket)
{
struct ar6k_hci_bridge_info *pHcidevInfo = (struct ar6k_hci_bridge_info *)pContext;
void *osbuf = pPacket->pPktContext;
A_ASSERT(osbuf != NULL);
A_ASSERT(pHcidevInfo != NULL);
if (pPacket->Status) {
if ((pPacket->Status != A_ECANCELED) && (pPacket->Status != A_NO_RESOURCE)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HCI Bridge: Send Packet Failed: %d \n",pPacket->Status));
}
}
FreeHTCStruct(pHcidevInfo,pPacket);
FreeBtOsBuf(pHcidevInfo,osbuf);
}
static void ar6000_hci_pkt_recv(void *pContext, struct htc_packet *pPacket)
{
struct ar6k_hci_bridge_info *pHcidevInfo = (struct ar6k_hci_bridge_info *)pContext;
struct sk_buff *skb;
A_ASSERT(pHcidevInfo != NULL);
skb = (struct sk_buff *)pPacket->pPktContext;
A_ASSERT(skb != NULL);
do {
if (pPacket->Status) {
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_RECV,
("HCI Bridge, packet received type : %d len:%d \n",
HCI_GET_PACKET_TYPE(pPacket),pPacket->ActualLength));
A_NETBUF_PUT(skb,pPacket->ActualLength + pHcidevInfo->HCIProps.HeadRoom);
A_NETBUF_PULL(skb,pHcidevInfo->HCIProps.HeadRoom);
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_HCI_DUMP)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,("<<< Recv HCI %s packet len:%d \n",
(HCI_GET_PACKET_TYPE(pPacket) == HCI_EVENT_TYPE) ? "EVENT" : "ACL",
skb->len));
AR_DEBUG_PRINTBUF(skb->data, skb->len,"BT HCI RECV Packet Dump");
}
if (pHcidevInfo->HciNormalMode) {
if (bt_indicate_recv(pHcidevInfo,HCI_GET_PACKET_TYPE(pPacket),skb)) {
skb = NULL;
}
break;
}
#ifdef EXPORT_HCI_BRIDGE_INTERFACE
skb->dev = (struct net_device *)(pHcidevInfo->HCITransHdl.netDevice);
if ((((struct net_device *)pHcidevInfo->HCITransHdl.netDevice)->flags & IFF_UP) == IFF_UP) {
skb->protocol = eth_type_trans(skb, (struct net_device *)(pHcidevInfo->HCITransHdl.netDevice));
#else
skb->dev = pHcidevInfo->ar->arNetDev;
if ((pHcidevInfo->ar->arNetDev->flags & IFF_UP) == IFF_UP) {
skb->protocol = eth_type_trans(skb, pHcidevInfo->ar->arNetDev);
#endif
netif_rx(skb);
skb = NULL;
}
} while (false);
FreeHTCStruct(pHcidevInfo,pPacket);
if (skb != NULL) {
FreeBtOsBuf(pHcidevInfo,skb);
}
}
static void ar6000_hci_pkt_refill(void *pContext, HCI_TRANSPORT_PACKET_TYPE Type, int BuffersAvailable)
{
struct ar6k_hci_bridge_info *pHcidevInfo = (struct ar6k_hci_bridge_info *)pContext;
int refillCount;
if (Type == HCI_ACL_TYPE) {
refillCount = MAX_ACL_RECV_BUFS - BuffersAvailable;
} else {
refillCount = MAX_EVT_RECV_BUFS - BuffersAvailable;
}
if (refillCount > 0) {
RefillRecvBuffers(pHcidevInfo,Type,refillCount);
}
}
static HCI_SEND_FULL_ACTION ar6000_hci_pkt_send_full(void *pContext, struct htc_packet *pPacket
void ar6000_set_default_ar3kconfig(struct ar6_softc *ar, void *ar3kconfig)
{
struct ar6k_hci_bridge_info *pHcidevInfo = (struct ar6k_hci_bridge_info *)ar->hcidev_info;
struct ar3k_config_info *config = (struct ar3k_config_info *)ar3kconfig;
config->pHCIDev = pHcidevInfo->pHCIDev;
config->pHCIProps = &pHcidevInfo->HCIProps;
config->pHIFDevice = ar->arHifDevice;
config->pBtStackHCIDev = pHcidevInfo->pBtStackHCIDev;
config->Flags |= AR3K_CONFIG_FLAG_SET_AR3K_BAUD;
config->AR3KBaudRate = 115200;
}
static int bt_open(struct hci_dev *hdev)
{
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HCI Bridge: bt_open - enter - x\n"));
set_bit(HCI_RUNNING, &hdev->flags);
set_bit(HCI_UP, &hdev->flags);
set_bit(HCI_INIT, &hdev->flags);
return 0;
}
static int bt_close(struct hci_dev *hdev)
{
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HCI Bridge: bt_close - enter\n"));
clear_bit(HCI_RUNNING, &hdev->flags);
return 0;
}
static int bt_send_frame(struct sk_buff *skb)
{
struct hci_dev *hdev = (struct hci_dev *)skb->dev;
HCI_TRANSPORT_PACKET_TYPE type;
struct ar6k_hci_bridge_info *pHcidevInfo;
struct htc_packet *pPacket;
int status = 0;
struct sk_buff *txSkb = NULL;
if (!hdev) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, ("HCI Bridge: bt_send_frame - no device\n"));
return -ENODEV;
}
if (!test_bit(HCI_RUNNING, &hdev->flags)) {
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HCI Bridge: bt_send_frame - not open\n"));
return -EBUSY;
}
pHcidevInfo = (struct ar6k_hci_bridge_info *)hdev->driver_data;
A_ASSERT(pHcidevInfo != NULL);
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_SEND, ("+bt_send_frame type: %d \n",bt_cb(skb)->pkt_type));
type = HCI_COMMAND_TYPE;
switch (bt_cb(skb)->pkt_type) {
case HCI_COMMAND_PKT:
type = HCI_COMMAND_TYPE;
hdev->stat.cmd_tx++;
break;
case HCI_ACLDATA_PKT:
type = HCI_ACL_TYPE;
hdev->stat.acl_tx++;
break;
case HCI_SCODATA_PKT:
kfree_skb(skb);
return 0;
default:
A_ASSERT(false);
kfree_skb(skb);
return 0;
}
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_HCI_DUMP)) {
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,(">>> Send HCI %s packet len: %d\n",
(type == HCI_COMMAND_TYPE) ? "COMMAND" : "ACL",
skb->len));
if (type == HCI_COMMAND_TYPE) {
u16 opcode = HCI_GET_OP_CODE(skb->data);
AR_DEBUG_PRINTF(ATH_DEBUG_ANY,(" HCI Command: OGF:0x%X OCF:0x%X \r\n",
opcode >> 10, opcode & 0x3FF));
}
AR_DEBUG_PRINTBUF(skb->data,skb->len,"BT HCI SEND Packet Dump");
}
do {
txSkb = bt_skb_alloc(TX_PACKET_RSV_OFFSET + pHcidevInfo->HCIProps.HeadRoom +
pHcidevInfo->HCIProps.TailRoom + skb->len,
GFP_ATOMIC);
if (txSkb == NULL) {
status = A_NO_MEMORY;
break;
}
bt_cb(txSkb)->pkt_type = bt_cb(skb)->pkt_type;
txSkb->dev = (void *)pHcidevInfo->pBtStackHCIDev;
skb_reserve(txSkb, TX_PACKET_RSV_OFFSET + pHcidevInfo->HCIProps.HeadRoom);
memcpy(txSkb->data, skb->data, skb->len);
skb_put(txSkb,skb->len);
pPacket = AllocHTCStruct(pHcidevInfo);
if (NULL == pPacket) {
status = A_NO_MEMORY;
break;
}
SET_HTC_PACKET_INFO_TX(pPacket,
txSkb,
txSkb->data,
txSkb->len,
type,
AR6K_CONTROL_PKT_TAG);
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_SEND, ("HCI Bridge: bt_send_frame skb:0x%lX \n",(unsigned long)txSkb));
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_SEND, ("HCI Bridge: type:%d, Total Length:%d Bytes \n",
type, txSkb->len));
status = HCI_TransportSendPkt(pHcidevInfo->pHCIDev,pPacket,false);
pPacket = NULL;
txSkb = NULL;
} while (false);
if (txSkb != NULL) {
kfree_skb(txSkb);
}
kfree_skb(skb);
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_SEND, ("-bt_send_frame \n"));
return 0;
}
static int bt_ioctl(struct hci_dev *hdev, unsigned int cmd, unsigned long arg)
{
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HCI Bridge: bt_ioctl - enter\n"));
return -ENOIOCTLCMD;
}
static int bt_flush(struct hci_dev *hdev)
{
struct ar6k_hci_bridge_info *pHcidevInfo;
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HCI Bridge: bt_flush - enter\n"));
pHcidevInfo = (struct ar6k_hci_bridge_info *)hdev->driver_data;
return 0;
}
static void bt_destruct(struct hci_dev *hdev)
{
AR_DEBUG_PRINTF(ATH_DEBUG_TRC, ("HCI Bridge: bt_destruct - enter\n"));
}
static int bt_setup_hci(struct ar6k_hci_bridge_info *pHcidevInfo)
{
int status = 0;
struct hci_dev *pHciDev = NULL;
struct hif_device_os_device_info osDevInfo;
if (!setupbtdev) {
return 0;
}
do {
A_MEMZERO(&osDevInfo,sizeof(osDevInfo));
#ifdef EXPORT_HCI_BRIDGE_INTERFACE
status = ar6000_get_hif_dev((struct hif_device *)(pHcidevInfo->HCITransHdl.hifDevice),
&osDevInfo);
#else
status = HIFConfigureDevice(pHcidevInfo->ar->arHifDevice,
HIF_DEVICE_GET_OS_DEVICE,
&osDevInfo,
sizeof(osDevInfo));
#endif
if (status) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Failed to OS device info from HIF\n"));
break;
}
pHciDev = hci_alloc_dev();
if (NULL == pHciDev) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HCI Bridge - failed to allocate bt struct \n"));
status = A_NO_MEMORY;
break;
}
pHcidevInfo->pBtStackHCIDev = pHciDev;
SET_HCIDEV_DEV(pHciDev,osDevInfo.pOSDevice);
SET_HCI_BUS_TYPE(pHciDev, HCI_VIRTUAL, HCI_BREDR);
pHciDev->driver_data = pHcidevInfo;
pHciDev->open = bt_open;
pHciDev->close = bt_close;
pHciDev->send = bt_send_frame;
pHciDev->ioctl = bt_ioctl;
pHciDev->flush = bt_flush;
pHciDev->destruct = bt_destruct;
pHciDev->owner = THIS_MODULE;
pHcidevInfo->HciNormalMode = true;
} while (false);
if (status) {
bt_cleanup_hci(pHcidevInfo);
}
return status;
}
static void bt_cleanup_hci(struct ar6k_hci_bridge_info *pHcidevInfo)
{
int err;
if (pHcidevInfo->HciRegistered) {
pHcidevInfo->HciRegistered = false;
clear_bit(HCI_RUNNING, &pHcidevInfo->pBtStackHCIDev->flags);
clear_bit(HCI_UP, &pHcidevInfo->pBtStackHCIDev->flags);
clear_bit(HCI_INIT, &pHcidevInfo->pBtStackHCIDev->flags);
A_ASSERT(pHcidevInfo->pBtStackHCIDev != NULL);
if ((err = hci_unregister_dev(pHcidevInfo->pBtStackHCIDev)) < 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HCI Bridge: failed to unregister with bluetooth %d\n",err));
}
}
kfree(pHcidevInfo->pBtStackHCIDev);
pHcidevInfo->pBtStackHCIDev = NULL;
}
static int bt_register_hci(struct ar6k_hci_bridge_info *pHcidevInfo)
{
int err;
int status = 0;
do {
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_BRIDGE, ("HCI Bridge: registering HCI... \n"));
A_ASSERT(pHcidevInfo->pBtStackHCIDev != NULL);
pHcidevInfo->HciRegistered = true;
if ((err = hci_register_dev(pHcidevInfo->pBtStackHCIDev)) < 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HCI Bridge: failed to register with bluetooth %d\n",err));
pHcidevInfo->HciRegistered = false;
status = A_ERROR;
break;
}
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_BRIDGE, ("HCI Bridge: HCI registered \n"));
} while (false);
return status;
}
static bool bt_indicate_recv(struct ar6k_hci_bridge_info *pHcidevInfo,
HCI_TRANSPORT_PACKET_TYPE Type,
struct sk_buff *skb)
{
u8 btType;
int len;
bool success = false;
BT_HCI_EVENT_HEADER *pEvent;
do {
if (!test_bit(HCI_RUNNING, &pHcidevInfo->pBtStackHCIDev->flags)) {
AR_DEBUG_PRINTF(ATH_DEBUG_WARN, ("HCI Bridge: bt_indicate_recv - not running\n"));
break;
}
switch (Type) {
case HCI_ACL_TYPE:
btType = HCI_ACLDATA_PKT;
break;
case HCI_EVENT_TYPE:
btType = HCI_EVENT_PKT;
break;
default:
btType = 0;
A_ASSERT(false);
break;
}
if (0 == btType) {
break;
}
bt_cb(skb)->pkt_type = btType;
skb->dev = (void *)pHcidevInfo->pBtStackHCIDev;
len = skb->len;
if (AR_DEBUG_LVL_CHECK(ATH_DEBUG_HCI_RECV)) {
if (bt_cb(skb)->pkt_type == HCI_EVENT_PKT) {
pEvent = (BT_HCI_EVENT_HEADER *)skb->data;
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_RECV, ("BT HCI EventCode: %d, len:%d \n",
pEvent->EventCode, pEvent->ParamLength));
}
}
if (hci_recv_frame(skb) != 0) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR, ("HCI Bridge: hci_recv_frame failed \n"));
break;
} else {
AR_DEBUG_PRINTF(ATH_DEBUG_HCI_RECV,
("HCI Bridge: Indicated RCV of type:%d, Length:%d \n",btType,len));
}
success = true;
} while (false);
return success;
}
static struct sk_buff* bt_alloc_buffer(struct ar6k_hci_bridge_info *pHcidevInfo, int Length)
{
struct sk_buff *skb;
skb = bt_skb_alloc(Length, GFP_ATOMIC);
if (NULL == skb) {
AR_DEBUG_PRINTF(ATH_DEBUG_ERR,("Failed to alloc bt sk_buff \n"));
}
return skb;
}
static void bt_free_buffer(struct ar6k_hci_bridge_info *pHcidevInfo, struct sk_buff *skb)
{
kfree_skb(skb);
}
static int bt_setup_hci(struct ar6k_hci_bridge_info *pHcidevInfo)
{
return 0;
}
static void bt_cleanup_hci(struct ar6k_hci_bridge_info *pHcidevInfo)
{
}
static int bt_register_hci(struct ar6k_hci_bridge_info *pHcidevInfo)
{
A_ASSERT(false);
return A_ERROR;
}
static bool bt_indicate_recv(struct ar6k_hci_bridge_info *pHcidevInfo,
HCI_TRANSPORT_PACKET_TYPE Type,
struct sk_buff *skb)
{
A_ASSERT(false);
return false;
}
static struct sk_buff* bt_alloc_buffer(struct ar6k_hci_bridge_info *pHcidevInfo, int Length)
{
A_ASSERT(false);
return NULL;
}
static void bt_free_buffer(struct ar6k_hci_bridge_info *pHcidevInfo, struct sk_buff *skb)
{
A_ASSERT(false);
}
void ar6000_set_default_ar3kconfig(struct ar6_softc *ar, void *ar3kconfig)
{
return;
}
static int __init
hcibridge_init_module(void)
{
int status;
struct hci_transport_callbacks hciTransCallbacks;
hciTransCallbacks.setupTransport = ar6000_setup_hci;
hciTransCallbacks.cleanupTransport = ar6000_cleanup_hci;
status = ar6000_register_hci_transport(&hciTransCallbacks);
if (status)
return -ENODEV;
return 0;
}
static void __exit
hcibridge_cleanup_module(void)
{
}
