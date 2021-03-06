INT SendControlPacket(PMINI_ADAPTER Adapter, char *pControlPacket)
{
PLEADER PLeader = (PLEADER)pControlPacket;
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_CONTROL, DBG_LVL_ALL, "Tx");
if(!pControlPacket || !Adapter)
{
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_CONTROL, DBG_LVL_ALL, "Got NULL Control Packet or Adapter");
return STATUS_FAILURE;
}
if((atomic_read( &Adapter->CurrNumFreeTxDesc ) <
((PLeader->PLength-1)/MAX_DEVICE_DESC_SIZE)+1))
{
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_CONTROL, DBG_LVL_ALL, "NO FREE DESCRIPTORS TO SEND CONTROL PACKET");
return STATUS_FAILURE;
}
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_CONTROL, DBG_LVL_ALL, "Leader Status: %x", PLeader->Status);
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_CONTROL, DBG_LVL_ALL, "Leader VCID: %x",PLeader->Vcid);
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_CONTROL, DBG_LVL_ALL, "Leader Length: %x",PLeader->PLength);
if(Adapter->device_removed)
return 0;
if (netif_msg_pktdata(Adapter))
print_hex_dump(KERN_DEBUG, PFX "tx control: ", DUMP_PREFIX_NONE,
16, 1, pControlPacket, PLeader->PLength + LEADER_SIZE, 0);
Adapter->interface_transmit(Adapter->pvInterfaceAdapter,
pControlPacket, (PLeader->PLength + LEADER_SIZE));
atomic_dec(&Adapter->CurrNumFreeTxDesc);
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_CONTROL, DBG_LVL_ALL, "<=========");
return STATUS_SUCCESS;
}
INT SetupNextSend(PMINI_ADAPTER Adapter, struct sk_buff *Packet, USHORT Vcid)
{
int status=0;
BOOLEAN bHeaderSupressionEnabled = FALSE;
B_UINT16 uiClassifierRuleID;
u16 QueueIndex = skb_get_queue_mapping(Packet);
LEADER Leader={0};
if(Packet->len > MAX_DEVICE_DESC_SIZE)
{
status = STATUS_FAILURE;
goto errExit;
}
uiClassifierRuleID = *((UINT32*) (Packet->cb)+SKB_CB_CLASSIFICATION_OFFSET);
bHeaderSupressionEnabled = Adapter->PackInfo[QueueIndex].bHeaderSuppressionEnabled
& Adapter->bPHSEnabled;
if(Adapter->device_removed)
{
status = STATUS_FAILURE;
goto errExit;
}
status = PHSTransmit(Adapter, &Packet, Vcid, uiClassifierRuleID, bHeaderSupressionEnabled,
(UINT *)&Packet->len, Adapter->PackInfo[QueueIndex].bEthCSSupport);
if(status != STATUS_SUCCESS)
{
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, NEXT_SEND, DBG_LVL_ALL, "PHS Transmit failed..\n");
goto errExit;
}
Leader.Vcid = Vcid;
if(TCP_ACK == *((UINT32*) (Packet->cb) + SKB_CB_TCPACK_OFFSET ))
Leader.Status = LEADER_STATUS_TCP_ACK;
else
Leader.Status = LEADER_STATUS;
if(Adapter->PackInfo[QueueIndex].bEthCSSupport)
{
Leader.PLength = Packet->len;
if(skb_headroom(Packet) < LEADER_SIZE)
{
if((status = skb_cow(Packet,LEADER_SIZE)))
{
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, NEXT_SEND, DBG_LVL_ALL,"bcm_transmit : Failed To Increase headRoom\n");
goto errExit;
}
}
skb_push(Packet, LEADER_SIZE);
memcpy(Packet->data, &Leader, LEADER_SIZE);
}
else
{
Leader.PLength = Packet->len - ETH_HLEN;
memcpy((LEADER*)skb_pull(Packet, (ETH_HLEN - LEADER_SIZE)), &Leader, LEADER_SIZE);
}
status = Adapter->interface_transmit(Adapter->pvInterfaceAdapter,
Packet->data, (Leader.PLength + LEADER_SIZE));
if(status)
{
++Adapter->dev->stats.tx_errors;
if (netif_msg_tx_err(Adapter))
pr_info(PFX "%s: transmit error %d\n", Adapter->dev->name,
status);
}
else
{
struct net_device_stats *netstats = &Adapter->dev->stats;
Adapter->PackInfo[QueueIndex].uiTotalTxBytes += Leader.PLength;
netstats->tx_bytes += Leader.PLength;
++netstats->tx_packets;
Adapter->PackInfo[QueueIndex].uiCurrentTokenCount -= Leader.PLength << 3;
Adapter->PackInfo[QueueIndex].uiSentBytes += (Packet->len);
Adapter->PackInfo[QueueIndex].uiSentPackets++;
Adapter->PackInfo[QueueIndex].NumOfPacketsSent++;
atomic_dec(&Adapter->PackInfo[QueueIndex].uiPerSFTxResourceCount);
Adapter->PackInfo[QueueIndex].uiThisPeriodSentBytes += Leader.PLength;
}
atomic_dec(&Adapter->CurrNumFreeTxDesc);
errExit:
dev_kfree_skb(Packet);
return status;
}
static int tx_pending(PMINI_ADAPTER Adapter)
{
return (atomic_read(&Adapter->TxPktAvail)
&& MINIMUM_PENDING_DESCRIPTORS < atomic_read(&Adapter->CurrNumFreeTxDesc))
|| Adapter->device_removed || (1 == Adapter->downloadDDR);
}
int tx_pkt_handler(PMINI_ADAPTER Adapter
)
{
int status = 0;
while(! kthread_should_stop()) {
if(Adapter->LinkUpStatus)
wait_event_timeout(Adapter->tx_packet_wait_queue,
tx_pending(Adapter), msecs_to_jiffies(10));
else
wait_event_interruptible(Adapter->tx_packet_wait_queue,
tx_pending(Adapter));
if (Adapter->device_removed)
break;
if(Adapter->downloadDDR == 1)
{
Adapter->downloadDDR +=1;
status = download_ddr_settings(Adapter);
if(status)
pr_err(PFX "DDR DOWNLOAD FAILED! %d\n", status);
continue;
}
if(Adapter->bEndPointHalted == TRUE)
{
Bcm_clear_halt_of_endpoints(Adapter);
Adapter->bEndPointHalted = FALSE;
StartInterruptUrb((PS_INTERFACE_ADAPTER)(Adapter->pvInterfaceAdapter));
}
if(Adapter->LinkUpStatus && !Adapter->IdleMode)
{
if(atomic_read(&Adapter->TotalPacketCount))
{
update_per_sf_desc_cnts(Adapter);
}
}
if( atomic_read(&Adapter->CurrNumFreeTxDesc) &&
Adapter->LinkStatus == SYNC_UP_REQUEST &&
!Adapter->bSyncUpRequestSent)
{
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_PACKETS, DBG_LVL_ALL, "Calling LinkMessage");
LinkMessage(Adapter);
}
if((Adapter->IdleMode || Adapter->bShutStatus) && atomic_read(&Adapter->TotalPacketCount))
{
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_PACKETS, DBG_LVL_ALL, "Device in Low Power mode...waking up");
Adapter->usIdleModePattern = ABORT_IDLE_MODE;
Adapter->bWakeUpDevice = TRUE;
wake_up(&Adapter->process_rx_cntrlpkt);
}
transmit_packets(Adapter);
atomic_set(&Adapter->TxPktAvail, 0);
}
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_TX, TX_PACKETS, DBG_LVL_ALL, "Exiting the tx thread..\n");
Adapter->transmit_packet_thread = NULL;
return 0;
}
