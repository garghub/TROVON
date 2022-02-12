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
void iwl_rx_queue_update_write_ptr(struct iwl_priv *priv,
struct iwl_rx_queue *q)
{
unsigned long flags;
u32 reg;
spin_lock_irqsave(&q->lock, flags);
if (q->need_update == 0)
goto exit_unlock;
if (priv->cfg->base_params->shadow_reg_enable) {
q->write_actual = (q->write & ~0x7);
iwl_write32(priv, FH_RSCSR_CHNL0_WPTR, q->write_actual);
} else {
if (test_bit(STATUS_POWER_PMI, &priv->status)) {
reg = iwl_read32(priv, CSR_UCODE_DRV_GP1);
if (reg & CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP) {
IWL_DEBUG_INFO(priv,
"Rx queue requesting wakeup,"
" GP1 = 0x%x\n", reg);
iwl_set_bit(priv, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
goto exit_unlock;
}
q->write_actual = (q->write & ~0x7);
iwl_write_direct32(priv, FH_RSCSR_CHNL0_WPTR,
q->write_actual);
} else {
q->write_actual = (q->write & ~0x7);
iwl_write_direct32(priv, FH_RSCSR_CHNL0_WPTR,
q->write_actual);
}
}
q->need_update = 0;
exit_unlock:
spin_unlock_irqrestore(&q->lock, flags);
}
static inline __le32 iwlagn_dma_addr2rbd_ptr(struct iwl_priv *priv,
dma_addr_t dma_addr)
{
return cpu_to_le32((u32)(dma_addr >> 8));
}
static void iwlagn_rx_queue_restock(struct iwl_priv *priv)
{
struct iwl_rx_queue *rxq = &priv->rxq;
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
rxq->bd[rxq->write] = iwlagn_dma_addr2rbd_ptr(priv,
rxb->page_dma);
rxq->queue[rxq->write] = rxb;
rxq->write = (rxq->write + 1) & RX_QUEUE_MASK;
rxq->free_count--;
}
spin_unlock_irqrestore(&rxq->lock, flags);
if (rxq->free_count <= RX_LOW_WATERMARK)
queue_work(priv->workqueue, &priv->rx_replenish);
if (rxq->write_actual != (rxq->write & ~0x7)) {
spin_lock_irqsave(&rxq->lock, flags);
rxq->need_update = 1;
spin_unlock_irqrestore(&rxq->lock, flags);
iwl_rx_queue_update_write_ptr(priv, rxq);
}
}
static void iwlagn_rx_allocate(struct iwl_priv *priv, gfp_t priority)
{
struct iwl_rx_queue *rxq = &priv->rxq;
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
if (priv->hw_params.rx_page_order > 0)
gfp_mask |= __GFP_COMP;
page = alloc_pages(gfp_mask, priv->hw_params.rx_page_order);
if (!page) {
if (net_ratelimit())
IWL_DEBUG_INFO(priv, "alloc_pages failed, "
"order: %d\n",
priv->hw_params.rx_page_order);
if ((rxq->free_count <= RX_LOW_WATERMARK) &&
net_ratelimit())
IWL_CRIT(priv, "Failed to alloc_pages with %s."
"Only %u free buffers remaining.\n",
priority == GFP_ATOMIC ?
"GFP_ATOMIC" : "GFP_KERNEL",
rxq->free_count);
return;
}
spin_lock_irqsave(&rxq->lock, flags);
if (list_empty(&rxq->rx_used)) {
spin_unlock_irqrestore(&rxq->lock, flags);
__free_pages(page, priv->hw_params.rx_page_order);
return;
}
element = rxq->rx_used.next;
rxb = list_entry(element, struct iwl_rx_mem_buffer, list);
list_del(element);
spin_unlock_irqrestore(&rxq->lock, flags);
BUG_ON(rxb->page);
rxb->page = page;
rxb->page_dma = dma_map_page(priv->bus->dev, page, 0,
PAGE_SIZE << priv->hw_params.rx_page_order,
DMA_FROM_DEVICE);
BUG_ON(rxb->page_dma & ~DMA_BIT_MASK(36));
BUG_ON(rxb->page_dma & DMA_BIT_MASK(8));
spin_lock_irqsave(&rxq->lock, flags);
list_add_tail(&rxb->list, &rxq->rx_free);
rxq->free_count++;
spin_unlock_irqrestore(&rxq->lock, flags);
}
}
void iwlagn_rx_replenish(struct iwl_priv *priv)
{
unsigned long flags;
iwlagn_rx_allocate(priv, GFP_KERNEL);
spin_lock_irqsave(&priv->lock, flags);
iwlagn_rx_queue_restock(priv);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void iwlagn_rx_replenish_now(struct iwl_priv *priv)
{
iwlagn_rx_allocate(priv, GFP_ATOMIC);
iwlagn_rx_queue_restock(priv);
}
void iwl_bg_rx_replenish(struct work_struct *data)
{
struct iwl_priv *priv =
container_of(data, struct iwl_priv, rx_replenish);
if (test_bit(STATUS_EXIT_PENDING, &priv->status))
return;
mutex_lock(&priv->mutex);
iwlagn_rx_replenish(priv);
mutex_unlock(&priv->mutex);
}
static void iwl_rx_handle(struct iwl_priv *priv)
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
if (WARN_ON(rxb == NULL)) {
i = (i + 1) & RX_QUEUE_MASK;
continue;
}
rxq->queue[i] = NULL;
dma_unmap_page(priv->bus->dev, rxb->page_dma,
PAGE_SIZE << priv->hw_params.rx_page_order,
DMA_FROM_DEVICE);
pkt = rxb_addr(rxb);
IWL_DEBUG_RX(priv, "r = %d, i = %d, %s, 0x%02x\n", r,
i, get_cmd_string(pkt->hdr.cmd), pkt->hdr.cmd);
len = le32_to_cpu(pkt->len_n_flags) & FH_RSCSR_FRAME_SIZE_MSK;
len += sizeof(u32);
trace_iwlwifi_dev_rx(priv, pkt, len);
reclaim = !(pkt->hdr.sequence & SEQ_RX_FRAME) &&
(pkt->hdr.cmd != REPLY_RX_PHY_CMD) &&
(pkt->hdr.cmd != REPLY_RX) &&
(pkt->hdr.cmd != REPLY_RX_MPDU_CMD) &&
(pkt->hdr.cmd != REPLY_COMPRESSED_BA) &&
(pkt->hdr.cmd != STATISTICS_NOTIFICATION) &&
(pkt->hdr.cmd != REPLY_TX);
iwl_rx_dispatch(priv, rxb);
if (reclaim) {
if (rxb->page)
iwl_tx_cmd_complete(priv, rxb);
else
IWL_WARN(priv, "Claim null rxb?\n");
}
spin_lock_irqsave(&rxq->lock, flags);
if (rxb->page != NULL) {
rxb->page_dma = dma_map_page(priv->bus->dev, rxb->page,
0, PAGE_SIZE << priv->hw_params.rx_page_order,
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
iwlagn_rx_replenish_now(priv);
count = 0;
}
}
}
rxq->read = i;
if (fill_rx)
iwlagn_rx_replenish_now(priv);
else
iwlagn_rx_queue_restock(priv);
}
void iwl_irq_tasklet(struct iwl_priv *priv)
{
u32 inta = 0;
u32 handled = 0;
unsigned long flags;
u32 i;
#ifdef CONFIG_IWLWIFI_DEBUG
u32 inta_mask;
#endif
spin_lock_irqsave(&priv->lock, flags);
iwl_write32(priv, CSR_INT, priv->inta | ~priv->inta_mask);
inta = priv->inta;
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_get_debug_level(priv) & IWL_DL_ISR) {
inta_mask = iwl_read32(priv, CSR_INT_MASK);
IWL_DEBUG_ISR(priv, "inta 0x%08x, enabled 0x%08x\n ",
inta, inta_mask);
}
#endif
spin_unlock_irqrestore(&priv->lock, flags);
priv->inta = 0;
if (inta & CSR_INT_BIT_HW_ERR) {
IWL_ERR(priv, "Hardware error detected. Restarting.\n");
iwl_disable_interrupts(priv);
priv->isr_stats.hw++;
iwl_irq_handle_error(priv);
handled |= CSR_INT_BIT_HW_ERR;
return;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_get_debug_level(priv) & (IWL_DL_ISR)) {
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
iwl_irq_handle_error(priv);
handled |= CSR_INT_BIT_SW_ERR;
}
if (inta & CSR_INT_BIT_WAKEUP) {
IWL_DEBUG_ISR(priv, "Wakeup interrupt\n");
iwl_rx_queue_update_write_ptr(priv, &priv->rxq);
for (i = 0; i < priv->hw_params.max_txq_num; i++)
iwl_txq_update_write_ptr(priv, &priv->txq[i]);
priv->isr_stats.wakeup++;
handled |= CSR_INT_BIT_WAKEUP;
}
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX |
CSR_INT_BIT_RX_PERIODIC)) {
IWL_DEBUG_ISR(priv, "Rx interrupt\n");
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX)) {
handled |= (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX);
iwl_write32(priv, CSR_FH_INT_STATUS,
CSR_FH_INT_RX_MASK);
}
if (inta & CSR_INT_BIT_RX_PERIODIC) {
handled |= CSR_INT_BIT_RX_PERIODIC;
iwl_write32(priv, CSR_INT, CSR_INT_BIT_RX_PERIODIC);
}
iwl_write8(priv, CSR_INT_PERIODIC_REG,
CSR_INT_PERIODIC_DIS);
iwl_rx_handle(priv);
if (inta & (CSR_INT_BIT_FH_RX | CSR_INT_BIT_SW_RX))
iwl_write8(priv, CSR_INT_PERIODIC_REG,
CSR_INT_PERIODIC_ENA);
priv->isr_stats.rx++;
}
if (inta & CSR_INT_BIT_FH_TX) {
iwl_write32(priv, CSR_FH_INT_STATUS, CSR_FH_INT_TX_MASK);
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
}
if (test_bit(STATUS_INT_ENABLED, &priv->status))
iwl_enable_interrupts(priv);
else if (handled & CSR_INT_BIT_RF_KILL)
iwl_enable_rfkill_int(priv);
}
void iwl_free_isr_ict(struct iwl_priv *priv)
{
if (priv->ict_tbl_vir) {
dma_free_coherent(priv->bus->dev,
(sizeof(u32) * ICT_COUNT) + PAGE_SIZE,
priv->ict_tbl_vir,
priv->ict_tbl_dma);
priv->ict_tbl_vir = NULL;
memset(&priv->ict_tbl_dma, 0,
sizeof(priv->ict_tbl_dma));
memset(&priv->aligned_ict_tbl_dma, 0,
sizeof(priv->aligned_ict_tbl_dma));
}
}
int iwl_alloc_isr_ict(struct iwl_priv *priv)
{
priv->ict_tbl_vir =
dma_alloc_coherent(priv->bus->dev,
(sizeof(u32) * ICT_COUNT) + PAGE_SIZE,
&priv->ict_tbl_dma, GFP_KERNEL);
if (!priv->ict_tbl_vir)
return -ENOMEM;
priv->aligned_ict_tbl_dma =
ALIGN(priv->ict_tbl_dma, PAGE_SIZE);
IWL_DEBUG_ISR(priv, "ict dma addr %Lx dma aligned %Lx diff %d\n",
(unsigned long long)priv->ict_tbl_dma,
(unsigned long long)priv->aligned_ict_tbl_dma,
(int)(priv->aligned_ict_tbl_dma -
priv->ict_tbl_dma));
priv->ict_tbl = priv->ict_tbl_vir +
(priv->aligned_ict_tbl_dma -
priv->ict_tbl_dma);
IWL_DEBUG_ISR(priv, "ict vir addr %p vir aligned %p diff %d\n",
priv->ict_tbl, priv->ict_tbl_vir,
(int)(priv->aligned_ict_tbl_dma -
priv->ict_tbl_dma));
memset(priv->ict_tbl_vir, 0,
(sizeof(u32) * ICT_COUNT) + PAGE_SIZE);
priv->ict_index = 0;
priv->inta_mask |= CSR_INT_BIT_RX_PERIODIC;
return 0;
}
int iwl_reset_ict(struct iwl_priv *priv)
{
u32 val;
unsigned long flags;
if (!priv->ict_tbl_vir)
return 0;
spin_lock_irqsave(&priv->lock, flags);
iwl_disable_interrupts(priv);
memset(&priv->ict_tbl[0], 0, sizeof(u32) * ICT_COUNT);
val = priv->aligned_ict_tbl_dma >> PAGE_SHIFT;
val |= CSR_DRAM_INT_TBL_ENABLE;
val |= CSR_DRAM_INIT_TBL_WRAP_CHECK;
IWL_DEBUG_ISR(priv, "CSR_DRAM_INT_TBL_REG =0x%X "
"aligned dma address %Lx\n",
val,
(unsigned long long)priv->aligned_ict_tbl_dma);
iwl_write32(priv, CSR_DRAM_INT_TBL_REG, val);
priv->use_ict = true;
priv->ict_index = 0;
iwl_write32(priv, CSR_INT, priv->inta_mask);
iwl_enable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
void iwl_disable_ict(struct iwl_priv *priv)
{
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
priv->use_ict = false;
spin_unlock_irqrestore(&priv->lock, flags);
}
static irqreturn_t iwl_isr(int irq, void *data)
{
struct iwl_priv *priv = data;
u32 inta, inta_mask;
unsigned long flags;
#ifdef CONFIG_IWLWIFI_DEBUG
u32 inta_fh;
#endif
if (!priv)
return IRQ_NONE;
spin_lock_irqsave(&priv->lock, flags);
inta_mask = iwl_read32(priv, CSR_INT_MASK);
iwl_write32(priv, CSR_INT_MASK, 0x00000000);
inta = iwl_read32(priv, CSR_INT);
if (!inta) {
IWL_DEBUG_ISR(priv, "Ignore interrupt, inta == 0\n");
goto none;
}
if ((inta == 0xFFFFFFFF) || ((inta & 0xFFFFFFF0) == 0xa5a5a5a0)) {
IWL_WARN(priv, "HARDWARE GONE?? INTA == 0x%08x\n", inta);
goto unplugged;
}
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_get_debug_level(priv) & (IWL_DL_ISR)) {
inta_fh = iwl_read32(priv, CSR_FH_INT_STATUS);
IWL_DEBUG_ISR(priv, "ISR inta 0x%08x, enabled 0x%08x, "
"fh 0x%08x\n", inta, inta_mask, inta_fh);
}
#endif
priv->inta |= inta;
if (likely(inta))
tasklet_schedule(&priv->irq_tasklet);
else if (test_bit(STATUS_INT_ENABLED, &priv->status) &&
!priv->inta)
iwl_enable_interrupts(priv);
unplugged:
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_HANDLED;
none:
if (test_bit(STATUS_INT_ENABLED, &priv->status) && !priv->inta)
iwl_enable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_NONE;
}
irqreturn_t iwl_isr_ict(int irq, void *data)
{
struct iwl_priv *priv = data;
u32 inta, inta_mask;
u32 val = 0;
unsigned long flags;
if (!priv)
return IRQ_NONE;
if (!priv->use_ict)
return iwl_isr(irq, data);
spin_lock_irqsave(&priv->lock, flags);
inta_mask = iwl_read32(priv, CSR_INT_MASK);
iwl_write32(priv, CSR_INT_MASK, 0x00000000);
if (!priv->ict_tbl[priv->ict_index]) {
IWL_DEBUG_ISR(priv, "Ignore interrupt, inta == 0\n");
goto none;
}
while (priv->ict_tbl[priv->ict_index]) {
val |= le32_to_cpu(priv->ict_tbl[priv->ict_index]);
IWL_DEBUG_ISR(priv, "ICT index %d value 0x%08X\n",
priv->ict_index,
le32_to_cpu(
priv->ict_tbl[priv->ict_index]));
priv->ict_tbl[priv->ict_index] = 0;
priv->ict_index = iwl_queue_inc_wrap(priv->ict_index,
ICT_COUNT);
}
if (val == 0xffffffff)
val = 0;
if (val & 0xC0000)
val |= 0x8000;
inta = (0xff & val) | ((0xff00 & val) << 16);
IWL_DEBUG_ISR(priv, "ISR inta 0x%08x, enabled 0x%08x ict 0x%08x\n",
inta, inta_mask, val);
inta &= priv->inta_mask;
priv->inta |= inta;
if (likely(inta))
tasklet_schedule(&priv->irq_tasklet);
else if (test_bit(STATUS_INT_ENABLED, &priv->status) &&
!priv->inta) {
iwl_enable_interrupts(priv);
}
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_HANDLED;
none:
if (test_bit(STATUS_INT_ENABLED, &priv->status) && !priv->inta)
iwl_enable_interrupts(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_NONE;
}
