void iwl4965_update_chain_flags(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx;
if (priv->cfg->ops->hcmd->set_rxon_chain) {
for_each_context(priv, ctx) {
priv->cfg->ops->hcmd->set_rxon_chain(priv, ctx);
if (ctx->active.rx_chain != ctx->staging.rx_chain)
iwl_legacy_commit_rxon(priv, ctx);
}
}
}
static void iwl4965_clear_free_frames(struct iwl_priv *priv)
{
struct list_head *element;
IWL_DEBUG_INFO(priv, "%d frames on pre-allocated heap on clear.\n",
priv->frames_count);
while (!list_empty(&priv->free_frames)) {
element = priv->free_frames.next;
list_del(element);
kfree(list_entry(element, struct iwl_frame, list));
priv->frames_count--;
}
if (priv->frames_count) {
IWL_WARN(priv, "%d frames still in use. Did we lose one?\n",
priv->frames_count);
priv->frames_count = 0;
}
}
static struct iwl_frame *iwl4965_get_free_frame(struct iwl_priv *priv)
{
struct iwl_frame *frame;
struct list_head *element;
if (list_empty(&priv->free_frames)) {
frame = kzalloc(sizeof(*frame), GFP_KERNEL);
if (!frame) {
IWL_ERR(priv, "Could not allocate frame!\n");
return NULL;
}
priv->frames_count++;
return frame;
}
element = priv->free_frames.next;
list_del(element);
return list_entry(element, struct iwl_frame, list);
}
static void iwl4965_free_frame(struct iwl_priv *priv, struct iwl_frame *frame)
{
memset(frame, 0, sizeof(*frame));
list_add(&frame->list, &priv->free_frames);
}
static u32 iwl4965_fill_beacon_frame(struct iwl_priv *priv,
struct ieee80211_hdr *hdr,
int left)
{
lockdep_assert_held(&priv->mutex);
if (!priv->beacon_skb)
return 0;
if (priv->beacon_skb->len > left)
return 0;
memcpy(hdr, priv->beacon_skb->data, priv->beacon_skb->len);
return priv->beacon_skb->len;
}
static void iwl4965_set_beacon_tim(struct iwl_priv *priv,
struct iwl_tx_beacon_cmd *tx_beacon_cmd,
u8 *beacon, u32 frame_size)
{
u16 tim_idx;
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)beacon;
tim_idx = mgmt->u.beacon.variable - beacon;
while ((tim_idx < (frame_size - 2)) &&
(beacon[tim_idx] != WLAN_EID_TIM))
tim_idx += beacon[tim_idx+1] + 2;
if ((tim_idx < (frame_size - 1)) && (beacon[tim_idx] == WLAN_EID_TIM)) {
tx_beacon_cmd->tim_idx = cpu_to_le16(tim_idx);
tx_beacon_cmd->tim_size = beacon[tim_idx+1];
} else
IWL_WARN(priv, "Unable to find TIM Element in beacon\n");
}
static unsigned int iwl4965_hw_get_beacon_cmd(struct iwl_priv *priv,
struct iwl_frame *frame)
{
struct iwl_tx_beacon_cmd *tx_beacon_cmd;
u32 frame_size;
u32 rate_flags;
u32 rate;
lockdep_assert_held(&priv->mutex);
if (!priv->beacon_ctx) {
IWL_ERR(priv, "trying to build beacon w/o beacon context!\n");
return 0;
}
tx_beacon_cmd = &frame->u.beacon;
memset(tx_beacon_cmd, 0, sizeof(*tx_beacon_cmd));
frame_size = iwl4965_fill_beacon_frame(priv, tx_beacon_cmd->frame,
sizeof(frame->u) - sizeof(*tx_beacon_cmd));
if (WARN_ON_ONCE(frame_size > MAX_MPDU_SIZE))
return 0;
if (!frame_size)
return 0;
tx_beacon_cmd->tx.len = cpu_to_le16((u16)frame_size);
tx_beacon_cmd->tx.sta_id = priv->beacon_ctx->bcast_sta_id;
tx_beacon_cmd->tx.stop_time.life_time = TX_CMD_LIFE_TIME_INFINITE;
tx_beacon_cmd->tx.tx_flags = TX_CMD_FLG_SEQ_CTL_MSK |
TX_CMD_FLG_TSF_MSK | TX_CMD_FLG_STA_RATE_MSK;
iwl4965_set_beacon_tim(priv, tx_beacon_cmd, (u8 *)tx_beacon_cmd->frame,
frame_size);
rate = iwl_legacy_get_lowest_plcp(priv, priv->beacon_ctx);
priv->mgmt_tx_ant = iwl4965_toggle_tx_ant(priv, priv->mgmt_tx_ant,
priv->hw_params.valid_tx_ant);
rate_flags = iwl4965_ant_idx_to_flags(priv->mgmt_tx_ant);
if ((rate >= IWL_FIRST_CCK_RATE) && (rate <= IWL_LAST_CCK_RATE))
rate_flags |= RATE_MCS_CCK_MSK;
tx_beacon_cmd->tx.rate_n_flags = iwl4965_hw_set_rate_n_flags(rate,
rate_flags);
return sizeof(*tx_beacon_cmd) + frame_size;
}
int iwl4965_send_beacon_cmd(struct iwl_priv *priv)
{
struct iwl_frame *frame;
unsigned int frame_size;
int rc;
frame = iwl4965_get_free_frame(priv);
if (!frame) {
IWL_ERR(priv, "Could not obtain free frame buffer for beacon "
"command.\n");
return -ENOMEM;
}
frame_size = iwl4965_hw_get_beacon_cmd(priv, frame);
if (!frame_size) {
IWL_ERR(priv, "Error configuring the beacon command\n");
iwl4965_free_frame(priv, frame);
return -EINVAL;
}
rc = iwl_legacy_send_cmd_pdu(priv, REPLY_TX_BEACON, frame_size,
&frame->u.cmd[0]);
iwl4965_free_frame(priv, frame);
return rc;
}
static inline dma_addr_t iwl4965_tfd_tb_get_addr(struct iwl_tfd *tfd, u8 idx)
{
struct iwl_tfd_tb *tb = &tfd->tbs[idx];
dma_addr_t addr = get_unaligned_le32(&tb->lo);
if (sizeof(dma_addr_t) > sizeof(u32))
addr |=
((dma_addr_t)(le16_to_cpu(tb->hi_n_len) & 0xF) << 16) << 16;
return addr;
}
static inline u16 iwl4965_tfd_tb_get_len(struct iwl_tfd *tfd, u8 idx)
{
struct iwl_tfd_tb *tb = &tfd->tbs[idx];
return le16_to_cpu(tb->hi_n_len) >> 4;
}
static inline void iwl4965_tfd_set_tb(struct iwl_tfd *tfd, u8 idx,
dma_addr_t addr, u16 len)
{
struct iwl_tfd_tb *tb = &tfd->tbs[idx];
u16 hi_n_len = len << 4;
put_unaligned_le32(addr, &tb->lo);
if (sizeof(dma_addr_t) > sizeof(u32))
hi_n_len |= ((addr >> 16) >> 16) & 0xF;
tb->hi_n_len = cpu_to_le16(hi_n_len);
tfd->num_tbs = idx + 1;
}
static inline u8 iwl4965_tfd_get_num_tbs(struct iwl_tfd *tfd)
{
return tfd->num_tbs & 0x1f;
}
void iwl4965_hw_txq_free_tfd(struct iwl_priv *priv, struct iwl_tx_queue *txq)
{
struct iwl_tfd *tfd_tmp = (struct iwl_tfd *)txq->tfds;
struct iwl_tfd *tfd;
struct pci_dev *dev = priv->pci_dev;
int index = txq->q.read_ptr;
int i;
int num_tbs;
tfd = &tfd_tmp[index];
num_tbs = iwl4965_tfd_get_num_tbs(tfd);
if (num_tbs >= IWL_NUM_OF_TBS) {
IWL_ERR(priv, "Too many chunks: %i\n", num_tbs);
return;
}
if (num_tbs)
pci_unmap_single(dev,
dma_unmap_addr(&txq->meta[index], mapping),
dma_unmap_len(&txq->meta[index], len),
PCI_DMA_BIDIRECTIONAL);
for (i = 1; i < num_tbs; i++)
pci_unmap_single(dev, iwl4965_tfd_tb_get_addr(tfd, i),
iwl4965_tfd_tb_get_len(tfd, i),
PCI_DMA_TODEVICE);
if (txq->txb) {
struct sk_buff *skb;
skb = txq->txb[txq->q.read_ptr].skb;
if (skb) {
dev_kfree_skb_any(skb);
txq->txb[txq->q.read_ptr].skb = NULL;
}
}
}
int iwl4965_hw_txq_attach_buf_to_tfd(struct iwl_priv *priv,
struct iwl_tx_queue *txq,
dma_addr_t addr, u16 len,
u8 reset, u8 pad)
{
struct iwl_queue *q;
struct iwl_tfd *tfd, *tfd_tmp;
u32 num_tbs;
q = &txq->q;
tfd_tmp = (struct iwl_tfd *)txq->tfds;
tfd = &tfd_tmp[q->write_ptr];
if (reset)
memset(tfd, 0, sizeof(*tfd));
num_tbs = iwl4965_tfd_get_num_tbs(tfd);
if (num_tbs >= IWL_NUM_OF_TBS) {
IWL_ERR(priv, "Error can not send more than %d chunks\n",
IWL_NUM_OF_TBS);
return -EINVAL;
}
BUG_ON(addr & ~DMA_BIT_MASK(36));
if (unlikely(addr & ~IWL_TX_DMA_MASK))
IWL_ERR(priv, "Unaligned address = %llx\n",
(unsigned long long)addr);
iwl4965_tfd_set_tb(tfd, num_tbs, addr, len);
return 0;
}
int iwl4965_hw_tx_queue_init(struct iwl_priv *priv,
struct iwl_tx_queue *txq)
{
int txq_id = txq->q.id;
iwl_legacy_write_direct32(priv, FH_MEM_CBBC_QUEUE(txq_id),
txq->q.dma_addr >> 8);
return 0;
}
static void iwl4965_rx_reply_alive(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl_alive_resp *palive;
struct delayed_work *pwork;
palive = &pkt->u.alive_frame;
IWL_DEBUG_INFO(priv, "Alive ucode status 0x%08X revision "
"0x%01X 0x%01X\n",
palive->is_valid, palive->ver_type,
palive->ver_subtype);
if (palive->ver_subtype == INITIALIZE_SUBTYPE) {
IWL_DEBUG_INFO(priv, "Initialization Alive received.\n");
memcpy(&priv->card_alive_init,
&pkt->u.alive_frame,
sizeof(struct iwl_init_alive_resp));
pwork = &priv->init_alive_start;
} else {
IWL_DEBUG_INFO(priv, "Runtime Alive received.\n");
memcpy(&priv->card_alive, &pkt->u.alive_frame,
sizeof(struct iwl_alive_resp));
pwork = &priv->alive_start;
}
if (palive->is_valid == UCODE_VALID_OK)
queue_delayed_work(priv->workqueue, pwork,
msecs_to_jiffies(5));
else
IWL_WARN(priv, "uCode did not respond OK.\n");
}
static void iwl4965_bg_statistics_periodic(unsigned long data)
{
struct iwl_priv *priv = (struct iwl_priv *)data;
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (!iwl_legacy_is_ready_rf(priv))
return;
iwl_legacy_send_statistics_request(priv, CMD_ASYNC, false);
}
static void iwl4965_print_cont_event_trace(struct iwl_priv *priv, u32 base,
u32 start_idx, u32 num_events,
u32 mode)
{
u32 i;
u32 ptr;
u32 ev, time, data;
unsigned long reg_flags;
if (mode == 0)
ptr = base + (4 * sizeof(u32)) + (start_idx * 2 * sizeof(u32));
else
ptr = base + (4 * sizeof(u32)) + (start_idx * 3 * sizeof(u32));
spin_lock_irqsave(&priv->reg_lock, reg_flags);
if (iwl_grab_nic_access(priv)) {
spin_unlock_irqrestore(&priv->reg_lock, reg_flags);
return;
}
_iwl_legacy_write_direct32(priv, HBUS_TARG_MEM_RADDR, ptr);
rmb();
for (i = 0; i < num_events; i++) {
ev = _iwl_legacy_read_direct32(priv, HBUS_TARG_MEM_RDAT);
time = _iwl_legacy_read_direct32(priv, HBUS_TARG_MEM_RDAT);
if (mode == 0) {
trace_iwlwifi_legacy_dev_ucode_cont_event(priv,
0, time, ev);
} else {
data = _iwl_legacy_read_direct32(priv,
HBUS_TARG_MEM_RDAT);
trace_iwlwifi_legacy_dev_ucode_cont_event(priv,
time, data, ev);
}
}
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, reg_flags);
}
static void iwl4965_continuous_event_trace(struct iwl_priv *priv)
{
u32 capacity;
u32 base;
u32 mode;
u32 num_wraps;
u32 next_entry;
if (priv->ucode_type == UCODE_INIT)
base = le32_to_cpu(priv->card_alive_init.error_event_table_ptr);
else
base = le32_to_cpu(priv->card_alive.log_event_table_ptr);
if (priv->cfg->ops->lib->is_valid_rtc_data_addr(base)) {
capacity = iwl_legacy_read_targ_mem(priv, base);
num_wraps = iwl_legacy_read_targ_mem(priv,
base + (2 * sizeof(u32)));
mode = iwl_legacy_read_targ_mem(priv, base + (1 * sizeof(u32)));
next_entry = iwl_legacy_read_targ_mem(priv,
base + (3 * sizeof(u32)));
} else
return;
if (num_wraps == priv->event_log.num_wraps) {
iwl4965_print_cont_event_trace(priv,
base, priv->event_log.next_entry,
next_entry - priv->event_log.next_entry,
mode);
priv->event_log.non_wraps_count++;
} else {
if ((num_wraps - priv->event_log.num_wraps) > 1)
priv->event_log.wraps_more_count++;
else
priv->event_log.wraps_once_count++;
trace_iwlwifi_legacy_dev_ucode_wrap_event(priv,
num_wraps - priv->event_log.num_wraps,
next_entry, priv->event_log.next_entry);
if (next_entry < priv->event_log.next_entry) {
iwl4965_print_cont_event_trace(priv, base,
priv->event_log.next_entry,
capacity - priv->event_log.next_entry,
mode);
iwl4965_print_cont_event_trace(priv, base, 0,
next_entry, mode);
} else {
iwl4965_print_cont_event_trace(priv, base,
next_entry, capacity - next_entry,
mode);
iwl4965_print_cont_event_trace(priv, base, 0,
next_entry, mode);
}
}
priv->event_log.num_wraps = num_wraps;
priv->event_log.next_entry = next_entry;
}
static void iwl4965_bg_ucode_trace(unsigned long data)
{
struct iwl_priv *priv = (struct iwl_priv *)data;
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (priv->event_log.ucode_trace) {
iwl4965_continuous_event_trace(priv);
mod_timer(&priv->ucode_trace,
jiffies + msecs_to_jiffies(UCODE_TRACE_PERIOD));
}
}
static void iwl4965_rx_beacon_notif(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
struct iwl4965_beacon_notif *beacon =
(struct iwl4965_beacon_notif *)pkt->u.raw;
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
u8 rate = iwl4965_hw_get_rate(beacon->beacon_notify_hdr.rate_n_flags);
IWL_DEBUG_RX(priv, "beacon status %x retries %d iss %d "
"tsf %d %d rate %d\n",
le32_to_cpu(beacon->beacon_notify_hdr.u.status) & TX_STATUS_MSK,
beacon->beacon_notify_hdr.failure_frame,
le32_to_cpu(beacon->ibss_mgr_status),
le32_to_cpu(beacon->high_tsf),
le32_to_cpu(beacon->low_tsf), rate);
#endif
priv->ibss_manager = le32_to_cpu(beacon->ibss_mgr_status);
}
static void iwl4965_perform_ct_kill_task(struct iwl_priv *priv)
{
unsigned long flags;
IWL_DEBUG_POWER(priv, "Stop all queues\n");
if (priv->mac80211_registered)
ieee80211_stop_queues(priv->hw);
iwl_write32(priv, CSR_UCODE_DRV_GP1_SET,
CSR_UCODE_DRV_GP1_REG_BIT_CT_KILL_EXIT);
iwl_read32(priv, CSR_UCODE_DRV_GP1);
spin_lock_irqsave(&priv->reg_lock, flags);
if (!iwl_grab_nic_access(priv))
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
static void iwl4965_rx_card_state_notif(struct iwl_priv *priv,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u32 flags = le32_to_cpu(pkt->u.card_state_notif.flags);
unsigned long status = priv->status;
IWL_DEBUG_RF_KILL(priv, "Card state received: HW:%s SW:%s CT:%s\n",
(flags & HW_CARD_DISABLED) ? "Kill" : "On",
(flags & SW_CARD_DISABLED) ? "Kill" : "On",
(flags & CT_CARD_DISABLED) ?
"Reached" : "Not reached");
if (flags & (SW_CARD_DISABLED | HW_CARD_DISABLED |
CT_CARD_DISABLED)) {
iwl_write32(priv, CSR_UCODE_DRV_GP1_SET,
CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED);
iwl_legacy_write_direct32(priv, HBUS_TARG_MBX_C,
HBUS_TARG_MBX_C_REG_BIT_CMD_BLOCKED);
if (!(flags & RXON_CARD_DISABLED)) {
iwl_write32(priv, CSR_UCODE_DRV_GP1_CLR,
CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED);
iwl_legacy_write_direct32(priv, HBUS_TARG_MBX_C,
HBUS_TARG_MBX_C_REG_BIT_CMD_BLOCKED);
}
}
if (flags & CT_CARD_DISABLED)
iwl4965_perform_ct_kill_task(priv);
if (flags & HW_CARD_DISABLED)
set_bit(STATUS_RF_KILL_HW, &priv->status);
else
clear_bit(STATUS_RF_KILL_HW, &priv->status);
if (!(flags & RXON_CARD_DISABLED))
iwl_legacy_scan_cancel(priv);
if ((test_bit(STATUS_RF_KILL_HW, &status) !=
test_bit(STATUS_RF_KILL_HW, &priv->status)))
wiphy_rfkill_set_hw_state(priv->hw->wiphy,
test_bit(STATUS_RF_KILL_HW, &priv->status));
else
wake_up_interruptible(&priv->wait_command_queue);
}
static void iwl4965_setup_rx_handlers(struct iwl_priv *priv)
{
priv->rx_handlers[REPLY_ALIVE] = iwl4965_rx_reply_alive;
priv->rx_handlers[REPLY_ERROR] = iwl_legacy_rx_reply_error;
priv->rx_handlers[CHANNEL_SWITCH_NOTIFICATION] = iwl_legacy_rx_csa;
priv->rx_handlers[SPECTRUM_MEASURE_NOTIFICATION] =
iwl_legacy_rx_spectrum_measure_notif;
priv->rx_handlers[PM_SLEEP_NOTIFICATION] = iwl_legacy_rx_pm_sleep_notif;
priv->rx_handlers[PM_DEBUG_STATISTIC_NOTIFIC] =
iwl_legacy_rx_pm_debug_statistics_notif;
priv->rx_handlers[BEACON_NOTIFICATION] = iwl4965_rx_beacon_notif;
priv->rx_handlers[REPLY_STATISTICS_CMD] = iwl4965_reply_statistics;
priv->rx_handlers[STATISTICS_NOTIFICATION] = iwl4965_rx_statistics;
iwl_legacy_setup_rx_scan_handlers(priv);
priv->rx_handlers[CARD_STATE_NOTIFICATION] =
iwl4965_rx_card_state_notif;
priv->rx_handlers[MISSED_BEACONS_NOTIFICATION] =
iwl4965_rx_missed_beacon_notif;
priv->rx_handlers[REPLY_RX_PHY_CMD] = iwl4965_rx_reply_rx_phy;
priv->rx_handlers[REPLY_RX_MPDU_CMD] = iwl4965_rx_reply_rx;
priv->rx_handlers[REPLY_COMPRESSED_BA] = iwl4965_rx_reply_compressed_ba;
priv->cfg->ops->lib->rx_handler_setup(priv);
}
void iwl4965_rx_handle(struct iwl_priv *priv)
{
struct iwl_rx_mem_buffer *rxb;
struct iwl_rx_packet *pkt;
struct iwl_rx_queue *rxq = &priv->rxq;
u32 r, i;
int reclaim;
unsigned long flags;
u8 fill_rx = 0;
u32 count = 8;
int total_empty;
r = le16_to_cpu(rxq->rb_stts->closed_rb_num) & 0x0FFF;
i = rxq->read;
if (i == r)
IWL_DEBUG_RX(priv, "r = %d, i = %d\n", r, i);
total_empty = r - rxq->write_actual;
if (total_empty < 0)
total_empty += RX_QUEUE_SIZE;
if (total_empty > (RX_QUEUE_SIZE / 2))
fill_rx = 1;
while (i != r) {
int len;
rxb = rxq->queue[i];
BUG_ON(rxb == NULL);
rxq->queue[i] = NULL;
pci_unmap_page(priv->pci_dev, rxb->page_dma,
PAGE_SIZE << priv->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
pkt = rxb_addr(rxb);
len = le32_to_cpu(pkt->len_n_flags) & FH_RSCSR_FRAME_SIZE_MSK;
len += sizeof(u32);
trace_iwlwifi_legacy_dev_rx(priv, pkt, len);
reclaim = !(pkt->hdr.sequence & SEQ_RX_FRAME) &&
(pkt->hdr.cmd != REPLY_RX_PHY_CMD) &&
(pkt->hdr.cmd != REPLY_RX) &&
(pkt->hdr.cmd != REPLY_RX_MPDU_CMD) &&
(pkt->hdr.cmd != REPLY_COMPRESSED_BA) &&
(pkt->hdr.cmd != STATISTICS_NOTIFICATION) &&
(pkt->hdr.cmd != REPLY_TX);
if (priv->rx_handlers[pkt->hdr.cmd]) {
IWL_DEBUG_RX(priv, "r = %d, i = %d, %s, 0x%02x\n", r,
i, iwl_legacy_get_cmd_string(pkt->hdr.cmd),
pkt->hdr.cmd);
priv->isr_stats.rx_handlers[pkt->hdr.cmd]++;
priv->rx_handlers[pkt->hdr.cmd] (priv, rxb);
} else {
IWL_DEBUG_RX(priv,
"r %d i %d No handler needed for %s, 0x%02x\n",
r, i, iwl_legacy_get_cmd_string(pkt->hdr.cmd),
pkt->hdr.cmd);
}
if (reclaim) {
if (rxb->page)
iwl_legacy_tx_cmd_complete(priv, rxb);
else
IWL_WARN(priv, "Claim null rxb?\n");
}
spin_lock_irqsave(&rxq->lock, flags);
if (rxb->page != NULL) {
rxb->page_dma = pci_map_page(priv->pci_dev, rxb->page,
0, PAGE_SIZE << priv->hw_params.rx_page_order,
PCI_DMA_FROMDEVICE);
list_add_tail(&rxb->list, &rxq->rx_free);
rxq->free_count++;
} else
list_add_tail(&rxb->list, &rxq->rx_used);
spin_unlock_irqrestore(&rxq->lock, flags);
i = (i + 1) & RX_QUEUE_MASK;
if (fill_rx) {
count++;
if (count >= 8) {
rxq->read = i;
iwl4965_rx_replenish_now(priv);
count = 0;
}
}
}
rxq->read = i;
if (fill_rx)
iwl4965_rx_replenish_now(priv);
else
iwl4965_rx_queue_restock(priv);
}
static inline void iwl4965_synchronize_irq(struct iwl_priv *priv)
{
synchronize_irq(priv->pci_dev->irq);
tasklet_kill(&priv->irq_tasklet);
}
static void iwl4965_irq_tasklet(struct iwl_priv *priv)
{
u32 inta, handled = 0;
u32 inta_fh;
unsigned long flags;
u32 i;
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
u32 inta_mask;
#endif
spin_lock_irqsave(&priv->lock, flags);
inta = iwl_read32(priv, CSR_INT);
iwl_write32(priv, CSR_INT, inta);
inta_fh = iwl_read32(priv, CSR_FH_INT_STATUS);
iwl_write32(priv, CSR_FH_INT_STATUS, inta_fh);
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
if (iwl_legacy_get_debug_level(priv) & IWL_DL_ISR) {
inta_mask = iwl_read32(priv, CSR_INT_MASK);
IWL_DEBUG_ISR(priv, "inta 0x%08x, enabled 0x%08x, fh 0x%08x\n",
inta, inta_mask, inta_fh);
}
#endif
spin_unlock_irqrestore(&priv->lock, flags);
if (inta_fh & CSR49_FH_INT_RX_MASK)
inta |= CSR_INT_BIT_FH_RX;
if (inta_fh & CSR49_FH_INT_TX_MASK)
inta |= CSR_INT_BIT_FH_TX;
if (inta & CSR_INT_BIT_HW_ERR) {
IWL_ERR(priv, "Hardware error detected. Restarting.\n");
iwl_legacy_disable_interrupts(priv);
priv->isr_stats.hw++;
iwl_legacy_irq_handle_error(priv);
handled |= CSR_INT_BIT_HW_ERR;
return;
}
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
if (iwl_legacy_get_debug_level(priv) & (IWL_DL_ISR)) {
if (inta & CSR_INT_BIT_SCD) {
IWL_DEBUG_ISR(priv, "Scheduler finished to transmit "
"the frame/frames.\n");
priv->isr_stats.sch++;
}
if (inta & CSR_INT_BIT_ALIVE) {
IWL_DEBUG_ISR(priv, "Alive interrupt\n");
priv->isr_stats.alive++;
}
}
#endif
inta &= ~(CSR_INT_BIT_SCD | CSR_INT_BIT_ALIVE);
if (inta & CSR_INT_BIT_RF_KILL) {
int hw_rf_kill = 0;
if (!(iwl_read32(priv, CSR_GP_CNTRL) &
CSR_GP_CNTRL_REG_FLAG_HW_RF_KILL_SW))
hw_rf_kill = 1;
IWL_WARN(priv, "RF_KILL bit toggled to %s.\n",
hw_rf_kill ? "disable radio" : "enable radio");
priv->isr_stats.rfkill++;
if (!test_bit(STATUS_ALIVE, &priv->status)) {
if (hw_rf_kill)
set_bit(STATUS_RF_KILL_HW, &priv->status);
else
clear_bit(STATUS_RF_KILL_HW, &priv->status);
wiphy_rfkill_set_hw_state(priv->hw->wiphy, hw_rf_kill);
}
handled |= CSR_INT_BIT_RF_KILL;
}
if (inta & CSR_INT_BIT_CT_KILL) {
IWL_ERR(priv, "Microcode CT kill error detected.\n");
priv->isr_stats.ctkill++;
handled |= CSR_INT_BIT_CT_KILL;
}
if (inta & CSR_INT_BIT_SW_ERR) {
IWL_ERR(priv, "Microcode SW error detected. "
" Restarting 0x%X.\n", inta);
priv->isr_stats.sw++;
iwl_legacy_irq_handle_error(priv);
handled |= CSR_INT_BIT_SW_ERR;
}
if (inta & CSR_INT_BIT_WAKEUP) {
IWL_DEBUG_ISR(priv, "Wakeup interrupt\n");
iwl_legacy_rx_queue_update_write_ptr(priv, &priv->rxq);
for (i = 0; i < priv->hw_params.max_txq_num; i++)
iwl_legacy_txq_update_write_ptr(priv, &priv->txq[i]);
priv->isr_stats.wakeup++;
handled |= CSR_INT_BIT_WAKEUP;
}
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX)) {
iwl4965_rx_handle(priv);
priv->isr_stats.rx++;
handled |= (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX);
}
if (inta & CSR_INT_BIT_FH_TX) {
IWL_DEBUG_ISR(priv, "uCode load interrupt\n");
priv->isr_stats.tx++;
handled |= CSR_INT_BIT_FH_TX;
priv->ucode_write_complete = 1;
wake_up_interruptible(&priv->wait_command_queue);
}
if (inta & ~handled) {
IWL_ERR(priv, "Unhandled INTA bits 0x%08x\n", inta & ~handled);
priv->isr_stats.unhandled++;
}
if (inta & ~(priv->inta_mask)) {
IWL_WARN(priv, "Disabled INTA bits 0x%08x were pending\n",
inta & ~priv->inta_mask);
IWL_WARN(priv, " with FH_INT = 0x%08x\n", inta_fh);
}
if (test_bit(STATUS_INT_ENABLED, &priv->status))
iwl_legacy_enable_interrupts(priv);
else if (handled & CSR_INT_BIT_RF_KILL)
iwl_legacy_enable_rfkill_int(priv);
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
if (iwl_legacy_get_debug_level(priv) & (IWL_DL_ISR)) {
inta = iwl_read32(priv, CSR_INT);
inta_mask = iwl_read32(priv, CSR_INT_MASK);
inta_fh = iwl_read32(priv, CSR_FH_INT_STATUS);
IWL_DEBUG_ISR(priv,
"End inta 0x%08x, enabled 0x%08x, fh 0x%08x, "
"flags 0x%08lx\n", inta, inta_mask, inta_fh, flags);
}
#endif
}
static ssize_t iwl4965_show_debug_level(struct device *d,
struct device_attribute *attr, char *buf)
{
struct iwl_priv *priv = dev_get_drvdata(d);
return sprintf(buf, "0x%08X\n", iwl_legacy_get_debug_level(priv));
}
static ssize_t iwl4965_store_debug_level(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct iwl_priv *priv = dev_get_drvdata(d);
unsigned long val;
int ret;
ret = strict_strtoul(buf, 0, &val);
if (ret)
IWL_ERR(priv, "%s is not in hex or decimal form.\n", buf);
else {
priv->debug_level = val;
if (iwl_legacy_alloc_traffic_mem(priv))
IWL_ERR(priv,
"Not enough memory to generate traffic log\n");
}
return strnlen(buf, count);
}
static ssize_t iwl4965_show_temperature(struct device *d,
struct device_attribute *attr, char *buf)
{
struct iwl_priv *priv = dev_get_drvdata(d);
if (!iwl_legacy_is_alive(priv))
return -EAGAIN;
return sprintf(buf, "%d\n", priv->temperature);
}
static ssize_t iwl4965_show_tx_power(struct device *d,
struct device_attribute *attr, char *buf)
{
struct iwl_priv *priv = dev_get_drvdata(d);
if (!iwl_legacy_is_ready_rf(priv))
return sprintf(buf, "off\n");
else
return sprintf(buf, "%d\n", priv->tx_power_user_lmt);
}
static ssize_t iwl4965_store_tx_power(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct iwl_priv *priv = dev_get_drvdata(d);
unsigned long val;
int ret;
ret = strict_strtoul(buf, 10, &val);
if (ret)
IWL_INFO(priv, "%s is not in decimal form.\n", buf);
else {
ret = iwl_legacy_set_tx_power(priv, val, false);
if (ret)
IWL_ERR(priv, "failed setting tx power (0x%d).\n",
ret);
else
ret = count;
}
return ret;
}
static void iwl4965_dealloc_ucode_pci(struct iwl_priv *priv)
{
iwl_legacy_free_fw_desc(priv->pci_dev, &priv->ucode_code);
iwl_legacy_free_fw_desc(priv->pci_dev, &priv->ucode_data);
iwl_legacy_free_fw_desc(priv->pci_dev, &priv->ucode_data_backup);
iwl_legacy_free_fw_desc(priv->pci_dev, &priv->ucode_init);
iwl_legacy_free_fw_desc(priv->pci_dev, &priv->ucode_init_data);
iwl_legacy_free_fw_desc(priv->pci_dev, &priv->ucode_boot);
}
static void iwl4965_nic_start(struct iwl_priv *priv)
{
iwl_write32(priv, CSR_RESET, 0);
}
static int __must_check iwl4965_request_firmware(struct iwl_priv *priv, bool first)
{
const char *name_pre = priv->cfg->fw_name_pre;
char tag[8];
if (first) {
priv->fw_index = priv->cfg->ucode_api_max;
sprintf(tag, "%d", priv->fw_index);
} else {
priv->fw_index--;
sprintf(tag, "%d", priv->fw_index);
}
if (priv->fw_index < priv->cfg->ucode_api_min) {
IWL_ERR(priv, "no suitable firmware found!\n");
return -ENOENT;
}
sprintf(priv->firmware_name, "%s%s%s", name_pre, tag, ".ucode");
IWL_DEBUG_INFO(priv, "attempting to load firmware '%s'\n",
priv->firmware_name);
return request_firmware_nowait(THIS_MODULE, 1, priv->firmware_name,
&priv->pci_dev->dev, GFP_KERNEL, priv,
iwl4965_ucode_callback);
}
static int iwl4965_load_firmware(struct iwl_priv *priv,
const struct firmware *ucode_raw,
struct iwl4965_firmware_pieces *pieces)
{
struct iwl_ucode_header *ucode = (void *)ucode_raw->data;
u32 api_ver, hdr_size;
const u8 *src;
priv->ucode_ver = le32_to_cpu(ucode->ver);
api_ver = IWL_UCODE_API(priv->ucode_ver);
switch (api_ver) {
default:
case 0:
case 1:
case 2:
hdr_size = 24;
if (ucode_raw->size < hdr_size) {
IWL_ERR(priv, "File size too small!\n");
return -EINVAL;
}
pieces->inst_size = le32_to_cpu(ucode->v1.inst_size);
pieces->data_size = le32_to_cpu(ucode->v1.data_size);
pieces->init_size = le32_to_cpu(ucode->v1.init_size);
pieces->init_data_size =
le32_to_cpu(ucode->v1.init_data_size);
pieces->boot_size = le32_to_cpu(ucode->v1.boot_size);
src = ucode->v1.data;
break;
}
if (ucode_raw->size != hdr_size + pieces->inst_size +
pieces->data_size + pieces->init_size +
pieces->init_data_size + pieces->boot_size) {
IWL_ERR(priv,
"uCode file size %d does not match expected size\n",
(int)ucode_raw->size);
return -EINVAL;
}
pieces->inst = src;
src += pieces->inst_size;
pieces->data = src;
src += pieces->data_size;
pieces->init = src;
src += pieces->init_size;
pieces->init_data = src;
src += pieces->init_data_size;
pieces->boot = src;
src += pieces->boot_size;
return 0;
}
static void
iwl4965_ucode_callback(const struct firmware *ucode_raw, void *context)
{
struct iwl_priv *priv = context;
struct iwl_ucode_header *ucode;
int err;
struct iwl4965_firmware_pieces pieces;
const unsigned int api_max = priv->cfg->ucode_api_max;
const unsigned int api_min = priv->cfg->ucode_api_min;
u32 api_ver;
u32 max_probe_length = 200;
u32 standard_phy_calibration_size =
IWL_DEFAULT_STANDARD_PHY_CALIBRATE_TBL_SIZE;
memset(&pieces, 0, sizeof(pieces));
if (!ucode_raw) {
if (priv->fw_index <= priv->cfg->ucode_api_max)
IWL_ERR(priv,
"request for firmware file '%s' failed.\n",
priv->firmware_name);
goto try_again;
}
IWL_DEBUG_INFO(priv, "Loaded firmware file '%s' (%zd bytes).\n",
priv->firmware_name, ucode_raw->size);
if (ucode_raw->size < 4) {
IWL_ERR(priv, "File size way too small!\n");
goto try_again;
}
ucode = (struct iwl_ucode_header *)ucode_raw->data;
err = iwl4965_load_firmware(priv, ucode_raw, &pieces);
if (err)
goto try_again;
api_ver = IWL_UCODE_API(priv->ucode_ver);
if (api_ver < api_min || api_ver > api_max) {
IWL_ERR(priv,
"Driver unable to support your firmware API. "
"Driver supports v%u, firmware is v%u.\n",
api_max, api_ver);
goto try_again;
}
if (api_ver != api_max)
IWL_ERR(priv,
"Firmware has old API version. Expected v%u, "
"got v%u. New firmware can be obtained "
"from http://www.intellinuxwireless.org.\n",
api_max, api_ver);
IWL_INFO(priv, "loaded firmware version %u.%u.%u.%u\n",
IWL_UCODE_MAJOR(priv->ucode_ver),
IWL_UCODE_MINOR(priv->ucode_ver),
IWL_UCODE_API(priv->ucode_ver),
IWL_UCODE_SERIAL(priv->ucode_ver));
snprintf(priv->hw->wiphy->fw_version,
sizeof(priv->hw->wiphy->fw_version),
"%u.%u.%u.%u",
IWL_UCODE_MAJOR(priv->ucode_ver),
IWL_UCODE_MINOR(priv->ucode_ver),
IWL_UCODE_API(priv->ucode_ver),
IWL_UCODE_SERIAL(priv->ucode_ver));
IWL_DEBUG_INFO(priv, "f/w package hdr ucode version raw = 0x%x\n",
priv->ucode_ver);
IWL_DEBUG_INFO(priv, "f/w package hdr runtime inst size = %Zd\n",
pieces.inst_size);
IWL_DEBUG_INFO(priv, "f/w package hdr runtime data size = %Zd\n",
pieces.data_size);
IWL_DEBUG_INFO(priv, "f/w package hdr init inst size = %Zd\n",
pieces.init_size);
IWL_DEBUG_INFO(priv, "f/w package hdr init data size = %Zd\n",
pieces.init_data_size);
IWL_DEBUG_INFO(priv, "f/w package hdr boot inst size = %Zd\n",
pieces.boot_size);
if (pieces.inst_size > priv->hw_params.max_inst_size) {
IWL_ERR(priv, "uCode instr len %Zd too large to fit in\n",
pieces.inst_size);
goto try_again;
}
if (pieces.data_size > priv->hw_params.max_data_size) {
IWL_ERR(priv, "uCode data len %Zd too large to fit in\n",
pieces.data_size);
goto try_again;
}
if (pieces.init_size > priv->hw_params.max_inst_size) {
IWL_ERR(priv, "uCode init instr len %Zd too large to fit in\n",
pieces.init_size);
goto try_again;
}
if (pieces.init_data_size > priv->hw_params.max_data_size) {
IWL_ERR(priv, "uCode init data len %Zd too large to fit in\n",
pieces.init_data_size);
goto try_again;
}
if (pieces.boot_size > priv->hw_params.max_bsm_size) {
IWL_ERR(priv, "uCode boot instr len %Zd too large to fit in\n",
pieces.boot_size);
goto try_again;
}
priv->ucode_code.len = pieces.inst_size;
iwl_legacy_alloc_fw_desc(priv->pci_dev, &priv->ucode_code);
priv->ucode_data.len = pieces.data_size;
iwl_legacy_alloc_fw_desc(priv->pci_dev, &priv->ucode_data);
priv->ucode_data_backup.len = pieces.data_size;
iwl_legacy_alloc_fw_desc(priv->pci_dev, &priv->ucode_data_backup);
if (!priv->ucode_code.v_addr || !priv->ucode_data.v_addr ||
!priv->ucode_data_backup.v_addr)
goto err_pci_alloc;
if (pieces.init_size && pieces.init_data_size) {
priv->ucode_init.len = pieces.init_size;
iwl_legacy_alloc_fw_desc(priv->pci_dev, &priv->ucode_init);
priv->ucode_init_data.len = pieces.init_data_size;
iwl_legacy_alloc_fw_desc(priv->pci_dev, &priv->ucode_init_data);
if (!priv->ucode_init.v_addr || !priv->ucode_init_data.v_addr)
goto err_pci_alloc;
}
if (pieces.boot_size) {
priv->ucode_boot.len = pieces.boot_size;
iwl_legacy_alloc_fw_desc(priv->pci_dev, &priv->ucode_boot);
if (!priv->ucode_boot.v_addr)
goto err_pci_alloc;
}
priv->sta_key_max_num = STA_KEY_MAX_NUM;
IWL_DEBUG_INFO(priv, "Copying (but not loading) uCode instr len %Zd\n",
pieces.inst_size);
memcpy(priv->ucode_code.v_addr, pieces.inst, pieces.inst_size);
IWL_DEBUG_INFO(priv, "uCode instr buf vaddr = 0x%p, paddr = 0x%08x\n",
priv->ucode_code.v_addr, (u32)priv->ucode_code.p_addr);
IWL_DEBUG_INFO(priv, "Copying (but not loading) uCode data len %Zd\n",
pieces.data_size);
memcpy(priv->ucode_data.v_addr, pieces.data, pieces.data_size);
memcpy(priv->ucode_data_backup.v_addr, pieces.data, pieces.data_size);
if (pieces.init_size) {
IWL_DEBUG_INFO(priv,
"Copying (but not loading) init instr len %Zd\n",
pieces.init_size);
memcpy(priv->ucode_init.v_addr, pieces.init, pieces.init_size);
}
if (pieces.init_data_size) {
IWL_DEBUG_INFO(priv,
"Copying (but not loading) init data len %Zd\n",
pieces.init_data_size);
memcpy(priv->ucode_init_data.v_addr, pieces.init_data,
pieces.init_data_size);
}
IWL_DEBUG_INFO(priv, "Copying (but not loading) boot instr len %Zd\n",
pieces.boot_size);
memcpy(priv->ucode_boot.v_addr, pieces.boot, pieces.boot_size);
priv->_4965.phy_calib_chain_noise_reset_cmd =
standard_phy_calibration_size;
priv->_4965.phy_calib_chain_noise_gain_cmd =
standard_phy_calibration_size + 1;
err = iwl4965_mac_setup_register(priv, max_probe_length);
if (err)
goto out_unbind;
err = iwl_legacy_dbgfs_register(priv, DRV_NAME);
if (err)
IWL_ERR(priv,
"failed to create debugfs files. Ignoring error: %d\n", err);
err = sysfs_create_group(&priv->pci_dev->dev.kobj,
&iwl_attribute_group);
if (err) {
IWL_ERR(priv, "failed to create sysfs device attributes\n");
goto out_unbind;
}
release_firmware(ucode_raw);
complete(&priv->_4965.firmware_loading_complete);
return;
try_again:
if (iwl4965_request_firmware(priv, false))
goto out_unbind;
release_firmware(ucode_raw);
return;
err_pci_alloc:
IWL_ERR(priv, "failed to allocate pci memory\n");
iwl4965_dealloc_ucode_pci(priv);
out_unbind:
complete(&priv->_4965.firmware_loading_complete);
device_release_driver(&priv->pci_dev->dev);
release_firmware(ucode_raw);
}
static const char *iwl4965_desc_lookup(u32 num)
{
int i;
int max = ARRAY_SIZE(desc_lookup_text);
if (num < max)
return desc_lookup_text[num];
max = ARRAY_SIZE(advanced_lookup) - 1;
for (i = 0; i < max; i++) {
if (advanced_lookup[i].num == num)
break;
}
return advanced_lookup[i].name;
}
void iwl4965_dump_nic_error_log(struct iwl_priv *priv)
{
u32 data2, line;
u32 desc, time, count, base, data1;
u32 blink1, blink2, ilink1, ilink2;
u32 pc, hcmd;
if (priv->ucode_type == UCODE_INIT) {
base = le32_to_cpu(priv->card_alive_init.error_event_table_ptr);
} else {
base = le32_to_cpu(priv->card_alive.error_event_table_ptr);
}
if (!priv->cfg->ops->lib->is_valid_rtc_data_addr(base)) {
IWL_ERR(priv,
"Not valid error log pointer 0x%08X for %s uCode\n",
base, (priv->ucode_type == UCODE_INIT) ? "Init" : "RT");
return;
}
count = iwl_legacy_read_targ_mem(priv, base);
if (ERROR_START_OFFSET <= count * ERROR_ELEM_SIZE) {
IWL_ERR(priv, "Start IWL Error Log Dump:\n");
IWL_ERR(priv, "Status: 0x%08lX, count: %d\n",
priv->status, count);
}
desc = iwl_legacy_read_targ_mem(priv, base + 1 * sizeof(u32));
priv->isr_stats.err_code = desc;
pc = iwl_legacy_read_targ_mem(priv, base + 2 * sizeof(u32));
blink1 = iwl_legacy_read_targ_mem(priv, base + 3 * sizeof(u32));
blink2 = iwl_legacy_read_targ_mem(priv, base + 4 * sizeof(u32));
ilink1 = iwl_legacy_read_targ_mem(priv, base + 5 * sizeof(u32));
ilink2 = iwl_legacy_read_targ_mem(priv, base + 6 * sizeof(u32));
data1 = iwl_legacy_read_targ_mem(priv, base + 7 * sizeof(u32));
data2 = iwl_legacy_read_targ_mem(priv, base + 8 * sizeof(u32));
line = iwl_legacy_read_targ_mem(priv, base + 9 * sizeof(u32));
time = iwl_legacy_read_targ_mem(priv, base + 11 * sizeof(u32));
hcmd = iwl_legacy_read_targ_mem(priv, base + 22 * sizeof(u32));
trace_iwlwifi_legacy_dev_ucode_error(priv, desc,
time, data1, data2, line,
blink1, blink2, ilink1, ilink2);
IWL_ERR(priv, "Desc Time "
"data1 data2 line\n");
IWL_ERR(priv, "%-28s (0x%04X) %010u 0x%08X 0x%08X %u\n",
iwl4965_desc_lookup(desc), desc, time, data1, data2, line);
IWL_ERR(priv, "pc blink1 blink2 ilink1 ilink2 hcmd\n");
IWL_ERR(priv, "0x%05X 0x%05X 0x%05X 0x%05X 0x%05X 0x%05X\n",
pc, blink1, blink2, ilink1, ilink2, hcmd);
}
static int iwl4965_print_event_log(struct iwl_priv *priv, u32 start_idx,
u32 num_events, u32 mode,
int pos, char **buf, size_t bufsz)
{
u32 i;
u32 base;
u32 event_size;
u32 ptr;
u32 ev, time, data;
unsigned long reg_flags;
if (num_events == 0)
return pos;
if (priv->ucode_type == UCODE_INIT) {
base = le32_to_cpu(priv->card_alive_init.log_event_table_ptr);
} else {
base = le32_to_cpu(priv->card_alive.log_event_table_ptr);
}
if (mode == 0)
event_size = 2 * sizeof(u32);
else
event_size = 3 * sizeof(u32);
ptr = base + EVENT_START_OFFSET + (start_idx * event_size);
spin_lock_irqsave(&priv->reg_lock, reg_flags);
iwl_grab_nic_access(priv);
_iwl_legacy_write_direct32(priv, HBUS_TARG_MEM_RADDR, ptr);
rmb();
for (i = 0; i < num_events; i++) {
ev = _iwl_legacy_read_direct32(priv, HBUS_TARG_MEM_RDAT);
time = _iwl_legacy_read_direct32(priv, HBUS_TARG_MEM_RDAT);
if (mode == 0) {
if (bufsz) {
pos += scnprintf(*buf + pos, bufsz - pos,
"EVT_LOG:0x%08x:%04u\n",
time, ev);
} else {
trace_iwlwifi_legacy_dev_ucode_event(priv, 0,
time, ev);
IWL_ERR(priv, "EVT_LOG:0x%08x:%04u\n",
time, ev);
}
} else {
data = _iwl_legacy_read_direct32(priv,
HBUS_TARG_MEM_RDAT);
if (bufsz) {
pos += scnprintf(*buf + pos, bufsz - pos,
"EVT_LOGT:%010u:0x%08x:%04u\n",
time, data, ev);
} else {
IWL_ERR(priv, "EVT_LOGT:%010u:0x%08x:%04u\n",
time, data, ev);
trace_iwlwifi_legacy_dev_ucode_event(priv, time,
data, ev);
}
}
}
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, reg_flags);
return pos;
}
static int iwl4965_print_last_event_logs(struct iwl_priv *priv, u32 capacity,
u32 num_wraps, u32 next_entry,
u32 size, u32 mode,
int pos, char **buf, size_t bufsz)
{
if (num_wraps) {
if (next_entry < size) {
pos = iwl4965_print_event_log(priv,
capacity - (size - next_entry),
size - next_entry, mode,
pos, buf, bufsz);
pos = iwl4965_print_event_log(priv, 0,
next_entry, mode,
pos, buf, bufsz);
} else
pos = iwl4965_print_event_log(priv, next_entry - size,
size, mode, pos, buf, bufsz);
} else {
if (next_entry < size) {
pos = iwl4965_print_event_log(priv, 0, next_entry,
mode, pos, buf, bufsz);
} else {
pos = iwl4965_print_event_log(priv, next_entry - size,
size, mode, pos, buf, bufsz);
}
}
return pos;
}
int iwl4965_dump_nic_event_log(struct iwl_priv *priv, bool full_log,
char **buf, bool display)
{
u32 base;
u32 capacity;
u32 mode;
u32 num_wraps;
u32 next_entry;
u32 size;
int pos = 0;
size_t bufsz = 0;
if (priv->ucode_type == UCODE_INIT) {
base = le32_to_cpu(priv->card_alive_init.log_event_table_ptr);
} else {
base = le32_to_cpu(priv->card_alive.log_event_table_ptr);
}
if (!priv->cfg->ops->lib->is_valid_rtc_data_addr(base)) {
IWL_ERR(priv,
"Invalid event log pointer 0x%08X for %s uCode\n",
base, (priv->ucode_type == UCODE_INIT) ? "Init" : "RT");
return -EINVAL;
}
capacity = iwl_legacy_read_targ_mem(priv, base);
mode = iwl_legacy_read_targ_mem(priv, base + (1 * sizeof(u32)));
num_wraps = iwl_legacy_read_targ_mem(priv, base + (2 * sizeof(u32)));
next_entry = iwl_legacy_read_targ_mem(priv, base + (3 * sizeof(u32)));
size = num_wraps ? capacity : next_entry;
if (size == 0) {
IWL_ERR(priv, "Start IWL Event Log Dump: nothing in log\n");
return pos;
}
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
if (!(iwl_legacy_get_debug_level(priv) & IWL_DL_FW_ERRORS) && !full_log)
size = (size > DEFAULT_DUMP_EVENT_LOG_ENTRIES)
? DEFAULT_DUMP_EVENT_LOG_ENTRIES : size;
#else
size = (size > DEFAULT_DUMP_EVENT_LOG_ENTRIES)
? DEFAULT_DUMP_EVENT_LOG_ENTRIES : size;
#endif
IWL_ERR(priv, "Start IWL Event Log Dump: display last %u entries\n",
size);
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
if (display) {
if (full_log)
bufsz = capacity * 48;
else
bufsz = size * 48;
*buf = kmalloc(bufsz, GFP_KERNEL);
if (!*buf)
return -ENOMEM;
}
if ((iwl_legacy_get_debug_level(priv) & IWL_DL_FW_ERRORS) || full_log) {
if (num_wraps)
pos = iwl4965_print_event_log(priv, next_entry,
capacity - next_entry, mode,
pos, buf, bufsz);
pos = iwl4965_print_event_log(priv, 0,
next_entry, mode, pos, buf, bufsz);
} else
pos = iwl4965_print_last_event_logs(priv, capacity, num_wraps,
next_entry, size, mode,
pos, buf, bufsz);
#else
pos = iwl4965_print_last_event_logs(priv, capacity, num_wraps,
next_entry, size, mode,
pos, buf, bufsz);
#endif
return pos;
}
static void iwl4965_rf_kill_ct_config(struct iwl_priv *priv)
{
struct iwl_ct_kill_config cmd;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&priv->lock, flags);
iwl_write32(priv, CSR_UCODE_DRV_GP1_CLR,
CSR_UCODE_DRV_GP1_REG_BIT_CT_KILL_EXIT);
spin_unlock_irqrestore(&priv->lock, flags);
cmd.critical_temperature_R =
cpu_to_le32(priv->hw_params.ct_kill_threshold);
ret = iwl_legacy_send_cmd_pdu(priv, REPLY_CT_KILL_CONFIG_CMD,
sizeof(cmd), &cmd);
if (ret)
IWL_ERR(priv, "REPLY_CT_KILL_CONFIG_CMD failed\n");
else
IWL_DEBUG_INFO(priv, "REPLY_CT_KILL_CONFIG_CMD "
"succeeded, "
"critical temperature is %d\n",
priv->hw_params.ct_kill_threshold);
}
static int iwl4965_alive_notify(struct iwl_priv *priv)
{
u32 a;
unsigned long flags;
int i, chan;
u32 reg_val;
spin_lock_irqsave(&priv->lock, flags);
priv->scd_base_addr = iwl_legacy_read_prph(priv,
IWL49_SCD_SRAM_BASE_ADDR);
a = priv->scd_base_addr + IWL49_SCD_CONTEXT_DATA_OFFSET;
for (; a < priv->scd_base_addr + IWL49_SCD_TX_STTS_BITMAP_OFFSET; a += 4)
iwl_legacy_write_targ_mem(priv, a, 0);
for (; a < priv->scd_base_addr + IWL49_SCD_TRANSLATE_TBL_OFFSET; a += 4)
iwl_legacy_write_targ_mem(priv, a, 0);
for (; a < priv->scd_base_addr +
IWL49_SCD_TRANSLATE_TBL_OFFSET_QUEUE(priv->hw_params.max_txq_num); a += 4)
iwl_legacy_write_targ_mem(priv, a, 0);
iwl_legacy_write_prph(priv, IWL49_SCD_DRAM_BASE_ADDR,
priv->scd_bc_tbls.dma >> 10);
for (chan = 0; chan < FH49_TCSR_CHNL_NUM ; chan++)
iwl_legacy_write_direct32(priv,
FH_TCSR_CHNL_TX_CONFIG_REG(chan),
FH_TCSR_TX_CONFIG_REG_VAL_DMA_CHNL_ENABLE |
FH_TCSR_TX_CONFIG_REG_VAL_DMA_CREDIT_ENABLE);
reg_val = iwl_legacy_read_direct32(priv, FH_TX_CHICKEN_BITS_REG);
iwl_legacy_write_direct32(priv, FH_TX_CHICKEN_BITS_REG,
reg_val | FH_TX_CHICKEN_BITS_SCD_AUTO_RETRY_EN);
iwl_legacy_write_prph(priv, IWL49_SCD_QUEUECHAIN_SEL, 0);
for (i = 0; i < priv->hw_params.max_txq_num; i++) {
iwl_legacy_write_prph(priv, IWL49_SCD_QUEUE_RDPTR(i), 0);
iwl_legacy_write_direct32(priv, HBUS_TARG_WRPTR, 0 | (i << 8));
iwl_legacy_write_targ_mem(priv, priv->scd_base_addr +
IWL49_SCD_CONTEXT_QUEUE_OFFSET(i),
(SCD_WIN_SIZE <<
IWL49_SCD_QUEUE_CTX_REG1_WIN_SIZE_POS) &
IWL49_SCD_QUEUE_CTX_REG1_WIN_SIZE_MSK);
iwl_legacy_write_targ_mem(priv, priv->scd_base_addr +
IWL49_SCD_CONTEXT_QUEUE_OFFSET(i) +
sizeof(u32),
(SCD_FRAME_LIMIT <<
IWL49_SCD_QUEUE_CTX_REG2_FRAME_LIMIT_POS) &
IWL49_SCD_QUEUE_CTX_REG2_FRAME_LIMIT_MSK);
}
iwl_legacy_write_prph(priv, IWL49_SCD_INTERRUPT_MASK,
(1 << priv->hw_params.max_txq_num) - 1);
iwl4965_txq_set_sched(priv, IWL_MASK(0, 6));
iwl4965_set_wr_ptrs(priv, IWL_DEFAULT_CMD_QUEUE_NUM, 0);
memset(&priv->queue_stopped[0], 0, sizeof(priv->queue_stopped));
for (i = 0; i < 4; i++)
atomic_set(&priv->queue_stop_count[i], 0);
priv->txq_ctx_active_msk = 0;
BUILD_BUG_ON(ARRAY_SIZE(default_queue_to_tx_fifo) != 7);
for (i = 0; i < ARRAY_SIZE(default_queue_to_tx_fifo); i++) {
int ac = default_queue_to_tx_fifo[i];
iwl_txq_ctx_activate(priv, i);
if (ac == IWL_TX_FIFO_UNUSED)
continue;
iwl4965_tx_queue_set_status(priv, &priv->txq[i], ac, 0);
}
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static void iwl4965_alive_start(struct iwl_priv *priv)
{
int ret = 0;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
IWL_DEBUG_INFO(priv, "Runtime Alive received.\n");
if (priv->card_alive.is_valid != UCODE_VALID_OK) {
IWL_DEBUG_INFO(priv, "Alive failed.\n");
goto restart;
}
if (iwl4965_verify_ucode(priv)) {
IWL_DEBUG_INFO(priv, "Bad runtime uCode load.\n");
goto restart;
}
ret = iwl4965_alive_notify(priv);
if (ret) {
IWL_WARN(priv,
"Could not complete ALIVE transition [ntf]: %d\n", ret);
goto restart;
}
set_bit(STATUS_ALIVE, &priv->status);
iwl_legacy_setup_watchdog(priv);
if (iwl_legacy_is_rfkill(priv))
return;
ieee80211_wake_queues(priv->hw);
priv->active_rate = IWL_RATES_MASK;
if (iwl_legacy_is_associated_ctx(ctx)) {
struct iwl_legacy_rxon_cmd *active_rxon =
(struct iwl_legacy_rxon_cmd *)&ctx->active;
ctx->staging.filter_flags |= RXON_FILTER_ASSOC_MSK;
active_rxon->filter_flags &= ~RXON_FILTER_ASSOC_MSK;
} else {
struct iwl_rxon_context *tmp;
for_each_context(priv, tmp)
iwl_legacy_connection_init_rx_config(priv, tmp);
if (priv->cfg->ops->hcmd->set_rxon_chain)
priv->cfg->ops->hcmd->set_rxon_chain(priv, ctx);
}
iwl_legacy_send_bt_config(priv);
iwl4965_reset_run_time_calib(priv);
set_bit(STATUS_READY, &priv->status);
iwl_legacy_commit_rxon(priv, ctx);
iwl4965_rf_kill_ct_config(priv);
IWL_DEBUG_INFO(priv, "ALIVE processing complete.\n");
wake_up_interruptible(&priv->wait_command_queue);
iwl_legacy_power_update_mode(priv, true);
IWL_DEBUG_INFO(priv, "Updated power mode\n");
return;
restart:
queue_work(priv->workqueue, &priv->restart);
}
static void __iwl4965_down(struct iwl_priv *priv)
{
unsigned long flags;
int exit_pending;
IWL_DEBUG_INFO(priv, DRV_NAME " is going down\n");
iwl_legacy_scan_cancel_timeout(priv, 200);
exit_pending = test_and_set_bit(STATUS_EXIT_PENDING, &priv->status);
del_timer_sync(&priv->watchdog);
iwl_legacy_clear_ucode_stations(priv, NULL);
iwl_legacy_dealloc_bcast_stations(priv);
iwl_legacy_clear_driver_stations(priv);
wake_up_interruptible_all(&priv->wait_command_queue);
if (!exit_pending)
clear_bit(STATUS_EXIT_PENDING, &priv->status);
iwl_write32(priv, CSR_RESET, CSR_RESET_REG_FLAG_NEVO_RESET);
spin_lock_irqsave(&priv->lock, flags);
iwl_legacy_disable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
iwl4965_synchronize_irq(priv);
if (priv->mac80211_registered)
ieee80211_stop_queues(priv->hw);
if (!iwl_legacy_is_init(priv)) {
priv->status = test_bit(STATUS_RF_KILL_HW, &priv->status) <<
STATUS_RF_KILL_HW |
test_bit(STATUS_GEO_CONFIGURED, &priv->status) <<
STATUS_GEO_CONFIGURED |
test_bit(STATUS_EXIT_PENDING, &priv->status) <<
STATUS_EXIT_PENDING;
goto exit;
}
priv->status &= test_bit(STATUS_RF_KILL_HW, &priv->status) <<
STATUS_RF_KILL_HW |
test_bit(STATUS_GEO_CONFIGURED, &priv->status) <<
STATUS_GEO_CONFIGURED |
test_bit(STATUS_FW_ERROR, &priv->status) <<
STATUS_FW_ERROR |
test_bit(STATUS_EXIT_PENDING, &priv->status) <<
STATUS_EXIT_PENDING;
iwl4965_txq_ctx_stop(priv);
iwl4965_rxq_stop(priv);
iwl_legacy_write_prph(priv, APMG_CLK_DIS_REG, APMG_CLK_VAL_DMA_CLK_RQT);
udelay(5);
iwl_legacy_clear_bit(priv, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
iwl_legacy_apm_stop(priv);
exit:
memset(&priv->card_alive, 0, sizeof(struct iwl_alive_resp));
dev_kfree_skb(priv->beacon_skb);
priv->beacon_skb = NULL;
iwl4965_clear_free_frames(priv);
}
static void iwl4965_down(struct iwl_priv *priv)
{
mutex_lock(&priv->mutex);
__iwl4965_down(priv);
mutex_unlock(&priv->mutex);
iwl4965_cancel_deferred_work(priv);
}
static int iwl4965_set_hw_ready(struct iwl_priv *priv)
{
int ret = 0;
iwl_legacy_set_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_NIC_READY);
ret = iwl_poll_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_NIC_READY,
CSR_HW_IF_CONFIG_REG_BIT_NIC_READY,
HW_READY_TIMEOUT);
if (ret != -ETIMEDOUT)
priv->hw_ready = true;
else
priv->hw_ready = false;
IWL_DEBUG_INFO(priv, "hardware %s\n",
(priv->hw_ready == 1) ? "ready" : "not ready");
return ret;
}
static int iwl4965_prepare_card_hw(struct iwl_priv *priv)
{
int ret = 0;
IWL_DEBUG_INFO(priv, "iwl4965_prepare_card_hw enter\n");
ret = iwl4965_set_hw_ready(priv);
if (priv->hw_ready)
return ret;
iwl_legacy_set_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_PREPARE);
ret = iwl_poll_bit(priv, CSR_HW_IF_CONFIG_REG,
~CSR_HW_IF_CONFIG_REG_BIT_NIC_PREPARE_DONE,
CSR_HW_IF_CONFIG_REG_BIT_NIC_PREPARE_DONE, 150000);
if (ret != -ETIMEDOUT)
iwl4965_set_hw_ready(priv);
return ret;
}
static int __iwl4965_up(struct iwl_priv *priv)
{
struct iwl_rxon_context *ctx;
int i;
int ret;
if (test_bit(STATUS_EXIT_PENDING, &priv->status)) {
IWL_WARN(priv, "Exit pending; will not bring the NIC up\n");
return -EIO;
}
if (!priv->ucode_data_backup.v_addr || !priv->ucode_data.v_addr) {
IWL_ERR(priv, "ucode not available for device bringup\n");
return -EIO;
}
for_each_context(priv, ctx) {
ret = iwl4965_alloc_bcast_station(priv, ctx);
if (ret) {
iwl_legacy_dealloc_bcast_stations(priv);
return ret;
}
}
iwl4965_prepare_card_hw(priv);
if (!priv->hw_ready) {
IWL_WARN(priv, "Exit HW not ready\n");
return -EIO;
}
if (iwl_read32(priv,
CSR_GP_CNTRL) & CSR_GP_CNTRL_REG_FLAG_HW_RF_KILL_SW)
clear_bit(STATUS_RF_KILL_HW, &priv->status);
else
set_bit(STATUS_RF_KILL_HW, &priv->status);
if (iwl_legacy_is_rfkill(priv)) {
wiphy_rfkill_set_hw_state(priv->hw->wiphy, true);
iwl_legacy_enable_interrupts(priv);
IWL_WARN(priv, "Radio disabled by HW RF Kill switch\n");
return 0;
}
iwl_write32(priv, CSR_INT, 0xFFFFFFFF);
priv->cmd_queue = IWL_DEFAULT_CMD_QUEUE_NUM;
ret = iwl4965_hw_nic_init(priv);
if (ret) {
IWL_ERR(priv, "Unable to init nic\n");
return ret;
}
iwl_write32(priv, CSR_UCODE_DRV_GP1_CLR, CSR_UCODE_SW_BIT_RFKILL);
iwl_write32(priv, CSR_UCODE_DRV_GP1_CLR,
CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED);
iwl_write32(priv, CSR_INT, 0xFFFFFFFF);
iwl_legacy_enable_interrupts(priv);
iwl_write32(priv, CSR_UCODE_DRV_GP1_CLR, CSR_UCODE_SW_BIT_RFKILL);
iwl_write32(priv, CSR_UCODE_DRV_GP1_CLR, CSR_UCODE_SW_BIT_RFKILL);
memcpy(priv->ucode_data_backup.v_addr, priv->ucode_data.v_addr,
priv->ucode_data.len);
for (i = 0; i < MAX_HW_RESTARTS; i++) {
ret = priv->cfg->ops->lib->load_ucode(priv);
if (ret) {
IWL_ERR(priv, "Unable to set up bootstrap uCode: %d\n",
ret);
continue;
}
iwl4965_nic_start(priv);
IWL_DEBUG_INFO(priv, DRV_NAME " is coming up\n");
return 0;
}
set_bit(STATUS_EXIT_PENDING, &priv->status);
__iwl4965_down(priv);
clear_bit(STATUS_EXIT_PENDING, &priv->status);
IWL_ERR(priv, "Unable to initialize device after %d attempts.\n", i);
return -EIO;
}
static void iwl4965_bg_init_alive_start(struct work_struct *data)
{
struct iwl_priv *priv =
container_of(data, struct iwl_priv, init_alive_start.work);
mutex_lock(&priv->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
goto out;
priv->cfg->ops->lib->init_alive_start(priv);
out:
mutex_unlock(&priv->mutex);
}
static void iwl4965_bg_alive_start(struct work_struct *data)
{
struct iwl_priv *priv =
container_of(data, struct iwl_priv, alive_start.work);
mutex_lock(&priv->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
goto out;
iwl4965_alive_start(priv);
out:
mutex_unlock(&priv->mutex);
}
static void iwl4965_bg_run_time_calib_work(struct work_struct *work)
{
struct iwl_priv *priv = container_of(work, struct iwl_priv,
run_time_calib_work);
mutex_lock(&priv->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->status) ||
test_bit(STATUS_SCANNING, &priv->status)) {
mutex_unlock(&priv->mutex);
return;
}
if (priv->start_calib) {
iwl4965_chain_noise_calibration(priv,
(void *)&priv->_4965.statistics);
iwl4965_sensitivity_calibration(priv,
(void *)&priv->_4965.statistics);
}
mutex_unlock(&priv->mutex);
}
static void iwl4965_bg_restart(struct work_struct *data)
{
struct iwl_priv *priv = container_of(data, struct iwl_priv, restart);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
if (test_and_clear_bit(STATUS_FW_ERROR, &priv->status)) {
struct iwl_rxon_context *ctx;
mutex_lock(&priv->mutex);
for_each_context(priv, ctx)
ctx->vif = NULL;
priv->is_open = 0;
__iwl4965_down(priv);
mutex_unlock(&priv->mutex);
iwl4965_cancel_deferred_work(priv);
ieee80211_restart_hw(priv->hw);
} else {
iwl4965_down(priv);
mutex_lock(&priv->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->status)) {
mutex_unlock(&priv->mutex);
return;
}
__iwl4965_up(priv);
mutex_unlock(&priv->mutex);
}
}
static void iwl4965_bg_rx_replenish(struct work_struct *data)
{
struct iwl_priv *priv =
container_of(data, struct iwl_priv, rx_replenish);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
mutex_lock(&priv->mutex);
iwl4965_rx_replenish(priv);
mutex_unlock(&priv->mutex);
}
static int iwl4965_mac_setup_register(struct iwl_priv *priv,
u32 max_probe_length)
{
int ret;
struct ieee80211_hw *hw = priv->hw;
struct iwl_rxon_context *ctx;
hw->rate_control_algorithm = "iwl-4965-rs";
hw->flags = IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_AMPDU_AGGREGATION |
IEEE80211_HW_NEED_DTIM_PERIOD |
IEEE80211_HW_SPECTRUM_MGMT |
IEEE80211_HW_REPORTS_TX_ACK_STATUS;
if (priv->cfg->sku & IWL_SKU_N)
hw->flags |= IEEE80211_HW_SUPPORTS_DYNAMIC_SMPS |
IEEE80211_HW_SUPPORTS_STATIC_SMPS;
hw->sta_data_size = sizeof(struct iwl_station_priv);
hw->vif_data_size = sizeof(struct iwl_vif_priv);
for_each_context(priv, ctx) {
hw->wiphy->interface_modes |= ctx->interface_modes;
hw->wiphy->interface_modes |= ctx->exclusive_interface_modes;
}
hw->wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY |
WIPHY_FLAG_DISABLE_BEACON_HINTS;
hw->wiphy->flags &= ~WIPHY_FLAG_PS_ON_BY_DEFAULT;
hw->wiphy->max_scan_ssids = PROBE_OPTION_MAX;
hw->wiphy->max_scan_ie_len = max_probe_length - 24 - 2;
hw->queues = 4;
hw->max_listen_interval = IWL_CONN_MAX_LISTEN_INTERVAL;
if (priv->bands[IEEE80211_BAND_2GHZ].n_channels)
priv->hw->wiphy->bands[IEEE80211_BAND_2GHZ] =
&priv->bands[IEEE80211_BAND_2GHZ];
if (priv->bands[IEEE80211_BAND_5GHZ].n_channels)
priv->hw->wiphy->bands[IEEE80211_BAND_5GHZ] =
&priv->bands[IEEE80211_BAND_5GHZ];
iwl_legacy_leds_init(priv);
ret = ieee80211_register_hw(priv->hw);
if (ret) {
IWL_ERR(priv, "Failed to register hw (error %d)\n", ret);
return ret;
}
priv->mac80211_registered = 1;
return 0;
}
int iwl4965_mac_start(struct ieee80211_hw *hw)
{
struct iwl_priv *priv = hw->priv;
int ret;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->mutex);
ret = __iwl4965_up(priv);
mutex_unlock(&priv->mutex);
if (ret)
return ret;
if (iwl_legacy_is_rfkill(priv))
goto out;
IWL_DEBUG_INFO(priv, "Start UP work done.\n");
ret = wait_event_interruptible_timeout(priv->wait_command_queue,
test_bit(STATUS_READY, &priv->status),
UCODE_READY_TIMEOUT);
if (!ret) {
if (!test_bit(STATUS_READY, &priv->status)) {
IWL_ERR(priv, "START_ALIVE timeout after %dms.\n",
jiffies_to_msecs(UCODE_READY_TIMEOUT));
return -ETIMEDOUT;
}
}
iwl4965_led_enable(priv);
out:
priv->is_open = 1;
IWL_DEBUG_MAC80211(priv, "leave\n");
return 0;
}
void iwl4965_mac_stop(struct ieee80211_hw *hw)
{
struct iwl_priv *priv = hw->priv;
IWL_DEBUG_MAC80211(priv, "enter\n");
if (!priv->is_open)
return;
priv->is_open = 0;
iwl4965_down(priv);
flush_workqueue(priv->workqueue);
iwl_write32(priv, CSR_INT, 0xFFFFFFFF);
iwl_legacy_enable_rfkill_int(priv);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
void iwl4965_mac_tx(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct iwl_priv *priv = hw->priv;
IWL_DEBUG_MACDUMP(priv, "enter\n");
IWL_DEBUG_TX(priv, "dev->xmit(%d bytes) at rate 0x%02x\n", skb->len,
ieee80211_get_tx_rate(hw, IEEE80211_SKB_CB(skb))->bitrate);
if (iwl4965_tx_skb(priv, skb))
dev_kfree_skb_any(skb);
IWL_DEBUG_MACDUMP(priv, "leave\n");
}
void iwl4965_mac_update_tkip_key(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_key_conf *keyconf,
struct ieee80211_sta *sta,
u32 iv32, u16 *phase1key)
{
struct iwl_priv *priv = hw->priv;
struct iwl_vif_priv *vif_priv = (void *)vif->drv_priv;
IWL_DEBUG_MAC80211(priv, "enter\n");
iwl4965_update_tkip_key(priv, vif_priv->ctx, keyconf, sta,
iv32, phase1key);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
int iwl4965_mac_set_key(struct ieee80211_hw *hw, enum set_key_cmd cmd,
struct ieee80211_vif *vif, struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
struct iwl_priv *priv = hw->priv;
struct iwl_vif_priv *vif_priv = (void *)vif->drv_priv;
struct iwl_rxon_context *ctx = vif_priv->ctx;
int ret;
u8 sta_id;
bool is_default_wep_key = false;
IWL_DEBUG_MAC80211(priv, "enter\n");
if (priv->cfg->mod_params->sw_crypto) {
IWL_DEBUG_MAC80211(priv, "leave - hwcrypto disabled\n");
return -EOPNOTSUPP;
}
sta_id = iwl_legacy_sta_id_or_broadcast(priv, vif_priv->ctx, sta);
if (sta_id == IWL_INVALID_STATION)
return -EINVAL;
mutex_lock(&priv->mutex);
iwl_legacy_scan_cancel_timeout(priv, 100);
if ((key->cipher == WLAN_CIPHER_SUITE_WEP40 ||
key->cipher == WLAN_CIPHER_SUITE_WEP104) &&
!sta) {
if (cmd == SET_KEY)
is_default_wep_key = !ctx->key_mapping_keys;
else
is_default_wep_key =
(key->hw_key_idx == HW_KEY_DEFAULT);
}
switch (cmd) {
case SET_KEY:
if (is_default_wep_key)
ret = iwl4965_set_default_wep_key(priv,
vif_priv->ctx, key);
else
ret = iwl4965_set_dynamic_key(priv, vif_priv->ctx,
key, sta_id);
IWL_DEBUG_MAC80211(priv, "enable hwcrypto key\n");
break;
case DISABLE_KEY:
if (is_default_wep_key)
ret = iwl4965_remove_default_wep_key(priv, ctx, key);
else
ret = iwl4965_remove_dynamic_key(priv, ctx,
key, sta_id);
IWL_DEBUG_MAC80211(priv, "disable hwcrypto key\n");
break;
default:
ret = -EINVAL;
}
mutex_unlock(&priv->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
return ret;
}
int iwl4965_mac_ampdu_action(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
enum ieee80211_ampdu_mlme_action action,
struct ieee80211_sta *sta, u16 tid, u16 *ssn,
u8 buf_size)
{
struct iwl_priv *priv = hw->priv;
int ret = -EINVAL;
IWL_DEBUG_HT(priv, "A-MPDU action on addr %pM tid %d\n",
sta->addr, tid);
if (!(priv->cfg->sku & IWL_SKU_N))
return -EACCES;
mutex_lock(&priv->mutex);
switch (action) {
case IEEE80211_AMPDU_RX_START:
IWL_DEBUG_HT(priv, "start Rx\n");
ret = iwl4965_sta_rx_agg_start(priv, sta, tid, *ssn);
break;
case IEEE80211_AMPDU_RX_STOP:
IWL_DEBUG_HT(priv, "stop Rx\n");
ret = iwl4965_sta_rx_agg_stop(priv, sta, tid);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
ret = 0;
break;
case IEEE80211_AMPDU_TX_START:
IWL_DEBUG_HT(priv, "start Tx\n");
ret = iwl4965_tx_agg_start(priv, vif, sta, tid, ssn);
if (ret == 0) {
priv->_4965.agg_tids_count++;
IWL_DEBUG_HT(priv, "priv->_4965.agg_tids_count = %u\n",
priv->_4965.agg_tids_count);
}
break;
case IEEE80211_AMPDU_TX_STOP:
IWL_DEBUG_HT(priv, "stop Tx\n");
ret = iwl4965_tx_agg_stop(priv, vif, sta, tid);
if ((ret == 0) && (priv->_4965.agg_tids_count > 0)) {
priv->_4965.agg_tids_count--;
IWL_DEBUG_HT(priv, "priv->_4965.agg_tids_count = %u\n",
priv->_4965.agg_tids_count);
}
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
ret = 0;
break;
case IEEE80211_AMPDU_TX_OPERATIONAL:
ret = 0;
break;
}
mutex_unlock(&priv->mutex);
return ret;
}
int iwl4965_mac_sta_add(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct iwl_priv *priv = hw->priv;
struct iwl_station_priv *sta_priv = (void *)sta->drv_priv;
struct iwl_vif_priv *vif_priv = (void *)vif->drv_priv;
bool is_ap = vif->type == NL80211_IFTYPE_STATION;
int ret;
u8 sta_id;
IWL_DEBUG_INFO(priv, "received request to add station %pM\n",
sta->addr);
mutex_lock(&priv->mutex);
IWL_DEBUG_INFO(priv, "proceeding to add station %pM\n",
sta->addr);
sta_priv->common.sta_id = IWL_INVALID_STATION;
atomic_set(&sta_priv->pending_frames, 0);
ret = iwl_legacy_add_station_common(priv, vif_priv->ctx, sta->addr,
is_ap, sta, &sta_id);
if (ret) {
IWL_ERR(priv, "Unable to add station %pM (%d)\n",
sta->addr, ret);
mutex_unlock(&priv->mutex);
return ret;
}
sta_priv->common.sta_id = sta_id;
IWL_DEBUG_INFO(priv, "Initializing rate scaling for station %pM\n",
sta->addr);
iwl4965_rs_rate_init(priv, sta, sta_id);
mutex_unlock(&priv->mutex);
return 0;
}
void iwl4965_mac_channel_switch(struct ieee80211_hw *hw,
struct ieee80211_channel_switch *ch_switch)
{
struct iwl_priv *priv = hw->priv;
const struct iwl_channel_info *ch_info;
struct ieee80211_conf *conf = &hw->conf;
struct ieee80211_channel *channel = ch_switch->channel;
struct iwl_ht_config *ht_conf = &priv->current_ht_config;
struct iwl_rxon_context *ctx = &priv->contexts[IWL_RXON_CTX_BSS];
u16 ch;
unsigned long flags = 0;
IWL_DEBUG_MAC80211(priv, "enter\n");
mutex_lock(&priv->mutex);
if (iwl_legacy_is_rfkill(priv))
goto out;
if (test_bit(STATUS_EXIT_PENDING, &priv->status) ||
test_bit(STATUS_SCANNING, &priv->status) ||
test_bit(STATUS_CHANNEL_SWITCH_PENDING, &priv->status))
goto out;
if (!iwl_legacy_is_associated_ctx(ctx))
goto out;
if (priv->cfg->ops->lib->set_channel_switch) {
ch = channel->hw_value;
if (le16_to_cpu(ctx->active.channel) != ch) {
ch_info = iwl_legacy_get_channel_info(priv,
channel->band,
ch);
if (!iwl_legacy_is_channel_valid(ch_info)) {
IWL_DEBUG_MAC80211(priv, "invalid channel\n");
goto out;
}
spin_lock_irqsave(&priv->lock, flags);
priv->current_ht_config.smps = conf->smps_mode;
ctx->ht.enabled = conf_is_ht(conf);
if (ctx->ht.enabled) {
if (conf_is_ht40_minus(conf)) {
ctx->ht.extension_chan_offset =
IEEE80211_HT_PARAM_CHA_SEC_BELOW;
ctx->ht.is_40mhz = true;
} else if (conf_is_ht40_plus(conf)) {
ctx->ht.extension_chan_offset =
IEEE80211_HT_PARAM_CHA_SEC_ABOVE;
ctx->ht.is_40mhz = true;
} else {
ctx->ht.extension_chan_offset =
IEEE80211_HT_PARAM_CHA_SEC_NONE;
ctx->ht.is_40mhz = false;
}
} else
ctx->ht.is_40mhz = false;
if ((le16_to_cpu(ctx->staging.channel) != ch))
ctx->staging.flags = 0;
iwl_legacy_set_rxon_channel(priv, channel, ctx);
iwl_legacy_set_rxon_ht(priv, ht_conf);
iwl_legacy_set_flags_for_band(priv, ctx, channel->band,
ctx->vif);
spin_unlock_irqrestore(&priv->lock, flags);
iwl_legacy_set_rate(priv);
set_bit(STATUS_CHANNEL_SWITCH_PENDING, &priv->status);
priv->switch_channel = cpu_to_le16(ch);
if (priv->cfg->ops->lib->set_channel_switch(priv, ch_switch)) {
clear_bit(STATUS_CHANNEL_SWITCH_PENDING,
&priv->status);
priv->switch_channel = 0;
ieee80211_chswitch_done(ctx->vif, false);
}
}
}
out:
mutex_unlock(&priv->mutex);
IWL_DEBUG_MAC80211(priv, "leave\n");
}
void iwl4965_configure_filter(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags,
u64 multicast)
{
struct iwl_priv *priv = hw->priv;
__le32 filter_or = 0, filter_nand = 0;
struct iwl_rxon_context *ctx;
#define CHK(test, flag) do { \
if (*total_flags & (test)) \
filter_or |= (flag); \
else \
filter_nand |= (flag); \
} while (0)
IWL_DEBUG_MAC80211(priv, "Enter: changed: 0x%x, total: 0x%x\n",
changed_flags, *total_flags);
CHK(FIF_OTHER_BSS | FIF_PROMISC_IN_BSS, RXON_FILTER_PROMISC_MSK);
CHK(FIF_CONTROL, RXON_FILTER_CTL2HOST_MSK | RXON_FILTER_PROMISC_MSK);
CHK(FIF_BCN_PRBRESP_PROMISC, RXON_FILTER_BCON_AWARE_MSK);
#undef CHK
mutex_lock(&priv->mutex);
for_each_context(priv, ctx) {
ctx->staging.filter_flags &= ~filter_nand;
ctx->staging.filter_flags |= filter_or;
}
mutex_unlock(&priv->mutex);
*total_flags &= FIF_OTHER_BSS | FIF_ALLMULTI | FIF_PROMISC_IN_BSS |
FIF_BCN_PRBRESP_PROMISC | FIF_CONTROL;
}
static void iwl4965_bg_txpower_work(struct work_struct *work)
{
struct iwl_priv *priv = container_of(work, struct iwl_priv,
txpower_work);
mutex_lock(&priv->mutex);
if (test_bit(STATUS_EXIT_PENDING, &priv->status) ||
test_bit(STATUS_SCANNING, &priv->status))
goto out;
priv->cfg->ops->lib->send_tx_power(priv);
priv->last_temperature = priv->temperature;
out:
mutex_unlock(&priv->mutex);
}
static void iwl4965_setup_deferred_work(struct iwl_priv *priv)
{
priv->workqueue = create_singlethread_workqueue(DRV_NAME);
init_waitqueue_head(&priv->wait_command_queue);
INIT_WORK(&priv->restart, iwl4965_bg_restart);
INIT_WORK(&priv->rx_replenish, iwl4965_bg_rx_replenish);
INIT_WORK(&priv->run_time_calib_work, iwl4965_bg_run_time_calib_work);
INIT_DELAYED_WORK(&priv->init_alive_start, iwl4965_bg_init_alive_start);
INIT_DELAYED_WORK(&priv->alive_start, iwl4965_bg_alive_start);
iwl_legacy_setup_scan_deferred_work(priv);
INIT_WORK(&priv->txpower_work, iwl4965_bg_txpower_work);
init_timer(&priv->statistics_periodic);
priv->statistics_periodic.data = (unsigned long)priv;
priv->statistics_periodic.function = iwl4965_bg_statistics_periodic;
init_timer(&priv->ucode_trace);
priv->ucode_trace.data = (unsigned long)priv;
priv->ucode_trace.function = iwl4965_bg_ucode_trace;
init_timer(&priv->watchdog);
priv->watchdog.data = (unsigned long)priv;
priv->watchdog.function = iwl_legacy_bg_watchdog;
tasklet_init(&priv->irq_tasklet, (void (*)(unsigned long))
iwl4965_irq_tasklet, (unsigned long)priv);
}
static void iwl4965_cancel_deferred_work(struct iwl_priv *priv)
{
cancel_work_sync(&priv->txpower_work);
cancel_delayed_work_sync(&priv->init_alive_start);
cancel_delayed_work(&priv->alive_start);
cancel_work_sync(&priv->run_time_calib_work);
iwl_legacy_cancel_scan_deferred_work(priv);
del_timer_sync(&priv->statistics_periodic);
del_timer_sync(&priv->ucode_trace);
}
static void iwl4965_init_hw_rates(struct iwl_priv *priv,
struct ieee80211_rate *rates)
{
int i;
for (i = 0; i < IWL_RATE_COUNT_LEGACY; i++) {
rates[i].bitrate = iwlegacy_rates[i].ieee * 5;
rates[i].hw_value = i;
rates[i].hw_value_short = i;
rates[i].flags = 0;
if ((i >= IWL_FIRST_CCK_RATE) && (i <= IWL_LAST_CCK_RATE)) {
rates[i].flags |=
(iwlegacy_rates[i].plcp == IWL_RATE_1M_PLCP) ?
0 : IEEE80211_RATE_SHORT_PREAMBLE;
}
}
}
void iwl4965_set_wr_ptrs(struct iwl_priv *priv, int txq_id, u32 index)
{
iwl_legacy_write_direct32(priv, HBUS_TARG_WRPTR,
(index & 0xff) | (txq_id << 8));
iwl_legacy_write_prph(priv, IWL49_SCD_QUEUE_RDPTR(txq_id), index);
}
void iwl4965_tx_queue_set_status(struct iwl_priv *priv,
struct iwl_tx_queue *txq,
int tx_fifo_id, int scd_retry)
{
int txq_id = txq->q.id;
int active = test_bit(txq_id, &priv->txq_ctx_active_msk) ? 1 : 0;
iwl_legacy_write_prph(priv, IWL49_SCD_QUEUE_STATUS_BITS(txq_id),
(active << IWL49_SCD_QUEUE_STTS_REG_POS_ACTIVE) |
(tx_fifo_id << IWL49_SCD_QUEUE_STTS_REG_POS_TXF) |
(scd_retry << IWL49_SCD_QUEUE_STTS_REG_POS_WSL) |
(scd_retry << IWL49_SCD_QUEUE_STTS_REG_POS_SCD_ACK) |
IWL49_SCD_QUEUE_STTS_REG_MSK);
txq->sched_retry = scd_retry;
IWL_DEBUG_INFO(priv, "%s %s Queue %d on AC %d\n",
active ? "Activate" : "Deactivate",
scd_retry ? "BA" : "AC", txq_id, tx_fifo_id);
}
static int iwl4965_init_drv(struct iwl_priv *priv)
{
int ret;
spin_lock_init(&priv->sta_lock);
spin_lock_init(&priv->hcmd_lock);
INIT_LIST_HEAD(&priv->free_frames);
mutex_init(&priv->mutex);
priv->ieee_channels = NULL;
priv->ieee_rates = NULL;
priv->band = IEEE80211_BAND_2GHZ;
priv->iw_mode = NL80211_IFTYPE_STATION;
priv->current_ht_config.smps = IEEE80211_SMPS_STATIC;
priv->missed_beacon_threshold = IWL_MISSED_BEACON_THRESHOLD_DEF;
priv->_4965.agg_tids_count = 0;
priv->force_reset[IWL_RF_RESET].reset_duration =
IWL_DELAY_NEXT_FORCE_RF_RESET;
priv->force_reset[IWL_FW_RESET].reset_duration =
IWL_DELAY_NEXT_FORCE_FW_RELOAD;
if (priv->cfg->ops->hcmd->set_rxon_chain)
priv->cfg->ops->hcmd->set_rxon_chain(priv,
&priv->contexts[IWL_RXON_CTX_BSS]);
iwl_legacy_init_scan_params(priv);
ret = iwl_legacy_init_channel_map(priv);
if (ret) {
IWL_ERR(priv, "initializing regulatory failed: %d\n", ret);
goto err;
}
ret = iwl_legacy_init_geos(priv);
if (ret) {
IWL_ERR(priv, "initializing geos failed: %d\n", ret);
goto err_free_channel_map;
}
iwl4965_init_hw_rates(priv, priv->ieee_rates);
return 0;
err_free_channel_map:
iwl_legacy_free_channel_map(priv);
err:
return ret;
}
static void iwl4965_uninit_drv(struct iwl_priv *priv)
{
iwl4965_calib_free_results(priv);
iwl_legacy_free_geos(priv);
iwl_legacy_free_channel_map(priv);
kfree(priv->scan_cmd);
}
static void iwl4965_hw_detect(struct iwl_priv *priv)
{
priv->hw_rev = _iwl_legacy_read32(priv, CSR_HW_REV);
priv->hw_wa_rev = _iwl_legacy_read32(priv, CSR_HW_REV_WA_REG);
priv->rev_id = priv->pci_dev->revision;
IWL_DEBUG_INFO(priv, "HW Revision ID = 0x%X\n", priv->rev_id);
}
static int iwl4965_set_hw_params(struct iwl_priv *priv)
{
priv->hw_params.max_rxq_size = RX_QUEUE_SIZE;
priv->hw_params.max_rxq_log = RX_QUEUE_SIZE_LOG;
if (priv->cfg->mod_params->amsdu_size_8K)
priv->hw_params.rx_page_order = get_order(IWL_RX_BUF_SIZE_8K);
else
priv->hw_params.rx_page_order = get_order(IWL_RX_BUF_SIZE_4K);
priv->hw_params.max_beacon_itrvl = IWL_MAX_UCODE_BEACON_INTERVAL;
if (priv->cfg->mod_params->disable_11n)
priv->cfg->sku &= ~IWL_SKU_N;
return priv->cfg->ops->lib->set_hw_params(priv);
}
static int
iwl4965_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int err = 0, i;
struct iwl_priv *priv;
struct ieee80211_hw *hw;
struct iwl_cfg *cfg = (struct iwl_cfg *)(ent->driver_data);
unsigned long flags;
u16 pci_cmd;
hw = iwl_legacy_alloc_all(cfg);
if (!hw) {
err = -ENOMEM;
goto out;
}
priv = hw->priv;
priv->valid_contexts = BIT(IWL_RXON_CTX_BSS);
for (i = 0; i < NUM_IWL_RXON_CTX; i++)
priv->contexts[i].ctxid = i;
priv->contexts[IWL_RXON_CTX_BSS].always_active = true;
priv->contexts[IWL_RXON_CTX_BSS].is_active = true;
priv->contexts[IWL_RXON_CTX_BSS].rxon_cmd = REPLY_RXON;
priv->contexts[IWL_RXON_CTX_BSS].rxon_timing_cmd = REPLY_RXON_TIMING;
priv->contexts[IWL_RXON_CTX_BSS].rxon_assoc_cmd = REPLY_RXON_ASSOC;
priv->contexts[IWL_RXON_CTX_BSS].qos_cmd = REPLY_QOS_PARAM;
priv->contexts[IWL_RXON_CTX_BSS].ap_sta_id = IWL_AP_ID;
priv->contexts[IWL_RXON_CTX_BSS].wep_key_cmd = REPLY_WEPKEY;
priv->contexts[IWL_RXON_CTX_BSS].ac_to_fifo = iwl4965_bss_ac_to_fifo;
priv->contexts[IWL_RXON_CTX_BSS].ac_to_queue = iwl4965_bss_ac_to_queue;
priv->contexts[IWL_RXON_CTX_BSS].exclusive_interface_modes =
BIT(NL80211_IFTYPE_ADHOC);
priv->contexts[IWL_RXON_CTX_BSS].interface_modes =
BIT(NL80211_IFTYPE_STATION);
priv->contexts[IWL_RXON_CTX_BSS].ap_devtype = RXON_DEV_TYPE_AP;
priv->contexts[IWL_RXON_CTX_BSS].ibss_devtype = RXON_DEV_TYPE_IBSS;
priv->contexts[IWL_RXON_CTX_BSS].station_devtype = RXON_DEV_TYPE_ESS;
priv->contexts[IWL_RXON_CTX_BSS].unused_devtype = RXON_DEV_TYPE_ESS;
BUILD_BUG_ON(NUM_IWL_RXON_CTX != 1);
SET_IEEE80211_DEV(hw, &pdev->dev);
IWL_DEBUG_INFO(priv, "*** LOAD DRIVER ***\n");
priv->cfg = cfg;
priv->pci_dev = pdev;
priv->inta_mask = CSR_INI_SET_MASK;
if (iwl_legacy_alloc_traffic_mem(priv))
IWL_ERR(priv, "Not enough memory to generate traffic log\n");
pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S | PCIE_LINK_STATE_L1 |
PCIE_LINK_STATE_CLKPM);
if (pci_enable_device(pdev)) {
err = -ENODEV;
goto out_ieee80211_free_hw;
}
pci_set_master(pdev);
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(36));
if (!err)
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(36));
if (err) {
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (!err)
err = pci_set_consistent_dma_mask(pdev,
DMA_BIT_MASK(32));
if (err) {
IWL_WARN(priv, "No suitable DMA available.\n");
goto out_pci_disable_device;
}
}
err = pci_request_regions(pdev, DRV_NAME);
if (err)
goto out_pci_disable_device;
pci_set_drvdata(pdev, priv);
priv->hw_base = pci_iomap(pdev, 0, 0);
if (!priv->hw_base) {
err = -ENODEV;
goto out_pci_release_regions;
}
IWL_DEBUG_INFO(priv, "pci_resource_len = 0x%08llx\n",
(unsigned long long) pci_resource_len(pdev, 0));
IWL_DEBUG_INFO(priv, "pci_resource_base = %p\n", priv->hw_base);
spin_lock_init(&priv->reg_lock);
spin_lock_init(&priv->lock);
iwl_write32(priv, CSR_RESET, CSR_RESET_REG_FLAG_NEVO_RESET);
iwl4965_hw_detect(priv);
IWL_INFO(priv, "Detected %s, REV=0x%X\n",
priv->cfg->name, priv->hw_rev);
pci_write_config_byte(pdev, PCI_CFG_RETRY_TIMEOUT, 0x00);
iwl4965_prepare_card_hw(priv);
if (!priv->hw_ready) {
IWL_WARN(priv, "Failed, HW not ready\n");
goto out_iounmap;
}
err = iwl_legacy_eeprom_init(priv);
if (err) {
IWL_ERR(priv, "Unable to init EEPROM\n");
goto out_iounmap;
}
err = iwl4965_eeprom_check_version(priv);
if (err)
goto out_free_eeprom;
if (err)
goto out_free_eeprom;
iwl4965_eeprom_get_mac(priv, priv->addresses[0].addr);
IWL_DEBUG_INFO(priv, "MAC address: %pM\n", priv->addresses[0].addr);
priv->hw->wiphy->addresses = priv->addresses;
priv->hw->wiphy->n_addresses = 1;
if (iwl4965_set_hw_params(priv)) {
IWL_ERR(priv, "failed to set hw parameters\n");
goto out_free_eeprom;
}
err = iwl4965_init_drv(priv);
if (err)
goto out_free_eeprom;
spin_lock_irqsave(&priv->lock, flags);
iwl_legacy_disable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
pci_enable_msi(priv->pci_dev);
err = request_irq(priv->pci_dev->irq, iwl_legacy_isr,
IRQF_SHARED, DRV_NAME, priv);
if (err) {
IWL_ERR(priv, "Error allocating IRQ %d\n", priv->pci_dev->irq);
goto out_disable_msi;
}
iwl4965_setup_deferred_work(priv);
iwl4965_setup_rx_handlers(priv);
pci_read_config_word(priv->pci_dev, PCI_COMMAND, &pci_cmd);
if (pci_cmd & PCI_COMMAND_INTX_DISABLE) {
pci_cmd &= ~PCI_COMMAND_INTX_DISABLE;
pci_write_config_word(priv->pci_dev, PCI_COMMAND, pci_cmd);
}
iwl_legacy_enable_rfkill_int(priv);
if (iwl_read32(priv, CSR_GP_CNTRL) &
CSR_GP_CNTRL_REG_FLAG_HW_RF_KILL_SW)
clear_bit(STATUS_RF_KILL_HW, &priv->status);
else
set_bit(STATUS_RF_KILL_HW, &priv->status);
wiphy_rfkill_set_hw_state(priv->hw->wiphy,
test_bit(STATUS_RF_KILL_HW, &priv->status));
iwl_legacy_power_initialize(priv);
init_completion(&priv->_4965.firmware_loading_complete);
err = iwl4965_request_firmware(priv, true);
if (err)
goto out_destroy_workqueue;
return 0;
out_destroy_workqueue:
destroy_workqueue(priv->workqueue);
priv->workqueue = NULL;
free_irq(priv->pci_dev->irq, priv);
out_disable_msi:
pci_disable_msi(priv->pci_dev);
iwl4965_uninit_drv(priv);
out_free_eeprom:
iwl_legacy_eeprom_free(priv);
out_iounmap:
pci_iounmap(pdev, priv->hw_base);
out_pci_release_regions:
pci_set_drvdata(pdev, NULL);
pci_release_regions(pdev);
out_pci_disable_device:
pci_disable_device(pdev);
out_ieee80211_free_hw:
iwl_legacy_free_traffic_mem(priv);
ieee80211_free_hw(priv->hw);
out:
return err;
}
static void __devexit iwl4965_pci_remove(struct pci_dev *pdev)
{
struct iwl_priv *priv = pci_get_drvdata(pdev);
unsigned long flags;
if (!priv)
return;
wait_for_completion(&priv->_4965.firmware_loading_complete);
IWL_DEBUG_INFO(priv, "*** UNLOAD DRIVER ***\n");
iwl_legacy_dbgfs_unregister(priv);
sysfs_remove_group(&pdev->dev.kobj, &iwl_attribute_group);
set_bit(STATUS_EXIT_PENDING, &priv->status);
iwl_legacy_leds_exit(priv);
if (priv->mac80211_registered) {
ieee80211_unregister_hw(priv->hw);
priv->mac80211_registered = 0;
} else {
iwl4965_down(priv);
}
iwl_legacy_apm_stop(priv);
spin_lock_irqsave(&priv->lock, flags);
iwl_legacy_disable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
iwl4965_synchronize_irq(priv);
iwl4965_dealloc_ucode_pci(priv);
if (priv->rxq.bd)
iwl4965_rx_queue_free(priv, &priv->rxq);
iwl4965_hw_txq_ctx_free(priv);
iwl_legacy_eeprom_free(priv);
flush_workqueue(priv->workqueue);
destroy_workqueue(priv->workqueue);
priv->workqueue = NULL;
iwl_legacy_free_traffic_mem(priv);
free_irq(priv->pci_dev->irq, priv);
pci_disable_msi(priv->pci_dev);
pci_iounmap(pdev, priv->hw_base);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
iwl4965_uninit_drv(priv);
dev_kfree_skb(priv->beacon_skb);
ieee80211_free_hw(priv->hw);
}
void iwl4965_txq_set_sched(struct iwl_priv *priv, u32 mask)
{
iwl_legacy_write_prph(priv, IWL49_SCD_TXFACT, mask);
}
static int __init iwl4965_init(void)
{
int ret;
pr_info(DRV_DESCRIPTION ", " DRV_VERSION "\n");
pr_info(DRV_COPYRIGHT "\n");
ret = iwl4965_rate_control_register();
if (ret) {
pr_err("Unable to register rate control algorithm: %d\n", ret);
return ret;
}
ret = pci_register_driver(&iwl4965_driver);
if (ret) {
pr_err("Unable to initialize PCI module\n");
goto error_register;
}
return ret;
error_register:
iwl4965_rate_control_unregister();
return ret;
}
static void __exit iwl4965_exit(void)
{
pci_unregister_driver(&iwl4965_driver);
iwl4965_rate_control_unregister();
}
