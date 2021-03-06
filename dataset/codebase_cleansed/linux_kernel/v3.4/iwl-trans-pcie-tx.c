void iwl_trans_txq_update_byte_cnt_tbl(struct iwl_trans *trans,
struct iwl_tx_queue *txq,
u16 byte_cnt)
{
struct iwlagn_scd_bc_tbl *scd_bc_tbl;
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
int write_ptr = txq->q.write_ptr;
int txq_id = txq->q.id;
u8 sec_ctl = 0;
u8 sta_id = 0;
u16 len = byte_cnt + IWL_TX_CRC_SIZE + IWL_TX_DELIMITER_SIZE;
__le16 bc_ent;
struct iwl_tx_cmd *tx_cmd =
(struct iwl_tx_cmd *) txq->cmd[txq->q.write_ptr]->payload;
scd_bc_tbl = trans_pcie->scd_bc_tbls.addr;
WARN_ON(len > 0xFFF || write_ptr >= TFD_QUEUE_SIZE_MAX);
sta_id = tx_cmd->sta_id;
sec_ctl = tx_cmd->sec_ctl;
switch (sec_ctl & TX_CMD_SEC_MSK) {
case TX_CMD_SEC_CCM:
len += CCMP_MIC_LEN;
break;
case TX_CMD_SEC_TKIP:
len += TKIP_ICV_LEN;
break;
case TX_CMD_SEC_WEP:
len += WEP_IV_LEN + WEP_ICV_LEN;
break;
}
bc_ent = cpu_to_le16((len & 0xFFF) | (sta_id << 12));
scd_bc_tbl[txq_id].tfd_offset[write_ptr] = bc_ent;
if (write_ptr < TFD_QUEUE_SIZE_BC_DUP)
scd_bc_tbl[txq_id].
tfd_offset[TFD_QUEUE_SIZE_MAX + write_ptr] = bc_ent;
}
void iwl_txq_update_write_ptr(struct iwl_trans *trans, struct iwl_tx_queue *txq)
{
u32 reg = 0;
int txq_id = txq->q.id;
if (txq->need_update == 0)
return;
if (cfg(trans)->base_params->shadow_reg_enable) {
iwl_write32(trans, HBUS_TARG_WRPTR,
txq->q.write_ptr | (txq_id << 8));
} else {
if (test_bit(STATUS_POWER_PMI, &trans->shrd->status)) {
reg = iwl_read32(trans, CSR_UCODE_DRV_GP1);
if (reg & CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP) {
IWL_DEBUG_INFO(trans,
"Tx queue %d requesting wakeup,"
" GP1 = 0x%x\n", txq_id, reg);
iwl_set_bit(trans, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
return;
}
iwl_write_direct32(trans, HBUS_TARG_WRPTR,
txq->q.write_ptr | (txq_id << 8));
} else
iwl_write32(trans, HBUS_TARG_WRPTR,
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
static void iwlagn_unmap_tfd(struct iwl_trans *trans, struct iwl_cmd_meta *meta,
struct iwl_tfd *tfd, enum dma_data_direction dma_dir)
{
int i;
int num_tbs;
num_tbs = iwl_tfd_get_num_tbs(tfd);
if (num_tbs >= IWL_NUM_OF_TBS) {
IWL_ERR(trans, "Too many chunks: %i\n", num_tbs);
return;
}
if (num_tbs)
dma_unmap_single(trans->dev,
dma_unmap_addr(meta, mapping),
dma_unmap_len(meta, len),
DMA_BIDIRECTIONAL);
for (i = 1; i < num_tbs; i++)
dma_unmap_single(trans->dev, iwl_tfd_tb_get_addr(tfd, i),
iwl_tfd_tb_get_len(tfd, i), dma_dir);
}
void iwlagn_txq_free_tfd(struct iwl_trans *trans, struct iwl_tx_queue *txq,
int index, enum dma_data_direction dma_dir)
{
struct iwl_tfd *tfd_tmp = txq->tfds;
lockdep_assert_held(&txq->lock);
iwlagn_unmap_tfd(trans, &txq->meta[index], &tfd_tmp[index], dma_dir);
if (txq->skbs) {
struct sk_buff *skb;
skb = txq->skbs[index];
if (skb) {
iwl_op_mode_free_skb(trans->op_mode, skb);
txq->skbs[index] = NULL;
}
}
}
int iwlagn_txq_attach_buf_to_tfd(struct iwl_trans *trans,
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
IWL_ERR(trans, "Error can not send more than %d chunks\n",
IWL_NUM_OF_TBS);
return -EINVAL;
}
if (WARN_ON(addr & ~DMA_BIT_MASK(36)))
return -EINVAL;
if (unlikely(addr & ~IWL_TX_DMA_MASK))
IWL_ERR(trans, "Unaligned address = %llx\n",
(unsigned long long)addr);
iwl_tfd_set_tb(tfd, num_tbs, addr, len);
return 0;
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
int iwl_queue_init(struct iwl_queue *q, int count, int slots_num, u32 id)
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
static void iwlagn_txq_inval_byte_cnt_tbl(struct iwl_trans *trans,
struct iwl_tx_queue *txq)
{
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwlagn_scd_bc_tbl *scd_bc_tbl = trans_pcie->scd_bc_tbls.addr;
int txq_id = txq->q.id;
int read_ptr = txq->q.read_ptr;
u8 sta_id = 0;
__le16 bc_ent;
struct iwl_tx_cmd *tx_cmd =
(struct iwl_tx_cmd *) txq->cmd[txq->q.read_ptr]->payload;
WARN_ON(read_ptr >= TFD_QUEUE_SIZE_MAX);
if (txq_id != trans_pcie->cmd_queue)
sta_id = tx_cmd->sta_id;
bc_ent = cpu_to_le16(1 | (sta_id << 12));
scd_bc_tbl[txq_id].tfd_offset[read_ptr] = bc_ent;
if (read_ptr < TFD_QUEUE_SIZE_BC_DUP)
scd_bc_tbl[txq_id].
tfd_offset[TFD_QUEUE_SIZE_MAX + read_ptr] = bc_ent;
}
static int iwlagn_tx_queue_set_q2ratid(struct iwl_trans *trans, u16 ra_tid,
u16 txq_id)
{
u32 tbl_dw_addr;
u32 tbl_dw;
u16 scd_q2ratid;
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
scd_q2ratid = ra_tid & SCD_QUEUE_RA_TID_MAP_RATID_MSK;
tbl_dw_addr = trans_pcie->scd_base_addr +
SCD_TRANS_TBL_OFFSET_QUEUE(txq_id);
tbl_dw = iwl_read_targ_mem(trans, tbl_dw_addr);
if (txq_id & 0x1)
tbl_dw = (scd_q2ratid << 16) | (tbl_dw & 0x0000FFFF);
else
tbl_dw = scd_q2ratid | (tbl_dw & 0xFFFF0000);
iwl_write_targ_mem(trans, tbl_dw_addr, tbl_dw);
return 0;
}
static void iwlagn_tx_queue_stop_scheduler(struct iwl_trans *trans, u16 txq_id)
{
iwl_write_prph(trans,
SCD_QUEUE_STATUS_BITS(txq_id),
(0 << SCD_QUEUE_STTS_REG_POS_ACTIVE)|
(1 << SCD_QUEUE_STTS_REG_POS_SCD_ACT_EN));
}
void iwl_trans_set_wr_ptrs(struct iwl_trans *trans,
int txq_id, u32 index)
{
IWL_DEBUG_TX_QUEUES(trans, "Q %d WrPtr: %d", txq_id, index & 0xff);
iwl_write_direct32(trans, HBUS_TARG_WRPTR,
(index & 0xff) | (txq_id << 8));
iwl_write_prph(trans, SCD_QUEUE_RDPTR(txq_id), index);
}
void iwl_trans_tx_queue_set_status(struct iwl_trans *trans,
struct iwl_tx_queue *txq,
int tx_fifo_id, int scd_retry)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int txq_id = txq->q.id;
int active =
test_bit(txq_id, &trans_pcie->txq_ctx_active_msk) ? 1 : 0;
iwl_write_prph(trans, SCD_QUEUE_STATUS_BITS(txq_id),
(active << SCD_QUEUE_STTS_REG_POS_ACTIVE) |
(tx_fifo_id << SCD_QUEUE_STTS_REG_POS_TXF) |
(1 << SCD_QUEUE_STTS_REG_POS_WSL) |
SCD_QUEUE_STTS_REG_MSK);
txq->sched_retry = scd_retry;
if (active)
IWL_DEBUG_TX_QUEUES(trans, "Activate %s Queue %d on FIFO %d\n",
scd_retry ? "BA" : "AC/CMD", txq_id, tx_fifo_id);
else
IWL_DEBUG_TX_QUEUES(trans, "Deactivate %s Queue %d\n",
scd_retry ? "BA" : "AC/CMD", txq_id);
}
static inline int get_ac_from_tid(u16 tid)
{
if (likely(tid < ARRAY_SIZE(tid_to_ac)))
return tid_to_ac[tid];
return -EINVAL;
}
static inline int get_fifo_from_tid(struct iwl_trans_pcie *trans_pcie,
u8 ctx, u16 tid)
{
const u8 *ac_to_fifo = trans_pcie->ac_to_fifo[ctx];
if (likely(tid < ARRAY_SIZE(tid_to_ac)))
return ac_to_fifo[tid_to_ac[tid]];
return -EINVAL;
}
static inline bool is_agg_txqid_valid(struct iwl_trans *trans, int txq_id)
{
if (txq_id < IWLAGN_FIRST_AMPDU_QUEUE)
return false;
return txq_id < (IWLAGN_FIRST_AMPDU_QUEUE +
hw_params(trans).num_ampdu_queues);
}
void iwl_trans_pcie_tx_agg_setup(struct iwl_trans *trans,
enum iwl_rxon_context_id ctx, int sta_id,
int tid, int frame_limit, u16 ssn)
{
int tx_fifo, txq_id;
u16 ra_tid;
unsigned long flags;
struct iwl_trans_pcie *trans_pcie =
IWL_TRANS_GET_PCIE_TRANS(trans);
if (WARN_ON(sta_id == IWL_INVALID_STATION))
return;
if (WARN_ON(tid >= IWL_MAX_TID_COUNT))
return;
tx_fifo = get_fifo_from_tid(trans_pcie, ctx, tid);
if (WARN_ON(tx_fifo < 0)) {
IWL_ERR(trans, "txq_agg_setup, bad fifo: %d\n", tx_fifo);
return;
}
txq_id = trans_pcie->agg_txq[sta_id][tid];
if (WARN_ON_ONCE(!is_agg_txqid_valid(trans, txq_id))) {
IWL_ERR(trans,
"queue number out of range: %d, must be %d to %d\n",
txq_id, IWLAGN_FIRST_AMPDU_QUEUE,
IWLAGN_FIRST_AMPDU_QUEUE +
hw_params(trans).num_ampdu_queues - 1);
return;
}
ra_tid = BUILD_RAxTID(sta_id, tid);
spin_lock_irqsave(&trans_pcie->irq_lock, flags);
iwlagn_tx_queue_stop_scheduler(trans, txq_id);
iwlagn_tx_queue_set_q2ratid(trans, ra_tid, txq_id);
iwl_set_bits_prph(trans, SCD_QUEUECHAIN_SEL, (1<<txq_id));
iwl_set_bits_prph(trans, SCD_AGGR_SEL, (1<<txq_id));
trans_pcie->txq[txq_id].q.read_ptr = (ssn & 0xff);
trans_pcie->txq[txq_id].q.write_ptr = (ssn & 0xff);
iwl_trans_set_wr_ptrs(trans, txq_id, ssn);
iwl_write_targ_mem(trans, trans_pcie->scd_base_addr +
SCD_CONTEXT_QUEUE_OFFSET(txq_id) +
sizeof(u32),
((frame_limit <<
SCD_QUEUE_CTX_REG2_WIN_SIZE_POS) &
SCD_QUEUE_CTX_REG2_WIN_SIZE_MSK) |
((frame_limit <<
SCD_QUEUE_CTX_REG2_FRAME_LIMIT_POS) &
SCD_QUEUE_CTX_REG2_FRAME_LIMIT_MSK));
iwl_set_bits_prph(trans, SCD_INTERRUPT_MASK, (1 << txq_id));
iwl_trans_tx_queue_set_status(trans, &trans_pcie->txq[txq_id],
tx_fifo, 1);
trans_pcie->txq[txq_id].sta_id = sta_id;
trans_pcie->txq[txq_id].tid = tid;
spin_unlock_irqrestore(&trans_pcie->irq_lock, flags);
}
static int iwlagn_txq_ctx_activate_free(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int txq_id;
for (txq_id = 0; txq_id < cfg(trans)->base_params->num_of_queues;
txq_id++)
if (!test_and_set_bit(txq_id,
&trans_pcie->txq_ctx_active_msk))
return txq_id;
return -1;
}
int iwl_trans_pcie_tx_agg_alloc(struct iwl_trans *trans,
int sta_id, int tid)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int txq_id;
txq_id = iwlagn_txq_ctx_activate_free(trans);
if (txq_id == -1) {
IWL_ERR(trans, "No free aggregation queue available\n");
return -ENXIO;
}
trans_pcie->agg_txq[sta_id][tid] = txq_id;
iwl_set_swq_id(&trans_pcie->txq[txq_id], get_ac_from_tid(tid), txq_id);
return 0;
}
int iwl_trans_pcie_tx_agg_disable(struct iwl_trans *trans, int sta_id, int tid)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
u8 txq_id = trans_pcie->agg_txq[sta_id][tid];
if (WARN_ON_ONCE(!is_agg_txqid_valid(trans, txq_id))) {
IWL_ERR(trans,
"queue number out of range: %d, must be %d to %d\n",
txq_id, IWLAGN_FIRST_AMPDU_QUEUE,
IWLAGN_FIRST_AMPDU_QUEUE +
hw_params(trans).num_ampdu_queues - 1);
return -EINVAL;
}
iwlagn_tx_queue_stop_scheduler(trans, txq_id);
iwl_clear_bits_prph(trans, SCD_AGGR_SEL, (1 << txq_id));
trans_pcie->agg_txq[sta_id][tid] = 0;
trans_pcie->txq[txq_id].q.read_ptr = 0;
trans_pcie->txq[txq_id].q.write_ptr = 0;
iwl_trans_set_wr_ptrs(trans, txq_id, 0);
iwl_clear_bits_prph(trans, SCD_INTERRUPT_MASK, (1 << txq_id));
iwl_txq_ctx_deactivate(trans_pcie, txq_id);
iwl_trans_tx_queue_set_status(trans, &trans_pcie->txq[txq_id], 0, 0);
return 0;
}
static int iwl_enqueue_hcmd(struct iwl_trans *trans, struct iwl_host_cmd *cmd)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_tx_queue *txq = &trans_pcie->txq[trans_pcie->cmd_queue];
struct iwl_queue *q = &txq->q;
struct iwl_device_cmd *out_cmd;
struct iwl_cmd_meta *out_meta;
dma_addr_t phys_addr;
u32 idx;
u16 copy_size, cmd_size;
bool had_nocopy = false;
int i;
u8 *cmd_dest;
#ifdef CONFIG_IWLWIFI_DEVICE_TRACING
const void *trace_bufs[IWL_MAX_CMD_TFDS + 1] = {};
int trace_lens[IWL_MAX_CMD_TFDS + 1] = {};
int trace_idx;
#endif
if (test_bit(STATUS_FW_ERROR, &trans->shrd->status)) {
IWL_WARN(trans, "fw recovery, no hcmd send\n");
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
spin_lock_bh(&txq->lock);
if (iwl_queue_space(q) < ((cmd->flags & CMD_ASYNC) ? 2 : 1)) {
spin_unlock_bh(&txq->lock);
IWL_ERR(trans, "No space in command queue\n");
iwl_op_mode_cmd_queue_full(trans->op_mode);
return -ENOSPC;
}
idx = get_cmd_index(q, q->write_ptr);
out_cmd = txq->cmd[idx];
out_meta = &txq->meta[idx];
memset(out_meta, 0, sizeof(*out_meta));
if (cmd->flags & CMD_WANT_SKB)
out_meta->source = cmd;
out_cmd->hdr.cmd = cmd->id;
out_cmd->hdr.flags = 0;
out_cmd->hdr.sequence =
cpu_to_le16(QUEUE_TO_SEQ(trans_pcie->cmd_queue) |
INDEX_TO_SEQ(q->write_ptr));
cmd_dest = out_cmd->payload;
for (i = 0; i < IWL_MAX_CMD_TFDS; i++) {
if (!cmd->len[i])
continue;
if (cmd->dataflags[i] & IWL_HCMD_DFL_NOCOPY)
break;
memcpy(cmd_dest, cmd->data[i], cmd->len[i]);
cmd_dest += cmd->len[i];
}
IWL_DEBUG_HC(trans, "Sending command %s (#%x), seq: 0x%04X, "
"%d bytes at %d[%d]:%d\n",
get_cmd_string(out_cmd->hdr.cmd),
out_cmd->hdr.cmd,
le16_to_cpu(out_cmd->hdr.sequence), cmd_size,
q->write_ptr, idx, trans_pcie->cmd_queue);
phys_addr = dma_map_single(trans->dev, &out_cmd->hdr, copy_size,
DMA_BIDIRECTIONAL);
if (unlikely(dma_mapping_error(trans->dev, phys_addr))) {
idx = -ENOMEM;
goto out;
}
dma_unmap_addr_set(out_meta, mapping, phys_addr);
dma_unmap_len_set(out_meta, len, copy_size);
iwlagn_txq_attach_buf_to_tfd(trans, txq,
phys_addr, copy_size, 1);
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
phys_addr = dma_map_single(trans->dev,
(void *)cmd->data[i],
cmd->len[i], DMA_BIDIRECTIONAL);
if (dma_mapping_error(trans->dev, phys_addr)) {
iwlagn_unmap_tfd(trans, out_meta,
&txq->tfds[q->write_ptr],
DMA_BIDIRECTIONAL);
idx = -ENOMEM;
goto out;
}
iwlagn_txq_attach_buf_to_tfd(trans, txq, phys_addr,
cmd->len[i], 0);
#ifdef CONFIG_IWLWIFI_DEVICE_TRACING
trace_bufs[trace_idx] = cmd->data[i];
trace_lens[trace_idx] = cmd->len[i];
trace_idx++;
#endif
}
out_meta->flags = cmd->flags;
txq->need_update = 1;
BUILD_BUG_ON(IWL_MAX_CMD_TFDS + 1 != 3);
#ifdef CONFIG_IWLWIFI_DEVICE_TRACING
trace_iwlwifi_dev_hcmd(trans->dev, cmd->flags,
trace_bufs[0], trace_lens[0],
trace_bufs[1], trace_lens[1],
trace_bufs[2], trace_lens[2]);
#endif
q->write_ptr = iwl_queue_inc_wrap(q->write_ptr, q->n_bd);
iwl_txq_update_write_ptr(trans, txq);
out:
spin_unlock_bh(&txq->lock);
return idx;
}
static void iwl_hcmd_queue_reclaim(struct iwl_trans *trans, int txq_id,
int idx)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_tx_queue *txq = &trans_pcie->txq[txq_id];
struct iwl_queue *q = &txq->q;
int nfreed = 0;
lockdep_assert_held(&txq->lock);
if ((idx >= q->n_bd) || (iwl_queue_used(q, idx) == 0)) {
IWL_ERR(trans, "%s: Read index for DMA queue txq id (%d), "
"index %d is out of range [0-%d] %d %d.\n", __func__,
txq_id, idx, q->n_bd, q->write_ptr, q->read_ptr);
return;
}
for (idx = iwl_queue_inc_wrap(idx, q->n_bd); q->read_ptr != idx;
q->read_ptr = iwl_queue_inc_wrap(q->read_ptr, q->n_bd)) {
if (nfreed++ > 0) {
IWL_ERR(trans, "HCMD skipped: index (%d) %d %d\n", idx,
q->write_ptr, q->read_ptr);
iwl_op_mode_nic_error(trans->op_mode);
}
}
}
void iwl_tx_cmd_complete(struct iwl_trans *trans, struct iwl_rx_cmd_buffer *rxb,
int handler_status)
{
struct iwl_rx_packet *pkt = rxb_addr(rxb);
u16 sequence = le16_to_cpu(pkt->hdr.sequence);
int txq_id = SEQ_TO_QUEUE(sequence);
int index = SEQ_TO_INDEX(sequence);
int cmd_index;
struct iwl_device_cmd *cmd;
struct iwl_cmd_meta *meta;
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_tx_queue *txq = &trans_pcie->txq[trans_pcie->cmd_queue];
if (WARN(txq_id != trans_pcie->cmd_queue,
"wrong command queue %d (should be %d), sequence 0x%X readp=%d writep=%d\n",
txq_id, trans_pcie->cmd_queue, sequence,
trans_pcie->txq[trans_pcie->cmd_queue].q.read_ptr,
trans_pcie->txq[trans_pcie->cmd_queue].q.write_ptr)) {
iwl_print_hex_error(trans, pkt, 32);
return;
}
spin_lock(&txq->lock);
cmd_index = get_cmd_index(&txq->q, index);
cmd = txq->cmd[cmd_index];
meta = &txq->meta[cmd_index];
txq->time_stamp = jiffies;
iwlagn_unmap_tfd(trans, meta, &txq->tfds[index],
DMA_BIDIRECTIONAL);
if (meta->flags & CMD_WANT_SKB) {
struct page *p = rxb_steal_page(rxb);
meta->source->resp_pkt = pkt;
meta->source->_rx_page_addr = (unsigned long)page_address(p);
meta->source->_rx_page_order = hw_params(trans).rx_page_order;
meta->source->handler_status = handler_status;
}
iwl_hcmd_queue_reclaim(trans, txq_id, index);
if (!(meta->flags & CMD_ASYNC)) {
if (!test_bit(STATUS_HCMD_ACTIVE, &trans->shrd->status)) {
IWL_WARN(trans,
"HCMD_ACTIVE already clear for command %s\n",
get_cmd_string(cmd->hdr.cmd));
}
clear_bit(STATUS_HCMD_ACTIVE, &trans->shrd->status);
IWL_DEBUG_INFO(trans, "Clearing HCMD_ACTIVE for command %s\n",
get_cmd_string(cmd->hdr.cmd));
wake_up(&trans->wait_command_queue);
}
meta->flags = 0;
spin_unlock(&txq->lock);
}
static int iwl_send_cmd_async(struct iwl_trans *trans, struct iwl_host_cmd *cmd)
{
int ret;
if (WARN_ON(cmd->flags & CMD_WANT_SKB))
return -EINVAL;
ret = iwl_enqueue_hcmd(trans, cmd);
if (ret < 0) {
IWL_ERR(trans,
"Error sending %s: enqueue_hcmd failed: %d\n",
get_cmd_string(cmd->id), ret);
return ret;
}
return 0;
}
static int iwl_send_cmd_sync(struct iwl_trans *trans, struct iwl_host_cmd *cmd)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int cmd_idx;
int ret;
IWL_DEBUG_INFO(trans, "Attempting to send sync command %s\n",
get_cmd_string(cmd->id));
if (test_bit(STATUS_FW_ERROR, &trans->shrd->status)) {
IWL_ERR(trans, "Command %s failed: FW Error\n",
get_cmd_string(cmd->id));
return -EIO;
}
if (WARN_ON(test_and_set_bit(STATUS_HCMD_ACTIVE,
&trans->shrd->status))) {
IWL_ERR(trans, "Command %s: a command is already active!\n",
get_cmd_string(cmd->id));
return -EIO;
}
IWL_DEBUG_INFO(trans, "Setting HCMD_ACTIVE for command %s\n",
get_cmd_string(cmd->id));
cmd_idx = iwl_enqueue_hcmd(trans, cmd);
if (cmd_idx < 0) {
ret = cmd_idx;
clear_bit(STATUS_HCMD_ACTIVE, &trans->shrd->status);
IWL_ERR(trans,
"Error sending %s: enqueue_hcmd failed: %d\n",
get_cmd_string(cmd->id), ret);
return ret;
}
ret = wait_event_timeout(trans->wait_command_queue,
!test_bit(STATUS_HCMD_ACTIVE, &trans->shrd->status),
HOST_COMPLETE_TIMEOUT);
if (!ret) {
if (test_bit(STATUS_HCMD_ACTIVE, &trans->shrd->status)) {
struct iwl_tx_queue *txq =
&trans_pcie->txq[trans_pcie->cmd_queue];
struct iwl_queue *q = &txq->q;
IWL_ERR(trans,
"Error sending %s: time out after %dms.\n",
get_cmd_string(cmd->id),
jiffies_to_msecs(HOST_COMPLETE_TIMEOUT));
IWL_ERR(trans,
"Current CMD queue read_ptr %d write_ptr %d\n",
q->read_ptr, q->write_ptr);
clear_bit(STATUS_HCMD_ACTIVE, &trans->shrd->status);
IWL_DEBUG_INFO(trans, "Clearing HCMD_ACTIVE for command"
"%s\n", get_cmd_string(cmd->id));
ret = -ETIMEDOUT;
goto cancel;
}
}
if ((cmd->flags & CMD_WANT_SKB) && !cmd->resp_pkt) {
IWL_ERR(trans, "Error: Response NULL in '%s'\n",
get_cmd_string(cmd->id));
ret = -EIO;
goto cancel;
}
return 0;
cancel:
if (cmd->flags & CMD_WANT_SKB) {
trans_pcie->txq[trans_pcie->cmd_queue].meta[cmd_idx].flags &=
~CMD_WANT_SKB;
}
if (cmd->resp_pkt) {
iwl_free_resp(cmd);
cmd->resp_pkt = NULL;
}
return ret;
}
int iwl_trans_pcie_send_cmd(struct iwl_trans *trans, struct iwl_host_cmd *cmd)
{
if (cmd->flags & CMD_ASYNC)
return iwl_send_cmd_async(trans, cmd);
return iwl_send_cmd_sync(trans, cmd);
}
int iwl_tx_queue_reclaim(struct iwl_trans *trans, int txq_id, int index,
struct sk_buff_head *skbs)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_tx_queue *txq = &trans_pcie->txq[txq_id];
struct iwl_queue *q = &txq->q;
int last_to_free;
int freed = 0;
if (WARN_ON(txq_id == trans_pcie->cmd_queue))
return 0;
lockdep_assert_held(&txq->lock);
last_to_free = iwl_queue_dec_wrap(index, q->n_bd);
if ((index >= q->n_bd) ||
(iwl_queue_used(q, last_to_free) == 0)) {
IWL_ERR(trans, "%s: Read index for DMA queue txq id (%d), "
"last_to_free %d is out of range [0-%d] %d %d.\n",
__func__, txq_id, last_to_free, q->n_bd,
q->write_ptr, q->read_ptr);
return 0;
}
if (WARN_ON(!skb_queue_empty(skbs)))
return 0;
for (;
q->read_ptr != index;
q->read_ptr = iwl_queue_inc_wrap(q->read_ptr, q->n_bd)) {
if (WARN_ON_ONCE(txq->skbs[txq->q.read_ptr] == NULL))
continue;
__skb_queue_tail(skbs, txq->skbs[txq->q.read_ptr]);
txq->skbs[txq->q.read_ptr] = NULL;
iwlagn_txq_inval_byte_cnt_tbl(trans, txq);
iwlagn_txq_free_tfd(trans, txq, txq->q.read_ptr, DMA_TO_DEVICE);
freed++;
}
return freed;
}
