void iwl_pcie_gen2_tx_stop(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int txq_id;
memset(trans_pcie->queue_stopped, 0, sizeof(trans_pcie->queue_stopped));
memset(trans_pcie->queue_used, 0, sizeof(trans_pcie->queue_used));
for (txq_id = 0; txq_id < ARRAY_SIZE(trans_pcie->txq); txq_id++) {
if (!trans_pcie->txq[txq_id])
continue;
iwl_pcie_gen2_txq_unmap(trans, txq_id);
}
}
static void iwl_pcie_gen2_update_byte_tbl(struct iwl_txq *txq, u16 byte_cnt,
int num_tbs)
{
struct iwlagn_scd_bc_tbl *scd_bc_tbl = txq->bc_tbl.addr;
int write_ptr = txq->write_ptr;
u8 filled_tfd_size, num_fetch_chunks;
u16 len = byte_cnt;
__le16 bc_ent;
len = DIV_ROUND_UP(len, 4);
if (WARN_ON(len > 0xFFF || write_ptr >= TFD_QUEUE_SIZE_MAX))
return;
filled_tfd_size = offsetof(struct iwl_tfh_tfd, tbs) +
num_tbs * sizeof(struct iwl_tfh_tb);
num_fetch_chunks = DIV_ROUND_UP(filled_tfd_size, 64) - 1;
bc_ent = cpu_to_le16(len | (num_fetch_chunks << 12));
scd_bc_tbl->tfd_offset[write_ptr] = bc_ent;
}
static void iwl_pcie_gen2_txq_inc_wr_ptr(struct iwl_trans *trans,
struct iwl_txq *txq)
{
lockdep_assert_held(&txq->lock);
IWL_DEBUG_TX(trans, "Q:%d WR: 0x%x\n", txq->id, txq->write_ptr);
iwl_write32(trans, HBUS_TARG_WRPTR, txq->write_ptr | (txq->id << 16));
}
static u8 iwl_pcie_gen2_get_num_tbs(struct iwl_trans *trans,
struct iwl_tfh_tfd *tfd)
{
return le16_to_cpu(tfd->num_tbs) & 0x1f;
}
static void iwl_pcie_gen2_tfd_unmap(struct iwl_trans *trans,
struct iwl_cmd_meta *meta,
struct iwl_tfh_tfd *tfd)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int i, num_tbs;
num_tbs = iwl_pcie_gen2_get_num_tbs(trans, tfd);
if (num_tbs >= trans_pcie->max_tbs) {
IWL_ERR(trans, "Too many chunks: %i\n", num_tbs);
return;
}
for (i = 1; i < num_tbs; i++) {
if (meta->tbs & BIT(i))
dma_unmap_page(trans->dev,
le64_to_cpu(tfd->tbs[i].addr),
le16_to_cpu(tfd->tbs[i].tb_len),
DMA_TO_DEVICE);
else
dma_unmap_single(trans->dev,
le64_to_cpu(tfd->tbs[i].addr),
le16_to_cpu(tfd->tbs[i].tb_len),
DMA_TO_DEVICE);
}
tfd->num_tbs = 0;
}
static void iwl_pcie_gen2_free_tfd(struct iwl_trans *trans, struct iwl_txq *txq)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int rd_ptr = txq->read_ptr;
int idx = get_cmd_index(txq, rd_ptr);
lockdep_assert_held(&txq->lock);
iwl_pcie_gen2_tfd_unmap(trans, &txq->entries[idx].meta,
iwl_pcie_get_tfd(trans_pcie, txq, rd_ptr));
if (txq->entries) {
struct sk_buff *skb;
skb = txq->entries[idx].skb;
if (skb) {
iwl_op_mode_free_skb(trans->op_mode, skb);
txq->entries[idx].skb = NULL;
}
}
}
static int iwl_pcie_gen2_set_tb(struct iwl_trans *trans,
struct iwl_tfh_tfd *tfd, dma_addr_t addr,
u16 len)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int idx = iwl_pcie_gen2_get_num_tbs(trans, tfd);
struct iwl_tfh_tb *tb = &tfd->tbs[idx];
if (le16_to_cpu(tfd->num_tbs) >= trans_pcie->max_tbs) {
IWL_ERR(trans, "Error can not send more than %d chunks\n",
trans_pcie->max_tbs);
return -EINVAL;
}
put_unaligned_le64(addr, &tb->addr);
tb->tb_len = cpu_to_le16(len);
tfd->num_tbs = cpu_to_le16(idx + 1);
return idx;
}
static int iwl_pcie_gen2_build_amsdu(struct iwl_trans *trans,
struct sk_buff *skb,
struct iwl_tfh_tfd *tfd, int start_len,
u8 hdr_len, struct iwl_device_cmd *dev_cmd)
{
#ifdef CONFIG_INET
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_tx_cmd *tx_cmd = (void *)dev_cmd->payload;
struct ieee80211_hdr *hdr = (void *)skb->data;
unsigned int snap_ip_tcp_hdrlen, ip_hdrlen, total_len, hdr_room;
unsigned int mss = skb_shinfo(skb)->gso_size;
u16 length, iv_len, amsdu_pad;
u8 *start_hdr;
struct iwl_tso_hdr_page *hdr_page;
struct page **page_ptr;
struct tso_t tso;
iv_len = ieee80211_has_protected(hdr->frame_control) ?
IEEE80211_CCMP_HDR_LEN : 0;
trace_iwlwifi_dev_tx(trans->dev, skb, tfd, sizeof(*tfd),
&dev_cmd->hdr, start_len, 0);
ip_hdrlen = skb_transport_header(skb) - skb_network_header(skb);
snap_ip_tcp_hdrlen = 8 + ip_hdrlen + tcp_hdrlen(skb);
total_len = skb->len - snap_ip_tcp_hdrlen - hdr_len - iv_len;
amsdu_pad = 0;
hdr_room = DIV_ROUND_UP(total_len, mss) *
(3 + snap_ip_tcp_hdrlen + sizeof(struct ethhdr)) + iv_len;
hdr_page = get_page_hdr(trans, hdr_room);
if (!hdr_page)
return -ENOMEM;
get_page(hdr_page->page);
start_hdr = hdr_page->pos;
page_ptr = (void *)((u8 *)skb->cb + trans_pcie->page_offs);
*page_ptr = hdr_page->page;
memcpy(hdr_page->pos, skb->data + hdr_len, iv_len);
hdr_page->pos += iv_len;
skb_pull(skb, hdr_len + iv_len);
le16_add_cpu(&tx_cmd->len, -snap_ip_tcp_hdrlen);
tso_start(skb, &tso);
while (total_len) {
unsigned int data_left = min_t(unsigned int, mss, total_len);
struct sk_buff *csum_skb = NULL;
unsigned int tb_len;
dma_addr_t tb_phys;
struct tcphdr *tcph;
u8 *iph, *subf_hdrs_start = hdr_page->pos;
total_len -= data_left;
memset(hdr_page->pos, 0, amsdu_pad);
hdr_page->pos += amsdu_pad;
amsdu_pad = (4 - (sizeof(struct ethhdr) + snap_ip_tcp_hdrlen +
data_left)) & 0x3;
ether_addr_copy(hdr_page->pos, ieee80211_get_DA(hdr));
hdr_page->pos += ETH_ALEN;
ether_addr_copy(hdr_page->pos, ieee80211_get_SA(hdr));
hdr_page->pos += ETH_ALEN;
length = snap_ip_tcp_hdrlen + data_left;
*((__be16 *)hdr_page->pos) = cpu_to_be16(length);
hdr_page->pos += sizeof(length);
tso_build_hdr(skb, hdr_page->pos, &tso, data_left, !total_len);
iph = hdr_page->pos + 8;
tcph = (void *)(iph + ip_hdrlen);
hdr_page->pos += snap_ip_tcp_hdrlen;
tb_len = hdr_page->pos - start_hdr;
tb_phys = dma_map_single(trans->dev, start_hdr,
tb_len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(trans->dev, tb_phys))) {
dev_kfree_skb(csum_skb);
goto out_err;
}
iwl_pcie_gen2_set_tb(trans, tfd, tb_phys, tb_len);
trace_iwlwifi_dev_tx_tso_chunk(trans->dev, start_hdr, tb_len);
le16_add_cpu(&tx_cmd->len, hdr_page->pos - subf_hdrs_start);
start_hdr = hdr_page->pos;
while (data_left) {
tb_len = min_t(unsigned int, tso.size, data_left);
tb_phys = dma_map_single(trans->dev, tso.data,
tb_len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(trans->dev, tb_phys))) {
dev_kfree_skb(csum_skb);
goto out_err;
}
iwl_pcie_gen2_set_tb(trans, tfd, tb_phys, tb_len);
trace_iwlwifi_dev_tx_tso_chunk(trans->dev, tso.data,
tb_len);
data_left -= tb_len;
tso_build_data(skb, &tso, tb_len);
}
}
skb_push(skb, hdr_len + iv_len);
return 0;
out_err:
#endif
return -EINVAL;
}
static
struct iwl_tfh_tfd *iwl_pcie_gen2_build_tfd(struct iwl_trans *trans,
struct iwl_txq *txq,
struct iwl_device_cmd *dev_cmd,
struct sk_buff *skb,
struct iwl_cmd_meta *out_meta)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct iwl_tfh_tfd *tfd =
iwl_pcie_get_tfd(trans_pcie, txq, txq->write_ptr);
dma_addr_t tb_phys;
bool amsdu;
int i, len, tb1_len, tb2_len, hdr_len;
void *tb1_addr;
memset(tfd, 0, sizeof(*tfd));
amsdu = ieee80211_is_data_qos(hdr->frame_control) &&
(*ieee80211_get_qos_ctl(hdr) &
IEEE80211_QOS_CTL_A_MSDU_PRESENT);
tb_phys = iwl_pcie_get_first_tb_dma(txq, txq->write_ptr);
if (!amsdu)
memcpy(&txq->first_tb_bufs[txq->write_ptr], &dev_cmd->hdr,
IWL_FIRST_TB_SIZE);
iwl_pcie_gen2_set_tb(trans, tfd, tb_phys, IWL_FIRST_TB_SIZE);
BUILD_BUG_ON(sizeof(struct iwl_tx_cmd_gen2) < IWL_FIRST_TB_SIZE);
len = sizeof(struct iwl_tx_cmd_gen2) + sizeof(struct iwl_cmd_header) +
ieee80211_hdrlen(hdr->frame_control) - IWL_FIRST_TB_SIZE;
if (amsdu)
tb1_len = len;
else
tb1_len = ALIGN(len, 4);
tb1_addr = ((u8 *)&dev_cmd->hdr) + IWL_FIRST_TB_SIZE;
tb_phys = dma_map_single(trans->dev, tb1_addr, tb1_len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(trans->dev, tb_phys)))
goto out_err;
iwl_pcie_gen2_set_tb(trans, tfd, tb_phys, tb1_len);
hdr_len = ieee80211_hdrlen(hdr->frame_control);
if (amsdu) {
if (!iwl_pcie_gen2_build_amsdu(trans, skb, tfd,
tb1_len + IWL_FIRST_TB_SIZE,
hdr_len, dev_cmd))
goto out_err;
memcpy(&txq->first_tb_bufs[txq->write_ptr], &dev_cmd->hdr,
IWL_FIRST_TB_SIZE);
return tfd;
}
tb2_len = skb_headlen(skb) - hdr_len;
if (tb2_len > 0) {
tb_phys = dma_map_single(trans->dev, skb->data + hdr_len,
tb2_len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(trans->dev, tb_phys)))
goto out_err;
iwl_pcie_gen2_set_tb(trans, tfd, tb_phys, tb2_len);
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
int tb_idx;
if (!skb_frag_size(frag))
continue;
tb_phys = skb_frag_dma_map(trans->dev, frag, 0,
skb_frag_size(frag), DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(trans->dev, tb_phys)))
goto out_err;
tb_idx = iwl_pcie_gen2_set_tb(trans, tfd, tb_phys,
skb_frag_size(frag));
out_meta->tbs |= BIT(tb_idx);
}
trace_iwlwifi_dev_tx(trans->dev, skb, tfd, sizeof(*tfd), &dev_cmd->hdr,
IWL_FIRST_TB_SIZE + tb1_len, hdr_len);
trace_iwlwifi_dev_tx_data(trans->dev, skb, hdr_len);
return tfd;
out_err:
iwl_pcie_gen2_tfd_unmap(trans, out_meta, tfd);
return NULL;
}
int iwl_trans_pcie_gen2_tx(struct iwl_trans *trans, struct sk_buff *skb,
struct iwl_device_cmd *dev_cmd, int txq_id)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_tx_cmd_gen2 *tx_cmd = (void *)dev_cmd->payload;
struct iwl_cmd_meta *out_meta;
struct iwl_txq *txq = trans_pcie->txq[txq_id];
void *tfd;
if (WARN_ONCE(!test_bit(txq_id, trans_pcie->queue_used),
"TX on unused queue %d\n", txq_id))
return -EINVAL;
if (skb_is_nonlinear(skb) &&
skb_shinfo(skb)->nr_frags > IWL_PCIE_MAX_FRAGS(trans_pcie) &&
__skb_linearize(skb))
return -ENOMEM;
spin_lock(&txq->lock);
txq->entries[txq->write_ptr].skb = skb;
txq->entries[txq->write_ptr].cmd = dev_cmd;
dev_cmd->hdr.sequence =
cpu_to_le16((u16)(QUEUE_TO_SEQ(txq_id) |
INDEX_TO_SEQ(txq->write_ptr)));
out_meta = &txq->entries[txq->write_ptr].meta;
out_meta->flags = 0;
tfd = iwl_pcie_gen2_build_tfd(trans, txq, dev_cmd, skb, out_meta);
if (!tfd) {
spin_unlock(&txq->lock);
return -1;
}
iwl_pcie_gen2_update_byte_tbl(txq, le16_to_cpu(tx_cmd->len),
iwl_pcie_gen2_get_num_tbs(trans, tfd));
if (txq->read_ptr == txq->write_ptr) {
if (txq->wd_timeout)
mod_timer(&txq->stuck_timer, jiffies + txq->wd_timeout);
IWL_DEBUG_RPM(trans, "Q: %d first tx - take ref\n", txq->id);
iwl_trans_ref(trans);
}
txq->write_ptr = iwl_queue_inc_wrap(txq->write_ptr);
iwl_pcie_gen2_txq_inc_wr_ptr(trans, txq);
if (iwl_queue_space(txq) < txq->high_mark)
iwl_stop_queue(trans, txq);
spin_unlock(&txq->lock);
return 0;
}
static int iwl_pcie_gen2_enqueue_hcmd(struct iwl_trans *trans,
struct iwl_host_cmd *cmd)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_txq *txq = trans_pcie->txq[trans_pcie->cmd_queue];
struct iwl_device_cmd *out_cmd;
struct iwl_cmd_meta *out_meta;
unsigned long flags;
void *dup_buf = NULL;
dma_addr_t phys_addr;
int idx, i, cmd_pos;
u16 copy_size, cmd_size, tb0_size;
bool had_nocopy = false;
u8 group_id = iwl_cmd_groupid(cmd->id);
const u8 *cmddata[IWL_MAX_CMD_TBS_PER_TFD];
u16 cmdlen[IWL_MAX_CMD_TBS_PER_TFD];
struct iwl_tfh_tfd *tfd =
iwl_pcie_get_tfd(trans_pcie, txq, txq->write_ptr);
memset(tfd, 0, sizeof(*tfd));
copy_size = sizeof(struct iwl_cmd_header_wide);
cmd_size = sizeof(struct iwl_cmd_header_wide);
for (i = 0; i < IWL_MAX_CMD_TBS_PER_TFD; i++) {
cmddata[i] = cmd->data[i];
cmdlen[i] = cmd->len[i];
if (!cmd->len[i])
continue;
if (copy_size < IWL_FIRST_TB_SIZE) {
int copy = IWL_FIRST_TB_SIZE - copy_size;
if (copy > cmdlen[i])
copy = cmdlen[i];
cmdlen[i] -= copy;
cmddata[i] += copy;
copy_size += copy;
}
if (cmd->dataflags[i] & IWL_HCMD_DFL_NOCOPY) {
had_nocopy = true;
if (WARN_ON(cmd->dataflags[i] & IWL_HCMD_DFL_DUP)) {
idx = -EINVAL;
goto free_dup_buf;
}
} else if (cmd->dataflags[i] & IWL_HCMD_DFL_DUP) {
had_nocopy = true;
if (WARN_ON(dup_buf)) {
idx = -EINVAL;
goto free_dup_buf;
}
dup_buf = kmemdup(cmddata[i], cmdlen[i],
GFP_ATOMIC);
if (!dup_buf)
return -ENOMEM;
} else {
if (WARN_ON(had_nocopy)) {
idx = -EINVAL;
goto free_dup_buf;
}
copy_size += cmdlen[i];
}
cmd_size += cmd->len[i];
}
if (WARN(copy_size > TFD_MAX_PAYLOAD_SIZE,
"Command %s (%#x) is too large (%d bytes)\n",
iwl_get_cmd_string(trans, cmd->id), cmd->id, copy_size)) {
idx = -EINVAL;
goto free_dup_buf;
}
spin_lock_bh(&txq->lock);
if (iwl_queue_space(txq) < ((cmd->flags & CMD_ASYNC) ? 2 : 1)) {
spin_unlock_bh(&txq->lock);
IWL_ERR(trans, "No space in command queue\n");
iwl_op_mode_cmd_queue_full(trans->op_mode);
idx = -ENOSPC;
goto free_dup_buf;
}
idx = get_cmd_index(txq, txq->write_ptr);
out_cmd = txq->entries[idx].cmd;
out_meta = &txq->entries[idx].meta;
memset(out_meta, 0, sizeof(*out_meta));
if (cmd->flags & CMD_WANT_SKB)
out_meta->source = cmd;
out_cmd->hdr_wide.cmd = iwl_cmd_opcode(cmd->id);
out_cmd->hdr_wide.group_id = group_id;
out_cmd->hdr_wide.version = iwl_cmd_version(cmd->id);
out_cmd->hdr_wide.length =
cpu_to_le16(cmd_size - sizeof(struct iwl_cmd_header_wide));
out_cmd->hdr_wide.reserved = 0;
out_cmd->hdr_wide.sequence =
cpu_to_le16(QUEUE_TO_SEQ(trans_pcie->cmd_queue) |
INDEX_TO_SEQ(txq->write_ptr));
cmd_pos = sizeof(struct iwl_cmd_header_wide);
copy_size = sizeof(struct iwl_cmd_header_wide);
for (i = 0; i < IWL_MAX_CMD_TBS_PER_TFD; i++) {
int copy;
if (!cmd->len[i])
continue;
if (!(cmd->dataflags[i] & (IWL_HCMD_DFL_NOCOPY |
IWL_HCMD_DFL_DUP))) {
copy = cmd->len[i];
memcpy((u8 *)out_cmd + cmd_pos, cmd->data[i], copy);
cmd_pos += copy;
copy_size += copy;
continue;
}
copy = min_t(int, TFD_MAX_PAYLOAD_SIZE - cmd_pos, cmd->len[i]);
memcpy((u8 *)out_cmd + cmd_pos, cmd->data[i], copy);
cmd_pos += copy;
if (copy_size < IWL_FIRST_TB_SIZE) {
copy = IWL_FIRST_TB_SIZE - copy_size;
if (copy > cmd->len[i])
copy = cmd->len[i];
copy_size += copy;
}
}
IWL_DEBUG_HC(trans,
"Sending command %s (%.2x.%.2x), seq: 0x%04X, %d bytes at %d[%d]:%d\n",
iwl_get_cmd_string(trans, cmd->id), group_id,
out_cmd->hdr.cmd, le16_to_cpu(out_cmd->hdr.sequence),
cmd_size, txq->write_ptr, idx, trans_pcie->cmd_queue);
tb0_size = min_t(int, copy_size, IWL_FIRST_TB_SIZE);
memcpy(&txq->first_tb_bufs[idx], &out_cmd->hdr, tb0_size);
iwl_pcie_gen2_set_tb(trans, tfd, iwl_pcie_get_first_tb_dma(txq, idx),
tb0_size);
if (copy_size > tb0_size) {
phys_addr = dma_map_single(trans->dev,
((u8 *)&out_cmd->hdr) + tb0_size,
copy_size - tb0_size,
DMA_TO_DEVICE);
if (dma_mapping_error(trans->dev, phys_addr)) {
idx = -ENOMEM;
iwl_pcie_gen2_tfd_unmap(trans, out_meta, tfd);
goto out;
}
iwl_pcie_gen2_set_tb(trans, tfd, phys_addr,
copy_size - tb0_size);
}
for (i = 0; i < IWL_MAX_CMD_TBS_PER_TFD; i++) {
const void *data = cmddata[i];
if (!cmdlen[i])
continue;
if (!(cmd->dataflags[i] & (IWL_HCMD_DFL_NOCOPY |
IWL_HCMD_DFL_DUP)))
continue;
if (cmd->dataflags[i] & IWL_HCMD_DFL_DUP)
data = dup_buf;
phys_addr = dma_map_single(trans->dev, (void *)data,
cmdlen[i], DMA_TO_DEVICE);
if (dma_mapping_error(trans->dev, phys_addr)) {
idx = -ENOMEM;
iwl_pcie_gen2_tfd_unmap(trans, out_meta, tfd);
goto out;
}
iwl_pcie_gen2_set_tb(trans, tfd, phys_addr, cmdlen[i]);
}
BUILD_BUG_ON(IWL_TFH_NUM_TBS > sizeof(out_meta->tbs) * BITS_PER_BYTE);
out_meta->flags = cmd->flags;
if (WARN_ON_ONCE(txq->entries[idx].free_buf))
kzfree(txq->entries[idx].free_buf);
txq->entries[idx].free_buf = dup_buf;
trace_iwlwifi_dev_hcmd(trans->dev, cmd, cmd_size, &out_cmd->hdr_wide);
if (txq->read_ptr == txq->write_ptr && txq->wd_timeout)
mod_timer(&txq->stuck_timer, jiffies + txq->wd_timeout);
spin_lock_irqsave(&trans_pcie->reg_lock, flags);
if (!(cmd->flags & CMD_SEND_IN_IDLE) &&
!trans_pcie->ref_cmd_in_flight) {
trans_pcie->ref_cmd_in_flight = true;
IWL_DEBUG_RPM(trans, "set ref_cmd_in_flight - ref\n");
iwl_trans_ref(trans);
}
txq->write_ptr = iwl_queue_inc_wrap(txq->write_ptr);
iwl_pcie_gen2_txq_inc_wr_ptr(trans, txq);
spin_unlock_irqrestore(&trans_pcie->reg_lock, flags);
out:
spin_unlock_bh(&txq->lock);
free_dup_buf:
if (idx < 0)
kfree(dup_buf);
return idx;
}
static int iwl_pcie_gen2_send_hcmd_sync(struct iwl_trans *trans,
struct iwl_host_cmd *cmd)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
const char *cmd_str = iwl_get_cmd_string(trans, cmd->id);
struct iwl_txq *txq = trans_pcie->txq[trans_pcie->cmd_queue];
int cmd_idx;
int ret;
IWL_DEBUG_INFO(trans, "Attempting to send sync command %s\n", cmd_str);
if (WARN(test_and_set_bit(STATUS_SYNC_HCMD_ACTIVE,
&trans->status),
"Command %s: a command is already active!\n", cmd_str))
return -EIO;
IWL_DEBUG_INFO(trans, "Setting HCMD_ACTIVE for command %s\n", cmd_str);
if (pm_runtime_suspended(&trans_pcie->pci_dev->dev)) {
ret = wait_event_timeout(trans_pcie->d0i3_waitq,
pm_runtime_active(&trans_pcie->pci_dev->dev),
msecs_to_jiffies(IWL_TRANS_IDLE_TIMEOUT));
if (!ret) {
IWL_ERR(trans, "Timeout exiting D0i3 before hcmd\n");
return -ETIMEDOUT;
}
}
cmd_idx = iwl_pcie_gen2_enqueue_hcmd(trans, cmd);
if (cmd_idx < 0) {
ret = cmd_idx;
clear_bit(STATUS_SYNC_HCMD_ACTIVE, &trans->status);
IWL_ERR(trans, "Error sending %s: enqueue_hcmd failed: %d\n",
cmd_str, ret);
return ret;
}
ret = wait_event_timeout(trans_pcie->wait_command_queue,
!test_bit(STATUS_SYNC_HCMD_ACTIVE,
&trans->status),
HOST_COMPLETE_TIMEOUT);
if (!ret) {
IWL_ERR(trans, "Error sending %s: time out after %dms.\n",
cmd_str, jiffies_to_msecs(HOST_COMPLETE_TIMEOUT));
IWL_ERR(trans, "Current CMD queue read_ptr %d write_ptr %d\n",
txq->read_ptr, txq->write_ptr);
clear_bit(STATUS_SYNC_HCMD_ACTIVE, &trans->status);
IWL_DEBUG_INFO(trans, "Clearing HCMD_ACTIVE for command %s\n",
cmd_str);
ret = -ETIMEDOUT;
iwl_force_nmi(trans);
iwl_trans_fw_error(trans);
goto cancel;
}
if (test_bit(STATUS_FW_ERROR, &trans->status)) {
IWL_ERR(trans, "FW error in SYNC CMD %s\n", cmd_str);
dump_stack();
ret = -EIO;
goto cancel;
}
if (!(cmd->flags & CMD_SEND_IN_RFKILL) &&
test_bit(STATUS_RFKILL_OPMODE, &trans->status)) {
IWL_DEBUG_RF_KILL(trans, "RFKILL in SYNC CMD... no rsp\n");
ret = -ERFKILL;
goto cancel;
}
if ((cmd->flags & CMD_WANT_SKB) && !cmd->resp_pkt) {
IWL_ERR(trans, "Error: Response NULL in '%s'\n", cmd_str);
ret = -EIO;
goto cancel;
}
return 0;
cancel:
if (cmd->flags & CMD_WANT_SKB) {
txq->entries[cmd_idx].meta.flags &= ~CMD_WANT_SKB;
}
if (cmd->resp_pkt) {
iwl_free_resp(cmd);
cmd->resp_pkt = NULL;
}
return ret;
}
int iwl_trans_pcie_gen2_send_hcmd(struct iwl_trans *trans,
struct iwl_host_cmd *cmd)
{
if (!(cmd->flags & CMD_SEND_IN_RFKILL) &&
test_bit(STATUS_RFKILL_OPMODE, &trans->status)) {
IWL_DEBUG_RF_KILL(trans, "Dropping CMD 0x%x: RF KILL\n",
cmd->id);
return -ERFKILL;
}
if (cmd->flags & CMD_ASYNC) {
int ret;
if (WARN_ON(cmd->flags & CMD_WANT_SKB))
return -EINVAL;
ret = iwl_pcie_gen2_enqueue_hcmd(trans, cmd);
if (ret < 0) {
IWL_ERR(trans,
"Error sending %s: enqueue_hcmd failed: %d\n",
iwl_get_cmd_string(trans, cmd->id), ret);
return ret;
}
return 0;
}
return iwl_pcie_gen2_send_hcmd_sync(trans, cmd);
}
void iwl_pcie_gen2_txq_unmap(struct iwl_trans *trans, int txq_id)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_txq *txq = trans_pcie->txq[txq_id];
spin_lock_bh(&txq->lock);
while (txq->write_ptr != txq->read_ptr) {
IWL_DEBUG_TX_REPLY(trans, "Q %d Free %d\n",
txq_id, txq->read_ptr);
iwl_pcie_gen2_free_tfd(trans, txq);
txq->read_ptr = iwl_queue_inc_wrap(txq->read_ptr);
if (txq->read_ptr == txq->write_ptr) {
unsigned long flags;
spin_lock_irqsave(&trans_pcie->reg_lock, flags);
if (txq_id != trans_pcie->cmd_queue) {
IWL_DEBUG_RPM(trans, "Q %d - last tx freed\n",
txq->id);
iwl_trans_unref(trans);
} else if (trans_pcie->ref_cmd_in_flight) {
trans_pcie->ref_cmd_in_flight = false;
IWL_DEBUG_RPM(trans,
"clear ref_cmd_in_flight\n");
iwl_trans_unref(trans);
}
spin_unlock_irqrestore(&trans_pcie->reg_lock, flags);
}
}
spin_unlock_bh(&txq->lock);
iwl_wake_queue(trans, txq);
}
static void iwl_pcie_gen2_txq_free_memory(struct iwl_trans *trans,
struct iwl_txq *txq)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct device *dev = trans->dev;
if (txq->tfds) {
dma_free_coherent(dev,
trans_pcie->tfd_size * TFD_QUEUE_SIZE_MAX,
txq->tfds, txq->dma_addr);
dma_free_coherent(dev,
sizeof(*txq->first_tb_bufs) * txq->n_window,
txq->first_tb_bufs, txq->first_tb_dma);
}
kfree(txq->entries);
iwl_pcie_free_dma_ptr(trans, &txq->bc_tbl);
kfree(txq);
}
static void iwl_pcie_gen2_txq_free(struct iwl_trans *trans, int txq_id)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_txq *txq = trans_pcie->txq[txq_id];
int i;
if (WARN_ON(!txq))
return;
iwl_pcie_gen2_txq_unmap(trans, txq_id);
if (txq_id == trans_pcie->cmd_queue)
for (i = 0; i < txq->n_window; i++) {
kzfree(txq->entries[i].cmd);
kzfree(txq->entries[i].free_buf);
}
del_timer_sync(&txq->stuck_timer);
iwl_pcie_gen2_txq_free_memory(trans, txq);
trans_pcie->txq[txq_id] = NULL;
clear_bit(txq_id, trans_pcie->queue_used);
}
int iwl_trans_pcie_dyn_txq_alloc(struct iwl_trans *trans,
struct iwl_tx_queue_cfg_cmd *cmd,
int cmd_id,
unsigned int timeout)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_tx_queue_cfg_rsp *rsp;
struct iwl_txq *txq;
struct iwl_host_cmd hcmd = {
.id = cmd_id,
.len = { sizeof(*cmd) },
.data = { cmd, },
.flags = CMD_WANT_SKB,
};
int ret, qid;
txq = kzalloc(sizeof(*txq), GFP_KERNEL);
if (!txq)
return -ENOMEM;
ret = iwl_pcie_alloc_dma_ptr(trans, &txq->bc_tbl,
sizeof(struct iwlagn_scd_bc_tbl));
if (ret) {
IWL_ERR(trans, "Scheduler BC Table allocation failed\n");
kfree(txq);
return -ENOMEM;
}
ret = iwl_pcie_txq_alloc(trans, txq, TFD_TX_CMD_SLOTS, false);
if (ret) {
IWL_ERR(trans, "Tx queue alloc failed\n");
goto error;
}
ret = iwl_pcie_txq_init(trans, txq, TFD_TX_CMD_SLOTS, false);
if (ret) {
IWL_ERR(trans, "Tx queue init failed\n");
goto error;
}
txq->wd_timeout = msecs_to_jiffies(timeout);
cmd->tfdq_addr = cpu_to_le64(txq->dma_addr);
cmd->byte_cnt_addr = cpu_to_le64(txq->bc_tbl.dma);
cmd->cb_size = cpu_to_le32(TFD_QUEUE_CB_SIZE(TFD_QUEUE_SIZE_MAX));
ret = iwl_trans_send_cmd(trans, &hcmd);
if (ret)
goto error;
if (WARN_ON(iwl_rx_packet_payload_len(hcmd.resp_pkt) != sizeof(*rsp))) {
ret = -EINVAL;
goto error_free_resp;
}
rsp = (void *)hcmd.resp_pkt->data;
qid = le16_to_cpu(rsp->queue_number);
if (qid >= ARRAY_SIZE(trans_pcie->txq)) {
WARN_ONCE(1, "queue index %d unsupported", qid);
ret = -EIO;
goto error_free_resp;
}
if (test_and_set_bit(qid, trans_pcie->queue_used)) {
WARN_ONCE(1, "queue %d already used", qid);
ret = -EIO;
goto error_free_resp;
}
txq->id = qid;
trans_pcie->txq[qid] = txq;
txq->read_ptr = le16_to_cpu(rsp->write_pointer);
txq->write_ptr = le16_to_cpu(rsp->write_pointer);
iwl_write_direct32(trans, HBUS_TARG_WRPTR,
(txq->write_ptr) | (qid << 16));
IWL_DEBUG_TX_QUEUES(trans, "Activate queue %d\n", qid);
iwl_free_resp(&hcmd);
return qid;
error_free_resp:
iwl_free_resp(&hcmd);
error:
iwl_pcie_gen2_txq_free_memory(trans, txq);
return ret;
}
void iwl_trans_pcie_dyn_txq_free(struct iwl_trans *trans, int queue)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
if (!test_and_clear_bit(queue, trans_pcie->queue_used)) {
WARN_ONCE(test_bit(STATUS_DEVICE_ENABLED, &trans->status),
"queue %d not used", queue);
return;
}
iwl_pcie_gen2_txq_unmap(trans, queue);
IWL_DEBUG_TX_QUEUES(trans, "Deactivate queue %d\n", queue);
}
void iwl_pcie_gen2_tx_free(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
int i;
memset(trans_pcie->queue_used, 0, sizeof(trans_pcie->queue_used));
for (i = 0; i < ARRAY_SIZE(trans_pcie->txq); i++) {
if (!trans_pcie->txq[i])
continue;
iwl_pcie_gen2_txq_free(trans, i);
}
}
int iwl_pcie_gen2_tx_init(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
struct iwl_txq *cmd_queue;
int txq_id = trans_pcie->cmd_queue, ret;
if (!trans_pcie->txq[txq_id]) {
cmd_queue = kzalloc(sizeof(*cmd_queue), GFP_KERNEL);
if (!cmd_queue) {
IWL_ERR(trans, "Not enough memory for command queue\n");
return -ENOMEM;
}
trans_pcie->txq[txq_id] = cmd_queue;
ret = iwl_pcie_txq_alloc(trans, cmd_queue, TFD_CMD_SLOTS, true);
if (ret) {
IWL_ERR(trans, "Tx %d queue init failed\n", txq_id);
goto error;
}
} else {
cmd_queue = trans_pcie->txq[txq_id];
}
ret = iwl_pcie_txq_init(trans, cmd_queue, TFD_CMD_SLOTS, true);
if (ret) {
IWL_ERR(trans, "Tx %d queue alloc failed\n", txq_id);
goto error;
}
trans_pcie->txq[txq_id]->id = txq_id;
set_bit(txq_id, trans_pcie->queue_used);
return 0;
error:
iwl_pcie_gen2_tx_free(trans);
return ret;
}
