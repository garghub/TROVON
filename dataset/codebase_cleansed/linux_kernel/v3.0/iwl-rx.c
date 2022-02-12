int iwl_legacy_rx_queue_space(const struct iwl_rx_queue *q)
{
int s = q->read - q->write;
if (s <= 0)
s += RX_QUEUE_SIZE;
s -= 2;
if (s < 0)
s = 0;
return s;
}
void
iwl_legacy_rx_queue_update_write_ptr(struct iwl_priv *priv,
struct iwl_rx_queue *q)
{
unsigned long flags;
u32 rx_wrt_ptr_reg = priv->hw_params.rx_wrt_ptr_reg;
u32 reg;
spin_lock_irqsave(&q->lock, flags);
if (q->need_update == 0)
goto exit_unlock;
if (test_bit(STATUS_POWER_PMI, &priv->status)) {
reg = iwl_read32(priv, CSR_UCODE_DRV_GP1);
if (reg & CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP) {
IWL_DEBUG_INFO(priv,
"Rx queue requesting wakeup,"
" GP1 = 0x%x\n", reg);
iwl_legacy_set_bit(priv, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
goto exit_unlock;
}
q->write_actual = (q->write & ~0x7);
iwl_legacy_write_direct32(priv, rx_wrt_ptr_reg,
q->write_actual);
} else {
q->write_actual = (q->write & ~0x7);
iwl_legacy_write_direct32(priv, rx_wrt_ptr_reg,
q->write_actual);
}
q->need_update = 0;
exit_unlock:
spin_unlock_irqrestore(&q->lock, flags);
}
int iwl_legacy_rx_queue_alloc(struct iwl_priv *priv)
{
struct iwl_rx_queue *rxq = &priv->rxq;
struct device *dev = &priv->pci_dev->dev;
int i;
spin_lock_init(&rxq->lock);
INIT_LIST_HEAD(&rxq->rx_free);
INIT_LIST_HEAD(&rxq->rx_used);
rxq->bd = dma_alloc_coherent(dev, 4 * RX_QUEUE_SIZE, &rxq->bd_dma,
GFP_KERNEL);
if (!rxq->bd)
goto err_bd;
rxq->rb_stts = dma_alloc_coherent(dev, sizeof(struct iwl_rb_status),
&rxq->rb_stts_dma, GFP_KERNEL);
if (!rxq->rb_stts)
goto err_rb;
for (i = 0; i < RX_FREE_BUFFERS + RX_QUEUE_SIZE; i++)
list_add_tail(&rxq->pool[i].list, &rxq->rx_used);
rxq->read = rxq->write = 0;
rxq->write_actual = 0;
rxq->free_count = 0;
rxq->need_update = 0;
return 0;
err_rb:
dma_free_coherent(&priv->pci_dev->dev, 4 * RX_QUEUE_SIZE, rxq->bd,
rxq->bd_dma);
err_bd:
return -ENOMEM;
}
void iwl_legacy_rx_spectrum_measure_notif(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_spectrum_notification *report = &(pkt->u.spectrum_notif);
if (!report->state) {
IWL_DEBUG_11H(priv,
"Spectrum Measure Notification: Start\n");
return;
}
memcpy(&priv->measure_report, report, sizeof(*report));
priv->measurement_status |= MEASUREMENT_READY;
}
void iwl_legacy_recover_from_statistics(struct iwl_priv *priv,
struct iwl_rx_packet *pkt)
{
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (iwl_legacy_is_any_associated(priv)) {
if (priv->cfg->ops->lib->check_plcp_health) {
if (!priv->cfg->ops->lib->check_plcp_health(
priv, pkt)) {
iwl_legacy_force_reset(priv,
IWL_RF_RESET, false);
}
}
}
}
int iwl_legacy_set_decrypted_flag(struct iwl_priv *priv,
struct ieee80211_hdr *hdr,
u32 decrypt_res,
struct ieee80211_rx_status *stats)
{
u16 fc = le16_to_cpu(hdr->frame_control);
if (priv->contexts[IWL_RXON_CTX_BSS].active.filter_flags &
RXON_FILTER_DIS_DECRYPT_MSK)
return 0;
if (!(fc & IEEE80211_FCTL_PROTECTED))
return 0;
IWL_DEBUG_RX(priv, "decrypt_res:0x%x\n", decrypt_res);
switch (decrypt_res & RX_RES_STATUS_SEC_TYPE_MSK) {
case RX_RES_STATUS_SEC_TYPE_TKIP:
if ((decrypt_res & RX_RES_STATUS_DECRYPT_TYPE_MSK) ==
RX_RES_STATUS_BAD_KEY_TTAK)
break;
case RX_RES_STATUS_SEC_TYPE_WEP:
if ((decrypt_res & RX_RES_STATUS_DECRYPT_TYPE_MSK) ==
RX_RES_STATUS_BAD_ICV_MIC) {
IWL_DEBUG_RX(priv, "Packet destroyed\n");
return -1;
}
case RX_RES_STATUS_SEC_TYPE_CCMP:
if ((decrypt_res & RX_RES_STATUS_DECRYPT_TYPE_MSK) ==
RX_RES_STATUS_DECRYPT_OK) {
IWL_DEBUG_RX(priv, "hw decrypt successfully!!!\n");
stats->flag |= RX_FLAG_DECRYPTED;
}
break;
default:
break;
}
return 0;
}
