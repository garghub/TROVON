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
if (trans->cfg->base_params->shadow_reg_enable) {
q->write_actual = (q->write & ~0x7);
iwl_write32(trans, FH_RSCSR_CHNL0_WPTR, q->write_actual);
} else {
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
if (test_bit(STATUS_TPOWER_PMI, &trans_pcie->status)) {
reg = iwl_read32(trans, CSR_UCODE_DRV_GP1);
if (reg & CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP) {
IWL_DEBUG_INFO(trans,
"Rx queue requesting wakeup,"
" GP1 = 0x%x\n", reg);
iwl_set_bit(trans, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
goto exit_unlock;
}
q->write_actual = (q->write & ~0x7);
iwl_write_direct32(trans, FH_RSCSR_CHNL0_WPTR,
q->write_actual);
} else {
q->write_actual = (q->write & ~0x7);
iwl_write_direct32(trans, FH_RSCSR_CHNL0_WPTR,
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
schedule_work(&trans_pcie->rx_replenish);
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
if (trans_pcie->rx_page_order > 0)
gfp_mask |= __GFP_COMP;
page = alloc_pages(gfp_mask,
trans_pcie->rx_page_order);
if (!page) {
if (net_ratelimit())
IWL_DEBUG_INFO(trans, "alloc_pages failed, "
"order: %d\n",
trans_pcie->rx_page_order);
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
__free_pages(page, trans_pcie->rx_page_order);
return;
}
element = rxq->rx_used.next;
rxb = list_entry(element, struct iwl_rx_mem_buffer, list);
list_del(element);
spin_unlock_irqrestore(&rxq->lock, flags);
BUG_ON(rxb->page);
rxb->page = page;
rxb->page_dma = dma_map_page(trans->dev, page, 0,
PAGE_SIZE << trans_pcie->rx_page_order,
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
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
unsigned long flags;
iwlagn_rx_allocate(trans, GFP_KERNEL);
spin_lock_irqsave(&trans_pcie->irq_lock, flags);
iwlagn_rx_queue_restock(trans);
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
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
iwlagn_rx_replenish(trans_pcie->trans);
}
static void iwl_rx_handle_rxbuf(struct iwl_trans *trans,
struct iwl_rx_mem_buffer *rxb)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_rx_queue *rxq = &trans_pcie->rxq;
struct iwl_tx_queue *txq = &trans_pcie->txq[trans_pcie->cmd_queue];
unsigned long flags;
bool page_stolen = false;
int max_len = PAGE_SIZE << trans_pcie->rx_page_order;
u32 offset = 0;
if (WARN_ON(!rxb))
return;
dma_unmap_page(trans->dev, rxb->page_dma, max_len, DMA_FROM_DEVICE);
while (offset + sizeof(u32) + sizeof(struct iwl_cmd_header) < max_len) {
struct iwl_rx_packet *pkt;
struct iwl_device_cmd *cmd;
u16 sequence;
bool reclaim;
int index, cmd_index, err, len;
struct iwl_rx_cmd_buffer rxcb = {
._offset = offset,
._page = rxb->page,
._page_stolen = false,
.truesize = max_len,
};
pkt = rxb_addr(&rxcb);
if (pkt->len_n_flags == cpu_to_le32(FH_RSCSR_FRAME_INVALID))
break;
IWL_DEBUG_RX(trans, "cmd at offset %d: %s (0x%.2x)\n",
rxcb._offset,
trans_pcie_get_cmd_string(trans_pcie, pkt->hdr.cmd),
pkt->hdr.cmd);
len = le32_to_cpu(pkt->len_n_flags) & FH_RSCSR_FRAME_SIZE_MSK;
len += sizeof(u32);
trace_iwlwifi_dev_rx(trans->dev, pkt, len);
reclaim = !(pkt->hdr.sequence & SEQ_RX_FRAME);
if (reclaim) {
int i;
for (i = 0; i < trans_pcie->n_no_reclaim_cmds; i++) {
if (trans_pcie->no_reclaim_cmds[i] ==
pkt->hdr.cmd) {
reclaim = false;
break;
}
}
}
sequence = le16_to_cpu(pkt->hdr.sequence);
index = SEQ_TO_INDEX(sequence);
cmd_index = get_cmd_index(&txq->q, index);
if (reclaim)
cmd = txq->entries[cmd_index].cmd;
else
cmd = NULL;
err = iwl_op_mode_rx(trans->op_mode, &rxcb, cmd);
if (reclaim) {
if (!rxcb._page_stolen)
iwl_tx_cmd_complete(trans, &rxcb, err);
else
IWL_WARN(trans, "Claim null rxb?\n");
}
page_stolen |= rxcb._page_stolen;
offset += ALIGN(len, FH_RSCSR_FRAME_ALIGN);
}
if (page_stolen) {
__free_pages(rxb->page, trans_pcie->rx_page_order);
rxb->page = NULL;
}
spin_lock_irqsave(&rxq->lock, flags);
if (rxb->page != NULL) {
rxb->page_dma =
dma_map_page(trans->dev, rxb->page, 0,
PAGE_SIZE << trans_pcie->rx_page_order,
DMA_FROM_DEVICE);
list_add_tail(&rxb->list, &rxq->rx_free);
rxq->free_count++;
} else
list_add_tail(&rxb->list, &rxq->rx_used);
spin_unlock_irqrestore(&rxq->lock, flags);
}
static void iwl_rx_handle(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_rx_queue *rxq = &trans_pcie->rxq;
u32 r, i;
u8 fill_rx = 0;
u32 count = 8;
int total_empty;
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
struct iwl_rx_mem_buffer *rxb;
rxb = rxq->queue[i];
rxq->queue[i] = NULL;
IWL_DEBUG_RX(trans, "rxbuf: r = %d, i = %d (%p)\n", rxb);
iwl_rx_handle_rxbuf(trans, rxb);
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
static void iwl_irq_handle_error(struct iwl_trans *trans)
{
if (trans->cfg->internal_wimax_coex &&
(!(iwl_read_prph(trans, APMG_CLK_CTRL_REG) &
APMS_CLK_VAL_MRB_FUNC_MODE) ||
(iwl_read_prph(trans, APMG_PS_CTRL_REG) &
APMG_PS_CTRL_VAL_RESET_REQ))) {
struct iwl_trans_pcie *trans_pcie;
trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
clear_bit(STATUS_HCMD_ACTIVE, &trans_pcie->status);
iwl_op_mode_wimax_active(trans->op_mode);
wake_up(&trans->wait_command_queue);
return;
}
iwl_dump_csr(trans);
iwl_dump_fh(trans, NULL, false);
iwl_op_mode_nic_error(trans->op_mode);
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
spin_lock_irqsave(&trans_pcie->irq_lock, flags);
iwl_write32(trans, CSR_INT,
trans_pcie->inta | ~trans_pcie->inta_mask);
inta = trans_pcie->inta;
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_have_debug_level(IWL_DL_ISR)) {
inta_mask = iwl_read32(trans, CSR_INT_MASK);
IWL_DEBUG_ISR(trans, "inta 0x%08x, enabled 0x%08x\n",
inta, inta_mask);
}
#endif
trans_pcie->inta = 0;
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
if (inta & CSR_INT_BIT_HW_ERR) {
IWL_ERR(trans, "Hardware error detected. Restarting.\n");
iwl_disable_interrupts(trans);
isr_stats->hw++;
iwl_irq_handle_error(trans);
handled |= CSR_INT_BIT_HW_ERR;
return;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_have_debug_level(IWL_DL_ISR)) {
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
bool hw_rfkill;
hw_rfkill = iwl_is_rfkill_set(trans);
IWL_WARN(trans, "RF_KILL bit toggled to %s.\n",
hw_rfkill ? "disable radio" : "enable radio");
isr_stats->rfkill++;
iwl_op_mode_hw_rf_kill(trans->op_mode, hw_rfkill);
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
for (i = 0; i < trans->cfg->base_params->num_of_queues; i++)
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
iwl_write32(trans, CSR_FH_INT_STATUS,
CSR_FH_INT_RX_MASK);
}
if (inta & CSR_INT_BIT_RX_PERIODIC) {
handled |= CSR_INT_BIT_RX_PERIODIC;
iwl_write32(trans,
CSR_INT, CSR_INT_BIT_RX_PERIODIC);
}
iwl_write8(trans, CSR_INT_PERIODIC_REG,
CSR_INT_PERIODIC_DIS);
#ifdef CONFIG_IWLWIFI_IDI
iwl_amfh_rx_handler();
#else
iwl_rx_handle(trans);
#endif
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX))
iwl_write8(trans, CSR_INT_PERIODIC_REG,
CSR_INT_PERIODIC_ENA);
isr_stats->rx++;
}
if (inta & CSR_INT_BIT_FH_TX) {
iwl_write32(trans, CSR_FH_INT_STATUS, CSR_FH_INT_TX_MASK);
IWL_DEBUG_ISR(trans, "uCode load interrupt\n");
isr_stats->tx++;
handled |= CSR_INT_BIT_FH_TX;
trans_pcie->ucode_write_complete = true;
wake_up(&trans_pcie->ucode_write_waitq);
}
if (inta & ~handled) {
IWL_ERR(trans, "Unhandled INTA bits 0x%08x\n", inta & ~handled);
isr_stats->unhandled++;
}
if (inta & ~(trans_pcie->inta_mask)) {
IWL_WARN(trans, "Disabled INTA bits 0x%08x were pending\n",
inta & ~trans_pcie->inta_mask);
}
if (test_bit(STATUS_INT_ENABLED, &trans_pcie->status))
iwl_enable_interrupts(trans);
else if (handled & CSR_INT_BIT_RF_KILL)
iwl_enable_rfkill_int(trans);
}
void iwl_free_isr_ict(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
if (trans_pcie->ict_tbl) {
dma_free_coherent(trans->dev, ICT_SIZE,
trans_pcie->ict_tbl,
trans_pcie->ict_tbl_dma);
trans_pcie->ict_tbl = NULL;
trans_pcie->ict_tbl_dma = 0;
}
}
int iwl_alloc_isr_ict(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
trans_pcie->ict_tbl =
dma_alloc_coherent(trans->dev, ICT_SIZE,
&trans_pcie->ict_tbl_dma,
GFP_KERNEL);
if (!trans_pcie->ict_tbl)
return -ENOMEM;
if (WARN_ON(trans_pcie->ict_tbl_dma & (ICT_SIZE - 1))) {
iwl_free_isr_ict(trans);
return -EINVAL;
}
IWL_DEBUG_ISR(trans, "ict dma addr %Lx\n",
(unsigned long long)trans_pcie->ict_tbl_dma);
IWL_DEBUG_ISR(trans, "ict vir addr %p\n", trans_pcie->ict_tbl);
memset(trans_pcie->ict_tbl, 0, ICT_SIZE);
trans_pcie->ict_index = 0;
trans_pcie->inta_mask |= CSR_INT_BIT_RX_PERIODIC;
return 0;
}
void iwl_reset_ict(struct iwl_trans *trans)
{
u32 val;
unsigned long flags;
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
if (!trans_pcie->ict_tbl)
return;
spin_lock_irqsave(&trans_pcie->irq_lock, flags);
iwl_disable_interrupts(trans);
memset(trans_pcie->ict_tbl, 0, ICT_SIZE);
val = trans_pcie->ict_tbl_dma >> ICT_SHIFT;
val |= CSR_DRAM_INT_TBL_ENABLE;
val |= CSR_DRAM_INIT_TBL_WRAP_CHECK;
IWL_DEBUG_ISR(trans, "CSR_DRAM_INT_TBL_REG =0x%x\n", val);
iwl_write32(trans, CSR_DRAM_INT_TBL_REG, val);
trans_pcie->use_ict = true;
trans_pcie->ict_index = 0;
iwl_write32(trans, CSR_INT, trans_pcie->inta_mask);
iwl_enable_interrupts(trans);
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
}
void iwl_disable_ict(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
unsigned long flags;
spin_lock_irqsave(&trans_pcie->irq_lock, flags);
trans_pcie->use_ict = false;
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
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
trace_iwlwifi_dev_irq(trans->dev);
trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
spin_lock_irqsave(&trans_pcie->irq_lock, flags);
inta_mask = iwl_read32(trans, CSR_INT_MASK);
iwl_write32(trans, CSR_INT_MASK, 0x00000000);
inta = iwl_read32(trans, CSR_INT);
if (!inta) {
IWL_DEBUG_ISR(trans, "Ignore interrupt, inta == 0\n");
goto none;
}
if ((inta == 0xFFFFFFFF) || ((inta & 0xFFFFFFF0) == 0xa5a5a5a0)) {
IWL_WARN(trans, "HARDWARE GONE?? INTA == 0x%08x\n", inta);
goto unplugged;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_have_debug_level(IWL_DL_ISR)) {
inta_fh = iwl_read32(trans, CSR_FH_INT_STATUS);
IWL_DEBUG_ISR(trans, "ISR inta 0x%08x, enabled 0x%08x, "
"fh 0x%08x\n", inta, inta_mask, inta_fh);
}
#endif
trans_pcie->inta |= inta;
if (likely(inta))
tasklet_schedule(&trans_pcie->irq_tasklet);
else if (test_bit(STATUS_INT_ENABLED, &trans_pcie->status) &&
!trans_pcie->inta)
iwl_enable_interrupts(trans);
unplugged:
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
return IRQ_HANDLED;
none:
if (test_bit(STATUS_INT_ENABLED, &trans_pcie->status) &&
!trans_pcie->inta)
iwl_enable_interrupts(trans);
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
return IRQ_NONE;
}
irqreturn_t iwl_isr_ict(int irq, void *data)
{
struct iwl_trans *trans = data;
struct iwl_trans_pcie *trans_pcie;
u32 inta, inta_mask;
u32 val = 0;
u32 read;
unsigned long flags;
if (!trans)
return IRQ_NONE;
trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
if (!trans_pcie->use_ict)
return iwl_isr(irq, data);
trace_iwlwifi_dev_irq(trans->dev);
spin_lock_irqsave(&trans_pcie->irq_lock, flags);
inta_mask = iwl_read32(trans, CSR_INT_MASK);
iwl_write32(trans, CSR_INT_MASK, 0x00000000);
read = le32_to_cpu(trans_pcie->ict_tbl[trans_pcie->ict_index]);
trace_iwlwifi_dev_ict_read(trans->dev, trans_pcie->ict_index, read);
if (!read) {
IWL_DEBUG_ISR(trans, "Ignore interrupt, inta == 0\n");
goto none;
}
do {
val |= read;
IWL_DEBUG_ISR(trans, "ICT index %d value 0x%08X\n",
trans_pcie->ict_index, read);
trans_pcie->ict_tbl[trans_pcie->ict_index] = 0;
trans_pcie->ict_index =
iwl_queue_inc_wrap(trans_pcie->ict_index, ICT_COUNT);
read = le32_to_cpu(trans_pcie->ict_tbl[trans_pcie->ict_index]);
trace_iwlwifi_dev_ict_read(trans->dev, trans_pcie->ict_index,
read);
} while (read);
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
else if (test_bit(STATUS_INT_ENABLED, &trans_pcie->status) &&
!trans_pcie->inta) {
iwl_enable_interrupts(trans);
}
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
return IRQ_HANDLED;
none:
if (test_bit(STATUS_INT_ENABLED, &trans_pcie->status) &&
!trans_pcie->inta)
iwl_enable_interrupts(trans);
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
return IRQ_NONE;
}
