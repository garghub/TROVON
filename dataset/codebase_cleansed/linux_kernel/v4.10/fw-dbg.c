static void iwl_mvm_read_radio_reg(struct iwl_mvm *mvm,
struct iwl_fw_error_dump_data **dump_data)
{
u8 *pos = (void *)(*dump_data)->data;
unsigned long flags;
int i;
if (!iwl_trans_grab_nic_access(mvm->trans, &flags))
return;
(*dump_data)->type = cpu_to_le32(IWL_FW_ERROR_DUMP_RADIO_REG);
(*dump_data)->len = cpu_to_le32(RADIO_REG_MAX_READ);
for (i = 0; i < RADIO_REG_MAX_READ; i++) {
u32 rd_cmd = RADIO_RSP_RD_CMD;
rd_cmd |= i << RADIO_RSP_ADDR_POS;
iwl_write_prph_no_grab(mvm->trans, RSP_RADIO_CMD, rd_cmd);
*pos = (u8)iwl_read_prph_no_grab(mvm->trans, RSP_RADIO_RDDAT);
pos++;
}
*dump_data = iwl_fw_error_next_data(*dump_data);
iwl_trans_release_nic_access(mvm->trans, &flags);
}
static void iwl_mvm_dump_fifos(struct iwl_mvm *mvm,
struct iwl_fw_error_dump_data **dump_data)
{
struct iwl_fw_error_dump_fifo *fifo_hdr;
u32 *fifo_data;
u32 fifo_len;
unsigned long flags;
int i, j;
if (!iwl_trans_grab_nic_access(mvm->trans, &flags))
return;
for (i = 0; i < ARRAY_SIZE(mvm->shared_mem_cfg.rxfifo_size); i++) {
u32 offset_diff = RXF_DIFF_FROM_PREV * i;
fifo_hdr = (void *)(*dump_data)->data;
fifo_data = (void *)fifo_hdr->data;
fifo_len = mvm->shared_mem_cfg.rxfifo_size[i];
if (fifo_len == 0)
continue;
(*dump_data)->type = cpu_to_le32(IWL_FW_ERROR_DUMP_RXF);
(*dump_data)->len = cpu_to_le32(fifo_len + sizeof(*fifo_hdr));
fifo_hdr->fifo_num = cpu_to_le32(i);
fifo_hdr->available_bytes =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
RXF_RD_D_SPACE +
offset_diff));
fifo_hdr->wr_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
RXF_RD_WR_PTR +
offset_diff));
fifo_hdr->rd_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
RXF_RD_RD_PTR +
offset_diff));
fifo_hdr->fence_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
RXF_RD_FENCE_PTR +
offset_diff));
fifo_hdr->fence_mode =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
RXF_SET_FENCE_MODE +
offset_diff));
iwl_trans_write_prph(mvm->trans,
RXF_SET_FENCE_MODE + offset_diff, 0x1);
iwl_trans_write_prph(mvm->trans,
RXF_LD_WR2FENCE + offset_diff, 0x1);
iwl_trans_write_prph(mvm->trans,
RXF_LD_FENCE_OFFSET_ADDR + offset_diff,
0x0);
fifo_len /= sizeof(u32);
for (j = 0; j < fifo_len; j++)
fifo_data[j] = iwl_trans_read_prph(mvm->trans,
RXF_FIFO_RD_FENCE_INC +
offset_diff);
*dump_data = iwl_fw_error_next_data(*dump_data);
}
for (i = 0; i < ARRAY_SIZE(mvm->shared_mem_cfg.txfifo_size); i++) {
iwl_trans_write_prph(mvm->trans, TXF_LARC_NUM, i);
fifo_hdr = (void *)(*dump_data)->data;
fifo_data = (void *)fifo_hdr->data;
fifo_len = mvm->shared_mem_cfg.txfifo_size[i];
if (fifo_len == 0)
continue;
(*dump_data)->type = cpu_to_le32(IWL_FW_ERROR_DUMP_TXF);
(*dump_data)->len = cpu_to_le32(fifo_len + sizeof(*fifo_hdr));
fifo_hdr->fifo_num = cpu_to_le32(i);
fifo_hdr->available_bytes =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_FIFO_ITEM_CNT));
fifo_hdr->wr_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_WR_PTR));
fifo_hdr->rd_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_RD_PTR));
fifo_hdr->fence_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_FENCE_PTR));
fifo_hdr->fence_mode =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_LOCK_FENCE));
iwl_trans_write_prph(mvm->trans, TXF_READ_MODIFY_ADDR,
TXF_WR_PTR);
iwl_trans_read_prph(mvm->trans, TXF_READ_MODIFY_DATA);
fifo_len /= sizeof(u32);
for (j = 0; j < fifo_len; j++)
fifo_data[j] = iwl_trans_read_prph(mvm->trans,
TXF_READ_MODIFY_DATA);
*dump_data = iwl_fw_error_next_data(*dump_data);
}
if (fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_EXTEND_SHARED_MEM_CFG)) {
for (i = 0;
i < ARRAY_SIZE(mvm->shared_mem_cfg.internal_txfifo_size);
i++) {
fifo_hdr = (void *)(*dump_data)->data;
fifo_data = (void *)fifo_hdr->data;
fifo_len = mvm->shared_mem_cfg.internal_txfifo_size[i];
if (fifo_len == 0)
continue;
(*dump_data)->type =
cpu_to_le32(IWL_FW_ERROR_DUMP_INTERNAL_TXF);
(*dump_data)->len =
cpu_to_le32(fifo_len + sizeof(*fifo_hdr));
fifo_hdr->fifo_num = cpu_to_le32(i);
iwl_trans_write_prph(mvm->trans, TXF_CPU2_NUM, i +
ARRAY_SIZE(mvm->shared_mem_cfg.txfifo_size));
fifo_hdr->available_bytes =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_CPU2_FIFO_ITEM_CNT));
fifo_hdr->wr_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_CPU2_WR_PTR));
fifo_hdr->rd_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_CPU2_RD_PTR));
fifo_hdr->fence_ptr =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_CPU2_FENCE_PTR));
fifo_hdr->fence_mode =
cpu_to_le32(iwl_trans_read_prph(mvm->trans,
TXF_CPU2_LOCK_FENCE));
iwl_trans_write_prph(mvm->trans,
TXF_CPU2_READ_MODIFY_ADDR,
TXF_CPU2_WR_PTR);
iwl_trans_read_prph(mvm->trans,
TXF_CPU2_READ_MODIFY_DATA);
fifo_len /= sizeof(u32);
for (j = 0; j < fifo_len; j++)
fifo_data[j] =
iwl_trans_read_prph(mvm->trans,
TXF_CPU2_READ_MODIFY_DATA);
*dump_data = iwl_fw_error_next_data(*dump_data);
}
}
iwl_trans_release_nic_access(mvm->trans, &flags);
}
void iwl_mvm_free_fw_dump_desc(struct iwl_mvm *mvm)
{
if (mvm->fw_dump_desc == &iwl_mvm_dump_desc_assert)
return;
kfree(mvm->fw_dump_desc);
mvm->fw_dump_desc = NULL;
}
static u32 iwl_dump_prph(struct iwl_trans *trans,
struct iwl_fw_error_dump_data **data,
const struct iwl_prph_range *iwl_prph_dump_addr,
u32 range_len)
{
struct iwl_fw_error_dump_prph *prph;
unsigned long flags;
u32 prph_len = 0, i;
if (!iwl_trans_grab_nic_access(trans, &flags))
return 0;
for (i = 0; i < range_len; i++) {
int num_bytes_in_chunk = iwl_prph_dump_addr[i].end -
iwl_prph_dump_addr[i].start + 4;
int reg;
__le32 *val;
prph_len += sizeof(**data) + sizeof(*prph) + num_bytes_in_chunk;
(*data)->type = cpu_to_le32(IWL_FW_ERROR_DUMP_PRPH);
(*data)->len = cpu_to_le32(sizeof(*prph) +
num_bytes_in_chunk);
prph = (void *)(*data)->data;
prph->prph_start = cpu_to_le32(iwl_prph_dump_addr[i].start);
val = (void *)prph->data;
for (reg = iwl_prph_dump_addr[i].start;
reg <= iwl_prph_dump_addr[i].end;
reg += 4)
*val++ = cpu_to_le32(iwl_read_prph_no_grab(trans,
reg));
*data = iwl_fw_error_next_data(*data);
}
iwl_trans_release_nic_access(trans, &flags);
return prph_len;
}
static struct scatterlist *alloc_sgtable(int size)
{
int alloc_size, nents, i;
struct page *new_page;
struct scatterlist *iter;
struct scatterlist *table;
nents = DIV_ROUND_UP(size, PAGE_SIZE);
table = kcalloc(nents, sizeof(*table), GFP_KERNEL);
if (!table)
return NULL;
sg_init_table(table, nents);
iter = table;
for_each_sg(table, iter, sg_nents(table), i) {
new_page = alloc_page(GFP_KERNEL);
if (!new_page) {
iter = table;
for_each_sg(table, iter, sg_nents(table), i) {
new_page = sg_page(iter);
if (new_page)
__free_page(new_page);
}
return NULL;
}
alloc_size = min_t(int, size, PAGE_SIZE);
size -= PAGE_SIZE;
sg_set_page(iter, new_page, alloc_size, 0);
}
return table;
}
void iwl_mvm_fw_error_dump(struct iwl_mvm *mvm)
{
struct iwl_fw_error_dump_file *dump_file;
struct iwl_fw_error_dump_data *dump_data;
struct iwl_fw_error_dump_info *dump_info;
struct iwl_fw_error_dump_mem *dump_mem;
struct iwl_fw_error_dump_trigger_desc *dump_trig;
struct iwl_mvm_dump_ptrs *fw_error_dump;
struct scatterlist *sg_dump_data;
u32 sram_len, sram_ofs;
struct iwl_fw_dbg_mem_seg_tlv * const *fw_dbg_mem =
mvm->fw->dbg_mem_tlv;
u32 file_len, fifo_data_len = 0, prph_len = 0, radio_len = 0;
u32 smem_len = mvm->fw->dbg_dynamic_mem ? 0 : mvm->cfg->smem_len;
u32 sram2_len = mvm->fw->dbg_dynamic_mem ? 0 : mvm->cfg->dccm2_len;
bool monitor_dump_only = false;
int i;
if (!IWL_MVM_COLLECT_FW_ERR_DUMP &&
!mvm->trans->dbg_dest_tlv)
return;
lockdep_assert_held(&mvm->mutex);
if (test_bit(STATUS_TRANS_DEAD, &mvm->trans->status)) {
IWL_ERR(mvm, "Skip fw error dump since bus is dead\n");
goto out;
}
if (mvm->fw_dump_trig &&
mvm->fw_dump_trig->mode & IWL_FW_DBG_TRIGGER_MONITOR_ONLY)
monitor_dump_only = true;
fw_error_dump = kzalloc(sizeof(*fw_error_dump), GFP_KERNEL);
if (!fw_error_dump)
goto out;
if (!mvm->cfg->dccm_offset || !mvm->cfg->dccm_len) {
const struct fw_img *img;
img = &mvm->fw->img[mvm->cur_ucode];
sram_ofs = img->sec[IWL_UCODE_SECTION_DATA].offset;
sram_len = img->sec[IWL_UCODE_SECTION_DATA].len;
} else {
sram_ofs = mvm->cfg->dccm_offset;
sram_len = mvm->cfg->dccm_len;
}
if (test_bit(STATUS_FW_ERROR, &mvm->trans->status)) {
struct iwl_mvm_shared_mem_cfg *mem_cfg = &mvm->shared_mem_cfg;
fifo_data_len = 0;
for (i = 0; i < ARRAY_SIZE(mem_cfg->rxfifo_size); i++) {
if (!mem_cfg->rxfifo_size[i])
continue;
fifo_data_len += mem_cfg->rxfifo_size[i] +
sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_fifo);
}
for (i = 0; i < mem_cfg->num_txfifo_entries; i++) {
if (!mem_cfg->txfifo_size[i])
continue;
fifo_data_len += mem_cfg->txfifo_size[i] +
sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_fifo);
}
if (fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_EXTEND_SHARED_MEM_CFG)) {
for (i = 0;
i < ARRAY_SIZE(mem_cfg->internal_txfifo_size);
i++) {
if (!mem_cfg->internal_txfifo_size[i])
continue;
fifo_data_len +=
mem_cfg->internal_txfifo_size[i] +
sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_fifo);
}
}
for (i = 0; i < ARRAY_SIZE(iwl_prph_dump_addr_comm); i++) {
int num_bytes_in_chunk =
iwl_prph_dump_addr_comm[i].end -
iwl_prph_dump_addr_comm[i].start + 4;
prph_len += sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_prph) +
num_bytes_in_chunk;
}
if (mvm->cfg->mq_rx_supported) {
for (i = 0; i <
ARRAY_SIZE(iwl_prph_dump_addr_9000); i++) {
int num_bytes_in_chunk =
iwl_prph_dump_addr_9000[i].end -
iwl_prph_dump_addr_9000[i].start + 4;
prph_len += sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_prph) +
num_bytes_in_chunk;
}
}
if (mvm->cfg->device_family == IWL_DEVICE_FAMILY_7000)
radio_len = sizeof(*dump_data) + RADIO_REG_MAX_READ;
}
file_len = sizeof(*dump_file) +
sizeof(*dump_data) * 2 +
fifo_data_len +
prph_len +
radio_len +
sizeof(*dump_info);
if (smem_len)
file_len += sizeof(*dump_data) + sizeof(*dump_mem) + smem_len;
if (sram2_len)
file_len += sizeof(*dump_data) + sizeof(*dump_mem) + sram2_len;
for (i = 0; i < ARRAY_SIZE(mvm->fw->dbg_mem_tlv); i++) {
if (fw_dbg_mem[i])
file_len += sizeof(*dump_data) + sizeof(*dump_mem) +
le32_to_cpu(fw_dbg_mem[i]->len);
}
if (mvm->fw->img[mvm->cur_ucode].paging_mem_size &&
mvm->fw_paging_db[0].fw_paging_block)
file_len += mvm->num_of_paging_blk *
(sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_paging) +
PAGING_BLOCK_SIZE);
if (monitor_dump_only) {
file_len = sizeof(*dump_file) + sizeof(*dump_data) +
sizeof(*dump_info);
}
if (mvm->cfg->device_family == IWL_DEVICE_FAMILY_8000 &&
CSR_HW_REV_STEP(mvm->trans->hw_rev) == SILICON_B_STEP)
file_len += sizeof(*dump_data) + sizeof(*dump_mem) +
IWL8260_ICCM_LEN;
if (mvm->fw_dump_desc)
file_len += sizeof(*dump_data) + sizeof(*dump_trig) +
mvm->fw_dump_desc->len;
if (!mvm->fw->dbg_dynamic_mem)
file_len += sram_len + sizeof(*dump_mem);
dump_file = vzalloc(file_len);
if (!dump_file) {
kfree(fw_error_dump);
goto out;
}
fw_error_dump->op_mode_ptr = dump_file;
dump_file->barker = cpu_to_le32(IWL_FW_ERROR_DUMP_BARKER);
dump_data = (void *)dump_file->data;
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_DEV_FW_INFO);
dump_data->len = cpu_to_le32(sizeof(*dump_info));
dump_info = (void *)dump_data->data;
dump_info->device_family =
mvm->cfg->device_family == IWL_DEVICE_FAMILY_7000 ?
cpu_to_le32(IWL_FW_ERROR_DUMP_FAMILY_7) :
cpu_to_le32(IWL_FW_ERROR_DUMP_FAMILY_8);
dump_info->hw_step = cpu_to_le32(CSR_HW_REV_STEP(mvm->trans->hw_rev));
memcpy(dump_info->fw_human_readable, mvm->fw->human_readable,
sizeof(dump_info->fw_human_readable));
strncpy(dump_info->dev_human_readable, mvm->cfg->name,
sizeof(dump_info->dev_human_readable));
strncpy(dump_info->bus_human_readable, mvm->dev->bus->name,
sizeof(dump_info->bus_human_readable));
dump_data = iwl_fw_error_next_data(dump_data);
if (test_bit(STATUS_FW_ERROR, &mvm->trans->status)) {
iwl_mvm_dump_fifos(mvm, &dump_data);
if (radio_len)
iwl_mvm_read_radio_reg(mvm, &dump_data);
}
if (mvm->fw_dump_desc) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_ERROR_INFO);
dump_data->len = cpu_to_le32(sizeof(*dump_trig) +
mvm->fw_dump_desc->len);
dump_trig = (void *)dump_data->data;
memcpy(dump_trig, &mvm->fw_dump_desc->trig_desc,
sizeof(*dump_trig) + mvm->fw_dump_desc->len);
dump_data = iwl_fw_error_next_data(dump_data);
}
if (monitor_dump_only)
goto dump_trans_data;
if (!mvm->fw->dbg_dynamic_mem) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(sram_len + sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM_SRAM);
dump_mem->offset = cpu_to_le32(sram_ofs);
iwl_trans_read_mem_bytes(mvm->trans, sram_ofs, dump_mem->data,
sram_len);
dump_data = iwl_fw_error_next_data(dump_data);
}
for (i = 0; i < ARRAY_SIZE(mvm->fw->dbg_mem_tlv); i++) {
if (fw_dbg_mem[i]) {
u32 len = le32_to_cpu(fw_dbg_mem[i]->len);
u32 ofs = le32_to_cpu(fw_dbg_mem[i]->ofs);
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(len +
sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = fw_dbg_mem[i]->data_type;
dump_mem->offset = cpu_to_le32(ofs);
iwl_trans_read_mem_bytes(mvm->trans, ofs,
dump_mem->data,
len);
dump_data = iwl_fw_error_next_data(dump_data);
}
}
if (smem_len) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(smem_len + sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM_SMEM);
dump_mem->offset = cpu_to_le32(mvm->cfg->smem_offset);
iwl_trans_read_mem_bytes(mvm->trans, mvm->cfg->smem_offset,
dump_mem->data, smem_len);
dump_data = iwl_fw_error_next_data(dump_data);
}
if (sram2_len) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(sram2_len + sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM_SRAM);
dump_mem->offset = cpu_to_le32(mvm->cfg->dccm2_offset);
iwl_trans_read_mem_bytes(mvm->trans, mvm->cfg->dccm2_offset,
dump_mem->data, sram2_len);
dump_data = iwl_fw_error_next_data(dump_data);
}
if (mvm->cfg->device_family == IWL_DEVICE_FAMILY_8000 &&
CSR_HW_REV_STEP(mvm->trans->hw_rev) == SILICON_B_STEP) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(IWL8260_ICCM_LEN +
sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM_SRAM);
dump_mem->offset = cpu_to_le32(IWL8260_ICCM_OFFSET);
iwl_trans_read_mem_bytes(mvm->trans, IWL8260_ICCM_OFFSET,
dump_mem->data, IWL8260_ICCM_LEN);
dump_data = iwl_fw_error_next_data(dump_data);
}
if (mvm->fw->img[mvm->cur_ucode].paging_mem_size &&
mvm->fw_paging_db[0].fw_paging_block) {
for (i = 1; i < mvm->num_of_paging_blk + 1; i++) {
struct iwl_fw_error_dump_paging *paging;
struct page *pages =
mvm->fw_paging_db[i].fw_paging_block;
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_PAGING);
dump_data->len = cpu_to_le32(sizeof(*paging) +
PAGING_BLOCK_SIZE);
paging = (void *)dump_data->data;
paging->index = cpu_to_le32(i);
memcpy(paging->data, page_address(pages),
PAGING_BLOCK_SIZE);
dump_data = iwl_fw_error_next_data(dump_data);
}
}
if (prph_len) {
iwl_dump_prph(mvm->trans, &dump_data,
iwl_prph_dump_addr_comm,
ARRAY_SIZE(iwl_prph_dump_addr_comm));
if (mvm->cfg->mq_rx_supported)
iwl_dump_prph(mvm->trans, &dump_data,
iwl_prph_dump_addr_9000,
ARRAY_SIZE(iwl_prph_dump_addr_9000));
}
dump_trans_data:
fw_error_dump->trans_ptr = iwl_trans_dump_data(mvm->trans,
mvm->fw_dump_trig);
fw_error_dump->op_mode_len = file_len;
if (fw_error_dump->trans_ptr)
file_len += fw_error_dump->trans_ptr->len;
dump_file->file_len = cpu_to_le32(file_len);
sg_dump_data = alloc_sgtable(file_len);
if (sg_dump_data) {
sg_pcopy_from_buffer(sg_dump_data,
sg_nents(sg_dump_data),
fw_error_dump->op_mode_ptr,
fw_error_dump->op_mode_len, 0);
sg_pcopy_from_buffer(sg_dump_data,
sg_nents(sg_dump_data),
fw_error_dump->trans_ptr->data,
fw_error_dump->trans_ptr->len,
fw_error_dump->op_mode_len);
dev_coredumpsg(mvm->trans->dev, sg_dump_data, file_len,
GFP_KERNEL);
}
vfree(fw_error_dump->op_mode_ptr);
vfree(fw_error_dump->trans_ptr);
kfree(fw_error_dump);
out:
iwl_mvm_free_fw_dump_desc(mvm);
mvm->fw_dump_trig = NULL;
clear_bit(IWL_MVM_STATUS_DUMPING_FW_LOG, &mvm->status);
}
int iwl_mvm_fw_dbg_collect_desc(struct iwl_mvm *mvm,
const struct iwl_mvm_dump_desc *desc,
const struct iwl_fw_dbg_trigger_tlv *trigger)
{
unsigned int delay = 0;
if (trigger)
delay = msecs_to_jiffies(le32_to_cpu(trigger->stop_delay));
if (test_and_set_bit(IWL_MVM_STATUS_DUMPING_FW_LOG, &mvm->status))
return -EBUSY;
if (WARN_ON(mvm->fw_dump_desc))
iwl_mvm_free_fw_dump_desc(mvm);
IWL_WARN(mvm, "Collecting data: trigger %d fired.\n",
le32_to_cpu(desc->trig_desc.type));
mvm->fw_dump_desc = desc;
mvm->fw_dump_trig = trigger;
queue_delayed_work(system_wq, &mvm->fw_dump_wk, delay);
return 0;
}
int iwl_mvm_fw_dbg_collect(struct iwl_mvm *mvm, enum iwl_fw_dbg_trigger trig,
const char *str, size_t len,
const struct iwl_fw_dbg_trigger_tlv *trigger)
{
struct iwl_mvm_dump_desc *desc;
desc = kzalloc(sizeof(*desc) + len, GFP_ATOMIC);
if (!desc)
return -ENOMEM;
desc->len = len;
desc->trig_desc.type = cpu_to_le32(trig);
memcpy(desc->trig_desc.data, str, len);
return iwl_mvm_fw_dbg_collect_desc(mvm, desc, trigger);
}
int iwl_mvm_fw_dbg_collect_trig(struct iwl_mvm *mvm,
struct iwl_fw_dbg_trigger_tlv *trigger,
const char *fmt, ...)
{
u16 occurrences = le16_to_cpu(trigger->occurrences);
int ret, len = 0;
char buf[64];
if (!occurrences)
return 0;
if (fmt) {
va_list ap;
buf[sizeof(buf) - 1] = '\0';
va_start(ap, fmt);
vsnprintf(buf, sizeof(buf), fmt, ap);
va_end(ap);
if (WARN_ON_ONCE(buf[sizeof(buf) - 1]))
buf[sizeof(buf) - 1] = '\0';
len = strlen(buf) + 1;
}
ret = iwl_mvm_fw_dbg_collect(mvm, le32_to_cpu(trigger->id), buf, len,
trigger);
if (ret)
return ret;
trigger->occurrences = cpu_to_le16(occurrences - 1);
return 0;
}
static inline void iwl_mvm_restart_early_start(struct iwl_mvm *mvm)
{
if (mvm->cfg->device_family == IWL_DEVICE_FAMILY_7000)
iwl_clear_bits_prph(mvm->trans, MON_BUFF_SAMPLE_CTL, 0x100);
else
iwl_write_prph(mvm->trans, DBGC_IN_SAMPLE, 1);
}
int iwl_mvm_start_fw_dbg_conf(struct iwl_mvm *mvm, u8 conf_id)
{
u8 *ptr;
int ret;
int i;
if (WARN_ONCE(conf_id >= ARRAY_SIZE(mvm->fw->dbg_conf_tlv),
"Invalid configuration %d\n", conf_id))
return -EINVAL;
if ((!mvm->fw->dbg_conf_tlv[conf_id] ||
!mvm->fw->dbg_conf_tlv[conf_id]->num_of_hcmds) &&
conf_id == FW_DBG_START_FROM_ALIVE) {
iwl_mvm_restart_early_start(mvm);
return 0;
}
if (!mvm->fw->dbg_conf_tlv[conf_id])
return -EINVAL;
if (mvm->fw_dbg_conf != FW_DBG_INVALID)
IWL_WARN(mvm, "FW already configured (%d) - re-configuring\n",
mvm->fw_dbg_conf);
ptr = (void *)&mvm->fw->dbg_conf_tlv[conf_id]->hcmd;
for (i = 0; i < mvm->fw->dbg_conf_tlv[conf_id]->num_of_hcmds; i++) {
struct iwl_fw_dbg_conf_hcmd *cmd = (void *)ptr;
ret = iwl_mvm_send_cmd_pdu(mvm, cmd->id, 0,
le16_to_cpu(cmd->len), cmd->data);
if (ret)
return ret;
ptr += sizeof(*cmd);
ptr += le16_to_cpu(cmd->len);
}
mvm->fw_dbg_conf = conf_id;
return 0;
}
