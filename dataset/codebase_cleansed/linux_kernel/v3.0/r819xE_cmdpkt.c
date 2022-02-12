RT_STATUS cmpk_message_handle_tx(
struct r8192_priv *priv,
u8* code_virtual_address,
u32 packettype,
u32 buffer_len)
{
RT_STATUS rt_status = RT_STATUS_SUCCESS;
u16 frag_threshold;
u16 frag_length = 0, frag_offset = 0;
rt_firmware *pfirmware = priv->pFirmware;
struct sk_buff *skb;
unsigned char *seg_ptr;
cb_desc *tcb_desc;
u8 bLastIniPkt;
PTX_FWINFO_8190PCI pTxFwInfo = NULL;
int i;
RT_TRACE(COMP_CMDPKT,"%s(),buffer_len is %d\n",__FUNCTION__,buffer_len);
firmware_init_param(priv);
frag_threshold = pfirmware->cmdpacket_frag_thresold;
do {
if((buffer_len - frag_offset) > frag_threshold) {
frag_length = frag_threshold ;
bLastIniPkt = 0;
} else {
frag_length =(u16)(buffer_len - frag_offset);
bLastIniPkt = 1;
}
skb = dev_alloc_skb(frag_length + priv->ieee80211->tx_headroom + 4);
if(skb == NULL) {
rt_status = RT_STATUS_FAILURE;
goto Failed;
}
tcb_desc = (cb_desc*)(skb->cb + MAX_DEV_ADDR_SIZE);
tcb_desc->queue_index = TXCMD_QUEUE;
tcb_desc->bCmdOrInit = packettype;
tcb_desc->bLastIniPkt = bLastIniPkt;
tcb_desc->pkt_size = frag_length;
seg_ptr = skb_put(skb, priv->ieee80211->tx_headroom);
pTxFwInfo = (PTX_FWINFO_8190PCI)seg_ptr;
memset(pTxFwInfo,0,sizeof(TX_FWINFO_8190PCI));
memset(pTxFwInfo,0x12,8);
seg_ptr +=sizeof(TX_FWINFO_8190PCI);
seg_ptr = skb_tail_pointer(skb);
for(i=0 ; i < frag_length; i+=4) {
*seg_ptr++ = ((i+0)<frag_length)?code_virtual_address[i+3]:0;
*seg_ptr++ = ((i+1)<frag_length)?code_virtual_address[i+2]:0;
*seg_ptr++ = ((i+2)<frag_length)?code_virtual_address[i+1]:0;
*seg_ptr++ = ((i+3)<frag_length)?code_virtual_address[i+0]:0;
}
skb_put(skb, i);
priv->ieee80211->softmac_hard_start_xmit(skb, priv->ieee80211);
code_virtual_address += frag_length;
frag_offset += frag_length;
}while(frag_offset < buffer_len);
Failed:
return rt_status;
}
static void cmpk_count_txstatistic(struct r8192_priv *priv, cmpk_txfb_t *pstx_fb)
{
#ifdef ENABLE_PS
RT_RF_POWER_STATE rtState;
pAdapter->HalFunc.GetHwRegHandler(pAdapter, HW_VAR_RF_STATE, (pu1Byte)(&rtState));
if (rtState == eRfOff)
{
return;
}
#endif
#ifdef TODO
if(pAdapter->bInHctTest)
return;
#endif
if (pstx_fb->tok)
{
priv->stats.txoktotal++;
if (pstx_fb->pkt_type != PACKET_MULTICAST &&
pstx_fb->pkt_type != PACKET_BROADCAST) {
priv->stats.txbytesunicast += pstx_fb->pkt_length;
}
}
}
static void cmpk_handle_tx_feedback(struct r8192_priv *priv, u8 *pmsg)
{
cmpk_txfb_t rx_tx_fb;
priv->stats.txfeedback++;
memcpy((u8*)&rx_tx_fb, pmsg, sizeof(cmpk_txfb_t));
cmpk_count_txstatistic(priv, &rx_tx_fb);
}
static void cmpk_handle_interrupt_status(struct r8192_priv *priv, u8 *pmsg)
{
cmpk_intr_sta_t rx_intr_status;
DMESG("---> cmpk_Handle_Interrupt_Status()\n");
rx_intr_status.length = pmsg[1];
if (rx_intr_status.length != (sizeof(cmpk_intr_sta_t) - 2))
{
DMESG("cmpk_Handle_Interrupt_Status: wrong length!\n");
return;
}
if( priv->ieee80211->iw_mode == IW_MODE_ADHOC)
{
rx_intr_status.interrupt_status = *((u32 *)(pmsg + 4));
DMESG("interrupt status = 0x%x\n", rx_intr_status.interrupt_status);
if (rx_intr_status.interrupt_status & ISR_TxBcnOk)
{
priv->ieee80211->bibsscoordinator = true;
priv->stats.txbeaconokint++;
}
else if (rx_intr_status.interrupt_status & ISR_TxBcnErr)
{
priv->ieee80211->bibsscoordinator = false;
priv->stats.txbeaconerr++;
}
}
DMESG("<---- cmpk_handle_interrupt_status()\n");
}
static void cmpk_handle_query_config_rx(struct r8192_priv *priv, u8 *pmsg)
{
cmpk_query_cfg_t rx_query_cfg;
rx_query_cfg.cfg_action = (pmsg[4] & 0x80000000)>>31;
rx_query_cfg.cfg_type = (pmsg[4] & 0x60) >> 5;
rx_query_cfg.cfg_size = (pmsg[4] & 0x18) >> 3;
rx_query_cfg.cfg_page = (pmsg[6] & 0x0F) >> 0;
rx_query_cfg.cfg_offset = pmsg[7];
rx_query_cfg.value = (pmsg[8] << 24) | (pmsg[9] << 16) |
(pmsg[10] << 8) | (pmsg[11] << 0);
rx_query_cfg.mask = (pmsg[12] << 24) | (pmsg[13] << 16) |
(pmsg[14] << 8) | (pmsg[15] << 0);
}
static void cmpk_count_tx_status(struct r8192_priv *priv, cmpk_tx_status_t *pstx_status)
{
#ifdef ENABLE_PS
RT_RF_POWER_STATE rtstate;
pAdapter->HalFunc.GetHwRegHandler(pAdapter, HW_VAR_RF_STATE, (pu1Byte)(&rtState));
if (rtState == eRfOff)
{
return;
}
#endif
priv->stats.txfeedbackok += pstx_status->txok;
priv->stats.txoktotal += pstx_status->txok;
priv->stats.txbytesunicast += pstx_status->txuclength;
}
static void cmpk_handle_tx_status(struct r8192_priv *priv, u8 *pmsg)
{
cmpk_tx_status_t rx_tx_sts;
memcpy((void*)&rx_tx_sts, (void*)pmsg, sizeof(cmpk_tx_status_t));
cmpk_count_tx_status(priv, &rx_tx_sts);
}
static void cmpk_handle_tx_rate_history(struct r8192_priv *priv, u8 *pmsg)
{
u8 i;
u16 length = sizeof(cmpk_tx_rahis_t);
u32 *ptemp;
#ifdef ENABLE_PS
pAdapter->HalFunc.GetHwRegHandler(pAdapter, HW_VAR_RF_STATE, (pu1Byte)(&rtState));
if (rtState == eRfOff)
{
return;
}
#endif
ptemp = (u32 *)pmsg;
for (i = 0; i < (length/4); i++)
{
u16 temp1, temp2;
temp1 = ptemp[i]&0x0000FFFF;
temp2 = ptemp[i]>>16;
ptemp[i] = (temp1<<16)|temp2;
}
}
u32 cmpk_message_handle_rx(struct r8192_priv *priv, struct ieee80211_rx_stats *pstats)
{
int total_length;
u8 cmd_length, exe_cnt = 0;
u8 element_id;
u8 *pcmd_buff;
RT_TRACE(COMP_EVENTS, "---->cmpk_message_handle_rx()\n");
if ((pstats== NULL))
{
return 0;
}
total_length = pstats->Length;
pcmd_buff = pstats->virtual_address;
element_id = pcmd_buff[0];
while (total_length > 0 || exe_cnt++ >100)
{
element_id = pcmd_buff[0];
switch(element_id)
{
case RX_TX_FEEDBACK:
RT_TRACE(COMP_EVENTS, "---->cmpk_message_handle_rx():RX_TX_FEEDBACK\n");
cmpk_handle_tx_feedback(priv, pcmd_buff);
cmd_length = CMPK_RX_TX_FB_SIZE;
break;
case RX_INTERRUPT_STATUS:
RT_TRACE(COMP_EVENTS, "---->cmpk_message_handle_rx():RX_INTERRUPT_STATUS\n");
cmpk_handle_interrupt_status(priv, pcmd_buff);
cmd_length = sizeof(cmpk_intr_sta_t);
break;
case BOTH_QUERY_CONFIG:
RT_TRACE(COMP_EVENTS, "---->cmpk_message_handle_rx():BOTH_QUERY_CONFIG\n");
cmpk_handle_query_config_rx(priv, pcmd_buff);
cmd_length = CMPK_BOTH_QUERY_CONFIG_SIZE;
break;
case RX_TX_STATUS:
RT_TRACE(COMP_EVENTS, "---->cmpk_message_handle_rx():RX_TX_STATUS\n");
cmpk_handle_tx_status(priv, pcmd_buff);
cmd_length = CMPK_RX_TX_STS_SIZE;
break;
case RX_TX_PER_PKT_FEEDBACK:
RT_TRACE(COMP_EVENTS, "---->cmpk_message_handle_rx():RX_TX_PER_PKT_FEEDBACK\n");
cmd_length = CMPK_RX_TX_FB_SIZE;
break;
case RX_TX_RATE_HISTORY:
RT_TRACE(COMP_EVENTS, "---->cmpk_message_handle_rx():RX_TX_HISTORY\n");
cmpk_handle_tx_rate_history(priv, pcmd_buff);
cmd_length = CMPK_TX_RAHIS_SIZE;
break;
default:
RT_TRACE(COMP_EVENTS, "---->cmpk_message_handle_rx():unknown CMD Element\n");
return 1;
}
total_length -= cmd_length;
pcmd_buff += cmd_length;
}
return 1;
RT_TRACE(COMP_EVENTS, "<----cmpk_message_handle_rx()\n");
}
