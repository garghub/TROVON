void iwl_txq_update_write_ptr(struct iwl_priv *priv, struct iwl_tx_queue *txq)
{
u32 reg = 0;
int txq_id = txq->q.id;
if (txq->need_update == 0)
return;
if (priv->cfg->base_params->shadow_reg_enable) {
iwl_write32(priv, HBUS_TARG_WRPTR,
txq->q.write_ptr | (txq_id << 8));
} else {
if (test_bit(STATUS_POWER_PMI, &priv->status)) {
reg = iwl_read32(priv, CSR_UCODE_DRV_GP1);
if (reg & CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP) {
IWL_DEBUG_INFO(priv,
"Tx queue %d requesting wakeup,"
" GP1 = 0x%x\n", txq_id, reg);
iwl_set_bit(priv, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
return;
}
iwl_write_direct32(priv, HBUS_TARG_WRPTR,
txq->q.write_ptr | (txq_id << 8));
} else
iwl_write32(priv, HBUS_TARG_WRPTR,
txq->q.write_ptr | (txq_id << 8));
}
txq->need_update = 0;
}
static inline dma_addr_t iwl_tfd_tb_get_addr(struct iwl_tfd *tfd, u8 idx)
{
struct iwl_tfd_tb *tb = &tfd->tbs[idx];
dma_addr_t addr = get_unaligned_le32(&tb->lo);
if (sizeof(dma_addr_t) > sizeof(u32))
addr |=
((dma_addr_t)(le16_to_cpu(tb->hi_n_len) & 0xF) << 16) << 16;
return addr;
}
static inline u16 iwl_tfd_tb_get_len(struct iwl_tfd *tfd, u8 idx)
{
struct iwl_tfd_tb *tb = &tfd->tbs[idx];
return le16_to_cpu(tb->hi_n_len) >> 4;
}
static inline void iwl_tfd_set_tb(struct iwl_tfd *tfd, u8 idx,
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
static inline u8 iwl_tfd_get_num_tbs(struct iwl_tfd *tfd)
{
return tfd->num_tbs & 0x1f;
}
static void iwlagn_unmap_tfd(struct iwl_priv *priv, struct iwl_cmd_meta *meta,
struct iwl_tfd *tfd, int dma_dir)
{
struct pci_dev *dev = priv->pci_dev;
int i;
int num_tbs;
num_tbs = iwl_tfd_get_num_tbs(tfd);
if (num_tbs >= IWL_NUM_OF_TBS) {
IWL_ERR(priv, "Too many chunks: %i\n", num_tbs);
return;
}
if (num_tbs)
pci_unmap_single(dev,
dma_unmap_addr(meta, mapping),
dma_unmap_len(meta, len),
PCI_DMA_BIDIRECTIONAL);
for (i = 1; i < num_tbs; i++)
pci_unmap_single(dev, iwl_tfd_tb_get_addr(tfd, i),
iwl_tfd_tb_get_len(tfd, i), dma_dir);
}
void iwlagn_txq_free_tfd(struct iwl_priv *priv, struct iwl_tx_queue *txq)
{
struct iwl_tfd *tfd_tmp = txq->tfds;
int index = txq->q.read_ptr;
iwlagn_unmap_tfd(priv, &txq->meta[index], &tfd_tmp[index],
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
int iwlagn_txq_attach_buf_to_tfd(struct iwl_priv *priv,
struct iwl_tx_queue *txq,
dma_addr_t addr, u16 len,
u8 reset)
{
struct iwl_queue *q;
struct iwl_tfd *tfd, *tfd_tmp;
u32 num_tbs;
q = &txq->q;
tfd_tmp = txq->tfds;
tfd = &tfd_tmp[q->write_ptr];
if (reset)
memset(tfd, 0, sizeof(*tfd));
num_tbs = iwl_tfd_get_num_tbs(tfd);
if (num_tbs >= IWL_NUM_OF_TBS) {
IWL_ERR(priv, "Error can not send more than %d chunks\n",
IWL_NUM_OF_TBS);
return -EINVAL;
}
if (WARN_ON(addr & ~DMA_BIT_MASK(36)))
return -EINVAL;
if (unlikely(addr & ~IWL_TX_DMA_MASK))
IWL_ERR(priv, "Unaligned address = %llx\n",
(unsigned long long)addr);
iwl_tfd_set_tb(tfd, num_tbs, addr, len);
return 0;
}
static int iwlagn_tx_queue_init(struct iwl_priv *priv, struct iwl_tx_queue *txq)
{
int txq_id = txq->q.id;
iwl_write_direct32(priv, FH_MEM_CBBC_QUEUE(txq_id),
txq->q.dma_addr >> 8);
return 0;
}
void iwl_tx_queue_unmap(struct iwl_priv *priv, int txq_id)
{
struct iwl_tx_queue *txq = &priv->txq[txq_id];
struct iwl_queue *q = &txq->q;
if (q->n_bd == 0)
return;
while (q->write_ptr != q->read_ptr) {
iwlagn_txq_free_tfd(priv, txq);
q->read_ptr = iwl_queue_inc_wrap(q->read_ptr, q->n_bd);
}
}
void iwl_tx_queue_free(struct iwl_priv *priv, int txq_id)
{
struct iwl_tx_queue *txq = &priv->txq[txq_id];
struct device *dev = &priv->pci_dev->dev;
int i;
iwl_tx_queue_unmap(priv, txq_id);
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
void iwl_cmd_queue_unmap(struct iwl_priv *priv)
{
struct iwl_tx_queue *txq = &priv->txq[priv->cmd_queue];
struct iwl_queue *q = &txq->q;
int i;
if (q->n_bd == 0)
return;
while (q->read_ptr != q->write_ptr) {
i = get_cmd_index(q, q->read_ptr);
if (txq->meta[i].flags & CMD_MAPPED) {
iwlagn_unmap_tfd(priv, &txq->meta[i], &txq->tfds[i],
PCI_DMA_BIDIRECTIONAL);
txq->meta[i].flags = 0;
}
q->read_ptr = iwl_queue_inc_wrap(q->read_ptr, q->n_bd);
}
}
void iwl_cmd_queue_free(struct iwl_priv *priv)
{
struct iwl_tx_queue *txq = &priv->txq[priv->cmd_queue];
struct device *dev = &priv->pci_dev->dev;
int i;
iwl_cmd_queue_unmap(priv);
for (i = 0; i < TFD_CMD_SLOTS; i++)
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
int iwl_queue_space(const struct iwl_queue *q)
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
static int iwl_queue_init(struct iwl_priv *priv, struct iwl_queue *q,
int count, int slots_num, u32 id)
{
q->n_bd = count;
q->n_window = slots_num;
q->id = id;
if (WARN_ON(!is_power_of_2(count)))
return -EINVAL;
if (WARN_ON(!is_power_of_2(slots_num)))
return -EINVAL;
q->low_mark = q->n_window / 4;
if (q->low_mark < 4)
q->low_mark = 4;
q->high_mark = q->n_window / 8;
if (q->high_mark < 2)
q->high_mark = 2;
q->write_ptr = q->read_ptr = 0;
return 0;
}
static int iwl_tx_queue_alloc(struct iwl_priv *priv,
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
int iwl_tx_queue_init(struct iwl_priv *priv, struct iwl_tx_queue *txq,
int slots_num, u32 txq_id)
{
int i, len;
int ret;
txq->meta = kzalloc(sizeof(struct iwl_cmd_meta) * slots_num,
GFP_KERNEL);
txq->cmd = kzalloc(sizeof(struct iwl_device_cmd *) * slots_num,
GFP_KERNEL);
if (!txq->meta || !txq->cmd)
goto out_free_arrays;
len = sizeof(struct iwl_device_cmd);
for (i = 0; i < slots_num; i++) {
txq->cmd[i] = kmalloc(len, GFP_KERNEL);
if (!txq->cmd[i])
goto err;
}
ret = iwl_tx_queue_alloc(priv, txq, txq_id);
if (ret)
goto err;
txq->need_update = 0;
if (txq_id < 4)
iwl_set_swq_id(txq, txq_id, txq_id);
BUILD_BUG_ON(TFD_QUEUE_SIZE_MAX & (TFD_QUEUE_SIZE_MAX - 1));
ret = iwl_queue_init(priv, &txq->q, TFD_QUEUE_SIZE_MAX, slots_num, txq_id);
if (ret)
return ret;
iwlagn_tx_queue_init(priv, txq);
return 0;
err:
for (i = 0; i < slots_num; i++)
kfree(txq->cmd[i]);
out_free_arrays:
kfree(txq->meta);
kfree(txq->cmd);
return -ENOMEM;
}
void iwl_tx_queue_reset(struct iwl_priv *priv, struct iwl_tx_queue *txq,
int slots_num, u32 txq_id)
{
memset(txq->meta, 0, sizeof(struct iwl_cmd_meta) * slots_num);
txq->need_update = 0;
iwl_queue_init(priv, &txq->q, TFD_QUEUE_SIZE_MAX, slots_num, txq_id);
iwlagn_tx_queue_init(priv, txq);
}
int iwl_enqueue_hcmd(struct iwl_priv *priv, struct iwl_host_cmd *cmd)
{
struct iwl_tx_queue *txq = &priv->txq[priv->cmd_queue];
struct iwl_queue *q = &txq->q;
struct iwl_device_cmd *out_cmd;
struct iwl_cmd_meta *out_meta;
dma_addr_t phys_addr;
unsigned long flags;
u32 idx;
u16 copy_size, cmd_size;
bool is_ct_kill = false;
bool had_nocopy = false;
int i;
u8 *cmd_dest;
#ifdef CONFIG_IWLWIFI_DEVICE_TRACING
const void *trace_bufs[IWL_MAX_CMD_TFDS + 1] = {};
int trace_lens[IWL_MAX_CMD_TFDS + 1] = {};
int trace_idx;
#endif
if (test_bit(STATUS_FW_ERROR, &priv->status)) {
IWL_WARN(priv, "fw recovery, no hcmd send\n");
return -EIO;
}
copy_size = sizeof(out_cmd->hdr);
cmd_size = sizeof(out_cmd->hdr);
BUILD_BUG_ON(IWL_MAX_CMD_TFDS > IWL_NUM_OF_TBS - 1);
for (i = 0; i < IWL_MAX_CMD_TFDS; i++) {
if (!cmd->len[i])
continue;
if (cmd->dataflags[i] & IWL_HCMD_DFL_NOCOPY) {
had_nocopy = true;
} else {
if (WARN_ON(had_nocopy))
return -EINVAL;
copy_size += cmd->len[i];
}
cmd_size += cmd->len[i];
}
if (WARN_ON(copy_size > TFD_MAX_PAYLOAD_SIZE))
return -EINVAL;
if (iwl_is_rfkill(priv) || iwl_is_ctkill(priv)) {
IWL_WARN(priv, "Not sending command - %s KILL\n",
iwl_is_rfkill(priv) ? "RF" : "CT");
return -EIO;
}
spin_lock_irqsave(&priv->hcmd_lock, flags);
if (iwl_queue_space(q) < ((cmd->flags & CMD_ASYNC) ? 2 : 1)) {
spin_unlock_irqrestore(&priv->hcmd_lock, flags);
IWL_ERR(priv, "No space in command queue\n");
is_ct_kill = iwl_check_for_ct_kill(priv);
if (!is_ct_kill) {
IWL_ERR(priv, "Restarting adapter due to queue full\n");
iwlagn_fw_error(priv, false);
}
return -ENOSPC;
}
idx = get_cmd_index(q, q->write_ptr);
out_cmd = txq->cmd[idx];
out_meta = &txq->meta[idx];
if (WARN_ON(out_meta->flags & CMD_MAPPED)) {
spin_unlock_irqrestore(&priv->hcmd_lock, flags);
return -ENOSPC;
}
memset(out_meta, 0, sizeof(*out_meta));
if (cmd->flags & CMD_WANT_SKB)
out_meta->source = cmd;
if (cmd->flags & CMD_ASYNC)
out_meta->callback = cmd->callback;
out_cmd->hdr.cmd = cmd->id;
out_cmd->hdr.flags = 0;
out_cmd->hdr.sequence = cpu_to_le16(QUEUE_TO_SEQ(priv->cmd_queue) |
INDEX_TO_SEQ(q->write_ptr));
cmd_dest = &out_cmd->cmd.payload[0];
for (i = 0; i < IWL_MAX_CMD_TFDS; i++) {
if (!cmd->len[i])
continue;
if (cmd->dataflags[i] & IWL_HCMD_DFL_NOCOPY)
break;
memcpy(cmd_dest, cmd->data[i], cmd->len[i]);
cmd_dest += cmd->len[i];
}
IWL_DEBUG_HC(priv, "Sending command %s (#%x), seq: 0x%04X, "
"%d bytes at %d[%d]:%d\n",
get_cmd_string(out_cmd->hdr.cmd),
out_cmd->hdr.cmd,
le16_to_cpu(out_cmd->hdr.sequence), cmd_size,
q->write_ptr, idx, priv->cmd_queue);
phys_addr = pci_map_single(priv->pci_dev, &out_cmd->hdr,
copy_size, PCI_DMA_BIDIRECTIONAL);
if (unlikely(pci_dma_mapping_error(priv->pci_dev, phys_addr))) {
idx = -ENOMEM;
goto out;
}
dma_unmap_addr_set(out_meta, mapping, phys_addr);
dma_unmap_len_set(out_meta, len, copy_size);
iwlagn_txq_attach_buf_to_tfd(priv, txq, phys_addr, copy_size, 1);
#ifdef CONFIG_IWLWIFI_DEVICE_TRACING
trace_bufs[0] = &out_cmd->hdr;
trace_lens[0] = copy_size;
trace_idx = 1;
#endif
for (i = 0; i < IWL_MAX_CMD_TFDS; i++) {
if (!cmd->len[i])
continue;
if (!(cmd->dataflags[i] & IWL_HCMD_DFL_NOCOPY))
continue;
phys_addr = pci_map_single(priv->pci_dev, (void *)cmd->data[i],
cmd->len[i], PCI_DMA_BIDIRECTIONAL);
if (pci_dma_mapping_error(priv->pci_dev, phys_addr)) {
iwlagn_unmap_tfd(priv, out_meta,
&txq->tfds[q->write_ptr],
PCI_DMA_BIDIRECTIONAL);
idx = -ENOMEM;
goto out;
}
iwlagn_txq_attach_buf_to_tfd(priv, txq, phys_addr,
cmd->len[i], 0);
#ifdef CONFIG_IWLWIFI_DEVICE_TRACING
trace_bufs[trace_idx] = cmd->data[i];
trace_lens[trace_idx] = cmd->len[i];
trace_idx++;
#endif
}
out_meta->flags = cmd->flags | CMD_MAPPED;
txq->need_update = 1;
BUILD_BUG_ON(IWL_MAX_CMD_TFDS + 1 != 3);
#ifdef CONFIG_IWLWIFI_DEVICE_TRACING
trace_iwlwifi_dev_hcmd(priv, cmd->flags,
trace_bufs[0], trace_lens[0],
trace_bufs[1], trace_lens[1],
trace_bufs[2], trace_lens[2]);
#endif
q->write_ptr = iwl_queue_inc_wrap(q->write_ptr, q->n_bd);
iwl_txq_update_write_ptr(priv, txq);
out:
spin_unlock_irqrestore(&priv->hcmd_lock, flags);
return idx;
}
static void iwl_hcmd_queue_reclaim(struct iwl_priv *priv, int txq_id, int idx)
{
struct iwl_tx_queue *txq = &priv->txq[txq_id];
struct iwl_queue *q = &txq->q;
int nfreed = 0;
if ((idx >= q->n_bd) || (iwl_queue_used(q, idx) == 0)) {
IWL_ERR(priv, "Read index for DMA queue txq id (%d), index %d, "
"is out of range [0-%d] %d %d.\n", txq_id,
idx, q->n_bd, q->write_ptr, q->read_ptr);
return;
}
for (idx = iwl_queue_inc_wrap(idx, q->n_bd); q->read_ptr != idx;
q->read_ptr = iwl_queue_inc_wrap(q->read_ptr, q->n_bd)) {
if (nfreed++ > 0) {
IWL_ERR(priv, "HCMD skipped: index (%d) %d %d\n", idx,
q->write_ptr, q->read_ptr);
iwlagn_fw_error(priv, false);
}
}
}
void iwl_tx_cmd_complete(struct iwl_priv *priv, struct iwl_rx_mem_buffer *rxb)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u16 sequence = le16_to_cpu(pkt->hdr.sequence);
int txq_id = SEQ_TO_QUEUE(sequence);
int index = SEQ_TO_INDEX(sequence);
int cmd_index;
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
cmd_index = get_cmd_index(&txq->q, index);
cmd = txq->cmd[cmd_index];
meta = &txq->meta[cmd_index];
iwlagn_unmap_tfd(priv, meta, &txq->tfds[index], PCI_DMA_BIDIRECTIONAL);
if (meta->flags & CMD_WANT_SKB) {
meta->source->reply_page = (unsigned long)rxb_addr(rxb);
rxb->page = NULL;
} else if (meta->callback)
meta->callback(priv, cmd, pkt);
spin_lock_irqsave(&priv->hcmd_lock, flags);
iwl_hcmd_queue_reclaim(priv, txq_id, index);
if (!(meta->flags & CMD_ASYNC)) {
clear_bit(STATUS_HCMD_ACTIVE, &priv->status);
IWL_DEBUG_INFO(priv, "Clearing HCMD_ACTIVE for command %s\n",
get_cmd_string(cmd->hdr.cmd));
wake_up_interruptible(&priv->wait_command_queue);
}
meta->flags = 0;
spin_unlock_irqrestore(&priv->hcmd_lock, flags);
}
