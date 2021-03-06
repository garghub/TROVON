static VOID handle_rx_control_packet(struct bcm_mini_adapter *Adapter,
struct sk_buff *skb)
{
struct bcm_tarang_data *pTarang = NULL;
bool HighPriorityMessage = false;
struct sk_buff *newPacket = NULL;
CHAR cntrl_msg_mask_bit = 0;
bool drop_pkt_flag = TRUE;
USHORT usStatus = *(PUSHORT)(skb->data);
if (netif_msg_pktdata(Adapter))
print_hex_dump(KERN_DEBUG, PFX "rx control: ", DUMP_PREFIX_NONE,
16, 1, skb->data, skb->len, 0);
switch (usStatus) {
case CM_RESPONSES:
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, CP_CTRL_PKT,
DBG_LVL_ALL,
"MAC Version Seems to be Non Multi-Classifier, rejected by Driver");
HighPriorityMessage = TRUE;
break;
case CM_CONTROL_NEWDSX_MULTICLASSIFIER_RESP:
HighPriorityMessage = TRUE;
if (Adapter->LinkStatus == LINKUP_DONE)
CmControlResponseMessage(Adapter,
(skb->data + sizeof(USHORT)));
break;
case LINK_CONTROL_RESP:
case STATUS_RSP:
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, CP_CTRL_PKT,
DBG_LVL_ALL, "LINK_CONTROL_RESP");
HighPriorityMessage = TRUE;
LinkControlResponseMessage(Adapter,
(skb->data + sizeof(USHORT)));
break;
case STATS_POINTER_RESP:
HighPriorityMessage = TRUE;
StatisticsResponse(Adapter, (skb->data + sizeof(USHORT)));
break;
case IDLE_MODE_STATUS:
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, CP_CTRL_PKT,
DBG_LVL_ALL,
"IDLE_MODE_STATUS Type Message Got from F/W");
InterfaceIdleModeRespond(Adapter, (PUINT)(skb->data +
sizeof(USHORT)));
HighPriorityMessage = TRUE;
break;
case AUTH_SS_HOST_MSG:
HighPriorityMessage = TRUE;
break;
default:
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, CP_CTRL_PKT,
DBG_LVL_ALL, "Got Default Response");
break;
}
down(&Adapter->RxAppControlQueuelock);
for (pTarang = Adapter->pTarangs; pTarang; pTarang = pTarang->next) {
if (Adapter->device_removed)
break;
drop_pkt_flag = TRUE;
cntrl_msg_mask_bit = (usStatus & 0x1F);
if (pTarang->RxCntrlMsgBitMask & (1 << cntrl_msg_mask_bit))
drop_pkt_flag = false;
if ((drop_pkt_flag == TRUE) ||
(pTarang->AppCtrlQueueLen > MAX_APP_QUEUE_LEN)
|| ((pTarang->AppCtrlQueueLen >
MAX_APP_QUEUE_LEN / 2) &&
(HighPriorityMessage == false))) {
struct bcm_mibs_dropped_cntrl_msg *msg =
&pTarang->stDroppedAppCntrlMsgs;
switch (*(PUSHORT)skb->data) {
case CM_RESPONSES:
msg->cm_responses++;
break;
case CM_CONTROL_NEWDSX_MULTICLASSIFIER_RESP:
msg->cm_control_newdsx_multiclassifier_resp++;
break;
case LINK_CONTROL_RESP:
msg->link_control_resp++;
break;
case STATUS_RSP:
msg->status_rsp++;
break;
case STATS_POINTER_RESP:
msg->stats_pointer_resp++;
break;
case IDLE_MODE_STATUS:
msg->idle_mode_status++;
break;
case AUTH_SS_HOST_MSG:
msg->auth_ss_host_msg++;
break;
default:
msg->low_priority_message++;
break;
}
continue;
}
newPacket = skb_clone(skb, GFP_KERNEL);
if (!newPacket)
break;
ENQUEUEPACKET(pTarang->RxAppControlHead,
pTarang->RxAppControlTail, newPacket);
pTarang->AppCtrlQueueLen++;
}
up(&Adapter->RxAppControlQueuelock);
wake_up(&Adapter->process_read_wait_queue);
dev_kfree_skb(skb);
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, CP_CTRL_PKT, DBG_LVL_ALL,
"After wake_up_interruptible");
}
int control_packet_handler(struct bcm_mini_adapter *Adapter )
{
struct sk_buff *ctrl_packet = NULL;
unsigned long flags = 0;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, CP_CTRL_PKT, DBG_LVL_ALL,
"Entering to make thread wait on control packet event!");
while (1) {
wait_event_interruptible(Adapter->process_rx_cntrlpkt,
atomic_read(&Adapter->cntrlpktCnt) ||
Adapter->bWakeUpDevice ||
kthread_should_stop());
if (kthread_should_stop()) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS, CP_CTRL_PKT,
DBG_LVL_ALL, "Exiting\n");
return 0;
}
if (TRUE == Adapter->bWakeUpDevice) {
Adapter->bWakeUpDevice = false;
if ((false == Adapter->bTriedToWakeUpFromlowPowerMode)
&& ((TRUE == Adapter->IdleMode) ||
(TRUE == Adapter->bShutStatus))) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
CP_CTRL_PKT, DBG_LVL_ALL,
"Calling InterfaceAbortIdlemode\n");
InterfaceIdleModeWakeup(Adapter);
}
continue;
}
while (atomic_read(&Adapter->cntrlpktCnt)) {
spin_lock_irqsave(&Adapter->control_queue_lock, flags);
ctrl_packet = Adapter->RxControlHead;
if (ctrl_packet) {
DEQUEUEPACKET(Adapter->RxControlHead,
Adapter->RxControlTail);
}
spin_unlock_irqrestore(&Adapter->control_queue_lock,
flags);
handle_rx_control_packet(Adapter, ctrl_packet);
atomic_dec(&Adapter->cntrlpktCnt);
}
SetUpTargetDsxBuffers(Adapter);
}
return STATUS_SUCCESS;
}
INT flushAllAppQ(void)
{
struct bcm_mini_adapter *Adapter = GET_BCM_ADAPTER(gblpnetdev);
struct bcm_tarang_data *pTarang = NULL;
struct sk_buff *PacketToDrop = NULL;
for (pTarang = Adapter->pTarangs; pTarang; pTarang = pTarang->next) {
while (pTarang->RxAppControlHead != NULL) {
PacketToDrop = pTarang->RxAppControlHead;
DEQUEUEPACKET(pTarang->RxAppControlHead,
pTarang->RxAppControlTail);
dev_kfree_skb(PacketToDrop);
}
pTarang->AppCtrlQueueLen = 0;
memset((PVOID)&pTarang->stDroppedAppCntrlMsgs, 0,
sizeof(struct bcm_mibs_dropped_cntrl_msg));
}
return STATUS_SUCCESS;
}
