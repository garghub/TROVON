void
iwl_legacy_txq_update_write_ptr(struct iwl_priv *priv, struct iwl_tx_queue *txq)
{
u32 reg = 0;
int txq_id = txq->q.id;
if (txq->need_update == 0)
return;
if (test_bit(STATUS_POWER_PMI, &priv->status)) {
reg = iwl_read32(priv, CSR_UCODE_DRV_GP1);
if (reg & CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP) {
IWL_DEBUG_INFO(priv,
"Tx queue %d requesting wakeup,"
" GP1 = 0x%x\n", txq_id, reg);
iwl_legacy_set_bit(priv, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
return;
}
iwl_legacy_write_direct32(priv, HBUS_TARG_WRPTR,
txq->q.write_ptr | (txq_id << 8));
} else
iwl_write32(priv, HBUS_TARG_WRPTR,
txq->q.write_ptr | (txq_id << 8));
txq->need_update = 0;
}
void iwl_legacy_tx_queue_unmap(struct iwl_priv *priv, int txq_id)
{
struct iwl_tx_queue *txq = &priv->txq[txq_id];
struct iwl_queue *q = &txq->q;
if (q->n_bd == 0)
return;
while (q->write_ptr != q->read_ptr) {
priv->cfg->ops->lib->txq_free_tfd(priv, txq);
q->read_ptr = iwl_legacy_queue_inc_wrap(q->read_ptr, q->n_bd);
}
}
void iwl_legacy_tx_queue_free(struct iwl_priv *priv, int txq_id)
{
struct iwl_tx_queue *txq = &priv->txq[txq_id];
struct device *dev = &priv->pci_dev->dev;
int i;
iwl_legacy_tx_queue_unmap(priv, txq_id);
for (i = 0; i < TFD_TX_CMD_SLOTS; i++)
kfree(txq->cmd[i]);
if (txq->q.n_bd)
dma_free_coherent(dev, priv->hw_params.tfd_size *
txq->q.n_bd, txq->tfds, txq->q.dma_addr);
kfree(txq->txb);
txq->txb = NULL;
kfree(txq->cmd);
kfree(txq->meta);
txq->cmd = NULL;
txq->meta = NULL;
memset(txq, 0, sizeof(*txq));
}
void iwl_legacy_cmd_queue_unmap(struct iwl_priv *priv)
{
struct iwl_tx_queue *txq = &priv->txq[priv->cmd_queue];
struct iwl_queue *q = &txq->q;
int i;
if (q->n_bd == 0)
return;
while (q->read_ptr != q->write_ptr) {
i = iwl_legacy_get_cmd_index(q, q->read_ptr, 0);
if (txq->meta[i].flags & CMD_MAPPED) {
pci_unmap_single(priv->pci_dev,
dma_unmap_addr(&txq->meta[i], mapping),
dma_unmap_len(&txq->meta[i], len),
PCI_DMA_BIDIRECTIONAL);
txq->meta[i].flags = 0;
}
q->read_ptr = iwl_legacy_queue_inc_wrap(q->read_ptr, q->n_bd);
}
i = q->n_window;
if (txq->meta[i].flags & CMD_MAPPED) {
pci_unmap_single(priv->pci_dev,
dma_unmap_addr(&txq->meta[i], mapping),
dma_unmap_len(&txq->meta[i], len),
PCI_DMA_BIDIRECTIONAL);
txq->meta[i].flags = 0;
}
}
void iwl_legacy_cmd_queue_free(struct iwl_priv *priv)
{
struct iwl_tx_queue *txq = &priv->txq[priv->cmd_queue];
struct device *dev = &priv->pci_dev->dev;
int i;
iwl_legacy_cmd_queue_unmap(priv);
for (i = 0; i <= TFD_CMD_SLOTS; i++)
kfree(txq->cmd[i]);
if (txq->q.n_bd)
dma_free_coherent(dev, priv->hw_params.tfd_size * txq->q.n_bd,
txq->tfds, txq->q.dma_addr);
kfree(txq->cmd);
kfree(txq->meta);
txq->cmd = NULL;
txq->meta = NULL;
memset(txq, 0, sizeof(*txq));
}
int iwl_legacy_queue_space(const struct iwl_queue *q)
{
int s = q->read_ptr - q->write_ptr;
if (q->read_ptr > q->write_ptr)
s -= q->n_bd;
if (s <= 0)
s += q->n_window;
s -= 2;
if (s < 0)
s = 0;
return s;
}
static int iwl_legacy_queue_init(struct iwl_priv *priv, struct iwl_queue *q,
int count, int slots_num, u32 id)
{
q->n_bd = count;
q->n_window = slots_num;
q->id = id;
BUG_ON(!is_power_of_2(count));
BUG_ON(!is_power_of_2(slots_num));
q->low_mark = q->n_window / 4;
if (q->low_mark < 4)
q->low_mark = 4;
q->high_mark = q->n_window / 8;
if (q->high_mark < 2)
q->high_mark = 2;
q->write_ptr = q->read_ptr = 0;
return 0;
}
static int iwl_legacy_tx_queue_alloc(struct iwl_priv *priv,
struct iwl_tx_queue *txq, u32 id)
{
struct device *dev = &priv->pci_dev->dev;
size_t tfd_sz = priv->hw_params.tfd_size * TFD_QUEUE_SIZE_MAX;
if (id != priv->cmd_queue) {
txq->txb = kzalloc(sizeof(txq->txb[0]) *
TFD_QUEUE_SIZE_MAX, GFP_KERNEL);
if (!txq->txb) {
IWL_ERR(priv, "kmalloc for auxiliary BD "
"structures failed\n");
goto error;
}
} else {
txq->txb = NULL;
}
txq->tfds = dma_alloc_coherent(dev, tfd_sz, &txq->q.dma_addr,
GFP_KERNEL);
if (!txq->tfds) {
IWL_ERR(priv, "pci_alloc_consistent(%zd) failed\n", tfd_sz);
goto error;
}
txq->q.id = id;
return 0;
error:
kfree(txq->txb);
txq->txb = NULL;
return -ENOMEM;
}
int iwl_legacy_tx_queue_init(struct iwl_priv *priv, struct iwl_tx_queue *txq,
int slots_num, u32 txq_id)
{
int i, len;
int ret;
int actual_slots = slots_num;
if (txq_id == priv->cmd_queue)
actual_slots++;
txq->meta = kzalloc(sizeof(struct iwl_cmd_meta) * actual_slots,
GFP_KERNEL);
txq->cmd = kzalloc(sizeof(struct iwl_device_cmd *) * actual_slots,
GFP_KERNEL);
if (!txq->meta || !txq->cmd)
goto out_free_arrays;
len = sizeof(struct iwl_device_cmd);
for (i = 0; i < actual_slots; i++) {
if (i == slots_num)
len = IWL_MAX_CMD_SIZE;
txq->cmd[i] = kmalloc(len, GFP_KERNEL);
if (!txq->cmd[i])
goto err;
}
ret = iwl_legacy_tx_queue_alloc(priv, txq, txq_id);
if (ret)
goto err;
txq->need_update = 0;
if (txq_id < 4)
iwl_legacy_set_swq_id(txq, txq_id, txq_id);
BUILD_BUG_ON(TFD_QUEUE_SIZE_MAX & (TFD_QUEUE_SIZE_MAX - 1));
iwl_legacy_queue_init(priv, &txq->q,
TFD_QUEUE_SIZE_MAX, slots_num, txq_id);
priv->cfg->ops->lib->txq_init(priv, txq);
return 0;
err:
for (i = 0; i < actual_slots; i++)
kfree(txq->cmd[i]);
out_free_arrays:
kfree(txq->meta);
kfree(txq->cmd);
return -ENOMEM;
}
void iwl_legacy_tx_queue_reset(struct iwl_priv *priv, struct iwl_tx_queue *txq,
int slots_num, u32 txq_id)
{
int actual_slots = slots_num;
if (txq_id == priv->cmd_queue)
actual_slots++;
memset(txq->meta, 0, sizeof(struct iwl_cmd_meta) * actual_slots);
txq->need_update = 0;
iwl_legacy_queue_init(priv, &txq->q,
TFD_QUEUE_SIZE_MAX, slots_num, txq_id);
priv->cfg->ops->lib->txq_init(priv, txq);
}
int iwl_legacy_enqueue_hcmd(struct iwl_priv *priv, struct iwl_host_cmd *cmd)
{
struct iwl_tx_queue *txq = &priv->txq[priv->cmd_queue];
struct iwl_queue *q = &txq->q;
struct iwl_device_cmd *out_cmd;
struct iwl_cmd_meta *out_meta;
dma_addr_t phys_addr;
unsigned long flags;
int len;
u32 idx;
u16 fix_size;
cmd->len = priv->cfg->ops->utils->get_hcmd_size(cmd->id, cmd->len);
fix_size = (u16)(cmd->len + sizeof(out_cmd->hdr));
BUG_ON((fix_size > TFD_MAX_PAYLOAD_SIZE) &&
!(cmd->flags & CMD_SIZE_HUGE));
BUG_ON(fix_size > IWL_MAX_CMD_SIZE);
if (iwl_legacy_is_rfkill(priv) || iwl_legacy_is_ctkill(priv)) {
IWL_WARN(priv, "Not sending command - %s KILL\n",
iwl_legacy_is_rfkill(priv) ? "RF" : "CT");
return -EIO;
}
spin_lock_irqsave(&priv->hcmd_lock, flags);
if (iwl_legacy_queue_space(q) < ((cmd->flags & CMD_ASYNC) ? 2 : 1)) {
spin_unlock_irqrestore(&priv->hcmd_lock, flags);
IWL_ERR(priv, "Restarting adapter due to command queue full\n");
queue_work(priv->workqueue, &priv->restart);
return -ENOSPC;
}
idx = iwl_legacy_get_cmd_index(q, q->write_ptr, cmd->flags & CMD_SIZE_HUGE);
out_cmd = txq->cmd[idx];
out_meta = &txq->meta[idx];
if (WARN_ON(out_meta->flags & CMD_MAPPED)) {
spin_unlock_irqrestore(&priv->hcmd_lock, flags);
return -ENOSPC;
}
memset(out_meta, 0, sizeof(*out_meta));
out_meta->flags = cmd->flags | CMD_MAPPED;
if (cmd->flags & CMD_WANT_SKB)
out_meta->source = cmd;
if (cmd->flags & CMD_ASYNC)
out_meta->callback = cmd->callback;
out_cmd->hdr.cmd = cmd->id;
memcpy(&out_cmd->cmd.payload, cmd->data, cmd->len);
out_cmd->hdr.flags = 0;
out_cmd->hdr.sequence = cpu_to_le16(QUEUE_TO_SEQ(priv->cmd_queue) |
INDEX_TO_SEQ(q->write_ptr));
if (cmd->flags & CMD_SIZE_HUGE)
out_cmd->hdr.sequence |= SEQ_HUGE_FRAME;
len = sizeof(struct iwl_device_cmd);
if (idx == TFD_CMD_SLOTS)
len = IWL_MAX_CMD_SIZE;
#ifdef CONFIG_IWLWIFI_LEGACY_DEBUG
switch (out_cmd->hdr.cmd) {
case REPLY_TX_LINK_QUALITY_CMD:
case SENSITIVITY_CMD:
IWL_DEBUG_HC_DUMP(priv,
"Sending command %s (#%x), seq: 0x%04X, "
"%d bytes at %d[%d]:%d\n",
iwl_legacy_get_cmd_string(out_cmd->hdr.cmd),
out_cmd->hdr.cmd,
le16_to_cpu(out_cmd->hdr.sequence), fix_size,
q->write_ptr, idx, priv->cmd_queue);
break;
default:
IWL_DEBUG_HC(priv, "Sending command %s (#%x), seq: 0x%04X, "
"%d bytes at %d[%d]:%d\n",
iwl_legacy_get_cmd_string(out_cmd->hdr.cmd),
out_cmd->hdr.cmd,
le16_to_cpu(out_cmd->hdr.sequence), fix_size,
q->write_ptr, idx, priv->cmd_queue);
}
#endif
txq->need_update = 1;
if (priv->cfg->ops->lib->txq_update_byte_cnt_tbl)
priv->cfg->ops->lib->txq_update_byte_cnt_tbl(priv, txq, 0);
phys_addr = pci_map_single(priv->pci_dev, &out_cmd->hdr,
fix_size, PCI_DMA_BIDIRECTIONAL);
dma_unmap_addr_set(out_meta, mapping, phys_addr);
dma_unmap_len_set(out_meta, len, fix_size);
trace_iwlwifi_legacy_dev_hcmd(priv, &out_cmd->hdr,
fix_size, cmd->flags);
priv->cfg->ops->lib->txq_attach_buf_to_tfd(priv, txq,
phys_addr, fix_size, 1,
U32_PAD(cmd->len));
q->write_ptr = iwl_legacy_queue_inc_wrap(q->write_ptr, q->n_bd);
iwl_legacy_txq_update_write_ptr(priv, txq);
spin_unlock_irqrestore(&priv->hcmd_lock, flags);
return idx;
}
static void iwl_legacy_hcmd_queue_reclaim(struct iwl_priv *priv, int txq_id,
int idx, int cmd_idx)
{
struct iwl_tx_queue *txq = &priv->txq[txq_id];
struct iwl_queue *q = &txq->q;
int nfreed = 0;
if ((idx >= q->n_bd) || (iwl_legacy_queue_used(q, idx) == 0)) {
IWL_ERR(priv, "Read index for DMA queue txq id (%d), index %d, "
"is out of range [0-%d] %d %d.\n", txq_id,
idx, q->n_bd, q->write_ptr, q->read_ptr);
return;
}
for (idx = iwl_legacy_queue_inc_wrap(idx, q->n_bd); q->read_ptr != idx;
q->read_ptr = iwl_legacy_queue_inc_wrap(q->read_ptr, q->n_bd)) {
if (nfreed++ > 0) {
IWL_ERR(priv, "HCMD skipped: index (%d) %d %d\n", idx,
q->write_ptr, q->read_ptr);
queue_work(priv->workqueue, &priv->restart);
}
}
}
void
iwl_legacy_tx_cmd_complete(struct iwl_priv *priv, struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u16 sequence = le16_to_cpu(pkt->hdr.sequence);
int txq_id = SEQ_TO_QUEUE(sequence);
int index = SEQ_TO_INDEX(sequence);
int cmd_index;
bool huge = !!(pkt->hdr.sequence & SEQ_HUGE_FRAME);
struct iwl_device_cmd *cmd;
struct iwl_cmd_meta *meta;
struct iwl_tx_queue *txq = &priv->txq[priv->cmd_queue];
unsigned long flags;
if (WARN(txq_id != priv->cmd_queue,
"wrong command queue %d (should be %d), sequence 0x%X readp=%d writep=%d\n",
txq_id, priv->cmd_queue, sequence,
priv->txq[priv->cmd_queue].q.read_ptr,
priv->txq[priv->cmd_queue].q.write_ptr)) {
iwl_print_hex_error(priv, pkt, 32);
return;
}
cmd_index = iwl_legacy_get_cmd_index(&txq->q, index, huge);
cmd = txq->cmd[cmd_index];
meta = &txq->meta[cmd_index];
txq->time_stamp = jiffies;
pci_unmap_single(priv->pci_dev,
dma_unmap_addr(meta, mapping),
dma_unmap_len(meta, len),
PCI_DMA_BIDIRECTIONAL);
if (meta->flags & CMD_WANT_SKB) {
meta->source->reply_page = (unsigned long)rxb_addr(rxb);
rxb->page = NULL;
} else if (meta->callback)
meta->callback(priv, cmd, pkt);
spin_lock_irqsave(&priv->hcmd_lock, flags);
iwl_legacy_hcmd_queue_reclaim(priv, txq_id, index, cmd_index);
if (!(meta->flags & CMD_ASYNC)) {
clear_bit(STATUS_HCMD_ACTIVE, &priv->status);
IWL_DEBUG_INFO(priv, "Clearing HCMD_ACTIVE for command %s\n",
iwl_legacy_get_cmd_string(cmd->hdr.cmd));
wake_up(&priv->wait_command_queue);
}
meta->flags = 0;
spin_unlock_irqrestore(&priv->hcmd_lock, flags);
}
