bool cmpk_message_handle_tx(
struct net_device *dev,
u8 *code_virtual_address,
u32 packettype,
u32 buffer_len)
{
bool rt_status = true;
struct r8192_priv *priv = rtllib_priv(dev);
u16 frag_threshold;
u16 frag_length = 0, frag_offset = 0;
struct rt_firmware *pfirmware = priv->pFirmware;
struct sk_buff *skb;
unsigned char *seg_ptr;
struct cb_desc *tcb_desc;
u8 bLastIniPkt;
struct tx_fwinfo_8190pci *pTxFwInfo = NULL;
RT_TRACE(COMP_CMDPKT, "%s(),buffer_len is %d\n", __func__, buffer_len);
firmware_init_param(dev);
frag_threshold = pfirmware->cmdpacket_frag_thresold;
do {
if ((buffer_len - frag_offset) > frag_threshold) {
frag_length = frag_threshold;
bLastIniPkt = 0;
} else {
frag_length = (u16)(buffer_len - frag_offset);
bLastIniPkt = 1;
}
skb = dev_alloc_skb(frag_length +
priv->rtllib->tx_headroom + 4);
if (skb == NULL) {
rt_status = false;
goto Failed;
}
memcpy((unsigned char *)(skb->cb), &dev, sizeof(dev));
tcb_desc = (struct cb_desc *)(skb->cb + MAX_DEV_ADDR_SIZE);
tcb_desc->queue_index = TXCMD_QUEUE;
tcb_desc->bCmdOrInit = DESC_PACKET_TYPE_NORMAL;
tcb_desc->bLastIniPkt = bLastIniPkt;
tcb_desc->pkt_size = frag_length;
seg_ptr = skb_put(skb, priv->rtllib->tx_headroom);
pTxFwInfo = (struct tx_fwinfo_8190pci *)seg_ptr;
memset(pTxFwInfo, 0, sizeof(struct tx_fwinfo_8190pci));
memset(pTxFwInfo, 0x12, 8);
seg_ptr = skb_put(skb, frag_length);
memcpy(seg_ptr, code_virtual_address, (u32)frag_length);
priv->rtllib->softmac_hard_start_xmit(skb, dev);
code_virtual_address += frag_length;
frag_offset += frag_length;
} while (frag_offset < buffer_len);
write_nic_byte(dev, TPPoll, TPPoll_CQ);
Failed:
return rt_status;
}
