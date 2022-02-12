static int iwl_rx_queue_space(const struct iwl_rx_queue *q)
{
int s = q->read - q->write;
if (s <= 0)
s += RX_QUEUE_SIZE;
s -= 2;
if (s < 0)
s = 0;
return s;
}
void iwl_rx_queue_update_write_ptr(struct iwl_trans *trans,
struct iwl_rx_queue *q)
{
unsigned long flags;
u32 reg;
spin_lock_irqsave(&q->lock, flags);
if (q->need_update == 0)
goto exit_unlock;
if (hw_params(trans).shadow_reg_enable) {
q->write_actual = (q->write & ~0x7);
iwl_write32(bus(trans), FH_RSCSR_CHNL0_WPTR, q->write_actual);
} else {
if (test_bit(STATUS_POWER_PMI, &trans->shrd->status)) {
reg = iwl_read32(bus(trans), CSR_UCODE_DRV_GP1);
if (reg & CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP) {
IWL_DEBUG_INFO(trans,
"Rx queue requesting wakeup,"
" GP1 = 0x%x\n", reg);
iwl_set_bit(bus(trans), CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
goto exit_unlock;
}
q->write_actual = (q->write & ~0x7);
iwl_write_direct32(bus(trans), FH_RSCSR_CHNL0_WPTR,
q->write_actual);
} else {
q->write_actual = (q->write & ~0x7);
iwl_write_direct32(bus(trans), FH_RSCSR_CHNL0_WPTR,
q->write_actual);
}
}
q->need_update = 0;
exit_unlock:
spin_unlock_irqrestore(&q->lock, flags);
}
static inline __le32 iwlagn_dma_addr2rbd_ptr(dma_addr_t dma_addr)
{
return cpu_to_le32((u32)(dma_addr >> 8));
}
static void iwlagn_rx_queue_restock(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_rx_queue *rxq = &trans_pcie->rxq;
struct list_head *element;
struct iwl_rx_mem_buffer *rxb;
unsigned long flags;
spin_lock_irqsave(&rxq->lock, flags);
while ((iwl_rx_queue_space(rxq) > 0) && (rxq->free_count)) {
rxb = rxq->queue[rxq->write];
BUG_ON(rxb && rxb->page);
element = rxq->rx_free.next;
rxb = list_entry(element, struct iwl_rx_mem_buffer, list);
list_del(element);
rxq->bd[rxq->write] = iwlagn_dma_addr2rbd_ptr(rxb->page_dma);
rxq->queue[rxq->write] = rxb;
rxq->write = (rxq->write + 1) & RX_QUEUE_MASK;
rxq->free_count--;
}
spin_unlock_irqrestore(&rxq->lock, flags);
if (rxq->free_count <= RX_LOW_WATERMARK)
queue_work(trans->shrd->workqueue, &trans_pcie->rx_replenish);
if (rxq->write_actual != (rxq->write & ~0x7)) {
spin_lock_irqsave(&rxq->lock, flags);
rxq->need_update = 1;
spin_unlock_irqrestore(&rxq->lock, flags);
iwl_rx_queue_update_write_ptr(trans, rxq);
}
}
static void iwlagn_rx_allocate(struct iwl_trans *trans, gfp_t priority)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_rx_queue *rxq = &trans_pcie->rxq;
struct list_head *element;
struct iwl_rx_mem_buffer *rxb;
struct page *page;
unsigned long flags;
gfp_t gfp_mask = priority;
while (1) {
spin_lock_irqsave(&rxq->lock, flags);
if (list_empty(&rxq->rx_used)) {
spin_unlock_irqrestore(&rxq->lock, flags);
return;
}
spin_unlock_irqrestore(&rxq->lock, flags);
if (rxq->free_count > RX_LOW_WATERMARK)
gfp_mask |= __GFP_NOWARN;
if (hw_params(trans).rx_page_order > 0)
gfp_mask |= __GFP_COMP;
page = alloc_pages(gfp_mask,
hw_params(trans).rx_page_order);
if (!page) {
if (net_ratelimit())
IWL_DEBUG_INFO(trans, "alloc_pages failed, "
"order: %d\n",
hw_params(trans).rx_page_order);
if ((rxq->free_count <= RX_LOW_WATERMARK) &&
net_ratelimit())
IWL_CRIT(trans, "Failed to alloc_pages with %s."
"Only %u free buffers remaining.\n",
priority == GFP_ATOMIC ?
"GFP_ATOMIC" : "GFP_KERNEL",
rxq->free_count);
return;
}
spin_lock_irqsave(&rxq->lock, flags);
if (list_empty(&rxq->rx_used)) {
spin_unlock_irqrestore(&rxq->lock, flags);
__free_pages(page, hw_params(trans).rx_page_order);
return;
}
element = rxq->rx_used.next;
rxb = list_entry(element, struct iwl_rx_mem_buffer, list);
list_del(element);
spin_unlock_irqrestore(&rxq->lock, flags);
BUG_ON(rxb->page);
rxb->page = page;
rxb->page_dma = dma_map_page(bus(trans)->dev, page, 0,
PAGE_SIZE << hw_params(trans).rx_page_order,
DMA_FROM_DEVICE);
BUG_ON(rxb->page_dma & ~DMA_BIT_MASK(36));
BUG_ON(rxb->page_dma & DMA_BIT_MASK(8));
spin_lock_irqsave(&rxq->lock, flags);
list_add_tail(&rxb->list, &rxq->rx_free);
rxq->free_count++;
spin_unlock_irqrestore(&rxq->lock, flags);
}
}
void iwlagn_rx_replenish(struct iwl_trans *trans)
{
unsigned long flags;
iwlagn_rx_allocate(trans, GFP_KERNEL);
spin_lock_irqsave(&trans->shrd->lock, flags);
iwlagn_rx_queue_restock(trans);
spin_unlock_irqrestore(&trans->shrd->lock, flags);
}
static void iwlagn_rx_replenish_now(struct iwl_trans *trans)
{
iwlagn_rx_allocate(trans, GFP_ATOMIC);
iwlagn_rx_queue_restock(trans);
}
void iwl_bg_rx_replenish(struct work_struct *data)
{
struct iwl_trans_pcie *trans_pcie =
container_of(data, struct iwl_trans_pcie, rx_replenish);
struct iwl_trans *trans = trans_pcie->trans;
if (test_bit(STATUS_EXIT_PENDING, &trans->shrd->status))
return;
mutex_lock(&trans->shrd->mutex);
iwlagn_rx_replenish(trans);
mutex_unlock(&trans->shrd->mutex);
}
static void iwl_rx_handle(struct iwl_trans *trans)
{
struct iwl_rx_mem_buffer *rxb;
struct iwl_rx_packet *pkt;
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_rx_queue *rxq = &trans_pcie->rxq;
struct iwl_tx_queue *txq = &trans_pcie->txq[trans->shrd->cmd_queue];
struct iwl_device_cmd *cmd;
u32 r, i;
int reclaim;
unsigned long flags;
u8 fill_rx = 0;
u32 count = 8;
int total_empty;
int index, cmd_index;
r = le16_to_cpu(rxq->rb_stts->closed_rb_num) & 0x0FFF;
i = rxq->read;
if (i == r)
IWL_DEBUG_RX(trans, "r = %d, i = %d\n", r, i);
total_empty = r - rxq->write_actual;
if (total_empty < 0)
total_empty += RX_QUEUE_SIZE;
if (total_empty > (RX_QUEUE_SIZE / 2))
fill_rx = 1;
while (i != r) {
int len, err;
u16 sequence;
rxb = rxq->queue[i];
if (WARN_ON(rxb == NULL)) {
i = (i + 1) & RX_QUEUE_MASK;
continue;
}
rxq->queue[i] = NULL;
dma_unmap_page(bus(trans)->dev, rxb->page_dma,
PAGE_SIZE << hw_params(trans).rx_page_order,
DMA_FROM_DEVICE);
pkt = rxb_addr(rxb);
IWL_DEBUG_RX(trans, "r = %d, i = %d, %s, 0x%02x\n", r,
i, get_cmd_string(pkt->hdr.cmd), pkt->hdr.cmd);
len = le32_to_cpu(pkt->len_n_flags) & FH_RSCSR_FRAME_SIZE_MSK;
len += sizeof(u32);
trace_iwlwifi_dev_rx(priv(trans), pkt, len);
reclaim = !(pkt->hdr.sequence & SEQ_RX_FRAME) &&
(pkt->hdr.cmd != REPLY_RX_PHY_CMD) &&
(pkt->hdr.cmd != REPLY_RX) &&
(pkt->hdr.cmd != REPLY_RX_MPDU_CMD) &&
(pkt->hdr.cmd != REPLY_COMPRESSED_BA) &&
(pkt->hdr.cmd != STATISTICS_NOTIFICATION) &&
(pkt->hdr.cmd != REPLY_TX);
sequence = le16_to_cpu(pkt->hdr.sequence);
index = SEQ_TO_INDEX(sequence);
cmd_index = get_cmd_index(&txq->q, index);
if (reclaim)
cmd = txq->cmd[cmd_index];
else
cmd = NULL;
WARN(pkt->hdr.cmd != REPLY_TX && reclaim == false &&
(!(pkt->hdr.sequence & SEQ_RX_FRAME)),
"reclaim is false, SEQ_RX_FRAME unset: %s\n",
get_cmd_string(pkt->hdr.cmd));
err = iwl_rx_dispatch(priv(trans), rxb, cmd);
if (reclaim) {
if (rxb->page)
iwl_tx_cmd_complete(trans, rxb, err);
else
IWL_WARN(trans, "Claim null rxb?\n");
}
spin_lock_irqsave(&rxq->lock, flags);
if (rxb->page != NULL) {
rxb->page_dma = dma_map_page(bus(trans)->dev, rxb->page,
0, PAGE_SIZE <<
hw_params(trans).rx_page_order,
DMA_FROM_DEVICE);
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
iwlagn_rx_replenish_now(trans);
count = 0;
}
}
}
rxq->read = i;
if (fill_rx)
iwlagn_rx_replenish_now(trans);
else
iwlagn_rx_queue_restock(trans);
}
static const char *desc_lookup(u32 num)
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
static void iwl_dump_nic_error_log(struct iwl_trans *trans)
{
u32 base;
struct iwl_error_event_table table;
struct iwl_priv *priv = priv(trans);
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
base = priv->device_pointers.error_event_table;
if (priv->ucode_type == IWL_UCODE_INIT) {
if (!base)
base = priv->init_errlog_ptr;
} else {
if (!base)
base = priv->inst_errlog_ptr;
}
if (!iwlagn_hw_valid_rtc_data_addr(base)) {
IWL_ERR(trans,
"Not valid error log pointer 0x%08X for %s uCode\n",
base,
(priv->ucode_type == IWL_UCODE_INIT)
? "Init" : "RT");
return;
}
iwl_read_targ_mem_words(bus(priv), base, &table, sizeof(table));
if (ERROR_START_OFFSET <= table.valid * ERROR_ELEM_SIZE) {
IWL_ERR(trans, "Start IWL Error Log Dump:\n");
IWL_ERR(trans, "Status: 0x%08lX, count: %d\n",
trans->shrd->status, table.valid);
}
trans_pcie->isr_stats.err_code = table.error_id;
trace_iwlwifi_dev_ucode_error(priv, table.error_id, table.tsf_low,
table.data1, table.data2, table.line,
table.blink1, table.blink2, table.ilink1,
table.ilink2, table.bcon_time, table.gp1,
table.gp2, table.gp3, table.ucode_ver,
table.hw_ver, table.brd_ver);
IWL_ERR(trans, "0x%08X | %-28s\n", table.error_id,
desc_lookup(table.error_id));
IWL_ERR(trans, "0x%08X | uPc\n", table.pc);
IWL_ERR(trans, "0x%08X | branchlink1\n", table.blink1);
IWL_ERR(trans, "0x%08X | branchlink2\n", table.blink2);
IWL_ERR(trans, "0x%08X | interruptlink1\n", table.ilink1);
IWL_ERR(trans, "0x%08X | interruptlink2\n", table.ilink2);
IWL_ERR(trans, "0x%08X | data1\n", table.data1);
IWL_ERR(trans, "0x%08X | data2\n", table.data2);
IWL_ERR(trans, "0x%08X | line\n", table.line);
IWL_ERR(trans, "0x%08X | beacon time\n", table.bcon_time);
IWL_ERR(trans, "0x%08X | tsf low\n", table.tsf_low);
IWL_ERR(trans, "0x%08X | tsf hi\n", table.tsf_hi);
IWL_ERR(trans, "0x%08X | time gp1\n", table.gp1);
IWL_ERR(trans, "0x%08X | time gp2\n", table.gp2);
IWL_ERR(trans, "0x%08X | time gp3\n", table.gp3);
IWL_ERR(trans, "0x%08X | uCode version\n", table.ucode_ver);
IWL_ERR(trans, "0x%08X | hw version\n", table.hw_ver);
IWL_ERR(trans, "0x%08X | board version\n", table.brd_ver);
IWL_ERR(trans, "0x%08X | hcmd\n", table.hcmd);
}
static void iwl_irq_handle_error(struct iwl_trans *trans)
{
struct iwl_priv *priv = priv(trans);
if (priv->cfg->internal_wimax_coex &&
(!(iwl_read_prph(bus(trans), APMG_CLK_CTRL_REG) &
APMS_CLK_VAL_MRB_FUNC_MODE) ||
(iwl_read_prph(bus(trans), APMG_PS_CTRL_REG) &
APMG_PS_CTRL_VAL_RESET_REQ))) {
clear_bit(STATUS_READY, &trans->shrd->status);
clear_bit(STATUS_HCMD_ACTIVE, &trans->shrd->status);
wake_up(&priv->shrd->wait_command_queue);
IWL_ERR(trans, "RF is used by WiMAX\n");
return;
}
IWL_ERR(trans, "Loaded firmware version: %s\n",
priv->hw->wiphy->fw_version);
iwl_dump_nic_error_log(trans);
iwl_dump_csr(trans);
iwl_dump_fh(trans, NULL, false);
iwl_dump_nic_event_log(trans, false, NULL, false);
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_get_debug_level(trans->shrd) & IWL_DL_FW_ERRORS)
iwl_print_rx_config_cmd(priv(trans), IWL_RXON_CTX_BSS);
#endif
iwlagn_fw_error(priv, false);
}
static int iwl_print_event_log(struct iwl_trans *trans, u32 start_idx,
u32 num_events, u32 mode,
int pos, char **buf, size_t bufsz)
{
u32 i;
u32 base;
u32 event_size;
u32 ptr;
u32 ev, time, data;
unsigned long reg_flags;
struct iwl_priv *priv = priv(trans);
if (num_events == 0)
return pos;
base = priv->device_pointers.log_event_table;
if (priv->ucode_type == IWL_UCODE_INIT) {
if (!base)
base = priv->init_evtlog_ptr;
} else {
if (!base)
base = priv->inst_evtlog_ptr;
}
if (mode == 0)
event_size = 2 * sizeof(u32);
else
event_size = 3 * sizeof(u32);
ptr = base + EVENT_START_OFFSET + (start_idx * event_size);
spin_lock_irqsave(&bus(trans)->reg_lock, reg_flags);
iwl_grab_nic_access(bus(trans));
iwl_write32(bus(trans), HBUS_TARG_MEM_RADDR, ptr);
rmb();
for (i = 0; i < num_events; i++) {
ev = iwl_read32(bus(trans), HBUS_TARG_MEM_RDAT);
time = iwl_read32(bus(trans), HBUS_TARG_MEM_RDAT);
if (mode == 0) {
if (bufsz) {
pos += scnprintf(*buf + pos, bufsz - pos,
"EVT_LOG:0x%08x:%04u\n",
time, ev);
} else {
trace_iwlwifi_dev_ucode_event(priv, 0,
time, ev);
IWL_ERR(trans, "EVT_LOG:0x%08x:%04u\n",
time, ev);
}
} else {
data = iwl_read32(bus(trans), HBUS_TARG_MEM_RDAT);
if (bufsz) {
pos += scnprintf(*buf + pos, bufsz - pos,
"EVT_LOGT:%010u:0x%08x:%04u\n",
time, data, ev);
} else {
IWL_ERR(trans, "EVT_LOGT:%010u:0x%08x:%04u\n",
time, data, ev);
trace_iwlwifi_dev_ucode_event(priv, time,
data, ev);
}
}
}
iwl_release_nic_access(bus(trans));
spin_unlock_irqrestore(&bus(trans)->reg_lock, reg_flags);
return pos;
}
static int iwl_print_last_event_logs(struct iwl_trans *trans, u32 capacity,
u32 num_wraps, u32 next_entry,
u32 size, u32 mode,
int pos, char **buf, size_t bufsz)
{
if (num_wraps) {
if (next_entry < size) {
pos = iwl_print_event_log(trans,
capacity - (size - next_entry),
size - next_entry, mode,
pos, buf, bufsz);
pos = iwl_print_event_log(trans, 0,
next_entry, mode,
pos, buf, bufsz);
} else
pos = iwl_print_event_log(trans, next_entry - size,
size, mode, pos, buf, bufsz);
} else {
if (next_entry < size) {
pos = iwl_print_event_log(trans, 0, next_entry,
mode, pos, buf, bufsz);
} else {
pos = iwl_print_event_log(trans, next_entry - size,
size, mode, pos, buf, bufsz);
}
}
return pos;
}
int iwl_dump_nic_event_log(struct iwl_trans *trans, bool full_log,
char **buf, bool display)
{
u32 base;
u32 capacity;
u32 mode;
u32 num_wraps;
u32 next_entry;
u32 size;
u32 logsize;
int pos = 0;
size_t bufsz = 0;
struct iwl_priv *priv = priv(trans);
base = priv->device_pointers.log_event_table;
if (priv->ucode_type == IWL_UCODE_INIT) {
logsize = priv->init_evtlog_size;
if (!base)
base = priv->init_evtlog_ptr;
} else {
logsize = priv->inst_evtlog_size;
if (!base)
base = priv->inst_evtlog_ptr;
}
if (!iwlagn_hw_valid_rtc_data_addr(base)) {
IWL_ERR(trans,
"Invalid event log pointer 0x%08X for %s uCode\n",
base,
(priv->ucode_type == IWL_UCODE_INIT)
? "Init" : "RT");
return -EINVAL;
}
capacity = iwl_read_targ_mem(bus(trans), base);
mode = iwl_read_targ_mem(bus(trans), base + (1 * sizeof(u32)));
num_wraps = iwl_read_targ_mem(bus(trans), base + (2 * sizeof(u32)));
next_entry = iwl_read_targ_mem(bus(trans), base + (3 * sizeof(u32)));
if (capacity > logsize) {
IWL_ERR(trans, "Log capacity %d is bogus, limit to %d "
"entries\n", capacity, logsize);
capacity = logsize;
}
if (next_entry > logsize) {
IWL_ERR(trans, "Log write index %d is bogus, limit to %d\n",
next_entry, logsize);
next_entry = logsize;
}
size = num_wraps ? capacity : next_entry;
if (size == 0) {
IWL_ERR(trans, "Start IWL Event Log Dump: nothing in log\n");
return pos;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (!(iwl_get_debug_level(trans->shrd) & IWL_DL_FW_ERRORS) && !full_log)
size = (size > DEFAULT_DUMP_EVENT_LOG_ENTRIES)
? DEFAULT_DUMP_EVENT_LOG_ENTRIES : size;
#else
size = (size > DEFAULT_DUMP_EVENT_LOG_ENTRIES)
? DEFAULT_DUMP_EVENT_LOG_ENTRIES : size;
#endif
IWL_ERR(trans, "Start IWL Event Log Dump: display last %u entries\n",
size);
#ifdef CONFIG_IWLWIFI_DEBUG
if (display) {
if (full_log)
bufsz = capacity * 48;
else
bufsz = size * 48;
*buf = kmalloc(bufsz, GFP_KERNEL);
if (!*buf)
return -ENOMEM;
}
if ((iwl_get_debug_level(trans->shrd) & IWL_DL_FW_ERRORS) || full_log) {
if (num_wraps)
pos = iwl_print_event_log(trans, next_entry,
capacity - next_entry, mode,
pos, buf, bufsz);
pos = iwl_print_event_log(trans, 0,
next_entry, mode, pos, buf, bufsz);
} else
pos = iwl_print_last_event_logs(trans, capacity, num_wraps,
next_entry, size, mode,
pos, buf, bufsz);
#else
pos = iwl_print_last_event_logs(trans, capacity, num_wraps,
next_entry, size, mode,
pos, buf, bufsz);
#endif
return pos;
}
void iwl_irq_tasklet(struct iwl_trans *trans)
{
u32 inta = 0;
u32 handled = 0;
unsigned long flags;
u32 i;
#ifdef CONFIG_IWLWIFI_DEBUG
u32 inta_mask;
#endif
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct isr_statistics *isr_stats = &trans_pcie->isr_stats;
spin_lock_irqsave(&trans->shrd->lock, flags);
iwl_write32(bus(trans), CSR_INT,
trans_pcie->inta | ~trans_pcie->inta_mask);
inta = trans_pcie->inta;
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_get_debug_level(trans->shrd) & IWL_DL_ISR) {
inta_mask = iwl_read32(bus(trans), CSR_INT_MASK);
IWL_DEBUG_ISR(trans, "inta 0x%08x, enabled 0x%08x\n ",
inta, inta_mask);
}
#endif
spin_unlock_irqrestore(&trans->shrd->lock, flags);
trans_pcie->inta = 0;
if (inta & CSR_INT_BIT_HW_ERR) {
IWL_ERR(trans, "Hardware error detected. Restarting.\n");
iwl_disable_interrupts(trans);
isr_stats->hw++;
iwl_irq_handle_error(trans);
handled |= CSR_INT_BIT_HW_ERR;
return;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_get_debug_level(trans->shrd) & (IWL_DL_ISR)) {
if (inta & CSR_INT_BIT_SCD) {
IWL_DEBUG_ISR(trans, "Scheduler finished to transmit "
"the frame/frames.\n");
isr_stats->sch++;
}
if (inta & CSR_INT_BIT_ALIVE) {
IWL_DEBUG_ISR(trans, "Alive interrupt\n");
isr_stats->alive++;
}
}
#endif
inta &= ~(CSR_INT_BIT_SCD | CSR_INT_BIT_ALIVE);
if (inta & CSR_INT_BIT_RF_KILL) {
int hw_rf_kill = 0;
if (!(iwl_read32(bus(trans), CSR_GP_CNTRL) &
CSR_GP_CNTRL_REG_FLAG_HW_RF_KILL_SW))
hw_rf_kill = 1;
IWL_WARN(trans, "RF_KILL bit toggled to %s.\n",
hw_rf_kill ? "disable radio" : "enable radio");
isr_stats->rfkill++;
if (!test_bit(STATUS_ALIVE, &trans->shrd->status)) {
if (hw_rf_kill)
set_bit(STATUS_RF_KILL_HW,
&trans->shrd->status);
else
clear_bit(STATUS_RF_KILL_HW,
&trans->shrd->status);
iwl_set_hw_rfkill_state(priv(trans), hw_rf_kill);
}
handled |= CSR_INT_BIT_RF_KILL;
}
if (inta & CSR_INT_BIT_CT_KILL) {
IWL_ERR(trans, "Microcode CT kill error detected.\n");
isr_stats->ctkill++;
handled |= CSR_INT_BIT_CT_KILL;
}
if (inta & CSR_INT_BIT_SW_ERR) {
IWL_ERR(trans, "Microcode SW error detected. "
" Restarting 0x%X.\n", inta);
isr_stats->sw++;
iwl_irq_handle_error(trans);
handled |= CSR_INT_BIT_SW_ERR;
}
if (inta & CSR_INT_BIT_WAKEUP) {
IWL_DEBUG_ISR(trans, "Wakeup interrupt\n");
iwl_rx_queue_update_write_ptr(trans, &trans_pcie->rxq);
for (i = 0; i < hw_params(trans).max_txq_num; i++)
iwl_txq_update_write_ptr(trans,
&trans_pcie->txq[i]);
isr_stats->wakeup++;
handled |= CSR_INT_BIT_WAKEUP;
}
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX |
CSR_INT_BIT_RX_PERIODIC)) {
IWL_DEBUG_ISR(trans, "Rx interrupt\n");
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX)) {
handled |= (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX);
iwl_write32(bus(trans), CSR_FH_INT_STATUS,
CSR_FH_INT_RX_MASK);
}
if (inta & CSR_INT_BIT_RX_PERIODIC) {
handled |= CSR_INT_BIT_RX_PERIODIC;
iwl_write32(bus(trans),
CSR_INT, CSR_INT_BIT_RX_PERIODIC);
}
iwl_write8(bus(trans), CSR_INT_PERIODIC_REG,
CSR_INT_PERIODIC_DIS);
iwl_rx_handle(trans);
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX))
iwl_write8(bus(trans), CSR_INT_PERIODIC_REG,
CSR_INT_PERIODIC_ENA);
isr_stats->rx++;
}
if (inta & CSR_INT_BIT_FH_TX) {
iwl_write32(bus(trans), CSR_FH_INT_STATUS, CSR_FH_INT_TX_MASK);
IWL_DEBUG_ISR(trans, "uCode load interrupt\n");
isr_stats->tx++;
handled |= CSR_INT_BIT_FH_TX;
priv(trans)->ucode_write_complete = 1;
wake_up(&trans->shrd->wait_command_queue);
}
if (inta & ~handled) {
IWL_ERR(trans, "Unhandled INTA bits 0x%08x\n", inta & ~handled);
isr_stats->unhandled++;
}
if (inta & ~(trans_pcie->inta_mask)) {
IWL_WARN(trans, "Disabled INTA bits 0x%08x were pending\n",
inta & ~trans_pcie->inta_mask);
}
if (test_bit(STATUS_INT_ENABLED, &trans->shrd->status))
iwl_enable_interrupts(trans);
else if (handled & CSR_INT_BIT_RF_KILL)
iwl_enable_rfkill_int(priv(trans));
}
void iwl_free_isr_ict(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
if (trans_pcie->ict_tbl_vir) {
dma_free_coherent(bus(trans)->dev,
(sizeof(u32) * ICT_COUNT) + PAGE_SIZE,
trans_pcie->ict_tbl_vir,
trans_pcie->ict_tbl_dma);
trans_pcie->ict_tbl_vir = NULL;
memset(&trans_pcie->ict_tbl_dma, 0,
sizeof(trans_pcie->ict_tbl_dma));
memset(&trans_pcie->aligned_ict_tbl_dma, 0,
sizeof(trans_pcie->aligned_ict_tbl_dma));
}
}
int iwl_alloc_isr_ict(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
trans_pcie->ict_tbl_vir =
dma_alloc_coherent(bus(trans)->dev,
(sizeof(u32) * ICT_COUNT) + PAGE_SIZE,
&trans_pcie->ict_tbl_dma, GFP_KERNEL);
if (!trans_pcie->ict_tbl_vir)
return -ENOMEM;
trans_pcie->aligned_ict_tbl_dma =
ALIGN(trans_pcie->ict_tbl_dma, PAGE_SIZE);
IWL_DEBUG_ISR(trans, "ict dma addr %Lx dma aligned %Lx diff %d\n",
(unsigned long long)trans_pcie->ict_tbl_dma,
(unsigned long long)trans_pcie->aligned_ict_tbl_dma,
(int)(trans_pcie->aligned_ict_tbl_dma -
trans_pcie->ict_tbl_dma));
trans_pcie->ict_tbl = trans_pcie->ict_tbl_vir +
(trans_pcie->aligned_ict_tbl_dma -
trans_pcie->ict_tbl_dma);
IWL_DEBUG_ISR(trans, "ict vir addr %p vir aligned %p diff %d\n",
trans_pcie->ict_tbl, trans_pcie->ict_tbl_vir,
(int)(trans_pcie->aligned_ict_tbl_dma -
trans_pcie->ict_tbl_dma));
memset(trans_pcie->ict_tbl_vir, 0,
(sizeof(u32) * ICT_COUNT) + PAGE_SIZE);
trans_pcie->ict_index = 0;
trans_pcie->inta_mask |= CSR_INT_BIT_RX_PERIODIC;
return 0;
}
int iwl_reset_ict(struct iwl_trans *trans)
{
u32 val;
unsigned long flags;
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
if (!trans_pcie->ict_tbl_vir)
return 0;
spin_lock_irqsave(&trans->shrd->lock, flags);
iwl_disable_interrupts(trans);
memset(&trans_pcie->ict_tbl[0], 0, sizeof(u32) * ICT_COUNT);
val = trans_pcie->aligned_ict_tbl_dma >> PAGE_SHIFT;
val |= CSR_DRAM_INT_TBL_ENABLE;
val |= CSR_DRAM_INIT_TBL_WRAP_CHECK;
IWL_DEBUG_ISR(trans, "CSR_DRAM_INT_TBL_REG =0x%X "
"aligned dma address %Lx\n",
val,
(unsigned long long)trans_pcie->aligned_ict_tbl_dma);
iwl_write32(bus(trans), CSR_DRAM_INT_TBL_REG, val);
trans_pcie->use_ict = true;
trans_pcie->ict_index = 0;
iwl_write32(bus(trans), CSR_INT, trans_pcie->inta_mask);
iwl_enable_interrupts(trans);
spin_unlock_irqrestore(&trans->shrd->lock, flags);
return 0;
}
void iwl_disable_ict(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
unsigned long flags;
spin_lock_irqsave(&trans->shrd->lock, flags);
trans_pcie->use_ict = false;
spin_unlock_irqrestore(&trans->shrd->lock, flags);
}
static irqreturn_t iwl_isr(int irq, void *data)
{
struct iwl_trans *trans = data;
struct iwl_trans_pcie *trans_pcie;
u32 inta, inta_mask;
unsigned long flags;
#ifdef CONFIG_IWLWIFI_DEBUG
u32 inta_fh;
#endif
if (!trans)
return IRQ_NONE;
trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
spin_lock_irqsave(&trans->shrd->lock, flags);
inta_mask = iwl_read32(bus(trans), CSR_INT_MASK);
iwl_write32(bus(trans), CSR_INT_MASK, 0x00000000);
inta = iwl_read32(bus(trans), CSR_INT);
if (!inta) {
IWL_DEBUG_ISR(trans, "Ignore interrupt, inta == 0\n");
goto none;
}
if ((inta == 0xFFFFFFFF) || ((inta & 0xFFFFFFF0) == 0xa5a5a5a0)) {
IWL_WARN(trans, "HARDWARE GONE?? INTA == 0x%08x\n", inta);
goto unplugged;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_get_debug_level(trans->shrd) & (IWL_DL_ISR)) {
inta_fh = iwl_read32(bus(trans), CSR_FH_INT_STATUS);
IWL_DEBUG_ISR(trans, "ISR inta 0x%08x, enabled 0x%08x, "
"fh 0x%08x\n", inta, inta_mask, inta_fh);
}
#endif
trans_pcie->inta |= inta;
if (likely(inta))
tasklet_schedule(&trans_pcie->irq_tasklet);
else if (test_bit(STATUS_INT_ENABLED, &trans->shrd->status) &&
!trans_pcie->inta)
iwl_enable_interrupts(trans);
unplugged:
spin_unlock_irqrestore(&trans->shrd->lock, flags);
return IRQ_HANDLED;
none:
if (test_bit(STATUS_INT_ENABLED, &trans->shrd->status) &&
!trans_pcie->inta)
iwl_enable_interrupts(trans);
spin_unlock_irqrestore(&trans->shrd->lock, flags);
return IRQ_NONE;
}
irqreturn_t iwl_isr_ict(int irq, void *data)
{
struct iwl_trans *trans = data;
struct iwl_trans_pcie *trans_pcie;
u32 inta, inta_mask;
u32 val = 0;
unsigned long flags;
if (!trans)
return IRQ_NONE;
trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
if (!trans_pcie->use_ict)
return iwl_isr(irq, data);
spin_lock_irqsave(&trans->shrd->lock, flags);
inta_mask = iwl_read32(bus(trans), CSR_INT_MASK);
iwl_write32(bus(trans), CSR_INT_MASK, 0x00000000);
if (!trans_pcie->ict_tbl[trans_pcie->ict_index]) {
IWL_DEBUG_ISR(trans, "Ignore interrupt, inta == 0\n");
goto none;
}
while (trans_pcie->ict_tbl[trans_pcie->ict_index]) {
val |= le32_to_cpu(trans_pcie->ict_tbl[trans_pcie->ict_index]);
IWL_DEBUG_ISR(trans, "ICT index %d value 0x%08X\n",
trans_pcie->ict_index,
le32_to_cpu(
trans_pcie->ict_tbl[trans_pcie->ict_index]));
trans_pcie->ict_tbl[trans_pcie->ict_index] = 0;
trans_pcie->ict_index =
iwl_queue_inc_wrap(trans_pcie->ict_index, ICT_COUNT);
}
if (val == 0xffffffff)
val = 0;
if (val & 0xC0000)
val |= 0x8000;
inta = (0xff & val) | ((0xff00 & val) << 16);
IWL_DEBUG_ISR(trans, "ISR inta 0x%08x, enabled 0x%08x ict 0x%08x\n",
inta, inta_mask, val);
inta &= trans_pcie->inta_mask;
trans_pcie->inta |= inta;
if (likely(inta))
tasklet_schedule(&trans_pcie->irq_tasklet);
else if (test_bit(STATUS_INT_ENABLED, &trans->shrd->status) &&
!trans_pcie->inta) {
iwl_enable_interrupts(trans);
}
spin_unlock_irqrestore(&trans->shrd->lock, flags);
return IRQ_HANDLED;
none:
if (test_bit(STATUS_INT_ENABLED, &trans->shrd->status) &&
!trans_pcie->inta)
iwl_enable_interrupts(trans);
spin_unlock_irqrestore(&trans->shrd->lock, flags);
return IRQ_NONE;
}
